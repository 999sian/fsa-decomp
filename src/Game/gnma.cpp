// GNMA actor. TU 801AAC8C-801AC8EC.
// Functions: draw (TODO), update (slot 3), state handlers (TODO), hit reaction
// (TODO), dtor, init (TODO).
#include "types.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern "C" void fn_80138B7C(void* game);
extern "C" void fn_801AB6A8(void* this_);
extern "C" void fn_801AAF44(void* this_);
extern void* lbl_804A307C[];
extern char* lbl_8053AAF8;
extern s32 lbl_8053ABD8;

struct GnmaTimers { u8 pad[0x234]; s32 t[4]; };

// GNMA update (vtable slot 3)
extern "C" void fn_801AAE88(char* this_) {
    switch (*(s32*)(this_ + 0x254)) {
    case 0:
    case 2:
        fn_801AB6A8(this_);
        break;
    case 1:
    case 3:
        fn_801AAF44(this_);
        break;
    }
    for (int i = 0; i < 4; i++) {
        if (((GnmaTimers*)this_)->t[i] > 0) {
            ((GnmaTimers*)this_)->t[i]--;
        }
    }
}

struct Handles_gnma { u8 pad[0x27c]; void* h[2]; };

// GNMA destructor
extern "C" void* fn_801AC324(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A307C;
        for (int i = 0; i < 2; i++) {
            fn_801EE434(((Handles_gnma*)this_)->h[i]);
        }
        s32 kind = *(s32*)(this_ + 0x254);
        if (kind == 2 || kind == 3) {
            if (--lbl_8053ABD8 == 0 && *(s32*)(lbl_8053AAF8 + 0x4c) != 9) {
                fn_80138B7C(lbl_8053AAF8);
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
