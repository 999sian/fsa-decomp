// TU 0x802BE39C-0x802BE8F8.
#include "types.h"

void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);

extern void* lbl_804A8B20[];
extern "C" void* fn_802BE39C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A8B20;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_802BE3FC(void) {}

struct ActorV {
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s10(s32 a, s32 b);
};

extern "C" u8* fn_802D6A9C(void);
extern "C" u8 fn_802D800C(void* mgr, u32 id);
extern "C" u8 fn_802D75BC(void* mgr, u32 id);
extern "C" void fn_80134DE4(void* game, s32 code, s32 param);
extern "C" void fn_802D79E8(void* mgr, s32 room, s32 a, f32 x, f32 y);
extern "C" void fn_801F3518(void* this_);
extern void* lbl_8053AAF8;

struct Obj {
    ActorV v;
    s32 room;
    u8 pad08[0x16c - 0x8];
    u32 sw16c;
    u8 pad170[0x230 - 0x170];
    s32 state;
    s32 period;
    s32 timer;
    s32 mode;
    u32 sw;
    s32 toggle;
    f32 speed;
    s32 step;
    s32 stepReset;
    u32 flag;
};

extern "C" void fn_802BE400(Obj* this_) {
    switch (this_->state) {
    case 0:
        if (fn_802D800C(fn_802D6A9C(), this_->sw)) {
            this_->state = 1;
            if (this_->mode >= 1 && this_->mode <= 5 && !fn_802D75BC(fn_802D6A9C(), this_->sw16c)) {
                fn_80134DE4(lbl_8053AAF8, 10, this_->period);
            }
        }
        break;
    case 1:
        if (!fn_802D75BC(fn_802D6A9C(), this_->sw16c)) {
            if (this_->mode >= 1 && this_->mode <= 5) {
                fn_802D79E8(fn_802D6A9C(), this_->room, 0, this_->speed, 0.0f);
                this_->step--;
                if (this_->step == 0) {
                    this_->step = this_->stepReset;
                    if (this_->mode == 4) {
                        this_->speed += 1.0f;
                        if (this_->speed >= 5.0f) {
                            this_->speed = 5.0f;
                        }
                    } else if (this_->mode == 5) {
                        this_->speed -= 1.0f;
                        if (this_->speed <= 1.0f) {
                            this_->speed = 1.0f;
                        }
                    }
                }
            }
            this_->timer--;
        } else {
            this_->timer = 0;
        }
        if (this_->timer == 0) {
            if (this_->mode == 6) {
                this_->timer = this_->period;
                this_->toggle ^= 1;
                if (this_->toggle != 0) {
                    this_->v.s10(0xff, 1);
                } else {
                    this_->v.s10(0xff, 0);
                }
            } else {
                this_->v.s10(0xff, 1);
                this_->state = 2;
            }
        }
        break;
    case 2:
        fn_801F3518(this_);
        break;
    }
}

static const f32 lbl_8046D448[6] = {0.0f, 2.0f, 4.0f, 5.0f, 1.0f, 5.0f};

extern "C" void fn_802BE628(Obj* this_) {
    u32 p = *(u32*)((u8*)this_ + 0x90);
    this_->period = p & 0x3ffff;
    this_->mode = (*(u32*)((u8*)this_ + 0x90) >> 19) & 7;
    this_->sw = (*(u32*)((u8*)this_ + 0x90) >> 22) & 0x1f;
    this_->flag = (*(u32*)((u8*)this_ + 0x90) >> 18) & 1;
    this_->toggle = 0;
    this_->timer = this_->period;
    this_->speed = lbl_8046D448[this_->mode];
    this_->step = 1;
    this_->stepReset = 1;
    if (this_->mode == 4 || this_->mode == 5) {
        this_->step = this_->timer / 5;
        this_->stepReset = this_->step;
    }
    this_->state = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

static u8 lbl_804D2BD4[0x94];
