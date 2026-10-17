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

extern "C" void fn_801CE00C(void) {}

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
        this_->m24C = this_->m24C < 0 ? 0 : this_->m24C;
        this_->v34();
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
    this_->v34();
    this_->v35();
}

extern "C" s32 fn_801CD950(f32* value, f32 target, f32 step);
extern const f32 lbl_8053EFCC;
extern "C" void fn_801CE32C(ItemBase* this_) {
    f32 a = *(f32*)((u8*)this_ + 0x254);
    f32 b = *(f32*)((u8*)this_ + 0x258);
    if (a != b) {
        f32 step = *(f32*)((u8*)this_ + 0x25c);
        if (a > b) {
            step = *(f32*)((u8*)this_ + 0x260);
        }
        fn_801CD950((f32*)((u8*)this_ + 0x254), b, step);
    }
    this_->v34();
    *(JGeometry::TVec3<f32>*)((u8*)this_ + 0xc) += *(JGeometry::TVec3<f32>*)((u8*)this_ + 0x3c);
    this_->v35();
    if (*(f32*)((u8*)this_ + 0x14) <= lbl_8053EFC4) {
        u32 idx = *(u32*)((u8*)this_ + 0x4);
        u8* mgr = fn_802D6A9C();
        if (mgr[0x131df + idx]) {
            this_->v32();
        } else if (*(u32*)((u8*)this_ + 0x230) & 0x40) {
            *(f32*)((u8*)this_ + 0x14) = -*(f32*)((u8*)this_ + 0x14) * lbl_8053EFCC;
            *(f32*)((u8*)this_ + 0x44) = -*(f32*)((u8*)this_ + 0x44) * lbl_8053EFCC;
            *(f32*)((u8*)this_ + 0x254) *= lbl_8053EFCC;
            *(f32*)((u8*)this_ + 0x258) *= lbl_8053EFCC;
            *(f32*)((u8*)this_ + 0x3c) *= lbl_8053EFCC;
            *(f32*)((u8*)this_ + 0x40) *= lbl_8053EFCC;
            if (__fabs(*(f32*)((u8*)this_ + 0x44)) < lbl_8053EFD0) {
                *(f32*)((u8*)this_ + 0x14) = lbl_8053EFC4;
                *(f32*)((u8*)this_ + 0x44) = lbl_8053EFC4;
            } else {
                this_->v31();
            }
        } else {
            *(f32*)((u8*)this_ + 0x14) = lbl_8053EFC4;
            *(f32*)((u8*)this_ + 0x44) = lbl_8053EFC4;
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
            bool hit = true;
            f32 out[2];
            f32 vec[2];
            f32 y = *(f32*)(this_ + 0x10) - *(f32*)(this_ + 0x14);
            vec[0] = *(f32*)(this_ + 0xc);
            vec[1] = *(f32*)(this_ + 0x8c) + y;
            u16 kind = fn_802265FC(vec, *(s32*)(this_ + 0x4));
            switch (kind) {
            case 0:
                hit = *(f32*)(this_ + 0x14) <= lbl_8053EFC4;
                break;
            case 2:
                hit = false;
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
    if (!(*(f32*)(this_ + 0x88) - *(f32*)(this_ + 0x80) > lbl_8053EFC4)) {
        return;
    }
    if (!(*(f32*)(this_ + 0x8c) - *(f32*)(this_ + 0x84) > lbl_8053EFC4)) {
        return;
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
    case 1:
        bVar1 = true;
        break;
    case 2:
        break;
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
    u8* obj = 0;
    if (*(f32*)(this_ + 0x68) - *(f32*)(this_ + 0x60) > lbl_8053EFC4 &&
        *(f32*)(this_ + 0x6c) - *(f32*)(this_ + 0x64) > lbl_8053EFC4) {
        s32 idx = fn_801F82CC(fn_801F856C(), this_, this_[0x195], lbl_8053EFE0);
        if (idx >= 0 && idx != *(s32*)(this_ + 0x198)) {
            obj = (u8*)fn_801F666C(fn_801F856C(), idx);
            if (obj != 0) {
                if (fn_801CC8E4()) {
                    result = 0;
                } else {
                    JGeometry::TVec3f vec = *(JGeometry::TVec3f*)(this_ + 0xc);
                    vec -= *(JGeometry::TVec3f*)(obj + 0x3c);
                    result = fn_801F37AC(this_, *(u32*)(obj + 0x118), (f32*)&vec, 0, *(u32*)(obj + 0x168), *(u32*)(obj + 0x110));
                }
                if (result != 0) {
                    obj[0x164] = 1;
                }
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

#pragma fp_contract off
extern "C" s32 fn_801CF0F4(u8* this_) {
    f32 x = *(f32*)(this_ + 0x3c);
    f32 a = JMath::atanTable_.atan2_(x, *(f32*)(this_ + 0x40));
    s32 q = (s32)(a * lbl_8053EFEC);
    return ClassifyBamAngleToQuadrant(q);
}

extern "C" bool fn_801CF144(u8* this_) {
    f32 pos[3];
    bool result = false;
    f32 y = *(f32*)(this_ + 0x10) - *(f32*)(this_ + 0x14) - lbl_8053EFF0;
    pos[0] = *(f32*)(this_ + 0xc);
    pos[1] = y;
    pos[2] = lbl_8053EFC4;
    if (fn_801CCB1C(pos, *(s32*)(this_ + 0x4))) {
        result = true;
    }
    return result;
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
    s32 v = 0;
    if (idx != v && dir != v) {
        *p = v;
        p++;
    }
    v = 1;
    if (idx != v && dir != v) {
        *p = v;
        p++;
    }
    v = 2;
    if (idx != v && dir != v) {
        *p = v;
        p++;
    }
    v = 3;
    if (idx != v && dir != v) {
        *p = v;
    }
    s32 i = fn_801CD664(2);
    if (fn_801CFCF0(this_, arr[i]) == 0) {
        return arr[i];
    }
    return arr[1 - i];
}

extern "C" u8 fn_801CFA70(ItemBase* this_, f32* a, f32* b, s32 idx) {
    f32 vec[3];
    u8* mgr = fn_802D6A9C();
    f32* r;
    if (idx < 8) {
        r = (f32*)(mgr + 0xcc);
    } else {
        r = (f32*)(mgr + 0xdc);
    }
    if (a[0] < r[0] || a[1] < r[1] || a[0] >= r[2] || a[1] >= r[3] || b[0] < r[0] || b[1] < r[1] || b[0] >= r[2] || b[1] >= r[3]) {
        return 1;
    }
    f32 dx = b[0] - a[0];
    f32 dy = b[1] - a[1];
    f32 len2 = dx * dx + dy * dy;
    f32 len = sqrt(len2);
    if (len <= lbl_8053EFC4) {
        vec[0] = a[0];
        vec[1] = a[1];
        vec[2] = lbl_8053EFC4;
        return this_->v17(idx, vec);
    }
    if (len2 > FLT_EPSILON * lbl_8053EFE0) {
        f32 inv = 1.0f / sqrt(len2);
        dx *= inv;
        dy *= inv;
    }
    s32 n = (s32)(lbl_8053EFF8 * len) + 1;
    dx *= lbl_8053EFDC;
    dy *= lbl_8053EFDC;
    f32 pos[3];
    pos[0] = a[0];
    pos[1] = a[1];
    pos[2] = lbl_8053EFC4;
    u8 result = 0;
    for (s32 i = 0; i < n; i++) {
        if (this_->v17(idx, pos)) {
            result = 1;
            break;
        }
        pos[0] += dx;
        pos[1] += dy;
    }
    if (result == 0) {
        vec[0] = b[0];
        vec[1] = b[1];
        vec[2] = lbl_8053EFC4;
        result = this_->v17(idx, vec);
    }
    return result;
}

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

extern "C" s32 fn_801D0020(u8* this_, f32* pos, s32 idx, u8 flag) {
    f32* rec = (f32*)(this_ + idx * 0xc + 0x1ac);
    f32 dx = rec[0] - pos[0];
    f32 dz = rec[1] - pos[1];
    if (__fabsf(dx) > __fabsf(dz)) {
        if (flag == 0) {
            goto x_axis;
        }
        if (flag == 1) {
            goto x_axis;
        }
    }
    if (__fabsf(dx) <= __fabsf(dz) || flag != 1) {
        if (pos[1] < rec[1]) {
            return 2;
        }
        return 3;
    }
x_axis:
    if (pos[0] < rec[0]) {
        return 0;
    }
    return 1;
}

#pragma fp_contract on
extern "C" void fn_801D00B4(u8* this_, s32 idx, f32* out, f32 maxLen) {
    f32* rec = (f32*)(this_ + idx * 0xc + 0x1ac);
    f32 dz = rec[1] - *(f32*)(this_ + 0x10);
    f32 dx = rec[0] - *(f32*)(this_ + 0xc);
    f32 lenSq = dx * dx + dz * dz;
    if (lenSq <= lbl_8053EFE0 * *(f32*)__float_epsilon) {
    } else {
        f32 scale;
        if (lenSq <= lbl_8053EFC4) {
            scale = lenSq;
        } else {
            f32 y = __frsqrte(lenSq);
            scale = lbl_8053EFE4 * y * (lbl_8053EFE8 - lenSq * (y * y));
        }
        dx *= scale;
        dz *= scale;
    }
    f32 ddz = rec[1] - *(f32*)(this_ + 0x10);
    f32 ddx = rec[0] - *(f32*)(this_ + 0xc);
    f32 dist = ddx * ddx + ddz * ddz;
    out[0] = dx;
    out[1] = dz;
    if (dist > lbl_8053EFC4) {
        dist = __frsqrte(dist) * dist;
    }
    if (dist < maxLen) {
        maxLen = dist;
    }
    out[0] *= maxLen;
    out[1] *= maxLen;
}
#pragma fp_contract off
extern "C" void fn_801D01A0(u8* this_, f32* pos, f32* out, f32 maxLen) {
    f32 dx = pos[0] - *(f32*)(this_ + 0xc);
    f32 dz = pos[1] - *(f32*)(this_ + 0x10);
    f32 lenSq = dx * dx + dz * dz;
    if (lenSq <= lbl_8053EFE0 * *(f32*)__float_epsilon) {
    } else {
        f32 scale;
        if (lenSq <= lbl_8053EFC4) {
            scale = lenSq;
        } else {
            f32 y = __frsqrte(lenSq);
            scale = lbl_8053EFE4 * y * (lbl_8053EFE8 - lenSq * (y * y));
        }
        dx *= scale;
        dz *= scale;
    }
    out[0] = dx;
    out[1] = dz;
    f32 ddx = pos[0] - *(f32*)(this_ + 0xc);
    f32 ddz = pos[1] - *(f32*)(this_ + 0x10);
    f32 dist = ddx * ddx + ddz * ddz;
    if (dist > lbl_8053EFC4) {
        dist = dist * __frsqrte(dist);
    }
    if (dist < maxLen) {
        maxLen = dist;
    }
    out[0] *= maxLen;
    out[1] *= maxLen;
}

#pragma fp_contract off
extern "C" s16 fn_801D0280(u8* this_, s32 idx) {
    Vec* rec = (Vec*)(this_ + idx * 0xc + 0x1ac);
    Vec* self = (Vec*)(this_ + 0xc);
    return JMAAtan2Radian(rec->x - self->x, rec->y - self->y) * lbl_8053EFEC;
}

extern "C" s16 fn_801D02E0(u8* this_, const Vec& pos) {
    f32 px = pos.x;
    f32 py = pos.y;
    return lbl_8053EFEC * JMAAtan2Radian(px - *(f32*)(this_ + 0xc), py - *(f32*)(this_ + 0x10));
}

extern "C" s32 fn_801D05F8(u8* this_, JGeometry::TVec2<f32>* pos, f32 radius) {
    s32 best = -1;
    f32 bestDist = *(f32*)__float_max;
    f32 r2 = radius * radius;
    for (s32 i = 0; i < 4; i++) {
        bool ok = false;
        if (fn_801CCFE4(i)) {
            bool match = false;
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
                match = fn_8023DE58(i) == *(s32*)(this_ + 0x4);
                break;
            default:
                match = fn_801F320C(this_, i);
                break;
            }
            if (match) {
                switch (*(u32*)(this_ + 0x1a0)) {
                case 'NAVI':
                case 'HRMN':
                case 'FLOR':
                case 'FALL':
                case 'KEPO':
                case 'TNDR':
                case 'TINK':
                case 'TZOK':
                    ok = fn_8022CAF8(i) == 4 || !fn_8022F514(i);
                    break;
                default:
                    ok = true;
                    break;
                }
            }
        }
        if (ok) {
            JGeometry::TVec3<f32>* arr = (JGeometry::TVec3<f32>*)(this_ + 0x1ac);
            f32 dx = arr[i].x - pos->x;
            f32 dy = arr[i].y - pos->y;
            f32 d2 = dx * dx + dy * dy;
            if (d2 < bestDist && (radius == lbl_8053EFC4 || d2 <= r2)) {
                bestDist = d2;
                best = i;
            }
        }
    }
    return best;
}

#pragma fp_contract off
extern "C" s32 fn_801D08B4(u8* this_, s32 id, f32 radius, f32* point) {
    s32 result;
    u8 flag;
    s32 ok;

    result = 0;
    if (id >= 0 && id < 4) {
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
            if (!(distSq <= radiusSq)) {
                result = 1;
            }
        }
    }
    return result;
}
#pragma fp_contract reset

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

extern "C" BOOL fn_801D0DD4(char* this_) {
    struct TndrG { u8 pad[0x131df]; u8 arr[4]; };
    struct Self { u8 pad0[4]; s32 room; u8 pad8[0xc]; f32 f14; u8 pad18[0x218]; u32 flags; };
    Self* s = (Self*)this_;
    s32 room = s->room;
    TndrG* g = (TndrG*)fn_802D6A9C();
    if (g->arr[room] != 0) {
        return (s->flags & 0x18) != 0;
    }
    return s->f14 <= lbl_8053EFC4 ? TRUE : FALSE;
}

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
