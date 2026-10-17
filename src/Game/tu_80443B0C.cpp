#include "types.h"
#include <JSystem/J2D/J2DScreen.h>


extern "C" void* lbl_804B1B60[];

struct FsaBlock48 {
    u32 w[12];
};
extern "C" void __dl__FPv(void* p);
extern const f32 lbl_80543D78;
extern "C" void fn_8013B490(void*);
extern "C" void fn_80402628(void*, s32, s32, u8);
extern void* lbl_8053AB10;
extern const f32 lbl_80543D7C;
extern "C" u8 fn_80402940(void*, s32, s32, f32, f32);
extern void* lbl_8053AAF8;

static inline f32 Tu80443B0C_randf() {
    u8* rng = (u8*)lbl_8053AAF8;
    u32 bits;
    *(u32*)(rng + 0xb4) = *(u32*)(rng + 0xb4) * 0x19660d + 0x3c6ef35f;
    bits = (*(u32*)(rng + 0xb4) >> 9) | 0x3f800000;
    return *(f32*)&bits;
}
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

extern "C" void fn_80443DAC(u8* this_) {
    void* obj;
    void* tb;
    u32 a;
    u32 b;
    u32 c;
    u32 d;
    u32 unk;
    s32 i;
    if (fn_80309C4C(lbl_8053AD30, 4, -1) != 0) {
        if (this_[0x4c] == 0) {
            this_[0x4c] = 1;
            b = *(u32*)(this_ + 0x38);
            a = *(u32*)(this_ + 0x3c);
            obj = *(void**)(this_ + 0x4);
            tb = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[0x3c / 4])(obj, unk, 0x54, 0x6d6d3033);
            ((void (*)(void*, void*, void*))(*(void***)tb)[0xac / 4])(tb, &b, &a);
            d = *(u32*)(this_ + 0x30);
            c = *(u32*)(this_ + 0x34);
            obj = *(void**)(this_ + 0x4);
            tb = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[0x3c / 4])(obj, unk, 0x54, 0x6d6d3035);
            ((void (*)(void*, void*, void*))(*(void***)tb)[0xac / 4])(tb, &d, &c);
            for (i = 0; i < 6; i++) {
                fn_80402E08(*(void**)(this_ + 0x10 + i * 4), lbl_80543D78, lbl_80543D78);
            }
            for (i = 0; i < 2; i++) {
                fn_80402E08(*(void**)(this_ + 0x28 + i * 4), lbl_80543D78, lbl_80543D78);
            }
            fn_80458880(lbl_8053AF80, 0, -1);
        }
    } else if (fn_80309C4C(lbl_8053AD30, 8, -1) != 0) {
        if (this_[0x4c] == 1) {
            this_[0x4c] = 0;
            d = *(u32*)(this_ + 0x30);
            c = *(u32*)(this_ + 0x34);
            obj = *(void**)(this_ + 0x4);
            tb = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[0x3c / 4])(obj, unk, 0x54, 0x6d6d3033);
            ((void (*)(void*, void*, void*))(*(void***)tb)[0xac / 4])(tb, &d, &c);
            b = *(u32*)(this_ + 0x38);
            a = *(u32*)(this_ + 0x3c);
            obj = *(void**)(this_ + 0x4);
            tb = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[0x3c / 4])(obj, unk, 0x54, 0x6d6d3035);
            ((void (*)(void*, void*, void*))(*(void***)tb)[0xac / 4])(tb, &b, &a);
            for (i = 0; i < 6; i++) {
                fn_80402E08(*(void**)(this_ + 0x10 + i * 4), lbl_80543D78, *(f32*)(this_ + 0x40));
            }
            for (i = 0; i < 2; i++) {
                fn_80402E08(*(void**)(this_ + 0x28 + i * 4), lbl_80543D78, *(f32*)(this_ + 0x40));
            }
            fn_80458880(lbl_8053AF80, 0, -1);
        }
    } else if (fn_80309C4C(lbl_8053AD30, 0x1100, -1) != 0) {
        *(u16*)(*(u8**)(this_ + 0x8) + 0x22) = 0;
        this_[0x4d] = 3;
        if (this_[0x4c] == 0) {
            fn_80458880(lbl_8053AF80, 0xb, -1);
        } else {
            fn_80458880(lbl_8053AF80, 0xc, -1);
        }
    } else if (fn_80309C4C(lbl_8053AD30, 0x200, -1) != 0) {
        this_[0x4c] = 1;
        b = *(u32*)(this_ + 0x38);
        a = *(u32*)(this_ + 0x3c);
        obj = *(void**)(this_ + 0x4);
        tb = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[0x3c / 4])(obj, unk, 0x54, 0x6d6d3033);
        ((void (*)(void*, void*, void*))(*(void***)tb)[0xac / 4])(tb, &b, &a);
        d = *(u32*)(this_ + 0x30);
        c = *(u32*)(this_ + 0x34);
        obj = *(void**)(this_ + 0x4);
        tb = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[0x3c / 4])(obj, unk, 0x54, 0x6d6d3035);
        ((void (*)(void*, void*, void*))(*(void***)tb)[0xac / 4])(tb, &d, &c);
        for (i = 0; i < 6; i++) {
            fn_80402E08(*(void**)(this_ + 0x10 + i * 4), lbl_80543D78, lbl_80543D78);
        }
        for (i = 0; i < 2; i++) {
            fn_80402E08(*(void**)(this_ + 0x28 + i * 4), lbl_80543D78, lbl_80543D78);
        }
        *(u16*)(*(u8**)(this_ + 0x8) + 0x22) = 0;
        this_[0x4d] = 3;
        fn_80458880(lbl_8053AF80, 0xc, -1);
    }
    {
        s32 n = *(s32*)(this_ + 0x48) - 1;
        *(s32*)(this_ + 0x48) = n;
        if (n <= 0) {
            u32 prod = *(u32*)((u8*)lbl_8053AAF8 + 0xb4) * 0x19660d;
            *(u32*)((u8*)lbl_8053AAF8 + 0xb4) = prod + 0x3c6ef35f;
            u32 bits = (*(u32*)((u8*)lbl_8053AAF8 + 0xb4) >> 9) | 0x3f800000;
            *(s32*)(this_ + 0x48) = (s32)(11.0f * (*(f32*)&bits - 1.0f)) + 10;
            obj = *(void**)(this_ + 0x4);
            tb = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[0x3c / 4])(obj, prod, 0x506f63, 0x75723031);
            if (((u8*)tb)[0xb0] != 0) {
                obj = *(void**)(this_ + 0x4);
                tb = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[0x3c / 4])(obj, 0x500000, 0x506f63, 0x75723031);
                ((u8*)tb)[0xb0] = 0;
                obj = *(void**)(this_ + 0x4);
                tb = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[0x3c / 4])(obj, 0x500000, 0x506f63, 0x75723032);
                ((u8*)tb)[0xb0] = 0;
                obj = *(void**)(this_ + 0x4);
                tb = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[0x3c / 4])(obj, 0x500000, 0x506f63, 0x75723033);
                ((u8*)tb)[0xb0] = 1;
                obj = *(void**)(this_ + 0x4);
                tb = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[0x3c / 4])(obj, 0x500000, 0x506f63, 0x75723034);
                ((u8*)tb)[0xb0] = 1;
                obj = *(void**)(this_ + 0x4);
                tb = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[0x3c / 4])(obj, 0x500000, 0x506f63, 0x75723035);
                ((u8*)tb)[0xb0] = 0;
                obj = *(void**)(this_ + 0x4);
                tb = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[0x3c / 4])(obj, 0x500000, 0x506f63, 0x75723036);
                ((u8*)tb)[0xb0] = 0;
            } else {
                obj = *(void**)(this_ + 0x4);
                tb = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[0x3c / 4])(obj, 0x500000, 0x506f63, 0x75723033);
                if (((u8*)tb)[0xb0] != 0) {
                    obj = *(void**)(this_ + 0x4);
                    tb = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[0x3c / 4])(obj, 0x500000, 0x506f63, 0x75723031);
                    ((u8*)tb)[0xb0] = 1;
                    obj = *(void**)(this_ + 0x4);
                    tb = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[0x3c / 4])(obj, 0x500000, 0x506f63, 0x75723032);
                    ((u8*)tb)[0xb0] = 1;
                    obj = *(void**)(this_ + 0x4);
                    tb = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[0x3c / 4])(obj, 0x500000, 0x506f63, 0x75723033);
                    ((u8*)tb)[0xb0] = 0;
                    obj = *(void**)(this_ + 0x4);
                    tb = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[0x3c / 4])(obj, 0x500000, 0x506f63, 0x75723034);
                    ((u8*)tb)[0xb0] = 0;
                    obj = *(void**)(this_ + 0x4);
                    tb = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[0x3c / 4])(obj, 0x500000, 0x506f63, 0x75723035);
                    ((u8*)tb)[0xb0] = 1;
                    obj = *(void**)(this_ + 0x4);
                    tb = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[0x3c / 4])(obj, 0x500000, 0x506f63, 0x75723036);
                    ((u8*)tb)[0xb0] = 1;
                } else {
                    obj = *(void**)(this_ + 0x4);
                    tb = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[0x3c / 4])(obj, 0x500000, 0x506f63, 0x75723031);
                    ((u8*)tb)[0xb0] = 0;
                    obj = *(void**)(this_ + 0x4);
                    tb = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[0x3c / 4])(obj, 0x500000, 0x506f63, 0x75723032);
                    ((u8*)tb)[0xb0] = 0;
                    obj = *(void**)(this_ + 0x4);
                    tb = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[0x3c / 4])(obj, 0x500000, 0x506f63, 0x75723033);
                    ((u8*)tb)[0xb0] = 1;
                    obj = *(void**)(this_ + 0x4);
                    tb = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[0x3c / 4])(obj, 0x500000, 0x506f63, 0x75723034);
                    ((u8*)tb)[0xb0] = 1;
                    obj = *(void**)(this_ + 0x4);
                    tb = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[0x3c / 4])(obj, 0x500000, 0x506f63, 0x75723035);
                    ((u8*)tb)[0xb0] = 0;
                    obj = *(void**)(this_ + 0x4);
                    tb = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[0x3c / 4])(obj, 0x500000, 0x506f63, 0x75723036);
                    ((u8*)tb)[0xb0] = 0;
                }
            }
        }
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
    s32 i;
    *(s32*)(this_ + 0x44) = num;

    fn_80443B0C(this_, (s8*)((J2DTextBox*)(*(J2DScreen**)(this_ + 4))->search(0x546d6d3031))->getStringPtr(), 0x241, num);
    fn_80443B0C(this_, (s8*)((J2DTextBox*)(*(J2DScreen**)(this_ + 4))->search(0x546d6d3032))->getStringPtr(), 0x241, num);
    fn_80443B0C(this_, (s8*)((J2DTextBox*)(*(J2DScreen**)(this_ + 4))->search(0x546d6d3033))->getStringPtr(), 0x242, num);
    fn_80443B0C(this_, (s8*)((J2DTextBox*)(*(J2DScreen**)(this_ + 4))->search(0x546d6d3034))->getStringPtr(), 0x242, num);
    fn_80443B0C(this_, (s8*)((J2DTextBox*)(*(J2DScreen**)(this_ + 4))->search(0x546d6d3035))->getStringPtr(), 0x243, num);
    fn_80443B0C(this_, (s8*)((J2DTextBox*)(*(J2DScreen**)(this_ + 4))->search(0x546d6d3036))->getStringPtr(), 0x243, num);

    fn_80402E08(*(void**)(this_ + 8), lbl_80543D78, lbl_80543D84);
    *(u16*)(*(u8**)(this_ + 8) + 0x22) = 0;
    (*(J2DPane**)(*(u8**)(this_ + 0xc) + 4))->setAlpha(0);
    *(u16*)(*(u8**)(this_ + 0xc) + 0x26) = 0;
    *(u8*)(*(u8**)(*(u8**)(this_ + 0x10) + 4) + 0xb0) = 1;
    *(u8*)(*(u8**)(*(u8**)(this_ + 0x14) + 4) + 0xb0) = 1;

    {
        u8* rng = (u8*)lbl_8053AAF8;
        *(u32*)(rng + 0xb4) = *(u32*)(rng + 0xb4) * 0x19660d + 0x3c6ef35f;
        const u32& bits = (*(u32*)(rng + 0xb4) >> 9) | 0x3f800000;
        *(s32*)(this_ + 0x48) = (s32)(11.0f * (*(const f32*)&bits - 1.0f)) + 10;
    }
    this_[0x4c] = 0;

    ((J2DTextBox*)(*(J2DScreen**)(this_ + 4))->search(0x546d6d3033))->setBlackWhite(*(JUtility::TColor*)(this_ + 0x30), *(JUtility::TColor*)(this_ + 0x34));
    ((J2DTextBox*)(*(J2DScreen**)(this_ + 4))->search(0x546d6d3035))->setBlackWhite(*(JUtility::TColor*)(this_ + 0x38), *(JUtility::TColor*)(this_ + 0x3c));
    for (i = 0; i < 6; i++) {
        fn_80402E08(*(void**)(this_ + 0x10 + i * 4), lbl_80543D78, *(f32*)(this_ + 0x40));
    }
    for (i = 0; i < 2; i++) {
        fn_80402E08(*(void**)(this_ + 0x28 + i * 4), lbl_80543D78, *(f32*)(this_ + 0x40));
    }
    this_[0x4d] = 0;
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

extern "C" void* __nw__FUl(u32 size);
extern "C" void fn_80402F04(void* a, void* b);
extern u8 lbl_80529DEC[];
extern "C" const char lbl_8048FBEC[];
extern "C" void* lbl_804AF86C[];
extern const f32 lbl_80543D70;
extern const f32 lbl_80543D74;
extern "C" void fn_80444B68(void* this_) {
    u8* self = (u8*)this_;
    void* p;
    void* font;
    void* tb;
    f32 base;
    u32 bits;
    u8 c18[4];
    u8 c14[4];
    u8 c10[4];
    u8 c0c[4];

    *(void**)self = lbl_804B1B60;
    *(s32*)(self + 0x30) = -1;
    *(s32*)(self + 0x34) = -1;
    *(s32*)(self + 0x38) = -1;
    *(s32*)(self + 0x3c) = -1;

    *(J2DScreen**)(self + 4) = new J2DScreen;
    ((J2DScreen*)*(void**)(self + 4))->setPriority(lbl_8048FBEC, 0x1100000, *(JKRArchive**)(lbl_80529DEC + 0x34));

    p = __nw__FUl(0x2c);
    if (p != 0) {
        *(void**)p = lbl_804AF86C;
        *(void**)(self + 8) = p;
        fn_80402F04(*(void**)(self + 8), ((J2DScreen*)*(void**)(self + 4))->search(0x004e646174613031ULL));
        fn_80402E08(*(void**)(self + 8), lbl_80543D78, lbl_80543D84);
    }
    *(u16*)(*(u8**)(self + 8) + 0x22) = 0;

    p = __nw__FUl(0x2c);
    if (p != 0) {
        *(void**)p = lbl_804AF86C;
        *(void**)(self + 0xc) = p;
        fn_80402F04(*(void**)(self + 0xc), ((J2DScreen*)*(void**)(self + 4))->search(0x000050626c61636bULL));
    }
    tb = *(void**)(*(u8**)(self + 0xc) + 4);
    ((void (*)(void*, s32))(*(void***)tb)[0x24 / 4])(tb, 0);
    *(u16*)(*(u8**)(self + 0xc) + 0x26) = 0;

    p = __nw__FUl(0x2c);
    if (p != 0) {
        *(void**)p = lbl_804AF86C;
        *(void**)(self + 0x10) = p;
        fn_80402F04(*(void**)(self + 0x10), ((J2DScreen*)*(void**)(self + 4))->search(0x00506f6375723031ULL));
    }
    p = __nw__FUl(0x2c);
    if (p != 0) {
        *(void**)p = lbl_804AF86C;
        *(void**)(self + 0x14) = p;
        fn_80402F04(*(void**)(self + 0x14), ((J2DScreen*)*(void**)(self + 4))->search(0x00506f6375723032ULL));
    }
    p = __nw__FUl(0x2c);
    if (p != 0) {
        *(void**)p = lbl_804AF86C;
        *(void**)(self + 0x18) = p;
        fn_80402F04(*(void**)(self + 0x18), ((J2DScreen*)*(void**)(self + 4))->search(0x00506f6375723033ULL));
    }
    p = __nw__FUl(0x2c);
    if (p != 0) {
        *(void**)p = lbl_804AF86C;
        *(void**)(self + 0x1c) = p;
        fn_80402F04(*(void**)(self + 0x1c), ((J2DScreen*)*(void**)(self + 4))->search(0x00506f6375723034ULL));
    }
    p = __nw__FUl(0x2c);
    if (p != 0) {
        *(void**)p = lbl_804AF86C;
        *(void**)(self + 0x20) = p;
        fn_80402F04(*(void**)(self + 0x20), ((J2DScreen*)*(void**)(self + 4))->search(0x00506f6375723035ULL));
    }
    p = __nw__FUl(0x2c);
    if (p != 0) {
        *(void**)p = lbl_804AF86C;
        *(void**)(self + 0x24) = p;
        fn_80402F04(*(void**)(self + 0x24), ((J2DScreen*)*(void**)(self + 4))->search(0x00506f6375723036ULL));
    }
    p = __nw__FUl(0x2c);
    if (p != 0) {
        *(void**)p = lbl_804AF86C;
        *(void**)(self + 0x28) = p;
        fn_80402F04(*(void**)(self + 0x28), ((J2DScreen*)*(void**)(self + 4))->search(0x0050746375723032ULL));
    }
    p = __nw__FUl(0x2c);
    if (p != 0) {
        *(void**)p = lbl_804AF86C;
        *(void**)(self + 0x2c) = p;
        fn_80402F04(*(void**)(self + 0x2c), ((J2DScreen*)*(void**)(self + 4))->search(0x0050746375723034ULL));
    }

    *(u8*)(*(u8**)(*(u8**)(self + 0x10) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(self + 0x14) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(self + 0x18) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(self + 0x1c) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(self + 0x20) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(self + 0x24) + 4) + 0xb0) = 0;

    tb = ((J2DScreen*)*(void**)(self + 4))->search(0x000000546d6d3035ULL);
    ((void (*)(u8*, void*))(*(void***)tb)[0xb0 / 4])(c18, tb);
    self[0x30] = c18[0];
    self[0x31] = c18[1];
    self[0x32] = c18[2];
    self[0x33] = c18[3];

    tb = ((J2DScreen*)*(void**)(self + 4))->search(0x000000546d6d3035ULL);
    ((void (*)(u8*, void*))(*(void***)tb)[0xb4 / 4])(c14, tb);
    self[0x34] = c14[0];
    self[0x35] = c14[1];
    self[0x36] = c14[2];
    self[0x37] = c14[3];

    tb = ((J2DScreen*)*(void**)(self + 4))->search(0x000000546d6d3033ULL);
    ((void (*)(u8*, void*))(*(void***)tb)[0xb0 / 4])(c10, tb);
    self[0x38] = c10[0];
    self[0x39] = c10[1];
    self[0x3a] = c10[2];
    self[0x3b] = c10[3];

    tb = ((J2DScreen*)*(void**)(self + 4))->search(0x000000546d6d3033ULL);
    ((void (*)(u8*, void*))(*(void***)tb)[0xb4 / 4])(c0c, tb);
    self[0x3c] = c0c[0];
    self[0x3d] = c0c[1];
    self[0x3e] = c0c[2];
    self[0x3f] = c0c[3];

    font = *(void**)((u8*)lbl_8053AD78 + 0x154);
    tb = ((J2DScreen*)*(void**)(self + 4))->search(0x000000546d6d3031ULL);
    ((void (*)(void*, void*))(*(void***)tb)[0x9c / 4])(tb, font);
    tb = ((J2DScreen*)*(void**)(self + 4))->search(0x000000546d6d3032ULL);
    ((void (*)(void*, void*))(*(void***)tb)[0x9c / 4])(tb, font);
    tb = ((J2DScreen*)*(void**)(self + 4))->search(0x000000546d6d3033ULL);
    ((void (*)(void*, void*))(*(void***)tb)[0x9c / 4])(tb, font);
    tb = ((J2DScreen*)*(void**)(self + 4))->search(0x000000546d6d3034ULL);
    ((void (*)(void*, void*))(*(void***)tb)[0x9c / 4])(tb, font);
    tb = ((J2DScreen*)*(void**)(self + 4))->search(0x000000546d6d3035ULL);
    ((void (*)(void*, void*))(*(void***)tb)[0x9c / 4])(tb, font);
    tb = ((J2DScreen*)*(void**)(self + 4))->search(0x000000546d6d3036ULL);
    ((void (*)(void*, void*))(*(void***)tb)[0x9c / 4])(tb, font);

    tb = ((J2DScreen*)*(void**)(self + 4))->search(0x000000546d6d3035ULL);
    base = *(f32*)((u8*)((J2DPane*)tb)->getBounds() + 4);
    tb = ((J2DScreen*)*(void**)(self + 4))->search(0x000000546d6d3033ULL);
    *(f32*)(self + 0x40) = *(f32*)((u8*)((J2DPane*)tb)->getBounds() + 4) - base;
    *(s32*)(self + 0x44) = 0;

    *(u32*)((u8*)lbl_8053AAF8 + 0xb4) = *(u32*)((u8*)lbl_8053AAF8 + 0xb4) * 0x19660d + 0x3c6ef35f;
    bits = (*(u32*)((u8*)lbl_8053AAF8 + 0xb4) >> 9) | 0x3f800000;
    *(s32*)(self + 0x48) = (s32)(lbl_80543D70 * (*(f32*)&bits - lbl_80543D74)) + 10;
    self[0x4c] = 0;
    self[0x4d] = 0;
}

extern "C" u8 lbl_804B1B00[];
extern "C" u8 lbl_8052CD00[];
extern "C" char memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[];
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" char memPool___30JASPoolAllocObject_9JAIStream[];
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*);
extern "C" char memPool___35JASPoolAllocObject_13JAISoundChild[];
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern "C" char memPool___27JASPoolAllocObject_6JAISeq[];
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*);
extern "C" char memPool___26JASPoolAllocObject_5JAISe[];
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;
extern "C" void __dt__18JASMemPool_5JAISeFv(void*);
extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __register_global_object(void*, void*, void*);
extern "C" void fn_80445338(void) {
    u8* base = lbl_8052CD00;
    u8* p = lbl_804B1B00;
    u8* dst = p + 0x30;
    *(FsaBlock48*)dst = *(FsaBlock48*)p;
    if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, base + 0x0);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, base + 0xc);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, base + 0x18);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, base + 0x24);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, base + 0x30);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, base + 0x3c);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, base + 0x48);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, base + 0x54);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, base + 0x60);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}

