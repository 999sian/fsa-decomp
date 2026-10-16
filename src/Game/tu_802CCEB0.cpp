#include "Game/Actor.h"


extern void* lbl_804A9078[];
extern const f32 lbl_80540E14;
extern const f32 lbl_80540E18;
extern const f32 lbl_80540E1C;
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* p);
extern "C" void* fn_802CCEB0(void* this_, s16 freeFlag) {
    if (this_ != NULL) {
        *(void**)this_ = lbl_804A9078;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_802CCF10(void) {}
