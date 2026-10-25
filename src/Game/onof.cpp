// TU 0x802cb1c4-0x802cc1c4 (actor ONOF).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"
#include "Game/Actor.h"

struct OnofVec2 {
    f32 x, y;
    OnofVec2() {}
    OnofVec2(f32 x_, f32 y_) { set(x_, y_); }
    void set(f32 x_, f32 y_) {
        x = x_;
        y = y_;
    }
    void set(const OnofVec2& o) {
        x = o.x;
        y = o.y;
    }
    void add(const OnofVec2& o) {
        x += o.x;
        y += o.y;
    }
};

struct OnofBox2 {
    OnofVec2 i, f;
    OnofBox2() {}
    OnofBox2(const OnofBox2& o) {
        i.set(o.i);
        f.set(o.f);
    }
    void set(f32 x0, f32 y0, f32 x1, f32 y1) {
        i.set(x0, y0);
        f.set(x1, y1);
    }
    void addPos(const OnofVec2& p) {
        i.add(p);
        f.add(p);
    }
};

extern const f32 lbl_80540DA8;
extern const f32 lbl_80540DAC;
extern const f32 lbl_80540DB0;
extern const f32 lbl_80540DB4;
extern const f32 lbl_80540DB8;
extern const f32 lbl_80540DBC;
extern f32 lbl_80540DC0;
extern f32 lbl_80540DC4;
extern f32 lbl_80540DC8;
extern char* lbl_8053AB10;
extern void* lbl_8053AC98;
extern void* lbl_8053AAF8;
extern u32 lbl_8046D8F8[];

extern "C" void* fn_801F856C(void);
extern "C" void* fn_802D6A9C(void);
extern "C" bool fn_802D800C(void* mgr, s32 id);
extern "C" bool fn_802D7888(void* mgr, s32 bit);
extern "C" void fn_802D78B4(void* mgr, s32 bit, u8 set);
extern "C" void fn_802A3948(void* g, void* pos, s32 a, s32 kind, s32 b);
extern "C" void fn_802A3884(void* g, void* pos, s32 a, s32 kind, s32 b);
extern "C" s32 fn_8013CC50(s32 kind, void* pos, f32 f, s32 a, s32 b, s32 c, s32 d, s32 e, s32 g);
extern "C" u8 fn_80138A30(void* game);
extern "C" s32 fn_8023AE34(void* box, s32 room, void* pos);
extern "C" s32 fn_8023BA68(void* box, s32 room, void* pos, s32 a);
extern "C" s32 fn_8023A6CC(void* box, s32 room);
extern "C" s32 fn_801F8108(void* actor, u32 type, s32 handle, f32 radius);
extern "C" s32 fn_801F2718(void* actor, u32 type);
extern "C" u8* fn_801F666C(void* mgr, s32 id);
extern "C" void fn_801BEDBC(void* actor);
extern "C" void fn_801F0E34(void* actor, u32 a, s32 b);

// fn_802CB1C4 - ONOF: draw a shadow/marker while in state 1 or 2.
// NONMATCHING (79.8%): retail shares the zero register (r7) between the
// colour bytes and the flag argument.
struct OnofColor {
    u8 r, g, b, a;
    OnofColor(u8 r_, u8 g_, u8 b_, u8 a_) { r = r_; g = g_; b = b_; a = a_; }
};
struct OnofShadowMgr {
    void draw(u32 room, void* pos, OnofColor color, s32 flag, f32 scale);
};
extern "C" void fn_80158B5C(void* mgr, u32 room, void* pos, OnofColor color, int flag, f32 scale);
#pragma peephole off
extern "C" void fn_802CB1C4(char* p) {
    s32 st = *(s32*)(p + 0x238);
    if (st == 2 || st == 1) {
        u32 room = *(u32*)(p + 4);
        char* pos = p + 0xc;
        OnofColor c(0, 0, 0, 0x80);
        fn_80158B5C(*(void**)(lbl_8053AB10 + 0x2c), room, pos, c, 0, lbl_80540DA8);
    }
}
#pragma peephole reset
extern "C" void fn_802CB230(void* this_) {
    s32 r31;
    s32 ae;
    s32 r26;
    s32 r27;
    s32 r30;
    u8* p = (u8*)this_;
    s32 r28;

    OnofVec2 pos(*(f32*)(p + 0xc), *(f32*)(p + 0x10));
    OnofBox2* hb = (OnofBox2*)(p + 0x60);
    hb->set(lbl_80540DAC, lbl_80540DAC, lbl_80540DB0, lbl_80540DB0);
    OnofBox2 box(*hb);
    box.addPos(pos);
    ae = fn_8023AE34(&box, *(s32*)(p + 4), &pos);
    hb->set(lbl_80540DB4, lbl_80540DB4, lbl_80540DB8, lbl_80540DB8);
    box.i.x = *(f32*)(p + 0x60);
    box.i.y = *(f32*)(p + 0x64);
    box.f.x = *(f32*)(p + 0x68);
    box.f.y = *(f32*)(p + 0x6c);
    box.addPos(pos);
    r31 = fn_8023BA68(&box, *(s32*)(p + 4), &pos, 1);
    if (r31 < 0) {
        r31 = ae;
    }
    r27 = fn_8023A6CC(&box, *(s32*)(p + 4));
    r30 = fn_801F8108(p, 0x4c4e424d, -1, lbl_80540DBC);
    r28 = fn_801F8108(p, 0x5455424f, -1, lbl_80540DBC);
    r26 = fn_801F2718(p, 0x48424d42);
    *(s32*)(p + 0xd8) = 0;
    switch (*(s32*)(p + 0x238)) {
    case 0:
        if (*(s32*)(p + 0x254) == 0 && (r31 >= 0 || r27 >= 0 || r30 >= 0 || r28 >= 0 || r26 >= 0)) {
            if (r30 >= 0) {
                u8* a = fn_801F666C(fn_801F856C(), r30);
                if (a != 0 && *(u32*)(a + 0x1a0) == 0x4c4e424d) {
                    fn_801BEDBC(fn_801F666C(fn_801F856C(), r30));
                }
            } else if (r26 >= 0) {
                u8* a = fn_801F666C(fn_801F856C(), r26);
                if (a != 0 && *(u16*)(a + 0x94) == 0) {
                    return;
                }
            }
            if (*(s32*)(p + 0x240) == 3 || *(s32*)(p + 0x240) == 4) {
                fn_802D78B4(fn_802D6A9C(), *(s32*)(p + 0x244), 1);
            }
            fn_802A3948(lbl_8053AC98, p + 0xc, 0, *(s32*)(p + 4), 0xbe);
            ((Actor*)p)->v10(0xff, 1);
            fn_8013CC50(*(s32*)(p + 4), p + 0xc, lbl_80540DC0, 0x42b, 1, 0, 0, 0, 1);
            if (*(u32*)(p + 0x230) == 0) {
                *(s32*)(p + 0x230) = fn_8013CC50(*(s32*)(p + 4), p + 0xc, lbl_80540DC0, 0x428, 1, 0, 0, 0, 1);
            }
            if (*(u32*)(p + 0x234) == 0) {
                *(s32*)(p + 0x234) = fn_8013CC50(*(s32*)(p + 4), p + 0xc, lbl_80540DC0, 0x429, 1, 0, 0, 0, 1);
            }
            if (*(s32*)(p + 0x240) == 1 || *(s32*)(p + 0x240) == 3) {
                *(s32*)(p + 0x238) = 2;
                *(s32*)(p + 0x23c) = 0x19;
            } else if (*(s32*)(p + 0x240) == 2) {
                *(s32*)(p + 0x238) = 1;
                *(s32*)(p + 0x23c) = *(s32*)(p + 0x24c);
            } else {
                *(s32*)(p + 0x238) = 4;
            }
            fn_801F0E34(p, 0x30009, 0);
            *(s32*)(p + 0x254) = 1;
        } else {
            if (*(s32*)(p + 0x240) == 3 && fn_802D7888(fn_802D6A9C(), *(s32*)(p + 0x244)) == 1) {
                fn_802A3948(lbl_8053AC98, p + 0xc, 0, *(s32*)(p + 4), 0xbe);
                ((Actor*)p)->v10(0xff, 1);
                if (*(u32*)(p + 0x230) == 0) {
                    *(s32*)(p + 0x230) = fn_8013CC50(*(s32*)(p + 4), p + 0xc, lbl_80540DC0, 0x428, 1, 0, 0, 0, 1);
                }
                if (*(u32*)(p + 0x234) == 0) {
                    *(s32*)(p + 0x234) = fn_8013CC50(*(s32*)(p + 4), p + 0xc, lbl_80540DC0, 0x429, 1, 0, 0, 0, 1);
                }
                *(s32*)(p + 0x238) = 2;
                *(s32*)(p + 0x23c) = 0x19;
                *(s32*)(p + 0x254) = 1;
                return;
            }
            if (r31 < 0 && r27 < 0 && r30 < 0 && r28 < 0 && r26 < 0) {
                *(s32*)(p + 0x254) = 0;
            }
        }
        break;
    case 2:
        if (*(s32*)(p + 0x23c) == 0 && *(s32*)(p + 0x254) == 0) {
            if (r31 >= 0 || r27 >= 0 || r30 >= 0 || r28 >= 0 || r26 >= 0) {
                *(s32*)(p + 0x254) = 1;
                if (r30 >= 0) {
                    u8* a = fn_801F666C(fn_801F856C(), r30);
                    if (a != 0 && *(u32*)(a + 0x1a0) == 0x4c4e424d) {
                        fn_801BEDBC(fn_801F666C(fn_801F856C(), r30));
                    }
                } else if (r26 >= 0) {
                    u8* a = fn_801F666C(fn_801F856C(), r26);
                    if (a != 0 && *(u16*)(a + 0x94) == 0) {
                        return;
                    }
                }
                if (*(s32*)(p + 0x240) == 3) {
                    fn_802D78B4(fn_802D6A9C(), *(s32*)(p + 0x244), 0);
                }
                fn_802A3884(lbl_8053AC98, p + 0xc, 0, *(s32*)(p + 4), 0xbf);
                ((Actor*)p)->v10(0xff, 0);
                *(s32*)(p + 0x238) = 3;
                *(s32*)(p + 0x23c) = 0x19;
                fn_801F0E34(p, 0x30009, 0);
                u8* e0 = *(u8**)(p + 0x230);
                if (e0 != 0) {
                    *(u32*)(e0 + 0xf4) |= 1;
                    *(u32*)(e0 + 0x24) = 1;
                    *(u32*)(p + 0x230) = 0;
                }
                u8* e1 = *(u8**)(p + 0x234);
                if (e1 != 0) {
                    *(u32*)(e1 + 0xf4) |= 1;
                    *(u32*)(e1 + 0x24) = 1;
                    *(u32*)(p + 0x234) = 0;
                }
            } else {
                if (*(s32*)(p + 0x240) == 3 && fn_802D7888(fn_802D6A9C(), *(s32*)(p + 0x244)) == 0) {
                    fn_802A3884(lbl_8053AC98, p + 0xc, 0, *(s32*)(p + 4), 0xbf);
                    ((Actor*)p)->v10(0xff, 0);
                    *(s32*)(p + 0x238) = 3;
                    *(s32*)(p + 0x23c) = 0x19;
                    u8* e0 = *(u8**)(p + 0x230);
                    if (e0 != 0) {
                        *(u32*)(e0 + 0xf4) |= 1;
                        *(u32*)(e0 + 0x24) = 1;
                        *(u32*)(p + 0x230) = 0;
                    }
                    u8* e1 = *(u8**)(p + 0x234);
                    if (e1 != 0) {
                        *(u32*)(e1 + 0xf4) |= 1;
                        *(u32*)(e1 + 0x24) = 1;
                        *(u32*)(p + 0x234) = 0;
                    }
                }
            }
        } else {
            if (*(s32*)(p + 0x23c) != 0) {
                *(s32*)(p + 0x23c) -= 1;
            }
            if (r31 < 0 && r27 < 0 && r30 < 0 && r28 < 0 && r26 < 0) {
                *(s32*)(p + 0x254) = 0;
            }
        }
        break;
    case 1:
        if (*(s32*)(p + 0x23c) == 0) {
            *(s32*)(p + 0x254) = 0;
            if (*(s32*)(p + 0x240) == 3) {
                fn_802D78B4(fn_802D6A9C(), *(s32*)(p + 0x244), 0);
            }
            fn_802A3884(lbl_8053AC98, p + 0xc, 0, *(s32*)(p + 4), 0xbf);
            ((Actor*)p)->v10(0xff, 0);
            *(s32*)(p + 0x238) = 3;
            fn_801F0E34(p, 0x30009, 0);
            *(s32*)(p + 0x23c) = 0x19;
            u8* e0 = *(u8**)(p + 0x230);
            if (e0 != 0) {
                *(u32*)(e0 + 0xf4) |= 1;
                *(u32*)(e0 + 0x24) = 1;
                *(u32*)(p + 0x230) = 0;
            }
            u8* e1 = *(u8**)(p + 0x234);
            if (e1 != 0) {
                *(u32*)(e1 + 0xf4) |= 1;
                *(u32*)(e1 + 0x24) = 1;
                *(u32*)(p + 0x234) = 0;
            }
        } else {
            *(s32*)(p + 0x23c) -= 1;
        }
        break;
    case 3:
        if (*(s32*)(p + 0x23c) == 0) {
            *(s32*)(p + 0x238) = 0;
        } else {
            *(s32*)(p + 0x23c) -= 1;
        }
        break;
    case 4:
        break;
    }
}

// ---- fn_802CBA78_dtor.cpp ----
extern "C" void* fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804A8FC8[];

extern "C" void* fn_802CBA78(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A8FC8;
        if (*(void**)(p + 0x230) != 0) {
            fn_801EE434(*(void**)(p + 0x230));
        }
        if (*(void**)(p + 0x234) != 0) {
            fn_801EE434(*(void**)(p + 0x234));
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" void* fn_801F856C(void);
extern "C" void* fn_802D6A9C(void);
extern "C" bool fn_802D800C(void* mgr, s32 id);
extern "C" void fn_802A3948(void* g, void* pos, s32 a, s32 kind, s32 b);
extern "C" s32 fn_8013CC50(s32 kind, void* pos, f32 f, s32 a, s32 b, s32 c, s32 d, s32 e, s32 g);
extern void* lbl_8053AC98;
extern u32 lbl_8046D8F8[];
extern f32 lbl_80540DC0;
extern "C" void fn_802CBAFC(u8* this_) {
    s32 count = *(s32*)((u8*)fn_801F856C() + 0x1008);
    s32 i = 0;
    s32 off = 0;
    for (; i < count; i++, off += 4) {
        u8* obj = *(u8**)((u8*)fn_801F856C() + off + 8);
        if (obj != 0 && (*(s32*)(obj + 0x1a0) == 0x53575434 || *(s32*)(obj + 0x1a0) == 0x4c4f5357) &&
            *(s32*)(this_ + 0x170) == *(s32*)(obj + 0x170)) {
            u32 v = *(u32*)(obj + 0x90);
            u32 tag = v >> 27;
            for (s32 k = 0; k < 4; k++) {
                if (*(u32*)(this_ + 0x244) == ((v >> lbl_8046D8F8[k]) & 0x1f)) {
                    *(u32*)(this_ + 0x258) = (unsigned short)tag;
                    if (fn_802D800C(fn_802D6A9C(), *(s32*)(this_ + 0x258))) {
                        fn_802A3948(lbl_8053AC98, this_ + 0xc, 0, *(s32*)(this_ + 4), 0xbe);
                        if (*(u32*)(this_ + 0x230) == 0) {
                            *(s32*)(this_ + 0x230) = fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, lbl_80540DC0, 0x428, 1, 0, 0, 0, 1);
                        }
                        if (*(u32*)(this_ + 0x234) == 0) {
                            *(s32*)(this_ + 0x234) = fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, lbl_80540DC0, 0x429, 1, 0, 0, 0, 1);
                        }
                        *(s32*)(this_ + 0x238) = 4;
                        break;
                    }
                }
            }
        }
    }
}

struct OnofActor : Actor {
    /* 0x230 */ u32 field_230;
    /* 0x234 */ u32 field_234;
    /* 0x238 */ s32 field_238;
    /* 0x23c */ s32 field_23C;
    /* 0x240 */ s32 field_240;
    /* 0x244 */ s32 field_244;
    /* 0x248 */ s32 field_248;
    /* 0x24c */ s32 field_24C;
    /* 0x250 */ u8 field_250[4];
    /* 0x254 */ s32 field_254;
};

extern void* lbl_8053AAF8;
extern f32 lbl_80540DC4;
extern f32 lbl_80540DC8;
extern "C" u8 fn_80138A30(void* game);
extern "C" bool fn_802D7888(void* mgr, s32 bit);
extern "C" void fn_802A3884(void* g, void* pos, s32 a, s32 kind, s32 b);
extern "C" void fn_802CBC70(OnofActor* this_) {
    this_->field_0C.x = this_->field_0C.x + lbl_80540DB0;
    this_->field_0C.y = this_->field_0C.y + lbl_80540DB0;
    this_->field_244 = this_->field_90 >> 27;
    this_->field_24C = this_->field_90 & 0xfff;
    this_->field_240 = (this_->field_90 >> 12) & 7;
    this_->field_248 = (this_->field_90 >> 25) & 3;
    this_->field_23C = 0;
    this_->field_254 = 0;
    this_->field_230 = 0;
    this_->field_234 = 0;
    u8 area = (u8)(u32)fn_80138A30(lbl_8053AAF8);
    s32 mode = this_->field_248;
    s32 skip = 0;
    if (mode == 0) {
        skip = 1;
    } else if (mode == 1) {
        if (area != 2) {
            skip = 1;
        }
    } else if (mode == 2) {
        if ((u8)(area - 2) > 1) {
            skip = 1;
        }
    } else if (mode == 3) {
        skip = 1;
    }
    if (skip == 1) {
        if (this_->field_240 == 3 || this_->field_240 == 4) {
            if (fn_802D7888(fn_802D6A9C(), this_->field_244) == 1) {
                fn_802A3948(lbl_8053AC98, &this_->field_0C, 0, this_->field_04, 0xbe);
                if (this_->field_230 == 0) {
                    this_->field_230 = fn_8013CC50(this_->field_04, &this_->field_0C, lbl_80540DC0, 0x428, 1, 0, 0, 0, 1);
                }
                if (this_->field_234 == 0) {
                    this_->field_234 = fn_8013CC50(this_->field_04, &this_->field_0C, lbl_80540DC0, 0x429, 1, 0, 0, 0, 1);
                }
                ((Actor*)this_)->v10(0xff, 1);
                if (this_->field_240 == 3) {
                    this_->field_238 = 2;
                } else {
                    this_->field_238 = 4;
                }
            } else {
                fn_802A3884(lbl_8053AC98, &this_->field_0C, 0, this_->field_04, 0xbf);
                ((Actor*)this_)->v10(0xff, 0);
                this_->field_238 = 0;
            }
        } else {
            fn_802A3884(lbl_8053AC98, &this_->field_0C, 0, this_->field_04, 0xbf);
            ((Actor*)this_)->v10(0xff, 0);
            this_->field_238 = 0;
        }
    } else {
        fn_802A3948(lbl_8053AC98, &this_->field_0C, 0, this_->field_04, 0xbe);
        if (this_->field_230 == 0) {
            this_->field_230 = fn_8013CC50(this_->field_04, &this_->field_0C, lbl_80540DC0, 0x428, 1, 0, 0, 0, 1);
        }
        if (this_->field_234 == 0) {
            this_->field_234 = fn_8013CC50(this_->field_04, &this_->field_0C, lbl_80540DC0, 0x429, 1, 0, 0, 0, 1);
        }
        ((Actor*)this_)->v10(0xff, 1);
        this_->field_238 = 4;
    }
    f32 wide = lbl_80540DC4;
    f32 near = lbl_80540DC8;
    this_->field_60 = wide;
    this_->field_64 = wide;
    this_->field_68 = near;
    this_->field_6C = near;
}

// Shared JAudio pool __sinit (docs/game/sinit_pools.md). Drop the ESD
// macros/typedefs that clash with the JSystem headers first.
#undef ALIGN_NEXT
#undef ALIGN_PREV
#undef ARRAY_SIZE
#undef ASM
#undef ATTRIBUTE_ALIGN
#undef IS_ALIGNED
#undef IS_NOT_ALIGNED
#undef MACROS_H
#undef MAX
#undef MIN
#undef NULL
#define NULL 0
#define unknown jsys_unknown
#include "JSystem/JAudio/JASFakeMatchFSA.h"
