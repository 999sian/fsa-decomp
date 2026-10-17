#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80140d7c-0x80140ee4 (3 functions). split_file divides it into the game's real files.

extern void* lbl_802FF390;
extern void* lbl_802FF394;
extern void* lbl_802FF3A0;
extern void* lbl_802FF3A8;
extern void* lbl_802FF3AC;
extern u8 lbl_802C8280[];
extern "C" void fn_80140D7C(int* param_1)
{
    void* head;

    if ((u32)param_1[0] != 0) {
        *(int*)(param_1[0] + 4) = param_1[1];
    }
    if ((u32)param_1[1] != 0) {
        *(int*)param_1[1] = param_1[0];
    } else {
        *(int*)((int)lbl_802FF390 + 0xe6c) = param_1[0];
    }
    head = lbl_802FF394;
    param_1[0] = (int)head;
    if (head != 0) {
        ((int*)lbl_802FF394)[1] = (int)param_1;
    }
    param_1[1] = 0;
    lbl_802FF394 = (void*)param_1;
}

extern "C" u32 fn_80140DDC(int param_1)
{
    int* p;
    int* q;
    int* a;
    int* b;
    u32 id;

    a = (int*)lbl_802FF3AC;
    b = (int*)lbl_802FF3A8;
    do {
        id = (u32)lbl_802FF3A0;
        lbl_802FF3A0 = (void*)(id + 1);
        lbl_802FF3A0 = (void*)((u32)lbl_802FF3A0 & 0x7fffffff);
        for (p = a; p != 0; p = (int*)p[0]) {
            if ((u32)p[3] == id) {
                id = -1;
                break;
            }
        }
        for (q = b; q != 0; q = (int*)q[0]) {
            if ((u32)q[3] == id) {
                id = -1;
                break;
            }
        }
    } while (id == -1);
    *(u32*)(lbl_802C8280 + param_1 * 0x1868 + 0xc) = id;
    return id;
}

extern "C" u32 fn_80140E78(u32 param_1)
{
    u32 id;
    int* p;

    id = param_1 & 0x7fffffff;
    for (p = (int*)lbl_802FF3AC; p != 0; p = (int*)p[0]) {
        if ((u32)p[3] == id) {
            return (param_1 & 0x80000000) | ((u8*)p)[9];
        }
    }
    for (p = (int*)lbl_802FF3A8; p != 0; p = (int*)p[0]) {
        if ((u32)p[3] == id) {
            return (param_1 & 0x80000000) | ((u8*)p)[9];
        }
    }
    return -1;
}

