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
extern void* lbl_8029839C[];
extern "C" void fn_8015D29C(void*, int);
extern char lbl_80298304[];
extern "C" void* fn_80166528(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_80298304;
        fn_8015D29C(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void* fn_80166B1C(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void* fn_80167074(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029839C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80298390;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* lbl_8029836C[];
extern "C" void* fn_80167398(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029836C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029839C;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_80298390;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

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

extern "C" void* fn_801679DC(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_80168280(void);
extern "C" void fn_80167CB8(void) {
    fn_80168280();
}

extern void* lbl_80298520[];
extern "C" void* fn_80168D68(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80298520;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80298600[];
extern "C" void* fn_8016ABEC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80298600;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80298B14[];
extern "C" void* fn_8016AC34(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80298B14;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802985C8[];
extern "C" void* fn_8016ACA0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802985C8;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80298600;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_8016AD40(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void* fn_8016AD94(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" u32 fn_801725D8(void) { return 0x54563136; }

extern "C" u32 fn_801725E4(void) { return 0x10; }

extern "C" void fn_801725EC(u8* p, s32 i, u16 v) { ((u16*)(p + 4))[i] = v; }

extern "C" u16 fn_801725FC(u8* p, s32 i) { return ((u16*)(p + 4))[i]; }

extern "C" void fn_8017288C(u8* p, s32 i, u16 v) { ((u16*)(p + 4))[i] = v; }

extern "C" u16 fn_8017289C(u8* p, s32 i) { return ((u16*)(p + 4))[i]; }

extern "C" void fn_80172B2C(u8* p, s32 i, u16 v) { ((u16*)(p + 4))[i] = v; }

extern "C" u32 fn_80172DC8(void) {
    return 2;
}

extern "C" void fn_80172DD0(u8* p, s32 i, u16 v) { ((u16*)(p + 4))[i] = v; }

extern "C" u16 fn_80172DE0(u8* p, s32 i) { return ((u16*)(p + 4))[i]; }

extern "C" void fn_80173074(u8* p, s32 i, u16 v) { ((u16*)(p + 4))[i] = v; }

extern "C" void fn_80174858(Unk80174858Pair* out, void* ptr, u32 index, u32 subindex) {
    Unk80174858Pair fallback;
    fallback.x = lbl_80301AC0.x;
    fallback.y = lbl_80301AC0.y;
    u8* data = *(u8**)((u8*)ptr + 0xc);
    if (data != nullptr && data[index * 0x128] == 1) {
        Unk80174858Pair* entry = (Unk80174858Pair*)(data + index * 0x128 + subindex * 2 + 0x60);
        out->x = entry->x;
        out->y = entry->y;
    } else {
        *(u16*)out = *(u16*)&fallback;
    }
}

extern "C" void fn_801748C0(u16* out, void* ptr, u32 index) {
    u8* data = *(u8**)((u8*)ptr + 4);
    u16* indices = *(u16**)((u8*)ptr + 8);
    u16 value = *(u16*)(data + indices[index] * 0xe8 + 0xe2);
    if (value != 0xffff) {
        u8* entry = *(u8**)((u8*)ptr + 0x50) + (u16)value * 8;
        out[0] = ((u8)entry[0] << 5 | (u8)entry[2] << 3) | entry[3];
        ((u8*)out)[2] = entry[1];
        ((u8*)out)[3] = entry[4];
    } else {
        out[0] = lbl_80301ADE;
        ((u8*)out)[2] = 0;
        ((u8*)out)[3] = 0;
    }
}

extern "C" void* fn_80174A50(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174A68(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174A80(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174A98(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174AB0(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174AC8(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174AE0(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174AF8(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174B10(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174B28(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174B40(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174B58(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174B70(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174B88(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174BA0(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174BB8(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174BD0(void* ptr, u32 arg, u32* a, u32* b, u32* c, u32* d) {
    u32 aa, bb, cc, dd;
    u32 va, vb, vc, vd;
    vd = *d; vc = *c; vb = *b;
    *(void**)ptr = lbl_80298C5C;
    va = *a;
    u32* words = (u32*)ptr;
    words[2] = -1;
    words[3] = -1;
    words[14] = -1;
    words[15] = -1;
    words[16] = -1;
    words[17] = -1;
    dd = vd; cc = vc; bb = vb; aa = va;
    fn_80174CAC(ptr, arg, &aa, &bb, &cc, &dd, 0);
    return ptr;
}

extern "C" void* fn_80174C64(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80298C5C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" u32 fn_80178E08(void) { return 0x10; }

