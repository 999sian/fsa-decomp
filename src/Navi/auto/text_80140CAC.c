#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80140cac-0x80140d7c (1 functions). split_file divides it into the game's real files.

extern void* lbl_802FF390;
extern "C" void fn_801465D0(int param_1);
extern "C" void fn_80140CAC(void)
{
    int i;
    int off;
    int* node;
    int* next;
    int* head;
    int* tail;

    i = 0;
    off = 0;
    do {
        node = *(int**)((int)lbl_802FF390 + off + 0xe64);
        while (node != NULL) {
            next = (int*)node[0];
            fn_801465D0(node[2]);
            head = (int*)node[0];
            *(int*)((int)lbl_802FF390 + off + 0xe64) = (int)head;
            if (head != NULL) {
                ((int*)*(int*)((int)lbl_802FF390 + off + 0xe64))[1] = 0;
            }
            tail = *(int**)((int)lbl_802FF390 + 0xe6c);
            node[0] = (int)tail;
            if (tail != NULL) {
                ((int*)*(int*)((int)lbl_802FF390 + 0xe6c))[1] = (int)node;
            }
            *(int*)((int)lbl_802FF390 + 0xe6c) = (int)node;
            node = next;
        }
        i++;
        off += 4;
    } while (i < 2);
}
