// TU 0x802ecad4-0x802ed140 — Actor 'SDSM' (Sandstorm / Screen-Wide Weather Effect Controller).
#include "Game/esd/types.h"

extern "C" {
void Sdsm_EmptyHook(void) {}
}

struct SdsmMsg { u32 id; };
struct SdsmWaveBase { u8 pad[8]; };
struct SdsmWave : SdsmWaveBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void send(SdsmMsg*);
};
class WaveController {
public:
    WaveController(s32 a, s32 b, s32 c);
    ~WaveController();
private:
    unsigned char pad[0x5c];
};

#undef ALIGN_NEXT
#undef ALIGN_PREV
#undef ARRAY_SIZE
#undef ASM
#undef ATTRIBUTE_ALIGN
#undef IS_ALIGNED
#undef IS_NOT_ALIGNED
#undef MACROS_H
#undef MAX
#undef MIN
#undef NULL
#define NULL 0
#ifndef unknown
#define unknown jsys_unknown
#endif
#include "JSystem/JParticle/JPAEmitter.h"


struct SdsmActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ s32 mRoomId;
    /* 0x008 */ u8 _pad08[0x90 - 0x08];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[0x230 - 0x94];
    /* 0x230 */ WaveController* mWaveCtrl;
    /* 0x234 */ JPABaseEmitter* mEmitter;
    /* 0x238 */ u32 mField238;
    /* 0x23C */ u32 mVariantFlags;  // Unpacked from spawnParam & 0xF
    /* 0x240 */ s32 mEndCountdown;  // Counts down from 100 when cleared
    /* 0x244 */ f32 mEffectPos[3];  // Camera-locked world position
    /* 0x250 */ s32 mIsCleared;     // 1 once room flag (mgr+0xC9) triggers clear
    /* 0x254 */ u32 mSubVariant;    // Unpacked from (spawnParam >> 4) & 0xF
};

extern const f32 lbl_805413F8;
extern const f32 lbl_805413FC;
extern char* lbl_8053AB10;
extern char* lbl_8053AAF8;
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D9FF4(void* rec, u32 a, u32 b);
extern "C" void fn_80136798(void* obj, int id, int arg);
extern "C" void fn_8013CB44(void* handle, f32* pos, s32 a, s32 b, s32 c);
extern "C" JPABaseEmitter* fn_8013CC50(s32 player, f32* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" u8 fn_8023077C();
extern "C" u8 fn_80230534(s32 a);

static inline void sdsmSetPos(SdsmActor* p) {
    char* cam = *(char**)(lbl_8053AB10 + 0x24);
    p->mEffectPos[0] = -*(f32*)(cam + 0x10);
    p->mEffectPos[1] = -*(f32*)(cam + 0x20);
    p->mEffectPos[2] = lbl_805413F8;
}

static inline void sdsmSpawn(SdsmActor* p, s32 a, s32 b, s32 c, s32 d) {
    u32 f = p->mVariantFlags;
    if (f & 1) {
        p->mEmitter = fn_8013CC50(p->mRoomId, p->mEffectPos, lbl_805413FC, a, 1, 1, 0, 0, 1);
    } else if (f & 2) {
        p->mEmitter = fn_8013CC50(p->mRoomId, p->mEffectPos, lbl_805413FC, b, 1, 1, 0, 0, 1);
    } else if (f & 4) {
        p->mEmitter = fn_8013CC50(p->mRoomId, p->mEffectPos, lbl_805413FC, c, 1, 1, 0, 0, 1);
    } else {
        p->mEmitter = fn_8013CC50(p->mRoomId, p->mEffectPos, lbl_805413FC, d, 1, 1, 0, 0, 1);
    }
}

// SDSM update (vtable slot 3)
extern "C" void fn_802ECAD8(SdsmActor* p) {
    sdsmSetPos(p);
    fn_8013CB44(p->mEmitter, p->mEffectPos, 1, 1, 1);
    if (p->mEndCountdown != 0) {
        p->mEndCountdown = p->mEndCountdown - 1;
        if (p->mEndCountdown == 0) {
            fn_80230534(0);
            u32 params = p->mSpawnParam;
            fn_802D9FF4(fn_802D6A9C(), (params >> 8) & 0xf, (params >> 12) & 0xf);
            fn_80136798(lbl_8053AAF8, 0xd, 0);
        }
    } else {
        if (*(s32*)(lbl_8053AAF8 + 0x4c) != 0xb) {
            SdsmMsg m;
            m.id = 0x50079;
            ((SdsmWave*)p->mWaveCtrl)->send(&m);
        }
        if (p->mIsCleared == 0 && *((u8*)fn_802D6A9C() + 0xc9) != 0) {
            p->mIsCleared = 1;
            p->mEmitter->becomeInvalidEmitter();
            p->mEmitter = 0;
            sdsmSpawn(p, 0x3e9, 0x3e8, 0x3e7, 0x3ea);
            p->mEndCountdown = 100;
            fn_8023077C();
            SdsmMsg m2;
            m2.id = 0x400b9;
            ((SdsmWave*)p->mWaveCtrl)->send(&m2);
        }
    }
}

extern "C" void fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int how);
extern void* lbl_804AA280[];

struct NonPolyBase {
    void* pad0;
    void* pad1;
};

struct NotifyTarget : NonPolyBase {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9();
    virtual void Notify(int arg);
};

static inline void NotifySub(void* obj, int arg) {
    if (obj) {
        ((NotifyTarget*)obj)->Notify(arg);
    }
}

extern "C" void* fn_802ECD0C(SdsmActor* this_, short how) {
    if (this_) {
        this_->mVtable = lbl_804AA280;
        void* handle = this_->mEmitter;
        if (handle) {
            fn_801EE434(handle);
        }
        void* sub = this_->mWaveCtrl;
        if (sub) {
            NotifySub(sub, 1);
        }
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

// SDSM init (vtable slot 1)
extern "C" void fn_802ECDA4(SdsmActor* p) {
    p->mVariantFlags = p->mSpawnParam & 0xF;
    p->mSubVariant = (p->mSpawnParam >> 4) & 0xF;
    sdsmSetPos(p);
    sdsmSpawn(p, 0x3e6, 0x3e5, 0x3e4, 0x3eb);
    p->mEndCountdown = 0;
    p->mIsCleared = 0;
    p->mWaveCtrl = new WaveController(0, 0, 8);
}

#undef ALIGN_NEXT
#undef ALIGN_PREV
#undef ARRAY_SIZE
#undef ASM
#undef ATTRIBUTE_ALIGN
#undef IS_ALIGNED
#undef IS_NOT_ALIGNED
#undef MACROS_H
#undef MAX
#undef MIN
#undef NULL
#define NULL 0
#define unknown jsys_unknown
#include "JSystem/JAudio/JASFakeMatchFSA.h"
