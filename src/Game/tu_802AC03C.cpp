// TU 0x802AC03C-0x802AC58C.
#include "types.h"

void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);

extern void* lbl_804A82A8[];
extern "C" void* fn_802AC03C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A82A8;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_802AC09C(u8* this_) {
    *(s32*)(this_ + 0x238) = 0;
}

extern "C" void fn_802AC0A8(void) {}

extern "C" u8 fn_80388EEC(s32 p);
extern "C" void fn_8029EC84(void* mgr, u32 a, s32 room, u32 b, s32 c, s32 d);
extern "C" u8 fn_8023061C(s32 p, s32 a);
extern "C" u8 fn_80230534(s32 a);
extern "C" u8 fn_8022F514(s32 p);
extern "C" s32 fn_8022F3DC(s32 p);
extern void* lbl_8053AC98;
extern u8* lbl_8053AAF8;

// Code matches, but the TU cannot link as Matching yet: its jump table sits in
// .data right after the vtable lbl_804A82A8 (0x804A82A8-0x804A8338), which
// needs the real class definition to be emitted from this TU.
extern "C" void fn_802AC0AC(u8* this_) {
    switch (*(s32*)(this_ + 0x230)) {
    case 0:
        if (*(s32*)(this_ + 0x238) == 0) {
            if (fn_80388EEC(*(s32*)(this_ + 0x234))) {
                u32 p = *(u32*)(this_ + 0x90);
                u32 a = p >> 16;
                u32 b = (p >> 8) & 0xf;
                switch (p & 0xf) {
                case 0:
                    break;
                case 1:
                    fn_8029EC84(lbl_8053AC98, a, *(s32*)(this_ + 4), b, 0x18, 0x28);
                    break;
                case 2:
                    fn_8029EC84(lbl_8053AC98, a, *(s32*)(this_ + 4), b, 0x19, 0x29);
                    break;
                case 3:
                    fn_8029EC84(lbl_8053AC98, a, *(s32*)(this_ + 4), b, 0x1a, 0x2a);
                    break;
                case 4:
                    fn_8029EC84(lbl_8053AC98, a, *(s32*)(this_ + 4), b, 0x1b, 0x2b);
                    break;
                case 5:
                    fn_8029EC84(lbl_8053AC98, a, *(s32*)(this_ + 4), b, 0x1c, 0x2c);
                    break;
                case 6:
                    fn_8029EC84(lbl_8053AC98, a, *(s32*)(this_ + 4), b, 0x1d, 0x2d);
                    break;
                case 7:
                    fn_8029EC84(lbl_8053AC98, a, *(s32*)(this_ + 4), b, 0x1e, 0x2e);
                    break;
                case 8:
                    fn_8029EC84(lbl_8053AC98, a, *(s32*)(this_ + 4), b, 0x1f, 0x2f);
                    break;
                case 9:
                    fn_8029EC84(lbl_8053AC98, a, *(s32*)(this_ + 4), b, 0xa0, 0xb0);
                    break;
                case 10:
                    fn_8029EC84(lbl_8053AC98, a, *(s32*)(this_ + 4), b, 0xa1, 0xb1);
                    break;
                case 11:
                    fn_8029EC84(lbl_8053AC98, a, *(s32*)(this_ + 4), b, 0xa2, 0xb2);
                    break;
                case 12:
                    fn_8029EC84(lbl_8053AC98, a, *(s32*)(this_ + 4), b, 0xa3, 0xb3);
                    break;
                case 13:
                    fn_8029EC84(lbl_8053AC98, a, *(s32*)(this_ + 4), b, 0xfff, 0x100f);
                    break;
                }
                if (*(s32*)(this_ + 0x23c) != 0) {
                    *(s32*)(this_ + 0x230) = 1;
                } else {
                    this_[0x11c] = 0;
                }
            }
        } else if (*(s32*)(this_ + 0x238) > 0) {
            (*(s32*)(this_ + 0x238))--;
        }
        break;
    case 1:
        if (lbl_8053AAF8[0x7e] == 1) {
            if (fn_8023061C(*(s32*)(this_ + 0x240), 0) == 1) {
                this_[0x11c] = 0;
            }
        } else if (fn_80230534(0) == 1) {
            this_[0x11c] = 0;
        }
        break;
    }
}

extern "C" void fn_802AC2F4(u8* this_) {
    *(u32*)(this_ + 0x234) = (*(u32*)(this_ + 0x90) >> 12) & 0xf;
    *(u32*)(this_ + 0x23c) = (*(u32*)(this_ + 0x90) >> 4) & 1;
    *(s32*)(this_ + 0x230) = 0;
    *(s32*)(this_ + 0x238) = 40;
    *(s32*)(this_ + 0x240) = *(s32*)(this_ + 0x234);
    if (fn_8022F514(*(s32*)(this_ + 0x234))) {
        *(s32*)(this_ + 0x240) = fn_8022F3DC(*(s32*)(this_ + 0x234));
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

static u8 lbl_804D14D4[0x94];
