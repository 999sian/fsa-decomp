// TU 0x8021693C-0x80217374.
#include "types.h"
#include "JSystem/JGeometry/Box.h"
extern const f32 lbl_8053FC00;
extern const f32 lbl_8053FC04;
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

extern const f32 lbl_8053FC08;
extern const f32 lbl_8053FC0C;
extern const f32 lbl_8053FC10;
extern const f32 lbl_8053FC14;
extern const f32 lbl_8053FC18;
extern const f32 lbl_8053FC1C;
extern const f32 lbl_8053FC20;
extern const f32 lbl_8053FC24;

static inline void TuBoxSetQuad(TuBox* box, f32 bx, f32 by, f32 ax, f32 ay, int state) {
    box->mMinX = bx;
    box->mMinY = bx;
    box->mMaxX = by;
    box->mMaxY = by;
    box->mMinX += ax;
    box->mMinY += ay;
    box->mMaxX += ax;
    box->mMaxY += ay;
    box->mField14 = state;
}

extern "C" u8* fn_802D6A9C(void);
extern "C" f32* fn_8023E724(int i);
extern "C" u8 fn_80239B64(int i, f32* rect, int a, int b, int c, int d);

extern "C" u8 fn_8021693C(TuBox* box, u32 param2) {
    int field4;
    TuObj* obj;
    TuObj* current;
    u8 mask = param2;
    u8 result;
    int i;
    if (!mask) return 0;
    result = 0;
    JGeometry::TBox2f* bounds = (JGeometry::TBox2f*)&box->mMinX;
    if (bounds->getWidth() > lbl_8053FC00 && bounds->getHeight() > lbl_8053FC00) {
        JGeometry::TBox2f rect;
        JGeometry::TVec2<f32> maximum(box->mMaxX, box->mMaxY);
        JGeometry::TVec2<f32> minimum(bounds->i.x, box->mMinY);
        rect.i.x = minimum.x;
        obj = (TuObj*)box->mData;
        rect.i.y = minimum.y;
        rect.f.set(maximum);
        rect.addPos(obj->mField0C, obj->mField10 - obj->mField14);
        for (i = 0; i < 4; i++) {
            field4 = obj->mField4;
            u8* base = fn_802D6A9C();
            if (base[field4 + 0x131df] == 0) {
                current = (TuObj*)box->mData;
                if (__fabsf(current->mField14 - fn_8023E724(i)[2]) > lbl_8053FC04) continue;
            }
            int bit = 1 << i;
            if (mask & bit) {
                if (fn_80239B64(i, (f32*)&rect, ((TuObj*)box->mData)->mField4, box->mField14, 1, 1)) {
                    result |= bit;
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

