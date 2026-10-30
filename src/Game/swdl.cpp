// TU 0x802f032c-0x802f184c (actor SWDL).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"

// ---- Swdl_EmptyHook.cpp ----
// Swdl_EmptyHook - SWDL: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void Swdl_EmptyHook(void) {}

extern "C" JGeometry::TVec3<f32>* fn_8023E724(s32 i);
extern "C" void fn_8030C210(void* p, void* pos);
extern "C" s32 fn_80236228(s32 i);
extern "C" s32 fn_8023077C(void);
extern "C" void fn_80230498(s32 i, void* vec, s32 id, s32 a, s32 b, s32 c, s32 d);
extern "C" void* fn_8013CC50(void* obj, void* vec, f32 f, s32 a, s32 b, s32 c, s32 d, s32 e, s32 g);
extern "C" void fn_80134D14(void* p, s32 mode);
extern "C" u8 fn_801B7550(void);
extern "C" s32 fn_8023DE58(s32 i);
extern "C" void fn_8043D67C(void* p, s32 a, s32 b, s32 c);
extern "C" void fn_80230F44(s32 a, s32 b);
extern "C" void fn_80236ED8(s32 a, s32 b);
extern "C" void fn_8045873C(void* p, s32 a);
extern "C" void fn_80128C58(s32 a);
extern "C" u8* lbl_8053AAF8;
extern "C" char* lbl_8053AB10;
extern "C" char* lbl_8053AEC8;
extern "C" void* lbl_8053AF80;
extern "C" void* lbl_8053AED0;
extern "C" const u8 lbl_8046F628[];
extern "C" char lbl_80529DEC[];
extern "C" char lbl_8050EC80[];
extern "C" f32 lbl_80541438;
extern "C" f32 lbl_8054143C;
extern "C" char* fn_802D6A9C();
extern "C" void fn_802D9FF4(void*, s32, s32);
extern "C" void fn_802D6AAC(void*, s32);
extern "C" u8 fn_802DE7CC();
extern "C" u8 fn_80230534(s32);
extern "C" u8 fn_80388EEC(s32);
extern "C" void fn_8038BD08(s32, s32, s32, void*, s32);
extern "C" void fn_8013CB44(void*, void*, s32, s32, s32);
extern "C" void fn_801EE434(void*);
extern "C" void fn_80230FD0(s32,s32);
extern "C" s32 fn_80237810(s32);
extern "C" void fn_80236554(s32,s32,s32);
extern "C" void* fn_80119DD0();
extern "C" void fn_80119468(void*,s32,s32);
extern "C" void fn_80136798(void*,s32,s32);
struct SwdlControlBase { u32 _0, _4; };
struct SwdlControl : SwdlControlBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void command(u32*);
};
static inline u32 Swdl_isPlayer(s32 i) {
    return (lbl_8053AAF8[0x82] & (u8)(1<<i)) != 0;
}
static inline s32 Swdl_isCleared() {
    s32 room=*(s32*)(lbl_80529DEC+0x118);
    s32 layer=*(s32*)(lbl_80529DEC+0x11c);
    if(room<0 || room>7) return 0;
    if(layer<0 || layer>3) return 0;
    return (*(u32*)(lbl_8050EC80 + 0x28 + 200**(s32*)(lbl_8050EC80+0x10)) & (1 << (room*4+layer))) != 0;
}

extern "C" void fn_802F0330(void* this_) {
    u8* p = (u8*)this_;
    s32 i;
    for (i = 0; i < 4; i++) {
        fn_8023E724(i);
    }
    switch (*(s32*)(p + 0x244)) {
    case 0x0:
    case 0x1:
    default:
        break;
    }
}

}

// ---- Swdl_dtor_802F14B4.cpp ----
extern "C" void fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804AA590[];

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

extern "C" void* fn_802F14B4(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AA590;
        for (int i = 0; i < 4; i++) {
            void* h = *(void**)((char*)this_ + 0x234 + i * 4);
            if (h) {
                fn_801EE434(h);
            }
        }
        void* sub = *(void**)((char*)this_ + 0x230);
        if (sub) {
            NotifySub(sub, 1);
        }
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- Swdl_SetParams_802F1574.cpp ----
// fn_802F1574 - SWDL: setParams. Reads the ambient effect group byte and
// mirrors it into this->0x258/0x25c, branches on fn_80237060(0)'s result
// to clear either the "active" flag (0x11c) or a counter (0x244), sets a
// run of paired int/int field defaults (0x234/0x238/0x23c/0x240 = 0,
// 0x264/0x268/0x26c/0x270 = 2), then allocates and placement-constructs
// an owned sub-object at this->0x230 - the same owned-sub-object
// composition pattern (same size 0x5c, same (0,0,8) constructor args) as
// WAVE/SDSM, see Wave_SetParams_802E73B4.cpp for the operator new/delete
// unlock this pattern needed.




class WaveController {
public:
    WaveController(s32 a, s32 b, s32 c);
    ~WaveController();
private:
    unsigned char pad[0x5c];
};

extern "C" u8 Glwp_GetAmbientEffectGroupByte(void);
extern "C" s32 fn_80237060(s32 arg);

extern "C" void Swdl_SetParams(void* this_) {
    char* p = (char*)this_;
    u8 byte = Glwp_GetAmbientEffectGroupByte();
    *(s32*)(p + 0x258) = byte;
    *(s32*)(p + 0x25c) = *(s32*)(p + 0x258);
    s32 r = fn_80237060(0);
    if (r == 2) {
        *(u8*)(p + 0x11c) = 0;
    } else {
        *(s32*)(p + 0x244) = 0;
    }
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x264) = 2;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x268) = 2;
    *(s32*)(p + 0x23c) = 0;
    *(s32*)(p + 0x26c) = 2;
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x270) = 2;
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
