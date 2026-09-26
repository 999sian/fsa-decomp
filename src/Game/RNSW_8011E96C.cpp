// RNSW_8011E96C: .text 0x8011E96C-0x8011EEEC (actor RNSW, random flag switch)
#include "types.h"

extern "C" void __dt__5ActorFv(void* this_, s16 freeFlag);
extern "C" void detach__5ActorFv(void* actor);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D8050(void* mgr, s32 flag, s32 on, s32 c);
extern "C" s32 fn_801CD664(s32 n);
extern "C" s32 fn_8023DE58(s32 playerIdx);
void operator delete(void* p);
extern void* lbl_8049DE90[];

class RNSW_Actor {
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

#define S32(o) (*(s32*)(this_ + (o)))

struct RNSW_Data {
    u8 _000[0x244];
    s32 mFlags[4];
};
#define FLAGS (((RNSW_Data*)this_)->mFlags)

extern "C" void* fn_8011E96C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049DE90;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

static inline void setFlag(s32 flag, s32 on) {
    fn_802D8050(fn_802D6A9C(), flag, on, 0xFF);
}
static inline void switchTo(u8* this_, s32 sel) {
    RNSW_Data* sp = (RNSW_Data*)(this_ + sel * 4);
    if (sp->mFlags[0] != 0) {
        for (int i = 0; i < 4; i++) {
            if (i != sel && FLAGS[i] != FLAGS[sel]) {
                setFlag(FLAGS[i], 0);
            }
        }
        setFlag(sp->mFlags[0], 1);
    }
}

extern "C" void fn_8011E9CC(u8* this_) {
    s32 sel;
    switch (S32(0x230)) {
    case 0:
        if (((RNSW_Actor*)this_)->vf3C() != 0 && !((RNSW_Actor*)this_)->vf34()) {
            S32(0x230) = 1;
            break;
        }
        S32(0x238)++;
        if (S32(0x238) >= S32(0x23C)) {
            sel = fn_801CD664(4);
            if (S32(0x234) == 1) {
                sel = S32(0x240);
                S32(0x240) = sel + 1;
                if (S32(0x240) >= 4) {
                    S32(0x240) = 0;
                }
            }
            switchTo(this_, sel);
            S32(0x238) = 0;
        }
        if (S32(0x23C) == 0) {
            S32(0x230) = 2;
            detach__5ActorFv(this_);
        }
        break;
    case 1: {
        if (S32(0x23C) == 0) {
            BOOL found;
            if (S32(4) == 0) {
                found = TRUE;
            } else {
                for (int i = 0; i < 4; i++) {
                    if (S32(4) == fn_8023DE58(i)) {
                        found = TRUE;
                        goto done;
                    }
                }
                found = FALSE;
            }
        done:
            if ((u8)found) {
                S32(0x230) = 0;
                break;
            }
        }
        if (((RNSW_Actor*)this_)->vf3C() == 0) {
            S32(0x230) = 0;
        } else if (((RNSW_Actor*)this_)->vf34()) {
            S32(0x230) = 0;
        }
        break;
    }
    case 2:
    default:
        break;
    }
}

extern "C" void fn_8011EBF0(u8* this_) {
    BOOL ok = TRUE;
    S32(0x23C) = *(u32*)(this_ + 0x90) & 0x3F;
    S32(0x23C) = S32(0x23C) * 10;
    S32(0x234) = (*(u32*)(this_ + 0x90) >> 6) & 1;
    S32(0x244) = (*(u32*)(this_ + 0x90) >> 7) & 0x1F;
    S32(0x248) = (*(u32*)(this_ + 0x90) >> 12) & 0x1F;
    S32(0x24C) = (*(u32*)(this_ + 0x90) >> 17) & 0x1F;
    S32(0x250) = (*(u32*)(this_ + 0x90) >> 22) & 0x1F;
    for (int i = 0; i < 4; i++) {
        if (FLAGS[i] != 0) {
            ok = FALSE;
            break;
        }
    }
    if ((u8)ok) {
        S32(0x230) = 2;
        detach__5ActorFv(this_);
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
