#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80141ea4-0x80142140 (3 functions). split_file divides it into the game's real files.

extern void* lbl_802FF3AC;
extern void* lbl_802FF3A8;
extern u8 lbl_802C6E80[];
extern "C" void fn_80141EA4(u32 param_1, u16 param_2) {
    u8* base = lbl_802C6E80;
    int* p;
    u32 key = param_1 & 0x7fffffff;
    u32 idx;

    for (p = (int*)lbl_802FF3AC; p != 0; p = (int*)p[0]) {
        if ((u32)p[3] == key) {
            idx = (param_1 & 0x80000000) | *((u8*)p + 9);
            goto found;
        }
    }
    for (p = (int*)lbl_802FF3A8; p != 0; p = (int*)p[0]) {
        if ((u32)p[3] == key) {
            idx = (param_1 & 0x80000000) | *((u8*)p + 9);
            goto found;
        }
    }
    idx = -1;
found:
    if (!(idx & 0x80000000)) {
        *(u16*)(base + idx * 0x1868 + 0x291a) = param_2;
        *(u16*)(base + idx * 0x1868 + 0x2952) = param_2;
        *(u16*)(base + idx * 0x1868 + 0x298a) = param_2;
        *(u16*)(base + idx * 0x1868 + 0x29c2) = param_2;
        *(u16*)(base + idx * 0x1868 + 0x29fa) = param_2;
        *(u16*)(base + idx * 0x1868 + 0x2a32) = param_2;
        *(u16*)(base + idx * 0x1868 + 0x2a6a) = param_2;
        *(u16*)(base + idx * 0x1868 + 0x2aa2) = param_2;
        *(u16*)(base + idx * 0x1868 + 0x2ada) = param_2;
        *(u16*)(base + idx * 0x1868 + 0x2b12) = param_2;
        *(u16*)(base + idx * 0x1868 + 0x2b4a) = param_2;
        *(u16*)(base + idx * 0x1868 + 0x2b82) = param_2;
        *(u16*)(base + idx * 0x1868 + 0x2bba) = param_2;
        *(u16*)(base + idx * 0x1868 + 0x2bf2) = param_2;
        *(u16*)(base + idx * 0x1868 + 0x2c2a) = param_2;
        *(u16*)(base + idx * 0x1868 + 0x2c62) = param_2;
        return;
    }
    idx &= 0x7fffffff;
    *(u8*)(base + idx * 0x1868 + 0x22da) |= 0x20;
    *(u16*)(base + idx * 0x1868 + 0x22d8) = param_2;
}

extern u8 lbl_802C8280[];
extern "C" void fn_80141F80(u32 param_1) {
    u8* base = lbl_802C8280;
    int* p;
    u32 key = param_1 & 0x7fffffff;
    u32 idx;

    for (p = (int*)lbl_802FF3AC; p != 0; p = (int*)p[0]) {
        if ((u32)p[3] == key) {
            idx = (param_1 & 0x80000000) | *((u8*)p + 9);
            goto found;
        }
    }
    for (p = (int*)lbl_802FF3A8; p != 0; p = (int*)p[0]) {
        if ((u32)p[3] == key) {
            idx = (param_1 & 0x80000000) | *((u8*)p + 9);
            goto found;
        }
    }
    idx = -1;
found:
    if (!(idx & 0x80000000)) {
        int* node = (int*)(base + idx * 0x1868);
        if (*((u8*)node + 8) == 2) {
            if ((int*)node[1] != 0) {
                ((int*)node[1])[0] = node[0];
            } else {
                lbl_802FF3A8 = (void*)node[0];
            }
            if ((int*)node[0] != 0) {
                ((int*)node[0])[1] = node[1];
            }
            node[0] = (int)lbl_802FF3AC;
            if (lbl_802FF3AC != 0) {
                ((int*)lbl_802FF3AC)[1] = (int)node;
            }
            node[1] = 0;
            lbl_802FF3AC = node;
            *((u8*)node + 8) = 1;
        }
        return;
    }
    idx &= 0x7fffffff;
    *(u8*)(base + idx * 0x1868 + 0xeda) &= 0xf7;
}

extern "C" void fn_8014208C(u32 param_1, u32 param_2, u32 param_3)
{
    u8* base = lbl_802C6E80;
    int* p;
    u32 key = param_1 & 0x7fffffff;
    u32 idx;

    for (p = (int*)lbl_802FF3AC; p != 0; p = (int*)p[0]) {
        if ((u32)p[3] == key) {
            idx = (param_1 & 0x80000000) | *((u8*)p + 9);
            goto found;
        }
    }
    for (p = (int*)lbl_802FF3A8; p != 0; p = (int*)p[0]) {
        if ((u32)p[3] == key) {
            idx = (param_1 & 0x80000000) | *((u8*)p + 9);
            goto found;
        }
    }
    idx = -1;
found:
    if (idx == 0xffffffff) {
        return;
    }
    if (!(idx & 0x80000000)) {
        *(u32*)(base + idx * 0x1868 + 0x151c) = param_2;
        *(u32*)(base + idx * 0x1868 + 0x1520) = param_3;
        return;
    }
    idx &= 0x7fffffff;
    *(u8*)(base + idx * 0x1868 + 0x22da) |= 0x10;
    *(u32*)(base + idx * 0x1868 + 0x22d0) = param_2;
    *(u32*)(base + idx * 0x1868 + 0x22d4) = param_3;
}
