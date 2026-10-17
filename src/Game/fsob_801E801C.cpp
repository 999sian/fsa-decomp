// Game TU 801E801C-801E9AFC (FSOB). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
#include "JSystem/JMath/JMath.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_804A5568[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern "C" void* fn_801E9AFC();
extern "C" void fn_801EA108(void* mgr, void* pos, s32 a, f32 r);
extern "C" void fn_8030C210(void* mgr, void* pos);
extern "C" u8 fn_801F2B7C(void* this_, s32 a, s32 b, s32 c);
extern "C" s32 fn_801E9B58(void* this_);
extern "C" void* fn_8013C824();
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* mgr, void* emitter);
extern "C" void* fn_8013CC50(u32 id, void* pos, s32 type, s32 p4, s32 p5, u32 p6, u32 p7, u32 p8, f32 f);
extern "C" void fn_801D0ED0(void* this_);
extern "C" void fn_801D0F40(char* p);
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void __ct__Q29JGeometry8TVec2_f_Fv();
extern f32 lbl_8053F5FC;
struct Fsob8B10 { u8 pad[0x24]; void* m24; };
extern Fsob8B10* lbl_8053AB10;

extern "C" void fn_801E801C(char* p) {
    static f32 radius = -256.0f;
    if (*(s32*)(p + 0x248) == 0) {
        fn_801EA108(fn_801E9AFC(), p + 0xc, *(s16*)(p + 0x3bc), radius);
    }
}

struct FsobVec2 {
    f32 x, y;
};

extern "C" void fn_801E8EB4(char* p, u8 idx, s32 unused, FsobVec2* v) {
    f32 x = v->x;
    f32 y = v->y;
    *(u32*)(p + 0x2a8) |= 1 << idx;
    p += idx * 8;
    *(f32*)(p + 0x2b0) = x;
    *(f32*)(p + 0x2b4) = y;
}

extern "C" void fn_801E8EE8(char* p) {
    if (*(u32*)(p + 0x230) & 0x2000) {
        fn_8030C210(lbl_8053AB10->m24, p + 0xc);
    }
}

extern "C" u8 fn_801E8F20(char* p) {
    u8 ret = 0;
    if (*(u32*)(p + 0x230) & 0x2000) {
        f32 x0 = *(f32*)(p + 0x60);
        f32 y0 = *(f32*)(p + 0x64);
        f32 x1 = *(f32*)(p + 0x68);
        f32 y1 = *(f32*)(p + 0x6c);
        *(f32*)(p + 0x60) = -8.0f;
        *(f32*)(p + 0x64) = -8.0f;
        *(f32*)(p + 0x68) = 8.0f;
        *(f32*)(p + 0x6c) = 8.0f;
        ret = fn_801F2B7C(p, 0, -1, 0x16);
        *(f32*)(p + 0x60) = x0;
        *(f32*)(p + 0x64) = y0;
        *(f32*)(p + 0x68) = x1;
        *(f32*)(p + 0x6c) = y1;
    }
    return ret;
}

extern "C" s32 fn_801E8FE8(char* p) {
    if (*(s32*)(p + 0x248) == 0 && *(f32*)(p + 0x68) - *(f32*)(p + 0x60) > 0.0f &&
        *(f32*)(p + 0x6c) - *(f32*)(p + 0x64) > 0.0f && fn_801E9B58(p) >= 0) {
        *(u32*)(p + 0x230) |= 0x2000;
        if (*(void**)(p + 0x3c0) != 0) {
            void* mgr = *(void**)((char*)fn_8013C824() + 0xc);
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)(p + 0x3c0));
        }
        *(void**)(p + 0x3c0) = fn_8013CC50(*(u32*)(p + 0x4), p + 0xc, 0x260, 0, -2, 0, 0, 1, 1.0f);
        *(s32*)(p + 0x24c) = 0;
        *(s32*)(p + 0x248) = 1;
    }
    return 0;
}

struct FsobBox {
    f32 x0, y0, x1, y1;
};
static inline void setBox(FsobBox* b, f32 r) {
    b->x0 = -r;
    b->y0 = -r;
    b->x1 = r;
    b->y1 = r;
}

extern "C" void fn_801E96F8(char* p) {
    fn_801D0ED0(p);
    *(u8*)(p + 0x2ac) = *(u32*)(p + 0x90);
    f32 r = 6.0f;
    *(f32*)(p + 0x64) = *(f32*)(p + 0x60) = -r;
    *(f32*)(p + 0x6c) = *(f32*)(p + 0x68) = r;
    *(f32*)(p + 0x70) = 1.0f;
    *(f32*)(p + 0x74) = 1.0f;
    *(f32*)(p + 0x78) = -1.0f;
    *(f32*)(p + 0x7c) = -1.0f;
    *(f32*)(p + 0x80) = 1.0f;
    *(f32*)(p + 0x84) = 1.0f;
    *(f32*)(p + 0x88) = -1.0f;
    *(f32*)(p + 0x8c) = -1.0f;
    *(u32*)(p + 0xb0) = 0;
    *(u32*)(p + 0x98) = 2;
    *(u32*)(p + 0x230) |= 0x280;
    *(s32*)(p + 0x108) = 1000;
    *(s32*)(p + 0x244) = *(s32*)(p + 0x108);
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = -1;
    *(f32*)(p + 0x254) = 0.0f;
    *(f32*)(p + 0x258) = 0.0f;
}

extern "C" int fn_801E90BC(void) { return 0; }

extern f32 lbl_8053F600;
extern "C" void fn_801E9224(void);
extern "C" void fn_801E6EAC(void);
extern "C" void fn_8013CB44(void* a, void* b, s32 c, s32 d, s32 e);
extern "C" void fn_801F0E34(void* this_, s32 a, s32 b);
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D800C(void* a, u16 b);
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F666C(void* a, s32 b);
extern "C" void fn_801E90C4(char* p) {
    switch (*(s32*)(p + 0x248)) {
    case 0: {
        u16 sVar = *(u16*)(p + 0x94);
        if (sVar != 0) {
            void* a = fn_802D6A9C();
            if (fn_802D800C(a, sVar) != 0) {
                *(u32*)(p + 0x230) |= 0x2000;
                if (*(void**)(p + 0x3c0) != 0) {
                    void* mgr = *(void**)((char*)fn_8013C824() + 0xc);
                    forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)(p + 0x3c0));
                }
                *(void**)(p + 0x3c0) = fn_8013CC50(*(u32*)(p + 0x4), p + 0xc, 0x260, 0, -2, 0, 0, 1, lbl_8053F600);
                *(s32*)(p + 0x24c) = 0;
                *(s32*)(p + 0x248) = 1;
            }
        }
    } break;
    case 1:
        fn_801E9224();
        fn_8013CB44(*(void**)(p + 0x3c0), p + 0xc, 0, -2, 1);
        fn_801F0E34(p, 0x3003e, 0);
        if (*(u32*)(p + 0x230) & 0x4000) {
            s32 idx = *(s32*)(p + 0x3b8);
            if (idx >= 0) {
                void* a = fn_801F856C();
                if (fn_801F666C(a, idx) != 0) {
                    fn_801E6EAC();
                }
            }
            *(u32*)(p + 0x230) &= ~0x2000;
            fn_801EE434(*(void**)(p + 0x3c0));
            *(void**)(p + 0x3c0) = 0;
            *(s32*)(p + 0x24c) = 0;
            *(s32*)(p + 0x248) = 2;
        }
        break;
    default:
        break;
    }
}

extern "C" void* fn_801E97B4(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A5568;
        fn_801EE434(*(void**)(p + 0x3c0));
        if (this_ != 0) {
            *(void**)p = lbl_804A4808;
            if (p + 0x270 != 0) {
                if (p + 0x294 != 0) {
                    *(void**)(p + 0x294) = lbl_8049CC34;
                }
            }
            __dt__5ActorFv(this_, 0);
        }
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" char* fn_801E9850(char* p) {
    fn_801D0F40(p);
    *(void***)p = lbl_804A5568;
    *(u32*)(p + 0x2a8) = 0;
    *(u8*)(p + 0x2ac) = 0;
    *(u8*)(p + 0x2ad) = 0;
    __construct_array(p + 0x2b0, (void*)__ct__Q29JGeometry8TVec2_f_Fv, 0, 8, 0x20);
    *(u8*)(p + 0x3b0) = 0;
    *(f32*)(p + 0x3b4) = 0.0f;
    *(s32*)(p + 0x3b8) = -1;
    *(s16*)(p + 0x3bc) = 0;
    *(u32*)(p + 0x3c0) = 0;
    return p;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
