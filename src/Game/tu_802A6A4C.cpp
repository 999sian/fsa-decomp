#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"

class Tu2A6A4CActor : public Actor {
public:
    virtual void v19(s32);
    s32 field_230;
    s32 field_234;
    s32 field_238;
    s32 field_23C;
    s32 field_240;
    s32 field_244;
    s32 field_248;
    s32 field_24C;
    s32 field_250;
    s32 field_254;
    u16 field_258;
    u16 field_25A;
    s32 field_25C;
    s32 field_260;
    s32 field_264;
};

extern "C" s32 fn_80226AE0(void*, u32);
extern "C" u16 fn_802F9908(void*, u32, s32);
extern "C" void* fn_801F856C(void);
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D800C(void*, s32);
extern "C" void fn_802A3884(void*, void*, s32, u32, u16);
extern void* lbl_8053AB10;
extern const u32 lbl_8046C828[];


extern "C" char lbl_804A7F38[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_802A6A4C(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804A7F38;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void* lbl_8053AC98;
extern "C" void fn_802A3948(void* mgr, void* pos, s32 player, u32 room, s32 id);
extern "C" void fn_802A6AAC(Actor* p, s32 player) {
    switch (*(u16*)((u8*)p + 0x258)) {
    case 0x41:
    case 0x12:
    case 0x68:
        fn_802A3948(lbl_8053AC98, (u8*)p + 0xc, player, p->field_04, 0x13);
        break;
    case 0x50:
    case 0x43:
    case 0x6a:
        fn_802A3948(lbl_8053AC98, (u8*)p + 0xc, player, p->field_04, 0x51);
        break;
    case 0x14:
    case 0x52:
        fn_802A3948(lbl_8053AC98, (u8*)p + 0xc, player, p->field_04, 0x15);
        break;
    case 0x15a:
        fn_802A3948(lbl_8053AC98, (u8*)p + 0xc, player, p->field_04, 0x360);
        break;
    }
}

extern "C" void fn_802A6BC0(void) {}

#include "JSystem/JGeometry/Box.h"
extern "C" s32 fn_801F8108(void* p, u32 id, s32 n, f32 range = 32.0f);
extern "C" s32 fn_8023AF14(void* box, u32 room, s32 flag, f32 offset = 0.0f);
extern "C" void* fn_8023E724(s32);
extern "C" u8 fn_8023513C(s32);
extern "C" u8 fn_802353AC(s32);
extern "C" u8 fn_80233DA4(s32);
extern "C" u8 fn_80235004(s32);
extern "C" s32 fn_802D7E1C(void*, u32);
extern "C" u8 fn_8022E39C(s32, s32);
extern "C" void fn_801F0E34(void*, u32, void*);
extern "C" void* fn_801F666C(void*, s32);
extern "C" void fn_802302C4(s32, s32, s32);
extern "C" u8 fn_80230188(s32);
extern void* lbl_8053AAF8;
extern const u32 lbl_8046C838[];
extern const f32 lbl_805407F0;
extern const f32 lbl_805407F4;
extern const f32 lbl_805407F8;
extern const f32 lbl_805407FC;
extern const f32 lbl_80540800;
#pragma opt_propagation off
extern "C" void fn_802A6BC4(Tu2A6A4CActor* self) {
    u32 flags;
    s32 actor;
    s32 i;
    bool found;
    s32 player;
    s32 kind;
    u8* p = (u8*)self;
    JGeometry::TVec3<f32> pos;
    JGeometry::TBox2<f32> box;
    f32 y = *(f32*)(p + 0x10);
    f32 x = *(f32*)(p + 0xc);
    box.i.x = *(f32*)(p + 0x60); box.i.y = *(f32*)(p + 0x64);
    box.f.x = *(f32*)(p + 0x68); box.f.y = *(f32*)(p + 0x6c);
    box.addPos(x, y);
    if (fn_801F8108(p, 'TBO2', -1, lbl_805407F0) >= 0) return;
    player = fn_8023AF14(&box, *(s32*)(p + 4), 1, lbl_805407F4);
    kind = 0;
    actor = -1;
    if (self->field_234 != 7) {
        actor = fn_801F8108(p, 'AMOS', -1, lbl_805407F0);
        if (actor < 0) {
            actor = fn_801F8108(p, 'BRBL', -1, lbl_805407F0); kind = 1;
            if (actor < 0) {
                actor = fn_801F8108(p, 'BLCK', -1, lbl_805407F0); kind = 2;
                if (actor < 0) {
                    actor = fn_801F8108(p, 'BCK2', -1, lbl_805407F0); kind = 3;
                    if (actor < 0) {
                        actor = fn_801F8108(p, 'SMRI', -1, lbl_805407F8); kind = 4;
                    }
                }
            }
        }
    }
    if (player >= 0 && (self->field_234 == 2 || self->field_234 == 3)) {
        pos = *(JGeometry::TVec3<f32>*)fn_8023E724(player);
        f32 dx = *(f32*)(p + 0xc) - pos.x;
        if (!(dx > lbl_805407FC && dx < lbl_80540800)) player = -1;
    }
    switch ((u32)self->field_230) {
    case 1:
        if ((u8)self->v11()) {
            self->field_244 = fn_80226AE0(p + 0xc, *(s32*)(p + 4));
self->field_258 = fn_802F9908(*(void**)((u8*)lbl_8053AB10 + 0x20), *(s32*)(p + 4), self->field_244) & 0x3ff;
            self->v19(player); *(u8*)(p + 0x11c) = 0; break;
        }
        self->field_244 = fn_80226AE0(p + 0xc, *(s32*)(p + 4));
self->field_258 = fn_802F9908(*(void**)((u8*)lbl_8053AB10 + 0x20), *(s32*)(p + 4), self->field_244) & 0x3ff;
        if (self->field_258 == 0x12 || self->field_258 == 0x50 || self->field_258 == 0x14 ||
            self->field_258 == 0x52 || self->field_258 == 0x15a || self->field_258 == 0x41) self->field_230 = 2;
        break;
    case 2:
        if (player >= 0) {
            if (self->field_234 != 4 && self->field_234 != 7) {
            if (fn_8023513C(player) == 1 || fn_802353AC(player) == 1 ||
                fn_80233DA4(player) == 1 || fn_80235004(player) == 1) break;
            kind = self->v13();
            if (!fn_802D800C(fn_802D6A9C(), kind)) {
                if (((u8*)lbl_8053AAF8)[0x7e] == 1) {
                    found = false;
                    kind = *(s32*)((u8*)fn_801F856C() + 0x1008);
                    i = 0;
                    actor = 0;
                    for (; i < kind; actor += 4, i++) {
                        u8* other = *(u8**)((u8*)fn_801F856C() + actor + 8);
                        if (other && *(u32*)(other + 0x1a0) == 'SWTH' && *(s32*)(other + 0x198) != *(s32*)(p + 0x198)) {
                            flags = *(u32*)(other + 0x90);
                            if (player == fn_802D7E1C(fn_802D6A9C(), flags >> 27) && ((flags & 0x3f) == 0 || (flags & 0x3f) == 5)) found = true;
                        }
                    }
                    if (found) break;
                    if (fn_8022E39C(player, 10) != 1) break;
                    self->v10((u8)player, 1); fn_801F0E34(p, 0x30009, 0); self->v19(player);
                    self->field_230 = 3; self->field_248 = 5; self->field_250 = player; break;
                }
                if (player == 0) {
                    if (fn_8022E39C(player, 5) == 1) { self->v10((u8)player, 1); fn_801F0E34(p, 0x30009, 0); self->v19(player); self->field_248 = 5; }
                } else { self->v10((u8)player, 1); fn_801F0E34(p, 0x30009, 0); self->v19(player); self->field_248 = 0; }
                self->field_230 = 3; self->field_250 = player; break;
            }
            self->v19(player); self->field_250 = player; self->field_230 = 4;
            } else { self->v10((u8)player, 1); self->field_230 = 6; }
        } else {
            if (actor < 0) break;
            u8* other = (u8*)fn_801F666C(fn_801F856C(), actor);
            if (!other) break;
            if (lbl_8046C838[kind] != *(u32*)(other + 0x1a0)) break;
            self->field_250 = -1; self->field_254 = kind;
            self->v10(0xff, 1); fn_801F0E34(p, 0x30009, 0); self->v19(self->field_250);
            self->field_230 = 7; self->field_248 = 10;
        }
        break;
    case 3:
        fn_802302C4(self->field_250, 0xe8, 0xff);
        if (self->field_248 == 0) self->field_230 = 4; else --self->field_248;
        if (self->field_248 == 2 && (self->field_234 == 2 || self->field_234 == 3 || self->field_234 == 6)) fn_801F0E34(p, 0x30009, 0);
        break;
    case 4:
        if (player < 0) {
            if (fn_80230188(self->field_250)) break;
            if ((u8)self->v11() && (self->field_234 == 1 || self->field_234 == 3)) { *(u8*)(p + 0x11c) = 0; break; }
            if (self->field_234 == 8) { self->field_230 = 5; self->field_24C = self->field_240; break; }
            if ((u32)self->field_234 <= 1 || self->field_234 == 5) {
                actor = self->field_264;
                if (actor >= 0) {
                    if (fn_802D800C(fn_802D6A9C(), actor)) { *(u8*)(p + 0x11c) = 0; break; }
                } else {
                    actor = self->field_260;
                    if (actor >= 0 && fn_802D800C(fn_802D6A9C(), actor)) { *(u8*)(p + 0x11c) = 0; break; }
                }
                if (self->field_234 == 0 || self->field_234 == 5) { self->v10(0xff, 0); fn_802A3884(lbl_8053AC98, p + 0xc, player, *(s32*)(p + 4), self->field_258); }
                else { fn_802A3884(lbl_8053AC98, p + 0xc, player, *(s32*)(p + 4), self->field_258); }
            } else {
                if (self->field_234 == 2 || self->field_234 == 6) { self->v10(0xff, 0); fn_802A3884(lbl_8053AC98, p + 0xc, player, *(s32*)(p + 4), self->field_258); }
                else { fn_802A3884(lbl_8053AC98, p + 0xc, player, *(s32*)(p + 4), self->field_258); }
            }
            self->field_230 = 2;
        } else {
            fn_802302C4(player, 0xe8, 0xff);
            if (player == self->field_250) {
                if (self->field_234 == 5 || self->field_234 == 6) self->v10((u8)self->field_250, 1);
            } else { self->field_250 = player; self->v10((u8)self->field_250, 1); }
        }
        break;
    case 5:
        if (self->field_24C == 0) { self->v10(0xff, 0); fn_802A3884(lbl_8053AC98, p + 0xc, player, *(s32*)(p + 4), self->field_258); self->field_230 = 2; }
        else --self->field_24C;
        break;
    case 7:
        if (self->field_248 == 0) self->field_230 = 8; else --self->field_248;
        break;
    case 8:
        if (actor < 0 || (actor >= 0 && self->field_254 != kind)) { if (self->field_234 == 0 || self->field_234 == 1 || self->field_234 == 5 || self->field_234 == 8) {
    if (self->field_234 == 0 || self->field_234 == 5) { self->v10(0xff, 0); fn_802A3884(lbl_8053AC98, p + 0xc, self->field_250, *(s32*)(p + 4), self->field_258); }
    else { fn_802A3884(lbl_8053AC98, p + 0xc, self->field_250, *(s32*)(p + 4), self->field_258); }
} else {
    if (self->field_234 == 2 || self->field_234 == 6) self->v10(0xff, 0);
    fn_802A3884(lbl_8053AC98, p + 0xc, self->field_250, *(s32*)(p + 4), self->field_258);
}
self->field_230 = 2; }
        break;
    }
}
#pragma opt_propagation reset
extern "C" void fn_802A75F4(Tu2A6A4CActor* p) {
    if (*(s32*)((u8*)p + 0x230) != 1) {
        return;
    }
    if ((u8)p->v11()) {
        *(s32*)((u8*)p + 0x244) = fn_80226AE0(&p->field_0C, p->field_04);
        *(u16*)((u8*)p + 0x258) = fn_802F9908(*(void**)((u8*)lbl_8053AB10 + 0x20), p->field_04, *(s32*)((u8*)p + 0x244)) & 0x3ff;
        p->v19(-1);
        *((u8*)p + 0x11c) = 0;
        return;
    }
    *(s32*)((u8*)p + 0x244) = fn_80226AE0(&p->field_0C, p->field_04);
    *(u16*)((u8*)p + 0x258) = fn_802F9908(*(void**)((u8*)lbl_8053AB10 + 0x20), p->field_04, *(s32*)((u8*)p + 0x244)) & 0x3ff;
    if (*(u16*)((u8*)p + 0x258) != 0x12 && *(u16*)((u8*)p + 0x258) != 0x50 &&
        *(u16*)((u8*)p + 0x258) != 0x52 && *(u16*)((u8*)p + 0x258) != 0x41 &&
        *(u16*)((u8*)p + 0x258) != 0x43 && *(u16*)((u8*)p + 0x258) != 0x68 &&
        *(u16*)((u8*)p + 0x258) != 0x6a && *(u16*)((u8*)p + 0x258) != 0x15a &&
        (u16)(*(u16*)((u8*)p + 0x258) - 0x13) > 1 && *(u16*)((u8*)p + 0x258) != 0x51) {
        return;
    }
    *(s32*)((u8*)p + 0x230) = 2;
    if (*(u16*)((u8*)p + 0x258) == 0x41) {
        *(u16*)((u8*)p + 0x258) = 0x12;
    }
    s32 sw = *(s32*)((u8*)p + 0x264);
    if (sw < 0) {
        s32 count = *(s32*)((u8*)fn_801F856C() + 0x1008);
        s32 off;
        s32 i;
        i = 0;
        off = 0;
        for (; i < count; off += 4, i++) {
            u8* obj = *(u8**)((u8*)fn_801F856C() + off + 8);
            if (obj != 0 && (*(s32*)(obj + 0x1a0) == 0x53575434 || *(s32*)(obj + 0x1a0) == 0x4c4f5357) &&
                *(s32*)((u8*)p + 0x170) == *(s32*)(obj + 0x170) &&
                ((*(u32*)(obj + 0x90) & 0x1f) == 1 || (*(u32*)(obj + 0x90) & 0x1f) == 2)) {
                u32 v = *(u32*)(obj + 0x90);
                for (s32 k = 0; k < 4; k++) {
                    if (*(u32*)((u8*)p + 0x25c) == ((v >> lbl_8046C828[k]) & 0x1f)) {
                        *(u32*)((u8*)p + 0x260) = v >> 27;
                        if (fn_802D800C(fn_802D6A9C(), *(s32*)((u8*)p + 0x260))) {
                            p->v19(-1);
                            *((u8*)p + 0x11c) = 0;
                        } else if (*(u16*)((u8*)p + 0x258) == 0x13 || *(u16*)((u8*)p + 0x258) == 0x51) {
                            if (*(u16*)((u8*)p + 0x258) == 0x13) {
                                *(u16*)((u8*)p + 0x258) = 0x12;
                            } else {
                                *(u16*)((u8*)p + 0x258) = 0x51;
                            }
                            p->v10(0xff, 0);
                            fn_802A3884(lbl_8053AC98, &p->field_0C, -1, p->field_04, *(u16*)((u8*)p + 0x258));
                        }
                        break;
                    }
                }
            }
        }
        if (*(u16*)((u8*)p + 0x258) == 0x43 || *(u16*)((u8*)p + 0x258) == 0x68 ||
            *(u16*)((u8*)p + 0x258) == 0x6a || *(u16*)((u8*)p + 0x258) == 0x41) {
            if ((u8)p->v11()) {
                p->v19(-1);
                *((u8*)p + 0x11c) = 0;
            } else {
                *(s32*)((u8*)p + 0x230) = 1;
            }
        }
    } else {
        if (fn_802D800C(fn_802D6A9C(), sw)) {
            p->v19(-1);
            *((u8*)p + 0x11c) = 0;
        } else if (*(u16*)((u8*)p + 0x258) == 0x43 || *(u16*)((u8*)p + 0x258) == 0x68 ||
                   *(u16*)((u8*)p + 0x258) == 0x6a) {
            *(s32*)((u8*)p + 0x230) = 1;
        }
    }
}

extern f32 lbl_80540804;
extern f32 lbl_80540808;
extern f32 lbl_8054080C;
extern f32 lbl_80540810;
extern "C" void fn_802A7978(Actor* p) {
    register u8* base = (u8*)p;
    register f32 c;
    f32 d;
    f32 k;

    *(u32*)(base + 0x238) = ((*(u32*)(base + 0x90) >> 0x16) & 0x1f) + 1;
    *(u32*)(base + 0x23c) = ((*(u32*)(base + 0x90) >> 0x11) & 0x1f) + 1;
    *(u32*)(base + 0x240) = *(u32*)(base + 0x90) & 0x3e0;
    *(u32*)(base + 0x234) = *(u32*)(base + 0x90) & 0x1f;
    *(s32*)(base + 0x264) = (*(u32*)(base + 0x90) >> 0xc) & 0x1f;
    if (*(s32*)(base + 0x264) == 0) {
        *(s32*)(base + 0x264) = -1;
    }
    *(u32*)(base + 0x25c) = *(u32*)(base + 0x90) >> 0x1b;
    if (*(s32*)(base + 0x234) == 8 && *(s32*)(base + 0x240) == 0) {
        *(s32*)(base + 0x240) = 0x3c;
    }
    *(s32*)(base + 0x24c) = *(s32*)(base + 0x240);
    k = lbl_80540804;
    *(f32*)(base + 0xc) = *(f32*)(base + 0xc) + k;
    *(f32*)(base + 0x10) = *(f32*)(base + 0x10) + k;
    if (*(s32*)(base + 0x234) == 2 || *(s32*)(base + 0x234) == 3) {
        d = lbl_8054080C;
        c = lbl_80540808;
        *(f32*)(base + 0x60) = c;
        *(f32*)(base + 0x68) = d;
        *(f32*)(base + 0x64) = c;
        *(f32*)(base + 0x6c) = d;
    } else if (*(s32*)(base + 0x234) == 7) {
        register f32 a = lbl_80540810 * (f32)*(s32*)(base + 0x238);
        f32 b = lbl_80540810 * (f32)*(s32*)(base + 0x23c);
        *(f32*)(base + 0x64) = -b;
        *(f32*)(base + 0x60) = -a;
        *(f32*)(base + 0x6c) = b;
        *(f32*)(base + 0x68) = a;
    } else {
        d = lbl_8054080C;
        c = lbl_80540808;
        *(f32*)(base + 0x60) = c;
        *(f32*)(base + 0x68) = d;
        *(f32*)(base + 0x64) = c;
        *(f32*)(base + 0x6c) = d;
    }
    *(s32*)(base + 0x248) = 0;
    if (*(s32*)(base + 0x234) == 4 || *(s32*)(base + 0x234) == 7) {
        *(s32*)(base + 0x230) = 2;
    } else {
        *(s32*)(base + 0x230) = 1;
    }
    *(s32*)(base + 0x250) = -1;
    *(s32*)(base + 0x260) = -1;
}

extern "C" char lbl_804D0C68[];
extern "C" char memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[];
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" char memPool___30JASPoolAllocObject_9JAIStream[];
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*);
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" char memPool___35JASPoolAllocObject_13JAISoundChild[];
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" char memPool___27JASPoolAllocObject_6JAISeq[];
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*);
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" char memPool___26JASPoolAllocObject_5JAISe[];
extern "C" void __dt__18JASMemPool_5JAISeFv(void*);
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;
extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __register_global_object(void*, void (*)(void*), void*);
extern "C" void fn_802A7B18(void)
{
    static u32 c0[3];
    static u32 c1[3];
    static u32 c2[3];
    static u32 c3[3];
    static u32 c4[3];
    static u32 c5[3];
    static u32 c6[3];
    static u32 c7[3];
    static u32 c8[3];
    if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, c0);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, c1);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, c2);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, c3);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, c4);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, c5);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, c6);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, c7);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, c8);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}

