#include "types.h"
#include "Game/SinitPoolChain.h"

extern "C" char __vt__4DGTL[];
extern "C" void fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, s32 p);
extern "C" void __dl__FPv(void* p);
extern s32 lbl_80539F58;
extern s32 lbl_80539F5C;
extern "C" void* fn_8013C824(void);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* mgr, void* emitter);
extern "C" void* fn_8013CC50(s32 room, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
extern "C" void fn_801F0E34(void* this_, s32 id, s32 flag);
extern "C" u16 lbl_8049F630[][2];
extern "C" const f32 lbl_8053D0B4;
extern "C" const f32 lbl_8053D110;
extern "C" const f32 lbl_8053D114;
extern "C" u8* lbl_8053AAF8;
extern "C" void* fn_80149A10(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = __vt__4DGTL;
        char* p = this_;
        int i = 0;
        do {
            fn_801EE434(*(void**)(p + 0x798));
            i++;
            p += 4;
        } while (i < 10);
        i = 0;
        p = this_;
        do {
            fn_801EE434(*(void**)(p + 0x7c0));
            i++;
            p += 4;
        } while (i < 2);
        if (*(s32*)(this_ + 0x90) == 1) {
            lbl_80539F58 = -1;
        }
        if (*(s32*)(this_ + 0x90) == 0) {
            lbl_80539F5C = -1;
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" s32 fn_80149FDC(char* this_) {
    if (*(s32*)(this_ + 0x250) == 0) {
        return 1;
    }
    if (*(s32*)(this_ + 0x24c) == 0) {
        *(s32*)(this_ + 0x24c) = 300 - *(s32*)(this_ + 0x250);
        *(s32*)(this_ + 0x24c) = (s32)((f32)*(s32*)(this_ + 0x24c) * lbl_8053D110);
        if (*(s32*)(this_ + 0x24c) < 8) {
            *(s32*)(this_ + 0x24c) = 8;
        }
        *(s32*)(this_ + 0x278) += 1;
        *(s32*)(this_ + 0x278) &= 3;
        if (*(s32*)(this_ + 0x230) != 1 && *(s32*)(this_ + 0x230) != 2) {
            switch (*(s32*)(this_ + 0x278)) {
            case 0:
                fn_801F0E34(this_, 0x400bb, 0);
                break;
            case 1:
                fn_801F0E34(this_, 0x400bc, 0);
                break;
            case 2:
                fn_801F0E34(this_, 0x400bd, 0);
                break;
            case 3:
                fn_801F0E34(this_, 0x400be, 0);
                break;
            }
        }
    }
    if (*(s32*)(this_ + 0x250) == 1) {
        *(s32*)(this_ + 0x278) = *(s32*)(this_ + 0x27c);
        s32 count = 0;
        while (*(s32*)(this_ + 0x27c) == *(s32*)(this_ + 0x278) && count < 100) {
            count++;
            u8* g = lbl_8053AAF8;
            *(u32*)(g + 0xb4) = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
            u32 bits = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
            f32 r = *(f32*)&bits;
            *(s32*)(this_ + 0x278) = (s32)(lbl_8053D114 * (r - lbl_8053D0B4));
            *(s32*)(this_ + 0x278) &= 3;
        }
        *(s32*)(this_ + 0x27c) = *(s32*)(this_ + 0x278);
        char* p = this_;
        s32 i = 0;
        do {
            if (*(void**)(p + 0x7c0) != 0) {
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)fn_8013C824() + 0xc), *(void**)(p + 0x7c0));
            }
            *(void**)(p + 0x7c0) = 0;
            i++;
            p += 4;
        } while (i < 2);
        s32 idx = *(s32*)(this_ + 0x278);
        *(void**)(this_ + 0x7c0) = fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, lbl_8049F630[idx][0], 0, 0, 0, 0, 1, lbl_8053D0B4);
        *(void**)(this_ + 0x7c4) = fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, lbl_8049F630[idx][1], 0, 0, 0, 0, 1, lbl_8053D0B4);
        if (*(s32*)(this_ + 0x230) != 1 && *(s32*)(this_ + 0x230) != 2) {
            fn_801F0E34(this_, 0x400bf, 0);
        }
        *(s32*)(this_ + 0x254) = 0xe10;
        return 0;
    }
    return 0;
}

