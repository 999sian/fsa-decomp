// Game TU 801B7784-801B80C0 (ROPE). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
#include "Game/ItemBase.h"
extern "C" void fn_801F06F0(void* actor, void* res, u32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern "C" void fn_801D2264(void* obj, s32 a, u32 b);
extern "C" void fn_801CE4BC(void* this_);
extern "C" void fn_801D0ED0(void* this_);
extern "C" s32 fn_801CD664(s32 n);
extern "C" void fn_801D2608(void* obj, void* tbl, u32 n);
extern "C" void fn_801D22DC(void* obj, s32 a, u32 b, u32 c);
extern "C" void fn_801D1D60(void* obj);
extern u8 lbl_80469168[];
extern u8 lbl_804A3A58[];
extern const f32 lbl_8053EAF0;
extern const f32 lbl_8053EAF4;
extern const f32 lbl_8053EAF8;
extern const f32 lbl_8053EAFC;
extern const f32 lbl_8053EB00;
extern const f32 lbl_8053EB18;

extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_801D0F40(void* this_);
extern void* lbl_804A3A68[];
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_801B7784(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A3A68;
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

extern "C" void fn_801B7814(u8* this_) {
    fn_801F06F0(this_, lbl_80469168, *(s32*)(this_ + 0x280) + 0xb5, 0, 0, 1.0f, 1.0f);
}

static inline f32 rope_lerp(f32 a, f32 b, f32 t) { return t * (b - a) + a; }
extern "C" void fn_801B7854(u8* this_) {
    fn_801D2264(this_ + 0x270, *(s32*)(this_ + 0x98), 2);
    f32 t = *(f32*)(this_ + 0x254) - 0.4f;
    t *= 0.9090909f;
    if (t > 1.0f) {
        t = 1.0f;
    } else if (t < 0.0f) {
        t = 0.0f;
    }
    *(f32*)(this_ + 0x2a0) = rope_lerp(1.0f, 3.0f, t);
    fn_801CE4BC(this_);
}

struct ROPE_Random {
    u32 seed;
    f32 get() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
};
struct ROPE_Game { u8 pad[0xb4]; ROPE_Random rnd; };
extern ROPE_Game* lbl_8053AAF8;
extern int __float_max[];
extern "C" u8 fn_801D0B44(void* actor, s32 idx);
extern "C" f32* fn_8023E724(s32 idx);
extern "C" f32 fn_801D0DA0(void* actor, s32 idx, void* pos);
extern "C" u8 fn_801CFD68(void* actor, s32 dir, f32 d);
extern "C" s32 fn_801CF720(void* actor, s32 dir);
extern "C" s32 fn_801CF6B8(void* actor);

static inline void rope_startMove(u8* this_) {
    *(s32*)(this_ + 0x250) = fn_801CD664(0x29) + 0x3c;
    *(f32*)(this_ + 0x258) = 0.4f;
    if (*(s32*)(this_ + 0x248) != 2) {
        *(s32*)(this_ + 0x98) = fn_801CF6B8(this_);
    }
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x248) = 1;
}

static inline void rope_startWait(u8* this_) {
    *(s32*)(this_ + 0x250) = fn_801CD664(0x3d) + 0x28;
    *(f32*)(this_ + 0x258) = 0.0f;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x248) = 0;
}

extern "C" void fn_801B78DC(u8* this_, u8 blocked) {
    s32 i;
    s32 dir;
    int found;
    switch (*(s32*)(this_ + 0x248)) {
    case 0:
    case 1:
        found = 0;
        if (*(s32*)(this_ + 0x24c) >= 0x1e) {
            dir = 0;
            f32 best = *(f32*)__float_max;
            for (i = 0; i < 4; i++) {
                if (!fn_801D0B44(this_, i)) {
                    continue;
                }
                f32 dx = __fabsf(*(f32*)(this_ + 0xc) - fn_8023E724(i)[0]);
                f32 dy = __fabsf(*(f32*)(this_ + 0x10) - fn_8023E724(i)[1]);
                if (dx <= 10.0f) {
                    f32 d = fn_801D0DA0(this_, i, this_ + 0xc);
                    if (100.0f < d && d < 14400.0f && d < best) {
                        if (*(f32*)(this_ + 0x10) < fn_8023E724(i)[1]) {
                            if (!fn_801CFD68(this_, 2, dy)) {
                                best = d;
                                dir = 2;
                                found = 1;
                            }
                        } else {
                            if (!fn_801CFD68(this_, 3, dy)) {
                                best = d;
                                dir = 3;
                                found = 1;
                            }
                        }
                    }
                } else if (dy <= 10.0f) {
                    f32 d = fn_801D0DA0(this_, i, this_ + 0xc);
                    if (100.0f < d && d < 14400.0f && d < best) {
                        if (*(f32*)(this_ + 0xc) < fn_8023E724(i)[0]) {
                            if (!fn_801CFD68(this_, 0, dx)) {
                                best = d;
                                dir = 0;
                                found = 1;
                            }
                        } else {
                            if (!fn_801CFD68(this_, 1, dx)) {
                                best = d;
                                dir = 1;
                                found = 1;
                            }
                        }
                    }
                }
            }
            if ((u8)found) {
                *(s32*)(this_ + 0x250) = fn_801CD664(0x29) + 0x3c;
                *(f32*)(this_ + 0x258) = 1.5f;
                *(s32*)(this_ + 0x24c) = 0;
                *(s32*)(this_ + 0x248) = 2;
                *(s32*)(this_ + 0x98) = dir;
            }
        }
        break;
    }

    s32 state = *(s32*)(this_ + 0x248);
    switch (state) {
    case 0:
        if (*(s32*)(this_ + 0x24c) >= *(s32*)(this_ + 0x250)) {
            rope_startMove(this_);
        }
        break;
    case 1:
    case 2:
        if (blocked) {
            *(s32*)(this_ + 0x98) = fn_801CF720(this_, *(s32*)(this_ + 0x98));
            *(s32*)(this_ + 0x250) += 10;
        } else if (*(s32*)(this_ + 0x24c) >= *(s32*)(this_ + 0x250)) {
            if (state == 1) {
                if (lbl_8053AAF8->rnd.get() < 0.35f) {
                    rope_startWait(this_);
                } else {
                    rope_startMove(this_);
                }
            } else {
                rope_startMove(this_);
            }
        }
        break;
    case 3:
        if (*(s32*)(this_ + 0x24c) > 1 && *(f32*)(this_ + 0x14) <= 0.0f) {
            rope_startWait(this_);
        }
        break;
    }
}

extern "C" void fn_801B7D34(u8* this_) {
    fn_801D0ED0(this_);
    if (*(f32*)(this_ + 0x14) > 0.001f) {
        *(s32*)(this_ + 0x248) = 3;
        *(s32*)(this_ + 0x250) = -1;
    } else {
        *(s32*)(this_ + 0x248) = 0;
        *(s32*)(this_ + 0x250) = fn_801CD664(0x3d) + 0x28;
    }
    *(s32*)(this_ + 0x24c) = 0;
    *(f32*)(this_ + 0x254) = 0.0f;
    *(f32*)(this_ + 0x258) = 0.0f;
    fn_801D2608(this_ + 0x270, lbl_804A3A58, 4);
    fn_801D22DC(this_ + 0x270, *(s32*)(this_ + 0x98), 2, 0);
    fn_801D1D60(this_ + 0x270);
}

extern "C" void* fn_801B7DE0(void* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A3A68;
    return this_;
}

extern "C" void* dtor_801B7E1C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A4808;
        if (p + 0x270 != 0) {
            if (p + 0x294 != 0) {
                *(void**)(p + 0x294) = lbl_8049CC34;
            }
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
