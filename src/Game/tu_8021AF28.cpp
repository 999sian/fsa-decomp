#include "types.h"
#include "Game/ItemBase.h"


extern "C" void* fn_8013C824(void);
extern "C" void* fn_8013CC50(void* a, void* pos, u32 id, u32 b, s32 c, u32 d, u32 e, u32 f, f32 scale);
extern "C" void fn_801CB71C(void** pe, void* pos, u32 a, u32 b);
extern "C" void fn_801CB7A0(void* obj);
extern "C" bool fn_80219E04(void* thisObj);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* mgr, void* emitter);
extern const f32 lbl_8053FCD4;
extern "C" f32 lbl_8053FCC8;
extern "C" void fn_8021B1AC(void* this_);
extern "C" void fn_8021AFB8(void* this_);
extern "C" void fn_801F06F0(void* this_, void* table, u32 id, void* data, f32 f1, f32 f2, s32 mode);
extern "C" void fn_801EF830(u32 id, void* pos, void* rec, u32 mask, void* tbl, u32 c, u32 d);
extern u8 lbl_8046A660[];
extern "C" void fn_8021AF28(void* this_) {
    char* p = (char*)this_;
    *(f32*)(p + 0x10) += lbl_8053FCC8;
    if (fn_80219E04(this_)) {
        fn_8021B1AC(this_);
    } else {
        s32 s = *(s32*)(p + 0x248);
        if (s < 0xb) {
            if (s >= 4 && s < 6) {
                fn_8021AFB8(this_);
            }
        } else if (s < 0xd) {
            fn_8021AFB8(this_);
        }
    }
    *(f32*)(p + 0x10) -= lbl_8053FCC8;
}

extern "C" void fn_8021B548(void* this_) {
    char* p = (char*)this_;
    char cVar2 = 0;
    if (fn_80219E04(this_)) {
        cVar2 = -6;
    }
    fn_801CB71C((void**)(p + 0x2c4), p + 0xc, 0, cVar2);
}

extern "C" void fn_8021B5A0(void* this_) {
    fn_801CB7A0(*(void**)((char*)this_ + 0x2c4));
}

extern "C" void fn_8021B5C4(void* this_) {
    char* p = (char*)this_;
    if (*(void**)(p + 0x2c4) != 0) {
        void* mgr = fn_8013C824();
        forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)mgr + 0xc), *(void**)(p + 0x2c4));
        *(void**)(p + 0x2c4) = 0;
    }
    void* uVar2 = *(void**)(p + 0x4);
    char cVar4 = 0;
    if (fn_80219E04(this_)) {
        cVar4 = -6;
    }
    *(void**)(p + 0x2c4) = fn_8013CC50(uVar2, p + 0xc, 0x344, 0, cVar4, 0, 0, 1, lbl_8053FCD4);
}

extern "C" void fn_8021B668(void* this_) {
    char* p = (char*)this_;
    void* uVar1 = *(void**)(p + 0x4);
    char cVar3 = 0;
    if (fn_80219E04(this_)) {
        cVar3 = -6;
    }
    fn_8013CC50(uVar1, p + 0xc, 0x343, 0, cVar3, 0, 0, 1, lbl_8053FCD4);
}

