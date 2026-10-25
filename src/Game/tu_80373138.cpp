#include "Game/SinitPoolChain.h"
#include "JSystem/JGeometry/Vec.h"
#define Vec ActorVec
#include "Game/Actor.h"
#include "Game/SinitPoolChain.h"


extern "C" char lbl_804AE574[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" f32 lbl_80542E54;
extern "C" s32 lbl_80475024[];
extern "C" u8 fn_8023077C(void);
extern "C" u8 fn_80230534(s32 i);
extern "C" Vec* fn_8023E724(s32 i);
extern "C" void fn_80230498(s32 i, Vec* pos, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_80230FD0(s32 i, s32 id);
extern "C" Actor* fn_80373138(Actor* this_, s16 del) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AE574;
        __dt__5ActorFv(this_, 0);
        if (del > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_80373198(Actor* this_) {
    u8* p = (u8*)this_;
    s32 i;
    Vec v;
    Vec off;
    s32 state = *(s32*)(p + 0x24c);
    if (state < 0) {
        return;
    }
    if (state < 4) {
        if (!fn_8023077C()) {
            return;
        }
        *(s32*)(p + 0x24c) = 4;
        *(s32*)(p + 0x248) = 0x32;
        *(s32*)(p + 0x250) = 0;
        off.x = 0.0f;
        off.y = lbl_80542E54;
        off.z = 0.0f;
        for (i = 0; i < 4; i++) {
            Vec* src = fn_8023E724(i);
            v.x = src->x + off.x;
            v.y = src->y + off.y;
            v.z = src->z + off.z;
            fn_80230498(i, &v, 0x2e2, 0xff, -0x80, -0x80, 1);
        }
        return;
    }
    if (*(s32*)(p + 0x250) == 0 && *(s32*)(p + 0x248) > 0x1e) {
        for (i = 0; i < 4; i++) {
            Vec* src = fn_8023E724(i);
            v = *src;
            fn_80230498(i, &v, 0x2e2, 0xff, -0x80, -0x80, 1);
        }
        return;
    }
    if (*(s32*)(p + 0x250) >= 0xd) {
        if (*(s32*)(p + 0x248) == 0) {
            if (fn_80230534(0)) {
                *(s32*)(p + 0x24c) = -1;
            }
        } else if (*(s32*)(p + 0x248) == 0xf) {
            ((void (*)(Actor*, s32, s32))(*(void***)this_)[12])(this_, 0xff, 1);
        }
        return;
    }
    if (*(s32*)(p + 0x248) != 0) {
        return;
    }
    *(s32*)(p + 0x250) += 1;
    *(s32*)(p + 0x248) = lbl_80475024[*(s32*)(p + 0x250)];
    for (i = 0; i < 4; i++) {
        Vec* src = fn_8023E724(i);
        v = *src;
        fn_80230498(i, &v, *(s32*)(p + 0x250) + 0xdb, 0xff, -0x80, -0x80, 1);
        if (*(s32*)(p + 0x250) == 1) {
            fn_80230FD0(i, 0x10001);
        }
    }
    if (*(s32*)(p + 0x250) == 0xd) {
        *(s32*)(p + 0x248) = 0x19;
    }
}

extern "C" char lbl_804AE560[];
extern "C" u8* lbl_8053AAF8;
extern "C" u8* lbl_8053AB10;
extern "C" void fn_802F745C(u8*, u8*, u32, s32);
extern "C" void fn_80373434(u8* this_) {
    u8* obj = *(u8**)(lbl_8053AAF8 + 0xa4);
    u32* vtbl = *(u32**)obj;
    u32 val = ((u32*)lbl_804AE560)[*(s32*)(this_ + 0x23c)];
    u32 r = ((u32 (*)(u8*, u32, u32))vtbl[6])(obj, 0x54494d47, val);
    if (*(s32*)(this_ + 4) < 8) {
        fn_802F745C(*(u8**)(lbl_8053AB10 + 0x20), this_ + 0xc, r, 0);
    }
}

extern "C" s32 fn_80239470(f32* box, s32 room, s32 handle);
extern "C" s32 fn_80238A68(s32 handle);
extern "C" void fn_80239914(f32* box, s32 room, s32 handle);
extern "C" void fn_801F0E34(Actor* this_, s32 id, s32 arg);
extern "C" f32 lbl_80474F98[];
extern "C" void fn_803734B4(Actor* this_) {
    u8* p = (u8*)this_;
    f32 box[4];
    Vec v;
    s32 state;
    s32 cnt = 0;
    s32 i;
    f32 t;

    *(f32*)(p + 0x3c) = 0.0f;
    *(f32*)(p + 0x40) = 0.0f;
    *(f32*)(p + 0x44) = 0.0f;
    state = *(s32*)(p + 0x248);
    if (state > 0) {
        *(s32*)(p + 0x248) = state - 1;
        fn_80373198(this_);
    }
    box[0] = -32.0f;
    box[1] = -8.0f;
    box[2] = 32.0f;
    box[3] = 8.0f;
    box[0] += *(f32*)(p + 0xc);
    box[2] += *(f32*)(p + 0xc);
    box[1] += *(f32*)(p + 0x10);
    box[3] += *(f32*)(p + 0x10);
    if (fn_80239470(box, *(s32*)(p + 4), *(s32*)(p + 0x198)) >= 0) {
        cnt = fn_80238A68(*(s32*)(p + 0x198));
        if (cnt > 4) {
            cnt = 4;
            if (*(f32*)(p + 0x244) >= 3.0f) {
                box[0] = *(f32*)(p + 0x60);
                box[1] = *(f32*)(p + 0x64);
                box[2] = *(f32*)(p + 0x68);
                box[3] = *(f32*)(p + 0x6c);
            } else {
                box[0] = *(f32*)(p + 0x70);
                box[1] = *(f32*)(p + 0x74);
                box[2] = *(f32*)(p + 0x78);
                box[3] = *(f32*)(p + 0x7c);
            }
            box[0] += *(f32*)(p + 0xc);
            box[2] += *(f32*)(p + 0xc);
            box[1] += *(f32*)(p + 0x10);
            box[3] += *(f32*)(p + 0x10);
            box[0] += 0.0f;
            box[2] += 0.0f;
            box[1] += lbl_80474F98[*(s32*)(p + 0x23c)];
            box[3] += lbl_80474F98[*(s32*)(p + 0x23c)];
            if (cnt == 4) {
                fn_80239914(box, *(s32*)(p + 4), *(s32*)(p + 0x198));
                if (*(u8*)(p + 0x240) != 0) {
                    *(f32*)(p + 0x244) = 14.0f;
                } else {
                    t = *(f32*)(p + 0x244);
                    if (t >= 11.0f) {
                        t = t + 0.05f;
                        *(f32*)(p + 0x244) = t;
                        if (*(f32*)(p + 0x244) >= 14.0f) {
                            *(f32*)(p + 0x244) = 14.0f;
                            if (*(u8*)(p + 0x254) == 0) {
                                *(u8*)(p + 0x240) = 1;
                                fn_801F0E34(this_, 0x3004b, 0);
                                *(u8*)(p + 0x254) = 1;
                                if (fn_8023077C()) {
                                    *(s32*)(p + 0x248) = 0x32;
                                    *(s32*)(p + 0x24c) = 4;
                                    *(s32*)(p + 0x250) = 0;
                                    for (i = 0; i < 4; i++) {
                                        Vec* src = fn_8023E724(i);
                                        v.x = src->x + 0.0f;
                                        v.y = src->y + 7.0f;
                                        v.z = src->z + 0.0f;
                                        fn_80230498(i, &v, 0x2e2, 0xff, -0x80, -0x80, 1);
                                    }
                                } else {
                                    *(s32*)(p + 0x24c) = 0;
                                }
                            }
                        }
                    } else {
                        if (t <= 0.0f) {
                            *(f32*)(p + 0x230) = *(f32*)(p + 0xc);
                            *(f32*)(p + 0x234) = *(f32*)(p + 0x10);
                            *(f32*)(p + 0x238) = *(f32*)(p + 0x14);
                            *(f32*)(p + 0x234) = *(f32*)(p + 0x234) + 16.0f;
                            if (*(f32*)(p + 0x244) < 3.0f) {
                                *(f32*)(p + 0x244) = *(f32*)(p + 0x244) + 0.05f;
                            } else {
                                *(f32*)(p + 0x244) = *(f32*)(p + 0x244) + 0.125f;
                            }
                        } else {
                            if (*(u8*)(p + 0x240) != 0) {
                                *(f32*)(p + 0x244) = 14.0f;
                            } else {
                                f32 old = t;
                                *(f32*)(p + 0x244) = *(f32*)(p + 0x244) - 0.25f;
                                if (*(f32*)(p + 0x244) < old) {
                                    *(f32*)(p + 0x244) = old;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    t = *(f32*)(p + 0x244);
    if (t < 3.0f) {
        *(s32*)(p + 0x23c) = 0;
    } else if (t < 8.0f) {
        *(s32*)(p + 0x23c) = 1;
    } else if (t < 11.0f) {
        *(s32*)(p + 0x23c) = 2;
    } else if (t < 14.0f) {
        *(s32*)(p + 0x23c) = 3;
    } else {
        *(s32*)(p + 0x23c) = 4;
    }
}

extern "C" f32 lbl_80542E50;
extern "C" f32 lbl_80542E58;
extern "C" f32 lbl_80542E5C;
extern "C" f32 lbl_80542E60;
extern "C" f32 lbl_80542E64;
extern "C" f32 lbl_80542E6C;
extern "C" f32 lbl_80542E84;
extern "C" void fn_803738DC(Actor* this_) {
    f32 a = lbl_80542E58;
    f32 b = lbl_80542E5C;
    f32 c = lbl_80542E60;
    this_->field_60 = a;
    this_->field_64 = b;
    this_->field_68 = c;
    this_->field_6C = lbl_80542E64;
    this_->field_70.x = a;
    this_->field_70.y = b;
    this_->field_70.z = c;
    this_->field_7C.x = lbl_80542E84;
    f32 z = lbl_80542E50;
    this_->field_7C.y = z;
    this_->field_7C.z = z;
    this_->field_88 = z;
    this_->field_8C = z;
    this_->field_108 = 0;
    *(s32*)((u8*)this_ + 0x23c) = 0;
    *(u8*)((u8*)this_ + 0x240) = *(u8*)((u8*)this_ + 0x254) = this_->v11();
    if (*(u8*)((u8*)this_ + 0x240)) {
        *(f32*)((u8*)this_ + 0x244) = lbl_80542E6C;
    } else {
        *(f32*)((u8*)this_ + 0x244) = lbl_80542E50;
    }
    this_->field_3C.x = lbl_80542E50;
    this_->field_3C.y = lbl_80542E50;
    this_->field_3C.z = lbl_80542E50;
    *(s32*)((u8*)this_ + 0x248) = 0;
    *(s32*)((u8*)this_ + 0x24c) = -1;
    *(s32*)((u8*)this_ + 0x250) = 0;
}

