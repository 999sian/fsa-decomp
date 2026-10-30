// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 80160650-801618D0 (EZRY). Remaining functions are not yet decompiled.
#include "types.h"
#include "Game/ItemBase.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"

extern char* lbl_8053AAF8;
extern void* lbl_8053AED0;
extern u8 lbl_80529DEC[];
extern u8 lbl_8050EC80[];
extern const f32 lbl_8053D670;
extern const f32 lbl_8053D674;
extern const f32 lbl_8053D678;
extern const f32 lbl_8053D67C;
extern const f32 lbl_8053D680;
extern const f32 lbl_8053D684;
extern const f32 lbl_8053D688;
extern const f32 lbl_8053D68C;
extern const f32 lbl_8053D690;
extern const f32 lbl_8053D694;
extern const f32 lbl_8053D698;
extern const f32 lbl_8053D69C;
extern const f32 lbl_8053D6A0;
extern "C" void fn_801F0E34(void* target, s32 soundId, s32 flag);
extern "C" void* fn_8013CC50(u32 id, f32* pos, u32 kind, u32 a, u32 b, u32 c, u32 d, u32 e, f32 scale);
extern "C" void fn_8043D67C(void* mgr, s32 id, s32 arg, s32 flag);
extern "C" void fn_8013CB44(void* emitter, f32* pos, u32 a, u32 b, u32 c);
extern "C" void fn_801F71A4(void* obj, f32 a, f32 b, f32 c);

static inline u8 ezryCount() {
    return *(volatile u8*)&lbl_80529DEC[0x24f];
}

static inline void ezryPlaySe(s32 id) {
    fn_8043D67C(lbl_8053AED0, id, 0, ezryCount());
}

struct EzryRandom {
    u32 seed;
    u32 get() {
        seed = 0x19660d * seed + 0x3c6ef35f;
        return seed;
    }
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        out.s = (get() >> 9) | 0x3f800000;
        return out.f - lbl_8053D670;
    }
};

// from src/Game/fn_80161638_dtor.cpp
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_804A03B8[];

extern "C" void* fn_80161638(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A03B8;
        char* p = (char*)this_;
        fn_801EE434(*(void**)(p + 0x290));
        fn_801EE434(*(void**)(p + 0x294));
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// from src/Game/Fary_SyncEmberEffectPosition.cpp
// FARY actor cluster, part 4/5. If this->0x290 is set, copies this->0xc/
// 0x10/0x14 (position) into that sub-object's own +0xa4/+0xa8/+0xac
// fields. Does the identical copy for this->0x294 if set. A simple "keep
// both flame/ember effect sub-objects synced to my position" helper.
extern "C" {

void fn_801615EC(void* thisPtr) {
	char* p = (char*)thisPtr;
	void* a = *(void**)(p + 0x290);
	if (a != 0) {
		*(f32*)((char*)a + 0xa4) = *(f32*)(p + 0xc);
		*(f32*)((char*)a + 0xa8) = *(f32*)(p + 0x10);
		*(f32*)((char*)a + 0xac) = *(f32*)(p + 0x14);
	}
	void* b = *(void**)(p + 0x294);
	if (b == 0) return;
	*(f32*)((char*)b + 0xa4) = *(f32*)(p + 0xc);
	*(f32*)((char*)b + 0xa8) = *(f32*)(p + 0x10);
	*(f32*)((char*)b + 0xac) = *(f32*)(p + 0x14);
}

}

class EzryVis {
public:
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
    virtual void v10();
    virtual u8 isVisible();
};

extern "C" void fn_801F06F0(void* actor, void* res, u32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern "C" void fn_803075AC(void* caller, s32 owner, void* pos, s32 ref, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern u8 lbl_804661C8[];
extern const f32 lbl_8053D670;

extern "C" void fn_80160650(char* p) {
    DrawRec rec;
    if ((*(u32*)(p + 0x90) >> 27) != 0 && !((EzryVis*)p)->isVisible()) {
        return;
    }
    if (*(s32*)(p + 0x258) != 2) {
        s32 t = *(s32*)(p + 0x234);
        if (t < 0x100 && (t & 2)) {
            return;
        }
        rec.b2d = 1;
        if (*(s32*)(p + 0x258) == 3) {
            ((u8*)&rec.w10)[3] = (s32)*(f32*)(p + 0x270);
            rec.w30 = 0x11;
        }
        fn_801F06F0(p, lbl_804661C8, *(s32*)(p + 0x250) + 0x5e, &rec, 1, lbl_8053D670, lbl_8053D670);
        fn_803075AC(*(void**)(p + 0x198), *(s32*)(p + 0x4), p + 0xc, *(s32*)(p + 0x250) + 0x5e, 0, 2, -1, 0, 0, 1);
    } else {
        s32 base = 0x5e;
        if (*(s32*)(p + 0x248) != 0) {
            base = 0x7d;
        }
        fn_803075AC(*(void**)(p + 0x198), *(s32*)(p + 0x4), p + 0xc, base + *(s32*)(p + 0x250), 0, 2, -1, 1, 0, 1);
    }
}

extern s32 lbl_8053AB9C;
extern s32 lbl_8053ABEC;
extern "C" void fn_801F3604(void* p);
extern "C" s32 fn_8023AF14(f32* box, s32 room, u8 flag, f32 r);
extern "C" s32 fn_8023B8E4(f32* box, s32 room, f32* pos, s32 a);
extern "C" void fn_80236554(s32 i, s32 a, s32 b);
extern "C" void* fn_801F856C(void);
extern "C" char* fn_801F666C(void* mgr, s32 h);
extern "C" s32 fn_801F2718(void* p, u32 name);
extern "C" s32 Actor_CreateByID(void* base, u32 fourCC, u32 owner, void* posPtr, u32 param, s32 p6, s32 p7);
extern "C" void fn_80230FD0(s32 i, s32 v);
extern "C" s32 fn_8023DE58(s32 i);
extern "C" f32* fn_8023E724(s32 i);
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802DCD0C(void* p);
extern "C" char* fn_8013C824(void);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* mgr, void* e);
extern "C" void fn_8016088C(char* p) {
    s32 h;
    f32 tx;
    f32 ty;
    s32 i;

    if (*(u8*)(p + 0x268) == 0 && (*(u32*)(p + 0x90) >> 27) != 0) {
        if (!((EzryVis*)p)->isVisible()) {
            return;
        }
        *(u8*)(p + 0x268) = 1;
        if (*(u8*)(lbl_8053AAF8 + 0x7f) == 1) {
            u8* rec = lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xc8;
            if (!(rec[0x87] & 1)) {
                rec[0x87] |= 1;
                ezryPlaySe(0x339);
            }
        }
        *(u32*)(p + 0xb0) = 0x20000;
        if (*(void**)(p + 0x290) == 0) {
            *(void**)(p + 0x290) = fn_8013CC50(*(u32*)(p + 0x4), (f32*)(p + 0xc), 0x183, 0, 0, 0, 0, 1, lbl_8053D670);
        }
        if (*(void**)(p + 0x294) == 0) {
            *(void**)(p + 0x294) = fn_8013CC50(*(u32*)(p + 0x4), (f32*)(p + 0xc), 0x184, 0, 0, 0, 0, 1, lbl_8053D670);
        }
    }
    if (*(s32*)(p + 0x258) != 2) {
        fn_801F71A4(p + 0x3c, *(f32*)(p + 0x278), lbl_8053D674, lbl_8053D678);
        fn_801F71A4(p + 0x40, *(f32*)(p + 0x27c), lbl_8053D674, lbl_8053D678);
        fn_801F71A4(p + 0x14, *(f32*)(p + 0x280), lbl_8053D67C, lbl_8053D678);
        *(JGeometry::TVec3<f32>*)(p + 0xc) += *(JGeometry::TVec3<f32>*)(p + 0x3c);
    }
    fn_8013CB44(*(void**)(p + 0x290), (f32*)(p + 0xc), 0, 0, 1);
    fn_8013CB44(*(void**)(p + 0x294), (f32*)(p + 0xc), 0, 0, 1);

    switch (*(s32*)(p + 0x230)) {
    case 0:
        fn_801F3604(p);
        *(s32*)(p + 0x230) = 1;
    case 1: {
        if (*(s32*)(p + 0x23c) != 0) {
            break;
        }
        *(s32*)(p + 0x244) += 0x300;
        *(f32*)(p + 0x280) = lbl_8053D684 * JMath::sincosTable_.sinShort(*(s32*)(p + 0x244)) + lbl_8053D680;
        if (*(s32*)(p + 0x24c) == 0) {
            if (*(s32*)(p + 0x240) != 0) {
                if ((*(s32*)(p + 0x240) & 7) == 0) {
                    *(f32*)(p + 0x278) = lbl_8053D678 * JMath::sincosTable_.sinShort(*(s32*)(p + 0x248));
                    *(f32*)(p + 0x27c) = lbl_8053D678 * JMath::sincosTable_.cosShort(*(s32*)(p + 0x248));
                }
                *(s32*)(p + 0x248) += 0x100;
            } else {
                *(s32*)(p + 0x240) = (s32)(lbl_8053D688 * ((EzryRandom*)(lbl_8053AAF8 + 0xb4))->get_ufloat_1()) + 0x1e;
                *(s32*)(p + 0x24c) = 1;
                *(f32*)(p + 0x278) = lbl_8053D68C;
                *(f32*)(p + 0x27c) = lbl_8053D68C;
            }
        } else if (*(s32*)(p + 0x240) == 0) {
            *(s32*)(p + 0x248) += (s32)(lbl_8053D690 * ((EzryRandom*)(lbl_8053AAF8 + 0xb4))->get_ufloat_1());
            *(s32*)(p + 0x240) = (s32)(lbl_8053D694 * ((EzryRandom*)(lbl_8053AAF8 + 0xb4))->get_ufloat_1()) + 0x28;
            *(s32*)(p + 0x24c) = 0;
        }
        f32 box[4];
        box[0] = *(f32*)(p + 0x60);
        box[1] = *(f32*)(p + 0x64);
        box[2] = *(f32*)(p + 0x68);
        box[3] = *(f32*)(p + 0x6c);
        JGeometry::TVec2<f32> pos(*(f32*)(p + 0xc), *(f32*)(p + 0x10));
        box[0] += pos.x;
        box[1] += pos.y;
        box[2] += pos.x;
        box[3] += pos.y;
        u8 flag = 1;
        if (*(u8*)(lbl_8053AAF8 + 0x7f) != 0) {
            flag = 0;
        }
        s32 idx = fn_8023AF14(box, *(s32*)(p + 4), flag, lbl_8053D68C);
        if (idx < 0) {
            idx = fn_8023B8E4(box, *(s32*)(p + 4), &pos.x, 1);
        }
        if (idx >= 0) {
            *(s32*)(p + 0x244) = 0;
            *(s32*)(p + 0x248) = 0;
            *(s32*)(p + 0x24c) = 0;
            *(s32*)(p + 0x234) = 0x1f4;
            *(s32*)(p + 0x244) = idx;
            fn_80236554(*(s32*)(p + 0x244), 0x20, 0);
            h = *(s32*)(p + 4);
            if (h >= 8) {
                Actor_CreateByID(fn_801F856C(), 'PEFF', h, p + 0xc, (*(s32*)(p + 0x244) & 3) | 4, -1, -1);
            }
            *(s32*)(p + 0x230) = 2;
        } else {
            *(s32*)(p + 0x254) = fn_801F2718(p, 'ZLD2');
            h = *(s32*)(p + 0x254);
            if (h >= 0 && fn_801F666C(fn_801F856C(), h) != 0) {
                lbl_8053AB9C = 0x20;
                *(s32*)(p + 0x230) = 2;
            } else {
                *(s32*)(p + 0x254) = fn_801F2718(p, 'ZLD4');
                h = *(s32*)(p + 0x254);
                if (h >= 0 && fn_801F666C(fn_801F856C(), h) != 0) {
                    lbl_8053ABEC = 0x20;
                    *(s32*)(p + 0x230) = 2;
                }
            }
        }
        break;
    }
    case 2:
        if (*(s32*)(p + 0x254) < 0) {
            fn_80230FD0(*(s32*)(p + 0x244), 0x2000b);
        } else {
            fn_801F0E34(p, 0x400c8, 0);
        }
        if (*(u8*)(lbl_8053AAF8 + 0x7f) == 1) {
            u8* cnt = &lbl_80529DEC[0x24f];
            if (*cnt < 99) {
                (*cnt)++;
            } else {
                *cnt = 99;
            }
        }
        *(s32*)(p + 0x23c) = 0;
        *(s32*)(p + 0x248) = 0;
        *(s32*)(p + 0x24c) = 0;
        *(u32*)(p + 0xb0) = 0;
        *(u8*)(p + 0x11e) = 1;
        *(s32*)(p + 0x264) = *(s32*)(p + 4);
        *(s32*)(p + 0x230) = 3;
    case 3:
        *(s32*)(p + 0x234) = 0x1f4;
        *(s32*)(p + 0x248) += 1;
        h = *(s32*)(p + 0x254);
        tx = *(f32*)(p + 0xc);
        ty = *(f32*)(p + 0x10);
        if (h < 0) {
            if (*(s32*)(p + 0x264) == fn_8023DE58(*(s32*)(p + 0x244))) {
                f32* v = fn_8023E724(*(s32*)(p + 0x244));
                tx = v[0];
                ty = v[1];
                v = fn_8023E724(*(s32*)(p + 0x244));
                *(f32*)(p + 0x284) = v[0];
                *(f32*)(p + 0x288) = v[1];
                *(f32*)(p + 0x28c) = v[2];
            } else {
                *(s32*)(p + 0x248) = 0xc8;
                tx = *(f32*)(p + 0x284);
                ty = *(f32*)(p + 0x288);
            }
        } else {
            char* a = fn_801F666C(fn_801F856C(), h);
            if (a != 0) {
                if (*(s32*)(p + 0x264) == *(s32*)(a + 4)) {
                    tx = *(f32*)(a + 0xc);
                    ty = *(f32*)(a + 0x10);
                    *(f32*)(p + 0x284) = tx;
                    *(f32*)(p + 0x288) = *(f32*)(a + 0x10);
                    *(f32*)(p + 0x28c) = *(f32*)(a + 0x14);
                } else {
                    *(s32*)(p + 0x248) = 0xc8;
                    tx = *(f32*)(p + 0x284);
                    ty = *(f32*)(p + 0x288);
                }
            }
        }
        *(f32*)(p + 0x26c) = lbl_8053D698;
        if (*(s32*)(p + 0x23c) == 0) {
            f32 ang = JMath::atanTable_.atan2_(tx - *(f32*)(p + 0xc), ty - *(f32*)(p + 0x10));
            *(s16*)(p + 0x274) = (s32)(ang * lbl_8053D69C);
            *(s32*)(p + 0x23c) = 4;
        }
        *(f32*)(p + 0x278) = *(f32*)(p + 0x26c) * JMath::sincosTable_.sinShort(*(u16*)(p + 0x274));
        *(f32*)(p + 0x27c) = *(f32*)(p + 0x26c) * JMath::sincosTable_.cosShort(*(u16*)(p + 0x274));
        if (*(s32*)(p + 0x248) > 100 || fn_802DCD0C(fn_802D6A9C())) {
            if (*(void**)(p + 0x290) != 0) {
                void* manager = *(void**)(fn_8013C824() + 0xc);
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(manager, *(void**)(p + 0x290));
            }
            if (*(void**)(p + 0x294) != 0) {
                void* manager = *(void**)(fn_8013C824() + 0xc);
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(manager, *(void**)(p + 0x294));
            }
            if (*(u8*)(lbl_8053AAF8 + 0x7f) == 1) {
                ezryPlaySe(0x33a);
            }
            *(u8*)(p + 0x11c) = 0;
        }
        break;
    case 4:
        if (*(s32*)(p + 0x238) == 0) {
            if (*(s32*)(p + 0x248) == 0) {
                *(s32*)(p + 0x250) += 1;
                if (*(s32*)(p + 0x250) > 2) {
                    *(s32*)(p + 0x250) = 0;
                }
                if (*(s32*)(p + 0x25c) >= 0) {
                    f32 y = fn_8023E724(*(s32*)(p + 0x25c))[1];
                    fn_801F71A4(p + 0x10, y, lbl_8053D67C, lbl_8053D684);
                    if ((f32)__fabs(*(f32*)(p + 0x10) - y) < lbl_8053D670) {
                        *(s32*)(p + 0x250) = 0;
                        *(s32*)(p + 0x248) = 1;
                    }
                }
            } else {
                *(s32*)(p + 0x250) += 1;
                *(s32*)(p + 0x250) &= 7;
                if (*(s32*)(p + 0x250) == 0) {
                    *(u8*)(p + 0x11c) = 0;
                }
            }
            *(s32*)(p + 0x238) = 4;
        }
        break;
    case 5:
        if (*(s32*)(p + 0x23c) == 0) {
            fn_801F71A4(p + 0x270, lbl_8053D68C, lbl_8053D67C, lbl_8053D6A0);
            if (*(f32*)(p + 0x270) < lbl_8053D670) {
                *(u8*)(p + 0x11c) = 0;
            }
        }
        break;
    }

    if (*(s32*)(p + 0x230) != 4 && *(s32*)(p + 0x238) == 0) {
        *(s32*)(p + 0x238) = 4;
        *(s32*)(p + 0x250) += 1;
        if (*(s32*)(p + 0x250) > 2) {
            *(s32*)(p + 0x250) = 0;
        }
    }
    for (i = 0; i < 4; i++) {
        if (*(s32*)(p + 0x234 + i * 4) > 0) {
            *(s32*)(p + 0x234 + i * 4) -= 1;
        }
        if (*(s32*)(p + 0x230) != 4) {
            if (*(s32*)(p + 0x258) == 0) {
                if (*(s32*)(p + 0x234) <= 0) {
                    if (*(void**)(p + 0x290) != 0) {
                        void* manager = *(void**)(fn_8013C824() + 0xc);
                        forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(manager, *(void**)(p + 0x290));
                    }
                    if (*(void**)(p + 0x294) != 0) {
                        void* manager = *(void**)(fn_8013C824() + 0xc);
                        forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(manager, *(void**)(p + 0x294));
                    }
                    *(u8*)(p + 0x11c) = 0;
                }
            } else {
                *(s32*)(p + 0x234) = 0x400;
            }
        }
    }
}


extern "C" void* fn_8013CC50(u32 id, f32* pos, u32 kind, u32 a, u32 b, u32 c, u32 d, u32 e, f32 scale);
extern "C" void fn_801F0E34(void* target, s32 soundId, s32 flag);
extern "C" void fn_8043D67C(void* mgr, s32 id, s32 arg, s32 flag);
extern char* lbl_8053AAF8;
extern void* lbl_8053AED0;
extern u8 lbl_80529DEC[];
extern u8 lbl_8050EC80[];
extern const f32 lbl_8053D688;
extern const f32 lbl_8053D68C;
extern const f32 lbl_8053D690;
extern const f32 lbl_8053D6A4;
extern const f32 lbl_8053D6A8;
extern const f32 lbl_8053D6AC;
extern const f32 lbl_8053D6B0;
extern const f32 lbl_8053D6B4;

struct EzryTimers { u8 pad[0x234]; s32 t[4]; };

#define EZRY_RND() (((EzryRandom*)(lbl_8053AAF8 + 0xb4))->get_ufloat_1())


#pragma opt_lifetimes off
extern "C" void fn_80161290(char* p) {
    *(f32*)(p + 0x60) = lbl_8053D6A4;
    *(f32*)(p + 0x64) = lbl_8053D6A4;
    *(f32*)(p + 0x68) = lbl_8053D6A8;
    *(f32*)(p + 0x6c) = lbl_8053D6A8;
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    for (int i = 0; i < 4; i++) {
        ((EzryTimers*)p)->t[i] = 0;
    }
    *(s32*)(p + 0x250) = 0;
    *(f32*)(p + 0x26c) = lbl_8053D68C;
    *(f32*)(p + 0x278) = lbl_8053D68C;
    *(f32*)(p + 0x27c) = lbl_8053D68C;
    *(f32*)(p + 0x280) = lbl_8053D68C;
    *(s32*)(p + 0x234) = 0x400;
    *(f32*)(p + 0x280) = lbl_8053D6AC;
    *(s32*)(p + 0x23c) = 10;
    *(s32*)(p + 0x240) = (s32)(lbl_8053D688 * EZRY_RND()) + 0x1e;
    *(s32*)(p + 0x260) = (*(u32*)(p + 0x90) >> 22) & 0x1f;
    *(s32*)(p + 0x258) = (*(u32*)(p + 0x90) >> 4) & 0xf;
    *(s32*)(p + 0x25c) = *(u32*)(p + 0x90) & 0xf;
    *(s32*)(p + 0x264) = 0;
    *(u8*)(p + 0x268) = 0;
    *(f32*)(p + 0x270) = lbl_8053D6B0;
    if (*(s32*)(p + 0x25c) > 0) {
        (*(s32*)(p + 0x25c))--;
    } else {
        *(s32*)(p + 0x25c) = -1;
    }
    *(s32*)(p + 0x248) = (s32)(lbl_8053D690 * EZRY_RND());
    *(s32*)(p + 0x230) = 0;
    *(u32*)(p + 0xb0) = 0x20000;
    *(s32*)(p + 0x254) = -1;
    if (*(s32*)(p + 0x258) == 2) {
        *(u8*)(p + 0x11f) = 1;
    }
    *(void**)(p + 0x290) = 0;
    *(void**)(p + 0x294) = 0;
    *(f32*)(p + 0x284) = *(f32*)(p + 0xc);
    *(f32*)(p + 0x288) = *(f32*)(p + 0x10);
    *(f32*)(p + 0x28c) = *(f32*)(p + 0x14);
    if (*(s32*)(p + 0x258) == 2) {
        *(s32*)(p + 0x234) = 0;
        *(s32*)(p + 0x238) = 0;
        *(s32*)(p + 0x248) = 0;
        *(s32*)(p + 0x230) = 4;
    }
    if (*(s32*)(p + 0x258) == 3) {
        *(s32*)(p + 0x234) = 10000;
        *(f32*)(p + 0x280) = lbl_8053D6B4;
        u8* cnt = &lbl_80529DEC[0x24f];
        if (*cnt < 99) {
            (*cnt)++;
        } else {
            *cnt = 99;
        }
        *(s32*)(p + 0x23c) = 0x1e;
        fn_801F0E34(p, 0x400e5, 0);
        *(s32*)(p + 0x230) = 5;
    }
    if ((*(u32*)(p + 0x90) >> 27) != 0 && !((EzryVis*)p)->isVisible()) {
        *(u32*)(p + 0xb0) = 0;
        return;
    }
    *(void**)(p + 0x290) = fn_8013CC50(*(u32*)(p + 0x4), (f32*)(p + 0xc), 0x183, 0, 0, 0, 0, 1, lbl_8053D670);
    *(void**)(p + 0x294) = fn_8013CC50(*(u32*)(p + 0x4), (f32*)(p + 0xc), 0x184, 0, 0, 0, 0, 1, lbl_8053D670);
    s32 st = *(s32*)(p + 0x230);
    if (st == 0 || st == 5) {
        if (*(u8*)(lbl_8053AAF8 + 0x7f) == 1) {
            u8* e = lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xc8;
            if (!(e[0x87] & 1)) {
                e[0x87] |= 1;
                u8* g = lbl_80529DEC;
                fn_8043D67C(lbl_8053AED0, 0x339, 0, lbl_80529DEC[0x24f]);
            }
        }
    }
}
#pragma opt_lifetimes reset
#include "JSystem/JAudio/JASFakeMatchFSA.h"
