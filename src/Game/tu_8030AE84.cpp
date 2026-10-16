#include "types.h"


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

