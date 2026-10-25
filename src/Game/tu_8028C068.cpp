#include "Game/Actor.h"

struct YasiDrawKey {
    s32 a, b;
    YasiDrawKey() { a = -1; b = -1; }
};
struct YasiDrawParam {
    u8 map[16];
    YasiDrawKey key;
    s32 c;
    u8 palette;
    u8 color;
    u8 f1e, f1f, f20, f21, f22, f23, f24, f25, f26;
    s32 blend;
    u8 f2c, f2d, f2e;
    s32 g;
    s32 h;
    s32 i;

    YasiDrawParam() {
        for (u8 n = 0; n < 16; n++) {
            map[n] = n;
        }
        key.a = -1;
        key.b = 0;
        c = 0;
        palette = 0;
        color = 0;
        f1e = 0;
        f1f = 1;
        f20 = 1;
        f21 = 0;
        f22 = 0;
        f23 = 0;
        f24 = 0;
        f25 = 0;
        f26 = 1;
        blend = 3;
        f2c = 1;
        f2d = 0;
        f2e = 0;
        g = -1;
        h = 0;
        i = 2;
    }
};
extern "C" const char lbl_8046C210[];
extern "C" const f32 lbl_80540500;
extern "C" void fn_801F06F0(void* p, const char* name, s32 id, void* param, s32 a, f32 f1, f32 f2);
extern "C" void fn_80307AC8(void* a, u32 b, void* pos, s32 id, s32 c, s32 d, s32 e);


extern "C" char lbl_804A7A10[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_8028C068(Actor* p, s16 n) {
    if (p != 0) {
        *(void**)p = lbl_804A7A10;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern void* lbl_8053AC98;
extern "C" void fn_8029E928(void* sys, void* pos, u32 tag, s32 id);
extern "C" void fn_8028C0C8(u8* this_) {
    s32 x;

    x = (s32)*(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0xc) = (f32)((x + 4) / 8 * 8);
    x = (s32)*(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x10) = (f32)((x + 4) / 8 * 8);
    if ((*(u32*)(this_ + 0x90) & 3) == 0) {
        fn_8029E928(lbl_8053AC98, this_ + 0xc, *(u32*)(this_ + 0x4), 0x20);
    }
    *(u8*)(this_ + 0x11c) = 0;
}

extern "C" void fn_8028C190(u8* this_) {
    s32 idx = 0;
    YasiDrawParam param;
    s32 n = *(u32*)(this_ + 0x90) & 3;
    if (n != 0) {
        *(s8*)&param.color = -1;
        param.palette = 0;
        fn_801F06F0(this_, lbl_8046C210, n + 4, &param, 0, lbl_80540500, lbl_80540500);
        fn_80307AC8(*(void**)(this_ + 0x198), *(u32*)(this_ + 0x4), this_ + 0xc, n + 4, 0, 0, -1);
    } else {
        s32 m = (*(u32*)(this_ + 0x90) >> 4) & 7;
        if (m != 0) {
            idx = m + 3;
        }
        fn_801F06F0(this_, lbl_8046C210, idx + 0x45, 0, 0, lbl_80540500, lbl_80540500);
        fn_80307AC8(*(void**)(this_ + 0x198), *(u32*)(this_ + 0x4), this_ + 0xc, idx + 0x45, 0, 0, -1);
    }
}

extern "C" int fn_80238CB4(int idx);
extern "C" void* fn_8023E724(int idx);
extern "C" BOOL fn_8028C364(u8* this_, u8 mode) {
    s32 i;
    s32 n;
    f32 f31;
    f32 f30;
    f32 f29;
    f32 v;

    if (mode <= 1) {
        f31 = *(f32*)(this_ + 0x6c) + *(f32*)(this_ + 0x10);
        f29 = *(f32*)(this_ + 0xc);
        f30 = *(f32*)(this_ + 0x64) + *(f32*)(this_ + 0x10);
    } else {
        f31 = *(f32*)(this_ + 0x68) + *(f32*)(this_ + 0xc);
        f29 = *(f32*)(this_ + 0x10);
        f30 = *(f32*)(this_ + 0x60) + *(f32*)(this_ + 0xc);
    }

    for (i = 0; i < 4; i++) {
        n = *(s32*)(this_ + 0x198);
        if (fn_80238CB4(i) == n) {
            if (mode <= 1) {
                v = *(f32*)((u8*)fn_8023E724(i) + 0x4);
                if (v < f30 && f31 < v) {
                    return FALSE;
                }
                if (mode == 0) {
                    v = *(f32*)((u8*)fn_8023E724(i) + 0x0);
                    if (v > f29) {
                        return FALSE;
                    }
                } else {
                    v = *(f32*)((u8*)fn_8023E724(i) + 0x0);
                    if (v < f29) {
                        return FALSE;
                    }
                }
            } else {
                v = *(f32*)((u8*)fn_8023E724(i) + 0x0);
                if (v < f30 && f31 < v) {
                    return FALSE;
                }
                if (mode == 2) {
                    v = *(f32*)((u8*)fn_8023E724(i) + 0x4);
                    if (v > f29) {
                        return FALSE;
                    }
                } else {
                    v = *(f32*)((u8*)fn_8023E724(i) + 0x4);
                    if (v < f29) {
                        return FALSE;
                    }
                }
            }
        }
    }
    return TRUE;
}

extern "C" void fn_80239914(f32* rect, s32 room, s32 handle);
extern "C" void fn_8020D7D0(void* a, s32 b, void* c);
extern "C" void* fn_8020D58C(f32* a);
extern "C" s16 fn_8022461C(f32* a, s32 b);
extern "C" const f32 lbl_80540510;
extern "C" void fn_8028C7D0(u8* this_) {
    f32 rect[4];
    f32 x;
    rect[0] = *(f32*)(this_ + 0x60) + *(f32*)(this_ + 0xc);
    rect[1] = *(f32*)(this_ + 0x64) + *(f32*)(this_ + 0x10);
    rect[2] = *(f32*)(this_ + 0x68) + *(f32*)(this_ + 0xc);
    rect[3] = *(f32*)(this_ + 0x6c) + *(f32*)(this_ + 0x10);
    fn_80239914(rect, *(s32*)(this_ + 0x4), *(s32*)(this_ + 0x198));
}

extern "C" s16 fn_8022461C(float*, s32);
extern "C" int fn_8028D470(Actor* this_, int a, float* b) {
    if ((s32)(u16)fn_8022461C(b, a) == 0xd) {
        return 0;
    }
    return this_->Actor::v17(a, b);
}

extern "C" char lbl_8046C150[];
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D7544(void* a, void* b);
extern "C" int fn_8028D4DC(f32* this_, s32 a, void* c) {
    u8 r = fn_802D7544(fn_802D6A9C(), c);
    if (r == 0) {
        return 0;
    }
    f32* d = (f32*)(lbl_8046C150 + (u8)(r - 1) * 12);
    f32 x = (f32)(a + 1);
    this_[0] = this_[0] + 16.0f * (x * d[0]);
    this_[1] = this_[1] + 16.0f * (x * d[1]);
    this_[2] = this_[2] + 0.0f;
    return 1;
}

extern "C" int __float_epsilon[];
extern "C" const f32 lbl_80540504;
extern "C" const f32 lbl_80540514;
extern "C" const f32 lbl_80540518;
extern "C" const f32 lbl_8054051C;
extern "C" const f32 lbl_80540520;
extern "C" const f32 lbl_8054054C;
extern "C" const f32 lbl_80540550;
extern "C" const f32 lbl_80540554;
extern "C" const f32 lbl_80540558;
extern "C" const f32 lbl_8054055C;
extern "C" const f32 lbl_80540560;
extern "C" const f32 lbl_80540564;
extern "C" const f32 lbl_80540568;
extern "C" char lbl_8046C120[];
extern "C" int fn_8028D4DC(f32* this_, s32 a, void* c);
extern "C" u8 fn_8028C518(void* p, u32 idx);
extern "C" void fn_8029E9EC(void* sys, void* pos, u32 room, u32 id, s32 c, u32 idx);
extern "C" void fn_801F0E34(void* p, u32 a, s32 b);
extern "C" void fn_8028D5D0(u8* this_) {
    s32 n;
    s32 idx;
    s32 x;
    f32 v[3];
    f32 tmp[3];
    f32 sv[3];
    f32 sq;
    f32 inv;
    f32 y;
    f32 a;
    f32 b;
    f32* vel;
    f32* pos;
    f32* t;
    f32* p18;

    this_[0x244] = 0;
    n = *(u32*)(this_ + 0x90) & 3;
    idx = (*(u32*)(this_ + 0x90) >> 2) & 3;
    vel = (f32*)(this_ + 0x3c);
    pos = (f32*)(this_ + 0xc);
    if (n == 0) {
        x = (s32)pos[0];
        pos[0] = (f32)(x / 16 * 16 + 8);
        x = (s32)pos[1];
        pos[1] = (f32)(x / 16 * 16 + 8);
        t = (f32*)(lbl_8046C120 + idx * 12);
        vel[0] = t[0];
        vel[1] = t[1];
        vel[2] = t[2];
        v[0] = vel[0];
        v[1] = vel[1];
        v[2] = vel[2];
        sq = vel[2] * vel[2] + vel[0] * vel[0] + vel[1] * vel[1];
        if (sq > lbl_80540514 * *(f32*)__float_epsilon) {
            y = __frsqrte(sq);
            inv = lbl_80540518 * y * (lbl_8054051C - (sq * (y * y)));
            v[0] *= inv;
            v[1] *= inv;
            v[2] *= inv;
        }
        v[0] *= lbl_80540520;
        v[1] *= lbl_80540520;
        v[2] *= lbl_80540520;
        tmp[0] = v[0] + pos[0];
        tmp[1] = v[1] + pos[1];
        tmp[2] = v[2] + pos[2];
        if ((u16)fn_8022461C(tmp, *(s32*)(this_ + 4)) == 0x50) {
            sq = vel[2] * vel[2] + vel[0] * vel[0] + vel[1] * vel[1];
            if (sq > lbl_80540514 * *(f32*)__float_epsilon) {
                y = __frsqrte(sq);
                inv = lbl_80540518 * y * (lbl_8054051C - (sq * (y * y)));
                vel[0] *= inv;
                vel[1] *= inv;
                vel[2] *= inv;
            }
            vel[0] *= lbl_80540500;
            vel[1] *= lbl_80540500;
            vel[2] *= lbl_80540500;
        }
    } else {
        if ((*(u32*)(this_ + 0x90) & 0x200) == 0) {
            if (fn_8028D4DC(pos, n, *(void**)(this_ + 0x16c))) {
                this_[0x244] = 1;
                ((void (*)(void*, u32, s32))(*(void***)this_)[12])(this_, 0xff, 1);
            }
        }
        vel[0] = lbl_80540504;
        vel[1] = lbl_80540504;
        vel[2] = lbl_80540504;
    }

    *(f32*)(this_ + 0x230) = pos[0];
    *(f32*)(this_ + 0x234) = pos[1];
    *(f32*)(this_ + 0x238) = pos[2];
    *(u32*)(this_ + 0x248) = 0;
    this_[0x24c] = 1;

    if (n == 0) {
        a = lbl_8054054C;
        b = lbl_80540550;
        this_[0x24c] = 0;
        *(f32*)(this_ + 0x60) = a;
        *(f32*)(this_ + 0x64) = a;
        *(f32*)(this_ + 0x68) = b;
        *(f32*)(this_ + 0x6c) = b;
        *(f32*)(this_ + 0x80) = a;
        *(f32*)(this_ + 0x84) = a;
        *(f32*)(this_ + 0x88) = b;
        *(f32*)(this_ + 0x8c) = b;
    } else if (n == 1) {
        a = lbl_80540554;
        b = lbl_80540558;
        *(f32*)(this_ + 0x60) = a;
        *(f32*)(this_ + 0x64) = a;
        *(f32*)(this_ + 0x68) = b;
        *(f32*)(this_ + 0x6c) = b;
        *(f32*)(this_ + 0x80) = a;
        *(f32*)(this_ + 0x84) = a;
        *(f32*)(this_ + 0x88) = b;
        *(f32*)(this_ + 0x8c) = b;
    } else if (n == 2) {
        a = lbl_8054055C;
        b = lbl_80540560;
        *(f32*)(this_ + 0x60) = a;
        *(f32*)(this_ + 0x64) = a;
        *(f32*)(this_ + 0x68) = b;
        *(f32*)(this_ + 0x6c) = b;
        *(f32*)(this_ + 0x80) = a;
        *(f32*)(this_ + 0x84) = a;
        *(f32*)(this_ + 0x88) = b;
        *(f32*)(this_ + 0x8c) = b;
    } else if (n == 3) {
        a = lbl_80540564;
        b = lbl_80540568;
        *(f32*)(this_ + 0x60) = a;
        *(f32*)(this_ + 0x64) = a;
        *(f32*)(this_ + 0x68) = b;
        *(f32*)(this_ + 0x6c) = b;
        *(f32*)(this_ + 0x80) = a;
        *(f32*)(this_ + 0x84) = a;
        *(f32*)(this_ + 0x88) = b;
        *(f32*)(this_ + 0x8c) = b;
    }
    *(s32*)(this_ + 0x1a4) = n + 1;

    p18 = (f32*)(this_ + 0x18);
    p18[0] = pos[0];
    p18[1] = pos[1];
    p18[2] = pos[2];
    sv[0] = vel[0];
    sv[1] = vel[1];
    sv[2] = vel[2];
    if (!fn_8028C518(this_, idx)) {
        this_[0x11c] = 0;
        return;
    }
    p18[0] = pos[0];
    p18[1] = pos[1];
    p18[2] = pos[2];
    if (n == 0) {
        vel[0] = sv[0];
        vel[1] = sv[1];
        vel[2] = sv[2];
    }
    fn_8029E9EC(lbl_8053AC98, pos, *(u32*)(this_ + 4), (u16)(((*(u32*)(this_ + 0x90) >> 4) & 7) + 0x21), 0, idx);
    fn_801F0E34(this_, 0x30004, 0);
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0xb8) = 2;
    this_[0x24d] = 0;
    this_[0x24e] = 0;
    if (n != 0) {
        this_[0x24e] = (*(u32*)(this_ + 0x90) >> 10) & 1;
    }
}

extern "C" char lbl_804D0168[];
extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __register_global_object(void*, void (*)(void*), void*);
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
extern "C" void fn_8028DB54(void) {
    char* base = lbl_804D0168;
    if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, base + 0x0);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, base + 0xc);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, base + 0x18);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, base + 0x24);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, base + 0x30);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, base + 0x3c);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, base + 0x48);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, base + 0x54);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, base + 0x60);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}

