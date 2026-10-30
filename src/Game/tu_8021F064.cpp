// TU 0x8021f064-0x8021f4b0.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"

struct ActorGroup_8021F064 {
    ActorGroup_8021F064() {
        mFlags = 0;
        mCount = 0;
    }
    u16 mFlags;
    s32 mCount;
    s32 mIds[6];
};

extern "C" {
void* fn_801F856C();
void* fn_801F666C(void* mgr, s32 id);
u8 fn_8021D794(void* actor);
void fn_8021D764(void* actor);
void fn_8021D734(void* actor);

ActorGroup_8021F064* fn_8021F064() {
    static ActorGroup_8021F064 sInstance;
    return &sInstance;
}

#pragma opt_lifetimes off
extern "C" bool fn_8021F094(const ActorGroup_8021F064* g) {
    s32 n = g->mCount;
    if (n <= 0) return false;
    const ActorGroup_8021F064* p = g;
    bool result = true;
    s32 i = 0;
    while (i < n) {
        void* actor = fn_801F666C(fn_801F856C(), p->mIds[0]);
        if (actor != NULL && !fn_8021D794(actor)) {
            result = false;
            break;
        }
        p = (const ActorGroup_8021F064*)((const s32*)p + 1);
        i++;
    }
    return result;
}
#pragma opt_lifetimes reset
void fn_8021F130(ActorGroup_8021F064* g) {
    register void* actor;
    int i;
    if (g->mCount > 0 && (g->mFlags & 3)) {
        for (i = 0; (s32)i < g->mCount; i++) {
            s32 tmp = (s32)fn_801F666C(fn_801F856C(), g->mIds[i]);
            actor = (void*)tmp;
            if (actor != NULL) {
                if (g->mFlags & 1) {
                    fn_8021D764(actor);
                }
                if (g->mFlags & 2) {
                    fn_8021D734(actor);
                }
            }
        }
        g->mFlags &= ~3;
    }
}

#pragma opt_lifetimes off
void fn_8021F1F0(ActorGroup_8021F064* g, s32 id) {
    bool found;
    s32* ptr;
    register int i;
    if (g->mCount <= 0) {
        return;
    }
    ptr = g->mIds;
    found = false;
    if (g->mCount <= 0) {
        return;
    }
    i = found;
    for (; i < g->mCount; i++, ptr++) {
        if (!found) {
            if (id == *ptr) {
                found = true;
            }
        } else {
            *(ptr - 1) = *ptr;
        }
    }
    if (found) {
        g->mCount--;
    }
}
#pragma opt_lifetimes reset
}

// ---- GrowableArray_PushBack_8021F25C.cpp ----
// GrowableArray_PushBack - push-back: appends the incoming word to a growable
// array at this+0x8, indexed by the current count (this->0x4), then
// increments the count. GrowableArray_Reset - trivial reset (this->0x0
// halfword and this->0x4 word both zeroed).
extern "C" {

void GrowableArray_PushBack(void* thisObj, u32 value) {
	u32* arr = (u32*)((char*)thisObj + 0x8);
	u32 count = *(u32*)((char*)thisObj + 0x4);
	arr[count] = value;
	*(u32*)((char*)thisObj + 0x4) += 1;
}

void GrowableArray_Reset(void* thisObj) {
	*(u16*)((char*)thisObj + 0x0) = 0;
	*(u32*)((char*)thisObj + 0x4) = 0;
}

}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
