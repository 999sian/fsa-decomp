#include "types.h"
#define GAME_ACTOR_USE_SDK_VEC
#include "JSystem/JGeometry/Vec.h"
#include "Game/Actor.h"
#include "Game/SinitPoolChain.h"

extern "C" void* fn_801F856C(void);
extern "C" u8* fn_801F666C(void* mgr, s32 idx);
extern "C" void v03__5ActorFv(void* this_);
extern "C" void detach__5ActorFv(void* this_);
extern "C" void fn_80230534(s32 idx);
extern "C" u8* lbl_8053AB10;

static inline void setState(u8* p, s32 s) {
    *(s32*)(p + 0x230) = s;
    switch (*(s32*)(p + 0x230)) {
    case 0:
    case 2:
    case 4:
        break;
    case 1:
        *(s32*)(p + 0x24c) = 0;
        break;
    case 3:
        *(s32*)(p + 0x248) = 0;
        break;
    case 5:
        fn_80230534(0);
        detach__5ActorFv(p);
        break;
    }
}
extern "C" s32 fn_8022FE80(s32 a, void* b, s32 c, s32 d, s32 e);
extern "C" u8 fn_8038BD08(s32 a, u16 id, void* b, Vec* pos, s32 c);
extern "C" void fn_80125C58(void* p, s32 x);

extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void v01__5ActorFv(void* this_);
void operator delete(void* p);
extern "C" char lbl_8049EA88[];
extern const f32 lbl_8053CC94;
extern const f32 lbl_8053CC98;
extern const f32 lbl_8053CC78;
extern const f32 lbl_8053CC7C;
extern const f32 lbl_8053CC80;
extern const f32 lbl_8053CC84;

extern "C" void* fn_80130310(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_8049EA88;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" Vec* fn_8023E724(s32 idx);
extern "C" s32 fn_801CD950(f32* p, f32 a, f32 b);
extern "C" void fn_80230BF4(s32 idx, s32 quad);
extern "C" void fn_80230498(s32 idx, Vec* v, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_802303FC(s32 idx, Vec* v, s32 a);
extern "C" s32 ClassifyBamAngleToQuadrant(u16 angle);
extern "C" s32 fn_80130370(u8* p) {
    s32 ret = 1;
    s32 i;
    u8* actor = fn_801F666C(fn_801F856C(), *(s32*)(p + 0x238));
    if (actor == NULL) {
        return 0;
    }
    Vec pos = *(Vec*)(actor + 0xc);
    pos.x = pos.x + lbl_8053CC78;
    pos.y = pos.y + lbl_8053CC7C;
    pos.x = pos.x + lbl_8053CC80;
    for (i = 0; i < 4; i++) {
        Vec v = *fn_8023E724(i);
        u16 angle = (u16)(JMath::atanTable_.atan2_(pos.x - v.x, pos.y - v.y) * lbl_8053CC84);
        s32 quad = ClassifyBamAngleToQuadrant(angle);
        bool a = true;
        bool b = true;
        if (fn_801CD950(&v.x, pos.x, JMath::sincosTable_.mTable[angle >> 5].first)) {
            ret = 0;
            a = false;
        }
        if (fn_801CD950(&v.y, pos.y, JMath::sincosTable_.mTable[angle >> 5].second)) {
            ret = 0;
            b = false;
        }
        fn_80230BF4(i, quad);
        if (a && b) {
            fn_80230BF4(i, 3);
            fn_80230498(i, fn_8023E724(i), 0x3f, 0xff, -0x80, -0x80, 1);
        } else {
            fn_802303FC(i, &v, 0xff);
        }
    }
    return ret;
}

#pragma dont_inline on
extern "C" s32 fn_8013056C(char* p, u16 id, s32 mode, s32 val) {
    u8* actor;
    Vec pos;
    s32 which = *(s32*)(p + 0x238);
    if (mode == 1) {
        which = *(s32*)(p + 0x234);
    }
    fn_8022FE80(0, *(void**)(p + 4), which, 1, 0);
    pos = *(Vec*)(p + 0xc);
    if (fn_8038BD08(0, id, *(void**)(p + 4), &pos, 0x22) != 0) {
        switch (mode) {
        case 0:
            actor = fn_801F666C(fn_801F856C(), *(s32*)(p + 0x234));
            if (actor != 0) {
                *(s32*)(actor + 0x98) = val;
                fn_80125C58(actor, 1);
            }
            break;
        case 1:
            actor = fn_801F666C(fn_801F856C(), *(s32*)(p + 0x238));
            if (actor != 0) {
                *(s32*)(actor + 0x98) = val;
                fn_80125C58(actor, 1);
            }
            break;
        case 2:
            actor = fn_801F666C(fn_801F856C(), *(s32*)(p + 0x238));
            if (actor != 0) {
                *(s32*)(actor + 0x98) = val;
                fn_80125C58(actor, 1);
                actor = fn_801F666C(fn_801F856C(), *(s32*)(p + 0x234));
                if (actor != 0) {
                    *(s32*)(actor + 0x98) = val;
                }
            }
            break;
        }
        return 0;
    }
    return -1;
}
#pragma dont_inline reset

extern const f32 lbl_8053CC88;
extern const f32 lbl_8053CC8C;
extern "C" u8 lbl_8049EA58[];
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D800C(void* a, s32 b);
extern "C" void fn_80125BF4(void);
extern "C" u8 fn_803865B8(s32 idx);
extern "C" void fn_80388EEC(s32 idx);
extern "C" void fn_801306BC(u8* p) {
    v03__5ActorFv(p);
    s32 st = *(s32*)(p + 0x230);
    if (st >= 2 && st <= 4) {
        u8* obj = *(u8**)(lbl_8053AB10 + 0x24);
        obj[0x179] = 1;
        f32 r = lbl_8053CC88;
        f32 y = *(f32*)(p + 0x10);
        f32 x = *(f32*)(p + 0xc);
        obj = *(u8**)(lbl_8053AB10 + 0x24);
        if (obj[0x7f5] == 0) {
            obj[0x7f4] = 1;
            *(s32*)(obj + 0x7f8) = 5;
            *(f32*)(obj + 0x808) = x;
            *(f32*)(obj + 0x80c) = y - r;
            *(f32*)(obj + 0x810) = x;
            *(f32*)(obj + 0x814) = r + y;
            obj[0x7f6] = 0;
        }
    }
    st = *(s32*)(p + 0x230);
    switch (st) {
    case 0:
        if ((*(u8 (**)(u8*))(*(u8**)p + 0x34))(p)) {
            setState(p, 1);
        }
        break;
    case 1:
        *(s32*)(p + 0x24c) += 1;
        if (*(s32*)(p + 0x24c) >= 0x78) {
            u8* h = fn_801F666C(fn_801F856C(), *(s32*)(p + 0x238));
            if (h != NULL && *(s32*)(h + 0x98) != 1) {
                *(s32*)(h + 0x98) = 1;
                fn_80125BF4();
            }
        }
        if (fn_802D800C(fn_802D6A9C(), *(s32*)(p + 0x23c))) {
            setState(p, 2);
        }
        break;
    case 2: {
        u8* mgr = *(u8**)(lbl_8053AB10 + 0x30);
        if (mgr[0x284] == 0) {
            mgr[0x284] = 1;
            *(f32*)(mgr + 0x28c) = lbl_8053CC8C;
        }
        if ((u8)fn_80130370(p)) {
            s32 i = 0;
            do {
                fn_80230BF4(i, 3);
                fn_80230498(i, fn_8023E724(i), 0x3f, 0xff, -0x80, -0x80, 1);
                i++;
            } while (i < 4);
            setState(p, 3);
        }
        break;
    }
    case 3: {
        u8* mgr = *(u8**)(lbl_8053AB10 + 0x30);
        if (mgr[0x284] == 0) {
            mgr[0x284] = 1;
            *(f32*)(mgr + 0x28c) = lbl_8053CC8C;
        }
        *(s32*)(p + 0x248) += 1;
        if (*(s32*)(p + 0x248) >= 0x3c) {
            if (*(s32*)(p + 0x244) >= 4) {
                setState(p, 5);
            } else {
                s32 off = *(s32*)(p + 0x244) * 12;
                u8* e = lbl_8049EA58 + off;
                if (fn_8013056C((char*)p, *(u16*)e, *(s32*)(e + 4), *(s32*)(e + 8)) >= 0) {
                    setState(p, 4);
                }
            }
        }
        break;
    }
    case 4: {
        u8* mgr = *(u8**)(lbl_8053AB10 + 0x30);
        if (mgr[0x284] == 0) {
            mgr[0x284] = 1;
            *(f32*)(mgr + 0x28c) = lbl_8053CC8C;
        }
        fn_8022FE80(0, *(void**)(p + 4), *(s32*)(p + 0x198), 1, 0);
        u8 ok;
        if (fn_803865B8(0) == 0) {
            ok = 0;
        } else {
            fn_80388EEC(0);
            s32 which = 0;
            s32 off = *(s32*)(p + 0x244) * 12;
            u8* e = lbl_8049EA58 + off;
            switch (*(s32*)(e + 4)) {
            case 1:
                which = *(s32*)(p + 0x238);
                break;
            case 0:
                which = *(s32*)(p + 0x234);
                break;
            case 2:
                which = *(s32*)(p + 0x238);
                break;
            }
            u8* h = fn_801F666C(fn_801F856C(), which);
            if (h != NULL) {
                fn_80125C58(h, 0);
            }
            ok = 1;
        }
        if (ok) {
            *(s32*)(p + 0x244) += 1;
            setState(p, 3);
        }
        break;
    }
    case 5:
        break;
    }
}

extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F7884(void* mgr, u32 tag, s32 id);
extern "C" u8* fn_801F666C(void* mgr, s32 idx);
extern "C" s32 fn_801F78F4(void* mgr, u32 tag, s32 idx);
extern const f32 lbl_8053CC90;
extern "C" void fn_80130C18(char* p) {
 s32 idx=fn_801F7884(fn_801F856C(),0x4f504741,*(s32*)(p+4));
 while(idx!=-1) {
  u8* actor=fn_801F666C(fn_801F856C(),idx);
  if(actor!=0) {
   if(*(s32*)(actor+0x238)==1) *(s32*)(p+0x238)=*(s32*)(actor+0x198);
   else *(s32*)(p+0x234)=*(s32*)(actor+0x198);
   idx=fn_801F78F4(fn_801F856C(),0x4f504741,idx);
  }
 }
 u8* actor=fn_801F666C(fn_801F856C(),*(s32*)(p+0x238));
 *(JGeometry::TVec3<f32>*)(p+0xc)=*(JGeometry::TVec3<f32>*)(actor+0xc);
 *(f32*)(p+0x10)+=lbl_8053CC90;
}

extern "C" void fn_80130CEC(char* p) {
    v01__5ActorFv(p);
    f32 b = lbl_8053CC98;
    f32 a = lbl_8053CC94;
    *(f32*)(p + 0x60) = a;
    *(f32*)(p + 0x64) = a;
    *(f32*)(p + 0x68) = b;
    *(f32*)(p + 0x6c) = b;
    *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
    *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
    *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
    *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
    *(f32*)(p + 0x80) = *(f32*)(p + 0x60);
    *(f32*)(p + 0x84) = *(f32*)(p + 0x64);
    *(f32*)(p + 0x88) = *(f32*)(p + 0x68);
    *(f32*)(p + 0x8c) = *(f32*)(p + 0x6c);
    *(u32*)(p + 0x23c) = (*(u32*)(p + 0x90) >> 0x16) & 0x1f;
    *(u32*)(p + 0x240) = (*(u32*)(p + 0x90) >> 0x11) & 0x1f;
}

