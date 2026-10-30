// TU 0x80442810-0x80442c64 — Sound Settings & One-Shot Audio Resource Loader Singleton.
#include "types.h"
#include "JSystem/JKernel/JKRHeap.h"

extern "C" void OSReport(const char* fmt, ...);

struct AudioLoadBase {
    u8 pad0[4];
    u8 mDone;
    u8 pad5[3];
};
struct AudioLoadRes : public AudioLoadBase {
    virtual ~AudioLoadRes();
    u8 padC[8];
    void* mData;
};

struct SoundSettingsController {
    /* 0x00 */ void* mVtable;
    /* 0x04 */ u8 mAudioLoaded;
};

extern "C" AudioLoadRes* fn_804019A8(const char* path, int mode, u32 heap);
extern "C" AudioLoadRes* fn_80401E10(const char* path, int mode, u32 heap);
extern "C" void fn_80459AE4(u32 a, u32 b, u32 c, void* d, void* e);

static AudioLoadRes* sInitBaa;
static AudioLoadRes* sSeqArc;

extern u8 lbl_80529DEC[];

extern "C" void fn_80442810(SoundSettingsController* thisPtr) {
    if (thisPtr->mAudioLoaded == 0) {
        if (sInitBaa == NULL) {
            sInitBaa = fn_804019A8("/GC4Sword_usa/AudioRes/JaiInit.baa", 2, *(u32*)(lbl_80529DEC + 0x4));
            if (sInitBaa == NULL) {
                return;
            }
        }
        if (sSeqArc == NULL) {
            sSeqArc = fn_80401E10("/GC4Sword_usa/AudioRes/Seqs/JaiSeqs.arc", 1, *(u32*)(lbl_80529DEC + 0x4));
            if (sSeqArc == NULL) {
                return;
            }
        }
        if (sInitBaa->mDone == 1 && sSeqArc->mDone == 1) {
            OSReport("audio data load end!!\n");
            fn_80459AE4(*(u32*)(lbl_80529DEC + 0xc), *(u32*)(lbl_80529DEC + 0x4), 0x800000, sInitBaa->mData, sSeqArc->mData);
            JKRHeap::free(sInitBaa->mData, NULL);
            delete sInitBaa;
            delete sSeqArc;
            OSReport("auido init end!!\n");
            thisPtr->mAudioLoaded = 1;
        }
    }
}

extern "C" void __dl__FPv(void* this_);
extern "C" u32 OSGetSoundMode(void);
extern "C" void fn_804594E4(void* mgr, s32 flag);

extern void* lbl_804B1A38[];
extern void* lbl_8053ADD8;
extern void* lbl_8053AF80;

extern "C" void* fn_8044296C(SoundSettingsController* this_, s16 how) {
    if (this_) {
        this_->mVtable = lbl_804B1A38;
        if (how > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void* fn_804429B4(SoundSettingsController* this_) {
    this_->mVtable = lbl_804B1A38;
    lbl_8053ADD8 = this_;
    this_->mAudioLoaded = 0;

    if (OSGetSoundMode() == 0) {
        fn_804594E4(lbl_8053AF80, 0);
        lbl_80529DEC[0x245] = 0;
    } else {
        fn_804594E4(lbl_8053AF80, 1);
        lbl_80529DEC[0x245] = 1;
    }

    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
