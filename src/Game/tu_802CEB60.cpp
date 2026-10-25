#include "types.h"
#include "Game/ItemBase.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"

typedef JGeometry::TVec3<f32> YasiVec;
extern "C" f32 lbl_80540E48;
extern "C" f32 lbl_80540E58;
extern "C" f32 lbl_80540E5C;
extern "C" s32 Actor_CreateByID(void* base, u32 fourCC, u32 owner, void* posPtr, u32 param, s32 p6, s32 p7);
extern "C" u16 fn_8022461C(YasiVec* pos, u32 room);
extern "C" u8 fn_802DE9A0();
extern "C" u8 fn_802DEB58();
extern "C" u8 fn_802DEBF8();
extern "C" s32 fn_801CD664(s32 range);
extern "C" void fn_802CEC10(char* p);
extern "C" BOOL fn_802CF598(char* p);
extern "C" void* fn_801F856C();
void fn_801F0E34(void* a, u32 code, u32 z);
s32 fn_8013CC50(u32 id, void* p, f32 f, u32 a, u32 b, u32 c, u32 d, u32 e, u32 g);

void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void fn_801F132C(void* a, void* b, void* c, void* d);
extern "C" char lbl_804A92D0[];

struct Vt802CEBC0 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
};

extern "C" void* fn_802CEB60(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A92D0;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_802CEBC0(Vt802CEBC0* p) {
    p->m7();
}

extern "C" void fn_802CEBEC(void* this_, void* b, void* c) {
    fn_801F132C(this_, b, c, (char*)this_ + 0x23c);
}

extern "C" void fn_802CEC10(char* p) {
    if (*(s32*)(p + 0x234) == 1) {
        if (*(s32*)(p + 0x230) == 4) {
            if (fn_801CD664(100) < 60) {
                Actor_CreateByID(fn_801F856C(), 0x48415254, *(u32*)(p + 0x4), p + 0xc, 0, -1, -1);
            }
        } else if (*(s32*)(p + 0x238) == 3) {
            f32 y = *(f32*)(p + 0x10);
            YasiVec a;
            a.x = *(f32*)(p + 0xc) + (f32)(fn_801CD664(13) - 6);
            a.y = y;
            a.z = lbl_80540E48;
            Actor_CreateByID(fn_801F856C(), 0x48415254, *(u32*)(p + 0x4), &a, 0, -1, -1);
            y = *(f32*)(p + 0x10);
            YasiVec b;
            b.x = *(f32*)(p + 0xc) + (f32)(fn_801CD664(13) - 6);
            b.y = y;
            b.z = lbl_80540E48;
            Actor_CreateByID(fn_801F856C(), 0x48415254, *(u32*)(p + 0x4), &b, 0, -1, -1);
        } else if (*(s32*)(p + 0x238) == 2) {
            f32 y = *(f32*)(p + 0x10) + (f32)(fn_801CD664(13) - 6);
            YasiVec a;
            a.x = *(f32*)(p + 0xc) + (f32)(fn_801CD664(13) - 6);
            a.y = y;
            a.z = lbl_80540E48;
            Actor_CreateByID(fn_801F856C(), 0x52555059, *(u32*)(p + 0x4), &a, 0x262d01, -1, -1);
        } else {
            f32 y = *(f32*)(p + 0x10) + (f32)(fn_801CD664(13) - 6);
            YasiVec a;
            a.x = *(f32*)(p + 0xc) + (f32)(fn_801CD664(13) - 6);
            a.y = y;
            a.z = lbl_80540E48;
            Actor_CreateByID(fn_801F856C(), 0x52555059, *(u32*)(p + 0x4), &a, 0x262d00, -1, -1);
        }
    } else if (*(s32*)(p + 0x238) != 2 && !fn_802DEBF8()) {
        if (*(s32*)(p + 0x230) >= 1) {
            if (*(s32*)(p + 0x230) == 1) {
                Actor_CreateByID(fn_801F856C(), 0x48415254, *(u32*)(p + 0x4), p + 0xc, 0, -1, -1);
            } else if (*(s32*)(p + 0x230) == 2) {
                Actor_CreateByID(fn_801F856C(), 0x4d54424f, *(u32*)(p + 0x4), p + 0xc, 0, -1, -1);
            } else if (*(s32*)(p + 0x230) == 3) {
                f32 y = *(f32*)(p + 0x10);
                YasiVec a;
                a.x = *(f32*)(p + 0xc) + (f32)(fn_801CD664(13) - 6);
                a.y = y;
                a.z = lbl_80540E48;
                Actor_CreateByID(fn_801F856C(), 0x48415254, *(u32*)(p + 0x4), &a, 0, -1, -1);
                y = *(f32*)(p + 0x10);
                YasiVec b;
                b.x = *(f32*)(p + 0xc) + (f32)(fn_801CD664(13) - 6);
                b.y = y;
                b.z = lbl_80540E48;
                Actor_CreateByID(fn_801F856C(), 0x48415254, *(u32*)(p + 0x4), &b, 0, -1, -1);
            }
        } else {
            s32 r = fn_801CD664(100);
            if (*(s32*)(p + 0x238) == 0) {
                if (r >= 40 && r <= 60) {
                    if (r & 1) {
                        if (*(f32*)(p + 0x14) > lbl_80540E48) {
                            Actor_CreateByID(fn_801F856C(), 0x52555059, *(u32*)(p + 0x4), p + 0xc, 0x260a00, -1, -1);
                        } else {
                            Actor_CreateByID(fn_801F856C(), 0x52555059, *(u32*)(p + 0x4), p + 0xc, 0x260000, -1, -1);
                        }
                    } else {
                        Actor_CreateByID(fn_801F856C(), 0x48415254, *(u32*)(p + 0x4), p + 0xc, 0, -1, -1);
                    }
                }
            } else if (r <= 10) {
                if (r & 1) {
                    Actor_CreateByID(fn_801F856C(), 0x52555059, *(u32*)(p + 0x4), p + 0xc, 0x260000, -1, -1);
                } else {
                    Actor_CreateByID(fn_801F856C(), 0x48415254, *(u32*)(p + 0x4), p + 0xc, 0, -1, -1);
                }
            }
        }
    }
    *(u8*)(p + 0x11c) = 0;
}

extern "C" void fn_802CF130(char* p) {
    if (*(s32*)(p + 0x4) >= 8) {
        YasiVec pos(*(YasiVec*)(p + 0xc));
        pos.z = lbl_80540E48;
        Actor_CreateByID(fn_801F856C(), 0x4b4d5249, *(u32*)(p + 0x4), &pos, 4, -1, -1);
        if (*(s32*)(p + 0x238) == 0) {
            fn_801F0E34(p, 0x30006, 0);
        } else if (*(s32*)(p + 0x238) == 1) {
            fn_801F0E34(p, 0x5002f, 0);
        }
    } else if (*(s32*)(p + 0x238) == 0) {
        if (fn_8022461C((YasiVec*)(p + 0xc), *(u32*)(p + 0x4)) == 0xd || fn_8022461C((YasiVec*)(p + 0xc), *(u32*)(p + 0x4)) == 0x39) {
            fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_80540E58, 0x3d0, 0, 1, 0, 0, 1);
            fn_801F0E34(p, 0x30022, 0);
        } else if (fn_8022461C((YasiVec*)(p + 0xc), *(u32*)(p + 0x4)) == 0xe) {
            if (fn_802DE9A0()) {
                fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_80540E58, 0x2a9, -1, 1, 0, 0, 1);
                fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_80540E58, 0x2aa, 0, 0, 0, 0, 1);
                fn_801F0E34(p, 0x5005f, 0);
            } else if (fn_802DEB58()) {
                fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_80540E58, 0x45e, -1, 1, 0, 0, 1);
                fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_80540E58, 0x45f, 0, 0, 0, 0, 1);
                fn_801F0E34(p, 0x5003f, 0);
            }
        } else {
            fn_802CF598(p);
            fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_80540E5C, 0x357, 0, 0, 0, 0, 1);
            fn_801F0E34(p, 0x30006, 0);
            *(s32*)(p + 0x234) = 2;
            fn_802CEC10(p);
        }
    } else if (*(s32*)(p + 0x238) == 1) {
        fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_80540E5C, 0x358, 0, 0, 0, 0, 1);
        fn_801F0E34(p, 0x5002f, 0);
        fn_802CEC10(p);
    }
    *(u8*)(p + 0x11c) = 0;
}

extern "C" void fn_801F02BC(void* a, u8* p2, s32 p3, DrawRec* p4, s32 p5, s32 p6, u8 p7, f32 f6, f32 f7);
extern "C" s32 fn_8023CB24(s32 a);
extern "C" s32 fn_8023CA88(s32 a);
extern "C" u8 lbl_8046DFB8[];
extern "C" f32 lbl_80540E58;
extern "C" void fn_802CF408(char* p) {
    if (*(s32*)(p + 0x238) != 2) {
        s32 n = 7;
        DrawRec rec;
        ((u8*)&rec.w10)[3] = *(u8*)(p + 0x244);
        if (*(u8*)(p + 0xc4) != 0) {
            rec.b20 = 0;
            n = -1;
            rec.b1d = fn_8023CB24(*(s32*)(p + 0xc8)) + 1;
            rec.b1c = fn_8023CA88(*(s32*)(p + 0xc8));
        }
        fn_801F02BC(p, lbl_8046DFB8, 0x27, &rec, n, 0, 1, lbl_80540E58, lbl_80540E58);
    }
}

extern "C" void* fn_802D6A9C();
extern "C" void* fn_801F856C();
extern "C" void* fn_801F666C(void* mgr, s32 idx);
extern "C" s32 fn_801F78F4(void* mgr, u32 code, s32 idx);
void fn_801F0E34(void* a, u32 code, u32 z);
s32 fn_8013CC50(u32 id, void* p, f32 f, u32 a, u32 b, u32 c, u32 d, u32 e, u32 g);
extern f32 lbl_80540E58;
extern "C" BOOL fn_802CF598(char* p) {
    f32 x0 = *(f32*)(p + 0x60);
    f32 y0 = *(f32*)(p + 0x64);
    f32 x1 = *(f32*)(p + 0x68);
    f32 y1 = *(f32*)(p + 0x6c);
    x0 += *(f32*)(p + 0xc);
    y0 += *(f32*)(p + 0x10);
    x1 += *(f32*)(p + 0xc);
    y1 += *(f32*)(p + 0x10);
    s32 room = *(s32*)(p + 0x4);
    s32 id;
    s32 prev = -1;
    char* base;
    f32* o;
    char* obj;
    f32 ox0;
    f32 oy0;
    f32 ox1;
    f32 oy1;

    base = (char*)fn_802D6A9C();
    if (room < 8) {
        o = (f32*)(base + 0xcc);
    } else {
        o = (f32*)(base + 0xdc);
    }
    f32 dx = -o[0];
    f32 dy = -o[1];
    x0 += dx;
    y0 += dy;
    x1 += dx;
    y1 += dy;
    for (;;) {
        id = fn_801F78F4(fn_801F856C(), 0x424c5a32, prev);
        prev = id;
        if (id < 0) {
            return 0;
        }
        if (id == *(s32*)(p + 0x198)) {
            continue;
        }
        obj = (char*)fn_801F666C(fn_801F856C(), id);
        if (obj == NULL) {
            continue;
        }
        ox0 = *(f32*)(obj + 0x60);
        ox0 += *(f32*)(obj + 0xc);
        oy0 = *(f32*)(obj + 0x64);
        oy0 += *(f32*)(obj + 0x10);
        ox1 = *(f32*)(obj + 0x68);
        ox1 += *(f32*)(obj + 0xc);
        oy1 = *(f32*)(obj + 0x6c);
        oy1 += *(f32*)(obj + 0x10);
        room = *(s32*)(obj + 0x4);
        base = (char*)fn_802D6A9C();
        if (room < 8) {
            o = (f32*)(base + 0xcc);
        } else {
            o = (f32*)(base + 0xdc);
        }
        dx = -o[0];
        dy = -o[1];
        ox0 += dx;
        oy0 += dy;
        ox1 += dx;
        oy1 += dy;
        if (ox0 <= x0) {
            ox0 = x0;
        }
        if (oy0 <= y0) {
            oy0 = y0;
        }
        if (ox1 >= x1) {
            ox1 = x1;
        }
        if (oy1 >= y1) {
            oy1 = y1;
        }
        bool hit = 0;
        if (ox1 >= ox0 && oy1 >= oy0) {
            hit = 1;
        }
        if (hit) {
            fn_801F0E34(p, 0x3002f, 0);
            fn_8013CC50(*(s32*)(p + 0x4), p + 0xc, lbl_80540E58, 0x1a2, 1, 0, 0, 0, 1);
            return 1;
        }
    }
}

extern "C" YasiVec* fn_8023E7B0(s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" u8 fn_8023BCD4(s32);
extern "C" u8 fn_801F2618(void*, s32, s32);
extern "C" u8 fn_801F2B7C(void*, s32, s32, s32);
extern "C" u8 fn_801F2B20(void*, s32);
extern "C" s32 fn_80226AE0(void*, s32);
extern "C" void fn_802D7310(void*, s32, u8);
extern "C" f32 lbl_80540E60;
extern "C" f32 lbl_80540E64;
extern char* lbl_8053AAF8;
extern "C" void fn_802CF814(char* p) {
    if (*(s32*)(p + 0x238) != 2) {
        *(u8*)(p + 0x244) = 0xff;
        if (*(u8*)(p + 0xc4) != 0) {
            YasiVec* h = fn_8023E7B0(*(s32*)(p + 0xc8));
            YasiVec* pos = (YasiVec*)(p + 0xc);
            pos->x = h->x;
            pos->y = h->y;
            pos->z = h->z;
            *(s32*)(p + 4) = fn_8023DE58(*(s32*)(p + 0xc8));
            *(u8*)(p + 0x244) = fn_8023BCD4(*(s32*)(p + 0xc8));
        } else {
            s32 room = *(s32*)(p + 4);
            char* base = (char*)((u32)fn_802D6A9C() + 0x10000) + room;
            if (*(u8*)(base + 0x31df) == 0) {
                *(f32*)(p + 0x44) += lbl_80540E60;
                *(YasiVec*)(p + 0xc) += *(YasiVec*)(p + 0x3c);
                s32 hit = *(s32*)(p + 0x114);
                if (*(u8*)(lbl_8053AAF8 + 0x7f)) hit = 0;
                if (*(f32*)(p + 0x14) < lbl_80540E48 || fn_801F2618(p, 0, 0)) {
                    ((Vt802CEBC0*)p)->m7();
                } else if (fn_801F2B7C(p, hit, *(s32*)(p + 0xc8), 1) || fn_801F2B20(p, 0)) {
                    ((Vt802CEBC0*)p)->m7();
                }
            } else {
                if (*(u8*)(p + 0x245) == 0) {
                    *(f32*)(p + 0x10) -= *(f32*)(p + 0x14);
                    *(f32*)(p + 0x14) = 0.0f;
                    *(f32*)(p + 0x44) = 0.0f;
                    *(u8*)(p + 0x245) = 1;
                }
                *(f32*)(p + 0x40) += lbl_80540E64;
                *(YasiVec*)(p + 0xc) += *(YasiVec*)(p + 0x3c);
                s32 hit = *(s32*)(p + 0x114);
                if (*(u8*)(lbl_8053AAF8 + 0x7f)) hit = 0;
                if (fn_801F2618(p, 0, 0)) {
                    ((Vt802CEBC0*)p)->m7();
                } else if (fn_801F2B7C(p, hit, *(s32*)(p + 0xc8), 1) || fn_801F2B20(p, 0)) {
                    ((Vt802CEBC0*)p)->m7();
                }
            }
        }
    } else {
        --*(s32*)(p + 0x240);
        if (*(s32*)(p + 0x240) == 0) {
            s32 bit = fn_80226AE0(p + 0xc, *(s32*)(p + 4));
            fn_802D7310(fn_802D6A9C(), bit, 0);
            *(u8*)(p + 0x11c) = 0;
        }
    }
}

extern "C" s32 fn_8013CC50(s32 a, char* b, f32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i);
extern "C" void fn_802CFABC(char* p) {
    *(s32*)(p + 0x230) = *(s32*)(p + 0x90) & 0xf;
    *(s32*)(p + 0x234) = (*(s32*)(p + 0x90) >> 0x10) & 0xf;
    *(s32*)(p + 0x238) = (*(s32*)(p + 0x90) >> 0x14) & 0xf;
    *(u8*)(p + 0x244) = 0xff;
    *(f32*)(p + 0x60) = -4.0f;
    *(f32*)(p + 0x64) = -4.0f;
    *(f32*)(p + 0x68) = 4.0f;
    *(f32*)(p + 0x6c) = 4.0f;
    *(f32*)(p + 0x80) = -4.0f;
    *(f32*)(p + 0x84) = -4.0f;
    *(f32*)(p + 0x88) = 4.0f;
    *(f32*)(p + 0x8c) = 4.0f;
    *(s32*)(p + 0x23c) = 0;
    *(u8*)(p + 0x245) = 0;
    if (*(s32*)(p + 0x238) == 2) {
        fn_8013CC50(*(s32*)(p + 4), p + 0xc, 1.0f, 0x3d1, 0, 0, 0, 0, 1);
        fn_8013CC50(*(s32*)(p + 4), p + 0xc, 1.0f, 0x3d2, 0, 0, 0, 0, 1);
        *(s32*)(p + 0x240) = 0x1e;
    }
}

void fn_802CFBA8(void) {}

