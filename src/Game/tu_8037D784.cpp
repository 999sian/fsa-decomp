#include "types.h"


void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);
extern void* lbl_804AF018[];
extern f32 lbl_80543090;
extern const f32 lbl_80543094;
extern const char lbl_80475588[];
extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, s32 a, s32 b, f32 s0, f32 s1);
extern "C" void fn_803075AC(u32 callerID, u32 ownerID, void* posPtr, s32 effectRef, s32 flag,
                            s32 mode, s32 targetPlayerIdx, s32 kind, s32 stackArg9, s32 stackArg10);
extern "C" void* fn_8037D784(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AF018;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_8037D7E4(void* this_) {
    f32 val = lbl_80543090;
    *(f32*)((u8*)this_ + 0x44) = val;
    *(f32*)((u8*)this_ + 0x40) = val;
    *(f32*)((u8*)this_ + 0x3c) = val;
    *(u32*)((u8*)this_ + 0x230) = 2;
}

extern "C" void fn_8037DD38(u8* this_) {
    this_[0x11c] = 0;
}
#include "types.h"

void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);

extern void* lbl_804AF018[];
extern f32 lbl_80543090;
