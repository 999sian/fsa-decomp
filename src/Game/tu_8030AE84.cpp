#include "types.h"

extern "C" int fn_8022EA0C(int);
extern "C" int fn_8023DE58(int);
extern "C" u8 fn_80234950(void);
extern "C" u8 fn_80234ECC(void);
extern "C" u8* fn_802D6A9C(void);
extern "C" f32* fn_8023E724(int);


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

