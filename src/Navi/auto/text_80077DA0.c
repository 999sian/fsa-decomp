#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80077da0-0x8007bc94 (37 functions). split_file divides it into the game's real files.

extern void* lbl_80282198[];
extern "C" void fn_8007A404(void* param_1, void* param_2);
extern "C" void fn_800636F4(void* param_1, void* param_2, s32 param_3);
extern "C" void fn_800127A0(void* param_1);
extern void* lbl_80281950[];
extern void* lbl_8028216C[];
extern void* lbl_80281904[];
extern s32 lbl_802FCB30;
extern char lbl_802B7CA0[];
extern char lbl_802BB0FC[];
extern char lbl_802C4F3C[];
extern char lbl_8029FDB4[];
extern char lbl_802EE470[];
extern f32 lbl_803006D4;
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_80077F44(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80282198;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" BOOL fn_8007820C(void);
extern "C" BOOL fn_8007820C(void)
{
    return TRUE;
}

#pragma push
#pragma use_lmw_stmw off
extern "C" void fn_800782C0(char* param_1, char* param_2) {
    u32 i = 0;
    char* data = lbl_802EE470;
    u32 off = 0;
    do {
        if (*(u16*)(param_1 + off + 0x16) != 0) {
            char* obj = *(char**)(param_2 + 0x28);
            char* g = *(char**)(*(char**)(data + 0x38) + 0x14);
            char* part = (char*)((void* (*)(void*, u32))((void**)*(void**)obj)[0x50 / 4])(obj, i);
            *(f32*)(part + 0x1c) = *(f32*)(part + 0x1c) + *(f32*)(g + 0x418);
            *(f32*)(part + 0x20) = *(f32*)(part + 0x20) + *(f32*)(g + 0x41c);
        }
        i++;
        off += 8;
    } while (i < 8);
}
#pragma pop

extern "C" void fn_80078414(void);
extern "C" void fn_80078364(void) {
    fn_80078414();
}

extern "C" u8 fn_8000D6F4(void* param_1);
extern "C" BOOL fn_8007A190(void* param_1) {
    char* p = (char*)param_1;
    if (p[0x443] == 0) {
        p[0x443] = p[0x443] + 1;
    } else if (p[0x443] != -1) {
        float* sample;
        p[0x447] = fn_8000D6F4(p + 0x38c);
        sample = *(float**)(p + 0x390);
        if (sample[3] < 0.0f) {
            if (*(float*)(p + 0x40c) < sample[4]) {
                p[0x447] = 1;
            }
        } else if (sample[3] > 0.0f) {
            if (*(float*)(p + 0x40c) > sample[4]) {
                p[0x447] = 1;
            }
        }
        *(float*)(p + 0x40c) = (*(float**)(p + 0x390))[4];
    }
    return TRUE;
}

extern "C" BOOL fn_8007A348(void* param_1) {
    char* p = (char*)param_1;
    if (p[0x445] != 0) {
        s32* table = (s32*)lbl_80281950[*(s32*)(p + 0x3e4)];
        s32 count = *(s32*)(p + 0x3ec);
        if (count == 0) {
            *(s32*)(p + 0x3e8) += 1;
            fn_8007A404(param_1, (void*)table[*(s32*)(p + 0x3e8) * 2]);
            *(s32*)(p + 0x3ec) = table[*(s32*)(p + 0x3e8) * 2 + 1];
        } else if (count > 0) {
            *(s32*)(p + 0x3ec) = count - 1;
            fn_8007A404(param_1, (void*)table[*(s32*)(p + 0x3e8) * 2]);
        } else {
            return 1;
        }
    }
    return 0;
}

extern "C" void fn_80078384(void);
extern "C" void fn_8007BB2C(void) {
    fn_80078384();
}

extern "C" void fn_8007A404(void* param_1, void* param_2);
extern "C" void fn_800636F4(void* param_1, void* param_2, s32 param_3);
extern "C" void fn_800127A0(void* param_1);
extern "C" BOOL fn_8007BB4C(void) {
    *(s32*)((char*)lbl_802BB0FC + 0x38) = 0;
    fn_800636F4((void*)&lbl_802FCB30, lbl_802B7CA0 + 0x2200, 0x40);
    s8* st = (s8*)lbl_802C4F3C;
    s8 flag = st[4];
    if (flag >= 0) {
        if (--*(s32*)(st + 8) == 0) {
            fn_800127A0(lbl_8029FDB4 + 4);
            st[4] = -1;
        }
    }
    return 1;
}

extern "C" void fn_8007B638(void);
extern "C" void fn_8007BBD8(void) {
    fn_8007B638();
}

extern "C" void fn_80078F94(void);
extern "C" void fn_8007BBF8(void) {
    fn_80078F94();
}

extern "C" BOOL fn_8007BC18(void);
extern "C" BOOL fn_8007BC18(void)
{
    return TRUE;
}

extern "C" void* fn_8007BC20(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = lbl_8028216C;
        if ((s32)param_1 + 0x38 != 0) {
            *(void**)((char*)param_1 + 0x38) = lbl_80282198;
        }
        if ((s32)param_1 + 0xc != 0) {
            *(void**)((char*)param_1 + 0xc) = lbl_80281904;
        }
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

