#include "JSystem/JMessage/control.h"
#include "JSystem/JMessage/processor.h"
#include "JSystem/JMessage/resource.h"

// Adapted from the Pikmin 2 decompilation (projectPiki/pikmin2), reworked to
// FSA's JMessage version (no message-ID lookup).

namespace JMessage {

TControl::TControl()
    : mBaseProcSeq(nullptr), mBaseProcRender(nullptr), mMessageCode(0xFFFF), mMessageIndex(0xFFFF), mResourceCache(nullptr),
      mEntry(nullptr), mMessageBegin(nullptr), mCurrentText(nullptr), _20(nullptr) { }

TControl::~TControl() { }

void TControl::reset() {
    mEntry = nullptr;
    mMessageBegin = nullptr;
    mCurrentText = nullptr;
    _20 = nullptr;
    mRenderStack.clear();

    if (mBaseProcSeq) {
        mBaseProcSeq->reset();
    }

    if (mBaseProcRender) {
        mBaseProcRender->reset();
    }
}

bool TControl::update() {
    if (!isReady_update_()) {
        return false;
    }

    mCurrentText = mBaseProcSeq->process(nullptr);

    if (!mCurrentText) {
        mMessageBegin = nullptr;
        return false;
    }

    return true;
}

void TControl::render() {
    if (!isReady_render_()) {
        return;
    }

    mBaseProcRender->setBegin_messageEntryText(mResourceCache, mEntry, _20);
    mBaseProcRender->mStack = mRenderStack;
    mBaseProcRender->process(mCurrentText);
}

bool TControl::setMessageCode(u16 groupID, u16 index) {
    return setMessageCode_inReset_(getProcessor(), groupID, index);
}

bool TControl::setMessageCode_inSequence_(const TProcessor* proc, u16 groupID, u16 index) {
    mEntry = proc->getMessageEntry_messageCode(groupID, index);

    if (mEntry == nullptr) {
        return false;
    }

    mMessageCode = groupID;
    mMessageIndex = index;
    mResourceCache = proc->getResourceCache();
    mMessageBegin = mResourceCache->getMessageText_messageEntry(mEntry);
    _20 = mMessageBegin;
    mRenderStack.clear();
    return true;
}

} // namespace JMessage
