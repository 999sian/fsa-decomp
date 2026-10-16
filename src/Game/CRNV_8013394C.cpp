#include "types.h"

extern "C" void fn_801EE434(void* obj);
extern "C" void __dt__5ActorFv(void* this_, s16 freeFlag);
void operator delete(void* p);
extern "C" void* __vt__4CRNV[];
extern void* lbl_8049CC34[];
extern f32 lbl_8053CD30;
extern "C" void* fn_8013394C(u8* this_, s16 freeFlag) {
    if (this_ != 0) {
        s32 i = 0;
        u8* p = this_;
        *(void**)this_ = __vt__4CRNV;
        u32 zero = i;
        do {
            fn_801EE434(*(void**)(p + 0x278));
            i++;
            *(void**)(p + 0x278) = (void*)zero;
            p += 4;
        } while (i < 2);
        if (this_ + 0x240 != 0) {
            if (this_ + 0x264 != 0) {
                *(void**)(this_ + 0x264) = lbl_8049CC34;
            }
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F7A08(void* pool, s32 type);
extern "C" void* fn_801F666C(void* reg, s32 id);
extern "C" s32 fn_801F78F4(void* pool, s32 type, s32 afterId);
extern "C" void fn_801EE434(void* p);
extern "C" void detach__5ActorFv(void* actor);
extern f32 lbl_8053CD34;
extern "C" s32 fn_80133B58(void) {
    s32 ret = 1;
    char* actor;
    s32 id;
    bool ok;
    s32 i;
    void** slot;

    id = fn_801F7A08(fn_801F856C(), 0x43524e56);
    while (id != -1) {
        actor = (char*)fn_801F666C(fn_801F856C(), id);
        if (actor == NULL) {
            break;
        }
        if (*(s32*)(actor + 0x230) == 1) {
            ok = false;
        } else {
            *(s32*)(actor + 0x230) = 2;
            switch (*(s32*)(actor + 0x230)) {
            case 0:
                *(s32*)(actor + 0x238) = -1;
                break;
            case 2:
                *(f32*)(actor + 0x23c) = lbl_8053CD34;
                break;
            case 3:
                slot = (void**)(actor + 0x278);
                for (i = 0; i < 2; i++) {
                    fn_801EE434(*slot);
                    *slot = NULL;
                    slot++;
                }
                detach__5ActorFv(actor);
                break;
            }
            ok = true;
        }
        if (!ok) {
            ret = 0;
        }
        id = fn_801F78F4(fn_801F856C(), 0x43524e56, id);
    }
    return ret;
}

extern "C" void v01__5ActorFv(void* this_);
extern "C" void fn_801D2608(void*, void*, s32);
extern "C" void fn_801D22DC(void*, s32, s32, s32);
extern "C" void fn_801D1F14(void*, f32);
extern "C" s32 fn_8013CC50(s32 id, void* p, f32 f, s32 a, s32 b, s32 c, s32 d, s32 e, s32 g);
extern u8 lbl_80539F50[8];
extern f32 lbl_8053CD30;
extern f32 lbl_8053CD48;
extern f32 lbl_8053CD4C;
extern "C" void fn_8013416C(u8* param_1)
{
    v01__5ActorFv(param_1);
    *(s32*)(param_1 + 0x234) = *(u32*)(param_1 + 0x90) & 0x1f;
    *(f32*)(param_1 + 0x60) = lbl_8053CD48;
    *(f32*)(param_1 + 0x64) = lbl_8053CD48;
    *(f32*)(param_1 + 0x68) = lbl_8053CD4C;
    *(f32*)(param_1 + 0x6c) = lbl_8053CD4C;
    *(f32*)(param_1 + 0x70) = *(f32*)(param_1 + 0x60);
    *(f32*)(param_1 + 0x74) = *(f32*)(param_1 + 0x64);
    *(f32*)(param_1 + 0x78) = *(f32*)(param_1 + 0x68);
    *(f32*)(param_1 + 0x7c) = *(f32*)(param_1 + 0x6c);
    *(f32*)(param_1 + 0x80) = *(f32*)(param_1 + 0x60);
    *(f32*)(param_1 + 0x84) = *(f32*)(param_1 + 0x64);
    *(f32*)(param_1 + 0x88) = *(f32*)(param_1 + 0x68);
    *(f32*)(param_1 + 0x8c) = *(f32*)(param_1 + 0x6c);
    fn_801D2608(param_1 + 0x240, lbl_80539F50, 1);
    fn_801D22DC(param_1 + 0x240, 0, 2, 0);
    fn_801D1F14(param_1 + 0x240, lbl_8053CD34);
    if (*(s32*)(param_1 + 0x278) == 0) {
        *(s32*)(param_1 + 0x278) = fn_8013CC50(*(s32*)(param_1 + 4), param_1 + 0xc, lbl_8053CD30, 0x32c, 0, 0, 0, 0, 1);
    }
    if (*(s32*)(param_1 + 0x27c) == 0) {
        *(s32*)(param_1 + 0x27c) = fn_8013CC50(*(s32*)(param_1 + 4), param_1 + 0xc, lbl_8053CD30, 0x183, 0, 0, 0, 0, 1);
    }
}

