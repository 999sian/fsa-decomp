#include "types.h"

extern s32 lbl_8053AAF8;
extern s32 lbl_8053AB10;
extern "C" void fn_802D9FF4(s32, s32, s32);
extern "C" void fn_80136798(s32, s32, s32);
extern "C" void fn_8011921C(void);
extern "C" void fn_801183BC(void);
extern "C" s32 fn_802D6A9C(void);
extern "C" s32 fn_80119DD0(void);
extern "C" void fn_80119468(s32, s32, s32);
extern "C" u8 fn_803865B8(s32);
extern "C" void fn_80388EEC(s32);
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JUtility/JUTVideo.h"

extern "C" u8 lbl_8049E668[];
extern "C" JGeometry::TVec3<f32> lbl_804BD790[4];
extern "C" char memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[];
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" char memPool___30JASPoolAllocObject_9JAIStream[];
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*);
extern "C" char memPool___35JASPoolAllocObject_13JAISoundChild[];
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern "C" char memPool___27JASPoolAllocObject_6JAISeq[];
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*);
extern "C" char memPool___26JASPoolAllocObject_5JAISe[];
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;
extern "C" void __dt__18JASMemPool_5JAISeFv(void*);
extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __register_global_object(void*, void*, void*);

struct FsaBlock84 {
    u32 m0;
    u32 m4;
    u32 m8;
    u32 mc;
    u32 m10;
    u32 m14;
    u32 m18;
    u32 m1c;
    u32 m20;
    u32 m24;
    u32 m28;
    u32 m2c;
    u32 m30;
    u32 m34;
    u32 m38;
    u32 m3c;
    u32 m40;
    u32 m44;
    u32 m48;
    u32 m4c;
    u32 m50;
    u32 m54;
    u32 m58;
    u32 m5c;
    u32 m60;
    u32 m64;
    u32 m68;
    u32 m6c;
    u32 m70;
    u32 m74;
    u32 m78;
    u32 m7c;
    u32 m80;
};

static inline void copyFsaBlock84(FsaBlock84* __restrict dst, const FsaBlock84* __restrict src)
{
    *dst = *src;
}

extern "C" u8 fn_8012A5EC(void*);
extern "C" void* fn_8013CC50(u32 room, void* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_8022FE80(int, int, int, u8, u8);
extern "C" u8 fn_8038BD08(s32, s32, u32, JGeometry::TVec3<f32>*, s32);
extern "C" void fn_8011921C();
extern "C" void fn_80118454();
extern "C" void fn_801183BC();
extern "C" u8 fn_803865B8(s32);
extern "C" void fn_80388EEC(s32);
extern s32 lbl_804650C8[];
extern u8 lbl_8053CB60[4];
extern "C" void fn_801F0E34(void* self, u32 id, s32 flag);
extern "C" f32 lbl_8053CB90;
extern "C" void fn_80239914(void*, u32, u32);
extern "C" u8 fn_8012A5EC(void* this_)
{
    u8* p = (u8*)this_;
    register f32 b;
    f32 e;
    f32 c;
    f32 a;
    f32 lim;
    Vec vec;
    f32 d;
    u8* obj;

    switch (*(s32*)(p + 0x230)) {
    case 0:
    case 1:
    case 3:
    case 5:
    case 7:
    case 9:
        *(f32*)(p + 0x23c) = 154.0f + *(f32*)(p + 0x3f4) - 270.0f;
        *(f32*)(p + 0x248) = 186.0f;
        break;
    case 2:
        lim = 260.0f + *(f32*)(p + 0x3f4);
        if (*(f32*)(p + 0x23c) > lim) {
            *(f32*)(p + 0x23c) = *(f32*)(p + 0x23c) - *(f32*)(p + 0x244);
        } else {
            *(f32*)(p + 0x23c) = lim;
        }
        if (*(f32*)(p + 0x248) > 85.0f) {
            *(f32*)(p + 0x248) = *(f32*)(p + 0x248) - *(f32*)(p + 0x24c);
        } else {
            *(f32*)(p + 0x248) = 85.0f;
        }
        break;
    case 4:
        lim = 0.5f + *(f32*)(p + 0x3f4);
        if (*(f32*)(p + 0x23c) < lim) {
            *(f32*)(p + 0x23c) = *(f32*)(p + 0x23c) - *(f32*)(p + 0x244);
        } else {
            *(f32*)(p + 0x23c) = lim;
        }
        if (*(f32*)(p + 0x248) < 0.0f) {
            *(f32*)(p + 0x248) = *(f32*)(p + 0x248) - *(f32*)(p + 0x24c);
        } else {
            *(f32*)(p + 0x248) = 0.0f;
        }
        break;
    case 6:
        lim = 260.0f + *(f32*)(p + 0x3f4);
        if (*(f32*)(p + 0x23c) > lim) {
            *(f32*)(p + 0x23c) = *(f32*)(p + 0x23c) - *(f32*)(p + 0x244);
        } else {
            *(f32*)(p + 0x23c) = lim;
        }
        if (*(f32*)(p + 0x248) > 85.0f) {
            *(f32*)(p + 0x248) = *(f32*)(p + 0x248) - *(f32*)(p + 0x24c);
        } else {
            *(f32*)(p + 0x248) = 85.0f;
        }
        break;
    case 8:
        lim = -16.0f + *(f32*)(p + 0x3f4);
        if (*(f32*)(p + 0x23c) > lim) {
            *(f32*)(p + 0x23c) = *(f32*)(p + 0x23c) - *(f32*)(p + 0x244);
        } else {
            *(f32*)(p + 0x23c) = lim;
        }
        if (*(f32*)(p + 0x248) < 0.0f) {
            *(f32*)(p + 0x248) = *(f32*)(p + 0x248) - *(f32*)(p + 0x24c);
        } else {
            *(f32*)(p + 0x248) = 0.0f;
        }
        break;
    }

    a = *(f32*)(p + 0x238) + *(f32*)(p + 0x3fc);
    b = *(f32*)(p + 0x23c) + *(f32*)(p + 0x400);
    c = *(f32*)(p + 0x248);
    obj = *(u8**)((u8*)lbl_8053AB10 + 0x24);
    obj[0x179] = 1;
    d = b - c;
    e = c + b;
    if (!(*(f32*)(p + 0x3fc) == 0.0f && *(f32*)(p + 0x400) == 0.0f && *(s32*)(p + 0x230) != 0 && *(s32*)(p + 0x230) != 1)) {
        obj = *(u8**)((u8*)lbl_8053AB10 + 0x24);
        if (obj[0x840] == 0) {
            obj[0x840] = 1;
            *(f32*)(obj + 0x844) = a;
            *(f32*)(obj + 0x848) = d;
            *(f32*)(obj + 0x84c) = a;
            *(f32*)(obj + 0x850) = e;
            *(f32*)(obj + 0x854) = 1.0f;
            *(f32*)(obj + 0x1d4) = 0.0f;
            *(f32*)(obj + 0x1d8) = 0.0f;
        }
    } else {
        obj = *(u8**)((u8*)lbl_8053AB10 + 0x24);
        if (obj[0x7f5] == 0) {
            obj[0x7f4] = 1;
            *(s32*)(obj + 0x7f8) = 5;
            *(f32*)(obj + 0x808) = a;
            *(f32*)(obj + 0x80c) = d;
            *(f32*)(obj + 0x810) = a;
            *(f32*)(obj + 0x814) = e;
            obj[0x7f6] = 0;
        }
    }

    obj = *(u8**)((u8*)lbl_8053AB10 + 0x24);
    vec.x = -*(f32*)(obj + 0x10);
    vec.y = -*(f32*)(obj + 0x20);
    vec.z = 0.0f;
    return PSVECDistance((Vec*)(p + 0x238), &vec) < 0.05f;
}

extern "C" void fn_8012A8C0(char* this_) {
    struct Vec2 {
        f32 x, y;
    };
    struct Box {
        Vec2 min, max;
    };
    char* p = this_;
    s32 i = 0;
    Box box;
    Box orig;
    box.min.x = *(f32*)(this_ + 0x60);
    orig.min.x = box.min.x;
    box.min.y = *(f32*)(this_ + 0x64);
    orig.min.y = box.min.y;
    box.max.x = *(f32*)(this_ + 0x68);
    orig.max.x = box.max.x;
    box.max.y = *(f32*)(this_ + 0x6c);
    orig.max.y = box.max.y;
    do {
        box.min.x += *(f32*)(p + 0x25c);
        box.min.y += *(f32*)(p + 0x260);
        box.max.x += *(f32*)(p + 0x25c);
        box.max.y += *(f32*)(p + 0x260);
        fn_80239914(&box, *(u32*)(this_ + 4), *(u32*)(this_ + 0x198));
        box = orig;
        i++;
        p += 0xc;
    } while (i < 6);
}

extern "C" void fn_8012A9A0(char* this_) {
    fn_8012A5EC(this_);
    if (*(u8*)(this_ + 0x404) == 0) {
        fn_8022FE80(0, *(s32*)(this_ + 4), *(s32*)(this_ + 0x198), 1, 0);
        if (fn_803865B8(0)) {
            fn_80388EEC(0);
            *(s32*)(this_ + 0x250) = 0x28;
            this_[0x404] = 1;
        }
    } else if (*(s32*)(this_ + 0x250) == 0) {
        fn_8011921C();
        fn_801183BC();
        char* mgr = *(char**)(lbl_8053AB10 + 0x24);
        mgr[0x17a] = 1;
        mgr[0x179] = 0;
        fn_802D9FF4(fn_802D6A9C(), 0, 0);
        fn_80136798(lbl_8053AAF8, 0xd, 0);
        fn_80119468(fn_80119DD0(), 0, 1);
        *(s32*)(this_ + 0x230) += 1;
    }
}

extern "C" s32 fn_801CD664(s32);
extern "C" void fn_80134DE4(s32, s32, s32);
extern "C" void fn_802D8050(s32, s32, s32, s32);
extern "C" u8* sManager__8JUTVideo;
extern "C" void fn_8012AA84(u8* p)
{
    JGeometry::TVec3<f32> pos;
    JGeometry::TVec3<f32> v4;
    JGeometry::TVec3<f32> v3;
    JGeometry::TVec3<f32> v2;
    JGeometry::TVec3<f32> v1;
    JGeometry::TVec3<f32> v0;
    u8* obj;
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;
    f32 f4;

    if (*(s32*)(p + 0x250) >= 0x514) {
        if (*(s32*)(p + 0x250) == 0x514) {
            f32 y = 154.0f + *(f32*)(p + 0x3f4);
            v0.x = *(f32*)(p + 0x3f8);
            v0.y = y;
            v0.z = 0.0f;
            fn_8013CC50(*(u32*)(p + 4), &v0, lbl_8053CB90, 0x460, 0, -1, 0, 0, 1);
            y = 154.0f + *(f32*)(p + 0x3f4);
            v1.x = *(f32*)(p + 0x3f8);
            v1.y = y;
            v1.z = 0.0f;
            fn_8013CC50(*(u32*)(p + 4), &v1, lbl_8053CB90, 0x46f, 0, 0, 0, 0, 1);
            y = 154.0f + *(f32*)(p + 0x3f4);
            v2.x = *(f32*)(p + 0x3f8);
            v2.y = y;
            v2.z = 0.0f;
            fn_8013CC50(*(u32*)(p + 4), &v2, lbl_8053CB90, 0x470, 0, 1, 0, 0, 1);
            y = 154.0f + *(f32*)(p + 0x3f4);
            v3.x = *(f32*)(p + 0x3f8);
            v3.y = y;
            v3.z = 0.0f;
            fn_8013CC50(*(u32*)(p + 4), &v3, lbl_8053CB90, 0x46e, 0, 1, 0, 0, 1);
            fn_8013CC50(*(u32*)(p + 4), (void*)(p + 0x238), lbl_8053CB90, 0x471, 0, 0, 0, 0, 1);
            fn_8013CC50(*(u32*)(p + 4), (void*)(p + 0x238), lbl_8053CB90, 0x472, 0, 0, 0, 0, 1);
            fn_801F0E34(p, 0x50063, 0);
            *(s32*)(p + 0x2c0) = 0;
        } else if (*(s32*)(p + 0x250) == 0x51d) {
            *(s32*)(p + 0x2c0) = 0xb;
        }
        fn_8012A5EC(p);
        return;
    }

    if (*(s32*)(p + 0x250) > 0x190) {
        if (*(s32*)(p + 0x250) >= 0x2da) {
            if (*(s32*)(p + 0x2bc) == 0) {
                *(s32*)(p + 0x2c0) += 1;
                if (*(s32*)(p + 0x2c0) >= 6)
                    *(s32*)(p + 0x2c0) = 0;
                *(s32*)(p + 0x2bc) = 9;
            }
            if (*(s32*)(p + 0x250) == 0x2da) {
                *(s32*)(p + 0x2c0) = 0xe;
                *(s32*)(p + 0x2bc) = 9;
                fn_801F0E34(p, 0x50064, 0);
            }
        } else {
            if (*(s32*)(p + 0x2bc) == 0) {
                *(s32*)(p + 0x2c0) += 1;
                if (*(s32*)(p + 0x2c0) >= 0x14)
                    *(s32*)(p + 0x2c0) = 0xe;
                *(s32*)(p + 0x2bc) = 9;
            }
            f64 k = 1.0 - (f64)(*(s32*)(p + 0x250) - 0x190) / 330.0;
            *(f32*)(p + 0x3fc) = (f32)fn_801CD664((s32)k);
            *(f32*)(p + 0x400) = (f32)fn_801CD664((s32)k);
            fn_80134DE4(lbl_8053AAF8, 3, 0);
        }
        fn_8012A5EC(p);
        return;
    } else {
        if (*(s32*)(p + 0x250) > 0x84) {
            if (*(s32*)(p + 0x2bc) == 0) {
                *(s32*)(p + 0x2c0) += 1;
                if (*(s32*)(p + 0x2c0) >= 0x14)
                    *(s32*)(p + 0x2c0) = 0xe;
                *(s32*)(p + 0x2bc) = 9;
            }
        } else if (*(s32*)(p + 0x250) > 0x7b) {
            *(s32*)(p + 0x2c0) = 0x14;
            *(s32*)(p + 0x2bc) = 0;
        } else if (*(s32*)(p + 0x250) > 0x3f) {
            *(s32*)(p + 0x2c0) = 0x18;
            *(s32*)(p + 0x2bc) = 0;
        } else if (*(s32*)(p + 0x250) > 0x3c) {
            *(s32*)(p + 0x2c0) = 0x19;
            *(s32*)(p + 0x2bc) = 0;
        } else {
            *(s32*)(p + 0x2c0) = 8;
            *(s32*)(p + 0x2bc) = 0;
        }
    }

    if (*(s32*)(p + 0x250) == 0x190) {
        *(f32*)(p + 0x400) = 0.0f;
        *(f32*)(p + 0x3fc) = 0.0f;
        fn_802D8050(fn_802D6A9C(), 1, 1, 0xff);
        *(s32*)(p + 0x2c0) = 0x13;
        *(s32*)(p + 0x2bc) = 4;
    } else if (*(s32*)(p + 0x250) == 0x1e) {
        *(f32*)(p + 0x248) = 186.0f;
        *(f32*)(p + 0x23c) = 154.0f + *(f32*)(p + 0x3f4) - 270.0f;
    } else if (*(s32*)(p + 0x250) == 0) {
        pos.set((f32)(s32)JUTVideo::getManager()->getFbWidth() / 2.0f,
                (f32)(s32)JUTVideo::getManager()->getEfbHeight() / 2.0f, 0.0f);
        pos.y += -16.0f;
        fn_8022FE80(0, *(s32*)(p + 4), *(s32*)(p + 0x198), 1, 0);
        u32 owner = *(u32*)(p + 4);
        v4 = pos;
        if (!fn_8038BD08((s32)0, lbl_804650C8[*(s32*)(p + 0x254)], owner, &v4, (s32)0x22)) {
            return;
        }
        *(s32*)(p + 0x254) += 1;
        fn_8011921C();
        fn_80118454();
        *(s32*)(p + 0x230) += 1;
    }
    f1 = *(f32*)(p + 0x23c);
    f0 = *(f32*)(p + 0x248);
    f4 = *(f32*)(p + 0x238);
    f3 = f1 + f0;
    f2 = f1 - f0;
    obj = *(u8**)((u8*)lbl_8053AB10 + 0x24);
    obj[0x179] = 1;
    obj = *(u8**)((u8*)lbl_8053AB10 + 0x24);
    if (obj[0x840] == 0) {
        obj[0x840] = 1;
        *(f32*)(obj + 0x844) = f4;
        *(f32*)(obj + 0x848) = f2;
        *(f32*)(obj + 0x84c) = f4;
        *(f32*)(obj + 0x850) = f3;
        *(f32*)(obj + 0x854) = 1.0f;
        *(f32*)(obj + 0x1d4) = -1.0f;
        *(f32*)(obj + 0x1d8) = -1.0f;
    }
}

extern "C" void fn_8012B02C(char* this_) {
    fn_8012A5EC(this_);
    fn_8022FE80(0, *(s32*)(this_ + 4), *(s32*)(this_ + 0x198), 1, 0);
    if (fn_803865B8(0)) {
        fn_80388EEC(0);
        fn_8011921C();
        fn_801183BC();
        *(s32*)(this_ + 0x250) = 0x604;
        ++*(s32*)(this_ + 0x230);
        *(f32*)(this_ + 0x244) = (*(f32*)(this_ + 0x23c) - (154.0f + *(f32*)(this_ + 0x3f4))) / 270.0f;
        *(f32*)(this_ + 0x24c) = (*(f32*)(this_ + 0x248) - 186.0f) / 270.0f;
    }
}

extern "C" s8 lbl_8053AAB1;
extern "C" JGeometry::TVec3<f32> lbl_804BD7C0[4];
extern "C" f32 lbl_8053CB9C;
extern "C" f32 lbl_8053CBC4;
extern "C" f32 lbl_8053CBC8;
extern "C" f32 lbl_8053CBCC;
extern "C" f32 lbl_8053CBD0;
extern "C" f32 lbl_8053CBD4;
extern "C" f32 lbl_8053CBD8;
extern "C" f32 lbl_8053CBDC;
extern "C" f32 lbl_8053CBE0;
extern "C" f32 lbl_8053CBE4;
extern "C" f32 lbl_8053CBE8;
extern "C" f32 lbl_8053CB8C;
extern "C" void fn_8013CB44(void*, void*, s32, s32, s32);
extern "C" void fn_80119998(s32, s32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_8012B0D8(char* this_) {
    u8 result = fn_8012A5EC(this_);
    if (*(f32*)(this_ + 0x23c) == 260.0f + *(f32*)(this_ + 0x3f4) &&
        85.0f == *(f32*)(this_ + 0x248) && result == 1) {
        JGeometry::TVec3<f32> pos(
            (f32)(s32)JUTVideo::getManager()->getFbWidth() / 2.0f,
            (f32)(s32)JUTVideo::getManager()->getEfbHeight() / 2.0f,
            0.0f);
        pos.y += -16.0f;
        fn_8022FE80(0, *(s32*)(this_ + 4), *(s32*)(this_ + 0x198), 1, 0);
        u32 owner = *(u32*)(this_ + 4);
        JGeometry::TVec3<f32> copy(pos);
        if (fn_8038BD08(0, lbl_804650C8[*(s32*)(this_ + 0x254)], owner, &copy, 0x22)) {
            ++*(s32*)(this_ + 0x254);
            fn_8011921C();
            fn_80118454();
            ++*(s32*)(this_ + 0x230);
        }
    }
}

struct DmtwParts {
    u8 pad[0x2C8];
    JGeometry::TVec3<f32> pos[4];
    JGeometry::TVec3<f32> vel[4];
    void* emitters[3][4];
    void* rings[3][4];
    void* smoke[3][4];
};
static inline void* dmtwSpawn(u32 room, const JGeometry::TVec3<f32>& pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale) {
    return fn_8013CC50(room, (void*)&pos, scale, id, a, b, c, d, e);
}
static inline u8 dmtwDialog(u32 owner, s32 message, JGeometry::TVec3<f32> pos) {
    return fn_8038BD08(0, message, owner, (JGeometry::TVec3<f32>*)&pos, 0x22);
}
#pragma opt_common_subs on
extern "C" void fn_8012B218(char* p) {
    s32 i;
    if (!lbl_8053AAB1) {
        lbl_804BD7C0[0]=JGeometry::TVec3<f32>(-113.0f,382.0f,50.0f);
        lbl_804BD7C0[1]=JGeometry::TVec3<f32>(109.0f,300.0f,50.0f);
        lbl_804BD7C0[2]=JGeometry::TVec3<f32>(126.0f,382.0f,50.0f);
        lbl_804BD7C0[3]=JGeometry::TVec3<f32>(-99.0f,300.0f,50.0f);
        lbl_8053AAB1=1;
    }
    fn_8012A5EC(p);
    switch (*(s32*)(p+0x234)) {
    case 0:
        *(JGeometry::TVec3<f32>*)(p+0x2c8) += *(JGeometry::TVec3<f32>*)(p+0x2f8);
        *(JGeometry::TVec3<f32>*)(p+0x2d4) += *(JGeometry::TVec3<f32>*)(p+0x304);
        *(JGeometry::TVec3<f32>*)(p+0x2e0) += *(JGeometry::TVec3<f32>*)(p+0x310);
        *(JGeometry::TVec3<f32>*)(p+0x2ec) += *(JGeometry::TVec3<f32>*)(p+0x31c);
        if (*(f32*)(p+0x2D0)>=50.0f) {
            ++*(s32*)(p+0x234); *(s32*)(p+0x250)=60;
        }
        break;
    case 1:
        if (*(s32*)(p+0x250)==0) {
            ++*(s32*)(p+0x234);
            DmtwParts* q=(DmtwParts*)p;
            JGeometry::TVec3<f32>* table=lbl_804BD7C0;
            for (i=0;i<4;i++, q=(DmtwParts*)((char*)q+12),table++) {
                f32 y=*(f32*)(p+0x3F4)+table[0].y;
                f32 x=*(f32*)(p+0x3F8)+table[0].x;
                q->vel[0]=JGeometry::TVec3<f32>(
                    (x-q->pos[0].x)/40.0f,
                    (y-q->pos[0].y)/40.0f,0.0f);
            }
            *(s32*)(p+0x250)=40;
        }
        break;
    case 2:
        *(JGeometry::TVec3<f32>*)(p+0x2c8) += *(JGeometry::TVec3<f32>*)(p+0x2f8);
        *(JGeometry::TVec3<f32>*)(p+0x2d4) += *(JGeometry::TVec3<f32>*)(p+0x304);
        *(JGeometry::TVec3<f32>*)(p+0x2e0) += *(JGeometry::TVec3<f32>*)(p+0x310);
        *(JGeometry::TVec3<f32>*)(p+0x2ec) += *(JGeometry::TVec3<f32>*)(p+0x31c);
        if (*(s32*)(p+0x250)==0) {
            for (i=0;i<4;i++) {
                ((DmtwParts*)p)->vel[i].zero();
                ((DmtwParts*)p)->vel[i].z=-0.2f;
                ((DmtwParts*)p)->pos[i]=lbl_804BD7C0[i]+JGeometry::TVec3<f32>(*(f32*)(p+0x3F8),*(f32*)(p+0x3F4),0.0f);
            }
            ++*(s32*)(p+0x234); *(s32*)(p+0x250)=60;
        }
        break;
    case 3:
        if (*(s32*)(p+0x250)==0) {
        *(JGeometry::TVec3<f32>*)(p+0x2c8) += *(JGeometry::TVec3<f32>*)(p+0x2f8);
        *(JGeometry::TVec3<f32>*)(p+0x2d4) += *(JGeometry::TVec3<f32>*)(p+0x304);
        *(JGeometry::TVec3<f32>*)(p+0x2e0) += *(JGeometry::TVec3<f32>*)(p+0x310);
        *(JGeometry::TVec3<f32>*)(p+0x2ec) += *(JGeometry::TVec3<f32>*)(p+0x31c);
            if (*(f32*)(p+0x2D0)<=32.0f) {
                ++*(s32*)(p+0x234); *(s32*)(p+0x250)=390;
                i=0;
                char* q=p;
                for (;i<4;q+=4,++i) {
                    {u8* e=*(u8**)(q+0x328); if (e) {*(u32*)(e+0xF4)|=0x100;*(u8**)(q+0x328)=0;}}
                    {u8* e=*(u8**)(q+0x338); if (e) {*(u32*)(e+0xF4)|=0x100;*(u8**)(q+0x338)=0;}}
                    {u8* e=*(u8**)(q+0x348); if (e) {*(u32*)(e+0xF4)|=0x100;*(u8**)(q+0x348)=0;}}
                }
                {s32 id1; char* records; char* positions; s32 id0; s32 player; s32 id2;
                positions=p;records=p;player=0;id0=0x3B4;id1=0x3B5;id2=0x3B6;
                for (;player<4;player++,id0+=3,positions+=12,records+=4,id1+=3,id2+=3) {
                    *(void**)(records+0x358)=fn_8013CC50(*(u32*)(p+4),positions+0x2C8,1.0f,(u16)id0,0,0,0,0,1);
                    *(void**)(records+0x368)=fn_8013CC50(*(u32*)(p+4),positions+0x2C8,1.0f,(u16)id1,0,0,0,0,1);
                    *(void**)(records+0x378)=fn_8013CC50(*(u32*)(p+4),positions+0x2C8,1.0f,(u16)id2,0,0,0,0,1);
                                }}
            }
        }
        break;
    case 4:
        if (*(s32*)(p+0x250)==360) {
            fn_80119998(fn_80119DD0(),150,0,2,0,1,150,0);
        } else if (*(s32*)(p+0x250)==210) {
            i=0;
                char* q=p;
                for (;i<4;q+=4,++i) {
                {u8* e=*(u8**)(q+0x358); if (e) {*(u32*)(e+0xF4)|=0x100;*(u8**)(q+0x358)=0;}}
                {u8* e=*(u8**)(q+0x368); if (e) {*(u32*)(e+0xF4)|=0x100;*(u8**)(q+0x368)=0;}}
                {u8* e=*(u8**)(q+0x378); if (e) {*(u32*)(e+0xF4)|=0x100;*(u8**)(q+0x378)=0;}}
                }
            for (i=0;i<4;i++) {
                *(void**)(p+0x388+i*4)=dmtwSpawn(*(u32*)(p+4),JGeometry::TVec3<f32>(*(f32*)(p+0x3F8),192.0f+*(f32*)(p+0x3F4),0.0f),(u16)(0x461+i*3),1,2,0,0,1,1.0f);
                *(void**)(p+0x398+i*4)=dmtwSpawn(*(u32*)(p+4),JGeometry::TVec3<f32>(*(f32*)(p+0x3F8),192.0f+*(f32*)(p+0x3F4),0.0f),(u16)(0x462+i*3),1,2,0,0,1,1.0f);
                *(void**)(p+0x3a8+i*4)=dmtwSpawn(*(u32*)(p+4),JGeometry::TVec3<f32>(*(f32*)(p+0x3F8),192.0f+*(f32*)(p+0x3F4),0.0f),(u16)(0x463+i*3),1,2,0,0,1,1.0f);
            }
        }

        else if (*(s32*)(p+0x250)==30) {
            *(s32*)(p+0x2C0)=10;
        } else if (*(s32*)(p+0x250)==0) {
            *(s32*)(p+0x2C0)=10;
            *(s32*)(p+0x234)=0;
            JGeometry::TVec3<f32> pos(
                (f32)(s32)JUTVideo::getManager()->getFbWidth()/2.0f,
                (f32)(s32)JUTVideo::getManager()->getEfbHeight()/2.0f,0.0f);
            pos.y+=-16.0f;
            fn_8022FE80(0,*(s32*)(p+4),*(s32*)(p+0x198),1,0);
            u32 owner=*(u32*)(p+4);
            if (!dmtwDialog(owner,lbl_804650C8[*(s32*)(p+0x254)],JGeometry::TVec3<f32>(pos))) return;
            ++*(s32*)(p+0x254);
            fn_8011921C();
            fn_80118454();
            *(s32*)(p+0x230)+=2;
        }
        break;
    }
    char* records=p;
    char* positions=p;
    for (s32 player=0;player<4;player++,records+=4,positions+=12) {
        if (*(void**)(records+0x328))
            fn_8013CB44(*(void**)(records+0x328),positions+0x2C8,0,0,1);
        if (*(void**)(records+0x338))
            fn_8013CB44(*(void**)(records+0x338),positions+0x2C8,0,0,1);
        if (*(void**)(records+0x348))
            fn_8013CB44(*(void**)(records+0x348),positions+0x2C8,0,0,1);
    }
}
#pragma opt_common_subs reset
extern "C" void* fn_8013CC50(u32 room, void* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern const u8 lbl_8053CB64[4];
extern f32 lbl_8053CB8C;
extern f32 lbl_8053CBB0;
extern "C" void fn_8012BC40(char* this_) {
    u8 result = fn_8012A5EC(this_);
    if (*(f32*)(this_ + 0x23c) == 279.0f + *(f32*)(this_ + 0x3f4) && 105.0f == *(f32*)(this_ + 0x248) && result == 1) {
        for (s32 i = 0; i < 4; i++) {
            *(JGeometry::TVec3<f32>*)(this_ + 0x2c8 + i * 12) = *(JGeometry::TVec3<f32>*)(this_ + 0x3b8 + lbl_8053CB64[i] * 12);
            *(f32*)(this_ + 0x2f8 + i * 12) = 0.0f;
            *(f32*)(this_ + 0x2fc + i * 12) = 0.0f;
            *(f32*)(this_ + 0x300 + i * 12) = 0.5f;
        }
        {
            s32 player; u16 id0; char* positions; char* records; u16 id1; u16 id2;
            positions = this_; records = this_; player = 0; id0 = 0x3c0; id1 = 0x3c1; id2 = 0x3c2;
            for (; player < 4; player++, id0 += 3, positions += 12, records += 4, id1 += 3, id2 += 3) {
                *(void**)(records + 0x328) = fn_8013CC50(*(u32*)(this_ + 4), positions + 0x2c8, 1.0f, id0, 0, 0, 0, 0, 1);
                *(void**)(records + 0x338) = fn_8013CC50(*(u32*)(this_ + 4), positions + 0x2c8, 1.0f, id1, 0, 0, 0, 0, 1);
                *(void**)(records + 0x348) = fn_8013CC50(*(u32*)(this_ + 4), positions + 0x2c8, 1.0f, id2, 0, 0, 0, 0, 1);
            }
        }
        *(s32*)(this_ + 0x230) = *(s32*)(this_ + 0x230) + 1;
        *(s32*)(this_ + 0x234) = 0;
    }
}

extern "C" void fn_8012BE2C(char* this_) {
    fn_8012A5EC(this_);
    fn_8022FE80(0, *(s32*)(this_ + 4), *(s32*)(this_ + 0x198), 1, 0);
    if (fn_803865B8(0)) {
        fn_80388EEC(0);
        fn_8011921C();
        fn_801183BC();
    }
    u8* idx = lbl_8053CB60;
    f32 zero = lbl_8053CB8C;
    f32 half = lbl_8053CBB0;
    *(JGeometry::TVec3<f32>*)(this_ + 0x2c8) = *(JGeometry::TVec3<f32>*)(this_ + 0x3b8 + idx[0] * 12);
    *(s32*)(this_ + 0x230) += 2;
    *(f32*)(this_ + 0x2f8) = zero;
    *(f32*)(this_ + 0x2fc) = zero;
    *(f32*)(this_ + 0x300) = half;
    *(JGeometry::TVec3<f32>*)(this_ + 0x2d4) = *(JGeometry::TVec3<f32>*)(this_ + 0x3b8 + idx[1] * 12);
    *(f32*)(this_ + 0x304) = zero;
    *(f32*)(this_ + 0x308) = zero;
    *(f32*)(this_ + 0x30c) = half;
    *(JGeometry::TVec3<f32>*)(this_ + 0x2e0) = *(JGeometry::TVec3<f32>*)(this_ + 0x3b8 + idx[2] * 12);
    *(f32*)(this_ + 0x310) = zero;
    *(f32*)(this_ + 0x314) = zero;
    *(f32*)(this_ + 0x318) = half;
    *(JGeometry::TVec3<f32>*)(this_ + 0x2ec) = *(JGeometry::TVec3<f32>*)(this_ + 0x3b8 + idx[3] * 12);
    *(f32*)(this_ + 0x31c) = zero;
    *(f32*)(this_ + 0x320) = zero;
    *(f32*)(this_ + 0x324) = half;
    {
        s32 player; u16 id0; char* positions; char* records; u16 id1; u16 id2;
        positions = this_; records = this_; player = 0; id0 = 0x3c0; id1 = 0x3c1; id2 = 0x3c2;
        for (; player < 4; player++, id0 += 3, positions += 12, records += 4, id1 += 3, id2 += 3) {
            *(void**)(records + 0x328) = fn_8013CC50(*(u32*)(this_ + 4), positions + 0x2c8, lbl_8053CB90, id0, 0, 0, 0, 0, 1);
            *(void**)(records + 0x338) = fn_8013CC50(*(u32*)(this_ + 4), positions + 0x2c8, lbl_8053CB90, id1, 0, 0, 0, 0, 1);
            *(void**)(records + 0x348) = fn_8013CC50(*(u32*)(this_ + 4), positions + 0x2c8, lbl_8053CB90, id2, 0, 0, 0, 0, 1);
        }
    }
    *(s32*)(this_ + 0x234) = 0;
    fn_801F0E34(this_, 0x50062, 0);
}

extern "C" void fn_8012C030(char* this_) {
    u8 result = fn_8012A5EC(this_);
    if (*(f32*)(this_ + 0x23c) == 260.0f + *(f32*)(this_ + 0x3f4) &&
        85.0f == *(f32*)(this_ + 0x248) && result == 1) {
        JGeometry::TVec3<f32> pos(
            (f32)(s32)JUTVideo::getManager()->getFbWidth() / 2.0f,
            (f32)(s32)JUTVideo::getManager()->getEfbHeight() / 2.0f,
            0.0f);
        pos.y += -16.0f;
        fn_8022FE80(0, *(s32*)(this_ + 4), *(s32*)(this_ + 0x198), 1, 0);
        u32 owner = *(u32*)(this_ + 4);
        JGeometry::TVec3<f32> copy(pos);
        if (fn_8038BD08(0, lbl_804650C8[*(s32*)(this_ + 0x254)], owner, &copy, 0x22)) {
            ++*(s32*)(this_ + 0x254);
            fn_8011921C();
            fn_80118454();
            ++*(s32*)(this_ + 0x230);
        }
    }
}

extern "C" f32 lbl_8053CBEC;
extern "C" f32 lbl_8053CBB0;
extern "C" void fn_8012C170(char* this_) {
    f32 pos;
    f32 step;
    if (*(s32*)(this_ + 0x250) == 1) {
        fn_80119468(fn_80119DD0(), 0, 0);
    }
    pos = *(f32*)(this_ + 0x3bc);
    f32 threshold = lbl_8053CBEC + *(f32*)(this_ + 0x3f4);
    if (pos >= threshold) {
        step = lbl_8053CBB0;
        *(f32*)(this_ + 0x3bc) = pos - step;
        *(f32*)(this_ + 0x3c8) = *(f32*)(this_ + 0x3c8) - step;
        *(f32*)(this_ + 0x3d4) = *(f32*)(this_ + 0x3d4) - step;
        *(f32*)(this_ + 0x3e0) = *(f32*)(this_ + 0x3e0) - step;
        if (*(s32*)(this_ + 0x3f0) == 0) {
            *(s32*)(this_ + 0x3f0) = 6;
            *(s32*)(this_ + 0x3ec) += 1;
            if (*(s32*)(this_ + 0x3ec) >= 8) {
                *(s32*)(this_ + 0x3ec) = 0;
            }
        }
        fn_8012A5EC(this_);
        return;
    }
    *(f32*)(this_ + 0x3bc) = threshold;
    *(s32*)(this_ + 0x3ec) = 0;
    fn_8012A5EC(this_);
    JGeometry::TVec3<f32> pos2(
        (f32)(s32)JUTVideo::getManager()->getFbWidth() / 2.0f,
        (f32)(s32)JUTVideo::getManager()->getEfbHeight() / 2.0f,
        0.0f);
    pos2.y += -16.0f;
    fn_8022FE80(0, *(s32*)(this_ + 4), *(s32*)(this_ + 0x198), 1, 0);
    u32 owner = *(u32*)(this_ + 4);
    JGeometry::TVec3<f32> copy(pos2);
    if (fn_8038BD08(0, lbl_804650C8[*(s32*)(this_ + 0x254)], owner, &copy, 0x22)) {
        ++*(s32*)(this_ + 0x254);
        fn_8011921C();
        fn_80118454();
        *(s32*)(this_ + 0x230) += 2;
    }
}

extern "C" f32 lbl_8053CB68;
extern "C" f32 lbl_8053CB8C;
extern "C" f32 lbl_8053CBF0;
extern "C" f32 lbl_8053CBF4;
extern "C" s8 lbl_8053AAB0;
extern "C" JGeometry::TVec3<f32> lbl_804BD790[4];
extern "C" s32 fn_80230188(s32 idx);
extern "C" u8 fn_802300EC(s32 idx);
extern "C" void fn_8023EE28(s32 idx);
extern "C" void fn_8023077C(void);
extern "C" void fn_80230498(s32 idx, void* vec, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_8012C334(char* this_) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if ((u8)fn_80230188(i) != 0 || fn_802300EC(i) == 0) {
            goto end;
        }
    }
    if (lbl_8053AAB0 == 0) {
        f32 y = lbl_8053CB68 + *(f32*)(this_ + 0x3f4);
        f32 x = *(f32*)(this_ + 0x3f8);
        y = lbl_8053CBF0 + y;
        lbl_804BD790[0] = JGeometry::TVec3<f32>(x - lbl_8053CBF0, y, lbl_8053CB8C);
        lbl_804BD790[1] = JGeometry::TVec3<f32>(x - lbl_8053CBF4, y, lbl_8053CB8C);
        lbl_804BD790[2] = JGeometry::TVec3<f32>(x + lbl_8053CBF4, y, lbl_8053CB8C);
        lbl_804BD790[3] = JGeometry::TVec3<f32>(x + lbl_8053CBF0, y, lbl_8053CB8C);
        lbl_8053AAB0 = 1;
    }
    for (i = 0; i < 4; i++) {
        *(JGeometry::TVec3<f32>*)(this_ + 0x3b8 + i * 0xc) = lbl_804BD790[i];
        fn_8023EE28(i);
    }
    fn_8023077C();
    *(s32*)(this_ + 0x3e8) = 0x18;
    *(s32*)(this_ + 0x3ec) = 0;
    *(s32*)(this_ + 0x3f0) = 6;
    for (i = 0; i < 4; i++) {
        fn_80230498(i, this_ + 0x3b8 + i * 0xc, *(s32*)(this_ + 0x3e8) + *(s32*)(this_ + 0x3ec), 0xff, -0x80, -0x80, 1);
    }
end:
    *(s32*)(this_ + 0x230) += 1;
    fn_8012A5EC(this_);
}

extern void* __vt__4DMTW[];
extern "C" void __dt__5ActorFv(void* this_, s32 flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void* fn_8012C4F8(u32* this_, s16 freeFlag) {
    if (this_ != NULL) {
        u32* p = this_;
        *(void**)this_ = __vt__4DMTW;
        for (s32 i = 0; i < 2; i++) {
            u32* a = (u32*)p[0xe2];
            if (a != NULL) {
                a[0x3d] |= 0x100;
                p[0xe2] = 0;
            }
            a = (u32*)p[0xe6];
            if (a != NULL) {
                a[0x3d] |= 0x100;
                p[0xe6] = 0;
            }
            a = (u32*)p[0xea];
            if (a != NULL) {
                a[0x3d] |= 0x100;
                p[0xea] = 0;
            }
            a = (u32*)p[0xe3];
            if (a != NULL) {
                a[0x3d] |= 0x100;
                p[0xe3] = 0;
            }
            a = (u32*)p[0xe7];
            if (a != NULL) {
                a[0x3d] |= 0x100;
                p[0xe7] = 0;
            }
            a = (u32*)p[0xeb];
            if (a != NULL) {
                a[0x3d] |= 0x100;
                p[0xeb] = 0;
            }
            p += 2;
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, s32 a, s32 b, f32 s0, f32 s1);
extern "C" const char lbl_804650E0[];
extern "C" f32 lbl_8053CB90;
extern "C" s32 fn_80230188(s32);
extern "C" void fn_80230498(s32, void*, s32, s32, s32, s32, s32);
extern "C" void fn_8012C638(char* this_) {
    Vec saved;
    s32 i;
    s32 j;

    JGeometry::setTVec3f((f32*)(this_ + 0xc), (f32*)&saved);
    for (i = 0; i < 6; i++) {
        JGeometry::setTVec3f((f32*)(this_ + 0x25c + i * 0xc), (f32*)(this_ + 0xc));
        fn_801F06F0(this_, lbl_804650E0, *(s32*)(this_ + 0x2a4 + i * 4) + *(s32*)(this_ + 0x2c0), 0, 7, lbl_8053CB90, lbl_8053CB90);
    }
    if (*(s32*)(this_ + 0x230) > 0) {
        for (j = 0; j < 4; j++) {
            if ((u8)fn_80230188(j)) {
                fn_80230498(j, this_ + 0x3b8 + j * 0xc, *(s32*)(this_ + 0x3e8) + *(s32*)(this_ + 0x3ec), 0xff, -0x80, -0x80, 1);
            }
        }
    }
    JGeometry::setTVec3f((f32*)&saved, (f32*)(this_ + 0xc));
}

extern s32 lbl_8053AF80;
extern s32 lbl_8053AD30;
extern "C" f32 lbl_8053CBF8;
extern "C" char lbl_80529DEC[];
extern "C" char lbl_8050EC80[];
extern "C" void fn_80458FF0(s32, s32, s32, s32);
extern "C" s32 fn_80309C4C(s32, s32, s32);
extern "C" void fn_80387494(s32);
extern "C" void fn_80119958(void);
class DMTW;
typedef void (DMTW::*DMTWStateFn)();
extern DMTWStateFn lbl_8049E6EC[];
extern "C" void fn_8012C73C(char* this_) {
    if (*(s32*)(this_ + 0x258) != 0) {
        *(s32*)(this_ + 0x258) -= 1;
    } else if (*(u32*)(lbl_8053AF80 + 0x58) != 0x100001c) {
        fn_80458FF0(lbl_8053AF80, 0x100001c, 0, 0);
    }
    if (*(s32*)(this_ + 0x3f0) != 0) {
        *(s32*)(this_ + 0x3f0) -= 1;
    }
    if (*(s32*)(this_ + 0x2bc) != 0) {
        *(s32*)(this_ + 0x2bc) -= 1;
    }
    if (*(s32*)(this_ + 0x250) != 0) {
        *(s32*)(this_ + 0x250) -= 1;
    }
    u8* p = *(u8**)(lbl_8053AB10 + 0x30);
    if (p[0x284] == 0) {
        p[0x284] = 1;
        *(f32*)(p + 0x28c) = 0.05f;
    }
    (*(u8**)(lbl_8053AB10 + 0x24))[0x17c] = 1;
    BOOL unlocked;
    s32 a = *(s32*)(lbl_80529DEC + 0x118);
    s32 b = *(s32*)(lbl_80529DEC + 0x11c);
    if (a < 0 || a > 7) {
        unlocked = FALSE;
    } else if (b < 0 || b > 3) {
        unlocked = FALSE;
    } else {
        unlocked = ((1 << (b + a * 4)) & *(u32*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xc8 + 0x28)) != 0;
    }
    if (unlocked && *(s32*)(this_ + 0x230) >= 3 && *(s32*)(this_ + 0x230) <= 9) {
        *(u8*)(lbl_8053AAF8 + 0x85) = 2;
        if ((u32)fn_80309C4C(lbl_8053AD30, 0x1000, -1) != 0) {
            this_[0x404] = 1;
            fn_80387494(0);
            fn_80119DD0();
            fn_80119958();
            *(s32*)(this_ + 0x230) = 9;
            *(s32*)(this_ + 0x250) = 0;
        }
    }
    (((DMTW*)this_)->*lbl_8049E6EC[*(s32*)(this_ + 0x230)])();
}

extern "C" void fn_8012C910(void* this_) {}

extern s32 lbl_8053AD70;
extern s16 lbl_804650D4[];
extern s32 lbl_804650B0[];
extern u8 sincosTable___5JMath[];
extern f32 lbl_8053CB68;
extern f32 lbl_8053CB6C;
extern f32 lbl_8053CB70;
extern f32 lbl_8053CB90;
extern f32 lbl_8053CB94;
extern f32 lbl_8053CBFC;
extern f32 lbl_8053CC00;
extern f32 lbl_8053CC04;
extern f32 lbl_8053CC08;
extern f32 lbl_8053CC0C;
extern f32 lbl_8053CC10;
extern f32 lbl_8053CC14;
extern f32 lbl_8053CC18;
extern "C" void fn_8037AE00(s32);
extern "C" s32 fn_80458F9C(s32 mgr, s32 handle);
extern "C" void fn_80119998(s32, s32, s32, s32, s32, s32, s32, s32);

static inline void initDmtwCamera(f32 x, f32 lo, f32 hi) {
    *(u8*)(*(char**)(lbl_8053AB10 + 0x24) + 0x179) = 1;
    char* p = *(char**)(lbl_8053AB10 + 0x24);
    if (*(u8*)(p + 0x840) == 0) {
        *(u8*)(p + 0x840) = 1;
        *(f32*)(p + 0x844) = x;
        *(f32*)(p + 0x848) = lo;
        *(f32*)(p + 0x84c) = x;
        *(f32*)(p + 0x850) = hi;
        *(f32*)(p + 0x854) = lbl_8053CB90;
        *(f32*)(p + 0x1d4) = lbl_8053CB94;
        *(f32*)(p + 0x1d8) = lbl_8053CB94;
    }
}

extern "C" void fn_8012C914(char* this_) {
    s32 i;
    fn_8037AE00(lbl_8053AD70);
    *(f32*)(this_ + 0x3f4) = 384.0f * (f32)(s32)(*(f32*)(this_ + 0x10) / 384.0f);
    *(f32*)(this_ + 0x3f8) = 512.0f * (f32)(s32)(0.001953125f * *(f32*)(this_ + 0xc)) + 256.0f;
    *(f32*)(this_ + 0xc) = *(f32*)(this_ + 0x3f8);
    *(f32*)(this_ + 0x10) = 250.0f + *(f32*)(this_ + 0x3f4);
    *(s32*)(this_ + 0x230) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(f32*)(this_ + 0x248) = 130.0f;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x254) = 0;
    f32 top = 384.0f + *(f32*)(this_ + 0x3f4);
    f32 center = *(f32*)(this_ + 0x3f8);
    *(f32*)(this_ + 0x238) = center;
    *(f32*)(this_ + 0x23c) = top - 102.0f;
    *(f32*)(this_ + 0x240) = 0.0f;
    *(f32*)(this_ + 0x400) = 0.0f;
    *(f32*)(this_ + 0x3fc) = 0.0f;
    for (i = 0; i < 6; i++) {
        u32 off = (s16)lbl_804650D4[i] >> 2 & 0x3ff8;
        f32 cs;
        f32 sn;
        sn = *(f32*)(sincosTable___5JMath + off);
        cs = *(f32*)(sincosTable___5JMath + off + 4);
        JGeometry::TVec3f delta(55.0f * cs, 35.0f * sn, 0.0f);
        JGeometry::TVec3f value = *(JGeometry::TVec3f*)(this_ + 0xc) + delta;
        *(JGeometry::TVec3f*)(this_ + 0x25c + i*12) = value;
        *(s32*)(this_ + 0x2a4 + (i) * 4) = lbl_804650B0[i];
    }
    *(s32*)(this_ + 0x2bc) = 0;
    *(s32*)(this_ + 0x2c0) = 8;
    *(s32*)(this_ + 0x2c4) = 0;
    *(f32*)(this_ + 0x60) = -8.0f;
    *(f32*)(this_ + 0x64) = -8.0f;
    *(f32*)(this_ + 0x68) = 8.0f;
    *(f32*)(this_ + 0x6c) = 8.0f;
    if (*(u32*)(lbl_8053AF80 + 0x58) - 0x1000000 != 0x1c) {
        fn_80458F9C(lbl_8053AF80, 0x3c);
    }
    *(s32*)(this_ + 0x258) = 0x3c;
    *(u8*)(this_ + 0x404) = 0;
    *(s32*)(this_ + 0x388) = 0;
    *(s32*)(this_ + 0x398) = 0;
    *(s32*)(this_ + 0x3a8) = 0;
    *(s32*)(this_ + 0x38c) = 0;
    *(s32*)(this_ + 0x39c) = 0;
    *(s32*)(this_ + 0x3ac) = 0;
    *(s32*)(this_ + 0x390) = 0;
    *(s32*)(this_ + 0x3a0) = 0;
    *(s32*)(this_ + 0x3b0) = 0;
    *(s32*)(this_ + 0x394) = 0;
    *(s32*)(this_ + 0x3a4) = 0;
    *(s32*)(this_ + 0x3b4) = 0;
    fn_80119998(fn_80119DD0(), 0x96, 0, 0, 0, 0, 0x6e, 0);
    *(s32*)(this_ + 0x250) = 0x3c;
        f32 a = *(f32*)(this_ + 0x238);
    f32 b = *(f32*)(this_ + 0x23c);
    f32 e = *(f32*)(this_ + 0x248);
    initDmtwCamera(a, b-e, b+e);
}
#pragma opt_common_subs off
extern "C" void fn_8012CBE4(void)
{
    u8* p = lbl_8049E668;
    JGeometry::TVec3<f32>* base = lbl_804BD790;
    FsaBlock84* __restrict dst = (FsaBlock84*)(p + 0x84);
    *dst = *(FsaBlock84*)p;
    if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, (u8*)base + 0x60);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, (u8*)base + 0x6c);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, (u8*)base + 0x78);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, (u8*)base + 0x84);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, (u8*)base + 0x90);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, (u8*)base + 0x9c);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, (u8*)base + 0xa8);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, (u8*)base + 0xb4);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, (u8*)base + 0xc0);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}
#pragma opt_common_subs reset
