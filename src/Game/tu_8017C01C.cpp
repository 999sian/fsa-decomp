#include "types.h"
#include "JSystem/JGeometry/Box.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "Game/ItemBase.h"

struct PendingPositionRequest {
    u8 pad[0x7f4];
    u8 active;
    u8 blocked;
    u8 flag;
    u8 pad7f7;
    u32 state;
    JGeometry::TVec3<f32> position;
};

extern void* lbl_8053AB10;
extern f32 lbl_8053DDC8;
extern const f32 lbl_8053DD28;
extern "C" u8 fn_8030C2A8(void* mgr, f32* vec);
extern "C" void fn_801F0E34(void* this_, s32 p1, s32 p2);
extern "C" void* fn_8013CC50(s32 room, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
extern u16 lbl_804A1210[][2];
extern u8 lbl_80539F88[8];

struct ActorVt_tu8017C01C {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void setShadow(s32 type, f32 x, f32 y);
};

extern "C" void fn_8017C01C(ActorVt_tu8017C01C* this_) {
    fn_801F0E34(this_, 0x40047, 0);
    this_->setShadow(*(s8*)((char*)this_ + 0x2ba), 8.0f, -16.0f);
}

extern const f32 lbl_8053DD2C;
extern const f32 lbl_8053DD30;
extern "C" void* fn_804032E8(u32, const char*);
extern "C" void fn_801EFD34(void*, void*, DrawRec*, s32, f32, f32, f32);
#pragma opt_propagation off
extern "C" void fn_8017C078(char* this_) {
    const char* tbl = (const char*)lbl_804A1210;
    DrawRec rec;
    f32 sy = lbl_8053DD28;
    f32 sx = sy;
    JGeometry::TVec3<f32> pos(*(Vec*)(this_ + 0xc));
    f32 mtx[3][4];
    void* tex;
    u8* tag = (u8*)&rec.w10;
    mtx[0][3] = sy;
    mtx[1][3] = sy;
    mtx[2][3] = sy;
    rec.b1f = 0;
    rec.b2d = 1;
    if (*(u32*)(this_ + 0x90) != 0 && *(u32*)(this_ + 0x90) != 1) {
        return;
    }
    *(f32*)(this_ + 0x14) = lbl_8053DD28;
    switch (*(s32*)(this_ + 0x27c)) {
    case 0: {
        const char* const* p = (const char* const*)(tbl + 0x80);
        tex = fn_804032E8('FGAN', p[*(s32*)(this_ + 0x268)]);
        break;
    }
    case 1: {
        const char* const* p = (const char* const*)(tbl + 0xc0);
        tex = fn_804032E8('FGAN', p[*(s32*)(this_ + 0x268)]);
        const f32 (*sc)[2] = (const f32 (*)[2])(tbl + 0x98);
        sx = sc[*(s32*)(this_ + 0x268)][0];
        sy = sc[*(s32*)(this_ + 0x268)][1];
        break;
    }
    case 2: {
        const char* const* p = (const char* const*)(tbl + 0xd4);
        tex = fn_804032E8('FGAN', p[*(s32*)(this_ + 0x268)]);
        sy = lbl_8053DD2C;
        break;
    }
    case 3: {
        const char* const* p = (const char* const*)(tbl + 0xf4);
        tex = fn_804032E8('FGAN', p[*(s32*)(this_ + 0x268)]);
        break;
    }
    }
    if (*(u32*)(this_+0x90) == 0) {
    rec.b1d = -2;
    rec.b1c = 0;
    tag[0] = 0;
    tag[1] = 0;
    tag[2] = 0;
    tag[3] = 100;
    f32 scale = lbl_8053DD30 * *(f32*)(this_ + 0x2b0);
    mtx[0][0] = *(f32*)(this_ + 0x2ac);
    mtx[0][1] = lbl_8053DD28;
    mtx[0][2] = lbl_8053DD28;
    mtx[1][0] = lbl_8053DD28;
    mtx[1][1] = scale;
    mtx[1][2] = lbl_8053DD28;
    mtx[2][0] = lbl_8053DD28;
    mtx[2][1] = lbl_8053DD28;
    mtx[2][2] = mtx[1][1];
    rec.w18 = mtx;
    fn_801EFD34(this_, tex, &rec, -1, sx, sy, lbl_8053DD28);
    }
    *(Vec*)(this_ + 0xc) = pos;
    rec.b1d = *(u8*)(this_ + 0x2ba);
    rec.w30 = 14;
    f32 sy2 = *(f32*)(this_ + 0x2b0);
    mtx[0][0] = *(f32*)(this_ + 0x2ac);
    mtx[0][1] = lbl_8053DD28;
    mtx[0][2] = lbl_8053DD28;
    mtx[1][0] = lbl_8053DD28;
    mtx[1][1] = sy2;
    mtx[1][2] = lbl_8053DD28;
    mtx[2][0] = lbl_8053DD28;
    mtx[2][1] = lbl_8053DD28;
    mtx[2][2] = sy2;
    rec.w18 = mtx;
    tag[0] = 0xff;
    tag[1] = 0xff;
    tag[2] = 0xff;
    tag[3] = (u8)*(f32*)(this_ + 0x290);
    fn_801EFD34(this_, tex, &rec, -1, sx, sy, lbl_8053DD28);
}

#pragma opt_propagation reset
extern "C" void fn_801546F4(void* dst, void* src);
extern "C" void fn_8017ECE8(void* dst, f32 x, f32 y);
extern "C" void fn_801546BC(void* v);
extern "C" void fn_8017C40C(char* this_) {
    fn_801546F4(this_ + 0x60, this_ + 0x60);
    fn_8017ECE8(this_ + 0x60, *(f32*)(this_ + 0x2a0), *(f32*)(this_ + 0x2a4));
    fn_801546BC(this_ + 0x50);
}

extern "C" void fn_801EE434(void* handle);
extern "C" void fn_8022ADCC(void);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D7440(void* mgr, s32 v);
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* mgr, s32 idx);
extern "C" void __dt__5ActorFv(void* this_, s32 flag);
extern "C" void __dl__FPv(void* p);
extern char lbl_804A1318[];
extern f32 lbl_8053DD5C;
extern "C" void* fn_8017E640(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A1318;
        void** p = (void**)this_;
        s32 h;
        for (int i = 0; i < 4; i++) {
            fn_801EE434(p[0xaf]);
            fn_801EE434(p[0xb3]);
            p++;
        }
        fn_801EE434(((void**)this_)[0xb7]);
        if (*(u32*)(this_ + 0x90) == 0) {
            u8* q = *(u8**)((char*)lbl_8053AB10 + 0x2c);
            q[4] = 0xff;
            q[5] = 0xff;
            q[6] = 0xff;
            q[7] = 0;
            fn_802D7440(fn_802D6A9C(), 1);
            fn_8022ADCC();
        }
        if (*(u32*)(this_ + 0x90) == 10) {
            h = *(s32*)(this_ + 0x274);
            if (h >= 0) {
                u8* c = (u8*)fn_801F666C(fn_801F856C(), h);
                if (c != 0 && *(u8*)(c + 0x11c) == 1) {
                    *(f32*)(c + 0x28c) = lbl_8053DD5C;
                    *(s32*)(c + 0x278) = 0;
                    *(s32*)(this_ + 0x274) = -1;
                }
            }
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

#pragma opt_propagation off
extern "C" void fn_8017E770(char* this_) {
    s32 off = 0;
    *(u16*)(this_ + 0x94) = (*(u32*)(this_ + 0x90) >> 4) & 0xf;
    *(u32*)(this_ + 0x90) = *(u32*)(this_ + 0x90) & 0xf;
    *(u32*)(this_ + 0x24c) = off;
    *(u32*)(this_ + 0x250) = off;
    *(u32*)(this_ + 0x254) = off;
    *(u32*)(this_ + 0x258) = off;
    *(u32*)(this_ + 0x25c) = off;
    *(u32*)(this_ + 0x260) = off;
    *(u32*)(this_ + 0x264) = off;
    *(u32*)(this_ + 0x234) = off;
    *(u32*)(this_ + 0x238) = off;
    *(u32*)(this_ + 0x23c) = off;
    *(u32*)(this_ + 0x240) = off;
    *(u32*)(this_ + 0x244) = off;
    *(u32*)(this_ + 0x248) = off;
    *(u32*)(this_ + 0x268) = off;
    *(u8*)(this_ + 0x196) = 1;
    *(f32*)(this_ + 0x29c) = 0.0f;
    *(f32*)(this_ + 0x298) = 0.0f;
    *(f32*)(this_ + 0x294) = 0.0f;
    *(f32*)(this_ + 0x14) = 1.0f;
    *(f32*)(this_ + 0x280) = 2.0f;
    *(f32*)(this_ + 0x28c) = 0.0f;
    *(u32*)(this_ + 0x2bc) = off;
    *(u32*)(this_ + 0x2cc) = off;
    *(u32*)(this_ + 0x2c0) = off;
    *(u32*)(this_ + 0x2d0) = off;
    *(u32*)(this_ + 0x2c4) = off;
    *(u32*)(this_ + 0x2d4) = off;
    *(u32*)(this_ + 0x2c8) = off;
    *(u32*)(this_ + 0x2d8) = off;
    *(u32*)(this_ + 0x2dc) = off;
    *(u8*)(this_ + 0x2bb) = lbl_80539F88[0];
    *(s32*)(this_ + 0x274) = -1;
    *(s32*)(this_ + 0x27c) = 2;
    *(s32*)(this_ + 0x26c) = 0xd2;
    *(u32*)(this_ + 0x270) = off;
    *(s32*)(this_ + 0x108) = 10000;
    *(u16*)(this_ + 0x2b8) = off;
    *(f32*)(this_ + 0x290) = 255.0f;
    *(f32*)(this_ + 0x284) = 0.0f;
    *(f32*)(this_ + 0x288) = 0.0f;
    *(f32*)(this_ + 0x2ac) = 1.0f;
    *(f32*)(this_ + 0x2b0) = 1.0f;
    *(f32*)(this_ + 0x2b4) = 1.0f;
    *(u32*)(this_ + 0x278) = off;
    *(f32*)(this_ + 0x2a0) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x2a4) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x2a8) = *(f32*)(this_ + 0x14);
    *(f32*)(this_ + 0x2a4) += 16.0f;

    switch (*(u32*)(this_ + 0x90)) {
    case 0:
        *(f32*)(this_ + 0x2b4) = 0.0f;
        *(f32*)(this_ + 0x2b0) = 0.0f;
        *(f32*)(this_ + 0x2ac) = 0.0f;
        *(f32*)(this_ + 0x290) = 0.0f;
        fn_802D7440(fn_802D6A9C(), 0);
        // fallthrough
    case 1:
    default:
        *(f32*)(this_ + 0x60) = -16.0f;
        *(f32*)(this_ + 0x64) = -8.0f;
        *(f32*)(this_ + 0x68) = 16.0f;
        *(f32*)(this_ + 0x6c) = 40.0f;
        *(f32*)(this_ + 0x80) = -8.0f;
        *(f32*)(this_ + 0x84) = -8.0f;
        *(f32*)(this_ + 0x88) = 8.0f;
        *(f32*)(this_ + 0x8c) = 8.0f;
        *(u32*)(this_ + 0x114) = 2;
        *(u8*)(this_ + 0x2ba) = 1;
        *(u32*)(this_ + 0x230) = 0;
        break;
    case 10: {
        char* p = this_;
        u8* tbl;
        u16* e;
        s32 i;
        i = 0;
        tbl = (u8*)lbl_804A1210;
        do {
            e = (u16*)(tbl + off);
            *(void**)(p + 0x2bc) = fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, e[0], 1, 2, 0, 0, 1, 1.0f);
            *(void**)(p + 0x2cc) = fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, e[1], 1, 2, 0, 0, 1, 1.0f);
            if (i != 0) {
                if (*(void**)(p + 0x2bc) != 0) {
                    *(u32*)((char*)*(void**)(p + 0x2bc) + 0xf4) |= 4;
                }
                if (*(void**)(p + 0x2cc) != 0) {
                    *(u32*)((char*)*(void**)(p + 0x2cc) + 0xf4) |= 4;
                }
            }
            i++;
            off += 4;
            p += 4;
        } while (i < 4);
        *(u32*)(this_ + 0x118) = 4;
        *(f32*)(this_ + 0x2b4) = 0.0f;
        *(f32*)(this_ + 0x2b0) = 0.0f;
        *(f32*)(this_ + 0x2ac) = 0.0f;
        *(u8*)(this_ + 0x2ba) = 2;
        *(f32*)(this_ + 0x60) = -7.0f;
        *(f32*)(this_ + 0x64) = -7.0f;
        *(f32*)(this_ + 0x68) = 7.0f;
        *(f32*)(this_ + 0x6c) = 7.0f;
        *(f32*)(this_ + 0x80) = -2.0f;
        *(f32*)(this_ + 0x84) = -2.0f;
        *(f32*)(this_ + 0x88) = 2.0f;
        *(f32*)(this_ + 0x8c) = 2.0f;
        *(u32*)(this_ + 0x230) = 0x1a;
        break;
    }
    case 11:
        *(u8*)(this_ + 0x2bb) = lbl_80539F88[4];
        *(u16*)(this_ + 0x94) = off;
        *(u32*)(this_ + 0x118) = 2;
        *(u32*)(this_ + 0x234) = 0x1e;
        *(u8*)(this_ + 0x2ba) = 2;
        *(f32*)(this_ + 0x60) = -2.0f;
        *(f32*)(this_ + 0x64) = -2.0f;
        *(f32*)(this_ + 0x68) = 2.0f;
        *(f32*)(this_ + 0x6c) = 2.0f;
        *(f32*)(this_ + 0x80) = -2.0f;
        *(f32*)(this_ + 0x84) = -2.0f;
        *(f32*)(this_ + 0x88) = 2.0f;
        *(f32*)(this_ + 0x8c) = 2.0f;
        *(u32*)(this_ + 0x230) = 0x1b;
        return;
    }
}
#pragma opt_propagation reset
extern "C" void fn_8017EAB4(void* thisPtr) {
    *(u32*)((char*)thisPtr + 0xf4) |= 1;
    *(u32*)((char*)thisPtr + 0x24) = 1;
}

extern "C" void fn_8017EACC(void* thisPtr, u8 a, u8 b, u8 c) {
    *(u8*)((char*)thisPtr + 0xbc) = a;
    *(u8*)((char*)thisPtr + 0xbd) = b;
    *(u8*)((char*)thisPtr + 0xbe) = c;
}

extern void* lbl_8053AB10;
extern f32 lbl_8053DDC8;
extern "C" u8 fn_8030C2A8(void* mgr, f32* vec);

extern "C" void fn_8017EADC(f32* dst, const f32* src) { dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2]; }

extern "C" void fn_8017EAF8(void* dst, const f32* src) {
    *(JGeometry::TVec3<f32>*)((char*)dst + 0x3c) = *(JGeometry::TVec3<f32>*)src;
}

extern "C" void fn_8017EB0C(void* thisObj, f32 x, f32 y, f32 z) {
	*(f32*)((char*)thisObj + 0x0) = x;
	*(f32*)((char*)thisObj + 0x4) = y;
	*(f32*)((char*)thisObj + 0x8) = z;
}

extern "C" u32 fn_8017EB1C(f32 value) {
    void* p = *(void**)((char*)lbl_8053AB10 + 0x30);
    if (*(u8*)((char*)p + 0x284) == 0) {
        *(u8*)((char*)p + 0x284) = 1;
        *(f32*)((char*)p + 0x28c) = value;
    }
    return 0;
}

#pragma global_optimizer off
extern "C" u8 fn_8017EB44(const f32* pos) {
    char* base;
    s32 done;
    s32 one;
    char* p;
    base = (char*)lbl_8053AB10;
    done = 0;
    p = *(char**)(base + 0x24);
    if (*(u8*)(p + 0x7f5) == 0) {
        one = 1;
        *(u8*)(p + 0x7f4) = one;
        *(u32*)(p + 0x7f8) = 4;
        *(f32*)(p + 0x7fc) = pos[0];
        *(f32*)(p + 0x800) = pos[1];
        *(f32*)(p + 0x804) = pos[2];
        *(u8*)(p + 0x7f6) = done;
        do {} while (0);
        done = one;
    }
    return done;
}
#pragma global_optimizer reset
extern "C" u32 fn_8017EB94(f32* param_1) {
    JGeometry::TVec3<f32> v1;
    JGeometry::TVec3<f32> v0;
    f32 x, y, z;
    y = ((volatile f32*)param_1)[1];
    x = ((volatile f32*)param_1)[0];
    z = lbl_8053DD28;
    void* p = *(void**)((char*)lbl_8053AB10 + 0x24);
    u32 result = 0;
    v0.set(x, y, z);
    if (fn_8030C2A8(p, (f32*)&v0)) {
        v1.set(param_1[2], param_1[3], lbl_8053DD28);
        if (fn_8030C2A8(p, (f32*)&v1)) result = 1;
    }
    return result;
}
#pragma opt_propagation reset
extern "C" void fn_8017EC38(u32* dst, const u32* src) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
}

extern "C" void fn_8017EC5C(JGeometry::TBox2<f32>* box, f32 x0, f32 y0, f32 x1, f32 y1)
{
    box->i.x = x0;
    box->i.y = y0;
    box->f.x = x1;
    box->f.y = y1;
}

extern "C" u8 fn_8017EC70(const f32* pos, f32 val) {
    s32 ret = 0;
    char* p = *(char**)((char*)lbl_8053AB10 + 0x24);
    if (*(u8*)(p + 0x840) == 0) {
        f32 c, y, x;
        x = pos[0];
        *(u8*)(p + 0x840) = ++ret;
        y = pos[1];
        *(f32*)(p + 0x84c) = x;
        c = lbl_8053DDC8;
        *(f32*)(p + 0x844) = x;
        *(f32*)(p + 0x850) = y;
        *(f32*)(p + 0x848) = y;
        *(f32*)(p + 0x854) = val;
        *(f32*)(p + 0x1d4) = c;
        *(f32*)(p + 0x1d8) = c;
    }
    return ret;
}

extern "C" u8 fn_8017ECC0(void) {
    u32 result = 0;
    void* p = *(void**)((char*)lbl_8053AB10 + 0x24);
    if (*(u8*)((char*)p + 0x179) == 0) {
        *(u8*)((char*)p + 0x178) = result = 1;
    }
    return result;
}

extern "C" void fn_8017ECE8(void* thisPtr, f32 a, f32 b) { 
    *(f32*)((char*)thisPtr + 0x0) = a; 
    *(f32*)((char*)thisPtr + 0x4) = b; 
}

extern "C" void fn_8017ECF4(void* thisPtr, u8 a, u8 b, u8 c, u8 d) {
    *(u8*)((char*)thisPtr + 0x0) = a;
    *(u8*)((char*)thisPtr + 0x1) = b;
    *(u8*)((char*)thisPtr + 0x2) = c;
    *(u8*)((char*)thisPtr + 0x3) = d;
}

extern void* fn_8053AB10_ptr;
extern void* lbl_8053AB10;
extern "C" void fn_8017ED08(void) {
    void* p = *(void**)((char*)lbl_8053AB10 + 0x20);
    *(u8*)((char*)p + 0x216) = 1;
}

void __sinit_tu_8017C01C_cpp(void) {
}

