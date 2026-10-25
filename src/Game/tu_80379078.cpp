#include "types.h"
#include "Game/Actor.h"


struct LimtDrawParam {
    LimtDrawParam() : m40(-1), m44(-1) {
        for (u8 i = 0; i < 16; i++) {
            mIdx[i] = i;
        }
    }
    void reset() {
        m40 = -1;
        m44 = 0;
        mMtx = 0;
        m4C = 0;
        m4D = 0;
        m4E = 0;
        m4F = 1;
        m50 = 1;
        m51 = 0;
        m52 = 0;
        m53 = 0;
        m54 = 0;
        m55 = 0;
        m56 = 1;
        m58 = 3;
        m5C = 1;
        m5D = 0;
        m5E = 0;
        m60 = -1;
        m64 = 0;
        m68 = 2;
    }
    u8 mIdx[16];
    s32 m40;
    s32 m44;
    f32 (*mMtx)[4];
    u8 m4C, m4D, m4E, m4F, m50, m51, m52, m53, m54, m55, m56;
    s32 m58;
    u8 m5C, m5D, m5E;
    s32 m60;
    s32 m64;
    s32 m68;
};

extern "C" char lbl_804AE8F4[];
extern "C" void __dt__5ActorFv(void* p, int flag);
extern "C" void __dl__FPv(void*);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D7584(void* p, s32 room, s32 v);
extern "C" void fn_80239914(void* box, s32 room, s32 handle);
extern "C" void* fn_8020D58C(void);
extern "C" void fn_8020D7D0(void* p, s32 handle);
extern "C" s32 fn_80239108(s32 handle);
extern "C" s32 fn_80238BC4(s32 handle);
extern "C" void fn_80238E08(s32 handle);
extern "C" void fn_801F0E34(u8* this_, s32 a, s32 b);
extern f32 lbl_80475248[];
extern u8 lbl_804751F8[];
extern f32 lbl_80543014;
extern f32 lbl_8054301C;
extern f32 lbl_80543020;
extern f32 lbl_80543024;
extern "C" void* fn_80379078(void* param_1, short param_2) {
    if (param_1 != 0) {
        *(void**)param_1 = lbl_804AE8F4;
        __dt__5ActorFv(param_1, 0);
        if (param_2 > 0) {
            __dl__FPv(param_1);
        }
    }
    return param_1;
}

extern "C" u32 fn_804032E8(u32 tag, const char* name);
extern "C" void fn_802F745C(void* mgr, void* pos, void* tex, LimtDrawParam* prm);
extern "C" u8* lbl_8053AB10;
extern "C" const char* lbl_804AE8E0[];
extern "C" f32 __float_epsilon;
extern "C" void fn_803790D8(u8* this_) {
    LimtDrawParam prm;
    prm.reset();
    Vec* v = (Vec*)(this_ + 0x54);
    f32 lenSq = v->x * v->x + v->y * v->y + v->z * v->z;
    if (lenSq > 32.0f * __float_epsilon) {
        f32 mtx[3][4];
        mtx[0][3] = 0.0f;
        mtx[1][3] = 0.0f;
        mtx[2][3] = 0.0f;
        mtx[0][0] = v->x;
        mtx[0][1] = 0.0f;
        mtx[0][2] = 0.0f;
        mtx[1][0] = 0.0f;
        mtx[1][1] = v->y;
        mtx[1][2] = 0.0f;
        mtx[2][0] = 0.0f;
        mtx[2][1] = 0.0f;
        mtx[2][2] = v->z;
        prm.mMtx = mtx;
    }
    Vec pos;
    Vec* a = (Vec*)(this_ + 0xc);
    pos.x = a->x + 8.0f;
    pos.y = a->y;
    pos.z = a->z;
    u32 tex = fn_804032E8(0x54494D47, lbl_804AE8E0[this_[0x241]]);
    if (*(s32*)(this_ + 4) < 8) {
        fn_802F745C(*(void**)(lbl_8053AB10 + 0x20), &pos, (void*)tex, &prm);
    }
}

extern "C" void fn_803792C8(u8* this_) {
    f32 box[4];
    box[0] = *(f32*)(this_ + 0x60);
    box[1] = *(f32*)(this_ + 0x64);
    box[2] = *(f32*)(this_ + 0x68);
    box[3] = *(f32*)(this_ + 0x6c);
    box[0] += *(f32*)(this_ + 0xc);
    box[2] += *(f32*)(this_ + 0xc);
    box[1] += *(f32*)(this_ + 0x10);
    box[3] += *(f32*)(this_ + 0x10);
    fn_80239914(box, *(s32*)(this_ + 0x4), *(s32*)(this_ + 0x198));
    {
        s32 h = *(s32*)(this_ + 0x198);
        u8* p = (u8*)fn_8020D58C();
        fn_8020D7D0(p + p[0] * 0x784 + 4, h);
    }
    switch (*(s32*)(this_ + 0x23c)) {
    case 0: {
        s32 cur = 0;
        if (fn_80239108(*(s32*)(this_ + 0x198)) >= 1 && *(u8*)(this_ + 0x240) == (cur = fn_80238BC4(*(s32*)(this_ + 0x198))) && cur >= 0 && cur < 4) {
            *(u8*)(this_ + 0x242) += 1;
            if (*(u8*)(this_ + 0x242) >= 0x14) {
                if (!((*(u32*)(this_ + 0x90) >> 4) & 1)) {
                    fn_802D7584(fn_802D6A9C(), *(s32*)(this_ + 0x16c), (u8)(cur + 1));
                }
                fn_80238E08(*(s32*)(this_ + 0x198));
                *(u8*)(this_ + 0x243) += 1;
                if (lbl_80475248[*(u8*)(this_ + 0x241)] < (f32)*(u8*)(this_ + 0x243)) {
                    *(u8*)(this_ + 0x241) += 1;
                    fn_801F0E34(this_, 0x3004b, 0);
                }
                s32 n = (u32)*(u8*)(this_ + 0x243) >> 2;
                f32 t = (f32)n;
                *(f32*)(this_ + 0x60) = lbl_80543020;
                *(f32*)(this_ + 0x64) = lbl_80543020;
                *(f32*)(this_ + 0x68) = lbl_8054301C - t;
                *(f32*)(this_ + 0x6c) = lbl_80543024;
                if (*(u8*)(this_ + 0x241) == 3) {
                    *(f32*)(this_ + 0x60) = lbl_80543020;
                    *(f32*)(this_ + 0x64) = lbl_80543020;
                    *(f32*)(this_ + 0x68) = lbl_80543014;
                    *(f32*)(this_ + 0x6c) = lbl_80543024;
                    ((void (*)(u8*, s32, s32))(*(void***)this_)[12])(this_, 0xff, 1);
                    *(s32*)(this_ + 0x23c) = 2;
                }
            }
        } else {
            *(u8*)(this_ + 0x242) = 0;
        }
        break;
    }
    case 1:
        *(u8*)(this_ + 0x241) += 1;
        *(u8*)(this_ + 0x242) = 0;
        {
            u8* e = lbl_804751F8 + *(u8*)(this_ + 0x241) * 0x10;
            *(f32*)(this_ + 0x60) = *(f32*)(e + 0);
            *(f32*)(this_ + 0x64) = *(f32*)(e + 4);
            *(f32*)(this_ + 0x68) = *(f32*)(e + 8);
            *(f32*)(this_ + 0x6c) = *(f32*)(e + 0xc);
        }
        if (*(u8*)(this_ + 0x241) == 4) {
            ((void (*)(u8*, s32, s32))(*(void***)this_)[12])(this_, 0xff, 1);
            *(s32*)(this_ + 0x23c) = 2;
        } else {
            *(s32*)(this_ + 0x23c) = 0;
        }
        break;
    }
}

extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D7544(void*, s32);
extern "C" void fn_80379584(Actor* param_1) {
    param_1->field_60 = lbl_80543020;
    param_1->field_64 = lbl_80543020;
    param_1->field_68 = lbl_8054301C;
    param_1->field_6C = lbl_80543024;
    *(u8*)((u8*)param_1 + 0x240) = 1;
    *(u32*)((u8*)param_1 + 0x23C) = 0;
    *(u8*)((u8*)param_1 + 0x243) = 0;
    *(u8*)((u8*)param_1 + 0x242) = 0;
    *(u8*)((u8*)param_1 + 0x241) = 0;
    if (!(((u32)param_1->field_90 >> 4) & 1)) {
        void* uVar4 = fn_802D6A9C();
        u8 cVar5 = fn_802D7544(uVar4, param_1->field_16C);
        if (cVar5 != 0) {
            *(u8*)((u8*)param_1 + 0x241) = 3;
            param_1->field_60 = lbl_80543020;
            param_1->field_64 = lbl_80543020;
            param_1->field_68 = lbl_80543014;
            param_1->field_6C = lbl_80543024;
            ((void (*)(Actor*, s32, s32))(*(void***)param_1)[12])(param_1, 0xff, 1);
            *(u32*)((u8*)param_1 + 0x23C) = 2;
        }
    }
}

