#include "types.h"
#include "Game/Actor.h"
#include "Game/SinitPoolChain.h"

extern "C" u8 fn_80122834(void*);

class OPGL : public Actor {
public:
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25(s32);
};

extern "C" void fn_80124AD8(void* p) {
    ((OPGL*)p)->v25(9);
}

extern "C" void fn_80124B08(void* this_) {
    struct VObj {
        virtual void v00();
        virtual void v01();
        virtual void v02();
        virtual void v03();
        virtual void v04();
        virtual void v05();
        virtual void v06();
        virtual void v07();
        virtual void v08();
        virtual void v09();
        virtual void v0a();
        virtual void v0b();
        virtual void v0c();
        virtual void v0d();
        virtual void v0e();
        virtual void v0f();
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual void v14();
        virtual void v15();
        virtual void v16();
        virtual void v17();
        virtual void v18();
        virtual void v19(int);
    };
    if (fn_80122834(this_) && *(s32*)((char*)this_ + 0x33c) < 10) {
        ((VObj*)this_)->v19(10);
    }
}

extern "C" u8 fn_80122834(void*);
extern "C" void fn_80124B60(void* this_) {
    struct VObj {
        virtual void v00();
        virtual void v01();
        virtual void v02();
        virtual void v03();
        virtual void v04();
        virtual void v05();
        virtual void v06();
        virtual void v07();
        virtual void v08();
        virtual void v09();
        virtual void v0a();
        virtual void v0b();
        virtual void v0c();
        virtual void v0d();
        virtual void v0e();
        virtual void v0f();
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual void v14();
        virtual void v15();
        virtual void v16();
        virtual void v17();
        virtual void v18();
        virtual void v19(int);
    };
    ((VObj*)this_)->v19(8);
}

extern "C" void fn_80124B90(void* this_) {
    ((OPGL*)this_)->v25(5);
}

extern "C" void fn_80124BC0(void* this_) {
    struct VObj {
        virtual void v00();
        virtual void v01();
        virtual void v02();
        virtual void v03();
        virtual void v04();
        virtual void v05();
        virtual void v06();
        virtual void v07();
        virtual void v08();
        virtual void v09();
        virtual void v0a();
        virtual void v0b();
        virtual void v0c();
        virtual void v0d();
        virtual void v0e();
        virtual void v0f();
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual void v14();
        virtual void v15();
        virtual void v16();
        virtual void v17();
        virtual void v18();
        virtual void v19(int);
    };
    ((VObj*)this_)->v19(7);
}

extern "C" s32 fn_80123D88(u8* self);
extern "C" s32 fn_80124BF0(u8* self) {
    s32 val = *(s32*)(self + 0x33c);
    if (val >= 6 || val <= 3) {
        return 0;
    }
    return fn_80123D88(self);
}

extern "C" void fn_80121DB0(void);
extern "C" void fn_80124448(void*);
extern "C" int fn_8012285C(void*);
extern "C" float fn_80121DC8(void*, int);
extern float lbl_8053CA6C;
extern "C" void fn_80124C2C(void) {
    fn_80121DB0();
}

extern "C" void fn_801D2608(void*, void*, s32);
extern "C" void fn_801D22DC(void*, s32, s32, s32);
extern "C" void fn_801D1F14(void*, f32);
extern u8 lbl_8049E198[];
extern f32 lbl_8053CA40;
extern "C" void fn_80124C4C(u8* p) {
    fn_801D2608(p + 0x230, lbl_8049E198, 14);
    fn_801D22DC(p + 0x230, 7, 2, 0);
    fn_801D1F14(p + 0x230, lbl_8053CA40);
}

extern "C" void* fn_801F856C(void);
extern "C" void fn_801F3604(void*);
extern "C" void fn_8012202C(void*);
extern "C" void fn_80121FA8(void*);
extern "C" s32 fn_80230CFC(s32);
extern "C" void fn_801F0E34(void*, s32, s32);
extern "C" void fn_80121F34(void*);
extern "C" void fn_801F6884(void*);
extern "C" void fn_80121764(void*);
extern "C" void fn_80121ABC(void*);
extern "C" void fn_80121D68(void*);
extern "C" void fn_801220C4(void*);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D8050(void*, s32, s32, s32);
extern "C" s32 fn_80123E80(u8*, s32);
extern "C" void* fn_8022EA0C(void);
extern "C" void fn_8022FE80(void*, s32, s32, s32, s32);
extern "C" void fn_8022FF8C(s32, void*, s32, s32, s32, s32);
extern "C" u8 fn_80388CAC(s32, s32);
extern "C" void fn_8030C210(void*, void*);
extern "C" s32 fn_80138A30(void*);
extern "C" s32 fn_801F2718(void*, u32);
extern "C" void* fn_801F666C(void*, s32);
extern "C" s32 fn_80122804(void*);
extern "C" void fn_80122548(void*);
extern "C" s32 fn_802DCD0C(void*);
extern "C" s32 fn_8023DE58(s32);
extern "C" void fn_80122148(void*);
extern "C" s32 fn_8022D75C(s32);
extern "C" s32 fn_801216D0(void*, s32);
extern "C" u8 fn_80121E40(void*);
extern "C" u8 fn_801D208C(void*);
extern "C" u8 fn_801227D4(void*);
extern "C" s32 fn_801F68E0(void*);
extern "C" u8 fn_8038BD08(s32, s32, s32, void*, s32);
extern "C" u8 fn_803865B8(s32);
extern "C" void fn_80388EEC(s32);
extern "C" void fn_80124CA8(u8* p, u32 param) {
    *(u8*)(p + 0x330) = 0;
    *(u8*)(p + 0x335) = 0;
    *(s32*)(p + 0x378) = 0;
    switch (param) {
    case 0:
        *(u8*)(p + 0x330) = 1;
        fn_801D22DC(p + 0x230, 7, 2, 0);
        break;
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        *(u8*)(p + 0x11E) = 1;
        fn_801F3604(p);
        break;
    case 5:
        fn_8012202C(p);
        break;
    case 6:
        fn_80121FA8(p);
        fn_801D22DC(p + 0x230, 2, 2, 0);
        break;
    case 7:
        fn_801D22DC(p + 0x230, fn_80230CFC(fn_8012285C(p)), 2, 0);
        *(u8*)(p + 0x333) = 0;
        *(s32*)(p + 0x354) = 0;
        break;
    case 8:
        fn_801D22DC(p + 0x230, fn_80230CFC(fn_8012285C(p)), 2, 0);
        break;
    case 9:
        fn_801D22DC(p + 0x230, *(s32*)(p + 0x98) + 0xA, 0, 0);
        *(u8*)(p + 0x333) = 1;
        fn_801F0E34(p, 0x40071, 0);
        *(s32*)(p + 0x3C8) = 0;
        fn_80121F34(p);
        break;
    case 10:
        fn_801D22DC(p + 0x230, 4, 0, 0);
        fn_801F0E34(p, 0x40072, 0);
        break;
    case 11:
        fn_801F6884(fn_801F856C());
        fn_80121764(p);
        break;
    case 12:
        fn_801D22DC(p + 0x230, 2, 2, 0);
        fn_80121764(p);
        fn_80121ABC(p);
        *(u8*)(p + 0x333) = 1;
        break;
    case 13:
        fn_80121D68(p);
        fn_801220C4(p);
        break;
    case 14:
        *(u8*)(p + 0x331) = 0;
        break;
    case 15:
        fn_802D8050(fn_802D6A9C(), *(s32*)(p + 0x3CC), 1, 0xFF);
        *(u8*)(p + 0x11C) = 0;
        break;
    case 16:
    case 17:
        break;
    }
    fn_80123E80(p, param);
}

extern "C" s32 fn_80122898(void*, s32);
extern "C" void fn_801D1C18(void*);
extern f32 lbl_8053CA44;
extern f32 lbl_8053CA48;
extern f32 lbl_8053CA4C;
extern f32 lbl_8053CA50;
extern f32 lbl_8053CA54;
extern f32 lbl_8053CA58;
extern f32 lbl_8053CA5C;
extern f32 lbl_8053CA60;
extern f32 lbl_8053CA64;
extern f32 lbl_8053CA68;
extern u8 lbl_8053AAA0;
extern u8* lbl_8053AB10;
extern u8* lbl_8053AAF8;
extern "C" void fn_80124EA4(u8* this_) {
    struct VObj {
        virtual void v00();
        virtual void v01();
        virtual void v02();
        virtual void v03();
        virtual void v04();
        virtual void v05();
        virtual void v06();
        virtual void v07();
        virtual void v08();
        virtual void v09();
        virtual void v0a();
        virtual u8 v0d();
        virtual void v0e();
        virtual void v0f();
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual void v14();
        virtual void v15();
        virtual void v16();
        virtual void v17();
        virtual void v18();
        virtual void v19();
        virtual void v1a();
        virtual void v1b(s32);
        virtual void v1c();
        virtual void v1d();
        virtual void v1e();
        virtual void v1f();
        virtual void v20();
        virtual void v21();
        virtual void v22();
        virtual void v23();
        virtual void v24();
        virtual void v25();
        virtual void v26(s32, s32, f32);
        virtual void v27(s32, f32, f32, f32, f32, f32);
        virtual void v28();
        virtual void v29();
        virtual void v2a();
        virtual void v2b();
        virtual void v2c();
        virtual void v2d();
        virtual void v2e();
        virtual void v2f();
        virtual void v30();
        virtual void v31();
        virtual u8 v32(void*, f32);
    };
    VObj* self = (VObj*)this_;

    struct TBox {
        f32 x0, y0, x1, y1;
    };
    TBox box;
    box.x0 = *(f32*)(this_ + 0x60);
    box.y0 = *(f32*)(this_ + 0x64);
    box.x1 = *(f32*)(this_ + 0x68);
    box.y1 = *(f32*)(this_ + 0x6c);
    box.x0 += *(f32*)(this_ + 0xc);
    box.y0 += *(f32*)(this_ + 0x10);
    box.x1 += *(f32*)(this_ + 0xc);
    box.y1 += *(f32*)(this_ + 0x10);

    if (*(s32*)(this_ + 0x33c) >= 0xd) {
        u8* o = *(u8**)(lbl_8053AB10 + 0x30);
        if (o[0x284] == 0) {
            f32 c = lbl_8053CA44;
            o[0x284] = 1;
            *(f32*)(o + 0x28c) = c;
        }
    }

    switch (*(u32*)(this_ + 0x33c)) {
    case 0: {
        self->v26(0, 1, lbl_8053CA48);
        s32 r = fn_80122898(this_, 0x84d);
        if (r >= 0) {
            *(s32*)(this_ + 0x344) = r;
            self->v1b(1);
        }
        break;
    }
    case 1: {
        fn_8022FF8C(*(s32*)(this_ + 0x34c), &box, *(s32*)(this_ + 4), *(s32*)(this_ + 0x198), 1, 0);
        if (fn_80388CAC(*(s32*)(this_ + 0x34c), *(s32*)(this_ + 0x198))) {
            self->v1b(4);
        }
        break;
    }
    case 3: {
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), this_ + 0xc);
        u8* o = *(u8**)(lbl_8053AB10 + 0x24);
        if (o[0x840] == 0) {
            f32 a = lbl_8053CA4C;
            o[0x840] = 1;
            f32 b = lbl_8053CA50;
            f32 px = *(f32*)(this_ + 0xc);
            *(f32*)(o + 0x84c) = px;
            *(f32*)(o + 0x844) = px;
            f32 py = *(f32*)(this_ + 0x10);
            *(f32*)(o + 0x850) = py;
            *(f32*)(o + 0x848) = py;
            *(f32*)(o + 0x854) = a;
            *(f32*)(o + 0x1d4) = b;
            *(f32*)(o + 0x1d8) = b;
            fn_8012285C(this_);
            fn_8022FE80(fn_8022EA0C(), *(s32*)(this_ + 4), *(s32*)(this_ + 0x198), 0, 0);
            fn_8012285C(this_);
            if (fn_80388CAC((s32)fn_8022EA0C(), *(s32*)(this_ + 0x198))) {
                self->v1b(*(s32*)(this_ + 0x3d0));
            }
        }
        break;
    }
    case 4: {
        if (fn_8012285C(this_) < 0) {
            self->v1b(0);
            break;
        }
        if (self->v0d()) {
            self->v1b(0xe);
            break;
        }
        if (fn_80138A30(lbl_8053AAF8) > 1) {
            self->v27(fn_8012285C(this_), lbl_8053CA54, lbl_8053CA58, lbl_8053CA4C, lbl_8053CA5C, lbl_8053CA60);
        } else {
            self->v27(fn_8012285C(this_), lbl_8053CA54, lbl_8053CA58, lbl_8053CA4C, lbl_8053CA5C, lbl_8053CA64);
        }
        s32 r30 = fn_801F2718(this_, 0x48415254);
        if (r30 < 0) {
            break;
        }
        u8* e = (u8*)fn_801F666C(fn_801F856C(), r30);
        if (e == 0) {
            break;
        }
        e[0x11c] = 0;
        *(s32*)(this_ + 0x108) += 4;
        if (*(s32*)(this_ + 0x108) >= *(s32*)(this_ + 0x360) << 2) {
            *(s32*)(this_ + 0x108) = *(s32*)(this_ + 0x360) << 2;
            this_[0x335] = 1;
            break;
        }
    }
    /* fallthrough */
    case 5:
        if (fn_8012285C(this_) < 0) {
            self->v1b(0);
            break;
        }
        if (!(u8)fn_8022D75C(fn_8012285C(this_))) {
            if (*(s32*)(this_ + 4) == fn_8023DE58(fn_8012285C(this_))) {
                self->v1b(6);
            }
        }
        break;
    case 6:
        if (fn_8012285C(this_) < 0) {
            self->v1b(0);
            break;
        }
        if ((u8)fn_80122804(this_)) {
            self->v1b(4);
        }
        break;
    case 7:
        fn_80122548(this_);
        if (!(u8)fn_802DCD0C(fn_802D6A9C())) {
            self->v1b(4);
        }
        break;
    case 8:
        *(s32*)(this_ + 4) = fn_8023DE58(fn_8012285C(this_));
        fn_80122148(this_);
        if ((u8)fn_8022D75C(fn_8012285C(this_))) {
            break;
        }
        if (fn_801216D0(this_, fn_8012285C(this_)) >= 0) {
            break;
        }
        self->v1b(4);
        break;
    case 9:
        if (fn_80121E40(this_) && fn_801D208C(this_ + 0x230)) {
            f32 z = lbl_8053CA40;
            *(f32*)(this_ + 0x44) = z;
            *(f32*)(this_ + 0x40) = z;
            *(f32*)(this_ + 0x3c) = z;
            *(s32*)(this_ + 0x3c8) += 1;
            if (*(s32*)(this_ + 0x3c8) >= 0x1e) {
                *(s32*)(this_ + 0x3c8) = 0;
                self->v1b(*(s32*)(this_ + 0x340));
            }
        }
        break;
    case 10:
        if (fn_801F68E0(fn_801F856C()) && fn_801D208C(this_ + 0x230) && fn_801227D4(this_)) {
            self->v1b(0xb);
        }
        break;
    case 11:
        fn_801D1C18(this_ + 0x230);
        if (lbl_8053AAA0) {
            self->v1b(0xc);
        }
        break;
    case 12:
        if (fn_8012285C(this_) < 0) {
            self->v1b(0);
            break;
        }
        self->v1b(4);
        break;
    case 14:
        if (fn_801F68E0(fn_801F856C())) {
            self->v1b(0xf);
        }
        break;
    case 15:
        fn_8022FE80(0, *(s32*)(this_ + 4), *(s32*)(this_ + 0x198), 0, 0);
        *(s32*)(this_ + 0x3c4) += 1;
        if (*(s32*)(this_ + 0x3c4) < 0x5a) {
            break;
        }
        {
            Vec v = *(Vec*)(this_ + 0xc);
            if (fn_8038BD08(0, 0x4ba, *(s32*)(this_ + 4), &v, 0x22)) {
                *(s32*)(this_ + 0x3c4) = 0;
                self->v1b(0x10);
            }
        }
        break;
    case 16:
        fn_8022FE80(0, *(s32*)(this_ + 4), *(s32*)(this_ + 0x198), 1, 0);
        if (fn_803865B8(0)) {
            fn_80388EEC(0);
            self->v1b(0xd);
        }
        break;
    case 13: {
        u8* g = *(u8**)(lbl_8053AB10 + 0x24);
        if (g[0x7f5] == 0) {
            g[0x7f4] = 1;
            *(s32*)(g + 0x7f8) = 4;
            *(f32*)(g + 0x7fc) = *(f32*)(this_ + 0xc);
            *(f32*)(g + 0x800) = *(f32*)(this_ + 0x10);
            *(f32*)(g + 0x804) = *(f32*)(this_ + 0x14);
            g[0x7f6] = 0;
            *(f32*)(this_ + 0x380) = lbl_8053CA68;
            Vec v;
            v.x = lbl_8053CA40;
            v.y = lbl_8053CA64;
            v.z = lbl_8053CA40;
            if (self->v32(&v, *(f32*)(this_ + 0x380))) {
                self->v1b(0x11);
            }
        }
        break;
    }
    case 2:
    case 17:
    default:
        break;
    }
}

extern "C" void fn_8012562C(void* this_) {
    char* p = (char*)this_;
    *(unsigned int*)(p + 0x35c) = *(unsigned int*)(p + 0x90) & 0xFF;
    *(unsigned int*)(p + 0x3cc) = (*(unsigned int*)(p + 0x90) >> 22) & 0x1F;
}

extern "C" int fn_80125648(void* this_) {
    switch (*(int*)((char*)this_ + 0x33c)) {
    case 0xb:
        return 1;
    default:
        return 0;
    }
}

extern "C" void* fn_8012FF9C(void);
extern "C" u8 fn_80130030(void*, s32);
extern "C" void* fn_8022EA0C(void);
extern "C" void fn_8022FE80(void*, s32, s32, s32, s32);
extern "C" s32 fn_8022FD8C(s32);
extern "C" u8 fn_8038AD24(s32, s32, s32, s32, Vec*, s32);
extern "C" int fn_80125668(void* this_, s32 param_2) {
    typedef u8 (*method_t)(void*);
    typedef void (*vmethod_t)(void*, s32);
    if (*(s32*)((char*)this_ + 0x33c) == 0x11) {
        return 3;
    }
    if (!((method_t)(*(void***)this_)[0x54 / sizeof(void*)])(this_)) {
        return 0;
    }
    if (fn_80130030(fn_8012FF9C(), param_2) == 0) {
        s32 state = *(s32*)((char*)this_ + 0x33c);
        if (state != 3 && state != 0) {
            fn_8012285C(this_);
            fn_8022FE80(fn_8022EA0C(), *(s32*)((char*)this_ + 0x4), *(s32*)((char*)this_ + 0x198), 0, 0);
            s32 r = fn_8022FD8C(*(s32*)((char*)this_ + 0x198));
            if (r >= 0) {
                Vec v = *(Vec*)((char*)this_ + 0xc);
                if (fn_8038AD24(r, 0x442, *(s32*)((char*)this_ + 0x198), *(s32*)((char*)this_ + 0x4), &v, 0x28)) {
                    *(s32*)((char*)this_ + 0x3d0) = *(s32*)((char*)this_ + 0x33c);
                    vmethod_t move = (vmethod_t)(*(void***)this_)[0x6c / sizeof(void*)];
                    move(this_, 3);
                }
            }
        }
        return 1;
    }
    if (((method_t)(*(void***)this_)[0x58 / sizeof(void*)])(this_)) {
        return 2;
    }
    return 1;
}

extern "C" bool fn_801257A8(void* param_1)
{
  int v = *(int*)((char*)param_1 + 0x33c);
  switch (v) {
  case 4:
  case 7:
  case 8:
    return fn_80121DC8(param_1, fn_8012285C(param_1)) <= lbl_8053CA6C;
  case 0xF:
  case 0x10:
  default:
    return false;
  }
}

extern "C" s32 fn_80125830(void* self) {
    s32 v = *(s32*)((char*)self + 0x33c);
    switch (v) {
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        return 1;
    default:
        return 0;
    }
}

extern "C" void fn_80124448(void*);
extern "C" int fn_8012285C(void*);
extern "C" float fn_80121DC8(void*, int);
extern float lbl_8053CA6C;
extern "C" void fn_80125858(void* s)
{
  fn_80124448(s);
}

extern void* lbl_8049E1D0[];
extern "C" void fn_80124740(void*, short);
extern "C" void __dl__FPv(void*);
extern "C" void* fn_80125878(void* self, short flag) {
    if (self) {
        *(void***)self = lbl_8049E1D0;
        fn_80124740(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

extern "C" void fn_801247C8(void*, char*, s32, s32);
extern char lbl_80464E8C[];
extern "C" void* fn_801258D8(void* self) {
    fn_801247C8(self, lbl_80464E8C, 0x2e6, 1);
    *(void***)self = lbl_8049E1D0;
    *(s32*)((char*)self + 0x3c4) = 0;
    *(s32*)((char*)self + 0x3c8) = 0;
    *(s32*)((char*)self + 0x3cc) = 0;
    return self;
}

void __sinit_OPGL_80124AD8_cpp(void) {
}

