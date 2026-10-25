#include "types.h"

extern "C" void __ct__5ActorFv(void* this_);
extern "C" void fn_801D267C(void* anim);
extern void* lbl_8049DE18[];
extern const f32 lbl_8053C8BC;
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* p);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_8049CC34[];
extern "C" void v01__5ActorFv(void* this_);
extern "C" void fn_801D2608(void*, void*, s32);
extern "C" void fn_801D22DC(void*, s32, s32, s32);
extern "C" void fn_801D1F14(void*, f32);
extern u8 lbl_80539F28[8];
extern const f32 lbl_8053C8B8;
extern const f32 lbl_8053C8C0;
extern const f32 lbl_8053C8DC;
extern const f32 lbl_8053C8E0;
extern const f32 lbl_8053C8E4;
extern const f32 lbl_8053C8E8;
extern const f32 lbl_8053C8EC;
extern const f32 lbl_8053C8F0;
extern const f32 lbl_8053C8D4;
extern const f32 lbl_8053C8D8;
extern const f32 lbl_8053C8BC;
extern u32 lbl_80464C0C[];
extern u32 lbl_80464BE8[];
extern "C" void v03__5ActorFv(void* this_);
extern "C" void detach__5ActorFv(void* this_);
extern "C" void fn_80239914(void* box, u32 a, u32 b);
extern "C" s32 fn_8023AA18(void* box, s32 room, void* vec = 0);
extern "C" s32 fn_8023AB94(void* box, s32 room, void* vec);
extern "C" s32 fn_8023AC74(void* box, s32 room, void* vec);
extern "C" s32 fn_8023AD54(void* box, s32 room, void* vec);
extern "C" s32 fn_8023AE34(void* box, s32 room, void* vec);
extern "C" void fn_802379E4(s32 idx, void* vec);
extern "C" s32 fn_801F285C(void* this_, void* a, void* b, u32 c, s32 d);
extern "C" void fn_801F0E34(void* this_, u32 code, u32 z);
extern "C" void fn_801F0D20(void* this_, s32 p);
extern "C" s32 fn_801F2718(void* this_, u32 code);
extern "C" void* fn_801F856C(void);
extern "C" void Actor_CreateByID(void* mgr, u32 name, u32 room, void* pos, u32 arg, s32 a, s32 b);
extern "C" void fn_801CC820(s32 idx, s32 a);
extern "C" void fn_801CC538(s32 idx, void* a, void* b, s32 c);
extern "C" void fn_801CC640(s32 idx, s32 a, s32 b);
extern "C" void* fn_8013C824(void);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* mgr, void* emitter);
extern "C" void* fn_8020D58C(void);
extern "C" void fn_8020D7D0(void* entry, u32 handle);
extern "C" s32 fn_801CD950(void* value, f32 target, f32 step);
extern "C" s32 fn_8013CC50(u32 room, void* pos, f32 scale, u32 a, u32 b, u32 c, u32 d, u32 e, u32 g);
extern "C" void fn_801D1C18(void* p);
extern "C" void v06__5ActorFv(void* this_);
extern "C" void fn_8011DA20(char* this_) {
    v06__5ActorFv(this_);
    u8 tbl[16];
    s32 i;
    for (i = 0; i < 16; i++) {
        tbl[i] = (u8)i;
    }
}

extern "C" void fn_8011E030(u8* this_) {
    f32 box[4];
    f32 vec[2];
    f32 box2[4];
    f32 vec2[2];
    f32 box3[4];
    f32 vec3[2];
    s32 idx;
    s32 done;
    f32 scale;
    u8* emitter;
    u8* base;

    v03__5ActorFv(this_);
    box[0] = *(f32*)(this_ + 0x60);
    box[1] = *(f32*)(this_ + 0x64);
    box[2] = *(f32*)(this_ + 0x68);
    box[3] = *(f32*)(this_ + 0x6c);
    box[0] += *(f32*)(this_ + 0xc);
    box[2] += *(f32*)(this_ + 0xc);
    box[1] += *(f32*)(this_ + 0x10);
    box[3] += *(f32*)(this_ + 0x10);

    done = 0;
    switch (*(s32*)(this_ + 0x234)) {
    case 0:
        fn_80239914(box, *(s32*)(this_ + 0x4), *(u32*)(this_ + 0x198));
        idx = fn_801F285C(this_, 0, 0, 1, -1);
        if (idx >= 0) {
            fn_801F0E34(this_, 0x400D1, 0);
            vec[0] = *(f32*)(this_ + 0xc);
            vec[1] = *(f32*)(this_ + 0x10);
            fn_802379E4(idx, vec);
            done = 1;
        }
        if (!done) {
            vec2[0] = lbl_8053C8B8;
            vec2[1] = lbl_8053C8B8;
            box2[0] = *(f32*)(this_ + 0x70) + *(f32*)(this_ + 0xc);
            box2[1] = *(f32*)(this_ + 0x74) + (*(f32*)(this_ + 0x10) - *(f32*)(this_ + 0x14));
            box2[2] = *(f32*)(this_ + 0x78) + *(f32*)(this_ + 0xc);
            box2[3] = *(f32*)(this_ + 0x7C) + (*(f32*)(this_ + 0x10) - *(f32*)(this_ + 0x14));
            if (fn_8023AA18(box2, *(s32*)(this_ + 0x4)) >= 0) {
                done = 1;
            } else {
                idx = fn_8023AE34(box2, *(s32*)(this_ + 0x4), vec2);
                if (idx >= 0) {
                    fn_801CC820(idx, 0);
                    done = 1;
                } else {
                    idx = fn_8023AC74(box2, *(s32*)(this_ + 0x4), vec2);
                    if (idx >= 0) {
                        fn_801CC538(idx, vec2, vec3, 0);
                        done = 1;
                    } else {
                        idx = fn_8023AD54(box2, *(s32*)(this_ + 0x4), vec2);
                        if (idx >= 0) {
                            fn_801CC640(idx, 0, 0);
                            done = 1;
                        }
                    }
                }
            }
        }
        if (!done) {
            box3[0] = *(f32*)(this_ + 0x60) + *(f32*)(this_ + 0xc);
            box3[1] = *(f32*)(this_ + 0x64) + *(f32*)(this_ + 0x10);
            box3[2] = *(f32*)(this_ + 0x68) + *(f32*)(this_ + 0xc);
            box3[3] = *(f32*)(this_ + 0x6c) + *(f32*)(this_ + 0x10);
            vec3[0] = lbl_8053C8B8;
            vec3[1] = lbl_8053C8B8;
            if (fn_8023AB94(box3, *(s32*)(this_ + 0x4), vec3) >= 0 || fn_801F2718(this_, 0x46495245) >= 0) {
                if (*(void**)(this_ + 0x100) != 0) {
                    forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((u8*)fn_8013C824() + 0xc), *(void**)(this_ + 0x100));
                    *(void**)(this_ + 0x100) = 0;
                }
                if (*(void**)(this_ + 0x104) != 0) {
                    forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((u8*)fn_8013C824() + 0xc), *(void**)(this_ + 0x104));
                    *(void**)(this_ + 0x104) = 0;
                }
                if (*(s32*)(this_ + 0x4) == 0) {
                    scale = lbl_8053C8BC;
                    if (*(s32*)(this_ + 0x230) == 1) {
                        scale = lbl_8053C8C0;
                    }
                    *(void**)(this_ + 0x27C) = (void*)fn_8013CC50(*(s32*)(this_ + 0x4), this_ + 0xc, scale, 0x28D, 1, 0, 0, 0, 1);
                    fn_8013CC50(*(s32*)(this_ + 0x4), this_ + 0xc, scale, 0x28E, 1, 0, 0, 0, 1);
                    fn_801F0E34(this_, 0x30061, 0);
                    *(s32*)(this_ + 0x234) = 1;
                } else {
                    base = (u8*)fn_8020D58C();
                    fn_8020D7D0(base + 4 + base[0] * 0x784, *(u32*)(this_ + 0x198));
                }
                done = 1;
            }
        }
        break;
    case 1:
        break;
    default:
        return;
    }

    if (!done && fn_801CD950(this_ + 0x240, lbl_8053C8D4, lbl_8053C8D8) == 0) {
        emitter = *(u8**)(this_ + 0x27C);
        if (emitter != 0) {
            *(u32*)(emitter + 0xF4) |= 1;
            *(s32*)(emitter + 0x24) = 1;
        }
        switch (*(s32*)(this_ + 0x238)) {
        case 1:
            fn_801F0D20(this_, 3);
            break;
        case 2:
            fn_801F0D20(this_, 0x42);
            break;
        case 3:
            fn_801F0D20(this_, 6);
            break;
        }
        if (*(s32*)(this_ + 0x23C) != 0) {
            Actor_CreateByID(fn_801F856C(), lbl_80464BE8[*(s32*)(this_ + 0x23C)], *(s32*)(this_ + 0x4), this_ + 0xc, lbl_80464C0C[*(s32*)(this_ + 0x23C)], -1, -1);
            detach__5ActorFv(this_);
            *(s32*)(this_ + 0x234) = 2;
            *(f32*)(this_ + 0x54) = *(f32*)(this_ + 0x240);
            *(f32*)(this_ + 0x58) = *(f32*)(this_ + 0x240);
            *(f32*)(this_ + 0x5C) = *(f32*)(this_ + 0x240);
            fn_801D1C18(this_ + 0x244);
        }
    }
}

extern "C" void fn_8011E4FC(u8* this_) {
    v01__5ActorFv(this_);
    *(s32*)(this_ + 0x230) = *(s32*)(this_ + 0x90) & 0xF;
    *(s32*)(this_ + 0x238) = (*(s32*)(this_ + 0x90) >> 4) & 0xF;
    *(s32*)(this_ + 0x23C) = (*(s32*)(this_ + 0x90) >> 8) & 0xFF;
    switch (*(s32*)(this_ + 0x230)) {
    case 1: {
        f32 f0 = lbl_8053C8C0;
        f32 f1 = lbl_8053C8E4;
        f32 f2 = lbl_8053C8E0;
        f32 f3 = lbl_8053C8DC;
        *(f32*)(this_ + 0x240) = f0;
        f32 f4 = *(f32*)(this_ + 0x240);
        *(f32*)(this_ + 0x54) = f4;
        *(f32*)(this_ + 0x58) = f4;
        *(f32*)(this_ + 0x5C) = f4;
        *(f32*)(this_ + 0x60) = f3;
        *(f32*)(this_ + 0x64) = f3;
        *(f32*)(this_ + 0x68) = f2;
        *(f32*)(this_ + 0x6C) = f2;
        *(f32*)(this_ + 0x80) = f1;
        *(f32*)(this_ + 0x84) = f1;
        f0 = lbl_8053C8E8;
        *(f32*)(this_ + 0x88) = f0;
        *(f32*)(this_ + 0x8C) = f0;
        break;
    }
    case 0:
    default: {
        f32 f0 = lbl_8053C8EC;
        f32 f1 = lbl_8053C8DC;
        f32 f2 = lbl_8053C8F0;
        *(f32*)(this_ + 0x60) = f0;
        *(f32*)(this_ + 0x64) = f0;
        f0 = lbl_8053C8E0;
        *(f32*)(this_ + 0x68) = f2;
        *(f32*)(this_ + 0x6C) = f2;
        *(f32*)(this_ + 0x80) = f1;
        *(f32*)(this_ + 0x84) = f1;
        *(f32*)(this_ + 0x88) = f0;
        *(f32*)(this_ + 0x8C) = f0;
        break;
    }
    }
    *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
    *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
    *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
    *(f32*)(this_ + 0x7C) = *(f32*)(this_ + 0x6C);
    *(s32*)(this_ + 0xB8) = 1;
    *(s32*)(this_ + 0xB0) = 0x06040304;
    *(s32*)(this_ + 0x118) = 0;
    *(s32*)(this_ + 0xBC) = 3;
    fn_801D2608(this_ + 0x244, lbl_80539F28, 1);
    fn_801D22DC(this_ + 0x244, 0, 2, 0);
    fn_801D1F14(this_ + 0x244, lbl_8053C8B8);
}

extern "C" void* fn_8011E650(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_8049DE18;
        fn_801EE434(*(void**)(p + 0x27c));
        *(s32*)(p + 0x27c) = 0;
        if (p + 0x244 != 0) {
            if (p + 0x268 != 0) {
                *(void**)(p + 0x268) = lbl_8049CC34;
            }
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void* fn_8011E6E0(char* p) {
    __ct__5ActorFv(p);
    *(void**)p = lbl_8049DE18;
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x23c) = 0;
    *(f32*)(p + 0x240) = lbl_8053C8BC;
    fn_801D267C(p + 0x244);
    *(s32*)(p + 0x27c) = 0;
    return p;
}

void __sinit_ICWL_8011DA20_cpp(void) {}
#include "JSystem/JAudio/JASFakeMatchFSA.h"
