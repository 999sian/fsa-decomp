#include "types.h"
#include "Game/ItemBase.h"
#include "Game/Actor.h"


extern "C" void* fn_8013C824(void);
extern "C" void* fn_8013CC50(void* a, void* pos, u32 id, u32 b, s32 c, u32 d, u32 e, u32 f, f32 scale);
extern "C" void fn_801CB71C(void** pe, void* pos, u32 a, u32 b);
extern "C" void fn_801CB7A0(void* obj);
extern "C" bool fn_80219E04(void* thisObj);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* mgr, void* emitter);
extern const f32 lbl_8053FCD4;
extern "C" const f32 lbl_8053FCC8;
extern "C" void fn_8021B1AC(void* this_);
extern "C" void fn_8021AFB8(void* this_);
extern "C" void fn_801F06F0(void* this_, void* table, u32 id, void* data, f32 f1, f32 f2, s32 mode);
extern "C" void fn_801EF830(void* obj, void* pos, void* rec, u32 mask, void* tbl, u32 c, u32 d);
extern u8 lbl_8046A660[];
extern "C" void fn_8021AF28(void* this_) {
    char* p = (char*)this_;
    *(f32*)(p + 0x10) += lbl_8053FCC8;
    if (fn_80219E04(this_)) {
        fn_8021B1AC(this_);
    } else {
        s32 s = *(s32*)(p + 0x248);
        switch (s) {
        case 4:
        case 5:
        case 11:
        case 12:
            fn_8021AFB8(this_);
            break;
        }
    }
    *(f32*)(p + 0x10) -= lbl_8053FCC8;
}

extern "C" f32 lbl_8053FCCC;
extern "C" f32 lbl_8053FCD0;
extern "C" void fn_8021AFB8(void* this_) {
    char* p = (char*)this_;
    DrawRec rec;
    rec.b1f = 0;
    char cVar = 0;
    if (fn_80219E04(this_)) {
        cVar = -6;
    }
    u32 flags = *(u32*)(p + 0x230);
    rec.b1d = cVar;
    if (flags & 0x2000) {
        f32 m[3][4];
        m[0][0] = lbl_8053FCD0;
        m[1][1] = lbl_8053FCD4;
        m[2][2] = lbl_8053FCD4;
        m[0][1] = lbl_8053FCCC;
        m[0][2] = lbl_8053FCCC;
        m[0][3] = lbl_8053FCCC;
        m[1][0] = lbl_8053FCCC;
        m[1][2] = lbl_8053FCCC;
        m[1][3] = lbl_8053FCCC;
        m[2][0] = lbl_8053FCCC;
        m[2][1] = lbl_8053FCCC;
        m[2][3] = lbl_8053FCCC;
        rec.w18 = m;
    }
    fn_801F06F0(this_, lbl_8046A660, *(u32*)(p + 0x280) + 0x25c, &rec, lbl_8053FCD4, lbl_8053FCD4, -1);
    rec.w10 = 200;
    rec.b1d = 0;
    if (*(s32*)(p + 0x138) == 0) {
        fn_801EF830(*(void**)(p + 4), p + 0xc, &rec, 0x407, lbl_8046A660, *(u32*)(p + 0x280) + 0x25c, 0);
    }
}

extern "C" f32 lbl_8053FCD8;
extern "C" f32 lbl_8053FCDC;
extern "C" u8 sincosTable___5JMath[];
extern "C" void fn_8021B1AC(void* this_) {
    char* p = (char*)this_;
    {
        DrawRec rec;
        rec.b1f = 0;
        char cVar = 0;
        if (fn_80219E04(this_)) {
            cVar = -6;
        }
        rec.b1d = cVar;
        fn_801F06F0(this_, lbl_8046A660, 0x279, &rec, lbl_8053FCD4, lbl_8053FCD4, -1);
        ((u8*)&rec.w10)[3] = 200;
        rec.b1d = 0;
        if (*(s32*)(p + 0x138) == 0) {
            fn_801EF830(*(void**)(p + 4), p + 0xc, &rec, 0x407, lbl_8046A660, 0x279, 0);
        }
    }
    {
        DrawRec rec;
        rec.b1f = 0;
        char cVar = 0;
        if (fn_80219E04(this_)) {
            cVar = -6;
        }
        rec.b1d = cVar + 1;
        f32 m[3][4];
        u32 off = ((u32)(s32)*(s16*)(p + 0x2cc) >> 2) & 0x3ff8;
        f32 s = *(f32*)(sincosTable___5JMath + off);
        f32 c = *(f32*)(sincosTable___5JMath + off + 4);
        m[0][3] = lbl_8053FCCC;
        m[1][3] = lbl_8053FCCC;
        m[2][3] = lbl_8053FCCC;
        m[1][1] = lbl_8053FCD4;
        m[0][2] = s;
        m[0][0] = c;
        m[2][0] = -s;
        m[2][2] = c;
        m[2][1] = lbl_8053FCCC;
        m[1][2] = lbl_8053FCCC;
        m[1][0] = lbl_8053FCCC;
        m[0][1] = lbl_8053FCCC;
        rec.w18 = m;
        *(f32*)(p + 0x10) += lbl_8053FCD8;
        fn_801F06F0(this_, lbl_8046A660, 0x27a, &rec, lbl_8053FCD4, lbl_8053FCD4, -1);
        *(f32*)(p + 0x10) -= lbl_8053FCD8;
        ((u8*)&rec.w10)[3] = 200;
        rec.b1d = 0;
        *(f32*)(p + 0x10) += lbl_8053FCDC;
        if (*(s32*)(p + 0x138) == 0) {
            fn_801EF830(*(void**)(p + 4), p + 0xc, &rec, 0x407, lbl_8046A660, 0x27a, 0);
        }
        *(f32*)(p + 0x10) -= lbl_8053FCDC;
    }
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
    Actor* actor = (Actor*)this_;
    u32 room = actor->field_04;
    char layer = 0;
    if (fn_80219E04(actor)) layer = -6;
    fn_8013CC50((void*)room, &actor->field_0C, 0x343, 0, layer, 0, 0, 1, lbl_8053FCD4);
}

