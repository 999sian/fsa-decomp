#include "types.h"
#include "sdk/stl/float.h"

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
extern "C" u8 fn_80234950(int id = 0);
extern "C" u8 fn_80234ECC(int id = 0);
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
    if (id >= 8 && id != *(s32*)(p + 0x28c)) {
        return 0;
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
        if ((s32)rect[0] < *(s32*)(p + 0x290) || (s32)rect[0] > *(s32*)(p + 0x290) + 0xf0) {
            return 0;
        }
        if ((s32)rect[2] < *(s32*)(p + 0x290) || (s32)rect[2] > *(s32*)(p + 0x290) + 0xf0) {
            return 0;
        }
        if ((s32)rect[1] < *(s32*)(p + 0x294) || (s32)rect[1] > *(s32*)(p + 0x294) + 0xa0) {
            return 0;
        }
        if ((s32)rect[3] < *(s32*)(p + 0x294) || (s32)rect[3] > *(s32*)(p + 0x294) + 0xa0) {
            return 0;
        }
    }
    return 1;
}

extern "C" int fn_8030B084(u8* p, int idx, f32* pos)
{
    if (idx >= 8 && idx != *(int*)(p + 0x28c)) {
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

    if (fn_8023F264(*(void**)(p + 0x288))) {
        if (id == *(s32*)(p + 0x28c)) {
            if (id < 8) {
                return 1;
            }
            x = (s32)rect[0];
            if (x >= *(s32*)(p + 0x2a4) && x <= *(s32*)(p + 0x2a0)) {
                y = (s32)rect[1];
                if (y >= *(s32*)(p + 0x2ac) && y <= *(s32*)(p + 0x2a8)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

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
        f32 fx = pos[0] - *(f32*)(a + 0xcc);
        x = (int)(*(f32*)(b + 0xdc) + fx);
        a = fn_802D6A9C();
        b = fn_802D6A9C();
        pos = fn_8023E724(id);
        f32 fy = pos[1] - *(f32*)(a + 0xd0);
        y = (int)(*(f32*)(b + 0xe0) + fy);
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
            dy = (f32)(y - *(int*)(p + 0x294));
            dx = (f32)(x - *(int*)(p + 0x290));
            d2 = dx * dx + dy * dy;
            if (sqrt_guard(d2) > 16.0f) {
                if (!(d2 <= 32.0f * FLT_EPSILON)) {
                    f32 inv = rsqrt_guard(d2);
                    dx *= inv;
                    dy *= inv;
                }
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

