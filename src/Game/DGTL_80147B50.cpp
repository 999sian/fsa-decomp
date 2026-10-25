#include "types.h"
#include "JSystem/JParticle/JPAEmitter.h"
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
extern "C" const f32 lbl_8053D0B0;
extern "C" const f32 lbl_8053D0F8;
extern "C" const f32 lbl_8053D108;
extern "C" const f32 lbl_8053D10C;
extern "C" s32 fn_801F285C(void* a, f32* b, u32* c, u32 e, s32 d);
extern "C" s32 fn_8022EA0C(s32 a);
extern "C" u8 fn_801F2FAC(void* a);
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* mgr, s32 idx);
extern "C" s32 Actor_CreateByID(void* mgr, u32 id, s32 room, void* pos, s32 a, s32 b, s32 c);
extern "C" void fn_80134DE4(u8* a, s32 b, s32 c);
extern "C" void* fn_80149A10(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = __vt__4DGTL;
        int i;
        char* p = this_;
        i = 0;
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

extern "C" s32 fn_80149AEC(char* p) {
    u8 hit;
    char* q;
    int count;
    s32 i;
    hit = 0;
    if (*(s32*)(p + 0x240) || *(s32*)(p + 0x24c) || *(s32*)(p + 0x250)) return 0;
    f32 x = *(f32*)(p + 0xc);
    f32 y = *(f32*)(p + 0x10);
    f32 z = *(f32*)(p + 0x14);
    *(f32*)(p + 0x60) = lbl_8053D108;
    *(f32*)(p + 0x64) = lbl_8053D108;
    *(f32*)(p + 0x68) = lbl_8053D0F8;
    *(f32*)(p + 0x6c) = lbl_8053D0F8;
    *(f32*)(p + 0xc) = *(f32*)(p + 0x314);
    *(f32*)(p + 0x10) = *(f32*)(p + 0x318);
    *(f32*)(p + 0x14) = *(f32*)(p + 0x31c);
    *(u32*)(p + 0xb0) = 0x08040000;
    for (i = 0; i < 4; ++i) {
        s32 player = fn_801F285C(p, 0, 0, 1, i);
        if (player >= 0 && (player == *(s32*)(p + 0x278) || fn_8022EA0C(player) == *(s32*)(p + 0x278)) && fn_801F2FAC(p) && *(s32*)(p + 0x108) != 10000) {
            *(s32*)(p + 0x270) = 0;
            *(f32*)(p + 0x14) = lbl_8053D0B0;
            *(f32*)(p + 0x44) = lbl_8053D0B0;
            hit = 1;
        }
    }
    *(f32*)(p + 0xc) = x;
    *(f32*)(p + 0x10) = y;
    *(f32*)(p + 0x14) = z;
    if (!hit) return 0;
    *(s32*)(p + 0x260) = 0;
    *(s32*)(p + 0x264) = 0;
    *(f32*)(p + 0x2a8) = lbl_8053D0B0;
    *(f32*)(p + 0x2a4) = lbl_8053D0B0;
    *(f32*)(p + 0x2a0) = lbl_8053D0B0;
    *(f32*)(p + 0x44) = lbl_8053D0B0;
    *(f32*)(p + 0x40) = lbl_8053D0B0;
    *(f32*)(p + 0x3c) = lbl_8053D0B0;
    q = p;
    for (count = 0; count < 2; ++count, q += 4) {
        if (*(void* volatile*)(q + 0x7c0)) {
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)fn_8013C824() + 0xc), *(void* volatile*)(q + 0x7c0));
            *(void* volatile*)(q + 0x7c0) = 0;
        }
    }
    --*(s32*)(p + 0x274);
    if (*(s32*)(p + 0x274) <= 0) {
        *(s32*)(p + 0xd8) = 0;
        *(s32*)(p + 0xdc) = 0;
        if (*(s32*)(p + 0x90) == 1) lbl_80539F58 = -1;
        if (*(s32*)(p + 0x90) == 0) lbl_80539F5C = -1;
        for (int i = 0; i < 9; ++i) ((s32*)(p + 0x234))[i] = 0;
        *(s32*)(p + 0x23c) = 0xa8;
        q = p;
        for (s32 j = 0; j < 10; ++j, q += 4) {
            char* emitter = *(char**)(q + 0x798);
            if (emitter) {
                *(u32*)(emitter + 0xf4) |= 1;
                *(s32*)(emitter + 0x24) = 1;
                *(char**)(q + 0x798) = 0;
            }
        }
        fn_80134DE4(lbl_8053AAF8, 0xa8, 0);
        *(s32*)(p + 0x230) = 6;
    } else {
        if (*(s32*)(p + 0x274) == 1) *(f32*)(p + 0x290) = lbl_8053D10C;
        *(s32*)(p + 0x25c) = 4;
        if (*(s32*)(p + 0x274) == 2) {
            if (*(u32*)(p + 0x90) == 1) {
                Actor_CreateByID(fn_801F856C(), 0x4447544c, *(s32*)(p + 4), p + 0xc, 0, -1, -1);
                s32 id = lbl_80539F58;
                if (id >= 0) {
                    char* other = (char*)fn_801F666C(fn_801F856C(), id);
                    if (other) {
                        lbl_80539F5C = Actor_CreateByID(fn_801F856C(), 0x4447544c, *(s32*)(other + 4), other + 0xc, 3, -1, -1);
                    }
                }
                fn_801F0E34(p, 0x40023, 0);
            } else {
                fn_801F0E34(p, 0x40005, 0);
            }
        } else {
            fn_801F0E34(p, 0x40005, 0);
        }
        q = p;
        for (int j = 0; j < 80; ++j, q += 12) {
            *(f32*)(q + 0x3d8) = *(f32*)(p + 0xc);
            *(f32*)(q + 0x3dc) = *(f32*)(p + 0x10);
            *(f32*)(q + 0x3e0) = *(f32*)(p + 0x14);
        }
    }
    return 1;
}

extern "C" s32 fn_80149FDC(char* this_) {
    s32 i;
    s32 idx;
    char* p;
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
    if (*(s32*)(this_ + 0x250) != 1) {
        return 0;
    }
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
    i = 0;
    p = this_;
    do {
        if (*(void* volatile*)(p + 0x7c0) != 0) {
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)fn_8013C824() + 0xc), *(void* volatile*)(p + 0x7c0));
            *(void**)(p + 0x7c0) = 0;
        }
        i++;
        p += 4;
    } while (i < 2);
    idx = *(s32*)(this_ + 0x278);
    *(void**)(this_ + 0x7c0) = fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, lbl_8049F630[idx][0], 0, 0, 0, 0, 1, lbl_8053D0B4);
    *(void**)(this_ + 0x7c4) = fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, lbl_8049F630[idx][1], 0, 0, 0, 0, 1, lbl_8053D0B4);
    if (*(s32*)(this_ + 0x230) != 1 && *(s32*)(this_ + 0x230) != 2) {
        fn_801F0E34(this_, 0x400bf, 0);
    }
    *(s32*)(this_ + 0x254) = 0xe10;
    return 0;
}

