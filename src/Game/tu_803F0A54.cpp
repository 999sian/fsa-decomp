#include "types.h"
struct FsaMenuActionBase { u32 unk_0[2]; };
struct FsaMenuAction : FsaMenuActionBase {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void setAction(u32*);
};
#include "JSystem/J2D/J2DPane.h"
#include "JSystem/J2D/J2DPicture.h"


extern "C" void* lbl_8053AD30;
extern "C" void* fn_80309C4C(void* a, s32 b, s32 c);
extern "C" void* fn_80309A9C(void* a, s32 b, s32 c);
extern "C" void fn_80403680(void* p);
extern "C" u8 lbl_80529DEC[];

extern "C" void fn_8043670C(void* p, s32 a);
extern "C" void fn_80431A9C(void* p, s32 a, u8 b, s32 c);
extern void* lbl_8053AEC0;
extern void* lbl_8053AF80;
extern "C" void fn_80436668(void* p);
extern "C" s32 fn_804366B8(void* p);
extern "C" void fn_80458880(void* p, s32 a, s32 b);
extern "C" u8* lbl_8053AAF8;
extern const f32 lbl_8054372C;
extern const f32 lbl_80543768;
extern const f32 lbl_80543770;
extern const f32 lbl_80543774;
extern const f32 lbl_80543778;
extern "C" void fn_80402E08(void* p, f32 a, f32 b);
extern const f32 lbl_80543730;
extern const f32 lbl_80543784;
extern const f32 lbl_80543788;
extern const f32 lbl_8054378C;
extern const f32 lbl_8054377C;
extern const f32 lbl_80543790;
extern const f32 lbl_805437AC;
extern const f32 lbl_80543764;
extern const f32 lbl_8054376C;
extern "C" void fn_80440EE8(void* p);
extern u8 lbl_80478A60[];
extern void* lbl_8053AED8;
extern void* lbl_8053AB10;
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(void*, f32, f32, void*);
struct T803FC46C;
typedef void (T803FC46C::*PMF803FC46C)();
extern PMF803FC46C lbl_804B0BDC[];

extern "C" void fn_803F1C18(u8* p) {
    fn_8043670C(*(void**)(p + 0x58), 1);
    *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
    *(s32*)(p + 0x1c4) = 0xc;
}

extern "C" void fn_803F1C5C(u8* p) {
    *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
    *(s32*)(p + 0x1c4) = 0xb;
}

extern "C" void fn_803F2580(u8* p) {
    s32 j = 0;
    s32 i;
    s32 k;
    u8* b;

    *(s16*)(p + 0x240) = 0;
    *(s32*)(p + 0x1d0) = 5;
    if (*(s32*)(p + 0x1a8) == 0) {
        i = 0;
        for (k = 0; k < 4; k++) {
            if (i < *(s32*)(p + 0x1ac) + 2) {
                lbl_8053AAF8[0x82] |= (u8)(1 << i);
                b = lbl_8053AAF8;
                b[0x83] &= ~(u8)(3 << j);
                b[0x83] |= (u8)(1 << j);
            } else {
                lbl_8053AAF8[0x82] &= ~(u8)(1 << i);
                lbl_8053AAF8[0x83] &= ~(u8)(3 << j);
            }
            j += 2;
            i++;
        }
    }
    *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
    *(s32*)(p + 0x1c4) = 9;
}

extern "C" void fn_803F2660(u8* p) {
    *(s16*)(p + 0x240) = 0;
    *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
    *(s32*)(p + 0x1c4) = 8;
}

extern "C" void* getStringPtr__10J2DTextBoxCFv(void* p);
extern "C" void fn_803832BC(void* p, s32 a, s32 b, s32 c, s32 d);
extern "C" void* fn_804031C4(s32 a, void* b);
extern "C" u8 lbl_80478A60[];
extern const f32 lbl_80543754;
extern const f32 lbl_8054375C;
extern const f32 lbl_80543760;
extern "C" void fn_803F267C(u8* p) {
    u8* base;
    void* s1;
    void* s2;
    void* s3;
    J2DPane* piVar4;

    base = lbl_80478A60;
    {
        void* o = *(void**)(p + 0xc);
        s1 = getStringPtr__10J2DTextBoxCFv((*(J2DPane**)(p + 0xc))->search(0x5468616e3031ULL));
    }
    {
        void* o = *(void**)(p + 0xc);
        s2 = getStringPtr__10J2DTextBoxCFv((*(J2DPane**)(p + 0xc))->search(0x547374613031ULL));
    }
    {
        void* o = *(void**)(p + 0xc);
        s3 = getStringPtr__10J2DTextBoxCFv((*(J2DPane**)(p + 0xc))->search(0x5472756c653031ULL));
    }
    fn_803832BC(s2, 0x11b, 0, 0, 0);
    fn_803832BC(s1, 0xac, 0, 0, 0);
    fn_803832BC(s3, 0xf7, 0, 0, 0);

    if (*(s32*)(p + 0x1ac) == 0) {
        const ResTIMG* image = (const ResTIMG*)fn_804031C4(0x54494d47, base + 0xf30);
        {
            void* o = *(void**)(p + 0xc);
            piVar4 = (*(J2DPane**)(p + 0xc))->search(0x506e6f703032ULL);
        }
        ((J2DPicture*)piVar4)->changeTexture(image, 0);
        {
            void* o = *(void**)(p + 0xc);
            piVar4 = (*(J2DPane**)(p + 0xc))->search(0x506e6f703031ULL);
        }
        ((J2DPicture*)piVar4)->changeTexture(image, 0);
    } else if (*(s32*)(p + 0x1ac) == 1) {
        const ResTIMG* image = (const ResTIMG*)fn_804031C4(0x54494d47, base + 0xf44);
        {
            void* o = *(void**)(p + 0xc);
            piVar4 = (*(J2DPane**)(p + 0xc))->search(0x506e6f703032ULL);
        }
        ((J2DPicture*)piVar4)->changeTexture(image, 0);
        {
            void* o = *(void**)(p + 0xc);
            piVar4 = (*(J2DPane**)(p + 0xc))->search(0x506e6f703031ULL);
        }
        ((J2DPicture*)piVar4)->changeTexture(image, 0);
    } else {
        const ResTIMG* image = (const ResTIMG*)fn_804031C4(0x54494d47, base + 0xf58);
        {
            void* o = *(void**)(p + 0xc);
            piVar4 = (*(J2DPane**)(p + 0xc))->search(0x506e6f703032ULL);
        }
        ((J2DPicture*)piVar4)->changeTexture(image, 0);
        {
            void* o = *(void**)(p + 0xc);
            piVar4 = (*(J2DPane**)(p + 0xc))->search(0x506e6f703031ULL);
        }
        ((J2DPicture*)piVar4)->changeTexture(image, 0);
    }

    *(f32*)(p + 0x164) = lbl_80543754;
    *(f32*)(p + 0x168) = lbl_80543754;
    *(f32*)(p + 0x184) = lbl_8054375C;
    *(f32*)(p + 0x188) = lbl_8054375C;
    *(f32*)(p + 0x18c) = lbl_8054375C;
    *(f32*)(p + 0x198) = lbl_80543760;

    {
        void* o = *(void**)(p + 0xc);
        piVar4 = (*(J2DPane**)(p + 0xc))->search(0x506d626162623037ULL);
    }
    piVar4->move(*(f32*)(p + 0x15c), *(f32*)(p + 0x160) + *(f32*)(p + 0x164));
    fn_80402E08(*(void**)(p + 0x74), lbl_8054372C, *(f32*)(p + 0x168));

    {
        void* o = *(void**)(p + 0xc);
        piVar4 = (*(J2DPane**)(p + 0xc))->search(0x50737461623034ULL);
    }
    piVar4->move(*(f32*)(p + 0x16c) + *(f32*)(p + 0x184), *(f32*)(p + 0x178));

    {
        void* o = *(void**)(p + 0xc);
        piVar4 = (*(J2DPane**)(p + 0xc))->search(0x5068616e623034ULL);
    }
    piVar4->move(*(f32*)(p + 0x170) + *(f32*)(p + 0x188), *(f32*)(p + 0x17c));

    {
        void* o = *(void**)(p + 0xc);
        piVar4 = (*(J2DPane**)(p + 0xc))->search(0x507275623034ULL);
    }
    piVar4->move(*(f32*)(p + 0x174) + *(f32*)(p + 0x18c), *(f32*)(p + 0x180));

    {
        void* o = *(void**)(p + 0xc);
        piVar4 = (*(J2DPane**)(p + 0xc))->search(0x506c69626b6b3033ULL);
    }
    piVar4->move(*(f32*)(p + 0x190) + *(f32*)(p + 0x198), *(f32*)(p + 0x194));

    *(s32*)(p + 0x1d0) = 0;
    *(s16*)(p + 0x240) = 0;
    *(s32*)(p + 0x210) = 0;
    *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
    *(s32*)(p + 0x1c4) = 7;
}

extern "C" void fn_803F2AEC(u8* p) {
    fn_80431A9C(lbl_8053AEC0, 0xc4, (u8)(*(s32*)(p + 0x1ac) + 2), 0);
    *(u8*)(p + 0x25c) = 0;
    *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
    *(s32*)(p + 0x1c4) = 6;
}

extern "C" void fn_803F2B48(u8* p) {
    *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
    *(s32*)(p + 0x1c4) = 5;
}

extern "C" void fn_803F2B5C(u8* p) {
    *(s16*)(p + 0x240) = 0;
    *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
    *(s32*)(p + 0x1c4) = 4;
}

extern "C" void fn_803F2B78(u8* p) {
    u8* base;
    u32* pt31;
    u32* pt30;
    u32* pt29;
    u32* pt28;
    u32* pt27;
    u32* pt26;
    u32* pt25;
    u8* q;
    s32 i;
    s32 j;
    u32* t20;
    void* uVar1;
    void* piVar;
    void* s1;
    void* s2;
    u8* sp;

    base = lbl_80478A60;
    if (*(s32*)(p + 0x1ac) == 0) {
        uVar1 = fn_804031C4(0x54494d47, base + 0xf30);
        piVar = ((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 8)))[15])(*(void**)(p + 8), 0x746e0000, 0x50, 0x746e3032);
        ((void (*)(void*, void*, s32))(*(void***)piVar)[68])(piVar, uVar1, 0);
        piVar = ((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 8)))[15])(*(void**)(p + 8), 0x746e0000, 0x50, 0x746e3031);
        ((void (*)(void*, void*, s32))(*(void***)piVar)[68])(piVar, uVar1, 0);
    } else if (*(s32*)(p + 0x1ac) == 1) {
        uVar1 = fn_804031C4(0x54494d47, base + 0xf44);
        piVar = ((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 8)))[15])(*(void**)(p + 8), 0x746e0000, 0x50, 0x746e3032);
        ((void (*)(void*, void*, s32))(*(void***)piVar)[68])(piVar, uVar1, 0);
        piVar = ((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 8)))[15])(*(void**)(p + 8), 0x746e0000, 0x50, 0x746e3031);
        ((void (*)(void*, void*, s32))(*(void***)piVar)[68])(piVar, uVar1, 0);
    } else {
        uVar1 = fn_804031C4(0x54494d47, base + 0xf58);
        piVar = ((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 8)))[15])(*(void**)(p + 8), 0x746e0000, 0x50, 0x746e3032);
        ((void (*)(void*, void*, s32))(*(void***)piVar)[68])(piVar, uVar1, 0);
        piVar = ((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 8)))[15])(*(void**)(p + 8), 0x746e0000, 0x50, 0x746e3031);
        ((void (*)(void*, void*, s32))(*(void***)piVar)[68])(piVar, uVar1, 0);
    }

    piVar = ((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 8)))[15])(*(void**)(p + 8), 0x6b670000, 0x5474, 0x6b673031);
    s1 = getStringPtr__10J2DTextBoxCFv(piVar);
    piVar = ((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 8)))[15])(*(void**)(p + 8), 0x6b670000, 0x5474, 0x6b673032);
    s2 = getStringPtr__10J2DTextBoxCFv(piVar);
    fn_803832BC(s1, 0x3f, 0, 0, 0);
    fn_803832BC(s2, 0x3f, 0, 0, 0);

    *(f32*)(p + 0x9c) = lbl_80543764;
    piVar = ((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 8)))[15])(*(void**)(p + 8), 0x74610000, 0x4e6461, 0x74613033);
    ((void (*)(void*, f32, f32))(*(void***)piVar)[4])(piVar, *(f32*)(p + 0x94), *(f32*)(p + 0x98) + *(f32*)(p + 0x9c));

    *(f32*)(p + 0xa8) = lbl_80543768;
    piVar = ((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 8)))[15])(*(void**)(p + 8), 0x74610000, 0x4e6461, 0x74613035);
    ((void (*)(void*, f32, f32))(*(void***)piVar)[4])(piVar, *(f32*)(p + 0xa0), *(f32*)(p + 0xa4) + *(f32*)(p + 0xa8));

    *(f32*)(p + 0xb4) = lbl_80543754;
    piVar = ((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 8)))[15])(*(void**)(p + 8), 0x74610000, 0x4e6461, 0x74613036);
    ((void (*)(void*, f32, f32))(*(void***)piVar)[4])(piVar, *(f32*)(p + 0xac), *(f32*)(p + 0xb0) + *(f32*)(p + 0xb4));

    *(f32*)(p + 0xb8) = lbl_80543754;
    fn_80402E08(*(void**)(p + 0x74), lbl_8054372C, *(f32*)(p + 0xb8));

    *(f32*)(p + 0xdc) = lbl_8054376C;
    piVar = ((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 8)))[15])(*(void**)(p + 8), 0x626b0000, 0x50706c6c, 0x626b3032);
    ((void (*)(void*, f32, f32))(*(void***)piVar)[4])(piVar, *(f32*)(p + 0xbc), *(f32*)(p + 0xcc) + *(f32*)(p + 0xdc));

    *(f32*)(p + 0xe0) = lbl_8054376C;
    piVar = ((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 8)))[15])(*(void**)(p + 8), 0x626b0000, 0x50706c6c, 0x626b3132);
    ((void (*)(void*, f32, f32))(*(void***)piVar)[4])(piVar, *(f32*)(p + 0xc0), *(f32*)(p + 0xd0) + *(f32*)(p + 0xe0));

    *(f32*)(p + 0xe4) = lbl_8054376C;
    piVar = ((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 8)))[15])(*(void**)(p + 8), 0x626b0000, 0x50706c6c, 0x626b3232);
    ((void (*)(void*, f32, f32))(*(void***)piVar)[4])(piVar, *(f32*)(p + 0xc4), *(f32*)(p + 0xd4) + *(f32*)(p + 0xe4));

    *(f32*)(p + 0xe8) = lbl_8054376C;
    piVar = ((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 8)))[15])(*(void**)(p + 8), 0x626b0000, 0x50706c6c, 0x626b3332);
    ((void (*)(void*, f32, f32))(*(void***)piVar)[4])(piVar, *(f32*)(p + 0xc8), *(f32*)(p + 0xd8) + *(f32*)(p + 0xe8));

    q = p;
    pt30 = (u32*)(base + 0x7f8);
    pt29 = (u32*)(base + 0x818);
    pt28 = (u32*)(base + 0x838);
    pt27 = (u32*)(base + 0x858);
    pt26 = (u32*)(base + 0x898);
    pt25 = (u32*)(base + 0x878);
    pt31 = (u32*)(base + 0x918);
    for (i = 0; i < 4; i++) {
        if (*(s32*)(p + 0x1ac) + 1 < i) {
            sp = (u8*)((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 8)))[15])(*(void**)(p + 8), 0x626b0000, pt30[0], pt30[1]);
            sp[0xb0] = 0;
            sp = (u8*)((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 8)))[15])(*(void**)(p + 8), 0x626b0000, pt29[0], pt29[1]);
            sp[0xb0] = 0;
            sp = (u8*)((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 8)))[15])(*(void**)(p + 8), 0x626b0000, pt28[0], pt28[1]);
            sp[0xb0] = 0;
            sp = (u8*)((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 8)))[15])(*(void**)(p + 8), 0x626b0000, pt27[0], pt27[1]);
            sp[0xb0] = 0;
            t20 = pt26 + 4;
            for (j = 2; j < 4; j++) {
                sp = (u8*)((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 8)))[15])(*(void**)(p + 8), 0x626b0000, t20[0], t20[1]);
                sp[0xb0] = 0;
                t20 += 2;
            }
            piVar = ((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 8)))[15])(*(void**)(p + 8), 0x626b0000, pt25[0], pt25[1]);
            ((void (*)(void*, s32))(*(void***)piVar)[9])(piVar, 0x80);
            *(s32*)(q + 0x220) = 0;
            *(s32*)(q + 0x230) = 0;
        } else {
            sp = (u8*)((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 8)))[15])(*(void**)(p + 8), 0x626b0000, pt30[0], pt30[1]);
            sp[0xb0] = 1;
            sp = (u8*)((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 8)))[15])(*(void**)(p + 8), 0x626b0000, pt29[0], pt29[1]);
            sp[0xb0] = 1;
            sp = (u8*)((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 8)))[15])(*(void**)(p + 8), 0x626b0000, pt28[0], pt28[1]);
            sp[0xb0] = 1;
            sp = (u8*)((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 8)))[15])(*(void**)(p + 8), 0x626b0000, pt27[0], pt27[1]);
            sp[0xb0] = 1;
            t20 = pt26 + 4;
            for (j = 2; j < 4; j++) {
                sp = (u8*)((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 8)))[15])(*(void**)(p + 8), 0x626b0000, t20[0], t20[1]);
                sp[0xb0] = 1;
                t20 += 2;
            }
            piVar = ((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 8)))[15])(*(void**)(p + 8), 0x626b0000, pt25[0], pt25[1]);
            ((void (*)(void*, s32))(*(void***)piVar)[9])(piVar, 0xff);
            *(s32*)(q + 0x220) = *(s16*)(*(u8**)(q + 0x38) + 6);
            *(s32*)(q + 0x230) = *(s16*)(*(u8**)(q + 0x48) + 6);
        }
        sp = (u8*)((void* (*)(void*, u32, u32, u32))(*(void***)(*(void**)(p + 8)))[15])(*(void**)(p + 8), 0x626b0000, pt31[0], pt31[1]);
        sp[0xb0] = 0;
        q += 4;
        pt30 += 2;
        pt29 += 2;
        pt28 += 2;
        pt27 += 2;
        pt26 += 8;
        pt25 += 2;
        pt31 += 2;
    }

    *(s16*)(p + 0x240) = 0;
    *(s16*)(p + 0x248) = 0;
    *(s16*)(p + 0x24a) = 0;
    *(u8*)(p + 0x25b) = 0;
    *(s16*)(p + 0x24e) = -1;
    *(s16*)(p + 0x250) = -1;
    *(s32*)(p + 0x210) = 0;
    *(s32*)(p + 0x214) = 0;
    *(s32*)(p + 0x218) = 0;
    *(s32*)(p + 0x21c) = 0;
    *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
    *(s32*)(p + 0x1c4) = 3;
}

extern "C" void fn_803F32E8(u8* p) {
    *(s32*)(p + 0x210) = 0;
    *(s16*)(p + 0x240) = 0;
    *(s32*)(p + 0x1d0) = 5;
    *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
    *(s32*)(p + 0x1c4) = 2;
}

extern "C" void fn_803F3310(u8* p) {
    *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
    *(s32*)(p + 0x1c4) = 1;
}

extern "C" void fn_803F3324(u8* p) {
    void* obj;

    *(f32*)(p + 0x110) = lbl_80543770;
    obj = ((void* (*)(void*, u32, u32, u32))(**(void****)(p + 4))[15])(*(void**)(p + 4), 0x62620000, 0x506d6261, 0x62623037);
    ((void (*)(void*, f32, f32))(*(void***)obj)[4])(obj, *(f32*)(p + 0x108), *(f32*)(p + 0x10c) + *(f32*)(p + 0x110));
    *(f32*)(p + 0x114) = lbl_80543768;
    fn_80402E08(*(void**)(p + 0x74), lbl_8054372C, *(f32*)(p + 0x114));

    *(f32*)(p + 0x130) = lbl_80543774;
    obj = ((void* (*)(void*, u32, u32, u32))(**(void****)(p + 4))[15])(*(void**)(p + 4), 0x70620000, 0x506e6f, 0x70623038);
    ((void (*)(void*, f32, f32))(*(void***)obj)[4])(obj, *(f32*)(p + 0x118) + *(f32*)(p + 0x130), *(f32*)(p + 0x124));
    *(f32*)(p + 0x134) = lbl_80543774;
    obj = ((void* (*)(void*, u32, u32, u32))(**(void****)(p + 4))[15])(*(void**)(p + 4), 0x70620000, 0x506e6f, 0x70623132);
    ((void (*)(void*, f32, f32))(*(void***)obj)[4])(obj, *(f32*)(p + 0x11c) + *(f32*)(p + 0x134), *(f32*)(p + 0x128));
    *(f32*)(p + 0x138) = lbl_80543774;
    obj = ((void* (*)(void*, u32, u32, u32))(**(void****)(p + 4))[15])(*(void**)(p + 4), 0x70620000, 0x506e6f, 0x70623136);
    ((void (*)(void*, f32, f32))(*(void***)obj)[4])(obj, *(f32*)(p + 0x120) + *(f32*)(p + 0x138), *(f32*)(p + 0x12c));
    *(f32*)(p + 0x144) = lbl_80543778;
    obj = ((void* (*)(void*, u32, u32, u32))(**(void****)(p + 4))[15])(*(void**)(p + 4), 0x74610000, 0x4e6461, 0x74613032);
    ((void (*)(void*, f32, f32))(*(void***)obj)[4])(obj, *(f32*)(p + 0x13c) + *(f32*)(p + 0x144), *(f32*)(p + 0x140));
    *(f32*)(p + 0x158) = lbl_80543778;
    obj = ((void* (*)(void*, u32, u32, u32))(**(void****)(p + 4))[15])(*(void**)(p + 4), 0x74610000, 0x4e6461, 0x74613035);
    ((void (*)(void*, f32, f32))(*(void***)obj)[4])(obj, *(f32*)(p + 0x148) + *(f32*)(p + 0x158), *(f32*)(p + 0x14c));
    obj = ((void* (*)(void*, u32, u32, u32))(**(void****)(p + 4))[15])(*(void**)(p + 4), 0x4e0000, 0x4e6461, 0x74613037);
    ((void (*)(void*, f32, f32))(*(void***)obj)[4])(obj, *(f32*)(p + 0x150) + *(f32*)(p + 0x158), *(f32*)(p + 0x154));

    *(s32*)(p + 0x210) = 0;
    *(s32*)(p + 0x1d0) = 0;
    *(s16*)(p + 0x240) = 0;
    *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
    *(s32*)(p + 0x1c4) = 0;
}

extern "C" void fn_803F358C(u8* p) {
    fn_80436668(*(void**)(p + 0x58));
}

extern const f32 lbl_80543780;
extern "C" void* getBounds__7J2DPaneFv(void* p);
extern "C" void fn_803F35B0(u8* p) {
    u8* base;
    u8* q4;
    u32* pt30;
    u32* pt29;
    u32* pt28;
    u8* q2;
    s32 i;
    s32 v;
    s32 t;
    f32 f31;
    f32 f30;
    f32* bounds;
    void* obj;
    void* pane;

    base = lbl_80478A60;
    pt30 = (u32*)(base + 0x978);
    pt29 = (u32*)(base + 0x998);
    pt28 = (u32*)(base + 0x9b8);
    q4 = p;
    q2 = p;
    for (i = 0; i < 4; i++) {
        v = *(s32*)(q4 + 0x1d0);
        if (v < 30) {
            f31 = (f32)(v * v) / lbl_8054377C;
        } else {
            f31 = lbl_80543730 - (f32)((v - 30) * (v - 30)) / lbl_8054377C;
        }
        if (i <= *(s32*)(p + 0x1ac) + 1) {
            if (*(s32*)(q4 + 0x1b0) < 4) {
                obj = *(void**)(p + 0x10);
                pane = ((void* (*)(void*, s32, u32, u32))(*(void***)obj)[15])(obj, 0, pt30[0], pt30[1]);
                ((void (*)(void*, s32))(*(void***)pane)[9])(pane, (s32)(lbl_80543780 * f31));
            }
            if (*(s32*)(q4 + 0x1b0) == 3) {
                obj = *(void**)(p + 0x10);
                pane = ((void* (*)(void*, s32, u32, u32))(*(void***)obj)[15])(obj, 0, pt29[0], pt29[1]);
                ((void (*)(void*, s32))(*(void***)pane)[9])(pane, (s32)(f31 * (f32)*(u8*)(p + 0x25a)));
                obj = *(void**)(p + 0x10);
                pane = ((void* (*)(void*, s32, u32, u32))(*(void***)obj)[15])(obj, 0, pt28[0], pt28[1]);
                ((void (*)(void*, s32))(*(void***)pane)[9])(pane, (s32)(f31 * (f32)*(u8*)(p + 0x25a)));
            }
        }
        if (*(s32*)(p + 0x1c4) != 0xa) {
            t = *(s16*)(q2 + 0x240);
            if (t >= 5) {
                t = 10 - t;
            }
            f30 = (lbl_80543784 * (f32)(t * t)) / lbl_80543788;
            obj = *(void**)(p + 0x10);
            pane = ((void* (*)(void*, s32, u32, u32))(*(void***)obj)[15])(obj, t * t, pt29[0], pt29[1]);
            bounds = (f32*)getBounds__7J2DPaneFv(pane);
            f31 = *bounds;
            obj = *(void**)(p + 0x10);
            pane = ((void* (*)(void*, s32, u32, u32))(*(void***)obj)[15])(obj, 0, pt29[0], pt29[1]);
            ((void (*)(void*, f32, f32))(*(void***)pane)[4])(pane, f31, *(f32*)(p + 0x1a0) + f30);
            if (*(s32*)(q4 + 0x1b0) >= 3) {
                fn_80402E08(*(void**)(q4 + 0x64), lbl_8054372C, f30);
            }
        }
        q4 += 4;
        q2 += 2;
        pt30 += 2;
        pt29 += 2;
        pt28 += 2;
    }
    draw__9J2DScreenFffPC14J2DGrafContext(*(void**)(p + 0x10), lbl_8054372C, lbl_8054372C, *(void**)((u8*)lbl_8053AB10 + 0x10));
    fn_80440EE8(lbl_8053AED8);
}

extern "C" void fn_803F5410(u8* p) {
    u8* base = lbl_80478A60;
    u8* q = p;
    s32 state = *(s32*)(p + 0x1c4);
    s32 x = *(s32*)(p + 0x1d0);
    f32 f30;
    f32 f3;
    if (state != 2) {
        if (x < 0x1e) {
            f3 = (f32)(s32)(x * x) / lbl_8054377C;
        } else {
            f3 = lbl_80543730 - (f32)(s32)((x - 0x1e) * (x - 0x1e)) / lbl_8054377C;
        }
        f30 = f3 * (f32)*(u8*)(p + 0x258);
    } else {
        if (x < 0xf) {
            f3 = (f32)(s32)(x * x) / lbl_8054378C;
        } else {
            f3 = lbl_80543730 - (f32)(s32)((x - 0xf) * (x - 0xf)) / lbl_8054378C;
        }
        f30 = lbl_80543790 * f3;
    }
    s32 r0;
    if (state == 1 || (state == 2 && *(s16*)(p + 0x240) <= 10)) {
        r0 = *(s16*)(p + 0x240);
        if (r0 >= 5) {
            r0 = 10 - r0;
        }
    } else {
        r0 = 0;
    }
    f32 f31 = lbl_805437AC * f3;
    f32 f27 = lbl_80543784 * (f32)(s32)(r0 * r0) / lbl_80543788;
    u64* a = (u64*)(base + 0xe60);
    u64* b = (u64*)(base + 0xe78);
    u64* c = (u64*)(base + 0xe90);
    f32 f28;
    f32 f29;
    for (s32 i = 0; i < 3; i++, q += 4) {
        if (i == *(s32*)(p + 0x1ac)) {
            f28 = ((J2DPane*)*(void**)(p + 4))->search(a[i])->getBounds()->i.x;
            ((J2DPane*)*(void**)(p + 4))->search(a[i])->move(f28, *(f32*)(q + 0x124) + f27);
            if (i == 0) {
                f28 = ((J2DPane*)*(void**)(p + 4))->search(0x50736375726f3032ULL)->getBounds()->i.x;
                ((J2DPane*)*(void**)(p + 4))->search(0x50736375726f3032ULL)->move(f28, *(f32*)(p + 0xf0) + f27);
            } else {
                f28 = ((J2DPane*)*(void**)(p + 4))->search(a[0])->getBounds()->i.y;
                f32 t = ((J2DPane*)*(void**)(p + 4))->search(a[i])->getBounds()->i.y;
                f28 = (*(f32*)(p + 0xf0) + t) - f28;
                f29 = ((J2DPane*)*(void**)(p + 4))->search(0x50736375726f3032ULL)->getBounds()->i.x;
                ((J2DPane*)*(void**)(p + 4))->search(0x50736375726f3032ULL)->move(f29, f28);
            }
            ((u8*)((J2DPane*)*(void**)(p + 4))->search(b[i]))[0xb0] = 0;
            ((u8*)((J2DPane*)*(void**)(p + 4))->search(c[i]))[0xb0] = 1;
            ((J2DPane*)*(void**)(p + 4))->search(c[i])->setAlpha((u8)f31);
        } else {
            f29 = ((J2DPane*)*(void**)(p + 4))->search(a[i])->getBounds()->i.x;
            ((J2DPane*)*(void**)(p + 4))->search(a[i])->move(f29, *(f32*)(q + 0x124));
            ((u8*)((J2DPane*)*(void**)(p + 4))->search(b[i]))[0xb0] = 1;
            ((u8*)((J2DPane*)*(void**)(p + 4))->search(c[i]))[0xb0] = 0;
        }
    }
    ((J2DPane*)*(void**)(p + 4))->search(0x50736375726f3031ULL)->setAlpha((u8)f30);
    ((J2DPane*)*(void**)(p + 4))->search(0x50736375726f3032ULL)->setAlpha((u8)f30);
    draw__9J2DScreenFffPC14J2DGrafContext(*(void**)(p + 4), lbl_8054372C, lbl_8054372C, ((void**)lbl_8053AB10)[4]);
    fn_80440EE8(lbl_8053AED8);
}

extern "C" void fn_803F59A0(u8* p) {
    if (fn_804366B8(*(void**)(p + 0x58))) {
        if (p[0x25e] == 0) {
            *(s32*)(p + 0x1cc) = 7;
            p[0x25e] = 1;
        }
        *(s32*)(p + 0x1a8) = 0;
        fn_80458880(lbl_8053AF80, 0xb, -1);
    }
}

extern "C" u8 fn_80402940(void* p, s32 a, f32 x, f32 y, s32 b);
extern "C" void fn_803F715C(u8* p) {
    s32 t;
    u8* q;
    u8 a;
    u8 b;
    u8 c;
    s32 i;

    a = 0;
    b = 0;
    c = 0;
    *(s16*)(p + 0x24c) = *(s16*)(p + 0x24c) + 1;
    if (*(s16*)(p + 0x24c) > 0) {
        a = fn_80402940(*(void**)(p + 0x60), 0x16, -200.0f, 0.0f, 0);
    }
    if (*(s16*)(p + 0x24c) > 0x10) {
        b = fn_80402940(*(void**)(p + 0x74), 0x18, -200.0f, 0.0f, 0);
    }
    q = p;
    i = 0;
    t = 4;
    for (; i < 4; i++, q += 4) {
        if (i <= *(s32*)(p + 0x1ac) + 1 && *(s16*)(p + 0x24c) > t) {
            c = fn_80402940(*(void**)(q + 0x64), 0x12, 150.0f, 0.0f, 0);
        }
        t += 5;
    }
    if (a != 0 && b != 0 && c != 0) {
        *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
        *(s32*)(p + 0x1c4) = 0xb;
    }
}

extern "C" void fn_803F8050(u8* p) {
    s32 t = *(s16*)(p + 0x240);

    if (t != 0) {
        *(s16*)(p + 0x240) = t + 1;
        if (*(s16*)(p + 0x240) > 10) {
            *(s16*)(p + 0x240) = 0;
        }
    }
    *(s32*)(p + 0x210) = *(s32*)(p + 0x210) + 1;
    if (*(s32*)(p + 0x210) >= 0x1e) {
        *(s32*)(p + 0x210) = 0;
    }
    if (*(s32*)(p + 0x1c0) != *(s32*)(p + 0x1ac) + 2) {
        *(u8*)(p + 0x25c) = 0xff;
        (((T803FC46C*)p)->*lbl_804B0BDC[3])();
    } else {
        u8* q = lbl_80529DEC;
        if (fn_80309C4C(lbl_8053AD30, 0x1100, q[0x23d] + 2) != 0) {
            if (*(s32*)(p + 0x1a8) < 3) {
                *(s32*)(p + 0x1cc) = 0xd;
                *(s16*)(p + 0x240) = 0;
                *(s32*)(p + 0x1d0) = 5;
                if (*(s32*)(p + 0x1a8) == 0) {
                    s32 i = 0;
                    s32 j = 0;
                    s32 k;
                    u8* b;
                    for (k = 0; k < 4; k++) {
                        if (i < *(s32*)(p + 0x1ac) + 2) {
                            lbl_8053AAF8[0x82] |= (u8)(1 << i);
                            b = lbl_8053AAF8;
                            b[0x83] &= ~(u8)(3 << j);
                            b[0x83] |= (u8)(1 << j);
                        } else {
                            lbl_8053AAF8[0x82] &= ~(u8)(1 << i);
                            lbl_8053AAF8[0x83] &= ~(u8)(3 << j);
                        }
                        j += 2;
                        i++;
                    }
                }
                *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
                *(s32*)(p + 0x1c4) = 9;
            }
            fn_80458880(lbl_8053AF80, 0xb, -1);
        } else if (fn_80309C4C(lbl_8053AD30, 0x200, q[0x23d] + 2) != 0) {
            *(s32*)(p + 0x1cc) = 0;
            (((T803FC46C*)p)->*lbl_804B0BDC[9])();
            fn_80458880(lbl_8053AF80, 0xc, -1);
        } else if (fn_80309A9C(lbl_8053AD30, 4, q[0x23d] + 2) != 0) {
            *(s32*)(p + 0x1a8) = *(s32*)(p + 0x1a8) + 1;
            if (*(s32*)(p + 0x1a8) >= 3) {
                *(s32*)(p + 0x1a8) = 0;
            }
            *(s16*)(p + 0x240) = 1;
            *(s32*)(p + 0x1d0) = 0x1e;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        } else if (fn_80309A9C(lbl_8053AD30, 8, q[0x23d] + 2) != 0) {
            *(s32*)(p + 0x1a8) = *(s32*)(p + 0x1a8) - 1;
            if (*(s32*)(p + 0x1a8) < 0) {
                *(s32*)(p + 0x1a8) = 2;
            }
            *(s16*)(p + 0x240) = 1;
            *(s32*)(p + 0x1d0) = 0x1e;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    }
    *(s32*)(p + 0x1d0) = *(s32*)(p + 0x1d0) + 1;
    if (*(s32*)(p + 0x1d0) >= 0x3c) {
        *(s32*)(p + 0x1d0) = 0;
    }
}

extern "C" s32 fn_804317AC(void* p);
extern "C" s32 fn_80431740(void* p);
extern "C" void fn_8013CC50(s32 a, f32* v, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, f32 h);
extern "C" u8* sManager__8JUTVideo;
extern "C" const u64 lbl_80479238[];
extern const f32 lbl_80543720;
extern const f32 lbl_80543728;
extern const f32 lbl_80543730;
extern const f32 lbl_805437A4;
extern const f32 lbl_805437C8;
extern const f32 lbl_805437CC;
extern const f32 lbl_805437A0;
extern "C" void fn_803F8FBC(u8* p) {
    s32 i;
    f32 span;
    void* r;
    u32 t1;
    u32 t2;
    JGeometry::TVec3f v1;
    JGeometry::TVec3f v2;

    switch (p[0x25c]) {
    case 0:
        if (fn_804317AC(lbl_8053AEC0)) {
            p[0x25c] = 1;
        }
        break;
    case 2:
        if (fn_80431740(lbl_8053AEC0)) {
            p[0x25c] = 0;
            *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
            *(s32*)(p + 0x1c4) = 5;
        }
        break;
    case 3:
        if (fn_80431740(lbl_8053AEC0)) {
            p[0x25c] = 0;
            *(s32*)(p + 0x350) = 2;
        }
        break;
    default:
        if (*(s32*)(p + 0x1c0) == *(s32*)(p + 0x1ac) + 2) {
            p[0x25c] = 2;
            fn_80458880(lbl_8053AF80, 0xb, -1);
        } else {
            if (fn_80309C4C(lbl_8053AD30, 0x1100, lbl_80529DEC[0x23d] + 2)) {
                p[0x25c] = 2;
                fn_80458880(lbl_8053AF80, 0xb, -1);
            } else if (fn_80309C4C(lbl_8053AD30, 0x200, lbl_80529DEC[0x23d] + 2)) {
                p[0x25c] = 2;
                fn_80458880(lbl_8053AF80, 0xc, -1);
            }
        }
        break;
    }

    *(s16*)(p + 0x248) += 1;
    if (*(s16*)(p + 0x248) >= 100) {
        *(s16*)(p + 0x248) = 0;
    }
    *(s16*)(p + 0x24a) += 1;
    if (*(s16*)(p + 0x24a) >= 100) {
        *(s16*)(p + 0x24a) = 0;
    }

    for (i = 0; i < 4; i++) {
        if (lbl_8053AAF8[0x82] & (u8)(1 << (i + 4))) {
            *(s32*)(p + i * 4 + 0x210) += 1;
            if (*(s32*)(p + i * 4 + 0x210) >= 0x82) {
                *(s32*)(p + i * 4 + 0x210) = 0x64;
            }
            if (*(s32*)(p + i * 4 + 0x210) == 0xb) {
                ((u8*)*(void**)(p + i * 4 + 0x78))[0x44] = 0;
                ((u8*)*(void**)(p + i * 4 + 0x78))[0x45] = 0;
                t1 = 0x10001;
                (*(FsaMenuAction**)(p + i * 4 + 0x78))->setAction(&t1);
            } else if (*(s32*)(p + i * 4 + 0x210) == 0x24) {
                r = (*(J2DPane**)(p + 8))->search(lbl_80479238[i]);
                span = *(f32*)((u8*)r + 0x28) - *(f32*)((u8*)r + 0x20);
                r = (*(J2DPane**)(p + 8))->search(lbl_80479238[i]);
                *(f32*)(p + 0x88) = (lbl_805437A0 * (span * lbl_80543720 + *(f32*)((u8*)r + 0x30))) /
                                    (f32)(s32)*(u16*)(*(u8**)(sManager__8JUTVideo + 4) + 4);
                r = (*(J2DPane**)(p + 8))->search(lbl_80479238[i]);
                span = *(f32*)((u8*)r + 0x2c) - *(f32*)((u8*)r + 0x24);
                r = (*(J2DPane**)(p + 8))->search(lbl_80479238[i]);
                *(f32*)(p + 0x8c) = (lbl_805437A4 * (lbl_80543728 + (span * lbl_80543720 + *(f32*)((u8*)r + 0x34)))) /
                                    (f32)(s32)*(u16*)(*(u8**)(sManager__8JUTVideo + 4) + 6);
                *(f32*)(p + 0x90) = lbl_8054372C;
                ((u8*)*(void**)(p + i * 4 + 0x78))[0x44] = 0;
                ((u8*)*(void**)(p + i * 4 + 0x78))[0x45] = 0;
                t2 = 0x2000E;
                (*(FsaMenuAction**)(p + i * 4 + 0x78))->setAction(&t2);
                v1.set(lbl_805437CC + *(f32*)(p + 0x88), *(f32*)(p + 0x8c) - lbl_805437C8, *(f32*)(p + 0x90));
                fn_8013CC50(0, &v1.x, 0xcb, 1, 0, 0, 0, 1, lbl_80543730);
                v2.set(lbl_805437CC + *(f32*)(p + 0x88), *(f32*)(p + 0x8c) - lbl_805437C8, *(f32*)(p + 0x90));
                fn_8013CC50(0, &v2.x, 0xcc, 1, 0, 0, 0, 1, lbl_80543730);
            }
        } else {
            *(s32*)(p + i * 4 + 0x210) = 0;
        }
    }
}

extern "C" void fn_803FB6F4(u8* p) {
    s32 j;
    s32 i;
    u8* cfg;
    u8* flags;

    if ((s32)*(s16*)(p + 0x240) != 0) {
        *(s16*)(p + 0x240) = *(s16*)(p + 0x240) + 1;
        if (*(s16*)(p + 0x240) > 10) {
            *(s16*)(p + 0x240) = 0;
        }
    }
    *(s32*)(p + 0x210) = *(s32*)(p + 0x210) + 1;
    if (*(s32*)(p + 0x210) >= 0x1e) {
        *(s32*)(p + 0x210) = 0;
    }
    if (fn_80309C4C(lbl_8053AD30, 0x1100, 1) != 0) {
        j = 0;
        *(s32*)(p + 0x1a8) = 0;
        lbl_8053AAF8[0x7e] = 1;
        if (*(s32*)(p + 0x1c0) == *(s32*)(p + 0x1ac) + 2) {
            for (i = 0; i < 4; j += 2, i++) {
                if (i < *(s32*)(p + 0x1ac) + 2) {
                    lbl_8053AAF8[0x82] |= (u8)(1 << i);
                    flags = lbl_8053AAF8;
                    flags[0x83] &= ~(u8)(3 << j);
                    flags[0x83] |= (u8)(1 << j);
                } else {
                    lbl_8053AAF8[0x82] &= ~(u8)(1 << i);
                    flags = lbl_8053AAF8;
                    flags[0x83] &= ~(u8)(3 << j);
                }
            }
            *(s32*)(p + 0x1cc) = 0xd;
        }
        *(s32*)(p + 0x210) = 0;
        *(s16*)(p + 0x240) = 0;
        *(s32*)(p + 0x1d0) = 5;
        *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
        *(s32*)(p + 0x1c4) = 2;
        cfg = lbl_80529DEC;
        if (*(s32*)(p + 0x1ac) != cfg[0x23d]) {
            *(s32*)(cfg + 0x140) = 0;
            *(s32*)(cfg + 0x144) = 0;
            *(s32*)(cfg + 0x148) = 0;
            *(s32*)(cfg + 0x14c) = 0;
            *(s32*)(cfg + 0x64) = -1;
            fn_80403680(cfg);
        }
        cfg[0x23d] = *(s32*)(p + 0x1ac);
        fn_80458880(lbl_8053AF80, 0xb, -1);
    } else if (fn_80309C4C(lbl_8053AD30, 0x200, 1) != 0) {
        *(s32*)(p + 0x350) = 2;
        fn_80458880(lbl_8053AF80, 0xc, -1);
    } else if (fn_80309A9C(lbl_8053AD30, 4, 1) != 0) {
        *(s32*)(p + 0x1ac) = *(s32*)(p + 0x1ac) + 1;
        if (*(s32*)(p + 0x1ac) >= 3) {
            *(s32*)(p + 0x1ac) = 0;
        }
        *(s16*)(p + 0x240) = 1;
        *(s32*)(p + 0x1d0) = 0x1e;
        fn_80458880(lbl_8053AF80, 0x26, -1);
    } else if (fn_80309A9C(lbl_8053AD30, 8, 1) != 0) {
        *(s32*)(p + 0x1ac) = *(s32*)(p + 0x1ac) - 1;
        if (*(s32*)(p + 0x1ac) < 0) {
            *(s32*)(p + 0x1ac) = 2;
        }
        *(s16*)(p + 0x240) = 1;
        *(s32*)(p + 0x1d0) = 0x1e;
        fn_80458880(lbl_8053AF80, 0x26, -1);
    }
    *(s32*)(p + 0x1d0) = *(s32*)(p + 0x1d0) + 1;
    if (*(s32*)(p + 0x1d0) >= 0x3c) {
        *(s32*)(p + 0x1d0) = 0;
    }
}

extern "C" void fn_80456154(void* p);
extern "C" s32 fn_8030AAF4(s32 i);
extern "C" u8 fn_8030A308(void* a, s32 b);
extern "C" void* lbl_8053AD30;
struct T803FC304;
typedef void (T803FC304::*PMF803FC304)();
extern PMF803FC304 lbl_804B0D14[];
extern "C" void fn_803FC304(u8* p) {
    s32 i;

    *(s32*)(p + 0x1c0) = 0;
    for (i = 0; i < 4; i++) {
        if (i <= *(s32*)(p + 0x1ac) + 1) {
            if (fn_8030A308(lbl_8053AD30, fn_8030AAF4(i))) {
                lbl_8053AAF8[0x82] |= (u8)(1 << (i + 4));
                *(s32*)(p + 0x1c0) += 1;
            } else {
                lbl_8053AAF8[0x82] &= ~(u8)(1 << (i + 4));
            }
        } else {
            lbl_8053AAF8[0x82] &= ~(u8)(1 << (i + 4));
        }
    }
    if (p[0x25e] == 0 || *(s32*)(p + 0x1c4) == 4) {
        if (*(s32*)(p + 0x1c4) != 0xd) {
            (((T803FC304*)p)->*lbl_804B0D14[*(s32*)(p + 0x1c4)])();
        } else {
            (((T803FC304*)p)->*lbl_804B0D14[*(s32*)(p + 0x1c8)])();
        }
        for (i = 0; i < 4; i++, p += 4) {
            fn_80456154(*(void**)(p + 0x78));
        }
    }
}

extern "C" void fn_8013B490(void*);
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(void*, f32, f32, void*);
extern void* lbl_8053AB10;
extern const f32 lbl_8054372C;
extern const f32 lbl_8054374C;
extern const f32 lbl_80543750;
struct T803FC46C;
typedef void (T803FC46C::*PMF803FC46C)();
extern PMF803FC46C lbl_804B0E4C[];
extern PMF803FC46C lbl_804B0BDC[];
extern "C" void fn_803FC46C(u8* p) {
    fn_8013B490(lbl_8053AB10);
    draw__9J2DScreenFffPC14J2DGrafContext(*(void**)(p + 0x14), lbl_8054372C, lbl_8054372C, ((void**)lbl_8053AB10)[4]);
    if (*(s32*)(p + 0x1c4) != 0xd) {
        (((T803FC46C*)p)->*lbl_804B0E4C[*(s32*)(p + 0x1c4)])();
    } else {
        (((T803FC46C*)p)->*lbl_804B0E4C[*(s32*)(p + 0x1c8)])();
    }
    u8 state = p[0x25e];
    if (state != 0) {
        switch (state) {
        case 1:
            if (p[0x25d] >= 0xf5) {
                p[0x25d] = 0xff;
                p[0x25e] = 2;
                (((T803FC46C*)p)->*lbl_804B0BDC[*(s32*)(p + 0x1cc)])();
            } else {
                p[0x25d] += 10;
            }
            break;
        case 2:
            if (p[0x25d] <= 10) {
                p[0x25d] = 0;
                p[0x25e] = 0;
            } else {
                p[0x25d] -= 10;
            }
            break;
        }
        fn_8013B490(lbl_8053AB10);
        ((void(*)(void*, s32))(*(void***)(*(void**)(p + 0x5c)))[9])(*(void**)(p + 0x5c), p[0x25d]);
        ((void(*)(void*, s32, f32, s32, s32, f32, f32, f32))(*(void***)(*(void**)(p + 0x5c)))[59])(*(void**)(p + 0x5c), 0, lbl_8054372C, 0, 0, lbl_8054372C, lbl_8054374C, lbl_80543750);
    }
}

extern "C" void fn_804310CC(void* a);
extern "C" void fn_803F267C(u8* p);
extern "C" void fn_803FC5E4(u8* p, u8 flag) {
    s32 i;
    void* obj;
    void* sub;

    fn_804310CC(lbl_8053AEC0);
    if (flag) {
        *(s32*)(p + 0x1c4) = 7;
        fn_803F267C(p);
    } else {
        if (fn_8030A308(lbl_8053AD30, fn_8030AAF4(0))) {
            if (fn_8030A308(lbl_8053AD30, fn_8030AAF4(1))) {
                *(s32*)(p + 0x1ac) = 0;
                i = 2;
                do {
                    if (!fn_8030A308(lbl_8053AD30, fn_8030AAF4(i))) {
                        break;
                    }
                    i++;
                    *(s32*)(p + 0x1ac) += 1;
                } while (i < 4);
            }
        }
        *(s32*)(p + 0x1c4) = 0;

        *(f32*)(p + 0x110) = lbl_80543770;
        obj = *(void**)(p + 4);
        sub = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[15])(obj, 0x62620000, 0x506d6261, 0x62623037);
        ((void (*)(void*, f32, f32))(*(void***)sub)[4])(sub, *(f32*)(p + 0x108), *(f32*)(p + 0x10c) + *(f32*)(p + 0x110));

        *(f32*)(p + 0x114) = lbl_80543768;
        fn_80402E08(*(void**)(p + 0x74), lbl_8054372C, *(f32*)(p + 0x114));

        *(f32*)(p + 0x130) = lbl_80543774;
        obj = *(void**)(p + 4);
        sub = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[15])(obj, 0x70620000, 0x00506e6f, 0x70623038);
        ((void (*)(void*, f32, f32))(*(void***)sub)[4])(sub, *(f32*)(p + 0x118) + *(f32*)(p + 0x130), *(f32*)(p + 0x124));

        *(f32*)(p + 0x134) = lbl_80543774;
        obj = *(void**)(p + 4);
        sub = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[15])(obj, 0x70620000, 0x00506e6f, 0x70623132);
        ((void (*)(void*, f32, f32))(*(void***)sub)[4])(sub, *(f32*)(p + 0x11c) + *(f32*)(p + 0x134), *(f32*)(p + 0x128));

        *(f32*)(p + 0x138) = lbl_80543774;
        obj = *(void**)(p + 4);
        sub = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[15])(obj, 0x70620000, 0x00506e6f, 0x70623136);
        ((void (*)(void*, f32, f32))(*(void***)sub)[4])(sub, *(f32*)(p + 0x120) + *(f32*)(p + 0x138), *(f32*)(p + 0x12c));

        *(f32*)(p + 0x144) = lbl_80543778;
        obj = *(void**)(p + 4);
        sub = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[15])(obj, 0x74610000, 0x004e6461, 0x74613032);
        ((void (*)(void*, f32, f32))(*(void***)sub)[4])(sub, *(f32*)(p + 0x13c) + *(f32*)(p + 0x144), *(f32*)(p + 0x140));

        *(f32*)(p + 0x158) = lbl_80543778;
        obj = *(void**)(p + 4);
        sub = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[15])(obj, 0x74610000, 0x004e6461, 0x74613035);
        ((void (*)(void*, f32, f32))(*(void***)sub)[4])(sub, *(f32*)(p + 0x148) + *(f32*)(p + 0x158), *(f32*)(p + 0x14c));

        obj = *(void**)(p + 4);
        sub = ((void* (*)(void*, u32, u32, u32))(*(void***)obj)[15])(obj, 0x004e0000, 0x004e6461, 0x74613037);
        ((void (*)(void*, f32, f32))(*(void***)sub)[4])(sub, *(f32*)(p + 0x150) + *(f32*)(p + 0x158), *(f32*)(p + 0x154));

        *(s32*)(p + 0x210) = 0;
        *(s32*)(p + 0x1d0) = 0;
        *(s16*)(p + 0x240) = 0;
        *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
        *(s32*)(p + 0x1c4) = 0;
    }
    *(s32*)(p + 0x350) = 4;
}

extern "C" u8 lbl_804B0F10[];
class T803FC904Obj {
public:
    virtual void v08(s32);
};
struct T803FC904Base { u32 pad[2]; };
class T803FC904Late : public T803FC904Base {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v30(s32);
};
extern "C" void* fn_803FC904(u8* param_1, s16 param_2) {
    int firstIndex;
    u8* p;

    if (param_1 != 0) {
        *(void**)param_1 = lbl_804B0F10;
        if (*(void**)(param_1 + 0x8) != 0) {
            ((T803FC904Obj*)*(void**)(param_1 + 0x8))->v08(1);
        }
        *(void**)(param_1 + 0x8) = 0;
        if (*(void**)(param_1 + 0x4) != 0) {
            ((T803FC904Obj*)*(void**)(param_1 + 0x4))->v08(1);
        }
        *(void**)(param_1 + 0x4) = 0;
        if (*(void**)(param_1 + 0xc) != 0) {
            ((T803FC904Obj*)*(void**)(param_1 + 0xc))->v08(1);
        }
        *(void**)(param_1 + 0xc) = 0;
        if (*(void**)(param_1 + 0x10) != 0) {
            ((T803FC904Obj*)*(void**)(param_1 + 0x10))->v08(1);
        }
        *(void**)(param_1 + 0x10) = 0;
        if (*(void**)(param_1 + 0x14) != 0) {
            ((T803FC904Obj*)*(void**)(param_1 + 0x14))->v08(1);
        }
        *(void**)(param_1 + 0x14) = 0;

        p = param_1;
        for (firstIndex = 0; firstIndex < 4; firstIndex++, p += 4) {
            if (*(void**)(p + 0x18) != 0) {
                ((T803FC904Obj*)*(void**)(p + 0x18))->v08(1);
            }
            *(void**)(p + 0x18) = 0;
            if (*(void**)(p + 0x38) != 0) {
                ((T803FC904Obj*)*(void**)(p + 0x38))->v08(1);
            }
            *(void**)(p + 0x38) = 0;
            if (*(void**)(p + 0x28) != 0) {
                ((T803FC904Obj*)*(void**)(p + 0x28))->v08(1);
            }
            *(void**)(p + 0x28) = 0;
            if (*(void**)(p + 0x48) != 0) {
                ((T803FC904Obj*)*(void**)(p + 0x48))->v08(1);
            }
            *(void**)(p + 0x48) = 0;
        }

        if (*(void**)(param_1 + 0x60) != 0) {
            ((T803FC904Obj*)*(void**)(param_1 + 0x60))->v08(1);
        }
        *(void**)(param_1 + 0x60) = 0;

        p = param_1;
        for (int i = 0; i < 4; i++, p += 4) {
            if (*(void**)(p + 0x64) != 0) {
                ((T803FC904Obj*)*(void**)(p + 0x64))->v08(1);
            }
            *(void**)(p + 0x64) = 0;
        }

        if (*(void**)(param_1 + 0x58) != 0) {
            ((T803FC904Obj*)*(void**)(param_1 + 0x58))->v08(1);
        }
        *(void**)(param_1 + 0x58) = 0;
        if (*(void**)(param_1 + 0x5c) != 0) {
            ((T803FC904Obj*)*(void**)(param_1 + 0x5c))->v08(1);
        }
        *(void**)(param_1 + 0x5c) = 0;

        p = param_1;
        for (int i = 0; i < 4; i++, p += 4) {
            if (*(void**)(p + 0x78) != 0) {
                ((T803FC904Late*)*(void**)(p + 0x78))->v30(1);
            }
            *(void**)(p + 0x78) = 0;
        }

        if (param_2 > 0) {
            delete param_1;
        }
    }
    return param_1;
}

