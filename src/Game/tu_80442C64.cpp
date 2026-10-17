#include "types.h"
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" u8 fn_802308E0(s32 p);
extern void* lbl_804B1A48[];
extern void* lbl_8053AD30;
extern u8* lbl_8053AED0;
struct Tu80442Vec3 { f32 x; f32 y; f32 z; };
extern "C" s32 fn_8030AAF4(s32 i);
extern "C" u32 fn_80309D24(void* p, s32 i, u32 mask);
extern "C" u32 fn_80309D6C(void* p, s32 i, u32 mask);
extern "C" void fn_8023061C(s32 p, s32 a);
extern "C" void fn_8022FE80(s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" s32 fn_8022FD8C(s32 a);
extern "C" u8 fn_80388CAC(s32 a, s32 b);
extern "C" u8 fn_8038C678(s32 a, s32 b, s32 c, s32 d, void* e, s32 f);
extern "C" void* fn_80442C64(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804B1A48;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" void fn_80442CC4(void* this_) {
    s32 state = *(s32*)((u8*)this_ + 0x230);
    u32 room = *(u32*)((u8*)this_ + 0x90) >> 28;
    switch (state) {
    case 0:
        if (fn_80309D24(lbl_8053AD30, fn_8030AAF4(room), 0x400) != 0) {
            if (fn_80309D6C(lbl_8053AD30, fn_8030AAF4(room), 0x100) != 0) {
                lbl_8053AED0[room + 0x1f0] = 2;
                fn_8023061C(room, 0);
                *(u8*)((u8*)this_ + 0x11c) = 0;
                return;
            }
        }
        if (fn_80309D24(lbl_8053AD30, fn_8030AAF4(room), 0x100) != 0) {
            if (fn_80309D24(lbl_8053AD30, fn_8030AAF4(room), 0x200) != 0) {
                if (fn_80309D6C(lbl_8053AD30, fn_8030AAF4(room), 0x2) != 0) {
                    *(s32*)((u8*)this_ + 0x234) += 0x64;
                } else if (fn_80309D6C(lbl_8053AD30, fn_8030AAF4(room), 0x1) != 0) {
                    if (*(u32*)((u8*)this_ + 0x234) <= 0x64) {
                        *(s32*)((u8*)this_ + 0x234) = 1;
                    } else {
                        *(s32*)((u8*)this_ + 0x234) -= 0x64;
                    }
                }
            } else {
                if (fn_80309D6C(lbl_8053AD30, fn_8030AAF4(room), 0x2) != 0) {
                    *(s32*)((u8*)this_ + 0x234) += 0xa;
                } else if (fn_80309D6C(lbl_8053AD30, fn_8030AAF4(room), 0x1) != 0) {
                    if (*(u32*)((u8*)this_ + 0x234) <= 0xa) {
                        *(s32*)((u8*)this_ + 0x234) = 1;
                    } else {
                        *(s32*)((u8*)this_ + 0x234) -= 0xa;
                    }
                }
            }
        } else {
            if (fn_80309D6C(lbl_8053AD30, fn_8030AAF4(room), 0x2) != 0) {
                *(s32*)((u8*)this_ + 0x234) += 1;
            } else if (fn_80309D6C(lbl_8053AD30, fn_8030AAF4(room), 0x1) != 0) {
                if (*(u32*)((u8*)this_ + 0x234) <= 1) {
                    *(s32*)((u8*)this_ + 0x234) = 1;
                } else {
                    *(s32*)((u8*)this_ + 0x234) -= 1;
                }
            }
        }
        if (fn_80309D24(lbl_8053AD30, fn_8030AAF4(room), 0x20) != 0) {
            if (fn_80309D24(lbl_8053AD30, fn_8030AAF4(room), 0x20) != 0) {
                if (fn_80309D6C(lbl_8053AD30, fn_8030AAF4(room), 0x100) != 0) {
                    *(s32*)((u8*)this_ + 0x230) = 1;
                    fn_8023061C(room, 0);
                }
            }
        }
        break;
    case 1:
        fn_8022FE80(room, *(s32*)((u8*)this_ + 4), *(s32*)((u8*)this_ + 0x198), 0, 0);
        if (fn_8022FD8C(*(s32*)((u8*)this_ + 0x198)) == room) {
            Tu80442Vec3 pos = *(Tu80442Vec3*)((u8*)this_ + 0xc);
            if (fn_8038C678(room, *(s32*)((u8*)this_ + 0x234), *(s32*)((u8*)this_ + 0x198), *(s32*)((u8*)this_ + 4), &pos, 0x10)) {
                *(s32*)((u8*)this_ + 0x230) = 2;
            } else {
                lbl_8053AED0[room + 0x1f0] = 2;
                *(u8*)((u8*)this_ + 0x11c) = 0;
            }
        }
        break;
    case 2:
        fn_8022FE80(room, *(s32*)((u8*)this_ + 4), *(s32*)((u8*)this_ + 0x198), 0, 0);
        if (fn_80388CAC(room, *(s32*)((u8*)this_ + 0x198))) {
            lbl_8053AED0[room + 0x1f0] = 2;
            *(u8*)((u8*)this_ + 0x11c) = 0;
        }
        break;
    }
}

extern "C" void fn_80443064(void* this_)
{
    if (fn_802308E0(*(u32*)((u8*)this_ + 0x90) >> 28) == 0) {
        *((u8*)this_ + 0x11c) = 0;
    }
    *(s32*)((u8*)this_ + 0x230) = 0;
    *(s32*)((u8*)this_ + 0x234) = 1;
}
