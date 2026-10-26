#include "types.h"
#include "JSystem/JParticle/JPAEmitter.h"
#include "Game/SinitPoolChain.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"

struct DgtlEffMgr {
    u8 pad[0xc];
    JPAEmitterManager* mgr;
};

struct DgtlObj {
    u8 pad[0x2ae];
    u16 angles[7];
    u8 pad2bc[4];
    Vec joints[8];
    u8 pad320[0x18];
    u16 historyAngles[80];
    Vec history[80];
    JPABaseEmitter* bodyEff[10];
    JPABaseEmitter* eff[2];
};

static inline void dgtlStopBodyEffects(DgtlObj* obj) {
    JPABaseEmitter* emitter;
    s32 i;
    for (i = 0; i < 10; ++i) {
        emitter = obj->bodyEff[i];
        if (emitter) {
            emitter->becomeInvalidEmitter();
            obj->bodyEff[i] = 0;
        }
    }
}

struct TWEVParam {
    u8 buf[16];
    s32 a;
    s32 b;
    void* c;
    s8 d[11];
    s32 e;
    u8 f[3];
    s32 g;
    s32 h;
    s32 i;
};

typedef f32 TWEVMtx[3][4];

static inline void fn_80147B50_rotMtx(TWEVMtx m, f32 ax, f32 ay, f32 az, f32 s) {
    f32 sa = sin(ax);
    f32 sb = sin(ay);
    f32 sc = sin(az);
    f32 ca = cos(ax);
    f32 cb = cos(ay);
    f32 cc = cos(az);
    m[0][0] = s * (cb * cc);
    m[0][1] = s * (sa * sb * cc - ca * sc);
    m[0][2] = s * (ca * cc * sb + sa * sc);
    m[1][0] = s * (cb * sc);
    m[1][1] = s * (sa * sb * sc + ca * cc);
    m[1][2] = s * (ca * sc * sb - sa * cc);
    m[2][0] = s * -sb;
    m[2][1] = s * (sa * cb);
    m[2][2] = s * (ca * cb);
}

extern "C" char __vt__4DGTL[];
extern "C" void fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, s32 p);
extern "C" void __dl__FPv(void* p);
extern s32 lbl_80539F58;
extern s32 lbl_80539F5C;
extern "C" void* fn_8013C824(void);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* mgr, void* emitter);
extern "C" void* fn_8013CC50(s32 room, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
extern "C" void fn_801F0E34(void* this_, s32 id, s32 flag);
extern "C" u16 lbl_8049F630[][2];
extern "C" const f32 lbl_8053D0B4;
extern "C" const f32 lbl_8053D110;
extern "C" const f32 lbl_8053D114;
extern "C" u8* lbl_8053AAF8;
extern "C" const f32 lbl_8053D0B0;
extern "C" const f32 lbl_8053D0F8;
extern "C" const f32 lbl_8053D108;
extern "C" const f32 lbl_8053D10C;
extern "C" s32 fn_801F285C(void* a, f32* b, u32* c, u32 e, s32 d);
extern "C" s32 fn_8022EA0C(s32 a);
extern "C" u8 fn_801F2FAC(void* a);
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* mgr, s32 idx);
extern "C" s32 Actor_CreateByID(void* mgr, u32 id, s32 room, void* pos, s32 a, s32 b, s32 c);
extern "C" void fn_80134DE4(u8* a, s32 b, s32 c);
extern "C" u32 fn_804032E8(u32 tag, void* name);
extern "C" void fn_801EFD34(void* this_, u32 id, void* param, s32 n, f32 a, f32 b, f32 c);
extern "C" void fn_801F02BC(void* this_, void* name, s32 id, f32 a, f32 b, s32 c, s32 d, s32 e, s32 f);
extern "C" char lbl_80465D30[];
extern "C" void* lbl_8049F698[];
extern "C" u8 lbl_80539F60[];
extern "C" s32 lbl_8053AB34;
extern "C" const f32 lbl_8053D0B8;
extern "C" const f32 lbl_8053D0BC;
extern "C" void fn_80147B50(void* this_) {
    char* p = (char*)this_;
    TWEVParam param;
    TWEVMtx mtx;
    s32 i;
    s32 mode;

    param.a = -1;
    param.b = -1;
    for (i = 0; (u8)i < 16; i += 8) {
        param.buf[(u8)i] = i;
        param.buf[(u8)(i + 1)] = i + 1;
        param.buf[(u8)(i + 2)] = i + 2;
        param.buf[(u8)(i + 3)] = i + 3;
        param.buf[(u8)(i + 4)] = i + 4;
        param.buf[(u8)(i + 5)] = i + 5;
        param.buf[(u8)(i + 6)] = i + 6;
        param.buf[(u8)(i + 7)] = i + 7;
    }
    param.a = -1;
    param.b = 0;
    param.c = 0;
    param.d[0] = 0;
    param.d[1] = 0;
    param.d[2] = 0;
    param.d[3] = 1;
    param.d[4] = 1;
    param.d[5] = 0;
    param.d[6] = 0;
    param.d[7] = 0;
    param.d[8] = 0;
    param.d[9] = 0;
    param.d[10] = 1;
    param.e = 3;
    param.f[0] = 1;
    param.f[1] = 0;
    param.f[2] = 0;
    param.g = -1;
    param.h = 0;
    param.i = 2;
    mtx[0][3] = lbl_8053D0B0;
    mtx[1][3] = lbl_8053D0B0;
    mtx[2][3] = lbl_8053D0B0;
    param.d[1] = 1;

    mode = *(u32*)(p + 0x90);
    if (mode == 2 || mode == 3) {
        if (lbl_8053AB34 == 1) {
            fn_801F02BC(this_, lbl_80465D30, 0x176, lbl_8053D0B4, lbl_8053D0B4, 0, -1, 1, 0);
        }
    } else {
        f32 x0 = *(f32*)(p + 0xc);
        f32 y0 = *(f32*)(p + 0x10);
        f32 z0 = *(f32*)(p + 0x14);
        *(f32*)(p + 0xc) = *(f32*)(p + 0x314);
        *(f32*)(p + 0x10) = *(f32*)(p + 0x318);
        *(f32*)(p + 0x14) = *(f32*)(p + 0x31c);
        f32 ang = (f32)*(u16*)(p + 0x2ba) / lbl_8053D0B8;
        fn_80147B50_rotMtx(mtx, lbl_8053D0B0, ang, lbl_8053D0B0, lbl_8053D0B4);
        param.c = mtx;
        u32 id = fn_804032E8(0x44454754, lbl_8049F698[8 + *(s32*)(p + 0x278)]);
        fn_801EFD34(this_, id, &param, -1, lbl_8053D0B0, lbl_8053D0B0, lbl_8053D0B0);

        char* pa = p + 0x30;
        char* pb = p + 8;
        for (s32 r24 = 4; r24 >= 0; r24--, pa -= 12, pb -= 2) {
            param.d[1] = 6 - r24;
            mtx[0][3] = lbl_8053D0B0;
            mtx[1][3] = lbl_8053D0B0;
            mtx[2][3] = lbl_8053D0B0;
            *(f32*)(p + 0xc) = *(f32*)(pa + 0x2cc);
            *(f32*)(p + 0x10) = *(f32*)(pa + 0x2d0);
            *(f32*)(p + 0x14) = *(f32*)(pa + 0x2d4);
            f32 sc = lbl_8053D0B4 - lbl_8053D0BC * (f32)r24;
            f32 a2 = (f32)*(u16*)(pb + 0x2ae) / lbl_8053D0B8;
            fn_80147B50_rotMtx(mtx, lbl_8053D0B0, a2, lbl_8053D0B0, sc);
            param.c = mtx;
            id = fn_804032E8(0x44454754, lbl_8049F698[3 + *(s32*)(p + 0x25c)]);
            fn_801EFD34(this_, id, &param, -1, lbl_8053D0B0, lbl_8053D0B0, lbl_8053D0B0);
        }

        *(f32*)(p + 0xc) = x0;
        *(f32*)(p + 0x10) = y0;
        *(f32*)(p + 0x14) = z0;
        param.d[1] = 7;
        mtx[0][3] = lbl_8053D0B0;
        mtx[1][3] = lbl_8053D0B0;
        mtx[2][3] = lbl_8053D0B0;
        f32 ang2 = (f32)*(u16*)(p + 0x284) / lbl_8053D0B8;
        fn_80147B50_rotMtx(mtx, lbl_8053D0B0, ang2, lbl_8053D0B0, lbl_8053D0B4);
        param.c = mtx;
        id = fn_804032E8(0x44454754, lbl_8049F698[lbl_80539F60[*(s32*)(p + 0x258)]]);
        fn_801EFD34(this_, id, &param, -1, lbl_8053D0B0, lbl_8053D0B0, lbl_8053D0B0);
    }
}

extern "C" void fn_8014821C(char* this_) {
    if (*(s32*)(this_ + 0x90) == 1) {
        *(s32*)(this_ + 0x108) = 0x2710;
    }
}

extern "C" void* fn_80149A10(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = __vt__4DGTL;
        int i;
        char* p = this_;
        i = 0;
        do {
            fn_801EE434(*(void**)(p + 0x798));
            i++;
            p += 4;
        } while (i < 10);
        i = 0;
        p = this_;
        do {
            fn_801EE434(*(void**)(p + 0x7c0));
            i++;
            p += 4;
        } while (i < 2);
        if (*(s32*)(this_ + 0x90) == 1) {
            lbl_80539F58 = -1;
        }
        if (*(s32*)(this_ + 0x90) == 0) {
            lbl_80539F5C = -1;
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" s32 fn_80149AEC(char* p) {
    char* q;
    s32 id;
    u8 hit;
    int count;
    s32 i;
    hit = 0;
    if (*(s32*)(p + 0x240) || *(s32*)(p + 0x24c) || *(s32*)(p + 0x250)) return 0;
    f32 x = *(f32*)(p + 0xc);
    f32 y = *(f32*)(p + 0x10);
    f32 z = *(f32*)(p + 0x14);
    *(f32*)(p + 0x60) = lbl_8053D108;
    *(f32*)(p + 0x64) = lbl_8053D108;
    *(f32*)(p + 0x68) = lbl_8053D0F8;
    *(f32*)(p + 0x6c) = lbl_8053D0F8;
    *(f32*)(p + 0xc) = *(f32*)(p + 0x314);
    *(f32*)(p + 0x10) = *(f32*)(p + 0x318);
    *(f32*)(p + 0x14) = *(f32*)(p + 0x31c);
    *(u32*)(p + 0xb0) = 0x08040000;
    for (i = 0; i < 4; ++i) {
        s32 player = fn_801F285C(p, 0, 0, 1, i);
        if (player >= 0 && (player == *(s32*)(p + 0x278) || fn_8022EA0C(player) == *(s32*)(p + 0x278)) && fn_801F2FAC(p) && *(s32*)(p + 0x108) != 10000) {
            *(s32*)(p + 0x270) = 0;
            *(f32*)(p + 0x14) = lbl_8053D0B0;
            *(f32*)(p + 0x44) = lbl_8053D0B0;
            hit = 1;
        }
    }
    *(f32*)(p + 0xc) = x;
    *(f32*)(p + 0x10) = y;
    *(f32*)(p + 0x14) = z;
    if (!hit) return 0;
    *(s32*)(p + 0x260) = 0;
    *(s32*)(p + 0x264) = 0;
    *(f32*)(p + 0x2a8) = lbl_8053D0B0;
    *(f32*)(p + 0x2a4) = lbl_8053D0B0;
    *(f32*)(p + 0x2a0) = lbl_8053D0B0;
    *(f32*)(p + 0x44) = lbl_8053D0B0;
    *(f32*)(p + 0x40) = lbl_8053D0B0;
    *(f32*)(p + 0x3c) = lbl_8053D0B0;
    q = p;
    for (count = 0; count < 2; ++count, q += 4) {
        if (*(void* volatile*)(q + 0x7c0)) {
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)fn_8013C824() + 0xc), *(void* volatile*)(q + 0x7c0));
            *(void* volatile*)(q + 0x7c0) = 0;
        }
    }
    --*(s32*)(p + 0x274);
    if (*(s32*)(p + 0x274) <= 0) {
        *(s32*)(p + 0xd8) = 0;
        *(s32*)(p + 0xdc) = 0;
        if (*(s32*)(p + 0x90) == 1) lbl_80539F58 = -1;
        if (*(s32*)(p + 0x90) == 0) lbl_80539F5C = -1;
        u32* flags = (u32*)(p + 0x234);
        for (u32 j = 0; j < 9; ++j) flags[j] = 0;
        *(s32*)(p + 0x23c) = 0xa8;
        dgtlStopBodyEffects((DgtlObj*)p);
        fn_80134DE4(lbl_8053AAF8, 0xa8, 0);
        *(s32*)(p + 0x230) = 6;
    } else {
        if (*(s32*)(p + 0x274) == 1) *(f32*)(p + 0x290) = lbl_8053D10C;
        *(s32*)(p + 0x25c) = 4;
        if (*(s32*)(p + 0x274) == 2) {
            if (*(u32*)(p + 0x90) == 1) {
                Actor_CreateByID(fn_801F856C(), 0x4447544c, *(s32*)(p + 4), p + 0xc, 0, -1, -1);
                id = lbl_80539F58;
                if (id >= 0) {
                    char* other = (char*)fn_801F666C(fn_801F856C(), id);
                    if (other) {
                        lbl_80539F5C = Actor_CreateByID(fn_801F856C(), 0x4447544c, *(s32*)(other + 4), other + 0xc, 3, -1, -1);
                    }
                }
                fn_801F0E34(p, 0x40023, 0);
            } else {
                fn_801F0E34(p, 0x40005, 0);
            }
        } else {
            fn_801F0E34(p, 0x40005, 0);
        }
        q = p;
        for (int j = 0; j < 80; ++j, q += 12) {
            *(f32*)(q + 0x3d8) = *(f32*)(p + 0xc);
            *(f32*)(q + 0x3dc) = *(f32*)(p + 0x10);
            *(f32*)(q + 0x3e0) = *(f32*)(p + 0x14);
        }
    }
    return 1;
}

extern "C" s32 fn_80149FDC(char* this_) {
    s32 i;
    char* p;
    if (*(s32*)(this_ + 0x250) == 0) {
        return 1;
    }
    if (*(s32*)(this_ + 0x24c) == 0) {
        *(s32*)(this_ + 0x24c) = 300 - *(s32*)(this_ + 0x250);
        *(s32*)(this_ + 0x24c) = (s32)((f32)*(s32*)(this_ + 0x24c) * lbl_8053D110);
        if (*(s32*)(this_ + 0x24c) < 8) {
            *(s32*)(this_ + 0x24c) = 8;
        }
        *(s32*)(this_ + 0x278) += 1;
        *(s32*)(this_ + 0x278) &= 3;
        if (*(s32*)(this_ + 0x230) != 1 && *(s32*)(this_ + 0x230) != 2) {
            switch (*(s32*)(this_ + 0x278)) {
            case 0:
                fn_801F0E34(this_, 0x400bb, 0);
                break;
            case 1:
                fn_801F0E34(this_, 0x400bc, 0);
                break;
            case 2:
                fn_801F0E34(this_, 0x400bd, 0);
                break;
            case 3:
                fn_801F0E34(this_, 0x400be, 0);
                break;
            }
        }
    }
    if (*(s32*)(this_ + 0x250) != 1) {
        return 0;
    }
    *(s32*)(this_ + 0x278) = *(s32*)(this_ + 0x27c);
    i = 0;
    while (*(s32*)(this_ + 0x27c) == *(s32*)(this_ + 0x278) && i < 100) {
        i++;
        u8* g = lbl_8053AAF8;
        *(u32*)(g + 0xb4) = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
        u32 bits = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
        f32 r = *(f32*)&bits;
        *(s32*)(this_ + 0x278) = (s32)(lbl_8053D114 * (r - lbl_8053D0B4));
        *(s32*)(this_ + 0x278) &= 3;
    }
    *(s32*)(this_ + 0x27c) = *(s32*)(this_ + 0x278);
    i = 0;
    p = this_;
    do {
        if (*(JPABaseEmitter**)(p + 0x7c0) != 0) {
            DgtlEffMgr* m = (DgtlEffMgr*)fn_8013C824();
            m->mgr->forceDeleteEmitter(*(JPABaseEmitter**)(p + 0x7c0));
            *(JPABaseEmitter**)(p + 0x7c0) = 0;
        }
        i++;
        p += 4;
    } while (i < 2);
    s32 idx = *(s32*)(this_ + 0x278);
    *(void**)(this_ + 0x7c0) = fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, lbl_8049F630[idx][0], 0, 0, 0, 0, 1, lbl_8053D0B4);
    *(void**)(this_ + 0x7c4) = fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, lbl_8049F630[idx][1], 0, 0, 0, 0, 1, lbl_8053D0B4);
    if (*(s32*)(this_ + 0x230) != 1 && *(s32*)(this_ + 0x230) != 2) {
        fn_801F0E34(this_, 0x400bf, 0);
    }
    *(s32*)(this_ + 0x254) = 0xe10;
    return 0;
}

extern "C" s32 lbl_8049F640[];
extern "C" const f32 lbl_8053D118;
static inline s32 dgtlTrailHeightIndex(s32 index) {
    return (s32)((f32)index * lbl_8053D118);
}
extern "C" void fn_8013CB44(void*, void*, s32, s32, s32);
#pragma opt_propagation off
extern "C" void fn_8014A2CC(char* p, s32 mode) {
    char* pos;
    u16* angle;
    s32* table;
    char* eff;
    s32 i;
    s32 start = 0;
    if (*(s32*)(p + 0x274) == 1) start = 7;
    char* a = p + 0x3a8;
    char* b = p + 0x9c;
    s32 n = 78;
    if (mode == 0) {
        for (; n >= 0; a -= 12, n--, b -= 2) {
            *(JGeometry::TVec3<f32>*)(p + 0x3d8 + (n+1)*12) = *(JGeometry::TVec3<f32>*)(a + 0x3d8);
            *(u16*)(b+0x33a) = *(u16*)(b+0x338);
        }
    } else {
        for (; n >= 0; n--, a -= 12) {
            *(f32*)(a+0x3ec) = *(f32*)(a+0x3e0);
        }
    }
    if (mode == 0) {
        *(f32*)(p+0x3d8) = *(f32*)(p+0xc);
        *(f32*)(p+0x3dc) = *(f32*)(p+0x10);
        *(f32*)(p+0x3e0) = *(f32*)(p+0x14);
        *(u16*)(p+0x338) = *(u16*)(p+0x284);
    } else {
        *(f32*)(p+0x3e0) = *(f32*)(p+0x14);
    }
    pos = p;
    angle = (u16*)p;
    table = lbl_8049F640;
    eff = p;
    for (i=0; i<6; i++, pos+=12, angle++, table++, eff+=4) {
        s32 index = lbl_8049F640[start+i];
        char* src = p + index*12;
        *(f32*)(pos+0x2cc) = *(f32*)(src+0x3d8);
        *(f32*)(pos+0x2d0) = *(f32*)(src+0x3dc);
        *(f32*)(pos+0x2d4) = *(f32*)(src+0x3e0);
        *(u16*)((char*)angle+0x2ae) = *(u16*)(p+0x338+index*2);
        if (mode != 0) {
            *(f32*)(pos+0x2d4) = *(f32*)(p+0x3e0+(int)((f32)*table*lbl_8053D118)*sizeof(Vec));
        }
        if (i<5) {
            void* emitter = *(void**)(eff+0x798);
            if (emitter == 0) {
                *(void**)(eff+0x798) = fn_8013CC50(*(s32*)(p+4), p+0x2c0+(i+1)*12, 0x11c, 0,0,0,0,1, lbl_8053D0B4-lbl_8053D0BC*(f32)i);
            } else {
                *((u8*)emitter+0xbb) = (u8)*(f32*)(p+0x294);
                fn_8013CB44(*(void**)(eff+0x798), p+0x2c0+(i+1)*12,0,0,1);
            }
        }
    }
    s32* tail = lbl_8049F640+6;
    DgtlObj* obj = (DgtlObj*)p;
    s32 index = tail[start];
    char* src = p+index*12;
    *(f32*)(p+0x314) = *(f32*)(src+0x3d8);
    *(f32*)(p+0x318) = *(f32*)(src+0x3dc);
    *(f32*)(p+0x31c) = *(f32*)(src+0x3e0);
    char* anglesrc = p + index*2;
    obj->angles[6] = obj->historyAngles[index];
    eff = p;
    for (s32 j=0;j<2;j++,eff+=4) fn_8013CB44(*(void**)(eff+0x7c0),p+0x314,0,0,1);
    if (mode != 0) {
    s32 zindex = (s32)((f32)*tail*lbl_8053D118);
    char* zsrc = p + zindex*12;
    obj->joints[7].z = ((Vec*)((char*)obj->history+zindex*sizeof(Vec)))->z;
    }
    *(f32*)(p+0x2c0) = *(f32*)(p+0x3d8);
    *(f32*)(p+0x2c4) = *(f32*)(p+0x3dc);
    *(f32*)(p+0x2c8) = *(f32*)(p+0x3e0);
}
#pragma opt_propagation on
extern "C" void fn_802D7440(void* p, s32 x);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_80458F9C(void* p, s32 x);
extern "C" u8 sincosTable___5JMath[];
extern "C" const f32 lbl_8053D0D0;
extern "C" const f32 lbl_8053D0D4;
extern "C" const f32 lbl_8053D0E4;
extern "C" const f32 lbl_8053D11C;
extern "C" const f32 lbl_8053D120;
extern "C" const f32 lbl_8053D124;
extern "C" void* lbl_8053AF80;
extern s32 lbl_8053AB30;
extern s32 lbl_8053AB34;
extern s32 lbl_8053AB38;
static inline u16 dgtlAngleFromIndex(u32 index) {
    u16 angle;
    switch (index) {
    case 0:
        angle = 0;
        break;
    case 1:
        angle = 0x2000;
        break;
    case 2:
        angle = 0x4000;
        break;
    case 3:
        angle = 0x6000;
        break;
    case 4:
        angle = 0x8000;
        break;
    case 5:
        angle = 0xa000;
        break;
    case 6:
        angle = 0xc000;
        break;
    case 7:
        angle = 0xe000;
        break;
    }
    return angle;
}

extern "C" void fn_8014A5F4(char* this_) {
    char* p = this_;
    u8* g;
    u32 bits;
    u16 angle;
    f32 r;

    *(f32*)(p + 0x80) = lbl_8053D108;
    *(f32*)(p + 0x84) = lbl_8053D108;
    *(f32*)(p + 0x88) = lbl_8053D0F8;
    *(f32*)(p + 0x8c) = lbl_8053D0F8;
    *(s32*)(p + 0x258) = 0;
    *(s32*)(p + 0x25c) = 0;
    *(s32*)(p + 0x260) = 0;
    *(s32*)(p + 0x264) = 0;
    *(s32*)(p + 0x268) = 0;
    *(s32*)(p + 0x26c) = 0;
    *(s32*)(p + 0x270) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x23c) = 0;
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = 0;
    *(s32*)(p + 0x254) = 0;
    *(s32*)(p + 0x274) = 6;
    *(s32*)(p + 0x278) = 0;
    *(s32*)(p + 0x280) = *(s32*)(p + 0x278);
    *(s32*)(p + 0x250) = 300;
    *(s32*)(p + 0x27c) = *(s32*)(p + 0x278);
    *(s32*)(p + 0x798) = 0;
    *(s32*)(p + 0x79c) = 0;
    *(s32*)(p + 0x7a0) = 0;
    *(s32*)(p + 0x7a4) = 0;
    *(s32*)(p + 0x7a8) = 0;
    *(s32*)(p + 0x7ac) = 0;
    *(s32*)(p + 0x7b0) = 0;
    *(s32*)(p + 0x7b4) = 0;
    *(s32*)(p + 0x7b8) = 0;
    *(s32*)(p + 0x7bc) = 0;
    *(s32*)(p + 0x7c0) = 0;
    *(s32*)(p + 0x7c4) = 0;

    g = lbl_8053AAF8;
    *(u32*)(g + 0xb4) = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
    bits = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
    r = *(f32*)&bits;
    *(s32*)(p + 0x98) = (s32)((r - lbl_8053D0B4) * lbl_8053D11C);
    *(s32*)(p + 0x298) = *(s32*)(p + 0x98);
    *(s32*)(p + 0x29c) = -1;
    *(f32*)(p + 0x294) = lbl_8053D0E4;
    *(u8*)(p + 0x196) = 1;

    angle = dgtlAngleFromIndex(*(u32*)(p + 0x98));
    *(u16*)(p + 0x284) = angle;
    *(u16*)(p + 0x286) = *(u16*)(p + 0x284);

    {
        char* fp = p;
        char* sp = p;
        for (s32 i = 0; i < 2; i++) {
            *(f32*)(fp + 0x2c0) = *(f32*)(p + 0xc);
            *(f32*)(fp + 0x2c4) = *(f32*)(p + 0x10);
            *(f32*)(fp + 0x2c8) = *(f32*)(p + 0x14);
            *(u16*)(sp + 0x2ac) = *(u16*)(p + 0x284);
            *(f32*)(fp + 0x2cc) = *(f32*)(p + 0xc);
            *(f32*)(fp + 0x2d0) = *(f32*)(p + 0x10);
            *(f32*)(fp + 0x2d4) = *(f32*)(p + 0x14);
            *(u16*)(sp + 0x2ae) = *(u16*)(p + 0x284);
            *(f32*)(fp + 0x2d8) = *(f32*)(p + 0xc);
            *(f32*)(fp + 0x2dc) = *(f32*)(p + 0x10);
            *(f32*)(fp + 0x2e0) = *(f32*)(p + 0x14);
            *(u16*)(sp + 0x2b0) = *(u16*)(p + 0x284);
            *(f32*)(fp + 0x2e4) = *(f32*)(p + 0xc);
            *(f32*)(fp + 0x2e8) = *(f32*)(p + 0x10);
            *(f32*)(fp + 0x2ec) = *(f32*)(p + 0x14);
            *(u16*)(sp + 0x2b2) = *(u16*)(p + 0x284);
            *(f32*)(fp + 0x2f0) = *(f32*)(p + 0xc);
            *(f32*)(fp + 0x2f4) = *(f32*)(p + 0x10);
            *(f32*)(fp + 0x2f8) = *(f32*)(p + 0x14);
            fp += 0x3c;
            *(u16*)(sp + 0x2b4) = *(u16*)(p + 0x284);
            sp += 0xa;
        }
    }
    {
        char* fp = p;
        char* sp = p;
        for (s32 i = 0; i < 10; i++) {
            *(f32*)(fp + 0x3d8) = *(f32*)(p + 0xc);
            *(f32*)(fp + 0x3dc) = *(f32*)(p + 0x10);
            *(f32*)(fp + 0x3e0) = *(f32*)(p + 0x14);
            *(u16*)(sp + 0x338) = *(u16*)(p + 0x284);
            *(f32*)(fp + 0x3e4) = *(f32*)(p + 0xc);
            *(f32*)(fp + 0x3e8) = *(f32*)(p + 0x10);
            *(f32*)(fp + 0x3ec) = *(f32*)(p + 0x14);
            *(u16*)(sp + 0x33a) = *(u16*)(p + 0x284);
            *(f32*)(fp + 0x3f0) = *(f32*)(p + 0xc);
            *(f32*)(fp + 0x3f4) = *(f32*)(p + 0x10);
            *(f32*)(fp + 0x3f8) = *(f32*)(p + 0x14);
            *(u16*)(sp + 0x33c) = *(u16*)(p + 0x284);
            *(f32*)(fp + 0x3fc) = *(f32*)(p + 0xc);
            *(f32*)(fp + 0x400) = *(f32*)(p + 0x10);
            *(f32*)(fp + 0x404) = *(f32*)(p + 0x14);
            *(u16*)(sp + 0x33e) = *(u16*)(p + 0x284);
            *(f32*)(fp + 0x408) = *(f32*)(p + 0xc);
            *(f32*)(fp + 0x40c) = *(f32*)(p + 0x10);
            *(f32*)(fp + 0x410) = *(f32*)(p + 0x14);
            *(u16*)(sp + 0x340) = *(u16*)(p + 0x284);
            *(f32*)(fp + 0x414) = *(f32*)(p + 0xc);
            *(f32*)(fp + 0x418) = *(f32*)(p + 0x10);
            *(f32*)(fp + 0x41c) = *(f32*)(p + 0x14);
            *(u16*)(sp + 0x342) = *(u16*)(p + 0x284);
            *(f32*)(fp + 0x420) = *(f32*)(p + 0xc);
            *(f32*)(fp + 0x424) = *(f32*)(p + 0x10);
            *(f32*)(fp + 0x428) = *(f32*)(p + 0x14);
            *(u16*)(sp + 0x344) = *(u16*)(p + 0x284);
            *(f32*)(fp + 0x42c) = *(f32*)(p + 0xc);
            *(f32*)(fp + 0x430) = *(f32*)(p + 0x10);
            *(f32*)(fp + 0x434) = *(f32*)(p + 0x14);
            fp += 0x60;
            *(u16*)(sp + 0x346) = *(u16*)(p + 0x284);
            sp += 0x10;
        }
    }

    *(s32*)(p + 0x798) = 0;
    *(s32*)(p + 0x79c) = 0;
    *(s32*)(p + 0x7a0) = 0;
    *(s32*)(p + 0x7a4) = 0;
    *(s32*)(p + 0x7a8) = 0;
    *(s32*)(p + 0x7ac) = 0;
    *(s32*)(p + 0x7b0) = 0;
    *(s32*)(p + 0x7b4) = 0;
    *(s32*)(p + 0x7b8) = 0;
    *(s32*)(p + 0x7bc) = 0;
    *(f32*)(p + 0x290) = lbl_8053D120;
    *(f32*)(p + 0x2a0) = *(f32*)(p + 0x290) * JMath::sincosTable_.sinShort(*(u16*)(p + 0x284));
    *(f32*)(p + 0x2a4) = *(f32*)(p + 0x290) * JMath::sincosTable_.cosShort(*(u16*)(p + 0x284));
    *(f32*)(p + 0x2a8) = lbl_8053D0B0;
    *(f32*)(p + 0x288) = lbl_8053D124;
    *(f32*)(p + 0x28c) = lbl_8053D0B4;
    *(s32*)(p + 0x90) = *(s32*)(p + 0x90) & 3;
    *(u16*)(p + 0x94) = 0;
    *(s32*)(p + 0xbc) = 2;
    *(u32*)(p + 0xb0) = 0x08040004;
    fn_802D7440(fn_802D6A9C(), 0);

    switch (*(s32*)(p + 0x90)) {
    case 0:
        lbl_8053AB30 = lbl_8053AB30 + 1;
        *(s32*)(p + 0x230) = 0;
        return;
    case 1:
        lbl_80539F58 = -1;
        lbl_80539F5C = -1;
        lbl_8053AB34 = 0;
        lbl_8053AB38 = *(s32*)(p + 4);
        fn_80458F9C(lbl_8053AF80, 0x3c);
        lbl_8053AB30 = 0;
        *(s32*)(p + 0x230) = 1;
        lbl_8053AB30 = lbl_8053AB30 + 1;
        return;
    case 2:
        lbl_8053AB38 = *(s32*)(p + 4);
    case 3:
        *(f32*)(p + 0x60) = lbl_8053D0D0;
        *(f32*)(p + 0x64) = lbl_8053D0D0;
        *(f32*)(p + 0x68) = lbl_8053D0D4;
        *(f32*)(p + 0x6c) = lbl_8053D0D4;
        *(s32*)(p + 0x248) = 0x14;
        *(s32*)(p + 0x230) = 8;
        return;
    }
}
#pragma opt_common_subs reset
