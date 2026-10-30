// Game TU 801CDC8C-801D11FC (unnamed). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
#include "Game/ItemBase.h"
#include "JSystem/JMath/JMath.h"
extern "C" void fn_801D1C18(void* obj);
extern "C" u8 fn_801CCFE4(u32 id);
extern "C" u32 fn_801F320C(u8* this_, u32 id);
extern "C" s32 fn_8023DE58(s32 id);
extern "C" s32 fn_8022CAF8(s32 id);
extern "C" u8 fn_8022F514(s32 id);
extern "C" s32 fn_801CD950(f32* value, f32 target, f32 step);
extern "C" u8* fn_802D6A9C();
extern const f32 lbl_8053EFC4;
extern const f32 lbl_8053EFCC;
extern const f32 lbl_8053EFD0;
extern "C" s32 ClassifyBamAngleToQuadrant(u16 angle);
extern "C" u8 fn_801F2FAC(void* this_);
extern const f32 lbl_8053EFD4;
extern const f32 lbl_8053EFD8;
extern const f32 lbl_8053EFEC;
extern const f32 lbl_8053EFDC;
extern const f32 lbl_8053EFE0;
extern const f32 lbl_8053EFF8;
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JAudio/JAUSoundObject.h"
extern "C" s32 fn_801F285C(void* this_, f32* pos, s32* out, s32 a, s32 idx);
extern "C" void fn_8023B6CC(s32 idx);
extern "C" void fn_802379E4(s32 idx, void* pos);
extern "C" u8 fn_801EAC20(void* list, s32 idx);
extern "C" void fn_801CB538(u32 room, f32* pos, s32 a, s32 b);
extern "C" u16 fn_8022461C(void* pos, s32 room);
extern "C" u16 fn_802265FC(f32* pos, s32 room);

extern "C" JAUSoundObject* fn_801F1184(void* this_);
extern "C" void fn_801F0E34(void* this_, void* arg, u32 c);
extern "C" u8* fn_802D6A9C(void);
extern "C" void fn_801CCD34(f32* in, f32* out);
extern const f32 lbl_8053EFC8;
extern "C" void __ct__5ActorFv(void* this_);
extern "C" void* fn_801D267C(void* this_);
extern "C" s32 fn_801CD664(s32 n);
extern void* lbl_804A4808[];
extern const f32 lbl_8053EFC4;
extern const f32 lbl_8053EFD0;
extern const f32 lbl_8053EFDC;
extern const f32 lbl_8053F010;
extern const f32 lbl_8053F014;
extern const f32 lbl_8053EFF0;
extern const f32 lbl_8053EFE0;
extern const f32 lbl_8053EFE4;
extern const f32 lbl_8053EFE8;
extern int __float_epsilon[];
extern "C" s32 fn_801CF720(u8* this_, s32 dir);
extern "C" u8 fn_801CCB1C(const f32* pos, s32 layer);
extern "C" u8 fn_801CFCF0(u8* this_, s32 idx);
extern "C" s32 fn_801CF798(u8* this_, s32 idx, s32 dir);
extern "C" s32 fn_801CD580(s32 exclude);

extern "C" {
}

extern "C" void fn_801CDC8C(void* this_, u32 id) {
    JAUSoundObject* obj = fn_801F1184(this_);
    if (obj != 0) {
        obj->stopSound(id, 0);
    }
}

struct Vec3f { f32 x, y, z; };

extern "C" void fn_801CDCD0(u8* this_, u32 id, const JGeometry::TVec3<f32>& pos, void* arg) {
    JGeometry::TVec3<f32> save(*(JGeometry::TVec3<f32>*)(this_ + 0xc));
    u32 old = *(u32*)(this_ + 0x4);
    *(u32*)(this_ + 0x4) = id;
    *(f32*)(this_ + 0xc) = pos.x;
    *(f32*)(this_ + 0x10) = pos.y;
    *(f32*)(this_ + 0x14) = pos.z;
    fn_801F0E34(this_, arg, 0);
    *(u32*)(this_ + 0x4) = old;
    *(f32*)(this_ + 0xc) = save.x;
    *(f32*)(this_ + 0x10) = save.y;
    *(f32*)(this_ + 0x14) = save.z;
}

extern "C" s32 fn_801F3D94(void* this_, u8 flag);
extern "C" s32 fn_801CD2F8(s32 room);
#pragma opt_propagation off
extern "C" void fn_801CDD58(ItemBase* this_) {
    s32 oldD8;

    if ((this_->m230 & 0x400) == 0) {
        *(volatile u32*)&this_->m230 |= 0x400;
        this_->v19();
    }
    this_->m230 &= ~0x1f;
    this_->m240 = 0;
    {
        s32 flag = 1;
        if (this_->m230 & 0x80) {
            flag = 0;
        }
        this_->m234 = *(f32*)((u8*)this_ + 0x3c);
        this_->m238 = *(f32*)((u8*)this_ + 0x40);
        this_->m23C = *(f32*)((u8*)this_ + 0x44);
        if (this_->m230 & 0x200) {
            *(u32*)((u8*)this_ + 0x108) = this_->m244;
        }
        this_->v20();
        oldD8 = *(s32*)((u8*)this_ + 0xd8);
        if (fn_801F3D94(this_, flag) != 0) {
            this_->m230 |= 1;
        } else if (this_->v21()) {
            this_->m230 |= 2;
            this_->v25();
        } else if (this_->v22()) {
            this_->m230 |= 4;
            this_->v26();
        }
        if (!(u8)flag && *(s32*)((u8*)this_ + 0xd8) > 0 && *(s32*)((u8*)this_ + 0xf8) == 2) {
            f32 vz = *(f32*)((u8*)this_ + 0x44);
            if (vz > lbl_8053EFC4) {
                *(f32*)((u8*)this_ + 0x44) = lbl_8053EFC4;
            }
        }
    }
    if (this_->m230 & 0x200) {
        *(u32*)((u8*)this_ + 0x108) = this_->m244;
    }
    if (oldD8 == 1 && *(s32*)((u8*)this_ + 0xd8) == 0) {
        this_->v27();
    }
    if ((this_->m230 & 0x800) == 0 && *(s32*)((u8*)this_ + 0x108) <= 0) {
        *(volatile u32*)&this_->m230 |= 0x800;
        this_->v28();
    }
    this_->v36();
    {
        s32 flag2 = this_->v23();
        u8 gate = (this_->m230 & 7) != 0;
        if (!gate && (this_->m230 & 0x100) == 0) {
            this_->m240 = this_->v24();
        }
        this_->v37(flag2);
    }
    if (!(u8)fn_801CD2F8(*(s32*)((u8*)this_ + 4))) {
        this_->v38();
    }
}
#pragma opt_propagation reset
extern "C" void fn_801CE00C(void) {}

extern "C" f32 __fsels(f32 a, f32 b, f32 c);
extern "C" void fn_801CE010(u8* this_, f32* out) {
    s32 idx = *(s32*)(this_ + 0x4);
    u8* mgr = fn_802D6A9C();
    f32* r;
    if (idx < 8) {
        r = (f32*)(mgr + 0xcc);
    } else {
        r = (f32*)(mgr + 0xdc);
    }
    f32 y0 = *(f32*)(this_ + 0x10) - *(f32*)(this_ + 0x14);
    out[0] = *(f32*)(this_ + 0xc);
    out[1] = y0;
    out[2] = lbl_8053EFC4;
    f32 lim = lbl_8053EFC8 + r[1];
    f32 y = out[1];
    out[1] = __fsel(lim - y, lim, y);
}
extern "C" void fn_801CE0A4(ItemBase* this_) {
    if ((this_->m230 & 7) == 0) {
        this_->m24C++;
        if (this_->m24C < 0) this_->m24C = 0;
        void (**vtable)(ItemBase*) = *(void (***)(ItemBase*))this_;
        vtable[36](this_);
        this_->v35();
    }
}

extern "C" void fn_801CE120(ItemBase* this_) {
    if ((*(u32*)((u8*)this_ + 0x230) & 7) == 0) {
        if (this_->m254 != this_->m258) {
            f32 step = this_->m25C;
            if (this_->m254 > this_->m258) {
                step = this_->m260;
            }
            fn_801CD950(&this_->m254, this_->m258, step);
        }
        this_->v32();
        *(JGeometry::TVec3<f32>*)((u8*)this_ + 0xc) += *(JGeometry::TVec3<f32>*)((u8*)this_ + 0x3c);
        this_->v33();
        if (*(f32*)((u8*)this_ + 0x14) <= lbl_8053EFC4) {
            u32 idx = *(u32*)((u8*)this_ + 0x4);
            u8* mgr = fn_802D6A9C();
            if (mgr[0x131df + idx]) {
                this_->v30();
            } else if (*(u32*)((u8*)this_ + 0x230) & 0x40) {
                *(f32*)((u8*)this_ + 0x14) = lbl_8053EFCC * -*(f32*)((u8*)this_ + 0x14);
                *(f32*)((u8*)this_ + 0x44) = lbl_8053EFCC * -*(f32*)((u8*)this_ + 0x44);
                this_->m254 *= lbl_8053EFCC;
                this_->m258 *= lbl_8053EFCC;
                *(f32*)((u8*)this_ + 0x3c) *= lbl_8053EFCC;
                *(f32*)((u8*)this_ + 0x40) *= lbl_8053EFCC;
                if (__fabs(*(f32*)((u8*)this_ + 0x44)) < lbl_8053EFD0) {
                    *(f32*)((u8*)this_ + 0x14) = lbl_8053EFC4;
                    *(f32*)((u8*)this_ + 0x44) = lbl_8053EFC4;
                } else {
                    this_->v29();
                }
            } else {
                *(f32*)((u8*)this_ + 0x14) = lbl_8053EFC4;
                *(f32*)((u8*)this_ + 0x44) = lbl_8053EFC4;
            }
        }
    }
}

extern "C" s32 fn_801CD950(f32* value, f32 target, f32 step);
extern const f32 lbl_8053EFCC;

extern "C" void fn_801CE2BC(ItemBase* this_) {
    this_->m24C++;
    if (this_->m24C < 0) {
        this_->m24C = 0;
    }
    (*(void (***)(ItemBase*))this_)[0x90 / 4](this_);
    this_->v35();
}

extern "C" s32 fn_801CD950(f32* value, f32 target, f32 step);
extern const f32 lbl_8053EFCC;
extern "C" void fn_801CE32C(ItemBase* this_) {
    u8* self = (u8*)this_;
    if (*(f32*)(self + 0x254) != *(f32*)(self + 0x258)) {
        f32 step = *(f32*)(self + 0x25c);
        if (*(f32*)(self + 0x254) > *(f32*)(self + 0x258)) {
            step = *(f32*)(self + 0x260);
        }
        fn_801CD950((f32*)(self + 0x254), *(f32*)(self + 0x258), step);
    }
    this_->v32();
    *(JGeometry::TVec3<f32>*)(self + 0xc) += *(JGeometry::TVec3<f32>*)(self + 0x3c);
    this_->v33();
    if (*(f32*)(self + 0x14) <= lbl_8053EFC4) {
        u32 idx = *(u32*)(self + 0x4);
        u8* mgr = fn_802D6A9C();
        if (mgr[0x131df + idx]) {
            this_->v30();
        } else if (*(u32*)(self + 0x230) & 0x40) {
            *(f32*)(self + 0x14) = lbl_8053EFCC * -*(f32*)(self + 0x14);
            *(f32*)(self + 0x44) = lbl_8053EFCC * -*(f32*)(self + 0x44);
            *(f32*)(self + 0x254) *= lbl_8053EFCC;
            *(f32*)(self + 0x258) *= lbl_8053EFCC;
            *(f32*)(self + 0x3c) *= lbl_8053EFCC;
            *(f32*)(self + 0x40) *= lbl_8053EFCC;
            if (__fabs(*(f32*)(self + 0x44)) < lbl_8053EFD0) {
                *(f32*)(self + 0x14) = lbl_8053EFC4;
                *(f32*)(self + 0x44) = lbl_8053EFC4;
            } else {
                this_->v29();
            }
        } else {
            *(f32*)(self + 0x14) = lbl_8053EFC4;
            *(f32*)(self + 0x44) = lbl_8053EFC4;
        }
    }
}

extern "C" void fn_801CE4BC(u8* this_) {
    fn_801D1C18(this_ + 0x270);
}

extern "C" void fn_801CE4E0(void) {}

extern "C" void fn_801CE4E4(void) {}

extern "C" void fn_801CE4E8(ItemBase* this_) {
    u8* p = (u8*)this_;
    switch (*(s32*)(p + 0x98)) {
    case 0:
        *(f32*)(p + 0x3c) = *(f32*)(p + 0x254);
        *(f32*)(p + 0x40) = lbl_8053EFC4;
        break;
    case 1:
        *(f32*)(p + 0x3c) = -*(f32*)(p + 0x254);
        *(f32*)(p + 0x40) = lbl_8053EFC4;
        break;
    case 2:
        *(f32*)(p + 0x3c) = lbl_8053EFC4;
        *(f32*)(p + 0x40) = *(f32*)(p + 0x254);
        break;
    case 3:
        *(f32*)(p + 0x3c) = lbl_8053EFC4;
        *(f32*)(p + 0x40) = -*(f32*)(p + 0x254);
        break;
    }
    this_->v31();
}

extern "C" void fn_801CE594(u8* this_) {
    if (*(s32*)(this_ + 0xd8) > 0 && *(s32*)(this_ + 0xf8) == 2) {
        return;
    }
    *(f32*)(this_ + 0x44) += -0.2f;
    if (*(f32*)(this_ + 0x44) < -4.0f) {
        *(f32*)(this_ + 0x44) = -4.0f;
    }
}

extern "C" void fn_801F2B7C(u8* this_, u32 a, s32 b, s32 c);
extern "C" s32 fn_801F2618(u8* this_, s32 a);
extern "C" s32 fn_801F2DB4(u8* this_, u32 a, u32 b, s32 c);
extern "C" void fn_801CE5D4(u8* this_) {
    if (*(u32*)(this_ + 0x230) & 7) {
        *(f32*)(this_ + 0x14) = *(f32*)(this_ + 0x20);
        *(f32*)(this_ + 0x44) = *(f32*)(this_ + 0x23c);
        ((ItemBase*)this_)->v31();
        *(f32*)(this_ + 0x14) += *(f32*)(this_ + 0x44);
        if (*(f32*)(this_ + 0x14) <= lbl_8053EFC4) {
            u32 base = *(u32*)(this_ + 0x4);
            u8* p = fn_802D6A9C();
            if (p[base + 0x131df]) {
                ((ItemBase*)this_)->v30();
            } else {
                *(f32*)(this_ + 0x14) = lbl_8053EFC4;
                *(f32*)(this_ + 0x44) = lbl_8053EFC4;
            }
        }
    }
}

extern "C" void fn_801CE694(u8* this_) {
    if (!(*(u32*)(this_ + 0x230) & 0x20) && fn_8022461C(this_ + 0xc, *(s32*)(this_ + 0x4)) == 2) {
        f32 neg = -*(f32*)(this_ + 0x14);
        *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x10) + neg;
        *(f32*)(this_ + 0x14) = lbl_8053EFC4;
        if (*(f32*)(this_ + 0x88) - *(f32*)(this_ + 0x80) > lbl_8053EFC4 &&
            *(f32*)(this_ + 0x8c) - *(f32*)(this_ + 0x84) > lbl_8053EFC4) {
            bool hit = false;
            f32 out[2];
            f32 vec[2];
            f32 y = *(f32*)(this_ + 0x10) - *(f32*)(this_ + 0x14);
            vec[0] = *(f32*)(this_ + 0xc);
            vec[1] = *(f32*)(this_ + 0x8c) + y;
            u16 kind = fn_802265FC(vec, *(s32*)(this_ + 0x4));
            switch (kind) {
            case 0:
                if (*(f32*)(this_ + 0x14) <= lbl_8053EFC4) {
                    hit = true;
                }
                break;
            case 2:
                break;
            default:
                hit = true;
                break;
            }
            if (hit) {
                fn_801CCD34(vec, out);
                *(f32*)(this_ + 0x10) = (out[1] - lbl_8053EFDC) - *(f32*)(this_ + 0x8c);
                *(f32*)(this_ + 0x14) = lbl_8053EFC4;
                *(f32*)(this_ + 0x44) = lbl_8053EFC4;
                *(u32*)(this_ + 0x230) |= 8;
            }
        }
    } else {
        *(f32*)(this_ + 0x14) = lbl_8053EFC4;
        *(f32*)(this_ + 0x44) = lbl_8053EFC4;
        *(u32*)(this_ + 0x230) |= 8;
    }
}

extern "C" u16 fn_802265FC(f32* pos, s32 room);
extern "C" void fn_801CE800(u8* this_) {
    f32 pos[2];
    f32 out[2];
    {
        f32 zero = lbl_8053EFC4;
        if (!(*(f32*)(this_ + 0x88) - *(f32*)(this_ + 0x80) > zero)) {
            return;
        }
        if (!(*(f32*)(this_ + 0x8c) - *(f32*)(this_ + 0x84) > zero)) {
            return;
        }
    }
    f32 y = *(f32*)(this_ + 0x10) - *(f32*)(this_ + 0x14);
    pos[0] = *(f32*)(this_ + 0xc);
    bool bVar1 = false;
    pos[1] = *(f32*)(this_ + 0x8c) + y;
    switch (fn_802265FC(pos, *(s32*)(this_ + 0x4))) {
    case 0:
        if (*(f32*)(this_ + 0x14) <= lbl_8053EFC4) {
            bVar1 = true;
        }
        break;
    case 2:
        break;
    case 1:
    default:
        bVar1 = true;
        break;
    }
    if (bVar1) {
        fn_801CCD34(pos, out);
        *(f32*)(this_ + 0x10) = (out[1] - lbl_8053EFDC) - *(f32*)(this_ + 0x8c);
        *(f32*)(this_ + 0x14) = lbl_8053EFC4;
        *(f32*)(this_ + 0x44) = lbl_8053EFC4;
        *(u32*)(this_ + 0x230) |= 8;
    }
}

extern "C" void fn_801CE914(void) {}

extern "C" void fn_801CE918(void) {}

extern "C" void fn_801CE91C(void) {}

extern "C" void fn_801CE920(void) {}

extern "C" void fn_801CE924(void) {}

extern "C" s32 fn_801CE928(u8* this_) {
    s32 result = 0;
    if (*(f32*)(this_ + 0x68) - *(f32*)(this_ + 0x60) > lbl_8053EFC4 && *(f32*)(this_ + 0x6c) - *(f32*)(this_ + 0x64) > lbl_8053EFC4) {
        result = ((s32 (*)(u8*, u32, s32, s32))fn_801F2B7C)(this_, *(u32*)(this_ + 0x114), -1, 1);
    }
    return result;
}

extern "C" s32 fn_801CE98C(u8* this_) {
    s32 result = 0;
    if (!(*(u32*)(this_ + 0x230) & 0x1000) && *(f32*)(this_ + 0x88) - *(f32*)(this_ + 0x80) > lbl_8053EFC4 && *(f32*)(this_ + 0x8c) - *(f32*)(this_ + 0x84) > lbl_8053EFC4) {
        result = ((s32 (*)(u8*, u8*, s32))fn_801F2618)(this_, this_ + 0x264, 0);
    }
    return result;
}

extern "C" s32 fn_801CE9F8(u8* this_) {
    s32 result = 0;
    if (*(f32*)(this_ + 0x68) - *(f32*)(this_ + 0x60) > lbl_8053EFC4 && *(f32*)(this_ + 0x6c) - *(f32*)(this_ + 0x64) > lbl_8053EFC4) {
        u32 tag = 0x4E554C4C;
        result = fn_801F2DB4(this_, tag, tag, 0);
    }
    return result;
}

extern "C" s32 fn_801F82CC(void* a, u8* b, u8 c, f32 d);
extern "C" void* fn_801F666C(void* a, s32 b);
extern "C" void* fn_801F856C(void);
extern "C" u8 fn_801CC8E4(void);
extern "C" u8 fn_801F37AC(u8* a, u32 b, f32* c, u32 d, u32 e, u32 f);
extern "C" u8 fn_801CEA60(u8* this_) {
    u8 result = 0;
    if (*(f32*)(this_ + 0x68) - *(f32*)(this_ + 0x60) > lbl_8053EFC4 &&
        *(f32*)(this_ + 0x6c) - *(f32*)(this_ + 0x64) > lbl_8053EFC4) {
        s32 idx = fn_801F82CC(fn_801F856C(), this_, this_[0x195], lbl_8053EFE0);
        if (idx >= 0 && idx != *(s32*)(this_ + 0x198)) {
            u8* obj = (u8*)fn_801F666C(fn_801F856C(), idx);
            if (obj != 0) {
                if (fn_801CC8E4()) {
                    result = 0;
                } else {
                    JGeometry::TVec3f vec = *(JGeometry::TVec3f*)(this_ + 0xc);
                    vec -= *(JGeometry::TVec3f*)(obj + 0x3c);
                    result = fn_801F37AC(this_, *(u32*)(obj + 0x118), (f32*)&vec, 0, *(u32*)(obj + 0x168), *(u32*)(obj + 0x110));
                }
            }
            if (result != 0) {
                obj[0x164] = 1;
            }
        }
    }
    return result;
}

extern "C" u8 fn_801CEB78(u8* this_) {
    u8 result = 0;
    if (*(f32*)(this_ + 0x68) - *(f32*)(this_ + 0x60) > lbl_8053EFC4 && *(f32*)(this_ + 0x6c) - *(f32*)(this_ + 0x64) > lbl_8053EFC4) {
        result = fn_801F2FAC(this_);
    }
    return result;
}

extern "C" u8 fn_801CEBD0(u8* this_) {
    u8 result = 0;
    if (*(f32*)(this_ + 0x68) - *(f32*)(this_ + 0x60) > lbl_8053EFC4 && *(f32*)(this_ + 0x6c) - *(f32*)(this_ + 0x64) > lbl_8053EFC4) {
        for (s32 i = 0; i < 4; i++) {
            f32 pos[2];
            s32 out;
            if (i == fn_801F285C(this_, pos, &out, 0, i)) {
                fn_8023B6CC(i);
                fn_802379E4(i, this_ + 0xc);
                if (out == 1 && fn_801EAC20(this_ + 0x1dc, i)) {
                    f32 vec[3];
                    vec[0] = pos[0];
                    vec[1] = pos[1];
                    vec[2] = lbl_8053EFC4;
                    fn_801CB538(*(u32*)(this_ + 0x4), vec, 0, 0);
                    result = 1;
                }
            }
        }
        if (result) {
            fn_801F0E34(this_, (void*)0x400d1, 0);
        }
    }
    return result;
}

extern "C" int fn_801CECEC(void) { return 0; }

extern "C" void* fn_801F666C(void* mgr, s32 idx);
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 id, f32* pos, u32 arg5, s32 arg6, s32 arg7);
extern "C" void fn_801D2CF0(void* obj, f32* dir);
extern int __float_max[];
#pragma fp_contract on
static inline f32 DirectionInvSqrt(f32 lengthSquared) {
    if (lengthSquared <= lbl_8053EFC4) {
        return lengthSquared;
    }
    f32 estimate = __frsqrte(lengthSquared);
    f32 square = estimate * estimate;
    return (lbl_8053EFE4 * estimate) * __fnmsubs(lengthSquared, square, lbl_8053EFE8);
}
#pragma opt_lifetimes off
#pragma fp_contract off
extern "C" s32 fn_801CECF4(u8* this_, u32 name, f32 radius, f32 limit) {
    f32 bestDist = *(f32*)__float_max;
    f32 limitSq = limit * limit;
    s32 index;
    s32 result;
    s32 best = -1;
    u32 ok;
    u8 found;
    u8* scan;
    s32 i;
    JGeometry::TVec2<f32> dir;
    scan = this_;
    for (i = 0; i < 4; i++, scan += 0xc) {
        found = 0;
        if (fn_801CCFE4(i)) {
            ok = 0;
            switch (*(u32*)(this_ + 0x1a0)) {
            case 0x4b45504f:
            case 0x464c4f52:
            case 0x46424745:
            case 0x46414c4c:
            case 0x48524d4e:
            case 0x54494e4b:
            case 0x534c4b32:
            case 0x4e415649:
            case 0x545a4f4b:
                index = *(s32*)(this_ + 0x4);
                s32 owner = fn_8023DE58(i);
                if (owner == index) {
                    ok = 1;
                }
                break;
            default:
                ok = fn_801F320C(this_, i);
                break;
            }
            if ((u8)ok) {
                switch (*(u32*)(this_ + 0x1a0)) {
                case 0x4e415649:
                case 0x48524d4e:
                case 0x464c4f52:
                case 0x46414c4c:
                case 0x4b45504f:
                case 0x544e4452:
                case 0x54494e4b:
                case 0x545a4f4b:
                    if (fn_8022CAF8(i) == 4) {
                        found = 1;
                    } else if (!fn_8022F514(i)) {
                        found = 1;
                    }
                    break;
                default:
                    found = 1;
                    break;
                }
            }
        }
        if (found) {
            JGeometry::TVec2<f32> delta(*(f32*)(scan + 0x1ac) - *(f32*)(this_ + 0xc), *(f32*)(scan + 0x1b0) - *(f32*)(this_ + 0x10));
            f32 d2 = delta.squared();
            if (d2 < bestDist && (lbl_8053EFC4 == limit || d2 <= limitSq)) {
                bestDist = d2;
                best = i;
            }
        }
    }
    if (best < 0) {
        return 0;
    }
    result = 0;
    index = Actor_CreateByID(fn_801F856C(), name, *(u32*)(this_ + 0x4), (f32*)(this_ + 0xc), 0, -1, -1);
    if (index >= 0) {
        void* obj = fn_801F666C(fn_801F856C(), index);
        if (obj != 0) {
            f32* target = (f32*)(this_ + 0x1ac + best * 0xc);
            f32 dx = target[0] - *(f32*)(this_ + 0xc);
            f32 dy = target[1] - *(f32*)(this_ + 0x10);
            dir.x = dx;
            dir.y = dy;
            if (dir.squared() <= JGeometry::TUtilf::epsilon()) {
                dir.x = lbl_8053EFC4;
                dir.y = radius;
            } else {
                if (!(dir.squared() <= JGeometry::TUtilf::epsilon())) {
                    f32 inv = DirectionInvSqrt(dir.squared());
                    dir.scale(inv);
                }
                dir.scale(radius);
            }
            fn_801D2CF0(obj, (f32*)&dir);
            result = 1;
        }
    }
    return result;
}
#pragma fp_contract reset
#pragma opt_lifetimes reset

#pragma fp_contract off
extern "C" s32 fn_801CF0F4(const u8* this_) {
    const f32 x = *(const f32*)(this_ + 0x3c);
    f32 a = JMath::atanTable_.atan2_(x, *(const f32*)(this_ + 0x40));
    return ClassifyBamAngleToQuadrant((s32)(a * lbl_8053EFEC));
}

extern "C" bool fn_801CF144(const u8* this_) {
    f32 pos[3];
    f32 y, x, z;
    bool result = false;
    y = *(const f32*)(this_ + 0x10) - *(const f32*)(this_ + 0x14) - lbl_8053EFF0;
    x = *(const f32*)(this_ + 0xc);
    z = lbl_8053EFC4;
    s32 room = *(const s32*)(this_ + 0x4);
    pos[0] = x;
    pos[1] = y;
    pos[2] = z;
    if (fn_801CCB1C(pos, room)) result = true;
    return result;
}

extern "C" s32 fn_801CF6B8(u8* this_);
extern "C" s32 fn_801CD354(s32 side);
extern void* lbl_8053AAF8;
static inline s32 choosePointDirection(const u8* self, const f32* pt, const u8 swap) {
    f32 dx = __fabsf(pt[0] - *(const f32*)(self + 0xc));
    f32 dy = __fabsf(pt[1] - *(const f32*)(self + 0x10));
    if ((dx > dy && swap == 0) || (dx <= dy && swap == 1)) {
        return *(const f32*)(self + 0xc) < pt[0] ? 0 : 1;
    }
    return *(const f32*)(self + 0x10) < pt[1] ? 2 : 3;
}
extern "C" s32 fn_801CF1B0(u8* this_, u8 flag, f32 a, f32 b) {
    s32 i;
    s32 best = -1;
    s32 ok;
    u8 found;
    u8* q = this_;
    f32 minDist = *(f32*)__float_max;
    f32 aSq = a * a;
    s32 ret = flag;

    for (i = 0; i < 4; i++, q += 12) {
    found = 0;
    if (fn_801CCFE4(i)) {
        ok = 0;
        switch (*(u32*)(this_ + 0x1a0)) {
        case 0x4B45504F:
        case 0x464C4F52:
        case 0x46424745:
        case 0x46414C4C:
        case 0x48524D4E:
        case 0x54494E4B:
        case 0x534C4B32:
        case 0x4E415649:
        case 0x545A4F4B: {
            s32 room = *(s32*)(this_ + 4);
            s32 owner = fn_8023DE58(i);
            if (owner == room) {
                ok = 1;
            }
            break;
        }
        default:
            ok = fn_801F320C(this_, i);
        }
        if ((u8)ok) {
            switch (*(u32*)(this_ + 0x1a0)) {
            case 0x4E415649:
            case 0x48524D4E:
            case 0x464C4F52:
            case 0x46414C4C:
            case 0x4B45504F:
            case 0x544E4452:
            case 0x54494E4B:
            case 0x545A4F4B:
                if (fn_8022CAF8(i) == 4) {
                    found = 1;
                } else if (!fn_8022F514(i)) {
                    found = 1;
                }
                break;
            default:
                found = 1;
            }
        }
    }

        if (found) {
            JGeometry::TVec2<f32> delta(*(f32*)(q + 0x1ac) - *(f32*)(this_ + 0xc), *(f32*)(q + 0x1b0) - *(f32*)(this_ + 0x10));
            f32 dist = delta.squared();
            if (dist < minDist && (lbl_8053EFC4 == a || dist <= aSq)) {
                minDist = dist;
                best = i;
            }
        }
    }

    if (best < 0) {
        ret = fn_801CF6B8(this_);
    } else {
        u8 rnd = 0;
        if (((JMARandFast*)((u8*)lbl_8053AAF8 + 0xb4))->get_ufloat_1() < b) rnd = 1;
        f32* pt = (f32*)(this_ + 0x1ac + best * 12);
        s32 dir;
        f32 dx = pt[0] - *(f32*)(this_ + 0xc);
        f32 dy = pt[1] - *(f32*)(this_ + 0x10);

        f32 absY = __fabsf(dy); f32 absX = __fabsf(dx);
        if ((absX > absY && rnd == 0) || (absX <= absY && rnd == 1)) {
            dir = *(f32*)(this_ + 0xc) < pt[0] ? 0 : 1;
        } else {
            dir = *(f32*)(this_ + 0x10) < pt[1] ? 2 : 3;
        }

        ret = dir;
        if (flag) {
            if (dir == *(s32*)(this_ + 0x98)) {
                s32 side;
                ret = fn_801CF720(this_, *(s32*)(this_ + 0x98));
                side = choosePointDirection(this_, pt, 0);
                if (ret == fn_801CD354(side)) {
                    ret = fn_801CF798(this_, ret, *(s32*)(this_ + 0x98));
                }
            }
        } else if (fn_801CFCF0(this_, dir)) {
            dx = pt[0] - *(f32*)(this_ + 0xc);
            dy = pt[1] - *(f32*)(this_ + 0x10);
            f32 absY = __fabsf(dy); f32 absX = __fabsf(dx);
            if ((absX > absY && rnd != 0) || (absX <= absY && !rnd == 1)) {
                dir = *(f32*)(this_ + 0xc) < pt[0] ? 0 : 1;
            } else {
                dir = *(f32*)(this_ + 0x10) < pt[1] ? 2 : 3;
            }
            ret = dir;
        }
    }
    return ret;
}

extern "C" s32 fn_801CF6B8(u8* this_) {
    s32 idx = fn_801CD664(4);
    if (fn_801CFCF0(this_, idx)) {
        idx = fn_801CF720(this_, idx);
    }
    return idx;
}

extern "C" u8 fn_801CCB1C(const f32* pos, s32 layer);
extern "C" u8 fn_801CFCF0(u8* this_, s32 idx);
extern "C" s32 fn_801CF798(u8* this_, s32 idx, s32 dir);
extern "C" s32 fn_801CD580(s32 exclude);
extern "C" s32 fn_801CF720(u8* this_, s32 dir) {
    s32 idx = fn_801CD580(dir);
    if (fn_801CFCF0(this_, idx)) {
        idx = fn_801CF798(this_, dir, idx);
    }
    return idx;
}

extern "C" s32 fn_801CF798(u8* this_, s32 idx, s32 dir) {
    s32 arr[2];
    s32* p = arr;
    for (s32 v = 0; v < 4; v++) {
        if (v != idx && v != dir) {
            *p++ = v;
        }
    }
    s32 i = fn_801CD664(2);
    if (fn_801CFCF0(this_, arr[i]) == 0) {
        return arr[i];
    }
    return arr[1 - i];
}

extern const f32 lbl_8053EFF4;
extern "C" u8 fn_801CFA70(ItemBase* this_, f32* a, f32* b, s32 idx);
extern "C" void fn_801CF888(ItemBase* this_, f32* a, f32* b, s32 idx) {
    f32 pa[2];
    f32 pb[2];
    if (fn_801CFA70(this_, a, b, idx)) {
        return;
    }
    f32 dy = b[1] - a[1];
    f32 dx = b[0] - a[0];
    f32 len2 = dy * dy;
    len2 += dx * dx;
    if (len2 <= lbl_8053EFE0 * *(f32*)__float_epsilon) {
        return;
    }
    if (len2 > lbl_8053EFC4) {
        f32 r = (f32)__frsqrte(len2);
        f32 rr = r * r;
        f32 inv = (lbl_8053EFE4 * r) * (lbl_8053EFE8 - len2 * rr);
        dx *= inv;
        dy *= inv;
    }
    f32 sn = JMath::sincosTable_.mTable[1536].first;
    f32 cs = JMath::sincosTable_.mTable[1536].second;
    f32 vx = (dx * cs - dy * sn) * lbl_8053EFF4;
    f32 vy = (dx * sn + dy * cs) * lbl_8053EFF4;
    pa[0] = a[0] + vx;
    pa[1] = a[1] + vy;
    pb[0] = b[0] + vx;
    pb[1] = b[1] + vy;
    if (fn_801CFA70(this_, pa, pb, idx)) {
        return;
    }
    pa[0] = a[0] - vx;
    pa[1] = a[1] - vy;
    pb[0] = b[0] - vx;
    pb[1] = b[1] - vy;
    fn_801CFA70(this_, pa, pb, idx);
}

#pragma fp_contract on
#pragma opt_propagation off
extern "C" u8 fn_801CFA70(ItemBase* this_, f32* a, f32* b, s32 idx) {
    
    JGeometry::TVec3<f32> pos;
    u8* mgr = fn_802D6A9C();
    s32 room = idx;
    f32* r;
    if (idx < 8) r = (f32*)(mgr + 0xcc); else r = (f32*)(mgr + 0xdc);
    if (a[0] < r[0] || a[1] < r[1] || a[0] >= r[2] || a[1] >= r[3] || b[0] < r[0] || b[1] < r[1] || b[0] >= r[2] || b[1] >= r[3]) return 1;
    JGeometry::TVec2<f32> dir;
    dir.x = b[0] - a[0];
    dir.y = b[1] - a[1];
    f32 len2 = dir.squared();
    f32 len = JMAFastSqrt(len2);
    if (len <= 0.0f) {
        JGeometry::TVec3<f32> vec(a[0], a[1], 0.0f);
        return this_->v17(room, &vec.x);
    }
    u8 result = 0;
    dir.normalize();
    int n = (int)(lbl_8053EFF8 * len) + 1;
    dir.scale(lbl_8053EFDC);
    pos.set(a[0], a[1], 0.0f);
    for (int i = 0; i < n; i++) {
        if (this_->v17(room, &pos.x)) { result = 1; break; }
        pos.x += dir.x; pos.y += dir.y;
    }
    if (!result) {
        JGeometry::TVec3<f32> vec(b[0], b[1], 0.0f);
        result = (*(u8 (***)(ItemBase*, s32, f32*))this_)[0x4c / 4](this_, room, &vec.x);
    }
    return result;
}
#pragma opt_propagation reset
#pragma fp_contract off
extern "C" u8 fn_801CFD68(u8* this_, s32 idx, f32 v);
extern const f32 lbl_8053EFFC;
extern "C" u8 fn_801CFCF0(u8* this_, s32 idx) {
    f32 v = lbl_8053EFFC;
    switch (idx) {
    case 0:
        v += *(f32*)(this_ + 0x88);
        break;
    case 1:
        v -= *(f32*)(this_ + 0x80);
        break;
    case 2:
        v += *(f32*)(this_ + 0x8c);
        break;
    case 3:
        v -= *(f32*)(this_ + 0x84);
        break;
    }
    return fn_801CFD68(this_, idx, v);
}

extern "C" u8 fn_801CFD68(u8* this_, s32 idx, f32 v) {
    s32 lastCol;
    s32 lastRow;
    s32 rows;
    s32 cols;
    s32 i;
    s32 j;
    int room;
    JGeometry::TVec3<f32> pos(*(JGeometry::TVec3<f32>*)(this_ + 0xc));
    v = lbl_8053EFE4 * v;
    switch (idx) {
    case 0:
        pos.x += v;
        break;
    case 1:
        pos.x -= v;
        break;
    case 2:
        pos.y += v;
        break;
    case 3:
        pos.y -= v;
        break;
    }
    f32 x0 = *(f32*)(this_ + 0x80);
    f32 y0 = *(f32*)(this_ + 0x84);
    f32 x1 = *(f32*)(this_ + 0x88);
    f32 y1 = *(f32*)(this_ + 0x8c);
    switch (idx) {
    case 0:
    case 1:
        x0 = -v;
        x1 = v;
        break;
    case 2:
    case 3:
        y0 = -v;
        y1 = v;
        break;
    }
    f32 dy = pos.y - *(f32*)(this_ + 0x14);
    room = *(s32*)(this_ + 0x4);
    x0 += pos.x;
    x1 += pos.x;
    y0 += dy;
    y1 += dy;

    u8* mgr = fn_802D6A9C();
    f32* r;
    if (room < 8) {
        r = (f32*)(mgr + 0xcc);
    } else {
        r = (f32*)(mgr + 0xdc);
    }
    u8 inside = 0;
    if (x0 >= r[0] && y0 >= r[1] && x1 < r[2] && y1 < r[3]) {
        inside = 1;
    }
    if (!inside) {
        return 1;
    }
    f32 width = x1 - x0;
    f32 height;
    if (width < lbl_8053EFC4 || (height = y1 - y0) < lbl_8053EFC4) {
        return 1;
    }

    f32 cur[3];
    cur[0] = x0;
    cur[1] = y0;
    cur[2] = lbl_8053EFC4;
    s32 nx = (s32)(lbl_8053EFF8 * width);
    s32 ny = (s32)(lbl_8053EFF8 * height);
    cols = nx + 2;
    rows = ny + 2;
    lastCol = cols - 1;
    lastRow = rows - 1;
    for (i = 0; i < rows; i++) {
        cur[0] = x0;
        if (i == lastRow) {
            cur[1] = y1;
        }
        for (j = 0; j < cols; j++) {
            if (j == lastCol) {
                cur[0] = x1;
            }
            if (((ItemBase*)this_)->v17(room, cur)) {
                return 1;
            }
            cur[0] += lbl_8053EFDC;
        }
        cur[1] += lbl_8053EFDC;
    }
    return 0;
}

extern "C" s32 fn_801D0020(u8* this_, f32* pos, s32 idx, u8 flag) {
    f32* rec = (f32*)(this_ + idx * 0xc + 0x1ac);
    f32 ax = __fabsf(rec[0] - pos[0]);
    f32 az = __fabsf(rec[1] - pos[1]);
    if (ax > az) {
        if (flag == 0) goto x_axis;
    }
    if (!(ax <= az) || flag != 1) goto z_axis;
x_axis:
    if (pos[0] < rec[0]) return 0;
    return 1;
z_axis:
    if (pos[1] < rec[1]) return 2;
    return 3;
}

#pragma fp_contract on
extern "C" void fn_801D00B4(u8* this_, s32 idx, f32* out, f32 maxLen) {
    f32* rec = (f32*)(this_ + idx * 0xc + 0x1ac);
    JGeometry::TVec2<f32> delta(rec[0] - *(f32*)(this_ + 0xc), rec[1] - *(f32*)(this_ + 0x10));
    delta.normalize();
    f32 ddx = rec[0] - *(f32*)(this_ + 0xc);
    f32 ddz = rec[1] - *(f32*)(this_ + 0x10);
    out[0] = delta.x;
    out[1] = delta.y;
    f32 a = ddx * ddx;
    f32 b = ddz * ddz;
    f32 dist = JMAFastSqrt(a + b);
    if (dist < maxLen) maxLen = dist;
    out[0] *= maxLen;
    out[1] *= maxLen;
}
#pragma opt_propagation off
#pragma fp_contract on
extern "C" void fn_801D01A0(u8* this_, f32* pos, f32* out, f32 maxLen) {
    JGeometry::TVec2<f32> delta(pos[0] - *(f32*)(this_ + 0xc), pos[1] - *(f32*)(this_ + 0x10));
    delta.normalize();
    f32 ddx = pos[0] - *(f32*)(this_ + 0xc);
    f32 ddz = pos[1] - *(f32*)(this_ + 0x10);
    out[0] = delta.x;
    out[1] = delta.y;
    f32 a = ddx * ddx;
    f32 b = ddz * ddz;
    f32 dist = JMAFastSqrt(a + b);
    if (dist < maxLen) maxLen = dist;
    out[0] *= maxLen;
    out[1] *= maxLen;
}
#pragma fp_contract off
#pragma opt_propagation reset
extern "C" s16 fn_801D0280(const u8* this_, s32 idx) {
    const Vec* self = (const Vec*)(this_ + 0xc);
    f32 x = self->x;
    f32 y = self->y;
    const Vec* rec = (const Vec*)(this_ + idx * 0xc + 0x1ac);
    f32 ang = JMath::atanTable_.atan2_(rec->x - x, rec->y - y);
    return ang * lbl_8053EFEC;
}
extern "C" s16 fn_801D02E0(const u8* this_, const Vec& pos) {
    f32 dy = pos.y - *(const f32*)(this_ + 0x10);
    f32 dx = pos.x - *(const f32*)(this_ + 0xc);
    f32 ang = JMath::atanTable_.atan2Radian(dx, dy);
    return ang * lbl_8053EFEC;
}

extern const f32 lbl_8053F000;
extern const f32 lbl_8053F004;
extern "C" s32 fn_801D0338(u8* this_, f32* pos, s16 ang) {
    u32 match;
    u8 ok;
    u8* cursor;
    s32 direction;
    s32 best;
    u32 i;
    f32 bestDist = lbl_8053F000;
    direction = ang;
    best = -1;
    cursor = this_;
    for (i = 0; (s32)i < 4; i++, cursor += 12) {
        ok = 0;
        if (fn_801CCFE4(i)) {
            match = 0;
            switch (*(u32*)(this_ + 0x1a0)) {
            case 'KEPO':
            case 'FLOR':
            case 'FBGE':
            case 'FALL':
            case 'HRMN':
            case 'TINK':
            case 'SLK2':
            case 'NAVI':
            case 'TZOK':
                { s32 room = *(s32*)(this_ + 4);
                s32 roomId = fn_8023DE58(i);
                if (roomId == room) {
                    match = TRUE;
                }
                }
                break;
            default:
                match = fn_801F320C(this_, i);
                break;
            }
            if ((u8)match) {
                switch (*(u32*)(this_ + 0x1a0)) {
                case 'NAVI':
                case 'HRMN':
                case 'FLOR':
                case 'FALL':
                case 'KEPO':
                case 'TNDR':
                case 'TINK':
                case 'TZOK':
                    if (fn_8022CAF8(i) == 4) {
                        ok = true;
                    } else if (!fn_8022F514(i)) {
                        ok = true;
                    }
                    break;
                default:
                    ok = true;
                    break;
                }
            }
        }
        if (ok) {
            f32 a = JMath::atanTable_.atan2_(*(f32*)(cursor + 0x1ac) - pos[0], *(f32*)(cursor + 0x1b0) - pos[1]);
            a *= lbl_8053EFEC;
            s32 angle = (s32)a;
            s16 delta = (s16)(direction - angle);
            f32 difference = (f32)delta;
            difference = __fabsf(difference);
            f32 score = lbl_8053F004 * difference;
            if (score < bestDist) {
                bestDist = score;
                best = i;
            }
        }
    }
    return best;
}

#pragma opt_propagation on
extern "C" s32 fn_801D05F8(u8* this_, JGeometry::TVec2<f32>* pos, f32 radius) {
    u32 match;
    u8 ok;
    u8* cursor;
    s32 best;
    u32 i;
    f32 r2 = radius * radius;
    f32 bestDist = *(f32*)__float_max;
    best = -1;
    cursor = this_;
    for (i = 0; (s32)i < 4; i++, cursor += 12) {
        ok = 0;
        if (fn_801CCFE4(i)) {
            match = 0;
            switch (*(u32*)(this_ + 0x1a0)) {
            case 'KEPO':
            case 'FLOR':
            case 'FBGE':
            case 'FALL':
            case 'HRMN':
            case 'TINK':
            case 'SLK2':
            case 'NAVI':
            case 'TZOK':
                { s32 room = *(s32*)(this_ + 4);
                s32 roomId = fn_8023DE58(i);
                if (roomId == room) {
                    match = TRUE;
                }
                }
                break;
            default:
                match = fn_801F320C(this_, i);
                break;
            }
            if ((u8)match) {
                switch (*(u32*)(this_ + 0x1a0)) {
                case 'NAVI':
                case 'HRMN':
                case 'FLOR':
                case 'FALL':
                case 'KEPO':
                case 'TNDR':
                case 'TINK':
                case 'TZOK':
                    if (fn_8022CAF8(i) == 4) {
                        ok = true;
                    } else if (!fn_8022F514(i)) {
                        ok = true;
                    }
                    break;
                default:
                    ok = true;
                    break;
                }
            }
        }
        if (ok) {
            const f32* __restrict record = (f32*)(cursor + 0x1ac);
            const f32* __restrict point = (f32*)pos;
            f32 dy = point[1];
            dy = record[1] - dy;
            f32 dx = record[0] - point[0];
            f32 d2 = dx * dx + dy * dy;
            if (d2 < bestDist && (lbl_8053EFC4 == radius || d2 <= r2)) {
                bestDist = d2;
                best = i;
            }
        }
    }
    return best;
}
#pragma opt_propagation reset
extern "C" s32 fn_801D08B4(u8* this_, u32 id, f32 radius, f32* point) {
    u32 ok;
    u8 flag;
    s32 result;

    result = 0;
    if ((s32)id >= 0 && (s32)id < 4) {
        flag = 0;
        if (fn_801CCFE4(id)) {
            ok = 0;
            switch (*(s32*)(this_ + 0x1a0)) {
            case 0x4b45504f:
            case 0x464c4f52:
            case 0x46424745:
            case 0x46414c4c:
            case 0x48524d4e:
            case 0x54494e4b:
            case 0x534c4b32:
            case 0x4e415649:
            case 0x545a4f4b: {
                s32 room = *(s32*)(this_ + 4);
                s32 roomId = fn_8023DE58(id);
                if (roomId == room) {
                    ok = 1;
                }
                break;
            }
            default:
                ok = fn_801F320C(this_, id);
                break;
            }
            if ((u8)ok) {
                switch (*(s32*)(this_ + 0x1a0)) {
                case 0x4e415649:
                case 0x48524d4e:
                case 0x464c4f52:
                case 0x46414c4c:
                case 0x4b45504f:
                case 0x544e4452:
                case 0x54494e4b:
                case 0x545a4f4b:
                    if (fn_8022CAF8(id) == 4) {
                        flag = 1;
                    } else if (!fn_8022F514(id)) {
                        flag = 1;
                    }
                    break;
                default:
                    flag = 1;
                    break;
                }
            }
        }
        if (flag) {
            f32 radiusSq = radius * radius;
            f32* record = (f32*)(this_ + id * 0xc + 0x1ac);
            f32 dz = record[1] - point[1];
            f32 dx = record[0] - point[0];
            f32 distSq = dx * dx + dz * dz;
            u8 outside = 0;
            if (distSq <= radiusSq) {
                outside = 1;
            }
            if (outside) {
                result = 1;
            }
        }
    }
    return result;
}
#pragma opt_lifetimes reset

extern "C" u8 fn_801CCFE4(u32 id);
extern "C" u32 fn_801F320C(u8* this_, u32 id);
extern "C" s32 fn_8023DE58(s32 id);
extern "C" s32 fn_8022CAF8(s32 id);
extern "C" u8 fn_8022F514(s32 id);
extern "C" s32 fn_8023DE58(s32 id);
extern "C" s32 fn_8022CAF8(s32 id);
extern "C" u8 fn_8022F514(s32 id);
extern "C" s32 fn_801D0B44(u8* this_, u32 id) {
    s32 result = 0;
    if (fn_801CCFE4(id)) {
        s32 ok = 0;
        switch (*(s32*)(this_ + 0x1a0)) {
        case 0x4b45504f:
        case 0x464c4f52:
        case 0x46424745:
        case 0x46414c4c:
        case 0x48524d4e:
        case 0x54494e4b:
        case 0x534c4b32:
        case 0x4e415649:
        case 0x545a4f4b: {
            s32 room = *(s32*)(this_ + 4);
            s32 roomId = fn_8023DE58(id);
            if (roomId == room) {
                ok = 1;
            }
            break;
        }
        default:
            ok = fn_801F320C(this_, id);
            break;
        }
        if ((u8)ok) {
            switch (*(s32*)(this_ + 0x1a0)) {
            case 0x4e415649:
            case 0x48524d4e:
            case 0x464c4f52:
            case 0x46414c4c:
            case 0x4b45504f:
            case 0x544e4452:
            case 0x54494e4b:
            case 0x545a4f4b:
                if (fn_8022CAF8(id) == 4) {
                    result = 1;
                } else if (!fn_8022F514(id)) {
                    result = 1;
                }
                break;
            default:
                result = 1;
                break;
            }
        }
    }
    return result;
}

extern "C" s32 fn_801D0D50(void* thisArg, s32 playerIdx, f32* point, f32 radius) {
    u8* p = (u8*)thisArg;
    f32 radiusSq = radius * radius;
    s32 result = 0;
    f32* record = (f32*)(p + playerIdx * 0xc + 0x1ac);
    f32 dz = record[1] - point[1];
    f32 dx = record[0] - point[0];
    f32 distSq = dx * dx + dz * dz;
    if (distSq <= radiusSq) {
        result = 1;
    }
    return result;
}
#pragma fp_contract reset

#pragma fp_contract off
extern "C" f32 fn_801D0DA0(void* thisArg, s32 playerIdx, f32* point) {
    u8* p = (u8*)thisArg;
    f32* record = (f32*)(p + playerIdx * 0xc + 0x1ac);
    f32 dz = record[1] - point[1];
    f32 dx = record[0] - point[0];
    return dx * dx + dz * dz;
}

#pragma opt_propagation off
extern "C" BOOL fn_801D0DD4(const ItemBase* this_) {
    u32 room = *(u32*)this_->mActor;
    u8* g = fn_802D6A9C();
    if (g[0x131df + room] != 0) {
        return (this_->m230 & 0x18) != 0;
    }
    return *(const f32*)(this_->mActor + 0x10) <= lbl_8053EFC4 ? TRUE : FALSE;
}
#pragma opt_propagation reset
extern "C" void fn_801D0E58(char* p) {
    f32 v[2];
    fn_801CCD34((f32*)(p + 0xc), v);
    *(f32*)(p + 0xc) = v[0];
    *(f32*)(p + 0x10) = v[1];
    *(f32*)(p + 0x18) = *(f32*)(p + 0xc);
    *(f32*)(p + 0x1c) = *(f32*)(p + 0x10);
    *(f32*)(p + 0x20) = *(f32*)(p + 0x14);
    *(f32*)(p + 0x24) = *(f32*)(p + 0xc);
    *(f32*)(p + 0x28) = *(f32*)(p + 0x10);
    *(f32*)(p + 0x2c) = *(f32*)(p + 0x14);
}

#pragma fp_contract reset

extern "C" void fn_801D0ECC(void) {}

extern "C" void fn_801D0ED0(u8* this_) {
    *(f32*)(this_ + 0x60) = lbl_8053F010;
    *(f32*)(this_ + 0x64) = lbl_8053F010;
    *(f32*)(this_ + 0x68) = lbl_8053EFDC;
    *(f32*)(this_ + 0x6c) = lbl_8053EFDC;
    *(f32*)(this_ + 0x80) = lbl_8053F010;
    *(f32*)(this_ + 0x84) = lbl_8053F010;
    *(f32*)(this_ + 0x88) = lbl_8053EFDC;
    *(f32*)(this_ + 0x8c) = lbl_8053EFDC;
    *(u32*)(this_ + 0xb0) = 0x11101;
    *(s32*)(this_ + 0x98) = fn_801CD664(4);
    *(u32*)(this_ + 0x244) = *(u32*)(this_ + 0x108);
}

extern "C" void* fn_801D0F40(u8* this_) {
    __ct__5ActorFv(this_);
    *(void**)this_ = lbl_804A4808;
    *(u32*)(this_ + 0x230) = 0;
    *(f32*)(this_ + 0x234) = lbl_8053EFC4;
    *(f32*)(this_ + 0x238) = lbl_8053EFC4;
    *(f32*)(this_ + 0x23c) = lbl_8053EFC4;
    *(u8*)(this_ + 0x240) = 0;
    *(u32*)(this_ + 0x244) = 8;
    *(u32*)(this_ + 0x248) = 0;
    *(u32*)(this_ + 0x24c) = 0;
    *(u32*)(this_ + 0x250) = 0;
    *(f32*)(this_ + 0x254) = lbl_8053EFC4;
    *(f32*)(this_ + 0x258) = lbl_8053EFC4;
    *(f32*)(this_ + 0x25c) = lbl_8053EFD0;
    *(f32*)(this_ + 0x260) = lbl_8053F014;
    *(f32*)(this_ + 0x264) = lbl_8053EFC4;
    *(f32*)(this_ + 0x268) = lbl_8053EFC4;
    *(f32*)(this_ + 0x26c) = lbl_8053EFC4;
    fn_801D267C(this_ + 0x270);
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
