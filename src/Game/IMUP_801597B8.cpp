#include "types.h"
#include "Game/SinitPoolChain.h"

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
    Vec2f xy;
    f32 z;
};

extern "C" s32 fn_801597B8(char* p) {
    return *(s32*)(p + 0x230);
}

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* p);
extern void* lbl_804A01D0[];
extern "C" void fn_80236DB0(void*);
extern "C" void fn_80236C88(void*);
extern "C" void fn_80236ED8(void*, s32);
extern "C" void* fn_802373EC(void*);
extern "C" void* fn_8023725C(void*);
extern "C" void fn_802372F8(void*, s32, s32);
extern u8* lbl_8053AAF8;
extern "C" void* fn_801F856C(void);
extern "C" void Actor_CreateByID(void*, u32, void*, void*, u32, s32, s32);
extern "C" void fn_801597C0(FSAVirtBase* p) {
    p->m7();
}

extern "C" void fn_801597EC(char* this_) {
    s32 id = *(s32*)(this_ + 0x234);
    if (id == 0x10 || (u32)(id - 0x11) <= 1 || (u32)(id - 0x16) <= 2 || id == 0x19) {
        Actor_CreateByID(fn_801F856C(), 0x4b455930, *(void**)(this_ + 0x4), this_ + 0xc, id + (*(s32*)(this_ + 0x250) * 0x1000) + 0xf0, -1, -1);
    } else if (id == 0x13) {
        fn_80236DB0(*(void**)(this_ + 0x274));
    } else if (id == 0x15) {
        fn_80236C88(*(void**)(this_ + 0x274));
    } else if (id == 0x20) {
        Actor_CreateByID(fn_801F856C(), 0x4352544c, *(void**)(this_ + 0x4), this_ + 0xc, (*(s32*)(this_ + 0x250) << 16) | 1, -1, -1);
    } else if (id == 0x21) {
        Actor_CreateByID(fn_801F856C(), 0x4e495741, *(void**)(this_ + 0x4), this_ + 0xc, (*(s32*)(this_ + 0x250) << 8) | 5, -1, -1);
    } else if (id == 0x22) {
        Actor_CreateByID(fn_801F856C(), 0x424d5459, *(void**)(this_ + 0x4), this_ + 0xc, (*(s32*)(this_ + 0x250) << 16) | 5, -1, -1);
    } else if (id == 0x23) {
        Actor_CreateByID(fn_801F856C(), 0x4e4e4a4e, *(void**)(this_ + 0x4), this_ + 0xc, 0, -1, -1);
    } else if (id == 0x24) {
        Actor_CreateByID(fn_801F856C(), 0x4e495741, *(void**)(this_ + 0x4), this_ + 0xc, (*(s32*)(this_ + 0x250) << 8) | 0x1005, -1, -1);
    } else if (id == 0x25) {
        Actor_CreateByID(fn_801F856C(), 0x4352544c, *(void**)(this_ + 0x4), this_ + 0xc, (*(s32*)(this_ + 0x250) << 16) | 3, -1, -1);
    } else if (id >= 0x30) {
        if (id == 0x4a) {
            fn_80236ED8(*(void**)(this_ + 0x274), 2);
        } else {
            s32 kind = 1;
            s32 n = id - 0x2f;
            if (id >= 0x40) {
                n = id - 0x3f;
                kind = 2;
            }
            if (*(s32*)(this_ + 0x264) == 0) {
                if (*(s32*)(this_ + 0x254) == 0 && (s32)fn_802373EC(*(void**)(this_ + 0x250)) != 0 && lbl_8053AAF8[0x7f] == 1 && *(s32*)(this_ + 0x258) == 0) {
                    *(s32*)(this_ + 0x294) = (s32)fn_802373EC(*(void**)(this_ + 0x274));
                    *(s32*)(this_ + 0x298) = (s32)fn_8023725C(*(void**)(this_ + 0x274));
                }
                fn_802372F8(*(void**)(this_ + 0x250), n, kind);
            }
        }
    }
}

extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void*, s32);
extern "C" f32 lbl_8053D4AC;
extern "C" f32 lbl_8053D480;
extern "C" u8* lbl_8053AED0;
extern "C" void* lbl_804A0170[];
extern "C" u8 fn_8022F514(s32 i);
extern "C" void* fn_8022F3DC(s32 i);
extern "C" void fn_802362C4(void* p, void* v);
extern "C" void fn_8043D874(u8* p, void* q, void* r, s32 s);
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

void __sinit_IMUP_801597B8_cpp(void) {}

