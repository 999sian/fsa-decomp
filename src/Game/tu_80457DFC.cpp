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
#include "JSystem/JAudio/JAUAudience.h"
#include "JSystem/JAudio/System/JASWaveArcLoader.h"
#include "JSystem/JAudio/System/JASDsp.h"
#include "JSystem/JAudio/System/JASAudioReseter.h"
#include "JSystem/JAudio/JAUSoundObject.h"

extern "C" void* lbl_804B2074[];
extern "C" void* lbl_804954D8[];
extern "C" void* lbl_804954F8[];
extern "C" void* lbl_80495480[];
extern "C" void* lbl_80495450[];
extern "C" void __dt__11JAIAudienceFv(void*, short);
extern "C" void writePort__8JASTrackFUlUs(void* a, u32 b, u16 c);
extern "C" const f32 lbl_80543EC4;
extern "C" const f32 lbl_80543EC8;
extern "C" const f32 lbl_80543ECC;

static inline JAISoundID currentAudioID(JAISoundHandle* handle) {
    JAISoundID id=-1;
    if (*handle) id=JAISoundID(handle->getSound()->getID());
    return id;
}
struct Unk80459674MessageBase { u32 pad[2]; };
struct Unk80459674Message : Unk80459674MessageBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(const JAISoundID& id);
};
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

static inline void updateAudioTracks(Unk80458408Obj* sound, s32 id) {
    s32 i;
    Unk80458408Obj* bank;
    if (sound) {
        switch (id) { case 0x100001a: break; default: return; }
        bank=sound->v4();
        if (bank) {
            JASThreadingModel::InterruptsDisable<Unk80458408Obj>::Lock lock(*bank);
            for (i=0;i<16;i++) {
                JASTrack* track=bank->v7(i);
                if (track) {
                    if (i==2 || i==7) track->mute(false);
                    else track->mute(true);
                }
            }
        }
    }
}
static inline void updateAudioTracksForStart(Unk80458408Obj* sound, s32 id) {
    Unk80458408Obj* bank;
    s32 i;
    if (sound) {
        switch (id) { case 0x100001a: break; default: return; }
        bank = sound->v4();
        if (bank) {
            JASThreadingModel::InterruptsDisable<Unk80458408Obj>::Lock lock(*bank);
            for (i = 0; i < 16; i++) {
                JASTrack* track = bank->v7(i);
                if (track) {
                    if (i == 2 || i == 7) track->mute(false);
                    else track->mute(true);
                }
            }
        }
    }
}

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

struct Unk8045815COut {
    f32 m0;
    f32 m4;
    f32 m8;
    u32 mC;
};

struct Unk80458F04Sound {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Unk80458408Obj* v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual Unk8045815COut* v10();
    char pad[0x14];
    u32 mID;
    char pad1C[0x48 - 0x1C];
    JAISoundParamsMove mMove;
};

struct Unk8045A3D8Src {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual JASSoundParams* v3(s32 idx);
    char pad4[0x10 - 0x4];
    u8 m10;
    u8 m11;
};

static inline void startAudioSpecial(u8* self, u32 id) {
    if(self[4])return;
    if(self[5]==1 && *(Unk80458F04Sound**)(self+0x84) && id==(*(Unk80458F04Sound**)(self+0x84))->mID)return;
    ((JAISoundStarter*)*(void**)(self+0x30))->startSound(JAISoundID(id),(JAISoundHandle*)(self+0x84),0);
    if(*(Unk80458F04Sound**)(self+0x84))(*(Unk80458F04Sound**)(self+0x84))->mMove.moveVolume(*(f32*)(self+0x50),0);
}
struct AudioChannelBase { u8 pad[0x18]; JAUSoundObject* object; };
struct AudioContext { u8 pad[0x18]; JAUSoundObject* channels[4]; };

static inline JAUSoundObject* getAudioChannel(u8* self, const s32 channel) {
    return ((AudioContext*)self)->channels[channel];
}
static inline f32 getPlayerAudioPan(const u8* self, s32 channel) {
    if(channel>=self[5])return 0.5f;
    f32 pan=0.5f;
    switch(self[5]){
    case 1:default:pan=0.5f;break;
    case 2:case 3:case 4:
        switch(channel){
        case 0:case 2:pan=lbl_80543EC8;break;
        case 1:case 3:pan=lbl_80543ECC;break;
        }
        break;
    }
    return pan;
}

static inline f32 getAudioPan(const u8* self, const s8 mode) {
    if(mode<0)return 0.5f;
    return getPlayerAudioPan(self,mode);
}

static inline void stopAudioGroup(JAUSoundObject* obj) {
    obj->stopSound(JAISoundID(19), 0);
    obj->stopSound(JAISoundID(20), 0);
    obj->stopSound(JAISoundID(21), 0);
    obj->stopSound(JAISoundID(22), 0);
    obj->stopSound(JAISoundID(23), 0);
    obj->stopSound(JAISoundID(24), 0);
    obj->stopSound(JAISoundID(25), 0);
    obj->stopSound(JAISoundID(26), 0);
    obj->stopSound(JAISoundID(27), 0);
    obj->stopSound(JAISoundID(28), 0);
}

struct Unk80458880Mgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(JAISoundID* id, Unk80458F04Sound** handle, void* pos);
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
                f32 d;
                u32 n = lbl_8053A26C;
                f32 v = lbl_8053A268;
                if (n == 0) {
                    p[0] = v;
                    p[1] = lbl_80543EB0;
                    *(u32*)(p + 3) = 0;
                    p[2] = lbl_80543EB0;
                } else {
                    d = v - p[0];
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
        Unk804580DCTrack* track;
        u32 i = idx;
        if (i >= bank->mF0) {
            track = NULL;
        } else {
            track = bank->mEC[i];
        }
        if (track != NULL && track->v2(0)->m4C == 2) {
            return 1;
        }
    }
    return 0;
}

#pragma opt_dead_code off
extern "C" void fn_8045815C(u8* this_, u8 mode) {
    Unk80458F04* self = (Unk80458F04*)this_;
    JAITempoMgr* out;
    JAISound* obj;
    s32 i;

    self->m8B = mode;
    if (self->m80 != NULL || self->m84 != NULL) {
        JAISoundID id(-1);
        if (self->m80 != NULL) {
            id = JAISoundID(((JAISound*)self->m80)->getID());
        }
        if (self->m84 != NULL) {
            id = JAISoundID(((JAISound*)self->m84)->getID());
        }
        if (id != 0x1000002 && id != 0x1000023 && id != 0x100002D) {
            if ((u32)id == 0x1000001) { return; } else {
            if (self->m80 != NULL) {
                id = self->m80->mID;
            }
            switch ((s32)(u32)id) {
            case 0x100000d:
            case 0x1000004:
                return;
            default: {
                if (mode != 0) {
                    if (self->m80 != NULL) {
                        out = ((JAISound*)self->m80)->getTempoMgr();
                        if (out != NULL) {
                            u32 a = lbl_8053A26C;
                            f32 b = lbl_8053A268;
                            if (a == 0) {
                                out->mTempo = b;
                                out->mTransition._0 = lbl_80543EB0;
                                out->mTransition.mCount = 0;
                                out->mTransition._4 = lbl_80543EB0;
                            } else {
                                out->mTransition.set(b, out->mTempo, a);
                            }
                        }
                    }
                } else {
                    if (self->m80 != NULL) {
                        out = ((JAISound*)self->m80)->getTempoMgr();
                        if (out != NULL) {
                            out->mTempo = lbl_80543EB4;
                            out->mTransition._0 = lbl_80543EB0;
                            out->mTransition.mCount = 0;
                            out->mTransition._4 = lbl_80543EB0;
                        }
                    }
                }
                if (mode != 0) {
                    self->m80->mMove.movePitch(lbl_80543EC4, 0);
                } else {
                    self->m80->mMove.movePitch(lbl_80543EB4, 0);
                }
                if (mode != 0) {
                    self->m80->mMove.moveFxMix(lbl_80543EB4, 0);
                } else {
                    self->m80->mMove.moveFxMix(lbl_80543EB0, 0);
                }
                if (self->m84 != NULL) {
                    obj = (JAISound*)((JAISound*)self->m84)->asSeq();
                } else {
                    obj = (JAISound*)((JAISound*)self->m80)->asSeq();
                }
                if (obj != NULL) {
                    JASThreadingModel::InterruptsDisable<JAISound>::Lock lock(*obj);
                    for (i = 0; i < 16; i++) {
                        JASTrack* track = obj->getChildTrack(i);
                        if (track != NULL) {
                            writePort__8JASTrackFUlUs(track, 0, mode);
                        }
                    }
                    self->m8B = mode;
                }
            }
            }
            }
        }
    }
}
#pragma opt_dead_code reset
extern "C" void fn_80458408(u8* this_, s32 param_2, u8 param_3) {
    Unk80458408Obj* obj = *(Unk80458408Obj**)(this_ + 0x80);
    if (obj != NULL) {
        switch (param_2) {
        case 0x100001a:
            {
                Unk80458408Obj* bank = obj->v4();
                if (bank != NULL) {
                    s32 i;
                    volatile BOOL enabled = OSDisableInterrupts();
                    for (i = 0; i < 0x10; i++) {
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
            break;
        }
    }
}

extern "C" void fn_80458508(u8* this_, u8 mode) {
    void* obj = *(void**)(this_ + 0x80);
    if (obj != NULL) {
        f32* p = ((Unk80457E54Vt*)obj)->v8();
        if (p != NULL) {
            switch (mode) {
            case 1: {
                f32 d;
                u32 n = lbl_8053A264;
                f32 v = lbl_8053A260;
                if (n == 0) {
                    p[0] = v;
                    p[1] = lbl_80543EB0;
                    *(u32*)(p + 3) = 0;
                    p[2] = lbl_80543EB0;
                } else {
                    d = v - p[0];
                    *(u32*)(p + 3) = n;
                    f32 e = (f32)*(u32*)(p + 3);
                    p[1] = d / e;
                    p[2] = v;
                }
                break;
            }
            case 2: {
                f32 d;
                u32 n = lbl_8053A26C;
                f32 v = lbl_8053A268;
                if (n == 0) {
                    p[0] = v;
                    p[1] = lbl_80543EB0;
                    *(u32*)(p + 3) = 0;
                    p[2] = lbl_80543EB0;
                } else {
                    d = v - p[0];
                    *(u32*)(p + 3) = n;
                    f32 e = (f32)*(u32*)(p + 3);
                    p[1] = d / e;
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
    *(bool*)(this_ + 0x8a) = flag;
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
#pragma opt_strength_reduction off
extern "C" void fn_80458880(u8* this_, u32 id, s8 mode) {
    u8* self=this_;
    if(mode>=4)return;
    if(id==0x48 && self[0x6a]==0)self[0x6a]=1;
    if(id==12)((JAISeMgr*)*(void**)(self+0x34))->stop(1);
    switch((s32)id) {
    case 0: case 1: case 2: case 3: case 8: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 29: case 31: case 32: case 33: case 34: case 35: case 36: case 37: case 40: case 41: case 42: case 43: case 44: case 46: case 47: case 48: case 49: case 50: case 51: case 52: case 53: case 54: case 55: case 57: case 58: case 59: case 60: case 61: case 62: case 63: case 64: case 65: case 66: case 67: case 68: case 69: case 70: case 71: case 72: case 73: case 74: case 75: case 76: case 77: case 79: case 80: case 82: case 83: case 84: case 85: case 86: case 87: case 88: case 89: case 90: case 91: case 92: case 93: case 94: case 95: case 96: case 97: case 98:
        mode=-1;break;
    }
    switch((s32)id) {
    case 10:
        if(self[0x6c])return;
        self[0x6c]=3;
        break;
    case 3:
        if(self[0x74])return;
        if(self[0x6d])return;
        if(((JAISoundHandles*)*(void**)(self+0x14))->getHandleSoundID(JAISoundID(3)))return;
        ((JAUSoundObject*)*(void**)(self+0x14))->stopSound(JAISoundID(0x42),0);
        ((JAUSoundObject*)*(void**)(self+0x14))->stopSound(JAISoundID(0x41),0);
        break;
    case 0x42:
        if(self[0x74])return;
        if(self[0x6d])return;
        if(((JAISoundHandles*)*(void**)(self+0x14))->getHandleSoundID(JAISoundID(3)))return;
        if(((JAISoundHandles*)*(void**)(self+0x14))->getHandleSoundID(JAISoundID(0x41)))return;
        if(((JAISoundHandles*)*(void**)(self+0x14))->getHandleSoundID(JAISoundID(0x42)))return;
        break;
    case 0x41:
        if(((JAISoundHandles*)*(void**)(self+0x14))->getHandleSoundID(JAISoundID(3)))return;
        if(((JAISoundHandles*)*(void**)(self+0x14))->getHandleSoundID(JAISoundID(0x41)))return;
        ((JAUSoundObject*)*(void**)(self+0x14))->stopSound(JAISoundID(0x42),0);
        break;
    case 0x38:case 0x57:
        startAudioSpecial(self,id);
        return;
    }
    if(mode>=0){
        if(id!=14 && id!=31 && id!=54 && id!=84 && id!=85 && id!=79 && id!=80)
            (*(JAUSoundObject**)(self + (u32)(s32)mode * 4 + 0x18))->stopSound(JAISoundID(id),0);
        u8* channelBase=self+mode*4;
        stopAudioGroup(*(JAUSoundObject**)(channelBase+0x18));
        JAISoundHandle* h=(*(JAUSoundObject**)(channelBase+0x18))->startSound(JAISoundID(id));
        if(h && *h){
            JAISoundParamsMove* move=(JAISoundParamsMove*)((u8*)h->getSound()+0x48);
            move->movePan(mode<0 ? 0.5f : getPlayerAudioPan(self,mode),0);
        }
    }else{
        if(id!=14 && id!=31 && id!=54 && id!=84 && id!=85 && id!=79 && id!=80)
            (*(JAUSoundObject**)(self+0x14))->stopSound(JAISoundID(id),0);
        stopAudioGroup(*(JAUSoundObject**)(self+0x14));
        (*(JAUSoundObject**)(self+0x14))->startSound(JAISoundID(id));
    }
}
#pragma opt_strength_reduction reset

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

extern "C" void fn_8045815C(u8* this_, u8 mode);
extern "C" u32 lbl_8053A25C;
extern "C" void writePort__8JASTrackFUlUs(void* a, u32 b, u16 c);
extern "C" void fn_80458FF0(u8* this_, s32 id, u8 param_3, u8 param_4) {
    if (this_[0x4] != 0) {
        return;
    }
    if ((u32)id == 0xffffffff) {
        return;
    }
    switch (id) {
    case 0x1000028:
        this_[0x89] = 1;
    case 0x1000019:
        param_3 = 1;
        break;
    case 0x100000c:
    case 0x100001c:
        *(s32*)(this_ + 0x70) = 0;
        break;
    }
    if (this_[0x68] == 1 && param_3 == 0 && *(void**)(this_ + 0x80) != NULL) {
        if ((u32)id == *(u32*)(this_ + 0x58) && *(s32*)(this_ + 0x64) == -1) {
            return;
        }
        if ((u32)id == *(u32*)(this_ + 0x5c)) {
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
            updateAudioTracksForStart((Unk80458408Obj*)*(void**)(this_ + 0x80), *(s32*)(this_ + 0x5c));
            break;
        case 0x100000d:
        case 0x100001c:
        case 0x1000021:
        case 0x1000024:
            *(f32*)(this_ + 0x4c) = lbl_80543EB4;
            break;
        }
        if (*(void**)(this_ + 0x80) != NULL) {
            ((JAISoundParamsMove*)(*(char**)(this_ + 0x80) + 0x48))->moveVolume(*(f32*)(this_ + 0x4c) * *(f32*)(this_ + 0x54), 0);
            if (param_4 != 0) {
                u32 port = (u32)((Unk80458408Obj*)*(void**)(this_ + 0x80))->v6();
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

extern "C" u8 fn_8045A0D8();
extern "C" const f32 lbl_80543EC0;
extern "C" u32 lbl_8053A250;
extern "C" u32 lbl_8053A254;
extern "C" void fn_80459674(u8* p) {
    JAISoundID message;
    JAISoundID copy;
    JAUSoundMgr* mgr;
    s32 i;
    Unk80458408Obj* bank;
    if (p[0x6b]) --p[0x6b];
    if (p[0x7c]) {
        if (p[0x7c] && ((JASAudioReseter*)*(void**)(p+0x2c))->checkDone())
            ((JAUSoundMgr*)*(void**)(p+0x30))->stop();
    }
    if (*(void**)(p+0x84)) {
        *(f32*)(p+0x54)=lbl_80543EB0;
        if (*(void**)(p+0x80))
            ((JAISoundParamsMove*)(*(u8**)(p+0x80)+0x48))->moveVolume(*(f32*)(p+0x4c)**(f32*)(p+0x54),lbl_8053A250);
    } else {
        if (p[0x69]==1) *(f32*)(p+0x54)=lbl_80543EB0;
        else if (p[0x8b]==1) {
            JAISoundID id=-1;
            if (*(JAISound**)(p+0x80)) {
                copy.mId.mFullId=(*(JAISound**)(p+0x80))->getID();
                id=copy;
            }
            switch ((s32)(u32)id) {
            case 0x1000001: case 0x1000002: case 0x1000004:
            case 0x100000d: case 0x1000023: case 0x100002d:
                *(f32*)(p+0x54)=lbl_80543EB4; break;
            default: *(f32*)(p+0x54)=lbl_80543EC0; break;
            }
        } else *(f32*)(p+0x54)=lbl_80543EB4;
        if (*(void**)(p+0x80))
            ((JAISoundParamsMove*)(*(u8**)(p+0x80)+0x48))->moveVolume(*(f32*)(p+0x4c)**(f32*)(p+0x54),lbl_8053A254);
    }
    if (p[0x68] && *(s32*)(p+0x64)>=0) {
        if ((u32)*(s32*)(p+0x64)>=lbl_8053A25C) {
            if (p[4]==0) {
                JAISoundID id=*(u32*)(p+0x5c);
                ((JAUSoundMgr*)*(void**)(p+0x30))->startSound(id,(JAISoundHandle*)(p+0x80),0);
                fn_8045815C(p,p[0x8b]);
                switch (*(s32*)(p+0x5c)) {
                case 0x100001a:
                    if (*(Unk80458408Obj**)(p+0x80)) {
                        switch (*(s32*)(p+0x5c)) { case 0x100001a: break; default: goto soundStarted; }
                        bank=(*(Unk80458408Obj**)(p+0x80))->v4();
                        if (bank) {
                            volatile BOOL irq=OSDisableInterrupts();
                            for (i=0;i<16;i++) {
                                JASTrack* track=bank->v7(i);
                                if (track) {
                                    if (i==2 || i==7) track->mute(false);
                                    else track->mute(true);
                                }
                            }
                            OSRestoreInterrupts(irq);
                        }
                    }
                    break;
                case 0x100000d: case 0x1000021: case 0x1000024:
                    *(f32*)(p+0x4c)=lbl_80543EB4; break;
                }
soundStarted:
                if (*(void**)(p+0x80)) {
                    ((JAISoundParamsMove*)(*(u8**)(p+0x80)+0x48))->moveVolume(*(f32*)(p+0x4c)**(f32*)(p+0x54),0);
                    if (p[0x8d]) (*(JAISound**)(p+0x80))->getTrack()->writePort(0,1);
                }
            }
            *(u32*)(p+0x58)=*(u32*)(p+0x5c);
            *(u32*)(p+0x5c)=0;
            *(s32*)(p+0x64)=-1;
        } else ++*(s32*)(p+0x64);
    }
    mgr=*(JAUSoundMgr**)(p+0x30);
    mgr->calc(); mgr->mixOut();
    ++*(u32*)p;
    if (p[0x6c]) --p[0x6c];
    if (p[0x6a]) { fn_80458880(p,0x48,-1); p[0x6a]=0; }
    if (p[0x6d] && !p[0x8e] && !fn_8045A0D8()) --p[0x6d];
    if (p[0x89] && !*(void**)(p+0x80)) p[0x89]=0;
    if (!*(void**)(p+0x80)) { *(u32*)(p+0x58)=0; *(u32*)(p+0x5c)=0; *(u32*)(p+0x60)=0; }
    if (p[0x75]) {
        ++*(u32*)(p+0x78);
        if (*(u32*)(p+0x78)>45) {
            message.mId.mFullId=0x30089;
            ((Unk80459674Message*)*(void**)(p+0x28))->v3(message);
        }
    } else *(u32*)(p+0x78)=0;
    p[0x75]=0;
}

#include "JSystem/JAudio/JAUInitializer.h"
#include "JSystem/JAudio/JAUAudioArchive.h"
extern "C" void fn_8003C984(void*);
struct FsaAudienceBase {
    FsaAudienceBase() {
        fn_8003C984(this);
        *(void**)this = lbl_80495480;
    }
    u8 pad[0x84];
};
struct FsaAudienceMtx : FsaAudienceBase {
    FsaAudienceMtx() {
        *(void**)this = lbl_804954F8;
        *(u32*)(pad + 0x50) = 1;
        PSMTXIdentity((MtxPtr)(pad + 0x54));
    }
};
struct FsaAudience : FsaAudienceMtx {
    FsaAudience() {
        *(void**)this = lbl_804954D8;
        *(void**)this = lbl_804B2074;
    }
};
class WaveController {
public:
    WaveController(s32 a, s32 b, s32 c);
    u8 pad[0x5c];
};
#include "JSystem/JKernel/JKRArchive.h"
extern "C" u32 lbl_8053A220;
extern "C" u32 lbl_8053A224;
extern "C" int lbl_8053A228;
extern "C" f32 lbl_8053A22C;
extern "C" f32 lbl_8053A230;
extern "C" u8 lbl_8053A234;
extern "C" f32 lbl_8053A238;
extern "C" f32 lbl_8053A23C;
extern "C" f32 lbl_8053A240;
extern "C" char* lbl_8053A244;
extern "C" char* lbl_8053A248;
extern "C" char* lbl_8053A24C;
extern "C" f32 lbl_8053AF78;
extern "C" u8 lbl_80491600[];
extern "C" void* lbl_80495470[];
extern "C" char lbl_804B2098[];
extern "C" void* __vt__16JAIStreamDataMgr[];
extern "C" void fn_8003C984(void*);
extern "C" void fn_8003C8D8(void*);
extern "C" void fn_8045A0E4(int count);
extern "C" void __ct__12JAISoundInfoFb(void*, bool);
extern "C" void __ct__14WaveControllerFlll(void*, s32, void*, s32);
#pragma opt_lifetimes on
extern "C" void fn_80459AE4(u8* this_, s32 heap, u32 size, void* data, JKRArchive* arc) {
    JAUSoundInfo* info;
    JASDsp::FxlineConfig_* cfg;
    u8 i;
    JAU_JASInitializer jas;
    jas.mChannelPoolCount = lbl_8053A228;
    jas.mAudioMemSize = size;
    jas.mDSPLevel = lbl_8053A240;
    jas.initJASystem((JKRSolidHeap*)heap);
    JAU_JAIInitializer jai;
    jai.mSeCount = lbl_8053A220;
    jai.mSeqCount = lbl_8053A224;
    jai.initJAInterface();
    *(JASAudioReseter**)(this_ + 0x2c) = new ((JKRHeap*)heap, 0) JASAudioReseter();
    *(JAUSoundMgr**)(this_ + 0x30) = new ((JKRHeap*)heap, 0) JAUSoundMgr();
    *(u8**)(this_ + 0x34) = *(u8**)(this_ + 0x30) + 4;
    *(u8**)(this_ + 0x38) = *(u8**)(this_ + 0x30) + 0x728;
    u8* au = (u8*)operator new(0x84, (JKRHeap*)heap, 0);
    if (au) {
        new (au) FsaAudienceMtx();
        *(void**)au = lbl_804954D8;
        *(void**)au = lbl_804B2074;
    }
    *(u8**)(this_ + 0x3c) = au;
    *(f32*)(*(u8**)(this_ + 0x3c) + 0x4) = lbl_8053A22C;
    *(f32*)(*(u8**)(this_ + 0x3c) + 0x8) = lbl_8053A230;
    *(f32*)(*(u8**)(this_ + 0x3c) + 0xc) = lbl_8053AF78;
    *(f32*)(*(u8**)(this_ + 0x3c) + 0x10) = lbl_8053A238;
    *(f32*)(*(u8**)(this_ + 0x3c) + 0x14) = lbl_8053A23C;
    *(f32*)(*(u8**)(this_ + 0x3c) + 0x1c) = lbl_8053A234;
    fn_8045A0E4(jai.mSeCount);
    fn_8003C8D8(*(void**)(this_ + 0x3c));
    (*(JAISeMgr**)(this_ + 0x34))->setAudience(*(JAIAudience**)(this_ + 0x3c));
    JAISeCategoryArrangement cat;
    cat.mItems[0].mMaxActiveSe = 4;
    cat.mItems[0].mMaxInactiveSe = 4;
    cat.mItems[1].mMaxActiveSe = 4;
    cat.mItems[1].mMaxInactiveSe = 4;
    cat.mItems[2].mMaxActiveSe = 12;
    cat.mItems[2].mMaxInactiveSe = 12;
    cat.mItems[3].mMaxActiveSe = 12;
    cat.mItems[3].mMaxInactiveSe = 12;
    cat.mItems[4].mMaxActiveSe = 12;
    cat.mItems[4].mMaxInactiveSe = 12;
    cat.mItems[5].mMaxActiveSe = 8;
    cat.mItems[5].mMaxInactiveSe = 8;
    cat.mItems[6].mMaxActiveSe = 8;
    cat.mItems[6].mMaxInactiveSe = 8;
    (*(JAISeMgr**)(this_ + 0x34))->setCategoryArrangement(cat);
    ((JAISoundParamsMove*)(*(u8**)(this_ + 0x34) + 0x1c))->moveVolume(lbl_80543EB4, 0);
    ((JAISoundParamsMove*)(*(u8**)(this_ + 0x34) + 0x88))->moveVolume(lbl_80543EB4, 0);
    ((JAISoundParamsMove*)(*(u8**)(this_ + 0x34) + 0xf4))->moveVolume(lbl_80543EB4, 0);
    ((JAISoundParamsMove*)(*(u8**)(this_ + 0x34) + 0x160))->moveVolume(lbl_80543EB4, 0);
    ((JAISoundParamsMove*)(*(u8**)(this_ + 0x34) + 0x1cc))->moveVolume(lbl_80543EB4, 0);
    ((JAISoundParamsMove*)(*(u8**)(this_ + 0x34) + 0x238))->moveVolume(lbl_80543EB4, 0);
    ((JAISoundParamsMove*)(*(u8**)(this_ + 0x34) + 0x2a4))->moveVolume(lbl_80543EB4, 0);
    struct FxSet { JASDsp::FxlineConfig_ c[4]; };
    FxSet fx = *(FxSet*)lbl_80491600;
    for (i = 0; i < 4; i++) {
        s16* buf;
        cfg = &fx.c[i];
        buf = new ((JKRHeap*)heap, 0x20) s16[(cfg->mBufCount * 0xa0) / sizeof(s16)];
        JASDsp::setFXLine(i, buf, cfg);
    }
    *(WaveController**)(this_ + 0x14) = new WaveController(0, heap, 4);
    for (int k = 0; k < 4; k++) {
        *(WaveController**)(this_ + k * 4 + 0x18) = new WaveController(0, heap, 4);
    }
    *(WaveController**)(this_ + 0x28) = new WaveController(0, heap, 1);
    u8* si = (u8*)operator new(0x10, (JKRHeap*)heap, 0);
    if (si) {
        __ct__12JAISoundInfoFb(si, true);
        info = (JAUSoundInfo*)(si + 4);
        JASGlobalInstance<JAUSoundInfo>::sInstance = info;
        *(void**)info = lbl_80495470;
        *(void**)(si + 8) = __vt__16JAIStreamDataMgr;
        *(void**)si = lbl_804B2098;
        *(void**)(si + 4) = lbl_804B2098 + 0x24;
        *(void**)(si + 8) = lbl_804B2098 + 0x34;
        *(u32*)(si + 0xc) = 0;
    }
    *(u8**)(this_ + 0x40) = si;
    if (arc == 0) {
        arc = JKRArchive::mount(lbl_8053A24C, JKRArchive::MOUNT_DVD, (JKRHeap*)heap, JKRArchive::MOUNT_DIRECTION_HEAD);
    }
    JASWaveArcLoader::setCurrentDir(lbl_8053A248);
    *(JAUSectionHeap**)(this_ + 0x44) = JAUNewSectionHeap(true);
    (*(JAUSectionHeap**)(this_ + 0x44))->setSeqDataArchive(arc);
    (*(JAUSectionHeap**)(this_ + 0x44))->newDynamicSeqBlock(0x16000);
    (*(JAUSectionHeap**)(this_ + 0x44))->newDynamicSeqBlock(0x16000);
    (*(JAUSectionHeap**)(this_ + 0x44))->newDynamicSeqBlock(0xb000);
    JAUAudioArcLoader loader(*(JAUSectionHeap**)(this_ + 0x44));
    if (data) {
        loader.load(data);
    } else {
        loader.load(lbl_8053A244);
    }
    (*(JAISeMgr**)(this_ + 0x34))->setSeqDataMgr((*(JAUSectionHeap**)(this_ + 0x44))->sectionHeapData_.seSeqDataMgr_);
    (*(JAISeqMgr**)(this_ + 0x38))->setSeqDataMgr((JAISeqDataMgr*)*(JAUSectionHeap**)(this_ + 0x44));
    *(JAUSoundTable**)(*(u8**)(this_ + 0x40) + 0xc) = (*(JAUSectionHeap**)(this_ + 0x44))->getSoundTable();
    *(f32*)(this_ + 0x4c) = lbl_80543EB4;
    *(f32*)(this_ + 0x50) = lbl_80543EB4;
    *(f32*)(this_ + 0x54) = lbl_80543EB4;
    *(u32*)(this_ + 0x58) = 0;
    *(u32*)(this_ + 0x5c) = 0;
    *(u32*)(this_ + 0x60) = 0;
    *(s32*)(this_ + 0x64) = -1;
    this_[0x68] = 0;
    this_[0x89] = 0;
    this_[0x69] = 0;
    this_[0x7c] = 0;
    this_[0x6a] = 0;
    this_[0x88] = 0;
    this_[0x8a] = 0;
    this_[0x8b] = 0;
    this_[0x8c] = 0;
    this_[0x8d] = 0;
    this_[0x8e] = 0;
    this_[0x75] = 0;
    *(u32*)(this_ + 0x78) = 0;
    fn_80458744(this_, 0);
}
#pragma opt_lifetimes reset
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

#pragma dont_inline on
extern "C" u8 fn_8045A0D8()
{
    return *(u8*)(lbl_8053AAF8 + 0x96);
}
#pragma dont_inline reset

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
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, (char*)lbl_8052DBE0 + 0x0);
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

extern "C" const f32 lbl_80543ED0;
extern "C" int __float_epsilon[];
extern "C" void fn_8045A3D8(char* p1, JASSoundParams* p2, Unk8045A3D8Src* p3, s32 p4) {
    char* o = *(char**)((char*)p3 + p4 * 4 + 0x18);
    if (o != 0) {
        JASSoundParams sp;
        f32 t;
        f32 one = 1.0f;
        f32 zero = 0.0f;
        if ((p3->m10 >> 2) & 1) {
            t = *(f32*)(o + 0x20);
            if (t > *(f32*)(p1 + 0x4)) {
                sp.mVolume = *(f32*)(p1 + 0xc);
            } else if (t < *(f32*)(p1 + 0x8)) {
            } else {
                f32 v = *(f32*)(p1 + 0x44) * (t - *(f32*)(p1 + 0x8)) + one;
                sp.mVolume = v < zero ? zero : (v > one ? one : v);
            }
        }
        if ((p3->m11 >> 6) & 1) {
            t = *(f32*)(o + 0x1c);
            if (t > *(f32*)(p1 + 0x14)) {
                sp.mDolby = *(f32*)(p1 + 0x18);
            } else if (t < *(f32*)(p1 + 0x10)) {
                sp.mDolby = *(f32*)(p1 + 0x20);
            } else if (t < zero) {
                sp.mDolby = *(f32*)(p1 + 0x3c) * t + *(f32*)(p1 + 0x1c);
            } else {
                sp.mDolby = *(f32*)(p1 + 0x40) * t + *(f32*)(p1 + 0x1c);
            }
        } else {
            sp.mDolby = *(f32*)(p1 + 0x1c);
        }
        if ((p3->m11 >> 7) & 1) {
            if ((p3->m11 & 1) == 0 || (p3->m11 & 2) != 0) {
                if (*(s32*)(p1 + 0x50) > 2) {
                    sp.mPan = (p4 & 1) ? one : zero;
                } else {
                    f32 r;
                    if (*(f32*)(o + 0x20) <= lbl_80543ED0 * *(f32*)__float_epsilon) {
                        r = zero;
                    } else {
                        r = *(f32*)(o + 0x14) / *(f32*)(o + 0x20);
                    }
                    sp.mPan = r * *(f32*)(p1 + 0x2c) + 0.5f;
                }
                p3->m11 |= 2;
            } else {
                sp.mPan = 0.5f;
                sp.mPitch = one;
            }
        }
        if ((p3->m10 >> 1) & 1) {
            t = *(f32*)(o + 0x20);
            if (t > *(f32*)(p1 + 0x4)) {
                sp.mFxMix = *(f32*)(p1 + 0x28);
            } else if (t < *(f32*)(p1 + 0x8)) {
                sp.mFxMix = *(f32*)(p1 + 0x24);
            } else {
                sp.mFxMix = *(f32*)(p1 + 0x4c) * (t - *(f32*)(p1 + 0x8)) + *(f32*)(p1 + 0x24);
            }
        } else {
            sp.mFxMix = zero;
        }
        p3->v3(p4)->combine(*p2, sp);
    }
}

