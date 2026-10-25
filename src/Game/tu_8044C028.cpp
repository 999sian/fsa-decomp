#include "types.h"
#include "JSystem/J2D/J2DPane.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "JSystem/J2D/J2DScreen.h"


extern "C" void fn_8044C028(u8* this_, f32 val) {
    this_[0x18] = 1;
    *(f32*)(this_ + 0x14) = val;
}

extern "C" void fn_8044C038(u8* this_) {
    if (this_[0x18] != 0) {
        f32 x = (*(J2DPane**)(this_ + 8))->search(0x54703031)->getBounds()->i.x;
        (*(J2DPane**)(this_ + 8))->search(0x54703031)->move(x, *(f32*)(this_ + 0xc) - *(f32*)(this_ + 0x14));
        x = (*(J2DPane**)(this_ + 8))->search(0x54703032)->getBounds()->i.x;
        (*(J2DPane**)(this_ + 8))->search(0x54703032)->move(x, *(f32*)(this_ + 0x10) - *(f32*)(this_ + 0x14));
    }
}

extern "C" void fn_8013B490(void* p);
extern "C" void* lbl_8053AB10;
extern "C" const f32 lbl_80543DC8;
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(void* self, f32 x, f32 y, void* ctx);
extern "C" void fn_8044C14C(u8* this_) {
    if (this_[0x18] != 0) {
        fn_8013B490(lbl_8053AB10);
        (*(J2DScreen**)(this_ + 4))->draw(lbl_80543DC8, lbl_80543DC8, *(J2DGrafContext**)((u8*)lbl_8053AB10 + 0x10));
        (*(J2DScreen**)(this_ + 8))->setScissor(true);
        (*(J2DScreen**)(this_ + 8))->draw(lbl_80543DC8, lbl_80543DC8, *(J2DGrafContext**)((u8*)lbl_8053AB10 + 0x10));
        this_[0x18] = 0;
    }
}

extern "C" void __dl__FPv(void* p);
extern "C" char lbl_804B1D20[];
extern "C" s32 lbl_8053AF38;

class RupyDeletable {
public:
    virtual ~RupyDeletable();
};
extern "C" void* fn_8044C1CC(void** this_, s16 param_2) {
    if (this_ != nullptr) {
        void** p = this_;
        s32 i = 0;
        *this_ = lbl_804B1D20;
        do {
            delete (RupyDeletable*)p[1];
            i++;
            p++;
            *p = nullptr;
        } while (i < 2);
        lbl_8053AF38 = 0;
        if (param_2 > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" char lbl_80490FA0[];
extern "C" char lbl_80490FB0[];
extern "C" char lbl_80529DEC[];
extern "C" u8* lbl_8053AD78;
extern "C" f32 lbl_80543DCC;
extern "C" f32 lbl_80543DD0;
extern "C" f32 fn_803832BC(char*, s32, s32, s32, s32);
extern "C" char* getStringPtr__10J2DTextBoxCFv(void* this_);
extern "C" void* fn_8044C260(u8* this_) {
    *(void**)this_ = lbl_804B1D20;
    lbl_8053AF38 = (s32)this_;
    *(J2DScreen**)(this_ + 4) = new J2DScreen();
    (*(J2DScreen**)(this_ + 4))->setPriority(lbl_80490FA0, 0x1100000, *(JKRArchive**)(lbl_80529DEC + 0x10));
    *(J2DScreen**)(this_ + 8) = new J2DScreen();
    (*(J2DScreen**)(this_ + 8))->setPriority(lbl_80490FB0, 0x1100000, *(JKRArchive**)(lbl_80529DEC + 0x10));
    JUTFont* font = *(JUTFont**)(lbl_8053AD78 + 0x154);
    ((J2DTextBox*)(*(J2DScreen**)(this_ + 8))->search(0x54703031ULL))->setFont(font);
    font = *(JUTFont**)(lbl_8053AD78 + 0x154);
    ((J2DTextBox*)(*(J2DScreen**)(this_ + 8))->search(0x54703032ULL))->setFont(font);
    fn_803832BC(((J2DTextBox*)(*(J2DScreen**)(this_ + 8))->search(0x54703031ULL))->getStringPtr(), 0x14a, 0, 0, 0);
    fn_803832BC(((J2DTextBox*)(*(J2DScreen**)(this_ + 8))->search(0x54703032ULL))->getStringPtr(), 0x14a, 0, 0, 0);
    *(f32*)(this_ + 0xc) = lbl_80543DCC + (*(J2DScreen**)(this_ + 8))->search(0x54703031ULL)->getBounds()->i.y;
    *(f32*)(this_ + 0x10) = lbl_80543DCC + (*(J2DScreen**)(this_ + 8))->search(0x54703032ULL)->getBounds()->i.y;
    J2DPane* p7 = (*(J2DScreen**)(this_ + 8))->search(0x54703031ULL);
    f32 h = p7->mBounds.f.y - p7->mBounds.i.y;
    h = lbl_80543DD0 * h;
    (*(J2DScreen**)(this_ + 8))->search(0x54703031ULL)->resize(p7->mBounds.f.x - p7->mBounds.i.x, h);
    J2DPane* p9 = (*(J2DScreen**)(this_ + 8))->search(0x54703032ULL);
    (*(J2DScreen**)(this_ + 8))->search(0x54703032ULL)->resize(p9->mBounds.f.x - p9->mBounds.i.x, h);
    u32 a = 0;
    u32 b = 0;
    u32 c = 0;
    u32 d = 0;
    J2DPane* p11 = (*(J2DScreen**)(this_ + 8))->search(0x000050626C6B3031ULL);
    ((void (*)(void*, u32*, u32*))(*(void***)p11)[0x130 / 4])(p11, &d, &b);
    *(u8*)(this_ + 0x18) = 0;
    *(f32*)(this_ + 0x14) = lbl_80543DC8;
    return this_;
}

extern "C" void fn_8044C5CC(void) {}

