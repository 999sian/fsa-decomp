#include "types.h"
#include "JSystem/JGeometry/Box.h"

extern void* lbl_8053AB10;
extern f32 lbl_8053DDC8;
extern "C" u8 fn_8030C2A8(void* mgr, f32* vec);
extern "C" void fn_801F0E34(void* this_, s32 p1, s32 p2);

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
