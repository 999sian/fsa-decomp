#include "Game/Actor.h"
#include "Game/SinitPoolChain.h"


extern "C" char lbl_804ABA90[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void fn_801EE434(void* handle);
extern "C" void fn_80336294(void) {
}

extern "C" void* fn_8020D58C(void);
extern "C" u8 fn_8020D6AC(void* entry, int a, f32* b, s32 d, int e);
extern "C" u16 fn_8022461C(void* a, s32 b);
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802265DC(f32* b, int a, int c);
extern "C" u8 fn_80336C44(Actor* a, s32 b, f32* c) {
    u32 unk = *(u32*)((u8*)a + 0x198);
    u8* base = (u8*)fn_8020D58C();
    if (fn_8020D6AC(base + base[1] * 0x784 + 4, b, c, unk, 0) == 1) {
        return 1;
    }
    s32 code = fn_8022461C(c, b);
    if (code == 0 || code == 2 || code == 0x50 || code == 0x39 || code == 0xd || code == 0x61) {
        return 0;
    }
    if (code == 0x22 && ((u8*)fn_802D6A9C())[0x170] == 0) {
        return 0;
    }
    if (code == 0x25 && ((u8*)fn_802D6A9C())[0x171] == 0) {
        return 0;
    }
    if (code == 4) {
        if (((int)c[1] & 0xf) >= 8) {
            return 0;
        }
    } else if (code == 5) {
        if (((int)c[1] & 0xf) < 8) {
            return 0;
        }
    } else if (code == 6) {
        if (((int)c[0] & 0xf) >= 8) {
            return 0;
        }
    } else if (code == 7) {
        if (((int)c[0] & 0xf) < 8) {
            return 0;
        }
    }
    return fn_802265DC(c, b, 1);
}

extern "C" Actor* fn_80337010(Actor* p, s16 n) {
    if (p != 0) {
        *(void**)p = lbl_804ABA90;
        for (int i = 0; i < 4; i++) {
            fn_801EE434(*(void**)((u8*)p + 0x2a0 + i * 4));
            fn_801EE434(*(void**)((u8*)p + 0x2b0 + i * 4));
        }
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

