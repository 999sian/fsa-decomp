#ifndef JMESSAGE_PROCESSOR_H
#define JMESSAGE_PROCESSOR_H

#include "types.h"
#include "JSystem/JMessage/resource.h"

// Adapted from the Pikmin 2 decompilation (projectPiki/pikmin2), with the
// virtual function layout of FSA's JMessage (between Pikmin 2's and
// Twilight Princess' versions).

namespace JMessage {

struct TControl;

struct TReference {
    TReference() { mResource = nullptr; }

    virtual ~TReference();            // _08
    virtual char* do_word(u32) const; // _0C

    int on_parseCharacter(int c) const { return mResource->parseCharacter(c); }
    const char* on_word(u32 word) const { return do_word(word); }

    TResource* getResource_groupID(u16 groupID) const {
        if (mResource == nullptr) {
            return nullptr;
        }
        return mResource->getResource_groupID(groupID);
    }

    TResourceContainer* getResourceContainer() const { return mResource; }
    void setResourceContainer(TResourceContainer* container) { mResource = container; }

    // _00 = VTBL
    TResourceContainer* mResource; // _04
};

struct TProcessor {
    typedef bool (*OnCharacterEndCallBack)(TProcessor*);
    typedef const char* (*ProcessOnSelectCallBack)(TProcessor*);

    struct TStack {
        TStack() { clear(); }

        bool empty() const { return mSize == 0; }
        bool isPushable() const { return mSize < 4; }
        void clear() { mSize = 0; }

        u32 getSize() const { return mSize; }
        const char* getTop() const { return mStack[mSize - 1]; }

        void push(const char* str) {
            mStack[mSize] = str;
            mSize++;
        }

        void pop() { mSize--; }

        void operator=(const TStack& other) {
            mSize = other.mSize;
            const char** dst = mStack;
            const char** src = (const char**)other.mStack;
            const char** end = (const char**)&other.mStack[other.mSize];
            for (; src < end;) {
                *dst++ = *src++;
            }
        }

        u32 mSize;             // _00
        const char* mStack[4]; // _04
    };

    struct TProcess {
        struct TProcessData {
            ProcessOnSelectCallBack mSelectCallback; // _00
            const char* mBase;                       // _04
            const void* mOffset;                     // _08
            u32 mRest;                               // _0C
        };

        TProcess() { reset_normal(); }

        void reset_normal() { mEndCallback = process_onCharacterEnd_normal_; }
        void reset_select() { mEndCallback = process_onCharacterEnd_select_; }

        OnCharacterEndCallBack mEndCallback; // _00
        TProcessData mData;                  // _04
    };

    TProcessor(const TReference* reference) : mReference(reference), mResourceCache(nullptr), mCurrent(nullptr) { }

    virtual ~TProcessor();                                     // _08
    virtual void do_reset();                                   // _0C
    virtual void do_begin(const void*, const char*);           // _10
    virtual void do_end();                                     // _14
    virtual void do_character(int);                            // _18
    virtual bool do_tag(u32, const void*, u32);                // _1C
    virtual bool do_systemTagCode(u16, const void*, u32);      // _20
    virtual void do_select_begin(u32);                         // _24
    virtual void do_select_end();                              // _28
    virtual void do_select_separate();                         // _2C
    virtual void do_reset_(const char*);                       // _30
    virtual bool do_setBegin_isReady_() const;                 // _34
    virtual void do_begin_(const void*, const char*) = 0;      // _38
    virtual void do_end_() = 0;                                // _3C
    virtual void do_tag_(u32, const void*, u32) = 0;           // _40
    virtual void do_systemTagCode_(u16, const void*, u32) = 0; // _44

    void reset();
    const TResource* getResource_groupID(u16) const;
    const char* on_message_limited(u16) const;
    const char* on_message(u32) const;
    const char* getMessageText_messageCode(u32) const;
    static bool process_onCharacterEnd_normal_(TProcessor*);
    static bool process_onCharacterEnd_select_(TProcessor*);
    static const char* process_onSelect_limited_(TProcessor*);
    static const char* process_onSelect_(TProcessor*);

    void on_resetStatus_(const char* text) {
        mCurrent = text;
        mStack.clear();
        mProcess.reset_normal();
        do_reset_(text);
    }

    void setBegin_messageEntryText(const TResource* resource, const void* entry, const char* text) {
        mResourceCache = resource;
        on_resetStatus_(text);
        do_begin_(entry, text);
        do_begin(entry, text);
    }

    void* getMessageEntry_messageCode(u16 groupID, u16 messageIndex) const {
        const TResource* res = getResource_groupID(groupID);
        if (res == nullptr) {
            return nullptr;
        }
        return res->getMessageEntry_messageIndex(messageIndex);
    }

    const TResource* getResource_groupID_uncached(u16 groupID) const { return mReference->getResource_groupID(groupID); }

    bool isResourceCache_groupID(u16 groupID) const {
        return mResourceCache != nullptr && groupID == mResourceCache->getGroupID();
    }

    const TResource* getResourceCache() const { return mResourceCache; }
    const char* getCurrent() const { return mCurrent; }
    const TReference* getReference() const { return mReference; }

    int on_parseCharacter(int c) const { return mReference->on_parseCharacter(c); }
    void on_character(int c) { do_character(c); }

    void on_end() {
        do_end_();
        do_end();
    }

    const char* on_word(u32 word) const { return mReference->on_word(word); }

    void on_tag(u32 tag, const void* data, u32 size) {
        if (!do_tag(tag, data, size)) {
            do_tag_(tag, data, size);
        }
    }

    void setCurrent_(const char* p) { mCurrent = p; }

    void stack_pushCurrent(const char* p) {
        if (p != nullptr && mStack.isPushable()) {
            stack_pushCurrent_(p);
        }
    }

    void stack_pushCurrent_(const char* p) {
        mStack.push(mCurrent);
        mCurrent = p;
    }

    void stack_popCurrent_() {
        mCurrent = mStack.getTop();
        mStack.pop();
    }

    void on_select_begin(ProcessOnSelectCallBack pfn, const void* offset, const char* base, u32 number) {
        if (mStack.isPushable()) {
            mProcess.reset_select();
            mProcess.mData.mSelectCallback = pfn;
            mProcess.mData.mBase = base;
            mProcess.mData.mOffset = offset;
            mProcess.mData.mRest = number;
            stack_pushCurrent_(pfn(this));
            do_select_begin(number);
        }
    }

    void on_select_end() {
        mProcess.reset_normal();
        stack_popCurrent_();
        do_select_end();
    }

    void on_select_separate() {
        stack_popCurrent_();
        stack_pushCurrent_(mProcess.mData.mSelectCallback(this));
        do_select_separate();
    }

    void on_tag_() {
        const u8* current = (const u8*)getCurrent();
        const void* data = &current[5];
        u32 tag = 0;
        u32 size = current[1];
        setCurrent_((const char*)current + size);
        tag |= 0xFF0000 & (current[2] << 16);
        tag |= 0x00FF00 & (current[3] << 8);
        tag |= 0x0000FF & (current[4] << 0);
        if (!do_tag(tag, data, size - 5)) {
            do_tag_(tag, data, size - 5);
        }
    }

    bool process_character_() {
        int character = *(const u8*)getCurrent();

        switch (character) {
        case 0:
            if (!mProcess.mEndCallback(this)) {
                return false;
            }
            break;
        case data::gcTagBegin:
            on_tag_();
            break;
        default:
            if (on_parseCharacter(character)) {
                character <<= 8;
                mCurrent++;
                character |= ((const u8*)getCurrent())[0];
            }
            mCurrent++;
            on_character(character);
        }

        return true;
    }

    // _00 = VTBL
    const TReference* mReference;    // _04
    const TResource* mResourceCache; // _08
    const char* mCurrent;            // _0C
    TStack mStack;                   // _10
    TProcess mProcess;               // _24
};

struct TSequenceProcessor : public TProcessor {
    typedef const void* (*OnJumpCallBack)(const TSequenceProcessor*);
    typedef const void* (*OnBranchCallBack)(const TSequenceProcessor*, u32);

    enum SeqStatus {
        STATUS_Ready,
        STATUS_End,
        STATUS_Normal,
        STATUS_Jump,
        STATUS_Branch,
    };

    struct TProcess_ {
        union {
            struct {
                OnBranchCallBack mBranchFunc; // _00
                const void* mTargetAddr;      // _04
                u32 mTarget;                  // _08
            } mBranchProc;
            struct {
                OnJumpCallBack mJumpFunc; // _00
                u32 mTarget;              // _04
            } mJumpProc;
        };
    };

    TSequenceProcessor(const TReference*, TControl*);

    virtual ~TSequenceProcessor();                         // _08
    virtual void do_reset_(const char*);                   // _30
    virtual bool do_setBegin_isReady_() const;             // _34
    virtual void do_begin_(const void*, const char*);      // _38
    virtual void do_end_();                                // _3C
    virtual void do_tag_(u32, const void*, u32);           // _40
    virtual void do_systemTagCode_(u16, const void*, u32); // _44
    virtual bool do_isReady();                             // _48
    virtual bool do_jump_isReady();                        // _4C
    virtual void do_jump(const void*, const char*);        // _50
    virtual void do_branch_query(u16);                     // _54
    virtual int do_branch_queryResult();                   // _58
    virtual void do_branch(const void*, const char*);      // _5C

    const char* process(const char*);
    bool on_isReady();
    bool on_jump_isReady();
    void on_jump(const void*, const char*);
    int on_branch_queryResult();
    void on_branch(const void*, const char*);
    static const void* process_onJump_limited_(const TSequenceProcessor*);
    static const void* process_onJump_(const TSequenceProcessor*);
    static const void* process_onBranch_limited_(const TSequenceProcessor*, u32);
    static const void* process_onBranch_(const TSequenceProcessor*, u32);

    // _00-_38 = TProcessor
    TControl* mControl; // _38
    int mStatus;        // _3C
    TProcess_ mProc;    // _40
};

struct TRenderingProcessor : public TProcessor {
    TRenderingProcessor(const TReference*);

    virtual ~TRenderingProcessor();                        // _08
    virtual void do_begin_(const void*, const char*);      // _38
    virtual void do_end_();                                // _3C
    virtual void do_tag_(u32, const void*, u32);           // _40
    virtual void do_systemTagCode_(u16, const void*, u32); // _44

    int process(const char*);
};

} // namespace JMessage

#endif
