// DEAL_80108414: .text 0x80108414-0x80108A6C (actor DEAL)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

// ---- from Game/fn_80108414_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
void operator delete(void* p);
extern void* lbl_8049CD48[];
extern void* lbl_8049CC34[];

extern "C" void* fn_80108414(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_8049CD48;
        if (p + 0x238 != 0) {
            if (p + 0x25c != 0) {
                *(void**)(p + 0x25c) = lbl_8049CC34;
            }
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

// ---- fn_80108494 / fn_80108568 / fn_80108764
extern "C" void v06__5ActorFv(void* this_);
extern "C" void v03__5ActorFv(void* this_);
extern "C" void v01__5ActorFv(void* this_);
extern "C" void fn_801D1C18(void*);
extern "C" void fn_801D2608(void*, void*, s32);
extern "C" void fn_801D22DC(void*, s32, s32, s32);
extern "C" void fn_801D1F14(void*, f32);
extern "C" void fn_80239914(void*, s32, void*);
extern "C" void fn_802F86CC(void*, void*, void*, s32, f32, f32, s32);
extern "C" void fn_803075AC(void*, s32, void*, s32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_8022FEB8(void*, s32, void*, s32, s32);
extern "C" s32 fn_8022FD8C(void*);
extern "C" u8 fn_802300EC(void);
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F7A08(void*, u32);
extern "C" void* fn_801F666C(void*, s32);
extern "C" u8 fn_8038AD24(s32, u16, void*, s32, JGeometry::TVec3f, s32);
extern "C" void fn_8022FF8C(s32, void*, s32, void*, s32, s32);
extern "C" u8 fn_80388CAC(s32, void*);
extern "C" u8 fn_80388EEC(s32);

extern const char lbl_80464014[];
extern u8 lbl_80539ED8[8];
extern const f32 lbl_8053C318;
extern const f32 lbl_8053C31C;
extern const f32 lbl_8053C320;
extern const f32 lbl_8053C324;
extern u8* lbl_8053AAF8;
extern u8* lbl_8053AB10;

class DEAL_ResMgr {
public:
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void* vf18(u32 type, const char* name);
};

struct DEAL_Box {
    f32 x0, y0, x1, y1;
};


extern "C" void fn_80108494(u8* this_) {
    v06__5ActorFv(this_);
    s32 id = *(s32*)(this_ + 0x248) + 0x1AB;
    void* pos = this_ + 0xC;
    if (*(s32*)(this_ + 4) < 8) {
        void* res = (*(DEAL_ResMgr**)(lbl_8053AAF8 + 0xA4))->vf18('SOB ', lbl_80464014);
        fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), pos, res, id, lbl_8053C318, lbl_8053C318, 0);
    }
    fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xC,
                *(s32*)(this_ + 0x248) + 0x1AB, 0, 1, -1, 0, 0, 0);
}

static inline u8 DEAL_HasItem() {
    s32 idx = fn_801F7A08(fn_801F856C(), 'SITM');
    if (idx < 0) {
        return 0;
    }
    if (fn_801F666C(fn_801F856C(), idx) == 0) {
        return 0;
    }
    return 1;
}

extern "C" void fn_80108568(u8* this_) {
    v03__5ActorFv(this_);
    DEAL_Box b;
    b.x0 = *(f32*)(this_ + 0x60);
    b.y0 = *(f32*)(this_ + 0x64);
    b.x1 = *(f32*)(this_ + 0x68);
    b.y1 = *(f32*)(this_ + 0x6C);
    b.x0 += *(f32*)(this_ + 0xC);
    b.y0 += *(f32*)(this_ + 0x10);
    b.x1 += *(f32*)(this_ + 0xC);
    b.y1 += *(f32*)(this_ + 0x10);
    fn_80239914(&b, *(s32*)(this_ + 4), *(void**)(this_ + 0x198));
    switch (*(s32*)(this_ + 0x230)) {
    case 0: {
        fn_8022FEB8(&b, *(s32*)(this_ + 4), *(void**)(this_ + 0x198), 1, 0);
        s32 slot = fn_8022FD8C(*(void**)(this_ + 0x198));
        if (slot >= 0 && fn_802300EC()) {
            int msg = 0x259;
            if (!DEAL_HasItem()) {
                msg = 0x2AA;
            }
            void* room = *(void**)(this_ + 0x198);
            s32 player = *(s32*)(this_ + 4);
            if (fn_8038AD24(slot, msg, room, player, *(JGeometry::TVec3f*)(this_ + 0xC), 0x28)) {
                *(s32*)(this_ + 0x234) = slot;
                *(s32*)(this_ + 0x230) = 1;
            }
        }
        break;
    }
    case 1:
        fn_8022FF8C(*(s32*)(this_ + 0x234), &b, *(s32*)(this_ + 4), *(void**)(this_ + 0x198), 1, 0);
        if (fn_80388CAC(*(s32*)(this_ + 0x234), *(void**)(this_ + 0x198))) {
            *(s32*)(this_ + 0x234) = -1;
            *(s32*)(this_ + 0x230) = 0;
        }
        break;
    case 3:
        if (fn_80388EEC(*(s32*)(this_ + 0x234))) {
            *(s32*)(this_ + 0x234) = -1;
            *(s32*)(this_ + 0x230) = 0;
        }
        break;
    }
    fn_801D1C18(this_ + 0x238);
}

extern "C" void fn_80108764(u8* this_) {
    v01__5ActorFv(this_);
    *(f32*)(this_ + 0x60) = lbl_8053C31C;
    *(f32*)(this_ + 0x64) = lbl_8053C31C;
    *(f32*)(this_ + 0x68) = lbl_8053C320;
    *(f32*)(this_ + 0x6C) = lbl_8053C320;
    *(f32*)(this_ + 0x80) = lbl_8053C324;
    *(f32*)(this_ + 0x84) = lbl_8053C324;
    *(f32*)(this_ + 0x88) = lbl_8053C324;
    *(f32*)(this_ + 0x8C) = lbl_8053C324;
    *(s32*)(this_ + 0x108) = 0;
    fn_801D2608(this_ + 0x238, lbl_80539ED8, 1);
    fn_801D22DC(this_ + 0x238, 0, 2, 0);
    fn_801D1F14(this_ + 0x238, lbl_8053C324);
}

// ---- from Game/fn_801087F4_ctor.cpp

struct Actor {
    Actor();
    ~Actor();
};

extern "C" void fn_801D267C(void*);
extern void* lbl_8049CD48[];

class fn_801087F4_actor : public Actor {
public:
    fn_801087F4_actor();
};

fn_801087F4_actor::fn_801087F4_actor() : Actor() {
    *(void**)this = lbl_8049CD48;
    char* p = (char*)this;
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x234) = -1;
    fn_801D267C(p + 0x238);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
