#include "types.h"
#include "Game/Actor.h"


extern "C" char lbl_804AB9C0[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_80334318(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804AB9C0;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F78F4(void* m, u32 code, s32 i);
extern "C" void* fn_801F666C(void* m, s32 i);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_801F349C(Actor* a, u32 x, f32* p);
extern const f32 lbl_80541F70;
extern const f32 lbl_80541F74;
extern const f32 lbl_80541F84;
extern const f32 lbl_80541F88;
extern const f32 lbl_80541FA8;
extern const f32 lbl_80541FB0;
extern const f32 lbl_80541FB4;
extern const f32 lbl_80541FD0;
extern const f32 lbl_80541FD4;
extern const f32 lbl_80541FD8;
extern const f32 lbl_80541FDC;
extern const f32 lbl_80541FE0;
extern const f32 lbl_80541FE4;
extern const f32 lbl_80541FE8;
extern const f32 lbl_80541FEC;
extern const f32 lbl_80541FF0;
extern "C" s32 fn_80334378(Actor* a) {
    s32 i = -1;
    u8* e;
    u32 st;
    do {
        do {
            i = fn_801F78F4(fn_801F856C(), 0x57415250, i);
            if (i < 0) {
                goto done;
            }
            e = (u8*)fn_801F666C(fn_801F856C(), i);
        } while (e == 0);
        st = *(u32*)(e + 0x90);
    } while ((u8)st != 7);
    u32 idx = (st >> 24) & 7;
    f32 fx;
    f32 fy;
    if (idx == 0) {
        u8* m = (u8*)fn_802D6A9C();
        fx = *(f32*)(m + 0xcc);
        fy = *(f32*)(m + 0xd0);
    } else {
        fy = lbl_80541F70;
        idx += 7;
        fx = fy;
    }
    f32 pos[3];
    pos[2] = lbl_80541F70;
    pos[0] = lbl_80541F74 + ((f32)((st >> 13) & 0x1f8) + fx);
    pos[1] = lbl_80541F74 + ((f32)((st >> 5) & 0x1f8) + fy);
    fn_801F349C(a, idx, pos);
done:
    return i;
}

extern "C" u16 fn_8022461C(s32 a);
extern "C" s32 fn_80335688(Actor* p, s32 a, s32 b) {
    s32 r = (u16)fn_8022461C(b);
    if (*(s32*)((u8*)p + 0x230) != 3 && (r == 0xc || r == 3 || r == 0xe)) {
        if (*(s32*)((u8*)p + 0x230) != 7) {
            *(s32*)((u8*)p + 0x25c) = 0x1e;
        }
        *(s32*)((u8*)p + 0x230) = 7;
        return 0;
    }
    if (r == 0 || r == 0x22) return 0;
    return 1;
}

