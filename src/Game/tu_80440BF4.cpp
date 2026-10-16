#include "types.h"
#include "JSystem/J2D/J2DScreen.h"

struct fn_80440EE8_Ctx { u8 pad[0x10]; J2DGrafContext* graf; };
struct fn_80440EE8_Owner { void* vt; J2DScreen* screen; };
struct fn_80440F30_Del { virtual void destroy(int); };
extern fn_80440EE8_Ctx* lbl_805317C8;
extern "C" void fn_8013B490(fn_80440EE8_Ctx*);
struct fn_80440F30_Self { void* vt; fn_80440F30_Del* a; fn_80440F30_Del* b; };

struct fn_80440C6C_Obj {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12();
    virtual u8* find(u64);
};
struct fn_80440C6C_Owner { void* vt; fn_80440C6C_Obj* obj; };
struct fn_80440E0C_Pane {
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
virtual void v4(); virtual void v5(); virtual void v6();
virtual void setAlpha(int);
};
extern u64 lbl_8048FAA8[];

#define FN_80440CE4_V4(a) virtual void a##0(); virtual void a##1(); virtual void a##2(); virtual void a##3();
struct fn_80440CE4_Obj {
    FN_80440CE4_V4(a) FN_80440CE4_V4(b) FN_80440CE4_V4(c) FN_80440CE4_V4(d)
    FN_80440CE4_V4(e) FN_80440CE4_V4(f) FN_80440CE4_V4(g) FN_80440CE4_V4(h)
    FN_80440CE4_V4(i) FN_80440CE4_V4(j) FN_80440CE4_V4(k) FN_80440CE4_V4(l)
    FN_80440CE4_V4(m) FN_80440CE4_V4(n) FN_80440CE4_V4(o) FN_80440CE4_V4(p)
    virtual void q0(); virtual void q1();
    virtual void set(void*, int);
};

extern "C" void fn_80440BF4(fn_80440C6C_Owner* self, bool flag)
{
    if (flag) {
        u8* p = self->obj->find(0x5062623033ULL);
        p[0xb0] = true;
    } else {
        u8* p = self->obj->find(0x5062623033ULL);
        p[0xb0] = false;
    }
}

extern "C" void fn_80440C6C(fn_80440C6C_Owner* self, bool flag)
{
    if (flag) {
        u8* p = self->obj->find(0x5062613034ULL);
        p[0xb0] = true;
    } else {
        u8* p = self->obj->find(0x5062613034ULL);
        p[0xb0] = false;
    }
}

typedef void (*fn_80440CE4_Func)(void*, void*, int);
extern "C" void fn_80440CE4(fn_80440C6C_Owner* self, void* arg)
{
    u8* p = self->obj->find(0x5062623033ULL);
    p[0xb0] = true;
    ((fn_80440CE4_Obj*)self->obj->find(0x5062623032ULL))->set(arg, 0);
}

extern "C" void fn_80440D78(fn_80440C6C_Owner* self, void* arg)
{
    u8* p = self->obj->find(0x5062613034ULL);
    p[0xb0] = true;
    ((fn_80440CE4_Obj*)self->obj->find(0x5062613032ULL))->set(arg, 0);
}

extern "C" void fn_80440E0C(u8* self, f32 scale)
{
    for (int i = 0; i < 7; i++) {
        fn_80440E0C_Pane* p = (fn_80440E0C_Pane*)(*(fn_80440C6C_Obj**)(self + 4))->find(lbl_8048FAA8[i]);
        f32 a = self[0xc + i];
        p->setAlpha((int)(a * scale));
    }
}

extern "C" void fn_80440EE8(fn_80440EE8_Owner* self)
{
    fn_8013B490(lbl_805317C8);
    self->screen->draw(0.0f, 0.0f, lbl_805317C8->graf);
}

extern fn_80440EE8_Ctx* lbl_805317C8;
extern "C" void fn_8013B490(fn_80440EE8_Ctx*);
extern u8 lbl_804B1988[];
extern void* lbl_8053AED8;
extern "C" fn_80440F30_Self* fn_80440F30(fn_80440F30_Self* self, s16 flag)
{
    if (self != NULL) {
        self->vt = lbl_804B1988;
        if (self->a != NULL) {
            self->a->destroy(1);
        }
        self->a = NULL;
        if (self->b != NULL) {
            self->b->destroy(1);
        }
        self->b = NULL;
        lbl_8053AED8 = NULL;
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}

