// Game TU 801ED3DC-801EDBA4 (unnamed). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

#include "JSystem/JUtility/JUTVideo.h"

extern u8* lbl_8053AEF8;
extern void* lbl_8053AF80;
extern void* lbl_8053AED0;
extern const f32 lbl_8053F6F4;
extern const f32 lbl_8053F710;
extern "C" void fn_80458880(void* obj, u32 id, s32 a);
extern "C" void fn_8043CB24(void* obj, f32 x, f32 y, f32 scale, s32 digit, u32 alpha, u32 a, u32 b, u32 c);

struct Rec10 {
    u8 m0;
    u32 m4;
    u8 m8;
    u8 m9;
};

extern "C" void fn_801ED3DC(Rec10* rec, s32 idx, s32 lvl) {
    u8 a = rec->m8;
    u8 b = rec->m9;
    lbl_8053AEF8[0x44] |= (u8)(1 << idx);
    lbl_8053AEF8[idx + 0x3c] = a;
    lbl_8053AEF8[idx + 0x38] = b;
    if (lvl >= 0 && lvl < 4) {
        lbl_8053AEF8[0x44] |= (u8)(1 << (idx + 4));
        lbl_8053AEF8[idx + 0x40] = lvl + 1;
    }
}

extern "C" {
}

extern "C" void fn_801ED798(void* thisPtr) {
	char* p = (char*)thisPtr;
	*(u8*)(p + 0x0) = 0;
	*(u32*)(p + 0x4) = 0;
	*(u8*)(p + 0x8) = 0;
	*(u8*)(p + 0x9) = 0;
}

extern "C" s32 fn_801ED7B0(void* thisObj) {
	s32 result = 0;
	if (*(u8*)((char*)thisObj + 0x0) == 1 &&
	    *(s32*)((char*)thisObj + 0x4) == 0x1c20 &&
	    *(u8*)((char*)thisObj + 0x8) == 0x77 &&
	    *(u8*)((char*)thisObj + 0x9) == 0x63) {
		result = 1;
	}
	return result;
}

extern "C" void fn_801ED7F0(void* thisPtr) {
	char* p = (char*)thisPtr;
	*(u8*)(p + 0x0) = 1;
	*(u32*)(p + 0x4) = 0;
	*(u8*)(p + 0x8) = 0;
	*(u8*)(p + 0x9) = 0;
}

extern "C" void fn_801ED80C(void* thisPtr) {
	char* p = (char*)thisPtr;
	*(u8*)(p + 0x0) = 1;
	*(u32*)(p + 0x4) = 0;
	*(u8*)(p + 0x8) = 0;
	*(u8*)(p + 0x9) = 0;
}

extern "C" void fn_801ED828(const u16& timer) {
    if (timer != 0) {
        for (s32 i = 0; i < 3; i++) {
            if (i * 60 + 30 <= timer && timer <= (i + 1) * 60) {
                GXRenderModeObj* rm = JUTVideo::getManager()->getRenderMode();
                f32 y = lbl_8053F6F4 * (s32)rm->efbHeight;
                f32 x = lbl_8053F6F4 * (s32)rm->fbWidth;
                fn_8043CB24(lbl_8053AED0, x, y, lbl_8053F710, i, 0xff, 0, 1, 0);
                return;
            }
        }
    }
}

extern "C" void fn_801ED8F0(u16* timer) {
    if (*timer != 0) {
        if (*timer % 60 == 0) {
            fn_80458880(lbl_8053AF80, 0x3f, -1);
        }
        (*timer)--;
    }
}

extern "C" void fn_801ED968(void* thisPtr) { *(u16*)thisPtr = 0xb4; }

extern "C" void fn_801ED974(void* thisPtr) { *(u16*)thisPtr = 0x0; }

#include "JSystem/JAudio/JASFakeMatchFSA.h"
