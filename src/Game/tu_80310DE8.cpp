#include "Game/esd/types.h"
#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "Game/ItemBase.h"
#include "dolphin/mtx.h"


extern "C" void fn_802A3948(void* mgr, void* pos, s32 player, u32 room, s32 id);
extern "C" void fn_802A3884(void* mgr, void* pos, s32 player, u32 room, s32 id);
extern "C" void fn_801F0E34(void* this_, u32 id, s32 c);
extern "C" void fn_8023061C(s32 p, s32 a);
extern "C" char lbl_804AAAE8[];
extern "C" void __dt__5ActorFv(void* this_, s32 flag);
extern "C" f32 lbl_805417A0;
extern "C" f32 lbl_805417A4;
extern "C" f32 lbl_805417A8;
extern void* lbl_8053AC98;

struct Vec2_FSA {
    f32 x;
    f32 y;
};

struct Vec3_FSA {
    Vec2_FSA xy;
    f32 z;
};

extern "C" void fn_801F06F0(void* this_, void* p, s32 id, u8* ids, s32 flag, f32 a, f32 b);
extern "C" void fn_803075AC(void* a, void* b, void* c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j);
extern "C" char lbl_80471438[];
extern "C" f32 lbl_80541798;
extern "C" f32 lbl_8054179C;
extern "C" void* fn_80310DE8(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AAAE8;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_80310E48(void* this_) {
    fn_802A3948(lbl_8053AC98, (u8*)this_ + 0xc, 0, *(u32*)((u8*)this_ + 4), 0x10);
    *(s32*)((u8*)this_ + 0x234) = -1;
    *(s32*)((u8*)this_ + 0x230) = 0;
}

extern "C" void fn_80310E98(u8* this_) {
    if (*(s32*)(this_ + 0x230) == 1) {
        fn_802A3948(lbl_8053AC98, this_ + 0xc, 0, *(u32*)(this_ + 4), 0x10);
        fn_801F0E34(this_, 0x30076, 0);
        *(f32*)(this_ + 0x248) = *(f32*)(this_ + 0xc);
        *(f32*)(this_ + 0x24c) = *(f32*)(this_ + 0x10);
        *(f32*)(this_ + 0x250) = *(f32*)(this_ + 0x14);
        *(u8*)(this_ + 0x254) = 0;
        *(s32*)(this_ + 0x240) = 0x5a;
        *(s32*)(this_ + 0x230) = 2;
    } else if (*(s32*)(this_ + 0x230) == 3) {
        fn_8023061C(*(s32*)(this_ + 0x234), 0);
        *(s32*)(this_ + 0x234) = -1;
        *(s32*)(this_ + 0x230) = 0;
    }
}

extern "C" void fn_80310F50(void* this_, s32 p2, s32 p3, s32 p4) {
    fn_802A3884(lbl_8053AC98, (u8*)this_ + 0xc, 0, *(u32*)((u8*)this_ + 4), 0x30);
    *(s32*)((u8*)this_ + 0x234) = p2;
    *(s32*)((u8*)this_ + 0x238) = p3;
    *(s32*)((u8*)this_ + 0x23c) = p4;
    *(s32*)((u8*)this_ + 0x230) = 1;
}

extern "C" void fn_801F06F0(void* this_, void* p, s32 id, u8* ids, s32 flag, f32 a, f32 b);
extern "C" void fn_803075AC(void* a, void* b, void* c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j);
extern "C" char lbl_80471438[];
extern "C" f32 lbl_80541798;
extern "C" f32 lbl_8054179C;
extern "C" void fn_80310FC8(u8* this_) {
    u8* base = (u8*)lbl_80471438;
    if (*(s32*)(this_ + 0x230) >= 2) {
        Vec saved;
        JGeometry::setTVec3f((f32*)(this_ + 0xc), (f32*)&saved);
        JGeometry::setTVec3f((f32*)(this_ + 0x248), (f32*)(this_ + 0xc));
        DrawRec rec;
        Mtx mtx;
        rec.b1d = 1;
        rec.b1c = 1;
        rec.b1f = 0;
        if (*(s32*)(this_ + 0x238) == 4) {
            PSMTXScale(mtx, lbl_80541798, lbl_80541798, lbl_80541798);
            rec.w18 = mtx;
            fn_801F06F0(this_, base + 0x28, 0x45a, rec.ids, -1, lbl_8054179C, lbl_8054179C);
            fn_803075AC(*(void**)(this_ + 0x198), *(void**)(this_ + 4), this_ + 0xc, 0x11, 1, 2, -1, 1, 0, 0);
        } else {
            s32* ids = (s32*)(base + 0x14);
            fn_801F06F0(this_, base + 0x3c, ids[*(s32*)(this_ + 0x238)], rec.ids, -1, lbl_8054179C, lbl_8054179C);
            fn_803075AC(*(void**)(this_ + 0x198), *(void**)(this_ + 4), this_ + 0xc, ids[*(s32*)(this_ + 0x238)], 0, 2, -1, 1, 0, 0);
        }
        JGeometry::setTVec3f((f32*)&saved, (f32*)(this_ + 0xc));
    }
}

extern "C" s32 fn_8022EA0C(s32 h);
extern "C" s32 fn_8023AF14(f32* box, u32 room, f32 f, s32 flag);
extern "C" s32 fn_80230CFC(s32 h);
extern "C" u8 fn_8023EFEC(s32 h);
extern "C" void fn_8022F340(s32 h);
extern "C" u32 fn_8030AAF4(void);
extern "C" void* fn_80309D6C(void* a, u32 b, s32 c);
extern "C" u8 fn_802300EC(s32 h);
extern "C" void fn_802308E0(s32 h);
extern "C" void fn_80230FD0(s32 h, s32 id);
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* a, s32 b);
extern "C" void fn_8030FDC0(void* a, s32 b);
extern "C" void* fn_8023E724(s32 h);
extern "C" void fn_80230498(s32 h, void* pos, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_802362C4(s32 h, s32 id);
extern void* lbl_8053AD30;
extern "C" void fn_80311214(u8* this_) {
    switch (*(s32*)(this_ + 0x230)) {
    case 0:
        break;
    case 1: {
        f32 box[4];
        box[0] = *(f32*)(this_ + 0x60);
        box[1] = *(f32*)(this_ + 0x64);
        box[2] = *(f32*)(this_ + 0x68);
        box[3] = *(f32*)(this_ + 0x6c);
        box[0] += *(f32*)(this_ + 0xc);
        box[1] += *(f32*)(this_ + 0x10);
        box[2] += *(f32*)(this_ + 0xc);
        box[3] += *(f32*)(this_ + 0x10);
        s32 id = fn_8022EA0C(*(s32*)(this_ + 0x234));
        if (id == fn_8023AF14(box, *(u32*)(this_ + 4), lbl_805417A0, 0)) {
            if (fn_80230CFC(id) == 3 && fn_8023EFEC(id) == 0) {
                fn_8022F340(id);
                void* p = fn_80309D6C(lbl_8053AD30, fn_8030AAF4(), 0x100);
                if (p != 0 && fn_802300EC(id) == 1) {
                    *(s32*)(this_ + 0x234) = id;
                    fn_802308E0(*(s32*)(this_ + 0x234));
                    fn_802A3948(lbl_8053AC98, this_ + 0xc, 0, *(u32*)(this_ + 4), 0x10);
                    fn_80230FD0(*(s32*)(this_ + 0x234), 0x20013);
                    void* obj = fn_801F666C(fn_801F856C(), *(s32*)(this_ + 0x23c));
                    if (obj != 0 && *(s32*)((u8*)obj + 0x1a0) == 0x474d424c) {
                        fn_8030FDC0(obj, *(s32*)(this_ + 0x238));
                    }
                    JGeometry::TVec3f tmp(*(JGeometry::TVec3f*)fn_8023E724(*(s32*)(this_ + 0x234)));
                    f32 y = tmp.y - lbl_805417A4;
                    f32 z = tmp.z;
                    *(f32*)(this_ + 0x248) = tmp.x;
                    *(f32*)(this_ + 0x24c) = y;
                    *(f32*)(this_ + 0x250) = z;
                    *(s32*)(this_ + 0x244) = 0;
                    *(u8*)(this_ + 0x254) = 1;
                    fn_80230498(*(s32*)(this_ + 0x234), &tmp, *(s32*)(this_ + 0x244) + 0xed, 0xff, -0x80, -0x80, 1);
                    fn_802362C4(*(s32*)(this_ + 0x234), ((s32*)lbl_80471438)[*(s32*)(this_ + 0x238)]);
                    *(s32*)(this_ + 0x240) = 0x5a;
                    *(s32*)(this_ + 0x230) = 2;
                }
            }
        }
        break;
    }
    case 2:
        switch (*(s32*)(this_ + 0x240)) {
        case 0:
            if (*(u8*)(this_ + 0x254) != 0) {
                *(s32*)(this_ + 0x230) = 3;
            } else {
                *(s32*)(this_ + 0x234) = -1;
                *(s32*)(this_ + 0x230) = 0;
            }
            return;
        case 0x48:
            if (*(u8*)(this_ + 0x254) != 0) {
                fn_80230FD0(*(s32*)(this_ + 0x234), 0x10008);
            }
        case 0x4c:
        case 0x50:
            *(f32*)(this_ + 0x24c) = *(f32*)(this_ + 0x24c) - lbl_805417A8;
            if (*(u8*)(this_ + 0x254) != 0) {
                *(s32*)(this_ + 0x244) = *(s32*)(this_ + 0x244) + 1;
                fn_80230498(*(s32*)(this_ + 0x234), fn_8023E724(*(s32*)(this_ + 0x234)), *(s32*)(this_ + 0x244) + 0xed, 0xff, -0x80, -0x80, 1);
            }
            break;
        }
        *(s32*)(this_ + 0x240) = *(s32*)(this_ + 0x240) - 1;
        break;
    case 3:
        break;
    }
}

extern "C" f32 lbl_805417AC;
extern "C" f32 lbl_805417A4;
extern "C" f32 lbl_805417B0;
extern "C" f32 lbl_805417A0;
extern "C" f32 lbl_805417B4;
extern "C" void fn_80311504(u8* this_) {
    JGeometry::TVec3f* pos = (JGeometry::TVec3f*)(this_ + 0xc);
    f32 a = lbl_805417AC;
    f32 nx = pos->x + a;
    f32 b = lbl_805417A4;
    f32 c = lbl_805417B0;
    f32 d = lbl_805417A0;
    f32 z = lbl_805417B4;
    pos->x = nx;
    pos->y = pos->y + b;
    ((JGeometry::TVec3f*)(this_ + 0x60))->set(c, d, z);
    *(f32*)(this_ + 0x6c) = z;
    *(s32*)(this_ + 0x230) = 0;
    *(s32*)(this_ + 0x234) = -1;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = -1;
    *(s32*)(this_ + 0x240) = 0;
    *(JGeometry::TVec3f*)(this_ + 0x248) = *pos;
    *(u8*)(this_ + 0x254) = 0;
    *(s32*)(this_ + 0x244) = 0;
}

