#include "JSystem/JGeometry/Vec.h"

class WaveController {
public:
    WaveController(s32 a, s32 b, s32 c);
    ~WaveController();
private:
    unsigned char pad[0x5c];
};

struct WaveSubBase { u8 pad[8]; };
struct WaveSub : WaveSubBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void release(s32 how);
};

struct WaveOwner {
    void* vtbl;
    void* mpSub;
};

extern char lbl_804A7C98[];
extern void* lbl_8053AC98;
extern char* lbl_8053AB10;
extern "C" s32 fn_80226BC4(JGeometry::TVec2<f32>* pos, s32 room);
extern "C" void fn_802F9974(void* mgr, u32 room, s32 idx, u16 value);

extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D7970(void* p, s32 v);
extern "C" void fn_80138B7C(void* p);
extern "C" void* fn_8023E724(void* p);
extern "C" u32 fn_802A0800(char* self, void* p3, u32 room);
extern void* lbl_8053AAF8;
extern "C" void fn_8029D898(void* a, s32 b) {
    s32 v = *(s32*)((char*)fn_802D6A9C() + 0x34);
    fn_802D7970(fn_802D6A9C(), b);
    fn_80138B7C(lbl_8053AAF8);
    fn_802D7970(fn_802D6A9C(), v);
}

extern "C" void fn_802A381C(void* self, JGeometry::TVec2<f32>* pos, u32 room, u32 value) {
    JGeometry::TVec2<f32> p(pos->x, pos->y);
    s32 r = fn_80226BC4(&p, room & 0xfe);
    fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), room, r, value);
}

extern "C" void fn_802A3D80(char* p) {
    *(s32*)(p + 0x8) = 10;
    *(s32*)(p + 0xc) = 0;
    *(s32*)(p + 0x10) = 10;
    *(s32*)(p + 0x14) = 0;
    *(s32*)(p + 0x18) = 10;
    *(s32*)(p + 0x1c) = 0;
}

extern "C" WaveOwner* fn_802A3DA4(WaveOwner* this_, s16 del) {
    if (this_ != 0) {
        this_->vtbl = lbl_804A7C98;
        lbl_8053AC98 = 0;
        if (this_->mpSub != 0) {
            ((WaveSub*)this_->mpSub)->release(1);
        }
        this_->mpSub = 0;
        if (del > 0) {
            delete this_;
        }
    }
    return this_;
}

extern "C" WaveOwner* fn_802A3E2C(WaveOwner* this_) {
    this_->vtbl = lbl_804A7C98;
    lbl_8053AC98 = this_;
    WaveController* w = new WaveController(0, 0, 8);
    this_->mpSub = w;
    return this_;
}

