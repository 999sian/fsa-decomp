

#include "types.h"

extern "C" char lbl_8046A688[];
extern "C" int lbl_8053FD20;
extern "C" int lbl_8053FD24;
extern "C" u8 fn_8021C848(int* param_1) {
    char* base = lbl_8046A688;

    if (*(u8*)(param_1 + 5) == 0) {
        int n = 0;
        switch (param_1[0]) {
        case 0:
            n = 1;
            break;
        case 1:
            n = 7;
            break;
        case 2:
            n = 2;
            break;
        }
        param_1[3]++;
        int* tbl = 0;
        switch (param_1[0]) {
        case 0:
            tbl = &lbl_8053FD20;
            break;
        case 1:
            tbl = (int*)base;
            break;
        case 2:
            tbl = &lbl_8053FD24;
            break;
        }
        if (param_1[3] >= tbl[param_1[2]]) {
            param_1[3] = 0;
            param_1[2]++;
            if (param_1[2] >= n) {
                param_1[2]--;
                *(u8*)(param_1 + 5) = 1;
            }
        }
    }

    int r = 0;
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
    return *(u8*)(param_1 + 5);
}

#pragma opt_propagation off
extern "C" void fn_8021C9C4(int* param_1, int param_2)
{
    int r = 0;
    char* base = lbl_8046A688;
    param_1[4] = param_2;
    param_1[0] = r;
    param_1[2] = r;
    param_1[3] = r;
    *(char*)(param_1 + 5) = r;
    switch (param_1[0]) {
    case 0:
        base += 0x1c;
        { int offset = (param_1[4] << 2) + (param_1[2] << 2); r = *(int*)(base + offset); }
        break;
    case 1:
        base += 0x2c;
        { int offset = param_1[4] * 0x1c + param_1[2] * 4; r = *(int*)(base + offset); }
        break;
    case 2:
        base += 0x9c;
        { int offset = param_1[4] * 8 + param_1[2] * 4; r = *(int*)(base + offset); }
        break;
    }
    param_1[1] = r;
}
#pragma opt_propagation off
extern "C" void fn_8021CA70(int* param_1, int param_2)
{
    int r = 0;
    param_1[0] = param_2;
    param_1[2] = r;
    param_1[3] = r;
    *(char*)(param_1 + 5) = r;
    char* base = lbl_8046A688;
    switch (param_1[0]) {
    case 0: {
        r = param_1[4];
        base +=  0x1c;
        r *= 4;
        r = *(int*)(base + r + param_1[2] * 4);
        break;
    }
    case 1: {
        r = param_1[4];
        base +=  0x2c;
        r *= 0x1c;
        r = *(int*)(base + r + param_1[2] * 4);
        break;
    }
    case 2: {
        r = param_1[4];
        base +=  0x9c;
        r *= 8;
        r = *(int*)(base + r + param_1[2] * 4);
        break;
    }
    }
    param_1[1] = r;
}
#pragma opt_propagation reset
extern "C" int fn_8021CB18(int* param_1)
{
    int result = 0;
    switch (param_1[0]) {
    case 0:
        result = lbl_8053FD20;
        break;
    case 1: {
        int* tbl = (int*)lbl_8046A688;
        result = tbl[0] + tbl[1];
        result += tbl[2];
        result += tbl[3];
        result += tbl[4];
        result += tbl[5];
        result += tbl[6];
        break;
    }
    case 2:
        result = lbl_8053FD24 + *(int*)((char*)&lbl_8053FD24 + 4);
        break;
    }
    return result;
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
