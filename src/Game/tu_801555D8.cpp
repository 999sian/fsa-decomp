#include "types.h"
#include "Game/Actor.h"

extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void*, s32);
extern void* lbl_804A00C8[];
extern f32 lbl_8053D378;
extern f32 lbl_8053D39C;
extern "C" void __dt__5ActorFv(void*, s32);
extern "C" void __dl__FPv(void*);
extern "C" void fn_80157E20(char* self) {
    s32 idx = *(s32*)(self + 0x284);
    if (idx >= 0) {
        void* p = fn_801F666C(fn_801F856C(), idx);
        if (p != NULL) {
            Vec v;
            Vec* pv = &v;
            pv->x = 0.0f;
            pv->y = 0.0f;
            pv->z = 5.0f;
            *(Vec*)((char*)p + 0x3c) = *pv;
        }
        *(s32*)(self + 0x284) = -1;
    }
    if (*(s32*)(self + 0x108) <= 0) {
        s32 idx2 = *(s32*)(self + 0x280);
        if (idx2 >= 0) {
            void* p = fn_801F666C(fn_801F856C(), idx2);
            if (p != NULL) {
                *(s32*)((char*)p + 0x290) -= 1;
            }
        }
    }
}

extern "C" void fn_801583D4(void* thisObj, f32 x, f32 y, f32 z) {
	*(f32*)((char*)thisObj + 0x0) = x;
	*(f32*)((char*)thisObj + 0x4) = y;
	*(f32*)((char*)thisObj + 0x8) = z;
}

extern "C" void fn_801583E4(f32* dst, const f32* src) { dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2]; }
