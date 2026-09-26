// tu_8012FF9C: .text 0x8012FF9C-0x80130310 (OGST gate registry singleton)
#include "types.h"

extern "C" void* fn_801F856C(void);
extern "C" u8* fn_801F666C(void* mgr, s32 handle);
extern "C" s32 fn_8012FC2C(u8* ogst, s32* counts);

class OgstRegistry {
public:
    OgstRegistry() { mCount = 0; }
    ~OgstRegistry();

    u32 mIds[1];
    s32 mCount;
};

extern "C" OgstRegistry* fn_8012FF9C(void) {
    static OgstRegistry sInstance;
    return &sInstance;
}

OgstRegistry::~OgstRegistry() {}

extern "C" s32 fn_80130030(OgstRegistry* reg, s32* counts) {
    if (reg->mCount <= 0) {
        return 1;
    }
    u8* obj = fn_801F666C(fn_801F856C(), reg->mIds[0]);
    if (obj == 0) {
        return 1;
    }
    if (*(u32*)(obj + 0x1A0) != 'OGST') {
        return 1;
    }
    return fn_8012FC2C(obj, counts);
}

extern "C" void fn_801300B4(OgstRegistry* reg, s32 id) {
    if (id <= 0) {
        return;
    }
    reg->mIds[reg->mCount] = id;
    reg->mCount++;
}

extern "C" void fn_801300D8(OgstRegistry* reg) {
    reg->mCount = 0;
    reg->mIds[0] = 0xFFFFFFFF;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
