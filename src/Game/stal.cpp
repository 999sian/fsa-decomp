// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 80175684-801769D8 (STAL). Remaining functions are not yet decompiled.
#include "types.h"

// from src/Game/fn_80175684_dtor.cpp
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A0CD8[];

extern "C" void* fn_80175684(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A0CD8;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_801F02BC(void* actor, const char* file, s32 idx, f32 sx, f32 sy, s32 a, s32 b, s32 c, s32 d);

struct StalVec { f32 x, y, z; };
// STAL draw (vtable slot 6); shakes horizontally while reassembling.
extern "C" void fn_801756E4(char* this_) {
    s32 flag = 0;
    StalVec* pos = (StalVec*)(this_ + 0xc);
    StalVec save;
    save.x = pos->x;
    save.y = pos->y;
    save.z = pos->z;
    s32 t = *(s32*)(this_ + 0x248);
    if (t > 30 && t < 130) {
        if (!(t & 2)) {
            *(f32*)(this_ + 0xc) += 2.0f;
        } else {
            *(f32*)(this_ + 0xc) -= 2.0f;
        }
    }
    if (*(s32*)(this_ + 0x264) != 0) {
        flag = 1;
    }
    fn_801F02BC(this_, "enemy_both2_sob.bin", *(s32*)(this_ + 0x258) + 0x158, 1.0f, 1.0f, 0, 7, flag, 0);
    pos->x = save.x;
    pos->y = save.y;
    pos->z = save.z;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
