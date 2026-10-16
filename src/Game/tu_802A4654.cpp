#include "types.h"
#include "JSystem/JParticle/JPAEmitter.h"


extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* p);
extern "C" void* fn_8013C824(void);
extern "C" char __vt__4GOAL[];
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* a, void* p);
extern "C" void fn_801F0E34(void* this_, u32 id, s32 c);
extern "C" void fn_8030C210(void*, void*);
extern "C" u8* lbl_8053AB10;
extern "C" const s32 lbl_8046C658[][4];
extern "C" const s32 lbl_8046C6C8[][4];
extern "C" void fn_802A4654(void* this_) {
    f32 x = *(f32*)((u8*)this_ + 0xc);
    f32 y = *(f32*)((u8*)this_ + 0x10);
    f32 z = *(f32*)((u8*)this_ + 0x14);
    s32 i;
    for (i = 0; i < 4; i++) {
        *(f32*)((u8*)this_ + 0xc) = x + (f32)lbl_8046C658[*(s32*)((u8*)this_ + 0x234)][i];
        *(f32*)((u8*)this_ + 0x10) = y + (f32)lbl_8046C6C8[*(s32*)((u8*)this_ + 0x234)][i];
        fn_801F0E34(this_, 0x30084, 0);
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), (u8*)this_ + 0xc);
    }
    *(f32*)((u8*)this_ + 0xc) = x;
    *(f32*)((u8*)this_ + 0x10) = y;
    *(f32*)((u8*)this_ + 0x14) = z;
}

extern "C" void* fn_802A64E8(void* this_, short how) {
    if (this_) {
        volatile u32* slot = (volatile u32*)this_;
        s32 i = 0;
        *(void**)this_ = __vt__4GOAL;
        do {
            if (slot[0xad] != 0) {
                (*(JPAEmitterManager**)((char*)fn_8013C824() + 0xc))->forceDeleteEmitter((JPABaseEmitter*)slot[0xad]);
            }
            if (slot[0xb1] != 0) {
                (*(JPAEmitterManager**)((char*)fn_8013C824() + 0xc))->forceDeleteEmitter((JPABaseEmitter*)slot[0xb1]);
            }
            if (slot[0xb5] != 0) {
                (*(JPAEmitterManager**)((char*)fn_8013C824() + 0xc))->forceDeleteEmitter((JPABaseEmitter*)slot[0xb5]);
            }
            if (slot[0xb9] != 0) {
                (*(JPAEmitterManager**)((char*)fn_8013C824() + 0xc))->forceDeleteEmitter((JPABaseEmitter*)slot[0xb9]);
            }
            if (slot[0xbd] != 0) {
                (*(JPAEmitterManager**)((char*)fn_8013C824() + 0xc))->forceDeleteEmitter((JPABaseEmitter*)slot[0xbd]);
            }
            i++;
            slot++;
        } while (i < 4);
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}
struct Unk802A4654 {
    u8 pad00[0xc];
    JGeometry::TVec3f mPos; // 0x0c
    u8 pad18[0x234 - 0x18];
    s32 m234;
};
