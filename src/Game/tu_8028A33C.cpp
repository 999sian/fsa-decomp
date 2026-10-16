#include "Game/Actor.h"


extern "C" char lbl_804A7908[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" u8* lbl_8053AAF8;
extern "C" u8* lbl_8053AB10;
extern "C" f32 lbl_80540490;
extern "C" const char lbl_8046C0E8[];
extern "C" void fn_802F86CC(void*, void*, void*, s32, s32, f32, f32);
extern "C" void fn_803075AC(void*, s32, void*, s32, s32, s32, s32, s32, s32, s32);

class SobResMgr {
public:
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void* vf18(u32 type, const char* name);
};
extern "C" Actor* fn_8028A33C(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804A7908;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}
