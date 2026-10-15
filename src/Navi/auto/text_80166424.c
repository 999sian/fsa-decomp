// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80166424-0x80178e64 (536 functions). split_file divides it into the game's real files.
#include "types.h"

extern void* lbl_80298C5C[];
extern u16 lbl_80301ADE;
struct Unk80174858Pair { u8 x; u8 y; };
extern Unk80174858Pair lbl_80301AC0;
extern "C" void fn_80174CAC(void*, u32, u32*, u32*, u32*, u32*, u32);

extern void* lbl_80298390[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_80167404(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80298390;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802911A0[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_80167880(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802911A0;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_801748C0(u16* out, void* ptr, u32 index) {
    u8* data = *(u8**)((u8*)ptr + 4);
    u16* indices = *(u16**)((u8*)ptr + 8);
    u32 value = *(u16*)(data + indices[index] * 0xe8 + 0xe2);
    if (value != 0xffff) {
        u8* entry = *(u8**)((u8*)ptr + 0x50) + value * 8;
        out[0] = (entry[0] << 5 | entry[2] << 3) | entry[3];
        ((u8*)out)[2] = entry[1];
        ((u8*)out)[3] = entry[4];
    } else {
        out[0] = lbl_80301ADE;
        ((u8*)out)[2] = 0;
        ((u8*)out)[3] = 0;
    }
}

extern "C" u32 fn_80174A50(u32 base, u32 offset) {
    if (offset == 0) return 0;
    return base + offset;
}

extern "C" void* fn_80174BD0(void* ptr, u32 arg, u32* a, u32* b, u32* c, u32* d) {
    u32 dd = *d;
    u32 cc = *c;
    u32 bb = *b;
    *(void**)ptr = lbl_80298C5C;
    u32 aa = *a;
    u32* words = (u32*)ptr;
    words[2] = -1;
    words[3] = -1;
    words[14] = -1;
    words[15] = -1;
    words[16] = -1;
    words[17] = -1;
    fn_80174CAC(ptr, arg, &aa, &bb, &cc, &dd, 0);
    return ptr;
}

