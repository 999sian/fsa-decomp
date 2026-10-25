#include "Game/esd/types.h"
#include "types.h"
#include "JSystem/JGeometry/Vec.h"


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
extern "C" const f32 lbl_8053F8B0;
extern "C" const f32 lbl_8053F8B4;
extern "C" const f32 lbl_8053F8B8;
extern "C" u8 lbl_8046A238[];
extern "C" u8 fn_801F2740(u8* p, s32 n);
extern "C" void fn_801F3128(u8* p, f32* out);
extern "C" u8 fn_801F329C(u8* p, s32 i);
extern "C" void fn_801CD0D0(f32* a, f32* b);
extern "C" void fn_801F31C4(u8* p, f32* out);
extern "C" void fn_802397B4(f32* a, void* b, s32 c);
extern "C" void fn_80238548(s32 i, s32 n, f32* v, s32 t);
extern "C" void fn_801D2978(u8* p, f32* v, f32 f, void* q, s32 n);
extern "C" void* fn_8023E724(s32 i);
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

extern "C" u8 fn_80206CA8(u8* p) {
    u8 ret = 0;
    s32 i;
    f32 out2[2];
    f32 rect[4];
    f32 v3[3];
    f32 pos[2];
    f32 v8[2];
    f32 s60, s64, s68, s6c;

    if (p[0xc4] == 0 && *(f32*)(p + 0x68) - *(f32*)(p + 0x60) > lbl_8053F8AC &&
        *(f32*)(p + 0x6c) - *(f32*)(p + 0x64) > lbl_8053F8AC && !fn_802064E0(p)) {
        switch (*(s32*)(p + 0x248)) {
        case 2:
            s60 = *(f32*)(p + 0x60);
            s64 = *(f32*)(p + 0x64);
            s68 = *(f32*)(p + 0x68);
            s6c = *(f32*)(p + 0x6c);
            *(f32*)(p + 0x60) = lbl_8053F8B0;
            *(f32*)(p + 0x64) = lbl_8053F8B4;
            *(f32*)(p + 0x68) = lbl_8053F8B8;
            *(f32*)(p + 0x6c) = lbl_8053F8B8;
            ret = fn_801F2740(p, -1);
            *(f32*)(p + 0x60) = s60;
            *(f32*)(p + 0x64) = s64;
            *(f32*)(p + 0x68) = s68;
            *(f32*)(p + 0x6c) = s6c;
            if (ret != 0) {
                fn_801F3128(p, pos);
                for (i = 0; i < 4; i++) {
                    if ((u8)ret & (1 << i)) {
                        if (fn_801F329C(p, i)) {
                            v3[0] = pos[0];
                            v3[1] = pos[1];
                            v3[2] = lbl_8053F8AC;
                            fn_801CD0D0(v3, out2);
                            v8[0] = out2[0];
                            v8[1] = out2[1];
                        } else {
                            v8[0] = pos[0];
                            v8[1] = pos[1];
                        }
                        fn_80238548(i, 0, v8, *(s32*)(lbl_8046A238 + *(s32*)(p + 0x350) * 0x14 + 8));
                        if (*(s32*)(p + 0x248) != 5) {
                            fn_801D2978(p + 0x35c, v8, lbl_8053F8A8, fn_8023E724(i), 0x18);
                            fn_80205E0C(p, 5);
                        }
                    }
                }
            }
            break;
        case 3:
        case 4:
        case 9:
            break;
        default:
            fn_801F31C4(p, rect);
            fn_802397B4(rect, *(void**)(p + 4), *(s32*)(p + 0x198));
            break;
        }
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

extern "C" void fn_801F317C(void* p, void* box);
extern "C" s32 fn_8023AE34(void* box, s32 room, void* info);
extern "C" s32 fn_8023AA18(void* box, s32 room, void* info);
extern "C" s32 fn_8023AC74(void* box, s32 room, void* info);
extern "C" s32 fn_8023AD54(void* box, s32 room, void* info);
extern "C" u8 fn_801CC820(s32 idx, JGeometry::TVec3f* off);
extern "C" u8 fn_801CC538(s32 idx, void* info, JGeometry::TVec3f* out, s32* id);
extern "C" void fn_801CC640(s32 idx, s32* id, JGeometry::TVec3f* off);
extern "C" void fn_801C3B7C(void* p, s32 st);
extern "C" s32 fn_802070B4(u8* p) {
    if (p[0xc4] != 0 || *(s32*)(p + 0x248) == 3 || *(s32*)(p + 0x248) == 4 ||
        *(f32*)(p + 0x78) - *(f32*)(p + 0x70) <= lbl_8053F8AC ||
        *(f32*)(p + 0x7c) - *(f32*)(p + 0x74) <= lbl_8053F8AC) {
        return 0;
    }
    s32 idx;
    s32 id = -1;
    u32 info[2];
    JGeometry::TVec3f alt;
    JGeometry::TVec3f off;
    u32 box[4];
    off.set(lbl_8053F8AC, lbl_8053F8AC, lbl_8053F8AC);
    u8 useOff = 0;
    u8 isB = 0;
    u8 isC = 0;
    fn_801F317C(p, box);
    idx = fn_8023AE34(box, *(s32*)(p + 0x4), info);
    if (idx >= 0) {
        useOff = fn_801CC820(idx, &off);
    } else if ((idx = fn_8023AA18(box, *(s32*)(p + 0x4), info)) >= 0) {
        isB = 1;
    } else if ((idx = fn_8023AC74(box, *(s32*)(p + 0x4), info)) >= 0) {
        isC = fn_801CC538(idx, info, &alt, &id);
    } else if ((idx = fn_8023AD54(box, *(s32*)(p + 0x4), info)) >= 0) {
        fn_801CC640(idx, &id, &off);
    }
    s32 r = 0;
    if (idx >= 0) {
        JGeometry::TVec3f d(*(JGeometry::TVec3f*)fn_8023E724(idx));
        s32 mode = 0;
        if (isB) {
            mode = 4;
        } else if (isC) {
            d.set(alt);
        } else {
            d.set(*(JGeometry::TVec3f*)(p + 0xc) - off);
            if (useOff) {
                mode = 3;
            }
        }
        r = fn_801F37AC(p, 0, &d, 0, mode, idx);
        if ((u8)r) {
            fn_80205E0C(p, 7);
        }
    }
    return r;
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
