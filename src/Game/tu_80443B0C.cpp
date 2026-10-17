#include "types.h"
#include <JSystem/J2D/J2DScreen.h>


extern "C" void* lbl_804B1B60[];
extern "C" void __dl__FPv(void* p);
extern const f32 lbl_80543D78;
extern "C" void fn_8013B490(void*);
extern "C" void fn_80402628(void*, s32, s32, u8);
extern void* lbl_8053AB10;
extern const f32 lbl_80543D7C;
extern "C" u8 fn_80402940(void*, s32, s32, f32, f32);
extern void* lbl_8053AAF8;
extern void* lbl_8053AD78;
extern char lbl_8048FBD0[];
extern "C" s8* getStringPtr__10J2DTextBoxCFv(void* self);
extern "C" void fn_80402E08(void* state, f32 x, f32 y);
extern "C" u32 fn_80309C4C(void* pad, s32 mask, s32 a);
extern "C" void fn_80458880(void* mgr, u32 p, s32 v);
extern void* lbl_8053AF80;
extern void* lbl_8053AD30;
extern "C" void fn_80443B0C(void* unused, s8* dst, s32 idx, s32 num) {
    void* obj = *(void**)((u8*)lbl_8053AAF8 + 0xa8);
    u8* data = (u8*)((void* (*)(void*, u32, void*))(*(void***)obj)[6])(obj, 0x3f3f3f3f, lbl_8048FBD0) + 0x20;
    s32 top = num / 10000;
    s8* text = (s8*)(data + *(u32*)(data + 4) + *(u32*)(data + idx * 8 + 0x10) + 8);
    s32 in = 0;
    s32 out = 0;
    s8 c = text[in];
    while (c != 0) {
        s8* p = text + in;
        if (c == 0x1a) {
            if (p[2] == 3 && ((p[3] == 0 && p[4] == 3) || (p[3] == 0 && p[4] == 4))) {
                s32 rest = num;
                if (num >= 10000) {
                    dst[out++] = top + '0';
                    rest = num % 10000;
                }
                if (num >= 1000) {
                    dst[out++] = rest / 1000 + '0';
                    rest %= 1000;
                }
                if (num >= 100) {
                    dst[out++] = rest / 100 + '0';
                    rest %= 100;
                }
                if (num >= 10) {
                    dst[out++] = rest / 10 + '0';
                    rest %= 10;
                }
                dst[out++] = rest + '0';
            }
            in += p[1];
        } else {
            dst[out++] = c;
            in++;
            void* font = *(void**)((u8*)lbl_8053AD78 + 0x154);
            u8 lead = ((u8 (*)(void*, u8))(*(void***)font)[16])(font, (u8)c);
            if (lead) {
                dst[out++] = text[in++];
            }
        }
        c = text[in];
    }
    dst[out] = c;
}

extern "C" void fn_80443D5C(u8* p) {
    if (fn_80402940(*(void**)(p + 8), 10, 0, lbl_80543D78, lbl_80543D7C)) {
        p[0x4d] = 4;
    }
}

extern const f32 lbl_80543D80;
extern const f32 lbl_80543D84;
extern "C" void fn_80444590(u8* p) {
    if (fn_80402940(*(void**)(p + 8), 5, 0, lbl_80543D80, lbl_80543D78)) {
        p[0x4d] = 2;
    }
}

extern "C" void fn_804445E0(u8* p) {
    u8* obj = *(u8**)(p + 0xc);
    fn_80402628(obj, 0x10, 0, obj[0x28]);
    if (fn_80402940(*(void**)(p + 8), 0x10, 0, lbl_80543D84, lbl_80543D80)) {
        *(s16*)(*(u8**)(p + 8) + 0x22) = 0;
        p[0x4d] = 1;
    }
}

extern "C" void fn_80444650(void* this_) {
    char* p = (char*)this_;
    if (*(u8*)(p + 0x4d) != 4) {
        fn_8013B490(lbl_8053AB10);
        ((J2DScreen*)*(void**)(p + 0x4))->draw(lbl_80543D78, lbl_80543D78, (const J2DGrafContext*)((void**)lbl_8053AB10)[4]);
    }
}

struct T804446A4;
struct Slot0 {
    virtual void slot0(s32 arg);
};

struct T80444A24 {
    u8 pad0[0x10];
    Slot0* a[6];
    Slot0* b[2];
};

typedef void (T804446A4::*PMF804446A4)();
extern PMF804446A4 lbl_804B1B30[];
extern "C" bool fn_804446A4(T804446A4* this_) {
    u8 state = *(u8*)((char*)this_ + 0x4d);
    if (state != 4) {
        (this_->*lbl_804B1B30[state])();
        return false;
    }
    return true;
}

extern "C" void fn_804446F0(u8* this_, s32 num)
{
    u8* self = this_;
    s32 n = num;
    void* obj;
    void* tb;
    *(s32*)(self + 0x44) = n;

    obj = *(void**)(self + 4);
    tb = ((void* (*)(void*, s32, s32, u32))(*(void***)obj)[0x3c / 4])(obj, n, 0x54, 0x6d6d3031);
    fn_80443B0C(self, getStringPtr__10J2DTextBoxCFv(tb), 0x241, n);

    obj = *(void**)(self + 4);
    tb = ((void* (*)(void*, s32, s32, u32))(*(void***)obj)[0x3c / 4])(obj, 0x6d6d0000, 0x54, 0x6d6d3032);
    fn_80443B0C(self, getStringPtr__10J2DTextBoxCFv(tb), 0x241, n);

    obj = *(void**)(self + 4);
    tb = ((void* (*)(void*, s32, s32, u32))(*(void***)obj)[0x3c / 4])(obj, 0x6d6d0000, 0x54, 0x6d6d3033);
    fn_80443B0C(self, getStringPtr__10J2DTextBoxCFv(tb), 0x242, n);

    obj = *(void**)(self + 4);
    tb = ((void* (*)(void*, s32, s32, u32))(*(void***)obj)[0x3c / 4])(obj, 0x6d6d0000, 0x54, 0x6d6d3034);
    fn_80443B0C(self, getStringPtr__10J2DTextBoxCFv(tb), 0x242, n);

    obj = *(void**)(self + 4);
    tb = ((void* (*)(void*, s32, s32, u32))(*(void***)obj)[0x3c / 4])(obj, 0x6d6d0000, 0x54, 0x6d6d3035);
    fn_80443B0C(self, getStringPtr__10J2DTextBoxCFv(tb), 0x243, n);

    obj = *(void**)(self + 4);
    tb = ((void* (*)(void*, s32, s32, u32))(*(void***)obj)[0x3c / 4])(obj, 0x6d6d0000, 0x54, 0x6d6d3036);
    fn_80443B0C(self, getStringPtr__10J2DTextBoxCFv(tb), 0x243, n);

    fn_80402E08(*(void**)(self + 8), 0.0f, -480.0f);
    *(u16*)(*(u8**)(self + 8) + 0x22) = 0;

    obj = *(void**)(*(u8**)(self + 0xc) + 4);
    ((void (*)(void*, s32))(*(void***)obj)[0x24 / 4])(obj, 0);
    *(u16*)(*(u8**)(self + 0xc) + 0x26) = 0;

    *(u8*)(*(u8**)(*(u8**)(self + 0x10) + 4) + 0xb0) = 1;
    *(u8*)(*(u8**)(*(u8**)(self + 0x14) + 4) + 0xb0) = 1;

    *(u32*)((u8*)lbl_8053AAF8 + 0xb4) = *(u32*)((u8*)lbl_8053AAF8 + 0xb4) * 0x19660d + 0x3c6ef35f;
    u32 bits = (*(u32*)((u8*)lbl_8053AAF8 + 0xb4) >> 9) | 0x3f800000;
    *(s32*)(self + 0x48) = (s32)(11.0f * (*(f32*)&bits - 1.0f)) + 10;
    *(u8*)(self + 0x4c) = 0;

    u32 a = *(u32*)(self + 0x34);
    u32 b = *(u32*)(self + 0x30);
    obj = *(void**)(self + 4);
    tb = ((void* (*)(void*, s32, s32, u32))(*(void***)obj)[0x3c / 4])(obj, 0x6d6d0000, 0x54, 0x6d6d3035);
    ((void (*)(void*, void*, void*))(*(void***)tb)[0xac / 4])(tb, &b, &a);

    for (s32 i = 0; i < 6; i++) {
        fn_80402E08(*(void**)(self + 0x10 + i * 4), 0.0f, -480.0f);
    }
    for (s32 i = 0; i < 2; i++) {
        fn_80402E08(*(void**)(self + 0x28 + i * 4), 0.0f, -480.0f);
    }
    *(u8*)(self + 0x4d) = 0;
}

extern "C" void* fn_80444A24(T80444A24* this_, s16 flag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804B1B60;
        void* p1 = *(void**)((u8*)this_ + 0x4);
        if (p1 != 0) {
            ((Slot0*)p1)->slot0(1);
        }
        *(void**)((u8*)this_ + 0x4) = 0;
        void* p2 = *(void**)((u8*)this_ + 0x8);
        if (p2 != 0) {
            ((Slot0*)p2)->slot0(1);
        }
        *(void**)((u8*)this_ + 0x8) = 0;
        void* p3 = *(void**)((u8*)this_ + 0xc);
        if (p3 != 0) {
            ((Slot0*)p3)->slot0(1);
        }
        *(void**)((u8*)this_ + 0xc) = 0;
        for (int i = 0; i < 6; i++) {
            if (this_->a[i] != 0) {
                this_->a[i]->slot0(1);
            }
            this_->a[i] = 0;
        }
        for (int i = 0; i < 2; i++) {
            if (this_->b[i] != 0) {
                this_->b[i]->slot0(1);
            }
            this_->b[i] = 0;
        }
        if (flag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

