#include "Game/Actor.h"


extern "C" char lbl_804AC010[];
extern "C" void __dt__5ActorFv(Actor*, s32);
namespace JMath {
    template <int N, typename T>
    class TAtanTable {
    public:
        f32 atan2_(f32, f32) const;
    };
    extern const TAtanTable<1024, f32> atanTable_;
}
extern "C" void fn_801EE558(void* this_, void* p, f32* len, s32 p4);
extern f32 lbl_80542060;
extern f32 lbl_80542064;
extern "C" Actor* fn_80337650(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804AC010;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern char lbl_80471BB8[];
extern f32 lbl_8054205C;
extern "C" void fn_801F06F0(void* this_, void* p, s32 id, u32 p4, s32 p5, f32 a, f32 b);
extern "C" void fn_803075AC(void*, s32, void*, s32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_80337C88(char* this_) {
    char* base = lbl_80471BB8;
    s32 state = *(s32*)(this_ + 0x230);
    if (state != 2) {
        char* t = base + 0x100;
        char* p = base + 0x194;
        s32 val;
        if (*(s32*)(t + *(s32*)(this_ + 0x250) * 8) == 2) {
            p = base + 0x180;
        }
        switch (state) {
        case 1:
            val = *(s32*)(t + *(s32*)(this_ + 0x250) * 8 + 4) +
                  *(s32*)(*(char**)(base + *(s32*)(this_ + 0x250) * 16 + 8) + *(s32*)(this_ + 0x248) * 16 + *(s32*)(this_ + 0x238) * 4);
            break;
        case 0:
        case 3:
        case 4:
        default:
            val = *(s32*)(t + *(s32*)(this_ + 0x250) * 8 + 4) +
                  *(s32*)(*(char**)(base + *(s32*)(this_ + 0x250) * 16 + 0xc) + *(s32*)(this_ + 0x248) * 16 + *(s32*)(this_ + 0x238) * 4);
            break;
        }
        if (*(s32*)(this_ + 0x250) == 2) {
            fn_801F06F0(this_, p, val, 0, 3, lbl_8054205C, lbl_8054205C);
        }
        if (*(s32*)(this_ + 0x250) < 4 && *(s32*)(this_ + 0x250) >= 0) {
            fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xc, val, 0, 2, -1, 0, 0, 0);
        }
    }
}

