#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JGeometry/Util.h"
#include "JSystem/JMath/JMath.h"

extern "C" void fn_801F0E34(void* self, u32 id, s32 b);
extern "C" u8 fn_8022F514(s32);
extern "C" s32 fn_8022CAF8(s32);
extern "C" void* fn_8023E724(s32);
extern "C" s32 fn_8022F3DC(s32);
extern const f32 lbl_80542618;
extern const f32 lbl_80542604;
extern "C" char lbl_8050ADF8[];
extern "C" char lbl_8050AE38[];
extern const f32 lbl_8054261C;
extern const f64 lbl_805425F8;
extern const f32 lbl_805425D8;
extern const f32 lbl_805425DC;
extern const f32 lbl_805425E0;
extern const f32 lbl_805425E4;
extern const f32 lbl_805425E8;
extern const f32 lbl_805425EC;
extern const f32 lbl_805425F0;
extern const f32 lbl_80542600;

struct Actor {
    ~Actor();
};

extern "C" void __dt__5ActorFv(Actor* self, s16 flag);
extern u8 lbl_804ACA00[];
void operator delete(void* p);

extern "C" Actor* fn_8034EDDC(Actor* self, s16 flag) {
    if (self != 0) {
        *(u8**)self = lbl_804ACA00;
        __dt__5ActorFv(self, 0);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}

extern "C" void fn_8035001C(u8* self, u32 kind) {
    f32 x;

    switch (kind) {
    case 0:
        x = (f32)*(s32*)(self + 0x260);
        *(f32*)(self + 0x3c) = lbl_80542600 * x;
        *(f32*)(self + 0x40) = lbl_805425D8;
        *(f32*)(self + 0x44) = lbl_805425D8;
        break;
    case 1:
        x = (f32)*(s32*)(self + 0x260);
        *(f32*)(self + 0x3c) = lbl_80542600 * -x;
        *(f32*)(self + 0x40) = lbl_805425D8;
        *(f32*)(self + 0x44) = lbl_805425D8;
        break;
    case 2:
        x = (f32)*(s32*)(self + 0x260);
        *(f32*)(self + 0x3c) = lbl_805425D8;
        *(f32*)(self + 0x40) = lbl_80542600 * x;
        *(f32*)(self + 0x44) = lbl_805425D8;
        break;
    case 3:
        x = (f32)*(s32*)(self + 0x260);
        *(f32*)(self + 0x3c) = lbl_805425D8;
        *(f32*)(self + 0x40) = lbl_80542600 * -x;
        *(f32*)(self + 0x44) = lbl_805425D8;
        break;
    case 4:
        x = (f32)*(s32*)(self + 0x260);
        *(f32*)(self + 0x3c) = lbl_80542600 * x;
        *(f32*)(self + 0x40) = lbl_80542600 * x;
        *(f32*)(self + 0x44) = lbl_805425D8;
        break;
    case 5: {
        f32 y = (f32)*(s32*)(self + 0x260);
        x = (f32)*(s32*)(self + 0x260);
        *(f32*)(self + 0x3c) = lbl_80542600 * -x;
        *(f32*)(self + 0x40) = lbl_80542600 * y;
        *(f32*)(self + 0x44) = lbl_805425D8;
        break;
    }
    case 6: {
        f32 y = (f32)*(s32*)(self + 0x260);
        x = (f32)*(s32*)(self + 0x260);
        *(f32*)(self + 0x3c) = lbl_80542600 * x;
        *(f32*)(self + 0x40) = lbl_80542600 * -y;
        *(f32*)(self + 0x44) = lbl_805425D8;
        break;
    }
    case 7:
        x = (f32)*(s32*)(self + 0x260);
        *(f32*)(self + 0x3c) = lbl_80542600 * -x;
        *(f32*)(self + 0x40) = lbl_80542600 * -x;
        *(f32*)(self + 0x44) = lbl_805425D8;
        break;
    default:
        *(f32*)(self + 0x3c) = lbl_805425D8;
        *(f32*)(self + 0x40) = lbl_805425D8;
        *(f32*)(self + 0x44) = lbl_805425D8;
        break;
    }
}

extern "C" u32 fn_8013CC50(u32 owner, void* pos, u16 id, s32 a, f32 f, s32 b, s32 c, s32 d, s32 e);
extern "C" void* fn_801F856C(void);
extern "C" void Actor_CreateByID(void* mgr, u32 id, s32 kind, void* pos, s32 a, s32 b, s32 c);
extern const f32 lbl_805425F0;
extern const f32 lbl_805425D8;
extern "C" void fn_803511F0(u8* self);
extern "C" double sqrt(double);
extern const f32 lbl_80542608;
extern const f32 lbl_805425E8;
extern "C" s16 fn_8022461C(s32);
extern "C" s32 fn_80350274(s32 param_1, s32 param_2, s32 param_3) {
    s32 r = (u16)fn_8022461C(param_3);
    if (r == 0x3a || r == 3 || (u32)(r - 0xd) <= 1 || r == 0x3b) {
        return 0;
    }
    return 1;
}

extern "C" s32 fn_801F2618(void* this_, s32 a, s32 b);
extern "C" s32 fn_803502CC(u8* self) {
    s32 i;
    f32* p;
    s32 j;
    u8* base;
    f32 s0 = *(f32*)(self + 0x80);
    f32 s1 = *(f32*)(self + 0x84);
    f32 s2 = *(f32*)(self + 0x88);
    f32 s3 = *(f32*)(self + 0x8c);

    if (*(s32*)(self + 0x258) == 4) {
        p = (f32*)lbl_8050ADF8;
        for (i = 0; i < 4; i++) {
            *(f32*)(self + 0x80) = p[0];
            *(f32*)(self + 0x84) = p[1];
            *(f32*)(self + 0x88) = p[2];
            *(f32*)(self + 0x8c) = p[3];
            if (*(s32*)(self + 0x268) == 0 || *(s32*)(self + 0x268) == 1) {
                *(f32*)(self + 0x8c) = *(f32*)(self + 0x8c) - lbl_80542604;
            } else {
                *(f32*)(self + 0x84) = *(f32*)(self + 0x84) + *(f32*)(self + 0x290);
                *(f32*)(self + 0x8c) = *(f32*)(self + 0x8c) + *(f32*)(self + 0x290);
            }
            if ((u8)fn_801F2618(self, 0, 0) == 1) {
                *(f32*)(self + 0x80) = s0;
                *(f32*)(self + 0x84) = s1;
                *(f32*)(self + 0x88) = s2;
                *(f32*)(self + 0x8c) = s3;
                return 1;
            }
            p += 4;
        }
    } else if (*(s32*)(self + 0x258) >= 0x10 && *(s32*)(self + 0x258) <= 0x14) {
        base = (u8*)lbl_8050AE38 + (*(s32*)(self + 0x258) - 0x10) * 0x20;
        j = 0;
        for (i = 0; i < 2; i++) {
            p = (f32*)(base + j);
            *(f32*)(self + 0x80) = p[0];
            *(f32*)(self + 0x84) = p[1];
            *(f32*)(self + 0x88) = p[2];
            *(f32*)(self + 0x8c) = p[3];
            if (*(s32*)(self + 0x268) == 0 || *(s32*)(self + 0x268) == 1) {
                *(f32*)(self + 0x8c) = *(f32*)(self + 0x8c) - lbl_80542604;
            } else {
                *(f32*)(self + 0x84) = *(f32*)(self + 0x84) + *(f32*)(self + 0x290);
                *(f32*)(self + 0x8c) = *(f32*)(self + 0x8c) + *(f32*)(self + 0x290);
            }
            if ((u8)fn_801F2618(self, 0, 0) == 1) {
                *(f32*)(self + 0x80) = s0;
                *(f32*)(self + 0x84) = s1;
                *(f32*)(self + 0x88) = s2;
                *(f32*)(self + 0x8c) = s3;
                return 1;
            }
            j += 0x10;
        }
    } else {
        return fn_801F2618(self, 0, 0);
    }
    *(f32*)(self + 0x80) = s0;
    *(f32*)(self + 0x84) = s1;
    *(f32*)(self + 0x88) = s2;
    *(f32*)(self + 0x8c) = s3;
    return 0;
}

extern "C" s32 fn_80350530(u8* self) {
    s32 prev = *(s32*)(self + 0x270);
    s32 i;
    *(s32*)(self + 0x270) = 0;
    for (i = 0; i < 4; i++) {
        f32 x;
        f32 y;
        f32 r2;
        f32* p;
        f32 dx;
        f32 dy;
        f32 dx2;
        f32 dy2;
        if (fn_8022F514(i) == 1 && fn_8022CAF8(i) == 5) {
            continue;
        }
        x = *(f32*)(self + 0xc);
        y = *(f32*)(self + 0x10);
        r2 = lbl_80542618;
        if (prev != 0) {
            r2 = lbl_8054261C + (f32)*(s32*)(self + 0x260);
            r2 = r2 * r2;
        }
        p = (f32*)fn_8023E724(i);
        dx = x - p[0];
        dy = y - p[1];
        dx2 = dx * dx;
        dy2 = dy * dy;
        if (dx2 + dy2 < r2) {
            p = (f32*)fn_8023E724(i);
            if (!(p[2] != lbl_805425D8)) {
                if (prev == 0) {
                    fn_801F0E34(self, 0x30009, 0);
                    *(s32*)(self + 0x27c) = 0;
                    *(s32*)(self + 0x274) = i;
                    if (fn_8022F514(i) == 1) {
                        *(s32*)(self + 0x274) = fn_8022F3DC(i);
                    }
                }
                *(s32*)(self + 0x270) = 1;
                return *(s32*)(self + 0x244) <= 0 ? *(s32*)(self + 0x268) : -1;
            }
        }
    }
    *(s32*)(self + 0x27c) = 0;
    *(s32*)(self + 0x274) = -1;
    *(s32*)(self + 0x244) = 0;
    return -1;
}

extern const f32 lbl_80542614;
extern const f32 lbl_80542620;
extern u8 lbl_8053AD40;
f32 lbl_8050AED8[8];
extern "C" s32 fn_803506E0(u8* self) {
    f32* tbl;
    s32 bit;
    s32 j;
    s32 flags;
    s32 i;
    s32 m;
    f32 x;
    f32 y;
    f32 r2;
    f32 dx;
    f32 dy;
    f32 dx2;
    f32 dy2;
    f32* p;
    s32 idx;

    if (!(s8)lbl_8053AD40) {
        lbl_8050AED8[0] = lbl_80542614;
        lbl_8050AED8[1] = lbl_805425D8;
        lbl_8050AED8[2] = lbl_80542620;
        lbl_8050AED8[3] = lbl_805425D8;
        lbl_8050AED8[4] = lbl_805425D8;
        lbl_8050AED8[5] = lbl_80542614;
        lbl_8050AED8[6] = lbl_805425D8;
        lbl_8050AED8[7] = lbl_80542620;
        lbl_8053AD40 = 1;
    }

    flags = *(s32*)(self + 0x270);
    *(s32*)(self + 0x270) = 0;
    for (i = 0; i < 4; i++) {
        if (fn_8022F514(i) == 1 && fn_8022CAF8(i) == 5) {
            continue;
        }
        tbl = lbl_8050AED8;
        for (j = 0; j < 4; j++) {
            bit = 1 << j;
            x = tbl[0] + *(f32*)(self + 0xc);
            y = tbl[1] + *(f32*)(self + 0x10);
            r2 = lbl_80542618;
            m = flags & bit;
            if (m != 0) {
                r2 = lbl_8054261C + (f32)*(s32*)(self + 0x260);
                r2 = r2 * r2;
            }
            p = (f32*)fn_8023E724(i);
            dx = x - p[0];
            dy = y - p[1];
            dx2 = dx * dx;
            dy2 = dy * dy;
            if (dx2 + dy2 < r2) {
                p = (f32*)fn_8023E724(i);
                if (p[2] == lbl_805425D8) {
                    if (m == 0) {
                        fn_801F0E34(self, 0x30009, 0);
                    }
                    *(s32*)(self + 0x270) |= bit;
                }
            }
            tbl += 2;
        }
    }

    flags = *(s32*)(self + 0x270);
    if (flags == 1) {
        idx = 0;
    } else if (flags == 2) {
        idx = 1;
    } else if (flags == 4) {
        idx = 2;
    } else if (flags == 8) {
        idx = 3;
    } else if (flags == 5) {
        idx = 4;
    } else if (flags == 6) {
        idx = 5;
    } else if (flags == 9) {
        idx = 6;
    } else if (flags == 10) {
        idx = 7;
    } else {
        idx = -1;
    }
    *(s32*)(self + 0x268) = idx;
    return *(s32*)(self + 0x268);
}

extern const f32 lbl_80542628;
extern const f32 lbl_8054262C;
extern "C" s32 fn_8023DE58(s32 player);
extern "C" void fn_8022E088(s32 player, s32 idx, JGeometry::TVec3<f32>* out);
extern "C" void fn_8022DF48(s32 player);
extern const f32 lbl_80542600;
extern const f32 lbl_80542604;
extern "C" s32 fn_80351020(u8* this_, s32 player) {
    s32 room = *(s32*)(this_ + 4);
    if (room != fn_8023DE58(player)) {
        return 0;
    }
    f32 scale = lbl_80542628;
    f32 margin = lbl_8054262C;
    for (s32 i = 0; i < 8; i++) {
        JGeometry::TVec3f pt;
        fn_8022E088(player, i, &pt);
        pt -= *(JGeometry::TVec3f*)(this_ + 0xc);
        pt.z = 0.0f;
        f32 ang = JMath::atanTable_.atan2_(pt.y, pt.x);
        s32 idx = (s32)(ang * scale);
        f32 len = JGeometry::TUtilf::sqrt(pt.x * pt.x + pt.y * pt.y);
        u8* sc = (u8*)&JMath::sincosTable_ + ((idx >> 2) & 0x3ff8);
        pt.x = *(f32*)(sc + 4) * len;
        pt.y = *(f32*)sc * len;
        pt.z = 0.0f;
        f32 x0 = *(f32*)(this_ + 0x80) - margin;
        f32 y0 = *(f32*)(this_ + 0x84) - margin;
        f32 x1 = *(f32*)(this_ + 0x88) + margin;
        f32 y1 = *(f32*)(this_ + 0x8c) + margin;
        u8 in = 0;
        if (pt.x >= x0 && pt.y >= y0 && pt.x < x1 && pt.y < y1) {
            in = 1;
        }
        if (in) {
            fn_8022DF48(player);
            return 1;
        }
    }
    return 0;
}

extern "C" void fn_803511F0(u8* self) {
    fn_8013CC50(*(s32*)(self + 4), self + 0xc, 0x97, 0, lbl_805425F0, -3, 0, 0, 1);
    fn_8013CC50(*(s32*)(self + 4), self + 0xc, 0x98, 0, lbl_805425F0, -3, 0, 0, 1);
    *(s32*)(self + 0x258) = 0xb;
    self[0x282] = 0;
    *(s32*)(self + 0x24c) = 0;
    *(s32*)(self + 0x230) = 7;
    *(s32*)(self + 0x240) = 0xb;
    *(s32*)(self + 0x248) = 0xa;
    *(s32*)(self + 0x274) = -1;
    *(s32*)(self + 0x268) = *(s32*)(self + 0x264);
    f32 dx = *(f32*)(self + 0xc) - *(f32*)(self + 0x24);
    f32 dy = *(f32*)(self + 0x10) - *(f32*)(self + 0x28);
    f32 dx2 = dx * dx;
    f32 dy2 = dy * dy;
    f32 d2 = dx2 + dy2;
    if (d2 <= lbl_805425D8) {
        f32 y = __frsqrte(d2);
        y = lbl_80542600 * y * (lbl_80542604 - (d2 * (y * y)));
        d2 = d2 * y;
    } else {
        d2 = d2;
    }
    if (d2 > lbl_80542608) {
        *(JGeometry::TVec3f*)(self + 0xc) = *(JGeometry::TVec3f*)(self + 0x24);
        s32 kind = *(s32*)(self + 4);
        if (kind >= 8) {
            Actor_CreateByID(fn_801F856C(), 0x4b4d5249, kind, self + 0xc, 0x83, -1, -1);
            *(f32*)(self + 0x28c) = lbl_805425F0;
        } else {
            fn_8013CC50(kind, self + 0xc, 0x503, 1, lbl_805425E8, 0, 0, 0, 1);
            fn_801F0E34(self, 0x30003, 0);
        }
    } else {
        *(JGeometry::TVec3f*)(self + 0xc) = *(JGeometry::TVec3f*)(self + 0x24);
    }
    if (*(s32*)(self + 4) < 8) {
        *(f32*)(self + 0x28c) = lbl_805425D8;
    }
}

extern "C" u32 fn_8013CC50(u32 owner, void* pos, u16 id, s32 a, f32 f, s32 b, s32 c, s32 d, s32 e);
extern "C" void* fn_801F856C(void);
extern "C" void Actor_CreateByID(void* mgr, u32 id, s32 kind, void* pos, s32 a, s32 b, s32 c);
extern "C" void fn_801F0E34(void* self, u32 id, s32 b);
extern "C" void fn_803513C0(u8* self) {
    s32 kind = *(s32*)(self + 4);
    if (kind >= 8) {
        if (kind >= 8) {
            Actor_CreateByID(fn_801F856C(), 0x4b4d5249, kind, self + 0xc, 0x83, -1, -1);
            *(f32*)(self + 0x28c) = 1.0f;
        } else {
            fn_8013CC50(kind, self + 0xc, 0x503, 1, 2.0f, 0, 0, 0, 1);
            fn_801F0E34(self, 0x30003, 0);
        }
    } else {
        fn_8013CC50(kind, self + 0xc, 0x459, 0, 1.0f, -3, 0, 0, 1);
        fn_8013CC50(*(s32*)(self + 4), self + 0xc, 0x45a, 0, 1.0f, -3, 0, 0, 1);
        fn_8013CC50(*(s32*)(self + 4), self + 0xc, 0x45b, 0, 1.0f, -3, 0, 0, 1);
        fn_801F0E34(self, 0x30065, 0);
    }
    *(s32*)(self + 0x254) = 0x1e;
    *(s32*)(self + 0x258) = 0xc;
    *(s32*)(self + 0x230) = 0;
    *(s32*)(self + 0x240) = 0xa;
}

extern "C" char lbl_8050ADF8[];
extern "C" const f32 lbl_80542630;
extern "C" const f32 lbl_80542634;
extern "C" const f32 lbl_8054265C;
extern "C" const f32 lbl_80542660;
extern "C" const f32 lbl_80542664;
extern "C" const f32 lbl_80542668;
extern "C" const f32 lbl_8054266C;
extern "C" const f32 lbl_80542670;
extern "C" const f32 lbl_80542674;
extern "C" const f32 lbl_80542678;
extern "C" const f32 lbl_8054267C;
extern "C" char memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[];
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" char memPool___30JASPoolAllocObject_9JAIStream[];
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*);
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" char memPool___35JASPoolAllocObject_13JAISoundChild[];
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" char memPool___27JASPoolAllocObject_6JAISeq[];
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*);
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" char memPool___26JASPoolAllocObject_5JAISe[];
extern "C" void __dt__18JASMemPool_5JAISeFv(void*);
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;
extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __register_global_object(void*, void (*)(void*), void*);
extern "C" const f32 lbl_8054261C;
extern "C" const f32 lbl_805425D8;
extern "C" void fn_80351B84(void)
{
    *(f32*)(lbl_8050ADF8 + 0x00) = lbl_80542630;
    *(f32*)(lbl_8050ADF8 + 0x04) = lbl_80542630;
    *(f32*)(lbl_8050ADF8 + 0x08) = lbl_80542634;
    *(f32*)(lbl_8050ADF8 + 0x0C) = lbl_8054265C;
    *(f32*)(lbl_8050ADF8 + 0x10) = lbl_80542630;
    *(f32*)(lbl_8050ADF8 + 0x14) = lbl_80542660;
    *(f32*)(lbl_8050ADF8 + 0x18) = lbl_80542634;
    *(f32*)(lbl_8050ADF8 + 0x1C) = lbl_80542634;
    *(f32*)(lbl_8050ADF8 + 0x20) = lbl_80542630;
    *(f32*)(lbl_8050ADF8 + 0x24) = lbl_80542630;
    *(f32*)(lbl_8050ADF8 + 0x28) = lbl_8054265C;
    *(f32*)(lbl_8050ADF8 + 0x2C) = lbl_80542634;
    *(f32*)(lbl_8050ADF8 + 0x30) = lbl_80542660;
    *(f32*)(lbl_8050ADF8 + 0x34) = lbl_80542630;
    *(f32*)(lbl_8050ADF8 + 0x38) = lbl_80542634;
    *(f32*)(lbl_8050ADF8 + 0x3C) = lbl_80542660;
    *(f32*)(lbl_8050ADF8 + 0x40) = lbl_80542664;
    *(f32*)(lbl_8050ADF8 + 0x44) = lbl_80542668;
    *(f32*)(lbl_8050ADF8 + 0x48) = lbl_805425D8;
    *(f32*)(lbl_8050ADF8 + 0x4C) = lbl_8054266C;
    *(f32*)(lbl_8050ADF8 + 0x50) = lbl_805425D8;
    *(f32*)(lbl_8050ADF8 + 0x54) = lbl_80542670;
    *(f32*)(lbl_8050ADF8 + 0x58) = lbl_80542674;
    *(f32*)(lbl_8050ADF8 + 0x5C) = lbl_80542678;
    *(f32*)(lbl_8050ADF8 + 0x60) = lbl_80542664;
    *(f32*)(lbl_8050ADF8 + 0x64) = lbl_80542670;
    *(f32*)(lbl_8050ADF8 + 0x68) = lbl_805425D8;
    *(f32*)(lbl_8050ADF8 + 0x6C) = lbl_8054267C;
    *(f32*)(lbl_8050ADF8 + 0x70) = lbl_805425D8;
    *(f32*)(lbl_8050ADF8 + 0x74) = lbl_80542670;
    *(f32*)(lbl_8050ADF8 + 0x78) = lbl_80542674;
    *(f32*)(lbl_8050ADF8 + 0x7C) = lbl_8054266C;
    *(f32*)(lbl_8050ADF8 + 0x80) = lbl_80542670;
    *(f32*)(lbl_8050ADF8 + 0x84) = lbl_80542664;
    *(f32*)(lbl_8050ADF8 + 0x88) = lbl_80542678;
    *(f32*)(lbl_8050ADF8 + 0x8C) = lbl_805425D8;
    *(f32*)(lbl_8050ADF8 + 0x90) = lbl_80542668;
    *(f32*)(lbl_8050ADF8 + 0x94) = lbl_805425D8;
    *(f32*)(lbl_8050ADF8 + 0x98) = lbl_8054266C;
    *(f32*)(lbl_8050ADF8 + 0x9C) = lbl_80542674;
    *(f32*)(lbl_8050ADF8 + 0xA0) = lbl_80542664;
    *(f32*)(lbl_8050ADF8 + 0xA4) = lbl_8054261C;
    *(f32*)(lbl_8050ADF8 + 0xA8) = lbl_805425D8;
    *(f32*)(lbl_8050ADF8 + 0xAC) = lbl_8054266C;
    *(f32*)(lbl_8050ADF8 + 0xB0) = lbl_805425D8;
    *(f32*)(lbl_8050ADF8 + 0xB4) = lbl_80542670;
    *(f32*)(lbl_8050ADF8 + 0xB8) = lbl_80542674;
    *(f32*)(lbl_8050ADF8 + 0xBC) = lbl_8054266C;
    *(f32*)(lbl_8050ADF8 + 0xC0) = lbl_80542664;
    *(f32*)(lbl_8050ADF8 + 0xC4) = lbl_80542670;
    *(f32*)(lbl_8050ADF8 + 0xC8) = lbl_805425D8;
    *(f32*)(lbl_8050ADF8 + 0xCC) = lbl_8054266C;
    *(f32*)(lbl_8050ADF8 + 0xD0) = lbl_805425D8;
    *(f32*)(lbl_8050ADF8 + 0xD4) = lbl_80542670;
    *(f32*)(lbl_8050ADF8 + 0xD8) = lbl_80542674;
    *(f32*)(lbl_8050ADF8 + 0xDC) = lbl_8054267C;

    if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, lbl_8050ADF8 + 0x100);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, lbl_8050ADF8 + 0x10C);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, lbl_8050ADF8 + 0x118);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, lbl_8050ADF8 + 0x124);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, lbl_8050ADF8 + 0x130);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, lbl_8050ADF8 + 0x13C);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, lbl_8050ADF8 + 0x148);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, lbl_8050ADF8 + 0x154);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, lbl_8050ADF8 + 0x160);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}

