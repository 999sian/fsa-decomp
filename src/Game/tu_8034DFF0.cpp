#include "Game/Actor.h"

struct YnswVirt {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual s32 v13();
};
extern const f32 lbl_805425CC;
extern const f32 lbl_805425D0;
extern const f32 lbl_805425D4;


extern "C" char __vt__4YNSW[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_8034DFF0(Actor* p, s16 n) {
    if (p) {
        *(void**)p = __vt__4YNSW;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}
