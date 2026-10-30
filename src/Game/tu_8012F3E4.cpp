// tu_8012F3E4: .text 0x8012F3E4-0x8012F8AC — 'IFCK' Check-Flag Registry.
#include "types.h"

struct IfckActorObj {
    /* 0x000 */ u8 _pad00[0x198];
    /* 0x198 */ s32 mActorHandle;
    /* 0x19C */ u32 mField19C;
    /* 0x1A0 */ u32 mActorFourCC; // 'IFCK'
};

extern "C" void* fn_801F856C(void);
extern "C" IfckActorObj* fn_801F666C(void* mgr, s32 handle);
extern "C" u8 fn_8012F008(IfckActorObj* ifck);

class IfckRegistry {
public:
    IfckRegistry() {
        mCount = 0;
        reset();
    }
    ~IfckRegistry();

    void reset() {
        mCount = 0;
        for (int i = 0; i < 64; i++) {
            mIds[i] = -1;
        }
    }

    s32 mCount;
    s32 mIds[64];
};

extern "C" BOOL fn_8012F3E4(const IfckRegistry& reg) {
    s32 n = reg.mCount;
    if (n <= 0) {
        return FALSE;
    }
    const s32* ids = &reg.mCount;
    for (int i = 0; i < n; ids++, i++) {
        IfckActorObj* obj = fn_801F666C(fn_801F856C(), ids[1]);
        if (obj == 0) {
            return FALSE;
        }
        if (obj->mActorFourCC != 'IFCK') {
            return FALSE;
        }
        if (!fn_8012F008(obj)) {
            return FALSE;
        }
    }
    return TRUE;
}

extern "C" void fn_8012F494(IfckRegistry* reg) {
    reg->reset();
}

extern "C" void fn_8012F530(IfckRegistry* reg, IfckActorObj* actor) {
    reg->mIds[reg->mCount] = actor->mActorHandle;
    reg->mCount++;
}

extern "C" IfckRegistry* fn_8012F554(void) {
    static IfckRegistry sInstance;
    return &sInstance;
}

IfckRegistry::~IfckRegistry() {}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
