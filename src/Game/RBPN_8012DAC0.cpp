// RBPN_8012DAC0: .text 0x8012DAC0-0x8012DF70 (actor RBPN, periodic effect spawner)
#include "types.h"

extern "C" void v01__5ActorFv(void* this_);
extern "C" void __dt__5ActorFv(void* this_, s16 freeFlag);
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D800C(void* mgr, s32 flag);
extern "C" void fn_802A381C(void* mgr, void* pos, u32 room, s32 id);
void operator delete(void* p);
extern void* lbl_8049E848[];
extern u8* lbl_8053AAF8;
extern void* lbl_8053AC98;
extern const u16 lbl_8053CC30[4];
extern const s32 lbl_804650F8[];

class RBPN_Actor {
public:
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30(s32, s32);
    virtual u8 vf34();
    virtual void vf38();
    virtual s32 vf3C();
};

extern "C" void* fn_8012DAC0(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049E848;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

static inline void spawnEffect(u16 id, u8* this_) {
    fn_802A381C(lbl_8053AC98, this_ + 0xC, *(u32*)(this_ + 4), id);
}

extern "C" void fn_8012DB20(u8* this_) {
    switch (*(s32*)(this_ + 0x230)) {
    case 0: {
        if (((RBPN_Actor*)this_)->vf3C() != 0 && !((RBPN_Actor*)this_)->vf34()) {
            *(s32*)(this_ + 0x230) = 1;
            break;
        }
        s32 flag = *(s32*)(this_ + 0x244);
        if (flag != 0 && fn_802D800C(fn_802D6A9C(), flag)) {
            *(s32*)(this_ + 0x238) = *(s32*)(this_ + 0x23C);
        }
        (*(s32*)(this_ + 0x238))++;
        if (*(s32*)(this_ + 0x238) >= *(s32*)(this_ + 0x23C)) {
            s32 idx;
            if (lbl_8053AAF8[0x7F] != 0) {
                (*(s32*)(this_ + 0x240))--;
                if (*(s32*)(this_ + 0x240) < 0) {
                    *(s32*)(this_ + 0x240) = 3;
                }
                if (lbl_8053AAF8[0x7E] != 0) {
                    idx = lbl_804650F8[*(s32*)(this_ + 0x240)];
                } else {
                    idx = *(s32*)(this_ + 0x240);
                }
            } else {
                (*(s32*)(this_ + 0x240))++;
                if (*(s32*)(this_ + 0x240) >= 4) {
                    *(s32*)(this_ + 0x240) = 0;
                }
                idx = *(s32*)(this_ + 0x240);
            }
            spawnEffect(lbl_8053CC30[idx], this_);
            *(s32*)(this_ + 0x238) = 0;
        }
        break;
    }
    case 1:
        if (((RBPN_Actor*)this_)->vf3C() == 0) {
            *(s32*)(this_ + 0x230) = 0;
        } else if (((RBPN_Actor*)this_)->vf34()) {
            *(s32*)(this_ + 0x230) = 0;
        }
        break;
    case 2:
    default:
        break;
    }
}

extern "C" void fn_8012DCE8(u8* this_) {
    *(s32*)(this_ + 0x23C) = *(u32*)(this_ + 0x90) & 0x7F;
    *(s32*)(this_ + 0x23C) = *(s32*)(this_ + 0x23C) * 10;
    if (*(s32*)(this_ + 0x23C) <= 0) {
        *(s32*)(this_ + 0x23C) = 120;
    }
    *(s32*)(this_ + 0x234) = (*(u32*)(this_ + 0x90) >> 7) & 0x1F;
    if (*(s32*)(this_ + 0x234) >= 4) {
        *(s32*)(this_ + 0x234) = 0;
    }
    *(s32*)(this_ + 0x240) = *(s32*)(this_ + 0x234);
    *(s32*)(this_ + 0x244) = (*(u32*)(this_ + 0x90) >> 22) & 0x1F;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
