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

extern "C" void fn_80217128(TuBox* box) {
    box->mData = NULL;
    box->mField14 = 0;
    box->mMinX = 1.0f;
    box->mMinY = 1.0f;
    box->mMaxX = -1.0f;
    box->mMaxY = -1.0f;
  }

