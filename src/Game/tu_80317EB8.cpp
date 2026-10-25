#include "Game/Actor.h"

namespace JMath {
    template <int N, typename T>
    class TAtanTable {
    public:
        f32 atan2_(f32, f32) const;
        f32 mTable[1024];
        f32 mTable2[8];
    };
    extern const TAtanTable<1024, f32> atanTable_;
}
struct Tu80317Rect { f32 x0, y0, x1, y1; };
struct Tu80317Vec2 { f32 x, y; };
struct Tu80317Vec3 { Tu80317Vec2 xy; f32 z; };


extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void*, s32);
extern "C" s32 Actor_CreateByID(void*, u32, s32, char*, u32, s32, s32);
extern "C" char lbl_804AAFB8[];
extern "C" void (Actor::*lbl_804AAED4[])();
extern "C" f64 __psq_l(void* ptr, s32 offset, s32 w, s32 i);
extern "C" void __psq_st(f64 v, void* ptr, s32 offset, s32 w, s32 i);
extern "C" void fn_80239914(void*, s32, s32);
extern "C" void fn_8022FEB8(void*, s32, s32, s32, s32);
extern "C" s32 fn_8022FD8C(s32);
extern "C" u8 fn_802300EC(void);
extern "C" void fn_8022FF8C(s32, void*, s32, s32, s32, s32);
extern "C" u8 fn_80388CAC(s32, s32);
extern "C" u8 fn_8038AD24(s32, s32, s32, s32, void*, s32);
extern "C" s32 fn_802D6A9C(void);
extern "C" u8 fn_802D7F40(s32, s32);
extern "C" s32 lbl_804AAF58[];
extern "C" s32 lbl_804AAF70[];
extern "C" u8 fn_802D800C(s32, s32);
extern "C" s32 lbl_804AAF88[];
extern "C" s32 lbl_804AAFA0[];
extern "C" s32 lbl_804AAF40[];
extern "C" u8 lbl_8053A1B0[];
extern "C" u8 fn_8038C678(s32, s32, s32, s32, void*, s32);
extern "C" s32 fn_8023DE58(void);
extern "C" void fn_801EE558(void* this_, void* p, f32* len, s32 p4);
extern const f32 lbl_805418F8;
extern const f32 lbl_805418FC;
extern "C" void __dt__5ActorFv(void* p, int how);
extern "C" Actor* fn_80317EB8(Actor* param_1, s16 param_2)
{
    if (param_1 != 0) {
        *(void**)param_1 = lbl_804AAFB8;
        __dt__5ActorFv(param_1, 0);
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_80317F18(Actor* this_)
{
    u8* self = (u8*)this_;
    Tu80317Rect rect;
    Tu80317Vec3 vec;
    s32 idx;
    u8 ok;

    rect = *(Tu80317Rect*)(self + 0x60);
    rect.x0 += *(f32*)(self + 0xc);
    rect.y0 += *(f32*)(self + 0x10);
    rect.x1 += *(f32*)(self + 0xc);
    rect.y1 += *(f32*)(self + 0x10);
    fn_80239914(&rect, *(s32*)(self + 4), *(s32*)(self + 0x198));

    if ((fn_802D800C(fn_802D6A9C(), 0x1e) == 0 && *(s32*)(self + 0x264) == 2) || fn_802D800C(fn_802D6A9C(), 0x1e) == 1) {
        *(u64*)&rect = *(u64*)(self + 0x248);
        *((u64*)&rect + 1) = *(u64*)(self + 0x250);
        rect.x0 += *(f32*)(self + 0xc);
        rect.y0 += *(f32*)(self + 0x10);
        rect.x1 += *(f32*)(self + 0xc);
        rect.y1 += *(f32*)(self + 0x10);

        if (*(s32*)(self + 0x230) != 1) {
            fn_8022FEB8(&rect, *(s32*)(self + 4), *(s32*)(self + 0x198), 1, 0);
            idx = fn_8022FD8C(*(s32*)(self + 0x198));
            if (idx >= 0 && fn_802300EC()) {
                *(f64*)&vec = *(f64*)(self + 0xc);
                vec.z = *(f32*)(self + 0x14);
                if (fn_8038AD24(idx, *(s32*)(self + 0x244), *(s32*)(self + 0x198), *(s32*)(self + 4), &vec, 0x10)) {
                    *(s32*)(self + 0x234) = idx;
                    *(s32*)(self + 0x230) = 1;
                    ok = 1;
                } else {
                    ok = 0;
                }
                if (ok) {
                    if (fn_802D800C(fn_802D6A9C(), 0x1e) == 0) {
                        idx = *(s32*)(self + 0x258);
                        if (idx >= 0) {
                            u8* p = (u8*)fn_801F666C(fn_801F856C(), idx);
                            if (p != 0 && *(u32*)(p + 0x1a0) == 0x534e5043) {
                                s32 k = *(s32*)(p + 0x238);
                                if (k == 6 || k == 7 || k == 0 || k == 8) {
                                    *(s32*)(p + 0x264) = 3;
                                }
                            }
                        }
                    }
                }
            }
        } else {
            fn_8022FF8C(*(s32*)(self + 0x234), &rect, *(s32*)(self + 4), *(s32*)(self + 0x198), 1, 0);
            if (fn_80388CAC(*(s32*)(self + 0x234), *(s32*)(self + 0x198))) {
                *(s32*)(self + 0x234) = -1;
                *(s32*)(self + 0x230) = 0;
                if (fn_802D800C(fn_802D6A9C(), 0x1f) == 0) {
                    idx = *(s32*)(self + 0x258);
                    if (idx >= 0) {
                        u8* p = (u8*)fn_801F666C(fn_801F856C(), idx);
                        if (p != 0 && *(u32*)(p + 0x1a0) == 0x534e5043) {
                            s32 k = *(s32*)(p + 0x238);
                            if (k == 6 || k == 7 || k == 0 || k == 8) {
                                *(s32*)(p + 0x264) = 2;
                            }
                        }
                    }
                }
            }
        }
    }

    *(s32*)(self + 0x260) = *(s32*)(self + 0x260) - 1;
    if (*(s32*)(self + 0x260) <= 0) {
        if (*(s32*)(self + 0x264) == 2) {
            *(s32*)(self + 0x25c) = lbl_804AAF88[*(s32*)(self + 0x25c)];
        } else {
            *(s32*)(self + 0x25c) = lbl_804AAFA0[*(s32*)(self + 0x25c)];
        }
        if (*(s32*)(self + 0x25c) < 4) {
            *(s32*)(self + 0x260) = 0x14;
        } else {
            *(s32*)(self + 0x260) = 8;
        }
    }
}

extern "C" void fn_8031825C(Actor* this_) {
    u8* self = (u8*)this_;
    Tu80317Rect rect;
    Tu80317Vec3 vec;
    s32 r;
    Actor* p;
    u8 ok;

    rect = *(Tu80317Rect*)(self + 0x60);
    rect.x0 += *(f32*)(self + 0xc);
    rect.y0 += *(f32*)(self + 0x10);
    rect.x1 += *(f32*)(self + 0xc);
    rect.y1 += *(f32*)(self + 0x10);
    fn_80239914(&rect, *(s32*)(self + 4), *(s32*)(self + 0x198));

    if (fn_802D800C(fn_802D6A9C(), 0x1f) != 0 || *(s32*)(self + 0x264) != 2) {
        if (fn_802D800C(fn_802D6A9C(), 0x1f) != 1) {
            goto tail;
        }
    }

    *(u64*)&rect = *(u64*)(self + 0x248);
    *((u64*)&rect + 1) = *(u64*)(self + 0x250);
    rect.x0 += *(f32*)(self + 0xc);
    rect.y0 += *(f32*)(self + 0x10);
    rect.x1 += *(f32*)(self + 0xc);
    rect.y1 += *(f32*)(self + 0x10);

    if (*(s32*)(self + 0x230) != 1) {
        fn_8022FEB8(&rect, *(s32*)(self + 4), *(s32*)(self + 0x198), 1, 0);
        r = fn_8022FD8C(*(s32*)(self + 0x198));
        if (r < 0) {
            goto tail;
        }
        if (!fn_802300EC()) {
            goto tail;
        }
        vec = *(Tu80317Vec3*)(self + 0xc);
        ok = 0;
        if (fn_8038AD24(r, *(s32*)(self + 0x244), *(s32*)(self + 0x198), *(s32*)(self + 4), &vec, 0x10)) {
            *(s32*)(self + 0x234) = r;
            *(s32*)(self + 0x230) = 1;
            ok = 1;
        }
        if (!ok) {
            goto tail;
        }

        if (fn_802D800C(fn_802D6A9C(), 0x1f) != 0) {
            goto tail;
        }
        r = *(s32*)(self + 0x258);
        if (r < 0) {
            goto tail;
        }
        p = (Actor*)fn_801F666C(fn_801F856C(), r);
        if (p == 0) {
            goto tail;
        }
        if ((u32)*(s32*)((u8*)p + 0x1a0) != 0x534e5043) {
            goto tail;
        }
        if ((u32)*(s32*)((u8*)p + 0x238) == 6 || (u32)*(s32*)((u8*)p + 0x238) == 7 || (u32)*(s32*)((u8*)p + 0x238) == 0 || (u32)*(s32*)((u8*)p + 0x238) == 8) {
            *(s32*)((u8*)p + 0x264) = 3;
        }
    } else {
        fn_8022FF8C(*(s32*)(self + 0x234), &rect, *(s32*)(self + 4), *(s32*)(self + 0x198), 1, 0);
        if (!fn_80388CAC(*(s32*)(self + 0x234), *(s32*)(self + 0x198))) {
            goto tail;
        }
        *(s32*)(self + 0x234) = -1;
        *(s32*)(self + 0x230) = 0;
        if (fn_802D800C(fn_802D6A9C(), 0x1e) != 0) {
            goto tail;
        }
        r = *(s32*)(self + 0x258);
        if (r < 0) {
            goto tail;
        }
        p = (Actor*)fn_801F666C(fn_801F856C(), r);
        if (p == 0) {
            goto tail;
        }
        if ((u32)*(s32*)((u8*)p + 0x1a0) != 0x534e5043) {
            goto tail;
        }
        if ((u32)*(s32*)((u8*)p + 0x238) == 6 || (u32)*(s32*)((u8*)p + 0x238) == 7 || (u32)*(s32*)((u8*)p + 0x238) == 0 || (u32)*(s32*)((u8*)p + 0x238) == 8) {
            *(s32*)((u8*)p + 0x264) = 2;
        }
    }

tail:
    *(s32*)(self + 0x260) = *(s32*)(self + 0x260) - 1;
    if (*(s32*)(self + 0x260) > 0) {
        return;
    }
    if (*(s32*)(self + 0x264) == 2) {
        *(s32*)(self + 0x25c) = lbl_804AAF58[*(s32*)(self + 0x25c)];
    } else {
        *(s32*)(self + 0x25c) = lbl_804AAF70[*(s32*)(self + 0x25c)];
    }
    if (*(s32*)(self + 0x25c) == 2 || *(s32*)(self + 0x25c) == 5) {
        *(s32*)(self + 0x260) = 8;
    } else {
        *(s32*)(self + 0x260) = 10;
    }
}

extern "C" void fn_803185A8(Actor* this_)
{
    u8* self = (u8*)this_;
    Tu80317Rect rect;
    Tu80317Vec3 vec;
    s32 r;

    rect = *(Tu80317Rect*)(self + 0x60);
    rect.x0 += *(f32*)(self + 0xc);
    rect.y0 += *(f32*)(self + 0x10);
    rect.x1 += *(f32*)(self + 0xc);
    rect.y1 += *(f32*)(self + 0x10);
    fn_80239914(&rect, *(s32*)(self + 4), *(s32*)(self + 0x198));

    *(u64*)&rect = *(u64*)(self + 0x248);
    *((u64*)&rect + 1) = *(u64*)(self + 0x250);
    rect.x0 += *(f32*)(self + 0xc);
    rect.y0 += *(f32*)(self + 0x10);
    rect.x1 += *(f32*)(self + 0xc);
    rect.y1 += *(f32*)(self + 0x10);

    if (*(s32*)(self + 0x230) != 1) {
        fn_8022FEB8(&rect, *(s32*)(self + 4), *(s32*)(self + 0x198), 1, 0);
        r = fn_8022FD8C(*(s32*)(self + 0x198));
        if (r >= 0 && fn_802300EC()) {
            *(f64*)&vec = *(f64*)(self + 0xc);
            vec.z = *(f32*)(self + 0x14);
            if (fn_8038AD24(r, *(s32*)(self + 0x244), *(s32*)(self + 0x198), *(s32*)(self + 4), &vec, 0x10)) {
                *(s32*)(self + 0x234) = r;
                *(s32*)(self + 0x230) = 1;
            }
        }
    } else {
        fn_8022FF8C(*(s32*)(self + 0x234), &rect, *(s32*)(self + 4), *(s32*)(self + 0x198), 1, 0);
        if (fn_80388CAC(*(s32*)(self + 0x234), *(s32*)(self + 0x198))) {
            *(s32*)(self + 0x234) = -1;
            *(s32*)(self + 0x230) = 0;
        }
    }

    *(s32*)(self + 0x260) = *(s32*)(self + 0x260) + 1;
    if ((*(s32*)(self + 0x25c) < 2 && *(s32*)(self + 0x260) >= 0x10) ||
        (*(s32*)(self + 0x25c) >= 2 && *(s32*)(self + 0x260) >= 0xa)) {
        *(s32*)(self + 0x260) = 0;
        if (fn_802D7F40(fn_802D6A9C(), 2) == 0) {
            *(s32*)(self + 0x264) = *(s32*)(self + 0x264) + 1;
            if (*(s32*)(self + 0x264) >= 6) {
                *(s32*)(self + 0x264) = 0;
            }
            *(s32*)(self + 0x25c) = lbl_804AAF40[*(s32*)(self + 0x264)];
        } else {
            *(s32*)(self + 0x25c) = *(s32*)(self + 0x25c) + 1;
            *(s32*)(self + 0x25c) = *(s32*)(self + 0x25c) & 1;
        }
    }
}

extern "C" void fn_803187F4(Actor* this_)
{
    u8* self = (u8*)this_;
    Tu80317Rect rect;
    Tu80317Vec3 vec;
    Tu80317Vec2 dir;
    f32 len;
    s32 handle;
    bool ok;

    rect = *(Tu80317Rect*)(self + 0x60);
    rect.x0 += *(f32*)(self + 0xc);
    rect.y0 += *(f32*)(self + 0x10);
    rect.x1 += *(f32*)(self + 0xc);
    rect.y1 += *(f32*)(self + 0x10);
    fn_80239914(&rect, *(s32*)(self + 0x4), *(s32*)(self + 0x198));
    *(u64*)&rect.x0 = *(u64*)(self + 0x248);
    *(u64*)&rect.x1 = *(u64*)(self + 0x250);
    rect.x0 += *(f32*)(self + 0xc);
    rect.y0 += *(f32*)(self + 0x10);
    rect.x1 += *(f32*)(self + 0xc);
    rect.y1 += *(f32*)(self + 0x10);

    if (*(s32*)(self + 0x230) != 1)
    {
        if (*(s32*)(self + 0x268) <= 0)
        {
            *(s32*)(self + 0x268) = 0x14;
            if (*(s32*)(self + 0x234) < 0 || fn_8023DE58() != *(s32*)(self + 0x4))
            {
                fn_801EE558(this_, &dir, &len, 0);
            }
            else
            {
                fn_801EE558(this_, &dir, &len, *(s32*)(self + 0x234) + 1);
            }
            if (len >= lbl_805418F8)
            {
                *(s32*)(self + 0x264) = 2;
            }
            else
            {
                u16 angle = (u16)(s32)(JMath::atanTable_.atan2_(-dir.x, -dir.y) * lbl_805418FC);
                if (angle < 0x2000 || angle >= 0xe000)
                {
                    *(s32*)(self + 0x264) = 3;
                }
                else if (angle < 0x6000)
                {
                    *(s32*)(self + 0x264) = 1;
                }
                else if (angle <= 0xa000)
                {
                    *(s32*)(self + 0x264) = 2;
                }
                else
                {
                    *(s32*)(self + 0x264) = 0;
                }
            }
        }
        else
        {
            *(s32*)(self + 0x268) = *(s32*)(self + 0x268) - 1;
        }
        if (*(s32*)(self + 0x264) != 3)
        {
            fn_8022FEB8(&rect, *(s32*)(self + 0x4), *(s32*)(self + 0x198), 1, 0);
            handle = fn_8022FD8C(*(s32*)(self + 0x198));
            ok = false;
            if (handle >= 0 && fn_802300EC())
            {
                s32 anim = fn_802D7F40(fn_802D6A9C(), 1) == 1 ? 0x578 : 0x577;
                *(s32*)(self + 0x244) = anim;
                vec = *(Tu80317Vec3*)(self + 0xc);
                ok = fn_8038AD24(handle, *(s32*)(self + 0x244), *(s32*)(self + 0x198), *(s32*)(self + 0x4), &vec, 0x10);
                if (ok)
                {
                    *(s32*)(self + 0x234) = handle;
                    *(s32*)(self + 0x230) = 1;
                }
            }
            if (ok)
            {
                *(u32*)(self + 0x25c) = *(u32*)(self + 0x25c) & 1;
                *(u32*)(self + 0x25c) = *(u32*)(self + 0x25c) | (*(s32*)(self + 0x264) << 1);
            }
        }
        if (*(s32*)(self + 0x230) == 0)
        {
            *(s32*)(self + 0x264) = 2;
            *(s32*)(self + 0x268) = 0;
        }
    }
    else
    {
        fn_8022FF8C(*(s32*)(self + 0x234), &rect, *(s32*)(self + 0x4), *(s32*)(self + 0x198), 1, 0);
        if (fn_80388CAC(*(s32*)(self + 0x234), *(s32*)(self + 0x198)))
        {
            *(s32*)(self + 0x234) = -1;
            *(s32*)(self + 0x230) = 0;
            *(s32*)(self + 0x264) = 2;
            *(s32*)(self + 0x268) = 0;
            *(u32*)(self + 0x25c) = *(u32*)(self + 0x25c) & 1;
            *(u32*)(self + 0x25c) = *(u32*)(self + 0x25c) + 4;
        }
    }

    *(s32*)(self + 0x260) = *(s32*)(self + 0x260) + 1;
    if (*(s32*)(self + 0x260) >= 0x18)
    {
        *(s32*)(self + 0x260) = 0;
        *(u32*)(self + 0x25c) = *(u32*)(self + 0x25c) ^ 1;
    }
}

extern "C" void fn_80239914(void*, s32, s32);
extern "C" void fn_8022FEB8(void*, s32, s32, s32, s32);
extern "C" s32 fn_8022FD8C(s32);
extern "C" u8 fn_802300EC(void);
extern "C" u8 fn_8038C678(s32, s32, s32, s32, void*, s32);
extern "C" void fn_8022FF8C(s32, void*, s32, s32, s32, s32);
extern "C" u8 fn_80388CAC(s32, s32);
extern "C" f64 __psq_l(void* ptr, s32 offset, s32 w, s32 i);
extern "C" void __psq_st(f64 v, void* ptr, s32 offset, s32 w, s32 i);
extern "C" void fn_80318B84(Actor* this_)
{
    u8* self = (u8*)this_;
    Tu80317Rect rect;
    s32 r;

    rect = *(Tu80317Rect*)(self + 0x60);
    rect.x0 += *(f32*)(self + 0xc);
    rect.y0 += *(f32*)(self + 0x10);
    rect.x1 += *(f32*)(self + 0xc);
    rect.y1 += *(f32*)(self + 0x10);
    fn_80239914(&rect, *(s32*)(self + 4), *(s32*)(self + 0x198));

    *(u64*)&rect = *(u64*)(self + 0x248);
    *((u64*)&rect + 1) = *(u64*)(self + 0x250);
    rect.x0 += *(f32*)(self + 0xc);
    rect.y0 += *(f32*)(self + 0x10);
    rect.x1 += *(f32*)(self + 0xc);
    rect.y1 += *(f32*)(self + 0x10);

    if (*(s32*)(self + 0x230) != 1) {
        fn_8022FEB8(&rect, *(s32*)(self + 4), *(s32*)(self + 0x198), 1, 0);
        r = fn_8022FD8C(*(s32*)(self + 0x198));
        if (r >= 0 && fn_802300EC()) {
            Tu80317Vec3 vec;
            *(f64*)&vec = *(f64*)(self + 0xc);
            vec.z = *(f32*)(self + 0x14);
            if (fn_8038C678(r, *(s32*)(self + 0x244), *(s32*)(self + 0x198), *(s32*)(self + 4), &vec, 0x10)) {
                *(s32*)(self + 0x234) = r;
                *(s32*)(self + 0x230) = 1;
            }
        }
    } else {
        fn_8022FF8C(*(s32*)(self + 0x234), &rect, *(s32*)(self + 4), *(s32*)(self + 0x198), 1, 0);
        if (fn_80388CAC(*(s32*)(self + 0x234), *(s32*)(self + 0x198))) {
            *(s32*)(self + 0x234) = -1;
            *(s32*)(self + 0x230) = 0;
        }
    }

    *(s32*)(self + 0x260) = *(s32*)(self + 0x260) + 1;
    if ((*(s32*)(self + 0x25c) == 0 && *(s32*)(self + 0x260) >= 0x10) ||
        (*(s32*)(self + 0x25c) == 1 && *(s32*)(self + 0x260) >= 0x32)) {
        *(s32*)(self + 0x260) = 0;
        *(s32*)(self + 0x25c) ^= 1;
    }
}

extern "C" void fn_80318D74(char* p) {
    Tu80317Rect rect;
    Tu80317Vec3 vec;
    Tu80317Vec3 dir;
    f32 dist;
    s32 id;
    s32 room;
    u32 u;
    rect = *(Tu80317Rect*)(p + 0x60);
    rect.x0 += *(f32*)(p + 0xc);
    rect.y0 += *(f32*)(p + 0x10);
    rect.x1 += *(f32*)(p + 0xc);
    rect.y1 += *(f32*)(p + 0x10);
    fn_80239914(&rect, *(s32*)(p + 4), *(s32*)(p + 0x198));
    *(u64*)&rect.x0 = *(u64*)(p + 0x248);
    *(u64*)&rect.x1 = *(u64*)(p + 0x250);
    rect.x0 += *(f32*)(p + 0xc);
    rect.y0 += *(f32*)(p + 0x10);
    rect.x1 += *(f32*)(p + 0xc);
    rect.y1 += *(f32*)(p + 0x10);
    if (*(s32*)(p + 0x230) != 1) {
        if (fn_802D7F40(fn_802D6A9C(), 2) == 1) {
            *(u8*)(p + 0x11c) = 0;
            return;
        }
        fn_8022FEB8(&rect, *(s32*)(p + 4), *(s32*)(p + 0x198), 1, 0);
        id = fn_8022FD8C(*(s32*)(p + 0x198));
        if (id >= 0 && fn_802300EC()) {
            *(f64*)&vec = *(f64*)(p + 0xc);
            vec.z = *(f32*)(p + 0x14);
            if (fn_8038C678(id, *(s32*)(p + 0x244), *(s32*)(p + 0x198), *(s32*)(p + 4), &vec, 0x10)) {
                *(s32*)(p + 0x234) = id;
                *(s32*)(p + 0x230) = 1;
            }
        }
    } else {
        fn_8022FF8C(*(s32*)(p + 0x234), &rect, *(s32*)(p + 4), *(s32*)(p + 0x198), 1, 0);
        if (fn_80388CAC(*(s32*)(p + 0x234), *(s32*)(p + 0x198))) {
            *(s32*)(p + 0x234) = -1;
            *(s32*)(p + 0x230) = 0;
        }
    }
    if (*(u32*)(p + 0x23c) == 1) {
        *(s32*)(p + 0x260) += 1;
        if (*(s32*)(p + 0x260) >= 8) {
            *(s32*)(p + 0x260) = 0;
            *(s32*)(p + 0x25c) ^= 1;
        }
    } else {
        *(s32*)(p + 0x260) -= 1;
        if (*(s32*)(p + 0x260) <= 0) {
            *(s32*)(p + 0x25c) ^= 1;
            *(s32*)(p + 0x260) = lbl_8053A1B0[*(s32*)(p + 0x25c) & 1];
        }
        if (*(s32*)(p + 0x268) <= 0) {
            *(s32*)(p + 0x268) = 0x14;
            id = *(s32*)(p + 0x234);
            if (id < 0) goto no_room;
            room = *(s32*)(p + 4);
            if (fn_8023DE58() == room) goto same_room;
        no_room:
            fn_801EE558(p, &dir, &dist, 0);
            goto room_done;
        same_room:
            fn_801EE558(p, &dir, &dist, *(s32*)(p + 0x234) + 1);
        room_done:;
            if (dist >= lbl_805418F8) {
                *(s32*)(p + 0x264) = 2;
            } else {
                u = (s32)(JMath::atanTable_.atan2_(-dir.xy.x, -dir.xy.y) * lbl_805418FC) & 0xffff;
                if (u < 0x2000 || u > 0xdfff) {
                    *(s32*)(p + 0x264) = 3;
                } else if (u >= 0x2000 && u < 0x6000) {
                    *(s32*)(p + 0x264) = 1;
                } else if (u >= 0x6000 && u <= 0xa000) {
                    *(s32*)(p + 0x264) = 2;
                } else {
                    *(s32*)(p + 0x264) = 0;
                }
            }
        } else {
            *(s32*)(p + 0x268) -= 1;
        }
        *(s32*)(p + 0x25c) = (*(s32*)(p + 0x25c) & 1) + *(s32*)(p + 0x264) * 2;
    }
}

extern "C" void fn_801EE558(void* this_, void* p, f32* len, s32 p4);
extern "C" s32 fn_8023DE58(void);
extern "C" void fn_803190E0(Actor* self)
{
    Tu80317Rect rect;
    Tu80317Vec3 pos;
    u32 ang;
    Tu80317Vec2 dir;
    f32 dist;
    s32 r;

    u8* p = (u8*)self;
    rect = *(Tu80317Rect*)(p + 0x60);
    rect.x0 += *(f32*)(p + 0xc);
    rect.y0 += *(f32*)(p + 0x10);
    rect.x1 += *(f32*)(p + 0xc);
    rect.y1 += *(f32*)(p + 0x10);
    fn_80239914(&rect, *(s32*)(p + 4), *(s32*)(p + 0x198));
    *(u64*)&rect.x0 = *(u64*)(p + 0x248);
    *(u64*)&rect.x1 = *(u64*)(p + 0x250);
    rect.x0 += *(f32*)(p + 0xc);
    rect.y0 += *(f32*)(p + 0x10);
    rect.x1 += *(f32*)(p + 0xc);
    rect.y1 += *(f32*)(p + 0x10);

    if (*(s32*)(p + 0x230) != 1) {
        fn_8022FEB8(&rect, *(s32*)(p + 4), *(s32*)(p + 0x198), 1, 0);
        r = fn_8022FD8C(*(s32*)(p + 0x198));
        if (r >= 0 && fn_802300EC()) {
            pos = *(Tu80317Vec3*)(p + 0xc);
            if (fn_8038C678(r, *(s32*)(p + 0x244), *(s32*)(p + 0x198), *(s32*)(p + 4), &pos, 0x10)) {
                *(s32*)(p + 0x234) = r;
                *(s32*)(p + 0x230) = 1;
            }
        }
    } else {
        fn_8022FF8C(*(s32*)(p + 0x234), &rect, *(s32*)(p + 4), *(s32*)(p + 0x198), 1, 0);
        if (fn_80388CAC(*(s32*)(p + 0x234), *(s32*)(p + 0x198))) {
            *(s32*)(p + 0x234) = -1;
            *(s32*)(p + 0x230) = 0;
        }
    }

    if (*(s32*)(p + 0x23c) == 1) {
        if (*(s32*)(p + 0x268) > 0) {
            *(s32*)(p + 0x268) = *(s32*)(p + 0x268) - 1;
        } else {
            *(s32*)(p + 0x268) = 0x14;
            if (*(s32*)(p + 0x234) < 0 || fn_8023DE58() != *(s32*)(p + 4)) {
                fn_801EE558(self, &dir, &dist, 0);
            } else {
                fn_801EE558(self, &dir, &dist, *(s32*)(p + 0x234) + 1);
            }
            if (dist >= 0.0f) {
                *(s32*)(p + 0x264) = 2;
            } else {
                ang = (s32)(JMath::atanTable_.atan2_(-dir.x, -dir.y) * 10430.378f) & 0xffff;
                if (ang < 0x2000 || ang > 0xdfff) {
                    *(s32*)(p + 0x264) = 3;
                } else if (ang < 0x2000 || ang > 0x5fff) {
                    if (ang < 0x6000 || ang > 0xa000) {
                        *(s32*)(p + 0x264) = 0;
                    } else {
                        *(s32*)(p + 0x264) = 2;
                    }
                } else {
                    *(s32*)(p + 0x264) = 1;
                }
            }
        }
        *(s32*)(p + 0x25c) = *(s32*)(p + 0x264) << 3;
    }
}

extern "C" void fn_803193B4(Actor* this_)
{
    u8* self = (u8*)this_;
    Tu80317Rect rect;
    Tu80317Vec3 vec;
    s32 r;
    s32 idx;
    u32 type;
    u8 ok;
    u8* obj;

    rect = *(Tu80317Rect*)(self + 0x60);
    rect.x0 += *(f32*)(self + 0xc);
    rect.y0 += *(f32*)(self + 0x10);
    rect.x1 += *(f32*)(self + 0xc);
    rect.y1 += *(f32*)(self + 0x10);
    fn_80239914(&rect, *(s32*)(self + 0x4), *(s32*)(self + 0x198));
    if (*(s32*)(self + 0x264) == 2) {
        *(s32*)&rect.x0 = *(s32*)(self + 0x248);
        *(s32*)&rect.y0 = *(s32*)(self + 0x24c);
        *(s32*)&rect.x1 = *(s32*)(self + 0x250);
        *(s32*)&rect.y1 = *(s32*)(self + 0x254);
        rect.x0 += *(f32*)(self + 0xc);
        rect.y0 += *(f32*)(self + 0x10);
        rect.x1 += *(f32*)(self + 0xc);
        rect.y1 += *(f32*)(self + 0x10);
        if (*(s32*)(self + 0x230) == 1) {
            goto mode1;
        }
        fn_8022FEB8(&rect, *(s32*)(self + 0x4), *(s32*)(self + 0x198), 1, 0);
        r = fn_8022FD8C(*(s32*)(self + 0x198));
        if (r < 0) {
            goto tail;
        }
        if (!fn_802300EC()) {
            goto tail;
        }
        vec = *(Tu80317Vec3*)(self + 0xc);
        if (fn_8038C678(r, *(s32*)(self + 0x244), *(s32*)(self + 0x198), *(s32*)(self + 0x4), &vec, 0x10)) {
            *(s32*)(self + 0x234) = r;
            *(s32*)(self + 0x230) = 1;
            ok = 1;
        } else {
            ok = 0;
        }
        if (!ok) {
            goto tail;
        }

        idx = *(s32*)(self + 0x258);
        if (idx < 0) {
            goto tail;
        }
        obj = (u8*)fn_801F666C(fn_801F856C(), idx);
        if (obj == 0) {
            goto tail;
        }
        if (*(s32*)(obj + 0x1a0) != 0x534E5043) {
            goto tail;
        }
        type = *(u32*)(obj + 0x238);
        if (type == 6 || type == 7 || type == 0) {
            goto mode1;
        }
        if (type == 8) {
            *(s32*)(obj + 0x264) = 3;
        }
        goto tail;

    mode1:
        fn_8022FF8C(*(s32*)(self + 0x234), &rect, *(s32*)(self + 0x4), *(s32*)(self + 0x198), 1, 0);
        if (!fn_80388CAC(*(s32*)(self + 0x234), *(s32*)(self + 0x198))) {
            goto tail;
        }
        *(s32*)(self + 0x234) = -1;
        *(s32*)(self + 0x230) = 0;
        idx = *(s32*)(self + 0x258);
        if (idx < 0) {
            goto tail;
        }
        obj = (u8*)fn_801F666C(fn_801F856C(), idx);
        if (obj == 0) {
            goto tail;
        }
        if (*(s32*)(obj + 0x1a0) != 0x534E5043) {
            goto tail;
        }
        type = *(u32*)(obj + 0x238);
        if (type == 6 || type == 7 || type == 0 || type == 8) {
            *(s32*)(obj + 0x264) = 2;
        }
    }

tail:
    *(s32*)(self + 0x260) = *(s32*)(self + 0x260) + 1;
    if (*(s32*)(self + 0x260) >= 0x28) {
        *(s32*)(self + 0x260) = 0;
        *(s32*)(self + 0x25c) = *(s32*)(self + 0x25c) ^ 1;
    }
}

extern "C" s32 fn_802373EC(s32);
extern "C" void fn_801F35AC(Actor* a);
extern "C" void fn_80319658(Actor* this_)
{
    Tu80317Rect rect;
    Tu80317Vec3 pos;
    s32 slot;
    u8* self = (u8*)this_;

    if (*(s32*)(self + 0x264) == 2) {
        rect.x0 = *(f32*)(self + 0x248);
        rect.y0 = *(f32*)(self + 0x24c);
        rect.x1 = *(f32*)(self + 0x250);
        rect.y1 = *(f32*)(self + 0x254);
        rect.x0 = rect.x0 + *(f32*)(self + 0xc);
        rect.y0 = rect.y0 + *(f32*)(self + 0x10);
        rect.x1 = rect.x1 + *(f32*)(self + 0xc);
        rect.y1 = rect.y1 + *(f32*)(self + 0x10);
        if (*(s32*)(self + 0x230) != 1) {
            fn_8022FEB8(&rect, *(s32*)(self + 4), *(s32*)(self + 0x198), 0, 0);
            slot = fn_8022FD8C(*(s32*)(self + 0x198));
            if (slot >= 0 && fn_802300EC() && fn_802373EC(slot) == 6) {
                *(f64*)&pos = *(f64*)(self + 0xc);
                pos.z = *(f32*)(self + 0x14);
                if (fn_8038C678(slot, *(s32*)(self + 0x244), *(s32*)(self + 0x198), *(s32*)(self + 4), &pos, 0x10)) {
                    *(s32*)(self + 0x234) = slot;
                    *(s32*)(self + 0x230) = 1;
                    s32 idx = *(s32*)(self + 0x258);
                    if (idx >= 0) {
                        u8* p = (u8*)fn_801F666C(fn_801F856C(), idx);
                        if (p != 0 && *(u32*)(p + 0x1a0) == 0x534e5043) {
                            s32 k = *(s32*)(p + 0x238);
                            if (k == 6 || k == 7 || k == 0 || k == 8) {
                                *(s32*)(p + 0x264) = 3;
                            }
                        }
                    }
                }
            }
        } else {
            fn_8022FF8C(*(s32*)(self + 0x234), &rect, *(s32*)(self + 4), *(s32*)(self + 0x198), 1, 0);
            if (fn_80388CAC(*(s32*)(self + 0x234), *(s32*)(self + 0x198))) {
                s32 idx = *(s32*)(self + 0x258);
                if (idx >= 0) {
                    u8* p = (u8*)fn_801F666C(fn_801F856C(), idx);
                    if (p != 0 && *(u32*)(p + 0x1a0) == 0x534e5043) {
                        s32 k = *(s32*)(p + 0x238);
                        if (k == 6 || k == 7 || k == 0 || k == 8) {
                            *(s32*)(p + 0x264) = 2;
                        }
                    }
                }
                fn_801F35AC(this_);
            }
        }
    }
}

extern "C" void fn_80319870(Actor* this_)
{
    extern char lbl_80471638[];
    extern f32 lbl_80541900;
    extern void fn_801F06F0(void*, char*, s32, s32, s32, f32, f32);
    extern void fn_80307AC8(void*, s32, void*, s32, s32, s32, s32);
    extern void fn_803075AC(void*, s32, void*, s32, s32, s32, s32, s32, s32, s32);
    char* tbl = lbl_80471638;

    if (*((u8*)this_ + 0x270) != 0) {
        switch (*(s32*)((u8*)this_ + 0x23c) & 3) {
        case 1:
            fn_801F06F0(this_, tbl, *(s32*)((u8*)this_ + 0x26c) + *(s32*)((u8*)this_ + 0x25c), 0, 7, lbl_80541900, lbl_80541900);
            fn_80307AC8(*(void**)((u8*)this_ + 0x198), *(s32*)((u8*)this_ + 4), (u8*)this_ + 0xc, *(s32*)((u8*)this_ + 0x26c) + *(s32*)((u8*)this_ + 0x25c), 0, 0, -1);
            break;
        case 2:
            fn_801F06F0(this_, tbl + 0x14, *(s32*)((u8*)this_ + 0x26c) + *(s32*)((u8*)this_ + 0x25c), 0, 7, lbl_80541900, lbl_80541900);
            fn_803075AC(*(void**)((u8*)this_ + 0x198), *(s32*)((u8*)this_ + 4), (u8*)this_ + 0xc, *(s32*)((u8*)this_ + 0x26c) + *(s32*)((u8*)this_ + 0x25c), 0, 2, -1, 0, 0, 0);
            break;
        case 3:
            fn_801F06F0(this_, tbl + 0x28, *(s32*)((u8*)this_ + 0x26c) + *(s32*)((u8*)this_ + 0x25c), 0, 7, lbl_80541900, lbl_80541900);
            break;
        }
    }
}

extern "C" void fn_803199AC(u32* param_1)
{
    u32 state;
    int cVar1;
    if (param_1[0x90] != 0) {
        cVar1 = ((Actor*)param_1)->v11();
        state = param_1[0x90];
        if ((state == 1 && (u8)cVar1 == 1) || (state == 2 && (u8)cVar1 == 0)) {
            *(u8*)(param_1 + 0x9c) = 0;
        } else {
            *(u8*)(param_1 + 0x9c) = 1;
        }
    }
    if (*(u8*)(param_1 + 0x9c) == 1) {
        (((Actor*)param_1)->*lbl_804AAED4[param_1[0x8e]])();
    }
}

#pragma opt_propagation off
extern "C" void fn_80319A58(char* param_1) {
    s32 count;
    char* actor;
    s32 off;
    s32 owner;
    u32 flags;
    s32 id;
    s32 i;
    if (*(u32*)(param_1 + 0x238) == 0) {
        count = *(s32*)((char*)fn_801F856C() + 0x1008);
        i = 0;
        off = 0;
        for (; i < count; i++) {
            actor = *(char**)((char*)fn_801F856C() + off + 8);
            if (actor != 0 && *(s32*)(actor + 0x1a0) == 0x4a494a49) {
                if (*(s32*)(actor + 4) == (owner = *(s32*)(param_1 + 4))) {
                    flags = *(u32*)(actor + 0x90);
                    if (((flags >> 16) & 0xff) == 0x2a) {
                        *(s32*)(param_1 + 0x258) = Actor_CreateByID(fn_801F856C(), 0x534e5043, owner, actor + 0xc, (flags & 0xfff) | 0x90000, -1, -1);
                        id = *(s32*)(param_1 + 0x258);
                        if (id < 0) return;
                        char* obj = (char*)fn_801F666C(fn_801F856C(), id);
                        *(s32*)(obj + 0x258) = *(s32*)(param_1 + 0x198);
                        actor[0x11c] = 0;
                        return;
                    }
                }
            }
            off += 4;
        }
    }
}
#pragma opt_propagation reset
extern const f32 lbl_80541904;
extern const f32 lbl_80541908;
extern const f32 lbl_8054190C;
extern const f32 lbl_80541910;
extern const f32 lbl_80541914;
extern const f32 lbl_80541918;
extern const f32 lbl_8054191C;
extern "C" void fn_80319B4C(Actor* this_)
{
    u8* self = (u8*)this_;
    Vec vec;
    s32 idx;
    u8* p;
    u8 c;

    *(s32*)(self + 0x230) = 0;
    *(s32*)(self + 0x234) = -1;
    *(s32*)(self + 0x244) = (*(u32*)(self + 0x90) & 0xfff) + 299;
    *(s32*)(self + 0x258) = -1;
    *(s32*)(self + 0x25c) = 0;
    *(s32*)(self + 0x260) = 0;
    *(s32*)(self + 0x264) = 2;
    *(s32*)(self + 0x268) = 0;

    switch ((*(u32*)(self + 0x90) >> 16) & 0xf) {
    case 0:
        *(s32*)(self + 0x238) = 0;
        *(s32*)(self + 0x23c) = 0;
        *(s32*)(self + 0x26c) = 0;
        break;
    case 1:
        *(s32*)(self + 0x238) = 1;
        *(s32*)(self + 0x23c) = 2;
        *(s32*)(self + 0x26c) = 0x2f;
        break;
    case 2:
        *(s32*)(self + 0x238) = 1;
        *(s32*)(self + 0x23c) = 1;
        *(s32*)(self + 0x26c) = 0xc3;
        break;
    case 3:
        *(s32*)(self + 0x238) = 2;
        *(s32*)(self + 0x23c) = 1;
        *(s32*)(self + 0x26c) = 0x12e;
        if (fn_802D7F40(fn_802D6A9C(), 2) == 1) {
            *(u8*)(self + 0x11c) = 0;
        }
        break;
    case 4:
        *(s32*)(self + 0x238) = 3;
        *(s32*)(self + 0x23c) = 1;
        *(s32*)(self + 0x26c) = 0x130;
        break;
    case 5:
        *(s32*)(self + 0x238) = 4;
        *(s32*)(self + 0x23c) = 3;
        *(s32*)(self + 0x26c) = 0x530;
        *(s32*)(self + 0x25c) = *(s32*)(self + 0x25c) | (*(s32*)(self + 0x264) << 1);
        break;
    case 6:
        *(s32*)(self + 0x238) = 5;
        *(s32*)(self + 0x23c) = 1;
        *(s32*)(self + 0x26c) = 0x132;
        *(s32*)(self + 0x244) = 0x580;
        *(s32*)(self + 0x264) = 0;
        break;
    case 7:
        vec = *(Vec*)(self + 0xc);
        vec.x += lbl_80541904;
        *(s32*)(self + 0x258) = Actor_CreateByID(fn_801F856C(), 0x534e5043, *(s32*)(self + 4), (char*)&vec, 0x80000, -1, -1);
        idx = *(s32*)(self + 0x258);
        if (idx >= 0) {
            p = (u8*)fn_801F666C(fn_801F856C(), idx);
            *(s32*)(p + 0x258) = *(s32*)(self + 0x198);
        }
        *(s32*)(self + 0x238) = 6;
        *(s32*)(self + 0x23c) = 1;
        *(s32*)(self + 0x26c) = 0x126;
        *(s32*)(self + 0x244) = 0x591;
        *(s32*)(self + 0x260) = 10;
        if (fn_802D800C(fn_802D6A9C(), 0x1f) == 1) {
            *(s32*)(self + 0x264) = 3;
        }
        break;
    case 8:
        *(s32*)(self + 0x238) = 7;
        *(s32*)(self + 0x23c) = 1;
        *(s32*)(self + 0x26c) = 0x120;
        *(s32*)(self + 0x244) = 0x58e;
        *(s32*)(self + 0x260) = 20;
        if (fn_802D800C(fn_802D6A9C(), 0x1e) == 1) {
            *(s32*)(self + 0x264) = 3;
        }
        break;
    case 10:
        *(s32*)(self + 0x238) = 8;
        *(s32*)(self + 0x23c) = 2;
        *(s32*)(self + 0x26c) = 0x315;
        break;
    case 9:
        *(s32*)(self + 0x238) = 2;
        *(s32*)(self + 0x23c) = 2;
        *(s32*)(self + 0x26c) = 0x37e;
        *(s32*)(self + 0x260) = 0x3c;
        if (fn_802D7F40(fn_802D6A9C(), 2) == 1) {
            *(u8*)(self + 0x11c) = 0;
        }
        break;
    }

    if (*(u32*)(self + 0x238) == 0) {
        *(f32*)(self + 0x248) = lbl_80541908;
        *(f32*)(self + 0x24c) = lbl_8054190C;
        *(f32*)(self + 0x250) = lbl_80541910;
        *(f32*)(self + 0x254) = lbl_80541914;
    } else {
        *(f32*)(self + 0x248) = lbl_80541918;
        *(f32*)(self + 0x24c) = lbl_80541918;
        *(f32*)(self + 0x250) = lbl_8054191C;
        *(f32*)(self + 0x254) = lbl_8054191C;
        *(u64*)(self + 0x60) = *(u64*)(self + 0x248);
        *(u64*)(self + 0x68) = *(u64*)(self + 0x250);
    }

    if ((*(u32*)(self + 0x90) >> 27) != 0) {
        *(u32*)(self + 0x240) = (*(u32*)(self + 0x90) >> 24) & 3;
        c = (u8)this_->v11();
        if ((*(u32*)(self + 0x240) == 1 && c == 1) || (*(u32*)(self + 0x240) == 2 && c == 0)) {
            *(u8*)(self + 0x270) = 0;
        } else {
            *(u8*)(self + 0x270) = 1;
        }
    } else {
        *(u32*)(self + 0x240) = 0;
        *(u8*)(self + 0x270) = 1;
    }
}

