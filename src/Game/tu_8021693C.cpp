// TU 0x8021693C-0x80217374.
#include "types.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "Game/SinitPoolChain.h"

struct TuBox {
    void* mData;
    f32 mMinX;
    f32 mMinY;
    f32 mMaxX;
    f32 mMaxY;
    int mField14;
};

struct TuObj {
    u8 pad_0x0[4];
    int mField4;
    u8 pad_0x8[4];
    f32 mField0C;
    f32 mField10;
    f32 mField14;
};

extern "C" u8* fn_802D6A9C(void);
extern "C" f32* fn_8023E724(int i);
extern "C" u8 fn_80239B64(int i, f32* rect, int a, int b, int c, int d);

extern "C" u8 fn_8021693C(TuBox* box, u32 param2) {
    u8 result = 0;
    u8 mask = param2 & 0xff;
    if (mask == 0) {
        return 0;
    }
    if (box->mMaxX - box->mMinX > 0.0f && box->mMaxY - box->mMinY > 0.0f) {
        TuObj* obj = (TuObj*)box->mData;
        f32 rect[4];
        rect[0] = box->mMinX + obj->mField0C;
        rect[1] = box->mMinY + (obj->mField10 - obj->mField14);
        rect[2] = box->mMaxX + obj->mField0C;
        rect[3] = box->mMaxY + (obj->mField10 - obj->mField14);
        for (int i = 0; i < 4; i++) {
            int field4 = obj->mField4;
            u8* base = fn_802D6A9C();
            if (base[field4 + 0x131df] != 0 ||
                __fabsf(((TuObj*)box->mData)->mField14 - fn_8023E724(i)[2]) > 32.0f) {
                if (mask & (1 << i)) {
                    if (fn_80239B64(i, rect, ((TuObj*)box->mData)->mField4, box->mField14, 1, 1)) {
                        result |= (1 << i);
                    }
                }
            }
        }
    }
    return result;
}

extern "C" void fn_80217128(TuBox* box) {
    box->mData = NULL;
    box->mField14 = 0;
    box->mMinX = 1.0f;
    box->mMinY = 1.0f;
    box->mMaxX = -1.0f;
    box->mMaxY = -1.0f;
  }

#include "JSystem/JAudio/JASFakeMatchFSA.h"

