#include "types.h"
#include "Game/Actor.h"
#include "Game/ItemBase.h"

extern "C" char lbl_804A0FF8[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_80179150(Actor* p, s16 n)
{
    if (p != NULL) {
        *(void**)p = lbl_804A0FF8;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void fn_80158624(void* mgr, void* a, void* b, void* col, f32 scale);
extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern "C" void fn_801F02BC(void* this_, const char* name, s32 id, DrawRec* rec, s32 a, s32 b, s32 c, f32 s0, f32 s1);
extern "C" char lbl_80466868[];
extern void* lbl_8053AB10;
extern "C" void fn_801791B0(Actor* this_) {
    struct ShltColor {
        u32 rgba;
        ShltColor(u32 c) { rgba = c; }
    };
    typedef void (*DrawFn)(void*, void*, void*, ShltColor, f32);
    u8* p = (u8*)this_;
    if (this_->field_90 == 0xd) {
        DrawRec rec;
        rec.b1d = -1;
        fn_801F06F0(this_, lbl_80466868, 0x431, &rec, -1, 1.0f, 1.0f);
        fn_801F02BC(this_, lbl_80466868, 0x431, &rec, -1, 0, 0, 1.0f, 1.0f);
    } else {
        f32 s1 = *(f32*)(p + 0x344) * 0.7f;
        ShltColor c1(0x3f3f1f7f);
        ((DrawFn)fn_80158624)(*(void**)((u8*)lbl_8053AB10 + 0x2c), p + 0x34c, p + 0xc, c1, s1);
        f32 s2 = *(f32*)(p + 0x344);
        ShltColor c2(0x3f3f1f3f);
        ((DrawFn)fn_80158624)(*(void**)((u8*)lbl_8053AB10 + 0x2c), p + 0x34c, p + 0xc, c2, s2);
    }
}

extern "C" s32 fn_801F6874(u32 x);
extern "C" u8 sincosTable___5JMath[];
extern "C" Vec lbl_804C0EA0;
extern "C" s32 lbl_8053AB68;
extern "C" s32 lbl_80539F80;
extern "C" s32 lbl_80539F84;
extern "C" void fn_80179F64(Actor* this_)
{
    struct SinCosTable {
        struct Pair { f32 first; f32 second; } mTable[2048];
        f32 sinShort(s16 v) const { return mTable[static_cast<u16>(v) >> 5U].first; }
        f32 cosShort(s16 v) const { return mTable[static_cast<u16>(v) >> 5U].second; }
    };
    u8* p = (u8*)this_;

    *(f32*)(p + 0x60) = -8.0f;
    *(f32*)(p + 0x64) = -8.0f;
    *(f32*)(p + 0x68) = 8.0f;
    *(f32*)(p + 0x6c) = 8.0f;
    *(f32*)(p + 0x80) = -8.0f;
    *(f32*)(p + 0x84) = -8.0f;
    *(f32*)(p + 0x88) = 8.0f;
    *(f32*)(p + 0x8c) = 8.0f;
    *(u32*)(p + 0x328) = (this_->field_90 >> 4) & 0xf;
    *(u32*)(p + 0x32c) = (this_->field_90 >> 8) & 0xf;
    *(u32*)(p + 0x330) = (this_->field_90 >> 12) & 0xf;
    *(u32*)(p + 0x334) = (this_->field_90 >> 16) & 0xff;
    this_->field_90 &= 0xf;
    *(s32*)(p + 0x338) = 0;
    *(s32*)(p + 0x33c) = 0;
    lbl_804C0EA0.z = 0.0f;
    lbl_804C0EA0.y = 0.0f;
    lbl_804C0EA0.x = 0.0f;
    lbl_8053AB68 = -1;
    lbl_80539F80 = -1;
    lbl_80539F84 = -1;
    *(s32*)(p + 0x30c) = 0;
    *(s32*)(p + 0x310) = 0;
    *(s32*)(p + 0x314) = 0;
    *(s32*)(p + 0x318) = 0;
    *(s32*)(p + 0x31c) = 0;
    *(s32*)(p + 0x320) = 0;
    *(s32*)(p + 0x300) = 0;
    *(s32*)(p + 0x304) = 0;
    *(s32*)(p + 0x308) = 0;
    *(s32*)(p + 0x324) = 0;
    *(f32*)(p + 0x344) = 64.0f;
    *(f32*)(p + 0x378) = 0.0f;
    *(f32*)(p + 0x374) = 0.0f;
    *(f32*)(p + 0x370) = 0.0f;
    *(f32*)(p + 0x44) = 0.0f;
    *(f32*)(p + 0x40) = 0.0f;
    *(f32*)(p + 0x3c) = 0.0f;
    *(f32*)(p + 0x34c) = *(f32*)(p + 0xc);
    *(f32*)(p + 0x350) = *(f32*)(p + 0x10);
    *(f32*)(p + 0x354) = *(f32*)(p + 0x14);
    *(f32*)(p + 0x358) = *(f32*)(p + 0xc);
    *(f32*)(p + 0x35c) = *(f32*)(p + 0x10);
    *(f32*)(p + 0x360) = *(f32*)(p + 0x14);
    *(f32*)(p + 0x364) = *(f32*)(p + 0xc);
    *(f32*)(p + 0x368) = *(f32*)(p + 0x10);
    *(f32*)(p + 0x36c) = *(f32*)(p + 0x14);
    *(f32*)(p + 0x348) = 50.0f;
    *(s32*)(p + 0x30c) = 100;
    switch (this_->field_90) {
    case 0:
    case 4:
    case 8:
        *(s32*)(p + 0x98) = 3;
        break;
    case 1:
    case 5:
    case 9:
        *(s32*)(p + 0x98) = 2;
        break;
    case 2:
    case 6:
    case 10:
        *(s32*)(p + 0x98) = 1;
        break;
    case 3:
    case 7:
    case 11:
        *(s32*)(p + 0x98) = 0;
        break;
    }
    if (this_->field_90 >= 4 && this_->field_90 <= 7) {
        *(s32*)(p + 0x30c) = -100;
    }
    *(u16*)(p + 0x340) = fn_801F6874(*(u32*)(p + 0x98));
    if (this_->field_90 == 12) {
        *(s32*)(p + 0x2f8) = 2;
        *(s32*)(p + 0x2fc) = *(s32*)(p + 0x2f8);
    } else if (this_->field_90 == 13) {
        *(s32*)(p + 0x2f8) = 4;
        *(s32*)(p + 0x2fc) = *(s32*)(p + 0x2f8);
    } else {
        if (this_->field_90 >= 4 && this_->field_90 <= 11) {
            *(f32*)(p + 0xc) = *(f32*)(p + 0x348) * ((const SinCosTable*)sincosTable___5JMath)->sinShort(*(u16*)(p + 0x340)) + *(f32*)(p + 0x34c);
            *(f32*)(p + 0x10) = *(f32*)(p + 0x348) * ((const SinCosTable*)sincosTable___5JMath)->cosShort(*(u16*)(p + 0x340)) + *(f32*)(p + 0x350);
            *(s32*)(p + 0x2f8) = 1;
        } else {
            *(s32*)(p + 0x300) = 300;
            *(f32*)(p + 0x370) = 0.5f * ((const SinCosTable*)sincosTable___5JMath)->sinShort(*(u16*)(p + 0x340));
            *(f32*)(p + 0x374) = 0.5f * ((const SinCosTable*)sincosTable___5JMath)->cosShort(*(u16*)(p + 0x340));
            *(s32*)(p + 0x2f8) = 0;
        }
        *(s32*)(p + 0x2fc) = *(s32*)(p + 0x2f8);
    }
}

