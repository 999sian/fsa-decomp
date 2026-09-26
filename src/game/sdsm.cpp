// TU 0x802ecad4-0x802ed140 (actor SDSM).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- Sdsm_EmptyHook.cpp ----
// Sdsm_EmptyHook - SDSM: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void Sdsm_EmptyHook(void) {}

}

// ---- SDSM shared declarations ----
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
extern const f32 lbl_805413F8;
extern const f32 lbl_805413FC;
extern char* lbl_8053AB10;
extern char* lbl_8053AAF8;
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D9FF4(void* rec, u32 a, u32 b);
extern "C" void fn_80136798(void* obj, int id, int arg);
extern "C" void fn_8013CB44(void* handle, f32* pos, s32 a, s32 b, s32 c);
extern "C" void* fn_8013CC50(s32 player, f32* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" u8 fn_8023077C();
extern "C" u8 fn_80230534(s32 a);

static inline void sdsmSetPos(char* p) {
    char* cam = *(char**)(lbl_8053AB10 + 0x24);
    *(f32*)(p + 0x244) = -*(f32*)(cam + 0x10);
    *(f32*)(p + 0x248) = -*(f32*)(cam + 0x20);
    *(f32*)(p + 0x24c) = lbl_805413F8;
}

static inline void sdsmSpawn(char* p, s32 a, s32 b, s32 c, s32 d) {
    u32 f = *(u32*)(p + 0x23c);
    if (f & 1) {
        *(void**)(p + 0x234) = fn_8013CC50(*(s32*)(p + 0x4), (f32*)(p + 0x244), lbl_805413FC, a, 1, 1, 0, 0, 1);
    } else if (f & 2) {
        *(void**)(p + 0x234) = fn_8013CC50(*(s32*)(p + 0x4), (f32*)(p + 0x244), lbl_805413FC, b, 1, 1, 0, 0, 1);
    } else if (f & 4) {
        *(void**)(p + 0x234) = fn_8013CC50(*(s32*)(p + 0x4), (f32*)(p + 0x244), lbl_805413FC, c, 1, 1, 0, 0, 1);
    } else {
        *(void**)(p + 0x234) = fn_8013CC50(*(s32*)(p + 0x4), (f32*)(p + 0x244), lbl_805413FC, d, 1, 1, 0, 0, 1);
    }
}

// fn_802ECAD8 - SDSM: update(). Keeps the effect at the camera position,
// runs the end countdown, and swaps the effect once the room flag is set.
extern "C" void fn_802ECAD8(char* p) {
    sdsmSetPos(p);
    fn_8013CB44(*(void**)(p + 0x234), (f32*)(p + 0x244), 1, 1, 1);
    if (*(s32*)(p + 0x240) != 0) {
        *(s32*)(p + 0x240) = *(s32*)(p + 0x240) - 1;
        if (*(s32*)(p + 0x240) == 0) {
            fn_80230534(0);
            u32 params = *(u32*)(p + 0x90);
            fn_802D9FF4(fn_802D6A9C(), (params >> 8) & 0xf, (params >> 12) & 0xf);
            fn_80136798(lbl_8053AAF8, 0xd, 0);
        }
    } else {
        if (*(s32*)(lbl_8053AAF8 + 0x4c) != 0xb) {
            SdsmMsg m;
            m.id = 0x50079;
            (*(SdsmWave**)(p + 0x230))->send(&m);
        }
        if (*(s32*)(p + 0x250) == 0 && *((u8*)fn_802D6A9C() + 0xc9) != 0) {
            *(s32*)(p + 0x250) = 1;
            char* h = *(char**)(p + 0x234);
            *(u32*)(h + 0xf4) |= 1;
            *(s32*)(h + 0x24) = 1;
            *(void**)(p + 0x234) = 0;
            sdsmSpawn(p, 0x3e9, 0x3e8, 0x3e7, 0x3ea);
            *(s32*)(p + 0x240) = 100;
            fn_8023077C();
            SdsmMsg m2;
            m2.id = 0x400b9;
            (*(SdsmWave**)(p + 0x230))->send(&m2);
        }
    }
}

// ---- Sdsm_dtor_802ECD0C.cpp ----
extern "C" void fn_801EE434(void* handle);
extern "C" void dtor_801F593C(void* this_, int how);
extern void* lbl_804AA280[];

struct NonPolyBase {
    void* pad0;
    void* pad1;
};

struct NotifyTarget : NonPolyBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void Notify(int arg);
};

static inline void NotifySub(void* obj, int arg) {
    if (obj) {
        ((NotifyTarget*)obj)->Notify(arg);
    }
}

extern "C" void* fn_802ECD0C(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AA280;
        void* handle = *(void**)((char*)this_ + 0x234);
        if (handle) {
            fn_801EE434(handle);
        }
        void* sub = *(void**)((char*)this_ + 0x230);
        if (sub) {
            NotifySub(sub, 1);
        }
        dtor_801F593C(this_, 0);
        if (how > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

// fn_802ECDA4 - SDSM: setParams().
extern "C" void fn_802ECDA4(char* p) {
    *(u32*)(p + 0x23c) = *(u32*)(p + 0x90) & 0xF;
    *(u32*)(p + 0x254) = (*(u32*)(p + 0x90) >> 4) & 0xF;
    sdsmSetPos(p);
    sdsmSpawn(p, 0x3e6, 0x3e5, 0x3e4, 0x3eb);
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x250) = 0;
    *(WaveController**)(p + 0x230) = new WaveController(0, 0, 8);
}

// Shared JAudio pool __sinit (docs/game/sinit_pools.md). Drop the ESD
// macros/typedefs that clash with the JSystem headers first.
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
