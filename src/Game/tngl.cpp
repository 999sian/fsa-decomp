// TU 0x803d9944-0x803da6b4 (actor TNGL).
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JGeometry/Box.h"

extern "C" s32 fn_80237060(s32 arg);
extern "C" s32 fn_8023DE58(s32 player);
extern "C" s32 fn_8022EA0C(s32 arg);
extern "C" JGeometry::TVec3<f32>* fn_8023E724(s32 player);
extern "C" void fn_803075AC(void*, s32, void*, s32, s32, s32, s32, s32, s32, s32);

// TNGL sound/effect update
extern "C" void fn_803D9944(u8* this_) {
    s32 snd;
    u8* q;
    s32 base;
    s32 i;
    if (*(s32*)(this_ + 0x248) == 0) {
        base = 0x34C;
        if (fn_80237060(0) >= 2) {
            base = 0x364;
        }
        if (*(s32*)(this_ + 0x90) == 0) {
            f32 x = *(f32*)(this_ + 0xC);
            f32 y = *(f32*)(this_ + 0x10);
            f32 z = *(f32*)(this_ + 0x14);
            q = this_;
            for (i = 0; i < 4; i++) {
                if (fn_8023DE58(i) >= 8) {
                    *(f32*)(this_ + 0xC) = *(f32*)(q + 0x260);
                    *(f32*)(this_ + 0x10) = *(f32*)(q + 0x264);
                    *(f32*)(this_ + 0x14) = *(f32*)(q + 0x268);
                    snd = base + *(s32*)(this_ + 0x24C);
                    s32 room = fn_8023DE58(i);
                    fn_803075AC((void*)(i - 0x22B), room, this_ + 0xC, snd, 0, 2, -1, 1, 0, 1);
                }
                q += 0xC;
            }
            *(f32*)(this_ + 0xC) = x;
            *(f32*)(this_ + 0x10) = y;
            *(f32*)(this_ + 0x14) = z;
        } else {
            fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xC,
                        base + *(s32*)(this_ + 0x24C), 0, 2, -1, 1, 0, 1);
        }
    }
}

extern "C" void* fn_8013CC50(u32 room, void* pos, f32 f, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" s32 fn_80237810(s32 i);
extern "C" s32 fn_80237774(s32 i);
extern "C" void fn_80236554(s32 i, s32 a, s32 b);
extern "C" void fn_801F0E34(void* this_, s32 id, s32 a);
extern "C" void fn_801F71A4(void* box, f32 a, f32 b, f32 c);
extern "C" s32 fn_80388CAC(s32 handle, void* room);
extern "C" s32 fn_80138A30(void* game);
extern "C" void fn_80384C58(s32 handle, void* room);
extern "C" s32 fn_8022FD8C(void* room);
extern "C" void fn_8022FEB8(void* box, s32 room, void* handle, s32 a, s32 b);
extern "C" u8 fn_8038BD08(s32 handle, s32 id, s32 room, void* v, s32 n);
extern "C" f32 lbl_80543590;
extern "C" f32 lbl_80543594;
extern "C" u8* lbl_8053AB10;
extern "C" u8* lbl_8053AAF8;
static inline s32 tnglSequenceValue(const s32* sequence, s32 index) {
    return sequence[index];
}

struct TnglSequence {
    s32 first[3];
    s32 second[3];
    s32 third[8];
    s32 last[9];
    s32 delay[13];
};
extern "C" u8 lbl_804B03E8[];
extern "C" s32 lbl_8053A210[2];
extern "C" u8 lbl_80529DEC[];
extern "C" u8* lbl_8053AEC8;
extern "C" void* lbl_8053AED0;
extern "C" u8 lbl_8053AAA0;
extern "C" u8 lbl_8053AB98;
extern "C" u8 lbl_8053ABE8;
extern "C" void fn_8043D67C(void*, s32, s32, s32);
extern "C" s32 lbl_8053A210[2];
extern "C" void fn_803D9AA4(u8* this_) {
    const TnglSequence* data = (TnglSequence*)lbl_804B03E8;
    switch (*(s32*)(this_ + 0x230)) {
    case 0: {
        u8* q;
        JGeometry::TVec3<f32>* pos;
        int i;
        int id;
        if (*(s32*)(this_ + 0x240) < 0x3c) {
            *(s32*)(this_ + 0x240) += 1;
            break;
        }
        *(s32*)(this_ + 0x240) = 0;
        i = *(s32*)(this_ + 0x240);
        *(s32*)(this_ + 0x244) = -1;
        *(s32*)(this_ + 0x248) = i;
        q = this_;
        for (; i < 4; i++, q += 4) {
            void* handle = (void*)fn_8023DE58(i);
            if ((s32)handle < 8) {
                id = 0x3ae;
                if (fn_80237060(0) == 2) id = 0x3af;
                pos = fn_8023E724(i);
                s32 room = fn_8023DE58(i);
                fn_8013CC50(room, pos, lbl_80543590, id, 1, 1, 0, 0, 1);
                id = 0x3ac;
                if (fn_80237060(0) == 2) id = 0x3ad;
                pos = fn_8023E724(i);
                room = fn_8023DE58(i);
                handle = fn_8013CC50(room, pos, lbl_80543590, id, 1, 1, 0, 0, 1);
            }
            *(void**)(q + 0x290) = handle;
        }
        *(s32*)(this_ + 0x238) = 0x3c;
        *(s32*)(this_ + 0x230) = 1;
        break;
    }
    case 1: {
        JGeometry::TVec3<f32>* pos;
        u8* q;
        int i;
        (*(u8**)(lbl_8053AB10 + 0x24))[0x17d] = 1;
        for (i = 0; i < 4; i++) {
            for (i = 0, q = this_; i < 4; i++, q += 12) {
                fn_801F71A4(q + 0x264, fn_8023E724(i)->y, lbl_80543594, lbl_80543590);
            }
        }
        if (*(s32*)(this_ + 0x238) != 0) break;
        for (i = 0, q = this_; i < 4; i++, q += 12) {
            if (fn_8023DE58(i) >= 8) {
                pos = fn_8023E724(i);
                *(f32*)(q + 0x260) = pos->x;
                *(f32*)(q + 0x264) = pos->y;
                *(f32*)(q + 0x268) = pos->z;
            }
        }
        JGeometry::TVec3<f32> v;
        JGeometry::TBox2<f32> box;
        box.set(*(JGeometry::TBox2<f32>*)(this_ + 0x60));
        box.addPos(*(JGeometry::TVec2<f32>*)(this_ + 0xc));
        fn_8022FEB8(&box, *(s32*)(this_ + 4), *(void**)(this_ + 0x198), 0, 0);
        *(s32*)(this_ + 0x244) = fn_8022FD8C(*(void**)(this_ + 0x198));
        if (*(s32*)(this_ + 0x244) >= 0) {
            s32 room = *(s32*)(this_ + 4);
            JGeometry::TVec3<f32> copy(v);
            if (fn_8038BD08(*(s32*)(this_ + 0x244), 0x406, room, &copy, 0x28))
                *(s32*)(this_ + 0x230) = 2;
        }
        break;
    }
    case 2: {
        int i;
        (*(u8**)(lbl_8053AB10 + 0x24))[0x17d] = 1;
        if (!(u8)fn_80388CAC(*(s32*)(this_ + 0x244), *(void**)(this_ + 0x198))) break;
        if (fn_80138A30(lbl_8053AAF8) == 1)
            fn_801F0E34(this_, 0x5006c, 0);
        fn_80384C58(*(s32*)(this_ + 0x244), *(void**)(this_ + 0x198));
        *(s32*)(this_ + 0x238) = 0x15e;
        *(s32*)(this_ + 0x23c) = 0x5a;
        for (i = 0; i < 4; i++) {
            if ((u32)(bool)(lbl_8053AAF8[0x82] & (u8)(1 << i)) == 1) {
                s32 max = fn_80237810(i) - 4;
                if (fn_80237774(i) < max) {
                    s32 n = fn_80237810(i);
                    n -= fn_80237774(i);
                    fn_80236554(i, n - 4, 1);
                }
            }
        }
        *(s32*)(this_ + 0x230) = 3;
        break;
    }
    case 3: {
        int i;
        (*(u8**)(lbl_8053AB10 + 0x24))[0x17d] = 1;
        if (*(s32*)(this_ + 0x23c) == 0x1e && fn_80138A30(lbl_8053AAF8) > 1)
            fn_801F0E34(this_, 0x5006c, 0);
        if (*(s32*)(this_ + 0x23c) == 0) {
            for (i = 0; i < 4; i++) {
                u8* emitter = *(u8**)(this_ + 0x290 + i * 4);
                if (emitter) {
                    *(u32*)(emitter + 0xf4) |= 1;
                    *(s32*)(emitter + 0x24) = 1;
                    *(void**)(this_ + 0x290 + i * 4) = 0;
                }
            }
            *(s32*)(this_ + 0x248) = 1;
        }
        if (*(s32*)(this_ + 0x238) == 0x15c) this_[0x251] = 1;
        if (*(s32*)(this_ + 0x238) == 0) {
            *(s32*)(this_ + 0x238) = 0x46;
            lbl_8053AAA0 = 1;
            lbl_8053AB98 = 1;
            lbl_8053ABE8 = 1;
            *(s32*)(this_ + 0x230) = 4;
        }
        break;
    }
    case 4:
        (*(u8**)(lbl_8053AB10 + 0x24))[0x17d] = 1;
        if (*(s32*)(this_ + 0x238) == 0) {
            lbl_8053AEC8[0x59] = this_[0x250];
            this_[0x250] = 0xff;
            if (lbl_80529DEC[0x24f] != 0) lbl_80529DEC[0x24f]--;
            else lbl_80529DEC[0x24f] = 0;
            fn_8043D67C(lbl_8053AED0, 0x33a, 0, lbl_80529DEC[0x24f]);
            this_[0x11c] = 0;
        }
        break;
    case 5:
        *(s32*)(this_ + 0x244) += 1;
        if (*(s32*)(this_ + 0x244) == 2) this_[0x251] = 1;
        if (*(s32*)(this_ + 0x234) == 0) {
            *(s32*)(this_ + 0x24c) = lbl_8053A210[*(s32*)(this_ + 0x240)];
            *(s32*)(this_ + 0x240) += 1;
            *(s32*)(this_ + 0x240) = 1;
            if (*(s32*)(this_ + 0x240) == 0) *(s32*)(this_ + 0x234) = 2;
            else *(s32*)(this_ + 0x234) = 4;
        }
        if (*(s32*)(this_ + 0x244) >= 10) *(s32*)(this_ + 0x230) = 6;
        break;
    case 6:
        *(s32*)(this_ + 0x234) = 0;
        *(s32*)(this_ + 0x240) = 0;
        *(s32*)(this_ + 0x230) = 7;
    case 7:
        *(s32*)(this_ + 0x244) += 1;
        if (*(s32*)(this_ + 0x234) == 0) {
            *(s32*)(this_ + 0x24c) = data->first[*(s32*)(this_ + 0x240)];
            *(s32*)(this_ + 0x240) += 1;
            *(s32*)(this_ + 0x234) = 2;
            if (*(s32*)(this_ + 0x240) > 2) {
                *(s32*)(this_ + 0x240) = 0;
                *(s32*)(this_ + 0x230) = 8;
            }
        }
        break;
    case 8:
        *(s32*)(this_ + 0x244) += 1;
        if (*(s32*)(this_ + 0x234) == 0) {
            *(s32*)(this_ + 0x24c) = data->second[*(s32*)(this_ + 0x240)];
            *(s32*)(this_ + 0x240) += 1;
            *(s32*)(this_ + 0x234) = 2;
            if (*(s32*)(this_ + 0x240) > 2) *(s32*)(this_ + 0x240) = 0;
        }
        if (*(s32*)(this_ + 0x244) >= 0x12c) {
            *(s32*)(this_ + 0x240) = 0;
            *(s32*)(this_ + 0x230) = 9;
        }
        break;
    case 9:
        *(s32*)(this_ + 0x244) += 1;
        if (*(s32*)(this_ + 0x234) == 0) {
            *(s32*)(this_ + 0x24c) = data->third[*(s32*)(this_ + 0x240)];
            *(s32*)(this_ + 0x240) += 1;
            *(s32*)(this_ + 0x234) = 2;
            if (*(s32*)(this_ + 0x240) > 7) *(s32*)(this_ + 0x240) = 7;
        }
        if (*(s32*)(this_ + 0x244) >= 0x15e) {
            *(s32*)(this_ + 0x240) = 0;
            *(s32*)(this_ + 0x234) = 0;
            *(s32*)(this_ + 0x230) = 10;
        }
        break;
    case 10:
        if (*(s32*)(this_ + 0x234) == 0) {
            *(s32*)(this_ + 0x24c) = data->last[*(s32*)(this_ + 0x240)];
            *(s32*)(this_ + 0x234) = data->delay[*(s32*)(this_ + 0x240)];
            *(s32*)(this_ + 0x240) += 1;
            if (*(s32*)(this_ + 0x240) > 9) this_[0x11c] = 0;
        }
        break;
    }
    if (*(s32*)(this_ + 0x234) > 0) *(s32*)(this_ + 0x234) -= 1;
    if (*(s32*)(this_ + 0x238) > 0) *(s32*)(this_ + 0x238) -= 1;
    if (*(s32*)(this_ + 0x23c) > 0) *(s32*)(this_ + 0x23c) -= 1;
}

// ---- from src/Game/Tngl_dtor_803DA260.cpp ----
extern "C" void fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804B0478[];

extern "C" void* fn_803DA260(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804B0478;
        for (int i = 0; i < 4; i++) {
            fn_801EE434(*(void**)((char*)this_ + 0x290 + i * 4));
        }
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// TNGL init (vtable slot 1)
extern "C" void fn_803DA2F4(u8* this_) {
    *(f32*)(this_ + 0x60) = -1280.0f;
    *(f32*)(this_ + 0x64) = -1280.0f;
    *(f32*)(this_ + 0x68) = 1280.0f;
    *(f32*)(this_ + 0x6C) = 1280.0f;
    *(f32*)(this_ + 0x80) = -8.0f;
    *(f32*)(this_ + 0x84) = -8.0f;
    *(f32*)(this_ + 0x88) = 8.0f;
    *(f32*)(this_ + 0x8C) = 8.0f;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23C) = 0;
    *(s32*)(this_ + 0x24C) = 0;
    *(u8*)(this_ + 0x250) = 1;
    *(void**)(this_ + 0x290) = 0;
    *(void**)(this_ + 0x294) = 0;
    *(void**)(this_ + 0x298) = 0;
    *(void**)(this_ + 0x29C) = 0;
    *(u8*)(this_ + 0x251) = 0;
    *(u8*)(this_ + 0x11F) = 1;
    if (*(s32*)(this_ + 0x90) == 0) {
        s32 p = fn_8022EA0C(0);
        if (p >= 0) {
            fn_8023DE58(p);
            JGeometry::TVec3<f32>* v = fn_8023E724(p);
            *(f32*)(this_ + 0xC) = v->x;
            *(f32*)(this_ + 0x10) = v->y;
            *(f32*)(this_ + 0x14) = v->z;
            *(f32*)(this_ + 0x10) += 16.0f;
            *(s32*)(this_ + 4) = fn_8023DE58(p);
        }
    }
    u8* q = this_;
    for (s32 i = 0; i < 4; i++) {
        JGeometry::TVec3<f32>* v = fn_8023E724(i);
        *(f32*)(q + 0x260) = v->x;
        *(f32*)(q + 0x264) = v->y;
        *(f32*)(q + 0x268) = v->z;
        *(f32*)(q + 0x264) += 16.0f;
        q += 0xC;
    }
    *(f32*)(this_ + 0x254) = *(f32*)(this_ + 0xC);
    *(f32*)(this_ + 0x258) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x25C) = *(f32*)(this_ + 0x14);
    if (*(s32*)(this_ + 0x90) == 0) {
        *(s32*)(this_ + 0x248) = 1;
        *(s32*)(this_ + 0x230) = 0;
    } else {
        *(s32*)(this_ + 0x230) = 5;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
