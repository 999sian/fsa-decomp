// TU 0x803b9940-0x803bacf8.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"

// ---- from src/Game/fn_803B9A24.cpp ----
extern "C" s32 fn_8004377C(void* mutex);
extern "C" void OSUnlockMutex(void* mutex);

// fn_803B9A24 - helper: if the mutex at this+0x1fd4 can be acquired
// without blocking, inspects this->0x1fd0 (a state field): if 3, sets
// it to 1 and returns 1; otherwise returns 2. Unlocks before returning.
// If the mutex can't be acquired, returns 0.
extern "C" s32 fn_803B9A24(char* this_) {
    s32 result = 0;
    if (fn_8004377C(this_ + 0x1fd4) != 0) {
        s32 state = *(s32*)(this_ + 0x1fd0);
        if (state == 3) {
            *(s32*)(this_ + 0x1fd0) = 1;
            result = 1;
        } else {
            result = 2;
        }
        OSUnlockMutex(this_ + 0x1fd4);
    }
    return result;
}

// ---- from src/Game/fn_803B9A94.cpp ----
extern "C" s32 fn_8004377C(void* mutex);
extern "C" void OSUnlockMutex(void* mutex);
extern "C" void* memcpy(void* dst, const void* src, u32 n);

// fn_803B9A94(this, dst1, n1, dst2, n2, offset) - if the mutex at
// this+0x1fd4 can be acquired without blocking: if this->0x1fd0 (a
// state field) is 3, copies 2 chunks of embedded state OUT of
// this+offset+0x20/+0x280 into the caller-supplied dst1/dst2 buffers,
// sets the state field to 1, and returns 1; otherwise sets the state
// field to 2 and returns 2. Unlocks before returning either way. If
// the mutex couldn't be acquired without blocking, returns 0 (init
// value, no lock attempted release).
extern "C" s32 fn_803B9A94(char* this_, void* dst1, u32 n1, void* dst2, u32 n2, s32 offset) {
	s32 result = 0;
	if (fn_8004377C(this_ + 0x1fd4) != 0) {
		if (*(s32*)(this_ + 0x1fd0) == 3) {
			memcpy(dst1, this_ + offset + 0x20, n1);
			memcpy(dst2, this_ + offset + 0x280, n2);
			*(s32*)(this_ + 0x1fd0) = 1;
			result = 1;
		} else {
			*(s32*)(this_ + 0x1fd0) = 2;
			result = 2;
		}
		OSUnlockMutex(this_ + 0x1fd4);
	}
	return result;
}

// ---- from src/Game/fn_803B9B3C.cpp ----
extern "C" s32 fn_8004377C(void* mutex);
extern "C" void OSUnlockMutex(void* mutex);
extern "C" void fn_8004392C(void* cond);

// fn_803B9B3C - helper: if the mutex at this+0x1fd4 can be acquired
// without blocking, sets this->0x1fcc=2, unlocks, and signals the
// condvar at this+0x1fec.
extern "C" void fn_803B9B3C(char* this_) {
    if (fn_8004377C(this_ + 0x1fd4) != 0) {
        *(s32*)(this_ + 0x1fcc) = 2;
        OSUnlockMutex(this_ + 0x1fd4);
        fn_8004392C(this_ + 0x1fec);
    }
}

// ---- from src/Game/fn_803B9B8C.cpp ----
extern "C" s32 fn_8004377C(void* mutex);
extern "C" void OSUnlockMutex(void* mutex);
extern "C" void fn_8004392C(void* cond);

// fn_803B9B8C - sibling of fn_803B9B3C: same mutex-try/set/unlock/
// signal shape, but sets this->0x1fcc=1 instead of 2.
extern "C" void fn_803B9B8C(char* this_) {
    if (fn_8004377C(this_ + 0x1fd4) != 0) {
        *(s32*)(this_ + 0x1fcc) = 1;
        OSUnlockMutex(this_ + 0x1fd4);
        fn_8004392C(this_ + 0x1fec);
    }
}

// ---- from src/Game/fn_803B9BDC.cpp ----
extern "C" s32 fn_8004377C(void* mutex);
extern "C" void OSUnlockMutex(void* mutex);

// fn_803B9BDC - helper: if the mutex at this+0x1fd4 can be acquired
// without blocking, inspects this->0x1fd0 (a state field): if 4, sets
// it to 1 and returns 1; if 1, returns 0; otherwise returns 2. Unlocks
// before returning. If the mutex can't be acquired, returns 0 (init
// value, no lock attempted release).
extern "C" s32 fn_803B9BDC(char* this_) {
    s32 result = 0;
    if (fn_8004377C(this_ + 0x1fd4) != 0) {
        s32 state = *(s32*)(this_ + 0x1fd0);
        if (state == 4) {
            *(s32*)(this_ + 0x1fd0) = 1;
            result = 1;
        } else if (state == 1) {
            result = 0;
        } else {
            result = 2;
        }
        OSUnlockMutex(this_ + 0x1fd4);
    }
    return result;
}

// ---- from src/Game/fn_803B9C5C.cpp ----
extern "C" s32 fn_8004377C(void* mutex);
extern "C" void OSUnlockMutex(void* mutex);

// fn_803B9C5C - helper: if the mutex at this+0x1fd4 can be acquired
// without blocking, inspects this->0x1fd0 (a state field): if 5, sets
// it to 2 and returns 1; otherwise returns 2. Unlocks before returning.
// If the mutex can't be acquired, returns 0.
extern "C" s32 fn_803B9C5C(char* this_) {
    s32 result = 0;
    if (fn_8004377C(this_ + 0x1fd4) != 0) {
        s32 state = *(s32*)(this_ + 0x1fd0);
        if (state == 5) {
            *(s32*)(this_ + 0x1fd0) = 2;
            result = 1;
        } else {
            result = 2;
        }
        OSUnlockMutex(this_ + 0x1fd4);
    }
    return result;
}

// ---- from src/Game/fn_803B9CCC.cpp ----
extern "C" s32 fn_8004377C(void* mutex);
extern "C" void OSUnlockMutex(void* mutex);
extern "C" void fn_8004392C(void* cond);
extern "C" void* memcpy(void* dst, const void* src, u32 n);

// fn_803B9CCC(this, src, len, offset) - if the mutex at this+0x1fd4
// can be acquired without blocking, copies `len` bytes from `src` into
// this+offset+0x20 (an embedded byte-array member), sets
// this->0x1fcc=3, unlocks, and signals the condvar at this+0x1fec.
extern "C" void fn_803B9CCC(char* this_, void* src, u32 len, s32 offset) {
    if (fn_8004377C(this_ + 0x1fd4) != 0) {
        memcpy(this_ + offset + 0x20, src, len);
        *(s32*)(this_ + 0x1fcc) = 3;
        OSUnlockMutex(this_ + 0x1fd4);
        fn_8004392C(this_ + 0x1fec);
    }
}

// ---- from src/Game/fn_803B9D54.cpp ----
extern "C" s32 fn_8004377C(void* mutex);
extern "C" void OSUnlockMutex(void* mutex);
extern "C" void fn_8004392C(void* cond);
extern "C" void* memcpy(void* dst, const void* src, u32 n);

// fn_803B9D54(this, src1, len1, src2, len2, offset) - sibling of
// fn_803B9CCC with 2 embedded byte-array members instead of 1: if the
// mutex at this+0x1fd4 can be acquired without blocking, copies len1
// bytes from src1 into (this+offset)+0x20 and len2 bytes from src2
// into (this+offset)+0x280, sets this->0x1fcc=3, unlocks, and signals
// the condvar at this+0x1fec.
extern "C" void fn_803B9D54(char* this_, void* src1, u32 len1, void* src2, u32 len2, s32 offset) {
    if (fn_8004377C(this_ + 0x1fd4) != 0) {
        char* base = this_ + offset;
        memcpy(base + 0x20, src1, len1);
        memcpy(base + 0x280, src2, len2);
        *(s32*)(this_ + 0x1fcc) = 3;
        OSUnlockMutex(this_ + 0x1fd4);
        fn_8004392C(this_ + 0x1fec);
    }
}

// ---- from src/Game/fn_803B9DDC.cpp ----
extern "C" s32 fn_8004377C(void* mutex);
extern "C" void OSUnlockMutex(void* mutex);
extern "C" void fn_8004392C(void* cond);

// fn_803B9DDC - sibling of fn_803B9B3C/fn_803B9B8C: same mutex-try/
// set/unlock/signal shape, sets this->0x1fcc=4.
extern "C" void fn_803B9DDC(char* this_) {
    if (fn_8004377C(this_ + 0x1fd4) != 0) {
        *(s32*)(this_ + 0x1fcc) = 4;
        OSUnlockMutex(this_ + 0x1fd4);
        fn_8004392C(this_ + 0x1fec);
    }
}

// ---- from src/Game/MutexNotify_803B9E2C.cpp ----
extern "C" s32 fn_802B1DCC(void* obj);
extern "C" u32 fn_803B9940(char* this_, s32 arg);
extern "C" s32 fn_80056048(s32 arg);
extern "C" void OSLockMutex(void* mutex);
extern "C" void OSUnlockMutex(void* mutex);
extern "C" void fn_8004392C(void* cond);

extern void* lbl_8053ACA8;

extern "C" void fn_803B9E2C(char* this_) {
    if ((u8)fn_802B1DCC(lbl_8053ACA8) != 0) {
        OSLockMutex(this_ + 0x1fd4);
        *(s32*)(this_ + 0x1fcc) = 6;
        *(u8*)(this_ + 0x1ff5) = 3;
        OSUnlockMutex(this_ + 0x1fd4);
        fn_8004392C(this_ + 0x1fec);
        return;
    }

    if (fn_803B9940(this_, 0) == 0xe) {
        return;
    }

    if (fn_80056048(0) != 0) {
        if (fn_803B9940(this_, 0) == 0) {
            OSLockMutex(this_ + 0x1fd4);
            *(u8*)(this_ + 0x1ff5) = 0;
            *(s32*)(this_ + 0x1fcc) = 5;
            OSUnlockMutex(this_ + 0x1fd4);
            fn_8004392C(this_ + 0x1fec);
            return;
        }
    }

    if (fn_80056048(0) != 0) {
        return;
    }
    if (fn_803B9940(this_, 0) == 0) {
        return;
    }
    OSLockMutex(this_ + 0x1fd4);
    *(u8*)(this_ + 0x1ff5) = 1;
    *(s32*)(this_ + 0x1fcc) = 6;
    OSUnlockMutex(this_ + 0x1fd4);
    fn_8004392C(this_ + 0x1fec);
}

// ---- from src/Game/fn_803BAA1C_dtor.cpp ----
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AFB48[];

extern "C" void* fn_803BAA1C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AFB48;
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// ---- from src/Game/fn_803BAA64.cpp ----
extern char lbl_8051C1A0[];

extern "C" void* OSGetCurrentThread(void);
extern "C" void fn_800855CC(void* buf, void* thread, s32 flags);
extern "C" void __dt__9JKRThreadFv(void* buf, s32 val);
extern "C" void fn_803B9F40(void* obj);

// fn_803BAA64 - helper: sets up a stack context struct via
// fn_800855CC(buf, OSGetCurrentThread(), 0) and
// __dt__9JKRThreadFv(buf, -1), then calls fn_803B9F40(&lbl_8051C1A0). Returns
// 0.
extern "C" s32 fn_803BAA64(void) {
    char buf[0x88];
    fn_800855CC(buf, OSGetCurrentThread(), 0);
    __dt__9JKRThreadFv(buf, -1);
    fn_803B9F40(lbl_8051C1A0);
    return 0;
}
