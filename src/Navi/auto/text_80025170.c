#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80025170-0x800275d8 (75 functions). split_file divides it into the game's real files.

extern u8 lbl_802FED9C;
extern u8 lbl_802FED9D;
extern u8 lbl_802FED9E;
extern u8 lbl_802FED9F;
extern u8 lbl_802FEDA4;

extern "C" void fn_8015AB1C(void*);
extern "C" void fn_800254CC(void);
extern "C" void fn_8002544C(void) {
    fn_800254CC();
}

extern "C" void fn_80025570(void);
extern "C" void fn_8002546C(void) {
    fn_80025570();
}

extern "C" void fn_8002566C(void);
extern "C" void fn_8002548C(void) {
    fn_8002566C();
}

extern "C" void fn_80025710(void);
extern "C" void fn_800254AC(void) {
    fn_80025710();
}

extern u8 lbl_802FED9C;
extern "C" void fn_80026520(void) {
    lbl_802FED9C = 0;
}

extern "C" void fn_800265F0(u8 param_1) {
    lbl_802FED9D &= ~((u8)(1 << param_1));
}

extern u8 lbl_802FED9E;
extern "C" void fn_80026630(void) {
    lbl_802FED9E = 0;
}

extern "C" u32 fn_8002663C(void) {
    for (u8 i = 0; i < 4; i++) {
        u8 mask = 1 << i;
        if ((lbl_802FED9D & mask) != 0 && (lbl_802FED9E & mask) == 0) {
            return 0;
        }
    }
    return 1;
}

extern "C" u8 fn_80026694(void) {
    return lbl_802FED9F;
}

extern u8 lbl_802FED9F;
extern "C" void fn_800266A8(void) {
    lbl_802FED9F = 0;
}

extern u8 lbl_802FEDA4;
extern u8 lbl_802FED9D;
extern "C" void fn_800266B4(u8 param_1) {
    ((u8*)&lbl_802FEDA4)[param_1] = 1;
}

extern "C" void fn_800266C8(u8 param_1) {
    ((u8*)&lbl_802FEDA4)[param_1] = 2;
}

extern "C" u32 fn_800266DC(void) {
    u32 result = 1;
    for (u8 i = 0; i < 4; i++) {
        if ((lbl_802FED9D & (1 << i)) != 0) {
            u8 val = ((u8*)&lbl_802FEDA4)[i];
            if (val == 2) {
                result = 2;
            }
            if (val == 0) {
                return 0;
            }
        }
    }
    return result;
}

extern "C" void* fn_80026E54(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}
