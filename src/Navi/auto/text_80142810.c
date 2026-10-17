// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80142810-0x80142b40 (3 functions). split_file divides it into the game's real files.

#include "types.h"

typedef struct Node {
    struct Node *next;
    struct Node *prev;
    u32 key;
} Node;

typedef struct NodeList {
    u8 unk_0x0[0x1c];
    Node *head;
} NodeList;

u8 *fn_80142810(u8 *param_1, u16 *param_2, s16 *param_3)
{
    u8 b0 = param_1[0];
    u8 b1 = param_1[1];

    if (b0 == 0x80 && b1 == 0) {
        return 0;
    }
    if (b0 & 0x80) {
        *param_2 = ((b0 & 0x7f) << 8) | b1;
        param_1 += 2;
    } else {
        *param_2 = b0;
        param_1 += 1;
    }
    b0 = param_1[0];
    b1 = param_1[1];
    if (b0 & 0x80) {
        *param_3 = (s16)(((s16)(((b0 & 0x7f) << 8) | b1)) << 1) >> 1;
        return param_1 + 2;
    }
    *param_3 = ((s16)b0 << 9) >> 9;
    return param_1 + 1;
}

extern "C" u8 *fn_80142810(u8 *param_1, u16 *param_2, s16 *param_3);
extern "C" void fn_80142ACC(NodeList *param_1, Node *param_2);
void fn_80142ACC(NodeList *param_1, Node *param_2)
{
    Node *cur = param_1->head;
    Node *prev = 0;

    while (cur != 0) {
        if (cur->key > param_2->key) {
            param_2->next = cur;
            param_2->prev = prev;
            if (prev != 0) {
                prev->next = param_2;
            } else {
                param_1->head = param_2;
            }
            cur->prev = param_2;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
    param_2->prev = prev;
    if (prev != 0) {
        prev->next = param_2;
    } else {
        param_1->head = param_2;
    }
    param_2->next = 0;
}
