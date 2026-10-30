// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80153460-0x801535ec (3 functions). split_file divides it into the game's real files.
#include "types.h"

extern char lbl_802E3B10[];

extern "C" char lbl_802E3B10[];
extern "C" void fn_80153460(int param_1)
{
    int *p;

    if (*(u8 *)(param_1 + 0xec) == 0) {
        return;
    }
    if (*(u32 *)(param_1 + 0x10) != 0) {
        *(int *)(*(int *)(param_1 + 0x10) + 0xc) = *(int *)(param_1 + 0xc);
    } else {
        p = (int *)(lbl_802E3B10 + *(u8 *)(param_1 + 0xef) * 0xbc);
        p[0x12] = *(int *)(param_1 + 0xc);
    }
    if (*(u32 *)(param_1 + 0xc) != 0) {
        *(int *)(*(int *)(param_1 + 0xc) + 0x10) = *(int *)(param_1 + 0x10);
    }
    *(u8 *)(param_1 + 0xec) = 0;
}

extern "C" int fn_801534C0(int param_1, u8 *param_2)
{
    char *e;
    u32 v;

    if (*(u8 *)(param_1 + 0x52) < 7) {
        e = (char *)param_1 + *(u8 *)(param_1 + 0x52) * 12;
        e[0x58] = param_2[3];
        v = (param_2[0] << 8) | (param_2[0] << 1);
        e = (char *)param_1 + *(u8 *)(param_1 + 0x52) * 12;
        *(u16 *)(e + 0x5a) = v;
        v = (param_2[1] << 8) | (param_2[1] << 1);
        e = (char *)param_1 + *(u8 *)(param_1 + 0x52) * 12;
        *(u16 *)(e + 0x5c) = v;
        v = (param_2[2] << 8) | (param_2[2] << 1);
        e = (char *)param_1 + *(u8 *)(param_1 + 0x52) * 12;
        *(u16 *)(e + 0x5e) = v;
        e = (char *)param_1 + *(u8 *)(param_1 + 0x52) * 12;
        *(u8 **)(e + 0x60) = param_2;
        *(u8 *)(param_1 + 0x52) += 1;
        return 1;
    }
    return 0;
}

extern "C" int fn_80153568(int param_1, int param_2)
{
    int i;
    char *e;
    int count;

    count = *(u8 *)(param_1 + 0x52);
    for (i = 0, e = (char *)param_1; i < count; i++, e += 12) {
        if (*(int *)(e + 0x60) == param_2) {
            e = (char *)param_1 + i * 12;
            for (; i <= *(u8 *)(param_1 + 0x52) - 2; i++) {
                *(int *)(e + 0x58) = *(int *)(e + 0x64);
                *(int *)(e + 0x5c) = *(int *)(e + 0x68);
                *(int *)(e + 0x60) = *(int *)(e + 0x6c);
                e += 12;
            }
            *(u8 *)(param_1 + 0x52) = *(u8 *)(param_1 + 0x52) - 1;
            return 1;
        }
    }
    return 0;
}

