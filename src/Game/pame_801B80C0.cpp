// Game TU 801B80C0-801B9730 (PAME). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);

extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_801D0F40(void* this_);
extern void* lbl_804A3B10[];

extern "C" void* fn_801B80C0(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A3B10;
        if (this_ != 0) {
            *(void**)p = lbl_804A4808;
            if (p + 0x270 != 0) {
                if (p + 0x294 != 0) {
                    *(void**)(p + 0x294) = lbl_8049CC34;
                }
            }
            __dt__5ActorFv(this_, 0);
        }
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void* fn_801B94C8(void* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A3B10;
    *(s32*)((char*)this_ + 0x2a8) = 0;
    return this_;
}

extern "C" void fn_801F0E34(void* this_, s32 id, s32 c);
extern "C" s32 fn_801F2DB4(void* actor, u32 a, u32 b, u32 c);
extern "C" s32 fn_801D22A0(void* obj, s32 a, s32 b);
extern "C" void fn_801CE4BC(void* this_);
extern "C" void fn_801B91A8(void* this_, s32 mode);
extern const f32 lbl_8053EB20;
extern const f32 lbl_8053EB24;
extern const f32 lbl_8053EB34;
extern const f32 lbl_8053EB50;
extern s32 lbl_8053A100;

static inline u8 pameIsActive(s32 st) {
    u8 r = 0;
    switch (st) {
    case 1:
    case 2:
    case 3:
    case 5:
        r = 1;
        break;
    }
    return r;
}

extern "C" s32 fn_801B87DC(u8* this_) {
    u8 use = 1;
    s32 result = 0;
    s32 st = *(s32*)(this_ + 0x248);
    if (pameIsActive(st)) {
        use = 0;
        if (*(s32*)(this_ + 0x24c) < 10) {
            switch (st) {
            case 1:
            case 5:
                use = 1;
                break;
            }
        }
    }
    if (use) {
        fn_801F2DB4(this_, *(u32*)(this_ + 0x1a0), 'NULL', 0);
    } else {
        result = fn_801F2DB4(this_, 'NULL', 'NULL', 0);
    }
    return result;
}

extern "C" void fn_801B88A4(u8* this_) {
    if (__fabsf(*(f32*)(this_ + 0x44)) >= lbl_8053EB34) {
        if (*(u32*)(this_ + 0x230) & 0x2000) {
            fn_801F0E34(this_, 0x50014, 0);
        } else {
            fn_801F0E34(this_, 0x50015, 0);
        }
    }
}

extern "C" void fn_801B8908(u8* this_) {
    if (this_[0xd4] == 1) {
        u8 ok = 0;
        if (*(u32*)(this_ + 0x230) & 0x4000) {
            if (*(s32*)(this_ + 0x2a8) == lbl_8053A100) {
                ok = 1;
            }
        } else {
            ok = 1;
        }
        if (ok && *(f32*)(this_ + 0x14) <= lbl_8053EB20) {
            switch (*(s32*)(this_ + 0x248)) {
            case 0:
                fn_801B91A8(this_, 1);
                break;
            case 2:
            case 3:
            case 5:
                fn_801B91A8(this_, 4);
                break;
            }
        }
        this_[0xd4] = 0;
    }
}

extern "C" void fn_801B8C08(u8* this_) {
    s32 on = 0;
    if (pameIsActive(*(s32*)(this_ + 0x248))) {
        on = 1;
    }
    fn_801D22A0(this_ + 0x270, on, 2);
    f32 v = lbl_8053EB24;
    if (*(s32*)(this_ + 0x248) == 3) {
        v = lbl_8053EB50;
    }
    *(f32*)(this_ + 0x2a0) = v;
    fn_801CE4BC(this_);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
