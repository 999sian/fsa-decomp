#include "Game/Actor.h"

extern char lbl_80471BB8[];
extern u8* lbl_8053AAF8;
extern f32 lbl_80542058;
extern f32 lbl_8054205C;


extern "C" char lbl_804AC010[];
extern "C" void __dt__5ActorFv(Actor*, s32);
namespace JMath {
    template <int N, typename T>
    class TAtanTable {
    public:
        f32 atan2_(f32, f32) const;
        f32 mTable[1024];
        f32 mTable2[8];
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

extern "C" void fn_80337A08(u8* this_) {
    s32 state = *(s32*)(this_ + 0x250);
    s32 prev = *(s32*)(this_ + 0x248);

    switch (state) {
    case 5:
    case 6:
    case 14:
        *(s32*)(this_ + 0x248) = 0;
        return;
    }

    switch (*(s32*)(this_ + 0x230)) {
    case 0:
    case 1:
    case 4: {
        s32 timer = *(s32*)(this_ + 0x244);
        f32 v[3];
        f32 len;

        if (timer != 0) {
            *(s32*)(this_ + 0x244) = timer - 1;
            return;
        }
        *(s32*)(this_ + 0x244) = 0x14;
        fn_801EE558(this_, v, &len, 0);
        if (len < lbl_80542060) {
            f32 a = JMath::atanTable_.atan2_(-v[0], -v[1]);
            u16 ang = (s32)(a * lbl_80542064);
            if (ang < 0x2000 || ang >= 0xe000) {
                *(s32*)(this_ + 0x248) = 3;
            } else if (ang >= 0x2000 && ang < 0x6000) {
                *(s32*)(this_ + 0x248) = 1;
            } else if (ang >= 0x6000 && ang <= 0xa000) {
                *(s32*)(this_ + 0x248) = 2;
            } else {
                *(s32*)(this_ + 0x248) = 0;
            }
        } else {
            *(s32*)(this_ + 0x248) = 3;
        }
        break;
    }
    case 3:
    case 5: {
        s32 a = *(s32*)(this_ + 0x258);
        s32 b = *(s32*)(this_ + 0x25c);
        s32 a2 = a * a;
        s32 b2 = b * b;

        if (state >= 7 && state <= 15 && state != 14) {
            if (a > 0) {
                *(s32*)(this_ + 0x248) = 0;
            } else {
                *(s32*)(this_ + 0x248) = 1;
            }
        } else if (a2 == 0 && b2 == 0) {
            *(s32*)(this_ + 0x248) = 2;
        } else if (a2 > b2) {
            if (a > 0) {
                *(s32*)(this_ + 0x248) = 0;
            } else {
                *(s32*)(this_ + 0x248) = 1;
            }
        } else {
            if (b > 0) {
                *(s32*)(this_ + 0x248) = 2;
            } else {
                *(s32*)(this_ + 0x248) = 3;
            }
        }
        if (*(s32*)(this_ + 0x230) == 5) {
            *(s32*)(this_ + 0x248) ^= 1;
        }
        break;
    }
    }

    if (*(s32*)(this_ + 0x250) == 4) {
        s32 cur = *(s32*)(this_ + 0x248);
        if ((cur >= 2 && prev < 2) || (cur < 2 && prev >= 2)) {
            *(s32*)(this_ + 0x238) = 0;
            *(s32*)(this_ + 0x234) = 0x14;
        }
    }
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

