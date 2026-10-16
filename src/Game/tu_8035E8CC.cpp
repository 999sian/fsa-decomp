#include "types.h"


extern "C" void fn_801F0E34(void* this_, u32 a, u32 b);
extern "C" void* fn_801F856C();
extern "C" void* fn_801F666C(void* base, s32 id);
extern "C" void fn_8035EAA4(void* this_) {
    char* p = (char*)this_;
    if (*(s32*)(p + 0x234) == 0) {
        fn_801F0E34(this_, 0x30085, 0);
        void* base = fn_801F856C();
        void* found = fn_801F666C(base, *(s32*)(p + 0x23c));
        if (found != 0) {
            *(s32*)((char*)found + 0x238) = 1;
        }
        *(s32*)(p + 0x234) = 0x78;
        *(s32*)(p + 0x230) = *(s32*)(p + 0x230) + 1;
    }
}
