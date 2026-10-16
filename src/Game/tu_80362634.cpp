

#include "types.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" void* fn_8013C824(void);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* mgr, void* emitter);
extern "C" void* fn_804032E8(u32 type, const char* name);
extern "C" void fn_802F745C(void* mgr, void* pos, void* tex, void* prm);
extern "C" void* lbl_8053AB10;
extern "C" const char lbl_80474C10[];
extern "C" const s32 lbl_80474B88[];
extern "C" const s32 lbl_80474BA0[];

struct Unk80365AB8;
typedef void (Unk80365AB8::*Unk80365AB8Func)();
extern Unk80365AB8Func lbl_804ADDE8[];
extern Unk80365AB8Func lbl_804ADC38[];
extern "C" f32 lbl_80542BD4;

extern "C" void fn_80362634(char* self) {
    if (*(void**)(self + 0x300) != NULL) {
        void* mgr = *(void**)((char*)fn_8013C824() + 0xc);
        forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)(self + 0x300));
        *(void**)(self + 0x300) = NULL;
    }
}

extern "C" void fn_80362B14(char* self) {
    void* tex = fn_804032E8(0x54494d47, lbl_80474C10);
    if (*(s32*)(self + 4) < 8) {
        fn_802F745C(*(void**)((char*)lbl_8053AB10 + 0x20), self + 0xc, tex, NULL);
    }
}

extern "C" void fn_8036335C(void) {
}

extern "C" void fn_80363F7C(char* self) {
    if (*(s32*)(self + 0x25c) == 0) {
        *(s32*)(self + 0x268) = *(s32*)(self + 0x268) + 1;
        if (*(s32*)(self + 0x268) >= 6) {
            *(s32*)(self + 0x268) = 0;
        }
        *(s32*)(self + 0x25c) = lbl_80474B88[*(s32*)(self + 0x268)];
        *(s32*)(self + 0x264) = lbl_80474BA0[*(s32*)(self + 0x268)];
    }
    ((JGeometry::TVec3<f32>*)(self + 0xc))->add(*(JGeometry::TVec3<f32>*)(self + 0x3c));
}

extern "C" void fn_80365AB8(Unk80365AB8* self) {
    (self->*lbl_804ADDE8[*(s32*)((u8*)self + 0x234)])();
}

extern "C" void fn_80365AF0(Unk80365AB8* self) {
    if (*(s8*)((u8*)self + 0x230) == 0) {
        if (*(s32*)((u8*)self + 0x248) != 0) {
            *(s32*)((u8*)self + 0x248) -= 1;
        }
        if (*(s32*)((u8*)self + 0x25c) != 0) {
            *(s32*)((u8*)self + 0x25c) -= 1;
        }
        (self->*lbl_804ADC38[*(s32*)((u8*)self + 0x234)])();
    }
}

