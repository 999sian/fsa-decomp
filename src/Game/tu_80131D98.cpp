// tu_80131D98: .text 0x80131D98-0x801321DC (OPGL / FAZR gate lookup registry)
#include "types.h"

extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F7A08(void* mgr, u32 id);
extern "C" u8* fn_801F666C(void* mgr, s32 handle);

class OpglActor {
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
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual u8 vf60();
};

class GateRegistry {
public:
    GateRegistry() {
        mCount = 0;
        mIds[0] = 0;
        mIds[1] = 0;
    }
    ~GateRegistry();

    s32 mCount;
    s32 mIds[2];
};

extern "C" BOOL fn_80131D98(void) {
    s32 h = fn_801F7A08(fn_801F856C(), 'OPGL');
    if (h < 0) {
        return FALSE;
    }
    u8* obj = fn_801F666C(fn_801F856C(), h);
    if (obj == 0) {
        return FALSE;
    }
    if (*(u32*)(obj + 0x1A0) != 'OPGL') {
        return FALSE;
    }
    return ((OpglActor*)obj)->vf60() != 0;
}

extern "C" u8* fn_80131E30(GateRegistry* reg, s32 idx) {
    if (idx < 0 || idx >= reg->mCount) {
        return 0;
    }
    u8* obj = fn_801F666C(fn_801F856C(), reg->mIds[idx]);
    if (obj == 0) {
        return 0;
    }
    if (*(u32*)(obj + 0x1A0) != 'FAZR' && *(u32*)(obj + 0x1A0) != 'OPGL') {
        obj = 0;
    }
    return obj;
}

extern "C" void fn_80131EC0(GateRegistry* reg, u8* actor) {
    reg->mIds[reg->mCount] = *(s32*)(actor + 0x198);
    reg->mCount++;
}

extern "C" void fn_80131EE4(GateRegistry* reg) {
    reg->mCount = 0;
    reg->mIds[0] = 0;
    reg->mIds[1] = 0;
}

extern "C" void fn_80131EF8(GateRegistry* reg) {
    reg->mCount = 0;
    reg->mIds[0] = 0;
    reg->mIds[1] = 0;
}

extern "C" GateRegistry* fn_80131F0C(void) {
    static GateRegistry sInstance;
    return &sInstance;
}

GateRegistry::~GateRegistry() {
    mCount = 0;
    mIds[0] = 0;
    mIds[1] = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
