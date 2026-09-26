// Game TU 801B7784-801B80C0 (ROPE). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
#include "Game/ItemBase.h"
extern "C" void fn_801F06F0(void* actor, void* res, u32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern "C" void fn_801D2264(void* obj, s32 a, u32 b);
extern "C" void fn_801CE4BC(void* this_);
extern "C" void fn_801D0ED0(void* this_);
extern "C" s32 fn_801CD664(s32 n);
extern "C" void fn_801D2608(void* obj, void* tbl, u32 n);
extern "C" void fn_801D22DC(void* obj, s32 a, u32 b, u32 c);
extern "C" void fn_801D1D60(void* obj);
extern u8 lbl_80469168[];
extern u8 lbl_804A3A58[];
extern const f32 lbl_8053EAF0;
extern const f32 lbl_8053EAF4;
extern const f32 lbl_8053EAF8;
extern const f32 lbl_8053EAFC;
extern const f32 lbl_8053EB00;
extern const f32 lbl_8053EB18;

extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_801D0F40(void* this_);
extern void* lbl_804A3A68[];
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_801B7784(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A3A68;
        if (this_ != 0) {
            *(void**)p = lbl_804A4808;
            if (p + 0x270 != 0) {
                if (p + 0x294 != 0) {
                    *(void**)(p + 0x294) = lbl_8049CC34;
                }
            }
            __dt__5ActorFv(this_, 0);
        }
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_801B7814(u8* this_) {
    fn_801F06F0(this_, lbl_80469168, *(s32*)(this_ + 0x280) + 0xb5, 0, 0, 1.0f, 1.0f);
}

extern "C" void fn_801B7854(u8* this_) {
    fn_801D2264(this_ + 0x270, *(s32*)(this_ + 0x98), 2);
    f32 t = *(f32*)(this_ + 0x254) - 0.4f;
    t *= 0.9090909f;
    if (t > 1.0f) {
        t = 1.0f;
    } else if (t < 0.0f) {
        t = 0.0f;
    }
    *(f32*)(this_ + 0x2a0) = t * 2.0f + 1.0f;
    fn_801CE4BC(this_);
}

extern "C" void fn_801B7D34(u8* this_) {
    fn_801D0ED0(this_);
    if (*(f32*)(this_ + 0x14) > 0.001f) {
        *(s32*)(this_ + 0x248) = 3;
        *(s32*)(this_ + 0x250) = -1;
    } else {
        *(s32*)(this_ + 0x248) = 0;
        *(s32*)(this_ + 0x250) = fn_801CD664(0x3d) + 0x28;
    }
    *(s32*)(this_ + 0x24c) = 0;
    *(f32*)(this_ + 0x254) = 0.0f;
    *(f32*)(this_ + 0x258) = 0.0f;
    fn_801D2608(this_ + 0x270, lbl_804A3A58, 4);
    fn_801D22DC(this_ + 0x270, *(s32*)(this_ + 0x98), 2, 0);
    fn_801D1D60(this_ + 0x270);
}

extern "C" void* fn_801B7DE0(void* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A3A68;
    return this_;
}

extern "C" void* dtor_801B7E1C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A4808;
        if (p + 0x270 != 0) {
            if (p + 0x294 != 0) {
                *(void**)(p + 0x294) = lbl_8049CC34;
            }
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
