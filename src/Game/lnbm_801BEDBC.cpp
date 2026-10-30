// Game TU 801BEDBC-801BF810 (LNBM). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
#include "Game/ItemBase.h"
#include "JSystem/JMath/JMath.h"
#include "JSystem/JGeometry/Vec.h"
extern "C" void* fn_8013CC50(u32 id, void* pos, u32 kind, u32 a, s32 b, u32 c, u32 d, u32 e, f32 scale);
extern "C" void fn_801F0E34(void* this_, u32 id, u32 c);
extern "C" u32 fn_8022461C(void* p);
extern "C" u8 fn_802265DC(void* a, void* b, u32 c);
extern "C" u8* fn_8020D58C(void);
extern "C" u8 fn_8020D6AC(void* obj, void* a, void* b, u32 c, u32 d);
extern "C" void fn_801D0ED0(void* this_);
extern "C" void fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_8013CB44(void* h, void* pos, u32 a, u32 b, u32 c);
extern "C" void fn_8013CAA4(void* h, f32 angle);
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_801CCC78(void* pos, s32 room);
extern "C" void fn_802A20F0(void* h, void* pos, s32 a, s32 b, u32 c, u32 d);
extern "C" u8 fn_801F2B7C(void* this_, s32 a, s32 b, s32 c);
extern void* lbl_8053AC98;
extern const f32 lbl_8053ED04;
extern const f32 lbl_8053ED08;
extern const f32 lbl_8053ED0C;
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern const f32 lbl_8053ED00;
extern const f32 lbl_8053ED18;
extern const f32 lbl_8053ED1C;
extern const f32 lbl_8053ED20;

extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_801D0F40(void* this_);
extern void* lbl_804A4188[];

extern "C" void fn_801BEDBC(u8* this_) {
    if (this_[0x11c] != 0 && !(*(u32*)(this_ + 0x230) & 0x2000)) {
        fn_8013CC50(*(u32*)(this_ + 0x4), this_ + 0xc, 0x1e, 0, -1, 0, 0, 1, lbl_8053ED00);
        fn_8013CC50(*(u32*)(this_ + 0x4), this_ + 0xc, 0x1f, 0, 0, 0, 0, 1, lbl_8053ED00);
        fn_801F0E34(this_, 0x30061, 0);
        *(u32*)(this_ + 0x230) |= 0x2000;
    }
}

inline void* lnbmMgr() { u8* m = fn_8020D58C(); return m + m[1] * 0x784 + 4; }


static inline BOOL lnbmCollision(f32* b, int a, ItemBase* self) {
    switch ((u16)fn_8022461C(b)) {
    case 3: case 13: case 14: return FALSE;
    }
    BOOL result = TRUE;
    if (!fn_802265DC(b, (void*)a, 0)) {
        self = *(ItemBase**)((u8*)self + 0x90);
        if (!fn_8020D6AC(lnbmMgr(), (void*)a, b, (u32)self, 0)) result = FALSE;
    }
    return result;
}

#pragma opt_lifetimes off
extern "C" BOOL fn_801BEE6C(ItemBase* this_, int a, f32* b) {
    switch ((u16)fn_8022461C(b)) {
    case 3:
    case 13:
    case 14:
        return FALSE;
    }
    BOOL result = TRUE;
    if (!fn_802265DC(b, (void*)a, 0)) {
        this_ = *(ItemBase**)((u8*)this_ + 0x90);
        if (!fn_8020D6AC(lnbmMgr(), (void*)a, b, (u32)this_, 0)) {
            result = FALSE;
        }
    }
    return result;
}
#pragma opt_propagation off
extern "C" void fn_801BEF40(u8* this_) {
    if (*(u32*)(this_ + 0x230) & 0x2000) {
        fn_801EE434(*(void**)(this_ + 0x2a8));
        *(void**)(this_ + 0x2a8) = 0;
        this_[0x11c] = 0;
        return;
    }
    *(s32*)(this_ + 0x24c) += 1;
    if (*(s32*)(this_ + 0x24c) < 0) {
        *(s32*)(this_ + 0x24c) = 0;
    }
    if (!(*(volatile u32*)(this_ + 0x230) & 0x400)) {
        *(u32*)(this_ + 0x230) |= 0x400;
        ((ItemBase*)this_)->v19();
        return;
    }
    JGeometry::TVec3<f32>* pos = (JGeometry::TVec3<f32>*)(this_ + 0xc);
    pos->add(*(JGeometry::TVec3<f32>*)(this_ + 0x3c));
    if (*(void**)(this_ + 0x2a8) != 0) {
        u32 n = 1;
        if (*(s32*)(this_ + 0x24c) < 2) {
            n = *(u16*)(this_ + 0x94);
        }
        fn_8013CB44(*(void**)(this_ + 0x2a8), this_ + 0xc, 0, n, 1);
        f32 r = JMath::atanTable_.atan2_(*(f32*)(this_ + 0x3c), *(f32*)(this_ + 0x40));
        s16 ang = r * lbl_8053ED04;
        fn_8013CAA4(*(void**)(this_ + 0x2a8), lbl_8053ED08 * (lbl_8053ED0C * ang));
    }
    int room = *(s32*)(this_ + 0x4);
    u8* mgr = (u8*)fn_802D6A9C();
    f32* rb;
    if (room < 8) {
        rb = (f32*)(mgr + 0xcc);
    } else {
        rb = (f32*)(mgr + 0xdc);
    }
    if (!ItemBase_inArea(rb, &pos->x)) {
        *(u32*)(this_ + 0x230) |= 0x2000;
        return;
    }
    f32* box = (f32*)(this_ + 0x80);
    JGeometry::TVec3<f32> p0, p1, p2, p3;
    if ((p0.set(pos->x + box[0], pos->y + box[1], pos->z), (u8)((ItemBase*)this_)->v17(*(s32*)(this_ + 4), &p0.x)) ||
        (p1.set(pos->x + box[2], pos->y + box[1], pos->z), (u8)((ItemBase*)this_)->v17(*(s32*)(this_ + 4), &p1.x)) ||
        (p2.set(pos->x + box[0], pos->y + box[3], pos->z), (u8)((ItemBase*)this_)->v17(*(s32*)(this_ + 4), &p2.x)) ||
        (p3.set(pos->x + box[2], pos->y + box[3], pos->z), (u8)((ItemBase*)this_)->v17(*(s32*)(this_ + 4), &p3.x))) {
        JGeometry::TVec3<f32> sp(*pos);
        sp.x = pos->x + box[0];
        s32 j;
        s32 i;
        for (i = 0; i < 2; i++) {
            sp.y = pos->y + box[1];
            for (j = 0; j < 2; j++) {
                if (fn_801CCC78(&sp, *(s32*)(this_ + 4))) {
                    fn_802A20F0(lbl_8053AC98, &sp, -1, *(s32*)(this_ + 4), 0, 0);
                }
                sp.y += box[3] - box[1];
            }
            sp.x += box[2] - box[0];
        }
        fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, 0x1e, 0, -1, 0, 0, 1, lbl_8053ED00);
        fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, 0x1f, 0, 0, 0, 0, 1, lbl_8053ED00);
        fn_801F0E34(this_, 0x30061, 0);
        *(u32*)(this_ + 0x230) |= 0x2000;
        return;
    }
    fn_801F2B7C(this_, *(s32*)(this_ + 0x114), -1, 1);
}
#pragma opt_propagation reset
extern "C" void fn_801BF464(u8* this_) {
    fn_801D0ED0(this_);
    f32 a = lbl_8053ED18;
    f32 c = lbl_8053ED00;
    f32 b = lbl_8053ED1C;
    f32 d = lbl_8053ED20;
    *(f32*)(this_ + 0x60) = a;
    *(f32*)(this_ + 0x64) = a;
    *(f32*)(this_ + 0x68) = b;
    *(f32*)(this_ + 0x6c) = b;
    *(f32*)(this_ + 0x70) = c;
    *(f32*)(this_ + 0x74) = c;
    *(f32*)(this_ + 0x78) = d;
    *(f32*)(this_ + 0x7c) = d;
    *(f32*)(this_ + 0x80) = d;
    *(f32*)(this_ + 0x84) = d;
    *(f32*)(this_ + 0x88) = c;
    *(f32*)(this_ + 0x8c) = c;
    *(u32*)(this_ + 0xb0) = 0;
    *(u32*)(this_ + 0x98) = 2;
    *(u32*)(this_ + 0x230) |= 0x280;
    *(u32*)(this_ + 0x108) = 1000;
    *(u32*)(this_ + 0x244) = *(u32*)(this_ + 0x108);
    this_[0x194] = 1;
    *(u32*)(this_ + 0x114) = 2;
    *(u32*)(this_ + 0x24c) = 0;
}

extern "C" void* fn_801BF50C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A4188;
        fn_801EE434(*(void**)(p + 0x2a8));
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

extern "C" void* fn_801BF5A8(void* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A4188;
    *(s32*)((char*)this_ + 0x2a8) = 0;
    return this_;
}

extern "C" void fn_8013CB44(void* h, void* pos, u32 a, u32 b, u32 c);
extern "C" void fn_8013CAA4(void* h, f32 angle);
extern const f32 lbl_8053ED04;
extern const f32 lbl_8053ED08;
extern const f32 lbl_8053ED0C;

extern "C" void fn_801BF380(u8* this_) {
    *(void**)(this_ + 0x2a8) = fn_8013CC50(*(u32*)(this_ + 0x4), this_ + 0xc, 0x1b, 0, *(u16*)(this_ + 0x94), 0, 0, 1, lbl_8053ED00);
    if (*(void**)(this_ + 0x2a8) != 0) {
        u32 n = 1;
        if (*(s32*)(this_ + 0x24c) < 2) {
            n = *(u16*)(this_ + 0x94);
        }
        fn_8013CB44(*(void**)(this_ + 0x2a8), this_ + 0xc, 0, n, 1);
        f32 r = JMath::atanTable_.atan2_(*(f32*)(this_ + 0x3c), *(f32*)(this_ + 0x40));
        s16 ang = r * lbl_8053ED04;
        fn_8013CAA4(*(void**)(this_ + 0x2a8), lbl_8053ED08 * (lbl_8053ED0C * ang));
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
