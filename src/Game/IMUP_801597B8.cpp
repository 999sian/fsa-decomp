#include "types.h"
#include "Game/SinitPoolChain.h"
#include "Game/ItemBase.h"
#include "JSystem/JGeometry/Vec.h"

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
    virtual void* getResource(u32 id, const char* name);
};

struct Vec2f {
    f32 x, y;
};

struct Vec3f {
    Vec2f xy;
    f32 z;
};

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
extern "C" u8 fn_8023188C(void* p);
extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern "C" void fn_803075AC(void* h, s32 room, void* pos, s32 id, s32 sign, s32 two, s32 minus1, s32 p7, s32 u, s32 zero);
extern "C" void fn_802F86CC(void* obj, Vec3f* pos, void* p3, s32 id, f32 a, f32 b, DrawRec* rec);
extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void*, u32, void*, void*, u32, s32, s32);
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
extern "C" const f32 lbl_8053D4AC;
extern "C" f32 lbl_8053D480;
extern "C" u8* lbl_8053AED0;
extern "C" void* lbl_804A0170[];
extern "C" u8 fn_8022F514(s32 i);
extern "C" void* fn_8022F3DC(s32 i);
extern "C" void fn_802362C4(void* p, void* v);
extern "C" void fn_8043D874(u8* p, void* q, void* r, s32 s);
extern "C" void fn_802ED140(void*);
extern "C" void* fn_8023E724(void*);
extern "C" s32 Actor_CreateByID(void*, u32, void*, void*, u32, s32, s32);
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
        JGeometry::setTVec3f((const f32*)fn_8023E724(*(void**)(this_ + 0x250)), (f32*)(this_ + 0x27c));
    }
    u32 flags = (*(u32*)(this_ + 0x298) << 22) | *(u32*)(this_ + 0x294);
    Actor_CreateByID(fn_801F856C(), 0x4C535449, *(void**)(this_ + 0x4), this_ + 0x27c, flags, -1, -1);
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
                JGeometry::TVec3<f32> pos(*(f32*)(this_ + 0xc), *(f32*)(this_ + 0x10), *(f32*)(this_ + 0x14));
                if (*(s32*)(this_ + 4) < 8) {
                    void* model = (*(FSAObjMgr**)(lbl_8053AAF8 + 0xa4))->getResource(0x534f4220, lbl_804660B8);
                    fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), (Vec3f*)&pos, model, n, 1.0f, 1.0f, &rec);
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
                    JGeometry::TVec3<f32> pos(*(f32*)(this_ + 0xc), *(f32*)(this_ + 0x10), *(f32*)(this_ + 0x14));
                    if (*(s32*)(this_ + 4) < 8) {
                        void* model = (*(FSAObjMgr**)(lbl_8053AAF8 + 0xa4))->getResource(0x534f4220, lbl_804660B8);
                        fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), (Vec3f*)&pos, model, n, 1.0f, 1.0f, &rec);
                    }
                    fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xc, *(s32*)(this_ + 0x234) + 0x11, 0, 2, -1, 1, 0, 0);
                } else {
                    s32 n = id + 0x1cd;
                    JGeometry::TVec3<f32> pos(*(f32*)(this_ + 0xc), *(f32*)(this_ + 0x10), *(f32*)(this_ + 0x14));
                    if (*(s32*)(this_ + 4) < 8) {
                        void* model = (*(FSAObjMgr**)(lbl_8053AAF8 + 0xa4))->getResource(0x534f4220, lbl_804660B8);
                        fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), (Vec3f*)&pos, model, n, 1.0f, 1.0f, &rec);
                    }
                    fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xc, *(s32*)(this_ + 0x234) + 0x1cd, 0, 2, -1, 1, 0, 0);
                }
            }
        }
    }
}

extern "C" void fn_801F71A4(f32* p, f32 a, f32 b, f32 c);
extern "C" void fn_8043D67C(u8* p, s32 id, void* h, s32 zero);
extern "C" u8 fn_8038BD08(s32, s32, s32, JGeometry::TVec3<f32>*, s32);
static inline u8 requestMessage(s32 player, s32 id, s32 room, const JGeometry::TVec3<f32>& pos, s32 flags) {
    JGeometry::TVec3<f32> copy(pos);
    return fn_8038BD08(player, id, room, &copy, flags);
}
extern "C" void fn_80230EB8(s32 h, s32 id);
extern "C" void* fn_8022F340(void* h);
extern "C" void fn_80236804(void* p, s32 n);
extern "C" void fn_80230F44(s32 h, s32 id);
extern "C" void* fn_8013CC50(s32 room, void* p, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_80230498(s32 h, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d);
extern "C" u8 fn_80233E40(s32 h);
extern "C" void fn_80230FD0(s32 h, s32 id);
extern "C" void fn_801F6718(void* a, void* b, s32 c, void* d, s32 e, s32 f);
extern "C" void* fn_8030AAF4(s32 i);
extern "C" void* fn_80309D6C(void* p, void* q, s32 n);
extern "C" u8 fn_803865B8(s32 h);
extern "C" u8 fn_80388EEC(s32 h);
extern "C" u8 fn_8023061C(void* h, s32 n);
extern "C" u8 fn_80230224(s32 h, s32 n);
extern "C" u8 fn_80230534(s32 n);
extern "C" void fn_8037E8D4(s32 h);
extern s32 lbl_80465F78[];
extern u32 lbl_80465E38[];
extern void* lbl_8053AD30;
extern u8* lbl_8053AF80;
extern "C" const f32 lbl_8053D460;
extern "C" const f32 lbl_8053D464;
extern "C" const f32 lbl_8053D468;
extern "C" const f32 lbl_8053D46C;
extern "C" const f32 lbl_8053D470;
extern "C" const f32 lbl_8053D474;
extern "C" const f32 lbl_8053D478;
extern "C" const f32 lbl_8053D47C;
extern "C" const f32 lbl_8053D484;
extern "C" const f32 lbl_8053D488;
extern "C" const f32 lbl_8053D48C;
extern "C" const f32 lbl_8053D490;
extern "C" const f32 lbl_8053D494;
extern "C" const f32 lbl_8053D498;
extern "C" const f32 lbl_8053D49C;
extern "C" const f32 lbl_8053D4A0;
extern "C" const f32 lbl_8053D4A4;
extern "C" const f32 lbl_8053D4A8;
extern "C" const f32 lbl_8053D4B0;

static inline void spawnSparkle(char* p, f32 dy) {
    JGeometry::TVec3f c(*(JGeometry::TVec3f*)(p + 0xc));
    c.y -= dy;
    fn_801F6718(fn_801F856C(), *(void**)(p + 0x274), *(s32*)(p + 4), &c, *(s32*)(p + 0x234), 2);
}

static inline void* findGbaLink() {
    for (s32 i = 0; i < 4; i++) {
        void* r = fn_80309D6C(lbl_8053AD30, fn_8030AAF4(i), 0x100);
        if (r) return r;
    }
    return NULL;
}

extern "C" void fn_8015A374(char* this_) {
    typedef u8 (*MsgFn)(s32, s32, s32, JGeometry::TVec3f, s32);
    typedef void* (*SpawnFn)(s32, const JGeometry::TVec3f&, f32, s32, s32, s32, s32, s32, s32);
    fn_801F71A4((f32*)(this_ + 0x3c), *(f32*)(this_ + 0x29c), lbl_8053D464, lbl_8053D460);
    fn_801F71A4((f32*)(this_ + 0x40), *(f32*)(this_ + 0x2a0), lbl_8053D464, lbl_8053D460);
    ((JGeometry::TVec3f*)(this_ + 0xc))->add(*(JGeometry::TVec3f*)(this_ + 0x3c));
    switch (*(s32*)(this_ + 0x230)) {
    case 0:
        if (*(s32*)(this_ + 0x238) <= 0) {
            if (*(s32*)(this_ + 0x26c) != 0) {
                *(s32*)(this_ + 0x230) = 1;
                break;
            }
            if (*(s32*)(this_ + 0x258) == 0) {
                if (*(s32*)(this_ + 4) >= 8 && lbl_8053AAF8[0x7e] == 1) {
                    fn_8043D67C(lbl_8053AED0, lbl_80465F78[*(s32*)(this_ + 0x234)], *(void**)(this_ + 0x274), 0);
                }
                s32 id = *(s32*)(this_ + 0x234);
                if (lbl_80465E38[id] == 0x27f) {
                    if (((u32)(lbl_8053AAF8[0x83] >> (*(s32*)(this_ + 0x274) * 2)) & 3) == 2) {
                        s32 player = *(s32*)(this_ + 0x250);
                        if (player == *(s32*)(this_ + 0x24c)) {
                            *(s32*)(this_ + 0x278) = Actor_CreateByID(fn_801F856C(), 0x50454646, *(void**)(this_ + 4), this_ + 0xc, (player & 3) | 0x24, -1, -1);
                            s32 room = *(s32*)(this_ + 4);
                            ((MsgFn)fn_8038BD08)(*(s32*)(this_ + 0x24c), lbl_80465E38[*(s32*)(this_ + 0x234)], room, *(JGeometry::TVec3f*)(this_ + 0xc), 0x21);
                        }
                    } else {
                        s32 player = *(s32*)(this_ + 0x250);
                        if (player == *(s32*)(this_ + 0x24c)) {
                            *(s32*)(this_ + 0x278) = Actor_CreateByID(fn_801F856C(), 0x50454646, *(void**)(this_ + 4), this_ + 0xc, (player & 3) | 0x24, -1, -1);
                            s32 room = *(s32*)(this_ + 4);
                            ((MsgFn)fn_8038BD08)(*(s32*)(this_ + 0x24c), 0x284, room, *(JGeometry::TVec3f*)(this_ + 0xc), 0x21);
                        }
                    }
                } else if (id < 0x10) {
                    s32 player = *(s32*)(this_ + 0x250);
                    if (player == *(s32*)(this_ + 0x24c)) {
                        *(s32*)(this_ + 0x278) = Actor_CreateByID(fn_801F856C(), 0x50454646, *(void**)(this_ + 4), this_ + 0xc, (player & 3) | 0x24, -1, -1);
                        s32 room = *(s32*)(this_ + 4);
                        ((MsgFn)fn_8038BD08)(*(s32*)(this_ + 0x24c), lbl_80465E38[*(s32*)(this_ + 0x234)], room, *(JGeometry::TVec3f*)(this_ + 0xc), 1);
                    }
                } else {
                    s32 player = *(s32*)(this_ + 0x250);
                    if (player == *(s32*)(this_ + 0x24c)) {
                        *(s32*)(this_ + 0x278) = Actor_CreateByID(fn_801F856C(), 0x50454646, *(void**)(this_ + 4), this_ + 0xc, (player & 3) | 0x24, -1, -1);
                        s32 room = *(s32*)(this_ + 4);
                        ((MsgFn)fn_8038BD08)(*(s32*)(this_ + 0x24c), lbl_80465E38[*(s32*)(this_ + 0x234)], room, *(JGeometry::TVec3f*)(this_ + 0xc), 0x21);
                    }
                }
                if (*(s32*)(this_ + 0x250) == *(s32*)(this_ + 0x24c)) {
                    fn_801597EC(this_);
                }
            } else {
                fn_801597EC(this_);
            }
            *(s32*)(this_ + 0x230) = 1;
        } else {
            if (*(s32*)(this_ + 0x240) == 1 && *(s32*)(this_ + 0x234) == 0x2e) {
                fn_80230EB8(*(s32*)(this_ + 0x250), 0x3e);
            }
            *(s32*)(this_ + 0x28c) = *(s32*)(this_ + 0x28c) - 1;
            if (*(s32*)(this_ + 0x28c) == 0) {
                *(s32*)(this_ + 0x28c) = 1;
                if (*(s32*)(this_ + 0x26c) != 0) {
                    s32 h = *(s32*)(this_ + 0x260);
                    if (h != 0) {
                        void* o = fn_801F666C(fn_801F856C(), h);
                        if (o != NULL) {
                            fn_802ED140(o);
                        }
                    }
                }
                s32 id = *(s32*)(this_ + 0x234);
                if (id != 0x2f) {
                    if (id == 0x14) {
                        if (*(s32*)(this_ + 0x288) == 0) {
                            *(f32*)(this_ + 0xc) = lbl_8053D468 + *(f32*)(this_ + 0x27c);
                            *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x280) - lbl_8053D46C;
                            *(f32*)(this_ + 0x14) = *(f32*)(this_ + 0x284);
                            *(s32*)(this_ + 0x28c) = 4;
                            fn_80236804(fn_8022F340(*(void**)(this_ + 0x274)), 4);
                            fn_80230F44(*(s32*)(this_ + 0x24c), 0x1000002);
                        } else if (*(s32*)(this_ + 0x288) == 1) {
                            *(f32*)(this_ + 0xc) = lbl_8053D470 + *(f32*)(this_ + 0x27c);
                            *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x280) - lbl_8053D474;
                            *(f32*)(this_ + 0x14) = *(f32*)(this_ + 0x284);
                            *(void**)(this_ + 0x2b0) = fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, lbl_8053D478, 0x562, 0, 1, 0, 0, 1);
                            *(void**)(this_ + 0x2a8) = fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, lbl_8053D47C, 0x563, 0, 1, 0, 0, 1);
                        }
                        if (*(s32*)(this_ + 0x234) != 0x2f && *(s32*)(this_ + 0x288) < 4) {
                            *(s32*)(this_ + 0x288) = *(s32*)(this_ + 0x288) + 1;
                        }
                        if (*(s32*)(this_ + 0x288) < 4) {
                            *(s32*)(this_ + 0x288) = *(s32*)(this_ + 0x288) + 1;
                        }
                        s32 n = *(s32*)(this_ + 0x288);
                        if (n >= 4) n = 3;
                        fn_80230498(*(s32*)(this_ + 0x250), this_ + 0x27c, n + 0xe9, 0xff, -0x80, -0x80, 1);
                    } else if (id == 0x2e) {
                        if (*(s32*)(this_ + 0x288) == 0) {
                            *(f32*)(this_ + 0x14) = lbl_8053D480 + *(f32*)(this_ + 0x284);
                            *(s32*)(this_ + 0x28c) = 4;
                        } else if (*(s32*)(this_ + 0x288) == 1) {
                            *(f32*)(this_ + 0x14) = lbl_8053D484 + *(f32*)(this_ + 0x284);
                            *(s32*)(this_ + 0x28c) = 4;
                        } else if (*(s32*)(this_ + 0x288) == 2) {
                            *(f32*)(this_ + 0x14) = lbl_8053D488 + *(f32*)(this_ + 0x284);
                        }
                        char* o = (char*)fn_801F666C(fn_801F856C(), *(s32*)(this_ + 0x290));
                        if (o != NULL) {
                            *(JGeometry::TVec3f*)(o + 0xc) = JGeometry::TVec3f(*(JGeometry::TVec3f*)(this_ + 0xc));
                        }
                        if (*(s32*)(this_ + 0x288) < 4) {
                            *(s32*)(this_ + 0x288) = *(s32*)(this_ + 0x288) + 1;
                        }
                        s32 n = *(s32*)(this_ + 0x288);
                        if (n >= 4) n = 3;
                        if (fn_80233E40(*(s32*)(this_ + 0x250))) {
                            fn_80230498(*(s32*)(this_ + 0x250), this_ + 0x27c, n + 0x336, 0xff, -0x80, -0x80, 1);
                        } else {
                            fn_80230498(*(s32*)(this_ + 0x250), this_ + 0x27c, n + 0xed, 0xff, -0x80, -0x80, 1);
                        }
                    } else if (id <= 0xb) {
                        if (*(s32*)(this_ + 0x288) == 0) {
                            *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x280) - lbl_8053D48C;
                            if (*(s32*)(this_ + 0x270) != 0 && lbl_8053AAF8[0x7e] == 1) {
                                *(s32*)(this_ + 0x28c) = 4;
                            }
                        } else if (*(s32*)(this_ + 0x288) == 1) {
                            *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x280) - lbl_8053D490;
                            if (*(s32*)(this_ + 0x270) != 0 && lbl_8053AAF8[0x7e] == 1) {
                                *(s32*)(this_ + 0x28c) = 4;
                            }
                            if (*(s32*)(this_ + 0x25c) == 0) {
                                fn_80230FD0(*(s32*)(this_ + 0x250), 0x10008);
                            }
                        } else if (*(s32*)(this_ + 0x288) == 2) {
                            if (*(s32*)(this_ + 0x270) != 0 && lbl_8053AAF8[0x7e] == 1) {
                                *(s32*)(this_ + 0x28c) = 0x32;
                            }
                            *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x280) - lbl_8053D494;
                            if (*(s32*)(this_ + 0x234) >= 8) {
                                *(void**)(this_ + 0x2b0) = ((SpawnFn)fn_8013CC50)(*(s32*)(this_ + 4), JGeometry::TVec3f(*(f32*)(this_ + 0xc), *(f32*)(this_ + 0x10) - lbl_8053D498, *(f32*)(this_ + 0x14)), lbl_8053D49C, 0x562, 0, 1, 0, 0, 1);
                                *(void**)(this_ + 0x2a8) = ((SpawnFn)fn_8013CC50)(*(s32*)(this_ + 4), JGeometry::TVec3f(*(f32*)(this_ + 0xc), *(f32*)(this_ + 0x10) - lbl_8053D470, *(f32*)(this_ + 0x14)), lbl_8053D4A0, 0x563, 0, 1, 0, 0, 1);
                                if (*(s32*)(this_ + 0x25c) == 0) {
                                    JGeometry::TVec3f c(*(JGeometry::TVec3f*)(this_ + 0xc));
                                    c.y -= lbl_8053D4A4;
                                    fn_801F6718(fn_801F856C(), *(void**)(this_ + 0x274), *(s32*)(this_ + 4), &c, *(s32*)(this_ + 0x234), 2);
                                }
                            } else {
                                *(void**)(this_ + 0x2b0) = ((SpawnFn)fn_8013CC50)(*(s32*)(this_ + 4), JGeometry::TVec3f(*(f32*)(this_ + 0xc), *(f32*)(this_ + 0x10) - lbl_8053D470, *(f32*)(this_ + 0x14)), lbl_8053D478, 0x562, 0, 1, 0, 0, 1);
                                *(void**)(this_ + 0x2a8) = fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, lbl_8053D47C, 0x563, 0, 1, 0, 0, 1);
                                if (*(s32*)(this_ + 0x25c) == 0) {
                                    JGeometry::TVec3f c(*(JGeometry::TVec3f*)(this_ + 0xc));
                                    c.y -= lbl_8053D46C;
                                    fn_801F6718(fn_801F856C(), *(void**)(this_ + 0x274), *(s32*)(this_ + 4), &c, *(s32*)(this_ + 0x234), 2);
                                }
                            }
                        }
                        if (*(s32*)(this_ + 0x288) < 3) {
                            *(s32*)(this_ + 0x288) = *(s32*)(this_ + 0x288) + 1;
                        }
                        if (*(s32*)(this_ + 0x25c) == 0) {
                            s32 n = *(s32*)(this_ + 0x288);
                            if (n >= 4) n = 3;
                            if (fn_80233E40(*(s32*)(this_ + 0x250))) {
                                fn_80230498(*(s32*)(this_ + 0x250), this_ + 0x27c, n + 0x336, 0xff, -0x80, -0x80, 1);
                            } else {
                                fn_80230498(*(s32*)(this_ + 0x250), this_ + 0x27c, n + 0xed, 0xff, -0x80, -0x80, 1);
                            }
                        }
                    } else if ((u32)(id - 0x10) <= 2 || (u32)(id - 0x16) <= 3 || id == 0x25) {
                        if (*(s32*)(this_ + 0x288) == 0) {
                            *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x280) - lbl_8053D46C;
                            *(f32*)(this_ + 0x14) = *(f32*)(this_ + 0x284);
                            *(s32*)(this_ + 0x28c) = 4;
                            fn_80230F44(*(s32*)(this_ + 0x24c), 0x1000002);
                        } else if (*(s32*)(this_ + 0x288) == 1) {
                            *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x280) - lbl_8053D474;
                            *(f32*)(this_ + 0x14) = *(f32*)(this_ + 0x284);
                            *(void**)(this_ + 0x2b0) = fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, lbl_8053D4A8, 0x562, 0, 1, 0, 0, 1);
                            *(void**)(this_ + 0x2a8) = fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, lbl_8053D47C, 0x563, 0, 1, 0, 0, 1);
                        }
                        if (*(s32*)(this_ + 0x288) < 4) {
                            *(s32*)(this_ + 0x288) = *(s32*)(this_ + 0x288) + 1;
                        }
                        s32 n = *(s32*)(this_ + 0x288);
                        if (n >= 4) n = 3;
                        if (fn_80233E40(*(s32*)(this_ + 0x250))) {
                            fn_80230498(*(s32*)(this_ + 0x250), this_ + 0x27c, n + 0x336, 0xff, -0x80, -0x80, 1);
                        } else {
                            fn_80230498(*(s32*)(this_ + 0x250), this_ + 0x27c, n + 0xed, 0xff, -0x80, -0x80, 1);
                        }
                    } else {
                        if (*(s32*)(this_ + 0x288) == 0) {
                            *(f32*)(this_ + 0xc) = lbl_8053D468 + *(f32*)(this_ + 0x27c);
                            *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x280) - lbl_8053D46C;
                            *(f32*)(this_ + 0x14) = *(f32*)(this_ + 0x284);
                            fn_80230F44(*(s32*)(this_ + 0x24c), 0x1000002);
                            *(s32*)(this_ + 0x28c) = 4;
                        } else if (*(s32*)(this_ + 0x288) == 1) {
                            *(f32*)(this_ + 0xc) = lbl_8053D470 + *(f32*)(this_ + 0x27c);
                            *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x280) - lbl_8053D474;
                            *(f32*)(this_ + 0x14) = *(f32*)(this_ + 0x284);
                            *(void**)(this_ + 0x2b0) = fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, lbl_8053D4A8, 0x562, 0, 1, 0, 0, 1);
                            *(void**)(this_ + 0x2a8) = fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, lbl_8053D47C, 0x563, 0, 1, 0, 0, 1);
                        }
                        if (*(s32*)(this_ + 0x288) < 4) {
                            *(s32*)(this_ + 0x288) = *(s32*)(this_ + 0x288) + 1;
                        }
                        s32 n = *(s32*)(this_ + 0x288);
                        if (n >= 4) n = 3;
                        fn_80230498(*(s32*)(this_ + 0x250), this_ + 0x27c, n + 0xe9, 0xff, -0x80, -0x80, 1);
                    }
                }
            }
        }
        if (*(s32*)(this_ + 0x288) >= 4 && findGbaLink() != NULL) {
            *(s32*)(this_ + 0x288) = 3;
            *(s32*)(this_ + 0x238) = 0;
        }
        break;
    case 1:
        if (*(s32*)(this_ + 0x238) <= 0) {
            if (*(s32*)(this_ + 0x26c) != 0) {
                if (*(s32*)(this_ + 0x25c) != 0 || fn_803865B8(*(s32*)(this_ + 0x250))) {
                    ((FSAVirtBase*)this_)->m7();
                }
                break;
            }
            if (*(s32*)(this_ + 0x234) == 0x2e && *(s32*)(this_ + 4) < 8) {
                if (fn_80388EEC(*(s32*)(this_ + 0x250))) {
                    *(s32*)(this_ + 0x230) = 2;
                    *(s32*)(this_ + 0x238) = 0x14;
                    char* o = (char*)fn_801F666C(fn_801F856C(), *(s32*)(this_ + 0x290));
                    if (o != NULL) {
                        *(s32*)(o + 0x250) = *(s32*)(lbl_8053AF80 + 0x58);
                        *(s32*)(o + 0x230) = 4;
                        *(JGeometry::TVec3f*)(o + 0x3c) = JGeometry::TVec3f(lbl_8053D4AC, lbl_8053D4B0, lbl_8053D4AC);
                    }
                }
                break;
            }
            if (*(s32*)(this_ + 0x258) == 0) {
                if (lbl_8053AAF8[0x7e] == 1) {
                    if (fn_80388EEC(*(s32*)(this_ + 0x24c))) {
                        if (*(s32*)(this_ + 0x268) != 0) {
                            if (fn_8023061C(*(void**)(this_ + 0x274), 0) == 1) {
                                ((FSAVirtBase*)this_)->m7();
                            }
                        } else {
                            if (fn_80230224(*(s32*)(this_ + 0x250), 0) == 1) {
                                ((FSAVirtBase*)this_)->m7();
                            }
                        }
                    }
                } else {
                    if (fn_80388EEC(*(s32*)(this_ + 0x24c))) {
                        if (*(s32*)(this_ + 0x268) != 0) {
                            if (fn_80230534(0) == 1) {
                                ((FSAVirtBase*)this_)->m7();
                            }
                        } else {
                            if (fn_80230224(*(s32*)(this_ + 0x250), 0) == 1) {
                                ((FSAVirtBase*)this_)->m7();
                            }
                        }
                    }
                }
            } else {
                *(s32*)(this_ + 0x230) = 3;
            }
        }
        if (findGbaLink() != NULL) {
            *(s32*)(this_ + 0x238) = 0;
            fn_8037E8D4(*(s32*)(this_ + 0x250));
        }
        break;
    case 2: {
        s32 t = *(s32*)(this_ + 0x238);
        if (t > 0x11) {
            *(s32*)(this_ + 0x288) = 0xe;
        } else if (t > 9) {
            *(s32*)(this_ + 0x288) = 0xd;
        } else if (t > 8) {
            *(s32*)(this_ + 0x288) = 0xc;
        } else {
            *(s32*)(this_ + 0x288) = 0xb;
            if (lbl_8053AAF8[0x7e] == 1) {
                if (fn_80388EEC(*(s32*)(this_ + 0x24c))) {
                    if (*(s32*)(this_ + 0x268) != 0) {
                        if (fn_8023061C(*(void**)(this_ + 0x274), 0) == 1) {
                            ((FSAVirtBase*)this_)->m7();
                            break;
                        }
                    } else {
                        if (fn_80230224(*(s32*)(this_ + 0x250), 0) == 1) {
                            ((FSAVirtBase*)this_)->m7();
                            break;
                        }
                    }
                }
            } else {
                if (fn_80388EEC(*(s32*)(this_ + 0x24c))) {
                    if (*(s32*)(this_ + 0x268) != 0) {
                        if (fn_80230534(0) == 1) {
                            ((FSAVirtBase*)this_)->m7();
                            break;
                        }
                    } else {
                        if (fn_80230224(*(s32*)(this_ + 0x250), 0) == 1) {
                            ((FSAVirtBase*)this_)->m7();
                            break;
                        }
                    }
                }
            }
        }
        fn_80230498(*(s32*)(this_ + 0x250), this_ + 0x27c, *(s32*)(this_ + 0x288) + 0x322, 0xff, -0x80, -0x80, 1);
        break;
    }
    case 3:
        break;
    }
    if (*(s32*)(this_ + 0x234) == 0x20) {
        if (*(s32*)(this_ + 0x23c) <= 0) {
            *(s32*)(this_ + 0x244) ^= 1;
            *(s32*)(this_ + 0x23c) = 10;
        }
    } else if (*(s32*)(this_ + 0x234) <= 0xb) {
        if (*(s32*)(this_ + 0x23c) <= 0) {
            *(s32*)(this_ + 0x244) = *(s32*)(this_ + 0x244) + 1;
            *(s32*)(this_ + 0x244) = *(s32*)(this_ + 0x244) & 3;
            if (*(s32*)(this_ + 0x244) == 0) {
                *(s32*)(this_ + 0x23c) = 0x14;
            } else {
                *(s32*)(this_ + 0x23c) = 2;
            }
        }
    } else {
        if (*(s32*)(this_ + 0x23c) <= 0) {
            *(s32*)(this_ + 0x244) ^= 1;
            *(s32*)(this_ + 0x23c) = 10;
        }
    }
    if (*(s32*)(this_ + 0x238) > 0) {
        *(s32*)(this_ + 0x238) = *(s32*)(this_ + 0x238) - 1;
    }
    if (*(s32*)(this_ + 0x23c) > 0) {
        *(s32*)(this_ + 0x23c) = *(s32*)(this_ + 0x23c) - 1;
    }
    if (*(s32*)(this_ + 0x240) > 0) {
        *(s32*)(this_ + 0x240) = *(s32*)(this_ + 0x240) - 1;
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

#pragma opt_propagation off
extern "C" void fn_8015B49C(char* this_) {
    s32 id;
    f32 zero = 0.0f;
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
    JGeometry::setTVec3f((const f32*)fn_8023E724(*(void**)(this_ + 0x250)), (f32*)(this_ + 0x27c));
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
        }
        if (*(s32*)(this_ + 0x270) != 0) {
            *(s32*)(this_ + 0x28c) = 2;
        }
        break;
    case 0x2e:
    *(f32*)(this_ + 0x14) = lbl_8053D480 + *(f32*)(this_ + 0x284);
    *(s32*)(this_ + 0x290) = Actor_CreateByID(fn_801F856C(), 0x42424d42, *(void**)(this_ + 4), this_ + 0xc, 0x20000, -1, -1);
        break;
    }
    *(s32*)(this_ + 0x230) = 0;
    if (*(s32*)(this_ + 0x258) == 0) {
        if (*(s32*)(this_ + 0x28c) != 2) {
            *(s32*)(this_ + 0x260) = Actor_CreateByID(fn_801F856C(), 0x5354504e, *(void**)(this_ + 4), this_ + 0xc, 0, -1, -1);
            if (lbl_8053AAF8[0x96] == 0) *(s32*)(this_ + 0x260) = 0;
        } else {
            if(lbl_8053AAF8[0x7e] == 0) *(s32*)(this_ + 0x238) = 0x2d;
            else *(s32*)(this_ + 0x28c) = 0xa;
            *(s32*)(this_ + 0x260) = 0;
        }
    } else *(s32*)(this_ + 0x260) = 0;
    *(s32*)(this_ + 0x278) = -1;
    *(s32*)(this_ + 0x294) = -1;
}
#pragma opt_propagation reset
void __sinit_IMUP_801597B8_cpp(void) {}

