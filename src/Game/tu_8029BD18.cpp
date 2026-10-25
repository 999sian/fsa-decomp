#include "types.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "JSystem/JGeometry/Vec.h"
typedef Vec SDKVec;
#define Vec ActorVec
#include "Game/Actor.h"

extern "C" void fn_801F06F0(void* this_, void* name, s32 a, s32 b, s32 c, f32 x, f32 y);
extern f32 lbl_80540710;
extern char lbl_8046C3E8[];
extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A7B90[];

extern "C" void* fn_8029BD18(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A7B90;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) dtor_80084580(this_);
    }
    return this_;
}

extern "C" void fn_8029BD78(u8* this_) { this_[0x11c] = 0; }

extern "C" void fn_8029BD84(void* this_) {
    fn_801F06F0(this_, lbl_8046C3E8, 0x17e, 0, 0, 1.0f, 1.0f);
}

extern "C" void fn_80239914(f32* box, s32 room, s32 handle);

extern "C" u16 fn_80226850(const Vec* pos, s32 room);
extern "C" void fn_802A3948(void* mgr, Vec* pos, s32 flag, s32 room, s32 id);
extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 id, f32* pos, u32 arg5, s32 arg6, s32 arg7);
extern "C" s32 fn_80239108(s32 handle);
extern "C" s32 fn_80238BC4(s32 handle);
extern "C" u8 fn_802260DC(f32* pos, s32 room, s32 flag);
extern "C" void fn_80238E08(s32 handle);
extern "C" void fn_801F0E34(void* this_, s32 a, s32 b);
extern void* lbl_8053AC98;
extern int __float_epsilon[];
extern const f32 lbl_8046C398[8];
extern const f32 lbl_8046C3B8[12];
extern "C" void fn_8029BDC0(Actor* this_) {
    f32 box[4];
    box[0] = this_->field_60;
    box[1] = this_->field_64;
    box[2] = this_->field_68;
    box[3] = this_->field_6C;
    box[0] += this_->field_0C.x;
    box[2] += this_->field_0C.x;
    box[1] += this_->field_0C.y;
    box[3] += this_->field_0C.y;
    fn_80239914(box, this_->field_04, this_->field_198);

    if (PSVECDistance((SDKVec*)&this_->field_0C, (SDKVec*)((u8*)this_ + 0x230)) >= 15.9f) {
        f32 f = this_->field_24.x;
        if (this_->field_0C.x <= f + 15.5f && this_->field_0C.x >= f - 15.5f) {
            this_->field_0C.x = f;
        } else {
            this_->field_0C.x = (f32)(((s32)this_->field_0C.x + 4) / 8 * 8);
        }
        f = this_->field_24.y;
        if (this_->field_0C.y <= f + 15.5f && this_->field_0C.y >= f - 15.5f) {
            this_->field_0C.y = f;
        } else {
            this_->field_0C.y = (f32)(((s32)this_->field_0C.y + 4) / 8 * 8);
        }

        *(Vec*)((u8*)this_ + 0x230) = this_->field_0C;
        *(f32*)((u8*)this_ + 0x238) = this_->field_0C.z;
        this_->field_3C.x = 0.0f;
        this_->field_3C.y = 0.0f;
        this_->field_3C.z = 0.0f;
        this_->field_18 = this_->field_0C;
        *(s32*)((u8*)this_ + 0x23c) = 8;
        *(u16*)((u8*)this_ + 0x240) = fn_80226850(&this_->field_0C, this_->field_04);
        fn_802A3948(lbl_8053AC98, &this_->field_0C, 0, this_->field_04, 0x159);
        return;
    }

    this_->field_0C.x += this_->field_3C.x;
    this_->field_0C.y += this_->field_3C.y;
    this_->field_0C.z += this_->field_3C.z;
    if (*(s32*)((u8*)this_ + 0x23c) > 0) {
        *(s32*)((u8*)this_ + 0x23c) -= 1;
        return;
    }
    if (this_->field_3C.z * this_->field_3C.z + this_->field_3C.x * this_->field_3C.x + this_->field_3C.y * this_->field_3C.y > 32.0f * *(f32*)__float_epsilon) {
        return;
    }
    if (fn_80226850(&this_->field_0C, this_->field_04) != 0x159) {
        switch ((u8)this_->field_90) {
        case 1:
            Actor_CreateByID(fn_801F856C(), 0x52555059, this_->field_04, (f32*)&this_->field_0C, 2, -1, -1);
            break;
        case 2:
            Actor_CreateByID(fn_801F856C(), 0x52555059, this_->field_04, (f32*)&this_->field_0C, 4, -1, -1);
            break;
        case 3:
            Actor_CreateByID(fn_801F856C(), 0x52555059, this_->field_04, (f32*)&this_->field_0C, 7, -1, -1);
            this_->field_11C = 0;
            return;
        }
    }
    if (fn_80239108(this_->field_198) == 1) {
        s32 idx = fn_80238BC4(this_->field_198);
        if (idx >= 0 && idx < 4) {
            f32 tmp[2];
            tmp[0] = lbl_8046C398[idx * 2] + this_->field_0C.x;
            tmp[1] = lbl_8046C398[idx * 2 + 1] + this_->field_0C.y;
            if (fn_802260DC(tmp, this_->field_04, 0)) {
                return;
            }
            fn_80238E08(this_->field_198);
            this_->field_3C.x = lbl_8046C3B8[idx * 3];
            this_->field_3C.y = lbl_8046C3B8[idx * 3 + 1];
            this_->field_3C.z = lbl_8046C3B8[idx * 3 + 2];
            *(Vec*)((u8*)this_ + 0x230) = this_->field_0C;
            fn_801F0E34(this_, 0x30004, 0);
            fn_802A3948(lbl_8053AC98, &this_->field_0C, 0, this_->field_04, *(u16*)((u8*)this_ + 0x240));
        }
    }
}

extern "C" void fn_8029C1D0(Actor* this_) {
    this_->field_0C.x += (f32)(s32)(8.0f - (f32)((s32)this_->field_0C.x % 8));
    this_->field_0C.y += (f32)(s32)(8.0f - (f32)((s32)this_->field_0C.y % 8));
    this_->field_24 = this_->field_0C;
    *(Vec*)((u8*)this_ + 0x230) = this_->field_24;
    *(f32*)((u8*)this_ + 0x238) = this_->field_24.z;
    this_->field_3C.x = 0.0f;
    this_->field_3C.y = 0.0f;
    this_->field_3C.z = 0.0f;
    this_->field_60 = 0.0f;
    this_->field_64 = 0.0f;
    this_->field_68 = 8.0f;
    this_->field_6C = 8.0f;
    this_->field_7C.x = 0.0f;
    this_->field_7C.y = 0.0f;
    this_->field_88 = 8.0f;
    this_->field_8C = 8.0f;
    this_->field_1A4 = 1;
    *(s32*)((u8*)this_ + 0x23c) = 0;
    *(s32*)((u8*)this_ + 0xb8) = 2;
    *(u16*)((u8*)this_ + 0x240) = fn_80226850(&this_->field_0C, this_->field_04);
    fn_802A3948(lbl_8053AC98, &this_->field_0C, 0, this_->field_04, 0x159);
}

