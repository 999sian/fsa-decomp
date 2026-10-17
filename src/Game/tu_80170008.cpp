#include "types.h"
#include "Game/SinitPoolChain.h"

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

extern "C" void* fn_80171A28(char* self, s16 flag) {
    if (self != 0) {
        *(char**)self = __vt__4SLR3;
        if (*(u16*)(self + 0x94) != 5) {
            s32 st = *(s32*)(lbl_8053AAF8 + 0x4c);
            if (st != 9 && st != 0xb && *(s32*)(self + 0x108) != 0) {
                fn_80138B7C();
            }
            s32 id = *(s32*)(self + 0x26c);
            if (id != 0) {
                char* p = (char*)fn_801F666C(fn_801F856C(), id);
                if (p != 0) {
                    p[0x11c] = 0;
                }
            }
        }
        fn_801EE434(*(void**)(self + 0x28c));
        __dt__5ActorFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

