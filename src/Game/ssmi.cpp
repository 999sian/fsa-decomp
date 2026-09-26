// TU 0x80376394-0x80376850 (actor SSMI).
#include "types.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);

extern void* lbl_804AE6D0[];

extern "C" void* fn_80376394(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AE6D0;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

class SsmiActorV {
public:
    virtual void s00(); virtual void s01(); virtual void s02(); virtual void s03();
    virtual void s04(); virtual void s05(); virtual void s06(); virtual void s07();
    virtual void s08(); virtual void s09(); virtual void s10(); virtual u8 s11();
};
extern "C" u8* fn_8020D58C(void);
extern "C" void fn_8020D7D0(void* slot, u32 id);
extern "C" s32 fn_801F8108(void* actor, u32 type, s32 p3, f32 range);
extern "C" void* fn_801F856C(void);
extern "C" char* fn_801F666C(void* mgr, s32 id);
extern "C" void fn_802C2BD0(void* actor);

extern "C" void fn_803763F4(void* thisPtr) {
    char* p = (char*)thisPtr;
    switch (*(s32*)(p + 0x234)) {
    case 0:
        if (*(s32*)(p + 0x230) == 0 || ((SsmiActorV*)p)->s11()) {
            u32 id = *(u32*)(p + 0x198);
            u8* sys = fn_8020D58C();
            fn_8020D7D0(sys + sys[0] * 0x784 + 4, id);
        }
        break;
    case 1: {
        s32 n = fn_801F8108(p, 'KEY0', -1, 32.0f);
        if (n >= 0) {
            char* a = fn_801F666C(fn_801F856C(), n);
            if (a != NULL && *(s32*)(a + 0x240) == 4 && *(f32*)(a + 0x40) < 0.0f) {
                fn_802C2BD0(a);
            }
        }
        break;
    }
    }
}

extern "C" void fn_803764D4(void* thisPtr) {
    char* p = (char*)thisPtr;
    *(u32*)(p + 0x230) = *(u32*)(p + 0x90) >> 27;
    *(u32*)(p + 0x234) = (*(u32*)(p + 0x90) >> 22) & 0x1F;
    *(f32*)(p + 0x3c) = 0.0f;
    *(f32*)(p + 0x40) = 0.0f;
    *(f32*)(p + 0x44) = 0.0f;
    u32 flags = *(u32*)(p + 0x90);
    f32 w = (u32)(((flags & 0xFF) + 1) * 8);
    f32 h = (u32)((((flags >> 8) & 0xFF) + 1) * 8);
    if (*(s32*)(p + 0x234) == 1) {
        h = 4.0f;
    }
    if ((flags >> 16) & 1) {
        *(f32*)(p + 0xc) += w;
        *(f32*)(p + 0x10) += h;
    } else {
        *(f32*)(p + 0xc) = w + (f32)((s32)*(f32*)(p + 0xc) / 16 * 16);
        *(f32*)(p + 0x10) = h + (f32)((s32)*(f32*)(p + 0x10) / 16 * 16);
    }
    *(f32*)(p + 0x80) = -w;
    *(f32*)(p + 0x84) = -h;
    *(f32*)(p + 0x88) = w;
    *(f32*)(p + 0x8c) = h;
    if (*(s32*)(p + 0x234) == 1) {
        *(f32*)(p + 0x60) = -w;
        *(f32*)(p + 0x64) = -h;
        *(f32*)(p + 0x68) = w;
        *(f32*)(p + 0x6c) = h;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
