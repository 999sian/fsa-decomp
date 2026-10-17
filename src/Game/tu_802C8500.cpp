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
    do {
        do {
            idx = fn_801F78F4(fn_801F856C(), 0x4b455930, idx);
            if (idx < 0) {
                return 0;
            }
        } while (idx == *(s32*)(p + 0x198));
        u8* e = fn_801F666C(fn_801F856C(), idx);
        if (e != NULL && *(s32*)(e + 4) == id) {
            f32 vx = *(f32*)(e + 0xc);
            f32 vy = *(f32*)(e + 0x10);
            f32 vz = *(f32*)(e + 0x14);
            if (((u8 (*)(u8*, f32, f32, f32))((*(void***)p)[0x5c / 4]))(p, lbl_80540D58 + *(f32*)(p + 0xc), vx, lbl_80540D58) &&
                ((u8 (*)(u8*, f32, f32, f32))((*(void***)p)[0x5c / 4]))(p, lbl_80540D58 + *(f32*)(p + 0x10), vy, lbl_80540D58) &&
                ((u8 (*)(u8*, f32, f32, f32))((*(void***)p)[0x5c / 4]))(p, *(f32*)(p + 0x14), vz, lbl_80540D58) &&
                fn_802C1970(e, id, p + 0xc)) {
                fn_802C2B64(e);
                return 1;
            }
        }
    } while (1);
}

extern "C" void fn_8013CC50(u32 room, void* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_801F0D20(u8* p, u32 code);
extern "C" void fn_801F0E34(u8* p, u32 code, u32 z);
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 id, f32* pos, u32 arg5, s32 arg6, s32 arg7);
extern u32 lbl_8046D808[];
extern const f32 lbl_80540D5C;
extern const f32 lbl_80540D60;
extern const f32 lbl_80540D64;
extern "C" void fn_802C86A8(u8* p, u8 flag) {
    if (*(u8*)(p + 0x24c) != 0) {
        if (*(s32*)(p + 0x4) >= 8) {
            f32 pos[3];
            pos[0] = lbl_80540D58 + *(f32*)(p + 0xc);
            pos[1] = lbl_80540D58 + *(f32*)(p + 0x10);
            pos[2] = lbl_80540D5C;
            u32 kind = lbl_8046D808[*(s32*)(p + 0x244)];
            Actor_CreateByID(fn_801F856C(), 0x4b4d5249, *(u32*)(p + 0x4), pos, kind, -1, -1);
        } else {
            s32 idx = *(s32*)(p + 0x244);
            if (idx == 0) {
                fn_8013CC50(*(u32*)(p + 0x4), p + 0xc, lbl_80540D60, 0x564, 0, 0, 0, 0, 1);
                fn_8013CC50(*(u32*)(p + 0x4), p + 0xc, lbl_80540D64, 0x503, 1, 0, 0, 0, 1);
            } else if (idx == 1) {
                fn_8013CC50(*(u32*)(p + 0x4), p + 0xc, lbl_80540D64, 0x59, 1, 0, 0, 0, 1);
                fn_8013CC50(*(u32*)(p + 0x4), p + 0xc, lbl_80540D64, 0x5a, 1, 0, 0, 0, 1);
                fn_8013CC50(*(u32*)(p + 0x4), p + 0xc, lbl_80540D64, 0x5b, 1, 0, 0, 0, 1);
            } else if (idx == 2) {
                if (*(s32*)((u8*)fn_802D6A9C() + 0x40) == 0x11) {
                    fn_8013CC50(*(u32*)(p + 0x4), p + 0xc, lbl_80540D64, 0xad, 1, 0, 0, 0, 1);
                    fn_8013CC50(*(u32*)(p + 0x4), p + 0xc, lbl_80540D64, 0xb1, 1, 0, 0, 0, 1);
                    fn_8013CC50(*(u32*)(p + 0x4), p + 0xc, lbl_80540D64, 0xb2, 1, 0, 0, 0, 1);
                } else {
                    fn_8013CC50(*(u32*)(p + 0x4), p + 0xc, lbl_80540D64, 0xad, 1, 0, 0, 0, 1);
                    fn_8013CC50(*(u32*)(p + 0x4), p + 0xc, lbl_80540D64, 0xaf, 1, 0, 0, 0, 1);
                    fn_8013CC50(*(u32*)(p + 0x4), p + 0xc, lbl_80540D64, 0xb0, 1, 0, 0, 0, 1);
                }
            } else if (idx == 3) {
                fn_8013CC50(*(u32*)(p + 0x4), p + 0xc, lbl_80540D64, 0x99, 1, 0, 0, 0, 1);
                fn_8013CC50(*(u32*)(p + 0x4), p + 0xc, lbl_80540D64, 0x9a, 1, 0, 0, 0, 1);
            }
        }
        if (flag == 1) {
            if (*(s32*)(p + 0x240) == 0) {
                fn_801F0E34(p, 0x30003, 0);
            }
            if (*(s32*)(p + 0x240) == 2) {
                fn_801F0D20(p, 0x42);
            }
            if (*(s32*)(p + 0x240) == 3) {
                fn_801F0D20(p, 3);
            }
        }
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

