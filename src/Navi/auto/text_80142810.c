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
