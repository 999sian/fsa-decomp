#include "types.h"
#include "Game/SinitPoolChain.h"
#include "JSystem/JMath/JMath.h"

#include "JSystem/JGeometry/Vec.h"

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
    u8 unk_594[0x597 - 0x594];
    u8 field_597;
    u8 field_598;
    u8 field_599;
    u8 field_59A;
    u8 unk_59B[0x5AC - 0x59B];
    f32 field_5AC;
};
extern "C" s16 fn_801D0280(void* p, s32 idx);
extern "C" u8 fn_801CC9F8(void* p, s32 idx);
extern "C" u8* fn_802D6A9C(void);
extern "C" u8 fn_801C5340(void);
extern "C" void fn_801C5EBC(u8* this_, s32 state, u8 flag);
extern "C" void fn_801C3B7C(void* p, s32 state);
extern "C" s32 fn_801D05F8(void* p, void* pos, f32 radius);
extern "C" void fn_801C6260(void* p);
extern "C" u8 fn_801D0DD4(void* p);
extern "C" s32 fn_801CD664(s32 n);
extern "C" void* GetCurrentSlotPtr(void* p);
extern "C" Vec fn_800FE294(void* slot, s32 room);
extern "C" u8 fn_800FD5E8(void* slot, s32 room);
extern "C" s16 fn_801D02E0(void* p, void* pos);
extern void* lbl_8053AAF8;
extern const f32 lbl_8053EE68;
extern const f32 lbl_8053EE6C;
extern const f32 lbl_8053EE70;
extern const f32 lbl_8053EE74;
extern const f32 lbl_8053EE78;
extern const f32 lbl_8053EE7C;
extern const f32 lbl_8053EE80;

struct TuRandom {
    u32 seed;
    u32 get() {
        seed = (seed * 0x19660d) + 0x3c6ef35f;
        return seed;
    }
    f32 get_ufloat_1() {
        union {
            f32 f;
            u32 s;
        } out;
        out.s = (this->get() >> 9) | 0x3f800000;
        return out.f - lbl_8053EE68;
    }
};

static inline f32 tuRand01() {
    u8* g = (u8*)lbl_8053AAF8;
    *(u32*)(g + 0xb4) = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
    u32 bits = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
    return *(f32*)&bits - lbl_8053EE68;
}
extern "C" s32 fn_800FE2E4(void* slot, JGeometry::TVec3f pos, s32 room);
#pragma opt_propagation off
extern "C" void fn_801C5B08(Unk801C5B08* self, u8 param_2) {
    if (fn_801C5340() != 0) {
        self->field_230 |= 0x2000000;
        fn_801C3B7C(self, 0x1e);
    } else {
        u8 flag;
        s32 d;
        s32 r = fn_801D05F8(self, &self->field_0C, self->field_5AC);
        if (r < 0) {
            if (((TuRandom*)((u8*)lbl_8053AAF8 + 0xb4))->get_ufloat_1() < lbl_8053EE6C) {
                fn_801C3B7C(self, 0xf);
            } else {
                fn_801C3B7C(self, 0x11);
            }
        } else {
            d = r;
            self->field_338 = d;
            fn_801C6260(self);
            if (self->field_248 == 0x1b) {
                if (self->field_59A == 0 && self->field_24C >= 0xf0 && fn_801D0DD4(self) != 0 &&
                    (self->field_524 & 0x40) == 0) {
                    s32 off = self->field_04;
                    u8* base = fn_802D6A9C();
                    if (base[0x10000 + off + 0x31df] != 0 && fn_801CC9F8(&self->field_0C, self->field_04) == 0) {
                        if (((TuRandom*)((u8*)lbl_8053AAF8 + 0xb4))->get_ufloat_1() < lbl_8053EE70) {
                            self->field_33C = 0x4000;
                        } else {
                            self->field_33C = -0x4000;
                        }
                    } else {
                        self->field_33C = fn_801D0280(self, d);
                        s32 rnd = fn_801CD664(0x4001) - 0x2000;
                        self->field_33C += rnd;
                    }
                    fn_801C3B7C(self, 0x1c);
                    self->field_59A = 0xb4;
                } else {
                    flag = 0;
                    if (self->field_599 == 0) {
                        u8 r26 = ((u8*)GetCurrentSlotPtr(self->field_358))[3];
                        u8 r27 = fn_800FE2E4(GetCurrentSlotPtr(self->field_358), *(JGeometry::TVec3f*)&self->field_0C, self->field_04);
                        u8* slot = (u8*)GetCurrentSlotPtr(self->field_358);
                        if (r26 < slot[2]) {
                            slot[3] = r26;
                        }
                        JGeometry::TVec3f v;
                        v = fn_800FE294(GetCurrentSlotPtr(self->field_358), r27);
                        f32 dx = v.x - self->field_0C;
                        f32 dy = v.y - self->field_10;
                        f32 dx2 = dx * dx;
                        f32 dy2 = dy * dy;
                        if (dx2 + dy2 <= lbl_8053EE74) {
                            if (fn_800FD5E8(GetCurrentSlotPtr(self->field_358), r27)) {
                                flag = 1;
                            } else {
                                s16 ang;
                                ang = fn_801D02E0(self, &v);
                                if (lbl_8053EE78 * fabs((f32)(s16)(self->field_33C - ang)) <= lbl_8053EE7C) {
                                    if (((TuRandom*)((u8*)lbl_8053AAF8 + 0xb4))->get_ufloat_1() < lbl_8053EE80) {
                                        flag = 1;
                                    }
                                }
                            }
                        }
                    }
                    if (flag) {
                        self->field_230 |= 0x200000;
                        fn_801C3B7C(self, 0x11);
                        self->field_230 &= ~0x200000;
                        self->field_598 = 0x78;
                    } else {
                        fn_801C5EBC((u8*)self, d, param_2);
                    }
                }
            }
        }
    }
}
#pragma opt_propagation reset
extern "C" void fn_801C5EBC(u8* this_, s32 state, u8 flag) {
    extern u8* fn_802D6A9C(void);
    extern u8 fn_801CC9F8(void*, s32);
    extern void fn_801D11FC(void*);
    extern s32 fn_801CD664(s32);
    extern u8 fn_801CFA70(void*, void*, void*, s32);
    extern void fn_801CD930(void*, s32, s32);
    extern void* lbl_8053AAF8;
    extern int __float_epsilon[];
    extern const f32 lbl_8053EE90;
    extern const f32 lbl_8053EE94;
    struct TuGame { u8 pad[0xb4]; TuRandom rnd; };

    s32 off = *(s32*)(this_ + 4);
    u8 cVar6 = *(u8*)((u32)fn_802D6A9C() + 0x10000 + off + 0x31df);
    if (flag != 0) {
        *(u8*)(this_ + 0x595) = 0;
        if (cVar6 != 0 && fn_801CC9F8(this_ + 0xc, *(s32*)(this_ + 4)) == 0) {
            switch (*(s32*)(this_ + 0x98)) {
            case 0:
                *(s16*)(this_ + 0x33c) = -0x4000;
                break;
            case 1:
                *(s16*)(this_ + 0x33c) = 0x4000;
                break;
            default:
                if (((TuGame*)lbl_8053AAF8)->rnd.get_ufloat_1() < lbl_8053EE70) {
                    *(s16*)(this_ + 0x33c) = 0x4000;
                } else {
                    *(s16*)(this_ + 0x33c) = -0x4000;
                }
                break;
            }
        } else {
            fn_801D11FC(this_);
        }
    } else {
        *(u8*)(this_ + 0x595) = *(u8*)(this_ + 0x595) + 1;
        if (*(u8*)(this_ + 0x595) >= *(u8*)(this_ + 0x596)) {
            *(u8*)(this_ + 0x595) = 0;
            *(u8*)(this_ + 0x596) = fn_801CD664(0x15) + 0x14;
            f32* pf = (f32*)(this_ + state * 0xc + 0x1ac);
            if (cVar6 != 0 && fn_801CC9F8(this_ + 0xc, *(s32*)(this_ + 4)) == 0) {
                if (lbl_8053EE78 * JMAAbs((f32)(s16)(*(s16*)(this_ + 0x33c) + 0x4000)) < lbl_8053EE80 &&
                    fn_801CFA70(this_, this_ + 0xc, pf, *(s32*)(this_ + 4)) == 1) {
                    *(s16*)(this_ + 0x33c) = -0x4000;
                } else if (lbl_8053EE78 * JMAAbs((f32)(s16)(*(s16*)(this_ + 0x33c) - 0x4000)) < lbl_8053EE80 &&
                           fn_801CFA70(this_, this_ + 0xc, pf, *(s32*)(this_ + 4)) == 1) {
                    *(s16*)(this_ + 0x33c) = 0x4000;
                } else if (((TuGame*)lbl_8053AAF8)->rnd.get_ufloat_1() < lbl_8053EE7C) {
                    TuGame* game = (TuGame*)lbl_8053AAF8;
                    if (game->rnd.get_ufloat_1() < lbl_8053EE70) {
                        *(s16*)(this_ + 0x33c) = 0x4000;
                    } else {
                        *(s16*)(this_ + 0x33c) = -0x4000;
                    }
                } else {
                    if (*(f32*)(this_ + 0xc) < pf[0]) {
                        *(s16*)(this_ + 0x33c) = -0x4000;
                    } else {
                        *(s16*)(this_ + 0x33c) = 0x4000;
                    }
                }
            } else {
                f32 dy = *(f32*)(this_ + 0x10) - pf[1];
                f32 dx = *(f32*)(this_ + 0xc) - pf[0];
                s16 a = *(s16*)(this_ + 0x33c);
                if (!(dx * dx + dy * dy <= lbl_8053EE90 * *(f32*)__float_epsilon)) {
                    f32 ang = JMath::atanTable_.atan2_(dx, dy);
                    a = ang * lbl_8053EE94;
                }
                s32 r = fn_801CD664(0x4001) - 0x2000;
                a += r;
                fn_801CD930(this_ + 0x33c, a, 0xaaa);
            }
        }
    }
}

extern "C" f32 fn_801D0DA0(void* p, s32 state, void* pos);
extern "C" u8 fn_801D183C(void* p, f32 f);
extern "C" u8 fn_801CAED4(void* p, s32 state);
extern "C" u8 fn_801CFCF0(void* p, s32 arg);
extern f32 lbl_8053EDF4;
extern f32 lbl_8053EE98;
extern f32 lbl_8053EE9C;
extern f32 lbl_8053EEA0;
extern f32 lbl_8053EEA4;
extern f32 lbl_8053EEA8;
extern "C" void fn_801C6260(void* p) {
    Unk801C5B08* self = (Unk801C5B08*)p;
    f32 d = fn_801D0DA0(p, self->field_338, &self->field_0C);
    u8 r31 = fn_801D183C(p, lbl_8053EDF4);
    s32 r30 = fn_801CAED4(p, self->field_338) == 0;
    if (self->field_597 == 0 && r31 && (u8)r30 && (self->field_524 & 0x10) && d <= lbl_8053EE98) {
        fn_801C3B7C(p, 0x22);
        return;
    }
    if (!(d <= lbl_8053EE9C)) {
        return;
    }
    if (self->field_59A == 0 && fn_801D0DD4(p) && !(self->field_524 & 0x40)) {
        if (!(u8)r30 || ((JMARandFast*)((u8*)lbl_8053AAF8 + 0xb4))->get_ufloat_1() < lbl_8053EE70) {
            s32 state = self->field_338;
            s32 room = self->field_04;
            if (fn_802D6A9C()[0x10000 + room + 0x31df] != 0 && fn_801CC9F8(&self->field_0C, self->field_04) == 0) {
                f32* pf = (f32*)((u8*)self + state * 0xc + 0x1ac);
                f32 t;
                t = (f32)(s16)(self->field_33C + 0x4000);
                if (lbl_8053EE78 * fabs(t) < lbl_8053EE80 && !fn_801CFCF0(p, 1)) {
                    if (self->field_0C < pf[0]) {
                        self->field_33C = -0x4000;
                    } else {
                        self->field_33C = ((JMARandFast*)((u8*)lbl_8053AAF8 + 0xb4))->get_ufloat_1() < lbl_8053EEA0 ? -0x4000 : 0x4000;
                    }
                } else {
                    t = (f32)(s16)(self->field_33C - 0x4000);
                    if (lbl_8053EE78 * fabs(t) < lbl_8053EE80 && !fn_801CFCF0(p, 0)) {
                        if (self->field_0C > pf[0]) {
                            self->field_33C = 0x4000;
                        } else {
                            self->field_33C = ((JMARandFast*)((u8*)lbl_8053AAF8 + 0xb4))->get_ufloat_1() < lbl_8053EEA0 ? 0x4000 : -0x4000;
                        }
                    } else {
                        if (((JMARandFast*)((u8*)lbl_8053AAF8 + 0xb4))->get_ufloat_1() < lbl_8053EE7C) {
                            self->field_33C = ((JMARandFast*)((u8*)lbl_8053AAF8 + 0xb4))->get_ufloat_1() < lbl_8053EE70 ? 0x4000 : -0x4000;
                        } else {
                            self->field_33C = self->field_0C < pf[0] ? -0x4000 : 0x4000;
                        }
                    }
                }
            } else {
                self->field_33C -= 0x8000;
                self->field_33C += fn_801CD664(0x4001) - 0x2000;
            }
            fn_801C3B7C(p, 0x1c);
            return;
        }
    }
    if (self->field_597 != 0 || !(u8)r30) {
        return;
    }
    if (self->field_524 & 0x10) {
        if (((JMARandFast*)((u8*)lbl_8053AAF8 + 0xb4))->get_ufloat_1() < lbl_8053EEA4) {
            if (self->field_524 & 0x20) {
                if (((JMARandFast*)((u8*)lbl_8053AAF8 + 0xb4))->get_ufloat_1() < lbl_8053EEA8) {
                    fn_801C3B7C(p, 0x26);
                } else {
                    fn_801C3B7C(p, 0x25);
                }
            } else {
                fn_801C3B7C(p, 0x25);
            }
            return;
        }
    }
    if (r31 && (self->field_524 & 0x8)) {
        fn_801C3B7C(p, 0x22);
    }
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
