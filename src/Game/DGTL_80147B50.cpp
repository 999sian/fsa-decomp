#include "types.h"
#include "JSystem/JParticle/JPAEmitter.h"
#include "Game/SinitPoolChain.h"

struct TWEVParam {
    u8 buf[16];
    s32 a;
    s32 b;
    void* c;
    s8 d[11];
    s32 e;
    u8 f[3];
    s32 g;
    s32 h;
    s32 i;
};

typedef f32 TWEVMtx[3][4];

static inline void fn_80147B50_rotMtx(TWEVMtx m, f32 ax, f32 ay, f32 az, f32 s) {
    f32 sa = sin(ax);
    f32 sb = sin(ay);
    f32 sc = sin(az);
    f32 ca = cos(ax);
    f32 cb = cos(ay);
    f32 cc = cos(az);
    m[0][0] = s * (cb * cc);
    m[0][1] = s * (sa * sb * cc - ca * sc);
    m[0][2] = s * (ca * cc * sb + sa * sc);
    m[1][0] = s * (cb * sc);
    m[1][1] = s * (sa * sb * sc + ca * cc);
    m[1][2] = s * (ca * sc * sb - sa * cc);
    m[2][0] = s * -sb;
    m[2][1] = s * (sa * cb);
    m[2][2] = s * (ca * cb);
}

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

extern "C" void fn_802D7440(void* p, s32 x);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_80458F9C(void* p, s32 x);
extern "C" u8 sincosTable___5JMath[];
extern "C" const f32 lbl_8053D0D0;
extern "C" const f32 lbl_8053D0D4;
extern "C" const f32 lbl_8053D0E4;
extern "C" const f32 lbl_8053D11C;
extern "C" const f32 lbl_8053D120;
extern "C" const f32 lbl_8053D124;
extern "C" void* lbl_8053AF80;
extern s32 lbl_8053AB30;
extern s32 lbl_8053AB34;
extern s32 lbl_8053AB38;
extern "C" void fn_8014A5F4(char* this_) {
    char* p = this_;
    u8* g;
    u32 bits;
    u16 angle;
    f32 r;

    *(f32*)(p + 0x80) = lbl_8053D108;
    *(f32*)(p + 0x84) = lbl_8053D108;
    *(f32*)(p + 0x88) = lbl_8053D0F8;
    *(f32*)(p + 0x8c) = lbl_8053D0F8;
    *(s32*)(p + 0x258) = 0;
    *(s32*)(p + 0x25c) = 0;
    *(s32*)(p + 0x260) = 0;
    *(s32*)(p + 0x264) = 0;
    *(s32*)(p + 0x268) = 0;
    *(s32*)(p + 0x26c) = 0;
    *(s32*)(p + 0x270) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x23c) = 0;
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = 0;
    *(s32*)(p + 0x254) = 0;
    *(s32*)(p + 0x274) = 6;
    *(s32*)(p + 0x278) = 0;
    *(s32*)(p + 0x280) = *(s32*)(p + 0x278);
    *(s32*)(p + 0x250) = 300;
    *(s32*)(p + 0x27c) = *(s32*)(p + 0x278);
    *(s32*)(p + 0x798) = 0;
    *(s32*)(p + 0x79c) = 0;
    *(s32*)(p + 0x7a0) = 0;
    *(s32*)(p + 0x7a4) = 0;
    *(s32*)(p + 0x7a8) = 0;
    *(s32*)(p + 0x7ac) = 0;
    *(s32*)(p + 0x7b0) = 0;
    *(s32*)(p + 0x7b4) = 0;
    *(s32*)(p + 0x7b8) = 0;
    *(s32*)(p + 0x7bc) = 0;
    *(s32*)(p + 0x7c0) = 0;
    *(s32*)(p + 0x7c4) = 0;

    g = lbl_8053AAF8;
    *(u32*)(g + 0xb4) = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
    bits = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
    r = *(f32*)&bits;
    *(s32*)(p + 0x98) = (s32)((r - lbl_8053D0B4) * lbl_8053D11C);
    *(s32*)(p + 0x298) = *(s32*)(p + 0x98);
    *(s32*)(p + 0x29c) = -1;
    *(f32*)(p + 0x294) = lbl_8053D0E4;
    *(u8*)(p + 0x196) = 1;

    switch (*(u32*)(p + 0x98)) {
    case 0:
        angle = 0;
        break;
    case 1:
        angle = 0x2000;
        break;
    case 2:
        angle = 0x4000;
        break;
    case 3:
        angle = 0x6000;
        break;
    case 4:
        angle = 0x8000;
        break;
    case 5:
        angle = 0xa000;
        break;
    case 6:
        angle = 0xc000;
        break;
    case 7:
        angle = 0xe000;
        break;
    }
    *(u16*)(p + 0x284) = angle;
    *(u16*)(p + 0x286) = *(u16*)(p + 0x284);

    {
        char* fp = p;
        char* sp = p;
        for (s32 i = 0; i < 2; i++) {
            *(f32*)(fp + 0x2c0) = *(f32*)(p + 0xc);
            *(f32*)(fp + 0x2c4) = *(f32*)(p + 0x10);
            *(f32*)(fp + 0x2c8) = *(f32*)(p + 0x14);
            *(u16*)(sp + 0x2ac) = *(u16*)(p + 0x284);
            *(f32*)(fp + 0x2cc) = *(f32*)(p + 0xc);
            *(f32*)(fp + 0x2d0) = *(f32*)(p + 0x10);
            *(f32*)(fp + 0x2d4) = *(f32*)(p + 0x14);
            *(u16*)(sp + 0x2ae) = *(u16*)(p + 0x284);
            *(f32*)(fp + 0x2d8) = *(f32*)(p + 0xc);
            *(f32*)(fp + 0x2dc) = *(f32*)(p + 0x10);
            *(f32*)(fp + 0x2e0) = *(f32*)(p + 0x14);
            *(u16*)(sp + 0x2b0) = *(u16*)(p + 0x284);
            *(f32*)(fp + 0x2e4) = *(f32*)(p + 0xc);
            *(f32*)(fp + 0x2e8) = *(f32*)(p + 0x10);
            *(f32*)(fp + 0x2ec) = *(f32*)(p + 0x14);
            *(u16*)(sp + 0x2b2) = *(u16*)(p + 0x284);
            *(f32*)(fp + 0x2f0) = *(f32*)(p + 0xc);
            *(f32*)(fp + 0x2f4) = *(f32*)(p + 0x10);
            *(f32*)(fp + 0x2f8) = *(f32*)(p + 0x14);
            fp += 0x3c;
            *(u16*)(sp + 0x2b4) = *(u16*)(p + 0x284);
            sp += 0xa;
        }
    }
    {
        char* fp = p;
        char* sp = p;
        for (s32 i = 0; i < 10; i++) {
            *(f32*)(fp + 0x3d8) = *(f32*)(p + 0xc);
            *(f32*)(fp + 0x3dc) = *(f32*)(p + 0x10);
            *(f32*)(fp + 0x3e0) = *(f32*)(p + 0x14);
            *(u16*)(sp + 0x338) = *(u16*)(p + 0x284);
            *(f32*)(fp + 0x3e4) = *(f32*)(p + 0xc);
            *(f32*)(fp + 0x3e8) = *(f32*)(p + 0x10);
            *(f32*)(fp + 0x3ec) = *(f32*)(p + 0x14);
            *(u16*)(sp + 0x33a) = *(u16*)(p + 0x284);
            *(f32*)(fp + 0x3f0) = *(f32*)(p + 0xc);
            *(f32*)(fp + 0x3f4) = *(f32*)(p + 0x10);
            *(f32*)(fp + 0x3f8) = *(f32*)(p + 0x14);
            *(u16*)(sp + 0x33c) = *(u16*)(p + 0x284);
            *(f32*)(fp + 0x3fc) = *(f32*)(p + 0xc);
            *(f32*)(fp + 0x400) = *(f32*)(p + 0x10);
            *(f32*)(fp + 0x404) = *(f32*)(p + 0x14);
            *(u16*)(sp + 0x33e) = *(u16*)(p + 0x284);
            *(f32*)(fp + 0x408) = *(f32*)(p + 0xc);
            *(f32*)(fp + 0x40c) = *(f32*)(p + 0x10);
            *(f32*)(fp + 0x410) = *(f32*)(p + 0x14);
            *(u16*)(sp + 0x340) = *(u16*)(p + 0x284);
            *(f32*)(fp + 0x414) = *(f32*)(p + 0xc);
            *(f32*)(fp + 0x418) = *(f32*)(p + 0x10);
            *(f32*)(fp + 0x41c) = *(f32*)(p + 0x14);
            *(u16*)(sp + 0x342) = *(u16*)(p + 0x284);
            *(f32*)(fp + 0x420) = *(f32*)(p + 0xc);
            *(f32*)(fp + 0x424) = *(f32*)(p + 0x10);
            *(f32*)(fp + 0x428) = *(f32*)(p + 0x14);
            *(u16*)(sp + 0x344) = *(u16*)(p + 0x284);
            *(f32*)(fp + 0x42c) = *(f32*)(p + 0xc);
            *(f32*)(fp + 0x430) = *(f32*)(p + 0x10);
            *(f32*)(fp + 0x434) = *(f32*)(p + 0x14);
            fp += 0x60;
            *(u16*)(sp + 0x346) = *(u16*)(p + 0x284);
            sp += 0x10;
        }
    }

    *(s32*)(p + 0x798) = 0;
    *(s32*)(p + 0x79c) = 0;
    *(s32*)(p + 0x7a0) = 0;
    *(s32*)(p + 0x7a4) = 0;
    *(s32*)(p + 0x7a8) = 0;
    *(s32*)(p + 0x7ac) = 0;
    *(s32*)(p + 0x7b0) = 0;
    *(s32*)(p + 0x7b4) = 0;
    *(s32*)(p + 0x7b8) = 0;
    *(s32*)(p + 0x7bc) = 0;
    *(f32*)(p + 0x290) = lbl_8053D120;
    *(f32*)(p + 0x2a0) = *(f32*)(p + 0x290) * *(f32*)(sincosTable___5JMath + (((u16)*(u16*)(p + 0x284) >> 2) & 0x3ff8));
    *(f32*)(p + 0x2a4) = *(f32*)(p + 0x290) * *(f32*)(sincosTable___5JMath + (((u16)*(u16*)(p + 0x284) >> 2) & 0x3ff8) + 4);
    *(f32*)(p + 0x2a8) = lbl_8053D0B0;
    *(f32*)(p + 0x288) = lbl_8053D124;
    *(f32*)(p + 0x28c) = lbl_8053D0B4;
    *(s32*)(p + 0x90) = *(s32*)(p + 0x90) & 3;
    *(u16*)(p + 0x94) = 0;
    *(s32*)(p + 0xbc) = 2;
    *(u32*)(p + 0xb0) = 0x08040004;
    fn_802D7440(fn_802D6A9C(), 0);

    switch (*(s32*)(p + 0x90)) {
    case 0:
        lbl_8053AB30 = lbl_8053AB30 + 1;
        *(s32*)(p + 0x230) = 0;
        return;
    case 1:
        lbl_80539F58 = -1;
        lbl_80539F5C = -1;
        lbl_8053AB34 = 0;
        lbl_8053AB38 = *(s32*)(p + 4);
        fn_80458F9C(lbl_8053AF80, 0x3c);
        lbl_8053AB30 = 0;
        *(s32*)(p + 0x230) = 1;
        lbl_8053AB30 = lbl_8053AB30 + 1;
        return;
    case 2:
        lbl_8053AB38 = *(s32*)(p + 4);
    case 3:
        *(f32*)(p + 0x60) = lbl_8053D0D0;
        *(f32*)(p + 0x64) = lbl_8053D0D0;
        *(f32*)(p + 0x68) = lbl_8053D0D4;
        *(f32*)(p + 0x6c) = lbl_8053D0D4;
        *(s32*)(p + 0x248) = 0x14;
        *(s32*)(p + 0x230) = 8;
        return;
    }
}

