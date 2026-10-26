#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JMath/Inline.h"
#include "JSystem/JMath/JMath.h"
#include "JSystem/JGeometry/Box.h"

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
    s32 n;
    int i;
    f32 f31;
    f32 f30;
    f32 v;
    f32 f29;

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
        s32 h;
        n = *(s32*)(this_ + 0x198);
        h = fn_80238CB4(i);
        if (h == n) {
            if (mode <= 1) {
                v = *(f32*)((u8*)fn_8023E724(i) + 0x4);
                if (v < f30 && f31 < v) {
                    return FALSE;
                }
                if (!mode) {
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

extern "C" const f32 lbl_8046C1E0[][3];
extern "C" const f32 lbl_8046C1B0[][3];
extern "C" u8 fn_801F2618(void*, void*, s32);
extern "C" u8 fn_8023B0F4(int, void*, s32, s32, f32);
extern "C" int fn_8022CAF8(int);
extern "C" u8 fn_8022F478(int);
extern "C" u8 fn_8028C518(u8* this_, u8 mode) {
    s32 handle;
    int i;
    u8 result = 0;
    JGeometry::TVec3f old(*(JGeometry::TVec3f*)(this_ + 0xc));
    JGeometry::TVec3f delta;
    JGeometry::TBox2f box;
    s32 kind = *(u32*)(this_ + 0x90) & 3;
    if (kind == 3) return 1;
    if (kind == 0) {
        ((JGeometry::TVec3f*)(this_ + 0x3c))->set(lbl_8046C1E0[mode][0], lbl_8046C1E0[mode][1], lbl_8046C1E0[mode][2]);
        *(JGeometry::TVec3f*)(this_ + 0x18) += *(JGeometry::TVec3f*)(this_ + 0x3c);
    }
    ((JGeometry::TVec3f*)(this_ + 0x3c))->set(lbl_8046C1B0[mode][0], lbl_8046C1B0[mode][1], lbl_8046C1B0[mode][2]);
    *(JGeometry::TVec3f*)(this_ + 0xc) += *(JGeometry::TVec3f*)(this_ + 0x3c);
    delta.set(0.0f,0.0f,0.0f);
    if (fn_801F2618(this_, &delta, 0)) {
        switch(mode) {
        case 0: if(delta.x >= 0.0f) result = 1; break;
        case 1: if(delta.x <= 0.0f) result = 1; break;
        case 2: if(delta.y >= 0.0f) result = 1; break;
        case 3: if(delta.y <= 0.0f) result = 1; break;
        }
    } else result = 1;
    if (!result) {
        box.set(*(JGeometry::TBox2f*)(this_ + 0x60));
        result = 1;
        box.addPos(*(JGeometry::TVec2<f32>*)(this_ + 0xc));
        for(i=0;i<4;i++) {
            if(fn_8023B0F4(i,&box,*(s32*)(this_+4),0,0.0f)) {
                if(fn_8022CAF8(i)==5 && fn_8022F478(i)) continue;
                handle = *(s32*)(this_+0x198);
                int h = fn_80238CB4(i);
                if(h != handle) result = 0;
            }
        }
    }
    *(JGeometry::TVec3f*)(this_+0xc) = old;
    ((JGeometry::TVec3f*)(this_+0x3c))->set(0.0f,0.0f,0.0f);
    return result;
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
extern "C" u8 fn_8028D4DC(f32* this_, s32 a, void* c) {
    u8 r = fn_802D7544(fn_802D6A9C(), c);
    if (r == 0) {
        return 0;
    }
    u32 off = (u8)(r - 1);
    Vec v;
    Vec* table = (Vec*)lbl_8046C150;
    v.x = 16.0f * ((f32)(a + 1) * table[off].x);
    v.y = 16.0f * ((f32)(a + 1) * table[off].y);
    v.z = 0.0f;
    JMathInlineVEC::PSVECAdd((Vec*)this_, &v, (Vec*)this_);
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
extern "C" const char lbl_8046C120[];

extern "C" u8 fn_8028C518(u8* p, u8 idx);
extern "C" void fn_8029E9EC(void* sys, void* pos, u32 room, u32 id, s32 c, u32 idx);
extern "C" void fn_801F0E34(void* p, u32 a, s32 b);
extern "C" void fn_8028D5D0(u8* this_) {
    JGeometry::TVec3<f32> v;
    JGeometry::TVec3<f32> sv;
    s32 n;
    s32 x;
    this_[0x244] = 0;
    n = *(u32*)(this_ + 0x90) & 3;
    if (n == 0) {
        x = (s32)*(f32*)(this_ + 0xc);
        *(f32*)(this_ + 0xc) = (f32)(x / 16 * 16 + 8);
        x = (s32)*(f32*)(this_ + 0x10);
        *(f32*)(this_ + 0x10) = (f32)(x / 16 * 16 + 8);
        const f32* t = (const f32*)(lbl_8046C120 + ((*(u32*)(this_ + 0x90)>>2)&3)*12);
        ((JGeometry::TVec3<f32>*)(this_+0x3c))->set(*(const JGeometry::TVec3<f32>*)t);
        v = *(JGeometry::TVec3<f32>*)(this_+0x3c);
        v.normalize();
        v.scale(lbl_80540520, v);
        v += *(JGeometry::TVec3<f32>*)(this_+0xc);
        if ((u16)fn_8022461C(&v.x, *(s32*)(this_+4)) == 0x50) {
            ((JGeometry::TVec3<f32>*)(this_+0x3c))->normalize();
            ((JGeometry::TVec3<f32>*)(this_+0x3c))->scale(lbl_80540500, *(JGeometry::TVec3<f32>*)(this_+0x3c));
        }
    } else {
        if (((*(u32*)(this_+0x90)>>9)&1)==0) {
            if ((u8)fn_8028D4DC((f32*)(this_+0xc),n,*(void**)(this_+0x16c))) {
                this_[0x244]=1;
                ((Actor*)this_)->v10(0xff,1);
            }
        }
        *(f32*)(this_+0x3c)=lbl_80540504;
        *(f32*)(this_+0x40)=lbl_80540504;
        *(f32*)(this_+0x44)=lbl_80540504;
    }
    *(JGeometry::TVec3<f32>*)(this_+0x230) = *(JGeometry::TVec3<f32>*)(this_+0xc);
    *(u32*)(this_ + 0x248) = 0;
    this_[0x24c] = 1;

    if (((s32)*(u32*)(this_ + 0x90)&3) == 0) {
        f32 b;
        f32 a;
        a = lbl_8054054C;
        b = lbl_80540550;
        *(f32*)(this_ + 0x60) = a;
        *(f32*)(this_ + 0x64) = a;
        *(f32*)(this_ + 0x68) = b;
        *(f32*)(this_ + 0x6c) = b;
        *(f32*)(this_ + 0x80) = a;
        *(f32*)(this_ + 0x84) = a;
        *(f32*)(this_ + 0x88) = b;
        *(f32*)(this_ + 0x8c) = b;
        *(s32*)(this_+0x1a4) = 1;
        this_[0x24c] = 0;
    } else if (((s32)*(u32*)(this_ + 0x90)&3) == 1) {
        f32 b;
        f32 a;
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
        *(s32*)(this_+0x1a4) = 2;
    } else if (((s32)*(u32*)(this_ + 0x90)&3) == 2) {
        f32 b;
        f32 a;
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
        *(s32*)(this_+0x1a4) = 3;
    } else if (((s32)*(u32*)(this_ + 0x90)&3) == 3) {
        f32 b;
        f32 a;
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
        *(s32*)(this_+0x1a4) = 4;
    }

    *(JGeometry::TVec3<f32>*)(this_+0x18) = *(JGeometry::TVec3<f32>*)(this_+0xc);
    sv = *(JGeometry::TVec3<f32>*)(this_+0x3c);
    if (!fn_8028C518(this_, (*(u32*)(this_+0x90)>>2)&3)) {
        this_[0x11c] = 0;
        return;
    }
    *(JGeometry::TVec3<f32>*)(this_+0x18) = *(JGeometry::TVec3<f32>*)(this_+0xc);
    if (((s32)*(u32*)(this_ + 0x90)&3) == 0) {
        ((JGeometry::TVec3<f32>*)(this_+0x3c))->set(sv.x,sv.y,sv.z);
    u32 flags = *(u32*)(this_ + 0x90);
    u32 kind = (flags >> 4) & 7;
    u32 dir = (flags >> 2) & 3;
    fn_8029E9EC(lbl_8053AC98, this_+0xc, *(u32*)(this_ + 4), (u16)(kind + 0x21), 0, dir);
    fn_801F0E34(this_, 0x30004, 0);
    }
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0xb8) = 2;
    this_[0x24d] = 0;
    this_[0x24e] = 0;
    if ((*(u32*)(this_+0x90)&3) != 0) {
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
#include "JSystem/JAudio/JASFakeMatchFSA.h"

