#include "types.h"
#include "Game/FsaMenuAction.h"
#include "Game/ItemBase.h"
#include "JSystem/J2D/J2DPane.h"
#include "JSystem/J2D/J2DPicture.h"
#include "JSystem/J2D/J2DScreen.h"

struct Tu803FResMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* vf18(u32 type, const void* name);
};

struct Tu803FVObj {
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9(s32 a);
    virtual void v10();
    virtual void v11(s32 a);
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15(s32 a, s32 b, s32 c);
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59(s32 a, s32 b, s32 c, f32 d, f32 e, f32 f, f32 g);
};

extern "C" void fn_802F86CC(void* mgr, void* pos, void* res, s32 id, DrawRec* rec, f32 sx, f32 sy);
extern const f32 lbl_80543718;
extern const f32 lbl_8054371C;
extern const f32 lbl_80543724;
extern const f32 lbl_80543734;


extern "C" void* lbl_8053AD30;
extern "C" void* fn_80309C4C(void* a, s32 b, s32 c);
extern "C" void* fn_80309A9C(void* a, s32 b, s32 c);
extern "C" void fn_80403680(void* p);
extern "C" u8* sManager__8JUTVideo;
extern "C" const u64 lbl_80479238[];
extern "C" s32 fn_80403414(s32 a);
extern "C" s32 fn_804033D4(s32 a);
extern "C" s32 fn_8040336C(s32 a);
extern "C" void fn_8013CC50(s32 a, f32* v, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, f32 h);
extern const f32 lbl_80543720;
extern const f32 lbl_80543728;
extern const f32 lbl_80543730;
extern const f32 lbl_805437A0;
extern const f32 lbl_805437A4;
extern const f32 lbl_805437C8;
extern const f32 lbl_805437CC;
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
extern const f64 lbl_80543738;
extern const f64 lbl_80543740;
static inline f32 MenuSquare803F(s32 n) { return n * n; }
static inline s32 MenuDelayIndex803F(const s32 index) { return index * 5; }
static inline f32 MenuSelectionOffset803F(const u8* p) { return *(const f32*)(p + 0x130); }
extern const f32 lbl_80543784;
extern const f32 lbl_80543788;
extern const f32 lbl_8054378C;
extern const f32 lbl_8054377C;
extern const f32 lbl_80543790;
extern const f32 lbl_805437AC;
extern const f32 lbl_80543764;
extern const f32 lbl_8054376C;
extern "C" void fn_80440EE8(void* p);
extern const u8 lbl_80478A60[];
extern void* lbl_8053AED8;
extern void* lbl_8053AB10;
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(void*, f32, f32, void*);
struct T803FC46C {
    u8 pad0[0x184];
    f32 groupMotion[3];
};
typedef void (T803FC46C::*PMF803FC46C)();
extern PMF803FC46C lbl_804B0BDC[];

struct MenuTagData803F {
    u8 pad[0xec0];
    u64 tags[3][4];
};

struct FsaBlock156 {
    u32 field_00;
    u32 field_04;
    u32 field_08;
    u32 field_0C;
    u32 field_10;
    u32 field_14;
    u32 field_18;
    u32 field_1C;
    u32 field_20;
    u32 field_24;
    u32 field_28;
    u32 field_2C;
    u32 field_30;
    u32 field_34;
    u32 field_38;
    u32 field_3C;
    u32 field_40;
    u32 field_44;
    u32 field_48;
    u32 field_4C;
    u32 field_50;
    u32 field_54;
    u32 field_58;
    u32 field_5C;
    u32 field_60;
    u32 field_64;
    u32 field_68;
    u32 field_6C;
    u32 field_70;
    u32 field_74;
    u32 field_78;
    u32 field_7C;
    u32 field_80;
    u32 field_84;
    u32 field_88;
    u32 field_8C;
    u32 field_90;
    u32 field_94;
    u32 field_98;
};
extern "C" FsaBlock156 lbl_804B0B40[6];

extern "C" void fn_803F0A54(void* self) {
    u8* base = (u8*)lbl_80478A60;
    u8* p = (u8*)self;
    JGeometry::TVec3f pos;
    f32 ratio = (f32)(*(J2DPane**)(p + 0xc))->search(*(u64*)(base + 0x708))->getAlpha() / (f32)p[0x335];
    if (*(s32*)(p + 0x210) < 0x64) {
        f32 alpha = lbl_80543718 * ratio;
        s32 i;
        u64 (*tags)[4] = (u64 (*)[4])(base + 0xec0);
        for (i = 0; i < 4; i++) {
            if (tags[*(s32*)(p + 0x1ac)][i] != 0) {
                DrawRec rec;
                rec.b26 = 0;
                ((u8*)&rec)[0x13] = alpha;
                J2DPane* r = (*(J2DPane**)(p + 0xc))->search(tags[*(s32*)(p + 0x1ac)][i]);
                f32 span = *(f32*)((u8*)r + 0x28) - *(f32*)((u8*)r + 0x20);
                r = (*(J2DPane**)(p + 0xc))->search(tags[*(s32*)(p + 0x1ac)][i]);
                pos.x = (lbl_8054371C * (span * lbl_80543720 + *(f32*)((u8*)r + 0x30))) /
                        (f32)(s32)*(u16*)(*(u8**)(sManager__8JUTVideo + 4) + 4);
                r = (*(J2DPane**)(p + 0xc))->search(tags[*(s32*)(p + 0x1ac)][i]);
                span = *(f32*)((u8*)r + 0x2c) - *(f32*)((u8*)r + 0x24);
                r = (*(J2DPane**)(p + 0xc))->search(tags[*(s32*)(p + 0x1ac)][i]);
                pos.y = (lbl_80543724 * (lbl_80543728 + (span * lbl_80543720 + *(f32*)((u8*)r + 0x34)))) /
                        (f32)(s32)*(u16*)(*(u8**)(sManager__8JUTVideo + 4) + 6);
                pos.z = lbl_8054372C;
                rec.ids[7] = i + 12;
                s32 id = ((s32*)(base + 0x40))[*(s32*)(p + 0x210) % 30] + 0x10;
                void* res = (*(Tu803FResMgr**)(lbl_8053AAF8 + 0xa4))->vf18(0x534F4220, base + 0xf20);
                fn_802F86CC(*(void**)((u8*)lbl_8053AB10 + 0x20), &pos, res, id, &rec, 1.0f, 1.0f);
            }
        }
    } else if (*(s32*)(p + 0x210) < 0x70) {
        f32 alpha = lbl_80543718 * ratio;
        u64 (*tags)[4] = (u64 (*)[4])(base + 0xec0);
        for (s32 i = 3; i >= 0; i--) {
            DrawRec rec;
            rec.b26 = 0;
            ((u8*)&rec)[0x13] = alpha;
            f32 x0, x1;
            switch (*(s32*)(p + 0x1ac)) {
            case 0: {
                J2DPane* r = (*(J2DPane**)(p + 0xc))->search(tags[*(s32*)(p + 0x1ac)][i % 2]);
                f32 span = *(f32*)((u8*)r + 0x28) - *(f32*)((u8*)r + 0x20);
                r = (*(J2DPane**)(p + 0xc))->search(tags[*(s32*)(p + 0x1ac)][i % 2]);
                x0 = span * lbl_80543720 + *(f32*)((u8*)r + 0x30);
                r = (*(J2DPane**)(p + 0xc))->search(tags[2][i / 2 + (i % 2) * 2]);
                span = *(f32*)((u8*)r + 0x28) - *(f32*)((u8*)r + 0x20);
                r = (*(J2DPane**)(p + 0xc))->search(tags[2][i / 2 + (i % 2) * 2]);
                x1 = span * lbl_80543720 + *(f32*)((u8*)r + 0x30);
                break;
            }
            case 1: {
                if (i != 3) {
                    J2DPane* r = (*(J2DPane**)(p + 0xc))->search(tags[*(s32*)(p + 0x1ac)][i]);
                    f32 span = *(f32*)((u8*)r + 0x28) - *(f32*)((u8*)r + 0x20);
                    r = (*(J2DPane**)(p + 0xc))->search(tags[*(s32*)(p + 0x1ac)][i]);
                    x0 = span * lbl_80543720 + *(f32*)((u8*)r + 0x30);
                    r = (*(J2DPane**)(p + 0xc))->search(tags[2][i]);
                    span = *(f32*)((u8*)r + 0x28) - *(f32*)((u8*)r + 0x20);
                    r = (*(J2DPane**)(p + 0xc))->search(tags[2][i]);
                    x1 = span * lbl_80543720 + *(f32*)((u8*)r + 0x30);
                } else {
                    J2DPane* r = (*(J2DPane**)(p + 0xc))->search(tags[*(s32*)(p + 0x1ac)][2]);
                    f32 span = *(f32*)((u8*)r + 0x28) - *(f32*)((u8*)r + 0x20);
                    r = (*(J2DPane**)(p + 0xc))->search(tags[*(s32*)(p + 0x1ac)][2]);
                    x0 = span * lbl_80543720 + *(f32*)((u8*)r + 0x30);
                    r = (*(J2DPane**)(p + 0xc))->search(tags[2][i]);
                    span = *(f32*)((u8*)r + 0x28) - *(f32*)((u8*)r + 0x20);
                    r = (*(J2DPane**)(p + 0xc))->search(tags[2][i]);
                    x1 = span * lbl_80543720 + *(f32*)((u8*)r + 0x30);
                }
                break;
            }
            }
            pos.x = (lbl_8054371C * ((x1 - x0) * ((f32)(*(s32*)(p + 0x210) - 0x64) / lbl_80543734) + x0)) /
                    (f32)(s32)*(u16*)(*(u8**)(sManager__8JUTVideo + 4) + 4);
            J2DPane* r = (*(J2DPane**)(p + 0xc))->search(tags[2][i]);
            f32 span = *(f32*)((u8*)r + 0x2c) - *(f32*)((u8*)r + 0x24);
            r = (*(J2DPane**)(p + 0xc))->search(tags[2][i]);
            pos.y = (lbl_80543724 * (lbl_80543728 + (span * lbl_80543720 + *(f32*)((u8*)r + 0x34)))) /
                    (f32)(s32)*(u16*)(*(u8**)(sManager__8JUTVideo + 4) + 6);
            pos.z = lbl_8054372C;
            rec.ids[7] = i + 12;
            void* res = (*(Tu803FResMgr**)(lbl_8053AAF8 + 0xa4))->vf18(0x534F4220, base + 0xf20);
            fn_802F86CC(*(void**)((u8*)lbl_8053AB10 + 0x20), &pos, res, 0x10, &rec, 1.0f, 1.0f);
        }
    } else if (*(s32*)(p + 0x210) < 0xd4) {
        f32 alpha = lbl_80543718 * ratio;
        u64 (*tags)[4] = (u64 (*)[4])(base + 0xec0);
        s32* tbl = (s32*)(base + 0x40);
        for (s32 i = 0; i < 4; i++) {
            DrawRec rec;
            rec.b26 = 0;
            ((u8*)&rec)[0x13] = alpha;
            J2DPane* r = (*(J2DPane**)(p + 0xc))->search(tags[2][i]);
            f32 span = *(f32*)((u8*)r + 0x28) - *(f32*)((u8*)r + 0x20);
            r = (*(J2DPane**)(p + 0xc))->search(tags[2][i]);
            pos.x = (lbl_8054371C * (span * lbl_80543720 + *(f32*)((u8*)r + 0x30))) /
                    (f32)(s32)*(u16*)(*(u8**)(sManager__8JUTVideo + 4) + 4);
            r = (*(J2DPane**)(p + 0xc))->search(tags[2][i]);
            span = *(f32*)((u8*)r + 0x2c) - *(f32*)((u8*)r + 0x24);
            r = (*(J2DPane**)(p + 0xc))->search(tags[2][i]);
            pos.y = (lbl_80543724 * (lbl_80543728 + (span * lbl_80543720 + *(f32*)((u8*)r + 0x34)))) /
                    (f32)(s32)*(u16*)(*(u8**)(sManager__8JUTVideo + 4) + 6);
            pos.z = lbl_8054372C;
            if (*(s32*)(p + 0x1ac) == 0) {
                rec.ids[7] = 12 + (i / 2) + (i % 2) * 2;
            } else {
                rec.ids[7] = i + 12;
            }
            s32 id = tbl[*(s32*)(p + 0x210) % 30] + 0x10;
            void* res = (*(Tu803FResMgr**)(lbl_8053AAF8 + 0xa4))->vf18(0x534F4220, base + 0xf20);
            fn_802F86CC(*(void**)((u8*)lbl_8053AB10 + 0x20), &pos, res, id, &rec, 1.0f, 1.0f);
        }
    } else {
        f32 alpha = lbl_80543718 * ratio;
        u64 (*tags)[4] = (u64 (*)[4])(base + 0xec0);
        for (s32 i = 3; i >= 0; i--) {
            DrawRec rec;
            rec.b26 = 0;
            ((u8*)&rec)[0x13] = alpha;
            f32 x1, x0;
            switch (*(s32*)(p + 0x1ac)) {
            case 0: {
                J2DPane* r = (*(J2DPane**)(p + 0xc))->search(tags[2][i / 2 + (i % 2) * 2]);
                f32 s0 = *(f32*)((u8*)r + 0x28) - *(f32*)((u8*)r + 0x20);
                r = (*(J2DPane**)(p + 0xc))->search(tags[2][i / 2 + (i % 2) * 2]);
                x0 = s0 * lbl_80543720 + *(f32*)((u8*)r + 0x30);
                r = (*(J2DPane**)(p + 0xc))->search(tags[*(s32*)(p + 0x1ac)][i % 2]);
                f32 s1 = *(f32*)((u8*)r + 0x28) - *(f32*)((u8*)r + 0x20);
                r = (*(J2DPane**)(p + 0xc))->search(tags[*(s32*)(p + 0x1ac)][i % 2]);
                x1 = s1 * lbl_80543720 + *(f32*)((u8*)r + 0x30);
                break;
            }
            case 1: {
                if (i != 3) {
                    J2DPane* r = (*(J2DPane**)(p + 0xc))->search(tags[2][i]);
                    f32 s0 = *(f32*)((u8*)r + 0x28) - *(f32*)((u8*)r + 0x20);
                    r = (*(J2DPane**)(p + 0xc))->search(tags[2][i]);
                    x0 = s0 * lbl_80543720 + *(f32*)((u8*)r + 0x30);
                    r = (*(J2DPane**)(p + 0xc))->search(tags[*(s32*)(p + 0x1ac)][i]);
                    f32 s1 = *(f32*)((u8*)r + 0x28) - *(f32*)((u8*)r + 0x20);
                    r = (*(J2DPane**)(p + 0xc))->search(tags[*(s32*)(p + 0x1ac)][i]);
                    x1 = s1 * lbl_80543720 + *(f32*)((u8*)r + 0x30);
                } else {
                    J2DPane* r = (*(J2DPane**)(p + 0xc))->search(tags[2][i]);
                    f32 s0 = *(f32*)((u8*)r + 0x28) - *(f32*)((u8*)r + 0x20);
                    r = (*(J2DPane**)(p + 0xc))->search(tags[2][i]);
                    x0 = s0 * lbl_80543720 + *(f32*)((u8*)r + 0x30);
                    r = (*(J2DPane**)(p + 0xc))->search(tags[*(s32*)(p + 0x1ac)][2]);
                    f32 s1 = *(f32*)((u8*)r + 0x28) - *(f32*)((u8*)r + 0x20);
                    r = (*(J2DPane**)(p + 0xc))->search(tags[*(s32*)(p + 0x1ac)][2]);
                    x1 = s1 * lbl_80543720 + *(f32*)((u8*)r + 0x30);
                }
                break;
            }
            }
            pos.x = (lbl_8054371C * ((x1 - x0) * ((f32)(*(s32*)(p + 0x210) - 0xd4) / lbl_80543734) + x0)) /
                    (f32)(s32)*(u16*)(*(u8**)(sManager__8JUTVideo + 4) + 4);
            J2DPane* r = (*(J2DPane**)(p + 0xc))->search(tags[2][i]);
            f32 span = *(f32*)((u8*)r + 0x2c) - *(f32*)((u8*)r + 0x24);
            r = (*(J2DPane**)(p + 0xc))->search(tags[2][i]);
            pos.y = (lbl_80543724 * (lbl_80543728 + (span * lbl_80543720 + *(f32*)((u8*)r + 0x34)))) /
                    (f32)(s32)*(u16*)(*(u8**)(sManager__8JUTVideo + 4) + 6);
            pos.z = lbl_8054372C;
            rec.ids[7] = i + 12;
            void* res = (*(Tu803FResMgr**)(lbl_8053AAF8 + 0xa4))->vf18(0x534F4220, base + 0xf20);
            fn_802F86CC(*(void**)((u8*)lbl_8053AB10 + 0x20), &pos, res, 0x10, &rec, 1.0f, 1.0f);
        }
    }
}

extern "C" void fn_803F1C18(u8* p) {
    fn_8043670C(*(void**)(p + 0x58), 1);
    *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
    *(s32*)(p + 0x1c4) = 0xc;
}

extern "C" void fn_803F1C5C(u8* p) {
    *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
    *(s32*)(p + 0x1c4) = 0xb;
}

extern "C" s32 fn_80403070(s32 a);
extern "C" s32 fn_8040305C(s32 a);
extern "C" ResTIMG* fn_804030C4(u32, const void*);
extern const char* lbl_804B0EE8[];
extern const s16 lbl_80543710[4];
extern const f32 lbl_80543754;
extern const f32 lbl_80543758;
extern "C" void fn_803F1C70(u8* p) {
    s32 j;
    s32 rank;
    ResTIMG* img;
    s32 n;
    u8* base = (u8*)lbl_80478A60;
    const u64* rowA = (const u64*)(base+0xb60);
    const u64* rowB = (const u64*)(base+0xc20);
    const u64* rowC = (const u64*)(base+0xce0);
    const u64* rowD = (const u64*)(base+0xda0);
    for (s32 i = 0; i < 4; i++, rowA+=6, rowB+=6, rowC+=6, rowD+=6) {
        if (i >= 1) {
            if (i > *(s32*)(p + 0x1ac) + 1)
                (*(J2DPane**)(p + 0x10))->search(((const u64*)(base + 0xea0))[i])->show();
            else
                (*(J2DPane**)(p + 0x10))->search(((const u64*)(base + 0xea0))[i])->hide();
        }
        *(s32*)(p + 0x1e0 + i*4) = fn_80403414(i);
        *(s32*)(p + 0x1f0 + i*4) = fn_804033D4(i);
        *(s32*)(p + 0x200 + i*4) = fn_8040336C(i);
        n = fn_80403070(*(s32*)(p + 0x1e0 + i*4));
        img = fn_804030C4(0x54494d47, lbl_804B0EE8[n / 100]);
        ((J2DPicture*)(*(J2DPane**)(p + 0x10))->search(((const u64*)(base+0xa58))[i]))->changeTexture(img, 0);
        ((J2DPicture*)(*(J2DPane**)(p + 0x10))->search(((const u64*)(base+0xa78))[i]))->changeTexture(img, 0);
        img = fn_804030C4(0x54494d47, lbl_804B0EE8[(n % 100) / 10]);
        ((J2DPicture*)(*(J2DPane**)(p + 0x10))->search(((const u64*)(base+0xa18))[i]))->changeTexture(img, 0);
        ((J2DPicture*)(*(J2DPane**)(p + 0x10))->search(((const u64*)(base+0xa38))[i]))->changeTexture(img, 0);
        img = fn_804030C4(0x54494d47, lbl_804B0EE8[n % 10]);
        ((J2DPicture*)(*(J2DPane**)(p + 0x10))->search(((const u64*)(base+0x9d8))[i]))->changeTexture(img, 0);
        ((J2DPicture*)(*(J2DPane**)(p + 0x10))->search(((const u64*)(base+0x9f8))[i]))->changeTexture(img, 0);
        rank = fn_8040305C(*(s32*)(p+0x1f0+i*4)) - 1;
        for (j=0; j<6; j++) {
            if (j < rank) {
                (*(J2DPane**)(p+0x10))->search(rowA[j])->show();
                (*(J2DPane**)(p+0x10))->search(rowB[j])->show();
                (*(J2DPane**)(p+0x10))->search(rowC[j])->hide();
                (*(J2DPane**)(p+0x10))->search(rowD[j])->hide();
            } else if (j == rank) {
                (*(J2DPane**)(p+0x10))->search(rowA[j])->hide();
                (*(J2DPane**)(p+0x10))->search(rowB[j])->hide();
                (*(J2DPane**)(p+0x10))->search(rowC[j])->show();
                (*(J2DPane**)(p+0x10))->search(rowD[j])->show();
            } else {
                (*(J2DPane**)(p+0x10))->search(rowA[j])->hide();
                (*(J2DPane**)(p+0x10))->search(rowB[j])->hide();
                (*(J2DPane**)(p+0x10))->search(rowC[j])->hide();
                (*(J2DPane**)(p+0x10))->search(rowD[j])->hide();
            }
        }
        (*(J2DPane**)(p+0x10))->search(((const u64*)(base+0x998))[i])->hide();
    }
    fn_80402E08(*(void**)(p+0x60), lbl_8054372C, lbl_80543754);
    *(s16*)(*(u8**)(p+0x60)+0x22)=0;
    for (s32 i=0; i<4; i++) {
        if (i <= *(s32*)(p+0x1ac)+1) {
            fn_80402E08(*(void**)(p+0x64+i*4), lbl_8054372C, lbl_80543758);
            *(s16*)(*(u8**)(p+0x64+i*4)+0x22)=0;
        }
        if (i <= *(s32*)(p+0x1ac)+1) *(s32*)(p+0x1b0+i*4)=3;
        else *(s32*)(p+0x1b0+i*4)=4;
        *(s32*)(p+0x1d0+i*4)=30;
        if (i <= *(s32*)(p+0x1ac)+1) {
            if (*(s32*)(p+0x1b0+i*4) < 3) {
                (*(J2DPane**)(p+0x10))->search(((const u64*)(base+0x958))[i])->hide();
                (*(J2DPane**)(p+0x10))->search(((const u64*)(base+0x978))[i])->show();
                (*(J2DPane**)(p+0x10))->search(((const u64*)(base+0x998))[i])->hide();
            } else if (*(s32*)(p+0x1b0+i*4)==3) {
                (*(J2DPane**)(p+0x10))->search(((const u64*)(base+0x958))[i])->hide();
                (*(J2DPane**)(p+0x10))->search(((const u64*)(base+0x978))[i])->show();
                (*(J2DPane**)(p+0x10))->search(((const u64*)(base+0x998))[i])->show();
            } else {
                (*(J2DPane**)(p+0x10))->search(((const u64*)(base+0x958))[i])->show();
                (*(J2DPane**)(p+0x10))->search(((const u64*)(base+0x978))[i])->hide();
                (*(J2DPane**)(p+0x10))->search(((const u64*)(base+0x998))[i])->hide();
            }
        } else {
            (*(J2DPane**)(p+0x10))->search(((const u64*)(base+0x958))[i])->hide();
            (*(J2DPane**)(p+0x10))->search(((const u64*)(base+0x978))[i])->hide();
            (*(J2DPane**)(p+0x10))->search(((const u64*)(base+0x998))[i])->hide();
        }
        s32 state=*(s32*)(p+0x1b0+i*4);
        if (state<=3) {
            f32 x=(*(J2DPane**)(p+0x10))->search(((const u64*)(base+0x978))[i])->getBounds()->i.x;
            (*(J2DPane**)(p+0x10))->search(((const u64*)(base+0x978))[i])->move(x, lbl_80543710[state]);
        }
        *(s16*)(p+0x240+i*2)=0;
        *(s32*)(p+0x1d0+i*4)=0;
    }
    fn_80402E08(*(void**)(p+0x74),lbl_8054372C,lbl_80543754);
    *(s16*)(*(u8**)(p+0x74)+0x22)=0;
    *(s16*)(p+0x24c)=0;
    *(s32*)(p+0x1c8)=*(s32*)(p+0x1c4);
    *(s32*)(p+0x1c4)=10;
}

extern "C" void fn_803F2580(u8* p) {
    s32 j;
    s32 i;
    s32 k;
    u8* b;

    *(s16*)(p + 0x240) = j = 0;
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

static inline void tu803F_setAlphas(u8* p, u64* tags, u8* alphas, s32 n, f32 a) {
    for (s32 i = 0; i < n; i++) {
        f32 v = alphas[i];
        (*(J2DPane**)(p + 0xc))->search(tags[i])->setAlpha((u8)(v * a));
    }
}

static inline f32 tu803F_ease(s32 d, f32 div) {
    return (f32)(d * d) / div;
}

static inline void tu803F_fade(u8* p, s32 start, s32 len, f32* out, f32 scale, f32 div, f32 adiv, u64* tags, u8* alphas, s32 n) {
    if (*(s16*)(p + 0x240) < start + len) {
        s32 d = len - (*(s16*)(p + 0x240) - start);
        *out = scale * ((f32)(d * d) / div);
        f32 a = (f32)(*(s16*)(p + 0x240) - start) / adiv;
        if (a < lbl_8054372C) {
            a = lbl_8054372C;
        } else if (a > lbl_80543730) {
            a = lbl_80543730;
        }
        tu803F_setAlphas(p, tags, alphas, n, a);
    } else {
        *out = lbl_8054372C;
        tu803F_setAlphas(p, tags, alphas, n, lbl_80543730);
    }
}

extern "C" void fn_803F2660(u8* p) {
    *(s16*)(p + 0x240) = 0;
    *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
    *(s32*)(p + 0x1c4) = 8;
}

extern "C" void* getStringPtr__10J2DTextBoxCFv(void* p);
extern "C" void fn_803832BC(void* p, s32 a, s32 b, s32 c, s32 d);
extern "C" void* fn_804031C4(s32 a, void* b);
extern "C" const u8 lbl_80478A60[];
extern const f32 lbl_80543754;
extern const f32 lbl_8054375C;
extern const f32 lbl_80543760;
extern "C" void fn_803F267C(u8* p) {
    u8* base;
    void* s1;
    void* s2;
    void* s3;
    J2DPane* piVar4;

    base = (u8*)lbl_80478A60;
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

#pragma opt_propagation off
extern "C" void fn_803F2B78(u8* p) {
    u8* base;
    u8* obj=p;
    const u64* pt30;
    const u64* pt29;
    const u64* pt28;
    const u64* pt27;
    const u64* pt26;
    const u64* pt25;
    const u64* pt31;
    u8* q;
    int i;
    s32 j;
    const u64* t20;
    J2DPane* piVar;
    void* s1;
    void* s2;
    u8* sp;

    base = (u8*)lbl_80478A60;
    if (*(s32*)(p + 0x1ac) == 0) {
        void* uVar1 = fn_804031C4(0x54494d47, base + 0xf30);
        piVar = (*(J2DPane**)(obj + 8))->search(0x50746e3032ULL);
        ((J2DPicture*)piVar)->changeTexture((const ResTIMG*)uVar1, 0);
        piVar = (*(J2DPane**)(obj + 8))->search(0x50746e3031ULL);
        ((J2DPicture*)piVar)->changeTexture((const ResTIMG*)uVar1, 0);
    } else if (*(s32*)(p + 0x1ac) == 1) {
        void* uVar1 = fn_804031C4(0x54494d47, base + 0xf44);
        piVar = (*(J2DPane**)(obj + 8))->search(0x50746e3032ULL);
        ((J2DPicture*)piVar)->changeTexture((const ResTIMG*)uVar1, 0);
        piVar = (*(J2DPane**)(obj + 8))->search(0x50746e3031ULL);
        ((J2DPicture*)piVar)->changeTexture((const ResTIMG*)uVar1, 0);
    } else {
        void* uVar1 = fn_804031C4(0x54494d47, base + 0xf58);
        piVar = (*(J2DPane**)(obj + 8))->search(0x50746e3032ULL);
        ((J2DPicture*)piVar)->changeTexture((const ResTIMG*)uVar1, 0);
        piVar = (*(J2DPane**)(obj + 8))->search(0x50746e3031ULL);
        ((J2DPicture*)piVar)->changeTexture((const ResTIMG*)uVar1, 0);
    }

    piVar = (*(J2DPane**)(obj + 8))->search(0x54746b673031ULL);
    s1 = getStringPtr__10J2DTextBoxCFv(piVar);
    piVar = (*(J2DPane**)(obj + 8))->search(0x54746b673032ULL);
    s2 = getStringPtr__10J2DTextBoxCFv(piVar);
    fn_803832BC(s1, 0x3f, 0, 0, 0);
    fn_803832BC(s2, 0x3f, 0, 0, 0);

    *(f32*)(p + 0x9c) = lbl_80543764;
    piVar = (*(J2DPane**)(obj + 8))->search(0x4e646174613033ULL);
    piVar->move(*(f32*)(p + 0x94), *(f32*)(p + 0x98) + *(f32*)(p + 0x9c));

    *(f32*)(p + 0xa8) = lbl_80543768;
    piVar = (*(J2DPane**)(obj + 8))->search(0x4e646174613035ULL);
    piVar->move(*(f32*)(p + 0xa0), *(f32*)(p + 0xa4) + *(f32*)(p + 0xa8));

    *(f32*)(p + 0xb4) = lbl_80543754;
    piVar = (*(J2DPane**)(obj + 8))->search(0x4e646174613036ULL);
    piVar->move(*(f32*)(p + 0xac), *(f32*)(p + 0xb0) + *(f32*)(p + 0xb4));

    *(f32*)(p + 0xb8) = lbl_80543754;
    fn_80402E08(*(void**)(p + 0x74), lbl_8054372C, *(f32*)(p + 0xb8));

    *(f32*)(p + 0xdc) = lbl_8054376C;
    piVar = (*(J2DPane**)(obj + 8))->search(0x50706c6c626b3032ULL);
    piVar->move(*(f32*)(p + 0xbc), *(f32*)(p + 0xcc) + *(f32*)(p + 0xdc));

    *(f32*)(p + 0xe0) = lbl_8054376C;
    piVar = (*(J2DPane**)(obj + 8))->search(0x50706c6c626b3132ULL);
    piVar->move(*(f32*)(p + 0xc0), *(f32*)(p + 0xd0) + *(f32*)(p + 0xe0));

    *(f32*)(p + 0xe4) = lbl_8054376C;
    piVar = (*(J2DPane**)(obj + 8))->search(0x50706c6c626b3232ULL);
    piVar->move(*(f32*)(p + 0xc4), *(f32*)(p + 0xd4) + *(f32*)(p + 0xe4));

    *(f32*)(p + 0xe8) = lbl_8054376C;
    piVar = (*(J2DPane**)(obj + 8))->search(0x50706c6c626b3332ULL);
    piVar->move(*(f32*)(p + 0xc8), *(f32*)(p + 0xd8) + *(f32*)(p + 0xe8));

    q = p;
    pt30 = (const u64*)(base + 0x7f8);
    pt29 = (const u64*)(base + 0x818);
    pt28 = (const u64*)(base + 0x838);
    pt27 = (const u64*)(base + 0x858);
    pt26 = (const u64*)(base + 0x898);
    pt25 = (const u64*)(base + 0x878);
    pt31 = (const u64*)(base + 0x918);
    for (i = 0; i < 4; i++) {
        if (i <= *(s32*)(p + 0x1ac) + 1) {
            sp = (u8*)(*(J2DPane**)(obj + 8))->search(pt30[0]);
            ((J2DPane*)sp)->show();
            sp = (u8*)(*(J2DPane**)(obj + 8))->search(pt29[0]);
            ((J2DPane*)sp)->show();
            sp = (u8*)(*(J2DPane**)(obj + 8))->search(pt28[0]);
            ((J2DPane*)sp)->show();
            sp = (u8*)(*(J2DPane**)(obj + 8))->search(pt27[0]);
            ((J2DPane*)sp)->show();
            t20 = pt26 + 2;
            for (j = 2; j < 4; j++) {
                sp = (u8*)(*(J2DPane**)(obj + 8))->search(t20[0]);
                ((J2DPane*)sp)->show();
                t20 += 1;
            }
            piVar = (*(J2DPane**)(obj + 8))->search(pt25[0]);
            piVar->setAlpha(0xff);
            *(s32*)(q + 0x220) = *(s16*)(*(u8**)(q + 0x38) + 6);
            *(s32*)(q + 0x230) = *(s16*)(*(u8**)(q + 0x48) + 6);
        } else {
            sp = (u8*)(*(J2DPane**)(obj + 8))->search(pt30[0]);
            ((J2DPane*)sp)->hide();
            sp = (u8*)(*(J2DPane**)(obj + 8))->search(pt29[0]);
            ((J2DPane*)sp)->hide();
            sp = (u8*)(*(J2DPane**)(obj + 8))->search(pt28[0]);
            ((J2DPane*)sp)->hide();
            sp = (u8*)(*(J2DPane**)(obj + 8))->search(pt27[0]);
            ((J2DPane*)sp)->hide();
            t20 = pt26 + 2;
            for (j = 2; j < 4; j++) {
                sp = (u8*)(*(J2DPane**)(obj + 8))->search(t20[0]);
                ((J2DPane*)sp)->hide();
                t20 += 1;
            }
            piVar = (*(J2DPane**)(obj + 8))->search(pt25[0]);
            piVar->setAlpha(0x80);
            *(s32*)(q + 0x220) = 0;
            *(s32*)(q + 0x230) = 0;
        }
        sp = (u8*)(*(J2DPane**)(obj + 8))->search(pt31[0]);
        ((J2DPane*)sp)->hide();
        pt30 += 1;
        pt29 += 1;
        pt28 += 1;
        pt27 += 1;
        pt26 += 4;
        pt25 += 1;
        q += 4;
        pt31 += 1;
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
#pragma opt_propagation on
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
    *(f32*)(p + 0x110) = lbl_80543770;
    (*(J2DPane**)(p + 4))->search(0x506d626162623037ULL)->move(*(f32*)(p + 0x108), *(f32*)(p + 0x10c) + *(f32*)(p + 0x110));
    *(f32*)(p + 0x114) = lbl_80543768;
    fn_80402E08(*(void**)(p + 0x74), lbl_8054372C, *(f32*)(p + 0x114));
    *(f32*)(p + 304) = lbl_80543774;
    (*(J2DPane**)(p + 4))->search(0x00506e6f70623038ULL)->move(*(f32*)(p + 280) + *(f32*)(p + 304), *(f32*)(p + 292));
    *(f32*)(p + 308) = lbl_80543774;
    (*(J2DPane**)(p + 4))->search(0x00506e6f70623132ULL)->move(*(f32*)(p + 284) + *(f32*)(p + 308), *(f32*)(p + 296));
    *(f32*)(p + 312) = lbl_80543774;
    (*(J2DPane**)(p + 4))->search(0x00506e6f70623136ULL)->move(*(f32*)(p + 288) + *(f32*)(p + 312), *(f32*)(p + 300));
    *(f32*)(p + 324) = lbl_80543778;
    (*(J2DPane**)(p + 4))->search(0x004e646174613032ULL)->move(*(f32*)(p + 316) + *(f32*)(p + 324), *(f32*)(p + 320));
    *(f32*)(p + 344) = lbl_80543778;
    (*(J2DPane**)(p + 4))->search(0x004e646174613035ULL)->move(*(f32*)(p + 328) + *(f32*)(p + 344), *(f32*)(p + 332));
    (*(J2DPane**)(p + 4))->search(0x004e646174613037ULL)->move(*(f32*)(p + 0x150) + *(f32*)(p + 0x158), *(f32*)(p + 0x154));
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
#pragma opt_propagation off
extern "C" void fn_803F35B0(u8* p) {
    u8* q;
    u64* tA = (u64*)(lbl_80478A60 + 0x978);
    u64* tB = (u64*)(lbl_80478A60 + 0x998);
    u64* tC = (u64*)(lbl_80478A60 + 0x9b8);
    u8* sp;
    s32 i;
    s32 k;
    s32 n;
    f32 t;
    f32 off;
    f32 square;
    J2DPane* pane;
    i = 0;
    q = p;
    sp = p;
    for (; i < 4; i++, q += 4, tA++, tB++, tC++, sp += 2) {

    n = *(s32*)(q + 0x1d0);
    if (n < 30) {
        square = n * n;
        t = square / 900.0f;
    } else {
        n -= 30;
        f32 one = 1.0f;
        square = n * n;
        t = one - square / 900.0f;
    }
        if (i <= *(s32*)(p + 0x1ac) + 1) {
            if (*(s32*)(q + 0x1b0) < 4) {
                pane = (*(J2DPane**)(p + 0x10))->search(*tA);
                ((Tu803FVObj*)pane)->v9((s32)(160.0f * t));
            }
            if (*(s32*)(q + 0x1b0) == 3) {
                pane = (*(J2DPane**)(p + 0x10))->search(*tB);
                ((Tu803FVObj*)pane)->v9((s32)(t * (f32)p[0x25a]));
                pane = (*(J2DPane**)(p + 0x10))->search(*tC);
                ((Tu803FVObj*)pane)->v9((s32)(t * (f32)p[0x25a]));
            }
        }
            if (*(s32*)(p + 0x1c4) != 0xa) {
                k = *(s16*)(sp + 0x240);
                k = k < 5 ? k : 10 - k;
                off = (5.0f * (f32)(k * k)) / 25.0f;
                pane = (*(J2DPane**)(p + 0x10))->search(*tB);
                t = ((f32*)getBounds__7J2DPaneFv(pane))[0];
                pane = (*(J2DPane**)(p + 0x10))->search(*tB);
                pane->move(t, *(f32*)(p + 0x1a0) + off);
                if (*(s32*)(q + 0x1b0) >= 3) {
                    fn_80402E08(*(void**)(q + 0x64), 0.0f, off);
                }
            }
    }
    draw__9J2DScreenFffPC14J2DGrafContext(*(void**)(p + 0x10), 0.0f, 0.0f, *(void**)((u8*)lbl_8053AB10 + 0x10));
    fn_80440EE8(lbl_8053AED8);
}
#pragma opt_propagation reset
extern "C" void fn_8013B414(void* p, f32* box, s32 n);
extern "C" void fn_803F38A4(u8* p) {
    s32 state = *(s32*)(p + 0x1c4);
    f32 f2;
    f32 alpha;
    f32 off;
    f32 t;
    s32 n;
    if (state != 9) {
        if (*(s32*)(p + 0x1d0) < 0x1e) {
            f2 = MenuSquare803F(*(s32*)(p + 0x1d0)) / lbl_8054377C;
        } else {
            f2 = lbl_80543730 - MenuSquare803F(*(s32*)(p + 0x1d0) - 0x1e) / lbl_8054377C;
        }
        alpha = f2 * (f32)*(u8*)(p + 0x259);
    } else if (*(s32*)(p + 0x1cc) == 0) {
        alpha = lbl_8054372C;
    } else {
        if (*(s32*)(p + 0x1d0) < 0xf) {
            f2 = MenuSquare803F(*(s32*)(p + 0x1d0)) / lbl_8054378C;
        } else {
            f2 = lbl_80543730 - MenuSquare803F(*(s32*)(p + 0x1d0) - 0xf) / lbl_8054378C;
        }
        alpha = lbl_80543790 * f2;
    }
    if (state == 8 || (state == 9 && *(s32*)(p + 0x1cc) != 0 && *(s16*)(p + 0x240) <= 10)) {
        n = *(s16*)(p + 0x240);
        if (n < 5) {
            n = *(s16*)(p + 0x240);
        } else {
            n = 10 - n;
        }
    } else {
        n = 0;
    }
    off = lbl_80543784 * MenuSquare803F(n) / lbl_80543788;
    if (*(s32*)(p + 0x1a8) == 0) {
        t = (*(J2DPane**)(p + 0xc))->search(0x0050737461623034ULL)->getBounds()->i.x;
        (*(J2DPane**)(p + 0xc))->search(0x0050737461623034ULL)->move(t, *(f32*)(p + 0xfc) + off);
        t = (*(J2DPane**)(p + 0xc))->search(0x005068616e623034ULL)->getBounds()->i.x;
        (*(J2DPane**)(p + 0xc))->search(0x005068616e623034ULL)->move(t, *(f32*)(p + 0x100));
        t = (*(J2DPane**)(p + 0xc))->search(0x0000507275623034ULL)->getBounds()->i.x;
        (*(J2DPane**)(p + 0xc))->search(0x0000507275623034ULL)->move(t, *(f32*)(p + 0x104));
        t = (*(J2DPane**)(p + 0xc))->search(0x50736375726f3032ULL)->getBounds()->i.x;
        (*(J2DPane**)(p + 0xc))->search(0x50736375726f3032ULL)->move(t, *(f32*)(p + 0xf8) + off);
    } else if (*(s32*)(p + 0x1a8) == 1) {
        t = (*(J2DPane**)(p + 0xc))->search(0x0050737461623034ULL)->getBounds()->i.x;
        (*(J2DPane**)(p + 0xc))->search(0x0050737461623034ULL)->move(t, *(f32*)(p + 0xfc));
        t = (*(J2DPane**)(p + 0xc))->search(0x005068616e623034ULL)->getBounds()->i.x;
        (*(J2DPane**)(p + 0xc))->search(0x005068616e623034ULL)->move(t, *(f32*)(p + 0x100) + off);
        t = (*(J2DPane**)(p + 0xc))->search(0x0000507275623034ULL)->getBounds()->i.x;
        (*(J2DPane**)(p + 0xc))->search(0x0000507275623034ULL)->move(t, *(f32*)(p + 0x104));
        t = (*(J2DPane**)(p + 0xc))->search(0x0050737461623034ULL)->getBounds()->i.y;
        off = (*(f32*)(p + 0xf8) + (*(J2DPane**)(p + 0xc))->search(0x005068616e623034ULL)->getBounds()->i.y) - t;
        t = (*(J2DPane**)(p + 0xc))->search(0x50736375726f3032ULL)->getBounds()->i.x;
        (*(J2DPane**)(p + 0xc))->search(0x50736375726f3032ULL)->move(t, off);
    } else {
        t = (*(J2DPane**)(p + 0xc))->search(0x0050737461623034ULL)->getBounds()->i.x;
        (*(J2DPane**)(p + 0xc))->search(0x0050737461623034ULL)->move(t, *(f32*)(p + 0xfc));
        t = (*(J2DPane**)(p + 0xc))->search(0x005068616e623034ULL)->getBounds()->i.x;
        (*(J2DPane**)(p + 0xc))->search(0x005068616e623034ULL)->move(t, *(f32*)(p + 0x100));
        t = (*(J2DPane**)(p + 0xc))->search(0x0000507275623034ULL)->getBounds()->i.x;
        (*(J2DPane**)(p + 0xc))->search(0x0000507275623034ULL)->move(t, *(f32*)(p + 0x104) + off);
        t = (*(J2DPane**)(p + 0xc))->search(0x0050737461623034ULL)->getBounds()->i.y;
        t = (*(f32*)(p + 0xf8) + (*(J2DPane**)(p + 0xc))->search(0x0000507275623034ULL)->getBounds()->i.y) - t;
        off = (*(J2DPane**)(p + 0xc))->search(0x50736375726f3032ULL)->getBounds()->i.x;
        (*(J2DPane**)(p + 0xc))->search(0x50736375726f3032ULL)->move(off, t);
    }
    (*(J2DPane**)(p + 0xc))->search(0x50736375726f3031ULL)->setAlpha((u8)alpha);
    (*(J2DPane**)(p + 0xc))->search(0x50736375726f3032ULL)->setAlpha((u8)alpha);
    draw__9J2DScreenFffPC14J2DGrafContext(*(void**)(p + 0xc), lbl_8054372C, lbl_8054372C, ((void**)lbl_8053AB10)[4]);
    {
        f32 box[4];
        box[0] = lbl_8054372C;
        box[1] = lbl_8054372C;
        box[2] = lbl_8054371C;
        box[3] = lbl_80543724;
        fn_8013B414(lbl_8053AB10, box, 1);
    }
    fn_803F0A54(p);
    fn_80440EE8(lbl_8053AED8);
}

extern "C" u8 fn_8030A388(void*,s32);
extern "C" s32 fn_8030AAF4(s32);
extern "C" void fn_8013B490(void*);
extern "C" void fn_804316EC(void*);
extern const f32 lbl_80543758,lbl_80543794,lbl_80543798,lbl_8054379C,lbl_805437A8;
static inline u8 MenuEnabled803F(s32 i) { return (lbl_8053AAF8[0x82] & (u8)(1 << (i + 4))) != 0; }
static inline s16 MenuNext803F(s16 old,s32 count) {
    s16 next=old;
    for(s32 i=0;i<=count;i++) {
        next++;
        if(next>count)next=0;
        if(!(lbl_8053AAF8[0x82]&(u8)(1<<(next+4))))return next;
        if(next==old)return -1;
    }
    return -1;
}
static inline void MenuRestore803F(u8* p,const u64* a,const u64* b,const u64* c) {
    ((Tu803FVObj*)(*(J2DPane**)(p+8))->search(*a))->v9(p[0x253]);
    ((Tu803FVObj*)(*(J2DPane**)(p+8))->search(*b))->v9(p[0x254]);
    ((Tu803FVObj*)(*(J2DPane**)(p+8))->search(*c))->v9(p[0x255]);
}
static inline void MenuSprite803F(JGeometry::TVec3f& pos,s32 id,DrawRec& rec,const u8* base) {
    void* res=(*(Tu803FResMgr**)(lbl_8053AAF8+0xa4))->vf18('SOB ',base+0xf20);
    fn_802F86CC(((void**)lbl_8053AB10)[8],&pos,res,id,&rec,lbl_80543730,lbl_80543730);
}
struct MenuFrameValue803F {s32 frame;};
struct MenuCounters803F {u8 _00[0x220];s32 frame220;u8 _224[0xc];s32 frame230;};
struct MenuFrame803F {u8 _00[0x220];MenuFrameValue803F frame220[4];MenuFrameValue803F frame230[4];};
static inline void MenuMove803F(J2DPane* screen,u64 tag,f32 x,f32 y) {screen->search(tag)->move(x,y);}

#pragma opt_common_subs off
extern "C" void fn_803F4120(void* param_1) {
    u8* p=(u8*)param_1;
    f32 x,y,size;
    JGeometry::TVec3f pos;
    JGeometry::TBox2f box;
    const u8* base=lbl_80478A60;
    {
    u8* q=p;
    const u64* a=(u64*)(base+0x858);
    const u64* b=(u64*)(base+0x7f8);
    const u64* c=(u64*)(base+0x818);
    const u64* d=(u64*)(base+0x838);
    s32 mask;
    s32 i;
    for(i=0;i<4;i++,q+=4,a++,b++,c++,d++) {
        mask=1<<(i+4);
        if(MenuEnabled803F(i)&1) {
            s32 v=*(s32*)(q+0x210);
            s32 alpha;
            if(v==0) {p[0x25b]&=~(1<<i);alpha=0;}
            else if(v<36) alpha=lbl_80543758*((f32)(v*v)/lbl_80543794);
            else {
                if(*(s16*)(p+0x248)==0) p[0x25b]|=1<<i;
                if(p[0x25b]&(1<<i)) {
                    s16 t=*(s16*)(p+0x248);
                    if(t<50) {s32 n=t;alpha=((f32)(n*n)/lbl_8054379C)*lbl_80543798+lbl_80543758;}
                    else {s32 n=50-(t-50);alpha=((f32)(n*n)/lbl_8054379C)*lbl_80543798+lbl_80543758;}
                } else alpha=150;
            }
            ((Tu803FVObj*)(*(J2DPane**)(p+8))->search(*a))->v9(alpha);
            if(p[0x25b]&mask) {p[0x25b]&=~mask;MenuRestore803F(p,b,c,d);}
        } else {
            ((Tu803FVObj*)(*(J2DPane**)(p+8))->search(*a))->v9(0);
            if(fn_8030A388(lbl_8053AD30,fn_8030AAF4(i))) {
                if(!(p[0x25b]&mask)&&*(s16*)(p+0x24a)==50) p[0x25b]|=mask;
                if(p[0x25b]&mask) {
                    s16 t=*(s16*)(p+0x24a);
                    if(t<50) {s32 n=t;x=(f32)(n*n)/lbl_8054379C;}
                    else {s32 n=50-(t-50);x=(f32)(n*n)/lbl_8054379C;}
                    ((Tu803FVObj*)(*(J2DPane**)(p+8))->search(*b))->v9((f32)p[0x253]*x);
                    ((Tu803FVObj*)(*(J2DPane**)(p+8))->search(*c))->v9((f32)p[0x254]*x);
                    ((Tu803FVObj*)(*(J2DPane**)(p+8))->search(*d))->v9((f32)p[0x255]*x);
                }
            } else if(p[0x25b]&mask) {p[0x25b]&=~mask;MenuRestore803F(p,b,c,d);}
        }
    }
    }
    draw__9J2DScreenFffPC14J2DGrafContext(*(void**)(p+8),lbl_8054372C,lbl_8054372C,((void**)lbl_8053AB10)[4]);
    if(*(s32*)(p+0x1c4)!=3) {
        if(*(s32*)(p+0x220)==0&&*(s32*)(p+0x224)==0&&*(s32*)(p+0x228)==0&&*(s32*)(p+0x22c)==0) {
            *(s16*)(p+0x24e)=MenuNext803F(*(s16*)(p+0x24e),*(s32*)(p+0x1ac)+1);
            if(*(s16*)(p+0x24e)!=-1) ((MenuFrame803F*)(p+*(s16*)(p+0x24e)*4))->frame220[0].frame++;
        }
        if(*(s32*)(p+0x230)==0&&*(s32*)(p+0x234)==0&&*(s32*)(p+0x238)==0&&*(s32*)(p+0x23c)==0) {
            *(s16*)(p+0x250)=MenuNext803F(*(s16*)(p+0x250),*(s32*)(p+0x1ac)+1);
            if(*(s16*)(p+0x250)!=-1) ((MenuFrame803F*)(p+*(s16*)(p+0x250)*4))->frame230[0].frame++;
        }
    }
    {
    u8* q=p;
    const u64* a=(u64*)(base+0x918);
    const u64* b=(u64*)(base+0x938);
    const u64* c=(u64*)(base+0x898);
    s32 i;
    for(i=0;i<=*(s32*)(p+0x1ac)+1;q+=4,a++,b++,c+=4,i++) {

        if(*(s32*)(q+0x220)!=0) {
            ++*(s32*)(q+0x220);
            if(*(s32*)(q+0x220)>=*(s16*)(*(u8**)(q+0x38)+6)) *(s32*)(q+0x220)=0;
            *(f32*)(*(u8**)(q+0x38)+8)=(f32)*(s32*)(q+0x220);
            (*(J2DPane**)(q+0x18))->search(0x4e554c4c5f303031ULL)->animationTransform();
            if(i==*(s16*)(p+0x24e) && *(s32*)(q+0x220)==*(s16*)(*(u8**)(q+0x38)+6)-10) {
                s16 old=*(s16*)(p+0x24e);
                s16 next=MenuNext803F(old,*(s32*)(p+0x1ac)+1);
                if(next!=-1 && old!=next) {
                    *(s16*)(p+0x24e)=next;
                    u8* r=p+next*4;
                    ((MenuFrame803F*)r)->frame220[0].frame++;
                    *(f32*)(*(u8**)(q+0x38)+8)=(f32)*(s32*)(r+0x220);
                    (*(J2DPane**)(r+0x18))->search(0x4e554c4c5f303031ULL)->animationTransform();
                }
            }
        }

        if(*(s32*)(q+0x230)!=0) {
            ++*(s32*)(q+0x230);
            if(*(s32*)(q+0x230)>=*(s16*)(*(u8**)(q+0x48)+6)) *(s32*)(q+0x230)=0;
            *(f32*)(*(u8**)(q+0x48)+8)=(f32)*(s32*)(q+0x230);
            (*(J2DPane**)(q+0x28))->search(0x4e64617461793030ULL)->animationTransform();
            if(i==*(s16*)(p+0x250) && *(s32*)(q+0x230)==*(s16*)(*(u8**)(q+0x48)+6)-10) {
                s16 old=*(s16*)(p+0x250);
                s16 next=MenuNext803F(old,*(s32*)(p+0x1ac)+1);
                if(next!=-1 && old!=next) {
                    *(s16*)(p+0x250)=next;
                    u8* r=p+next*4;
                    ((MenuFrame803F*)r)->frame230[0].frame++;
                    *(f32*)(*(u8**)(q+0x48)+8)=(f32)*(s32*)(r+0x230);
                    (*(J2DPane**)(r+0x28))->search(0x4e64617461793030ULL)->animationTransform();
                }
            }
        }


        size=(*(J2DPane**)(q+0x18))->search(0x4e554c4c5f303031ULL)->getWidth();
        J2DPane* pane=(*(J2DPane**)(p+8))->search(*a);
        y=((*(J2DPane**)(p+8))->search(*a))->getBounds()->i.x;
        f32 root=((*(J2DPane**)(p+8))->search(0x4e554c4c5f303031ULL))->getBounds()->i.x;
        {f32 origin=root+y;f32 delta=pane->getWidth()-size;x=delta*lbl_80543720+origin;}
        size=(*(J2DPane**)(q+0x18))->search(0x4e554c4c5f303031ULL)->getHeight();
        pane=(*(J2DPane**)(p+8))->search(*a);
        y=((*(J2DPane**)(p+8))->search(*a))->getBounds()->i.y;
        root=((*(J2DPane**)(p+8))->search(0x4e554c4c5f303031ULL))->getBounds()->i.y;
        {f32 origin=root+y;f32 delta=pane->getHeight()-size;y=delta*lbl_80543720+origin;}
        MenuMove803F(*(J2DPane**)(q+0x18),0x4e554c4c5f303031ULL,x,y);
        y=((*(J2DPane**)(p+8))->search(*b))->getBounds()->i.x;
        root=((*(J2DPane**)(p+8))->search(0x004e646174613033ULL))->getBounds()->i.x;
        x=root+y;
        size=((*(J2DPane**)(q+0x28))->search(0x0050636361613030ULL))->getBounds()->i.y;
        y=((*(J2DPane**)(p+8))->search(*b))->getBounds()->i.y;
        root=((*(J2DPane**)(p+8))->search(0x004e646174613033ULL))->getBounds()->i.y;
        y=root+y;
        root=((*(J2DPane**)(p+8))->search(c[1]))->getBounds()->i.y;
        y=(root+y)-size;
        MenuMove803F(*(J2DPane**)(q+0x28),0x4e64617461793030ULL,x,y);
        draw__9J2DScreenFffPC14J2DGrafContext(*(void**)(q+0x28),lbl_8054372C,lbl_8054372C,((void**)lbl_8053AB10)[4]);
        if(*(s32*)(p+0x1c4)!=3 && !(lbl_8053AAF8[0x82]&(u8)(1<<(i+4))))
            draw__9J2DScreenFffPC14J2DGrafContext(*(void**)(q+0x18),lbl_8054372C,lbl_8054372C,((void**)lbl_8053AB10)[4]);
    }
    }
    box.set(lbl_8054372C,lbl_8054372C,lbl_805437A0,lbl_805437A4);
    fn_8013B414(lbl_8053AB10,&box.i.x,1);
    u8* row=p;
    const u64* a=(u64*)(base+0x7d8);
    const u64* b=(u64*)(base+0x4d0);
    u8* q=p;
    s32 i;
    for(i=0;i<4;i++,a++,b+=9,row+=9,q+=4) {
        DrawRec rec;
        rec.ids[7]=i+12;
        rec.b26=0;
        J2DPane* pane=(*(J2DPane**)(p+8))->search(*a);
        f32 size=pane->getWidth();
        pane=(*(J2DPane**)(p+8))->search(*a);
        pos.x=lbl_805437A0*(size*lbl_80543720+*(f32*)((u8*)pane+0x30))/(f32)(s32)*(u16*)(*(u8**)(sManager__8JUTVideo+4)+4);
        pane=(*(J2DPane**)(p+8))->search(*a);
        size=pane->getHeight();
        pane=(*(J2DPane**)(p+8))->search(*a);
        pos.y=lbl_805437A4*(lbl_80543728+(size*lbl_80543720+*(f32*)((u8*)pane+0x34)))/(f32)(s32)*(u16*)(*(u8**)(sManager__8JUTVideo+4)+6);
        pos.z=lbl_8054372C;
        u8 alpha=((u8*)(*(J2DPane**)(p+8))->search(*b))[0xb2];
        f32 ratio=(f32)alpha/(f32)row[0x2ee];
        if(!(lbl_8053AAF8[0x82]&(u8)(1<<(i+4)))||*(s32*)(q+0x210)==0) {
            if(i>*(s32*)(p+0x1ac)+1) {
                ((u8*)&rec.w10)[0]=0x80;((u8*)&rec.w10)[1]=0x80;((u8*)&rec.w10)[2]=0x80;
                ((u8*)&rec.w10)[3]=(u8)(lbl_805437A8*ratio);
            } else ((u8*)&rec.w10)[3]=(u8)(lbl_80543718*ratio);
            MenuSprite803F(pos,0x10,rec,base);
        } else {
            s32 v=*(s32*)(q+0x210);
            ((u8*)&rec.w10)[3]=(u8)(lbl_80543718*ratio);
            if(v<=10) MenuSprite803F(pos,0xdb,rec,base);
            else if(v<=36) MenuSprite803F(pos,(v-10)/2+0xdb,rec,base);
            else if(v<100) MenuSprite803F(pos,0xe8,rec,base);
            else {const s32* sequence=(const s32*)(base+0x40);s32 index=v-100;s32 id=sequence[index]+0x10;MenuSprite803F(pos,id,rec,base);}
        }
    }
    fn_8013B490(lbl_8053AB10);
    if(*(s32*)(p+0x1c4)==6) fn_804316EC(lbl_8053AEC0);
    fn_80440EE8(lbl_8053AED8);
}
#pragma opt_common_subs reset
extern "C" void fn_803F5410(u8* p) {
    int state = *(s32*)(p + 0x1c4);
    u8* base = (u8*)lbl_80478A60;
    u8* q;
    f32 cursorX;
    f32 baseY;
    f32 f28;
    f32 f29;
    f32 f27;
    f32 f31;
    f32 f30;
    f32 f3;
    if (state != 2) {
        if (*(s32*)(p + 0x1d0) < 0x1e) {
            f3 = MenuSquare803F(*(s32*)(p + 0x1d0)) / lbl_8054377C;
        } else {
            f3 = lbl_80543730 - MenuSquare803F(*(s32*)(p + 0x1d0) - 0x1e) / lbl_8054377C;
        }
        f30 = f3 * (f32)*(u8*)(p + 0x258);
    } else {
        if (*(s32*)(p + 0x1d0) < 0xf) {
            f3 = MenuSquare803F(*(s32*)(p + 0x1d0)) / lbl_8054378C;
        } else {
            f3 = lbl_80543730 - MenuSquare803F(*(s32*)(p + 0x1d0) - 0xf) / lbl_8054378C;
        }
        f30 = lbl_80543790 * f3;
    }
    s32 r0;
    if (state == 1 || (state == 2 && *(s16*)(p + 0x240) <= 10)) {
        r0 = *(s16*)(p + 0x240);
        if (r0 < 5) { r0 = *(s16*)(p + 0x240); } else { r0 = 10 - r0; }
    } else {
        r0 = 0;
    }
    f31 = lbl_805437AC * f3;
    f27 = lbl_80543784 * MenuSquare803F(r0) / lbl_80543788;
    q = p;
    const u64* a = (const u64*)(base + 0xe60);
    const u64* b = (const u64*)(base + 0xe78);
    const u64* c = (const u64*)(base + 0xe90);
    for (s32 i = 0; i < 3; i++, q += 4, a++, b++, c++) {
        if (i == *(s32*)(p + 0x1ac)) {
            f28 = ((J2DPane*)*(void**)(p + 4))->search(*a)->getBounds()->i.x;
            ((J2DPane*)*(void**)(p + 4))->search(*a)->move(f28, *(f32*)(q + 0x124) + f27);
            if (i == 0) {
                baseY = ((J2DPane*)*(void**)(p + 4))->search(0x50736375726f3032ULL)->getBounds()->i.x;
                ((J2DPane*)*(void**)(p + 4))->search(0x50736375726f3032ULL)->move(baseY, *(f32*)(p + 0xf0) + f27);
            } else {
                baseY = ((J2DPane*)*(void**)(p + 4))->search(*(u64*)(base + 0xe60))->getBounds()->i.y;
                f32 t = ((J2DPane*)*(void**)(p + 4))->search(*a)->getBounds()->i.y;
                baseY = (*(f32*)(p + 0xf0) + t) - baseY;
                cursorX = ((J2DPane*)*(void**)(p + 4))->search(0x50736375726f3032ULL)->getBounds()->i.x;
                ((J2DPane*)*(void**)(p + 4))->search(0x50736375726f3032ULL)->move(cursorX, baseY);
            }
            ((J2DPane*)*(void**)(p + 4))->search(*b)->hide();
            ((J2DPane*)*(void**)(p + 4))->search(*c)->show();
            ((J2DPane*)*(void**)(p + 4))->search(*c)->setAlpha((u8)f31);
        } else {
            f29 = ((J2DPane*)*(void**)(p + 4))->search(*a)->getBounds()->i.x;
            ((J2DPane*)*(void**)(p + 4))->search(*a)->move(f29, *(f32*)(q + 0x124));
            ((J2DPane*)*(void**)(p + 4))->search(*b)->show();
            ((J2DPane*)*(void**)(p + 4))->search(*c)->hide();
        }
    }
    ((J2DPane*)*(void**)(p + 4))->search(0x50736375726f3031ULL)->setAlpha((u8)f30);
    ((J2DPane*)*(void**)(p + 4))->search(0x50736375726f3032ULL)->setAlpha((u8)f30);
    draw__9J2DScreenFffPC14J2DGrafContext(*(void**)(p + 4), lbl_8054372C, lbl_8054372C, ((void**)lbl_8053AB10)[4]);
    fn_80440EE8(lbl_8053AED8);
}
#pragma opt_lifetimes reset
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

extern "C" void fn_803F5A0C(u8* this_) {
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

extern const f32 lbl_805437B0;
extern const f32 lbl_805437B4;
extern const f32 lbl_805437B8;
extern const f32 lbl_805437BC;
extern const f32 lbl_80543748;
#pragma opt_common_subs off
#pragma opt_propagation on
#pragma opt_lifetimes on
extern "C" void fn_803F726C(u8* p){
u8* base = (u8*)lbl_80478A60;
f32 fade;
s16 buf[3];s16* order;s16* dest;
s32 start,stop,offset,j,i;
T803FC46C* const obj=(T803FC46C*)p;
if(*(s32*)(p+0x1ac)!=2){
s32 t=*(s32*)(p+0x210);
if(t<100)*(s32*)(p+0x210)=0;
else if(t<112)*(s32*)(p+0x210)=t+1;
else if(t<212)*(s32*)(p+0x210)=112;
else{*(s32*)(p+0x210)=t+1;if(*(s32*)(p+0x210)>=224)*(s32*)(p+0x210)=0;}
}
++*(s16*)(p+0x240);
if(*(s16*)(p+0x240)>20){
if(*(s16*)(p+0x240)<28){
s32 d=*(s16*)(p+0x240)-20;*(f32*)(p+0x164)=lbl_80543754*(MenuSquare803F(d)*lbl_805437B0);
fade=(f32)(8-(*(s16*)(p+0x240)-20))*lbl_805437B4;
if(fade<lbl_8054372C)fade=lbl_8054372C;else if(fade>lbl_80543730)fade=lbl_80543730;
{const u64* tags=(const u64*)(base+0x5f0);s32 i;for(i=0;i<20;i++,tags++){J2DPane* pane=(*(J2DPane**)(p+0xc))->search(*tags);f32 value=p[0x312+i];value*=fade;((Tu803FVObj*)pane)->v9((s32)value);}}
}else{*(f32*)(p+0x164)=lbl_80543754;
{const u64* tags=(const u64*)(base+0x5f0);s32 i;for(i=0;i<20;i++,tags++){J2DPane* pane=(*(J2DPane**)(p+0xc))->search(*tags);f32 value=p[0x312+i];value*=lbl_8054372C;((Tu803FVObj*)pane)->v9((s32)value);}}
}}
if(*(s16*)(p+0x240)>0){if(*(s16*)(p+0x240)<10){s32 d=*(s16*)(p+0x240);*(f32*)(p+0x168)=lbl_80543754*(MenuSquare803F(d)/lbl_805437B8);}else *(f32*)(p+0x168)=lbl_80543754;}
order=buf;dest=order;
for(i=0;i<3;i++)if(i!=*(s32*)(p+0x1a8))*dest++=i;
if(*(s32*)(p+0x1cc)==0){
 start=0;j=0;offset=start;stop=10;
 for(;j<3;j++,stop+=10,offset+=30,start+=10){
 if(*(s16*)(p+0x240)>start){if(*(s16*)(p+0x240)<stop){s32 g=j;s32 d=*(s16*)(p+0x240)-start;
obj->groupMotion[g]=lbl_8054375C*(MenuSquare803F(d)/lbl_805437B8);
fade=(f32)(10-(*(s16*)(p+0x240)-offset))/lbl_805437BC;
if(fade<lbl_8054372C)fade=lbl_8054372C;else if(fade>lbl_80543730)fade=lbl_80543730;
{const u64* tags=(const u64*)(base+0x690)+g*5;u8* bytes=p+g*5;s32 i;for(i=0;i<5;i++,tags++,bytes++){J2DPane* pane=(*(J2DPane**)(p+0xc))->search(*tags);f32 value=bytes[0x326];value*=fade;((Tu803FVObj*)pane)->v9((s32)value);}}}else{s32 g=j;obj->groupMotion[g]=lbl_8054375C;{const u64* tags=(const u64*)(base+0x690)+g*5;u8* bytes=p+g*5;s32 i;for(i=0;i<5;i++,tags++,bytes++){J2DPane* pane=(*(J2DPane**)(p+0xc))->search(*tags);f32 value=bytes[0x326];value*=lbl_8054372C;((Tu803FVObj*)pane)->v9((s32)value);}}}}
}
}else{
 start=0;j=0;offset=start;stop=10;
 for(;j<2;j++,stop+=10,order++,offset+=30,start+=10){
 if(*(s16*)(p+0x240)>start){if(*(s16*)(p+0x240)<stop){s16 g=*order;s32 d=*(s16*)(p+0x240)-start;
obj->groupMotion[g]=lbl_8054375C*(MenuSquare803F(d)/lbl_805437B8);
fade=(f32)(10-(*(s16*)(p+0x240)-offset))/lbl_805437BC;
if(fade<lbl_8054372C)fade=lbl_8054372C;else if(fade>lbl_80543730)fade=lbl_80543730;
{const u64* tags=(const u64*)(base+0x690)+g*5;u8* bytes=p+g*5;s32 i;for(i=0;i<5;i++,tags++,bytes++){J2DPane* pane=(*(J2DPane**)(p+0xc))->search(*tags);f32 value=bytes[0x326];value*=fade;((Tu803FVObj*)pane)->v9((s32)value);}}}else{s16 g=*order;obj->groupMotion[g]=lbl_8054375C;{const u64* tags=(const u64*)(base+0x690)+g*5;u8* bytes=p+g*5;s32 i;for(i=0;i<5;i++,tags++,bytes++){J2DPane* pane=(*(J2DPane**)(p+0xc))->search(*tags);f32 value=bytes[0x326];value*=lbl_8054372C;((Tu803FVObj*)pane)->v9((s32)value);}}}}
 }
 if(*(s16*)(p+0x240)>15){if(*(s16*)(p+0x240)<23){s32 g=*(s32*)(p+0x1a8);s32 d=*(s16*)(p+0x240)-15;
obj->groupMotion[g]=lbl_8054375C*(MenuSquare803F(d)*lbl_805437B0);
g=*(s32*)(p+0x1a8);
fade=(f32)(8-(*(s16*)(p+0x240)-15))*lbl_805437B4;
if(fade<lbl_8054372C)fade=lbl_8054372C;else if(fade>lbl_80543730)fade=lbl_80543730;
{const u64* tags=(const u64*)(base+0x690)+g*5;u8* bytes=p+g*5;s32 i;for(i=0;i<5;i++,tags++,bytes++){J2DPane* pane=(*(J2DPane**)(p+0xc))->search(*tags);f32 value=bytes[0x326];value*=fade;((Tu803FVObj*)pane)->v9((s32)value);}}}else{s32 g=*(s32*)(p+0x1a8);obj->groupMotion[g]=lbl_8054375C;g=*(s32*)(p+0x1a8);{const u64* tags=(const u64*)(base+0x690)+g*5;u8* bytes=p+g*5;s32 i;for(i=0;i<5;i++,tags++,bytes++){J2DPane* pane=(*(J2DPane**)(p+0xc))->search(*tags);f32 value=bytes[0x326];value*=lbl_8054372C;((Tu803FVObj*)pane)->v9((s32)value);}}}}
}
if(*(s16*)(p+0x240)>15){if(*(s16*)(p+0x240)<23){
s32 d=*(s16*)(p+0x240)-15;*(f32*)(p+0x198)=lbl_80543760*(MenuSquare803F(d)*lbl_805437B0);
fade=(f32)(8-(*(s16*)(p+0x240)-15))*lbl_805437B4;if(fade<lbl_8054372C)fade=lbl_8054372C;else if(fade>lbl_80543730)fade=lbl_80543730;
{const u64* tags=(const u64*)(base+0x708);s32 i;for(i=0;i<26;i++,tags++){J2DPane* pane=(*(J2DPane**)(p+0xc))->search(*tags);f32 value=p[0x335+i];value*=fade;((Tu803FVObj*)pane)->v9((s32)value);}}
}else{*(f32*)(p+0x198)=lbl_80543760;{const u64* tags=(const u64*)(base+0x708);s32 i;for(i=0;i<26;i++,tags++){J2DPane* pane=(*(J2DPane**)(p+0xc))->search(*tags);f32 value=p[0x335+i];value*=lbl_8054372C;((Tu803FVObj*)pane)->v9((s32)value);}}}}
if(*(s16*)(p+0x240)>=48){
if(*(s32*)(p+0x1cc)==0){*(s32*)(p+0x1c8)=*(s32*)(p+0x1c4);*(s32*)(p+0x1c4)=13;*(s32*)(p+0x350)=6;
u8* data=lbl_80529DEC;data[0x23e]=0;
if(*(s32*)(p+0x1ac)==1&&*(s32*)(data+0x64)==-1){
union{u32 bits;f32 value;}random;u8* game=lbl_8053AAF8;
*(u32*)(game+0xb4)=*(u32*)(game+0xb4)*0x19660d+0x3c6ef35f;random.bits=(*(u32*)(game+0xb4)>>9)|0x3f800000;
s32 choice=(s32)(lbl_80543748*(random.value-lbl_80543730));if(choice>=3)choice=2;*(s32*)(data+0x64)=choice;
}}
else if(*(s32*)(p+0x1a8)==0){*(s32*)(p+0x1c8)=*(s32*)(p+0x1c4);*(s32*)(p+0x1c4)=13;*(s32*)(p+0x350)=6;
u8* data=lbl_80529DEC;data[0x23e]=0;
if(*(s32*)(p+0x1ac)==1&&*(s32*)(data+0x64)==-1){
union{u32 bits;f32 value;}random;u8* game=lbl_8053AAF8;
*(u32*)(game+0xb4)=*(u32*)(game+0xb4)*0x19660d+0x3c6ef35f;random.bits=(*(u32*)(game+0xb4)>>9)|0x3f800000;
s32 choice=(s32)(lbl_80543748*(random.value-lbl_80543730));if(choice>=3)choice=2;*(s32*)(data+0x64)=choice;
}}
else if(*(s32*)(p+0x1a8)==1){if(p[0x25e]==0){*(s32*)(p+0x1cc)=10;p[0x25e]=1;}}
else if(p[0x25e]==0){*(s32*)(p+0x1cc)=12;p[0x25e]=1;}
*(s16*)(p+0x240)=0;
}
++*(s32*)(p+0x1d0);if(*(s32*)(p+0x1d0)>=30)*(s32*)(p+0x1d0)=0;
(*(J2DPane**)(p+0xc))->search(0x506d626162623037ULL)->move(*(f32*)(p+0x15c),*(f32*)(p+0x160)+*(f32*)(p+0x164));
fn_80402E08(*(void**)(p+0x74),lbl_8054372C,*(f32*)(p+0x168));
(*(J2DPane**)(p+0xc))->search(0x0050737461623034ULL)->move(*(f32*)(p+0x16c)+*(f32*)(p+0x184),*(f32*)(p+0x178));
(*(J2DPane**)(p+0xc))->search(0x005068616e623034ULL)->move(*(f32*)(p+0x170)+*(f32*)(p+0x188),*(f32*)(p+0x17c));
(*(J2DPane**)(p+0xc))->search(0x0000507275623034ULL)->move(*(f32*)(p+0x174)+*(f32*)(p+0x18c),*(f32*)(p+0x180));
(*(J2DPane**)(p+0xc))->search(0x506c69626b6b3033ULL)->move(*(f32*)(p+0x190)+*(f32*)(p+0x198),*(f32*)(p+0x194));
f32 y=(*(J2DPane**)(p+0xc))->search(0x50736375726f3032ULL)->getBounds()->i.y;
(*(J2DPane**)(p+0xc))->search(0x50736375726f3032ULL)->move(*(f32*)(p+0xf4)+obj->groupMotion[*(s32*)(p+0x1a8)],y);
}
#pragma opt_common_subs reset
#pragma fp_contract reset
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
                fn_803F2580(p);
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
#pragma opt_propagation reset
#pragma opt_lifetimes reset
extern const f32 lbl_805437B8;
extern const f32 lbl_805437BC;
extern const f32 lbl_805437C0;
extern const f32 lbl_805437C4;
#pragma opt_common_subs off
extern "C" void fn_803F8354(u8* p) {
    u8* base = (u8*)lbl_80478A60;
    f32 a;
    int start;
    s32 stop;
    s32 offset;
    s32 k;
    (*(s16*)(p + 0x240))++;
    if (*(s16*)(p + 0x240) <= 0) {
    } else if (*(s16*)(p + 0x240) < 0x19) {
        *(f32*)(p + 0x164) = lbl_80543754 * (MenuSquare803F(0x19 - *(s16*)(p + 0x240)) / lbl_805437C0);
        a = (f32)*(s16*)(p + 0x240) / lbl_80543788;
        if (a < lbl_8054372C) {
            a = lbl_8054372C;
        } else if (a > lbl_80543730) {
            a = lbl_80543730;
        }
        tu803F_setAlphas(p, (u64*)(base + 0x5f0), p + 0x312, 20, a);
    } else {
        *(f32*)(p + 0x164) = lbl_8054372C;
        tu803F_setAlphas(p, (u64*)(base + 0x5f0), p + 0x312, 20, lbl_80543730);
    }
    if (*(s16*)(p + 0x240) > 0x19) {
        if (*(s16*)(p + 0x240) < 0x2d) {
            *(f32*)(p + 0x168) = lbl_80543754 * (MenuSquare803F(0x14 - (*(s16*)(p + 0x240) - 0x19)) / lbl_80543778);
        } else {
            *(f32*)(p + 0x168) = lbl_8054372C;
        }
    }
    start = 0;
    k = 0;
    offset = start;
    stop = 15;
    for (; k < 3; k++, start += 10, offset += 10, stop += 10) {
        if (*(s16*)(p + 0x240) > start) {
            if (*(s16*)(p + 0x240) < stop) {
                *(f32*)(p + 0x184 + k * 4) = lbl_8054375C * (MenuSquare803F(15 - (*(s16*)(p + 0x240) - offset)) / lbl_8054378C);
                a = (f32)(*(s16*)(p + 0x240) - offset) / lbl_805437C4;
                if (a < lbl_8054372C) {
                    a = lbl_8054372C;
                } else if (a > lbl_80543730) {
                    a = lbl_80543730;
                }
                tu803F_setAlphas(p, (u64*)(base + 0x690) + k * 5, p + 0x326 + k * 5, 5, a);
            } else {
                *(f32*)(p + 0x184 + k * 4) = lbl_8054372C;
                tu803F_setAlphas(p, (u64*)(base + 0x690) + k * 5, p + 0x326 + k * 5, 5, lbl_80543730);
            }
        }
    }
    if (*(s16*)(p + 0x240) <= 0) {
    } else if (*(s16*)(p + 0x240) < 15) {
        *(f32*)(p + 0x198) = lbl_80543760 * (MenuSquare803F(15 - *(s16*)(p + 0x240)) / lbl_8054378C);
        a = (f32)*(s16*)(p + 0x240) / lbl_805437C4;
        if (a < lbl_8054372C) {
            a = lbl_8054372C;
        } else if (a > lbl_80543730) {
            a = lbl_80543730;
        }
        tu803F_setAlphas(p, (u64*)(base + 0x708), p + 0x335, 26, a);
    } else {
        *(f32*)(p + 0x198) = lbl_8054372C;
        tu803F_setAlphas(p, (u64*)(base + 0x708), p + 0x335, 26, lbl_80543730);
    }
    if (*(s16*)(p + 0x240) >= 0x4b) {
        *(s16*)(p + 0x240) = 0;
        fn_803F2660(p);
    }
    (*(J2DPane**)(p + 0xc))->search(0x506d626162623037ULL)->move(*(f32*)(p + 0x15c), *(f32*)(p + 0x160) + *(f32*)(p + 0x164));
    fn_80402E08(*(void**)(p + 0x74), lbl_8054372C, *(f32*)(p + 0x168));
    (*(J2DPane**)(p + 0xc))->search(0x0050737461623034ULL)->move(*(f32*)(p + 0x16c) + *(f32*)(p + 0x184), *(f32*)(p + 0x178));
    (*(J2DPane**)(p + 0xc))->search(0x005068616e623034ULL)->move(*(f32*)(p + 0x170) + *(f32*)(p + 0x188), *(f32*)(p + 0x17c));
    (*(J2DPane**)(p + 0xc))->search(0x0000507275623034ULL)->move(*(f32*)(p + 0x174) + *(f32*)(p + 0x18c), *(f32*)(p + 0x180));
    (*(J2DPane**)(p + 0xc))->search(0x506c69626b6b3033ULL)->move(*(f32*)(p + 0x190) + *(f32*)(p + 0x198), *(f32*)(p + 0x194));
    f32 y = (*(J2DPane**)(p + 0xc))->search(0x50736375726f3032ULL)->getBounds()->i.y;
    (*(J2DPane**)(p + 0xc))->search(0x50736375726f3032ULL)->move(*(f32*)(p + 0xf4), y);
}
#pragma opt_common_subs reset
extern "C" void fn_803F8AE4(u8* p) {
    s32 i;
    f32 span;
    void* r;
    u32 t1;
    u32 t2;
    JGeometry::TVec3f v1;
    JGeometry::TVec3f v2;

    if (p[0x25c] == 0xff) {
        fn_80431A9C(lbl_8053AEC0, 0xc4, (u8)(*(s32*)(p + 0x1ac) + 2), 0);
        p[0x25c] = 0;
        *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
        *(s32*)(p + 0x1c4) = 6;
    } else if (fn_80309C4C(lbl_8053AD30, 0x1100, lbl_80529DEC[0x23d] + 2)) {
        if (*(s32*)(p + 0x1c0) == *(s32*)(p + 0x1ac) + 2) {
            *(s32*)(p + 0x1a8) = 0;
            for (i = 0; i < 4; i++) {
                *(s32*)(p + i * 4 + 0x1e0) = fn_80403414(i);
                *(s32*)(p + i * 4 + 0x1f0) = fn_804033D4(i);
                *(s32*)(p + i * 4 + 0x200) = fn_8040336C(i);
            }
            *(s32*)(p + 0x1b0) = 1;
            *(s32*)(p + 0x1b4) = 1;
            *(s32*)(p + 0x1b8) = 1;
            *(s32*)(p + 0x1bc) = 1;
            *(s16*)(p + 0x240) = 0;
            *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
            *(s32*)(p + 0x1c4) = 4;
            fn_80458880(lbl_8053AF80, 0xb, -1);
        } else {
            fn_80431A9C(lbl_8053AEC0, 0xc4, (u8)(*(s32*)(p + 0x1ac) + 2), 0);
            p[0x25c] = 0;
            *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
            *(s32*)(p + 0x1c4) = 6;
        }
    } else if (fn_80309C4C(lbl_8053AD30, 0x200, lbl_80529DEC[0x23d] + 2)) {
        (((T803FC46C*)p)->*lbl_804B0BDC[0])();
        fn_80458880(lbl_8053AF80, 0xc, -1);
    }

    *(s32*)(p + 0x1d0) += 1;
    if (*(s32*)(p + 0x1d0) >= 0x3c) {
        *(s32*)(p + 0x1d0) = 0;
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

extern const f32 lbl_805437B0;
extern const f32 lbl_805437B4;
extern const f32 lbl_80543748;
static inline void fadePanes803F(u8* p, const u64* tags, s32 n, s32 ofs, f32 fade) {
    for (s32 i = 0; i < n; i++, tags++) {
        J2DPane* pane = (*(J2DPane**)(p + 8))->search(tags[0]);
        f32 alpha = p[ofs + i];
        alpha *= fade;
        pane->setAlpha((u8)alpha);
    }
}


#pragma opt_common_subs off
extern "C" void fn_803F943C(u8* p) {
    u8* base = (u8*)lbl_80478A60;
    s32 i;
    int start;
    s32 stop;
    s32 offset;
    s32 j;
    f32 fade;
    *(s16*)(p+0x240)+=1;
    if(*(s16*)(p+0x240)>0) {
        if(*(s16*)(p+0x240)<8) {
            *(f32*)(p+0x9c)=lbl_80543764*((f32)(*(s16*)(p+0x240)* *(s16*)(p+0x240))/64.0f);
            *(f32*)(p+0xa8)=lbl_80543768*((f32)(*(s16*)(p+0x240)* *(s16*)(p+0x240))/64.0f);
            fade=(f32)(8-*(s16*)(p+0x240))*lbl_805437B4;
            if(fade<lbl_8054372C) fade=lbl_8054372C;
            else if(fade>lbl_80543730) fade=lbl_80543730;
            fadePanes803F(p, (const u64*)(base+0x3c0), 0x22, 0x2c4, fade);
            fade=(f32)(8-*(s16*)(p+0x240))*lbl_805437B4;
            if(fade<lbl_8054372C) fade=lbl_8054372C;
            else if(fade>lbl_80543730) fade=lbl_80543730;
            fadePanes803F(p, (const u64*)(base+0x338), 0xb, 0x2af, fade);
        } else {
            *(f32*)(p+0x9c)=lbl_80543764;
            *(f32*)(p+0xa8)=lbl_80543768;
            fadePanes803F(p, (const u64*)(base+0x3c0), 0x22, 0x2c4, lbl_8054372C);
            fadePanes803F(p, (const u64*)(base+0x338), 0xb, 0x2af, lbl_8054372C);
        }
    }
    if(*(s16*)(p+0x240)>0) {
        if(*(s16*)(p+0x240)<8) {
            *(f32*)(p+0xb4)=lbl_80543754*((f32)(*(s16*)(p+0x240)* *(s16*)(p+0x240))/64.0f);
            *(f32*)(p+0xb8)=lbl_80543754*((f32)(*(s16*)(p+0x240)* *(s16*)(p+0x240))/64.0f);
            fade=(f32)(8-*(s16*)(p+0x240))*lbl_805437B4;
            if(fade<lbl_8054372C) fade=lbl_8054372C;
            else if(fade>lbl_80543730) fade=lbl_80543730;
            fadePanes803F(p, (const u64*)(base+0x390), 6, 0x2ba, fade);
        } else {
            *(f32*)(p+0xb4)=lbl_80543754;
            *(f32*)(p+0xb8)=lbl_80543754;
            fadePanes803F(p, (const u64*)(base+0x390), 6, 0x2ba, lbl_8054372C);
        }
    }
    start=0;
    j=0;
    offset=start;
    stop=8;
    for(;j<4;j++,start+=5,stop+=5,offset+=5) {
        if(*(s16*)(p+0x240)>start) {
            if(*(s16*)(p+0x240)<stop) {
                s32 group=3-j;
                s32 d=*(s16*)(p+0x240)-offset;
                *(f32*)(p+0xdc+group*4)=lbl_8054376C*((f32)(d*d)/64.0f);
                fade=(f32)(8-(*(s16*)(p+0x240)-offset))*lbl_805437B4;
                if(fade<lbl_8054372C) fade=lbl_8054372C;
                else if(fade>lbl_80543730) fade=lbl_80543730;
                u8* alphaBase=p+group*9;
                const u64* groupTags=(const u64*)(base+0x4d0);
                groupTags+=group*9;
                for(i=0;i<9;i++,alphaBase++,groupTags++) {
                    J2DPane* pane=(*(J2DPane**)(p+8))->search(groupTags[0]);
                    f32 alpha=alphaBase[0x2ee];
                    alpha*=fade;
                    pane->setAlpha((u8)alpha);
                }
            } else {
                s32 group=3-j;
                *(f32*)(p+0xdc+group*4)=lbl_8054376C;
                u8* alphaBase=p+group*9;
                const u64* groupTags=(const u64*)(base+0x4d0);
                groupTags+=group*9;
                for(i=0;i<9;i++,alphaBase++,groupTags++) {
                    J2DPane* pane=(*(J2DPane**)(p+8))->search(groupTags[0]);
                    f32 alpha=alphaBase[0x2ee];
                    alpha*=lbl_8054372C;
                    pane->setAlpha((u8)alpha);
                }
            }
        }
    }
    if(*(s16*)(p+0x240)>=23) {
        s32 bits=0;
        for(s32 k=0;k<4;k++) {
            if(k<*(s32*)(p+0x1ac)+2) {
                lbl_8053AAF8[0x82]|=(u8)(1<<k);
                u8* game=lbl_8053AAF8;
                game[0x83]&=~(u8)(3<<bits);
                game[0x83]|=(u8)(1<<bits);
            } else {
                lbl_8053AAF8[0x82]&=~(u8)(1<<k);
                lbl_8053AAF8[0x83]&=~(u8)(3<<bits);
            }
            bits+=2;
        }
        if(*(s32*)(p+0x1c0)==*(s32*)(p+0x1ac)+2) {
            *(s32*)(p+0x1c8)=*(s32*)(p+0x1c4);
            *(s32*)(p+0x1c4)=13;
            *(s32*)(p+0x350)=6;
            u8* data=lbl_80529DEC;
            data[0x23e]=0;
            if(*(s32*)(p+0x1ac)==1 && *(s32*)(data+0x64)==-1) {
                union { u32 bits; f32 value; } random;
                u8* game=lbl_8053AAF8;
                *(u32*)(game+0xb4)=*(u32*)(game+0xb4)*0x19660d+0x3c6ef35f;
                random.bits=(*(u32*)(game+0xb4)>>9)|0x3f800000;
                s32 choice=(s32)(lbl_80543748*(random.value-lbl_80543730));
                if(choice>=3) choice=2;
                *(s32*)(data+0x64)=choice;
            }
        } else {
            fn_803F2B78(p);
        }
        *(s16*)(p+0x240)=0;
    }
    (*(J2DPane**)(p+8))->search(0x4e646174613033ULL)->move(*(f32*)(p+0x94),*(f32*)(p+0x98)+*(f32*)(p+0x9c));
    (*(J2DPane**)(p+8))->search(0x4e646174613035ULL)->move(*(f32*)(p+0xa0),*(f32*)(p+0xa4)+*(f32*)(p+0xa8));
    (*(J2DPane**)(p+8))->search(0x4e646174613036ULL)->move(*(f32*)(p+0xac),*(f32*)(p+0xb0)+*(f32*)(p+0xb4));
    fn_80402E08(*(void**)(p+0x74),lbl_8054372C,*(f32*)(p+0xb8));
    (*(J2DPane**)(p+8))->search(0x50706c6c626b3032ULL)->move(*(f32*)(p+0xbc),*(f32*)(p+0xcc)+*(f32*)(p+0xdc));
    (*(J2DPane**)(p+8))->search(0x50706c6c626b3132ULL)->move(*(f32*)(p+0xc0),*(f32*)(p+0xd0)+*(f32*)(p+0xe0));
    (*(J2DPane**)(p+8))->search(0x50706c6c626b3232ULL)->move(*(f32*)(p+0xc4),*(f32*)(p+0xd4)+*(f32*)(p+0xe4));
    (*(J2DPane**)(p+8))->search(0x50706c6c626b3332ULL)->move(*(f32*)(p+0xc8),*(f32*)(p+0xd8)+*(f32*)(p+0xe8));
}

extern const f32 lbl_805437D0;
extern "C" void fn_803F9EA8(u8* p) {
    u8* base = (u8*)lbl_80478A60;
    s32 i;
    int start;
    s32 stop;
    s32 offset;
    s32 j;
    f32 fade;
    f32 span;
    void* r;
    u32 t1;
    u32 t2;
    JGeometry::TVec3f v1;
    JGeometry::TVec3f v2;

    *(s16*)(p + 0x240) += 1;
    if (*(s16*)(p + 0x240) > 0) {
        if (*(s16*)(p + 0x240) < 0x19) {
            *(f32*)(p + 0x9c) = lbl_80543764 * tu803F_ease(0x19 - *(s16*)(p + 0x240), lbl_805437C0);
            *(f32*)(p + 0xa8) = lbl_80543768 * tu803F_ease(0x19 - *(s16*)(p + 0x240), lbl_805437C0);
            fade = (f32)*(s16*)(p + 0x240) / lbl_80543788;
            if (fade < lbl_8054372C) fade = lbl_8054372C;
            else if (fade > lbl_80543730) fade = lbl_80543730;
            fadePanes803F(p, (const u64*)(base + 0x3c0), 0x22, 0x2c4, fade);
            fade = (f32)*(s16*)(p + 0x240) / lbl_80543788;
            if (fade < lbl_8054372C) fade = lbl_8054372C;
            else if (fade > lbl_80543730) fade = lbl_80543730;
            fadePanes803F(p, (const u64*)(base + 0x338), 0xb, 0x2af, fade);
        } else {
            *(f32*)(p + 0xa8) = lbl_8054372C;
            *(f32*)(p + 0x9c) = lbl_8054372C;
            fadePanes803F(p, (const u64*)(base + 0x3c0), 0x22, 0x2c4, lbl_80543730);
            fadePanes803F(p, (const u64*)(base + 0x338), 0xb, 0x2af, lbl_80543730);
        }
    }
    if (*(s16*)(p + 0x240) > 0x19) {
        if (*(s16*)(p + 0x240) < 0x2d) {
            *(f32*)(p + 0xb4) = lbl_80543754 * tu803F_ease(0x14 - (*(s16*)(p + 0x240) - 0x19), lbl_80543778);
            *(f32*)(p + 0xb8) = lbl_80543754 * tu803F_ease(0x14 - (*(s16*)(p + 0x240) - 0x19), lbl_80543778);
            fade = (f32)(*(s16*)(p + 0x240) - 0x19) / lbl_805437D0;
            if (fade < lbl_8054372C) fade = lbl_8054372C;
            else if (fade > lbl_80543730) fade = lbl_80543730;
            fadePanes803F(p, (const u64*)(base + 0x390), 6, 0x2ba, fade);
        } else {
            *(f32*)(p + 0xb8) = lbl_8054372C;
            *(f32*)(p + 0xb4) = lbl_8054372C;
            fadePanes803F(p, (const u64*)(base + 0x390), 6, 0x2ba, lbl_80543730);
        }
    }
    start = 0;
    j = 0;
    offset = start;
    stop = 15;
    for (; j < 4; j++, start += 5, stop += 5, offset += 5) {
        if (*(s16*)(p + 0x240) > start) {
            if (*(s16*)(p + 0x240) < stop) {
                *(f32*)(p + 0xdc + j * 4) = lbl_8054376C * tu803F_ease(15 - (*(s16*)(p + 0x240) - offset), lbl_8054378C);
                fade = (f32)(*(s16*)(p + 0x240) - offset) / lbl_805437C4;
                if (fade < lbl_8054372C) fade = lbl_8054372C;
                else if (fade > lbl_80543730) fade = lbl_80543730;
                u8* alphaBase = p + j * 9;
                const u64* groupTags = (const u64*)(base + 0x4d0) + j * 9;
                for (i = 0; i < 9; i++, alphaBase++, groupTags++) {
                    J2DPane* pane = (*(J2DPane**)(p + 8))->search(groupTags[0]);
                    f32 alpha = alphaBase[0x2ee];
                    alpha *= fade;
                    pane->setAlpha((u8)alpha);
                }
            } else {
                *(f32*)(p + 0xdc + j * 4) = lbl_8054372C;
                u8* alphaBase = p + j * 9;
                const u64* groupTags = (const u64*)(base + 0x4d0) + j * 9;
                for (i = 0; i < 9; i++, alphaBase++, groupTags++) {
                    J2DPane* pane = (*(J2DPane**)(p + 8))->search(groupTags[0]);
                    f32 alpha = alphaBase[0x2ee];
                    alpha *= lbl_80543730;
                    pane->setAlpha((u8)alpha);
                }
            }
        }
    }

    *(s16*)(p + 0x248) += 1;
    if (*(s16*)(p + 0x248) >= 100) {
        *(s16*)(p + 0x248) = 0;
    }

    const u64* tags = (const u64*)(base + 0x7d8);
    for (i = 0; i < 4; i++) {
        if ((lbl_8053AAF8[0x82] & (u8)(1 << (i + 4))) && lbl_8054372C == *(f32*)(p + i * 4 + 0xdc)) {
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
                r = (*(J2DPane**)(p + 8))->search(tags[i]);
                span = *(f32*)((u8*)r + 0x28) - *(f32*)((u8*)r + 0x20);
                r = (*(J2DPane**)(p + 8))->search(tags[i]);
                *(f32*)(p + 0x88) = (lbl_805437A0 * (span * lbl_80543720 + *(f32*)((u8*)r + 0x30))) /
                                    (f32)(s32)*(u16*)(*(u8**)(sManager__8JUTVideo + 4) + 4);
                r = (*(J2DPane**)(p + 8))->search(tags[i]);
                span = *(f32*)((u8*)r + 0x2c) - *(f32*)((u8*)r + 0x24);
                r = (*(J2DPane**)(p + 8))->search(tags[i]);
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

    if (*(s16*)(p + 0x240) >= 0x4b) {
        *(s16*)(p + 0x240) = 0;
        *(s32*)(p + 0x1c8) = *(s32*)(p + 0x1c4);
        *(s32*)(p + 0x1c4) = 5;
    }
    (*(J2DPane**)(p+8))->search(0x4e646174613033ULL)->move(*(f32*)(p+0x94),*(f32*)(p+0x98)+*(f32*)(p+0x9c));
    (*(J2DPane**)(p+8))->search(0x4e646174613035ULL)->move(*(f32*)(p+0xa0),*(f32*)(p+0xa4)+*(f32*)(p+0xa8));
    (*(J2DPane**)(p+8))->search(0x4e646174613036ULL)->move(*(f32*)(p+0xac),*(f32*)(p+0xb0)+*(f32*)(p+0xb4));
    fn_80402E08(*(void**)(p+0x74),lbl_8054372C,*(f32*)(p+0xb8));
    (*(J2DPane**)(p+8))->search(0x50706c6c626b3032ULL)->move(*(f32*)(p+0xbc),*(f32*)(p+0xcc)+*(f32*)(p+0xdc));
    (*(J2DPane**)(p+8))->search(0x50706c6c626b3132ULL)->move(*(f32*)(p+0xc0),*(f32*)(p+0xd0)+*(f32*)(p+0xe0));
    (*(J2DPane**)(p+8))->search(0x50706c6c626b3232ULL)->move(*(f32*)(p+0xc4),*(f32*)(p+0xd4)+*(f32*)(p+0xe4));
    (*(J2DPane**)(p+8))->search(0x50706c6c626b3332ULL)->move(*(f32*)(p+0xc8),*(f32*)(p+0xd8)+*(f32*)(p+0xe8));
}

#pragma opt_common_subs off
extern "C" void fn_803FAA88(u8* p) {
 u8* base = (u8*)lbl_80478A60;
 s32 buf[3];
 s32 start,stop,offset,j;
 s32* order=buf;
 s32* dest=order;
 s32 i;
 f32 fade;
 for(i=0;i<3;i++)if(i!=*(s32*)(p+0x1ac))*dest++=i;
 ++*(s16*)(p+0x240);
 if(*(s16*)(p+0x240)>20){if(*(s16*)(p+0x240)<28){
 s32 d=*(s16*)(p+0x240)-20;
 fade=(f32)(d*d)*lbl_805437B0; *(f32*)(p+0x110)=lbl_80543770*fade;
 fade=(f32)(8-(*(s16*)(p+0x240)-20))*lbl_805437B4;if(fade<lbl_8054372C)fade=lbl_8054372C;else if(fade>lbl_80543730)fade=lbl_80543730;
{const u64* tags=(const u64*)(base+0xb8);s32 i;for(i=0;i<20;i++,tags++){J2DPane* pane=(*(J2DPane**)(p+4))->search(*tags);f32 value=p[0x25f+i];value*=fade;((Tu803FVObj*)pane)->v9((s32)value);}}
}else{*(f32*)(p+0x110)=lbl_80543770;{const u64* tags=(const u64*)(base+0xb8);s32 i;for(i=0;i<20;i++,tags++){J2DPane* pane=(*(J2DPane**)(p+4))->search(*tags);f32 value=p[0x25f+i];value*=lbl_8054372C;((Tu803FVObj*)pane)->v9((s32)value);}}
}}
 if(*(s16*)(p+0x240)>0){if(*(s16*)(p+0x240)<8){s32 d=*(s16*)(p+0x240);fade=(f32)(d*d)*lbl_805437B0; *(f32*)(p+0x114)=lbl_80543768*fade;}else *(f32*)(p+0x114)=lbl_80543768;}
 start=0;j=0;offset=start;stop=8;
 for(;j<2;j++,stop+=5,offset+=5,order++,start+=5){
 if(*(s16*)(p+0x240)>start){if(*(s16*)(p+0x240)<stop){
 s32 group=*order; s32 d=*(s16*)(p+0x240)-offset;fade=(f32)(d*d)*lbl_805437B0; *(f32*)(p+group*4+0x130)=lbl_80543774*fade;
 fade=(f32)(8-(*(s16*)(p+0x240)-offset))*lbl_805437B4;if(fade<lbl_8054372C)fade=lbl_8054372C;else if(fade>lbl_80543730)fade=lbl_80543730;
{u8* bytes=p+group*6;const u64* tags=(const u64*)(base+0x158)+group*6;s32 i;for(i=0;i<6;i++,tags++,bytes++){J2DPane* pane=(*(J2DPane**)(p+4))->search(*tags);f32 value=bytes[0x273];value*=fade;((Tu803FVObj*)pane)->v9((s32)value);}}
}else{s32 group=*order; *(f32*)(p+group*4+0x130)=lbl_80543774;{u8* bytes=p+group*6;const u64* tags=(const u64*)(base+0x158)+group*6;s32 i;for(i=0;i<6;i++,tags++,bytes++){J2DPane* pane=(*(J2DPane**)(p+4))->search(*tags);f32 value=bytes[0x273];value*=lbl_8054372C;((Tu803FVObj*)pane)->v9((s32)value);}}
}}}
 if(*(s16*)(p+0x240)>15){if(*(s16*)(p+0x240)<23){
 s32 group=*(s32*)(p+0x1ac);s32 d=*(s16*)(p+0x240)-15;fade=(f32)(d*d)*lbl_805437B0; *(f32*)(p+group*4+0x130)=lbl_80543774*fade;
 fade=(f32)(8-(*(s16*)(p+0x240)-15))*lbl_805437B4;if(fade<lbl_8054372C)fade=lbl_8054372C;else if(fade>lbl_80543730)fade=lbl_80543730;
{u8* bytes=p+group*6;const u64* tags=(const u64*)(base+0x158)+group*6;s32 i;for(i=0;i<6;i++,tags++,bytes++){J2DPane* pane=(*(J2DPane**)(p+4))->search(*tags);f32 value=bytes[0x273];value*=fade;((Tu803FVObj*)pane)->v9((s32)value);}}
}else{*(f32*)(p+*(s32*)(p+0x1ac)*4+0x130)=lbl_80543774;{s32 group=*(s32*)(p+0x1ac);u8* bytes=p+group*6;const u64* tags=(const u64*)(base+0x158)+group*6;s32 i;for(i=0;i<6;i++,tags++,bytes++){J2DPane* pane=(*(J2DPane**)(p+4))->search(*tags);f32 value=bytes[0x273];value*=lbl_8054372C;((Tu803FVObj*)pane)->v9((s32)value);}}
}}
 if(*(s16*)(p+0x240)>15){if(*(s16*)(p+0x240)<23){
 s32 d=*(s16*)(p+0x240)-15;fade=(f32)(d*d)*lbl_805437B0; f32 value=lbl_80543778*fade;
 *(f32*)(p+0x158)=value;*(f32*)(p+0x144)=value;
 fade=(f32)(8-(*(s16*)(p+0x240)-15))*lbl_805437B4;if(fade<lbl_8054372C)fade=lbl_8054372C;else if(fade>lbl_80543730)fade=lbl_80543730;
{const u64* tags=(const u64*)(base+0x1e8);s32 i;for(i=0;i<24;i++,tags++){J2DPane* pane=(*(J2DPane**)(p+4))->search(*tags);f32 value=p[0x285+i];value*=fade;((Tu803FVObj*)pane)->v9((s32)value);}}
{const u64* tags=(const u64*)(base+0x2a8);s32 i;for(i=0;i<18;i++,tags++){J2DPane* pane=(*(J2DPane**)(p+4))->search(*tags);f32 value=p[0x29d+i];value*=fade;((Tu803FVObj*)pane)->v9((s32)value);}}
}else{
 *(f32*)(p+0x158)=lbl_80543778;*(f32*)(p+0x144)=lbl_80543778;{const u64* tags=(const u64*)(base+0x1e8);s32 i;for(i=0;i<24;i++,tags++){J2DPane* pane=(*(J2DPane**)(p+4))->search(*tags);f32 value=p[0x285+i];value*=lbl_8054372C;((Tu803FVObj*)pane)->v9((s32)value);}}
{const u64* tags=(const u64*)(base+0x2a8);s32 i;for(i=0;i<18;i++,tags++){J2DPane* pane=(*(J2DPane**)(p+4))->search(*tags);f32 value=p[0x29d+i];value*=lbl_8054372C;((Tu803FVObj*)pane)->v9((s32)value);}}
}}
 if(*(s16*)(p+0x240)>=28){
 if(*(s32*)(p+0x1cc)==13){
 if(*(s32*)(p+0x1c0)==*(s32*)(p+0x1ac)+2){
 *(s32*)(p+0x1c8)=*(s32*)(p+0x1c4);*(s32*)(p+0x1c4)=13;*(s32*)(p+0x350)=6;
 u8* data=lbl_80529DEC;data[0x23e]=0;
 if(*(s32*)(p+0x1ac)==1 && *(s32*)(data+0x64)==-1){
 union{u32 bits;f32 value;} random;u8* game=lbl_8053AAF8;
 *(u32*)(game+0xb4)=*(u32*)(game+0xb4)*0x19660d+0x3c6ef35f;random.bits=(*(u32*)(game+0xb4)>>9)|0x3f800000;
 s32 choice=(s32)(lbl_80543748*(random.value-lbl_80543730));if(choice>=3)choice=2;*(s32*)(data+0x64)=choice;
 }}else fn_803F2B78(p);
 }else{p[0x25c]=0;(((T803FC46C*)p)->*lbl_804B0BDC[3])();}
 }
 if(*(s16*)(p+0x240)>=53)*(s16*)(p+0x240)=0;
 ++*(s32*)(p+0x1d0);if(*(s32*)(p+0x1d0)>=30)*(s32*)(p+0x1d0)=0;
 (*(J2DPane**)(p+4))->search(0x506d626162623037ULL)->move(*(f32*)(p+0x108),*(f32*)(p+0x10c)+*(f32*)(p+0x110));
 fn_80402E08(*(void**)(p+0x74),lbl_8054372C,*(f32*)(p+0x114));
(*(J2DPane**)(p+4))->search(0x00506e6f70623038ULL)->move(*(f32*)(p+280)+*(f32*)(p+304),*(f32*)(p+296));
(*(J2DPane**)(p+4))->search(0x00506e6f70623132ULL)->move(*(f32*)(p+284)+*(f32*)(p+308),*(f32*)(p+300));
(*(J2DPane**)(p+4))->search(0x00506e6f70623136ULL)->move(*(f32*)(p+288)+*(f32*)(p+312),*(f32*)(p+304));
(*(J2DPane**)(p+4))->search(0x004e646174613032ULL)->move(*(f32*)(p+316)+*(f32*)(p+324),*(f32*)(p+320));
(*(J2DPane**)(p+4))->search(0x004e646174613035ULL)->move(*(f32*)(p+328)+*(f32*)(p+344),*(f32*)(p+332));
(*(J2DPane**)(p+4))->search(0x004e646174613037ULL)->move(*(f32*)(p+336)+*(f32*)(p+344),*(f32*)(p+340));
f32 y=((f32*)(*(J2DPane**)(p+4))->search(0x50736375726f3032ULL)->getBounds())[1];
 (*(J2DPane**)(p+4))->search(0x50736375726f3032ULL)->move(*(f32*)(p+0xec)+*(f32*)(p+*(s32*)(p+0x1ac)*4+0x130),y);
 }
#pragma opt_common_subs reset
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

#pragma opt_common_subs off
#pragma opt_propagation off
extern "C" void fn_803FB9E4(u8* self) {
    u8* base = (u8*)lbl_80478A60;
    s32 j;
    s32 i;
    f32 t;
    ++*(s16*)(self+0x240);
    s32 time=*(s16*)(self+0x240);
    if(time>0) {
        if(time<25) {
            s32 d=25-time;
            f32 fraction=(f32)(d*d)/lbl_805437C0;
            *(f32*)(self+0x110)=lbl_80543770*fraction;
            t=(f32)*(s16*)(self+0x240)/lbl_80543788;
            if(t<lbl_8054372C) t=lbl_8054372C;
            else if(t>lbl_80543730) t=lbl_80543730;
            {
                u64* names=(u64*)(base+0xb8);
                s32 i;
                for(i=0;i<20;i++,names++) {
                    J2DPane* pane=(*(J2DPane**)(self+4))->search(*names);
                    f32 value=self[0x25f+i];
                    value*=t;
                    ((Tu803FVObj*)pane)->v9((s32)value);
                }
            }
        } else {
            *(f32*)(self+0x110)=lbl_8054372C;
            {
                u64* names=(u64*)(base+0xb8);
                s32 i;
                for(i=0;i<20;i++,names++) {
                    J2DPane* pane=(*(J2DPane**)(self+4))->search(*names);
                    f32 value=self[0x25f+i];
                    value*=lbl_80543730;
                    ((Tu803FVObj*)pane)->v9((s32)value);
                }
            }
        }
    }
    time=*(s16*)(self+0x240);
    if(time>25) {
        if(time<45) {
            s32 d=20-(time-25);
            f32 fraction=(f32)(d*d)/lbl_80543778;
            *(f32*)(self+0x114)=lbl_80543768*fraction;
        } else *(f32*)(self+0x114)=lbl_8054372C;
    }
    s32 lo;
    s32 hi;
    s32 lo2;
    u8* offsets;
    u8* bytes;
    u64* group;
    s32 k;
    offsets=self;
    lo2=0;
    bytes=self;
    group=(u64*)(base+0x158);
    k=0;
    hi=10;
    for(;k<3;k++,hi+=5,lo2+=5,offsets+=4,bytes+=6,group+=6) {
        lo=k*5;
        time=*(s16*)(self+0x240);
        if(time>lo) {
            if(time<hi) {
                s32 d=10-(time-lo2);
                f32 fraction=(f32)(d*d)/lbl_805437B8;
                *(f32*)(offsets+0x130)=lbl_80543774*fraction;
                t=(f32)(*(s16*)(self+0x240)-lo2)/lbl_805437BC;
            if(t<lbl_8054372C) t=lbl_8054372C;
            else if(t>lbl_80543730) t=lbl_80543730;
                u8* alpha=bytes;
                u64* names=group;
                for(i=0;i<6;i++,alpha++,names++) {
                    J2DPane* pane=(*(J2DPane**)(self+4))->search(*names);
                    f32 value=alpha[0x273];
                    value*=t;
                    ((Tu803FVObj*)pane)->v9((s32)value);
                }
            } else {
                *(f32*)(offsets+0x130)=lbl_8054372C;
                u8* alpha=bytes;
                u64* names=group;
                for(i=0;i<6;i++,alpha++,names++) {
                    J2DPane* pane=(*(J2DPane**)(self+4))->search(*names);
                    f32 value=alpha[0x273];
                    value*=lbl_80543730;
                    ((Tu803FVObj*)pane)->v9((s32)value);
                }
            }
        }
    }
    time=*(s16*)(self+0x240);
    if(time>0) {
        if(time<15) {
            s32 d=15-time;
            f32 fraction=(f32)(d*d)/lbl_8054378C;
            f32 value=lbl_80543778*fraction;
            *(f32*)(self+0x158)=value;
            *(f32*)(self+0x144)=value;
            t=(f32)*(s16*)(self+0x240)/lbl_805437C4;
            if(t<lbl_8054372C) t=lbl_8054372C;
            else if(t>lbl_80543730) t=lbl_80543730;
            {
                u64* names=(u64*)(base+0x1e8);
                for(j=0;j<24;j++,names++) {
                    J2DPane* pane=(*(J2DPane**)(self+4))->search(*names);
                    f32 value=self[0x285+j];
                    value*=t;
                    ((Tu803FVObj*)pane)->v9((s32)value);
                }
            }
            {
                u64* names=(u64*)(base+0x2a8);
                for(j=0;j<18;j++,names++) {
                    J2DPane* pane=(*(J2DPane**)(self+4))->search(*names);
                    f32 value=self[0x29d+j];
                    value*=t;
                    ((Tu803FVObj*)pane)->v9((s32)value);
                }
            }
        } else {
            *(f32*)(self+0x158)=lbl_8054372C;
            *(f32*)(self+0x144)=lbl_8054372C;
            {
                u64* names=(u64*)(base+0x1e8);
                for(j=0;j<24;j++,names++) {
                    J2DPane* pane=(*(J2DPane**)(self+4))->search(*names);
                    f32 value=self[0x285+j];
                    value*=lbl_80543730;
                    ((Tu803FVObj*)pane)->v9((s32)value);
                }
            }
            {
                u64* names=(u64*)(base+0x2a8);
                for(j=0;j<18;j++,names++) {
                    J2DPane* pane=(*(J2DPane**)(self+4))->search(*names);
                    f32 value=self[0x29d+j];
                    value*=lbl_80543730;
                    ((Tu803FVObj*)pane)->v9((s32)value);
                }
            }
        }
    }
    if(*(s16*)(self+0x240)>=75) {
        *(s16*)(self+0x240)=0;
        *(s32*)(self+0x1c8)=*(s32*)(self+0x1c4);
        *(s32*)(self+0x1c4)=1;
    }

    (*(J2DPane**)(self+4))->search(0x506d626162623037ULL)->move(*(f32*)(self+0x108),*(f32*)(self+0x10c)+*(f32*)(self+0x110));
    fn_80402E08(*(void**)(self+0x74),lbl_8054372C,*(f32*)(self+0x114));
    (*(J2DPane**)(self+4))->search(0x00506e6f70623038ULL)->move(*(f32*)(self+0x118)+*(f32*)(self+0x130),*(f32*)(self+0x128));
    (*(J2DPane**)(self+4))->search(0x00506e6f70623132ULL)->move(*(f32*)(self+0x11c)+*(f32*)(self+0x134),*(f32*)(self+0x12c));
    (*(J2DPane**)(self+4))->search(0x00506e6f70623136ULL)->move(*(f32*)(self+0x120)+*(f32*)(self+0x138),*(f32*)(self+0x130));
    (*(J2DPane**)(self+4))->search(0x004e646174613032ULL)->move(*(f32*)(self+0x13c)+*(f32*)(self+0x144),*(f32*)(self+0x140));
    (*(J2DPane**)(self+4))->search(0x004e646174613035ULL)->move(*(f32*)(self+0x148)+*(f32*)(self+0x158),*(f32*)(self+0x14c));
    (*(J2DPane**)(self+4))->search(0x004e646174613037ULL)->move(*(f32*)(self+0x150)+*(f32*)(self+0x158),*(f32*)(self+0x154));
    t = (*(J2DPane**)(self+4))->search(0x50736375726f3032ULL)->getBounds()->i.y;
    (*(J2DPane**)(self+4))->search(0x50736375726f3032ULL)->move(*(f32*)(self+0xec) + *(f32*)(self+0x130+4* *(s32*)(self+0x1ac)), t);
}
#pragma opt_common_subs reset
#pragma opt_propagation reset

#pragma opt_common_subs reset
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
        ((Tu803FVObj*)*(void**)(p + 0x5c))->v9(p[0x25d]);
        ((Tu803FVObj*)*(void**)(p + 0x5c))->v59(0, 0, 0, lbl_8054372C, lbl_8054372C, lbl_8054374C, lbl_80543750);
    }
}

extern "C" void fn_804310CC(void* a);
extern "C" void fn_803F267C(u8* p);
extern "C" void fn_803FC5E4(u8* p, u8 flag) {
    s32 i;

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
        (*(J2DPane**)(p + 4))->search(0x506d626162623037ULL)->move(*(f32*)(p + 0x108), *(f32*)(p + 0x10c) + *(f32*)(p + 0x110));

        *(f32*)(p + 0x114) = lbl_80543768;
        fn_80402E08(*(void**)(p + 0x74), lbl_8054372C, *(f32*)(p + 0x114));

        *(f32*)(p + 0x130) = lbl_80543774;
        (*(J2DPane**)(p + 4))->search(0x00506e6f70623038ULL)->move(*(f32*)(p + 0x118) + *(f32*)(p + 0x130), *(f32*)(p + 0x124));

        *(f32*)(p + 0x134) = lbl_80543774;
        (*(J2DPane**)(p + 4))->search(0x00506e6f70623132ULL)->move(*(f32*)(p + 0x11c) + *(f32*)(p + 0x134), *(f32*)(p + 0x128));

        *(f32*)(p + 0x138) = lbl_80543774;
        (*(J2DPane**)(p + 4))->search(0x00506e6f70623136ULL)->move(*(f32*)(p + 0x120) + *(f32*)(p + 0x138), *(f32*)(p + 0x12c));

        *(f32*)(p + 0x144) = lbl_80543778;
        (*(J2DPane**)(p + 4))->search(0x004e646174613032ULL)->move(*(f32*)(p + 0x13c) + *(f32*)(p + 0x144), *(f32*)(p + 0x140));

        *(f32*)(p + 0x158) = lbl_80543778;
        (*(J2DPane**)(p + 4))->search(0x004e646174613035ULL)->move(*(f32*)(p + 0x148) + *(f32*)(p + 0x158), *(f32*)(p + 0x14c));

        (*(J2DPane**)(p + 4))->search(0x004e646174613037ULL)->move(*(f32*)(p + 0x150) + *(f32*)(p + 0x158), *(f32*)(p + 0x154));

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

extern "C" void fn_803FCBC4(u8* p) {
    u8* base = (u8*)lbl_80478A60;
    *(s32*)(p + 0x1a4) = 0;
    *(s32*)(p + 0x1a8) = 0;
    *(s32*)(p + 0x1ac) = lbl_80529DEC[0x23d];
    *(s32*)(p + 0x1c0) = 0;
    p[0x252] = 0;
    p[0x25b] = 0;
    p[0x25c] = 0;
    *(s32*)(p + 0x1c8) = 0;
    *(s32*)(p + 0x1c4) = 0;
    *(s32*)(p + 0x1cc) = 0;
    for (s32 i = 0; i < 4; i++) {
        *(s32*)(p + i * 4 + 0x1d0) = 0;
        *(s32*)(p + i * 4 + 0x1e0) = fn_80403414(i);
        *(s32*)(p + i * 4 + 0x1f0) = fn_804033D4(i);
        *(s32*)(p + i * 4 + 0x200) = fn_8040336C(i);
        *(s32*)(p + i * 4 + 0x210) = 0;
        *(s32*)(p + i * 4 + 0x1b0) = 1;
        *(s16*)(p + i * 2 + 0x240) = 0;
    }
}

extern "C" char lbl_80528668[];
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
static inline void copyMenuRecord(FsaBlock156* dst, const FsaBlock156* src)
{
    dst->field_00 = src->field_00;
    dst->field_04 = src->field_04;
    dst->field_08 = src->field_08;
    dst->field_0C = src->field_0C;
    dst->field_10 = src->field_10;
    dst->field_14 = src->field_14;
    dst->field_18 = src->field_18;
    dst->field_1C = src->field_1C;
    dst->field_20 = src->field_20;
    dst->field_24 = src->field_24;
    dst->field_28 = src->field_28;
    dst->field_2C = src->field_2C;
    dst->field_30 = src->field_30;
    dst->field_34 = src->field_34;
    dst->field_38 = src->field_38;
    dst->field_3C = src->field_3C;
    dst->field_40 = src->field_40;
    dst->field_44 = src->field_44;
    dst->field_48 = src->field_48;
    dst->field_4C = src->field_4C;
    dst->field_50 = src->field_50;
    dst->field_54 = src->field_54;
    dst->field_58 = src->field_58;
    dst->field_5C = src->field_5C;
    dst->field_60 = src->field_60;
    dst->field_64 = src->field_64;
    dst->field_68 = src->field_68;
    dst->field_6C = src->field_6C;
    dst->field_70 = src->field_70;
    dst->field_74 = src->field_74;
    dst->field_78 = src->field_78;
    dst->field_7C = src->field_7C;
    dst->field_80 = src->field_80;
    dst->field_84 = src->field_84;
    dst->field_88 = src->field_88;
    dst->field_8C = src->field_8C;
    dst->field_90 = src->field_90;
    dst->field_94 = src->field_94;
    dst->field_98 = src->field_98;
}
#pragma opt_propagation off
extern "C" void fn_803FEB94(void) {
    register char* const registrations = lbl_80528668;
    u32* b = (u32*)lbl_804B0B40;
    u32* first = b + 39;
    u32* second = b + 117;
    u32* third = b + 195;
    first[0] = b[0x00]; first[1] = b[0x01]; first[2] = b[0x02]; first[3] = b[0x03];
    first[4] = b[0x04]; first[5] = b[0x05]; first[6] = b[0x06]; first[7] = b[0x07];
    first[8] = b[0x08]; first[9] = b[0x09]; first[10] = b[0x0a]; first[11] = b[0x0b];
    first[12] = b[0x0c]; first[13] = b[0x0d]; first[14] = b[0x0e]; first[15] = b[0x0f];
    first[16] = b[0x10]; first[17] = b[0x11]; first[18] = b[0x12]; first[19] = b[0x13];
    first[20] = b[0x14]; first[21] = b[0x15]; first[22] = b[0x16]; first[23] = b[0x17];
    first[24] = b[0x18]; first[25] = b[0x19]; first[26] = b[0x1a]; first[27] = b[0x1b];
    first[28] = b[0x1c]; first[29] = b[0x1d]; first[30] = b[0x1e]; first[31] = b[0x1f];
    first[32] = b[0x20]; first[33] = b[0x21]; first[34] = b[0x22]; first[35] = b[0x23];
    first[36] = b[0x24]; first[37] = b[0x25]; first[38] = b[0x26];
    second[0] = b[0x4e]; second[1] = b[0x4f]; second[2] = b[0x50]; second[3] = b[0x51];
    second[4] = b[0x52]; second[5] = b[0x53]; second[6] = b[0x54]; second[7] = b[0x55];
    second[8] = b[0x56]; second[9] = b[0x57]; second[10] = b[0x58]; second[11] = b[0x59];
    second[12] = b[0x5a]; second[13] = b[0x5b]; second[14] = b[0x5c]; second[15] = b[0x5d];
    second[16] = b[0x5e]; second[17] = b[0x5f]; second[18] = b[0x60]; second[19] = b[0x61];
    second[20] = b[0x62]; second[21] = b[0x63]; second[22] = b[0x64]; second[23] = b[0x65];
    second[24] = b[0x66]; second[25] = b[0x67]; second[26] = b[0x68]; second[27] = b[0x69];
    second[28] = b[0x6a]; second[29] = b[0x6b]; second[30] = b[0x6c]; second[31] = b[0x6d];
    second[32] = b[0x6e]; second[33] = b[0x6f]; second[34] = b[0x70]; second[35] = b[0x71];
    second[36] = b[0x72]; second[37] = b[0x73]; second[38] = b[0x74];
    third[0] = b[0x9c]; third[1] = b[0x9d]; third[2] = b[0x9e]; third[3] = b[0x9f];
    third[4] = b[0xa0]; third[5] = b[0xa1]; third[6] = b[0xa2]; third[7] = b[0xa3];
    third[8] = b[0xa4]; third[9] = b[0xa5]; third[10] = b[0xa6]; third[11] = b[0xa7];
    third[12] = b[0xa8]; third[13] = b[0xa9]; third[14] = b[0xaa]; third[15] = b[0xab];
    third[16] = b[0xac]; third[17] = b[0xad]; third[18] = b[0xae]; third[19] = b[0xaf];
    third[20] = b[0xb0]; third[21] = b[0xb1]; third[22] = b[0xb2]; third[23] = b[0xb3];
    third[24] = b[0xb4]; third[25] = b[0xb5]; third[26] = b[0xb6]; third[27] = b[0xb7];
    third[28] = b[0xb8]; third[29] = b[0xb9]; third[30] = b[0xba]; third[31] = b[0xbb];
    third[32] = b[0xbc]; third[33] = b[0xbd]; third[34] = b[0xbe]; third[35] = b[0xbf];
    third[36] = b[0xc0]; third[37] = b[0xc1]; third[38] = b[0xc2];

    if (!__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr,
                                 __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, registrations);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (!__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack,
                                 __dt__35JASMemPool_MultiThreaded_8JASTrackFv, registrations + 0xc);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (!__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel,
                                 __dt__38JASMemPool_MultiThreaded_10JASChannelFv, registrations + 0x18);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (!__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA,
                                 __dt__29JASMemPool_15JASPoolObj3_FSAFv, registrations + 0x24);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (!__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA,
                                 __dt__29JASMemPool_15JASPoolObj4_FSAFv, registrations + 0x30);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (!__init__memPool___30JASPoolAllocObject_9JAIStream) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream,
                                 __dt__22JASMemPool_9JAIStreamFv, registrations + 0x3c);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (!__init__memPool___35JASPoolAllocObject_13JAISoundChild) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild,
                                 __dt__27JASMemPool_13JAISoundChildFv, registrations + 0x48);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (!__init__memPool___27JASPoolAllocObject_6JAISeq) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq,
                                 __dt__19JASMemPool_6JAISeqFv, registrations + 0x54);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (!__init__memPool___26JASPoolAllocObject_5JAISe) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe,
                                 __dt__18JASMemPool_5JAISeFv, registrations + 0x60);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}
#pragma opt_propagation reset
