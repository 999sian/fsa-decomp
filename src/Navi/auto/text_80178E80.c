

#include "types.h"

class UnkVObj_80184B60 {
public:
    virtual void vfn0(void* self);
    virtual void vfn1(void* self);
};

extern "C" void fn_8016A39C(void* item, UnkVObj_80184B60* obj);
extern "C" u8 fn_8018A318(void* self, s32* param_2, s32* param_3);

extern "C" int fn_8018A064(void* self, s32* param_2) {
    s32 local_14 = -1;
    s32 local_10 = -1;
    if (fn_8018A318(self, &local_14, &local_10) == 0) {
        return 0;
    }
    s32 local_c;
    s32 local_18;
    local_18 = *param_2;
    local_c = local_14;
    int (*fn)(void*, s32*, s32*) = (int (*)(void*, s32*, s32*))(*(void***)self)[0xac / 4];
    return fn(self, &local_c, &local_18);
}
