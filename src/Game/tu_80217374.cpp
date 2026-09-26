// TU 0x80217374-0x8021775C.
#include "types.h"

void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);

struct Random {
    u32 seed;
    f32 get_ufloat_1() {
        union {
            f32 f;
            u32 s;
        } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
};
struct Game { u8 pad[0xb4]; Random rnd; };
extern Game* lbl_8053AAF8;
extern "C" s32 fn_801CD664(s32 n);

struct TurnTimer {
    s32 mode;
    s32 tick;
    s32 limit;
};

// NonMatching: else-branch result lands in r30 then mr r3 (retail computes
// straight into r3 without extsh).
extern "C" s16 fn_80217374(TurnTimer* t, s16 angle) {
    s16 ret = angle;
    t->tick++;
    if (t->tick >= t->limit) {
        switch (t->mode) {
        case 0:
            if (fn_801CD664(2) == 0) {
                t->limit = fn_801CD664(0x3d) + 0x3c;
                t->mode = 1;
                t->tick = 0;
                ret = angle - 0x4000;
            } else {
                t->limit = fn_801CD664(0x3d) + 0x3c;
                t->mode = 2;
                t->tick = 0;
                ret = angle + 0x4000;
            }
            break;
        case 1:
        case 2:
            t->limit = fn_801CD664(1) + 0xb4;
            if (t->mode == 1) {
                ret = angle += 0x4000;
            } else {
                ret = angle -= 0x4000;
            }
            t->mode = 0;
            t->tick = 0;
            break;
        }
    }
    return ret;
}

extern "C" void fn_80217484(TurnTimer* t) {
    t->mode = 0;
    t->tick = 0;
    t->limit = fn_801CD664(1) + 0xb4;
    t->limit = t->limit * lbl_8053AAF8->rnd.get_ufloat_1();
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

static u8 lbl_804CD7A4[0x94];
