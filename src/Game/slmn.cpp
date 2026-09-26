// TU 0x80207d84-0x80208e5c (actor SLMN).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"

// ---- Slmn_ctor_80208BE0.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_80207AC0(void* this_);
extern void* lbl_804A5BD8[];

extern "C" void* fn_80208BE0(void* this_) {
    fn_80207AC0(this_);
    *(void**)this_ = lbl_804A5BD8;
    *(s32*)((char*)this_ + 0x340) = 0;
    *(u8*)((char*)this_ + 0x344) = 0;
    *(u8*)((char*)this_ + 0x345) = 0;
    *(s16*)((char*)this_ + 0x346) = 0;
    *(s16*)((char*)this_ + 0x348) = 0;
    *(u8*)((char*)this_ + 0x34a) = 0;
    return this_;
}

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A5B28[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_80207D84(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A5BD8;
        if (this_ != 0) {
            *(void**)p = lbl_804A5B28;
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
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_80208244(char* this_, s32 state);

extern "C" void fn_80207E24(char* this_) {
    switch (*(s32*)(this_ + 0x248)) {
    case 4:
        fn_80208244(this_, 2);
        break;
    }
}

extern "C" BOOL fn_80207E58(char* this_) {
    BOOL r = FALSE;
    switch (*(s32*)(this_ + 0x248)) {
    case 3:
        if (*(u8*)(this_ + 0x34a) >= 10) {
            fn_80208244(this_, 6);
            r = TRUE;
        } else {
            fn_80208244(this_, 2);
        }
        break;
    case 6:
        r = TRUE;
        break;
    }
    return r;
}

extern "C" void fn_80207ECC(char* this_) {
    switch (*(s32*)(this_ + 0x248)) {
    case 1:
        fn_80208244(this_, 3);
        break;
    }
}

extern const f32 lbl_8053F8E0;

extern "C" void fn_80207F00(char* this_) {
    f32 z = lbl_8053F8E0;
    *(f32*)(this_ + 0x3c) = z;
    *(f32*)(this_ + 0x40) = z;
    *(f32*)(this_ + 0x44) = z;
}

extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* mgr, s32 id);
extern "C" void fn_80209CA4(void* obj, s32 a, s32 b, void* c, s32 d);
extern "C" void fn_80209D44(void* obj);
extern "C" u16 fn_8022461C(void* pos, s32 room);
extern "C" u16 fn_80226850(void* pos, s32 room);

struct SlmnPart {
    s32 id;       // 0x2b0
    u8 pad4[4];
    s32 a;        // 0x2b8
    s32 b;        // 0x2bc
    u8 c[0xc];    // 0x2c0
    s32 d;        // 0x2cc
    u8 pad20[4];
};

struct Slmn {
    u8 pad0[0x248];
    s32 state; // 0x248
    u8 pad24c[0x2b0 - 0x24c];
    SlmnPart parts[4]; // 0x2b0
};

extern "C" void fn_80208834(char* this_) {
    if (*(s32*)(this_ + 0x248) != 7) {
        fn_80208244(this_, 7);
    }
    for (s32 i = 0; i < 4; i++) {
        void* a = fn_801F666C(fn_801F856C(), ((Slmn*)this_)->parts[i].id);
        if (a != 0) {
            fn_80209CA4(a, ((Slmn*)this_)->parts[i].a, ((Slmn*)this_)->parts[i].b, ((Slmn*)this_)->parts[i].c, ((Slmn*)this_)->parts[i].d);
        }
    }
}

extern "C" void fn_802088B4(char* this_) {
    if (*(s32*)(this_ + 0x248) != 5) {
        fn_80208244(this_, 5);
    }
    for (s32 i = 0; i < 4; i++) {
        void* a = fn_801F666C(fn_801F856C(), ((Slmn*)this_)->parts[i].id);
        if (a != 0) {
            fn_80209D44(a);
        }
    }
}

extern "C" void fn_80208924(char* this_) {
    *(u16*)(this_ + 0x346) = fn_8022461C(this_ + 0xc, *(s32*)(this_ + 0x4));
    *(u16*)(this_ + 0x348) = fn_80226850(this_ + 0xc, *(s32*)(this_ + 0x4));
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
