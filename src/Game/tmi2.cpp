// TU 0x80376850-0x80376b4c (actor TMI2).
#include "types.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);

extern void* lbl_804AE728[];

extern "C" void* fn_80376850(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AE728;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" u16 fn_80226850(void* pos, u32 id);
extern "C" void* fn_801F856C(void);
extern "C" void Actor_CreateByID(void* mgr, u32 type, u32 id, void* pos, u32 flags, s32 a, s32 b);

extern "C" void fn_803768B0(void* thisPtr) {
    char* p = (char*)thisPtr;
    if (fn_80226850(p + 0xc, *(u32*)(p + 0x4)) == 0x12) {
        Actor_CreateByID(fn_801F856C(), 'BCK2', *(u32*)(p + 0x4), p + 0xc, 0x100, -1, -1);
        *(u8*)(p + 0x11c) = 0;
    }
}

extern "C" void fn_8037691C(void* thisPtr) {
    *(u8*)((char*)thisPtr + 0x11c) = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
