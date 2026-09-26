// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 80160650-801618D0 (EZRY). Remaining functions are not yet decompiled.
#include "types.h"
#include "Game/ItemBase.h"

// from src/Game/fn_80161638_dtor.cpp
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_804A03B8[];

extern "C" void* fn_80161638(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A03B8;
        char* p = (char*)this_;
        fn_801EE434(*(void**)(p + 0x290));
        fn_801EE434(*(void**)(p + 0x294));
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// from src/Game/Fary_SyncEmberEffectPosition.cpp
// FARY actor cluster, part 4/5. If this->0x290 is set, copies this->0xc/
// 0x10/0x14 (position) into that sub-object's own +0xa4/+0xa8/+0xac
// fields. Does the identical copy for this->0x294 if set. A simple "keep
// both flame/ember effect sub-objects synced to my position" helper.
extern "C" {

void fn_801615EC(void* thisPtr) {
	char* p = (char*)thisPtr;
	void* a = *(void**)(p + 0x290);
	if (a != 0) {
		*(f32*)((char*)a + 0xa4) = *(f32*)(p + 0xc);
		*(f32*)((char*)a + 0xa8) = *(f32*)(p + 0x10);
		*(f32*)((char*)a + 0xac) = *(f32*)(p + 0x14);
	}
	void* b = *(void**)(p + 0x294);
	if (b == 0) return;
	*(f32*)((char*)b + 0xa4) = *(f32*)(p + 0xc);
	*(f32*)((char*)b + 0xa8) = *(f32*)(p + 0x10);
	*(f32*)((char*)b + 0xac) = *(f32*)(p + 0x14);
}

}

class EzryVis {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual u8 isVisible();
};

extern "C" void fn_801F06F0(void* actor, void* res, u32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern "C" void fn_803075AC(void* caller, s32 owner, void* pos, s32 ref, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern u8 lbl_804661C8[];
extern const f32 lbl_8053D670;

extern "C" void fn_80160650(char* p) {
    DrawRec rec;
    if ((*(u32*)(p + 0x90) >> 27) != 0 && !((EzryVis*)p)->isVisible()) {
        return;
    }
    if (*(s32*)(p + 0x258) != 2) {
        s32 t = *(s32*)(p + 0x234);
        if (t < 0x100 && (t & 2)) {
            return;
        }
        rec.b2d = 1;
        if (*(s32*)(p + 0x258) == 3) {
            ((u8*)&rec.w10)[3] = (s32)*(f32*)(p + 0x270);
            rec.w30 = 0x11;
        }
        fn_801F06F0(p, lbl_804661C8, *(s32*)(p + 0x250) + 0x5e, &rec, 1, lbl_8053D670, lbl_8053D670);
        fn_803075AC(*(void**)(p + 0x198), *(s32*)(p + 0x4), p + 0xc, *(s32*)(p + 0x250) + 0x5e, 0, 2, -1, 0, 0, 1);
    } else {
        s32 base = 0x5e;
        if (*(s32*)(p + 0x248) != 0) {
            base = 0x7d;
        }
        fn_803075AC(*(void**)(p + 0x198), *(s32*)(p + 0x4), p + 0xc, base + *(s32*)(p + 0x250), 0, 2, -1, 1, 0, 1);
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
