#include "Game/Actor.h"


extern "C" char lbl_804AC100[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_803397C0(Actor* p, s16 n) {
    if (p != 0) {
        *(void**)p = lbl_804AC100;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void* fn_8020D58C(void);
extern "C" u8 fn_8020D6AC(u8* p, s32 a, f32* b, s32 c, s32 d);
extern "C" u16 fn_8022461C(f32* a, s32 b);
extern "C" void* fn_802D6A9C(void);
extern "C" BOOL fn_8033B7FC(Actor* self, s32 a, f32* b) {
    s32 region = self->field_198;
    u8* base = static_cast<u8*>(fn_8020D58C());
    if (fn_8020D6AC(base + base[1] * 0x784 + 4, a, b, region, 0) == 1) {
        return 1;
    }
    u16 code = fn_8022461C(b, a);
    if (code == 0 || code == 2 || code == 0x50) {
        return 0;
    }
    if (code == 0x22 && static_cast<u8*>(fn_802D6A9C())[0x170] == 0) {
        return 0;
    }
    if (code == 0x39) {
        return 0;
    }
    if (code == 0x25 && static_cast<u8*>(fn_802D6A9C())[0x171] == 0) {
        return 0;
    }
    if (code == 4) {
        if (((s32)b[1] & 0xf) >= 8) {
            return 0;
        }
    } else if (code == 5) {
        if (((s32)b[1] & 0xf) < 8) {
            return 0;
        }
    } else if (code == 6) {
        if (((s32)b[0] & 0xf) >= 8) {
            return 0;
        }
    } else if (code == 7) {
        if (((s32)b[0] & 0xf) < 8) {
            return 0;
        }
    } else if (code == 3 || code == 0xe || code == 0xd) {
        return 0;
    }
    return 1;
}

extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F78F4(void* mgr, u32 code, s32 idx);
extern "C" u8* fn_801F666C(void* mgr, s32 idx);
extern "C" void fn_8033B9D8(u8* self) {
    s32 idx = -1;
    s32 best = 0;
    u8* obj;
    s32 v;

    for (;;) {
        idx = fn_801F78F4(fn_801F856C(), 0x464c594f, idx);
        if (idx < 0) {
            break;
        }
        obj = fn_801F666C(fn_801F856C(), idx);
        if (obj == 0) {
            continue;
        }
        if (*(s32*)(obj + 0x230) == 0 || *(s32*)(obj + 0x230) == 4) {
            v = *(s32*)(obj + 0x248);
        } else {
            v = 0xfff;
        }
        if (v < *(s32*)(self + 0x26c)) {
            *(s32*)(self + 0x26c) = v;
        }
        if (best < v && v < *(s32*)(self + 0x244)) {
            best = v;
        }
    }
    if (*(s32*)(self + 0x26c) == *(s32*)(self + 0x244)) {
        *(u8*)(self + 0x278) = 1;
    }
    if (best != 0) {
        *(s32*)(self + 0x274) = *(s32*)(self + 0x244) - best;
    }
}

