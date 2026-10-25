#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry/Vec.h"
#include "dolphin/gx/GXStruct.h"
#include "JSystem/JParticle/JPAEmitter.h"

extern "C" char lbl_804A84C8[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void fn_801EE434(void*);
extern "C" const f32 lbl_805409A0;
extern "C" const f32 lbl_805409A4;
extern "C" const f32 lbl_80540990;
extern const f32 lbl_80540994;
extern const f32 lbl_80540998;
extern const f32 lbl_8054099C;
extern void* lbl_8053AB10;
extern "C" void fn_80158B5C(void* mgr, void* room, void* pos, GXColor col, f32 size);
extern "C" void fn_802B055C(char* p) {
    if (*(s32*)(p + 0x254) == 0) {
        if (*(f32*)(p + 0x258) > 0.0f) {
            *(f32*)(p + 0x258) -= 6.0f;
            if (*(f32*)(p + 0x258) <= 0.0f)
                *(f32*)(p + 0x258) = 0.0f;
        } else {
            *(f32*)(p + 0x258) = 0.0f;
        }
    } else {
        if (*(f32*)(p + 0x258) < 200.0f)
            *(f32*)(p + 0x258) += 6.0f;
        else
            *(f32*)(p + 0x258) = 200.0f;
    }
    f32 size = *(f32*)(p + 0x258);
    GXColor color;
    JGeometry::TVec3<f32> pos(8.0f + *(f32*)(p + 0xc), 8.0f + *(f32*)(p + 0x10), 0.0f);
    color.r = 0;
    color.g = 0;
    color.b = 0;
    color.a = 0x80;
    void* room = *(void**)(p + 4);
    fn_80158B5C(*(void**)((char*)lbl_8053AB10 + 0x2c), room, &pos, color, size);
}

extern "C" void* fn_802D6A9C();
extern "C" u8 fn_802D800C(void*, u32);
extern "C" void* fn_8013CC50(u32, void*, f32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_801F0E34(void*, u32, s32);
extern "C" u8 fn_801F2B20(void*, u32);
extern "C" const f32 lbl_805409A8;
extern "C" const f32 lbl_805409AC;
extern "C" void fn_802B0644(char* p) {
switch (*(s32*)(p+0x230)) {
case 0:
if ((u8)((Actor*)p)->v11() || fn_802D800C(fn_802D6A9C(), *(u32*)(p+0x248)) || fn_802D800C(fn_802D6A9C(), *(u32*)(p+0x24c)) || fn_802D800C(fn_802D6A9C(), *(u32*)(p+0x250))) {
*(s32*)(p+0x254)=1;
if (!*(void**)(p+568)) *(void**)(p+568)=fn_8013CC50(*(u32*)(p+4),p+0xc,lbl_805409A0,190,0,0,0,0,1);
if (!*(void**)(p+572)) *(void**)(p+572)=fn_8013CC50(*(u32*)(p+4),p+0xc,lbl_805409A0,191,0,0,0,0,1);
if (!*(void**)(p+576)) *(void**)(p+576)=fn_8013CC50(*(u32*)(p+4),p+0xc,lbl_805409A0,192,0,0,0,0,1);
if (!*(void**)(p+564)) *(void**)(p+564)=fn_8013CC50(*(u32*)(p+4),p+0xc,lbl_805409A0,189,0,0,0,0,1);
if (!*(void**)(p+580)) *(void**)(p+580)=fn_8013CC50(*(u32*)(p+4),p+0xc,lbl_805409A0,1354,0,0,0,0,1);
fn_801F0E34(p,0x30005,0); fn_801F0E34(p,0x30023,0); *(s32*)(p+0x230)=1;
} break;
case 1:
if (!((u8)((Actor*)p)->v11() || fn_802D800C(fn_802D6A9C(), *(u32*)(p+0x248)) || fn_802D800C(fn_802D6A9C(), *(u32*)(p+0x24c)) || fn_802D800C(fn_802D6A9C(), *(u32*)(p+0x250)))) {
*(s32*)(p+0x254)=0;
if (*(JPABaseEmitter**)(p+568)) { (*(JPABaseEmitter**)(p+568))->becomeInvalidEmitter(); *(JPABaseEmitter**)(p+568)=0; }
if (*(JPABaseEmitter**)(p+572)) { (*(JPABaseEmitter**)(p+572))->becomeInvalidEmitter(); *(JPABaseEmitter**)(p+572)=0; }
if (*(JPABaseEmitter**)(p+576)) { (*(JPABaseEmitter**)(p+576))->becomeInvalidEmitter(); *(JPABaseEmitter**)(p+576)=0; }
if (*(JPABaseEmitter**)(p+564)) { (*(JPABaseEmitter**)(p+564))->becomeInvalidEmitter(); *(JPABaseEmitter**)(p+564)=0; }
if (*(JPABaseEmitter**)(p+580)) { (*(JPABaseEmitter**)(p+580))->becomeInvalidEmitter(); *(JPABaseEmitter**)(p+580)=0; }
*(f32*)(p+0x60)=lbl_805409A0; *(f32*)(p+0x64)=lbl_805409A0; *(f32*)(p+0x68)=lbl_805409A4; *(f32*)(p+0x6c)=lbl_805409A4; *(s32*)(p+0x230)=0;
} else {
*(f32*)(p+0x60)=lbl_805409A8; *(f32*)(p+0x64)=lbl_805409A8; *(f32*)(p+0x68)=lbl_805409AC; *(f32*)(p+0x6c)=lbl_805409AC; fn_801F2B20(p,0);
} break;
}
}

extern "C" void* fn_802B0998(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A84C8;
        if (*(void**)(p + 0x234) != 0) {
            fn_801EE434(*(void**)(p + 0x234));
        }
        if (*(void**)(p + 0x238) != 0) {
            fn_801EE434(*(void**)(p + 0x238));
        }
        if (*(void**)(p + 0x23c) != 0) {
            fn_801EE434(*(void**)(p + 0x23c));
        }
        if (*(void**)(p + 0x240) != 0) {
            fn_801EE434(*(void**)(p + 0x240));
        }
        if (*(void**)(p + 0x244) != 0) {
            fn_801EE434(*(void**)(p + 0x244));
        }
        __dt__5ActorFv((Actor*)this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_802B0A4C(char* p) {
    *(u32*)(p + 0x248) = (*(u32*)(p + 0x90) >> 22) & 0x1f;
    *(u32*)(p + 0x24c) = (*(u32*)(p + 0x90) >> 17) & 0x1f;
    *(u32*)(p + 0x250) = (*(u32*)(p + 0x90) >> 12) & 0x1f;
    *(f32*)(p + 0x60) = lbl_805409A0;
    *(f32*)(p + 0x64) = lbl_805409A0;
    *(f32*)(p + 0x68) = lbl_805409A4;
    *(f32*)(p + 0x6c) = lbl_805409A4;
    *(u32*)(p + 0x234) = 0;
    *(u32*)(p + 0x238) = 0;
    *(u32*)(p + 0x23c) = 0;
    *(u32*)(p + 0x240) = 0;
    *(u32*)(p + 0x244) = 0;
    *(u32*)(p + 0x230) = 0;
    *(u32*)(p + 0x254) = 0;
    *(f32*)(p + 0x258) = lbl_80540990;
}

extern "C" void fn_802B0AB4(void) {
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
