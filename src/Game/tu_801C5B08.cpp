#include "types.h"
#include "Game/SinitPoolChain.h"
#include "JSystem/JMath/JMath.h"

struct Unk801C5B08 {
    u8 unk_00[0x4];
    s32 field_04;
    u8 unk_08[0x4];
    f32 field_0C;
    f32 field_10;
    f32 field_14;
    u8 unk_18[0x230 - 0x18];
    u32 field_230;
    u8 unk_234[0x248 - 0x234];
    s32 field_248;
    s32 field_24C;
    u8 unk_250[0x338 - 0x250];
    s32 field_338;
    s16 field_33C;
    u8 unk_33E[0x358 - 0x33E];
    u8 field_358[0x524 - 0x358];
    u32 field_524;
    u8 unk_528[0x590 - 0x528];
    s32 field_590;
    u8 unk_594[0x598 - 0x594];
    u8 field_598;
    u8 field_599;
    u8 field_59A;
};
extern "C" s16 fn_801D0280(void* p, s32 idx);
extern "C" u8 fn_801CC9F8(void* p, s32 idx);
extern "C" u8* fn_802D6A9C(void);
extern "C" int fn_801C5340(void);
extern "C" void fn_801C3B7C(void* p, s32 state);
extern "C" s32 fn_801D05F8(void* p, void* pos);
extern "C" void fn_801C6260(void* p);
extern "C" u8 fn_801D0DD4(void* p);
extern "C" s32 fn_801CD664(s32 n);
extern "C" void* GetCurrentSlotPtr(void* p);
extern "C" u8 fn_800FE2E4(void* slot, void* pos, s32 room);
extern "C" void fn_800FE294(void* out, void* slot, s32 room);
extern "C" u8 fn_800FD5E8(void* slot, s32 room);
extern "C" s16 fn_801D02E0(void* p, void* pos);
extern void* lbl_8053AAF8;
extern f32 lbl_8053EE68;
extern f32 lbl_8053EE6C;
extern f32 lbl_8053EE70;
extern f32 lbl_8053EE74;
extern f32 lbl_8053EE78;
extern f32 lbl_8053EE7C;
extern f32 lbl_8053EE80;
extern "C" void fn_801C5EBC(u8* this_, s32 state, u8 flag) {
    extern u8* fn_802D6A9C(void);
    extern u8 fn_801CC9F8(void*, s32);
    extern void fn_801D11FC(void*);
    extern s32 fn_801CD664(s32);
    extern u8 fn_801CFA70(void*, void*, void*, s32);
    extern void fn_801CD930(void*, s32, s32);
    extern void* lbl_8053AAF8;
    extern int __float_epsilon[];
    extern f32 lbl_8053EE70;
    extern f32 lbl_8053EE78;
    extern f32 lbl_8053EE7C;
    extern f32 lbl_8053EE80;
    extern f32 lbl_8053EE90;
    extern f32 lbl_8053EE94;

    s32 off = *(s32*)(this_ + 4);
    u8* base = fn_802D6A9C();
    u8 cVar6 = base[0x10000 + off + 0x31df];
    if (flag != 0) {
        *(u8*)(this_ + 0x595) = 0;
        if (cVar6 == 0 || fn_801CC9F8(this_ + 0xc, off) != 0) {
            fn_801D11FC(this_);
        } else {
            s32 k = *(s32*)(this_ + 0x98);
            if (k == 1) {
                *(s16*)(this_ + 0x33c) = 0x4000;
            } else if (k == 0) {
                *(s16*)(this_ + 0x33c) = -0x4000;
            } else {
                f32 r = ((JMARandFast*)((u8*)lbl_8053AAF8 + 0xb4))->get_ufloat_1();
                if (r >= lbl_8053EE70) {
                    *(s16*)(this_ + 0x33c) = -0x4000;
                } else {
                    *(s16*)(this_ + 0x33c) = 0x4000;
                }
            }
        }
    } else {
        f32 dx, dy;
        f32* pf;
        s16 a;
        *(u8*)(this_ + 0x595) = *(u8*)(this_ + 0x595) + 1;
        if (*(u8*)(this_ + 0x596) <= *(u8*)(this_ + 0x595)) {
            *(u8*)(this_ + 0x595) = 0;
            *(u8*)(this_ + 0x596) = fn_801CD664(0x15) + 0x14;
            pf = (f32*)(this_ + state * 0xc + 0x1ac);
            if (cVar6 == 0 || fn_801CC9F8(this_ + 0xc, off) != 0) {
                dx = *(f32*)(this_ + 0xc) - pf[0];
                dy = *(f32*)(this_ + 0x10) - pf[1];
                a = *(s16*)(this_ + 0x33c);
                if (dx * dx + dy * dy > lbl_8053EE90 * *(f32*)__float_epsilon) {
                    a = (s32)(JMath::atanTable_.atan2_(dx, dy) * lbl_8053EE94);
                }
                a = a + fn_801CD664(0x4001) - 0x2000;
                fn_801CD930(this_ + 0x33c, a, 0xaaa);
            } else {
                a = *(s16*)(this_ + 0x33c);
                if (lbl_8053EE78 * (f32)(a + 0x4000) >= lbl_8053EE80 || fn_801CFA70(this_, this_ + 0xc, pf, off) != 1) {
                    if (lbl_8053EE78 * (f32)(a - 0x4000) >= lbl_8053EE80 || fn_801CFA70(this_, this_ + 0xc, pf, off) != 1) {
                        f32 r1 = ((JMARandFast*)((u8*)lbl_8053AAF8 + 0xb4))->get_ufloat_1();
                        if (r1 >= lbl_8053EE7C) {
                            if (*(f32*)(this_ + 0xc) >= pf[0]) {
                                *(s16*)(this_ + 0x33c) = 0x4000;
                            } else {
                                *(s16*)(this_ + 0x33c) = -0x4000;
                            }
                        } else {
                            f32 r2 = ((JMARandFast*)((u8*)lbl_8053AAF8 + 0xb4))->get_ufloat_1();
                            if (r2 >= lbl_8053EE70) {
                                *(s16*)(this_ + 0x33c) = -0x4000;
                            } else {
                                *(s16*)(this_ + 0x33c) = 0x4000;
                            }
                        }
                    } else {
                        *(s16*)(this_ + 0x33c) = 0x4000;
                    }
                } else {
                    *(s16*)(this_ + 0x33c) = -0x4000;
                }
            }
        }
    }
    *(s32*)(this_ + 0x230) = state;
}

extern "C" void fn_801C6784(void* p) {
    Unk801C5B08* self = (Unk801C5B08*)p;
    s32 off = self->field_04;
    u8* base = fn_802D6A9C();
    if (base[0x10000 + off + 0x31df] != 0 && fn_801CC9F8(&self->field_0C, self->field_04) == 0) {
        if (self->field_0C < *(f32*)((char*)p + self->field_590 * 12 + 0x1ac)) {
            self->field_33C = 0x4000;
        } else {
            self->field_33C = -0x4000;
        }
    } else {
        self->field_33C = fn_801D0280(p, self->field_590);
    }
}
