// Game TU 801D1C18-801D2918 (unnamed). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern "C" void fn_801D22DC(void* this_, s32 seqIndex, s32 mode, s32 evalNow);

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

extern "C" BOOL fn_801D217C(AnmSeqCtrl* this_) {
    BOOL result = FALSE;
    if (this_->mCtrl.mAttr == 2 && this_->mCtrl.checkPass((f32)this_->mCurFrame - 0.001f)) {
        result = TRUE;
    }
    return result;
}

extern "C" BOOL fn_801D21F0(AnmSeqCtrl* this_) {
    BOOL result = FALSE;
    if (this_->mCtrl.checkState(1)
        || (this_->mCtrl.mAttr == 0 && this_->mCtrl.getRate() == 0.0f
            && this_->mCtrl.getFrame() > (f32)this_->mCurFrame - 0.002f))
    {
        result = TRUE;
    }
    return result;
}



extern "C" s32 fn_801D2264(void* this_, s32 seqIndex, s32 mode) {
    s32 result = 0;
    if (*(s32*)((char*)this_ + 0x8) != seqIndex) {
        fn_801D22DC(this_, seqIndex, mode, 1);
        result = 1;
    }
    return result;
}

extern "C" s32 fn_801D22A0(void* this_, s32 seqIndex, s32 mode) {
    s32 result = 0;
    if (*(s32*)((char*)this_ + 0x8) != seqIndex) {
        fn_801D22DC(this_, seqIndex, mode, 0);
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
