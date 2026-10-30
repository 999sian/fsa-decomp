#include "types.h"
#include "JSystem/JGeometry/Vec.h"

struct SubObject {
    void* pad0;
    void* pad4;
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual ~SubObject();
};

struct SubVT {
    void* slot[12];
    void (*fn12)(void*, s32);
};
struct SubObj {
    void* pad0;
    void* pad4;
    SubVT* vt;
};


extern "C" void* fn_8013C824(void);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D6BF8(void*, s32);
extern "C" void fn_8013A884(u32*);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void*, void*);
extern "C" char* fn_8016A3AC(void);
extern "C" void fn_80128C58(u8);
extern "C" void fn_801EE434(void*);
extern "C" u8 fn_802DEBF8(void);
extern "C" void fn_80458FF0(void* obj, u32 id, s32 a, s32 b);
extern void* lbl_8053AF80;
extern "C" u8 fn_802DEBF8(void);
extern "C" void fn_80458FF0(void* obj, u32 id, s32 a, s32 b);
extern void* lbl_8053AF80;
extern "C" void fn_802B3674(void) {
    u32 mode = *(u32*)((char*)lbl_8053AF80 + 0x60);
    u8 busy = fn_802DEBF8();
    if (busy == 0 && mode != 0 && mode != 0x1000021 && mode != 0x1000009 && mode - 0x1000018 > 1 && mode != 0x1000001 && mode != 0x100000d && mode != 0x1000007 && mode != 0x100002e && mode != 0x1000029 && mode != 0x1000024 && mode != 0x100000e) {
        fn_80458FF0(lbl_8053AF80, 0x100000e, 0, 0);
    }
}

extern "C" void fn_802B3724(char* p) {
    *(s32*)(p + 0x310) += 4;
    if (*(s32*)(p + 0x2e0) > *(s32*)(p + 0x2f0)) {
        *(s32*)(p + 0x2e0) = *(s32*)(p + 0x2e0) + *(s32*)(p + 0x318);
    } else {
        *(s32*)(p + 0x2e0) = *(s32*)(p + 0x2f0);
    }
    if (*(s32*)(p + 0x2e4) > *(s32*)(p + 0x2f4)) {
        *(s32*)(p + 0x2e4) = *(s32*)(p + 0x2e4) + *(s32*)(p + 0x31c);
    } else {
        *(s32*)(p + 0x2e4) = *(s32*)(p + 0x2f4);
    }
    if (*(s32*)(p + 0x2e8) > *(s32*)(p + 0x2f8)) {
        *(s32*)(p + 0x2e8) = *(s32*)(p + 0x2e8) + *(s32*)(p + 0x320);
    } else {
        *(s32*)(p + 0x2e8) = *(s32*)(p + 0x2f8);
    }
    if (*(s32*)(p + 0x310) >= *(s32*)(p + 0x314)) {
        *(s32*)(p + 0x310) = *(s32*)(p + 0x314);
        *(s32*)(p + 0x2e0) = *(s32*)(p + 0x2f0);
        *(s32*)(p + 0x2e4) = *(s32*)(p + 0x2f4);
        *(s32*)(p + 0x2e8) = *(s32*)(p + 0x2f8);
        *(s32*)(p + 0x240) = 9;
    }
    fn_80128C58((u8)*(s32*)(p + 0x310));
    u32 val = *(u32*)(p + 0x2e0) << 24 | *(u32*)(p + 0x2e4) << 16 | *(u32*)(p + 0x2e8) << 8 | *(u32*)(p + 0x2ec);
    fn_8013A884(&val);
}

extern "C" void fn_80128C58(u8 a);
extern "C" void fn_802B3838(char* p) {
    u32 val;
    *(s32*)(p + 0x310) -= 4;
    if (*(s32*)(p + 0x2e0) > *(s32*)(p + 0x2f0)) {
        *(s32*)(p + 0x2e0) += *(s32*)(p + 0x318);
    } else {
        *(s32*)(p + 0x2e0) = *(s32*)(p + 0x2f0);
    }
    if (*(s32*)(p + 0x2e4) > *(s32*)(p + 0x2f4)) {
        *(s32*)(p + 0x2e4) += *(s32*)(p + 0x31c);
    } else {
        *(s32*)(p + 0x2e4) = *(s32*)(p + 0x2f4);
    }
    if (*(s32*)(p + 0x2e8) > *(s32*)(p + 0x2f8)) {
        *(s32*)(p + 0x2e8) += *(s32*)(p + 0x320);
    } else {
        *(s32*)(p + 0x2e8) = *(s32*)(p + 0x2f8);
    }
    if (*(s32*)(p + 0x310) <= *(s32*)(p + 0x314)) {
        *(s32*)(p + 0x310) = *(s32*)(p + 0x314);
        *(s32*)(p + 0x2e0) = *(s32*)(p + 0x2f0);
        *(s32*)(p + 0x2e4) = *(s32*)(p + 0x2f4);
        *(s32*)(p + 0x2e8) = *(s32*)(p + 0x2f8);
        *(s32*)(p + 0x240) = 9;
    }
    fn_80128C58((u8)*(s32*)(p + 0x310));
    val = *(u32*)(p + 0x2ec) | (*(u32*)(p + 0x2e8) << 8 | (*(u32*)(p + 0x2e0) << 24 | *(u32*)(p + 0x2e4) << 16));
    fn_8013A884(&val);
}

extern "C" void fn_802B394C(char* p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 mode) {
    *(s32*)(p + 0x240) = mode;
    if (mode == 9) {
        *(s32*)(p + 0x2e0) = a;
        *(s32*)(p + 0x2e4) = b;
        *(s32*)(p + 0x2e8) = c;
        *(s32*)(p + 0x2ec) = d;
        *(s32*)(p + 0x310) = e;
        return;
    }
    *(s32*)(p + 0x2f0) = a;
    *(s32*)(p + 0x2f4) = b;
    *(s32*)(p + 0x2f8) = c;
    *(s32*)(p + 0x2ec) = d;
    *(s32*)(p + 0x314) = e;
    *(s32*)(p + 0x318) = (*(s32*)(p + 0x2f0) - *(s32*)(p + 0x2e0)) / 4;
    *(s32*)(p + 0x31c) = (*(s32*)(p + 0x2f4) - *(s32*)(p + 0x2e4)) / 4;
    *(s32*)(p + 0x320) = (*(s32*)(p + 0x2f8) - *(s32*)(p + 0x2e8)) / 4;
    if (*(s32*)(p + 0x310) >= *(s32*)(p + 0x314)) {
        return;
    }
    *(s32*)(p + 0x240) = 0xc;
}

extern "C" void fn_802B39E8(char* p) {
    *(s32*)(p + 0x290) = 0;
    if (*(void**)(p + 0x23c) != NULL) {
        void* mgr = *(void**)((char*)fn_8013C824() + 0xc);
        forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)(p + 0x23c));
        *(void**)(p + 0x23c) = NULL;
    }
}

extern "C" void fn_802B3A3C(char* p) {
    *(s32*)(p + 0x2b8) = 0;
}

extern "C" void fn_802B3A48(char* p) {
    char* q = fn_8016A3AC();
    q[0x1ee] = 0;
    void* e = *(void**)(p + 0x234);
    if (e != NULL) {
        fn_801EE434(e);
    }
    e = *(void**)(p + 0x238);
    if (e != NULL) {
        fn_801EE434(e);
    }
    e = *(void**)(p + 0x23c);
    if (e != NULL) {
        fn_801EE434(e);
    }
    p[0x11c] = 0;
}

extern "C" void fn_802B3AB4(void) {
}

extern "C" u8 fn_80236B50(s32);
extern "C" void fn_801F856C(void);
extern char* lbl_8053AAF8;
extern char lbl_80529DEC[];
extern char* lbl_8053AB10;
extern float lbl_80540A18[];
extern const f32 lbl_80540A1C;
extern "C" void fn_802B3AB8(char* this_) {
    u32 flag = 0;
    if (*(u8*)(lbl_8053AAF8 + 0x7f) != 0) {
        if (fn_80236B50(0) && fn_80236B50(1) && fn_80236B50(2) && fn_80236B50(3)) {
        }
    }
}

extern "C" void __dt__5ActorFv(void* this_, s32 flag);
extern char lbl_804A8638[];
extern "C" void* fn_802B51C0(void* this_, s16 how) {
 if(this_) {
  *(void**)this_=lbl_804A8638;
  char* p=fn_8016A3AC();p[0x1ee]=0;
  void* h0=*(void**)((char*)this_+0x234);
  if(h0) fn_801EE434(h0);
  void* h1=*(void**)((char*)this_+0x238);
  if(h1) fn_801EE434(h1);
  void* h2=*(void**)((char*)this_+0x23c);
  if(h2) fn_801EE434(h2);
  SubObject* sub=*(SubObject**)((char*)this_+0x230);
  if(sub) delete sub;
  __dt__5ActorFv(this_,0);
  if(how>0) ::operator delete(this_);
 }
 return this_;
}

extern "C" u8 fn_802DEBA0(void);
extern "C" void fn_80138B7C(void*);
extern "C" void fn_80458F9C(void*, s32);
extern "C" u8 fn_801B7550(void);
extern "C" s32 fn_801CD664(s32);
extern "C" void* fn_8013CC50(u32, void*, u32, u32, u32, u32, u32, u32, f32);
extern "C" void fn_8018330C(void*);
extern "C" void fn_802D7440(void*, s32);
extern "C" u8 fn_802D75BC(void*, s32);
extern f32 lbl_80540A20;
extern f32 lbl_80540A24;
extern f32 lbl_80540A28;
extern f32 lbl_80540A2C;
extern f32 lbl_80540A30;

class Actor802B {
public:
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual u8 v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54(s32, s32, s32, s32, s32, s32);
    virtual void v58();
    virtual void v5C();
    virtual void v60();
};

struct Rgba802B {
    u8 r, g, b, a;
};

struct Vec802B {
    f32 x, y, z;
};

class WaveController {
public:
    WaveController(s32 a, s32 b, s32 c);
    ~WaveController();
private:
    unsigned char pad[0x5c];
};

typedef void (*VFn802B)(char*);
typedef u8 (*VFnB802B)(char*);
typedef void (*VFn6802B)(char*, s32, s32, s32, s32, s32, s32);
#define VT802B(p, off) (*(void**)(*(char**)(p) + (off)))

extern "C" void fn_802B5284(char* p) {
    u32 val;
    if (*(s32*)(p + 0x288) == 4) {
        fn_802D6BF8(fn_802D6A9C(), 0);
        *(s32*)(p + 0x288) = 0;
        *(s32*)(p + 0x2e0) = *(s32*)(p + 0x300);
        *(s32*)(p + 0x2e4) = *(s32*)(p + 0x304);
        *(s32*)(p + 0x2e8) = *(s32*)(p + 0x308);
        if (*(u32*)(p + 0x234) != 0) {
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)fn_8013C824() + 0xc), *(void**)(p + 0x234));
            *(s32*)(p + 0x234) = 0;
        }
        if (*(u32*)(p + 0x238) != 0) {
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)fn_8013C824() + 0xc), *(void**)(p + 0x238));
            *(s32*)(p + 0x238) = 0;
        }
        val = *(u32*)(p + 0x2ec) | (*(u32*)(p + 0x2e8) << 8 | (*(u32*)(p + 0x2e0) << 24 | *(u32*)(p + 0x2e4) << 16));
        fn_8013A884(&val);
    }
}

extern "C" void fn_802B5360(char* p) {
    Rgba802B c;
    Vec802B v;
    *(void**)(p + 0x234) = 0;
    *(void**)(p + 0x238) = 0;
    *(void**)(p + 0x23c) = 0;
    *(s32*)(p + 0x260) = (*(u32*)(p + 0x90) >> 22) & 7;
    *(s32*)(p + 0x264) = (*(u32*)(p + 0x90) >> 21) & 1;
    *(s32*)(p + 0x268) = (*(u32*)(p + 0x90) >> 20) & 1;
    *(s32*)(p + 0x270) = (*(u32*)(p + 0x90) >> 19) & 1;
    *(s32*)(p + 0x274) = (*(u32*)(p + 0x90) >> 18) & 1;
    *(s32*)(p + 0x278) = (*(u32*)(p + 0x90) >> 17) & 1;
    *(s32*)(p + 0x27c) = (*(u32*)(p + 0x90) >> 16) & 1;
    *(s32*)(p + 0x280) = (*(u32*)(p + 0x90) >> 15) & 1;
    *(s32*)(p + 0x288) = (*(u32*)(p + 0x90) >> 13) & 3;
    *(s32*)(p + 0x28c) = (*(u32*)(p + 0x90) >> 12) & 1;
    *(s32*)(p + 0x290) = (*(u32*)(p + 0x90) >> 11) & 1;
    *(s32*)(p + 0x294) = (*(u32*)(p + 0x90) >> 10) & 1;
    *(s32*)(p + 0x298) = (*(u32*)(p + 0x90) >> 9) & 1;
    *(s32*)(p + 0x29c) = (*(u32*)(p + 0x90) >> 8) & 1;
    *(s32*)(p + 0x2a0) = (*(u32*)(p + 0x90) >> 7) & 1;
    *(s32*)(p + 0x2a4) = (*(u32*)(p + 0x90) >> 6) & 1;
    *(s32*)(p + 0x2a8) = (*(u32*)(p + 0x90) >> 5) & 1;
    *(s32*)(p + 0x2ac) = (*(u32*)(p + 0x90) >> 4) & 1;
    *(s32*)(p + 0x2b4) = (*(u32*)(p + 0x90) >> 26) & 1;
    *(s32*)(p + 0x2b8) = (*(u32*)(p + 0x90) >> 25) & 1;
    *(s32*)(p + 0x2d8) = *(u32*)(p + 0x90) & 0xf;
    if (fn_802DEBA0() == 1 && *(s32*)(p + 0x2d8) != 0xf && *(s32*)(p + 0x2d8) != 0xd) {
        *(s32*)(p + 0x2d8) = 0;
    }
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x244) = 0;
    switch (*(s32*)(p + 0x260)) {
    case 1:
        fn_80138B7C(lbl_8053AAF8);
        break;
    case 2:
        fn_80458FF0(lbl_8053AF80, 0x1000004, 0, 0);
        break;
    case 3:
        fn_80458F9C(lbl_8053AF80, 0x78);
        break;
    }
    if (*(s32*)(p + 0x264) != 0) {
        p[0x2d0] = fn_8016A3AC()[0x1ec];
        p[0x2d1] = (s32)(*(u8*)(*(char**)(lbl_8053AB10 + 0x2c) + 0xc) * 0x2f) / 0xff;
    } else {
        p[0x2d0] = fn_8016A3AC()[0x1ec];
    }
    fn_8016A3AC()[0x1ec] = p[0x2d0];
    p[0x2d2] = fn_8016A3AC()[0x1ed];
    if (*(s32*)(p + 0x268) != 0) {
        *(s32*)(p + 0x26c) = 0x8f;
    }
    fn_8016A3AC()[0x1ed] = p[0x2d2];
    if (*(s32*)(p + 0x270) != 0) {
        char* g = fn_8016A3AC();
        g[0x1c7] = 1;
    }
    if (*(s32*)(p + 0x274) != 0) {
        char* g = fn_8016A3AC();
        g[0x1c4] = 1;
    }
    p[0x2d3] = fn_8016A3AC()[0x1f1];
    if (*(s32*)(p + 0x280) != 0) {
        *(s32*)(p + 0x284) = 0xff;
    }
    fn_8016A3AC()[0x1f1] = p[0x2d3];
    p[0x2d4] = fn_8016A3AC()[0x1f0];
    if (*(s32*)(p + 0x2ac) != 0) {
        *(s32*)(p + 0x2b0) = 0xff;
    }
    fn_8016A3AC()[0x1f0] = p[0x2d4];
    p[0x2d5] = fn_8016A3AC()[0x1ef];
    if (*(s32*)(p + 0x2b8) != 0) {
        *(s32*)(p + 0x2bc) = 0xff;
    }
    fn_8016A3AC()[0x1ef] = p[0x2d5];
    if (*(s32*)(p + 0x288) == 0 && *((u8*)fn_802D6A9C() + 0x131f2) != 0) {
        if (*(s32*)((char*)fn_802D6A9C() + 4) == 1 && *(s32*)((char*)fn_802D6A9C() + 8) == 3) {
            *(s32*)(p + 0x288) = 4;
        } else {
            *(s32*)(p + 0x288) = 3;
        }
    }
    if (*(s32*)(p + 0x288) == 2 && *(s32*)((char*)fn_802D6A9C() + 4) == 1 && *(s32*)((char*)fn_802D6A9C() + 8) == 1 && ((Actor802B*)p)->v34()) {
        if (*((u8*)fn_802D6A9C() + 0x131f2) != 0) {
            *(s32*)(p + 0x288) = 3;
        } else {
            *(s32*)(p + 0x288) = 0;
        }
    }
    if (*(s32*)(p + 0x288) != 0) {
        *(s32*)(p + 0x310) = fn_801B7550();
        if (*(s32*)(p + 0x288) == 2 && (*(u32*)(p + 0x90) >> 27) != 0 && !((Actor802B*)p)->v34()) {
            *(s32*)(p + 0x288) = 1;
        }
        if (*(s32*)(p + 0x288) == 1 && (((*(u32*)(p + 0x90) >> 27) != 0 && ((Actor802B*)p)->v34() == 1) || *((u8*)fn_802D6A9C() + 0x131f2) != 0)) {
            *(s32*)(p + 0x288) = 2;
        }
        if (*(s32*)(p + 0x288) == 1) {
            *(s32*)(p + 0x2f0) = 0x9f;
            *(s32*)(p + 0x2f4) = 0xaf;
            *(s32*)(p + 0x2f8) = 0xff;
            *(s32*)(p + 0x300) = *(s32*)(p + 0x2e0);
            *(s32*)(p + 0x304) = *(s32*)(p + 0x2e4);
            *(s32*)(p + 0x308) = *(s32*)(p + 0x2e8);
            *(f32*)(p + 0x2c0) = lbl_80540A20;
            *(f32*)(p + 0x2c4) = lbl_80540A20;
            *(f32*)(p + 0x2c8) = lbl_80540A2C;
            *(f32*)(p + 0x2cc) = lbl_80540A30;
            *(s32*)(p + 0x24c) = 0x14;
            *(s32*)(p + 0x250) = 0x14;
            fn_802D6BF8(fn_802D6A9C(), 0);
        } else if (*(s32*)(p + 0x288) == 2) {
            *(s32*)(p + 0x2e0) = 0x9f;
            *(s32*)(p + 0x2e4) = 0xaf;
            *(s32*)(p + 0x2e8) = 0xff;
            *(f32*)(p + 0x2c0) = lbl_80540A24;
            *(f32*)(p + 0x2c4) = lbl_80540A28;
            *(f32*)(p + 0x2c8) = lbl_80540A2C;
            *(f32*)(p + 0x2cc) = lbl_80540A30;
            *(s32*)(p + 0x24c) = fn_801CD664(100);
            *(s32*)(p + 0x250) = 0;
            *(void**)(p + 0x234) = fn_8013CC50(*(u32*)(p + 4), p + 0x254, 0x3a1, 1, 0, 0, 0, 1, lbl_80540A20);
            if (*(void**)(p + 0x234) != 0) {
                *(f32*)(*(char**)(p + 0x234) + 0x28) = *(f32*)(p + 0x2c0);
            }
            *(void**)(p + 0x238) = fn_8013CC50(*(u32*)(p + 4), p + 0x254, 0x3a2, 1, 0, 0, 0, 1, lbl_80540A20);
            if (*(void**)(p + 0x238) != 0) {
                *(f32*)(*(char**)(p + 0x238) + 0x28) = *(f32*)(p + 0x2c4);
            }
            fn_802D6BF8(fn_802D6A9C(), 1);
            ((Actor802B*)p)->v60();
        } else {
            *(s32*)(p + 0x2f0) = 0x9f;
            *(s32*)(p + 0x2e0) = 0x9f;
            *(s32*)(p + 0x2f4) = 0xaf;
            *(s32*)(p + 0x2e4) = 0xaf;
            *(s32*)(p + 0x2f8) = 0xff;
            *(s32*)(p + 0x2e8) = 0xff;
            *(f32*)(p + 0x2c0) = lbl_80540A24;
            *(f32*)(p + 0x2c4) = lbl_80540A28;
            *(f32*)(p + 0x2c8) = lbl_80540A2C;
            *(f32*)(p + 0x2cc) = lbl_80540A30;
            *(s32*)(p + 0x24c) = fn_801CD664(100);
            *(s32*)(p + 0x250) = 0;
            *(void**)(p + 0x234) = fn_8013CC50(*(u32*)(p + 4), p + 0x254, 0x3a1, 1, 0, 0, 0, 1, lbl_80540A20);
            if (*(void**)(p + 0x234) != 0) {
                *(f32*)(*(char**)(p + 0x234) + 0x28) = *(f32*)(p + 0x2c0);
            }
            *(void**)(p + 0x238) = fn_8013CC50(*(u32*)(p + 4), p + 0x254, 0x3a2, 1, 0, 0, 0, 1, lbl_80540A20);
            if (*(void**)(p + 0x238) != 0) {
                *(f32*)(*(char**)(p + 0x238) + 0x28) = *(f32*)(p + 0x2c4);
            }
            fn_802D6BF8(fn_802D6A9C(), 1);
            ((Actor802B*)p)->v60();
        }
    }
    if (*(s32*)(p + 0x290) != 0) {
        *(void**)(p + 0x23c) = fn_8013CC50(*(u32*)(p + 4), p + 0x254, 0x449, 1, 0, 0, 0, 1, lbl_80540A20);
    } else if (*(s32*)(p + 0x294) != 0) {
        *(void**)(p + 0x23c) = fn_8013CC50(*(u32*)(p + 4), p + 0x254, 0x58, 1, 0, 0, 0, 1, lbl_80540A20);
    } else if (*(s32*)(p + 0x290) == 0 && *(s32*)(p + 0x294) == 0) {
        char* e = *(char**)(p + 0x23c);
        if (e != 0) {
            *(u32*)(e + 0xf4) |= 1;
            *(s32*)(e + 0x24) = 1;
            *(void**)(p + 0x23c) = 0;
        }
    }
    fn_8018330C(&c);
    *(Rgba802B*)(p + 0x2dc) = c;
    *(s32*)(p + 0x2e0) = *(u32*)(p + 0x2dc) >> 24;
    *(s32*)(p + 0x2e4) = (*(u32*)(p + 0x2dc) >> 16) & 0xff;
    *(s32*)(p + 0x2e8) = (*(u32*)(p + 0x2dc) >> 8) & 0xff;
    *(s32*)(p + 0x2ec) = *(u32*)(p + 0x2dc) & 0xff;
    *(s32*)(p + 0x300) = 0xff;
    *(s32*)(p + 0x304) = 0xff;
    *(s32*)(p + 0x308) = 0xff;
    *(s32*)(p + 0x30c) = 0;
    *(s32*)(p + 0x310) = fn_801B7550();
    char* cam = *(char**)(lbl_8053AB10 + 0x24);
    *(f32*)(p + 0x254) = -*(f32*)(cam + 0x10);
    *(f32*)(p + 0x258) = -*(f32*)(cam + 0x20);
    *(f32*)(p + 0x25c) = lbl_80540A1C;
    switch (*(u32*)(p + 0x2d8)) {
    case 0:
        *(s32*)(p + 0x240) = 9;
        break;
    case 1:
        ((Actor802B*)p)->v54(0xff, 0x80, 0xff, 0, 0xa, 0);
        break;
    case 2:
        ((Actor802B*)p)->v54(0xff, 0xff, 0xff, 0, 0xff, 0);
        *(s32*)(p + 0x240) = 0;
        break;
    case 3:
        fn_802D7440(fn_802D6A9C(), 0);
        ((Actor802B*)p)->v54(0xff, 0xff, 0xff, 0, 0xff, 0);
        *(s32*)(p + 0x240) = 0;
        break;
    case 4:
        fn_802D7440(fn_802D6A9C(), 0);
        if (!fn_802D75BC(fn_802D6A9C(), *(s32*)(p + 0x16c))) {
            ((Actor802B*)p)->v54(0xff, 0x80, 0xff, 0, 0xa, 0);
            *(s32*)(p + 0x240) = 0xb;
        } else {
            ((Actor802B*)p)->v54(0xff, 0xff, 0xff, 0, 0xff, 0);
            *(s32*)(p + 0x240) = 8;
        }
        break;
    case 5:
        ((Actor802B*)p)->v54(0xff, 0xff, 0xff, 0, 0x80, 0);
        break;
    case 6:
        ((Actor802B*)p)->v54(0xff, 0x80, 0xff, 0, 0xa, 0);
        *(s32*)(p + 0x240) = 0xb;
        break;
    case 7:
        ((Actor802B*)p)->v54(0xff, 0xff, 0xff, 0, 0xa, 9);
        *(s32*)(p + 0x248) = 100;
        *(s32*)(p + 0x334) = 0;
        *(s32*)(p + 0x338) = 0;
        *(s32*)(p + 0x314) = 10;
        break;
    case 8:
        ((Actor802B*)p)->v54(0x28, 0x50, 0xff, 0, 0xff, 0);
        break;
    case 9:
        ((Actor802B*)p)->v54(0x28, 0x50, 0xff, 0, 0xff, 9);
        break;
    case 10:
        ((Actor802B*)p)->v54(0xff, 0xb4, 0x78, 0, 0x8c, 9);
        break;
    case 11:
        ((Actor802B*)p)->v54(0xa4, 0xc8, 0xdc, 0, 0xff, 9);
        *(s32*)(p + 0x240) = 0;
        break;
    case 12:
        ((Actor802B*)p)->v54(0xff, 0xff, 0xff, 0, 0xff, 0);
        *(s32*)(p + 0x240) = 0;
        break;
    case 13:
        ((Actor802B*)p)->v54(0xbe, 0xd2, 0xc8, 0, 0xff, 9);
        break;
    case 14:
        ((Actor802B*)p)->v54(0x96, 0xc8, 0xff, 0x14, 0xb4, 9);
        break;
    case 15:
        ((Actor802B*)p)->v54(0xff, 0xff, 0xd2, 0x18, 0xff, 9);
        break;
    }
    *(WaveController**)(p + 0x230) = new WaveController(0, 0, 8);
    v = *(Vec802B*)(p + 0xc);
    ((Actor802B*)p)->v14();
    *(Vec802B*)(p + 0xc) = v;
    p[0x11f] = 1;
}

static void __sinit_tu_802B3674_cpp(void) {
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

