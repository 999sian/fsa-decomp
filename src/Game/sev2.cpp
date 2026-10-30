// TU 0x802e43e0-0x802e4c74 — Actor 'SEV2' (Scripted Stage Environment / Weather Controller).
#include "Game/esd/types.h"

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
#ifndef unknown
#define unknown jsys_unknown
#endif
#include "JSystem/JGeometry/Vec.h"

class WaveController {
public:
    WaveController(s32 a, s32 b, s32 c);
    ~WaveController();
private:
    unsigned char pad[0x5c];
};

struct Sev2Actor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ JGeometry::TVec3<f32> mPos;
    /* 0x018 */ u8 _pad18[0x90 - 0x18];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[0x230 - 0x94];
    /* 0x230 */ WaveController* mWaveCtrl;
    /* 0x234 */ s32 mPushSlotA;
    /* 0x238 */ s32 mPushSlotB;
    /* 0x23C */ s32 mPushSlotC;
    /* 0x240 */ s32 mRampEnable0;
    /* 0x244 */ s32 mRampLimit0;
    /* 0x248 */ s32 mSetFlag1D1;
    /* 0x24C */ s32 mSetFlag1D2;
    /* 0x250 */ s32 mSetFlag1D3;
    /* 0x254 */ s32 mRampEnable1;
    /* 0x258 */ s32 mRampLimit1;
    /* 0x25C */ s32 mInitTimer1D8;
    /* 0x260 */ s32 mSetFlag1DC;
    /* 0x264 */ s32 mSetFlag1CA;
    /* 0x268 */ s32 mRampEnable2;
    /* 0x26C */ s32 mRampLimit2;
    /* 0x270 */ s32 mRampEnable3;
    /* 0x274 */ s32 mRampLimit3;
    /* 0x278 */ s32 mSetFlag1CF;
    /* 0x27C */ s32 mSetFlag1DD;
    /* 0x280 */ s32 mHoldLevel4;
    /* 0x284 */ u8 mLevel0;
    /* 0x285 */ u8 mLevel1;
    /* 0x286 */ u8 mLevel2;
    /* 0x287 */ u8 mLevel3;
    /* 0x288 */ u8 mLevel4;
};

extern "C" {
void Sev2_ClearField_0x280(Sev2Actor* thisPtr) { thisPtr->mHoldLevel4 = 0; }
void Sev2_EmptyHook(void) {}
}

struct Sev2Msg { u32 id; };
struct Sev2WaveBase { u8 pad[8]; };
struct Sev2Wave : Sev2WaveBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void send(Sev2Msg*);
};
extern const f32 lbl_80541200;
extern const f32 lbl_80541204;
extern char* lbl_8053AAF8;
extern "C" char* fn_801902C0();
extern "C" u8* fn_8016A3AC();

// SEV2 update (vtable slot 3)
extern "C" void fn_802E43F0(Sev2Actor* p) {
    JGeometry::TVec3<f32> pos(p->mPos);
    if (p->mSpawnParam & 8) {
        pos.x += lbl_80541200;
    }
    if (p->mSpawnParam & 4) {
        pos.x -= lbl_80541200;
    }
    if (p->mSpawnParam & 2) {
        pos.y += lbl_80541204;
    }
    if (p->mSpawnParam & 1) {
        pos.y -= lbl_80541204;
    }
    if (p->mPushSlotA != 0) {
        char* m = fn_801902C0();
        if (*(void**)(m + 0x2b4) != 0 && *(u8*)(m + 0x2c0) == 0) {
            *(u8*)(m + 0x2c0) = 1;
            *(f32*)(m + 0x2a8) = pos.x;
            *(f32*)(m + 0x2ac) = pos.y;
            *(f32*)(m + 0x2b0) = pos.z;
        }
    }
    if (p->mPushSlotB != 0) {
        char* m = fn_801902C0();
        if (*(void**)(m + 0x2d0) != 0 && *(u8*)(m + 0x2dc) == 0) {
            *(u8*)(m + 0x2dc) = 1;
            *(f32*)(m + 0x2c4) = pos.x;
            *(f32*)(m + 0x2c8) = pos.y;
            *(f32*)(m + 0x2cc) = pos.z;
        }
    }
    if (p->mPushSlotC != 0) {
        char* m = fn_801902C0();
        s32 n = *(s32*)(m + 0x618);
        if (n < 2) {
            f32* d = (f32*)(m + 0x5f0 + n * 0x14);
            d[0] = pos.x;
            d[1] = pos.y;
            d[2] = pos.z;
            *(s32*)(m + 0x618) = *(s32*)(m + 0x618) + 1;
        }
    }
    if (p->mRampEnable0 == 0) {
        if (p->mLevel0 != 0) {
            p->mLevel0 = p->mLevel0 - 1;
        }
    } else if (p->mLevel0 < p->mRampLimit0) {
        p->mLevel0 = p->mLevel0 + 1;
    }
    fn_8016A3AC()[0x1f2] = p->mLevel0;
    if (p->mSetFlag1D1 != 0) {
        { u8* e = fn_8016A3AC(); e[0x1d1] = 1; }
    }
    if (p->mSetFlag1D2 != 0) {
        if (*(s32*)(lbl_8053AAF8 + 0x4c) != 0xb) {
            Sev2Msg msg;
            msg.id = 0x50078;
            ((Sev2Wave*)p->mWaveCtrl)->send(&msg);
        }
        { u8* e = fn_8016A3AC(); e[0x1d2] = 1; }
    }
    if (p->mSetFlag1D3 != 0) {
        { u8* e = fn_8016A3AC(); e[0x1d3] = 1; }
    }
    if (p->mRampEnable1 == 0) {
        if (p->mLevel1 != 0) {
            p->mLevel1 = p->mLevel1 - 1;
        }
    } else if (p->mLevel1 < p->mRampLimit1) {
        p->mLevel1 = p->mLevel1 + 1;
    }
    fn_8016A3AC()[0x1f3] = p->mLevel1;
    if (p->mInitTimer1D8 != 0) {
        u8* e = fn_8016A3AC();
        if (*(s32*)(e + 0x1d8) < 0) {
            *(s32*)(e + 0x1d8) = 0x100;
        }
    }
    if (p->mSetFlag1DC != 0) {
        { u8* e = fn_8016A3AC(); e[0x1dc] = 1; }
    }
    if (p->mSetFlag1CA != 0) {
        { u8* e = fn_8016A3AC(); e[0x1ca] = 1; }
    }
    if (p->mRampEnable2 == 0) {
        p->mLevel2 = 0;
    } else if (p->mLevel2 < p->mRampLimit2) {
        p->mLevel2 = p->mLevel2 + 1;
    }
    fn_8016A3AC()[0x1f4] = p->mLevel2;
    if (p->mRampEnable3 == 0) {
        if (p->mLevel3 != 0) {
            p->mLevel3 = p->mLevel3 - 1;
        }
    } else if (p->mLevel3 < p->mRampLimit3) {
        p->mLevel3 = p->mLevel3 + 1;
    }
    fn_8016A3AC()[0x1f5] = p->mLevel3;
    if (p->mSetFlag1CF != 0) {
        u8* e = fn_8016A3AC();
        e[0x1cf] = 1;
        e[0x1d0] = 0;
    }
    if (p->mSetFlag1DD != 0) {
        { u8* e = fn_8016A3AC(); e[0x1dd] = 1; }
    }
    if (p->mHoldLevel4 == 0) {
        if (p->mLevel4 != 0) {
            p->mLevel4 = p->mLevel4 - 1;
        }
    }
    fn_8016A3AC()[0x1ef] = p->mLevel4;
}

extern "C" void __dt__5ActorFv(void* this_, int how);
extern void* lbl_804A9CD0[];

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

extern "C" void* Sev2_dtor(Sev2Actor* this_, short how) {
    if (this_) {
        this_->mVtable = lbl_804A9CD0;
        void* sub = this_->mWaveCtrl;
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

// SEV2 init (vtable slot 1)
extern "C" void Sev2_Part4of5(Sev2Actor* p) {
    p->mPushSlotA = (p->mSpawnParam >> 26) & 1;
    p->mPushSlotB = (p->mSpawnParam >> 25) & 1;
    p->mPushSlotC = (p->mSpawnParam >> 24) & 1;
    p->mRampEnable0 = (p->mSpawnParam >> 23) & 1;
    p->mSetFlag1D1 = (p->mSpawnParam >> 22) & 1;
    p->mSetFlag1D2 = (p->mSpawnParam >> 21) & 1;
    p->mSetFlag1D3 = (p->mSpawnParam >> 20) & 1;
    p->mRampEnable1 = (p->mSpawnParam >> 19) & 1;
    p->mInitTimer1D8 = (p->mSpawnParam >> 18) & 1;
    p->mSetFlag1DC = (p->mSpawnParam >> 17) & 1;
    p->mSetFlag1CA = (p->mSpawnParam >> 16) & 1;
    p->mRampEnable2 = (p->mSpawnParam >> 15) & 1;
    p->mRampEnable3 = (p->mSpawnParam >> 14) & 1;
    p->mSetFlag1CF = (p->mSpawnParam >> 13) & 1;
    p->mSetFlag1DD = (p->mSpawnParam >> 12) & 1;
    p->mHoldLevel4 = (p->mSpawnParam >> 11) & 1;

    p->mLevel0 = *(u8*)((char*)fn_8016A3AC() + 0x1f2);
    if (p->mRampEnable0 != 0) {
        p->mRampLimit0 = 0xff;
    }
    *(u8*)((char*)fn_8016A3AC() + 0x1f2) = p->mLevel0;

    p->mLevel1 = *(u8*)((char*)fn_8016A3AC() + 0x1f3);
    if (p->mRampEnable1 != 0) {
        p->mRampLimit1 = 0xff;
    }
    *(u8*)((char*)fn_8016A3AC() + 0x1f3) = p->mLevel1;

    p->mLevel2 = *(u8*)((char*)fn_8016A3AC() + 0x1f4);
    if (p->mRampEnable2 != 0) {
        p->mRampLimit2 = 0xff;
    }
    *(u8*)((char*)fn_8016A3AC() + 0x1f4) = p->mLevel2;

    p->mLevel3 = *(u8*)((char*)fn_8016A3AC() + 0x1f5);
    if (p->mRampEnable3 != 0) {
        p->mRampLimit3 = 0xff;
    }
    *(u8*)((char*)fn_8016A3AC() + 0x1f5) = p->mLevel3;

    p->mLevel4 = *(u8*)((char*)fn_8016A3AC() + 0x1ef);
    if (p->mHoldLevel4 != 0) {
        p->mLevel4 = 0xff;
    }
    *(u8*)((char*)fn_8016A3AC() + 0x1ef) = p->mLevel4;

    p->mWaveCtrl = new WaveController(0, 0, 8);

    struct ActorSlot5 {
        virtual void v0(); virtual void v1(); virtual void v2();
        virtual void update();
    };
    ((ActorSlot5*)p)->update();
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
