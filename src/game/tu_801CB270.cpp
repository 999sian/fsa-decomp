// Game TU 801CB270-801CDC8C (unnamed). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern "C" u8 fn_8022F514(void* this_);
extern "C" u8 fn_80303750(void* this_);
extern "C" s32 fn_801CD970(s16* value, s16 target, s16 step);
extern "C" s32 fn_801CD9F0(f32* value, f32 target, f32 step);
extern "C" s32 fn_8023DE58(s32 playerIdx);

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

#include "JSystem/JAudio/JASFakeMatchFSA.h"
