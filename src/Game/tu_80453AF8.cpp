#include "types.h"
#include "JSystem/J2D/J2DScreen.h"
#include "JSystem/J2D/J2DPicture.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"


extern "C" void* lbl_8053AF48;
extern "C" void* lbl_8053AB10;
extern "C" void* lbl_8053AEC0;
extern "C" void fn_8013B490(void* a);
extern "C" void fn_804316EC(void* a);
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(void* self, f32 x, f32 y, void* ctx);
extern "C" void* lbl_804B1DA8[];
extern "C" void* lbl_8053AF80;
extern "C" void fn_80459274(void* a);
extern "C" void __dl__FPv(void* p);

struct FsaVt80454A6C {
    virtual void v0(void);
    virtual void v1(void);
    virtual void v2(void);
    virtual void v3(void);
    virtual void v4(void);
    virtual void v5(void);
    virtual void v6(void);
    virtual void v7(s32);
    virtual void v8(void);
    virtual void v9(s32);
    virtual void v10(void);
    virtual void v11(void);
    virtual void v12(void);
    virtual void* v13(u32, u32, u32);
    virtual void v14(void);
    virtual void* v15(u32, u32, u32);
    virtual void v16(void);
    virtual void v17(void);
    virtual void v18(void);
    virtual void v19(void);
    virtual void v20(void);
    virtual void v21(void);
    virtual void v22(void);
    virtual void v23(void);
    virtual void v24(void);
    virtual void v25(void);
    virtual void v26(void);
    virtual void v27(void);
    virtual void v28(void);
    virtual void v29(void);
    virtual void v30(void);
    virtual void v31(void);
    virtual void v32(void);
    virtual void v33(void);
    virtual void v34(void);
    virtual void v35(void);
    virtual void v36(void);
    virtual void v37(void);
    virtual void v38(void);
    virtual void v39(void);
    virtual void v40(void);
    virtual void v41(void);
    virtual void v42(void);
    virtual void v43(void);
    virtual void v44(void);
    virtual void v45(void);
    virtual void v46(void);
    virtual void v47(void);
    virtual void v48(void);
    virtual void v49(void);
    virtual void v50(void);
    virtual void v51(void);
    virtual void v52(void);
    virtual void v53(void);
    virtual void v54(void);
    virtual void v55(void);
    virtual void v56(void);
    virtual void v57(void);
    virtual void v58(void);
    virtual void v59(void);
    virtual void v60(void);
    virtual void v61(void);
    virtual void v62(void);
    virtual void v63(void);
    virtual void v64(void);
    virtual void v65(void);
    virtual void v66(u32, u32);
    virtual void v67(void);
    virtual void v68(u32, u32);
    virtual void v69(void);
    virtual void v70(void);
    virtual void v71(void);
    virtual void v72(void*);
    virtual void v73(void*);
    virtual void v74(void*);
    virtual void v75(void*);
};

struct Slot0 {
    virtual void slot0(s32 arg);
};

struct T80454DEC {
    void* vtable;
    J2DScreen* screen;
    void* backdrop;
    void* panel;
    void* entries[3];
    s16 selected;
    s16 state;
    s16 field20;
    f32 left[3];
    f32 top[3];
    f32 right[3];
    f32 bottom[3];
    u8 field54;
    u8 field55;
};

struct T80454CD8 {
    u8 pad0[0x10];
    Slot0* a[3];
};
extern "C" s32 fn_80453AF8(void) {
    if (lbl_8053AF48 != 0) {
        return *(s32*)((u8*)lbl_8053AF48 + 0x58);
    }
    return 9;
}

extern "C" const f32 lbl_80543E44;
extern "C" const f32 lbl_80543E40;
extern "C" const u32 lbl_80491470[];
extern "C" void fn_80402E08(void* p, f32 x, f32 y);
extern "C" u8 lbl_8050DB0C[];
extern "C" void* lbl_8053AD30;
extern "C" const f32 lbl_80543E48;
extern "C" const f32 lbl_80543E4C;
extern "C" const f32 lbl_80543E50;
extern "C" void fn_80402628(void*, s32, s32, s32);
extern "C" u8 fn_80402940(void*, s32, s32, f32, f32);
extern "C" u32 fn_80309A9C(void*, s32, s32);
extern "C" u32 fn_80309C4C(void*, s32, s32);
extern "C" void fn_80458880(void*, s32, s32);
extern "C" void fn_80458F9C(void*, s32);
extern "C" void fn_80431A9C(void*, s32, s32, u8*);
extern "C" void fn_80431174(void*, u8);
extern "C" s32 fn_80431740(void*);
extern "C" s32 fn_804317AC(void*);
extern "C" void fn_804310BC(void*);
static inline void MenuUpdateColors8045(T80454DEC* self) {
    for (int i = 0; i < 3; i++) {
        if (i == self->selected) {
            ((J2DPicture*)self->screen->search(((u64*)lbl_80491470)[i]))->setWhite(JUtility::TColor(255, 237, 160, 255));
            ((J2DPicture*)self->screen->search(((u64*)lbl_80491470)[i]))->setBlack(JUtility::TColor(39, 16, 0, 0));
        } else {
            ((J2DPicture*)self->screen->search(((u64*)lbl_80491470)[i]))->setWhite(JUtility::TColor(167, 76, 42, 255));
            ((J2DPicture*)self->screen->search(((u64*)lbl_80491470)[i]))->setBlack(JUtility::TColor(0, 0, 0, 0));
        }
    }
}
static inline void MenuLayout8045(T80454DEC* self, f32 off) {
    self->screen->search(0x506b656e633031ULL)->move(self->left[self->selected], self->top[self->selected] + off);
    self->screen->search(0x506b656e633032ULL)->move(self->right[self->selected], self->bottom[self->selected] + off);
    for (int i = 0; i < 3; i++) {
        if (i == self->selected) {
            fn_80402E08(self->entries[i], lbl_80543E44, off);
        } else {
            fn_80402E08(self->entries[i], lbl_80543E44, lbl_80543E44);
        }
    }
}
extern "C" s32 fn_80453B14(u8* this_) {
    T80454DEC* self = (T80454DEC*)this_;
    s32 v;
    f32 off;
    *(s32*)(this_ + 0x58) = 9;
    switch (*(s16*)(this_ + 0x1e)) {
    case 2:
        fn_80402628(*(void**)(this_ + 8), *(s16*)(lbl_8050DB0C + 0x8c), 0, *(u8*)(*(u8**)(this_ + 8) + 0x28));
        if (fn_80402940(*(void**)(this_ + 0xc), *(s16*)(lbl_8050DB0C + 0x8c), 0, lbl_80543E40, (f32)*(s16*)(lbl_8050DB0C + 0x90))) {
            *(s16*)(*(u8**)(this_ + 0xc) + 0x22) = 0;
            *(s16*)(this_ + 0x1e) = 3;
        }
        break;
    case 3:
        if (fn_80402940(*(void**)(this_ + 0xc), *(s16*)(lbl_8050DB0C + 0x8e), 2, (f32)*(s16*)(lbl_8050DB0C + 0x90), lbl_80543E44)) {
            *(s16*)(this_ + 0x1e) = 5;
        }
        break;
    case 5:
        if (*(s16*)(this_ + 0x20) != 0) {
            (*(s16*)(this_ + 0x20))++;
            if (*(s16*)(this_ + 0x20) > 10) {
                *(s16*)(this_ + 0x20) = 0;
            }
        }
        if (*(s16*)(this_ + 0x1c) > 0 && fn_80309A9C(lbl_8053AD30, 8, -1)) {
            (*(s16*)(this_ + 0x1c))--;
            *(s16*)(this_ + 0x20) = 1;
            MenuUpdateColors8045(self);
            fn_80458880(lbl_8053AF80, 0, -1);
        } else if (*(s16*)(this_ + 0x1c) < 2 && fn_80309A9C(lbl_8053AD30, 4, -1)) {
            (*(s16*)(this_ + 0x1c))++;
            *(s16*)(this_ + 0x20) = 1;
            MenuUpdateColors8045(self);
            fn_80458880(lbl_8053AF80, 0, -1);
        } else if (fn_80309C4C(lbl_8053AD30, 0x1100, -1)) {
            if (*(s16*)(this_ + 0x1c) == 0) {
                *(s16*)(this_ + 0x1e) = 0xa;
            } else {
                *(s16*)(this_ + 0x1e) = 0xa;
            }
            *(s16*)(this_ + 0x20) = 1;
            fn_80458880(lbl_8053AF80, 0xb, -1);
        } else if (fn_80309C4C(lbl_8053AD30, 0x200, -1)) {
            *(s16*)(this_ + 0x1c) = 0;
            MenuUpdateColors8045(self);
            *(s16*)(this_ + 0x1e) = 0xa;
            *(s16*)(this_ + 0x20) = 1;
            fn_80458880(lbl_8053AF80, 0xb, -1);
        }
        {
            s16 t = *(s16*)(this_ + 0x20);
            v = t >= 5 ? 10 - t : t;
        }
        off = lbl_80543E48 * (f32)(v * v) / lbl_80543E4C;
        MenuLayout8045(self, off);
        break;
    case 0xa:
        (*(s16*)(this_ + 0x20))++;
        {
            s16 t = *(s16*)(this_ + 0x20);
            if (t < 5) {
                v = t;
            } else if (t < 10) {
                v = 10 - t;
            } else {
                v = 0;
            }
        }
        off = lbl_80543E48 * (f32)(v * v) / lbl_80543E4C;
        MenuLayout8045(self, off);
        if (*(s16*)(this_ + 0x20) >= 0xf) {
            if (*(s16*)(this_ + 0x1c) == 0) {
                *(s16*)(this_ + 0x1e) = 0xb;
                *(s16*)(*(u8**)(this_ + 8) + 0x26) = 0;
            } else {
                *(s16*)(this_ + 0x1e) = 0xd;
            }
            *(s16*)(this_ + 0x20) = 0;
            *(s16*)(*(u8**)(this_ + 0xc) + 0x22) = 0;
        }
        break;
    case 0xb:
        if (fn_80402940(*(void**)(this_ + 0xc), *(s16*)(lbl_8050DB0C + 0x92), 2, lbl_80543E44, (f32)*(s16*)(lbl_8050DB0C + 0x90))) {
            *(s16*)(*(u8**)(this_ + 0xc) + 0x22) = 0;
            *(s16*)(this_ + 0x1e) = 0xc;
        }
        break;
    case 0xc:
        fn_80402628(*(void**)(this_ + 8), *(s16*)(lbl_8050DB0C + 0x94), *(u8*)(*(u8**)(this_ + 8) + 0x28), 0);
        if (fn_80402940(*(void**)(this_ + 0xc), *(s16*)(lbl_8050DB0C + 0x94), 0, (f32)*(s16*)(lbl_8050DB0C + 0x90), lbl_80543E40)) {
            *(s16*)(this_ + 0x1e) = 2;
            fn_80402E08(*(void**)(this_ + 0xc), lbl_80543E44, lbl_80543E40);
            *(s16*)(*(u8**)(this_ + 0xc) + 0x22) = 0;
            *(s32*)(this_ + 0x58) = 7;
            fn_80458880(lbl_8053AF80, 2, -1);
            fn_80459274(lbl_8053AF80);
        }
        break;
    case 0xd:
        if (fn_80402940(*(void**)(this_ + 0xc), 0xa, 0, lbl_80543E44, lbl_80543E50)) {
            *(s16*)(this_ + 0x1e) = 7;
            fn_80431A9C(lbl_8053AEC0, 0x10a, 0, this_ + 0x55);
        }
        break;
    case 7:
        if (fn_804317AC(lbl_8053AEC0) != 0) {
            *(s16*)(this_ + 0x1e) = 8;
        }
        break;
    case 8:
        if (fn_80309A9C(lbl_8053AD30, 2, -1)) {
            if (this_[0x55] == 0) {
                this_[0x55] = 1;
                fn_80458880(lbl_8053AF80, 0, -1);
            }
        } else if (fn_80309A9C(lbl_8053AD30, 1, -1)) {
            if (this_[0x55] == 1) {
                this_[0x55] = 0;
                fn_80458880(lbl_8053AF80, 0, -1);
            }
        } else if (fn_80309C4C(lbl_8053AD30, 0x1100, -1)) {
            *(s16*)(this_ + 0x1e) = 9;
            if (this_[0x55] == 1) {
                fn_80458880(lbl_8053AF80, 0xb, -1);
            }
        } else if (fn_80309C4C(lbl_8053AD30, 0x200, -1)) {
            this_[0x55] = 1;
            *(s16*)(this_ + 0x1e) = 9;
            if (this_[0x55] == 1) {
                fn_80458880(lbl_8053AF80, 0xb, -1);
            }
        }
        fn_80431174(lbl_8053AEC0, this_[0x55]);
        break;
    case 9:
        if (fn_80431740(lbl_8053AEC0) == 0) {
            break;
        }
        if (this_[0x55] == 0) {
            if (*(s16*)(this_ + 0x1c) == 1) {
                fn_80458880(lbl_8053AF80, 0xc, -1);
                fn_80458F9C(lbl_8053AF80, 0);
                fn_80459274(lbl_8053AF80);
                *(s32*)(this_ + 0x58) = 6;
            } else {
                *(s32*)(this_ + 0x58) = 2;
                fn_80458880(lbl_8053AF80, 0xc, -1);
                fn_80458F9C(lbl_8053AF80, 0);
                fn_80459274(lbl_8053AF80);
            }
        } else {
            *(s16*)(this_ + 0x1e) = 2;
            *(s16*)(this_ + 0x20) = 0;
            fn_80402E08(*(void**)(this_ + 0xc), lbl_80543E44, lbl_80543E40);
            *(s16*)(*(u8**)(this_ + 0xc) + 0x22) = 0;
            *(s16*)(this_ + 0x1c) = 0;
            MenuUpdateColors8045(self);
            self->screen->search(0x506b656e633031ULL)->move(self->left[self->selected], self->top[self->selected]);
            self->screen->search(0x506b656e633032ULL)->move(self->right[self->selected], self->bottom[self->selected]);
        }
        fn_804310BC(lbl_8053AEC0);
        break;
    }
    return 0;
}

extern "C" void fn_80454A00(u8* p) {
    fn_8013B490(lbl_8053AB10);
    draw__9J2DScreenFffPC14J2DGrafContext(*(void**)(p + 4), 1.0f, 1.0f, *(void**)((u8*)lbl_8053AB10 + 0x10));
    if (*(s16*)(p + 0x1e) == 7 || *(s16*)(p + 0x1e) == 8 || *(s16*)(p + 0x1e) == 9) {
        fn_804316EC(lbl_8053AEC0);
    }
}

extern "C" void fn_804310CC(void* a);
extern "C" void fn_80402E08(void* a, f32 x, f32 y);
extern "C" u32 fn_80403084(u32 a, void* b);
extern "C" u8 lbl_80491488[];
extern "C" const u32 lbl_80491470[];
extern "C" void fn_80402E08(void* p, f32 x, f32 y);
extern "C" void fn_80454A6C(void* this_) {
    fn_804310CC(lbl_8053AEC0);
    *(s16*)((u8*)this_ + 0x1c) = 0;
    *(s16*)((u8*)this_ + 0x1e) = 2;
    *(s16*)((u8*)this_ + 0x20) = 0;
    void* p4 = *(void**)((u8*)*(void**)((u8*)this_ + 0x8) + 0x4);
    ((FsaVt80454A6C*)p4)->v7(0);
    *(s16*)((u8*)*(void**)((u8*)this_ + 0x8) + 0x26) = 0;
    fn_80402E08(*(void**)((u8*)this_ + 0xc), 0.0f, -480.0f);
    *(s16*)((u8*)*(void**)((u8*)this_ + 0xc) + 0x22) = 0;
    u32 uVar1 = fn_80403084(0x54494d47, lbl_80491488);
    void* o = ((FsaVt80454A6C*)*(void**)((u8*)this_ + 0x4))->v13(0x73630000, 0x50, 0x73633031);
    ((FsaVt80454A6C*)o)->v66(uVar1, 0);

    u32* p = (u32*)lbl_80491470;
    for (s32 i = 0; i < 3; i++, p += 2) {
        if (i == *(s16*)((u8*)this_ + 0x1c)) {
            u32 c1;
            u8 col1[4];
            col1[0] = 0xff;
            col1[1] = 0xed;
            col1[2] = 0xa0;
            col1[3] = 0xff;
            c1 = *(u32*)col1;
            o = ((FsaVt80454A6C*)*(void**)((u8*)this_ + 0x4))->v13(0xff, p[0], p[1]);
            ((FsaVt80454A6C*)o)->v73(&c1);
            u32 c2;
            u8 col2[4];
            col2[0] = 0x27;
            col2[1] = 0x10;
            col2[2] = 0;
            col2[3] = 0;
            c2 = *(u32*)col2;
            o = ((FsaVt80454A6C*)*(void**)((u8*)this_ + 0x4))->v13(0x27, p[0], p[1]);
            ((FsaVt80454A6C*)o)->v72(&c2);
        } else {
            u32 c3;
            u8 col3[4];
            col3[0] = 0xa7;
            col3[1] = 0x4c;
            col3[2] = 0x2a;
            col3[3] = 0xff;
            c3 = *(u32*)col3;
            o = ((FsaVt80454A6C*)*(void**)((u8*)this_ + 0x4))->v13(0x4c, p[0], p[1]);
            ((FsaVt80454A6C*)o)->v73(&c3);
            u32 z;
            u8 zero[4];
            zero[0] = 0;
            zero[1] = 0;
            zero[2] = 0;
            zero[3] = 0;
            z = *(u32*)zero;
            o = ((FsaVt80454A6C*)*(void**)((u8*)this_ + 0x4))->v13(0, p[0], p[1]);
            ((FsaVt80454A6C*)o)->v72(&z);
        }
    }
    *(s32*)((u8*)this_ + 0x58) = 9;
}

extern "C" void* fn_80454CD8(void* this_, s16 flag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804B1DA8;
        fn_80459274(lbl_8053AF80);
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
        T80454CD8* o = (T80454CD8*)this_;
        for (int i = 0; i < 3; i++) {
            if (o->a[i] != 0) {
                o->a[i]->slot0(1);
            }
            o->a[i] = 0;
        }
        lbl_8053AF48 = 0;
        if (flag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" u8 lbl_80529DEC[];
extern "C" void* lbl_804AF86C[];
struct T80454DEC_Entry {
    void* vtable;
    u8 fields[0x28];
    T80454DEC_Entry() { vtable = lbl_804AF86C; }
};
extern "C" void fn_80402F04(void* a, void* b);
extern "C" void* __nw__FUl(u32 size);
extern "C" void* getBounds__7J2DPaneFv(void* self);
extern "C" void setPriority__9J2DScreenFPCcUlP10JKRArchive(void* self, const char* name, u32 pri, void* archive);
extern "C" void __ct__9J2DScreenFv(void* self);
extern "C" char lbl_8049149C[];
extern "C" const f32 lbl_80543E44;
extern "C" const f32 lbl_80543E40;
extern "C" u8* fn_80454DEC(u8* p) {
    typedef void* (*Search)(void*, u64);
    typedef void (*SetColor)(void*, void*);
    typedef void (*SetAlpha)(void*, u8);
    int j;
    int i;
    void* s;
    T80454DEC* self = (T80454DEC*)p;
    *(void**)p = lbl_804B1DA8;
    lbl_8053AF48 = p;
    self->screen = new J2DScreen;
    setPriority__9J2DScreenFPCcUlP10JKRArchive(*(void**)(p+4), lbl_8049149C, 0x1100000, *(void**)(lbl_80529DEC+0x4c));
    self->left[0] = *(f32*)((u8*)getBounds__7J2DPaneFv(self->screen->search(0x506b656e633031ULL)) + 0);
    self->top[0] = *(f32*)((u8*)getBounds__7J2DPaneFv(self->screen->search(0x506b656e633031ULL)) + 4);
    self->right[0] = *(f32*)((u8*)getBounds__7J2DPaneFv(self->screen->search(0x506b656e633032ULL)) + 0);
    self->bottom[0] = *(f32*)((u8*)getBounds__7J2DPaneFv(self->screen->search(0x506b656e633032ULL)) + 4);
    f32 left = *(f32*)((u8*)getBounds__7J2DPaneFv(self->screen->search(*(u64*)lbl_80491470)) + 0) - self->left[0];
    f32 right = self->right[0] - *(f32*)((u8*)getBounds__7J2DPaneFv(self->screen->search(*(u64*)lbl_80491470)) + 8);
    self->left[1] = *(f32*)((u8*)getBounds__7J2DPaneFv(self->screen->search(((u64*)lbl_80491470)[1])) + 0) - left;
    self->top[1] = *(f32*)((u8*)getBounds__7J2DPaneFv(self->screen->search(((u64*)lbl_80491470)[1])) + 4);
    self->right[1] = right + *(f32*)((u8*)getBounds__7J2DPaneFv(self->screen->search(((u64*)lbl_80491470)[1])) + 8);
    self->bottom[1] = *(f32*)((u8*)getBounds__7J2DPaneFv(self->screen->search(((u64*)lbl_80491470)[1])) + 4);
    self->left[2] = *(f32*)((u8*)getBounds__7J2DPaneFv(self->screen->search(((u64*)lbl_80491470)[2])) + 0) - left;
    self->top[2] = *(f32*)((u8*)getBounds__7J2DPaneFv(self->screen->search(((u64*)lbl_80491470)[2])) + 4);
    self->right[2] = right + *(f32*)((u8*)getBounds__7J2DPaneFv(self->screen->search(((u64*)lbl_80491470)[2])) + 8);
    self->bottom[2] = *(f32*)((u8*)getBounds__7J2DPaneFv(self->screen->search(((u64*)lbl_80491470)[2])) + 4);
    s = __nw__FUl(0x2c);
    if (s) *(void**)s = lbl_804AF86C;
    *(void**)(p+8) = s;
    fn_80402F04(*(void**)(p+8), self->screen->search(0x50626c61636bULL));
    s = __nw__FUl(0x2c);
    if (s) *(void**)s = lbl_804AF86C;
    *(void**)(p+12) = s;
    fn_80402F04(*(void**)(p+12), self->screen->search(0x4e646174613031ULL));
    for (i=0; i<3; i++) {
        s = new T80454DEC_Entry;
        self->entries[i] = s;
        fn_80402F04(self->entries[i], self->screen->search(((u64*)lbl_80491470)[i]));
    }
    *(s16*)(p+0x1c) = 0;
    *(s16*)(p+0x1e) = 2;
    *(s16*)(p+0x20) = 0;
    void* pane = *(void**)((u8*)*(void**)(p+8)+4);
    ((J2DPane*)pane)->setAlpha(0);
    *(s16*)((u8*)*(void**)(p+8)+0x26) = 0;
    fn_80402E08(*(void**)(p+0xc), lbl_80543E44, lbl_80543E40);
    *(s16*)((u8*)*(void**)(p+0xc)+0x22) = 0;
    for (j=0; j<3; j++) {
        if (j == *(s16*)(p+0x1c)) {
            ((J2DPicture*)self->screen->search(((u64*)lbl_80491470)[j]))->setWhite(JUtility::TColor(255,237,160,255));
            ((J2DPicture*)self->screen->search(((u64*)lbl_80491470)[j]))->setBlack(JUtility::TColor(39,16,0,0));
        } else {
            ((J2DPicture*)self->screen->search(((u64*)lbl_80491470)[j]))->setWhite(JUtility::TColor(167,76,42,255));
            ((J2DPicture*)self->screen->search(((u64*)lbl_80491470)[j]))->setBlack(JUtility::TColor(0,0,0,0));
        }
    }
    p[0x55] = 0;
    p[0x54] = 1;
    return p;
}

extern "C" void fn_804553E8(void) {
}

