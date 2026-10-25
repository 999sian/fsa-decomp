// TU 0x802e0ab4-0x802e1b40 (actor PRTC).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

extern "C" u8 fn_802DEBA0(void);

class WaveController {
public:
    WaveController(s32 a, s32 b, s32 c);
    ~WaveController();
private:
    unsigned char pad[0x5c];
};

extern "C" void fn_801F0E34(void* this_, u32 code, u32 z);
extern "C" void* fn_8013CC50(s32 room, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);

static inline void* PrtcSpawn(char* p, s32 id, s32 a) {
    f32 pos[3];
    pos[1] = *(f32*)(p + 0x10) + *(f32*)(p + 0x248);
    pos[0] = *(f32*)(p + 0xc) + *(f32*)(p + 0x244);
    pos[2] = 0.0f;
    return fn_8013CC50(*(s32*)(p + 4), pos, id, a, 0, 0, 0, 1, 1.0f);
}

extern f32 lbl_805411A8;
extern f32 lbl_805411AC;

static inline void* PrtcSpawnA(char* p, s32 id) {
    f32 pos[3];
    f32 x = *(f32*)(p + 0xc);
    f32 y = *(f32*)(p + 0x10);
    f32 x2 = *(f32*)(p + 0x244);
    f32 y2 = *(f32*)(p + 0x248);
    pos[0] = x + x2;
    pos[1] = y + y2;
    pos[2] = 0.0f;
    return fn_8013CC50(*(s32*)(p + 4), pos, id, *(s32*)(p + 0x254), 0, 0, 0, 1, lbl_805411AC);
}

static inline void PrtcNotify(char* p) {
    s32 code = 0x30074;
    void* obj = *(void**)(p + 0x230);
    ((void (*)(void*, s32*))(*(void***)((char*)obj + 8))[5])(obj, &code);
}

static inline void PrtcNotifyCheck(char* p) {
    s32 phase = *(s32*)(p + 0x250);
    if (phase != 7) {
        if (phase < 7) {
            if (phase >= 6) {
                PrtcNotify(p);
            }
        } else if (phase <= 8) {
            PrtcNotify(p);
        }
    }
}

extern "C" void fn_801F0E34(void* this_, u32 code, u32 z);
extern "C" void* fn_8013CC50(s32 room, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);

// ---- Prtc_EmptyHook.cpp ----
// PRTC (vtable lbl_804A9AC8, ctor fn_80201E80) cluster, part 1/4. No
// separate leading static-init this time - PRTC's cluster begins
// immediately after URAC's tail static-init. Prtc_EmptyHook - empty
// override (bare blr), no extab.
extern "C" {

void Prtc_EmptyHook(void) {}

extern "C" void fn_802E0AB8(void* this_) {
    char* p = (char*)this_;
    if (*(s32*)(p + 0x250) <= 1) {
        fn_801F0E34(this_, 0x30033, 0);
    }
    s32 state = *(s32*)(p + 0x240);
    if (state == 1) {
    } else if (state > 1) {
        return;
    } else if (state < 0) {
        return;
    } else if (!((u8 (*)(void*))(*(void***)this_)[13])(this_)) {
        return;
    } else {
        switch (*(s32*)(p + 0x250)) {
        case 0:
            *(void**)(p + 0x234) = PrtcSpawnA(p, 0x188);
            *(void**)(p + 0x238) = PrtcSpawnA(p, 0x189);
            *(void**)(p + 0x23c) = PrtcSpawnA(p, 0x18a);
            break;
        case 1:
            *(void**)(p + 0x234) = PrtcSpawnA(p, 0x18b);
            *(void**)(p + 0x238) = PrtcSpawnA(p, 0x18c);
            *(void**)(p + 0x23c) = PrtcSpawnA(p, 0x18d);
            break;
        case 2:
            *(void**)(p + 0x234) = PrtcSpawnA(p, 0x552);
            break;
        case 3:
            *(void**)(p + 0x234) = PrtcSpawnA(p, 0x17e);
            break;
        case 4:
            *(void**)(p + 0x234) = PrtcSpawnA(p, 0x17f);
            break;
        case 5:
            *(void**)(p + 0x234) = PrtcSpawnA(p, 0x180);
            break;
        case 6:
            *(void**)(p + 0x234) = PrtcSpawnA(p, 0x6e);
            break;
        case 7:
            *(void**)(p + 0x234) = PrtcSpawn(p, 0xa9, -1);
            *(void**)(p + 0x238) = PrtcSpawnA(p, 0xaa);
            break;
        case 8:
            *(void**)(p + 0x234) = PrtcSpawnA(p, 0x6f);
            *(s32*)(p + 0x240) = 1;
            return;
        }
    }
    s32 phase = *(s32*)(p + 0x250);
    if (phase == 6 || phase == 8) {
        PrtcNotify(p);
    }
}

}

// ---- Prtc_dtor_802E1064.cpp ----
extern "C" void fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804A9AC8[];

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
    virtual void v5(void* arg);
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

extern "C" void* Prtc_dtor(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804A9AC8;
        void* h0 = *(void**)((char*)this_ + 0x234);
        if (h0) {
            fn_801EE434(h0);
        }
        void* h1 = *(void**)((char*)this_ + 0x238);
        if (h1) {
            fn_801EE434(h1);
        }
        void* h2 = *(void**)((char*)this_ + 0x23c);
        if (h2) {
            fn_801EE434(h2);
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

extern "C" void fn_802E111C(void* this_) {
    char* p = (char*)this_;
    *(s32*)(p + 0x250) = *(s32*)(p + 0x90) & 0xff;
    *(s32*)(p + 0x258) = (*(s32*)(p + 0x90) >> 12) & 0xf;
    *(s32*)(p + 0x254) = (*(s32*)(p + 0x90) >> 16) & 0xf;
    *(s32*)(p + 0x25c) = (*(s32*)(p + 0x90) >> 20) & 0xf;
    *(s32*)(p + 0x254) = 1;
    if (fn_802DEBA0()) {
        if (*(s32*)(p + 0x250) == 9) {
            *(s32*)(p + 0x254) = 0;
        }
    }
    if (*(s32*)(p + 0x90) & 0x4000000) {
        *(u8*)(p + 0x260) = 1;
    } else {
        *(u8*)(p + 0x260) = 0;
    }
    *(f32*)(p + 0x244) = 0.0f;
    *(f32*)(p + 0x248) = 0.0f;
    *(f32*)(p + 0x24c) = 0.0f;
    if (*(s32*)(p + 0x90) & 0x800) {
        *(f32*)(p + 0x244) = *(f32*)(p + 0x244) + 512.0f;
    }
    if (*(s32*)(p + 0x90) & 0x400) {
        *(f32*)(p + 0x244) = *(f32*)(p + 0x244) - 512.0f;
    }
    if (*(s32*)(p + 0x90) & 0x200) {
        *(f32*)(p + 0x248) = *(f32*)(p + 0x248) + 384.0f;
    }
    if (*(s32*)(p + 0x90) & 0x100) {
        *(f32*)(p + 0x248) = *(f32*)(p + 0x248) - 384.0f;
    }
    *(void**)(p + 0x234) = 0;
    *(void**)(p + 0x238) = 0;
    *(void**)(p + 0x23c) = 0;
    if (*(s32*)(p + 0x25c) == 0) {
        switch (*(s32*)(p + 0x250)) {
        case 0:
            *(void**)(p + 0x234) = PrtcSpawn(p, 0x188, *(s32*)(p + 0x254));
            *(void**)(p + 0x238) = PrtcSpawn(p, 0x189, *(s32*)(p + 0x254));
            *(void**)(p + 0x23c) = PrtcSpawn(p, 0x18a, *(s32*)(p + 0x254));
            break;
        case 1:
            *(void**)(p + 0x234) = PrtcSpawn(p, 0x18b, *(s32*)(p + 0x254));
            *(void**)(p + 0x238) = PrtcSpawn(p, 0x18c, *(s32*)(p + 0x254));
            *(void**)(p + 0x23c) = PrtcSpawn(p, 0x18d, *(s32*)(p + 0x254));
            break;
        case 2:
            *(void**)(p + 0x234) = PrtcSpawn(p, 0x552, *(s32*)(p + 0x254));
            break;
        case 3:
            *(void**)(p + 0x234) = PrtcSpawn(p, 0x17e, *(s32*)(p + 0x254));
            break;
        case 4:
            *(void**)(p + 0x234) = PrtcSpawn(p, 0x17f, *(s32*)(p + 0x254));
            break;
        case 5:
            *(void**)(p + 0x234) = PrtcSpawn(p, 0x180, *(s32*)(p + 0x254));
            break;
        case 6:
            *(void**)(p + 0x234) = PrtcSpawn(p, 0x6e, *(s32*)(p + 0x254));
            break;
        case 7:
            *(void**)(p + 0x234) = PrtcSpawn(p, 0xa9, -1);
            *(void**)(p + 0x238) = PrtcSpawn(p, 0xaa, *(s32*)(p + 0x254));
            break;
        case 8:
            *(void**)(p + 0x234) = PrtcSpawn(p, 0x6f, *(s32*)(p + 0x254));
            break;
        case 9:
            *(void**)(p + 0x234) = PrtcSpawn(p, 0x185, *(s32*)(p + 0x254));
            *(void**)(p + 0x238) = PrtcSpawn(p, 0x186, *(s32*)(p + 0x254));
            *(void**)(p + 0x23c) = PrtcSpawn(p, 0x187, *(s32*)(p + 0x254));
            break;
        case 10:
            *(void**)(p + 0x234) = PrtcSpawn(p, 0x88, -1);
            *(void**)(p + 0x238) = PrtcSpawn(p, 0x89, *(s32*)(p + 0x254));
            break;
        }
        *(s32*)(p + 0x240) = 1;
    } else {
        *(s32*)(p + 0x240) = 0;
    }
    WaveController* wc = new WaveController(0, 0, 8);
    *(WaveController**)(p + 0x230) = wc;
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
