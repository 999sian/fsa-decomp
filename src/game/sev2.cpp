// TU 0x802e43e0-0x802e4c74 (actor SEV2).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- Sev2_ClearField_0x280.cpp ----
// SEV2 cluster, part 1/5. Sev2_ClearField_0x280 zeroes this->0x280; Sev2_EmptyHook is an empty override.
extern "C" {
void Sev2_ClearField_0x280(void* thisPtr) { *(s32*)((char*)thisPtr + 0x280) = 0; }
void Sev2_EmptyHook(void) {}
}

// ---- Sev2_dtor_802E47C4.cpp ----
extern "C" void dtor_801F593C(void* this_, int how);
extern "C" void dtor_80084580(void* this_);
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
            dtor_80084580(this_);
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

extern "C" void* fn_8016A3AC(void);

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
