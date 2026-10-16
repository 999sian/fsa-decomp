#include "types.h"
extern "C" {
extern const f32 lbl_8053F65C;
extern const f32 lbl_8053F660;
extern const f32 lbl_8053F664;
extern s8 lbl_8053AC50;
extern u8 lbl_804CA358[];
extern u8 lbl_80469C78[];
extern f32 sincosTable___5JMath[];

void* fn_801F856C(void);
s32 fn_801F7F58(void* a, void* b, void* c, s32 d, f32 e);
void* fn_801F666C(void* a, s32 b);
u8 fn_801CC8E4(void);
void fn_802BAA00(void* p);
void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
void fn_801E9B54(void);
}

extern "C" void* fn_801E9AFC(void) {
    if (lbl_8053AC50 == 0) {
        __construct_array(lbl_804CA358, (void*)fn_801E9B54, NULL, 0x78, 2);
        lbl_8053AC50 = 1;
    }
    return lbl_804CA358;
}

extern "C" void fn_801E9B54(void) {
}

extern "C" s32 fn_801E9B58(u8* param_1) {
    s32 iVar2;
    void* iVar3;

    iVar2 = fn_801F7F58(fn_801F856C(), param_1, lbl_80469C78, *(s32*)(param_1 + 0x198), lbl_8053F65C);
    if (iVar2 >= 0 && iVar2 != *(s32*)(param_1 + 0x198)) {
        iVar3 = fn_801F666C(fn_801F856C(), iVar2);
        if (iVar3 != NULL) {
            if (fn_801CC8E4() != 0) {
                iVar2 = -1;
            } else if (*(u32*)((u8*)iVar3 + 0x1a0) == 0x46495245) {
                fn_802BAA00(iVar3);
            }
        }
    }
    return iVar2;
}

