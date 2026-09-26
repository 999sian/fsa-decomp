#include "JSystem/JMessage/resource.h"
#include "JSystem/JGadget/enumerator.h"
#include "JSystem/JUtility/JUTFont.h"
#include "string.h"

// Adapted from the Pikmin 2 decompilation (projectPiki/pikmin2).
// FSA's version has no message-ID (MID1) lookup (toMessageIndex_messageID).

// Not present in FSA (inlined into TResourceContainer's ctor and dead-stripped),
// but defining it out of line here gives the retail vtable order.
JMessage::TResourceContainer::TCResource::TCResource() { }

JMessage::TResourceContainer::TCResource::~TCResource() { }

JMessage::TResource* JMessage::TResourceContainer::TCResource::Get_groupID(u16 groupID) {
    JGadget::TContainerEnumerator<TResource, 0> enumerator(this);
    while (enumerator) {
        const TResource* res = &(*enumerator);
        if (res->mInfo.getGroupID() == groupID)
            return (TResource*)res;
    }
    return nullptr;
}

JMessage::TResource* JMessage::TResourceContainer::TCResource::Do_create() {
    return new JMessage::TResource;
}

void JMessage::TResourceContainer::TCResource::Do_destroy(JMessage::TResource* res) {
    delete res;
}

JMessage::TResourceContainer::TResourceContainer() : mEncoding(0), isLeadByte(nullptr) { }

JMessage::TResourceContainer::IsLeadByteFunc JMessage::TResourceContainer::sapfnIsLeadByte_[4] = {
    nullptr,
    JUTFont::isLeadByte_1Byte,
    JUTFont::isLeadByte_2Byte,
    JUTFont::isLeadByte_ShiftJIS,
};

JMessage::TParse::TParse(JMessage::TResourceContainer* container) {
    mResourceContainer = container;
    mResource = nullptr;
}

JMessage::TParse::~TParse() { }

bool JMessage::TParse::parseHeader_next(const void** dataPtr, u32* outSize, u32 flag) {
    const void* pData = *dataPtr;

    data::TParse_THeader header(pData);
    *dataPtr = header.getContent();
    *outSize = header.getBlockNumber();

    if (memcmp(header.getSignature(), &data::ga4cSignature, sizeof(data::ga4cSignature)) != 0)
        return false;

    if (header.getType() != 'bmg1')
        return false;

    u8 encoding = header.getEncoding();
    if (encoding != 0) {
        if (!mResourceContainer->isEncodingSettable(encoding)) {
            return false;
        }
        mResourceContainer->setEncoding(encoding);
    }

    if (flag & 0x10)
        return true;

    TResourceContainer::TCResource* container = &mResourceContainer->mContainer;
    mResource = container->Do_create();
    if (mResource == nullptr)
        return flag & 0x20 ? true : false;

    container->Push_back(mResource);
    mResource->setData_header(header.getRaw());
    return true;
}

bool JMessage::TParse::parseBlock_next(const void** dataPtr, u32* outSize, u32 flag) {
    data::TParse_THeader* header = (data::TParse_THeader*)*dataPtr;

    data::TParse_TBlock oBlock(header);
    *dataPtr = oBlock.getNext();
    *outSize = oBlock.get_size();

    TResourceContainer::TCResource& container = mResourceContainer->mContainer;
    switch (oBlock.get_type()) {
    case 'INF1':
        mResource->setData_block_info(header);
        break;
    case 'DAT1':
        mResource->setData_block_messageData((char*)&header[2]);

        u16 group = mResource->getGroupID();
        if (flag & 0x80) {
            JGadget::TLinkList<TResource, 0>::iterator iResource(container.begin());
            TResource* pResource;
            while ((pResource = &*iResource) != mResource) {
                if (group != pResource->getGroupID()) {
                    iResource++;
                } else {
                    iResource = container.Erase_destroy(pResource);
                }
            }
        }
        break;
    case 'STR1':
        mResource->setData_block_stringAttribute((char*)&header[2]);
        break;
    case 'MID1':
        mResource->setData_block_messageID(header);
        break;
    default:
        if (!(flag & 0x40))
            return false;
        break;
    }

    return true;
}

JMessage::TParse_color::TParse_color(JMessage::TResourceContainer* container) {
    mResourceContainer = container;
}

JMessage::TParse_color::~TParse_color() { }

bool JMessage::TParse_color::parseHeader_next(const void** dataPtr, u32* outSize, u32 flag) {
    const void* pData = *dataPtr;
    data::TParse_THeader header(pData);
    *dataPtr = header.getContent();
    *outSize = header.getBlockNumber();

    if (memcmp(header.getSignature(), &data::ga4cSignature_color, sizeof(data::ga4cSignature_color)) != 0)
        return false;

    if (header.getType() != 'bmc1')
        return false;

    TResourceContainer* container = mResourceContainer;
    if (container->isResourceContained_color() && !(flag & 0x20)) {
        return false;
    }

    container->mColor.reset();
    container->mColor.setData_header(header.getRaw());

    return true;
}

bool JMessage::TParse_color::parseBlock_next(const void** dataPtr, u32* outSize, u32 flag) {
    const void* pData = *dataPtr;
    data::TParse_TBlock block(pData);
    *dataPtr = (const void*)((u32)pData + ((u32*)pData)[1]);
    *outSize = ((u32*)pData)[1];

    TResourceContainer* container = mResourceContainer;
    switch (((int*)pData)[0]) {
    case 'CLT1':
        container->mColor.mBlock.setRaw(pData);
        break;
    default:
        if (!(flag & 0x10)) {
            return false;
        }
        break;
    }
    return true;
}
