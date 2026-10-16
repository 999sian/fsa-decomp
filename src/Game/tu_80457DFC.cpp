#include "JSystem/JAudio/Interface/JAISoundParams.h"
#include "JSystem/JAudio/Interface/JAISound.h"

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

