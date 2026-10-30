#include "types.h"
class ResMgr8035B0E0 {
public:
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void* vf18(u32, u32);
};
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JGeometry/Box.h"
#include "Game/ItemBase.h"
extern "C" unsigned char sincosTable___5JMath[];
extern "C" void* lbl_8053AB10;
extern "C" u32 lbl_8053A1B8[2];
extern "C" char lbl_804724E0[];
extern "C" void fn_802F745C(void*, const void*, void*, DrawRec*);
#include "JSystem/JMath/JMath.h"
static inline void rotationEuler80359E18(f32 m[3][4], s16 rx, s16 ry, s16 rz, const f32 scale)
{
    f32 cz;
    f32 cy;
    f32 sz;
    f32 sy;
    f32 sx;
    f32 cx;
    sx = JMath::sincosTable_.sinShort(rx);
    sy = JMath::sincosTable_.sinShort(ry);
    sz = JMath::sincosTable_.sinShort(rz);
    cx = JMath::sincosTable_.cosShort(rx);
    cy = JMath::sincosTable_.cosShort(ry);
    cz = JMath::sincosTable_.cosShort(rz);
    m[0][0] = scale * (cy * cz);
    m[1][0] = scale * (cy * sz);
    m[2][0] = scale * -sy;
    f32 cxsz = cx * sz;
    f32 sxcz = sx * cz;
    m[0][1] = scale * ((sx * sy) * cz - cxsz);
    m[1][1] = scale * ((sx * sy) * sz + cx * cz);
    m[2][1] = scale * (sx * cy);
    m[0][2] = scale * ((cx * cz) * sy + sx * sz);
    m[1][2] = scale * (cxsz * sy - sxcz);
    m[2][2] = scale * (cx * cy);
}
#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"


struct Unk8035A1D4;
typedef void (Unk8035A1D4::*Unk8035A1D4Func)();
extern Unk8035A1D4Func lbl_804AD30C[];
extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __register_global_object(void*, void (*)(void*), void*);
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*);
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*);
extern "C" void __dt__18JASMemPool_5JAISeFv(void*);
extern "C" char memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[];
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" char memPool___30JASPoolAllocObject_9JAIStream[];
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" char memPool___35JASPoolAllocObject_13JAISoundChild[];
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" char memPool___27JASPoolAllocObject_6JAISeq[];
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" char memPool___26JASPoolAllocObject_5JAISe[];
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;
struct StateTable8035B348 {
    u32 word0;
    u32 word1;
    u32 word2;
    u32 word3;
    u32 word4;
    u32 word5;
    u32 word6;
    u32 word7;
    u32 word8;
    u32 word9;
    u32 word10;
    u32 word11;
    u32 word12;
    u32 word13;
    u32 word14;
};
extern StateTable8035B348 lbl_804AD2D0;
extern "C" u8 lbl_8050B9F8[];

extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" char lbl_804AD348[];
extern "C" unsigned char sincosTable___5JMath[];
extern "C" const f32 lbl_8054286C;
extern "C" const f32 lbl_8054287C;
extern "C" const f32 lbl_80542880;
extern "C" const f32 lbl_80542884;
extern "C" const f32 lbl_8054288C;
extern "C" u8* lbl_8053AC98;
extern "C" u8* lbl_8053AAF8;
extern "C" const f32 lbl_80542890;
extern "C" const f32 lbl_80542894;
extern "C" const f32 lbl_80542898;
extern "C" const u16 lbl_80542868[2];
extern "C" const f32 lbl_80542870;
extern "C" const f32 lbl_8054289C;
extern "C" const f32 lbl_805428A0;
extern "C" const f32 lbl_805428A4;
extern "C" const f32 lbl_805428A8;
extern "C" const f32 lbl_805428AC;
extern "C" s32 fn_8023DE58(void*);
struct Vec8035A860 {
    f32 x, y, z;
    Vec8035A860& operator-=(const Vec8035A860& o) {
        x -= o.x;
        y -= o.y;
        z -= o.z;
        return *this;
    }
};
extern "C" unsigned char sincosTable___5JMath[];
extern "C" u8 fn_8023F264(s32 i);
extern "C" void fn_8022DF48(void*);
extern "C" void fn_8022E088(void*, s32, Vec8035A860*);
extern "C" s32 fn_8035AE9C(u8* self, void* obj);
extern "C" void fn_801F317C(u8* self, f32* out);
extern "C" u8* fn_801902C0(void);
extern "C" void fn_8022E088(void*, s32, Vec8035A860*);
extern "C" void fn_8035AA54(u8* self);
extern "C" void fn_801F0D20(u8* self, s32 i);
extern "C" bool fn_8022D75C(void*);
extern "C" bool fn_80230188(void*);
extern "C" bool fn_8022F514(void*);
extern "C" void fn_8023DF68(s32, Vec8035A860*);
extern "C" void fn_802314D8(s32, f32*);
extern "C" u8 fn_80235448(s32 i);
extern "C" void fn_802A381C(u8* a, Vec8035A860* v, s32 room, u16 idx);
extern "C" u8 fn_8023AAF8(s32 i, f32* box, s32 room, Vec8035A860* out);
static inline void spawnGridCounter803597EC(u8* self, u16 idx, s32 state, s32& k) {
    JGeometry::TVec3f vec;
    JGeometry::TVec3f saved;
    vec = *(JGeometry::TVec3f*)(self + 0xc) + JGeometry::TVec3f(*(f32*)(self + 0x60), *(f32*)(self + 0x64), lbl_8054286C);
    saved = vec;
    *(s32*)(self + 0x258) = state;
    for (k = 0; k < 6; ++k) {
        for (s32 j = 0; j < 6; ++j) {
            fn_802A381C(lbl_8053AC98, (Vec8035A860*)&vec, *(s32*)(self + 4), idx);
            vec.y += lbl_80542870;
        }
        vec.y = saved.y;
        vec.x += lbl_80542870;
    }
}
static inline void applyRotationCounter803597EC(u8* self, s32& i) {
    s16 ang;
    f32 d;
    f32 cs;
    for (i = 0; i < 4; i++) {
        if (fn_8023F264(i) && (s8)self[0x246 + i] != 0 && !fn_8022D75C((void*)i) && !fn_80230188((void*)i) && !fn_8022F514((void*)i)) {
            ang = *(s16*)(self + 0x230);
            f32 sn = JMath::sincosTable_.mTable[(u16)ang >> 5].first;
            f32 an = __fabsf(sn);
            cs = lbl_8054288C * (sn * an);
            if (*(u8*)(lbl_8053AAF8 + 0x7e) != 0 && (s32)((*(u32*)(self + 0x90) >> 7) & 0x1f) >= 2) {
                cs = cs * lbl_80542890;
            }
            if (*(u8*)(self + 0x244) == 0) {
                if (*(s32*)(self + 0x258) == 1) {
                    Vec8035A860 vec;
                    vec.x = lbl_8054286C;
                    vec.y = lbl_80542894 * cs;
                    vec.z = lbl_8054286C;
                    fn_8023DF68(i, &vec);
                }
            } else {
                if (*(s32*)(self + 0x258) == 1) {
                    Vec8035A860 vec;
                    vec.x = lbl_8054286C;
                    vec.y = cs;
                    vec.z = lbl_8054286C;
                    fn_8023DF68(i, &vec);
                }
            }
        }
    }
}
static inline void probeContactsCounter80358F98(u8* self, s32& i, f32* box, f32* v8) {
    f32 d;
    f32 py;
    s8 r;
    for (i = 0; i < 4; i++) {
        u8* q = self + i;
        q[0x246] = 0;
        q[0x24a] = 0;
        if (!fn_8023F264(i)) continue;
        q[0x246] = fn_8035AE9C(self, (void*)i);
        fn_801F317C(self, box);
        py = *(f32*)(self + 0x10);
        f32 c = __fabsf(*(f32*)(sincosTable___5JMath + ((u16)*(s16*)(self + 0x230) >> 5) * 8 + 4));
        box[1] = c * (box[1] - py) + py;
        box[3] = c * (box[3] - py) + py;
        if (fn_8023AAF8(i, box, *(s32*)(self + 0x4), (Vec8035A860*)v8)) {
            d = py - v8[1];
            if (self[0x24e] != 0 && lbl_8054286C == d) {
                d = lbl_8054287C;
            }
            if (self[0x24e] == 0 && __fabsf(d) <= lbl_80542880) {
                d = lbl_8054286C;
            }
            *(f32*)(self + 0x240) += lbl_80542884 * d;
            if (d >= lbl_8054286C) {
                r = 1;
            } else {
                r = -1;
            }
        } else {
            r = 0;
        }
        q[0x24a] = r;
    }
}
static inline void pushOpposedCounter80358F98(u8* self, s32& a, s32& b) {
    Vec8035A860 cv;
    for (a = 0; a < 4; a++) {
        if ((s8)self[0x24a + a] != 0) {
            for (b = 0; b < 4; b++) {
                u8 t;
                if (!fn_8022F514((void*)b) && (s8)self[0x24a + b] == 0 && (s8)(t = self[0x246 + b]) != 0 &&
                    (s8)self[0x24a + a] * (s8)t < 0) {
                    cv.x = lbl_8054286C;
                    cv.y = lbl_8054286C;
                    cv.z = lbl_80542898;
                    fn_802314D8(b, (f32*)&cv);
                }
            }
        }
    }
}
extern "C" Actor* fn_80358460(Actor* p, s16 n) {
    if (p != 0) {
        *(void**)p = lbl_804AD348;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" s8 fn_8035AC84(u8* self, s32 i);
extern "C" bool fn_8023EFEC(s32 i);
extern "C" u32 fn_8023EEB4(s32 i);
extern "C" s32 fn_8023EF50(s32 i);
extern "C" void* fn_801F856C(void);
extern "C" Actor* fn_801F666C(void*, s32);
extern "C" void fn_8013CC50(s32, void*, s32, s32, s32, s32, s32, s32, f32);
extern "C" const f32 lbl_80542878;
extern "C" const f32 lbl_80542888;
extern "C" void fn_803584C0(u8* self) {
    JGeometry::TVec3f dv1;
    Vec8035A860 cv;
    f32 box[4];
    Vec8035A860 vB;
    Vec8035A860 vA;
    JGeometry::TVec3f dv2;
    s16 ang0;
    s32 i;
    s32 x;
    s32 k;
    s32 j;
    bool ok;
    u32 idx;
    f32 d;
    f32 py;
    s8 r;
    f32 v8[2];

    if (*(s32*)(self + 0x250) > 0) {
        *(s32*)(self + 0x250) -= 1;
    }
    if (*(s32*)(self + 0x26c) > 0) {
        *(s32*)(self + 0x26c) -= 1;
    }
    if (self[0x245] != 0) {
        u8* p = fn_801902C0();
        s32 cnt = *(s32*)(p + 0x79c);
        if (cnt < 0x10) {
            f32* v = (f32*)(p + cnt * 0x18 + 0x61c);
            v[0] = *(f32*)(self + 0xc);
            v[1] = *(f32*)(self + 0x10);
            v[2] = *(f32*)(self + 0x14);
            p[*(s32*)(p + 0x79c) * 0x18 + 0x628] = 0;
            *(s32*)(p + 0x79c) += 1;
        }
    }
    *(f32*)(self + 0x240) = lbl_8054286C;
    for (i = 0; i < 4; i++) {
        self[0x246 + i] = 0;
        self[0x24a + i] = 0;
        if (!fn_8023F264(i)) continue;
        self[0x246 + i] = fn_8035AC84(self, i);
        fn_801F317C(self, box);
        py = *(f32*)(self + 0x10);
        f32 cs=__fabsf(*(f32*)(sincosTable___5JMath + ((u16)*(s16*)(self + 0x230) >> 5) * 8 + 4));
        f32 bottom=box[1]-py;
        f32 top=box[3]-py;
        box[1]=bottom*cs+py;
        box[3]=top*cs+py;
        if (fn_8023AAF8(i, box, *(s32*)(self + 0x4), (Vec8035A860*)v8)) {
            d = py - v8[1];
            if (self[0x24e] != 0 && lbl_8054286C == d) {
                d = lbl_8054287C;
            }
            if (self[0x24e] == 0 && __fabsf(d) <= lbl_80542880) {
                d = lbl_8054286C;
            }
            *(f32*)(self + 0x240) += lbl_80542884 * d;
            if (d >= lbl_8054286C) {
                r = 1;
            } else {
                r = -1;
            }
        } else {
            r = 0;
        }
        self[0x24a + i] = r;
        Actor* h = *(Actor**)(self + 0x25c + i * 4);
        if (h == 0) {
            if (fn_8023EFEC(i) && fn_8023EEB4(i) == 'YASI') {
                x = fn_8023EF50(i);
                *(Actor**)(self + 0x25c + i * 4) = fn_801F666C(fn_801F856C(), x);
            }
        } else if (h->field_11C == 0) {
            *(Actor**)(self + 0x25c + i * 4) = 0;
        } else if (*(s16*)(self + 0x230) == 0) {
            if (!((JGeometry::TVec3f*)&h->field_3C)->isZero() && h->field_0C.z + h->field_3C.z < lbl_80542878) {
                dv1 = *(JGeometry::TVec3f*)&h->field_0C;
                dv1 -= *(JGeometry::TVec3f*)(self + 0xc);
                f32 x0 = *(f32*)(self + 0x60);
                f32 y0 = *(f32*)(self + 0x64);
                f32 x1 = *(f32*)(self + 0x68);
                f32 y1 = *(f32*)(self + 0x6c);
                bool inside = false;
                if (dv1.x >= x0 && dv1.y >= y0 && dv1.x < x1 && dv1.y < y1) {
                    inside = true;
                }
                if (inside) {
                    (*(Actor**)(self + 0x25c + i * 4))->v16();
                    *(Actor**)(self + 0x25c + i * 4) = 0;
                    if (dv1.y >= lbl_8054286C) {
                        *(s16*)(self + 0x270) = 0x20;
                    } else {
                        *(s16*)(self + 0x270) = -0x20;
                    }
                    *(s32*)(self + 0x26c) = 200;
                }
            }
        }
    }
    if (*(s32*)(self + 0x250) == -1) {
        for (i = 0; i < 4; i++) {
            if ((s8)self[0x246 + i] != 0) {
                for (j = 0; j < 4; j++) {
                    if ((s8)self[0x246 + j] == 0) {
                        *(s32*)(self + 0x250) = 6;
                        break;
                    }
                }
            }
        }
    }
    if (((s8)self[0x24a] | (s8)self[0x24b] | (s8)self[0x24c] | (s8)self[0x24d]) != 0 &&
        lbl_8054286C != *(f32*)(self + 0x240)) {
        fn_801F0D20(self, 3);
    }
    for (i = 0; i < 4; i++) {
        if (!fn_8023F264(i)) continue;
        if ((s8)self[0x246 + i] == 0) continue;
        if (fn_8022D75C((void*)i)) continue;
        if (fn_80230188((void*)i)) continue;
        if (fn_8022F514((void*)i)) continue;
        f32 sn = *(f32*)(sincosTable___5JMath + ((u16)*(s16*)(self + 0x230) >> 5) * 8);
        f32 kk = lbl_8054288C * (sn * __fabsf(sn));
        if (lbl_8053AAF8[0x7e] != 0 && (s32)((*(u32*)(self + 0x90) >> 7) & 0x1f) >= 2) {
            kk = kk * lbl_80542890;
        }
        if (self[0x244] == 0) {
            if (*(s32*)(self + 0x258) == 1) {
                vA.x = lbl_8054286C;
                vA.y = lbl_80542894 * kk;
                vA.z = lbl_8054286C;
                fn_8023DF68(i, &vA);
            }
        } else {
            if (*(s32*)(self + 0x258) == 1) {
                vB.x = lbl_8054286C;
                vB.y = kk;
                vB.z = lbl_8054286C;
                fn_8023DF68(i, &vB);
            }
        }
    }
    for (j = 0; j < 4; j++) {
        if ((s8)self[0x24a + j] != 0) {
            for (i = 0; i < 4; i++) {
                if (fn_8022F514((void*)i)) continue;
                if ((s8)self[0x24a + i] != 0) continue;
                u8 t = self[0x246 + i];
                if ((s8)t == 0) continue;
                if ((s8)self[0x24a + j] * (s8)t >= 0) continue;
                cv.x = lbl_8054286C;
                cv.y = lbl_8054286C;
                cv.z = lbl_80542898;
                fn_802314D8(i, (f32*)&cv);
            }
        }
    }
    fn_8035AA54(self);
    ang0 = *(s16*)(self + 0x230);
    if (ang0 != 0x3e00 && ang0 != -0x3e00) {
        ok = true;
    } else {
        f32 x0 = *(f32*)(self + 0x60);
        f32 y0 = *(f32*)(self + 0x64);
        f32 x1 = *(f32*)(self + 0x68);
        f32 y1 = *(f32*)(self + 0x6c);
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 8; j++) {
                fn_8022E088((void*)i, j, (Vec8035A860*)&dv2);
                dv2 -= *(JGeometry::TVec3f*)(self + 0xc);
                dv2.z = lbl_8054286C;
                bool inside = false;
                if (dv2.x >= x0 && dv2.y >= y0 && dv2.x < x1 && dv2.y < y1) {
                    inside = true;
                }
                if (inside) {
                    ok = false;
                    goto done;
                }
            }
        }
        ok = true;
    }
done:
    if (!ok) {
        *(s16*)(self + 0x238) = 0;
    }
    *(s16*)(self + 0x230) += *(s16*)(self + 0x238);
    if (*(s16*)(self + 0x238) > 0 && *(s16*)(self + 0x230) >= 0x3e00) {
        *(s16*)(self + 0x230) = 0x3e00;
        *(s16*)(self + 0x238) = 0;
        *(s16*)(self + 0x23a) = 0;
    } else if (*(s16*)(self + 0x238) < 0 && *(s16*)(self + 0x230) <= -0x3e00) {
        *(s16*)(self + 0x230) = -0x3e00;
        *(s16*)(self + 0x238) = 0;
        *(s16*)(self + 0x23a) = 0;
    } else if (lbl_8054286C == *(f32*)(self + 0x240) && *(s16*)(self + 0x230) * ang0 <= 0) {
        k = 0;
        *(s16*)(self + 0x230) = k;
        *(s16*)(self + 0x238) = k;
        *(s16*)(self + 0x23a) = k;
        self[0x245] = k;
        idx = lbl_80542868[0];
        JGeometry::TVec3f offset(*(f32*)(self + 0x60), *(f32*)(self + 0x64), lbl_8054286C);
        JGeometry::TVec3f pos = *(JGeometry::TVec3f*)(self + 0xc) + offset;
        JGeometry::TVec3f start = pos;
        *(s32*)(self + 0x258) = k;
        for (; k < 6; k++) {
            for (j = 0; j < 6; j++) {
                fn_802A381C(lbl_8053AC98, (Vec8035A860*)&pos, *(s32*)(self + 4), idx);
                pos.y += lbl_80542870;
            }
            pos.y = start.y;
            pos.x += lbl_80542870;
        }
        if (*(s32*)(self + 0x250) == 0) {
            *(s32*)(self + 0x250) = -1;
        }
    }
    if (ang0 == 0 && *(s16*)(self + 0x230) != 0) {
        fn_8013CC50(*(s32*)(self + 4), self + 0xc, 0x3de, 0, 0, 0, 0, 1, lbl_80542878);
        fn_8013CC50(*(s32*)(self + 4), self + 0xc, 0x3df, 0, 0, 0, 0, 1, lbl_80542878);
        fn_8013CC50(*(s32*)(self + 4), self + 0xc, 0x3e0, 0, 0, 0, 0, 1, lbl_80542878);
        fn_8013CC50(*(s32*)(self + 4), self + 0xc, 0x3e1, 0, 0, 0, 0, 1, lbl_80542878);
        self[0x245] = 1;
        idx = lbl_80542868[1];
        JGeometry::TVec3f offset(*(f32*)(self + 0x60), *(f32*)(self + 0x64), lbl_8054286C);
        JGeometry::TVec3f pos = *(JGeometry::TVec3f*)(self + 0xc) + offset;
        JGeometry::TVec3f start = pos;
        *(s32*)(self + 0x258) = 1;
        for (j = 0; j < 6; j++) {
            for (k = 0; k < 6; k++) {
                fn_802A381C(lbl_8053AC98, (Vec8035A860*)&pos, *(s32*)(self + 4), idx);
                pos.y += lbl_80542870;
            }
            pos.y = start.y;
            pos.x += lbl_80542870;
        }
    }
    if (*(s16*)(self + 0x230) != 0) {
        *(s32*)(self + 0x250) = 0;
    }
    if (*(s16*)(self + 0x230) == 0 &&
        (((s8)self[0x246] | (s8)self[0x247] | (s8)self[0x248] | (s8)self[0x249]) != 0 || *(s32*)(self + 0x26c) != 0)) {
        if (*(s32*)(self + 0x26c) != 0) {
            *(s16*)(self + 0x23c) += *(s16*)(self + 0x270);
            if (*(s16*)(self + 0x23c) >= 0xc80 || *(s16*)(self + 0x23c) < -0xc80) {
                *(s16*)(self + 0x23e) *= -1;
            }
        } else {
            *(s16*)(self + 0x23c) += *(s16*)(self + 0x23e);
            if (*(s16*)(self + 0x23c) >= 0x640 || *(s16*)(self + 0x23c) < -0x640) {
                *(s16*)(self + 0x23e) *= -1;
            }
        }
    } else {
        *(s16*)(self + 0x23c) = 0;
    }
}

extern "C" void fn_80358F98(u8* self) {
    Vec8035A860 cv;
    f32 box[4];
    f32 v8[2];
    f32 d;
    f32 py;
    s32 i;
    u8* q;
    s32 a;
    s32 b;
    s32 k;
    s8 r;
    s16 old;

    if (self[0x245] != 0) {
        u8* p = fn_801902C0();
        if (*(s32*)(p + 0x79c) < 0x10) {
            f32* v = (f32*)(p + *(s32*)(p + 0x79c) * 0x18 + 0x61c);
            v[0] = *(f32*)(self + 0xc);
            v[1] = *(f32*)(self + 0x10);
            v[2] = *(f32*)(self + 0x14);
            p[*(s32*)(p + 0x79c) * 0x18 + 0x628] = 0;
            *(s32*)(p + 0x79c) += 1;
        }
    }
    *(f32*)(self + 0x240) = lbl_8054286C;
    for (i = 0; i < 4; i++) {
        q = self + i;
        q[0x246] = 0;
        q[0x24a] = 0;
        if (!fn_8023F264(i)) continue;
        q[0x246] = fn_8035AE9C(self, (void*)i);
        fn_801F317C(self, box);
        py = *(f32*)(self + 0x10);
        f32 c = __fabsf(*(f32*)(sincosTable___5JMath + ((u16)*(s16*)(self + 0x230) >> 5) * 8 + 4));
        box[1] = c * (box[1] - py) + py;
        box[3] = c * (box[3] - py) + py;
        if (fn_8023AAF8(i, box, *(s32*)(self + 0x4), (Vec8035A860*)v8)) {
            d = py - v8[1];
            if (self[0x24e] != 0 && lbl_8054286C == d) {
                d = lbl_8054287C;
            }
            if (self[0x24e] == 0 && __fabsf(d) <= lbl_80542880) {
                d = lbl_8054286C;
            }
            *(f32*)(self + 0x240) += lbl_80542884 * d;
            if (d >= lbl_8054286C) {
                r = 1;
            } else {
                r = -1;
            }
        } else {
            r = 0;
        }
        q[0x24a] = r;
    }
    if (((s8)self[0x24a] | (s8)self[0x24b] | (s8)self[0x24c] | (s8)self[0x24d]) != 0 &&
        lbl_8054286C != *(f32*)(self + 0x240)) {
        fn_801F0D20(self, 3);
    }
    applyRotationCounter803597EC(self, i);
    for (a = 0; a < 4; a++) {
        if ((s8)self[0x24a + a] != 0) {
            for (b = 0; b < 4; b++) {
                u8 t;
                if (!fn_8022F514((void*)b) && (s8)self[0x24a + b] == 0 && (s8)(t = self[0x246 + b]) != 0 &&
                    (s8)self[0x24a + a] * (s8)t < 0) {
                    cv.x = lbl_8054286C;
                    cv.y = lbl_8054286C;
                    cv.z = lbl_80542898;
                    fn_802314D8(b, (f32*)&cv);
                }
            }
        }
    }
    if (lbl_8054286C != *(f32*)(self + 0x240)) {
        if (lbl_8053AAF8[0x7e] == 0) {
            if (*(f32*)(self + 0x240) > lbl_8054286C) {
                *(f32*)(self + 0x240) = lbl_8054289C;
            } else {
                *(f32*)(self + 0x240) = lbl_805428A0;
            }
        } else {
            if (*(f32*)(self + 0x240) > lbl_8054286C) {
                *(f32*)(self + 0x240) = lbl_80542898;
            } else {
                *(f32*)(self + 0x240) = lbl_805428A4;
            }
        }
        *(s16*)(self + 0x23a) = (s16)*(f32*)(self + 0x240);
    } else {
        *(s16*)(self + 0x23a) = (s16)((-(lbl_8054287C * (f32)*(s16*)(self + 0x238)) - lbl_805428A8 * (f32)*(s16*)(self + 0x230)) / lbl_805428AC);
    }
    *(s16*)(self + 0x238) += *(s16*)(self + 0x23a);
    old = *(s16*)(self + 0x230);
    *(s16*)(self + 0x230) = old + *(s16*)(self + 0x238);
    if ((s32)((*(u32*)(self + 0x90) >> 7) & 0x1f) == 2) {
        if (*(s16*)(self + 0x230) <= -0x3e00) {
            *(s16*)(self + 0x230) = -0x3e00;
            *(s16*)(self + 0x238) = 0;
            *(s16*)(self + 0x23a) = 0;
        } else if (*(s16*)(self + 0x230) >= 0) {
            *(s16*)(self + 0x230) = 0;
            *(s16*)(self + 0x238) = 0;
            *(s16*)(self + 0x23a) = 0;
            self[0x245] = 0;
            spawnGridCounter803597EC(self, lbl_80542868[0], 0, k);
        }
    } else {
        if (*(s16*)(self + 0x230) >= 0x3e00) {
            *(s16*)(self + 0x230) = 0x3e00;
            *(s16*)(self + 0x238) = 0;
            *(s16*)(self + 0x23a) = 0;
        } else if (*(s16*)(self + 0x230) <= 0) {
            *(s16*)(self + 0x230) = 0;
            *(s16*)(self + 0x238) = 0;
            *(s16*)(self + 0x23a) = 0;
            self[0x245] = 0;
            spawnGridCounter803597EC(self, lbl_80542868[0], 0, k);
        }
    }
    if (old == 0 && *(s16*)(self + 0x230) != 0) {
        fn_8013CC50(*(s32*)(self + 4), self + 0xc, 0x3de, 0, 0, 0, 0, 1, lbl_80542878);
        fn_8013CC50(*(s32*)(self + 4), self + 0xc, 0x3df, 0, 0, 0, 0, 1, lbl_80542878);
        fn_8013CC50(*(s32*)(self + 4), self + 0xc, 0x3e0, 0, 0, 0, 0, 1, lbl_80542878);
        fn_8013CC50(*(s32*)(self + 4), self + 0xc, 0x3e1, 0, 0, 0, 0, 1, lbl_80542878);
        self[0x245] = 1;
        spawnGridCounter803597EC(self, lbl_80542868[1], 1, k);
    }
}

extern "C" void fn_801F0D20(u8* self, s32 i);
extern "C" bool fn_8022D75C(void*);
extern "C" bool fn_80230188(void*);
extern "C" bool fn_8022F514(void*);
extern "C" void fn_8023DF68(s32, Vec8035A860*);
extern "C" void fn_802314D8(s32, f32*);
extern "C" u8 fn_80235448(s32 i);
extern "C" void fn_802A381C(u8* a, Vec8035A860* v, s32 room, u16 idx);
extern "C" void fn_803597EC(u8* object) {
    u8* self;
    u8* q;
    s32 flags;
    s32 i;
    s32 a;
    s32 b;
    s16 vel;
    s16 ang;
    f32 cs;
    f32 cv[3];
    f32 box[4];
    f32 d;
    f32 py;
    u16 idx;
    s32 k;
    s32 j;
    f32 v8[2];

    self = object;
    flags = 0;
    *(f32*)(self + 0x240) = lbl_8054286C;
    *(u8*)(self + 0x24e) = 0;
    if (*(s32*)(self + 0x254) != 0) {
        *(s32*)(self + 0x254) -= 1;
        if (*(s32*)(self + 0x254) == 0) {
            fn_801F0D20(self, 3);
        }
    }
    for (i = 0; i < 4; i++) {
        q = self + i;
        q[0x246] = 0;
        q[0x24a] = 0;
        if (fn_8023F264(i)) {
            q[0x246] = fn_8035AE9C(self, (void*)i);
            if (fn_80235448(i) && (s8)q[0x246] != 0) {
                *(u8*)(self + 0x24e) |= 1 << i;
            }
        }
        fn_801F317C(self, box);
        ang = *(s16*)(self + 0x230);
        py = *(f32*)(self + 0x10);
        f32 csd = __fabsf(JMath::sincosTable_.mTable[(u16)ang >> 5].second);
        box[1] = (box[1] - py) * csd + py;
        box[3] = (box[3] - py) * csd + py;
        s32 hit;
        if (fn_8023AAF8(i, box, *(s32*)(self + 4), (Vec8035A860*)v8)) {
            d = py - v8[1];
            if (self[0x24e] != 0 && lbl_8054286C == d) d = lbl_8054287C;
            if (self[0x24e] == 0 && __fabs(d) <= lbl_80542880) d = lbl_8054286C;
            *(f32*)(self + 0x240) += lbl_80542884 * d;
            hit = d >= lbl_8054286C ? 1 : -1;
        } else {
            hit = 0;
        }
        q[0x24a] = hit;
        flags |= *(u8*)(self + 0x24e);
        flags |= (s8)q[0x24a] << i;
    }
    if (flags != 0) {
        if (*(s16*)(self + 0x238) == 0 && lbl_8054286C != *(f32*)(self + 0x240)) {
            *(s32*)(self + 0x254) = 30;
            spawnGridCounter803597EC(self, lbl_80542868[1], 1, flags);
        }
        if (*(f32*)(self + 0x240) > lbl_8054286C) {
            *(s16*)(self + 0x238) = 0x200;
        } else if (*(f32*)(self + 0x240) < lbl_8054286C) {
            *(s16*)(self + 0x238) = -0x200;
        }
    }
    applyRotationCounter803597EC(self, i);
    for (a = 0; a < 4; a++) {
        if ((s8)self[0x24a + a] != 0) {
            for (b = 0; b < 4; b++) {
                if (!fn_8022F514((void*)b) && (s8)self[0x24a + b] == 0 && (s8)self[0x246 + b] != 0 &&
                    (s8)self[0x24a + a] * (s8)self[0x246 + b] < 0) {
                    cv[0] = lbl_8054286C;
                    cv[1] = lbl_8054286C;
                    cv[2] = lbl_80542898;
                    fn_802314D8(b, cv);
                }
            }
        }
    }
    ang = *(s16*)(self + 0x230);
    *(s16*)(self + 0x230) = ang + *(s16*)(self + 0x238);
    vel = *(s16*)(self + 0x238);
    if (vel < 0) {
        if ((ang > 0x4000 && *(s16*)(self + 0x230) <= 0x4000) ||
            (ang >= -0x4000 && *(s16*)(self + 0x230) < -0x4000)) self[0x244] ^= 1;
    } else if (vel > 0) {
        if ((ang <= 0x4000 && *(s16*)(self + 0x230) > 0x4000) ||
            (ang < -0x4000 && *(s16*)(self + 0x230) >= -0x4000)) self[0x244] ^= 1;
    }
    if (*(s16*)(self + 0x230) == 0 || *(s16*)(self + 0x230) == -0x8000) {
        if (*(s16*)(self + 0x238) != 0) {
            spawnGridCounter803597EC(self, lbl_80542868[0], 0, flags);
        }
        *(s16*)(self + 0x238) = 0;
    }
}

#pragma optimization_level 3
extern "C" void fn_80359E18(u8* self)
{
    DrawRec rec;
    Mtx mtx;
    mtx[0][3] = lbl_8054286C;
    mtx[1][3] = lbl_8054286C;
    mtx[2][3] = lbl_8054286C;
    if ((s32)((*(u32*)(self + 0x90) >> 7) & 0x1f) == 4 && *(s16*)(self + 0x230) == 0) {
        rotationEuler80359E18(mtx, *(s16*)(self + 0x23c), 0, 0, lbl_80542878);
    } else {
        rotationEuler80359E18(mtx, *(s16*)(self + 0x230), 0, 0, lbl_80542878);
    }
    rec.w18 = mtx;
    rec.b21 = 1;
    rec.b1d = -2;
    rec.b25 = 1;
    if ((s32)(*(u32*)(self + 0x90) & 0x7f) == 1) rec.b24 = 1;
    u32 resource = lbl_8053A1B8[*(u32*)(self + 0x90) & 0x7f];
    if (*(s32*)(self + 4) < 8) {
        void* texture = (*(ResMgr8035B0E0**)(lbl_8053AAF8 + 0xa4))->vf18('TIMG', resource);
        fn_802F745C(*(void**)((u8*)lbl_8053AB10 + 0x20), self + 0xc, texture, &rec);
    }
    if ((s32)((*(u32*)(self + 0x90) >> 7) & 0x1f) < 2) {
        *(s8*)&rec.b1c = -1;
        rec.b1d = -2;
        mtx[0][3] = lbl_8054286C;
    mtx[1][3] = lbl_8054286C;
    mtx[2][3] = lbl_8054286C;
        mtx[0][0] = 1.5f;
        mtx[0][1] = lbl_8054286C;
        mtx[0][2] = lbl_8054286C;
        mtx[1][0] = lbl_8054286C;
        mtx[1][1] = 1.5f;
        mtx[1][2] = lbl_8054286C;
        mtx[2][0] = lbl_8054286C;
        mtx[2][1] = lbl_8054286C;
        mtx[2][2] = 1.5f;
        rec.w18 = mtx;
        void* texture = (*(ResMgr8035B0E0**)(lbl_8053AAF8 + 0xa4))->vf18('TIMG', (u32)lbl_804724E0);
        JGeometry::TVec3<f32> pos;
        pos.set(*(f32*)(self + 0xc), *(f32*)(self + 0x10), lbl_8054286C);
        if (*(s32*)(self + 4) < 8) {
            fn_802F745C(*(void**)((u8*)lbl_8053AB10 + 0x20), &pos, texture, &rec);
        }
    }
}
#pragma optimization_level reset
extern "C" void fn_8035A1D4(Unk8035A1D4* self) {
    u32 v = *(u32*)((u8*)self + 0x90);
    (self->*lbl_804AD30C[(v >> 7) & 0x1f])();
}

extern "C" const f32 lbl_805428AC;
extern "C" const f32 lbl_805428BC;
extern "C" const f32 lbl_805428C0;
#pragma peephole off
extern "C" void fn_8035A210(u8* self) {
    f32 cv[3];
    f32 box[4];
    f32 tmp[2];
    u8* p;
    u8* q;
    s32 i;
    s32 m;
    s32 r;
    s32 flags;
    s16 rot;
    f32 py;
    s16 vel;
    s16 old;
    f32 c;
    f32 dy;
    f32 sn;
    f32 k;

    p = self;
    *(f32*)(p + 0x240) = lbl_8054286C;
    for (i = 0; i < 4; i++) {
        q = p + i;
        q[0x246] = 0;
        q[0x24a] = 0;
        if (fn_8023F264(i)) {
            q[0x246] = fn_8035AE9C(p, (void*)i);
            fn_801F317C(p, box);
            rot = *(s16*)(p + 0x230);
            py = *(f32*)(p + 0x10);
            const f32 scale = __fabsf(*(f32*)(sincosTable___5JMath + ((u16)rot >> 5) * 8 + 4));
            box[1] = (box[1] - py) * scale + py;
            box[3] = (box[3] - py) * scale + py;
            if (fn_8023AAF8(i, box, *(s32*)(p + 4), (Vec8035A860*)tmp)) {
                dy = py - tmp[1];
                if (p[0x24e] != 0 && lbl_8054286C == dy) dy = lbl_8054287C;
                if (p[0x24e] == 0 && __fabs(dy) <= lbl_80542880) dy = lbl_8054286C;
                *(f32*)(p + 0x240) += lbl_80542884 * dy;
                r = dy >= lbl_8054286C ? 1 : -1;
            } else {
                r = 0;
            }
            q[0x24a] = r;
        }
    }

    flags = (s8)p[0x24a] | (s8)p[0x24b] | (s8)p[0x24c] | (s8)p[0x24d];
    if (flags != 0 && lbl_8054286C != *(f32*)(p + 0x240)) {
        fn_801F0D20(p, 3);
    }

    applyRotationCounter803597EC(p, i);

    for (m = 0; m < 4; m++) {
        if ((s8)p[0x24a + m] != 0) {
            for (i = 0; i < 4; i++) {
                if (fn_8022F514((void*)i)) continue;
                if ((s8)p[0x24a + i] != 0) continue;
                if ((s8)p[0x246 + i] == 0) continue;
                if ((s8)p[0x24a + m] * (s8)p[0x246 + i] >= 0) continue;
                cv[0] = lbl_8054286C;
                cv[1] = lbl_8054286C;
                cv[2] = lbl_80542898;
                fn_802314D8(i, cv);
            }
        }
    }

    if (p[0x244] == 0) {
        *(s16*)(p + 0x23a) = (s16)((*(f32*)(p + 0x240) - lbl_805428BC * (f32)*(s16*)(p + 0x238) - lbl_805428C0 * (f32)*(s16*)(p + 0x230)) / lbl_805428AC);
    }
    else if (*(s16*)(p + 0x230) > 0) {
        *(s16*)(p + 0x23a) = (s16)((*(f32*)(p + 0x240) - lbl_805428BC * (f32)*(s16*)(p + 0x238) - lbl_805428C0 * (f32)(*(s16*)(p + 0x230) - 0x8000)) / lbl_805428AC);
    } else {
        *(s16*)(p + 0x23a) = (s16)((*(f32*)(p + 0x240) - lbl_805428BC * (f32)*(s16*)(p + 0x238) - lbl_805428C0 * (f32)(*(s16*)(p + 0x230) + 0x8000)) / lbl_805428AC);
    }
    if (*(s16*)(p + 0x238) == 0 && *(s16*)(p + 0x23a) != 0) {
        spawnGridCounter803597EC(p, lbl_80542868[1], 1, m);
    }
    *(s16*)(p + 0x238) += *(s16*)(p + 0x23a);
    old = *(s16*)(p + 0x230);
    *(s16*)(p + 0x230) = old + *(s16*)(p + 0x238);
    vel = *(s16*)(p + 0x238);
    if (vel < 0) {
        if ((old > 0x4000 && *(s16*)(p + 0x230) <= 0x4000) ||
            (old >= -0x4000 && *(s16*)(p + 0x230) < -0x4000)) p[0x244] ^= 1;
    } else if (vel > 0) {
        if ((old <= 0x4000 && *(s16*)(p + 0x230) > 0x4000) ||
            (old < -0x4000 && *(s16*)(p + 0x230) >= -0x4000)) p[0x244] ^= 1;
    }
}
#pragma peephole reset
extern "C" Vec8035A860* fn_8023E724(void*);
extern "C" void fn_8022BE24(void*, Vec8035A860*);
extern "C" unsigned char sincosTable___5JMath[];
extern "C" void fn_8035A860(u8* self, void* obj, f32 speed) {
    Vec8035A860 sc;
    JGeometry::TVec3f d;
    d = *(JGeometry::TVec3f*)fn_8023E724(obj);
    d -= *(JGeometry::TVec3f*)(self + 0xc);
    bool inside = false;
    if (d.x >= *(f32*)(self + 0x60) + 10.0f && d.y >= *(f32*)(self + 0x64)
        && d.x < *(f32*)(self + 0x68) - 10.0f && d.y < *(f32*)(self + 0x6c)) {
        inside = true;
    }
    if (inside) {
        s16 ang = *(s16*)(self + 0x230);
        f32* tbl = (f32*)((char*)sincosTable___5JMath + ((u16)ang >> 5) * 8);
        f32 s = 0.5f * __fabsf(tbl[0]) * (__fabsf(speed) / (*(f32*)(self + 0x6c) * __fabsf(tbl[1])));
        if (s > 0.5f) s = 0.5f;
        f32 r;
        if (*(u8*)(self + 0x244) == 0) {
            if ((f32)*(s16*)(self + 0x230) * speed >= 0.0f) r = 1.0f - s;
            else r = 1.0f + s;
        } else {
            if ((f32)*(s16*)(self + 0x230) * speed >= 0.0f) r = 1.0f + s;
            else r = 1.0f - s;
        }
        sc.x = r;
        sc.y = 1.0f;
        sc.z = r;
        fn_8022BE24(obj, &sc);
    }
}

extern "C" u8* lbl_8053AAF8;
extern "C" s32 fn_8022CAF8(s32);
extern "C" void fn_8035AA54(u8* self) {
    u8 bVar2 = 0;
    u8 bVar5 = 0;
    s32 bVar3 = 0;
    u8 bVar4;
    if (*(s8*)(self + 0x246) != 0) {
        if (*(s8*)(self + 0x247) != 0) {
            if (*(s8*)(self + 0x248) != 0) {
                if (*(s8*)(self + 0x249) != 0) {
                    bVar2 = 1;
                }
            }
        }
    }
    if (bVar2 && __fabsf(*(f32*)(self + 0x240)) < 33.0f) {
        bVar5 = 1;
    }
    bVar4 = bVar5;
    if (lbl_8053AAF8[0x7e] == 0) {
        bVar4 = bVar5 & (fn_8022CAF8(0) == 1);
    }
    if (*(f32*)(self + 0x240) != 0.0f) {
        if (bVar4 || *(s32*)(self + 0x250) > 0) {
            if (lbl_8053AAF8[0x7e] == 0) {
                if (*(f32*)(self + 0x240) > 0.0f) {
                    *(f32*)(self + 0x240) = -1500.0f;
                } else {
                    *(f32*)(self + 0x240) = 1500.0f;
                }
            } else {
                if (*(f32*)(self + 0x240) > 0.0f) {
                    *(f32*)(self + 0x240) = -10.0f;
                } else {
                    *(f32*)(self + 0x240) = 10.0f;
                }
            }
            bVar3 = 1;
        } else {
            if (lbl_8053AAF8[0x7e] == 0) {
                if (*(f32*)(self + 0x240) > 0.0f) {
                    *(f32*)(self + 0x240) = 1500.0f;
                } else {
                    *(f32*)(self + 0x240) = -1500.0f;
                }
            } else {
                if (*(f32*)(self + 0x240) > 0.0f) {
                    *(f32*)(self + 0x240) = 10.0f;
                } else {
                    *(f32*)(self + 0x240) = -10.0f;
                }
            }
        }
        *(s16*)(self + 0x23a) = (s16)*(f32*)(self + 0x240);
    } else {
        *(s16*)(self + 0x23a) = (s16)((-(0.1f * (f32)*(s16*)(self + 0x238)) - 0.01f * (f32)*(s16*)(self + 0x230)) / 15.0f);
    }
    *(s16*)(self + 0x238) += *(s16*)(self + 0x23a);
    if (bVar3) {
        *(f32*)(self + 0x240) = 0.0f;
    }
}

extern "C" s8 fn_8035AC84(u8* self, s32 i) {
    Vec8035A860 out;
    u8* tbl = sincosTable___5JMath;
    s32 j;
    s16 ang;

    if (fn_8022D75C((void*)i)) return 0;
    if (fn_80230188((void*)i)) return 0;
    if (*(s32*)(self + 0x4) != fn_8023DE58((void*)i)) return 0;
    if (*(f32*)((u8*)fn_8023E724((void*)i) + 0x8) > lbl_8054286C) {
        fn_8022DF48((void*)i);
        return 0;
    }
    for (j = 0; j < 8; j++) {
        ang = *(s16*)(self + 0x230);
        if ((ang >= 0x3c00 && ang <= 0x4400) || (ang <= -0x3c00 && ang >= -0x4400)) return 0;
        fn_8022E088((void*)i, j, &out);
        out.x -= *(f32*)(self + 0xc);
        out.y -= *(f32*)(self + 0x10);
        out.z = lbl_8054286C;
        if (out.x >= *(f32*)(self + 0x60) && out.y >= *(f32*)(self + 0x64) * __fabsf(*(f32*)(tbl + ((u16)ang >> 5) * 8 + 4)) && out.x < *(f32*)(self + 0x68) && out.y < *(f32*)(self + 0x6c) * __fabsf(*(f32*)(tbl + ((u16)ang >> 5) * 8 + 4))) {
            fn_8022DF48((void*)i);
            if (*(f32*)(self + 0x10) - *(f32*)((u8*)fn_8023E724((void*)i) + 0x4) == lbl_8054286C) {
                *(f32*)(self + 0x240) += lbl_8054287C;
                fn_8035A860(self, (void*)i, lbl_8054287C);
                return lbl_8054287C >= lbl_8054286C ? -1 : 1;
            }
        }
    }
    return 0;
}

extern "C" bool fn_8022D75C(void*);
extern "C" bool fn_80230188(void*);
extern "C" s32 fn_8023DE58(void*);
extern "C" void fn_8022DF48(void*);
extern "C" void fn_8022E088(void*, s32, Vec8035A860*);
extern "C" bool fn_8022F514(void*);
extern "C" void fn_8023DF68(s32, Vec8035A860*);
extern "C" void fn_802314D8(s32, f32*);
extern "C" s32 fn_8035AE9C(u8* self, void* obj) {
    Vec8035A860 d;
    Vec8035A860* pos;
    f32 dy;
    u8 flag;
    s32 i;
    if (fn_8022D75C(obj)) return 0;
    if (fn_80230188(obj)) return 0;
    s32 v = *(s32*)(self + 4);
    if (fn_8023DE58(obj) != v) return 0;
    if (fn_8023E724(obj)->z > 0.0f) {
        fn_8022DF48(obj);
        return 0;
    }
    for (i = 0; i < 8; i++) {
        if (*(s16*)(self + 0x230) >= 0x3c00 && *(s16*)(self + 0x230) <= 0x4400) return 0;
        if (*(s16*)(self + 0x230) <= -0x3c00 && *(s16*)(self + 0x230) >= -0x4400) return 0;
        fn_8022E088(obj, i, &d);
        d.x -= *(f32*)(self + 0xc);
        d.y -= *(f32*)(self + 0x10);
        d.z = 0.0f;
        f32 c = __fabsf(*(f32*)(sincosTable___5JMath + ((u16)*(s16*)(self + 0x230) >> 5) * 8 + 4));
        f32 f2 = *(f32*)(self + 0x64) * c;
        f32 f3 = *(f32*)(self + 0x6c) * c;
        if (!(d.x >= *(f32*)(self + 0x60)) && !(d.y >= f2) && !(d.x >= *(f32*)(self + 0x68)) && !(d.y >= f3)) {
            fn_8022DF48(obj);
            pos = fn_8023E724(obj);
            flag = *(u8*)(self + 0x24e);
            dy = *(f32*)(self + 0x10) - pos->y;
            if (flag == 0) {
                if (__fabsf(dy) > 8.0f) dy = 0.0f;
            } else if (dy == 0.0f) {
                dy = 0.1f;
            }
            *(f32*)(self + 0x240) += dy;
            fn_8035A860(self, obj, dy);
            if (dy >= 0.0f) return -1;
            return 1;
        }
    }
    return 0;
}

extern "C" u32 lbl_8053A1B8[2];
extern "C" u32 lbl_8053A1B8[2];
extern "C" void fn_8035B0E0(u8* arg) {
    u8* self = arg;
    int x;
    f32 step;
    *(void**)(self + 0x234) = (*(ResMgr8035B0E0**)(lbl_8053AAF8 + 0xa4))->vf18(0x3f3f3f3f, lbl_8053A1B8[*(u32*)(self + 0x90) & 0x7f]);
    u16* size = *(u16**)(self + 0x234);
    ((JGeometry::TBox2f*)(self + 0x60))->set(-size[1] / 2, -size[2] / 2, size[1] / 2, size[2] / 2);
    x = 0;
    *(s32*)(self + 0x108) = x;
    *(s16*)(self + 0x230) = x;
    *(s16*)(self + 0x238) = x;
    *(s16*)(self + 0x23a) = x;
    *(s16*)(self + 0x23c) = x;
    *(s16*)(self + 0x23e) = 24;
    *(f32*)(self + 0x240) = lbl_8054286C;
    self[0x244] = x; self[0x245] = x; self[0x24e] = x;
    for (int i=0;i<4;i++) {self[0x246+i]=0; self[0x24a+i]=0;}
    *(s32*)(self+0x250)=0;
    *(s32*)(self+0x26c)=0;
    for (int i=0;i<8;i++) *(s32*)(self+0x25c+i*4)=0;
    JGeometry::TVec3f offset(*(f32*)(self+0x60),*(f32*)(self+0x64),lbl_8054286C);
    JGeometry::TVec3f pos = *(JGeometry::TVec3f*)(self+0xc);
    pos += offset;
    JGeometry::TVec3f start = pos;
    u16 idx = lbl_80542868[0];
    step = lbl_80542870;
    *(s32*)(self+0x258)=0;
    for(;x<6;x++) {
        for(int y=0;y<6;y++) {
            fn_802A381C(lbl_8053AC98,(Vec8035A860*)&pos,*(s32*)(self+4),idx);
            pos.y += step;
        }
        pos.y = start.y;
        pos.x += lbl_80542870;
    }
}

#pragma opt_propagation off

extern "C" void fn_8035B348(void) {
    u8* records = lbl_8050B9F8;
    StateTable8035B348* table = &lbl_804AD2D0;
    u32* src = (u32*)table;
    u32* dst = src + 15;
    u32 word14;
    u32 word13;
    u32 word12;
    u32 word11;
    u32 word10;
    u32 word9;
    u32 word8;
    u32 word7;
    u32 word6;
    u32 word5;
    u32 word4;
    u32 word3;
    u32 word2;
    u32 word1;
    u32 word0;
    s8 initialized = __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
    word0 = src[0];
    word1 = src[1];
    word2 = src[2];
    word3 = src[3];
    word4 = src[4];
    word5 = src[5];
    word6 = src[6];
    word7 = src[7];
    word8 = src[8];
    word9 = src[9];
    word10 = src[10];
    word11 = src[11];
    word12 = src[12];
    word13 = src[13];
    word14 = src[14];
    dst[0] = word0;
    dst[1] = word1;
    dst[2] = word2;
    dst[3] = word3;
    dst[4] = word4;
    dst[5] = word5;
    dst[6] = word6;
    dst[7] = word7;
    dst[8] = word8;
    dst[9] = word9;
    dst[10] = word10;
    dst[11] = word11;
    dst[12] = word12;
    dst[13] = word13;
    dst[14] = word14;
    if (initialized == 0) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, records + 0x0);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, records + 0xc);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, records + 0x18);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, records + 0x24);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, records + 0x30);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, records + 0x3c);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, records + 0x48);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, records + 0x54);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, records + 0x60);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}

