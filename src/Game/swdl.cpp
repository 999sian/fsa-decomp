// TU 0x802f032c-0x802f184c (actor SWDL).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- Swdl_EmptyHook.cpp ----
// Swdl_EmptyHook - SWDL: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void Swdl_EmptyHook(void) {}

}

// ---- Swdl_dtor_802F14B4.cpp ----
extern "C" void fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int how);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
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

#include "JSystem/JAudio/JASFakeMatchFSA.h"
