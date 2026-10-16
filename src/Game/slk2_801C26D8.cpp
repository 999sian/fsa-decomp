// Game TU 801C26D8-801C5B08 (SLK2). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
#include "Game/Actor.h"
extern void* lbl_804A46F4[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);

extern "C" void* fn_801C0D70();
extern "C" void fn_801C1374(void* subRecord, s32 flag);
extern "C" void fn_801F4F28(void* this_);
extern "C" void fn_801C3B7C(void* this_, s32 state);
extern "C" u8 fn_801C11F0(void* rec);
extern "C" void fn_801C12B8(void* rec);

extern "C" void fn_801C26D8(void* this_) { fn_801C3B7C(this_, 0xd); }

extern "C" void fn_801C26FC(void* this_) {
    if (*(s32*)((char*)this_ + 0x248) != 0xe) {
        fn_801C3B7C(this_, 0xe);
    }
}

extern "C" void fn_801C272C(void* this_) {
    *(u8*)((char*)this_ + 0x11d) = 1;
    if (fn_801C11F0(fn_801C0D70())) {
        fn_801C3B7C(this_, 6);
    } else if (*(u16*)fn_801C0D70() & 1) {
        fn_801C3B7C(this_, 7);
    } else {
        fn_801C3B7C(this_, 9);
    }
}

extern "C" void fn_801C27A8(void* this_) {
    if (*(u32*)((char*)this_ + 0x230) & 0x4000) {
        switch (*(s32*)((char*)this_ + 0x248)) {
        case 0:
        case 1:
            fn_801C3B7C(this_, 2);
            break;
        }
    }
}

extern "C" void fn_801C27F0(void* this_) {
    s32 flag = (*(u32*)((char*)this_ + 0x230) >> 27) & 1;
    void* subRecord = fn_801C0D70();
    fn_801C1374(subRecord, flag);
    ((Actor*)this_)->Actor::v07();
}

extern const f32 lbl_8053EFB8;
extern const f32 lbl_8053EFBC;
extern "C" void fn_801C2D40(u8* this_) {
    if (*(s32*)(this_ + 0xd8) > 0 && *(s32*)(this_ + 0xf8) == 2) {
        return;
    }
    f32 min = -lbl_8053EFBC;
    *(f32*)(this_ + 0x44) += lbl_8053EFB8;
    if (*(f32*)(this_ + 0x44) < min) {
        *(f32*)(this_ + 0x44) = min;
    }
}

extern "C" void fn_800FE8C0(u8*);
extern "C" void fn_80216A8C(u8*);
extern "C" void fn_801C2E70(u8* this_) {
    *(u8*)(this_ + 0x34c) = *(s32*)(this_ + 0x98);
    if (*(s32*)(this_ + 0x248) != 0x13 || *(s32*)(this_ + 0x24c) <= 1) {
        if (!(*(u32*)(this_ + 0x230) & 0x80000)) {
            fn_800FE8C0(this_ + 0x340);
        }
    }
    fn_80216A8C(this_ + 0x528);
}

extern "C" int fn_801C5340(void) { return 0; }

extern "C" bool fn_801C53C4(void* thisObj) {
	return ((*(u32*)((char*)thisObj + 0x230) & 0x40000) != 0 && *(u8*)((char*)thisObj + 0x55c) <= 20) ? true : false;
}

extern "C" void fn_801C53F8(void* this_) {
    u8 off = (*(u32*)((char*)fn_801C0D70() + 0x50) >> 31) ^ 1;
    if (!off && (*(u32*)((char*)this_ + 0x230) & 0x2000)) {
        fn_801C12B8(fn_801C0D70());
    }
}

extern "C" u32 fn_801C5660(u32 a, u32 b, u32 c, u32 d, u32 e) {
    return ((e & 0xff) << 20) | ((d & 0xf) << 12) | ((c & 0xf) << 8) | ((b & 7) << 5) | (a & 0x1f);
}

extern "C" void* dtor_801C5854(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A46F4;
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

#include "JSystem/JAudio/JASFakeMatchFSA.h"
