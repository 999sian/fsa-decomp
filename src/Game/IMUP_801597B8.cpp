#include "types.h"
#include "Game/SinitPoolChain.h"
#include "Game/ItemBase.h"

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

struct FSAObjMgr {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void* m6(u32 id, const char* name);
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
extern u8* lbl_8053AB10;
extern const char lbl_804660B8[];
extern const char lbl_804660CC[];
extern s32 lbl_804A01A0[];
extern const f32 lbl_8053D460;
extern "C" u8 fn_8023188C(void* p);
extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern "C" void fn_803075AC(void* h, s32 room, void* pos, s32 id, s32 sign, s32 two, s32 minus1, s32 p7, s32 u, s32 zero);
extern "C" void fn_802F86CC(void* obj, Vec3f* pos, void* p3, s32 id, f32 a, f32 b, DrawRec* rec);
extern "C" void* fn_801F856C(void);
extern "C" void Actor_CreateByID(void*, u32, void*, void*, u32, s32, s32);
extern "C" void fn_801597C0(FSAVirtBase* p) {
    p->m7();
}

extern "C" void fn_801597EC(char* this_) {
    s32 id = *(s32*)(this_ + 0x234);
    if (id == 0x10 || (u32)(id - 0x11) <= 1 || (u32)(id - 0x16) <= 2 || id == 0x19) {
        Actor_CreateByID(fn_801F856C(), 0x4b455930, *(void**)(this_ + 0x4), this_ + 0xc, (id + 0xf0) + (*(s32*)(this_ + 0x250) << 12), -1, -1);
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

extern "C" void fn_80159C28(char* this_) {
    if (fn_8023188C(*(void**)(this_ + 0x250))) {
        s32 flag = 0;
        if (*(s32*)(this_ + 0x234) >= 8 && *(s32*)(this_ + 0x234) <= 0xb) {
            flag = 1;
        }
        DrawRec rec;
        rec.b1d = 1;
        rec.b1c = 1;
        rec.b2d = 1;
        s32 id = *(s32*)(this_ + 0x234);
        if (id != 0x2f) {
            if (id <= 7) {
                fn_801F06F0(this_, lbl_804660B8, *(s32*)(this_ + 0x244) + lbl_804A01A0[id], &rec, -1, 1.0f, 1.0f);
                fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xc, *(s32*)(this_ + 0x244) + lbl_804A01A0[*(s32*)(this_ + 0x234)], flag != 0, 2, -1, 1, 0, 0);
            } else if (id <= 0xb) {
                fn_801F06F0(this_, lbl_804660CC, *(s32*)(this_ + 0x244) + lbl_804A01A0[id], &rec, -1, 1.0f, 1.0f);
                fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xc, *(s32*)(this_ + 0x244) + lbl_804A01A0[*(s32*)(this_ + 0x234) - 4], flag != 0, 2, -1, 1, 0, 0);
            } else if (id >= 0x10 && id <= 0x19) {
                s32 n = id + 0x1d;
                Vec3f pos;
                pos.z = *(f32*)(this_ + 0x14);
                pos.xy.y = *(f32*)(this_ + 0x10);
                pos.xy.x = *(f32*)(this_ + 0xc);
                if (*(s32*)(this_ + 4) < 8) {
                    void* obj = *(void**)(lbl_8053AAF8 + 0xa4);
                    void* model = ((void* (*)(void*, u32, const char*))(*(void***)obj)[6])(obj, 0x534f4220, lbl_804660B8);
                    fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), &pos, model, n, 1.0f, 1.0f, &rec);
                }
                fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xc, *(s32*)(this_ + 0x234) + 0x1d, 0, 2, -1, 1, 0, 0);
            } else if (id == 0x20) {
                fn_801F06F0(this_, lbl_804660B8, *(s32*)(this_ + 0x244) + 0x90, &rec, -1, 1.0f, 1.0f);
                fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xc, *(s32*)(this_ + 0x244) + 0x90, 0, 2, -1, 1, 0, 0);
            } else if (id == 0x21) {
                fn_801F06F0(this_, lbl_804660B8, *(s32*)(this_ + 0x244) + 0x2af, &rec, -1, 1.0f, 1.0f);
                fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xc, *(s32*)(this_ + 0x244) + 0x2af, 0, 2, -1, 1, 0, 0);
            } else if (id == 0x22) {
                fn_801F06F0(this_, lbl_804660B8, *(s32*)(this_ + 0x244) + 0x8c, &rec, 7, 1.0f, 1.0f);
                fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xc, *(s32*)(this_ + 0x244) + 0x8c, 0, 2, -1, 0, 0, 0);
            } else if (id == 0x23) {
                rec.b2d = 1;
                fn_801F06F0(this_, lbl_804660B8, 0x2aa, &rec, 7, 1.0f, 1.0f);
                fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xc, 0x2aa, 0, 2, -1, 0, 0, 0);
            } else if (id == 0x24) {
                fn_801F06F0(this_, lbl_804660B8, *(s32*)(this_ + 0x244) + 0x2c7, &rec, -1, 1.0f, 1.0f);
                fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xc, *(s32*)(this_ + 0x244) + 0x2c7, 0, 2, -1, 1, 0, 0);
            } else if (id == 0x25) {
                fn_801F06F0(this_, lbl_804660B8, 0x98, &rec, -1, 1.0f, 1.0f);
                fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xc, 0x98, 0, 2, -1, 1, 0, 0);
            } else if (id >= 0x2a && id <= 0x2d) {
                fn_801F06F0(this_, lbl_804660CC, id + 0x255, &rec, -1, 1.0f, 1.0f);
            } else if (id != 0x2e) {
                if (id < 0x40) {
                    s32 n = id + 0x11;
                    Vec3f pos;
                    pos.z = *(f32*)(this_ + 0x14);
                    pos.xy.y = *(f32*)(this_ + 0x10);
                    pos.xy.x = *(f32*)(this_ + 0xc);
                    if (*(s32*)(this_ + 4) < 8) {
                        void* obj = *(void**)(lbl_8053AAF8 + 0xa4);
                        void* model = ((void* (*)(void*, u32, const char*))(*(void***)obj)[6])(obj, 0x534f4220, lbl_804660B8);
                        fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), &pos, model, n, 1.0f, 1.0f, &rec);
                    }
                    fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xc, *(s32*)(this_ + 0x234) + 0x11, 0, 2, -1, 1, 0, 0);
                } else {
                    s32 n = id + 0x1cd;
                    Vec3f pos;
                    pos.z = *(f32*)(this_ + 0x14);
                    pos.xy.y = *(f32*)(this_ + 0x10);
                    pos.xy.x = *(f32*)(this_ + 0xc);
                    if (*(s32*)(this_ + 4) < 8) {
                        void* obj = *(void**)(lbl_8053AAF8 + 0xa4);
                        void* model = ((void* (*)(void*, u32, const char*))(*(void***)obj)[6])(obj, 0x534f4220, lbl_804660B8);
                        fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), &pos, model, n, 1.0f, 1.0f, &rec);
                    }
                    fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xc, *(s32*)(this_ + 0x234) + 0x1cd, 0, 2, -1, 1, 0, 0);
                }
            }
        }
    }
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

extern "C" void fn_8015B49C(char* this_) {
    s32 id;
    f32 zero = lbl_8053D4AC;
    Vec3f* src;
    *(s32*)(this_ + 0x234) = *(u32*)(this_ + 0x90) & 0xfff;
    *(s32*)(this_ + 0x250) = (*(u32*)(this_ + 0x90) >> 24) & 3;
    *(s32*)(this_ + 0x24c) = (*(u32*)(this_ + 0x90) >> 26) & 3;
    *(s32*)(this_ + 0x254) = (*(u32*)(this_ + 0x90) >> 28) & 1;
    *(s32*)(this_ + 0x268) = (*(u32*)(this_ + 0x90) >> 23) & 1;
    *(s32*)(this_ + 0x26c) = (*(u32*)(this_ + 0x90) >> 22) & 1;
    *(s32*)(this_ + 0x270) = (*(u32*)(this_ + 0x90) >> 21) & 1;
    *(s32*)(this_ + 0x258) = *(u32*)(this_ + 0x90) >> 31;
    *(s32*)(this_ + 0x25c) = (*(u32*)(this_ + 0x90) >> 30) & 1;
    *(s32*)(this_ + 0x264) = (*(u32*)(this_ + 0x90) >> 29) & 1;
    *(s32*)(this_ + 0x2a8) = 0;
    *(s32*)(this_ + 0x2ac) = 0;
    *(s32*)(this_ + 0x2b0) = 0;
    *(s32*)(this_ + 0x290) = -1;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0x1a;
    *(f32*)(this_ + 0x29c) = zero;
    *(f32*)(this_ + 0x2a0) = zero;
    *(f32*)(this_ + 0x2a4) = zero;
    *(f32*)(this_ + 0x3c) = zero;
    *(f32*)(this_ + 0x40) = zero;
    *(f32*)(this_ + 0x44) = zero;
    if (lbl_8053AAF8[0x7f] == 1) {
        *(s32*)(this_ + 0x238) = 0x5a;
    } else {
        *(s32*)(this_ + 0x238) = 0x2d;
    }
    *(s32*)(this_ + 0x288) = 0;
    src = (Vec3f*)fn_8023E724((void*)*(s32*)(this_ + 0x250));
    *(Vec3f*)(this_ + 0x27c) = *src;
    *(s32*)(this_ + 0x274) = *(s32*)(this_ + 0x250);
    if (fn_8022F514(*(s32*)(this_ + 0x250))) {
        *(void**)(this_ + 0x274) = fn_8022F3DC(*(s32*)(this_ + 0x250));
    }
    *(s32*)(this_ + 0x28c) = 0xa;
    id = *(s32*)(this_ + 0x234);
    switch (id) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 0x2e:
        if (*(s32*)(this_ + 0x25c) == 0) {
            fn_802362C4(*(void**)(this_ + 0x274), lbl_804A0170[id]);
        }
        break;
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        if (*(s32*)(this_ + 0x25c) == 0) {
            fn_8043D874(lbl_8053AED0, *(void**)(this_ + 0x274), lbl_804A0170[id], 0);
            if (*(s32*)(this_ + 0x270) != 0) {
                *(s32*)(this_ + 0x28c) = 2;
            }
        }
        break;
    }
    *(f32*)(this_ + 0x14) = lbl_8053D480 + *(f32*)(this_ + 0x284);
    Actor_CreateByID(fn_801F856C(), 0x42424d42, *(void**)(this_ + 4), this_ + 0xc, 0x20000, -1, -1);
    *(s32*)(this_ + 0x230) = 0;
    if (*(s32*)(this_ + 0x258) == 0) {
        if (*(s32*)(this_ + 0x28c) != 2) {
            Actor_CreateByID(fn_801F856C(), 0x5354504e, *(void**)(this_ + 4), this_ + 0xc, 0, -1, -1);
        }
    }
    *(s32*)(this_ + 0x278) = -1;
    *(s32*)(this_ + 0x294) = -1;
}

void __sinit_IMUP_801597B8_cpp(void) {}

