// Game TU 801B4D0C-801B6634 (TLWP). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern "C" void* fn_8013C824(void);
extern "C" void fn_800EC240(void* a, void* b);
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A38D4[];

extern "C" void* fn_801B609C(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804A38D4;
        char* p = (char*)this_;
        int i = 0;
        do {
            if (*(void**)(p + 0x294)) {
                void* base = fn_8013C824();
                void* a = *(void**)((char*)base + 0xc);
                fn_800EC240(a, *(void**)(p + 0x294));
                *(void**)(p + 0x294) = 0;
            }
            i++;
            p += 4;
        } while (i < 3);
        p = (char*)this_;
        int j = 0;
        do {
            if (*(void**)(p + 0x2a0)) {
                void* base = fn_8013C824();
                void* a = *(void**)((char*)base + 0xc);
                fn_800EC240(a, *(void**)(p + 0x2a0));
                *(void**)(p + 0x2a0) = 0;
            }
            j++;
            p += 4;
        } while (j < 0x14);
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

struct TlwpDrawKey {
    s32 a, b;
    TlwpDrawKey() { a = -1; b = -1; }
};
struct TlwpDrawParam {
    u8 map[16];      // 0x00
    TlwpDrawKey key; // 0x10
    void* c;         // 0x18
    u8 palette;      // 0x1c
    u8 color;        // 0x1d
    u8 f1e, f1f, f20, f21, f22, f23, f24, f25, f26;
    s32 blend;       // 0x28
    u8 f2c, f2d, f2e;
    s32 g;           // 0x30
    s32 h;           // 0x34
    s32 i;           // 0x38

    TlwpDrawParam() {
        for (u8 n = 0; n < 16; n++) {
            map[n] = n;
        }
        key.a = -1;
        key.b = 0;
        c = 0;
        palette = 0;
        color = 0;
        f1e = 0;
        f1f = 1;
        f20 = 1;
        f21 = 0;
        f22 = 0;
        f23 = 0;
        f24 = 0;
        f25 = 0;
        f26 = 1;
        blend = 3;
        f2c = 1;
        f2d = 0;
        f2e = 0;
        g = -1;
        h = 0;
        i = 2;
    }
};
struct TlwpSave { u8 pad[0x10]; s32 cur; u8 pad2[0x7a - 0x14]; u8 mask; };
extern TlwpSave lbl_8050EC80;
extern const char lbl_804690F8[];
extern const f32 lbl_8053EA10;
extern "C" void fn_801F02BC(void* this_, const char* name, s32 id, TlwpDrawParam* param, s32 a, s32 b, s32 c, f32 s0, f32 s1);
extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, TlwpDrawParam* param, s32 a, f32 s0, f32 s1);
extern "C" void fn_801B4EC8(void* this_);
extern "C" void fn_801B56A0(void* this_);
extern "C" void fn_801B5228(void* this_);

extern "C" void fn_801B4D0C(char* p) {
    switch (*(s32*)(p + 0x250)) {
    case 0: {
        u8 m = 1 << *(s32*)(p + 0x254);
        if (((TlwpSave*)((u8*)&lbl_8050EC80 + lbl_8050EC80.cur * 0xc8))->mask & m) {
            TlwpDrawParam param;
            *(s8*)&param.color = -1;
            fn_801F06F0(p, lbl_804690F8, 0x431, &param, -1, lbl_8053EA10, lbl_8053EA10);
            fn_801F02BC(p, lbl_804690F8, 0x431, &param, -1, 0, 0, lbl_8053EA10, lbl_8053EA10);
        }
        break;
    }
    case 1:
    case 2:
    case 3:
        fn_801B4EC8(p);
        break;
    }
}

extern "C" void fn_801B5198(char* p) {
    switch (*(s32*)(p + 0x250)) {
    case 0:
        fn_801B56A0(p);
        break;
    case 1:
    case 2:
    case 3:
        fn_801B5228(p);
        break;
    }
    for (s32 i = 0; i < 3; i++) {
        if (*(s32*)(p + i * 4 + 0x234) > 0) {
            (*(s32*)(p + i * 4 + 0x234))--;
        }
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
