// TU 0x80222cc4-0x802233a4.
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
}
extern "C" void* fn_80223060(void* this_, s16 freeFlag);
extern "C" void fn_80222FF0(void* this_);
extern "C" void fn_80222CC4(void* this_);
extern "C" void fn_80222D28(void* this_);
extern "C" void fn_80222D5C(void* this_);
void* lbl_804A6C38[] = {
    0,
    0,
    (void*)fn_80223060,
    (void*)fn_80222FF0,
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
    (void*)fn_80222CC4,
    (void*)fn_801CE920,
    (void*)fn_80221160,
    (void*)fn_801CE918,
    (void*)fn_801CE914,
    (void*)fn_801CE694,
    (void*)fn_801CE594,
    (void*)fn_80222D28,
    (void*)fn_801CE4E4,
    (void*)fn_80222D5C,
    (void*)fn_801CE4BC,
    (void*)fn_801CE120,
    (void*)fn_80221210,
    (void*)fn_80221114,
};

// ---- fn_80222CC4.cpp ----
extern "C" void fn_80221184(void* this_);
extern "C" void* fn_801F856C();
extern "C" void* fn_801F666C(void* base, s32 id);

extern "C" void fn_80222CC4(void* this_) {
    fn_80221184(this_);
    char* p = (char*)this_;
    s32 id = *(s32*)(p + 0x2b8);
    if (id >= 0) {
        void* base = fn_801F856C();
        void* found = fn_801F666C(base, id);
        if (found != 0) {
            *(s32*)((char*)found + 0x108) = 0;
        }
        *(s32*)(p + 0x2b8) = -1;
    }
}

// ---- fn_80222D28.cpp ----
extern "C" void fn_80221250(void* this_);
extern "C" void fn_801CE4E8(void* this_);

// fn_80222D28 - fn_8022313C's own vtable-0x88 override (see
// extab_80223060.s and project_fsa_growing_area_extension.md).
// Byte-identical logic to fn_80221BE4 (fn_80222190's own 0x88): if
// this->0x248 == 2, calls fn_80221250, else falls through to the
// generic 0x88 default fn_801CE4E8.
extern "C" void fn_80222D28(void* this_) {
    s32 state = *(s32*)((char*)this_ + 0x248);
    if (state == 2) {
        fn_80221250(this_);
    } else {
        fn_801CE4E8(this_);
    }
}


// ---- fn_80222D5C / fn_80222FF0 ----
struct Vec_80222CC4 {
    Vec_80222CC4(f32 x_, f32 y_, f32 z_) { x = x_; y = y_; z = z_; }
    f32 x, y, z;
};

extern "C" {
extern const f32 lbl_8053FE70;
void fn_80221408(void* this_);
void fn_80221334(void* this_);
void fn_802212AC(void* this_);
void fn_802216E8(void* this_, s32 t);
void fn_8022149C(void* this_, s32 a);
void fn_802217C8(void* this_);
void fn_801D22DC(void* anim, s32 idx, s32 a, s32 b);
u8 fn_801D21F0(void* anim);
void* fn_801F856C();
s32 Actor_CreateByID(void* mgr, u32 id, u32 arg, Vec_80222CC4* pos, u32 arg2, s32 a, s32 b);

void fn_80222D5C(void* this_) {
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
        if (*(s32*)(p + 0x24c) >= 0x78) {
            fn_801D22DC(p + 0x270, *(s32*)(p + 0x98) + 0x10, 0, 0);
            *(s32*)(p + 0x24c) = 0;
            *(s32*)(p + 0x248) = 5;
        }
        break;
    case 4:
        fn_802216E8(this_, 0x78);
        if (*(f32*)(p + 0x14) <= 0.0f) {
            if (*(u32*)(p + 0x230) & 0x2000) {
                fn_801D22DC(p + 0x270, *(s32*)(p + 0x98) + 0x10, 0, 0);
                *(s32*)(p + 0x24c) = 0;
                *(s32*)(p + 0x248) = 5;
            } else {
                *(f32*)(p + 0x44) = lbl_8053FE70;
            }
        }
        break;
    case 5:
        if (*(s32*)(p + 0x24c) > 1 && fn_801D21F0(p + 0x270)) {
            Vec_80222CC4 pos(*(f32*)(p + 0xc), *(f32*)(p + 0x10), 0.0f);
            switch (*(s32*)(p + 0x98)) {
            case 0:
                pos.x += 24.0f;
                break;
            case 1:
                pos.x -= 24.0f;
                break;
            case 2:
                pos.x += 4.0f;
                pos.y += 22.0f;
                break;
            case 3:
                pos.x -= 4.0f;
                pos.y -= 26.0f;
                break;
            }
            *(s32*)(p + 0x2b8) = Actor_CreateByID(fn_801F856C(), 'DDGO', *(u32*)(p + 0x4), &pos, 1, -1, -1);
            s32 id = *(s32*)(p + 0x2b8);
            if (id >= 0) {
                void* found = fn_801F666C(fn_801F856C(), id);
                if (found != 0) {
                    *(s32*)((char*)found + 0x98) = *(s32*)(p + 0x98);
                }
            }
            *(s32*)(p + 0x24c) = 0;
            *(s32*)(p + 0x248) = 6;
        }
        break;
    case 6:
        if (*(s32*)(p + 0x24c) >= 0xb4) {
            s32 id = *(s32*)(p + 0x2b8);
            if (id >= 0) {
                void* found = fn_801F666C(fn_801F856C(), id);
                if (found != 0) {
                    *(s32*)((char*)found + 0x108) = 0;
                }
                *(s32*)(p + 0x2b8) = -1;
            }
            fn_801D22DC(p + 0x270, *(s32*)(p + 0x98), 0, 0);
            *(s32*)(p + 0x24c) = 0;
            *(s32*)(p + 0x248) = 7;
        }
        break;
    case 7:
        if (*(s32*)(p + 0x24c) >= 0x78) {
            fn_8022149C(this_, 1);
        }
        break;
    }
}

void fn_80222FF0(void* this_) {
    char* p = (char*)this_;
    fn_802217C8(this_);
    *(u32*)(p + 0x98) = *(u32*)(p + 0x90) & 3;
    *(s32*)(p + 0x248) = 4;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = -1;
    *(f32*)(p + 0x254) = 0.0f;
    *(f32*)(p + 0x258) = 0.0f;
    fn_801D22DC(p + 0x270, 2, 0, 0);
}
}

// ---- fn_80223060_dtor.cpp ----
extern "C" void* fn_801F856C();
extern "C" void* fn_801F666C(void* base, s32 id);
extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A6C38[];
extern void* lbl_804A6A00[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_80223060(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A6C38;
        s32 id = *(s32*)(p + 0x2b8);
        if (id >= 0) {
            void* base = fn_801F856C();
            void* found = fn_801F666C(base, id);
            if (found != 0) {
                *(s32*)((char*)found + 0x108) = 0;
            }
            *(s32*)(p + 0x2b8) = -1;
        }
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

// ---- fn_8022313C_ctor.cpp ----
extern "C" void* fn_802218C8(void* this_);
extern void* lbl_804A6C38[];

extern "C" void* fn_8022313C(void* this_) {
    fn_802218C8(this_);
    char* p = (char*)this_;
    *(void**)p = lbl_804A6C38;
    *(s32*)(p + 0x2b8) = -1;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
