// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include "types.h"

extern volatile s32 lbl_8053BC70;

#include <types.h>

void fn_800C9CF4(void)
{
}

void fn_800C9CF8(void)
{
}

void fn_800C9CFC(void)
{
}

extern "C" void fn_800C9D04(void) {
}

extern "C" void fn_800C9D08(void) {
}

extern "C" s32 fn_800C9D0C(void) {
    return 0;
}

extern "C" void fn_800C9D14(void) {
}

extern "C" void fn_800CAAA8(void) {
}

extern "C" void fn_800CAAAC(void* a, s32 v) {
    *(s32*)((u8*)a + 0x4) = v;
}

extern "C" s32 fn_800CAEC8(int param_1, u32 param_2) {
    s32 result = 0;
    if (param_2 == 0) {
        result = 100;
    }
    return result + 0x10;
}

extern "C" void fn_800CAEE0(s32 *param_1, int param_2, int param_3, int param_4) {
    int p2_4 = *(int *)(param_2 + 4);
    int p2_8 = *(int *)(param_2 + 8);
    int p2_10 = *(int *)(param_2 + 0x10);
    s32 default_val = lbl_8053BC70;
    ushort idx1 = *(ushort *)(p2_8 + param_3 * 2);
    ushort uVar1 = *(ushort *)(p2_4 + idx1 * 0x14c + 8 + param_4 * 2);
    
    if (uVar1 != 0xffff) {
        *param_1 = *(int *)(p2_10 + ((uint)uVar1 << 2));
    } else {
        *param_1 = default_val;
    }
}

extern "C" u32 fn_800CBC48(void) {
    return 0x50454E4C;
}

extern "C" void fn_800CBCB0(void) {
}

extern "C" void fn_800CBCB4(void) {
}

extern "C" void fn_800D9FE4(int param_1, int param_2);
extern "C" void fn_800CBCB8(int param_1) {
    fn_800D9FE4(param_1, *(int*)(param_1 + 4));
}

extern "C" u32 fn_800CBCDC(void) {
    return 0x54564E4C;
}

extern "C" char lbl_8049AAB4[];
extern "C" char __vt__11J3DTevBlock[];
extern "C" void** fn_800CBCE8(void** param_1, short param_2) {
    if (param_1 != NULL) {
        *param_1 = lbl_8049AAB4;
        if (param_1 != NULL) {
            *param_1 = __vt__11J3DTevBlock;
        }
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_800CBD48(void) {}

extern "C" void fn_800CBD4C(void) {}

extern "C" void fn_800CBD50(void) {}

extern "C" void fn_800CBD54(void) {}

extern "C" void fn_800CBD58(void) {
}

extern "C" void fn_800CBD5C(void) {
}

extern "C" void fn_800CBD60(void) {
}

extern "C" void fn_800CBD64(void) {
}

extern "C" void fn_800CBD68(void) {
}

extern "C" s32 fn_800CBD6C(void) {
    return 0;
}

extern "C" void fn_800CBD74(void) {
}

extern "C" void fn_800CBD78(void)
{
}

extern "C" void fn_800CBD7C(void)
{
}

extern "C" s32 fn_800CBD80(void)
{
    return 0;
}

extern "C" void fn_800CBD88(void)
{
}

extern "C" s32 fn_800CBD8C(void) {
    return 0;
}

extern "C" void fn_800CBD94(void) {
}

extern "C" void fn_800CBD98(void) {
}

extern "C" void fn_800CBD9C(void) {
}

extern "C" void fn_800CBDA0(void) {
}

extern "C" void fn_800CBDA4(void) {
}

extern "C" int fn_800CBDA8(void) {
    return 0;
}

extern "C" void fn_800CBDB0(void) {
}

extern "C" int fn_800CBDB4(void) {
    return 0;
}

extern "C" int fn_800CBDBC(void) {
    return 0;
}

extern "C" int fn_800CBDC4(void) {
    return 0;
}

extern "C" void fn_800CBDCC(void) {
}

extern "C" void fn_800CBDDC(void) {
}

extern "C" void fn_800CBDE0(void) {
}

extern "C" void fn_800CBDE4(void) {
}

extern "C" void fn_800CBDE8(void) {
}

extern "C" void fn_800CBDEC(void) {
}

extern "C" u32 fn_800CBDF0(void) {
    return 0x54474E4C;
}

extern "C" char lbl_8049ABFC[];
extern "C" char __vt__13J3DColorBlock[];
extern "C" char lbl_8049AA38[];
extern "C" char __vt__10J3DPEBlock[];
extern "C" void __dl__FPv(void*);
extern "C" char lbl_8049AB90[];
extern "C" char __vt__14J3DTexGenBlock[];
extern "C" void** fn_800CBDFC(void** param_1, short param_2) {
    if (param_1 != NULL) {
        *param_1 = lbl_8049AB90;
        if (param_1 != NULL) {
            *param_1 = __vt__14J3DTexGenBlock;
        }
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" u32 fn_800CBE58(void) {
    return 0x434c4e4c;
}

extern "C" void** fn_800CBE64(void** param_1, short param_2) {
    if (param_1 != NULL) {
        *param_1 = lbl_8049ABFC;
        if (param_1 != NULL) {
            *param_1 = __vt__13J3DColorBlock;
        }
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" void* fn_800CBEC0(const void* base, const void* offset) {
    if (offset == 0) {
        return 0;
    }
    return (void*)((unsigned int)base + (unsigned int)offset);
}

extern "C" void* fn_800CBED8(const void* base, const void* offset) {
    if (offset == 0) {
        return 0;
    }
    return (void*)((unsigned int)base + (unsigned int)offset);
}

extern "C" void* fn_800CBEF0(const void* base, const void* offset) {
    if (offset == 0) {
        return 0;
    }
    return (void*)((unsigned int)base + (unsigned int)offset);
}

extern "C" void* fn_800CBF20(const void* base, const void* offset) {
    if (offset == 0) {
        return 0;
    }
    return (void*)((int)base + (int)offset);
}

extern "C" void* fn_800CBF38(const void* base, const void* offset)
{
    if (offset == 0) return 0;
    return (void*)((int)base + (int)offset);
}

extern "C" void* fn_800CBF50(const void* base, const void* offset)
{
    if (offset == 0) return 0;
    return (void*)((int)base + (int)offset);
}

extern "C" void* fn_800CBF68(const void* base, const void* offset) {
    if (offset == 0) {
        return 0;
    }
    return (void*)((int)base + (int)offset);
}

extern "C" void* fn_800CBF80(const void* base, const void* offset) {
    if (offset == 0) {
        return 0;
    }
    return (void*)((unsigned int)base + (unsigned int)offset);
}

extern "C" void* fn_800CBF98(const void* base, const void* offset) {
    if (offset == 0) {
        return 0;
    }
    return (void*)((unsigned int)base + (unsigned int)offset);
}

extern "C" void* fn_800CBFB0(const void* base, const void* offset) {
    if (offset == 0) {
        return 0;
    }
    return (void*)((unsigned int)base + (unsigned int)offset);
}

extern "C" void* fn_800CBFC8(const void* base, const void* offset) {
    if (offset == 0) {
        return 0;
    }
    return (void*)((unsigned int)base + (unsigned int)offset);
}

extern "C" void* fn_800CBFE0(const void* base, const void* offset) {
    if (offset == 0) {
        return 0;
    }
    return (void*)((unsigned int)base + (unsigned int)offset);
}

extern "C" void* fn_800CBFF8(const void* base, const void* offset) {
    if (offset == 0) {
        return 0;
    }
    return (void*)((unsigned int)base + (unsigned int)offset);
}

extern "C" void* fn_800CC010(const void* base, const void* offset) {
    if (offset == 0) {
        return 0;
    }
    return (void*)((unsigned int)base + (unsigned int)offset);
}

extern "C" void* fn_800CC058(const void* base, const void* offset) {
    if (offset == 0) {
        return 0;
    }
    return (void*)((unsigned int)base + (unsigned int)offset);
}

extern "C" void* fn_800CC070(const void* base, const void* offset) {
    if (offset == 0) {
        return 0;
    }
    return (void*)((unsigned int)base + (unsigned int)offset);
}

