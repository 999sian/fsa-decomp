// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 80182914-80183544 (RDVR). Remaining functions are not yet decompiled.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

// from src/Game/fn_80183100_dtor.cpp
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_804A1718[];

extern "C" void* fn_80183100(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A1718;
        char* p = (char*)this_;
        fn_801EE434(*(void**)(p + 0x274));
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// from src/Game/fn_8018316C.cpp
extern "C" void* fn_80212AC0(void);
extern "C" void fn_80212AF0(void* registry, void* posPtr);
extern "C" void fn_801F5790(void* this_);

// fn_8018316C(this) - closes the loop on RUSA's fn_80212AF0 (see
// project_fsa_rusa_actor_progress.md and
// project_fsa_80212af0_callers_closed.md). This is one of (at least) 3
// near-identical vtable-slot-0x18 overrides found across a large,
// still-entirely-unclaimed actor family in the 0x8018xxxx address
// range (siblings: fn_80183C18, fn_80184A14). Each: fetches RUSA's
// "active instances" registry via fn_80212AC0, pushes
// this's own position (&this->0xc) away from any RUSA zone it's
// inside via fn_80212AF0, THEN chains to the confirmed GENERIC
// slot-0x18 default fn_801F5790 (extending, not replacing, the
// generic behavior). This confirms vtable offset 0x18 - previously
// catalogued as an always-generic slot - is in fact a real override
// point, used here as a "resolve collision with RUSA instances"
// post-step.
extern "C" void fn_8018316C(void* this_) {
    void* registry = fn_80212AC0();
    fn_80212AF0(registry, (char*)this_ + 0xc);
    fn_801F5790(this_);
}

// from src/Game/Rivr_StartTrigger.cpp
// RIVR's vtable-0x44 override. A start trigger gated by two early-return conditions.
extern "C" {
void fn_801831A8(void* thisPtr) {
	char* p = (char*)thisPtr;
	if (*(s32*)(p + 0x258) != 0) return;
	if (*(s32*)(p + 0x230) == 5) return;
	*(u32*)(p + 0xb0) = 0x11101;
	*(u32*)(p + 0x254) = 6;
	*(u32*)(p + 0x230) = 4;
}
}
extern "C" void fn_801F06F0(void* actor, const char* file, s32 idx, f32 sx, f32 sy, s32 a, s32 b);

// RDVR draw (vtable slot 6)
extern "C" void fn_80182914(char* this_) {
    s32 flag = -1;
    s32 state = *(s32*)(this_ + 0x230);
    s32 frame = *(s32*)(this_ + 0x254);
    if ((state == 0 || state == 1) && *(s32*)(this_ + 0x23c) == 0) {
        return;
    }
    if (*(s32*)(this_ + 0x258) != 0) {
        flag = 0;
    }
    if (*(s32*)(this_ + 0x25c) == 1 && frame >= 3) {
        frame += 5;
    }
    fn_801F06F0(this_, "enemy_gc_sob.bin", frame + 0x158, 1.0f, 1.0f, 0, flag);
}

extern void** lbl_8053AB10;

extern "C" void fn_8018330C(u32* out);

extern "C" void* fn_802D6A9C(void);


// ---- fn_8018299C: RDVR update
#include "JSystem/JMath/JMath.h"
extern "C" s32 fn_801F3D94(void* this_, s32 a);
extern "C" void fn_801F2618(void* this_, s32, s32);
extern "C" u8 fn_801F305C(void* this_);
extern "C" void fn_801F71A4(f32* v, f32 target, f32 a, f32 b);
extern "C" void fn_801EEC98(void* this_, void*, u16*, s32, f32*, s32*, s32, s32);
extern "C" void fn_801F2B7C(void* this_, s32, s32, s32);
extern "C" void fn_801F714C(u16* a, u16 target, s32 b, s32 step);
extern "C" u8* fn_8013CC50(s32 id, void* pos, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, f32 g);

class RDVR {
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
    s32 m04;
    u8 pad08[4];
    JGeometry::TVec3f mPos; // 0x0c
    u8 pad18[0x3c - 0x18];
    JGeometry::TVec3f mVel; // 0x3c
    u8 pad48[0xb0 - 0x48];
    u32 mB0;
    u8 padB4[4];
    s32 mB8;
    u8 padBC[0x198 - 0xbc];
    void* m198;
    u8 pad19C[0x230 - 0x19c];
    u32 mState;  // 0x230
    u8 m234[4];
    u8 m238, m239, m23A;
    u8 pad23B;
    s32 m23C;
    s32 m240;
    s32 m244;
    s32 m248;
    u8 pad24C[8];
    s32 m254;
    s32 m258;
    s32 m25C;
    s32 m260;
    u16 m264;
    f32 m268;
    f32 m26C;
    f32 m270;
    u8* mChild; // 0x274

    void syncColor() {
        u8 c = m23A;
        u8 b = m239;
        u8* ch = mChild;
        ch[0xb8] = m238;
        ch[0xb9] = b;
        ch[0xba] = c;
    }
    void syncChild() {
        u8* p = mChild;
        if (p != 0) {
            *(f32*)(p + 0xa4) = mPos.x;
            *(f32*)(p + 0xa8) = mPos.y;
            *(f32*)(p + 0xac) = mPos.z;
            if (*((u8*)fn_802D6A9C() + 0x131f2) == 1) {
                u8 c = m23A;
                u8 b = m239;
                u8* ch = mChild;
                ch[0xb8] = m238;
                ch[0xb9] = b;
                ch[0xba] = c;
            }
        }
    }
    u8* spawn(s32 id) {
        u8* e = fn_8013CC50(m04, &mPos, id, 0, 1, 0, 0, 1, 1.0f);
        if (*((u8*)fn_802D6A9C() + 0x131f2) == 1) {
            u8 c = m23A;
            u8 b = m239;
            e[0xb8] = m238;
            e[0xb9] = b;
            e[0xba] = c;
        }
        return e;
    }
    void stop() {
        m270 = 0.0f;
        m26C = 0.0f;
        m268 = 0.0f;
        mVel.z = 0.0f;
        mVel.y = 0.0f;
        mVel.x = 0.0f;
    }
};

extern "C" void fn_8018299C(RDVR* this_) {
    u16 angle = 0;
    f32 f = 0.0f;
    s32 hit = -1;
    if (fn_801F3D94(this_, 1)) {
        this_->syncChild();
        fn_801F2618(this_, 0, 0);
        return;
    }
    if (this_->m258 != 0 && fn_801F305C(this_)) {
        this_->syncChild();
        fn_801F2618(this_, 0, 0);
        return;
    }
    fn_801F71A4(&this_->mVel.x, this_->m268, 0.3f, 1.0f);
    fn_801F71A4(&this_->mVel.y, this_->m26C, 0.3f, 1.0f);
    this_->mPos.add(this_->mVel);
    fn_80212AF0(fn_80212AC0(), &this_->mPos);
    fn_801EEC98(this_, this_->m198, &angle, 0, &f, &hit, 0, 0);
    if (this_->m258 != 0) {
        fn_801F2B7C(this_, -100, -1, 1);
    }
    fn_801F2618(this_, 0, 0);
    switch (this_->mState) {
    case 0:
        if (this_->m260 == 1) {
            if (this_->v34()) {
                this_->mState = 2;
            }
            break;
        }
        this_->m240 = 100;
        this_->mState = 1;
    case 1:
        this_->m268 = 0.5f * JMASinShort(angle);
        this_->m26C = 0.5f * JMACosShort(angle);
        if (this_->m240 != 0) {
            break;
        }
        this_->mState = 2;
    case 2:
        this_->mB8 = 1;
        if (this_->mChild == 0) {
            this_->spawn(0x1da);
            this_->mChild = fn_8013CC50(this_->m04, &this_->mPos, 0x1db, 0, 1, 0, 0, 1, 1.0f);
            if (*((u8*)fn_802D6A9C() + 0x131f2) == 1) {
                this_->syncColor();
            }
        }
        this_->stop();
        this_->m23C = 6;
        this_->m248 = 0;
        this_->m254 = 0;
        this_->mState = 3;
    case 3:
        if (this_->m23C == 0) {
            this_->m254++;
            this_->m23C = 6;
            if (this_->m254 > 5) {
                this_->mState = 4;
            }
        }
        this_->syncChild();
        break;
    case 4:
        this_->mB0 = 0x11101;
        this_->m240 = 200;
        this_->m254 = 6;
        this_->m23C = 8;
        this_->m248 = 0;
        this_->m258 = 1;
        this_->mState = 5;
    case 5: {
        this_->syncChild();
        f32 speed;
        s32 step;
        if (this_->m25C == 1) {
            speed = 1.0f;
            step = 0x300;
        } else {
            speed = 0.5f;
            step = 0x100;
        }
        fn_801F714C(&this_->m264, angle, 1, step);
        this_->m268 = speed * JMASinShort(this_->m264);
        this_->m26C = speed * JMACosShort(this_->m264);
        if (this_->m23C == 0) {
            this_->m254++;
            if (this_->m254 > 7) {
                this_->m254 = 6;
            }
            this_->m23C = 8;
        }
        if (this_->m240 != 0) {
            break;
        }
        this_->mState = 6;
    }
    case 6:
        this_->syncChild();
        this_->mB0 = 0x1000;
        this_->stop();
        this_->m258 = 0;
        this_->m23C = 4;
        this_->m248 = 0;
        this_->m254 = 6;
        this_->mState = 7;
    case 7:
        this_->syncChild();
        if (this_->m23C == 0) {
            this_->m254--;
            this_->m23C = 6;
            if (this_->m254 <= 0) {
                if (this_->mChild != 0) {
                    this_->spawn(0x1da);
                    u8* c = this_->mChild;
                    *(u32*)(c + 0xf4) |= 1;
                    *(s32*)(c + 0x24) = 1;
                    this_->mChild = 0;
                }
                this_->m23C = 3;
                this_->mState = 0;
            }
        }
        break;
    }
    if (this_->m23C > 0) {
        this_->m23C--;
    }
    if (this_->m240 > 0) {
        this_->m240--;
    }
    if (this_->m244 > 0) {
        this_->m244--;
    }
}

// RDVR init (vtable slot 1)
extern "C" void fn_801831E0(char* this_) {
    *(f32*)(this_ + 0x60) = -8.0f;
    *(f32*)(this_ + 0x64) = -8.0f;
    *(f32*)(this_ + 0x68) = 8.0f;
    *(f32*)(this_ + 0x6c) = 8.0f;
    *(f32*)(this_ + 0x80) = -8.0f;
    *(f32*)(this_ + 0x84) = -8.0f;
    *(f32*)(this_ + 0x88) = 8.0f;
    *(f32*)(this_ + 0x8c) = 8.0f;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(u32*)(this_ + 0x25c) = *(u32*)(this_ + 0x90) & 1;
    *(u32*)(this_ + 0x260) = (*(u32*)(this_ + 0x90) >> 8) & 1;
    *(s32*)(this_ + 0x254) = 0;
    *(u8*)(this_ + 0x238) = 0;
    *(u8*)(this_ + 0x239) = 0;
    *(u8*)(this_ + 0x23a) = 0;
    if (*((u8*)fn_802D6A9C() + 0x131f2) == 1) {
        u8 c[4];
        fn_8018330C((u32*)c);
        *(u8*)(this_ + 0x234) = c[0];
        *(u8*)(this_ + 0x235) = c[1];
        *(u8*)(this_ + 0x236) = c[2];
        *(u8*)(this_ + 0x237) = c[3];
        *(u8*)(this_ + 0x238) = *(u32*)(this_ + 0x234) >> 24;
        *(u8*)(this_ + 0x239) = *(u32*)(this_ + 0x234) >> 16;
        *(u8*)(this_ + 0x23a) = *(u32*)(this_ + 0x234) >> 8;
    }
    *(f32*)(this_ + 0x270) = 0.0f;
    *(f32*)(this_ + 0x26c) = 0.0f;
    *(f32*)(this_ + 0x268) = 0.0f;
    *(f32*)(this_ + 0x44) = 0.0f;
    *(f32*)(this_ + 0x40) = 0.0f;
    *(f32*)(this_ + 0x3c) = 0.0f;
    *(s32*)(this_ + 0x258) = 0;
    *(s16*)(this_ + 0x264) = 0;
    *(u8*)(this_ + 0x195) = 1;
    *(s32*)(this_ + 0x274) = 0;
    *(s32*)(this_ + 0x230) = 0;
}

extern "C" void fn_8018330C(u32* out) {
    *out = ((u32*)lbl_8053AB10[0xb])[1];
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
