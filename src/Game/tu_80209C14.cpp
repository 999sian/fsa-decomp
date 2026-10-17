#include "Game/ItemBase.h"

extern "C" void* fn_801F856C();
extern "C" void* fn_801F666C(void* mgr, s32 idx);
extern "C" void fn_802075D8(void*, u16);
extern "C" void v07__5ActorFv(void*);
extern "C" u32 fn_801F37AC(void*, u32, void*, u32, u32, u32);
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"
#include "JSystem/JGeometry/Box.h"


extern void* lbl_804A5D60[];
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern "C" f32 lbl_8053F970;
extern "C" f32 lbl_8053F964;
extern "C" f32 lbl_8053EFB8;
extern "C" void* fn_80209C14(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A5D60;
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

extern "C" void fn_80209CA4(ItemBase* this_, u32 index, u32 value, void* pos, u32 buf) {
    if ((u8)fn_801F37AC(this_, value, pos, 0, buf, index)) {
        this_->m230 &= ~0x80;
    }
}

extern "C" void fn_80209CF4(u8* this_, const JGeometry::TVec2<f32>* pos) {
    if ((*(volatile u32*)(this_ + 0x230) & 0x2000) != 0) {
        return;
    }
    *(u32*)(this_ + 0x230) |= 0x8000;
    *(JGeometry::TVec2<f32>*)(this_ + 0x2C8) = *pos;
}

extern "C" void fn_80209D20(u8* this_, u32 value, u8 flag) {
    if ((*(volatile u32*)(this_ + 0x230) & 0x2000) != 0) {
        return;
    }
    *(u32*)(this_ + 0x230) |= 0x4000;
    *(u32*)(this_ + 0x2AC) = value;
    *(u8*)(this_ + 0x2B0) = flag;
}

extern "C" void fn_80209D44(ItemBase* this_) {
    this_->m230 |= 0x2000;
}

extern "C" void fn_80209FBC(u8* this_) {
    void* actor = fn_801F666C(fn_801F856C(), *(s32*)(this_ + 0x2A8));
    if (actor != 0) {
        fn_802075D8(actor, *(u16*)(this_ + 0x94));
    }
    v07__5ActorFv(this_);
}

extern "C" void* fn_801F856C();
extern "C" void* fn_801F666C(void* mgr, s32 idx);
extern "C" void fn_802075D8(void*, u16);
extern "C" void v07__5ActorFv(void*);
extern "C" u32 fn_801F2DB4(void*, u32, u32, void*);
extern "C" void fn_8020A008(ItemBase* this_) {
    this_->m230 |= 0x80;
}

extern "C" s32 fn_801F285C(void*, u32, void*, u32, s32);
extern "C" void* fn_8023E724(s32);
extern "C" s32 fn_8023B6CC(s32);
extern "C" void fn_80207830(void*, u16, s32, s32, void*, u32);
extern "C" s32 fn_8020A018(u8* this_) {
    u32 out;
    if (*(f32*)(this_ + 0x68) - *(f32*)(this_ + 0x60) > 0.0f &&
        *(f32*)(this_ + 0x6C) - *(f32*)(this_ + 0x64) > 0.0f) {
        s32 player = fn_801F285C(this_, 0, &out, 1, -1);
        if (player >= 0) {
            void* actor = fn_801F666C(fn_801F856C(), *(s32*)(this_ + 0x2A8));
            if (actor != 0) {
                fn_80207830(actor, *(u16*)(this_ + 0x94), player, fn_8023B6CC(player), fn_8023E724(player), out);
            }
        }
    }
    return 0;
}

extern "C" s32 fn_8020A0E8(u8* this_) {
    fn_801F2DB4(this_, *(u32*)(this_ + 0x1A0), 'NULL', 0);
    return 0;
}

extern f32 lbl_8053F96C;
void fn_801F317C(char* this_, u8* buf);
s32 fn_8023AE34(u8* buf, u32 id, f32* pos);
s32 fn_8023AA18(u8* buf, u32 id, f32* pos);
s32 fn_8023AC74(u8* buf, u32 id, f32* pos);
s32 fn_8023AD54(u8* buf, u32 id, f32* pos);
u8 fn_801CC820(s32 id, f32* v);
void fn_801CC538(s32 id, f32* pos, f32* buf, s32* out);
void fn_801CC640(s32 id, s32* out, f32* v);
u8 fn_801EAC20(char* this_, s32 id);
u8 fn_801EAC54(char* this_, s32 id);
void fn_801CB538(u32 id, f32* p, s32 a, s32 b);
extern "C" void fn_801F317C(char* this_, u8* buf);
extern "C" s32 fn_8023AE34(u8* buf, u32 id, f32* pos);
extern "C" s32 fn_8023AA18(u8* buf, u32 id, f32* pos);
extern "C" s32 fn_8023AC74(u8* buf, u32 id, f32* pos);
extern "C" s32 fn_8023AD54(u8* buf, u32 id, f32* pos);
extern "C" u8 fn_801CC820(s32 id, f32* v);
extern "C" void fn_801CC538(s32 id, f32* pos, f32* buf, s32* out);
extern "C" void fn_801CC640(s32 id, s32* out, f32* v);
extern "C" u8 fn_801EAC20(char* this_, s32 id);
extern "C" u8 fn_801EAC54(char* this_, s32 id);
extern "C" void fn_801CB538(u32 id, f32* p, s32 a, s32 b);
extern "C" u8 fn_8020A11C(char* this_) {
    s32 n;
    f32 pos[2];
    f32 p3[3];
    u8 bufC[24];
    s32 id;
    u8 hit;
    u8 wall;
    u8 r;

    if (*(f32*)(this_ + 0x78) - *(f32*)(this_ + 0x70) <= lbl_8053F964 ||
        *(f32*)(this_ + 0x7c) - *(f32*)(this_ + 0x74) <= lbl_8053F964) {
        return 0;
    }
    n = -1;
    hit = 0;
    wall = 0;

    fn_801F317C(this_, bufC);
    id = fn_8023AE34(bufC, *(u32*)(this_ + 0x4), pos);
    if (id >= 0) {
        hit = fn_801CC820(id, 0);
    } else {
        id = fn_8023AA18(bufC, *(u32*)(this_ + 0x4), pos);
        if (id >= 0) {
            wall = 1;
        } else {
            id = fn_8023AC74(bufC, *(u32*)(this_ + 0x4), pos);
            if (id >= 0) {
                fn_801CC538(id, pos, 0, &n);
            } else {
                id = fn_8023AD54(bufC, *(u32*)(this_ + 0x4), pos);
                if (id >= 0) {
                    fn_801CC640(id, &n, 0);
                }
            }
        }
    }
    r = 0;
    if (id >= 0) {
        if (wall) {
            if (fn_801EAC20(this_ + 0x1dc, id)) {
                r = 1;
            }
        } else if (hit || (n >= 0 && fn_801EAC54(this_ + 0x1dc, n))) {
            r = 1;
        }
    }
    if (r) {
        p3[0] = pos[0];
        p3[1] = pos[1];
        p3[2] = lbl_8053F96C;
        fn_801CB538(*(u32*)(this_ + 0x4), p3, 0, 0);
    }
    return r;
}

extern "C" void fn_8020A2C0(void* this_) {
    char* p = (char*)this_;
    switch (*(s32*)(p + 0x248)) {
    case 0:
        *(f32*)(p + 0x44) += lbl_8053F970 * lbl_8053EFB8;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        switch (*(s32*)(p + 0x278)) {
        case 2:
        case 6:
            *(f32*)(p + 0x3c) = *(f32*)(p + 0x2b4);
            *(f32*)(p + 0x40) = *(f32*)(p + 0x2b8);
            break;
        default:
            *(f32*)(p + 0x40) = *(f32*)(p + 0x3c) = lbl_8053F964;
            break;
        }
        *(f32*)(p + 0x44) += lbl_8053EFB8;
        break;
    default:
        *(f32*)(p + 0x40) = *(f32*)(p + 0x3c) = lbl_8053F964;
        ((ItemBase*)this_)->v31();
        break;
    }
}

// Keep regional definitions that were present before source-tree consolidation.
#if defined(VERSION_G4SJ01)
extern "C" void fn_8020AE2C(void* param_1) {
    f32 f1 = *(f32*)((u8*)param_1 + 0x24);
    f32 f0 = *(f32*)((u8*)param_1 + 0xc);
    f32 f3 = *(f32*)((u8*)param_1 + 0x28);
    f32 f2 = *(f32*)((u8*)param_1 + 0x10);
    *(f32*)((u8*)param_1 + 0x2c0) = f1 - f0;
    *(f32*)((u8*)param_1 + 0x2c4) = f3 - f2;
}

extern "C" void* fn_801D0F40(void* this_);
extern "C" float lbl_8053F964;
extern "C" void fn_801D0F40(void* this_);
extern "C" const f32 lbl_8053F964;
extern "C" void* fn_8020B0B8(char* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A5D60;
    *(s32*)(this_ + 0x2a8) = -1;
    *(s32*)(this_ + 0x2ac) = 0;
    *(u8*)(this_ + 0x2b0) = 1;
    *(u8*)(this_ + 0x2b1) = 0;
    *(f32*)(this_ + 0x2b4) = lbl_8053F964;
    *(f32*)(this_ + 0x2b8) = lbl_8053F964;
    *(f32*)(this_ + 0x2bc) = lbl_8053F964;
    *(f32*)(this_ + 0x2c0) = lbl_8053F964;
    *(f32*)(this_ + 0x2c4) = lbl_8053F964;
    *(f32*)(this_ + 0x2c8) = lbl_8053F964;
    *(f32*)(this_ + 0x2cc) = lbl_8053F964;
    return this_;
}


#endif
