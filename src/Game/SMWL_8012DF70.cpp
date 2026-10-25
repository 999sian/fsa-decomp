#include "types.h"
#include "Game/SinitPoolChain.h"
#include "Game/Actor.h"
#include "Game/ItemBase.h"

extern "C" char lbl_8049E8A0[];
extern "C" const f32 lbl_8053CC3C;
extern "C" void __ct__5ActorFv(Actor*);
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void fn_801EE434(void*);
extern "C" f32 lbl_8053CC50;
extern "C" f32 lbl_8053CC58;
extern "C" f32 lbl_8053CC5C;
extern "C" f32 lbl_8053CC60;
extern "C" const char* lbl_80539F40;
extern "C" void* fn_804032E8(u32 type, const char* name);
extern "C" void* fn_8013CC50(s32 id, void* pos, s32 kind, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
extern "C" void v01__5ActorFv(void* this_);
extern "C" u8* lbl_8053AB10;
extern "C" void fn_802F745C(void* a, void* b, s32 c, void* d);
extern f32 lbl_8053CC50;
extern int __float_epsilon[];

extern f32 lbl_8053CC54;
extern "C" void fn_8012DF70(Actor* this_) {
    u8* p = (u8*)this_;
    this_->Actor::v06();
    DrawRec rec;
    DrawRec rec2;
    f32 box[3][4];
    f32 x = *(f32*)(p + 0x54);
    f32 y = *(f32*)(p + 0x58);
    f32 z = *(f32*)(p + 0x5c);
    if (z * z + x * x + y * y > lbl_8053CC50 * *(f32*)__float_epsilon) {
        box[0][0] = x;
        box[0][1] = 0.0f;
        box[0][2] = 0.0f;
        box[0][3] = 0.0f;
        box[1][0] = 0.0f;
        box[1][1] = y;
        box[1][2] = 0.0f;
        box[1][3] = lbl_8053CC50 * (1.0f - *(f32*)(p + 0x238));
        box[2][0] = 0.0f;
        box[2][1] = 0.0f;
        box[2][2] = z;
        box[2][3] = 0.0f;
        rec.w18 = box;
    }
    if (*(s32*)(p + 0x4) < 8) {
        fn_802F745C(*(void**)(lbl_8053AB10 + 0x20), p + 0xc, *(s32*)(p + 0x23c), &rec);
    }
}

extern "C" void v03__5ActorFv(void* this_);
extern "C" void detach__5ActorFv(void* this_);
extern "C" void fn_80239914(f32* box, s32 room, s32 handle);
extern "C" void fn_801F0E34(void* this_, s32 a, s32 b);
extern "C" void fn_801F2DB4(void* this_, s32 a, s32 b, s32 c);
extern "C" s32 fn_801F285C(void* this_, s32 a, s32 b, s32 c, s32 d);
extern "C" void fn_802379E4(s32 r, f32* pos);
extern "C" s32 fn_801F2718(void* this_, u32 type);
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F666C(void* a, s32 b);
extern "C" s32 fn_802BA9F8(void);
extern "C" s32 fn_801CD950(f32* t, f32 a, f32 b);
extern "C" void fn_801F0D20(void* this_, s32 st);
extern "C" f32 lbl_8053CC38;
extern "C" f32 lbl_8053CC40;
extern "C" f32 lbl_8053CC44;
extern "C" f32 lbl_8053CC48;
extern "C" f32 lbl_8053CC4C;
extern "C" void fn_801EE434(void* p);
extern "C" void fn_8012E230(Actor* this_) {
    u8* p = (u8*)this_;
    v03__5ActorFv(this_);
    f32 box[4];
    Vec vec;
    f32 pos[2];
    box[0] = *(f32*)(p + 0x60);
    box[1] = *(f32*)(p + 0x64);
    box[2] = *(f32*)(p + 0x68);
    box[3] = *(f32*)(p + 0x6c);
    box[0] = box[0] + *(f32*)(p + 0xc);
    box[2] = box[2] + *(f32*)(p + 0xc);
    box[1] = box[1] + *(f32*)(p + 0x10);
    box[3] = box[3] + *(f32*)(p + 0x10);
    fn_80239914(box, *(s32*)(p + 0x4), *(s32*)(p + 0x198));
    switch (*(s32*)(p + 0x230)) {
    case 0:
        fn_801F0E34(this_, 0x50069, 0);
        fn_801F2DB4(this_, 0x4e554c4c, 0x4e554c4c, 0);
        s32 snd = fn_801F285C(this_, 0, 0, 1, -1);
        u8 ok;
        if (snd >= 0) {
            fn_801F0E34(this_, 0x400d1, 0);
            f32 y = *(f32*)(p + 0x10);
            pos[0] = *(f32*)(p + 0xc);
            pos[1] = y;
            fn_802379E4(snd, pos);
            s32 found = fn_801F2718(this_, 0x46495245);
            if (found <= 0) {
                ok = 0;
            } else {
                if (fn_801F666C(fn_801F856C(), found) == 0) {
                    ok = 0;
                } else {
                    if (fn_802BA9F8() == 1) {
                        ok = 1;
                    } else {
                        ok = 0;
                    }
                }
            }
        } else {
            ok = 0;
        }
        if (!ok) {
            *(s32*)(p + 0x234) = 0;
        } else {
            if (*(s32*)(p + 0x234) == 0) {
                vec = *(Vec*)(p + 0xc);
                vec.y = vec.y + lbl_8053CC38;
                fn_8013CC50(*(s32*)(p + 0x4), &vec, 0x28d, 0, 0, 0, 0, 1, *(f32*)(p + 0x238));
                fn_8013CC50(*(s32*)(p + 0x4), &vec, 0x28e, 0, 0, 0, 0, 1, *(f32*)(p + 0x238));
                fn_801F0E34(this_, 0x30061, 0);
            }
            *(s32*)(p + 0x234) = *(s32*)(p + 0x234) + 1;
            if (*(s32*)(p + 0x234) >= 0x3c) {
                *(s32*)(p + 0x230) = 1;
                fn_801EE434(*(void**)(p + 0x240));
                fn_801EE434(*(void**)(p + 0x244));
                fn_8013CC50(*(s32*)(p + 0x4), p + 0xc, 0x44f, 0, 0, 0, 0, 1, lbl_8053CC3C);
                fn_8013CC50(*(s32*)(p + 0x4), p + 0xc, 0x450, 0, 0, 0, 0, 1, lbl_8053CC3C);
                fn_8013CC50(*(s32*)(p + 0x4), p + 0xc, 0x451, 0, 0, 0, 0, 1, lbl_8053CC3C);
                fn_801F0E34(this_, 0x5006a, 0);
            }
        }
        break;
    case 1:
        p[0x11d] = 0;
        u8 done = 0;
        if (*(f32*)(p + 0x238) < lbl_8053CC40 || fn_801CD950((f32*)(p + 0x238), lbl_8053CC40, lbl_8053CC44) == 0) {
            done = fn_801CD950((f32*)(p + 0x238), lbl_8053CC48, lbl_8053CC4C) == 0;
        }
        if (done) {
            *(s32*)(p + 0x230) = 2;
            fn_801F0D20(this_, 3);
            detach__5ActorFv(this_);
        }
        break;
    }
    f32 t = *(f32*)(p + 0x238);
    *(f32*)(p + 0x54) = t;
    *(f32*)(p + 0x58) = t;
    *(f32*)(p + 0x5c) = t;
}

extern "C" void fn_8012E5A0(Actor* p) {
    v01__5ActorFv(p);
    f32* box = (f32*)((char*)p + 0x60);
    box[0] = lbl_8053CC58;
    box[1] = lbl_8053CC5C;
    box[2] = lbl_8053CC60;
    box[3] = lbl_8053CC50;
    box[4] = box[0];
    box[5] = box[1];
    box[6] = box[2];
    box[7] = box[3];
    box[8] = box[0];
    box[9] = box[1];
    box[10] = box[2];
    box[11] = box[3];
    *(s32*)((char*)p + 0x108) = 1000;
    *(s32*)((char*)p + 0xb8) = 1;
    *(s32*)((char*)p + 0xf8) = 2;
    *(s32*)((char*)p + 0xbc) = 3;
    *(s32*)((char*)p + 0x1a4) = 1;
    *(s32*)((char*)p + 0xb0) = 0xa040304;
    if (*(void**)((char*)p + 0x23c) == 0) {
        *(void**)((char*)p + 0x23c) = fn_804032E8('TIMG', lbl_80539F40);
    }
    if (*(void**)((char*)p + 0x240) == 0) {
        *(void**)((char*)p + 0x240) = fn_8013CC50(p->field_04, (char*)p + 0xc, 0x452, 0, 0, 0, 0, 1, lbl_8053CC3C);
    }
    if (*(void**)((char*)p + 0x244) == 0) {
        *(void**)((char*)p + 0x244) = fn_8013CC50(p->field_04, (char*)p + 0xc, 0x453, 0, 0, 0, 0, 1, lbl_8053CC3C);
    }
}

extern "C" Actor* fn_8012E6EC(Actor* p, s16 n) {
    if (p != 0) {
        *(void**)p = lbl_8049E8A0;
        if (*(void**)((char*)p + 0x240) != 0) {
            fn_801EE434(*(void**)((char*)p + 0x240));
            *(s32*)((char*)p + 0x240) = 0;
        }
        if (*(void**)((char*)p + 0x244) != 0) {
            fn_801EE434(*(void**)((char*)p + 0x244));
            *(s32*)((char*)p + 0x244) = 0;
        }
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" Actor* fn_8012E780(Actor* p) {
    __ct__5ActorFv(p);
    *(void**)p = lbl_8049E8A0;
    *(s32*)((char*)p + 0x230) = 0;
    *(s32*)((char*)p + 0x234) = 0;
    *(f32*)((char*)p + 0x238) = lbl_8053CC3C;
    *(s32*)((char*)p + 0x23c) = 0;
    *(s32*)((char*)p + 0x240) = 0;
    *(s32*)((char*)p + 0x244) = 0;
    return p;
}
