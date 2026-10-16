#include "Game/esd/types.h"
#include "types.h"


extern "C" const f32 lbl_8053F8AC;
extern "C" const f32 lbl_8053F8BC;
extern "C" const f32 lbl_8053F8C0;
extern "C" const f32 lbl_8053F8C4;
extern "C" u8 lbl_8053EFC0;
extern "C" u8 fn_8020609C(u8* p);
extern "C" u8 fn_801F2618(u8* p, u8* q, u8 c);
extern "C" u8 fn_801F2DB4(u8* p, u32 a, u32 b, u32 c);
extern "C" void fn_80205E0C(u8* p, s32 n);
extern "C" void* fn_80204638(void);
extern "C" u8 fn_802064E0(u8* p);
extern "C" u16 fn_8022461C(f32* pos, s32 room);
extern "C" s32 v17__5ActorFiPf(u8* p, s32 a, f32* b);
extern "C" f32 lbl_8053F8A8;
extern "C" s32 fn_80206B30(u8* p1, s32 p2, f32* p3) {
    if (p1[0xc4] != 0 || *(s32*)(p1 + 0x248) == 3) {
        return 0;
    }
    switch (fn_8022461C(p3, p2)) {
    case 0x39:
        return 0;
    case 0x20:
        if (*(u8*)fn_80204638() != 0 || (u8)fn_802064E0(p1)) {
            return 1;
        }
        if (*(s32*)(p1 + 0x248) == 4 && *(f32*)(p1 + 0x14) > lbl_8053F8A8) {
            return 0;
        }
    }
    return v17__5ActorFiPf(p1, p2, p3);
}

extern "C" u8 fn_80206C18(u8* p) {
    u8 ret = 0;
    if (!fn_8020609C(p) && !(*(u32*)(p + 0x230) & 0x1000) &&
        *(f32*)(p + 0x88) - *(f32*)(p + 0x80) > lbl_8053F8AC &&
        *(f32*)(p + 0x8c) - *(f32*)(p + 0x84) > lbl_8053F8AC) {
        ret = fn_801F2618(p, p + 0x264, lbl_8053EFC0);
    }
    return ret;
}

extern "C" s32 fn_801F285C(u8* a, f32* b, u32* c, u32 e, s32 d);
extern "C" u32 fn_801F37AC(u8* a, u32 x, void* p, u32 d, u32 buf, s32 i);
extern "C" u32 fn_8023B6CC(s32 i);
extern "C" void* fn_8023E724(s32 i);
extern "C" void fn_80205E0C(u8* p, s32 type);
extern "C" u8 fn_80206EFC(u8* p) {
    u8 ret = 0;
    s32 i;
    u32 buf;

    if (p[0xc4] == 0 && *(s32*)(p + 0x248) != 3 && *(s32*)(p + 0x248) != 4 &&
        *(f32*)(p + 0x68) - *(f32*)(p + 0x60) > lbl_8053F8AC &&
        *(f32*)(p + 0x6c) - *(f32*)(p + 0x64) > lbl_8053F8AC) {
        for (i = 0; i < 4; i++) {
            if (i == fn_801F285C(p, 0, &buf, 1, i)) {
                fn_8023B6CC(i);
                if ((u8)fn_801F37AC(p, 0, fn_8023E724(i), 0, buf, i)) {
                    ret = 1;
                }
            }
        }
        if (ret) {
            fn_80205E0C(p, 7);
        }
    }
    return ret;
}

extern "C" u8 fn_80207004(u8* p) {
    u8 ret = 0;
    if (p[0xc4] == 0 && *(s32*)(p + 0x248) != 3 && *(s32*)(p + 0x248) != 4 &&
        *(f32*)(p + 0x68) - *(f32*)(p + 0x60) > lbl_8053F8AC &&
        *(f32*)(p + 0x6c) - *(f32*)(p + 0x64) > lbl_8053F8AC) {
        ret = fn_801F2DB4(p, 0x4e554c4c, 0x4e554c4c, 0);
        if (ret) {
            fn_80205E0C(p, 7);
        }
    }
    return ret;
}

extern "C" void fn_802072E4(u8* p) {
    *(f32*)(p + 0x60) = lbl_8053F8BC;
    *(f32*)(p + 0x64) = lbl_8053F8C0;
    *(f32*)(p + 0x68) = lbl_8053F8C4;
    *(f32*)(p + 0x6c) = lbl_8053F8C4;
    *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
    *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
    *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
    *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
}
