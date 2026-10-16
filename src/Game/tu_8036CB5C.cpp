#include "Game/Actor.h"


extern "C" char lbl_804AE230[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" u8* lbl_8053AAF8;
extern "C" u8* lbl_8053AB10;
extern "C" f32 lbl_80542CE4;
extern "C" const char lbl_80474EAC[];
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
extern "C" Actor* fn_8036CB5C(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804AE230;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void fn_8036CE58(Actor* this_) {
    u8* p = (u8*)this_;
    s32 id = *(s32*)(p + 0x24c) + 0x147;
    if (*(s32*)(p + 4) < 8) {
        SobResMgr* mgr = *(SobResMgr**)(lbl_8053AAF8 + 0xa4);
        void* res = mgr->vf18('SOB ', lbl_80474EAC);
        fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), p + 0x24, res, id, 0, lbl_80542CE4, lbl_80542CE4);
    }
    fn_803075AC(*(void**)(p + 0x198), *(s32*)(p + 4), p + 0x24, *(s32*)(p + 0x24c) + 0x147, 0, 1, -1, 0, 0, 0);
}

