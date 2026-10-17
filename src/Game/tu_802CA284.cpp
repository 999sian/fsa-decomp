#include "Game/Actor.h"
#include "Game/SinitPoolChain.h"


extern "C" u8 lbl_804A8F74[];
extern "C" void __dl__FPv(void* p);
extern "C" void __dt__5ActorFv(Actor* self, s16 flag);
extern u8* lbl_8053AAF8;
extern "C" u8 fn_802DEBF8(void);
extern "C" u8 fn_802DEBA0(void);
extern "C" u8 fn_802DE814(void);
extern "C" s32 fn_80237774(s32);
extern "C" void fn_802CADB0(u8* this_) {
    u8* p;
    s32 i;

    if (lbl_8053AAF8[0x7e] == 1 && !fn_802DEBF8() && !fn_802DEBA0() && !fn_802DE814()) {
        this_[0x278] = 1;
    } else {
        this_[0x278] = 0;
    }

    p = this_;
    for (i = 0; i < 4; i++) {
        *(s32*)(p + 0x234) = 0;
        *(s32*)(p + 0x244) = 0;
        *(s32*)(p + 0x254) = 0;
        this_[0x274 + i] = 0xff;
        if (lbl_8053AAF8[0x82] & (u8)(1 << i)) {
            *(s32*)(p + 0x264) = fn_80237774(i);
        } else {
            *(s32*)(p + 0x264) = 0;
        }
        p += 4;
    }

    *(s32*)(this_ + 0x27c) = 0;
    *(s32*)(this_ + 0x28c) = 0;
    *(s32*)(this_ + 0x280) = 0;
    *(s32*)(this_ + 0x290) = 0;
    *(s32*)(this_ + 0x284) = 0;
    *(s32*)(this_ + 0x294) = 0;
    *(s32*)(this_ + 0x288) = 0;
    *(s32*)(this_ + 0x298) = 0;
    this_[0x11f] = 1;
}

extern "C" Actor* fn_802CAEB0(Actor* self, s16 flag)
{
    struct SubObj802CA {
        u8 pad[0x24];
        s32 f24;
        u8 pad2[0xf4 - 0x28];
        u32 f0f4;
    };
    u8* p = (u8*)self;
    if (self != 0) {
        *(u8**)p = lbl_804A8F74;
        SubObj802CA* s;
        u8* q = p;
        for (int i = 0; i < 2; i++) {
            s = *(SubObj802CA**)(q + 0x234);
            if (s != 0) {
                s->f0f4 |= 1;
                s->f24 = 1;
                *(SubObj802CA**)(q + 0x234) = 0;
            }
            s = *(SubObj802CA**)(q + 0x238);
            if (s != 0) {
                s->f0f4 |= 1;
                s->f24 = 1;
                *(SubObj802CA**)(q + 0x238) = 0;
            }
            q += 8;
        }
        __dt__5ActorFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
