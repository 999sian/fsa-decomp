// Game TU 801CB270-801CDC8C (unnamed). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
#include "JSystem/ResTIMG.h"
#include "JSystem/JGeometry.h"
extern "C" void* fn_8022F3DC(void* p);
extern "C" s32 fn_80236228(void* p);
extern "C" u32 fn_80226998(void* p, s32 layer);
extern "C" s32 fn_80138A30(void* p);
extern "C" u8 fn_80230188(s32 idx);
extern "C" void* fn_801F856C(void);
extern "C" void fn_801F8544(void* mgr, u32 tag, u32 a, u32 b, u32 flags);
extern u8* lbl_8053AAF8;
extern const f32 lbl_8053EF60;
extern const f64 lbl_8053EF68;
extern const f64 lbl_8053EF70;
extern const f32 lbl_8053EF7C;
extern const f32 lbl_8053EF90;
extern const f32 lbl_8053EF98;

extern "C" u8 fn_8022F514(void* this_);
extern "C" BOOL fn_801CD9F0(f32* value, f32 target, f32 step);
extern "C" u8 fn_80303750(void* this_);
extern "C" s32 fn_801CD970(s16* value, s16 target, s16 step);

extern "C" s32 fn_8023DE58(s32 playerIdx);

extern "C" void C_VECReflect(const JGeometry::TVec3f* src, const JGeometry::TVec3f* normal, JGeometry::TVec3f* dst);

extern "C" void fn_801CB434(u32 a, u32 b, u8 flag) {
    s32 kind = 4;
    kind += (flag != 0);
    fn_801F8544(fn_801F856C(), 'RUPY', a, b, kind | 0x261e00);
}

extern "C" void fn_801CB7A0(u8* obj) {
    if (obj != 0) {
        *(u32*)(obj + 0xf4) |= 0x40;
        *(u32*)(obj + 0xf4) |= 0x1;
        *(u32*)(obj + 0x24) = 1;
    }
}

extern "C" s32 fn_801CC8E4(void* thisObj) {
	char* p = (char*)thisObj;
	s32 result = 0;
	if (*(u32*)(p + 0x1a0) == 0x424D5459 && *(s32*)(p + 0x230) != 3) {
		result = 1;
	}
	return result;
}

extern "C" s32 fn_801CC910(void* thisObj) {
	char* p = (char*)thisObj;
	s32 result = 0;
	if (*(u32*)(p + 0x1a0) == 0x52555059) {
		s32 typeVal = -1;
		u16 v94 = *(u16*)(p + 0x94);
		if (v94 == 0 || v94 == 3) {
			typeVal = *(u32*)(p + 0x90) & 0xff;
		}
		if (typeVal >= 8 && typeVal <= 0xb) {
			result = 1;
		}
	}
	return result;
}

extern "C" s32 fn_801CC960(void* thisObj) {
	char* p = (char*)thisObj;
	s32 result = 0;
	if (*(u32*)(p + 0x1a0) == 0x52555059) {
		s32 typeVal = -1;
		u16 v94 = *(u16*)(p + 0x94);
		if (v94 == 0 || v94 == 3) {
			typeVal = *(u32*)(p + 0x90) & 0xff;
		}
		if (typeVal >= 4 && typeVal <= 7) {
			result = 1;
		}
	}
	return result;
}

extern "C" s32 fn_801CC9B0(void* thisObj) {
	char* p = (char*)thisObj;
	s32 result = 0;
	if (*(u32*)(p + 0x1a0) == 0x52555059) {
		s32 typeVal = -1;
		u16 v94 = *(u16*)(p + 0x94);
		if (v94 == 0 || v94 == 3) {
			typeVal = *(u32*)(p + 0x90) & 0xff;
		}
		if (typeVal >= 0) {
			result = 1;
		}
	}
	return result;
}

extern "C" BOOL fn_801CCC78(void* p, s32 layer) {
    BOOL result = FALSE;
    switch ((u16)fn_80226998(p, layer)) {
    case 0x40: case 0x41: case 0x42: case 0x43: case 0x44:
    case 0x45: case 0x46: case 0x47: case 0x48: case 0x49:
        result = TRUE;
        break;
    }
    return result;
}

extern "C" void fn_801CCCC4(f32* v) {
    v[0] = lbl_8053EF98 + (f32)(u32)((s32)v[0] & ~0xf);
    v[1] = lbl_8053EF98 + (f32)(u32)((s32)v[1] & ~0xf);
}

extern "C" void fn_801CCD34(const f32* src, f32* dst) {
    dst[0] = lbl_8053EF98 + (f32)(u32)((s32)src[0] & ~0xf);
    dst[1] = lbl_8053EF98 + (f32)(u32)((s32)src[1] & ~0xf);
}

extern "C" void fn_801CCF34(void* p) {
    if (fn_8022F514(p)) {
        p = fn_8022F3DC(p);
    }
    fn_80236228(p);
}

extern "C" BOOL fn_801CCF7C(void) {
    s32 n = fn_80138A30(lbl_8053AAF8);
    for (s32 i = 0; i < n; i++) {
        if (!fn_80230188(i)) {
            return FALSE;
        }
    }
    return TRUE;
}

extern "C" s32 fn_801CD1D0(void* this_) {
    s32 result = 0;
    if (!fn_8022F514(this_)) {
        if (fn_80303750(this_)) {
            result = 1;
        }
    }
    return result;
}

extern "C" s32 fn_801CD228(s32 groupID) {
    s32 result = 1;
    for (s32 i = 0; i < 4; i++) {
        if (fn_8023DE58(i) != groupID) {
            result = 0;
            break;
        }
    }
    return result;
}

extern "C" s32 fn_801CD290(s32 groupID) {
    s32 result = 0;
    for (s32 i = 0; i < 4; i++) {
        if (fn_8023DE58(i) == groupID) {
            result = 1;
            break;
        }
    }
    return result;
}

extern "C" bool fn_801CD2F8(s32 id) {
    bool r = false;
    if (id >= 8) {
        r = true;
    }
    return r;
}

extern "C" s32 fn_801CD30C(s32 val) {
	s32 result = 0;
	switch (val) {
	case 0:
		result = 3;
		break;
	case 1:
		result = 2;
		break;
	case 3:
		result = 1;
		break;
	default:
		break;
	}
	return result;
}

extern "C" s32 fn_801CD354(s32 val) {
	s32 result = 0;
	switch (val) {
	case 0:
		result = 1;
		break;
	case 2:
		result = 3;
		break;
	case 3:
		result = 2;
		break;
	default:
		break;
	}
	return result;
}

extern "C" s32 fn_801CD664(s32 n) {
    u32* seed = (u32*)(lbl_8053AAF8 + 0xb4);
    *seed = *seed * 0x19660d + 0x3c6ef35f;
    u32 bits = (*seed >> 9) | 0x3f800000;
    return (f32)n * (*(f32*)&bits - lbl_8053EF60);
}

extern "C" BOOL fn_801CD8E4(f32* value, f32 target, f32 rate, f32 eps) {
    if (rate > lbl_8053EF60) {
        rate = lbl_8053EF60;
    }
    eps = __fabsf(eps);
    *value = rate * (target - *value) + *value;
    if (__fabsf(*value - target) <= eps) {
        return FALSE;
    }
    return TRUE;
}

extern "C" s32 fn_801CD930(s16* value, s16 target, s16 step) {
    return fn_801CD970(value, target, step);
}

extern "C" s32 fn_801CD950(f32* value, f32 target, f32 step) {
    return fn_801CD9F0(value, target, step);
}

extern "C" s32 fn_801CD970(s16* value, s16 target, s16 step) {
	s16 diff = target - *value;
	if (step < 0) {
		step = -step;
	}
	if (diff > 0) {
		diff -= step;
		if (diff > 0) {
			*value = target - diff;
		} else {
			*value = target;
		}
	} else {
		diff += step;
		if (diff < 0) {
			*value = target - diff;
		} else {
			*value = target;
		}
	}
	s32 result = 1;
	if (*value == target) {
		result = 0;
	}
	return result;
}

extern "C" BOOL fn_801CD9F0(f32* value, f32 target, f32 step) {
    f32 d = target - *value;
    if (step < 0.0f) {
        step = -step;
    }
    if (d > 0.0f) {
        d -= step;
        if (d > 0.0f) {
            *value = target - d;
        } else {
            *value = target;
        }
    } else {
        d += step;
        if (d < 0.0f) {
            *value = target - d;
        } else {
            *value = target;
        }
    }
    BOOL r = TRUE;
    if (*value == target) {
        r = FALSE;
    }
    return r;
}

extern "C" u8* fn_802D6A9C(void);
extern "C" void fn_8013CB44(void* h, void* pos, u32 a, u32 b, u32 c);
extern "C" void* fn_8013C824();
class JPABaseEmitter;
class JPAEmitterManager {
public:
    void forceDeleteEmitter(JPABaseEmitter*);
};
extern const f32 lbl_8053EF80;
extern const f32 lbl_8053EF8C;
extern const f32 lbl_8053EFA4;
extern const f32 lbl_8053EFA8;
extern const f32 lbl_8053EFAC;
extern const f32 lbl_8053EFB0;

static inline u8 emitterDone(u8* q) {
    u8 dead = 0;
    if ((*(u32*)(q + 0xf4) & 8) && *(s32*)(q + 0xd0) + *(s32*)(q + 0xdc) == 0) {
        dead = 1;
    }
    return dead;
}

extern "C" void fn_801CB71C(JPABaseEmitter** pe, void* pos, u32 a, u32 b) {
    JPABaseEmitter* e = *pe;
    if (e == 0) {
        return;
    }
    if (emitterDone((u8*)e)) {
        JPAEmitterManager* mgr = *(JPAEmitterManager**)((char*)fn_8013C824() + 0xc);
        mgr->forceDeleteEmitter(*pe);
        *pe = 0;
        return;
    }
    fn_8013CB44(e, pos, a, b, 1);
}

extern "C" void fn_801CD0D0(const f32* src, f32* dst) {
    u8* a = fn_802D6A9C();
    u8* b = fn_802D6A9C();
    f32 dx = src[0] - *(f32*)(b + 0xdc);
    f32 dy = src[1] - *(f32*)(b + 0xe0);
    f32 x = *(f32*)(a + 0xcc) + dx;
    f32 y = *(f32*)(a + 0xd0) + dy;
    f32 z = src[2];
    dst[0] = x;
    dst[1] = y;
    dst[2] = z;
}

extern "C" void fn_801CD150(const f32* src, f32* dst) {
    u8* a = fn_802D6A9C();
    u8* b = fn_802D6A9C();
    f32 dx = src[0] - *(f32*)(a + 0xcc);
    f32 dy = src[1] - *(f32*)(a + 0xd0);
    f32 x = *(f32*)(b + 0xdc) + dx;
    f32 y = *(f32*)(b + 0xe0) + dy;
    f32 z = src[2];
    dst[0] = x;
    dst[1] = y;
    dst[2] = z;
}

extern "C" f32 fn_801CD6D8(f32 p0, f32 p1, f32 p2, f32 p3, f32 t) {
    f32 ht = lbl_8053EF8C * t;
    f32 t2 = t * t;
    f32 t3 = t2 * t;
    f32 b1 = lbl_8053EF60 + (lbl_8053EFAC * t3 - lbl_8053EFB0 * t2);
    f32 b0 = (lbl_8053EFA8 * t3 + t2) - ht;
    f32 b2 = ht + (lbl_8053EFA4 * t3 + lbl_8053EF80 * t2);
    f32 b3 = lbl_8053EF8C * t3 - lbl_8053EF8C * t2;
    return p3 * b3 + (p2 * b2 + (p0 * b0 + p1 * b1));
}

extern "C" u32 fn_801CD754(f32* a, f32* b, f32 t, f32 maxStep, f32 limit) {
    f32 dx;
    f32 dy;
    f32 len2;
    f32 len;
    f32 y;
    f32 f;

    if (t > lbl_8053EF60) {
        t = lbl_8053EF60;
    } else if (t < lbl_8053EF7C) {
        t = lbl_8053EF7C;
    }
    dx = b[0] - a[0];
    dy = b[1] - a[1];
    len2 = dx * dx + dy * dy;
    len = len2;
    if (len2 > lbl_8053EF7C) {
        y = (f32)__frsqrte(len2);
        y = (lbl_8053EF8C * y) * (lbl_8053EF90 - len2 * (y * y));
        len = len2 * y;
    }
    if (len > lbl_8053EF7C) {
        if (len * t < maxStep) {
            f = lbl_8053EF60 / len;
            f = maxStep * f;
            if (f > lbl_8053EF60) {
                f = lbl_8053EF60;
            } else if (f < t) {
                f = t;
            }
            t = f;
        } else if (len * t > limit) {
            f = lbl_8053EF60 / len;
            f = limit * f;
            if (f > t) {
                f = t;
            }
            if (f < lbl_8053EF7C) {
                f = lbl_8053EF7C;
            }
            t = f;
        }
    }
    {
        f32 k = t;
        if (k > lbl_8053EF60) {
            k = lbl_8053EF60;
        }
        a[0] = a[0] + k * (b[0] - a[0]);
        if (t > lbl_8053EF60) {
            t = lbl_8053EF60;
        }
        a[1] = a[1] + t * (b[1] - a[1]);
    }
    {
        u32 eq = 0;
        if (a[0] == b[0] && a[1] == b[1]) {
            eq = 1;
        }
        return !eq;
    }
}

extern "C" void fn_8013CC50(f32 scale, u32 owner, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);

extern "C" void fn_801CB4A4(void* actor, void* pos, s32 c, s32 d) {
    fn_8013CC50(lbl_8053EF60, (u32)actor, pos, 0x473, c, d + 1, 0, 0, 1);
    fn_8013CC50(lbl_8053EF60, (u32)actor, pos, 0x474, c, d + 1, 0, 0, 1);
}

extern "C" void fn_801CB538(void* actor, void* pos, s32 c, s32 d) {
    fn_8013CC50(lbl_8053EF60, (u32)actor, pos, 0x117, c, d + 1, 0, 0, 1);
    fn_8013CC50(lbl_8053EF60, (u32)actor, pos, 0x118, c, d + 1, 0, 0, 1);
}

extern "C" void fn_801CB5CC(void* actor, void* pos, s32 c, s32 d) {
    fn_8013CC50(lbl_8053EF60, (u32)actor, pos, 0xff, c, d + 1, 0, 0, 1);
    fn_8013CC50(lbl_8053EF60, (u32)actor, pos, 0x100, c, d + 1, 0, 0, 1);
    fn_8013CC50(lbl_8053EF60, (u32)actor, pos, 0x101, c, d + 1, 0, 0, 1);
}

extern "C" void fn_801CB688(void* actor, void* pos, s32 c, s32 d) {
    fn_8013CC50(lbl_8053EF60, (u32)actor, pos, 0x24a, c, d + 1, 0, 0, 1);
    fn_8013CC50(lbl_8053EF60, (u32)actor, pos, 0x24b, c, d + 1, 0, 0, 1);
}


extern "C" s16 fn_801CB7CC(s16 angle) {
    u16 x = angle;
    if (x <= 0x4000) {
        u16 t = 0x4000 - x;
        return t + 0x4000;
    }
    if (x >= 0x4000 && x <= 0x8000) {
        u16 t = x - 0x4000;
        return 0x4000 - t;
    }
    if (x >= 0x8000 && x <= 0xc000) {
        u16 t = 0xc000 - x;
        return t + 0xc000;
    }
    u16 t = x - 0xc000;
    return 0xc000 - t;
}

extern "C" s32 fn_801CC29C(const f32* a, const f32* b, f32* out) {
    s32 result = 0;
    out[0] = lbl_8053EF7C;
    out[1] = lbl_8053EF7C;
    f32 d = a[0] - b[0];
    if (d > lbl_8053EF7C) {
        out[0] += d;
        result = 1;
    }
    d = b[2] - a[2];
    if (d > lbl_8053EF7C) {
        out[0] -= d;
        result = 1;
    }
    d = a[1] - b[1];
    if (d > lbl_8053EF7C) {
        out[1] += d;
        result = 1;
    }
    d = b[3] - a[3];
    if (d > lbl_8053EF7C) {
        out[1] -= d;
        result = 1;
    }
    return result;
}

extern "C" u8 fn_8023F264(s32 idx);
extern "C" u32 fn_802265FC(void* p, s32 layer);
extern const f32 lbl_8053EFA0;

extern "C" s32 fn_801CCB1C(const f32* pos, s32 layer) {
    s32 result = 0;
    f32 v[2];
    f32 y = pos[1] - pos[2];
    v[0] = pos[0];
    v[1] = y;
    u8* mgr = fn_802D6A9C() + 0x10000;
    if (mgr[layer + 0x31df] != 0) {
        if ((u16)fn_802265FC(v, layer) == 2) {
            f32 w[2];
            w[0] = v[0];
            w[1] = lbl_8053EFA0 + v[1];
            if ((u16)fn_802265FC(w, layer) == 2) {
                result = 1;
            }
        }
    }
    return result;
}

extern "C" s32 fn_801CCBD0(const f32* pos, s32 layer) {
    s32 result = 0;
    f32 v[2];
    v[0] = pos[0];
    v[1] = pos[1];
    for (s32 i = 0; i < 2; i++) {
        switch ((u16)fn_80226998(v, layer)) {
        case 0x19c:
        case 0x19d:
            result = 1;
            break;
        }
        v[1] -= lbl_8053EFA0;
    }
    return result;
}

extern "C" s32 fn_801CCDA4(void) {
    s32 best = -1;
    s32 second = 0x7fffffff;
    s32 min = second;
    s32 n = fn_80138A30(lbl_8053AAF8);
    for (s32 i = 0; i < n; i++) {
        if (fn_8023F264(i)) {
            s32 v = fn_80236228((void*)i);
            if (v < min) {
                min = v;
                best = i;
            } else if (v == min) {
                second = min;
            }
        }
    }
    if (second == min) {
        best = -1;
    }
    return best;
}

extern "C" s32 fn_8023B2B0(s32 player);
extern "C" void* fn_801F666C(void* base, s32 id);
extern "C" void detach__5ActorFv(void* actor);
extern "C" f32* fn_8023E724(s32 idx);
extern "C" u8 fn_80236B50(s32 idx);
extern "C" u8 fn_8022DCD8(s32 idx);
extern "C" u8 fn_80234C5C(s32 idx);
extern "C" u8 fn_8023EA28(s32 idx);
extern "C" u8 fn_8022D534(s32 idx);
extern "C" u8 fn_802349EC(s32 idx);
extern "C" s32 fn_8022CAF8(s32 idx);
extern "C" u8 fn_8022F478(s32 idx);
extern int __float_max[];

extern "C" s32 fn_801CC820(s32 player, f32* outPos) {
    s32 id;
    s32 result = 0;
    if (outPos != 0) {
        outPos[0] = lbl_8053EF7C;
        outPos[1] = lbl_8053EF7C;
        outPos[2] = lbl_8053EF7C;
    }
    id = fn_8023B2B0(player);
    if (id >= 0) {
        u8* a = (u8*)fn_801F666C(fn_801F856C(), id);
        if (a != 0 && a[0x11c] != 0 && *(u32*)(a + 0x1a0) == 'ARRW' && *(s32*)(a + 0x108) > 0) {
            result = 1;
            if (outPos != 0) {
                outPos[0] = *(f32*)(a + 0x3c);
                outPos[1] = *(f32*)(a + 0x40);
                outPos[2] = *(f32*)(a + 0x44);
            }
            detach__5ActorFv(a);
        }
    }
    return result;
}

static inline f32 sq(f32 x) { return x * x; }

extern "C" s32 fn_801CCE3C(const f32* pos, s32 group) {
    f32 dy;
    f32 best = *(f32*)__float_max;
    s32 bestIdx = -1;
    for (s32 i = 0; i < 4; i++) {
        if (fn_8023F264(i) && group == fn_8023DE58(i) && !fn_8022F514((void*)i)) {
            dy = fn_8023E724(i)[1] - pos[1];
            f32 d = sq(fn_8023E724(i)[0] - pos[0]) + sq(dy);
            if (d < best) {
                best = d;
                bestIdx = i;
            }
        }
    }
    return bestIdx;
}

extern "C" s32 fn_801CCFE4(s32 i) {
    s32 result = 0;
    if (fn_8023F264(i) && !fn_80236B50(i) && !fn_8022DCD8(i) && !fn_80234C5C(i) && !fn_8023EA28(i)
        && !fn_80230188(i) && !fn_8022D534(i) && !fn_802349EC(i)) {
        switch (fn_8022CAF8(i)) {
        case 4:
        case 5:
            if (!fn_8022F478(i)) {
                result = 1;
            }
            break;
        default:
            result = 1;
            break;
        }
    }
    return result;
}

extern "C" s32 fn_8023B358(s32 player);

extern "C" s32 fn_801CC640(s32 player, s32* outId, f32* outPos) {
    s32 id;
    s32 result = 0;
    if (outId != 0) {
        *outId = -1;
    }
    if (outPos != 0) {
        outPos[0] = lbl_8053EF7C;
        outPos[1] = lbl_8053EF7C;
        outPos[2] = lbl_8053EF7C;
    }
    id = fn_8023B358(player);
    if (id >= 0) {
        u8* a = (u8*)fn_801F666C(fn_801F856C(), id);
        if (a != 0 && a[0x11c] != 0 && *(u32*)(a + 0x1a0) == 'PCDM' && *(s32*)(a + 0x108) > 0) {
            result = 1;
            if (outId != 0) {
                *outId = id;
            }
            if (outPos != 0) {
                outPos[0] = *(f32*)(a + 0x3c);
                outPos[1] = *(f32*)(a + 0x40);
                outPos[2] = *(f32*)(a + 0x44);
            }
            *(s32*)(a + 0x108) = 0;
        }
    }
    return result;
}

extern "C" s32 fn_801CC730(s32 player, s32* outId, f32* outPos) {
    s32 id;
    s32 result = 0;
    if (outId != 0) {
        *outId = -1;
    }
    if (outPos != 0) {
        outPos[0] = lbl_8053EF7C;
        outPos[1] = lbl_8053EF7C;
        outPos[2] = lbl_8053EF7C;
    }
    id = fn_8023B2B0(player);
    if (id >= 0) {
        u8* a = (u8*)fn_801F666C(fn_801F856C(), id);
        if (a != 0 && a[0x11c] != 0 && *(u32*)(a + 0x1a0) == 'ARRW' && *(s32*)(a + 0x108) > 0) {
            result = 1;
            if (outId != 0) {
                *outId = id;
            }
            if (outPos != 0) {
                outPos[0] = *(f32*)(a + 0x3c);
                outPos[1] = *(f32*)(a + 0x40);
                outPos[2] = *(f32*)(a + 0x44);
            }
            *(s32*)(a + 0x108) = 0;
        }
    }
    return result;
}

extern "C" s32 fn_8023B22C(s32 player);
extern const f32 lbl_8053EF90;

extern "C" s32 fn_801CC538(s32 player, const f32* in, JGeometry::TVec3<f32>* out, s32* outId) {
    s32 result = 0;
    if (outId != 0) {
        *outId = -1;
    }
    s32 id = fn_8023B22C(player);
    if (id >= 0) {
        u8* a = (u8*)fn_801F666C(fn_801F856C(), id);
        if (a != 0 && a[0x11c] != 0 && *(u32*)(a + 0x1a0) == 'BOME') {
            result = 1;
            if (outId != 0) {
                *outId = id;
            }
            *(s32*)(a + 0x254) = 1;
            if (out != 0) {
                JGeometry::TVec3<f32> scaled;
                scaled = *(JGeometry::TVec3<f32>*)(a + 0x3c);
                scaled.scale(3.0f);
                out->sub(JGeometry::TVec3<f32>(in[0], in[1], 0.0f), scaled);
            }
        }
    }
    return result;
}

extern const f32 lbl_8053EF9C;

extern "C" s32 fn_801CC9F8(const f32* pos, s32 layer) {
    s32 result = 0;
    u8* mgr = fn_802D6A9C() + 0x10000;
    if (mgr[layer + 0x31df] != 0 && (u16)fn_802265FC((void*)pos, layer) == 0) {
        if ((u16)fn_802265FC(&JGeometry::TVec2<f32>(lbl_8053EF9C + pos[0], pos[1]), layer) == 0) {
            if ((u16)fn_802265FC(&JGeometry::TVec2<f32>(pos[0] - lbl_8053EF9C, pos[1]), layer) == 0) {
                if ((u16)fn_802265FC(&JGeometry::TVec2<f32>(pos[0], lbl_8053EF9C + pos[1]), layer) == 0) {
                    if ((u16)fn_802265FC(&JGeometry::TVec2<f32>(pos[0], pos[1] - lbl_8053EF9C), layer) == 0) {
                        result = 1;
                    }
                }
            }
        }
    }
    return result;
}

extern "C" s32 fn_801CD580(s32 exclude) {
    s32 list[3];
    s32 n = 0;
    s32* p = list;
    for (s32 i = 0; i < 4; i++) {
        if (i != exclude) {
            *p++ = i;
            n++;
        }
    }
    return list[fn_801CD664(n)];
}
struct CB270ResMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* get(u32 type, const char* name);
};
extern const f32 lbl_8053EF58;
extern const f32 lbl_8053EF5C;

extern "C" f32 fn_801CB270(const char* name, GXTexObj* tex, GXTlutObj* tlut) {
    ResTIMG* img = (ResTIMG*)(*(CB270ResMgr**)(lbl_8053AAF8 + 0xa4))->get('TIMG', name);
    u32 mip = img->mIsMIPmapEnabled != 0;
    void* data = (u8*)img + (img->mImageDataOffset != 0 ? img->mImageDataOffset : 0x20);
    if (img->mPaletteFormat != 0) {
        GXInitTexObjCI(tex, data, img->mSizeX, img->mSizeY, (GXCITexFmt)img->mTextureFormat,
                       (GXTexWrapMode)img->mWrapS, (GXTexWrapMode)img->mWrapT, mip, 0);
        if (tlut != 0) {
            GXInitTlutObj(tlut, (u8*)img + img->mPaletteOffset, (GXTlutFmt)img->mLutFormat, (u16)img->mPaletteEntryCount);
        }
    } else {
        GXInitTexObj(tex, data, img->mSizeX, img->mSizeY, (GXTexFmt)img->mTextureFormat,
                     (GXTexWrapMode)img->mWrapS, (GXTexWrapMode)img->mWrapT, mip);
    }
    GXInitTexObjLOD(tex, (GXTexFilter)img->mMinFilterType, (GXTexFilter)img->mMagFilterType,
                    lbl_8053EF58 * img->mMinLOD, lbl_8053EF58 * img->mMaxLOD, lbl_8053EF5C * img->mLODBias,
                    (GXBool)img->mIsBiasClamp, (GXBool)img->mDoEdgeLOD, (GXAnisotropy)img->mIsMaxAnisotropy);
    return (f32)img->mSizeY * (lbl_8053EF60 / (f32)img->mSizeX);
}

extern "C" s32 fn_801CD398(s32 a, s32 b) {
    if (a == b) {
        s32 list[3];
        s32 n = 0;
        s32* p = list;
        for (s32 i = 0; i < 4; i++) {
            if (i != a) {
                *p++ = i;
                n++;
            }
        }
        return list[fn_801CD664(n)];
    } else {
        s32 list[2];
        s32* p = list;
        s32 n = 0;
        for (s32 i = 0; i < 4; i++) {
            if (i != a && i != b) {
                *p++ = i;
                n++;
            }
        }
        return list[fn_801CD664(n)];
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
