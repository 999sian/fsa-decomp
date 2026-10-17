#include "Game/Actor.h"

extern "C" {
void* fn_802D6A9C();
void fn_802F9974(void* mgr, s32 room, u32 key, s32 n);
}

struct Box4 {
    f32 a, b, c, d;
};

extern "C" f32 lbl_805408C8;
extern "C" f32 lbl_805408DC;
extern "C" f32 lbl_805408F4;
extern "C" f32 lbl_805408FC;
extern "C" f32 lbl_80540900;
extern "C" f32 lbl_80540904;
extern "C" f32 lbl_80540908;
extern "C" f32 lbl_8054090C;
extern "C" f32 lbl_80540948;
extern "C" f32 lbl_8054094C;
extern "C" f32 lbl_80540950;
extern "C" f32 lbl_80540954;
extern "C" f32 lbl_80540958;
extern "C" f32 lbl_8054095C;
extern "C" s32 lbl_8046C8CC[];
extern "C" s32 lbl_8046C8B0[];
extern void* lbl_8053AAF8;
extern void* lbl_8053AB10;


extern "C" char lbl_804A83A0[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_802ACEA4(Actor* p, s16 n) {
    if (p != NULL) {
        *(void**)p = lbl_804A83A0;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
