#include "JSystem/J2D/J2DPane.h"
#include "JSystem/J2D/J2DScreen.h"

struct fn_804461D0_Self {
    void* vt;
    J2DScreen* screen;
    void* a[4];
    void* b[4];
    void* c[4];
    u8 d[4];
    u8 e[4];
    u8 f[4];
    u8 g;
};
extern "C" u64 lbl_8048FC08[];
extern "C" char lbl_80490020[];
extern "C" u8 lbl_80529DEC[];
extern "C" u8 lbl_804AF86C[];
extern "C" void fn_80402F04(void*, void*);


extern "C" void fn_8013B490(void*);
extern u8* lbl_8053AB10;
extern f32 lbl_80543D88;
struct J2DGrafContext;
typedef void (*fn_80445D24_VFn)(void*, void*, int);
extern "C" void* fn_804030C4(u32, u32);
extern "C" u32 lbl_804B1B78[];
extern "C" u32 lbl_804B1BA0[];
static inline void SetAnimation(J2DPane* pane, void* anm) {
    void** vt = *(void***)pane;
    ((fn_80445D24_VFn)vt[0x110 / 4])(pane, anm, 0);
}
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(J2DScreen*, f32, f32, const J2DGrafContext*);
struct fn_804460AC_Obj {
    virtual void Release(int);
};

extern "C" void fn_80445CDC(void* self_) {
    u8* self = (u8*)self_;
    fn_8013B490(lbl_8053AB10);
    f32 f = lbl_80543D88;
    draw__9J2DScreenFffPC14J2DGrafContext(*(J2DScreen**)(self + 4), f, f, *(const J2DGrafContext**)(lbl_8053AB10 + 0x10));
}

extern "C" void fn_80445D24(void* self_) {
    void* anm;
    u32 tag = 0x54494D47;
    u32* p2 = lbl_804B1BA0;
    u32* p1 = lbl_804B1B78;
    fn_804461D0_Self* self = (fn_804461D0_Self*)self_;
    int i = 0;
    u64* row = lbl_8048FC08;
    for (; i < 4; i++, row += 24) {
        self->g &= ~(u8)(1 << i);
        self->g &= ~(u8)(1 << (i + 4));
        anm = fn_804030C4(tag, *p1);
        SetAnimation(self->screen->search(row[13]), anm);
        SetAnimation(self->screen->search(row[14]), anm);
        SetAnimation(self->screen->search(row[15]), anm);
        SetAnimation(self->screen->search(row[16]), anm);
        SetAnimation(self->screen->search(row[17]), anm);
        SetAnimation(self->screen->search(row[18]), anm);
        SetAnimation(self->screen->search(row[19]), anm);
        SetAnimation(self->screen->search(row[20]), anm);
        SetAnimation(self->screen->search(row[21]), anm);
        SetAnimation(self->screen->search(row[22]), anm);
        anm = fn_804030C4(tag, *p2);
        SetAnimation(self->screen->search(row[0]), anm);
        SetAnimation(self->screen->search(row[1]), anm);
        ((u8*)self->screen->search(row[8]))[0xb0] = 0;
        ((u8*)self->screen->search(row[23]))[0xb0] = 0;
        ((u8*)self->screen->search(row[1]))[0xb0] = 0;
    }
}

extern "C" void __dl__FPv(void*);
extern "C" u8 lbl_804B1BB0[];
extern u8* lbl_8053AEF8;
extern "C" void* fn_804460AC(void* param_1, short param_2) {
    void* result = param_1;

    if (result != 0) {
        *(void**)result = (void*)lbl_804B1BB0;

        if (((fn_804460AC_Obj**)result)[1] != 0) {
            ((fn_804460AC_Obj**)result)[1]->Release(1);
        }
        ((fn_804460AC_Obj**)result)[1] = 0;

        fn_804460AC_Obj** ptr = (fn_804460AC_Obj**)result;
        int i = 0;
        do {
            if (ptr[2] != 0) {
                ptr[2]->Release(1);
            }
            ptr[2] = 0;
            if (ptr[6] != 0) {
                ptr[6]->Release(1);
            }
            ptr[6] = 0;
            if (ptr[10] != 0) {
                ptr[10]->Release(1);
            }
            i++;
            ptr[10] = 0;
            ptr++;
        } while (i < 4);

        lbl_8053AEF8 = 0;

        if (param_2 > 0) {
            __dl__FPv(result);
        }
    }

    return result;
}

extern "C" void* fn_804461D0(void* self_) {
    fn_804461D0_Self* self = (fn_804461D0_Self*)self_;
    self->vt = lbl_804B1BB0;
    lbl_8053AEF8 = (u8*)self;
    self->screen = new J2DScreen();
    self->screen->setPriority(lbl_80490020, 0x1100000, *(JKRArchive**)(lbl_80529DEC + 0x10));
    for (int i = 0; i < 4; i++) {
        u64* row = &lbl_8048FC08[i * 24];
        void* obj = operator new(0x2c);
        if (obj != 0) {
            *(void**)obj = lbl_804AF86C;
        }
        self->a[i] = obj;
        fn_80402F04(self->a[i], self->screen->search(row[1]));
        obj = operator new(0x2c);
        if (obj != 0) {
            *(void**)obj = lbl_804AF86C;
        }
        self->b[i] = obj;
        fn_80402F04(self->b[i], self->screen->search(row[8]));
        obj = operator new(0x2c);
        if (obj != 0) {
            *(void**)obj = lbl_804AF86C;
        }
        self->c[i] = obj;
        fn_80402F04(self->c[i], self->screen->search(row[23]));
    }
    self->d[0] = 0;
    self->e[0] = 0;
    self->f[0] = 1;
    self->d[1] = 0;
    self->e[1] = 0;
    self->f[1] = 1;
    self->d[2] = 0;
    self->e[2] = 0;
    self->f[2] = 1;
    self->d[3] = 0;
    self->e[3] = 0;
    self->f[3] = 1;
    self->g = 0;
    return self_;
}

