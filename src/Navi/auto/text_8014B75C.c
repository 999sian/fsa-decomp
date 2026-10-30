// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8014b75c-0x8014b830 (1 functions). split_file divides it into the game's real files.
#include <types.h>
extern "C" void fn_8014CF34(u8* e);
extern "C" void fn_8014EA44(s32 idx);
extern void* lbl_802FF3E0;
extern u8 lbl_802D4A80[];

extern "C" void fn_8014B75C(u8* param_1, u32* param_2)
{
    s32 iVar5 = 0;
    u32 uVar4;
    u32 uVar1;
    u32 uVar2;
    u32 uVar3;
    BOOL bVar3;
    u8* e;

    iVar5 = 0;
    param_1[0x104] = 0;
    uVar1 = *param_2;
    uVar2 = (uVar1 >> 8) & 0xff;
    uVar3 = (uVar1 >> 16) & 0xff;
    bVar3 = uVar3 != 0;
    if (uVar2 != 0) {
        for (uVar4 = 0; uVar4 < lbl_802D4A80[0x210]; uVar4++) {
            e = (u8*)lbl_802FF3E0 + iVar5;
            if (*(u32*)(e + 0x34) != 0) {
                if (((*(u64*)(e + 0x114)) & 2ULL) == 0 && uVar2 == e[0x104]) {
                    if (bVar3) {
                        fn_8014EA44(uVar4);
                    } else {
                        fn_8014CF34(e);
                    }
                }
            }
            iVar5 += 0x404;
        }
        param_1[0x104] = uVar2;
    }
}
