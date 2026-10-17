#include "types.h"
#include "JSystem/JGeometry/Box.h"

extern void* lbl_8053AB10;
extern f32 lbl_8053DDC8;
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

extern "C" void fn_8017E770(char* this_) {
    *(u16*)(this_ + 0x94) = (*(u32*)(this_ + 0x90) >> 4) & 0xf;
    *(u32*)(this_ + 0x90) = *(u32*)(this_ + 0x90) & 0xf;
    *(u32*)(this_ + 0x24c) = 0;
    *(u32*)(this_ + 0x250) = 0;
    *(u32*)(this_ + 0x254) = 0;
    *(u32*)(this_ + 0x258) = 0;
    *(u32*)(this_ + 0x25c) = 0;
    *(u32*)(this_ + 0x260) = 0;
    *(u32*)(this_ + 0x264) = 0;
    *(u32*)(this_ + 0x234) = 0;
    *(u32*)(this_ + 0x238) = 0;
    *(u32*)(this_ + 0x23c) = 0;
    *(u32*)(this_ + 0x240) = 0;
    *(u32*)(this_ + 0x244) = 0;
    *(u32*)(this_ + 0x248) = 0;
    *(u32*)(this_ + 0x268) = 0;
    *(u8*)(this_ + 0x196) = 1;
    *(f32*)(this_ + 0x29c) = 0.0f;
    *(f32*)(this_ + 0x298) = 0.0f;
    *(f32*)(this_ + 0x294) = 0.0f;
    *(f32*)(this_ + 0x14) = 1.0f;
    *(f32*)(this_ + 0x280) = 2.0f;
    *(f32*)(this_ + 0x28c) = 0.0f;
    *(u32*)(this_ + 0x2bc) = 0;
    *(u32*)(this_ + 0x2cc) = 0;
    *(u32*)(this_ + 0x2c0) = 0;
    *(u32*)(this_ + 0x2d0) = 0;
    *(u32*)(this_ + 0x2c4) = 0;
    *(u32*)(this_ + 0x2d4) = 0;
    *(u32*)(this_ + 0x2c8) = 0;
    *(u32*)(this_ + 0x2d8) = 0;
    *(u32*)(this_ + 0x2dc) = 0;
    *(u8*)(this_ + 0x2bb) = lbl_80539F88[0];
    *(s32*)(this_ + 0x274) = -1;
    *(s32*)(this_ + 0x27c) = 2;
    *(s32*)(this_ + 0x26c) = 0xd2;
    *(u32*)(this_ + 0x270) = 0;
    *(s32*)(this_ + 0x108) = 10000;
    *(u16*)(this_ + 0x2b8) = 0;
    *(f32*)(this_ + 0x290) = 255.0f;
    *(f32*)(this_ + 0x284) = 0.0f;
    *(f32*)(this_ + 0x288) = 0.0f;
    *(f32*)(this_ + 0x2ac) = 1.0f;
    *(f32*)(this_ + 0x2b0) = 1.0f;
    *(f32*)(this_ + 0x2b4) = 1.0f;
    *(u32*)(this_ + 0x278) = 0;
    *(f32*)(this_ + 0x2a0) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x2a4) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x2a8) = *(f32*)(this_ + 0x14);
    *(f32*)(this_ + 0x2a4) = *(f32*)(this_ + 0x2a4) + 16.0f;

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
        for (int i = 0; i < 4; i++) {
            *(void**)(p + 0x2bc) = fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, lbl_804A1210[i][0], 1, 2, 0, 0, 1, 1.0f);
            *(void**)(p + 0x2cc) = fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, lbl_804A1210[i][1], 1, 2, 0, 0, 1, 1.0f);
            if (i != 0) {
                if (*(void**)(p + 0x2bc) != 0) {
                    *(u32*)((char*)*(void**)(p + 0x2bc) + 0xf4) |= 4;
                }
                if (*(void**)(p + 0x2cc) != 0) {
                    *(u32*)((char*)*(void**)(p + 0x2cc) + 0xf4) |= 4;
                }
            }
            p += 4;
        }
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
        *(u16*)(this_ + 0x94) = 0;
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

extern "C" void fn_8017EAB4(void* thisPtr) {
    *(u32*)((char*)thisPtr + 0xf4) |= 1;
    *(u32*)((char*)thisPtr + 0x24) = 1;
}

extern "C" void fn_8017EACC(void* thisPtr, u8 a, u8 b, u8 c) {
    *(u8*)((char*)thisPtr + 0xbc) = a;
    *(u8*)((char*)thisPtr + 0xbd) = b;
    *(u8*)((char*)thisPtr + 0xbe) = c;
}

extern "C" void fn_8017EADC(f32* dst, const f32* src) { dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2]; }

extern "C" void fn_8017EAF8(void* dst, const f32* src) {
    *(f32*)((char*)dst + 0x3c) = src[0];
    *(f32*)((char*)dst + 0x40) = src[1];
    *(f32*)((char*)dst + 0x44) = src[2];
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

extern "C" u8 fn_8017EB44(const f32* pos) {
    void* base = *(void**)lbl_8053AB10;
    u8 done = 0;
    void* p = *(void**)((char*)base + 0x24);
    
    if (*(u8*)((char*)p + 0x7f5) == 0) {
        done = 1;
        *(u8*)((char*)p + 0x7f4) = 1;
        *(u32*)((char*)p + 0x7f8) = 4;
        *(f32*)((char*)p + 0x7fc) = pos[0];
        *(f32*)((char*)p + 0x800) = pos[1];
        *(f32*)((char*)p + 0x804) = pos[2];
        *(u8*)((char*)p + 0x7f6) = 0;
    }
    
    return done;
}

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
    void* p = *(void**)((char*)lbl_8053AB10 + 0x24);
    if (*(u8*)((char*)p + 0x840) == 0) {
        *(u8*)((char*)p + 0x840) = 1;
        *(f32*)((char*)p + 0x844) = pos[0];
        *(f32*)((char*)p + 0x84c) = pos[0];
        *(f32*)((char*)p + 0x848) = pos[1];
        *(f32*)((char*)p + 0x850) = pos[1];
        *(f32*)((char*)p + 0x854) = val;
        *(f32*)((char*)p + 0x1d4) = lbl_8053DDC8;
        *(f32*)((char*)p + 0x1d8) = lbl_8053DDC8;
        return 1;
    }
    return 0;
}

extern "C" u8 fn_8017ECC0(void) {
    u8 result = 0;
    void* base;
    void* p;
    base = *(void**)lbl_8053AB10;
    p = *(void**)((char*)base + 0x24);
    if (*(u8*)((char*)p + 0x179) == 0) {
        *(u8*)((char*)p + 0x178) = 1;
        result = 1;
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
