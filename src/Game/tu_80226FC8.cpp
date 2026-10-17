#include "types.h"


extern "C" void fn_801EE434(void* p);
extern "C" void __dt__5ActorFv(void* p, int how);
extern void operator delete(void* p);
extern void* lbl_804A6DC8[];
typedef struct FsaVec3 {
    f32 x;
    f32 y;
    f32 z;
} FsaVec3;
extern void* lbl_8053AAF8;
extern void* lbl_8053AB10;
extern f32 lbl_8046AC58[];
extern void* lbl_8046ACB8[];
extern f32 lbl_8053FF74;
extern f32 lbl_8053FF84;
extern f32 lbl_8053FF88;
s32 fn_801CD664(s32 arg);
void fn_802F6CF4(void* obj, f32* pos, void* res, u8* blk);
extern "C" void fn_80227CE8(void* this_) {
    u8 blk[0x3c];
    f32 save[3];
    f32 d[3];
    u8 i;

    if ((*(s32*)((u8*)this_ + 0x90) & 0x7f) == 0x20 && *((u8*)this_ + 0x255) == 0) {
        *(s32*)(blk + 0x10) = -1;
        *(s32*)(blk + 0x14) = -1;
        for (i = 0; i < 0x10; i += 8) {
            blk[(u8)(i)] = i;
            blk[(u8)(i + 1)] = i + 1;
            blk[(u8)(i + 2)] = i + 2;
            blk[(u8)(i + 3)] = i + 3;
            blk[(u8)(i + 4)] = i + 4;
            blk[(u8)(i + 5)] = i + 5;
            blk[(u8)(i + 6)] = i + 6;
            blk[(u8)(i + 7)] = i + 7;
        }
        *(s32*)(blk + 0x10) = -1;
        *(s32*)(blk + 0x14) = 0;
        *(s32*)(blk + 0x18) = 0;
        blk[0x1c] = 0;
        blk[0x1d] = 0;
        blk[0x1e] = 0;
        blk[0x1f] = 1;
        blk[0x20] = 1;
        blk[0x21] = 0;
        blk[0x22] = 0;
        blk[0x23] = 0;
        blk[0x24] = 0;
        blk[0x25] = 0;
        blk[0x26] = 1;
        *(s32*)(blk + 0x28) = 3;
        blk[0x2c] = 1;
        blk[0x2d] = 0;
        blk[0x2e] = 0;
        *(s32*)(blk + 0x30) = -1;
        *(s32*)(blk + 0x34) = 0;
        *(s32*)(blk + 0x38) = 2;

        save[0] = *(f32*)((u8*)this_ + 0xc);
        save[1] = *(f32*)((u8*)this_ + 0x10);
        save[2] = *(f32*)((u8*)this_ + 0x14);
        d[0] = lbl_8053FF84;
        d[1] = lbl_8053FF84;
        d[2] = lbl_8053FF74;
        *(f32*)((u8*)this_ + 0xc) += d[0];
        *(f32*)((u8*)this_ + 0x10) += d[1];
        *(f32*)((u8*)this_ + 0x14) += d[2];

        if (*((u8*)this_ + 0x256) == 1 && *(s32*)((u8*)this_ + 0x278) >= 0) {
            *(f32*)((u8*)this_ + 0xc) += lbl_8046AC58[*(s32*)((u8*)this_ + 0x278)];
            *(s32*)((u8*)this_ + 0x278) += 1;
            if (*(s32*)((u8*)this_ + 0x278) >= 0x18) {
                *(s32*)((u8*)this_ + 0x278) = fn_801CD664(10) - 0x69;
            }
        }

        blk[0x24] = 1;
        blk[0x1d] = -2;
        blk[0x13] = 0xa0;
        blk[0x2c] = 0;

        if (*(s32*)((u8*)this_ + 0x4) < 8) {
            void* mgr = *(void**)((u8*)lbl_8053AAF8 + 0xa4);
            void* res = ((void* (*)(void*, u32, void*))(*(void***)mgr)[6])(mgr, 0x534d5020, lbl_8046ACB8);
            fn_802F6CF4(((void**)lbl_8053AB10)[8], (f32*)((u8*)this_ + 0xc), res, blk);
        }

        *(f32*)((u8*)this_ + 0xc) = save[0];
        *(f32*)((u8*)this_ + 0x10) = save[1];
        *(f32*)((u8*)this_ + 0x14) = save[2];
    } else {
        *(f32*)((u8*)this_ + 0x10) = *(f32*)((u8*)this_ + 0x10) + lbl_8053FF88;
        *(f32*)((u8*)this_ + 0x10) = *(f32*)((u8*)this_ + 0x10) - lbl_8053FF88;
    }
}

extern "C" void* fn_80228AEC(void* this_, s16 freeFlag) {
    if (this_) {
        *(void**)this_ = lbl_804A6DC8;
        fn_801EE434(*(void**)((u8*)this_ + 0x24c));
        fn_801EE434(*(void**)((u8*)this_ + 0x250));
        __dt__5ActorFv(this_, 0);
        s32 f = freeFlag;
        if (f > 0) {
            operator delete(this_);
        }
    }
    return this_;
}
