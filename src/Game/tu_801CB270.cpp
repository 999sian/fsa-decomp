// Game TU 801CB270-801CDC8C (unnamed). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
extern "C" void* fn_8022F3DC(void* p);
extern "C" void fn_80236228(void* p);
extern "C" u32 fn_80226998(void* p);
extern "C" s32 fn_80138A30(void* p);
extern "C" u8 fn_80230188(s32 idx);
extern "C" void* fn_801F856C(void);
extern "C" void fn_801F8544(void* mgr, u32 tag, u32 a, u32 b, u32 flags);
extern u8* lbl_8053AAF8;
extern const f32 lbl_8053EF60;
extern const f64 lbl_8053EF68;
extern const f64 lbl_8053EF70;
extern const f32 lbl_8053EF7C;
extern const f32 lbl_8053EF98;

extern "C" u8 fn_8022F514(void* this_);
extern "C" BOOL fn_801CD9F0(f32* value, f32 target, f32 step);
extern "C" u8 fn_80303750(void* this_);
extern "C" s32 fn_801CD970(s16* value, s16 target, s16 step);

extern "C" s32 fn_8023DE58(s32 playerIdx);

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

extern "C" BOOL fn_801CCC78(void* p) {
    BOOL result = FALSE;
    switch ((u16)fn_80226998(p)) {
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

#include "JSystem/JAudio/JASFakeMatchFSA.h"
