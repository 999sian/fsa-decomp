// Game TU 801D6CEC-801D7AFC (unnamed). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"
extern "C" void fn_801E4AB0(void* obj, s32 a, s32 b, f32 c);
extern const f32 lbl_8053F154;
extern const f32 lbl_8053F190;
extern const f32 lbl_8053F194;
extern const f32 lbl_8053F198;

extern "C" {
extern const f32 lbl_8053F150;
}
extern "C" void fn_8021BD18(void* subObj, s32 arg);

extern "C" void fn_801D76B4(void* thisPtr)
{
    char* t = (char*)thisPtr;
    *(s32*)(t + 0x0) = -1;
    f32 c = lbl_8053F150;
    *(s32*)(t + 0x4) = -1;
    *(s32*)(t + 0x8) = -1;
    *(s32*)(t + 0xc) = -1;
    *(s32*)(t + 0x10) = -1;
    *(s32*)(t + 0x14) = -1;
    *(s32*)(t + 0x18) = -1;
    *(s32*)(t + 0x1c) = -1;
    *(s32*)(t + 0x20) = -1;
    *(s32*)(t + 0x24) = -1;
    *(s32*)(t + 0x28) = -1;
    *(s32*)(t + 0x2c) = -1;
    *(s32*)(t + 0x30) = -1;
    *(s32*)(t + 0x34) = -1;
    *(s32*)(t + 0x38) = -1;
    *(s32*)(t + 0x3c) = -1;
    *(s32*)(t + 0x40) = 0;
    *(s32*)(t + 0x44) = 0;
    *(f32*)(t + 0x48) = c;
    *(f32*)(t + 0x4c) = c;
    *(f32*)(t + 0x50) = c;
    *(s16*)(t + 0x54) = 0;
    *(s16*)(t + 0x56) = 0;
    *(s8*)(t + 0x58) = 0;
    *(f32*)(t + 0x5c) = c;
    *(f32*)(t + 0x60) = c;
    *(s32*)(t + 0x64) = 0;
}

extern "C" void fn_801D6CEC(const f32* src, f32* dst) {
    dst[0] = src[0];
    dst[1] = src[5];
    dst[2] = lbl_8053F150;
}

extern "C" void fn_801D6D08(u8* this_) {
    fn_801E4AB0(this_ + 0x28, 0x1e, 0x400, lbl_8053F154);
}

extern "C" void fn_801D7830(f32* v) {
    v[2] *= 0.97f;
    v[3] *= 0.97f;
    v[4] += -0.2f;
    if (v[4] < -4.0f) {
        v[4] = -4.0f;
    }
}

extern "C" void fn_801D7874(u8* this_) {
    *(s32*)(this_ + 0x0) = -1;
    this_[4] = 0;
    this_[5] = 0;
    *(f32*)(this_ + 0x8) = lbl_8053F150;
    *(f32*)(this_ + 0xc) = lbl_8053F150;
    *(f32*)(this_ + 0x10) = lbl_8053F150;
}

extern "C" void fn_801D789C(void* child) {
    *(u8*)((char*)child + 0x0) = 0;
    *(s32*)((char*)child + 0x4) = 0;
    *(s32*)((char*)child + 0x8) = 0;
    fn_8021BD18((char*)child + 0xc, 2);
}

extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* base, s32 id);
extern "C" s32 Actor_CreateByID(void* base, u32 fourCC, u32 owner, void* posPtr, u32 param, s32 p6, s32 p7);
extern "C" u8 fn_801CD2F8(s32 id);
extern "C" void __dl__FPv(void* p);
extern const f32 lbl_8053F16C;
extern const f32 lbl_8053F170;

struct Tu6CECVec { f32 x, y, z; };
static inline void tu6cec_set(f32* d, f32 x, f32 y, f32 z) { d[0] = x; d[1] = y; d[2] = z; }

static inline void tu6cec_kill(s32 id) {
    if (id >= 0) {
        char* a = (char*)fn_801F666C(fn_801F856C(), id);
        if (a != 0) {
            a[0x11c] = 0;
        }
    }
}

struct Tu6CECIds {
    Tu6CECIds() {
        for (int i = 0; i < 16; i++) {
            ids[i] = -1;
        }
    }
    s32 ids[16];
};

struct Tu6CECGroup : Tu6CECIds {
    void init() {
        ids[0] = -1;
        f32 c = lbl_8053F150;
        ids[1] = -1;
        ids[2] = -1;
        ids[3] = -1;
        ids[4] = -1;
        ids[5] = -1;
        ids[6] = -1;
        ids[7] = -1;
        ids[8] = -1;
        ids[9] = -1;
        ids[10] = -1;
        ids[11] = -1;
        ids[12] = -1;
        ids[13] = -1;
        ids[14] = -1;
        ids[15] = -1;
        m40 = 0;
        m44 = 0;
        pos[0] = c;
        pos[1] = c;
        pos[2] = c;
        m54 = 0;
        m56 = 0;
        m58 = 0;
        m5c = c;
        m60 = c;
        m64 = 0;
    }
    Tu6CECGroup();
    void init3() {
        for (int i = 0; i < 16; i++) {
            ids[i] = -1;
        }
        m40 = 0;
        m44 = 0;
        pos[0] = lbl_8053F150;
        pos[1] = lbl_8053F150;
        pos[2] = lbl_8053F150;
        m54 = 0;
        m56 = 0;
        m58 = 0;
        m5c = lbl_8053F150;
        m60 = lbl_8053F150;
        m64 = 0;
    }
    ~Tu6CECGroup();
    void release() { s32* p = ids; for (int i = 0; i < 16; i++) { tu6cec_kill(*p); p++; } }
    /* 0x40 */ s32 m40;
    /* 0x44 */ s32 m44;
    /* 0x48 */ f32 pos[3];
    /* 0x54 */ s16 m54;
    /* 0x56 */ s16 m56;
    /* 0x58 */ s8 m58;
    /* 0x5c */ f32 m5c;
    /* 0x60 */ f32 m60;
    /* 0x64 */ s32 m64;
};

extern "C" void fn_801D74E0(Tu6CECGroup* g, Tu6CECVec p, s32 kind) {
    g->init3();
    g->m40 = kind;
    tu6cec_set(g->pos, p.x, lbl_8053F16C + p.y, p.z);
    if (fn_801CD2F8(g->m40)) {
        g->pos[1] = lbl_8053F170 + p.y;
    }
    s32 n;
    if (fn_801CD2F8(g->m40)) {
        g->m44 = 1;
        n = 1;
    } else {
        g->m44 = 2;
        n = 16;
    }
    for (int i = 0; i < n; i++) {
        g->ids[i] = Actor_CreateByID(fn_801F856C(), 'BGBL', g->m40, g->pos, 0, -1, -1);
    }
}

extern "C" void fn_801D7638(Tu6CECGroup* g) {
    s32* p = g->ids;
    s32 id;
    for (int i = 0; i < 16; i++) {
        id = *p;
        tu6cec_kill(id);
        p++;
    }
}

Tu6CECGroup::~Tu6CECGroup() {
    release();
}

Tu6CECGroup::Tu6CECGroup() {
    m40 = 0;
    m44 = 0;
    pos[0] = lbl_8053F150;
    pos[1] = lbl_8053F150;
    pos[2] = lbl_8053F150;
    m54 = 0;
    m56 = 0;
    m58 = 0;
    m5c = lbl_8053F150;
    m60 = lbl_8053F150;
    m64 = 0;
}

extern int __float_epsilon[];
extern const f32 lbl_8053F158;
extern const f32 lbl_8053F15C;
extern const f32 lbl_8053F160;
extern const f32 lbl_8053F164;
extern const f32 lbl_8053F168;

struct Tu6CECUtil {
    static f32 inv_sqrt(f32 x) {
        if (x <= lbl_8053F150)
            return x;
        f32 y = __frsqrte(x);
        return lbl_8053F160 * y * (lbl_8053F164 - (x * (y * y)));
    }
};
static inline f32 tu6cec_invSqrt(f32 x) { return Tu6CECUtil::inv_sqrt(x); }


struct Tu6CECVec2 {
    f32 x, y;
    void normalize() {
        f32 sq = x * x + y * y;
        if (sq <= lbl_8053F158 * *(f32*)__float_epsilon) {
            return;
        }
        f32 inv = tu6cec_invSqrt(sq);
        x *= inv;
        y *= inv;
    }
    void normalizeOr(f32 dx, f32 dy) {
        f32 sq = x * x + y * y;
        if (sq <= lbl_8053F158 * *(f32*)__float_epsilon) {
            x = dx;
            y = dy;
        } else {
            normalize();
        }
    }
};

static inline void tu6cec_scale(f32& x, f32& y, f32 s) { x *= s; y *= s; }
extern "C" void fn_801D6D38(char* p, Tu6CECVec2* in) {
    f32 y = in->y;
    f32 x = in->x;
    f32 sq = x * x + y * y;
    if (sq <= lbl_8053F158 * *(f32*)__float_epsilon) {
        x = lbl_8053F150;
        y = lbl_8053F15C;
    } else if (!(sq <= lbl_8053F158 * *(f32*)__float_epsilon)) {
        f32 inv = tu6cec_invSqrt(sq);
        x *= inv;
        y *= inv;
    }
    x *= lbl_8053F168;
    y *= lbl_8053F168;
    fn_801E4AB0(p, 0x3c, 0x2000, x);
    fn_801E4AB0(p + 0x14, 0x3c, 0x2000, y);
}

extern "C" f32* fn_8023E724(s32 idx);
extern "C" s32 fn_801CD664(s32 n);
extern const f32 lbl_8053F174;
extern const f32 lbl_8053F188;

struct Tu6CECVel { f32 x, y, z; };

extern "C" void fn_801D70BC(Tu6CECGroup* g, Tu6CECVec p, s32 player) {
    tu6cec_set(g->pos, p.x, lbl_8053F16C + p.y, p.z);
    if (fn_801CD2F8(g->m40)) {
        g->pos[1] = lbl_8053F170 + p.y;
    }
    s32 id = g->ids[0];
    if (id < 0) {
        return;
    }
    char* a = (char*)fn_801F666C(fn_801F856C(), id);
    if (a == 0) {
        return;
    }
    f32 vx, vy;
    if (player >= 0 && player < 4) {
        f32 dx, dy;
        dy = fn_8023E724(player)[1] - *(f32*)(a + 0x10);
        dx = fn_8023E724(player)[0] - *(f32*)(a + 0xc);
        f32 sq = dx * dx + dy * dy;
        if (sq <= lbl_8053F158 * *(f32*)__float_epsilon) {
            dx = lbl_8053F174;
            dy = lbl_8053F150;
        } else if (!(sq <= lbl_8053F158 * *(f32*)__float_epsilon)) {
            f32 inv = tu6cec_invSqrt(sq);
            dx *= inv;
            dy *= inv;
        }
        s16 ang = -(s16)(fn_801CD664(0xe39) - 0x71c);
        f32 sn = JMASSin(ang);
        f32 cs = JMASCos(ang);
        vy = dx * sn + dy * cs;
        vx = dx * cs - dy * sn;
    } else {
        s16 ang = fn_801CD664(0x10000);
        vx = JMASSin(ang);
        vy = JMASCos(ang);
    }
    *(JGeometry::TVec3<f32>*)(a + 0x3c) = JGeometry::TVec3<f32>(vx * lbl_8053F188, vy * lbl_8053F188, lbl_8053F150);
    g->m44 = 4;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
