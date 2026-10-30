// tu_80127E20: .text 0x80127E20-0x801286C0 — 'FZRA' Group Registry.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

struct FzraActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ JGeometry::TVec3<f32> mPos;
    /* 0x018 */ u8 _pad18[0x198 - 0x18];
    /* 0x198 */ s32 mActorHandle;
    /* 0x19C */ u32 mField19C;
    /* 0x1A0 */ u32 mActorFourCC; // 'FZRA'
    /* 0x1A4 */ u8 _pad1A4[0x230 - 0x1A4];
    /* 0x230 */ s32 mState;
    /* 0x234 */ u8 _pad234[0x258 - 0x234];
    /* 0x258 */ u8 mGroupSide;
};

extern "C" void* fn_801F856C(void);
extern "C" FzraActor* fn_801F666C(void* mgr, s32 handle);
extern "C" void fn_80126A4C(FzraActor* fzra, s32 mode);
extern "C" u8 fn_80126EF8(FzraActor* fzra);
extern "C" void fn_80230534(s32 a);
extern "C" void fn_8023077C(void);

class FzraRegistry {
public:
    FzraRegistry() { reset(); }
    ~FzraRegistry();

    void reset() {
        mCount = 0;
        mIds[0] = 0;
        mIds[1] = 0;
        mIds[2] = 0;
        mIds[3] = 0;
        mIds[4] = 0;
        mIds[5] = 0;
        mIds[6] = 0;
        mIds[7] = 0;
    }

    s32 mCount;
    s32 mIds[8];
};

static inline FzraActor* getActor(s32 id) {
    return fn_801F666C(fn_801F856C(), id);
}

extern "C" void fn_80127E20(FzraRegistry* reg, const JGeometry::TVec3<f32>& pos) {
    for (int i = 0; i < reg->mCount; i++) {
        FzraActor* a = getActor(reg->mIds[i]);
        if (a != 0 && a->mActorFourCC == 'FZRA' && a->mGroupSide == 0) {
            a->mPos = pos;
        }
    }
}

extern "C" void fn_80127ED8(FzraRegistry* reg, const JGeometry::TVec3<f32>& pos) {
    for (int i = 0; i < reg->mCount; i++) {
        FzraActor* a = getActor(reg->mIds[i]);
        if (a != 0 && a->mActorFourCC == 'FZRA' && a->mGroupSide != 0) {
            a->mPos = pos;
        }
    }
}

extern "C" JGeometry::TVec3<f32>* fn_80127F90(FzraRegistry* reg) {
    JGeometry::TVec3<f32> zero;
    JGeometry::TVec3<f32> mid;
    JGeometry::TVec3<f32> p[2];
    if (reg->mCount <= 1) {
        zero.x = 0.0f;
        zero.y = 0.0f;
        zero.z = 0.0f;
        return &zero;
    }
    for (int i = 0; i < 2; i++) {
        FzraActor* a = getActor(reg->mIds[i]);
        if (a != 0 && a->mActorFourCC == 'FZRA') {
            p[i] = a->mPos;
        }
    }
    mid.x = (p[0].x + p[1].x) / 2.0f;
    mid.y = (p[0].y + p[1].y) / 2.0f;
    mid.z = 0.0f;
    return &mid;
}

extern "C" void fn_80128074(FzraRegistry* reg) {
    for (int i = 0; i < reg->mCount; i++) {
        FzraActor* a = getActor(reg->mIds[i]);
        if (a != 0 && a->mActorFourCC == 'FZRA') {
            fn_80126A4C(a, 0x10);
        }
    }
}

extern "C" BOOL fn_801280F8(FzraRegistry* reg) {
    for (int i = 0; i < reg->mCount; i++) {
        FzraActor* a = getActor(reg->mIds[i]);
        if (a != 0 && a->mActorFourCC == 'FZRA') {
            switch (a->mState) {
            case 2:
            case 3:
            case 9:
                return TRUE;
            }
        }
    }
    return FALSE;
}

extern "C" void fn_801281A4(FzraRegistry* reg) {
    for (int i = 0; i < reg->mCount; i++) {
        FzraActor* a = getActor(reg->mIds[i]);
        if (a != 0 && a->mActorFourCC == 'FZRA') {
            fn_80126A4C(a, 0xA);
        }
    }
}

extern "C" void fn_80128228(void) {
    fn_80230534(0);
}

extern "C" BOOL fn_8012824C(FzraRegistry* reg) {
    fn_8023077C();
    for (int i = 0; i < reg->mCount; i++) {
        FzraActor* a = getActor(reg->mIds[i]);
        if (a != 0) {
            if (a->mActorFourCC != 'FZRA') {
                return FALSE;
            }
            fn_80126A4C(a, 5);
        }
    }
    return TRUE;
}

extern "C" BOOL fn_801282E0(FzraRegistry* reg) {
    if (reg->mCount <= 0) {
        return FALSE;
    }
    for (int i = 0; i < reg->mCount; i++) {
        FzraActor* a = getActor(reg->mIds[i]);
        if (a == 0) {
            return FALSE;
        }
        if (a->mActorFourCC != 'FZRA') {
            return FALSE;
        }
        if (!fn_80126EF8(a)) {
            return FALSE;
        }
    }
    return TRUE;
}

extern "C" void fn_80128398(FzraRegistry* reg, FzraActor* actor) {
    reg->mIds[reg->mCount] = actor->mActorHandle;
    reg->mCount++;
}

extern "C" void fn_801283BC(FzraRegistry* reg) {
    reg->reset();
}

extern "C" FzraRegistry* fn_801283E8(void) {
    static FzraRegistry sInstance;
    return &sInstance;
}

FzraRegistry::~FzraRegistry() {}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
