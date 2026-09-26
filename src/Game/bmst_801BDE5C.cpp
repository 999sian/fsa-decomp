// Game TU 801BDE5C-801BEDBC (BMST). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_801D0F40(void* this_);
extern void* lbl_804A40E0[];
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_801BDE5C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A40E0;
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

extern "C" void* fn_801BEB44(void* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A40E0;
    *(s16*)((char*)this_ + 0x2a8) = 0;
    *(s16*)((char*)this_ + 0x2aa) = 0;
    *(u8*)((char*)this_ + 0x2ac) = 0;
    *(s32*)((char*)this_ + 0x2b0) = 0;
    *(s32*)((char*)this_ + 0x2b4) = 0;
    return this_;
}

extern "C" void* fn_8013CC50(u32 id, void* pos, u32 kind, u32 a, u32 b, u32 c, u32 d, u32 e, f32 scale);
extern "C" void v07__5ActorFv(void* this_);

extern "C" void fn_801BE0F4(char* this_) {
    fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x70, 0, 0, 0, 0, 1, 1.0f);
    fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x71, 0, 0, 0, 0, 1, 1.0f);
    fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x72, 0, 0, 0, 0, 1, 1.0f);
    v07__5ActorFv(this_);
}

struct BmstVec2 { f32 x, y; };
extern "C" s32 fn_801F285C(void* actor, s32 a, s32 b, s32 c, s32 idx);
extern "C" void fn_8023B6CC(s32 idx);
extern "C" u8 fn_8023E854(s32 idx);
extern "C" void fn_801F3128(void* actor, BmstVec2* out);
extern "C" u8 fn_80238548(s32 idx, s32 a, BmstVec2* v, s32 d);
extern "C" void fn_801F0E34(void* actor, u32 msg, s32 arg);
extern "C" u8 fn_801CEBD0(void* actor);

extern "C" u8 fn_801BE19C(char* this_) {
    u8 hit = 0;
    if (*(s32*)(this_ + 0x248) == 2) {
        for (s32 i = 0; i < 4; i++) {
            if (i == fn_801F285C(this_, 0, 0, 1, i)) {
                fn_8023B6CC(i);
                if (!fn_8023E854(i)) {
                    BmstVec2 v;
                    fn_801F3128(this_, &v);
                    if (fn_80238548(i, *(s32*)(this_ + 0x114), &v, 10)) {
                        hit = 1;
                    }
                }
            }
        }
        if (hit) {
            fn_801F0E34(this_, 0x4000c, 0);
        }
    } else {
        hit = fn_801CEBD0(this_);
    }
    return hit;
}

extern "C" void fn_801F2DB4(void* actor, u32 a, u32 b, u32 c);

extern "C" void fn_801BE284(char* this_) {
    fn_801F2DB4(this_, *(u16*)(this_ + 0x2aa) != 0 ? 'NULL' : *(u32*)(this_ + 0x1a0), 'SWBM', 0);
}

extern "C" void fn_801BE2CC(void) {}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
