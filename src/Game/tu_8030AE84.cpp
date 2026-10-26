#include "types.h"
#include "sdk/stl/float.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"

// Reciprocal square root from frsqrte with one Newton step; x must be > 0.
static inline f32 rsqrt_step(f32 x) {
    f32 r = (f32)__frsqrte(x);
    return (0.5f * r) * (3.0f - x * (r * r));
}

static inline f32 rsqrt_guard(f32 x) {
    if (x <= 0.0f) {
        return x;
    }
    return rsqrt_step(x);
}

static inline f32 sqrt_guard(f32 x) {
    if (x <= 0.0f) {
        return x;
    }
    return x * rsqrt_step(x);
}

extern "C" f32 sqrtf(f32 x);
extern "C" int fn_8022EA0C(int);
extern "C" int fn_8023DE58(int);
extern "C" u8 fn_80234950(int id);
extern "C" u8 fn_80234ECC(int id);
extern "C" u8* fn_802D6A9C(void);
extern "C" f32* fn_8023E724(int);
extern "C" void fn_8030B97C(u8*);


extern "C" void fn_8030AE84(u8* p, f32* rect)
{
    rect[0] = *(int*)(p + 0x290);
    rect[1] = *(int*)(p + 0x294);
    rect[2] = *(int*)(p + 0x290) + 0xf0;
    rect[3] = *(int*)(p + 0x294) + 0xa0;
}

extern "C" s32 fn_8030AF10(u8* p, s32 id, f32* rect, u8 flag) {
    if (id >= 8) {
        s32 sel = *(s32*)(p + 0x28c);
        if (id != sel) {
            return 0;
        }
    }
    if (flag) {
        if ((s32)rect[2] < *(s32*)(p + 0x290)) {
            return 0;
        }
        if ((s32)rect[0] > *(s32*)(p + 0x290) + 0xf0) {
            return 0;
        }
        if ((s32)rect[3] < *(s32*)(p + 0x294)) {
            return 0;
        }
        if ((s32)rect[1] > *(s32*)(p + 0x294) + 0xa0) {
            return 0;
        }
    } else {
        s32 x = (s32)rect[0];
        if (x < *(s32*)(p + 0x290) || x > *(s32*)(p + 0x290) + 0xf0) {
            return 0;
        }
        x = (s32)rect[2];
        if (x < *(s32*)(p + 0x290) || x > *(s32*)(p + 0x290) + 0xf0) {
            return 0;
        }
        x = (s32)rect[1];
        if (x < *(s32*)(p + 0x294) || x > *(s32*)(p + 0x294) + 0xa0) {
            return 0;
        }
        x = (s32)rect[3];
        if (x < *(s32*)(p + 0x294) || x > *(s32*)(p + 0x294) + 0xa0) {
            return 0;
        }
    }
    return 1;
}

extern "C" int fn_8030B084(u8* p, int idx, f32* pos)
{
    if (idx < 8 || idx != *(int*)(p + 0x28c)) {
        return 0;
    }
    int x = (int)pos[0];
    if (x < *(int*)(p + 0x290) || x > *(int*)(p + 0x290) + 0xf0) {
        return 0;
    }
    int y = (int)pos[1];
    if (y < *(int*)(p + 0x294) || y > *(int*)(p + 0x294) + 0xa0) {
        return 0;
    }
    return 1;
}

extern "C" u8 fn_8023F264(void*);
extern "C" s32 fn_8030B110(u8* p, s32 id, f32* rect) {
    s32 x;
    s32 y;
    if (!fn_8023F264(*(void**)(p + 0x288)) || id != *(s32*)(p + 0x28c)) return 0;
    if (id < 8) return 1;
    x = (s32)rect[0];
    if (x < *(s32*)(p + 0x2a4) || x > *(s32*)(p + 0x2a0)) return 0;
    y = (s32)rect[1];
    if (y < *(s32*)(p + 0x2ac) || y > *(s32*)(p + 0x2a8)) return 0;
    return 1;
}

extern "C" int* fn_8030B1E8(u8* p, u8 arg1, u8 arg2, int arg3) {
    if (arg1 != *(u8*)(p + 0x2bc)) {
        if (arg2 == 0 || arg2 == 6) {
            *(u16*)(p + 0x2b8) = 0;
            *(s16*)(p + 0x2ba) = 0;
            *(u8*)(p + 0x2bc) = 0xff;
            *(u8*)(p + 0x284) = 0;
        } else {
            if (arg2 == 4) {
                *(u16*)(p + 0x2b8) = 0x60;
            } else if (arg2 == 5) {
                *(u16*)(p + 0x2b8) = 3;
            } else {
                *(u16*)(p + 0x2b8) = 8;
            }
            *(s16*)(p + 0x2ba) = 0;
            *(u8*)(p + 0x2bc) = arg1;
            *(u8*)(p + 0x284) = arg2;
        }
    } else if (arg2 != 6 && arg2 != *(u8*)(p + 0x284)) {
        if (arg2 == 4) {
            *(u16*)(p + 0x2b8) = 0x60;
        } else if (arg2 == 5) {
            *(u16*)(p + 0x2b8) = 3;
        } else {
            *(u16*)(p + 0x2b8) = 8;
        }
        *(s16*)(p + 0x2ba) = 0;
        *(u8*)(p + 0x2bc) = arg1;
        *(u8*)(p + 0x284) = arg2;
    }

    if (*(u16*)(p + 0x2b8) == 0) {
        return 0;
    }

    switch (*(u8*)(p + 0x284)) {
    case 2:
        *(s16*)(p + 0x2ba) += (0x160 - arg3) * 7 + 0xc0;
        break;
    case 3:
        *(s16*)(p + 0x2ba) += arg3 * 7 + 0xc0;
        break;
    case 5:
        *(s16*)(p + 0x2ba) += 0x120;
        break;
    default:
        *(s16*)(p + 0x2ba) += (*(u16*)(p + 0x2b8) << 4) + 0x100;
        break;
    }

    s16 angle = *(s16*)(p + 0x2ba);
    for (int i = 0; i < 160; i++) {
        *(int*)(p + i * 4 + 4) = (int)((f32)*(u16*)(p + 0x2b8) * JMath::sincosTable_.sinShort(angle));
        angle += 0x200;
    }

    if (*(u8*)(p + 0x284) == 0 || *(u8*)(p + 0x284) == 4) {
        *(u16*)(p + 0x2b8) -= 1;
    }

    return (int*)(p + 4);
}

#pragma opt_propagation off
extern "C" int fn_8030B570(u8* p, int* outX, int* outY) {
    int id = fn_8022EA0C(*(int*)(p + 0x288));
    int x;
    int y;

    if (fn_80234950(id)) {
        id = *(int*)(p + 0x2b4);
    }
    if (*(int*)(p + 0x28c) != fn_8023DE58(id)) {
        id = *(int*)(p + 0x2b0);
    }
    if (*(int*)(p + 0x28c) != fn_8023DE58(id)) {
        id = *(int*)(p + 0x288);
    }
    if (fn_8023DE58(id) >= 8) {
        f32* pos = fn_8023E724(id);
        x = (int)pos[0];
        pos = fn_8023E724(id);
        y = (int)pos[1];
        if (fn_80234ECC(id)) {
            pos = fn_8023E724(id);
            y -= (int)pos[2];
        }
    } else {
        u8* a = fn_802D6A9C();
        u8* b = fn_802D6A9C();
        f32* pos = fn_8023E724(id);
        f32 px = pos[0];
        f32 ax = *(f32*)(a + 0xcc);
        f32 bx = *(f32*)(b + 0xdc);
        x = (int)((px - ax) + bx);
        a = fn_802D6A9C();
        b = fn_802D6A9C();
        pos = fn_8023E724(id);
        f32 py = pos[1];
        f32 ay = *(f32*)(a + 0xd0);
        f32 by = *(f32*)(b + 0xe0);
        y = (int)((py - ay) + by);
    }

    y -= 0x50;
    x -= 0x78;
    if (x + 0xf0 >= *(int*)(p + 0x2a0)) {
        x = *(int*)(p + 0x2a0) - 0xf0;
    } else if (x <= *(int*)(p + 0x2a4)) {
        x = *(int*)(p + 0x2a4);
    }
    if (y + 0xa0 >= *(int*)(p + 0x2a8)) {
        y = *(int*)(p + 0x2a8) - 0xa0;
    } else if (y <= *(int*)(p + 0x2ac)) {
        y = *(int*)(p + 0x2ac);
    }

    x += *(int*)(p + 0x298);
    y += *(int*)(p + 0x29c);
    if (x < 0) {
        x = 0;
    } else if (x > 0x110) {
        x = 0x110;
    }
    if (y < 0) {
        y = 0;
    } else if (y > 0x160) {
        y = 0x160;
    }

    *outX = x;
    *outY = y;
    return id;
}
#pragma opt_propagation reset
extern "C" void fn_8030B774(u8* p) {
    int x;
    int y;
    f32 dx;
    f32 dy;
    f32 d2;

    if (fn_8023F264(*(void**)(p + 0x288))) {
        if (*(int*)(p + 0x28c) != fn_8023DE58(*(int*)(p + 0x288))) {
            *(int*)(p + 0x28c) = fn_8023DE58(*(int*)(p + 0x288));
            fn_8030B97C(p);
        }
        *(int*)(p + 0x2b4) = fn_8030B570(p, &x, &y);
        if (*(int*)(p + 0x2b4) != *(int*)(p + 0x2b0)) {
            JGeometry::TVec2<f32> delta;
            delta.x = (f32)(x - *(int*)(p + 0x290));
            delta.y = (f32)(y - *(int*)(p + 0x294));
            dx = delta.x;
            dy = delta.y;
            d2 = delta.squared();
            if (sqrt_guard(d2) > 16.0f) {
                delta.normalize();
                dx = delta.x;
                dy = delta.y;
                *(int*)(p + 0x290) = (int)(16.0f * dx + (f32)*(int*)(p + 0x290));
                *(int*)(p + 0x294) = (int)(16.0f * dy + (f32)*(int*)(p + 0x294));
            } else {
                *(int*)(p + 0x290) = x;
                *(int*)(p + 0x294) = y;
                *(int*)(p + 0x2b0) = *(int*)(p + 0x2b4);
            }
        } else {
            *(int*)(p + 0x290) = x;
            *(int*)(p + 0x294) = y;
        }
    }
}

extern "C" u16 fn_80226850(void* pos, int room);
extern "C" void fn_8030B97C(u8* p) {
    int room = fn_8023DE58(*(int*)(p + 0x288));
    u32 ux;
    u32 uy;
    u16 ret;

    if (room < 8) {
        room = 8;
    }

    JGeometry::TVec3<f32> pos(*(Vec*)fn_8023E724(*(int*)(p + 0x288)));
    ux = (u32)pos.x & ~7;
    uy = (u32)pos.y & ~7;
    pos.set((f32)ux, (f32)uy, 0.0f);

    for (int i = 0; i < 0x40; i++) {
        if (pos.x >= 512.0f) {
            pos.x = 512.0f;
            break;
        }
        ret = fn_80226850(&pos, room);
        if (ret >= 8 && ret < 0x10 && (ret & 1)) {
            break;
        }
        pos.x += 8.0f;
    }
    *(int*)(p + 0x2a0) = (int)pos.x;
    if (*(int*)(p + 0x2a0) < 0xf0) {
        *(int*)(p + 0x2a0) = 0xf0;
    }

    pos.x = (f32)ux;
    for (int i = 0; i < 0x40; i++) {
        if (pos.x < 8.0f) {
            pos.x = 0.0f;
            break;
        }
        ret = fn_80226850(&pos, room);
        if (ret >= 8 && ret < 0x10 && (ret & 1)) {
            pos.x += 8.0f;
            break;
        }
        pos.x -= 8.0f;
    }
    *(int*)(p + 0x2a4) = (int)pos.x;
    if (*(int*)(p + 0x2a4) < 0) {
        *(int*)(p + 0x2a4) = 0;
    }
    if (*(int*)(p + 0x2a0) - *(int*)(p + 0x2a4) < 0xf0) {
        *(int*)(p + 0x2a4) = *(int*)(p + 0x2a0) - 0xf0;
    }

    pos.set((f32)ux, (f32)uy, 0.0f);
    for (int i = 0; i < 0x40; i++) {
        if (pos.y >= 512.0f) {
            pos.y = 512.0f;
            break;
        }
        ret = fn_80226850(&pos, room);
        if (ret >= 8 && ret < 0x10 && (ret & 1)) {
            break;
        }
        pos.y += 8.0f;
    }
    *(int*)(p + 0x2a8) = (int)pos.y;
    if (*(int*)(p + 0x2a8) < 0xa0) {
        *(int*)(p + 0x2a8) = 0xa0;
    }

    pos.y = (f32)uy;
    for (int i = 0; i < 0x40; i++) {
        if (pos.y < 8.0f) {
            pos.y = 0.0f;
            break;
        }
        ret = fn_80226850(&pos, room);
        if (ret >= 8 && ret < 0x10 && (ret & 1)) {
            pos.y += 8.0f;
            break;
        }
        pos.y -= 8.0f;
    }
    *(int*)(p + 0x2ac) = (int)pos.y;
    if (*(int*)(p + 0x2ac) < 0) {
        *(int*)(p + 0x2ac) = 0;
    }
    if (*(int*)(p + 0x2a8) - *(int*)(p + 0x2ac) < 0xa0) {
        *(int*)(p + 0x2ac) = *(int*)(p + 0x2a8) - 0xa0;
    }
}

extern "C" int fn_8023DE58(int);
extern "C" void fn_8030B97C(u8*);
extern "C" int fn_8030B570(u8*, int*, int*);
extern "C" void fn_8030BD3C(u8* p, int id)
{
    *(int*)(p + 0x288) = id;
    if (*(int*)(p + 0x2b0) < 0) {
        *(int*)(p + 0x2b0) = *(int*)(p + 0x288);
    }
    *(int*)(p + 0x28c) = fn_8023DE58(id);
    fn_8030B97C(p);
    *(int*)(p + 0x2b4) = fn_8030B570(p, (int*)(p + 0x290), (int*)(p + 0x294));
    *(int*)(p + 0x298) = 0;
    *(int*)(p + 0x29c) = 0;
}

extern u8 lbl_804AA8D8[];
extern "C" u8* fn_8030BDB0(u8* p, s16 del)
{
    if (p != 0) {
        *(u8**)p = lbl_804AA8D8;
        if (del > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void fn_8030BDF8(u8* p)
{
    *(u8**)p = lbl_804AA8D8;
    *(int*)(p + 0x28c) = 0;
    *(int*)(p + 0x2b4) = -1;
    *(int*)(p + 0x2b0) = -1;
    *(int*)(p + 0x288) = -1;
    *(s16*)(p + 0x2b8) = 0;
    *(s16*)(p + 0x2ba) = 0;
    *(u8*)(p + 0x2bc) = 0xff;
    *(u8*)(p + 0x284) = 0;
}

void fn_8030BE34(void) {}

