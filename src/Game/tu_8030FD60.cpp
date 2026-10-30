#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"
struct Tu8030FEB8Rect { f32 x0, y0, x1, y1; };
struct Tu8030FEB8Counts { u8 pad[0x278]; u32 cnt[4]; };
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
extern "C" u8 fn_8038AD24(s32, s32, s32, s32, JGeometry::TVec3<f32>, s32);
extern "C" s32 fn_8022EA0C(s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" void fn_801EE558(void* this_, void* p, f32* len, s32 p4);
extern "C" f32 lbl_80541780;
extern "C" f32 lbl_80541784;
extern "C" void fn_8022FF8C(s32, void*, s32, s32, s32, s32);
extern "C" s32 fn_8022F340(s32);
extern "C" u8 fn_803865B8(s32);
extern "C" s32 fn_8037EFB4(s32);
extern "C" s32 fn_80236228(s32);
extern "C" u8 fn_8038470C(s32, s32);
extern "C" void fn_802362C4(s32, s32);
extern "C" u8 fn_80388CAC(s32, s32);
extern "C" void fn_80310F50(void*, s32, s32, s32);
extern "C" void fn_80310E48(void*);
extern "C" void fn_80310E98(void*);
extern "C" u8 fn_8038BD08(s32, s32, s32, JGeometry::TVec3<f32>, s32);
extern "C" s32 lbl_804713C0[][3];
extern "C" f32 lbl_80541788;
extern "C" f32 lbl_80541778;
#pragma opt_propagation off
extern "C" void fn_8030FEB8(u8* self) {
    Tu8030FEB8Rect rect;
    f32 ang[3];
    f32 len;
    s32 slot;
    s32 room;
    s32 player;
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
            s32 cur = *(s32*)(self + 0x248);
            player = cur;
            if (cur >= 0) {
                player = fn_8022EA0C(cur);
            }
            if (player < 0 || (room = *(s32*)(self + 4), room != fn_8023DE58(player))) {
                fn_801EE558(self, ang, &len, 0);
            } else {
                fn_801EE558(self, ang, &len, player + 1);
            }
            if (len >= lbl_80541780) {
                *(s32*)(self + 0x238) = 2;
            } else {
                f32 a = JMath::atanTable_.atan2_(-ang[0], -ang[1]);
                u = (s32)(a * lbl_80541784) & 0xffff;
                if (u < 0x2000 || u >= 0xe000) {
                    *(s32*)(self + 0x238) = 3;
                } else if (u >= 0x2000 && u < 0x6000) {
                    *(s32*)(self + 0x238) = 1;
                } else if (u >= 0x6000 && u <= 0xa000) {
                    *(s32*)(self + 0x238) = 2;
                } else {
                    *(s32*)(self + 0x238) = 0;
                }
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

    switch (*(u32*)(self + 0x230)) {
    case 0: {
        s32 id;
        fn_8022FEB8(&rect, *(s32*)(self + 4), *(s32*)(self + 0x198), 1, 0);
        slot = fn_8022FD8C(*(s32*)(self + 0x198));
        if (slot < 0) break;
        if (!fn_802300EC(slot)) break;
        if (((Tu8030FEB8Counts*)self)->cnt[fn_8022F340(slot)] < *(u32*)(self + 0x268)) {
            if (self[0x288] != 0) {
                id = 0x583;
            } else if (*(u32*)(self + 0x264) != 0) {
                id = 0x6f5;
            } else {
                id = 0x6ff;
            }
            s32 h = *(s32*)(self + 0x198);
            s32 rm = *(s32*)(self + 4);
            if (fn_8038AD24(slot, id, h, rm, *(JGeometry::TVec3<f32>*)(self + 0xc), 0x28)) {
                *(s32*)(self + 0x248) = slot;
                *(s32*)(self + 0x230) = 1;
            }
        } else {
            id = 0x6fb;
            if (self[0x288] != 0) {
                id = 0x5af;
            }
            s32 h = *(s32*)(self + 0x198);
            s32 rm = *(s32*)(self + 4);
            if (fn_8038AD24(slot, id, h, rm, *(JGeometry::TVec3<f32>*)(self + 0xc), 0x28)) {
                *(s32*)(self + 0x248) = slot;
                *(s32*)(self + 0x230) = 8;
            }
        }
        break;
    }
    case 1: {
        s32 id;
        fn_8022FF8C(*(s32*)(self + 0x248), &rect, *(s32*)(self + 4), *(s32*)(self + 0x198), 1, 0);
        if (!fn_803865B8(*(s32*)(self + 0x248))) break;
        if (fn_8037EFB4(*(s32*)(self + 0x248)) == 0) {
            if (fn_80236228(*(s32*)(self + 0x248)) >= *(s32*)(self + 0x260)) {
                if (!fn_8038470C(*(s32*)(self + 0x248), self[0x288] != 0 ? 0x5ac : 0x700)) break;
                fn_802362C4(*(s32*)(self + 0x248), -*(s32*)(self + 0x260));
                *(s32*)(self + 0x230) = 3;
                break;
            }
            if (self[0x288] != 0) {
                id = 0x5ae;
            } else if (*(u32*)(self + 0x264) != 0) {
                id = 0x6f6;
            } else {
                id = 0x702;
            }
            if (!fn_8038470C(*(s32*)(self + 0x248), id)) break;
            *(s32*)(self + 0x230) = 2;
            break;
        }
        if (!fn_8038470C(*(s32*)(self + 0x248), self[0x288] != 0 ? 0x5ad : 0x701)) break;
        *(s32*)(self + 0x230) = 2;
        break;
    }
    case 2:
        fn_8022FF8C(*(s32*)(self + 0x248), &rect, *(s32*)(self + 4), *(s32*)(self + 0x198), 1, 0);
        if (fn_80388CAC(*(s32*)(self + 0x248), *(s32*)(self + 0x198))) {
            *(s32*)(self + 0x248) = -1;
            *(s32*)(self + 0x230) = 0;
        }
        break;
    case 3: {
        u8* q;
        s32 id;
        s32* tb;
        s32 k;
        s32 sel;
        fn_8022FF8C(*(s32*)(self + 0x248), &rect, *(s32*)(self + 4), *(s32*)(self + 0x198), 1, 0);
        if (!fn_80388CAC(*(s32*)(self + 0x248), *(s32*)(self + 0x198))) break;
        *(s32*)(self + 0x248) = fn_8022F340(*(s32*)(self + 0x248));
        {
            f32 one = lbl_8054177C;
            char* g = lbl_8053AAF8;
            f32 scale = lbl_80541788;
            u32 bits;
            f32 x;
            u32 r;
            *(u32*)(g + 0xb4) = *(u32*)(g + 0xb4) * 0x19660du + 0x3c6ef35fu;
            bits = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000u;
            x = *(f32*)&bits;
            r = (s32)(scale * (x - one));
            if (r <= *(u32*)(self + 0x26c)) {
                sel = 0;
            } else if (r <= *(u32*)(self + 0x270)) {
                sel = 1;
            } else if (r <= *(u32*)(self + 0x274)) {
                sel = 2;
            } else {
                sel = 3;
            }
        }
        tb = lbl_804713C0[sel | (*(u32*)(self + 0x264) << 2)];
        q = self;
        for (k = 0; k < *(s32*)(self + 0x24c); q += 4, tb++, k++) {
            id = *(s32*)(q + 0x250);
            u8* a = *(u8**)((u8*)fn_801F856C() + id * 4 + 8);
            if (a != 0 && *(s32*)(a + 0x1a0) == 0x474d5442) {
                fn_80310F50(a, *(s32*)(self + 0x248), *tb, *(s32*)(self + 0x198));
            }
        }
        ((Tu8030FEB8Counts*)self)->cnt[*(s32*)(self + 0x248)]++;
        *(s32*)(self + 0x230) = 4;
        break;
    }
    case 4: {
        s32 n;
        u8* q;
        s32 k;
        s32 id;
        player = fn_8022EA0C(*(s32*)(self + 0x248));
        room = *(s32*)(self + 4);
        if (room != fn_8023DE58(player)) {
            q = self;
            for (k = 0; k < *(s32*)(self + 0x24c); q += 4, k++) {
                n = *(s32*)(q + 0x250);
                u8* a = *(u8**)((u8*)fn_801F856C() + n * 4 + 8);
                if (a != 0 && *(s32*)(a + 0x1a0) == 0x474d5442) {
                    fn_80310E48(a);
                }
            }
            *(s32*)(self + 0x248) = -1;
            *(s32*)(self + 0x230) = 0;
            break;
        }
        fn_8022FF8C(player, &rect, *(s32*)(self + 4), *(s32*)(self + 0x198), 1, 0);
        if (player != fn_8022FD8C(*(s32*)(self + 0x198))) break;
        if (!fn_802300EC(player)) break;
        id = 0x700;
        if (self[0x288] != 0) {
            id = 0x5ac;
        }
        s32 h = *(s32*)(self + 0x198);
        s32 rm = *(s32*)(self + 4);
        if (fn_8038AD24(player, id, h, rm, *(JGeometry::TVec3<f32>*)(self + 0xc), 0x28)) {
            *(s32*)(self + 0x248) = player;
            *(s32*)(self + 0x230) = 5;
        }
        break;
    }
    case 5:
        fn_8022FF8C(*(s32*)(self + 0x248), &rect, *(s32*)(self + 4), *(s32*)(self + 0x198), 1, 0);
        if (fn_80388CAC(*(s32*)(self + 0x248), *(s32*)(self + 0x198))) {
            *(s32*)(self + 0x248) = fn_8022F340(*(s32*)(self + 0x248));
            *(s32*)(self + 0x230) = 4;
        }
        break;
    case 6: {
        s32 n;
        u8* q;
        s32 k;
        s32 id;
        if (*(s32*)(self + 0x234) > 0) {
            *(s32*)(self + 0x234) = *(s32*)(self + 0x234) - 1;
            break;
        }
        if (*(u32*)(self + 0x264) != 0) {
            switch (*(s32*)(self + 0x25c)) {
            case 1: id = 0x6f8; break;
            case 3: id = 0x6f9; break;
            case 4: id = 0x6fa; break;
            case 0:
            case 2:
            default: id = 0x6f7; break;
            }
        } else {
            switch (*(s32*)(self + 0x25c)) {
            case 1: id = 0x704; break;
            case 2: id = 0x705; break;
            case 3: id = 0x706; break;
            case 0:
            default: id = 0x703; break;
            }
        }
        slot = fn_8022EA0C(*(s32*)(self + 0x248));
        s32 rm = *(s32*)(self + 4);
        if (!fn_8038BD08(slot, id, rm, *(JGeometry::TVec3<f32>*)(self + 0xc), 0x21)) break;
        q = self;
        for (k = 0; k < *(s32*)(self + 0x24c); q += 4, k++) {
            n = *(s32*)(q + 0x250);
            u8* a = *(u8**)((u8*)fn_801F856C() + n * 4 + 8);
            if (a != 0 && *(s32*)(a + 0x1a0) == 0x474d5442) {
                fn_80310E98(a);
            }
        }
        *(s32*)(self + 0x248) = slot;
        *(s32*)(self + 0x234) = 0x3c;
        *(s32*)(self + 0x230) = 7;
        break;
    }
    case 7: {
        s32 n;
        u8* q;
        s32 k;
        fn_8022FF8C(*(s32*)(self + 0x248), &rect, *(s32*)(self + 4), *(s32*)(self + 0x198), 1, 0);
        if (*(s32*)(self + 0x234) > 0) {
            *(s32*)(self + 0x234) = *(s32*)(self + 0x234) - 1;
            break;
        }
        if (!fn_80388CAC(*(s32*)(self + 0x248), *(s32*)(self + 0x198))) break;
        q = self;
        for (k = 0; k < *(s32*)(self + 0x24c); q += 4, k++) {
            n = *(s32*)(q + 0x250);
            u8* a = *(u8**)((u8*)fn_801F856C() + n * 4 + 8);
            if (a != 0 && *(s32*)(a + 0x1a0) == 0x474d5442) {
                fn_80310E98(a);
            }
        }
        {
            f32 one = lbl_8054177C;
            char* g = lbl_8053AAF8;
            f32 scale = lbl_80541778;
            u32 bits;
            f32 x;
            s32 sel;
            *(u32*)(g + 0xb4) = *(u32*)(g + 0xb4) * 0x19660du + 0x3c6ef35fu;
            bits = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000u;
            x = *(f32*)&bits;
            sel = (s32)(scale * (x - one));
            switch (sel) {
            case 0: {
                s32 t = *(s32*)(self + 0x250);
                *(s32*)(self + 0x250) = *(s32*)(self + 0x254);
                *(s32*)(self + 0x254) = t;
            } break;
            case 1: {
                s32 t = *(s32*)(self + 0x254);
                *(s32*)(self + 0x254) = *(s32*)(self + 0x258);
                *(s32*)(self + 0x258) = t;
            } break;
            case 2:
            default: {
                s32 t = *(s32*)(self + 0x250);
                *(s32*)(self + 0x250) = *(s32*)(self + 0x258);
                *(s32*)(self + 0x258) = t;
            } break;
            }
        }
        *(s32*)(self + 0x248) = -1;
        *(s32*)(self + 0x230) = 0;
        break;
    }
    case 8:
        fn_8022FF8C(*(s32*)(self + 0x248), &rect, *(s32*)(self + 4), *(s32*)(self + 0x198), 1, 0);
        if (fn_80388CAC(*(s32*)(self + 0x248), *(s32*)(self + 0x198))) {
            *(s32*)(self + 0x248) = -1;
            *(s32*)(self + 0x230) = 0;
        }
        break;
    }
}
#pragma opt_propagation reset
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

