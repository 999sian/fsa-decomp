#include "JSystem/JAudio/Interface/JAISoundParams.h"
#include "JSystem/JAudio/Interface/JAISound.h"
#include "JSystem/JAudio/Interface/JAISoundHandles.h"
#include "JSystem/JAudio/System/JASDriver.h"
#include "JSystem/JAudio/System/JASAudioReseter.h"
#include "JSystem/JAudio/System/JASHeapCtrl.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "JSystem/JAudio/Interface/JAIAudience.h"
#include "JSystem/JAudio/JAUSectionHeap.h"
#include "JSystem/JAudio/JAUSoundMgr.h"
#include "JSystem/JAudio/System/JASAudioReseter.h"

extern "C" void* lbl_804B2074[];
extern "C" void* lbl_804954D8[];
extern "C" void* lbl_804954F8[];
extern "C" void* lbl_80495480[];
extern "C" void* lbl_80495450[];
extern "C" void __dt__11JAIAudienceFv(void*, short);

struct Unk804580DCTrack {
    virtual void v0();
    virtual void v1();
    virtual Unk804580DCTrack* v2(u32 p);
    virtual void v3();
    virtual Unk804580DCTrack* v4(u32 p);
    char pad4[0x4C - 0x4];
    s32 m4C;
};

struct Unk80458408Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Unk80458408Obj* v4();
    virtual void v5();
    virtual Unk80458408Obj* v6();
    virtual JASTrack* v7(s32 idx);
            virtual u32 v8();
        virtual JASTrack* v9(s32 idx);
};

struct Unk804580DCBank {
    char padEC[0xEC];
    Unk804580DCTrack** mEC;
    u32 mF0;
};

struct Unk80458F9C {
    char pad0[0x58];
    u32 m58;
    u32 m5C;
    u32 m60;
    s32 m64;
    u8 m68;
    char pad69[0x80 - 0x69];
    JAISound* m80;
};

struct Unk80458F04Sound {
    char pad[0x18];
    u32 mID;
    char pad1C[0x48 - 0x1C];
    JAISoundParamsMove mMove;
};

struct Unk80458F04Starter {
    virtual void v0();
    virtual bool startSound(u32* id, Unk80458F04Sound** handle, void* pos);
};

struct Unk80458F04 {
    char pad0[4];
    u8 m4;
    u8 m5;
    char pad6[0x30 - 6];
    Unk80458F04Starter* m30;
    char pad34[0x50 - 0x34];
    f32 m50;
    char pad54[0x80 - 0x54];
    Unk80458F04Sound* m80;
    Unk80458F04Sound* m84;
    char pad88[0x8B - 0x88];
    u8 m8B;
};

extern "C" const f32 lbl_80543EB0;
extern "C" const f32 lbl_80543EB4;
extern "C" const f64 lbl_80543EB8;
extern "C" s32 lbl_8053A26C;
extern "C" f32 lbl_8053A268;
extern "C" void fn_80458744(void*, s32);
extern "C" f32 lbl_804B1E60[];
extern "C" f32 lbl_804B1E84[];
extern "C" f32 lbl_804B1EA8[];
extern "C" f32 lbl_804B1ECC[];
extern "C" u32 lbl_8053A258;
extern "C" f32 lbl_8053A260;
extern "C" u32 lbl_8053A264;

struct Unk80457E54Obj {
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
    virtual f32* v10();
};

struct Unk80457E54Vt {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual f32* v8();
};
extern "C" void fn_80457DFC(u8* this_, u8 v) {
    this_[0x6] = v;
}

extern "C" void fn_80457E04(u8* this_, u8 flag) {
    if (this_[0x8c] == 0 && this_[0x8b] == 0) {
        if (flag) {
            fn_80458744(this_, 3);
        } else {
            fn_80458744(this_, 0);
        }
    }
}

extern "C" const f64 lbl_80543EB8;
extern "C" s32 lbl_8053A26C;
extern "C" f32 lbl_8053A268;
extern "C" void fn_80457E54(u8* this_, u8 flag) {
    this_[0x8c] = flag;
    if (flag) {
        fn_80458744(this_, 2);
        void* obj = *(void**)(this_ + 0x80);
        if (obj != NULL) {
            f32* p = ((Unk80457E54Vt*)obj)->v8();
            if (p != NULL) {
                u32 n = lbl_8053A26C;
                f32 v = lbl_8053A268;
                if (n == 0) {
                    p[0] = v;
                    p[1] = lbl_80543EB0;
                    *(u32*)(p + 3) = 0;
                    p[2] = lbl_80543EB0;
                } else {
                    f32 d = lbl_8053A268 - p[0];
                    *(u32*)(p + 3) = n;
                    f32 e = (f32)*(u32*)(p + 3);
                    p[1] = d / e;
                    p[2] = v;
                }
            }
        }
    } else {
        fn_80458744(this_, 0);
        void* obj = *(void**)(this_ + 0x80);
        if (obj != NULL) {
            f32* p = ((Unk80457E54Vt*)obj)->v8();
            if (p != NULL) {
                p[0] = lbl_80543EB4;
                p[1] = lbl_80543EB0;
                *(u32*)(p + 3) = 0;
                p[2] = lbl_80543EB0;
            }
        }
    }
}

extern "C" void fn_80457F60(u8* this_) {
    this_[0x74] = 1;
}

extern "C" void fn_80457F6C(u8* this_) {
    this_[0x74] = 0;
    this_[0x6d] = 0xb4;
}

extern "C" s32 fn_80457F80(u8* this_, u32* param_2, s8 param_3) {
    if (param_3 == -2) {
        JAISoundID soundID = *param_2;
        if (((JAISoundHandles*)*(void**)(this_ + 0x14))->getHandleSoundID(soundID) != NULL) {
            return 0;
        }
        for (s32 i = 0; i < 4; i++) {
            JAISoundID loopID = *param_2;
            if (((JAISoundHandles*)*(void**)(this_ + 0x18 + i * 4))->getHandleSoundID(loopID) != NULL) {
                return 0;
            }
        }
    } else if (param_3 == -1) {
        JAISoundID soundID = *param_2;
        if (((JAISoundHandles*)*(void**)(this_ + 0x14))->getHandleSoundID(soundID) != NULL) {
            return 0;
        }
    } else {
        for (s32 i = 0; i < 4; i++) {
            JAISoundID loopID = *param_2;
            if (((JAISoundHandles*)*(void**)(this_ + 0x18 + i * 4))->getHandleSoundID(loopID) != NULL) {
                return 0;
            }
        }
    }
    return 1;
}

extern "C" void fn_80458090(char* this_) {
    ((JAUSection*)*(void**)(this_ + 0x44))->loadWaveArc(2);
    ((JAUSection*)*(void**)(this_ + 0x44))->loadWaveArc(3);
    ((JAUSection*)*(void**)(this_ + 0x44))->loadWaveArc(4);
}

extern "C" u32 fn_804580DC(char* this_, u8 idx) {
    Unk804580DCBank* bank = *(Unk804580DCBank**)(this_ + 0x44);
    if (bank != NULL) {
        Unk804580DCTrack* track = NULL;
        if (idx < bank->mF0) {
            track = bank->mEC[idx];
        }
        if (track != NULL && track->v2(0)->m4C == 2) {
            return 1;
        }
    }
    return 0;
}

extern "C" void fn_80458408(u8* this_, s32 param_2, u8 param_3) {
    Unk80458408Obj* obj = *(Unk80458408Obj**)(this_ + 0x80);
    if (obj != NULL && param_2 == 0x100001a) {
        Unk80458408Obj* bank = obj->v4();
        if (bank != NULL) {
            BOOL enabled = OSDisableInterrupts();
            for (s32 i = 0; i < 0x10; i++) {
                JASTrack* track = bank->v7(i);
                if (track != NULL) {
                    if (param_3 != 0) {
                        if (i == 2) {
                            track->mute(TRUE);
                        } else {
                            track->mute(FALSE);
                        }
                    } else {
                        if (i == 2 || i == 7) {
                            track->mute(FALSE);
                        } else {
                            track->mute(TRUE);
                        }
                    }
                }
            }
            OSRestoreInterrupts(enabled);
        }
    }
}

extern "C" void fn_80458508(u8* this_, u8 mode) {
    Unk80457E54Obj* obj = *(Unk80457E54Obj**)(this_ + 0x80);
    if (obj != NULL) {
        f32* p = obj->v10();
        if (p != NULL) {
            switch (mode) {
            case 1: {
                u32 n = lbl_8053A264;
                f32 v = lbl_8053A260;
                if (n == 0) {
                    p[0] = v;
                    p[1] = lbl_80543EB0;
                    *(u32*)(p + 3) = 0;
                    p[2] = lbl_80543EB0;
                } else {
                    f32 d = v - p[0];
                    union {
                        f64 f;
                        u32 w[2];
                    } conv;
                    conv.w[0] = 0x43300000;
                    *(u32*)(p + 3) = n;
                    conv.w[1] = *(u32*)(p + 3);
                    p[1] = d / (f32)(conv.f - lbl_80543EB8);
                    p[2] = v;
                }
                break;
            }
            case 2: {
                u32 n = lbl_8053A26C;
                f32 v = lbl_8053A268;
                if (n == 0) {
                    p[0] = v;
                    p[1] = lbl_80543EB0;
                    *(u32*)(p + 3) = 0;
                    p[2] = lbl_80543EB0;
                } else {
                    f32 d = v - p[0];
                    union {
                        f64 f;
                        u32 w[2];
                    } conv;
                    conv.w[0] = 0x43300000;
                    *(u32*)(p + 3) = n;
                    conv.w[1] = *(u32*)(p + 3);
                    p[1] = d / (f32)(conv.f - lbl_80543EB8);
                    p[2] = v;
                }
                break;
            }
            case 0:
            default:
                p[0] = lbl_80543EB4;
                p[1] = lbl_80543EB0;
                *(u32*)(p + 3) = 0;
                p[2] = lbl_80543EB0;
                break;
            }
        }
    }
}

extern "C" void fn_80458658(u8* this_, bool flag) {
    this_[0x8a] = flag;
    ((JAISeMgr*)*(void**)(this_ + 0x34))->getCategory(3)->pause(flag);
    ((JAISeMgr*)*(void**)(this_ + 0x34))->getCategory(4)->pause(flag);
    ((JAISeMgr*)*(void**)(this_ + 0x34))->getCategory(5)->pause(flag);
    ((JAISeMgr*)*(void**)(this_ + 0x34))->getCategory(6)->pause(flag);
    f32 volume = lbl_80543EB4;
    if (flag) {
        volume = lbl_80543EB0;
    }
    ((JAISeMgr*)*(void**)(this_ + 0x34))->getCategory(3)->getParams()->moveVolume(volume, 3);
    ((JAISeMgr*)*(void**)(this_ + 0x34))->getCategory(4)->getParams()->moveVolume(volume, 3);
    ((JAISeMgr*)*(void**)(this_ + 0x34))->getCategory(5)->getParams()->moveVolume(volume, 3);
    ((JAISeMgr*)*(void**)(this_ + 0x34))->getCategory(6)->getParams()->moveVolume(volume, 3);
}

extern "C" void fn_8045873C(u8* this_, u8 v) {
    this_[0x69] = v;
}

#pragma dont_inline on
extern "C" void fn_80458744(void* this_, s32 mode) {
    f32 a;
    f32 b;
    f32 c;
    char* self = (char*)this_;

    switch (mode) {
    case 0:
        a = lbl_804B1E60[0];
        b = lbl_804B1E60[1];
        c = lbl_804B1E60[2];
        break;
    case 1:
        a = lbl_804B1E84[0];
        b = lbl_804B1E84[1];
        c = lbl_804B1E84[2];
        break;
    case 2:
        a = lbl_804B1EA8[0];
        b = lbl_804B1EA8[1];
        c = lbl_804B1EA8[2];
        break;
    case 3:
        switch (*(s32*)(self + 0x58)) {
        case 0x1000000:
        case 0x1000003:
        case 0x1000008:
        case 0x1000009:
        case 0x100000A:
        case 0x100000B:
        case 0x100000E:
        case 0x1000010:
        case 0x1000011:
        case 0x1000012:
        case 0x1000013:
        case 0x1000014:
        case 0x1000015:
        case 0x1000016:
            a = lbl_804B1ECC[0];
            b = lbl_804B1ECC[1];
            c = lbl_804B1ECC[2];
            break;
        default:
            return;
        }
        break;
    default:
        return;
    }
    *(f32*)(self + 0x4c) = a;
    *(f32*)(self + 0x50) = b;
    if (*(char**)(self + 0x80) != NULL) {
        ((JAISoundParamsMove*)(*(char**)(self + 0x80) + 0x48))->moveVolume(*(f32*)(self + 0x4c) * *(f32*)(self + 0x54), lbl_8053A258);
    }
    if (*(char**)(self + 0x84) != NULL) {
        ((JAISoundParamsMove*)(*(char**)(self + 0x84) + 0x48))->moveVolume(*(f32*)(self + 0x50), lbl_8053A258);
    }
    ((JAISoundParamsMove*)(*(char**)(self + 0x34) + 0x1c))->moveVolume(c, 0);
}
#pragma dont_inline reset

extern "C" void fn_80458F04(Unk80458F04* self, u32 id)
{
    if (self->m4 != 0) {
        return;
    }
    if (self->m5 == 1 && self->m84 != 0 && id == self->m84->mID) {
        return;
    }
    u32 soundID = id;
    self->m30->startSound(&soundID, &self->m84, 0);
    if (self->m84 != 0) {
        self->m84->mMove.moveVolume(self->m50, 0);
    }
}

extern "C" void fn_80458F9C(Unk80458F9C* self, u32 fadeout)
{
    if (self->m80 != 0) {
        self->m80->stop(fadeout);
    }
    self->m68 = 0;
    self->m64 = -1;
    self->m58 = 0;
    self->m5C = 0;
    self->m60 = 0;
}

extern "C" void fn_8045815C(void* this_, s32 mode);
extern "C" u32 lbl_8053A25C;
extern "C" void writePort__8JASTrackFUlUs(void* a, u32 b, u16 c);
extern "C" void fn_80458FF0(u8* this_, s32 id, u8 param_3, u8 param_4) {
    if (this_[0x4] != 0) {
        return;
    }
    if (id == -1) {
        return;
    }
    switch (id) {
    case 0x100000c:
    case 0x100001c:
        *(s32*)(this_ + 0x70) = 0;
        break;
    case 0x1000019:
        param_3 = 1;
        break;
    case 0x1000028:
        this_[0x89] = 1;
        param_3 = 1;
        break;
    }
    if (this_[0x68] == 1 && param_3 == 0 && *(void**)(this_ + 0x80) != NULL) {
        if (id == *(s32*)(this_ + 0x58) && *(s32*)(this_ + 0x64) == -1) {
            return;
        }
        if (id == *(s32*)(this_ + 0x5c)) {
            return;
        }
        if (*(void**)(this_ + 0x80) != NULL) {
            ((JAISound*)*(void**)(this_ + 0x80))->stop(lbl_8053A25C);
            *(s32*)(this_ + 0x64) = 0;
        }
        *(s32*)(this_ + 0x5c) = id;
        *(s32*)(this_ + 0x60) = id;
        this_[0x8d] = param_4;
    } else {
        u32 soundID = id;
        ((Unk80458F04Starter*)*(void**)(this_ + 0x30))->startSound(&soundID, (Unk80458F04Sound**)(this_ + 0x80), 0);
        fn_8045815C(this_, this_[0x8b]);
        switch (*(s32*)(this_ + 0x5c)) {
        case 0x100001a:
            if (*(void**)(this_ + 0x80) != NULL) {
                Unk80458408Obj* bank = ((Unk80458408Obj*)*(void**)(this_ + 0x80))->v6();
                if (bank != NULL) {
                    BOOL enabled = OSDisableInterrupts();
                    for (s32 i = 0; i < 0x10; i++) {
                        JASTrack* track = bank->v9(i);
                        if (track != NULL) {
                            if (i == 2 || i == 7) {
                                track->mute(FALSE);
                            } else {
                                track->mute(TRUE);
                            }
                        }
                    }
                    OSRestoreInterrupts(enabled);
                }
            }
            break;
        }
        *(f32*)(this_ + 0x4c) = lbl_80543EB4;
        if (*(void**)(this_ + 0x80) != NULL) {
            ((JAISoundParamsMove*)(*(char**)(this_ + 0x80) + 0x48))->moveVolume(*(f32*)(this_ + 0x4c) * *(f32*)(this_ + 0x54), 0);
            if (param_4 != 0) {
                u32 port = ((Unk80458408Obj*)*(void**)(this_ + 0x80))->v8();
                writePort__8JASTrackFUlUs((void*)port, 0, 1);
            }
        }
        *(s32*)(this_ + 0x58) = id;
        *(s32*)(this_ + 0x60) = id;
        *(s32*)(this_ + 0x5c) = 0;
        *(s32*)(this_ + 0x64) = -1;
    }
    this_[0x68] = 1;
}

extern "C" void fn_80459274(u8* this_) {
    this_[0x8e] = 0;
    if (this_[0x8c]) {
        fn_80458744(this_, 2);
    } else {
        fn_80458744(this_, 0);
    }
    ((JAISeCategoryMgr*)(*(u8**)(this_ + 0x34) + 0x80))->pause(false);
    ((JAISeCategoryMgr*)(*(u8**)(this_ + 0x34) + 0xec))->pause(false);
    if (this_[0x8a] == 1) {
        ((JAISoundParamsMove*)(*(u8**)(this_ + 0x34) + 0x88))->moveVolume(lbl_80543EB4, 3);
        ((JAISoundParamsMove*)(*(u8**)(this_ + 0x34) + 0xf4))->moveVolume(lbl_80543EB4, 3);
    } else {
        ((JAISeCategoryMgr*)(*(u8**)(this_ + 0x34) + 0x158))->pause(false);
        ((JAISeCategoryMgr*)(*(u8**)(this_ + 0x34) + 0x1c4))->pause(false);
        ((JAISeCategoryMgr*)(*(u8**)(this_ + 0x34) + 0x230))->pause(false);
        ((JAISeCategoryMgr*)(*(u8**)(this_ + 0x34) + 0x29c))->pause(false);
        ((JAISoundParamsMove*)(*(u8**)(this_ + 0x34) + 0x88))->moveVolume(lbl_80543EB4, 3);
        ((JAISoundParamsMove*)(*(u8**)(this_ + 0x34) + 0xf4))->moveVolume(lbl_80543EB4, 3);
        ((JAISoundParamsMove*)(*(u8**)(this_ + 0x34) + 0x160))->moveVolume(lbl_80543EB4, 3);
        ((JAISoundParamsMove*)(*(u8**)(this_ + 0x34) + 0x1cc))->moveVolume(lbl_80543EB4, 3);
        ((JAISoundParamsMove*)(*(u8**)(this_ + 0x34) + 0x238))->moveVolume(lbl_80543EB4, 3);
        ((JAISoundParamsMove*)(*(u8**)(this_ + 0x34) + 0x2a4))->moveVolume(lbl_80543EB4, 3);
    }
}

extern "C" void fn_804593D4(char* this_) {
    this_[0x8e] = 1;
    fn_80458744(this_, 1);
    ((JAISeCategoryMgr*)(*(char**)(this_ + 0x34) + 0x80))->pause(true);
    ((JAISeCategoryMgr*)(*(char**)(this_ + 0x34) + 0xec))->pause(true);
    ((JAISeCategoryMgr*)(*(char**)(this_ + 0x34) + 0x158))->pause(true);
    ((JAISeCategoryMgr*)(*(char**)(this_ + 0x34) + 0x1c4))->pause(true);
    ((JAISeCategoryMgr*)(*(char**)(this_ + 0x34) + 0x230))->pause(true);
    ((JAISeCategoryMgr*)(*(char**)(this_ + 0x34) + 0x29c))->pause(true);
    ((JAISoundParamsMove*)(*(char**)(this_ + 0x34) + 0x88))->moveVolume(lbl_80543EB0, 3);
    ((JAISoundParamsMove*)(*(char**)(this_ + 0x34) + 0xf4))->moveVolume(lbl_80543EB0, 3);
    ((JAISoundParamsMove*)(*(char**)(this_ + 0x34) + 0x160))->moveVolume(lbl_80543EB0, 3);
    ((JAISoundParamsMove*)(*(char**)(this_ + 0x34) + 0x1cc))->moveVolume(lbl_80543EB0, 3);
    ((JAISoundParamsMove*)(*(char**)(this_ + 0x34) + 0x238))->moveVolume(lbl_80543EB0, 3);
    ((JAISoundParamsMove*)(*(char**)(this_ + 0x34) + 0x2a4))->moveVolume(lbl_80543EB0, 3);
}

extern "C" const f32 lbl_80543EB0;
extern "C" const f32 lbl_80543EB4;
extern "C" void* lbl_8053AF80;
extern "C" char* lbl_8053AAF8;
extern "C" void fn_804594E4(void* self, u32 mode)
{
    JASDriver::setOutputMode(mode);
}

extern "C" void fn_80459508(char* this_) {
    ((JAUSoundMgr*)*(void**)(this_ + 0x30))->stop();
    *(f32*)(this_ + 0x4c) = lbl_80543EB4;
    *(f32*)(this_ + 0x50) = lbl_80543EB4;
    *(f32*)(this_ + 0x54) = lbl_80543EB4;
    *(u32*)(this_ + 0x58) = 0;
    *(u32*)(this_ + 0x5c) = 0;
    *(u32*)(this_ + 0x60) = 0;
    *(s32*)(this_ + 0x64) = -1;
    *(u8*)(this_ + 0x68) = 0;
    *(u8*)(this_ + 0x89) = 0;
    *(u8*)(this_ + 0x69) = 0;
    *(u8*)(this_ + 0x7c) = 0;
    *(u8*)(this_ + 0x6a) = 0;
    *(u8*)(this_ + 0x88) = 0;
    *(u8*)(this_ + 0x8a) = 0;
    *(u8*)(this_ + 0x8b) = 0;
    *(u8*)(this_ + 0x8c) = 0;
    *(u8*)(this_ + 0x8d) = 0;
    *(u8*)(this_ + 0x8e) = 0;
    *(u8*)(this_ + 0x75) = 0;
    *(u32*)(this_ + 0x78) = 0;
    ((JASAudioReseter*)*(void**)(this_ + 0x2c))->resume();
}

extern "C" s32 fn_8045959C(u8* this_) {
    if (this_[0x7c] == 0) {
        return 0;
    }
    return (((JASAudioReseter*)*(u32*)(this_ + 0x2c))->checkDone() != 0) + 1;
}

extern "C" void fn_804595E4(u8* this_, bool b) {
    ((JASAudioReseter*)*(u32*)(this_ + 0x2c))->start(5, b);
    this_[0x7c] = 1;
}

extern "C" void fn_80459624(char* self, f32* pos, Mtx mtx, int idx)
{
    *(f32*)(self + 0x8) = pos[0];
    *(f32*)(self + 0xc) = pos[2];
    *(f32*)(self + 0x10) = pos[1];
    PSMTXCopy(mtx, (f32(*)[4])(*(char**)(self + 0x3c) + idx * 0x30 + 0x54));
}

extern "C" void fn_8045A080(char* self)
{
    *(u32*)(self + 0x80) = 0;
    *(u32*)(self + 0x84) = 0;
    lbl_8053AF80 = self;
    *(u32*)(self + 0x30) = 0;
    *(u32*)(self + 0x34) = 0;
    *(u32*)(self + 0x38) = 0;
    *(u32*)(self + 0x0) = 0;
    *(u8*)(self + 0x6b) = 0;
    *(u32*)(self + 0x70) = 0;
    *(u8*)(self + 0x6c) = 0;
    *(u8*)(self + 0x6d) = 0;
    *(u8*)(self + 0x74) = 0;
    *(u8*)(self + 0x4) = 0;
    *(u8*)(self + 0x5) = 1;
    *(u8*)(self + 0x6) = 0;
    *(f32*)(self + 0x8) = lbl_80543EB0;
    *(f32*)(self + 0xc) = lbl_80543EB0;
    *(f32*)(self + 0x10) = lbl_80543EB0;
}

extern "C" u8 fn_8045A0D8()
{
    return *(u8*)(lbl_8053AAF8 + 0x96);
}

extern "C" void fn_8045A0E4(int count)
{
    JASPoolAllocObject<JASPoolObj3_FSA>::memPool_.JASGenericMemPool::newMemPool(0x40, count);
}

extern "C" char lbl_8052DBE0[];
extern "C" char memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[];
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" char memPool___30JASPoolAllocObject_9JAIStream[];
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" char memPool___35JASPoolAllocObject_13JAISoundChild[];
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" char memPool___27JASPoolAllocObject_6JAISeq[];
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" char memPool___26JASPoolAllocObject_5JAISe[];
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;
extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*);
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*);
extern "C" void __dt__18JASMemPool_5JAISeFv(void*);
extern "C" void __register_global_object(void*, void (*)(void*), void*);
extern "C" void fn_8045A114(void) {
    char* base = lbl_8052DBE0;
    if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, base);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, base + 0xc);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, base + 0x18);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, base + 0x24);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, base + 0x30);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, base + 0x3c);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, base + 0x48);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, base + 0x54);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, base + 0x60);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}

extern "C" void** fn_8045A338(void** p, short del) {
    if (p != 0) {
        *p = lbl_804B2074;
        if (p != 0) {
            *p = lbl_804954D8;
            if (p != 0) {
                *p = lbl_804954F8;
                if (p != 0) {
                    *p = lbl_80495480;
                    if (p != 0) {
                        *p = lbl_80495450;
                        __dt__11JAIAudienceFv(p, 0);
                    }
                }
            }
        }
        if (del > 0) {
            operator delete(p);
        }
    }
    return p;
}

