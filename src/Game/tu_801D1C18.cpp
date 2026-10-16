// Game TU 801D1C18-801D2918 (unnamed). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"



#include "dolphin/os.h"
#include "JSystem/JKernel/JKRHeap.h"

#include "JSystem/J3D/J3DFrameCtrl.h"

struct SeqEntry {
    s16 mFrame;
    s16 _2;
};

struct AnmSeqCtrl {
    SeqEntry** mSeqs;   // 0x00
    s32 mSeqNum;        // 0x04
    s32 mCurSeq;        // 0x08
    s32 mCurFrame;      // 0x0C
    s32 _10;            // 0x10
    s32 mMin;           // 0x14
    s32 mMax;           // 0x18
    s32 _1C;            // 0x1C
    u8 _20;             // 0x20
    J3DFrameCtrl mCtrl; // 0x24
};

extern "C" s32 fn_801CD664(s32 n);

static inline s32 clampS32(s32 v, s32 lo, s32 hi) {
    if (v > hi) {
        v = hi;
    } else if (v < lo) {
        v = lo;
    }
    return v;
}

static inline s32 clampSeq(AnmSeqCtrl* this_, s32 f) {
    return clampS32(f, this_->mMin, this_->mMax);
}

static inline void calcSeq(AnmSeqCtrl* this_) {
    f32 frame = this_->mCtrl.mFrame;
    s32 start = 0;
    s32 idx = start;
    for (SeqEntry* e = this_->mSeqs[this_->mCurSeq]; e->mFrame >= 0; e++, idx++) {
        s32 prev = start;
        start += e->_2;
        if ((f32)prev <= frame && frame < (f32)start) {
            this_->_10 = clampSeq(this_, e->mFrame);
            this_->_1C = idx;
            return;
        }
    }
    this_->_10 = clampSeq(this_, this_->mSeqs[this_->mCurSeq]->mFrame);
    this_->_1C = 0;
}

static inline void setSeqFrame(AnmSeqCtrl* this_, f32 frame) {
    f32 end = (f32)this_->mCurFrame;
    f32 f = frame;
    if (f > end) {
        f = end;
    } else if (f < 0.0f) {
        f = 0.0f;
    }
    if (f == (f32)this_->mCurFrame) {
        if (this_->mCtrl.mAttr == 2) {
            f = 0.0f;
        } else {
            f -= 0.001f;
        }
    }
    this_->mCtrl.mFrame = f;
    calcSeq(this_);
}

extern "C" void fn_801D1C18(AnmSeqCtrl* this_) {
    if (this_->mCurSeq >= 0 && this_->mCurSeq < this_->mSeqNum) {
        if (this_->_20 != 0) {
            this_->_20 = 0;
        } else {
            this_->mCtrl.update();
            f32 frame = this_->mCtrl.mFrame;
            s32 start = 0;
            s32 idx = 0;
            for (SeqEntry* e = this_->mSeqs[this_->mCurSeq]; e->mFrame >= 0; e++, idx++) {
                s32 prev = start;
                start += e->_2;
                if ((f32)prev <= frame && frame < (f32)start) {
                    this_->_10 = clampSeq(this_, e->mFrame);
                    this_->_1C = idx;
                    return;
                }
            }
            this_->_10 = clampSeq(this_, this_->mSeqs[this_->mCurSeq]->mFrame);
            this_->_1C = 0;
        }
    }
}

extern "C" void fn_801D1D60(AnmSeqCtrl* this_) {
    setSeqFrame(this_, (f32)fn_801CD664(this_->mCurFrame + 1));
}

extern "C" void fn_801D1F14(AnmSeqCtrl* this_, f32 frame) {
    setSeqFrame(this_, frame);
}

static inline BOOL isEndPass(AnmSeqCtrl* this_) {
    BOOL result = FALSE;
    if (this_->mCtrl.mAttr == 2 && this_->mCtrl.checkPass((f32)this_->mCurFrame - 0.001f)) {
        result = TRUE;
    }
    return result;
}

static inline BOOL isEndStop(AnmSeqCtrl* this_) {
    BOOL result = FALSE;
    if (this_->mCtrl.checkState(1)
        || (this_->mCtrl.mAttr == 0 && this_->mCtrl.mRate == 0.0f
            && this_->mCtrl.mFrame > (f32)this_->mCurFrame - 0.002f))
    {
        result = TRUE;
    }
    return result;
}

static inline bool isOnce(AnmSeqCtrl* this_) {
    return this_->mCtrl.mAttr == 0;
}

extern "C" BOOL fn_801D208C(AnmSeqCtrl* this_) {
    BOOL result = FALSE;
    u8 once = (this_->mCtrl.mAttr == 0) ? 1 : 0;
    if (once) {
        result = FALSE;
        if (this_->mCtrl.checkState(1)
            || (this_->mCtrl.mAttr == 0 && this_->mCtrl.mRate == 0.0f
                && this_->mCtrl.mFrame > (f32)this_->mCurFrame - 0.002f))
        {
            result = TRUE;
        }
    } else if (this_->mCtrl.mAttr == 2) {
        result = isEndPass(this_);
    }
    return result;
}

extern "C" BOOL fn_801D217C(AnmSeqCtrl* this_) {
    return isEndPass(this_);
}

extern "C" BOOL fn_801D21F0(AnmSeqCtrl* this_) {
    u8 state = this_->mCtrl.mState;
    BOOL result = FALSE;
    if ((state & 1)
        || (this_->mCtrl.mAttr == 0 && this_->mCtrl.mRate == 0.0f
            && this_->mCtrl.mFrame > (f32)this_->mCurFrame - 0.002f))
    {
        result = TRUE;
    }
    return result;
}

extern "C" void fn_801D22DC(AnmSeqCtrl* this_, s32 seqIndex, s32 mode, bool keepFrame) {
    this_->mCurSeq = seqIndex;
    SeqEntry* e = this_->mSeqs[this_->mCurSeq];
    this_->mCurFrame = 0;
    for (; e->mFrame >= 0; e++) {
        this_->mCurFrame += e->_2;
    }
    if (mode != 2) {
        this_->mCurFrame--;
    }
    f32 frame = this_->mCtrl.mFrame;
    this_->mCtrl.init((s16)this_->mCurFrame);
    this_->mCtrl.mAttr = mode;
    if (keepFrame) {
        setSeqFrame(this_, frame);
        this_->_20 = 0;
    } else {
        calcSeq(this_);
        this_->_20 = 1;
    }
}

extern "C" s32 fn_801D2264(void* this_, s32 seqIndex, s32 mode) {
    s32 result = 0;
    if (*(s32*)((char*)this_ + 0x8) != seqIndex) {
        fn_801D22DC((AnmSeqCtrl*)this_, seqIndex, mode, 1);
        result = 1;
    }
    return result;
}

extern "C" s32 fn_801D22A0(void* this_, s32 seqIndex, s32 mode) {
    s32 result = 0;
    if (*(s32*)((char*)this_ + 0x8) != seqIndex) {
        fn_801D22DC((AnmSeqCtrl*)this_, seqIndex, mode, 0);
        result = 1;
    }
    return result;
}

extern "C" void fn_801D2608(AnmSeqCtrl* this_, SeqEntry** seqs, s32 num) {
    this_->mSeqs = seqs;
    this_->mSeqNum = num;
    for (s32 i = 0; i < this_->mSeqNum; i++) {
        SeqEntry* e = this_->mSeqs[i];
        while (e->mFrame >= 0) {
            this_->mMin = this_->mMin >= e->mFrame ? e->mFrame : this_->mMin;
            this_->mMax = this_->mMax >= e->mFrame ? this_->mMax : e->mFrame;
            e++;
        }
    }
}

extern void* lbl_8049CC34[];

extern "C" AnmSeqCtrl* fn_801D267C(AnmSeqCtrl* this_) {
    this_->mSeqs = NULL;
    this_->mSeqNum = 0;
    this_->mCurSeq = -1;
    this_->mCurFrame = 0;
    this_->_10 = 0;
    this_->mMin = 0x7fffffff;
    this_->mMax = 0x80000000;
    this_->_1C = 0;
    this_->_20 = 0;
    *(void**)&this_->mCtrl = lbl_8049CC34;
    this_->mCtrl.init((s16)0);
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
