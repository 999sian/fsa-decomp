// RAIL_800FD438: .text 0x800FD438-0x800FE8C0 (actor RAIL)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

// ---- from Game/fn_800FD438_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049C770[];

extern "C" void* fn_800FD438(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049C770;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- from Game/oscluster_800fde38.cpp

extern "C" {

/* fn_800FDE38(ringArray): a "ping-pong" direction stepper for the same
 * ring struct documented in oscluster_800fd498.c/fn_800FD894/fn_800FD998
 * (`+0x1`=direction mode, `+0x2`=ring size, `+0x3`=accumulator index).
 * Toggles the direction mode, then increments or decrements the
 * accumulator index accordingly, and reverses direction automatically
 * when the accumulator underflows (`0xFF`) or reaches the ring size -
 * i.e. this steps the accumulator back and forth between `0` and
 * `size-1` rather than wrapping around like `fn_800FD818`'s plain
 * stepper. A natural fit for animating a wave/oscillation traveling
 * back and forth along a chain of ring segments. No extab content of
 * its own, landed via the ordinary ASM/nofralloc convention. Caller
 * not traced.
 */

void fn_800FDE38(void* ringArray)
{
    char* r = (char*)ringArray;
    u8 dir;

    dir = *(u8*)(r + 0x1) ^ 1;
    *(u8*)(r + 0x1) = dir;

    if (*(u8*)(r + 0x1) == 0) {
        u8 idx = *(u8*)(r + 0x3);
        *(u8*)(r + 0x3) = idx + 1;
    } else {
        u8 idx = *(u8*)(r + 0x3);
        *(u8*)(r + 0x3) = idx - 1;
    }

    {
        u8 idx = *(u8*)(r + 0x3);
        if (idx == 0xff) {
            u8 size = *(u8*)(r + 0x2);
            *(u8*)(r + 0x3) = size - 1;
            return;
        }
        if (idx != *(u8*)(r + 0x2)) {
            return;
        }
        *(u8*)(r + 0x3) = 0;
    }
}

} // extern "C"


// ---- rail node ring helpers

typedef JGeometry::TVec3<f32> RailVec;

struct RailNode {
    u8 pad0[4];
    s32 mId;
    u8 pad8[4];
    RailVec mPos;
    u8 pad18[0x90 - 0x18];
    u32 mFlags;
};

struct RailRing {
    u8 m0;
    u8 mDir;
    u8 mSize;
    u8 mCur;
    RailNode* mNodes[1];
};

extern f32 lbl_8053C0B0;
extern f32 lbl_8053C0D8;

extern "C" void fn_800FD498(void) {}
extern "C" void fn_800FD49C(void) {}

extern "C" void fn_800FD4A0(RailNode* node) {
    node->mPos.x += 8.0f;
    node->mPos.y += 8.0f;
}

extern "C" BOOL fn_800FD4C0(RailRing* ring, u8 a, u8 b) {
    u8 f8 = 0;
    u8 f10 = 0;
    u32 flags = ring->mNodes[a]->mFlags;
    if (flags & 8) {
        f8 = 1;
    } else if (flags & 0x10) {
        f10 = 1;
    }
    flags = ring->mNodes[b]->mFlags;
    if (flags & 8) {
        f8 = 1;
    } else if (flags & 0x10) {
        f10 = 1;
    }
    if (f8 == 1 && f10 == 1) {
        return TRUE;
    }
    return FALSE;
}

extern "C" u32 fn_800FD548(RailRing* ring, u8 i) {
    if (i == 0xff) {
        i = ring->mCur;
    }
    if (ring->mDir != 0) {
        return (ring->mNodes[i]->mFlags >> 3) & 1;
    }
    return (ring->mNodes[i]->mFlags >> 4) & 1;
}

extern "C" BOOL fn_800FD594(RailRing* ring, u8 i) {
    u32 f;
    if (i == 0xff) {
        f = ring->mNodes[ring->mCur]->mFlags & 4;
    } else {
        f = ring->mNodes[i]->mFlags & 4;
    }
    if (f != 0) {
        return FALSE;
    }
    return TRUE;
}

extern "C" u8 fn_800FE21C(RailRing* ring, u8 i) {
    if (i == 0xff) {
        return ring->mNodes[ring->mCur]->mFlags >> 24;
    }
    return ring->mNodes[i]->mFlags >> 24;
}

extern "C" s32 fn_800FE25C(RailRing* ring, u8 i) {
    if (i == 0xff) {
        return ring->mNodes[ring->mCur]->mId;
    }
    return ring->mNodes[i]->mId;
}

extern "C" RailVec fn_800FE294(RailRing* ring, u8 i) {
    if (i == 0xff) {
        return ring->mNodes[ring->mCur]->mPos;
    }
    return ring->mNodes[i]->mPos;
}

extern "C" void OSPanic(const char* file, int line, const char* msg, ...);
extern char lbl_80463A70[];
extern char lbl_80463A80[];

static inline s32 railGetId(RailRing* ring, u8 i) {
    if (i == 0xff) {
        return ring->mNodes[ring->mCur]->mId;
    }
    return ring->mNodes[i]->mId;
}

static inline u32 railLoopMode(RailRing* ring, u8 n) {
    return ((RailNode**)ring)[n]->mFlags & 3;
}

extern "C" void fn_800FD818(RailRing* ring, s8 step) {
    u8 size = ring->mSize;
    u32 mode = railLoopMode(ring, size);
    s32 idx = step + ring->mCur;
    if ((s16)idx < 0) {
        if (mode == 1) {
            ring->mCur = size + idx;
        } else {
            ring->mCur = 0;
        }
    } else if ((s16)idx >= size) {
        idx -= size;
        if (mode == 1) {
            ring->mCur = idx;
        } else {
            ring->mCur = size - 1;
        }
    } else {
        ring->mCur = idx;
    }
}

extern "C" u8 fn_800FD894(RailRing* ring, s32 id, u8* out, s32 max) {
    if (id == -1) {
        if (out != NULL) {
            for (u8 i = 0; i < ring->mSize; i++) {
                out[i] = i;
            }
        }
        return ring->mSize;
    }
    u8 n = 0;
    for (u8 i = 0; i < ring->mSize; i++) {
        if (id == railGetId(ring, i)) {
            if (max == n) {
                OSPanic(lbl_80463A70, 0x1a3, lbl_80463A80);
            }
            out[n++] = i;
        }
    }
    return n;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
