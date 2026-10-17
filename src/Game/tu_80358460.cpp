#include "types.h"
#include "JSystem/JGeometry/Vec.h"

struct Actor;


struct Unk8035A1D4;
typedef void (Unk8035A1D4::*Unk8035A1D4Func)();
extern Unk8035A1D4Func lbl_804AD30C[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" char lbl_804AD348[];
struct Vec8035A860 { f32 x, y, z; };
extern "C" Actor* fn_80358460(Actor* p, s16 n) {
    if (p != 0) {
        *(void**)p = lbl_804AD348;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void fn_8035A1D4(Unk8035A1D4* self) {
    u32 v = *(u32*)((u8*)self + 0x90);
    (self->*lbl_804AD30C[(v >> 7) & 0x1f])();
}

extern "C" Vec8035A860* fn_8023E724(void*);
extern "C" void fn_8022BE24(void*, Vec8035A860*);
extern "C" unsigned char sincosTable___5JMath[];
extern "C" void fn_8035A860(u8* self, void* obj, f32 speed) {
    Vec8035A860 pos = *fn_8023E724(obj);
    Vec8035A860 d;
    d.x = pos.x - *(f32*)(self + 0xc);
    d.y = pos.y - *(f32*)(self + 0x10);
    d.z = pos.z - *(f32*)(self + 0x14);
    d.z = 0.0f;
    bool inside = false;
    if (d.x >= *(f32*)(self + 0x60) + 10.0f && d.y >= *(f32*)(self + 0x64)
        && d.x < *(f32*)(self + 0x68) - 10.0f && d.y < *(f32*)(self + 0x6c)) {
        inside = true;
    }
    if (inside) {
        s16 ang = *(s16*)(self + 0x230);
        f32* tbl = (f32*)((char*)sincosTable___5JMath + ((ang >> 5) << 3));
        f32 s = 0.5f * __fabs(tbl[0]) * (__fabs(speed) / (*(f32*)(self + 0x6c) * __fabs(tbl[1])));
        if (s > 0.5f) s = 0.5f;
        f32 r;
        if (*(u8*)(self + 0x244) == 0) {
            if ((f32)*(s16*)(self + 0x230) * speed >= 0.0f) r = 1.0f - s;
            else r = 1.0f + s;
        } else {
            if ((f32)*(s16*)(self + 0x230) * speed >= 0.0f) r = 1.0f + s;
            else r = 1.0f - s;
        }
        Vec8035A860 sc;
        sc.x = r;
        sc.y = 1.0f;
        sc.z = r;
        fn_8022BE24(obj, &sc);
    }
}

