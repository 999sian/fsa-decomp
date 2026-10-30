#include "types.h"
#include "Game/PaneState.h"
struct MenuAnimParams80441 {
    u8 pad[0x8c];
    s16 appearFrames;
    s16 slideFrames;
    s16 slideDistance;
    s16 leaveFrames;
    s16 fadeFrames;
};

struct Menu80441A1C {
    u8 pad[8];
    PaneState* alphaPane;
    PaneState* movePane;
    s32 result;
    s32 player;
    s32 state;
    s32 timer;
};
#include "JSystem/J2D/J2DPane.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"
static inline void capPaneFrame(PaneState* pane, s16 limit) {
    if (pane->alphaFrame > limit) pane->alphaFrame = limit;
}

struct Slot0 {
    virtual void slot0(s32 arg);
};


extern "C" void __dl__FPv(void*);
extern "C" u8 lbl_804B19F0[];
extern "C" u32 lbl_8053AEE0;

struct fn_80442368_Obj {
    virtual void Release(int);
};

extern "C" void fn_8013B490(void* p);
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(void* screen, f32 x, f32 y, void* ctx);
extern "C" void* lbl_8053AB10;
extern "C" f32 lbl_80543D40;
extern "C" f32 lbl_80543D44;
extern "C" f32 lbl_80543D48;
extern "C" f32 lbl_80543D4C;
extern "C" f64 lbl_80543D50;
extern "C" f64 lbl_80543D58;
extern "C" u8 lbl_804AF86C[];
extern "C" u8 lbl_8050DB0C[];
extern "C" void* lbl_8053AAF8;
extern "C" void* lbl_8053AD30;
extern "C" void* lbl_8053AF80;
extern "C" u8 fn_8030A258(void*, s32);
extern "C" u8 fn_8030A388(void*, s32);
extern "C" s32 fn_8030AAF4(s32);
extern "C" u8 AnimTable_IsField0xdcLessThan3(void*, s32);
extern "C" u8 AnimTable_IsField0xe0LessThan3(void*, s32);
extern "C" void* fn_80309C4C(void*, s32, s32);
extern "C" void fn_80458F9C(void*, s32);
extern "C" void fn_80459274(void*);
struct Unk80441A1CVt {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7(s32);
    virtual void m8();
    virtual void m9(s32);
};
extern "C" u8 lbl_8048FAF0[];
extern "C" u8 lbl_80529DEC[];
extern "C" void* lbl_8053AD78;
extern "C" void* __nw__FUl(unsigned long size);
extern "C" void __ct__9J2DScreenFv(void* self);
extern "C" void setPriority__9J2DScreenFPCcUlP10JKRArchive(void* pane, const char* name, unsigned long id, void* archive);
extern "C" void fn_80402F04(void* a, void* b);
extern "C" void fn_80402E08(void* a, f32 b, f32 c);
struct J2DScreenVt {
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
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void* m13(s32, s32, u32);
};
struct J2DScreenObjVt {
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
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37(void*);
};
struct Unk80442254Vt {
    virtual void m0() = 0;
    virtual void m1() = 0;
    virtual void m2() = 0;
    virtual void m3() = 0;
    virtual void m4() = 0;
    virtual void m5() = 0;
    virtual void m6() = 0;
    virtual void m7(s32) = 0;
    virtual void m8() = 0;
    virtual void m9() = 0;
    virtual void m10() = 0;
    virtual void m11() = 0;
    virtual void m12() = 0;
    virtual void* m13(s32, s32, u32, s32) = 0;
};

extern "C" s32 fn_80441A1C(Menu80441A1C* menu) {
    u32 f = ((s32)((u8*)lbl_8053AAF8)[0x83] >> (menu->player << 1)) & 3;
    if (f == 1) {
        if (fn_8030A258(lbl_8053AD30, fn_8030AAF4(menu->player))) {
            PaneState* p8;
            s16* tbl;
            s16 frame;
            s16 limit;
            p8 = menu->alphaPane;
            tbl = (s16*)lbl_8050DB0C;
            frame = p8->alphaFrame;
            limit = tbl[0x94 / 2];
            if (frame > limit) {
                p8->alphaFrame = limit;
            }
            if (menu->movePane->alphaFrame > ((s16*)lbl_8050DB0C)[0x92 / 2] + tbl[0x94 / 2]) {
                menu->movePane->alphaFrame = ((s16*)lbl_8050DB0C)[0x92 / 2] + tbl[0x94 / 2];
            }
            menu->state = 0xb;
        }
    } else if (f == 2) {
        if (fn_8030A388(lbl_8053AD30, fn_8030AAF4(menu->player))) {
            PaneState* p8;
            s16* tbl;
            s16 frame;
            s16 limit;
            p8 = menu->alphaPane;
            tbl = (s16*)lbl_8050DB0C;
            frame = p8->alphaFrame;
            limit = tbl[0x94 / 2];
            if (frame > limit) {
                p8->alphaFrame = limit;
            }
            if (menu->movePane->alphaFrame > ((s16*)lbl_8050DB0C)[0x92 / 2] + tbl[0x94 / 2]) {
                menu->movePane->alphaFrame = ((s16*)lbl_8050DB0C)[0x92 / 2] + tbl[0x94 / 2];
            }
            menu->state = 0xb;
        }
    }
    switch (menu->state) {
    case 1: {
        u32 f = ((s32)((u8*)lbl_8053AAF8)[0x83] >> (menu->player << 1)) & 3;
        if (f == 2) {
            if (!AnimTable_IsField0xdcLessThan3(lbl_8053AD30, fn_8030AAF4(menu->player))) {
                break;
            }
        }
        (menu->timer)++;
        s16* tbl = (s16*)lbl_8050DB0C;
        if (menu->alphaPane->alphaFrame < tbl[0x8c / 2] + 2) {
            menu->alphaPane->alphaFrame += 1;
            f32 ratio = ((f32)(menu->alphaPane->alphaFrame * menu->alphaPane->alphaFrame) / (f32)((tbl[0x8c / 2] + 2) * (tbl[0x8c / 2] + 2)));
            J2DPane* obj = menu->alphaPane->pane;
            obj->setAlpha(ratio * (f32)menu->alphaPane->alpha);
        }
        if (menu->timer >= 0x78) {
            menu->timer = 0;
            menu->state = 2;
        }
        break;
    }
    case 2: {
        (menu->timer)++;
        s16* tbl = (s16*)lbl_8050DB0C;
        s32 t = tbl[0x8c / 2] + 2;
        if (menu->movePane->alphaFrame < t) {
            menu->movePane->alphaFrame += 1;
            fn_80402E08(menu->movePane, 0.0f, ((f32)(menu->movePane->alphaFrame * menu->movePane->alphaFrame) / (f32)(t * t)) * (480.0f + (f32)tbl[0x90 / 2]) + -480.0f);
        }
        if (menu->movePane->alphaFrame >= t) {
            menu->state = 3;
        }
        break;
    }
    case 3: {
        (menu->timer)++;
        s16* tbl = (s16*)lbl_8050DB0C;
        s32 t = 2;
        t += tbl[0x8c / 2];
        t += tbl[0x8e / 2];
        if (menu->movePane->alphaFrame < t) {
            menu->movePane->alphaFrame += 1;
            s32 d = t - menu->movePane->alphaFrame;
            s32 g8e = tbl[0x8e / 2];
            fn_80402E08(menu->movePane, 0.0f, (f32)tbl[0x90 / 2] * ((f32)(d * d) / (f32)(g8e * g8e)));
        }
        if (menu->movePane->alphaFrame >= t) {
            menu->state = 4;
        }
        break;
    }
    case 4:
        menu->timer += 1;
        if (menu->timer >= 0xb4) {
            menu->timer = 0;
            menu->state = 5;
        }
        break;
    case 5:
        menu->timer += 1;
        if (menu->timer >= 0xb4) {
            if (menu->movePane->alphaFrame > 0xa) {
                menu->movePane->alphaFrame = 0xa;
            }
            menu->state = 0xd;
        }
        break;
    case 6: {
        if (fn_80309C4C(lbl_8053AD30, 0x1300, -1)) {
            if (menu->movePane->alphaFrame > 0xa) {
                menu->movePane->alphaFrame = 0xa;
            }
            menu->state = 0xd;
            break;
        }
        s32 sh;
        s32 cnt1;
        s32 cnt2;
        s32 i;
        cnt1 = 0;
        cnt2 = 0;
        i = 0;
        sh = 0;
        for (; i < 4; i++, sh += 2) {
            if (((u32)((s32)((u8*)lbl_8053AAF8)[0x83] >> sh) & 3) != 0) {
                cnt1++;
                if (((u32)((s32)((u8*)lbl_8053AAF8)[0x83] >> sh) & 3) == 1) {
                    if (!AnimTable_IsField0xdcLessThan3(lbl_8053AD30, fn_8030AAF4(i))) {
                        cnt2++;
                    }
                }
                if (((u32)((s32)((u8*)lbl_8053AAF8)[0x83] >> sh) & 3) == 2) {
                    if (!AnimTable_IsField0xe0LessThan3(lbl_8053AD30, fn_8030AAF4(i))) {
                        cnt2++;
                    }
                }
            }
        }
        if (cnt1 != cnt2) {
            break;
        }
        menu->timer = 0;
        menu->state = 5;
        break;
    }
    case 11: {
        s16* tbl = (s16*)lbl_8050DB0C;
        s32 sum = tbl[0x92 / 2] + tbl[0x94 / 2];
        if (menu->alphaPane->alphaFrame > 0 && menu->alphaPane->alphaFrame >= menu->movePane->alphaFrame) {
            menu->alphaPane->alphaFrame -= 1;
            f32 ratio = ((f32)(menu->alphaPane->alphaFrame * menu->alphaPane->alphaFrame) / (f32)(tbl[0x94 / 2] * tbl[0x94 / 2]));
            J2DPane* obj = menu->alphaPane->pane;
            obj->setAlpha(ratio * (f32)menu->alphaPane->alpha);
        }
        if ((s16)menu->movePane->alphaFrame > 0) {
            menu->movePane->alphaFrame -= 1;
        }
        if (menu->movePane->alphaFrame > tbl[0x94 / 2]) {
            s32 d = sum - menu->movePane->alphaFrame;
            fn_80402E08(menu->movePane, 0.0f, (f32)((s16*)lbl_8050DB0C)[0x90 / 2] * ((f32)(d * d) / (f32)(tbl[0x92 / 2] * tbl[0x92 / 2])));
        } else if (menu->movePane->alphaFrame > 0) {
            fn_80402E08(menu->movePane, 0.0f, ((f32)(menu->movePane->alphaFrame * menu->movePane->alphaFrame) / (f32)(tbl[0x94 / 2] * tbl[0x94 / 2])) * (480.0f + (f32)((s16*)lbl_8050DB0C)[0x90 / 2]) + -480.0f);
        } else {
            fn_80402E08(menu->movePane, 0.0f, -480.0f);
        }
        if (menu->alphaPane->alphaFrame > 0) {
            break;
        }
        if (menu->movePane->alphaFrame > 0) {
            break;
        }
        return menu->result;
    }
    case 13: {
        if ((s16)menu->movePane->alphaFrame > 0) {
            menu->movePane->alphaFrame -= 1;
            fn_80402E08(menu->movePane, 0.0f, 480.0f * ((f32)((10 - (s32)menu->movePane->alphaFrame) * (10 - (int)menu->movePane->alphaFrame)) / 100.0f));
        }
        if (menu->movePane->alphaFrame > 0) {
            break;
        }
        fn_80458F9C(lbl_8053AF80, 0);
        fn_80459274(lbl_8053AF80);
        return 1;
    }
    }
    return 0x16;
}

extern "C" void fn_80442200(void* this_) {
    fn_8013B490(lbl_8053AB10);
    if (*(int*)((char*)this_ + 0x18) != 0) {
        draw__9J2DScreenFffPC14J2DGrafContext(*(void**)((char*)this_ + 0x4), lbl_80543D40, lbl_80543D40, ((void**)lbl_8053AB10)[4]);
    }
}

extern "C" void fn_80402E08(void*, f32, f32);
extern "C" void fn_803832BC(const char*, u32, u32, u32, u32);
extern "C" void* lbl_8053AAF8;
extern "C" f32 lbl_80543D44;
extern "C" void fn_80442254(char* this_, s32 param_2, s32 param_3) {
    u16 z = 0;
    Unk80442254Vt* obj = *(Unk80442254Vt**)(*(char**)(this_ + 0x8) + 0x4);
    obj->m7(0);
    f32 a = lbl_80543D40;
    *(u16*)(*(char**)(this_ + 0x8) + 0x26) = z;
    f32 b = lbl_80543D44;
    fn_80402E08(*(void**)(this_ + 0xc), a, b);
    *(u16*)(*(char**)(this_ + 0xc) + 0x22) = z;
    *(s32*)(this_ + 0x10) = param_2;
    *(s32*)(this_ + 0x14) = param_3 - 1;
    *(s32*)(this_ + 0x18) = 1;
    *(s32*)(this_ + 0x1c) = 0;
    Unk80442254Vt* tb = *(Unk80442254Vt**)(this_ + 0x4);
    char* str = (char*)tb->m13(param_3 - 1, 0x54, 0x77743031, 0);
    const char* text = ((J2DTextBox*)str)->getStringPtr();
    s32 idx = *(s32*)(this_ + 0x14);
    u32 f = ((s32)((u8*)lbl_8053AAF8)[0x83] >> (idx << 1)) & 3;
    if (f == 1) {
        fn_803832BC(text, 0x3b, idx + 1, 0, 0);
    } else if (f == 2) {
        fn_803832BC(text, 0x3a, idx + 1, 0, 0);
    }
}

extern "C" void* fn_80442368(void* this_, s16 flag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804B19F0;
        void* p1 = *(void**)((char*)this_ + 0x4);
        if (p1 != 0) {
            ((Slot0*)p1)->slot0(1);
        }
        *(void**)((char*)this_ + 0x4) = 0;
        void* p2 = *(void**)((char*)this_ + 0x8);
        if (p2 != 0) {
            ((Slot0*)p2)->slot0(1);
        }
        *(void**)((char*)this_ + 0x8) = 0;
        void* p3 = *(void**)((char*)this_ + 0xc);
        if (p3 != 0) {
            ((Slot0*)p3)->slot0(1);
        }
        *(void**)((char*)this_ + 0xc) = 0;
        lbl_8053AEE0 = 0;
        if (flag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void* fn_8044243C(void* this_) {
    u8* self = (u8*)this_;
    *(void**)self = (void*)lbl_804B19F0;
    lbl_8053AEE0 = (u32)self;

    void* screen = __nw__FUl(0x118);
    if (screen != 0) {
        __ct__9J2DScreenFv(screen);
    }
    *(void**)(self + 4) = screen;
    setPriority__9J2DScreenFPCcUlP10JKRArchive(*(void**)(self + 4), (const char*)lbl_8048FAF0, 0x1100000, *(void**)(lbl_80529DEC + 0x20));

    void* r30 = *(void**)((char*)lbl_8053AD78 + 0x154);
    ((J2DScreenObjVt*)((J2DScreenVt*)*(void**)(self + 4))->m13(0x77740000, 0x54, 0x77743031))->m37(r30);

    void* obj = __nw__FUl(0x2c);
    if (obj != 0) {
        *(void**)obj = (void*)lbl_804AF86C;
    }
    *(void**)(self + 8) = obj;
    u32 k = 0x6c6b3031;
    fn_80402F04(*(void**)(self + 8), ((J2DScreenVt*)*(void**)(self + 4))->m13(0x500000, 0x507762, k));

    obj = __nw__FUl(0x2c);
    if (obj != 0) {
        *(void**)obj = (void*)lbl_804AF86C;
    }
    *(void**)(self + 12) = obj;
    u32 k2 = 0x61673031;
    fn_80402F04(*(void**)(self + 12), ((J2DScreenVt*)*(void**)(self + 4))->m13(0x4e640000, 0x4e646174, k2));

    ((Unk80442254Vt*)*(void**)(*(char**)(self + 8) + 4))->m7(0);
    u16* p = (u16*)(*(char**)(self + 8) + 0x26);
    f32 a = lbl_80543D40;
    *p = 0;
    f32 b = lbl_80543D44;
    fn_80402E08(*(void**)(self + 12), a, b);
    *(u16*)(*(char**)(self + 12) + 0x22) = 0;
    *(s32*)(self + 0x10) = 0x16;
    *(s32*)(self + 0x14) = 0;
    *(s32*)(self + 0x18) = 0;
    *(s32*)(self + 0x1c) = 0;
    return this_;
}

void fn_804425EC(void) {
}

