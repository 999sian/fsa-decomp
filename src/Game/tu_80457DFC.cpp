#include "JSystem/JAudio/Interface/JAISoundParams.h"
#include "JSystem/JAudio/Interface/JAISound.h"
#include "JSystem/JAudio/System/JASDriver.h"
#include "JSystem/JAudio/JAUSectionHeap.h"
#include "JSystem/JAudio/JAUSoundMgr.h"
#include "JSystem/JAudio/System/JASAudioReseter.h"

struct Unk804580DCTrack {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Unk804580DCTrack* v4(u32 p);
    char pad4[0x4C - 0x4];
    s32 m4C;
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
    char pad54[0x84 - 0x54];
    Unk80458F04Sound* m84;
};

extern "C" void fn_80458744(void*, s32);
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

extern "C" void fn_80457F60(u8* this_) {
    this_[0x74] = 1;
}

extern "C" void fn_80457F6C(u8* this_) {
    this_[0x74] = 0;
    this_[0x6d] = 0xb4;
}

extern "C" void fn_80458090(char* this_) {
    ((JAUSection*)*(void**)(this_ + 0x44))->loadWaveArc(2);
    ((JAUSection*)*(void**)(this_ + 0x44))->loadWaveArc(3);
    ((JAUSection*)*(void**)(this_ + 0x44))->loadWaveArc(4);
}

extern "C" void fn_8045873C(u8* this_, u8 v) {
    this_[0x69] = v;
}

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

extern "C" const f32 lbl_80543EB0;
extern "C" const f32 lbl_80543EB4;
extern "C" void* lbl_8053AF80;
extern "C" char* lbl_8053AAF8;
extern "C" void fn_804594E4(void* self, u32 mode)
{
    JASDriver::setOutputMode(mode);
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

