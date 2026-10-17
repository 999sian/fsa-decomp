#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "Game/SinitPoolChain.h"

extern "C" u8* fn_802D6A9C(void);
extern "C" void fn_801F0E34(void* this_, s32 p1, s32 p2);
extern "C" void fn_802D7440(u8* mgr, s32 p);
extern "C" void fn_8022ADCC(void);
extern "C" void fn_801EE434(void* p);
extern "C" void __dt__5ActorFv(void* this_, s32 p);
extern "C" void __dl__FPv(void* p);
extern "C" char __vt__4GROK[];

struct ActorVt_grok {
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

extern "C" void fn_8017EF40(ActorVt_grok* this_) {
    fn_801F0E34(this_, 0x40038, 0);
    this_->setShadow(2, 0.0f, 16.0f);
}

extern "C" void* fn_80181FFC(void* this_, s16 param_2) {
    if (this_ != 0) {
        *(void**)this_ = __vt__4GROK;
        if (*(u32*)((u8*)this_ + 0x90) == 0) {
            u8* mgr = fn_802D6A9C();
            fn_802D7440(mgr, 1);
            fn_8022ADCC();
        }
        for (s32 i = 0; i < 2; i++) {
            void* p = *(void**)((u8*)this_ + 0x318 + i * 4);
            if (p != 0) {
                fn_801EE434(p);
            }
        }
        __dt__5ActorFv(this_, 0);
        if (param_2 > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_80182640(void* thisObj, f32 x, f32 y, f32 z) {
	*(f32*)((char*)thisObj + 0x0) = x;
	*(f32*)((char*)thisObj + 0x4) = y;
	*(f32*)((char*)thisObj + 0x8) = z;
}

extern "C" void fn_80182650(void* thisObj, f32 x, f32 y, f32 z) {
	*(f32*)((char*)thisObj + 0x0) = x;
	*(f32*)((char*)thisObj + 0x4) = y;
	*(f32*)((char*)thisObj + 0x8) = z;
}

extern "C" void fn_80182660(u8* dst, const f32* src) { JGeometry::setTVec3f(src, (f32*)(dst + 0xc)); }

extern "C" void fn_80182674(f32* dst, const f32* src) { dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2]; }

extern "C" void fn_80182690(f32* dst, const f32* src) { dst[0] = src[0]; dst[1] = src[1]; }

extern "C" u8* fn_801826A4(s32 idx) {
    u8* mgr = fn_802D6A9C();
    if (idx < 8) {
        return mgr + 0xcc;
    }
    return mgr + 0xdc;
}

extern "C" void fn_801826E4(f32* dst, f32 a, f32 b) { dst[0] = a; dst[1] = b; }

