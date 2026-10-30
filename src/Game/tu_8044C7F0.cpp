#include "types.h"
struct MenuTables8044 {
    u64 picture[3];
    u64 window[3];
    u8 pad30[0x138];
    u64 hide168[7];
    u64 alpha1a0[7];
    u64 alpha1d8[7];
    u64 hide210[7];
    u64 show248[4];
    u64 alpha268[4];
    u64 alpha288[4];
    u8 pad2a8[0x140];
    u16 particle3e8[8];
    u16 particle3f8[8];
};
struct MenuTag8044 {
    u64 id;
};
struct MenuTagTables8044 {
    MenuTag8044 picture[3];
    MenuTag8044 window[3];
    u8 pad30[0x138];
    MenuTag8044 hide168[7];
    MenuTag8044 alpha1a0[7];
    MenuTag8044 alpha1d8[7];
    MenuTag8044 hide210[7];
    MenuTag8044 show248[4];
    MenuTag8044 alpha268[4];
    MenuTag8044 alpha288[4];
    u8 pad2a8[0x140];
    u16 particle3e8[8];
    u16 particle3f8[8];
};
struct MenuParticles8044 {
    u8 pad[0x6c];
    void* first[7];
    void* second[7];
};
#include "JSystem/J2D/J2DPane.h"
#include "JSystem/J2D/J2DScreen.h"
static inline J2DPane* MenuSearch8044(J2DPane* screen, const u64* tags, s32 index) {
    return screen->search(tags[index]);
}
#include "JSystem/J2D/J2DPicture.h"
#include "JSystem/JParticle/JPAEmitter.h"
#include "dolphin/os/OSFastCast.h"


extern "C" void fn_804316EC(void*);
extern void* lbl_8053AEC0;
extern void* lbl_8053AF40;
extern void* lbl_8053AF80;
extern void* lbl_804B1D58[];
extern "C" void fn_80459274(void* a);
extern "C" void __dl__FPv(void* p);
extern f32 lbl_80543DF8;
extern f32 lbl_80543DFC;
extern "C" void fn_80402E08(void*, f32, f32);
struct UlPane {
    virtual void v08();
    virtual void v0c();
    virtual void move(f32, f32);
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void setAlpha(u32);
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual UlPane* find(u64 tag);
};
struct Deletable {
    virtual void del(s32 flag);
};

extern "C" void* fn_8013C824(void);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* mgr, void* emitter);
struct MenuEmitters8044 {
    u8 pad[0x6c];
    JPABaseEmitter* a[7];
    JPABaseEmitter* b[7];
    JPABaseEmitter* c[3];
    JPABaseEmitter* d[2][2];
    JPABaseEmitter* e[3];
};

extern "C" void fn_8044C7F0(u8* self) {
    MenuEmitters8044* t = (MenuEmitters8044*)self;
    for (int i = 0; i < 7; i++) {
        if (t->a[i] != NULL) {
            t->a[i]->becomeInvalidEmitter();
            t->a[i] = NULL;
        }
        if (t->b[i] != NULL) {
            t->b[i]->becomeInvalidEmitter();
            t->b[i] = NULL;
        }
    }
    for (int j = 0; j < 2; j++) {
        JPABaseEmitter** d = t->d[j];
        if (d[0] != NULL) {
            d[0]->becomeInvalidEmitter();
            d[0] = NULL;
        }
        if (d[1] != NULL) {
            d[1]->becomeInvalidEmitter();
            d[1] = NULL;
        }
    }
    for (int k = 0; k < 3; k++) {
        if (t->c[k] != NULL) {
            JPAEmitterManager* mgr = *(JPAEmitterManager**)((u8*)fn_8013C824() + 0xc);
            mgr->forceDeleteEmitter(t->c[k]);
            t->c[k] = NULL;
        }
        if (t->e[k] != NULL) {
            JPAEmitterManager* mgr = *(JPAEmitterManager**)((u8*)fn_8013C824() + 0xc);
            mgr->forceDeleteEmitter(t->e[k]);
            t->e[k] = NULL;
        }
    }
}

extern "C" void fn_8044C968(u8* self) {
    u8* p = self;
    s32 i;
    for (i = 0; i < 3; i++) {
        fn_80402E08(*(void**)(p + 0x48), lbl_80543DF8, lbl_80543DFC);
        fn_80402E08(*(void**)(p + 0x60), lbl_80543DF8, lbl_80543DFC);
        *(s16*)(*(u8**)(p + 0x48) + 0x20) = 0;
        *(s16*)(*(u8**)(p + 0x60) + 0x20) = 0;
        (*(UlPane**)(*(u8**)(p + 0x48) + 4))->setAlpha(0);
        *(s16*)(*(u8**)(p + 0x48) + 0x26) = 0;
        (*(UlPane**)(*(u8**)(p + 0x54) + 4))->setAlpha(0);
        *(s16*)(*(u8**)(p + 0x54) + 0x26) = 0;
        (*(UlPane**)(*(u8**)(p + 0x60) + 4))->setAlpha(0);
        *(s16*)(*(u8**)(p + 0x60) + 0x26) = 0;
        p += 4;
    }
    (*(UlPane**)(self + 4))->find(0x5063756c3031ULL)
        ->move(lbl_80543DF8 + *(f32*)(self + 0x114),
               *(f32*)(self + 0x118) + ((f32*)(self + 0x108))[*(s16*)(self + 0xf8)]);
    (*(UlPane**)(self + 4))->find(0x5063756c3031ULL)->setAlpha(0);
    *(s16*)(self + 0x132) = 0;
    *(s16*)(self + 0xfe) = 0;
    *(s16*)(self + 0xfa) = 2;
}

extern "C" void fn_80134D20(u8*, s32);
extern u8* lbl_8053AAF8;
extern "C" MenuTables8044 lbl_80490FC8;
extern "C" void* fn_8013CC50(void*, f32*, u16, s32, s32, s32, s32, s32, f32);
extern f32 lbl_80543E00;
extern f32 lbl_80543E04;
extern "C" u8 fn_8044CB00(u8* p) { return p[0x140]; }

#pragma opt_strength_reduction off
extern "C" void fn_8044CB08(u8* self, s32 index) {
    MenuTables8044* data = &lbl_80490FC8;
    MenuParticles8044* menu = (MenuParticles8044*)self;
    u64* a;
    u64* b;
    s32 i;
    f32 origin;
    f32 height;
    f32 width;
    if (index < 0) return;
    if (index > 6) return;
    fn_80134D20(lbl_8053AAF8, 0);
    self[0x140] = 1;
    self[0x137] = 2;
    *(s16*)(self + 0x134) = 0;
    self[0x138] = index;
    a = data->picture;
    b = data->window;
    for (i = 0; i < 3; i++, a++, b++) {
        ((J2DPicture*)(*(J2DPane**)(self + 4))->search(*a))->setBlackWhite(JUtility::TColor(0, 0, 0, self[0x157]), JUtility::TColor(100, 100, 100, self[0x15f]));
        ((J2DWindow*)(*(J2DPane**)(self + 4))->search(*b))->setBlackWhite(JUtility::TColor(80, 80, 80, self[0x147]), JUtility::TColor(80, 80, 80, self[0x14f]));
        ((J2DWindow*)(*(J2DPane**)(self + 4))->search(*b))->setContentsColor(JUtility::TColor(150, 150, 150, self[0x167]), JUtility::TColor(150, 150, 150, self[0x16b]), JUtility::TColor(150, 150, 150, self[0x16f]), JUtility::TColor(150, 150, 150, self[0x173]));
        (*(J2DPane**)(self + 4))->search(*b)->setAlpha(200);
    }
    (*(J2DPane**)(self+4))->search(*(u64*)((u32)data->hide168 + (u32)self[0x138]*8))->hide();
    (*(J2DPane**)(self+4))->search(*(u64*)((u32)data->hide210 + (u32)self[0x138]*8))->hide();
    (*(J2DPane**)(self+4))->search(*(u64*)((u32)data->alpha1a0 + (u32)self[0x138]*8))->setAlpha(0);
    (*(J2DPane**)(self+4))->search(*(u64*)((u32)data->alpha1d8 + (u32)self[0x138]*8))->setAlpha(0);

    if (menu->first[self[0x138]] == 0) {
        f32 pos[3];
        J2DPane* pane = (*(J2DPane**)(self+4))->search(*(u64*)((u32)data->hide210 + (u32)self[0x138]*8));
        height = pane->mBounds.f.y - pane->mBounds.i.y;
        origin = (*(J2DPane**)(self+4))->search(*(u64*)((u32)data->hide210 + (u32)self[0x138]*8))->getBounds()->i.y;
        height = (*(J2DPane**)(self+4))->search(0x004e646174613036ULL)->getBounds()->i.y + origin + height * lbl_80543E00;
        pane = (*(J2DPane**)(self+4))->search(*(u64*)((u32)data->hide210 + (u32)self[0x138]*8));
        width = pane->mBounds.f.x - pane->mBounds.i.x;
        origin = (*(J2DPane**)(self+4))->search(*(u64*)((u32)data->hide210 + (u32)self[0x138]*8))->getBounds()->i.x;
        pos[0] = (*(J2DPane**)(self+4))->search(0x004e646174613036ULL)->getBounds()->i.x + origin + width * lbl_80543E00;
        pos[1] = height;
        pos[2] = lbl_80543DFC;
        menu->first[self[0x138]] = fn_8013CC50(0, pos, *(u16*)((u32)data->particle3e8 + (u32)self[0x138]*2), 0,0,0,0,1,lbl_80543E04);
    }

    if (menu->second[self[0x138]] == 0) {
        f32 pos[3];
        J2DPane* pane = (*(J2DPane**)(self+4))->search(*(u64*)((u32)data->hide210 + (u32)self[0x138]*8));
        height = pane->mBounds.f.y - pane->mBounds.i.y;
        origin = (*(J2DPane**)(self+4))->search(*(u64*)((u32)data->hide210 + (u32)self[0x138]*8))->getBounds()->i.y;
        height = (*(J2DPane**)(self+4))->search(0x004e646174613036ULL)->getBounds()->i.y + origin + height * lbl_80543E00;
        pane = (*(J2DPane**)(self+4))->search(*(u64*)((u32)data->hide210 + (u32)self[0x138]*8));
        width = pane->mBounds.f.x - pane->mBounds.i.x;
        origin = (*(J2DPane**)(self+4))->search(*(u64*)((u32)data->hide210 + (u32)self[0x138]*8))->getBounds()->i.x;
        pos[0] = (*(J2DPane**)(self+4))->search(0x004e646174613036ULL)->getBounds()->i.x + origin + width * lbl_80543E00;
        pos[1] = height;
        pos[2] = lbl_80543DFC;
        menu->second[self[0x138]] = fn_8013CC50(0, pos, *(u16*)((u32)data->particle3f8 + (u32)self[0x138]*2), 0,0,0,0,1,lbl_80543E04);
    }
    *(u32*)((u8*)menu->first[self[0x138]]+0xf4) |= 1;
    *(u32*)((u8*)menu->first[self[0x138]]+0xf4) |= 2;
    *(u32*)((u8*)menu->first[self[0x138]]+0xf4) |= 4;
    *(u32*)((u8*)menu->second[self[0x138]]+0xf4) |= 1;
    *(u32*)((u8*)menu->second[self[0x138]]+0xf4) |= 2;
    *(u32*)((u8*)menu->second[self[0x138]]+0xf4) |= 4;
    (*(J2DPane**)(self+4))->search(0x5063756c3031ULL)->hide();
}
#pragma opt_strength_reduction reset
extern "C" u8 fn_8044D290(u8* p) { return p[0x140]; }

extern "C" void fn_80134D20(u8*, s32);
extern u8* lbl_8053AAF8;
extern "C" MenuTables8044 lbl_80490FC8;
extern "C" void* fn_8013CC50(void*, f32*, u16, s32, s32, s32, s32, s32, f32);
extern f32 lbl_80543E00;
extern f32 lbl_80543E04;
extern "C" u16 lbl_80543DD8[4];
#pragma opt_strength_reduction off
#pragma opt_common_subs reset
#pragma opt_propagation reset
#pragma peephole reset
extern "C" void fn_8044D298(u8* self, int index) {
    MenuTables8044* data;
    data = &lbl_80490FC8;
    u64* a;
    u64* b;
    s32 i;
    J2DPane* f;
    f32 f30;
    f32 f31;
    f32 f29;
    f32 pos[3];
    if (index < 0) {
        return;
    }
    if (index > 3) {
        return;
    }
    fn_80134D20(lbl_8053AAF8, 0);
    self[0x140] = 1;
    self[0x137] = 1;
    *(s16*)(self + 0x134) = 0;
    self[0x138] = index;
    a = data->picture;
    b = data->window;
    for (i = 0; i < 3; i++, a++, b++) {
        ((J2DPicture*)(*(J2DPane**)(self + 4))->search(*a))->setBlackWhite(JUtility::TColor(0, 0, 0, self[0x157]), JUtility::TColor(100, 100, 100, self[0x15f]));
        ((J2DWindow*)(*(J2DPane**)(self + 4))->search(*b))->setBlackWhite(JUtility::TColor(80, 80, 80, self[0x147]), JUtility::TColor(80, 80, 80, self[0x14f]));
        ((J2DWindow*)(*(J2DPane**)(self + 4))->search(*b))->setContentsColor(JUtility::TColor(150, 150, 150, self[0x167]), JUtility::TColor(150, 150, 150, self[0x16b]), JUtility::TColor(150, 150, 150, self[0x16f]), JUtility::TColor(150, 150, 150, self[0x173]));
        (*(J2DPane**)(self + 4))->search(*b)->setAlpha(200);
    }
    (*(J2DPane**)(self + 4))->search(*(u64*)((u32)data->show248 + (u32)self[0x138]*8))->show();
    (*(J2DPane**)(self + 4))->search(*(u64*)((u32)data->show248 + (u32)self[0x138]*8))->setAlpha(0);
    (*(J2DPane**)(self + 4))->search(*(u64*)((u32)data->alpha268 + (u32)self[0x138]*8))->setAlpha(0);
    (*(J2DPane**)(self + 4))->search(*(u64*)((u32)data->alpha288 + (u32)self[0x138]*8))->setAlpha(0);
    if (((void**)(self + 0xb0))[self[0x138]] == NULL) {
        f = (*(J2DPane**)(self + 4))->search(*(u64*)((u32)data->alpha268 + (u32)self[0x138]*8));
        f30 = *(f32*)((u8*)f + 0x2c) - *(f32*)((u8*)f + 0x24);
        f = (*(J2DPane**)(self + 4))->search(*(u64*)((u32)data->show248 + (u32)self[0x138]*8));
        f31 = ((J2DPane*)f)->getBounds()->i.y;
        f = (*(J2DPane**)(self + 4))->search(0x4E646174616A3031ULL);
        f31 += ((J2DPane*)f)->getBounds()->i.y;
        f = (*(J2DPane**)(self + 4))->search(*(u64*)((u32)data->alpha268 + (u32)self[0x138]*8));
        f30 = ((J2DPane*)f)->getBounds()->i.y + f31 + f30 * lbl_80543E00;
        f = (*(J2DPane**)(self + 4))->search(*(u64*)((u32)data->alpha268 + (u32)self[0x138]*8));
        f29 = *(f32*)((u8*)f + 0x28) - *(f32*)((u8*)f + 0x20);
        f = (*(J2DPane**)(self + 4))->search(*(u64*)((u32)data->show248 + (u32)self[0x138]*8));
        f31 = ((J2DPane*)f)->getBounds()->i.x;
        f = (*(J2DPane**)(self + 4))->search(0x4E646174616A3031ULL);
        f31 += ((J2DPane*)f)->getBounds()->i.x;
        f = (*(J2DPane**)(self + 4))->search(*(u64*)((u32)data->alpha268 + (u32)self[0x138]*8));
        pos[0] = ((J2DPane*)f)->getBounds()->i.x + f31 + f29 * lbl_80543E00;
        pos[1] = f30;
        pos[2] = lbl_80543DFC;
        *(void**)(self + 0xb0 + self[0x138] * 4) = fn_8013CC50(0, pos, lbl_80543DD8[self[0x138]], 0, 0, 0, 0, 1, lbl_80543E04);
    }
    *(u32*)((u8*)*(void**)(self + 0xb0 + self[0x138] * 4) + 0xf4) |= 1;
        *(u32*)((u8*)*(void**)(self + 0xb0 + self[0x138] * 4) + 0xf4) |= 2;
        *(u32*)((u8*)*(void**)(self + 0xb0 + self[0x138] * 4) + 0xf4) |= 4;
    f = (*(J2DPane**)(self + 4))->search(0x5063756c3031ULL);
    f->hide();
}

#pragma opt_strength_reduction reset
#pragma opt_common_subs reset
#pragma opt_propagation reset
#pragma peephole reset
#pragma dont_inline on
extern "C" void fn_8044D894(u8* self) {
    u8* p;
    s32 i;
    if (*(s16*)(self + 0xf8) != 0) {
        return;
    }
    for (i = 0; i < 3; i++) {
        ((UlPane*)(*(u8**)(self + 4)))->setAlpha(0);
        ((UlPane*)(*(u8**)(self + 4)))->setAlpha(0);
    }
    for (i = 0; i < 3; i++) {
        p = self;
        (void)p;
    }
    p = self;
    (void)p;
}

#pragma dont_inline reset
extern "C" void* fn_8044F664(void) {
    if (lbl_8053AF40 != 0) {
        return *(void**)((char*)lbl_8053AF40 + 0x184);
    }
    return (void*)9;
}

void fn_8044F680(u8* self)
{
    *(s32*)(self + 0x184) = 9;
    if (*(s16*)(self + 0xfa) == 2) {
        return;
    }
}

extern "C" void fn_804522C8(u8* p) {
    if (*(s16*)(p + 0xfa) == 7 || *(s16*)(p + 0xfa) == 8 || *(s16*)(p + 0xfa) == 9) {
        fn_804316EC(lbl_8053AEC0);
    }
}

extern "C" void fn_8013B490(void*);
extern u8* lbl_8053AB10;
extern f32 lbl_80543DFC;
struct J2DGrafContext;
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(J2DScreen*, f32, f32, const J2DGrafContext*);
extern "C" void fn_80452308(void* self_) {
    u8* self = (u8*)self_;
    fn_8013B490(lbl_8053AB10);
    f32 f = lbl_80543DFC;
    draw__9J2DScreenFffPC14J2DGrafContext(*(J2DScreen**)(self + 4), f, f, *(const J2DGrafContext**)(lbl_8053AB10 + 0x10));
}

extern "C" void fn_804310CC(void*);
extern "C" u32 fn_804030C4(u32, void*);
extern "C" u32 fn_80403084(u32, void*);
extern "C" void fn_8044D894(u8*);
extern "C" char lbl_80529DEC[];
extern "C" char lbl_80491400[];
extern "C" char lbl_80491414[];
extern "C" u8* lbl_8053AAF8;
extern f32 lbl_80543E18;
#pragma auto_inline off
extern "C" void fn_80452350(u8* self) {
	u8* p;
	int i;
	fn_804310CC(lbl_8053AEC0);
	*(s16*)(self + 0xfe) = *(s16*)(self + 0xf8) = i = 0;
	p = self;
	do {
		fn_80402E08(*(void**)(p + 0x48), lbl_80543DF8, lbl_80543DFC);
		fn_80402E08(*(void**)(p + 0x60), lbl_80543DF8, lbl_80543DFC);
		*(s16*)(*(u8**)(p + 0x48) + 0x20) = 0;
		*(s16*)(*(u8**)(p + 0x60) + 0x20) = 0;
		(*(UlPane**)(*(u8**)(p + 0x48) + 4))->setAlpha(0);
		*(s16*)(*(u8**)(p + 0x48) + 0x26) = 0;
		(*(UlPane**)(*(u8**)(p + 0x54) + 4))->setAlpha(0);
		*(s16*)(*(u8**)(p + 0x54) + 0x26) = 0;
		(*(UlPane**)(*(u8**)(p + 0x60) + 4))->setAlpha(0);
		*(s16*)(*(u8**)(p + 0x60) + 0x26) = 0;
		p += 4;
		i++;
	} while (i < 3);
	(*(UlPane**)(self + 4))->find(0x5063756c3031ULL)
		->move(lbl_80543DF8 + *(f32*)(self + 0x114),
		       *(f32*)(self + 0x118) + ((f32*)(self + 0x108))[*(s16*)(self + 0xf8)]);
	(*(UlPane**)(self + 4))->find(0x5063756c3031ULL)->setAlpha(0);
	*(s16*)(self + 0x132) = 0;
	*(s16*)(self + 0xfe) = 0;
	*(s16*)(self + 0xfa) = 2;
	*(s16*)(self + 0xfc) = 0;
	(*(UlPane**)(*(u8**)(self + 8) + 4))->setAlpha(0);
	*(s16*)(*(u8**)(self + 8) + 0x26) = 0;
	p = self;
	for (int j = 0; j < 0xf; j++) {
		fn_80402E08(*(void**)(p + 0xc), lbl_80543DFC, lbl_80543E18);
		*(s16*)(*(u8**)(p + 0xc) + 0x22) = 0;
		p += 4;
	}
	if (*(u8*)(lbl_8053AAF8 + 0x7f) != 0 && (
		(*(s32*)(lbl_80529DEC + 0x118) == 0 && *(s32*)(lbl_80529DEC + 0x11c) == 2) ||
		(*(s32*)(lbl_80529DEC + 0x118) == 1 && *(s32*)(lbl_80529DEC + 0x11c) == 2) ||
		(*(s32*)(lbl_80529DEC + 0x118) == 2 && *(s32*)(lbl_80529DEC + 0x11c) == 2) ||
		(*(s32*)(lbl_80529DEC + 0x118) == 3 && *(s32*)(lbl_80529DEC + 0x11c) == 2) ||
		(*(s32*)(lbl_80529DEC + 0x118) == 4 && *(s32*)(lbl_80529DEC + 0x11c) == 2) ||
		(*(s32*)(lbl_80529DEC + 0x118) == 5 && *(s32*)(lbl_80529DEC + 0x11c) == 2) ||
		(*(s32*)(lbl_80529DEC + 0x118) == 6 && *(s32*)(lbl_80529DEC + 0x11c) == 2) ||
		(*(s32*)(lbl_80529DEC + 0x118) == 7 && *(s32*)(lbl_80529DEC + 0x11c) == 1))) {
		u32 h = fn_804030C4(0x54494d47, lbl_80491400);
		((J2DPicture*)(*(UlPane**)(self + 4))->find(0x5073633031ULL))->changeTexture((const ResTIMG*)h, 0);
	} else {
		u32 h = fn_80403084(0x54494d47, lbl_80491414);
		((J2DPicture*)(*(UlPane**)(self + 4))->find(0x5073633031ULL))->changeTexture((const ResTIMG*)h, 0);
	}
	fn_8044D894(self);
	*(s32*)(self + 0x184) = 9;
}
#pragma auto_inline reset
extern "C" void* fn_8045270C(u8* self, s16 deleting) {
    if (self != NULL) {
        *(void***)(self) = lbl_804B1D58;
        fn_80459274(lbl_8053AF80);
    for (int i = 0; i < 7; i++) {
        if (((MenuEmitters8044*)self)->a[i] != NULL) {
            ((MenuEmitters8044*)self)->a[i]->becomeInvalidEmitter();
            ((MenuEmitters8044*)self)->a[i] = NULL;
        }
        if (((MenuEmitters8044*)self)->b[i] != NULL) {
            ((MenuEmitters8044*)self)->b[i]->becomeInvalidEmitter();
            ((MenuEmitters8044*)self)->b[i] = NULL;
        }
    }
    for (int j = 0; j < 2; j++) {
        JPABaseEmitter** __restrict d = ((MenuEmitters8044*)self)->d[j];
        if (d[0] != NULL) {
            d[0]->becomeInvalidEmitter();
            d[0] = NULL;
        }
        if (d[1] != NULL) {
            d[1]->becomeInvalidEmitter();
            d[1] = NULL;
        }
    }
    for (int k = 0; k < 3; k++) {
        if (((MenuEmitters8044*)self)->c[k] != NULL) {
            JPAEmitterManager* mgr = *(JPAEmitterManager**)((u8*)fn_8013C824() + 0xc);
            mgr->forceDeleteEmitter(((MenuEmitters8044*)self)->c[k]);
            ((MenuEmitters8044*)self)->c[k] = NULL;
        }
        if (((MenuEmitters8044*)self)->e[k] != NULL) {
            JPAEmitterManager* mgr = *(JPAEmitterManager**)((u8*)fn_8013C824() + 0xc);
            mgr->forceDeleteEmitter(((MenuEmitters8044*)self)->e[k]);
            ((MenuEmitters8044*)self)->e[k] = NULL;
        }
    }
        if (*(Deletable**)(self + 0x4) != NULL) {
            (*(Deletable**)(self + 0x4))->del(1);
        }
        *(void**)(self + 0x4) = NULL;
        for (int i = 0; i < 4; i++) {
            if (*(Deletable**)(self + 0xd8 + i * 4) != NULL) {
                (*(Deletable**)(self + 0xd8 + i * 4))->del(1);
            }
            *(void**)(self + 0xd8 + i * 4) = NULL;
        }
        if (*(Deletable**)(self + 0xec) != NULL) {
            (*(Deletable**)(self + 0xec))->del(1);
        }
        *(void**)(self + 0xec) = NULL;
        if (*(Deletable**)(self + 0xf4) != NULL) {
            (*(Deletable**)(self + 0xf4))->del(1);
        }
        *(void**)(self + 0xf4) = NULL;
        if (*(Deletable**)(self + 0xd0) != NULL) {
            (*(Deletable**)(self + 0xd0))->del(1);
        }
        *(void**)(self + 0xd0) = NULL;
        if (*(Deletable**)(self + 0x8) != NULL) {
            (*(Deletable**)(self + 0x8))->del(1);
        }
        *(void**)(self + 0x8) = NULL;
        for (int i = 0; i < 15; i++) {
            if (*(Deletable**)(self + 0xc + i * 4) != NULL) {
                (*(Deletable**)(self + 0xc + i * 4))->del(1);
            }
            *(void**)(self + 0xc + i * 4) = NULL;
        }
        for (int i = 0; i < 3; i++) {
            if (*(Deletable**)(self + 0x48 + i * 4) != NULL) {
                (*(Deletable**)(self + 0x48 + i * 4))->del(1);
            }
            *(void**)(self + 0x48 + i * 4) = NULL;
            if (*(Deletable**)(self + 0x54 + i * 4) != NULL) {
                (*(Deletable**)(self + 0x54 + i * 4))->del(1);
            }
            *(void**)(self + 0x54 + i * 4) = NULL;
            if (*(Deletable**)(self + 0x60 + i * 4) != NULL) {
                (*(Deletable**)(self + 0x60 + i * 4))->del(1);
            }
            *(void**)(self + 0x60 + i * 4) = NULL;
        }
        lbl_8053AF40 = NULL;
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
extern "C" void __construct_array(void*, void*, void*, u32, u32);
extern "C" void __ct__Q28JUtility6TColorFv(void*);
extern "C" void fn_80453830(void*);
extern "C" void* lbl_804AF86C[];
struct MenuRes8044 {
    void* vt;
    u8* data;
    u8 pad[0x24];
    MenuRes8044() { vt = lbl_804AF86C; }
};
static inline void MenuSetContents8044(J2DWindow* window, J2DWindow::TContentsColor color) {
    window->setContentsColor(color.mColorA, color.mColorB, color.mColorC, color.mColorD);
}
struct MenuAnm8044 {
    virtual void v08();
    virtual void searchUpdateMaterialID(J2DScreen*);
};
extern "C" void fn_80402F04(void*, void*);
extern "C" MenuAnm8044* load__20J2DAnmLoaderDataBaseFPCv(const void* p);
#pragma opt_loop_invariants off
extern "C" u8* fn_80452A80(u8* self) {
    MenuTables8044* data;
    u64* win;
    u64* pic;
    u64* tag;
    u64* tag2;
    s32 i;
    data = &lbl_80490FC8;
    *(void**)self = lbl_804B1D58;
    __construct_array(self + 0x144, __ct__Q28JUtility6TColorFv, 0, 4, 2);
    __construct_array(self + 0x14c, __ct__Q28JUtility6TColorFv, 0, 4, 2);
    __construct_array(self + 0x154, __ct__Q28JUtility6TColorFv, 0, 4, 2);
    __construct_array(self + 0x15c, __ct__Q28JUtility6TColorFv, 0, 4, 2);
    __construct_array(self + 0x164, fn_80453830, 0, 0x10, 2);
    lbl_8053AF40 = self;
    *(J2DScreen**)(self + 4) = new J2DScreen;
    (*(J2DScreen**)(self + 4))->setPriority((char*)data + 0x460, 0x1100000, *(JKRArchive**)(lbl_80529DEC + 0x4c));
    OSInitFastCast();
    tag = data->alpha288;
    for (i = 0; i < 4; i++) {
        *(u32*)(self + 0xd4) = fn_80403084(0x5343524e, (char*)data + 0x46c);
        *(MenuAnm8044**)(self + 0xd8 + i * 4) = load__20J2DAnmLoaderDataBaseFPCv(*(void**)(self + 0xd4));
        (*(MenuAnm8044**)(self + 0xd8 + i * 4))->searchUpdateMaterialID(*(J2DScreen**)(self + 4));
        (*(J2DScreen**)(self + 4))->search(tag[i])->setAnimation((J2DAnmTextureSRTKey*)*(MenuAnm8044**)(self + 0xd8 + i * 4));
    }
    *(u32*)(self + 0x124) = 0;
    *(u32*)(self + 0xe8) = fn_80403084(0x5343524e, (char*)data + 0x478);
    *(MenuAnm8044**)(self + 0xec) = load__20J2DAnmLoaderDataBaseFPCv(*(void**)(self + 0xe8));
    (*(MenuAnm8044**)(self + 0xec))->searchUpdateMaterialID(*(J2DScreen**)(self + 4));
    (*(J2DScreen**)(self + 4))->search(0x50706f3031ULL)->setAnimation((J2DAnmTextureSRTKey*)*(MenuAnm8044**)(self + 0xec));
    *(u32*)(self + 0x128) = 0;
    *(u32*)(self + 0xf0) = fn_80403084(0x5343524e, (char*)data + 0x488);
    *(MenuAnm8044**)(self + 0xf4) = load__20J2DAnmLoaderDataBaseFPCv(*(void**)(self + 0xf0));
    (*(MenuAnm8044**)(self + 0xf4))->searchUpdateMaterialID(*(J2DScreen**)(self + 4));
    (*(J2DScreen**)(self + 4))->search(0x50706f3032ULL)->setAnimation((J2DAnmTextureSRTKey*)*(MenuAnm8044**)(self + 0xf4));
    *(u32*)(self + 0x12c) = 0;
    self[0x13e] = 0;
    *(u32*)(self + 0xcc) = fn_80403084(0x5343524e, (char*)data + 0x498);
    *(MenuAnm8044**)(self + 0xd0) = load__20J2DAnmLoaderDataBaseFPCv(*(void**)(self + 0xcc));
    (*(J2DScreen**)(self + 4))->setAnimation((J2DAnmTevRegKey*)*(MenuAnm8044**)(self + 0xd0));
    *(s16*)(self + 0x130) = 0;
    *(s16*)(self + 0x132) = 0;
    *(f32*)(self + 0x114) = (*(J2DScreen**)(self + 4))->search(0x5063756c3031ULL)->getBounds()->i.x;
    *(f32*)(self + 0x118) = (*(J2DScreen**)(self + 4))->search(0x5063756c3031ULL)->getBounds()->i.y;
    pic = lbl_80490FC8.picture;
    for (i = 0; i < 3; i++) {
        f32 base = (*(J2DScreen**)(self + 4))->search(data->picture[0])->getBounds()->i.y;
        *(f32*)(self + 0x108 + i * 4) = (*(J2DScreen**)(self + 4))->search(pic[i])->getBounds()->i.y - base;
    }
    self[0x13b] = (*(J2DScreen**)(self + 4))->search(data->show248[0])->mAlpha;
    self[0x13c] = (*(J2DScreen**)(self + 4))->search(data->alpha268[0])->mAlpha;
    self[0x13d] = (*(J2DScreen**)(self + 4))->search(data->alpha288[0])->mAlpha;
    self[0x139] = (*(J2DScreen**)(self + 4))->search(data->alpha1a0[0])->mAlpha;
    self[0x13a] = (*(J2DScreen**)(self + 4))->search(data->alpha1d8[0])->mAlpha;
    tag = data->alpha1a0;
    tag2 = data->alpha1d8;
    for (i = 0; i < 7; i++, tag++, tag2++) {
        (*(J2DScreen**)(self + 4))->search(*tag)->mIsVisible = false;
        (*(J2DScreen**)(self + 4))->search(*tag2)->mIsVisible = false;
    }
    win = lbl_80490FC8.window;
    for (i = 0; i < 2; i++) {
        *(JUtility::TColor*)(self + 0x154 + i * 4) = ((J2DPicture*)(*(J2DScreen**)(self + 4))->search(pic[i]))->getBlack();
        *(JUtility::TColor*)(self + 0x15c + i * 4) = ((J2DPicture*)(*(J2DScreen**)(self + 4))->search(pic[i]))->getWhite();
        *(JUtility::TColor*)(self + 0x144 + i * 4) = ((J2DWindow*)(*(J2DScreen**)(self + 4))->search(win[i]))->getBlack();
        *(JUtility::TColor*)(self + 0x14c + i * 4) = ((J2DWindow*)(*(J2DScreen**)(self + 4))->search(win[i]))->getWhite();
        ((J2DWindow*)(*(J2DScreen**)(self + 4))->search(win[i]))->getContentsColor(*(J2DWindow::TContentsColor*)(self + 0x164 + i * 16));
        self[0x15f + i * 4] = 0xff;
        self[0x157 + i * 4] = 0;
        self[0x14f + i * 4] = 0xff;
        self[0x147 + i * 4] = 0xff;
    }
    self[0x173] = 0xff; self[0x16f] = 0xff; self[0x16b] = 0xff; self[0x167] = 0xff;
    self[0x183] = 0xc8; self[0x17f] = 0xc8; self[0x17b] = 0xc8; self[0x177] = 0xc8;
    ((JUtility::TColor*)(self + 0x15c))->set(0xa7, 0x4c, 0x2a, self[0x15f]);
    ((JUtility::TColor*)(self + 0x154))->set(0x27, 0x10, 0x00, self[0x157]);
    ((JUtility::TColor*)(self + 0x160))->set(0xff, 0xed, 0xa0, self[0x163]);
    ((JUtility::TColor*)(self + 0x158))->set(0x00, 0x00, 0x00, self[0x15b]);
    self[0x14c] = 0x7f; self[0x14d] = 0x51; self[0x14e] = 0x18;
    self[0x144] = 0x7f; self[0x145] = 0x51; self[0x146] = 0x18;
    self[0x150] = 0x7f; self[0x151] = 0x51; self[0x152] = 0x18;
    self[0x148] = 0x7f; self[0x149] = 0x51; self[0x14a] = 0x18;
    ((JUtility::TColor*)(self + 0x164))->set(0xc0, 0x91, 0x4c, self[0x167]);
    ((JUtility::TColor*)(self + 0x168))->set(0xc0, 0x91, 0x4c, self[0x16b]);
    ((JUtility::TColor*)(self + 0x16c))->set(0xe6, 0xe1, 0x87, self[0x16f]);
    ((JUtility::TColor*)(self + 0x170))->set(0xe6, 0xe1, 0x87, self[0x173]);
    ((JUtility::TColor*)(self + 0x174))->set(0xa9, 0x80, 0x46, self[0x177]);
    ((JUtility::TColor*)(self + 0x178))->set(0xa9, 0x80, 0x46, self[0x17b]);
    ((JUtility::TColor*)(self + 0x17c))->set(0xa9, 0x80, 0x46, self[0x17f]);
    ((JUtility::TColor*)(self + 0x180))->set(0xa9, 0x80, 0x46, self[0x183]);
    (*(J2DScreen**)(self + 4))->search(lbl_80490FC8.window[1])->setAlpha(0xff);
    *(MenuRes8044**)(self + 8) = new MenuRes8044;
    fn_80402F04(*(void**)(self + 8), (*(J2DScreen**)(self + 4))->search(0x50626c61636bULL));
    tag = (u64*)((u8*)data + 0x2a8);
    for (i = 0; i < 15; i++) {
        *(MenuRes8044**)(self + 0xc + i * 4) = new MenuRes8044;
        fn_80402F04(*(MenuRes8044**)(self + 0xc + i * 4), (*(J2DScreen**)(self + 4))->search(tag[i]));
    }
    tag = (u64*)((u8*)data + 0x30);
    for (i = 0; i < 3; i++) {
        *(MenuRes8044**)(self + 0x48 + i * 4) = new MenuRes8044;
        fn_80402F04(*(MenuRes8044**)(self + 0x48 + i * 4), (*(J2DScreen**)(self + 4))->search(pic[i]));
        *(MenuRes8044**)(self + 0x54 + i * 4) = new MenuRes8044;
        fn_80402F04(*(MenuRes8044**)(self + 0x54 + i * 4), (*(J2DScreen**)(self + 4))->search(win[i]));
        *(MenuRes8044**)(self + 0x60 + i * 4) = new MenuRes8044;
        fn_80402F04(*(MenuRes8044**)(self + 0x60 + i * 4), (*(J2DScreen**)(self + 4))->search(tag[i]));
    }
    *(s16*)(self + 0xf8) = 0;
    *(s16*)(self + 0xfe) = 0;
    *(s16*)(self + 0xfa) = 2;
    *(s16*)(self + 0xfc) = 0;
    (*(UlPane**)(*(u8**)(self + 8) + 4))->setAlpha(0);
    *(s16*)(*(u8**)(self + 8) + 0x26) = 0;
    for (i = 0; i < 15; i++) {
        fn_80402E08(*(void**)(self + 0xc + i * 4), lbl_80543DFC, lbl_80543E18);
        *(s16*)(*(u8**)(self + 0xc + i * 4) + 0x22) = 0;
    }
    for (i = 0; i < 3; i++, pic++, win++) {
        if (i == *(s16*)(self + 0xf8)) {
            ((J2DPicture*)(*(J2DScreen**)(self + 4))->search(*pic))->setBlackWhite(*(JUtility::TColor*)(self + 0x154), *(JUtility::TColor*)(self + 0x15c));
            ((J2DWindow*)(*(J2DScreen**)(self + 4))->search(*win))->setBlackWhite(*(JUtility::TColor*)(self + 0x144), *(JUtility::TColor*)(self + 0x14c));
            MenuSetContents8044((J2DWindow*)(*(J2DScreen**)(self + 4))->search(*win), *(J2DWindow::TContentsColor*)(self + 0x164));
            (*(J2DScreen**)(self + 4))->search(*win)->setAlpha(0xff);
        } else {
            ((J2DPicture*)(*(J2DScreen**)(self + 4))->search(*pic))->setBlackWhite(*(JUtility::TColor*)(self + 0x158), *(JUtility::TColor*)(self + 0x160));
            ((J2DWindow*)(*(J2DScreen**)(self + 4))->search(*win))->setBlackWhite(*(JUtility::TColor*)(self + 0x148), *(JUtility::TColor*)(self + 0x150));
            MenuSetContents8044((J2DWindow*)(*(J2DScreen**)(self + 4))->search(*win), *(J2DWindow::TContentsColor*)(self + 0x174));
            (*(J2DScreen**)(self + 4))->search(*win)->setAlpha(0xc8);
        }
    }
    self[0x136] = 0;
    self[0x13f] = 1;
    self[0x140] = 0;
    *(u32*)(self + 0x120) = 0;
    self[0x137] = 0;
    *(s16*)(self + 0x134) = 0;
    self[0x138] = 0;
    MenuEmitters8044* t = (MenuEmitters8044*)self;
    for (i = 0; i < 7; i++) {
        t->a[i] = NULL;
        t->b[i] = NULL;
    }
    for (i = 0; i < 2; i++) {
        t->d[i][0] = NULL;
        t->d[i][1] = NULL;
    }
    for (i = 0; i < 3; i++) {
        t->c[i] = NULL;
        t->e[i] = NULL;
    }
    return self;
}
#pragma opt_loop_invariants reset
extern "C" void fn_80453830(void* thisPtr) {
	s32* p = (s32*)thisPtr;
	p[0] = -1;
	p[1] = -1;
	p[2] = -1;
	p[3] = -1;
}

extern "C" u8 fn_80453848(u8* p) {
    u8 dead = 0;
    if ((*(u32*)(p + 0xf4) & 8) && *(s32*)(p + 0xd0) + *(s32*)(p + 0xdc) == 0) {
        dead = 1;
    }
    return dead;
}

extern "C" void fn_80453874(void* thisObj, f32 x, f32 y, f32 z) {
	*(f32*)((char*)thisObj + 0x0) = x;
	*(f32*)((char*)thisObj + 0x4) = y;
	*(f32*)((char*)thisObj + 0x8) = z;
}

extern "C" void fn_80453884(J2DWindow* window, const JUtility::TColor* colors) {
    window->setContentsColor(colors[0], colors[1], colors[2], colors[3]);
}

extern "C" char lbl_8052D700[];
extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __register_global_object(void*, void (*)(void*), void*);
extern "C" char memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[];
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" char memPool___30JASPoolAllocObject_9JAIStream[];
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*);
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" char memPool___35JASPoolAllocObject_13JAISoundChild[];
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" char memPool___27JASPoolAllocObject_6JAISeq[];
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*);
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" char memPool___26JASPoolAllocObject_5JAISe[];
extern "C" void __dt__18JASMemPool_5JAISeFv(void*);
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;
extern "C" void fn_804538D4(void)
{
    struct PoolBase {
        u32 first;
    };
    PoolBase* base = (PoolBase*)&lbl_8052D700;
    u8* pool = (u8*)base;
    if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, (u8*)&base->first + 0x0);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, pool + 0xc);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, pool + 0x18);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, pool + 0x24);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, pool + 0x30);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, pool + 0x3c);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, pool + 0x48);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, pool + 0x54);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, pool + 0x60);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}

