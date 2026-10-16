#include "Game/esd/types.h"


extern "C" void fn_801F132C(void* a, s32 b, s32 c, s32* d);
extern "C" void fn_801F06F0(void* actor, const char* file, s32 idx, s32 a, s32 b, f32 sx, f32 sy);
extern "C" void fn_803075AC(void*, s32, void*, s32, s32, s32, s32, s32, s32, s32);
extern "C" void __dt__5ActorFv(void* this_, int how);
void operator delete(void* p);
extern "C" char lbl_804A9480[];
extern "C" char lbl_8046E118[];
extern const f32 lbl_80540F1C;
extern const f32 lbl_80540F24;
extern const f32 lbl_80540F28;
extern const f32 lbl_80540F2C;
extern const f32 lbl_80540F30;
extern "C" void fn_802D2B04(void* this_, s32 b, s32 c) {
    fn_801F132C(this_, b, c, (s32*)((char*)this_ + 0x234));
}
