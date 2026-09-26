#ifndef GAME_ACTOR_H
#define GAME_ACTOR_H

#include "types.h"

/* Basic vector/rotation tuple used all over the game side. */
struct Vec {
    f32 x, y, z;
};

/* Small POD living at Actor+0x1DC. 0x14 bytes of flags/ids followed by 16
 * words the Actor constructor sets to -1 (sub_801EAD68). */
struct ActorSub1DC {
    /* 0x00 */ u8 field_00[0x14];
    /* 0x14 */ s32 field_14[0x10];
};

/*
 * Game actor base class.
 *
 * Layout and the vtable order below were recovered from the retail DOL:
 *  - constructor           0x801F5AE0
 *  - destructor            0x801F593C
 *  - vtable                lbl_804A5770 (.data, 0x54 bytes = 2 header words
 *                          + 19 virtuals).  In the object file the class
 *                          vptr is at offset 0, so the first declared data
 *                          member is 0x004 and the vtable word for slot k
 *                          lives at vtable offset 8 + 4*k.
 *  - size                  0x230 (actors with no extra members, e.g. STGN,
 *                          GFBS, URAC, TJIJ, LCS*, are allocated as 0x230)
 *
 * All 19 virtuals are `void f()`.  Names are deliberately placeholders
 * (v01..v18); the retail address of the base implementation is given next
 * to each so the mapping can never be misread.  Derived actors override by
 * slot, and the slot assignment comes from this declaration order - never
 * add, remove or reorder a virtual here.
 */
class Actor {
public:
    Actor();

    /* slot 0  */ virtual ~Actor();      /* 0x801F593C */
    /* slot 1  */ virtual void v01();    /* 0x801F5938 */
    /* slot 2  */ virtual void v02();    /* 0x801F5934 */
    /* slot 3  */ virtual void v03();    /* 0x801F5930 */
    /* slot 4  */ virtual void v04();    /* 0x801F5790 */
    /* slot 5  */ virtual void v05();    /* 0x801F577C */
    /* slot 6  */ virtual void v06();    /* 0x801F5778 */
    /* slot 7  */ virtual void v07();    /* 0x801F4F28 */
    /* slot 8  */ virtual void v08();    /* 0x801F4E0C */
    /* slot 9  */ virtual void v09();    /* 0x801F4850 */
    /* slot 10 */ virtual void v10(u32 a, u32 b); /* 0x801F47CC */
    /* slot 11 */ virtual u32 v11();     /* 0x801F4760 */
    /* slot 12 */ virtual void v12();    /* 0x801F471C */
    /* slot 13 */ virtual int v13();     /* 0x801F4710 */
    /* slot 14 */ virtual void v14();    /* 0x801F470C */
    /* slot 15 */ virtual void v15();    /* 0x801F4708 */
    /* slot 16 */ virtual void v16();    /* 0x801F4704 */
    /* slot 17 */ virtual int v17(int a, f32* b); /* 0x801F15BC */
    /* slot 18 */ virtual int v18(int a, f32* b); /* 0x801F165C */

    /* 0x801F3668 - not virtual.  Clears field_11C and detaches the actor from
     * the area manager: if field_16C != -1 calls fn_802D7704(manager, field_16C,
     * field_1A8, field_04), otherwise fn_802D766C(manager, field_1A8, field_04),
     * where manager = fn_802D6A9C().  153 direct callers in retail.  Name is a
     * placeholder. */
    void detach();

    /* 0x004 */ u32 field_04;
    /* 0x008 */ u32 field_08;
    /* 0x00C */ Vec field_0C;              /* copied to field_18 by v05 */
    /* 0x018 */ Vec field_18;
    /* 0x024 */ Vec field_24;
    /* 0x030 */ Vec field_30;
    /* 0x03C */ Vec field_3C;
    /* 0x048 */ Vec field_48;
    /* 0x054 */ Vec field_54;
    /* 0x060 */ f32 field_60;
    /* 0x064 */ f32 field_64;
    /* 0x068 */ f32 field_68;
    /* 0x06C */ f32 field_6C;
    /* 0x070 */ Vec field_70;
    /* 0x07C */ Vec field_7C;
    /* 0x088 */ f32 field_88;
    /* 0x08C */ f32 field_8C;
    /* 0x090 */ u32 field_90;              /* status/flags; v13 reads >> 27, other code masks & 0xF */
    /* 0x094 */ u16 field_94;
    /* 0x098 */ u32 field_98;
    /* 0x09C */ s32 field_9C;
    /* 0x0A0 */ s32 field_A0;
    /* 0x0A4 */ u32 field_A4;
    /* 0x0A8 */ u32 field_A8;
    /* 0x0AC */ u32 field_AC;
    /* 0x0B0 */ u32 field_B0;
    /* 0x0B4 */ u32 field_B4;
    /* 0x0B8 */ u32 field_B8;
    /* 0x0BC */ u32 field_BC;
    /* 0x0C0 */ u32 field_C0;
    /* 0x0C4 */ u8 field_C4;
    /* 0x0C8 */ s32 field_C8;
    /* 0x0CC */ u8 field_CC;
    /* 0x0D0 */ s32 field_D0;
    /* 0x0D4 */ u8 field_D4;
    /* 0x0D5 */ u8 field_D5;
    /* 0x0D8 */ u32 field_D8;
    /* 0x0DC */ u32 field_DC;
    /* 0x0E0 */ u32 field_E0;
    /* 0x0E4 */ u32 field_E4;
    /* 0x0E8 */ u32 field_E8;
    /* 0x0EC */ Vec field_EC;
    /* 0x0F8 */ u32 field_F8;
    /* 0x0FC */ u32 field_FC;
    /* 0x100 */ void* field_100;            /* pointer released by ~Actor */
    /* 0x104 */ void* field_104;            /* pointer released by ~Actor */
    /* 0x108 */ u32 field_108;
    /* 0x10C */ s32 field_10C;
    /* 0x110 */ s32 field_110;
    /* 0x114 */ u32 field_114;
    /* 0x118 */ u32 field_118;
    /* 0x11C */ u8 field_11C;
    /* 0x11D */ u8 field_11D;
    /* 0x11E */ u8 field_11E;
    /* 0x11F */ u8 field_11F;
    /* 0x120 */ u8 field_120[0x10];        /* initialised to 0..0xF */
    /* 0x130 */ s32 field_130;
    /* 0x134 */ u32 field_134;
    /* 0x138 */ u32 field_138;
    /* 0x13C */ u8 field_13C;
    /* 0x13D */ u8 field_13D;
    /* 0x13E */ u8 field_13E;
    /* 0x13F */ u8 field_13F;
    /* 0x140 */ u8 field_140;
    /* 0x141 */ u8 field_141;
    /* 0x142 */ u8 field_142;
    /* 0x143 */ u8 field_143;
    /* 0x144 */ u8 field_144;
    /* 0x145 */ u8 field_145;
    /* 0x146 */ u8 field_146;
    /* 0x148 */ u32 field_148;
    /* 0x14C */ u8 field_14C;
    /* 0x14D */ u8 field_14D;
    /* 0x14E */ u8 field_14E;
    /* 0x150 */ s32 field_150;
    /* 0x154 */ u32 field_154;
    /* 0x158 */ u32 field_158;
    /* 0x15C */ u32 field_15C;
    /* 0x160 */ u32 field_160;
    /* 0x164 */ u8 field_164;
    /* 0x165 */ u8 field_165;
    /* 0x168 */ u32 field_168;
    /* 0x16C */ s32 field_16C;
    /* 0x170 */ u32 field_170;
    /* 0x174 */ u32 field_174;
    /* 0x178 */ u32 field_178;
    /* 0x17C */ u8 field_17C;
    /* 0x17D */ u8 field_17D;
    /* 0x180 */ u32 field_180;
    /* 0x184 */ f32 field_184;
    /* 0x188 */ s32 field_188;
    /* 0x18C */ u32 field_18C;
    /* 0x190 */ u32 field_190;
    /* 0x194 */ u8 field_194;
    /* 0x195 */ u8 field_195;
    /* 0x196 */ u8 field_196;
    /* 0x198 */ s32 field_198;              /* read by v17 */
    /* 0x19C */ u32 field_19C;
    /* 0x1A0 */ u32 field_1A0;             /* initialised to 'NULL' (0x4E554C4C) */
    /* 0x1A4 */ u32 field_1A4;
    /* 0x1A8 */ u8 field_1A8;
    /* 0x1AC */ Vec field_1AC[4];          /* each element zeroed by the ctor */
    /* 0x1DC */ ActorSub1DC field_1DC;
};

#endif
