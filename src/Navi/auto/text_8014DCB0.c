#include "types.h"

extern u32* lbl_802FF46C;
extern u32 lbl_802E1C00[];
extern u16 lbl_802FF474;

struct Unk8014Node {
    Unk8014Node* next;
    Unk8014Node* prev;
    u32 id;
    u32 val;
};

extern u32 lbl_802FF468;
extern Unk8014Node* lbl_802FF470;

static inline u32 nextId()
{
    u32 id;
    do {
        id = lbl_802FF468++;
    } while (id == 0xffffffff);
    return id;
}

static inline Unk8014Node* allocNode()
{
    Unk8014Node* node = lbl_802FF470;
    if (node != 0) {
        lbl_802FF470 = node->next;
        if (lbl_802FF470 != 0) {
            lbl_802FF470->prev = 0;
        }
    }
    return node;
}

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8014dcb0-0x8014def0 (4 functions). split_file divides it into the game's real files.

extern "C" u32 fn_8014DCB0(u8* param_1)
{
    *(u32*)(param_1 + 0xfc) = *(u32*)(param_1 + 0xf8);
    return *(u32*)(*(u32*)(param_1 + 0xf8) + 8);
}

extern "C" u32 fn_8014DCC4(u8* param_1, u32 param_2)
{
    u32 id;
    Unk8014Node* p;
    Unk8014Node* prev;
    Unk8014Node* node;

    while ((id = lbl_802FF468++) == 0xffffffff) {
    }

    prev = 0;
    for (p = (Unk8014Node*)lbl_802FF46C; p != 0; p = p->next) {
        if (p->id > id) {
            break;
        }
        if (p->id == id) {
            while ((id = lbl_802FF468++) == 0xffffffff) {
            }
        }
        prev = p;
    }

    if ((node = lbl_802FF470) == 0) {
        return 0xffffffff;
    }
    if ((lbl_802FF470 = node->next) != 0) {
        lbl_802FF470->prev = 0;
    }
    if (prev == 0) {
        lbl_802FF46C = (u32*)node;
    } else {
        prev->next = node;
    }
    node->prev = prev;
    node->next = p;
    if (p != 0) {
        p->prev = node;
    }
    node->id = id;
    node->val = *(u32*)(param_1 + 0xf4);
    *(Unk8014Node**)(param_1 + 0xfc) = param_2 ? node : 0;
    *(Unk8014Node**)(param_1 + 0xf8) = node;
    if (param_2) {
        return id;
    }
    return *(u32*)(param_1 + 0xf4);
}

extern "C" u32 fn_8014DDC0(u32 param_1)
{
    u32* p;

    if (param_1 != 0xffffffff) {
        for (p = lbl_802FF46C; p != 0; p = (u32*)*p) {
            if (p[2] == param_1) {
                break;
            } else if (p[2] > param_1) {
                p = 0;
                break;
            }
        }
        if (p != 0) {
            return p[3];
        }
    }
    return 0xffffffff;
}

extern "C" void fn_8014DE10(u8* param_1)
{
    u8* base = (u8*)lbl_802E1C00;
    u8* e = base + ((*(u32*)(param_1 + 0xf4) & 0xff) * 4);
    u16 flag = *(u16*)(e + 0x8c2);

    e += 0x8c0;
    if (flag != 1) {
        return;
    }
    if (e[0] != 0xff) {
        base[e[0] * 4 + 0x8c1] = e[1];
    } else {
        base[*(u8*)(param_1 + 0x10c) + 0x9c0] = e[1];
    }
    if (e[1] != 0xff) {
        base[e[1] * 4 + 0x8c0] = e[0];
    } else if (e[0] == 0xff) {
        u8* e2 = base + *(u8*)(param_1 + 0x10c) * 4;

        if (*(u16*)(e2 + 0xac2) != 0xffff) {
            *(u16*)(base + *(u16*)(e2 + 0xac2) * 4 + 0xac0) = *(u16*)(e2 + 0xac0);
        } else {
            lbl_802FF474 = *(u16*)(e2 + 0xac0);
        }
        if (*(u16*)(e2 + 0xac0) != 0xffff) {
            *(u16*)(base + *(u16*)(e2 + 0xac0) * 4 + 0xac2) = *(u16*)(e2 + 0xac2);
        }
    }
    *(u16*)(e + 2) = 0;
}

