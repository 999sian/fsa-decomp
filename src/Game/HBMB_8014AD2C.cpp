#include "types.h"
#include <math.h>

extern "C" u16 fn_8022461C(s32 a, s32 b);
extern "C" u16 fn_80226850(s32 a, s32 b);
extern "C" void* fn_802D6A9C(void);

static inline f64 sqrtStep(f64 tmpd, f32 mag) {
    return tmpd * 0.5 * (3.0 - mag * (tmpd * tmpd));
}
static inline f32 dolsqrtfull(f32 mag) {
    if (mag > 0.0f) {
        f64 tmpd = __frsqrte(mag);
        tmpd = sqrtStep(tmpd, mag);
        tmpd = sqrtStep(tmpd, mag);
        tmpd = sqrtStep(tmpd, mag);
        return mag * tmpd;
    } else if (mag < 0.0) {
        return NAN;
    } else if (fpclassify(mag) == 1) {
        return NAN;
    } else {
        return mag;
    }
}

extern "C" s32 fn_801F7818(void* mgr, u32 name, u32 id, void* list, s32 max);
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 id, f32* pos, u32 arg5, s32 arg6, s32 arg7);

extern "C" char lbl_8049F784[];
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* p);
extern "C" void fn_801EE434(void* p);
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* a, s32 b);
extern "C" void fn_8013CB44(void* a, void* b, s32 c, s32 d, s32 e);
extern "C" void* fn_8014CF28(u32* this_, s16 freeFlag) {
    if (this_ != 0) {
        u32* p = this_;
        s32 i = 0;
        *(char**)this_ = lbl_8049F784;
        do {
            fn_801EE434((void*)p[0xa4]);
            i++;
            p++;
        } while (i < 3);
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_8014D304(u8* this_) {
    struct VObj {
        virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
        virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
        virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
        virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20(); virtual void v21();
    };
    ((VObj*)this_)->v19();
}

extern "C" u16 fn_802265FC(f32* pos, s32 room);
extern "C" u8 fn_802DE9A0(void);
extern "C" u8 fn_802DEB58(void);
extern "C" f32 lbl_8053D128;
extern "C" f32 lbl_8053D12C;
extern "C" f32 lbl_8053D160;
extern "C" f32 lbl_8053D178;
extern "C" f32 lbl_8053D198;
extern "C" BOOL fn_8014D6DC(u8* this_) {
    f32 pos[2];
    f32 x;
    f32 y;
    f32 minX;
    f32 maxX;
    f32 minY;
    f32 maxY;

    if (*(f32*)(this_ + 0x14) > 0.1f) {
        return 0;
    }
    x = *(f32*)(this_ + 0xc);
    y = *(f32*)(this_ + 0x10);
    minX = x + -3.0f;
    maxX = x + 3.0f;
    minY = y + -3.0f;
    maxY = y + 3.0f;
    pos[0] = maxX + 0.5f * (minX - maxX);
    pos[1] = maxY + 0.5f * (minY - maxY);
    u16 kind = fn_802265FC(pos, *(s32*)(this_ + 4));
    if (kind == 3) {
        *(f32*)(this_ + 0x284) = *(f32*)(this_ + 0xc);
        *(f32*)(this_ + 0x288) = *(f32*)(this_ + 0x10);
        *(f32*)(this_ + 0x28c) = *(f32*)(this_ + 0x14);
        *(f32*)(this_ + 0x44) = 0.0f;
        *(f32*)(this_ + 0x40) = 0.0f;
        *(f32*)(this_ + 0x3c) = 0.0f;
        *(s32*)(this_ + 0x230) = 6;
        return 1;
    } else if (kind == 0xe) {
        *(f32*)(this_ + 0x284) = *(f32*)(this_ + 0xc);
        *(f32*)(this_ + 0x288) = *(f32*)(this_ + 0x10);
        *(f32*)(this_ + 0x28c) = *(f32*)(this_ + 0x14);
        *(f32*)(this_ + 0x44) = 0.0f;
        *(f32*)(this_ + 0x40) = 0.0f;
        *(f32*)(this_ + 0x3c) = 0.0f;
        if (fn_802DE9A0() == 1 || fn_802DEB58() == 1) {
            *(s32*)(this_ + 0x230) = 8;
        } else {
            *(s32*)(this_ + 0x230) = 6;
        }
        return 1;
    } else if (kind == 0xd || kind == 0x3b) {
        *(f32*)(this_ + 0x284) = *(f32*)(this_ + 0xc);
        *(f32*)(this_ + 0x288) = *(f32*)(this_ + 0x10);
        *(f32*)(this_ + 0x28c) = *(f32*)(this_ + 0x14);
        *(f32*)(this_ + 0x44) = 0.0f;
        *(f32*)(this_ + 0x40) = 0.0f;
        *(f32*)(this_ + 0x3c) = 0.0f;
        *(s32*)(this_ + 0x230) = 7;
        return 1;
    }
    return 0;
}

extern "C" void fn_8014D868(u8* this_, f32* pos) {
    s32 list[1024];
    s32 count = fn_801F7818(fn_801F856C(), 0x57415250, *(u32*)(this_ + 4), list, -1);
    for (s32 i = 0; i < count; i++) {
        u8* p = (u8*)list[i];
        if (p != 0) {
            f32 dx = *(f32*)(p + 0xc) - pos[0];
            f32 dz = *(f32*)(p + 0x10) - pos[1];
            f32 dist = dolsqrtfull(dx * dx + dz * dz);
            if (dist < 24.0f) {
                u32 type = (*(u32*)(p + 0x90) >> 24) & 7;
                f32* q = (f32*)(p + 0x238);
                s32 id = type + 7;
                if (type == 0) {
                    id = type;
                }
                Actor_CreateByID(fn_801F856C(), 0x48424d42, id, q, 0xc, -1, -1);
            }
        }
    }
}

extern "C" void fn_8014DA20(u8* this_) {
    s32 idx = *(s32*)(this_ + 0xa0);
    if (idx >= 0) {
        void* p = fn_801F666C(fn_801F856C(), idx);
        if (p != 0 && *(u32*)((u8*)p + 0x1a0) == 0x41525257) {
            fn_8013CB44(*(void**)(this_ + 0x294), this_ + 0xc, 0, 0, 0);
            fn_8013CB44(*(void**)(this_ + 0x298), this_ + 0xc, 0, 0, 0);
        }
    }
}

