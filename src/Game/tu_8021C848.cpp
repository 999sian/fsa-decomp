

#include "types.h"

extern "C" char lbl_8046A688[];
extern "C" int lbl_8053FD20;
extern "C" int lbl_8053FD24;
extern "C" void fn_8021C9C4(int* param_1, int param_2)
{
    char* base = lbl_8046A688;
    int r;

    param_1[4] = param_2;
    param_1[0] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    *(char*)(param_1 + 5) = 0;
    switch (param_1[0]) {
    case 0:
        base += 0x1c;
        r = *(int*)(base + (param_1[4] * 4 + param_1[2] * 4));
        break;
    case 1:
        base += 0x2c;
        r = *(int*)(base + (param_1[4] * 0x1c + param_1[2] * 4));
        break;
    case 2:
        base += 0x9c;
        r = *(int*)(base + (param_1[4] * 8 + param_1[2] * 4));
        break;
    }
    param_1[1] = r;
}

extern "C" void fn_8021CA70(int* param_1, int param_2)
{
    char* base = lbl_8046A688;
    int r;

    param_1[0] = param_2;
    param_1[2] = 0;
    param_1[3] = 0;
    *(char*)(param_1 + 5) = 0;
    switch (param_1[0]) {
    case 0:
        r = *(int*)(base + 0x1c + param_1[4] * 4 + param_1[2] * 4);
        break;
    case 1:
        r = *(int*)(base + 0x2c + param_1[4] * 0x1c + param_1[2] * 4);
        break;
    case 2:
        r = *(int*)(base + 0x9c + param_1[4] * 8 + param_1[2] * 4);
        break;
    }
    param_1[1] = r;
}

extern "C" int fn_8021CB18(int* param_1)
{
    if (param_1[0] > 1) {
        if (param_1[0] >= 3) {
            return 0;
        }
        return lbl_8053FD24 + *(int*)((char*)&lbl_8053FD24 + 4);
    }
    if (param_1[0] == 1) {
        int* tbl = (int*)lbl_8046A688;
        return tbl[0] + tbl[1] + tbl[2] + tbl[3] + tbl[4] + tbl[5] + tbl[6];
    }
    if (param_1[0] >= 0) {
        return lbl_8053FD20;
    }
    return 0;
}

extern "C" void fn_8021CBA0(int* param_1)
{
    param_1[0] = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    *(char*)(param_1 + 5) = 0;
}
