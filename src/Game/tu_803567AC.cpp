#include "Game/SinitPoolChain.h"
#include "JSystem/JMath/JMath.h"


extern "C" void __dt__5ActorFv(void* this_, int how);
void operator delete(void* p);
extern "C" char lbl_804AD1C8[];
extern "C" void* fn_803567AC(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AD1C8;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_801EE558(void* a, void* b, f32* c, s32 d);
extern "C" void* fn_802D6A9C(void);
extern "C" float lbl_805427E8;
extern "C" float lbl_805427EC;
extern "C" void fn_8035680C(u8* this_) {
    switch (*(s32*)(this_ + 0x250)) {
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        *(s32*)(this_ + 0x248) = 0;
        return;
    case 1:
    case 3:
        if (this_[0x268] == 1 && *(s32*)((u8*)fn_802D6A9C() + 4) == 1 && *(s32*)((u8*)fn_802D6A9C() + 8) == 1) {
            *(s32*)(this_ + 0x248) = 0;
            return;
        }
        break;
    }

    switch (*(s32*)(this_ + 0x230)) {
    case 0:
    case 1:
    case 4:
        {
            s32 n = *(s32*)(this_ + 0x244);
            if (n != 0) {
                *(s32*)(this_ + 0x244) = n - 1;
            } else {
                f32 v[3];
                f32 len;
                *(s32*)(this_ + 0x244) = 0x14;
                fn_801EE558(this_, v, &len, 0);
                if (len < lbl_805427E8) {
                    f32 a = JMath::atanTable_.atan2_(-v[0], -v[1]);
                    u16 ang = (s32)(a * lbl_805427EC);
                    if (ang < 0x2000 || ang >= 0xe000) {
                        *(s32*)(this_ + 0x248) = 3;
                    } else if (ang >= 0x2000 && ang < 0x6000) {
                        *(s32*)(this_ + 0x248) = 1;
                    } else if (ang >= 0x6000 && ang <= 0xa000) {
                        *(s32*)(this_ + 0x248) = 2;
                    } else {
                        *(s32*)(this_ + 0x248) = 0;
                    }
                } else {
                    *(s32*)(this_ + 0x248) = 3;
                }
            }
        }
        break;
    case 3:
    case 5:
        if (*(s32*)(this_ + 0x250) == 5) {
            if (*(s32*)(this_ + 0x25c) > 0) {
                *(s32*)(this_ + 0x248) = 0;
            } else {
                *(s32*)(this_ + 0x248) = 1;
            }
        } else if (*(s32*)(this_ + 0x258) > 0) {
            *(s32*)(this_ + 0x248) = 0;
        } else {
            *(s32*)(this_ + 0x248) = 1;
        }
        if (*(s32*)(this_ + 0x230) == 5) {
            *(s32*)(this_ + 0x248) ^= 1;
        }
        break;
    }
}

extern "C" char lbl_80472390[];
extern "C" float lbl_805427E4;
extern "C" void fn_801F06F0(void* this_, void* p2, int p3, int p4, int p5, float f6, float f7);
extern "C" void fn_80307AC8(void* obj, unsigned int id, void* pos, int kind, unsigned int a, unsigned int b, int c);
extern "C" void fn_80307AC8(void* obj, unsigned int id, void* pos, int kind, unsigned int a, unsigned int b, int c);
extern "C" void fn_80356A24(char* this_) {
    char* base = lbl_80472390;
    int mode = *(int*)(this_ + 0x230);
    if (mode != 2) {
        int idx = *(int*)(this_ + 0x250);
        int off = idx * 8;
        char* res = base + 0x11c;
        int val;
        if (*(int*)(base + 0xb0 + off) == 1) {
            res = base + 0x108;
        }
        if (mode == 0 || (unsigned int)(mode - 3) <= 1 || mode == 1) {
            int a248 = *(int*)(this_ + 0x248);
            int a238 = *(int*)(this_ + 0x238);
            char* tbl = ((char**)(base + idx * 16))[2];
            val = *(int*)(base + 0xb4 + off) + *(int*)(tbl + a248 * 16 + a238 * 4);
        } else {
            int a248 = *(int*)(this_ + 0x248);
            int a238 = *(int*)(this_ + 0x238);
            char* tbl = ((char**)(base + idx * 16))[3];
            val = *(int*)(base + 0xb4 + off) + *(int*)(tbl + a248 * 16 + a238 * 4);
        }
        fn_801F06F0(this_, res, val, 0, 0, lbl_805427E4, lbl_805427E4);
        if (*(int*)(this_ + 0x250) == 5) {
            fn_80307AC8(*(void**)(this_ + 0x198), *(unsigned int*)(this_ + 4), this_ + 0xc, val, 0, 0, -1);
        }
    }
}
extern "C" u8* lbl_8053AAF8;
extern "C" u8 fn_801F6758(void* pos, u32 room, f32 r);

static f32 tu803567AC_rnd() {
    union { f32 f; u32 s; } out;
    u32* seed = (u32*)(lbl_8053AAF8 + 0xb4);
    *seed = *seed * 0x19660d + 0x3c6ef35f;
    out.s = (*seed >> 9) | 0x3f800000;
    return out.f - 1.0f;
}
