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

extern "C" void fn_80216A8C(TuBox* box) {
    box->mMinX = lbl_8053FC08;
    box->mMinY = lbl_8053FC08;
    box->mMaxX = lbl_8053FC0C;
    box->mMaxY = lbl_8053FC0C;
    u8* o = (u8*)box->mData;
    if (*(s32*)(o + 0x340) == 2) {
        if (*(u8*)(o + 0x34d) < 3) return;
        switch (*(s8*)(o + 0x34c)) {
            case 0: TuBoxSetQuad(box, lbl_8053FC10, lbl_8053FC14, lbl_8053FC18, lbl_8053FC00, 0); break;
            case 1: TuBoxSetQuad(box, lbl_8053FC10, lbl_8053FC14, lbl_8053FC1C, lbl_8053FC00, 1); break;
            case 2: TuBoxSetQuad(box, lbl_8053FC10, lbl_8053FC14, lbl_8053FC00, lbl_8053FC18, 2); break;
            case 3: TuBoxSetQuad(box, lbl_8053FC10, lbl_8053FC14, lbl_8053FC00, lbl_8053FC1C, 3); break;
        }
        return;
    }
    if (*(s32*)(o + 0x340) == 3) {
        if (*(u8*)(o + 0x34d) < 1) return;
        switch (*(s8*)(o + 0x34c)) {
            case 0: TuBoxSetQuad(box, lbl_8053FC10, lbl_8053FC14, lbl_8053FC18, lbl_8053FC00, 0); break;
            case 1: TuBoxSetQuad(box, lbl_8053FC10, lbl_8053FC14, lbl_8053FC1C, lbl_8053FC00, 1); break;
            case 2: TuBoxSetQuad(box, lbl_8053FC10, lbl_8053FC14, lbl_8053FC00, lbl_8053FC18, 2); break;
            case 3: TuBoxSetQuad(box, lbl_8053FC10, lbl_8053FC14, lbl_8053FC00, lbl_8053FC1C, 3); break;
        }
        return;
    }
    if (*(s32*)(o + 0x340) == 6) {
        if (*(u8*)(o + 0x34d) < 2) return;
        switch (*(s32*)(o + 0x348) - 0x8f) {
            case 1: case 12: case 18:
                TuBoxSetQuad(box, lbl_8053FC10, lbl_8053FC14, lbl_8053FC18, lbl_8053FC00, 0); break;
            case 2: case 13: case 19:
                TuBoxSetQuad(box, lbl_8053FC10, lbl_8053FC14, lbl_8053FC20, lbl_8053FC20, 2); break;
            case 3: case 14: case 20:
                TuBoxSetQuad(box, lbl_8053FC10, lbl_8053FC14, lbl_8053FC00, lbl_8053FC18, 2); break;
            case 4: case 15: case 21:
                TuBoxSetQuad(box, lbl_8053FC10, lbl_8053FC14, lbl_8053FC24, lbl_8053FC20, 1); break;
            case 5: case 8: case 22:
                TuBoxSetQuad(box, lbl_8053FC10, lbl_8053FC14, lbl_8053FC1C, lbl_8053FC00, 1); break;
            case 6: case 9: case 23:
                TuBoxSetQuad(box, lbl_8053FC10, lbl_8053FC14, lbl_8053FC24, lbl_8053FC24, 3); break;
            case 7: case 10: case 16:
                TuBoxSetQuad(box, lbl_8053FC10, lbl_8053FC14, lbl_8053FC00, lbl_8053FC1C, 3); break;
            case 0: case 11: case 17:
                TuBoxSetQuad(box, lbl_8053FC10, lbl_8053FC14, lbl_8053FC20, lbl_8053FC24, 0); break;
        }
    }
}

extern "C" void fn_80217128(TuBox* box) {
    box->mData = NULL;
    box->mField14 = 0;
    box->mMinX = 1.0f;
    box->mMinY = 1.0f;
    box->mMaxX = -1.0f;
    box->mMaxY = -1.0f;
  }

void __sinit_tu_8021693C_cpp(void) {}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

