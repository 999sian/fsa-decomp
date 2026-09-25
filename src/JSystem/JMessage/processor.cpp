#include "JSystem/JMessage/processor.h"
#include "JSystem/JMessage/control.h"
#include "JSystem/JMessage/data.h"

// Adapted from the Pikmin 2 decompilation (projectPiki/pikmin2), reworked to
// FSA's JMessage version.

namespace JMessage {

TReference::~TReference() { }

char* TReference::do_word(u32) const { return nullptr; }

TProcessor::~TProcessor() { }

void TProcessor::reset() {
    on_resetStatus_(nullptr);
    do_reset();
}

const TResource* TProcessor::getResource_groupID(u16 groupID) const {
    if (isResourceCache_groupID(groupID)) {
        return mResourceCache;
    }

    ((TProcessor*)this)->mResourceCache = getResource_groupID_uncached(groupID);
    return mResourceCache;
}

void TProcessor::do_reset() { }

void TProcessor::do_begin(const void*, const char*) { }

void TProcessor::do_end() { }

void TProcessor::do_character(int) { }

bool TProcessor::do_tag(u32, const void*, u32) { return false; }

bool TProcessor::do_systemTagCode(u16, const void*, u32) { return false; }

void TProcessor::do_select_begin(u32) { }

void TProcessor::do_select_end() { }

void TProcessor::do_select_separate() { }

void TProcessor::do_reset_(const char*) { }

bool TProcessor::do_setBegin_isReady_() const { return true; }

void TProcessor::do_tag_(u32 tag, const void* data, u32 size) {
    int group = data::getTagGroup(tag);
    int code = data::getTagCode(tag);
    switch (group) {
    case 0xFF:
        if (do_systemTagCode(code, data, size) == false) {
            do_systemTagCode_(code, data, size);
        }
        break;
    case 0xFE:
        stack_pushCurrent(on_word(code));
        break;
    case 0xFD:
        stack_pushCurrent(on_message_limited(code));
        break;
    case 0xF6:
        on_select_begin(&process_onSelect_limited_, data, (const char*)data + size, code);
        break;
    case 0xF5:
        on_select_begin(&process_onSelect_, data, (const char*)data + size, code);
        break;
    }
}

const char* TProcessor::on_message_limited(u16 messageIndex) const {
    return mResourceCache->getMessageText_messageIndex(messageIndex);
}

void TProcessor::do_systemTagCode_(u16 code, const void* data, u32) {
    switch (code) {
    case 4:
        stack_pushCurrent(mReference->do_word(*(u32*)data));
        break;
    case 5:
        stack_pushCurrent(on_message(*(u32*)data));
        break;
    }
}

const char* TProcessor::on_message(u32 code) const { return getMessageText_messageCode(code); }

const char* TProcessor::getMessageText_messageCode(u32 code) const {
    const TResource* resource = getResource_groupID(code >> 16);
    void* entry = (resource == nullptr) ? nullptr : resource->getMessageEntry_messageIndex(data::getTagCode(code));

    if (!entry) {
        return nullptr;
    }

    return mResourceCache->getMessageText_messageEntry(entry);
}

bool TProcessor::process_onCharacterEnd_normal_(TProcessor* processor) {
    if (!processor->mStack.empty()) {
        processor->stack_popCurrent_();
        return true;
    }

    processor->on_end();
    return false;
}

bool TProcessor::process_onCharacterEnd_select_(TProcessor* processor) {
    processor->mProcess.mData.mRest--;
    if (processor->mProcess.mData.mRest != 0) {
        processor->on_select_separate();
        return true;
    }

    processor->on_select_end();
    return true;
}

const char* TProcessor::process_onSelect_limited_(TProcessor* processor) {
    TProcess::TProcessData& pdata = processor->mProcess.mData;

    const u16* puOffset = (const u16*)pdata.mOffset;
    u16 uData = JGadget::binary::TParseValue<JGadget::binary::TParseValue_endian_big_<u16> >::parse(puOffset);
    pdata.mOffset = puOffset + 1;
    return &pdata.mBase[uData];
}

const char* TProcessor::process_onSelect_(TProcessor* processor) {
    TProcess::TProcessData& pdata = processor->mProcess.mData;

    const u32* puOffset = (const u32*)pdata.mOffset;
    u32 uData = JGadget::binary::TParseValue<JGadget::binary::TParseValue_endian_big_<u32> >::parse(puOffset);
    pdata.mOffset = puOffset + 1;
    return &pdata.mBase[uData];
}

TSequenceProcessor::TSequenceProcessor(const TReference* ref, TControl* control)
    : TProcessor(ref), mControl(control), mStatus(STATUS_Ready) { }

TSequenceProcessor::~TSequenceProcessor() { }

const char* TSequenceProcessor::process(const char* pszText) {
    do {
        switch (mStatus) {
        case STATUS_Normal:
            break;
        case STATUS_Jump: {
            if (!on_jump_isReady()) {
                return mCurrent;
            }

            mStatus = STATUS_Normal;
            const void* entry = mProc.mJumpProc.mJumpFunc(this);
            if (entry != nullptr) {
                on_jump(entry, mControl->getMessageText_begin());
            }
            break;
        }
        case STATUS_Branch: {
            u32 result = on_branch_queryResult();
            if (result > 0x7FFFFFFF) {
                switch (result) {
                case 0xFFFFFFFF:
                    return mCurrent;
                case 0xFFFFFFFE:
                    mStatus = STATUS_Normal;
                    break;
                }
            } else {
                mStatus = STATUS_Normal;
                if (result < mProc.mBranchProc.mTarget) {
                    const void* entry = mProc.mBranchProc.mBranchFunc(this, result);
                    if (entry != nullptr) {
                        on_branch(entry, mControl->getMessageText_begin());
                    }
                }
            }
            break;
        }
        }

        if (mCurrent == pszText) {
            on_end();
            return nullptr;
        }

        if (!on_isReady()) {
            return mCurrent;
        }
    } while (process_character_());

    return nullptr;
}

bool TSequenceProcessor::on_isReady() { return do_isReady(); }

bool TSequenceProcessor::on_jump_isReady() { return do_jump_isReady(); }

void TSequenceProcessor::on_jump(const void* entry, const char* text) {
    on_resetStatus_(text);
    do_jump(entry, text);
}

int TSequenceProcessor::on_branch_queryResult() { return do_branch_queryResult(); }

void TSequenceProcessor::on_branch(const void* entry, const char* text) {
    on_resetStatus_(text);
    do_branch(entry, text);
}

bool TSequenceProcessor::do_isReady() { return true; }

bool TSequenceProcessor::do_jump_isReady() { return true; }

void TSequenceProcessor::do_jump(const void*, const char*) { }

void TSequenceProcessor::do_branch_query(u16) { }

int TSequenceProcessor::do_branch_queryResult() { return -2; }

void TSequenceProcessor::do_branch(const void*, const char*) { }

void TSequenceProcessor::do_reset_(const char* text) {
    mStatus = STATUS_Ready;
    if (text) {
        mStatus = STATUS_Normal;
    }
}

bool TSequenceProcessor::do_setBegin_isReady_() const { return mStatus == STATUS_Ready; }

void TSequenceProcessor::do_begin_(const void*, const char*) { }

void TSequenceProcessor::do_end_() { mStatus = STATUS_End; }

void TSequenceProcessor::do_tag_(u32 tag, const void* data, u32 size) {
    u32 group = data::getTagGroup(tag);
    u16 code = data::getTagCode(tag);
    switch (group) {
    case 0xFC:
        mStatus = STATUS_Jump;
        mProc.mJumpProc.mJumpFunc = &process_onJump_limited_;
        mProc.mJumpProc.mTarget = code;
        break;
    case 0xFB:
        mProc.mBranchProc.mBranchFunc = &process_onBranch_limited_;
        mProc.mBranchProc.mTargetAddr = data;
        mProc.mBranchProc.mTarget = code;
        break;
    case 0xFA:
        mProc.mBranchProc.mBranchFunc = &process_onBranch_;
        mProc.mBranchProc.mTargetAddr = data;
        mProc.mBranchProc.mTarget = code;
        break;
    case 0xF9:
        mStatus = STATUS_Branch;
        do_branch_query(code);
        break;
    case 0xF8:
        mProc.mBranchProc.mBranchFunc = &process_onBranch_limited_;
        mProc.mBranchProc.mTargetAddr = (const void*)((u32)data + 2);
        mProc.mBranchProc.mTarget = *(u16*)(data);
        mStatus = STATUS_Branch;
        do_branch_query(code);
        break;
    case 0xF7:
        mProc.mBranchProc.mBranchFunc = &process_onBranch_;
        mProc.mBranchProc.mTargetAddr = (const void*)((u32)data + 2);
        mProc.mBranchProc.mTarget = *(u16*)(data);
        mStatus = STATUS_Branch;
        do_branch_query(code);
        break;
    default:
        TProcessor::do_tag_(tag, data, size);
        break;
    }
}

void TSequenceProcessor::do_systemTagCode_(u16 code, const void* data, u32 size) {
    switch (code) {
    case 6:
        u32 target = *(u32*)data;
        mStatus = STATUS_Jump;
        mProc.mJumpProc.mJumpFunc = &process_onJump_;
        mProc.mJumpProc.mTarget = target;
        break;
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 4:
    case 5:
    default:
        TProcessor::do_systemTagCode_(code, data, size);
        break;
    }
}

const void* TSequenceProcessor::process_onJump_limited_(const TSequenceProcessor* processor) {
    u16 groupID = processor->mResourceCache->getGroupID();

    u16 index = processor->mProc.mJumpProc.mTarget & 0xFFFF;
    if (index >= 0xFF00) {
        return nullptr;
    }

    TControl* control = processor->mControl;
    return (!control->setMessageCode_inSequence_(processor, groupID, index)) ? nullptr : control->mEntry;
}

const void* TSequenceProcessor::process_onJump_(const TSequenceProcessor* processor) {
    u16 index = processor->mProc.mJumpProc.mTarget & 0xFFFF;
    if (index >= 0xFF00) {
        return nullptr;
    }

    TControl* control = processor->mControl;
    return (!control->setMessageCode_inSequence_(processor, processor->mProc.mJumpProc.mTarget >> 0x10, index))
               ? nullptr
               : control->mEntry;
}

const void* TSequenceProcessor::process_onBranch_limited_(const TSequenceProcessor* processor, u32 target) {
    u16 index = ((u16*)processor->mProc.mBranchProc.mTargetAddr)[target];
    u16 groupID = processor->mResourceCache->getGroupID();

    if (index >= 0xFF00) {
        return nullptr;
    }

    TControl* control = processor->mControl;
    return (!control->setMessageCode_inSequence_(processor, groupID, index)) ? nullptr : control->mEntry;
}

const void* TSequenceProcessor::process_onBranch_(const TSequenceProcessor* processor, u32 target) {
    u16 index = ((u32*)processor->mProc.mJumpProc.mTarget)[target];

    if (index >= 0xFF00) {
        return nullptr;
    }

    TControl* control = processor->mControl;
    return (!control->setMessageCode_inSequence_(processor, ((u32*)processor->mProc.mJumpProc.mTarget)[target] >> 0x10,
                                                 index))
               ? nullptr
               : control->mEntry;
}

TRenderingProcessor::TRenderingProcessor(const TReference* ref) : TProcessor(ref) { }

TRenderingProcessor::~TRenderingProcessor() { }

int TRenderingProcessor::process(const char* pszText) {
    do {
        if (mCurrent == pszText) {
            on_end();
            return 0;
        }
    } while (process_character_());

    return 0;
}

void TRenderingProcessor::do_begin_(const void*, const char*) { }

void TRenderingProcessor::do_end_() { }

void TRenderingProcessor::do_tag_(u32 tag, const void* data, u32 size) {
    int group = tag >> 0x10 & 0xFF;
    if ((group >= 0xFD) || (group < 0xF7)) {
        TProcessor::do_tag_(tag, data, size);
    }
}

void TRenderingProcessor::do_systemTagCode_(u16 code, const void* data, u32 size) {
    switch (code) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 6:
        break;
    case 4:
    case 5:
    default:
        TProcessor::do_systemTagCode_(code, data, size);
        break;
    }
}

} // namespace JMessage
