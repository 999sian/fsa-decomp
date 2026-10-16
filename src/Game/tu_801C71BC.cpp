#include "types.h"

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

extern "C" void fn_801C7EE4(char* this_) {
    f32 d;
    s32 id;
    TndrG* g;
    if (*(u32*)(this_ + 0x230) & 0x2000000) {
        return;
    }
    if (!fn_800FD548(GetCurrentSlotPtr(this_ + 0x358), 0xff)) {
        return;
    }
    id = *(s32*)(this_ + 0x4);
    g = fn_802D6A9C();
    d = *(f32*)(this_ + 0x10) - *(f32*)(this_ + 0x330);
    if (g->arr[id] == 0 || __fabsf(d) <= lbl_8053EEC8) {
        if (!fn_801CF888(this_, this_ + 0xc, this_ + 0x32c, *(s32*)(this_ + 0x4))) {
            return;
        }
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

