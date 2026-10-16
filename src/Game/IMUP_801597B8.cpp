#include "types.h"

class FSAVirtBase {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
};

struct Vec2f {
    f32 x, y;
};

struct Vec3f {
    f32 x, y, z;
};

extern "C" s32 fn_801597B8(char* p) {
    return *(s32*)(p + 0x230);
}

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* p);
extern void* lbl_804A01D0[];
extern "C" void fn_801597C0(FSAVirtBase* p) {
    p->m7();
}

extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void*, s32);
extern "C" void fn_802ED140(void*);
extern "C" void* fn_8023E724(void*);
extern "C" void Actor_CreateByID(void*, u32, void*, void*, u32, s32, s32);
extern "C" void fn_80159AA0(char* this_) {
    char* a = *(char**)(this_ + 0x2a8);
    if (a != NULL) {
        *(u32*)(a + 0xf4) |= 1;
        *(s32*)(a + 0x24) = 1;
        *(u32*)(*(char**)(this_ + 0x2a8) + 0xf4) |= 1;
        *(void**)(this_ + 0x2a8) = NULL;
    }
    a = *(char**)(this_ + 0x2ac);
    if (a != NULL) {
        *(u32*)(a + 0xf4) |= 1;
        *(s32*)(a + 0x24) = 1;
        *(u32*)(*(char**)(this_ + 0x2ac) + 0xf4) |= 1;
        *(void**)(this_ + 0x2ac) = NULL;
    }
    a = *(char**)(this_ + 0x2b0);
    if (a != NULL) {
        *(u32*)(a + 0xf4) |= 1;
        *(s32*)(a + 0x24) = 1;
        *(u32*)(*(char**)(this_ + 0x2b0) + 0xf4) |= 1;
        *(void**)(this_ + 0x2b0) = NULL;
    }
    s32 id = *(s32*)(this_ + 0x260);
    if (id != 0) {
        char* b = (char*)fn_801F666C(fn_801F856C(), id);
        if (b != NULL) {
            fn_802ED140(b);
        }
    }
    this_[0x11c] = 0;
    id = *(s32*)(this_ + 0x278);
    if (id >= 0) {
        char* b = (char*)fn_801F666C(fn_801F856C(), id);
        if (b != NULL) {
            b[0x11c] = 0;
        }
        *(s32*)(this_ + 0x278) = -1;
    }
    if (*(s32*)(this_ + 0x294) >= 0) {
        *(Vec3f*)(this_ + 0x27c) = *(Vec3f*)fn_8023E724(*(void**)(this_ + 0x250));
    }
    Actor_CreateByID(fn_801F856C(), 0x4C535449, *(void**)(this_ + 0x4), this_ + 0x27c, (*(u32*)(this_ + 0x298) << 22) | *(u32*)(this_ + 0x294), -1, -1);
}

extern "C" void* fn_8015B420(char* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804A01D0;
        fn_801EE434(*(void**)(this_ + 0x2a8));
        fn_801EE434(*(void**)(this_ + 0x2ac));
        fn_801EE434(*(void**)(this_ + 0x2b0));
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}
