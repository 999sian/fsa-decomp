// TU 0x8021693C-0x80217374.
#include "types.h"

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

extern "C" void fn_80217128(TuBox* box) {
    box->mData = NULL;
    box->mField14 = 0;
    box->mMinX = 1.0f;
    box->mMinY = 1.0f;
    box->mMaxX = -1.0f;
    box->mMaxY = -1.0f;
  }

