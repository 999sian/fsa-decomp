// TU 0x802e43e0-0x802e4c74 (actor SEV2).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- Sev2_ClearField_0x280.cpp ----
// SEV2 cluster, part 1/5. Sev2_ClearField_0x280 zeroes this->0x280; Sev2_EmptyHook is an empty override.
extern "C" {
void Sev2_ClearField_0x280(void* thisPtr) { *(s32*)((char*)thisPtr + 0x280) = 0; }
void Sev2_EmptyHook(void) {}
}

// ---- fn_802E43F0: SEV2 update() ----
// Drives scripted-event globals: pushes an offset copy of the actor position
// into the event manager slots and ramps several byte levels towards their
// configured limits.
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
#include "JSystem/JGeometry/Vec.h"
struct Sev2Msg { u32 id; };
struct Sev2WaveBase { u8 pad[8]; };
struct Sev2Wave : Sev2WaveBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void send(Sev2Msg*);
};
extern const f32 lbl_80541200;
extern const f32 lbl_80541204;
extern char* lbl_8053AAF8;
extern "C" char* fn_801902C0();
extern "C" u8* fn_8016A3AC();

extern "C" void fn_802E43F0(char* p) {
    JGeometry::TVec3<f32> pos(*(JGeometry::TVec3<f32>*)(p + 0xc));
    if (*(u32*)(p + 0x90) & 8) {
        pos.x += lbl_80541200;
    }
    if (*(u32*)(p + 0x90) & 4) {
        pos.x -= lbl_80541200;
    }
    if (*(u32*)(p + 0x90) & 2) {
        pos.y += lbl_80541204;
    }
    if (*(u32*)(p + 0x90) & 1) {
        pos.y -= lbl_80541204;
    }
    if (*(s32*)(p + 0x234) != 0) {
        char* m = fn_801902C0();
        if (*(void**)(m + 0x2b4) != 0 && *(u8*)(m + 0x2c0) == 0) {
            *(u8*)(m + 0x2c0) = 1;
            *(f32*)(m + 0x2a8) = pos.x;
            *(f32*)(m + 0x2ac) = pos.y;
            *(f32*)(m + 0x2b0) = pos.z;
        }
    }
    if (*(s32*)(p + 0x238) != 0) {
        char* m = fn_801902C0();
        if (*(void**)(m + 0x2d0) != 0 && *(u8*)(m + 0x2dc) == 0) {
            *(u8*)(m + 0x2dc) = 1;
            *(f32*)(m + 0x2c4) = pos.x;
            *(f32*)(m + 0x2c8) = pos.y;
            *(f32*)(m + 0x2cc) = pos.z;
        }
    }
    if (*(s32*)(p + 0x23c) != 0) {
        char* m = fn_801902C0();
        s32 n = *(s32*)(m + 0x618);
        if (n < 2) {
            f32* d = (f32*)(m + 0x5f0 + n * 0x14);
            d[0] = pos.x;
            d[1] = pos.y;
            d[2] = pos.z;
            *(s32*)(m + 0x618) = *(s32*)(m + 0x618) + 1;
        }
    }
    if (*(s32*)(p + 0x240) == 0) {
        if (*(u8*)(p + 0x284) != 0) {
            *(u8*)(p + 0x284) = *(u8*)(p + 0x284) - 1;
        }
    } else if (*(u8*)(p + 0x284) < *(s32*)(p + 0x244)) {
        *(u8*)(p + 0x284) = *(u8*)(p + 0x284) + 1;
    }
    fn_8016A3AC()[0x1f2] = *(u8*)(p + 0x284);
    if (*(s32*)(p + 0x248) != 0) {
        { u8* e = fn_8016A3AC(); e[0x1d1] = 1; }
    }
    if (*(s32*)(p + 0x24c) != 0) {
        if (*(s32*)(lbl_8053AAF8 + 0x4c) != 0xb) {
            Sev2Msg msg;
            msg.id = 0x50078;
            (*(Sev2Wave**)(p + 0x230))->send(&msg);
        }
        { u8* e = fn_8016A3AC(); e[0x1d2] = 1; }
    }
    if (*(s32*)(p + 0x250) != 0) {
        { u8* e = fn_8016A3AC(); e[0x1d3] = 1; }
    }
    if (*(s32*)(p + 0x254) == 0) {
        if (*(u8*)(p + 0x285) != 0) {
            *(u8*)(p + 0x285) = *(u8*)(p + 0x285) - 1;
        }
    } else if (*(u8*)(p + 0x285) < *(s32*)(p + 0x258)) {
        *(u8*)(p + 0x285) = *(u8*)(p + 0x285) + 1;
    }
    fn_8016A3AC()[0x1f3] = *(u8*)(p + 0x285);
    if (*(s32*)(p + 0x25c) != 0) {
        u8* e = fn_8016A3AC();
        if (*(s32*)(e + 0x1d8) < 0) {
            *(s32*)(e + 0x1d8) = 0x100;
        }
    }
    if (*(s32*)(p + 0x260) != 0) {
        { u8* e = fn_8016A3AC(); e[0x1dc] = 1; }
    }
    if (*(s32*)(p + 0x264) != 0) {
        { u8* e = fn_8016A3AC(); e[0x1ca] = 1; }
    }
    if (*(s32*)(p + 0x268) == 0) {
        *(u8*)(p + 0x286) = 0;
    } else if (*(u8*)(p + 0x286) < *(s32*)(p + 0x26c)) {
        *(u8*)(p + 0x286) = *(u8*)(p + 0x286) + 1;
    }
    fn_8016A3AC()[0x1f4] = *(u8*)(p + 0x286);
    if (*(s32*)(p + 0x270) == 0) {
        if (*(u8*)(p + 0x287) != 0) {
            *(u8*)(p + 0x287) = *(u8*)(p + 0x287) - 1;
        }
    } else if (*(u8*)(p + 0x287) < *(s32*)(p + 0x274)) {
        *(u8*)(p + 0x287) = *(u8*)(p + 0x287) + 1;
    }
    fn_8016A3AC()[0x1f5] = *(u8*)(p + 0x287);
    if (*(s32*)(p + 0x278) != 0) {
        u8* e = fn_8016A3AC();
        e[0x1cf] = 1;
        e[0x1d0] = 0;
    }
    if (*(s32*)(p + 0x27c) != 0) {
        { u8* e = fn_8016A3AC(); e[0x1dd] = 1; }
    }
    if (*(s32*)(p + 0x280) == 0) {
        if (*(u8*)(p + 0x288) != 0) {
            *(u8*)(p + 0x288) = *(u8*)(p + 0x288) - 1;
        }
    }
    fn_8016A3AC()[0x1ef] = *(u8*)(p + 0x288);
}

// ---- Sev2_dtor_802E47C4.cpp ----
extern "C" void dtor_801F593C(void* this_, int how);
extern void* lbl_804A9CD0[];

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

extern "C" void* Sev2_dtor(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804A9CD0;
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

// ---- Sev2_Part4of5_802E484C.cpp ----
// SEV2 cluster, part 4/5. Unpacks 16 single-bit flags from this->0x90 into
// individual s32 fields (0x234-0x280), mirrors 5 byte fields to/from a
// shared global resource (fn_8016A3AC(), re-fetched fresh for every
// individual read/write rather than cached), conditionally overrides 5
// paired fields, allocates+constructs the same owned sub-object pattern as
// Wave_SetParams_802E73B4.cpp, then dispatches through this actor's own
// vtable slot 5 (byte offset 0x14).





class WaveController {
public:
    WaveController(s32 a, s32 b, s32 c);
    ~WaveController();
private:
    unsigned char pad[0x5c];
};


extern "C" void Sev2_Part4of5(void* this_) {
    char* p = (char*)this_;
    *(s32*)(p + 0x234) = (*(u32*)(p + 0x90) >> 26) & 1;
    *(s32*)(p + 0x238) = (*(u32*)(p + 0x90) >> 25) & 1;
    *(s32*)(p + 0x23c) = (*(u32*)(p + 0x90) >> 24) & 1;
    *(s32*)(p + 0x240) = (*(u32*)(p + 0x90) >> 23) & 1;
    *(s32*)(p + 0x248) = (*(u32*)(p + 0x90) >> 22) & 1;
    *(s32*)(p + 0x24c) = (*(u32*)(p + 0x90) >> 21) & 1;
    *(s32*)(p + 0x250) = (*(u32*)(p + 0x90) >> 20) & 1;
    *(s32*)(p + 0x254) = (*(u32*)(p + 0x90) >> 19) & 1;
    *(s32*)(p + 0x25c) = (*(u32*)(p + 0x90) >> 18) & 1;
    *(s32*)(p + 0x260) = (*(u32*)(p + 0x90) >> 17) & 1;
    *(s32*)(p + 0x264) = (*(u32*)(p + 0x90) >> 16) & 1;
    *(s32*)(p + 0x268) = (*(u32*)(p + 0x90) >> 15) & 1;
    *(s32*)(p + 0x270) = (*(u32*)(p + 0x90) >> 14) & 1;
    *(s32*)(p + 0x278) = (*(u32*)(p + 0x90) >> 13) & 1;
    *(s32*)(p + 0x27c) = (*(u32*)(p + 0x90) >> 12) & 1;
    *(s32*)(p + 0x280) = (*(u32*)(p + 0x90) >> 11) & 1;

    *(u8*)(p + 0x284) = *(u8*)((char*)fn_8016A3AC() + 0x1f2);
    if (*(s32*)(p + 0x240) != 0) {
        *(s32*)(p + 0x244) = 0xff;
    }
    *(u8*)((char*)fn_8016A3AC() + 0x1f2) = *(u8*)(p + 0x284);

    *(u8*)(p + 0x285) = *(u8*)((char*)fn_8016A3AC() + 0x1f3);
    if (*(s32*)(p + 0x254) != 0) {
        *(s32*)(p + 0x258) = 0xff;
    }
    *(u8*)((char*)fn_8016A3AC() + 0x1f3) = *(u8*)(p + 0x285);

    *(u8*)(p + 0x286) = *(u8*)((char*)fn_8016A3AC() + 0x1f4);
    if (*(s32*)(p + 0x268) != 0) {
        *(s32*)(p + 0x26c) = 0xff;
    }
    *(u8*)((char*)fn_8016A3AC() + 0x1f4) = *(u8*)(p + 0x286);

    *(u8*)(p + 0x287) = *(u8*)((char*)fn_8016A3AC() + 0x1f5);
    if (*(s32*)(p + 0x270) != 0) {
        *(s32*)(p + 0x274) = 0xff;
    }
    *(u8*)((char*)fn_8016A3AC() + 0x1f5) = *(u8*)(p + 0x287);

    *(u8*)(p + 0x288) = *(u8*)((char*)fn_8016A3AC() + 0x1ef);
    if (*(s32*)(p + 0x280) != 0) {
        *(u8*)(p + 0x288) = 0xff;
    }
    *(u8*)((char*)fn_8016A3AC() + 0x1ef) = *(u8*)(p + 0x288);

    *(WaveController**)(p + 0x230) = new WaveController(0, 0, 8);

    // Real C++ ->method() virtual dispatch (not a manual vtable[]
    // index) is required here so MWCC reuses one register for the
    // vtable-fetch-then-funcptr-fetch chain, matching retail exactly.
    struct ActorSlot5 {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void update();
    };
    ((ActorSlot5*)this_)->update();
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
