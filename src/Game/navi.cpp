// TU 0x8021d734-0x8021f064 (actor NAVI).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"

// ---- fn_8021ED04_dtor.cpp ----
extern "C" void* fn_801EE434(void* handle);
extern "C" void* CompanionRegistry_GetOrInit();
extern "C" void fn_8021F1F0(void* registry, s32 id);
extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A6708[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_8021ED04(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A6708;
        fn_801EE434(*(void**)(p + 0x2d0));
        fn_801EE434(*(void**)(p + 0x2d4));
        if (*(u32*)(p + 0x230) & 0x4000) {
            void* registry = CompanionRegistry_GetOrInit();
            fn_8021F1F0(registry, *(s32*)(p + 0x198));
        }
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
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" void fn_8021DFAC(void* this_, s32 state);
extern "C" void fn_801CE120(void* this_);
extern "C" void fn_801D0F40(void* this_);
struct NaviVec {
    f32 x, y, z;
    NaviVec(f32 a, f32 b, f32 c) { x = a; y = b; z = c; }
};
extern "C" void fn_8030C210(void* p, NaviVec* v);
extern const f32 lbl_8053FD64;
extern const f32 lbl_8053FD88;
extern const f32 lbl_8053FD58;
extern const f32 lbl_8053FD60;
extern const f32 lbl_8053FD5C;
extern char* lbl_8053AB10;
extern "C" void fn_801D01A0(void* self, f32 speed, void* dir, void* out);
extern int __float_max[];
extern const f32 lbl_8053FD68;
extern const f32 lbl_8053FD6C;
extern const f32 lbl_8053FD70;
extern const f32 lbl_8053FD74;
extern const f32 lbl_8053FD78;
extern const f32 lbl_8053FD7C;

extern "C" void fn_8021D734(char* p) {
    if (*(s32*)(p + 0x248) != 8) {
        fn_8021DFAC(p, 8);
    }
}

extern "C" void fn_8021D764(char* p) {
    if (*(s32*)(p + 0x248) != 6) {
        fn_8021DFAC(p, 6);
    }
}

extern "C" bool fn_8021D794(char* p) {
    return *(s32*)(p + 0x248) == 5;
}

extern "C" void fn_8021D938(char* p) {
    if (*(s32*)(p + 0x248) != 3) {
        u32 fl = *(u32*)(p + 0x230);
        if ((fl & 0x2000) && !(fl & 0x40000)) {
            u8* q = *(u8**)(lbl_8053AB10 + 0x30);
            if (q[0x284] == 0) {
                q[0x284] = 1;
                *(f32*)(q + 0x28c) = lbl_8053FD60;
            }
        }
        if (!(*(u32*)(p + 0x230) & 0x10000)) {
            NaviVec v(*(f32*)(p + 0x2c8), *(f32*)(p + 0x2cc) - *(f32*)(p + 0x14), lbl_8053FD58);
            fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), &v);
        }
    }
}

extern "C" void fn_8021D9D4(char* p) {
    fn_801CE120(p);
    if (*(s32*)(p + 0x248) == 9) {
        if (*(f32*)(p + 0x14) > lbl_8053FD64) {
            *(f32*)(p + 0x14) = lbl_8053FD64;
        }
    }
}

extern "C" void fn_8021DA20(char* p) {
    f32 v[2];
    *(f32*)(p + 0x3c) = lbl_8053FD58;
    *(f32*)(p + 0x40) = lbl_8053FD58;
    *(f32*)(p + 0x44) = lbl_8053FD58;
    switch (*(s32*)(p + 0x248)) {
    case 4:
        *(f32*)(p + 0x44) = lbl_8053FD68;
        break;
    case 7:
        *(f32*)(p + 0x44) = lbl_8053FD6C;
        break;
    case 9:
        *(f32*)(p + 0x44) = lbl_8053FD70;
        break;
    }
    switch (*(s32*)(p + 0x248)) {
    case 4:
    case 7:
        fn_801D01A0(p, *(f32*)__float_max, p + 0x2c0, v);
        *(f32*)(p + 0x3c) = v[0];
        *(f32*)(p + 0x40) = v[1];
        break;
    case 10:
        *(f32*)(p + 0x3c) = lbl_8053FD74;
        *(f32*)(p + 0x40) = lbl_8053FD78;
        break;
    case 9:
        *(f32*)(p + 0x40) = lbl_8053FD7C;
        break;
    }
}

extern "C" void fn_801CE0A4(void* this_);
extern "C" void fn_8013CB44(void* obj, void* pos, s32 a, s32 b, s32 c);
extern const f32 lbl_8053FD80;
extern const f32 lbl_8053FD84;
extern const f32 lbl_8053FD5C;
extern "C" void fn_8021DB24(char* p) {
    f32 f;
    s32 flag;
    fn_801CE0A4(p);
    if (*(s32*)(p + 0x248) == 9) {
        f = *(f32*)(p + 0x14) - lbl_8053FD80;
        f = f * lbl_8053FD84;
        if (f > lbl_8053FD5C) {
            f = lbl_8053FD5C;
        } else if (f < lbl_8053FD58) {
            f = lbl_8053FD58;
        }
        *(f32*)(p + 0x2b8) = lbl_8053FD88 * f;
    } else {
        *(f32*)(p + 0x2b8) = lbl_8053FD88;
    }
    flag = 0;
    if (*(s32*)(p + 0x248) == 9) {
        flag = 1;
    }
    fn_8013CB44(*(void**)(p + 0x2d0), p + 0xc, 0, -1, flag);
    flag = 0;
    if (*(s32*)(p + 0x248) == 9) {
        flag = 1;
    }
    fn_8013CB44(*(void**)(p + 0x2d4), p + 0xc, 0, -1, flag);
    if (*(void**)(p + 0x2d0) != 0) {
        *(char*)(*(char**)(p + 0x2d0) + 0xbb) = (char)(s32)*(f32*)(p + 0x2b8);
    }
    if (*(void**)(p + 0x2d4) != 0) {
        *(char*)(*(char**)(p + 0x2d4) + 0xbb) = (char)(s32)*(f32*)(p + 0x2b8);
    }
}

extern "C" void* fn_8021EDC0(char* p) {
    fn_801D0F40(p);
    *(void**)p = lbl_804A6708;
    *(s32*)(p + 0x2a8) = 0;
    p[0x2ac] = 0;
    p[0x2ad] = 0;
    *(s32*)(p + 0x2b0) = 0;
    *(s32*)(p + 0x2b4) = -1;
    *(f32*)(p + 0x2b8) = lbl_8053FD88;
    *(f32*)(p + 0x2bc) = lbl_8053FD58;
    *(f32*)(p + 0x2c0) = lbl_8053FD58;
    *(f32*)(p + 0x2c4) = lbl_8053FD58;
    *(f32*)(p + 0x2c8) = lbl_8053FD58;
    *(f32*)(p + 0x2cc) = lbl_8053FD58;
    *(s32*)(p + 0x2d0) = 0;
    *(s32*)(p + 0x2d4) = 0;
    return p;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
