#include "types.h"
#include "Game/Actor.h"
#include "Game/ItemBase.h"

extern "C" char lbl_804A0FF8[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_80179150(Actor* p, s16 n)
{
    if (p != NULL) {
        *(void**)p = lbl_804A0FF8;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void fn_80158624(void* mgr, void* a, void* b, void* col, f32 scale);
extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern "C" void fn_801F02BC(void* this_, const char* name, s32 id, DrawRec* rec, s32 a, s32 b, s32 c, f32 s0, f32 s1);
extern "C" char lbl_80466868[];
extern void* lbl_8053AB10;
extern "C" void fn_801791B0(Actor* this_) {
    u8* p = (u8*)this_;
    if (this_->field_90 == 0xd) {
        DrawRec rec;
        rec.b1d = -1;
        fn_801F06F0(this_, lbl_80466868, 0x431, &rec, -1, 1.0f, 1.0f);
        fn_801F02BC(this_, lbl_80466868, 0x431, &rec, -1, 0, 0, 1.0f, 1.0f);
    } else {
        u32 col[4];
        col[1] = 0x3f3f1f7f;
        col[3] = 0x3f3f1f7f;
        fn_80158624(*(void**)((u8*)lbl_8053AB10 + 0x2c), p + 0x34c, p + 0xc, &col[1], *(f32*)(p + 0x344) * 0.7f);
        col[0] = 0x3f3f1f3f;
        col[2] = 0x3f3f1f3f;
        fn_80158624(*(void**)((u8*)lbl_8053AB10 + 0x2c), p + 0x34c, p + 0xc, &col[0], *(f32*)(p + 0x344));
    }
}

