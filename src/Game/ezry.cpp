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

struct EzryRandom {
    u32 seed;
    u32 get() {
        seed = 0x19660d * seed + 0x3c6ef35f;
        return seed;
    }
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        out.s = (get() >> 9) | 0x3f800000;
        return out.f - lbl_8053D670;
    }
};

extern "C" void* fn_8013CC50(u32 id, f32* pos, u32 kind, u32 a, u32 b, u32 c, u32 d, u32 e, f32 scale);
extern "C" void fn_801F0E34(void* target, s32 soundId, s32 flag);
extern "C" void fn_8043D67C(void* mgr, s32 id, s32 arg, s32 flag);
extern char* lbl_8053AAF8;
extern void* lbl_8053AED0;
extern u8 lbl_80529DEC[];
extern u8 lbl_8050EC80[];
extern const f32 lbl_8053D688;
extern const f32 lbl_8053D68C;
extern const f32 lbl_8053D690;
extern const f32 lbl_8053D6A4;
extern const f32 lbl_8053D6A8;
extern const f32 lbl_8053D6AC;
extern const f32 lbl_8053D6B0;
extern const f32 lbl_8053D6B4;

struct EzryTimers { u8 pad[0x234]; s32 t[4]; };

#define EZRY_RND() (((EzryRandom*)(lbl_8053AAF8 + 0xb4))->get_ufloat_1())

extern "C" void fn_80161290(char* p) {
    *(f32*)(p + 0x60) = lbl_8053D6A4;
    *(f32*)(p + 0x64) = lbl_8053D6A4;
    *(f32*)(p + 0x68) = lbl_8053D6A8;
    *(f32*)(p + 0x6c) = lbl_8053D6A8;
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    for (int i = 0; i < 4; i++) {
        ((EzryTimers*)p)->t[i] = 0;
    }
    *(s32*)(p + 0x250) = 0;
    *(f32*)(p + 0x26c) = lbl_8053D68C;
    *(f32*)(p + 0x278) = lbl_8053D68C;
    *(f32*)(p + 0x27c) = lbl_8053D68C;
    *(f32*)(p + 0x280) = lbl_8053D68C;
    *(s32*)(p + 0x234) = 0x400;
    *(f32*)(p + 0x280) = lbl_8053D6AC;
    *(s32*)(p + 0x23c) = 10;
    *(s32*)(p + 0x240) = (s32)(lbl_8053D688 * EZRY_RND()) + 0x1e;
    *(s32*)(p + 0x260) = (*(u32*)(p + 0x90) >> 22) & 0x1f;
    *(s32*)(p + 0x258) = (*(u32*)(p + 0x90) >> 4) & 0xf;
    *(s32*)(p + 0x25c) = *(u32*)(p + 0x90) & 0xf;
    *(s32*)(p + 0x264) = 0;
    *(u8*)(p + 0x268) = 0;
    *(f32*)(p + 0x270) = lbl_8053D6B0;
    if (*(s32*)(p + 0x25c) > 0) {
        (*(s32*)(p + 0x25c))--;
    } else {
        *(s32*)(p + 0x25c) = -1;
    }
    *(s32*)(p + 0x248) = (s32)(lbl_8053D690 * EZRY_RND());
    *(s32*)(p + 0x230) = 0;
    *(u32*)(p + 0xb0) = 0x20000;
    *(s32*)(p + 0x254) = -1;
    if (*(s32*)(p + 0x258) == 2) {
        *(u8*)(p + 0x11f) = 1;
    }
    *(void**)(p + 0x290) = 0;
    *(void**)(p + 0x294) = 0;
    *(f32*)(p + 0x284) = *(f32*)(p + 0xc);
    *(f32*)(p + 0x288) = *(f32*)(p + 0x10);
    *(f32*)(p + 0x28c) = *(f32*)(p + 0x14);
    if (*(s32*)(p + 0x258) == 2) {
        *(s32*)(p + 0x234) = 0;
        *(s32*)(p + 0x238) = 0;
        *(s32*)(p + 0x248) = 0;
        *(s32*)(p + 0x230) = 4;
    }
    if (*(s32*)(p + 0x258) == 3) {
        *(s32*)(p + 0x234) = 10000;
        *(f32*)(p + 0x280) = lbl_8053D6B4;
        u8* cnt = &lbl_80529DEC[0x24f];
        if (*cnt < 99) {
            (*cnt)++;
        } else {
            *cnt = 99;
        }
        *(s32*)(p + 0x23c) = 0x1e;
        fn_801F0E34(p, 0x400e5, 0);
        *(s32*)(p + 0x230) = 5;
    }
    if ((*(u32*)(p + 0x90) >> 27) != 0 && !((EzryVis*)p)->isVisible()) {
        *(u32*)(p + 0xb0) = 0;
        return;
    }
    *(void**)(p + 0x290) = fn_8013CC50(*(u32*)(p + 0x4), (f32*)(p + 0xc), 0x183, 0, 0, 0, 0, 1, lbl_8053D670);
    *(void**)(p + 0x294) = fn_8013CC50(*(u32*)(p + 0x4), (f32*)(p + 0xc), 0x184, 0, 0, 0, 0, 1, lbl_8053D670);
    s32 st = *(s32*)(p + 0x230);
    if (st == 0 || st == 5) {
        if (*(u8*)(lbl_8053AAF8 + 0x7f) == 1) {
            u8* e = lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xc8;
            if (!(e[0x87] & 1)) {
                e[0x87] |= 1;
                u8* g = lbl_80529DEC;
                fn_8043D67C(lbl_8053AED0, 0x339, 0, g[0x24f]);
            }
        }
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
