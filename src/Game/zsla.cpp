// TU 0x802223fc-0x80222cc4 (actor ZSLA).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"

extern "C" {
void fn_801CDD58();
void fn_801CE120();
void fn_801CE4BC();
void fn_801CE4E4();
void fn_801CE594();
void fn_801CE694();
void fn_801CE914();
void fn_801CE918();
void fn_801CE920();
void fn_801CE928();
void fn_801CE98C();
void fn_801CEB78();
void fn_801CECEC();
void fn_801D0ECC();
void fn_80220F54();
void fn_80221114();
void fn_80221158();
void fn_80221160();
void fn_80221184();
void fn_80221210();
void v02__5ActorFv();
void v04__5ActorFv();
void v05__5ActorFv();
void v07__5ActorFv();
void v08__5ActorFv();
void v09__5ActorFv();
void v10__5ActorFUlUl();
void v11__5ActorFv();
void v12__5ActorFv();
void v13__5ActorFv();
void v14__5ActorFv();
void v15__5ActorFv();
void v16__5ActorFv();
void v17__5ActorFiPf();
void v18__5ActorFiPf();
void* fn_802223FC(void* this_, s16 freeFlag);
void fn_802229EC(void* this_);
void fn_8022249C(void* this_);
void fn_802224D0(void* this_);
}
void* lbl_804A6B70[] = {
    0,
    0,
    (void*)fn_802223FC,
    (void*)fn_802229EC,
    (void*)v02__5ActorFv,
    (void*)fn_801CDD58,
    (void*)v04__5ActorFv,
    (void*)v05__5ActorFv,
    (void*)fn_80220F54,
    (void*)v07__5ActorFv,
    (void*)v08__5ActorFv,
    (void*)v09__5ActorFv,
    (void*)v10__5ActorFUlUl,
    (void*)v11__5ActorFv,
    (void*)v12__5ActorFv,
    (void*)v13__5ActorFv,
    (void*)v14__5ActorFv,
    (void*)v15__5ActorFv,
    (void*)v16__5ActorFv,
    (void*)v17__5ActorFiPf,
    (void*)v18__5ActorFiPf,
    (void*)fn_801D0ECC,
    (void*)fn_801CECEC,
    (void*)fn_801CEB78,
    (void*)fn_80221158,
    (void*)fn_801CE98C,
    (void*)fn_801CE928,
    (void*)fn_80221184,
    (void*)fn_801CE920,
    (void*)fn_80221160,
    (void*)fn_801CE918,
    (void*)fn_801CE914,
    (void*)fn_801CE694,
    (void*)fn_801CE594,
    (void*)fn_8022249C,
    (void*)fn_801CE4E4,
    (void*)fn_802224D0,
    (void*)fn_801CE4BC,
    (void*)fn_801CE120,
    (void*)fn_80221210,
    (void*)fn_80221114,
};

// ---- fn_802223FC_dtor.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A6B70[];
extern void* lbl_804A6A00[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_802223FC(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A6B70;
        if (this_ != 0) {
            *(void**)p = lbl_804A6A00;
            if (this_ != 0) {
                *(void**)p = lbl_804A4808;
                if (p + 0x270 != 0) {
                    if (p + 0x294 != 0) {
                        *(void**)(p + 0x294) = lbl_8049CC34;
                    }
                }
                __dt__5ActorFv(this_, 0);
            }
        }
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- fn_8022249C.cpp ----
extern "C" void fn_80221250(void* this_);
extern "C" void fn_801CE4E8(void* this_);

// fn_8022249C - ZSLA's own vtable-0x88 override (see extab_80222a58.s
// and project_fsa_growing_area_extension.md). Byte-identical to
// fn_80221BE4/fn_80222D28 (fn_80222190's/fn_8022313C's own 0x88
// overrides): if this->0x248 == 2, calls fn_80221250, else falls
// through to the generic 0x88 default fn_801CE4E8. Confirms ZSLA
// carries the SAME 14-slot growing-area vtable extension (0x60-0x8c)
// as ZSLJ and the 3 previously-anonymous siblings - every other slot
// in ZSLA's vtable (0x54-0x8c) matches the already-landed
// generic/shared values exactly, so this was the only genuinely new
// function needed.
extern "C" void fn_8022249C(void* this_) {
    s32 state = *(s32*)((char*)this_ + 0x248);
    if (state == 2) {
        fn_80221250(this_);
    } else {
        fn_801CE4E8(this_);
    }
}


// ---- fn_802224D0 / fn_80222668 / fn_80222730 / fn_802229EC ----
#include "JSystem/JGeometry.h"

struct ZslaRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
    f32 get_sym(f32 s) { return s * (2.0f * get_ufloat_1() - 1.0f); }
};
struct ZslaGame { u8 pad[0xb4]; ZslaRandom rnd; };

extern "C" {
extern const f32 lbl_8053FE70;
extern ZslaGame* lbl_8053AAF8;
void fn_80221408(void* this_);
void fn_80221334(void* this_);
void fn_802212AC(void* this_);
void fn_802216E8(void* this_, s32 t);
void fn_8022149C(void* this_, s32 a);
void fn_802217C8(void* this_);
void fn_801D22DC(void* anim, s32 idx, s32 a, s32 b);
u8 fn_801D21F0(void* anim);
void fn_801F0E34(void* this_, s32 p1, s32 p2);
char* fn_802D6A9C(void);
void* fn_801F856C();
void* fn_801F666C(void* base, s32 id);
s32 Actor_CreateByID(void* mgr, u32 id, u32 arg, JGeometry::TVec3<f32>* pos, u32 arg2, s32 a, s32 b);
void fn_80222668(void* this_, s32 state);

void fn_802224D0(void* this_) {
    char* p = (char*)this_;
    switch (*(u32*)(p + 0x248)) {
    case 0:
        fn_80221408(this_);
        break;
    case 1:
        fn_80221334(this_);
        break;
    case 2:
        fn_802212AC(this_);
        break;
    case 3:
        if (*(s32*)(p + 0x24c) >= *(s32*)(p + 0x250)) {
            fn_80222668(this_, 5);
        }
        break;
    case 4:
        fn_802216E8(this_, 0x78);
        if (*(f32*)(p + 0x14) <= 0.0f) {
            if (*(u32*)(p + 0x230) & 0x2000) {
                fn_80222668(this_, 5);
            } else {
                *(f32*)(p + 0x44) = lbl_8053FE70;
            }
        }
        break;
    case 5:
        if (*(s32*)(p + 0x24c) > 1 && fn_801D21F0(p + 0x270)) {
            fn_80222668(this_, 6);
        } else if (*(s32*)(p + 0x24c) == 0x19) {
            fn_801F0E34(this_, 0x400c6, 0);
        }
        break;
    case 6:
        if (*(s32*)(p + 0x24c) >= 10) {
            if (*(s32*)(p + 0x2bc) % 10 == 0) {
                (*(s32*)(p + 0x2b8))++;
                if (*(s32*)(p + 0x2b8) >= 3) {
                    fn_80222668(this_, 7);
                } else {
                    fn_80222668(this_, 3);
                }
            } else {
                fn_80222668(this_, 6);
            }
        }
        break;
    case 7:
        if (*(s32*)(p + 0x24c) >= 0x78) {
            fn_8022149C(this_, 1);
        }
        break;
    }
}

void fn_80222730(void* this_);

void fn_80222668(void* this_, s32 state) {
    char* p = (char*)this_;
    switch (state) {
    case 3:
        *(s32*)(p + 0x250) = 0x78;
        fn_801D22DC(p + 0x270, *(s32*)(p + 0x98), 0, 0);
        break;
    case 5:
        fn_801D22DC(p + 0x270, 0x1b, 0, 0);
        break;
    case 6:
        fn_80222730(this_);
        (*(s32*)(p + 0x2bc))++;
        break;
    case 7:
        fn_801D22DC(p + 0x270, *(s32*)(p + 0x98), 0, 0);
        break;
    }
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x248) = state;
}

// NonMatching (~92%): float register allocation / RNG reload scheduling differ.
void fn_80222730(void* this_) {
    char* p = (char*)this_;
    s32 room = *(s32*)(p + 0x4);
    char* cfg = fn_802D6A9C();
    f32* rect;
    if (room < 8) {
        rect = (f32*)(cfg + 0xcc);
    } else {
        rect = (f32*)(cfg + 0xdc);
    }
    f32 halfW = 0.5f * (rect[2] - rect[0]);
    f32 height = 64.0f + (32.0f + (rect[3] - rect[1]));
    f32 x = *(f32*)(p + 0xc) - 0.5f * halfW;
    f32 baseY = rect[1] - 32.0f;
    s32 n = (s32)(0.0625f * halfW) + 1;
    for (s32 i = 0; i < n; i++) {
        f32 dy = 15.0f * (2.0f * lbl_8053AAF8->rnd.get_ufloat_1() - 1.0f);
        f32 dx = 7.0f * (2.0f * lbl_8053AAF8->rnd.get_ufloat_1() - 1.0f);
        JGeometry::TVec3<f32> pos(x + dx, baseY + dy, 0.0f);
        s32 id = Actor_CreateByID(fn_801F856C(), 'OKTM', *(u32*)(p + 0x4), &pos, 5, -1, -1);
        if (id >= 0) {
            char* a = (char*)fn_801F666C(fn_801F856C(), id);
            if (a != 0) {
                *(s32*)(a + 0x98) = 2;
                JGeometry::TVec3<f32> vel(0.0f, 3.2f + 0.6f * (2.0f * lbl_8053AAF8->rnd.get_ufloat_1() - 1.0f), 0.0f);
                *(JGeometry::TVec3<f32>*)(a + 0x3c) = vel;
                *(u8*)(a + 0x194) = 1;
                *(s32*)(a + 0x23c) = (s32)(height * (1.0f / *(f32*)(a + 0x40)));
            }
        }
        x += 16.0f;
    }
}

void fn_802229EC(void* this_) {
    char* p = (char*)this_;
    fn_802217C8(this_);
    *(s32*)(p + 0x98) = 2;
    *(s32*)(p + 0x248) = 4;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = -1;
    *(f32*)(p + 0x254) = 0.0f;
    *(f32*)(p + 0x258) = 0.0f;
    fn_801D22DC(p + 0x270, 2, 0, 0);
}
}

// ---- Zsla_ctor_80222A58.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_802218C8(void* this_);
extern void* lbl_804A6B70[];

extern "C" void* fn_80222A58(void* this_) {
    fn_802218C8(this_);
    *(void**)this_ = lbl_804A6B70;
    *(s32*)((char*)this_ + 0x2b8) = 0;
    *(s32*)((char*)this_ + 0x2bc) = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
