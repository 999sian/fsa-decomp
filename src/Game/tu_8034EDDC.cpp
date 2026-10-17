#include "types.h"

extern "C" s32 fn_8022F514(s32);
extern "C" s32 fn_8022CAF8(s32);
extern "C" void* fn_8023E724(s32);
extern "C" s32 fn_8022F3DC(s32);
extern const f32 lbl_80542618;
extern const f32 lbl_8054261C;
extern const f64 lbl_805425F8;

struct Actor {
    ~Actor();
};

extern "C" void __dt__5ActorFv(Actor* self, s16 flag);
extern u8 lbl_804ACA00[];
void operator delete(void* p);

extern "C" Actor* fn_8034EDDC(Actor* self, s16 flag) {
    if (self != 0) {
        *(u8**)self = lbl_804ACA00;
        __dt__5ActorFv(self, 0);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}

extern "C" u32 fn_8013CC50(u32 owner, void* pos, u16 id, s32 a, f32 f, s32 b, s32 c, s32 d, s32 e);
extern "C" void* fn_801F856C(void);
extern "C" void Actor_CreateByID(void* mgr, u32 id, s32 kind, void* pos, s32 a, s32 b, s32 c);
extern const f32 lbl_805425F0;
extern const f32 lbl_805425D8;
extern const f32 lbl_80542608;
extern "C" s16 fn_8022461C(s32);
extern "C" s32 fn_80350274(s32 param_1, s32 param_2, s32 param_3) {
    s32 r = (u16)fn_8022461C(param_3);
    if (r == 0x3a || r == 3 || (u32)(r - 0xd) <= 1 || r == 0x3b) {
        return 0;
    }
    return 1;
}

extern "C" u32 fn_8013CC50(u32 owner, void* pos, u16 id, s32 a, f32 f, s32 b, s32 c, s32 d, s32 e);
extern "C" void* fn_801F856C(void);
extern "C" void Actor_CreateByID(void* mgr, u32 id, s32 kind, void* pos, s32 a, s32 b, s32 c);
extern "C" void fn_801F0E34(void* self, u32 id, s32 b);
extern "C" void fn_803513C0(u8* self) {
    s32 kind = *(s32*)(self + 4);
    if (kind < 8) {
        fn_8013CC50(kind, self + 0xc, 0x459, 0, -3.0f, 0, 0, 1, 0);
    } else {
        Actor_CreateByID(fn_801F856C(), 0x4b4d5249, kind, self + 0xc, 0x83, -1, -1);
    }
}

