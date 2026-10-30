#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"
struct Tu8030FEB8Rect { f32 x0, y0, x1, y1; };
struct Tu8030FEB8Vec3 { f32 x, y; f32 z; };


extern "C" char lbl_804AAA70[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_8030FD60(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804AAA70;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void fn_8030FDC0(char* p, s32 v) {
    *(s32*)(p + 0x25c) = v;
    *(s32*)(p + 0x234) = 0x3c;
    *(s32*)(p + 0x230) = 6;
}

extern "C" void* fn_801F856C(void);
extern char* lbl_8053AAF8;
extern f32 lbl_8054178C;
extern "C" char lbl_80471420[];
extern "C" f32 lbl_8054177C;
extern "C" void fn_801F06F0(void* a, void* p2, s32 idx, void* p4, s32 p5, f32 f1, f32 f2);
extern "C" void fn_80307AC8(void* obj, u32 id, void* pos, u32 kind, u32 a, u32 b, s32 c);
#pragma opt_propagation off
extern "C" void fn_8030FDD8(char* p) {
    if (*(u8*)(p + 0x288)) {
        fn_801F06F0(p, lbl_80471420, *(s32*)(p + 0x240) + 0x12c, 0, 0, lbl_8054177C, lbl_8054177C);
        fn_80307AC8(*(void**)(p + 0x198), *(u32*)(p + 0x4), p + 0xc, *(s32*)(p + 0x240) + 0x12c, 0, 0, -1);
    } else {
        s32 n = *(s32*)(p + 0x238);
        s32 frame = *(s32*)(p + 0x240);
        n *= 2;
        frame = n + frame;
        frame += 0xec;
        fn_801F06F0(p, lbl_80471420, frame, 0, 0, lbl_8054177C, lbl_8054177C);
        n = *(s32*)(p + 0x238);
        frame = *(s32*)(p + 0x240);
        n *= 2;
        frame = n + frame;
        frame += 0xec;
        fn_80307AC8(*(void**)(p + 0x198), *(u32*)(p + 0x4), p + 0xc, frame, 0, 0, -1);
    }
}
#pragma opt_propagation reset
extern "C" void fn_80239914(void*, s32, s32);
extern "C" void fn_8022FEB8(void*, s32, s32, s32, s32);
extern "C" s32 fn_8022FD8C(s32);
extern "C" u8 fn_802300EC(s32);
extern "C" u8 fn_8038AD24(s32, s32, s32, s32, void*, s32);
extern "C" s32 fn_8022EA0C(s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" void fn_801EE558(void* this_, void* p, f32* len, s32 p4);
extern "C" f32 lbl_80541780;
extern "C" f32 lbl_80541784;
extern "C" void fn_8030FEB8(Actor* this_) {
    u8* self = (u8*)this_;
    Tu8030FEB8Rect rect;
    f32 ang[3];
    f32 tbl[13];
    s32 idx;
    u16 u;

    rect = *(Tu8030FEB8Rect*)(self + 0x60);
    rect.x0 += *(f32*)(self + 0xc);
    rect.y0 += *(f32*)(self + 0x10);
    rect.x1 += *(f32*)(self + 0xc);
    rect.y1 += *(f32*)(self + 0x10);
    fn_80239914(&rect, *(s32*)(self + 4), *(s32*)(self + 0x198));
    if (self[0x288] != 0) {
        *(s32*)(self + 0x244) = *(s32*)(self + 0x244) + 1;
        if (*(s32*)(self + 0x244) >= 0x10) {
            *(s32*)(self + 0x244) = 0;
            *(u32*)(self + 0x240) = *(u32*)(self + 0x240) ^ 1;
        }
    } else {
        if (*(s32*)(self + 0x23c) <= 0) {
            *(s32*)(self + 0x23c) = 0x14;
            idx = *(s32*)(self + 0x248);
            if (idx >= 0) {
                idx = fn_8022EA0C(idx);
            }
            if (idx < 0 || fn_8023DE58(idx) != *(s32*)(self + 4)) {
                fn_801EE558(self, ang, tbl, 0);
            } else {
                fn_801EE558(self, ang, tbl, idx + 1);
            }
            if (tbl[0] < lbl_80541780) {
                u = (s32)(JMath::atanTable_.atan2_(-ang[0], -ang[1]) * lbl_80541784) & 0xffff;
                if (u < 0x2000 || u >= 0xe000) {
                    *(s32*)(self + 0x238) = 3;
                } else if (u < 0x6000) {
                    *(s32*)(self + 0x238) = 1;
                } else if (u <= 0xa000) {
                    *(s32*)(self + 0x238) = 2;
                } else {
                    *(s32*)(self + 0x238) = 0;
                }
            } else {
                *(s32*)(self + 0x238) = 2;
            }
        } else {
            *(s32*)(self + 0x23c) = *(s32*)(self + 0x23c) - 1;
        }
        *(s32*)(self + 0x244) = *(s32*)(self + 0x244) + 1;
        if (*(s32*)(self + 0x244) >= 0x14) {
            *(s32*)(self + 0x244) = 0;
            *(u32*)(self + 0x240) = *(u32*)(self + 0x240) ^ 1;
        }
    }
}

extern "C" void fn_80310904(char* p) {
    s32 n = *(s32*)((char*)fn_801F856C() + 0x1008);
    s32 off = 0;
    char* q = p;
    s32 cnt = 0;
    s32 i = 0;
    for (; i < n; off += 4, i++) {
        char* a = *(char**)((char*)fn_801F856C() + off + 8);
        if (a != 0 && *(s32*)(a + 0x1a0) == 0x474d5442) {
            cnt++;
            *(s32*)(q + 0x250) = i;
            q += 4;
            if (cnt >= 3) {
                break;
            }
        }
    }
    if (cnt == 0) {
        *(u8*)(p + 0x11c) = 0;
        return;
    }
    *(s32*)(p + 0x24c) = cnt;
    {
        f32 one = lbl_8054177C;
        char* g = lbl_8053AAF8;
        f32 scale = lbl_8054178C;
        u32 bits;
        f32 x;
        s32 sel;
        *(u32*)(g + 0xb4) = *(u32*)(g + 0xb4) * 0x19660du + 0x3c6ef35fu;
        bits = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000u;
        x = *(f32*)&bits;
        sel = (s32)(scale * (x - one));
        switch (sel) {
        case 0: {
            s32 t = *(s32*)(p + 0x250);
            *(s32*)(p + 0x250) = *(s32*)(p + 0x254);
            *(s32*)(p + 0x254) = t;
        } break;
        case 1: {
            s32 t = *(s32*)(p + 0x254);
            *(s32*)(p + 0x254) = *(s32*)(p + 0x258);
            *(s32*)(p + 0x258) = t;
        } break;
        case 2: {
            s32 t = *(s32*)(p + 0x250);
            *(s32*)(p + 0x250) = *(s32*)(p + 0x258);
            *(s32*)(p + 0x258) = t;
        } break;
        case 3: {
            s32 t = *(s32*)(p + 0x250);
            *(s32*)(p + 0x250) = *(s32*)(p + 0x254);
            *(s32*)(p + 0x254) = *(s32*)(p + 0x258);
            *(s32*)(p + 0x258) = t;
        } break;
        case 4: {
            s32 t = *(s32*)(p + 0x250);
            *(s32*)(p + 0x250) = *(s32*)(p + 0x258);
            *(s32*)(p + 0x258) = *(s32*)(p + 0x254);
            *(s32*)(p + 0x254) = t;
        } break;
        case 5:
            break;
        }
    }
}

extern f32 lbl_80541790;
extern f32 lbl_80541794;
extern char* lbl_8053AAF8;
extern u8 lbl_80529DEC[];
extern "C" void fn_80310A9C(char* p)
{
    const f32 b = lbl_80541794;
    const f32 a = lbl_80541790;

    *(f32*)(p + 0x60) = a;
    *(f32*)(p + 0x64) = a;
    *(f32*)(p + 0x68) = b;
    *(f32*)(p + 0x6c) = b;
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x248) = -1;
    *(s32*)(p + 0x264) = *(u32*)(p + 0x90) >> 31;
    if (*(u32*)(p + 0x264) != 0) {
        *(s32*)(p + 0x260) = 300;
    } else {
        *(s32*)(p + 0x260) = 100;
    }
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = -1;
    *(s32*)(p + 0x254) = -1;
    *(s32*)(p + 0x258) = -1;
    *(u32*)(p + 0x26c) = *(u32*)(p + 0x90) & 0xf;
    *(u32*)(p + 0x270) = *(u32*)(p + 0x26c) + ((*(u32*)(p + 0x90) >> 4) & 0xf);
    *(u32*)(p + 0x274) = *(u32*)(p + 0x270) + ((*(u32*)(p + 0x90) >> 8) & 0xf);
    *(s32*)(p + 0x25c) = -1;
    *(u32*)(p + 0x268) = (*(u32*)(p + 0x90) >> 24) & 0xf;
    *(s32*)(p + 0x278) = 0;
    *(s32*)(p + 0x27c) = 0;
    *(s32*)(p + 0x280) = 0;
    *(s32*)(p + 0x284) = 0;
    if (*(u8*)(lbl_8053AAF8 + 0x7f) != 0 && *(s32*)(lbl_80529DEC + 0x118) == 1 && *(s32*)(lbl_80529DEC + 0x11c) == 1) {
        *(u8*)(p + 0x288) = 1;
    } else {
        *(u8*)(p + 0x288) = 0;
    }
    *(s32*)(p + 0x238) = 2;
    *(s32*)(p + 0x23c) = 0x14;
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x244) = 0;
}

extern "C" void fn_80310BC4(void) {
}

