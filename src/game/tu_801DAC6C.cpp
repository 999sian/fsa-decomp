// Game TU 801DAC6C-801DB18C (unnamed). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern "C" void* fn_801F856C();
extern "C" void* fn_801F666C(void* base, s32 id);
extern "C" void fn_801D8400(void* target);
extern "C" void fn_801F0E34(void* target, s32 soundId, s32 flag);

extern "C" void fn_801DAD88(void* record) {
    s32 id = *(s32*)record;
    if (id >= 0) {
        void* base = fn_801F856C();
        void* found = fn_801F666C(base, id);
        if (found != 0) {
            fn_801D8400(found);
        }
    }
}

extern "C" void fn_801DADD0(void* record) {
    s32 id = *(s32*)record;
    if (id >= 0) {
        void* base = fn_801F856C();
        void* found = fn_801F666C(base, id);
        if (found != 0) {
            fn_801F0E34(found, 0x40005, 0);
        }
    }
}
