#include "Game/esd/types.h"

extern "C" void* fn_802D6A9C(void);
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F78F4(void* mgr, u32 tag, s32 idx);
extern "C" u8* fn_801F666C(void* mgr, s32 idx);
extern "C" u8 fn_802C1970(u8* p, s32 room, void* pos);
extern "C" void fn_802C2B64(u8* p);
extern const f32 lbl_80540D58;

extern "C" s32 fn_802C8500(f32 a, f32 b, f32 c) {
    f32 d = a - b;
    if (d >= -c && d <= c) {
        return 1;
    }
    return 0;
}

extern "C" s32 fn_802C8530(u8* p) {
    s32 idx = -1;
    s32 id = *(s32*)(p + 4);
    if (*((u8*)fn_802D6A9C() + id + 0x131df) != 0) {
        return 0;
    }
    for (;;) {
        do {
            idx = fn_801F78F4(fn_801F856C(), 0x4b455930, idx);
            if (idx < 0) {
                return 0;
            }
        } while (idx == *(s32*)(p + 0x198));
        u8* e = fn_801F666C(fn_801F856C(), idx);
        if (e == NULL) {
            continue;
        }
        if (*(s32*)(e + 4) != id) {
            continue;
        }
        f32 vx = *(f32*)(e + 0xc);
        f32 vy = *(f32*)(e + 0x10);
        f32 vz = *(f32*)(e + 0x14);
        if (!((u8 (*)(u8*, f32, f32, f32))((*(void***)p)[0x5c / 4]))(p, lbl_80540D58 + *(f32*)(p + 0xc), vx, lbl_80540D58)) {
            continue;
        }
        if (!((u8 (*)(u8*, f32, f32, f32))((*(void***)p)[0x5c / 4]))(p, lbl_80540D58 + *(f32*)(p + 0x10), vy, lbl_80540D58)) {
            continue;
        }
        if (!((u8 (*)(u8*, f32, f32, f32))((*(void***)p)[0x5c / 4]))(p, *(f32*)(p + 0x14), vz, lbl_80540D58)) {
            continue;
        }
        if (!fn_802C1970(e, id, p + 0xc)) {
            continue;
        }
        fn_802C2B64(e);
        return 1;
    }
}

extern "C" void fn_802C89F8(void) {}

extern "C" void* fn_802D6A9C(void);
extern "C" void __dt__5ActorFv(void* this_, s32 flag);
extern "C" s32 fn_80226BC4(f32* pos, u32 id);
extern "C" s32 fn_802D4C10(void* mgr, u32 id, u16 idx);
extern "C" void fn_802D7D00(void* mgr, u32 id, s32 idx, s32 flag);
extern char lbl_804A8E40[];
extern "C" u8* fn_802C8E60(u8* p, s16 n) {
    if (p != NULL) {
        *(void**)p = lbl_804A8E40;
        if (*(s32*)(p + 0x23c) == 2) {
            f32 pos[2];
            f32 y = *(f32*)(p + 0x10);
            f32 x = *(f32*)(p + 0xc);
            pos[0] = x;
            pos[1] = y;
            s32 idx = fn_80226BC4(pos, *(u32*)(p + 0x4));
            s32 slot = fn_802D4C10(fn_802D6A9C(), *(u32*)(p + 0x4), (u16)idx);
            if (slot != -1) {
                fn_802D7D00(fn_802D6A9C(), *(u32*)(p + 0x4), slot, 0);
            }
        }
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void fn_802C9284(u8* p) {
    *(u32*)(p + 0x234) = *(u32*)(p + 0x90) & 0x3ff;
    *(u32*)(p + 0x238) = (*(u32*)(p + 0x90) >> 16) & 0xf;
    *(u32*)(p + 0x23c) = (*(u32*)(p + 0x90) >> 20) & 0x7;
    *(u32*)(p + 0x240) = (*(u32*)(p + 0x90) >> 23) & 0x7;
    *(u32*)(p + 0x244) = (*(u32*)(p + 0x90) >> 12) & 0xf;
    *(u32*)(p + 0x248) = (*(u32*)(p + 0x90) >> 10) & 0x3;
}

