#include "types.h"

extern "C" void* fn_801F856C();
extern "C" void* fn_801F666C(void* base, s32 id);
extern "C" void fn_80138B7C();
extern "C" void fn_801EE434(void*);
extern "C" void __dt__5ActorFv(void*, s32);
extern "C" void __dl__FPv(void*);
extern "C" char __vt__4SLR3[];
extern "C" char* lbl_8053AAF8;
extern "C" void fn_801719C0(void* this_) {
    char* p = (char*)this_;
    if (*(s32*)(p + 0x108) > 0) {
        return;
    }
    s32 id = *(s32*)(p + 0x26c);
    if (id != 0) {
        void* base = fn_801F856C();
        void* found = fn_801F666C(base, id);
        if (found != 0) {
            *(u8*)((char*)found + 0x11c) = 0;
            *(s32*)(p + 0x26c) = 0;
        }
    }
}
