#include "types.h"
#include "JSystem/JGeometry/Vec.h"
extern "C" void fn_801C8B50(char* this_);
extern "C" void fn_801C3B7C(void* this_, s32 state);
extern "C" u8 fn_800FD4C0(void* ring, u8 a, u8 b);
extern "C" JGeometry::TVec3<f32> fn_800FE294(void* ring, u8 i);
extern "C" void fn_800FD818(void* p, s32 n);
extern "C" void* GetCurrentSlotPtr(void* thisPtr);
extern "C" s32 fn_801CD664(s32 n);

struct TndrG { u8 pad[0x131df]; u8 arr[4]; };
extern "C" TndrG* fn_802D6A9C(void);
extern "C" u32 fn_800FD548(void* ring, u8 i);
extern "C" u8 fn_801CF888(void* this_, void* a, void* b, s32 c);
extern "C" void* GetCurrentSlotPtr(void* thisPtr);
extern "C" f32 lbl_8053EEC8;
extern "C" void fn_800FDE38(void* p);
extern "C" void fn_801C8C84(char* this_, s32 a, s32 b);
extern "C" s16 fn_801D02E0(char* this_, void* p);
extern "C" u8 fn_800FD894(void* ring, s32 id, u8* buf, s32 n);
extern "C" s32 fn_801CD664(s32 n);

extern "C" void fn_801C71BC(char* this_) {
    u8 ids[4];
    u8 b;
    u8 c;
    u32 a;
    u8* s;
    u8 done;
    JGeometry::TVec3<f32> pos;

    *(u32*)(this_ + 0x230) &= 0xffefffff;
    if (!(*(u32*)(this_ + 0x230) & 0x2000000)) {
        done = 0;
        a = ((u8*)GetCurrentSlotPtr(this_ + 0x358))[3];
        fn_800FD818(GetCurrentSlotPtr(this_ + 0x358), 1);
        b = ((u8*)GetCurrentSlotPtr(this_ + 0x358))[3];
        s = (u8*)GetCurrentSlotPtr(this_ + 0x358);
        if (a < s[2]) {
            s[3] = a;
        }
        fn_800FD818(GetCurrentSlotPtr(this_ + 0x358), -1);
        c = ((u8*)GetCurrentSlotPtr(this_ + 0x358))[3];
        s = (u8*)GetCurrentSlotPtr(this_ + 0x358);
        if ((u8)a < s[2]) {
            s[3] = a;
        }
        if (&ids[0] != 0) {
            ids[0] = c;
        }
        if (&ids[1] != 0) {
            ids[1] = a;
        }
        if (&ids[2] != 0) {
            ids[2] = b;
        }
        if (fn_800FD4C0(GetCurrentSlotPtr(this_ + 0x358), ids[1], ids[0]) ||
            fn_800FD4C0(GetCurrentSlotPtr(this_ + 0x358), ids[1], ids[2])) {
            *(s32*)(this_ + 0x2a8) = 0;
            *(u32*)(this_ + 0x230) &= 0xfffdefff;
            *(u32*)(this_ + 0x230) |= 0x400000;
            pos = fn_800FE294(GetCurrentSlotPtr(this_ + 0x358), 0xff);
            *(f32*)(this_ + 0x32c) = pos.x;
            *(f32*)(this_ + 0x330) = pos.y;
            *(f32*)(this_ + 0x334) = pos.z;
            done = 1;
        }
        if (done) {
            return;
        }
    }
    fn_801C8B50(this_);
    *(s16*)(this_ + 0x33c) += fn_801CD664(0x4001) - 0x2000;
    if (!(*(u32*)(this_ + 0x524) & 0x40)) {
        fn_801C3B7C(this_, 0x1c);
    }
}

extern "C" void fn_801C7EE4(char* this_) {
    TndrG* g;
    s32 id;
    if (*(u32*)(this_ + 0x230) & 0x2000000) {
        return;
    }
    if (!(u8)fn_800FD548(GetCurrentSlotPtr(this_ + 0x358), 0xff)) {
        return;
    }
    id = *(s32*)(this_ + 0x4);
    g = fn_802D6A9C();
    if (!(g->arr[id] != 0 && __fabsf(*(f32*)(this_ + 0x10) - *(f32*)(this_ + 0x330)) > lbl_8053EEC8) && !fn_801CF888(this_, this_ + 0xc, this_ + 0x32c, *(s32*)(this_ + 0x4))) {
        return;
    }
    *(u32*)(this_ + 0x230) |= 0x400000;
}

extern "C" void fn_801C8B50(char* this_) {
    *(s32*)(this_ + 0x2a8) = 0;
    *(u32*)(this_ + 0x230) &= 0xffffefff;
    fn_800FDE38(GetCurrentSlotPtr(this_ + 0x358));
    fn_801C8C84(this_, 0, 0);
    *(s16*)(this_ + 0x33c) = fn_801D02E0(this_, this_ + 0x32c);
    *(u32*)(this_ + 0x230) &= 0xfffdffff;
}

extern "C" void fn_801C8BC4(char* this_, u8 param_2) {
    u8 buf[0x30];
    void* p;
    s32 r;
    u8 t;
    if (param_2) {
        p = GetCurrentSlotPtr(this_ + 0x358);
        r = fn_800FD894(p, *(s32*)(this_ + 0x4), buf, 0x30);
        if (r <= 3) {
            *(u8*)(this_ + 0x55d) = 1;
        } else {
            *(u8*)(this_ + 0x55d) = fn_801CD664(4) + 1;
            if (*(u32*)(this_ + 0x524) & 0x100) {
                *(u8*)(this_ + 0x55d) += 1;
            }
            t = r - 2;
            if (t >= *(u8*)(this_ + 0x55d)) {
                t = *(u8*)(this_ + 0x55d);
            }
            *(u8*)(this_ + 0x55d) = t;
        }
    } else {
        *(u8*)(this_ + 0x55d) = fn_801CD664(0xc) + 1;
    }
}

extern "C" void* lbl_8053AAF8;
extern "C" f32 lbl_8053EED8;
extern "C" void fn_800FD818(void* p, s32 n);
extern "C" s32 fn_800FE25C(void* p, u8 n);
extern "C" u8 fn_801C976C(char* this_) {
    u8 pair[2];
    u8 a = ((u8*)GetCurrentSlotPtr(this_ + 0x358))[3];
    fn_800FD818(GetCurrentSlotPtr(this_ + 0x358), 1);
    u8 b = ((u8*)GetCurrentSlotPtr(this_ + 0x358))[3];
    u8* s = (u8*)GetCurrentSlotPtr(this_ + 0x358);
    if (a < s[2]) {
        s[3] = a;
    }
    fn_800FD818(GetCurrentSlotPtr(this_ + 0x358), -1);
    u8 c = ((u8*)GetCurrentSlotPtr(this_ + 0x358))[3];
    s = (u8*)GetCurrentSlotPtr(this_ + 0x358);
    u32 ia = a;
    if ((u8)ia < s[2]) {
        s[3] = a;
    }
    u8* pc = &pair[1];
    if (pc != 0) {
        *pc = c;
    }
    u8* pb = &pair[0];
    if (pb != 0) {
        *pb = b;
    }
    f32 one = lbl_8053EEC8;
    f32 thr = lbl_8053EED8;
    u32* seed = (u32*)((u8*)lbl_8053AAF8 + 0xb4);
    *seed = *seed * 0x19660d + 0x3c6ef35f;
    u32 bits = (*seed >> 9) | 0x3f800000;
    f32 r = *(f32*)&bits;
    r = r - one;
    u8 x;
    if (r < thr) {
        x = pair[0];
        s32 cur = *(s32*)(this_ + 4);
        if (cur != fn_800FE25C(GetCurrentSlotPtr(this_ + 0x358), x)) {
            x = pair[1];
        }
    } else {
        x = pair[1];
        s32 cur = *(s32*)(this_ + 4);
        if (cur != fn_800FE25C(GetCurrentSlotPtr(this_ + 0x358), x)) {
            x = pair[0];
        }
    }
    return x;
}

