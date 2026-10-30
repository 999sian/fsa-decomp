// TU 0x802e72a4-0x802e7634 — Actor 'WAVE' (Ambient Wave Sound/Effect Controller).
#include "Game/esd/types.h"

extern "C" {
void Wave_EmptyHook(void) {}
}

struct WaveMsg { u32 id; };
struct WaveTargetBase { u8 pad[8]; };
struct WaveTarget : WaveTargetBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void send(WaveMsg*);
};

class WaveController {
public:
    WaveController(s32 a, s32 b, s32 c);
    ~WaveController();
private:
    unsigned char pad[0x5c];
};

struct WaveActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u8 _pad04[0x230 - 0x04];
    /* 0x230 */ WaveController* mController;
    /* 0x234 */ s32 mPulseTimer; // Initialized to 60 (0x3C)
};

// WAVE update (vtable slot 3)
extern "C" void fn_802E72A8(WaveActor* this_) {
    WaveMsg m1;
    m1.id = 0x3003c;
    WaveTarget* t = (WaveTarget*)this_->mController;
    t->send(&m1);
    if (this_->mPulseTimer == 0) {
        WaveMsg m2;
        this_->mPulseTimer = 60;
        m2.id = 0x3003d;
        t = (WaveTarget*)this_->mController;
        t->send(&m2);
    }
}

extern "C" void __dt__5ActorFv(void* this_, int how);
extern void* lbl_804A9EA8[];

struct NonPolyBase {
    void* pad0;
    void* pad1;
};

struct NotifyTarget : NonPolyBase {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9();
    virtual void Notify(int arg);
};

static inline void NotifySub(void* obj, int arg) {
    if (obj) {
        ((NotifyTarget*)obj)->Notify(arg);
    }
}

extern "C" void* fn_802E732C(WaveActor* this_, short how) {
    if (this_) {
        this_->mVtable = lbl_804A9EA8;
        void* sub = this_->mController;
        if (sub) {
            NotifySub(sub, 1);
        }
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

// WAVE init (vtable slot 1)
extern "C" void Wave_SetParams(WaveActor* this_) {
    this_->mPulseTimer = 0x3c;
    this_->mController = new WaveController(0, 0, 8);
}

#undef ALIGN_NEXT
#undef ALIGN_PREV
#undef ARRAY_SIZE
#undef ASM
#undef ATTRIBUTE_ALIGN
#undef IS_ALIGNED
#undef IS_NOT_ALIGNED
#undef MACROS_H
#undef MAX
#undef MIN
#undef NULL
#define NULL 0
#define unknown jsys_unknown
#include "JSystem/JAudio/JASFakeMatchFSA.h"
