// TU 0x801f68e0-0x801f9484.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"
#include "float.h"
#include "Game/Actor.h"

extern "C" u8* fn_802D6A9C(void);
extern "C" void fn_802D39B8(void* mgr, s32 idx, s32 value);
extern "C" u8 fn_8023EBB8(s32 idx);
extern "C" s32 fn_8023EF50(s32 idx);
extern "C" void fn_80204638(void);
extern "C" void fn_802048F4(void);

// ---- stub_801f714c.cpp ----
// fn_801F714C(shortPtr, target, divisor, maxStep) - integer/angle "ease
// toward" helper: delta = (target - *shortPtr) / divisor (word divide,
// sign-extended through 16 bits at each step, matching 16-bit angle
// arithmetic), then clamps that delta to +/-maxStep before adding it
// to *shortPtr.
extern "C" void fn_801F714C(void* shortPtr, s32 target, s32 divisor, s32 maxStep) {
	u16 current = *(u16*)shortPtr;
	s32 divisorMasked = divisor & 0xffff;
	s32 maxStepMasked = maxStep & 0xffff;
	s16 delta = (s16)(target - current);
	s32 rawDiv = delta / divisorMasked;
	s16 clampedDelta = (s16)rawDiv;
	if (clampedDelta > maxStepMasked) {
		*(u16*)shortPtr = current + maxStep;
		return;
	}
	if (clampedDelta < -maxStepMasked) {
		*(u16*)shortPtr = current - maxStep;
		return;
	}
	*(u16*)shortPtr = current + (u16)clampedDelta;
}

// ---- fn_801F8544.cpp ----
extern "C" s32 Actor_CreateByID(void* base, u32 fourCC, u32 owner, void* posPtr, u32 param, s32 p6, s32 p7);

// fn_801F8544(slotTable, code4, ownerID, posPtr, flags) - NOT a separate
// "spawn by code" primitive after all: it's a thin trampoline around the
// CONFIRMED universal actor dispatcher `Actor_CreateByID` itself (see
// project_fsa_actor_system_discovery.md), appending 2 fixed trailing
// args (-1, -1) that most callers don't need to specify. This means
// Actor_CreateByID's real signature has (at least) 7 parameters, not the
// (slotTable, code4, ownerID, ...) 3-4 previously documented - the 2
// extra args this wrapper defaults are still unconfirmed in meaning.
// Confirmed used by WIZR's rupee-drop-on-defeat mechanic (see
// project_fsa_stal_wizr_full_depth.md) with code4='RUPY'.
extern "C" s32 fn_801F8544(void* base, u32 fourCC, u32 owner, void* posPtr, u32 param) {
    return Actor_CreateByID(base, fourCC, owner, posPtr, param, -1, -1);
}

// ---- stub_801f857c.cpp ----
extern "C" void fn_80456120(void* handle);

// vtable slot 2 (byte offset 8) - see [[reference_fsa_virtual_dispatch_codegen_trick]]
// for why this is a real `virtual` member rather than a manual cast dispatch.
struct ActorSlot2 {
    virtual void destroy(s32 freeFlag);
};

// fn_801F857C(actorPoolBase) - "DESTROY ALL ACTIVE ACTORS", the 3rd sibling
// in the actor-pool API alongside fn_801F8658 (draw-all) and fn_801F871C
// (update-all). Walks the 1024-slot pool; per occupied slot, calls
// fn_80456120(this->0x100c[slot-parallel-array]) (unexplored - shape
// matches an OS lock/mutex acquire given the paired release-style call at
// the very end), destructs via actor->vtable[2](freeFlag=1), clears the
// slot to 0, then maintains a "high-water mark" cache at this->0x1008 -
// if the slot just freed WAS the current high-water index, scans backward
// for the new highest occupied slot. After the full sweep, calls
// fn_80456120(this->0x200c) once more (a 2nd, different lock/counter).
extern "C" void fn_801F857C(void* actorPoolBase) {
    u8* slot = (u8*)actorPoolBase;

    for (u32 i = 0; i < 0x400; i++) {
        if (*(void**)(slot + 8) != 0) {
            fn_80456120(*(void**)(slot + 0x100c));

            ActorSlot2* actor = (ActorSlot2*)*(void**)(slot + 8);
            if (actor != 0) {
                actor->destroy(1);
            }

            *(void**)(slot + 8) = 0;

            s32 highWater = *(s32*)((u8*)actorPoolBase + 0x1008);
            if ((s32)(i + 1) == highWater) {
                s32 j = highWater - 2;
                u8* scan = (u8*)actorPoolBase + j * 4;
                while (j >= 0) {
                    if (*(void**)(scan + 8) != 0) break;
                    scan = scan - 4;
                    j = j - 1;
                }
                *(s32*)((u8*)actorPoolBase + 0x1008) = j + 1;
            }
        }
        slot += 4;
    }

    fn_80456120(*(void**)((u8*)actorPoolBase + 0x200c));
}

// ---- actor pool helpers

struct PoolActor {
    u8 pad0[4];
    s32 mParam;
    u8 pad8[4];
    f32 mX;
    f32 mY;
    f32 mZ;
    u8 pad18[0x90 - 0x18];
    u32 m90;
    u8 pad94[0x11c - 0x94];
    u8 mActive;
    u8 mVisible;
    u8 pad11e;
    u8 m11f;
    u8 pad120[0x194 - 0x120];
    u8 m194;
    u8 pad195[0x198 - 0x195];
    s32 mId;
    u8 pad19c[4];
    u32 mType;
    u8 pad1a4[4];
    u8 m1a8;
};

struct LinkActor {
    u8 pad0[0x15c];
    LinkActor* mPrev;
    LinkActor* mNext;
    u8 pad164;
    u8 mLinked;
};

struct LinkPool {
    u8 pad0[0x2018];
    LinkActor* mHead;
};

struct ActorPool {
    u8 pad0[8];
    PoolActor* mActors[0x400];
    s32 mCount;
};

struct PoolHolder {
    u8 pad0[4];
    struct {
        u8 pad0[8];
        void* m8;
    }* m4;
};

extern PoolHolder* lbl_8053AAF8;

extern "C" void* fn_801F856C(void) {
    return lbl_8053AAF8->m4->m8;
}

extern "C" void fn_801F71A4(f32* value, f32 target, f32 rate, f32 maxStep) {
    if (*value == target) {
        return;
    }
    f32 step = rate * (target - *value);
    if (step > maxStep) {
        step = maxStep;
    } else if (step < -maxStep) {
        step = -maxStep;
    }
    *value += step;
}

extern "C" s32 fn_801F7A08(ActorPool* pool, u32 type) {
    for (s32 i = 0; i < pool->mCount; i++) {
        if (pool->mActors[i] != NULL && pool->mActors[i]->mActive && type == pool->mActors[i]->mType) {
            return pool->mActors[i]->mId;
        }
    }
    return -1;
}

extern "C" s32 fn_801F7A6C(ActorPool* pool) {
    s32 n = 0;
    for (s32 i = 0; i < pool->mCount; i++) {
        if (pool->mActors[i] != NULL && pool->mActors[i]->mActive && pool->mActors[i]->m1a8) {
            n++;
        }
    }
    return n;
}

extern "C" s32 fn_801F7AB8(ActorPool* pool, u32 type, s32 exceptId) {
    s32 n = 0;
    s32 i;
    s32 cnt;
    for (i = 0, cnt = pool->mCount; i < cnt; i++) {
        if (pool->mActors[i] != NULL && pool->mActors[i]->mActive && type == pool->mActors[i]->mType &&
            exceptId != pool->mActors[i]->mId)
        {
            pool->mActors[i]->mActive = 0;
            n++;
        }
    }
    return n;
}

extern "C" void fn_801F7B18(ActorPool* pool) {
    fn_802D6A9C();
    for (s32 i = 0; i < 4; i++) {
        fn_802D39B8(fn_802D6A9C(), i, -1);
        if (fn_8023EBB8(i)) {
            s32 v = fn_8023EF50(i);
            fn_802D39B8(fn_802D6A9C(), i, v);
        }
    }

    s32 count = pool->mCount;
    for (s32 i = 0; i < count; i++) {
        if (pool->mActors[i] != NULL && pool->mActors[i]->mActive && pool->mActors[i]->mType != 0x545a4f4b) {
            s32 id = pool->mActors[i]->mId;
            if (id != *(s32*)(fn_802D6A9C() + 0x131a8) && id != *(s32*)(fn_802D6A9C() + 0x131ac) &&
                id != *(s32*)(fn_802D6A9C() + 0x131b0) && id != *(s32*)(fn_802D6A9C() + 0x131b4))
            {
                u32 type = pool->mActors[i]->mType;
                if (type != 0x52414e4b && type != 0x4742414f && type != 0x454e444d && type != 0x444d4741) {
                    if (type == 0x5241534e) {
                        if (*(s32*)((u8*)pool->mActors[i] + 0x230) == 0) {
                            pool->mActors[i]->mActive = 0;
                        }
                    } else {
                        pool->mActors[i]->mActive = 0;
                    }
                }
            }
        }
    }

    fn_80204638();
    fn_802048F4();
}

extern "C" s32 fn_801F7818(ActorPool* pool, u32 type, s32 param, PoolActor** out, s32 exceptId) {
    s32 n = 0;
    s32 count = pool->mCount;
    for (s32 i = 0; i < count; i++) {
        if (pool->mActors[i] != NULL && pool->mActors[i]->mActive && param == pool->mActors[i]->mParam &&
            type == pool->mActors[i]->mType && exceptId != pool->mActors[i]->mId)
        {
            *out++ = pool->mActors[i];
            n++;
        }
    }
    return n;
}

extern "C" s32 fn_801F7884(ActorPool* pool, u32 type, s32 param) {
    for (s32 i = 0; i < pool->mCount; i++) {
        if (pool->mActors[i] != NULL && pool->mActors[i]->mActive && param == pool->mActors[i]->mParam &&
            type == pool->mActors[i]->mType)
        {
            return pool->mActors[i]->mId;
        }
    }
    return -1;
}

extern "C" BOOL fn_801F8448(LinkPool* pool, LinkActor* actor) {
    bool removed = false;
    if (actor->mPrev != NULL) {
        actor->mPrev->mNext = actor->mNext;
        if (actor->mNext != NULL) {
            actor->mNext->mPrev = actor->mPrev;
        }
        removed = true;
    } else if (actor == pool->mHead) {
        pool->mHead = actor->mNext;
        if (pool->mHead != NULL) {
            pool->mHead->mPrev = NULL;
        }
        removed = true;
    }
    if (removed) {
        actor->mPrev = NULL;
        actor->mNext = NULL;
    }
    return removed;
}

extern "C" BOOL fn_801F84C4(LinkPool* pool, LinkActor* actor) {
    bool added = false;
    if (pool->mHead != NULL) {
        LinkActor* p = pool->mHead;
        while (true) {
            LinkActor* next = p->mNext;
            if (p == actor) {
                actor->mLinked = 1;
                break;
            }
            if (next == NULL) {
                break;
            }
            p = next;
        }
        if (p != actor) {
            p->mNext = actor;
            added = true;
            actor->mPrev = p;
            actor->mLinked = 1;
        }
    } else {
        pool->mHead = actor;
        added = true;
        actor->mPrev = NULL;
        actor->mNext = NULL;
        actor->mLinked = 1;
    }
    return added;
}

extern "C" BOOL fn_801F71E8(ActorPool* pool, u32 key, PoolActor** out, s32* count, s32 max) {
    s32 n = pool->mCount;
    *count = 0;
    for (s32 i = 0; i < n; i++) {
        if (pool->mActors[i] != NULL && pool->mActors[i]->mActive && pool->mActors[i]->mType == 'RAIL' &&
            key == ((pool->mActors[i]->m90 >> 8) & 0xff))
        {
            out[*count] = pool->mActors[i];
            (*count)++;
            if (*count == max) {
                return FALSE;
            }
        }
    }
    return TRUE;
}

extern "C" s32 fn_801F7664(ActorPool* pool, f32* pos, f32* outDist) {
    s32 id = -1;
    f32 best = 1000000.0f;
    for (s32 i = 0; i < pool->mCount; i++) {
        if (pool->mActors[i] != NULL && pool->mActors[i]->mActive && pool->mActors[i]->m1a8 == 1) {
            f32 dy = pos[1] - pool->mActors[i]->mY;
            f32 dx = pos[0] - pool->mActors[i]->mX;
            f32 dx2 = dx * dx;
            f32 dy2 = dy * dy;
            f32 d = dx2 + dy2;
            if (d < best) {
                id = pool->mActors[i]->mId;
                best = d;
            }
        }
    }
    if (outDist != NULL) {
        *outDist = best;
    }
    return id;
}

extern "C" s32 fn_801F778C(ActorPool* pool, u32 type, f32* pos, f32* outDist) {
    s32 id = -1;
    f32 best = 1000000.0f;
    for (s32 i = 0; i < pool->mCount; i++) {
        if (pool->mActors[i] != NULL && pool->mActors[i]->mActive && type == pool->mActors[i]->mType) {
            f32 dx = pos[0] - pool->mActors[i]->mX;
            f32 dy = pos[1] - pool->mActors[i]->mY;
            f32 dx2 = dx * dx;
            f32 dy2 = dy * dy;
            f32 d = dx2 + dy2;
            if (d < best) {
                id = pool->mActors[i]->mId;
                best = d;
            }
        }
    }
    if (outDist != NULL) {
        *outDist = best;
    }
    return id;
}

extern "C" s32 fn_801F76F0(ActorPool* pool, u32 type, s32 param, f32* pos, s32 exceptId) {
    f32 best = FLT_MAX;
    s32 id = -1;
    for (s32 i = 0; i < pool->mCount; i++) {
        if (pool->mActors[i] != NULL && pool->mActors[i]->mActive && type == pool->mActors[i]->mType &&
            param == pool->mActors[i]->mParam && exceptId != pool->mActors[i]->mId)
        {
            f32 dy = pool->mActors[i]->mY - pos[1];
            f32 dx = pool->mActors[i]->mX - pos[0];
            f32 dy2 = dy * dy;
            f32 dx2 = dx * dx;
            f32 d = dx2 + dy2;
            if (d < best) {
                best = d;
                id = pool->mActors[i]->mId;
            }
        }
    }
    return id;
}

extern "C" u8 fn_801CC910(PoolActor* actor);
extern "C" u8 fn_801CC960(PoolActor* actor);
extern "C" u8 fn_801CC9B0(PoolActor* actor);

extern "C" s32 fn_801F7464(ActorPool* pool, s32 param, s32 exceptId) {
    s32 count = pool->mCount;
    PoolActor** cur = (PoolActor**)pool;
    s32 id = -1;
    s32 i = 0;
    while (i < count) {
        PoolActor* a = cur[2];
        if (a != NULL && a->mActive && param == a->mParam && exceptId != a->mId && fn_801CC960(a)) {
            id = pool->mActors[i]->mId;
            break;
        }
        cur++;
        i++;
    }
    return id;
}

extern "C" s32 fn_801F750C(ActorPool* pool, s32 param, s32 exceptId) {
    s32 count = pool->mCount;
    s32 id = -1;
    for (s32 i = 0; i < count; i++) {
        if (pool->mActors[i] != NULL && pool->mActors[i]->mActive && param == pool->mActors[i]->mParam &&
            exceptId != pool->mActors[i]->mId && fn_801CC910(pool->mActors[i]))
        {
            id = pool->mActors[i]->mId;
            break;
        }
    }
    return id;
}

extern "C" s32 fn_801F7274(ActorPool* pool, s32 param, PoolActor** out, s32 exceptId) {
    s32 n = 0;
    s32 count = pool->mCount;
    for (s32 i = 0; i < count; i++) {
        if (pool->mActors[i] != NULL && pool->mActors[i]->mActive && param == pool->mActors[i]->mParam &&
            exceptId != pool->mActors[i]->mId && pool->mActors[i]->mZ <= 16.0f &&
            fn_801CC9B0(pool->mActors[i]))
        {
            n++;
            *out++ = pool->mActors[i];
        }
    }
    return n;
}

struct Rect4 { f32 x0, y0, x1, y1; };

static inline u8 rectContains(Rect4* rect, f32* p) {
    return p[0] >= rect->x0 && p[1] >= rect->y0 && p[0] < rect->x1 && p[1] < rect->y1;
}

extern "C" u8 fn_801F75B4(ActorPool* pool, s32 param, f32* rect) {
    s32 result = 1;
    for (s32 i = 0; i < pool->mCount; i++) {
        if (pool->mActors[i] != NULL && pool->mActors[i]->mActive == 1 && param == pool->mActors[i]->mParam &&
            pool->mActors[i]->m1a8 == 1)
        {
            if (rectContains((Rect4*)rect, &pool->mActors[i]->mX) == 1) {
                result = 0;
                break;
            }
        }
    }
    return result;
}

extern "C" u8 fn_80134CC8(PoolHolder* holder);
extern "C" void fn_801A3CFC(PoolActor* actor);
extern "C" void fn_801E9AFC(void);
extern "C" void fn_801E9C74(void);
extern "C" u8* fn_802D6A9C(void);
extern "C" void fn_801F31C4(const Actor* a, f32* out);
extern s32 lbl_8053A168;

extern "C" void fn_801F8658(ActorPool* pool) {
    u8 paused = false;
    if (fn_80134CC8(lbl_8053AAF8)) {
        paused = true;
    }
    for (u32 i = 0; i < 0x400; i++) {
        if (pool->mActors[i] != NULL && pool->mActors[i]->mActive && pool->mActors[i]->mVisible) {
            if (paused) {
                if (pool->mActors[i]->m11f == 0) {
                    continue;
                }
                fn_801A3CFC(pool->mActors[i]);
            }
            ((Actor*)pool->mActors[i])->v06();
        }
    }
    if (!paused) {
        fn_801E9AFC();
        fn_801E9C74();
    }
}

extern "C" void fn_801F7E88(ActorPool* pool) {
    u8* cfg = fn_802D6A9C();
    s32 count = pool->mCount;
    for (s32 i = 0; i < count; i++) {
        if (pool->mActors[i] != NULL && pool->mActors[i]->mActive) {
            if (pool->mActors[i]->mParam != 0 ||
                (pool->mActors[i]->m194 != 0 && !rectContains((Rect4*)(cfg + 0xcc), &pool->mActors[i]->mX)))
            {
                pool->mActors[i]->mActive = 0;
            }
        }
    }
}

extern "C" void fn_801F31C4(const Actor* a, f32* out);
extern "C" s32 fn_801F82CC(void* mgr, Actor* a, u8 c, f32 f) {
    f32 other[4];
    f32 pos[4];
    s32 result = -1;
    fn_801F31C4(a, pos);
    u8 kind = ((u8*)fn_802D6A9C())[a->field_04 + 0x131df];
    PoolActor* p = *(PoolActor**)((u8*)mgr + 0x2018);
    while (p != NULL) {
        if (*((u8*)p + 0x11c) != 0 && p->mParam == (s32)a->field_04 && *((u8*)p + 0xc4) == 0) {
            if (c != 0 || p->mType != 0x4152494A) {
                if (kind != 0 || __fabs(a->field_0C.z - p->mZ) <= f) {
                    fn_801F31C4((Actor*)p, other);
                    f32 v0 = other[0];
                    f32 v1 = other[1];
                    f32 v2 = other[2];
                    f32 v3 = other[3];
                    if (other[0] <= pos[0]) v0 = pos[0];
                    if (other[1] <= pos[1]) v1 = pos[1];
                    if (other[2] >= pos[2]) v2 = pos[2];
                    if (other[3] >= pos[3]) v3 = pos[3];
                    if (v2 < v0 && v3 < v1) {
                        result = p->mId;
                        break;
                    }
                }
            }
        }
        p = *(PoolActor**)((u8*)p + 0x160);
    }
    return result;
}

extern "C" s32 fn_801F78F4(ActorPool* pool, u32 type, s32 afterId) {
    s32 start = 0;
    if (afterId >= 0) {
        if (lbl_8053A168 >= 0 && pool->mActors[lbl_8053A168] != NULL && pool->mActors[lbl_8053A168]->mActive &&
            afterId == pool->mActors[lbl_8053A168]->mId)
        {
            start = lbl_8053A168 + 1;
        } else {
            for (s32 i = 0; i < pool->mCount; i++) {
                if (pool->mActors[i] != NULL && pool->mActors[i]->mActive && afterId == pool->mActors[i]->mId) {
                    start = i + 1;
                    break;
                }
            }
        }
    }
    for (s32 i = start; i < pool->mCount; i++) {
        if (pool->mActors[i] != NULL && pool->mActors[i]->mActive && type == pool->mActors[i]->mType) {
            lbl_8053A168 = i;
            return pool->mActors[i]->mId;
        }
    }
    lbl_8053A168 = -1;
    return -1;
}

struct FadeState {
    u8 pad0[0x284];
    u8 m284;
    u8 pad285[0x28c - 0x285];
    f32 m28c;
};

struct GameGlobals {
    u8 pad0[0x30];
    FadeState* m30;
};

extern GameGlobals* lbl_8053AB10;
extern void* lbl_8053AD70;
extern "C" u8 fn_8023F264(s32 player);
extern "C" u8 fn_8023ED8C(s32 player);
extern "C" void fn_80230C6C(s32 player);
extern "C" u8 fn_802300EC(s32 player);
extern "C" u8 fn_8023E854(s32 player);
extern "C" void fn_80230AD4(s32 player);
extern "C" void fn_8037AE00(void* p);

extern "C" BOOL fn_801F68E0(u8* self) {
    FadeState* fade = lbl_8053AB10->m30;
    if (fade->m284 == 0) {
        fade->m284 = 1;
        fade->m28c = 0.05f;
    }
    s32 n = 0;
    u8 mask = 0;
    for (s32 i = 0; i < 4; i++) {
        if (fn_8023F264(i) && fn_8023ED8C(i)) {
            fn_80230C6C(i);
            n++;
        }
    }
    if (n != 0) {
        return FALSE;
    }
    for (s32 i = 0; i < 4; i++) {
        if (fn_8023F264(i)) {
            mask |= 1 << i;
        }
    }
    for (s32 i = 0; i < 4; i++) {
        if (fn_8023F264(i) && fn_802300EC(i) == 1 && !fn_8023E854(i)) {
            fn_80230AD4(i);
            self[0x3041] |= 1 << i;
        }
    }
    if (self[0x3041] == mask) {
        fn_8037AE00(lbl_8053AD70);
        return TRUE;
    }
    return FALSE;
}

extern "C" s32 fn_801F732C(ActorPool* pool, s32 param, f32* center, f32* pos, s32 exceptId, f32 radius) {
    f32 r2 = radius * radius;
    f32 best = FLT_MAX;
    s32 count = pool->mCount;
    s32 id = -1;
    for (s32 i = 0; i < count; i++) {
        if (pool->mActors[i] != NULL && pool->mActors[i]->mActive && param == pool->mActors[i]->mParam &&
            exceptId != pool->mActors[i]->mId && pool->mActors[i]->mZ <= 16.0f &&
            fn_801CC9B0(pool->mActors[i]))
        {
            PoolActor* a = pool->mActors[i];
            f32 dy = a->mY - center[1];
            f32 dx = a->mX - center[0];
            f32 dy2 = dy * dy;
            f32 dx2 = dx * dx;
            if (dx2 + dy2 <= r2) {
                dy = a->mY - pos[1];
                dx = a->mX - pos[0];
                dy2 = dy * dy;
                dx2 = dx * dx;
                f32 d = dx2 + dy2;
                if (d < best) {
                    best = d;
                    id = a->mId;
                }
            }
        }
    }
    return id;
}

struct PoolLock {
    u8 pad0[0x31];
    u8 m31;
};

struct PoolHolder2 {
    u8 pad0[4];
    struct {
        u8 pad0[8];
        u8* m8;
    }* m4;
};

struct PoolSlots {
    u8 pad0[8];
    ActorSlot2* mActors[0x400];
    s32 mCount;
    void* mLocks[0x400];
};

extern "C" void fn_801F8E4C(u8* pool) {
    PoolSlots* p = (PoolSlots*)pool;
    u32 off;
    u32 i;
    i = 0;
    off = i;
    for (; i < 0x400; i++, off += 4) {
        PoolSlots* s = (PoolSlots*)(pool + off);
        if (s->mActors[0] != 0) {
            fn_80456120(s->mLocks[0]);
            if (s->mActors[0] != 0) {
                s->mActors[0]->destroy(1);
            }
            s->mActors[0] = 0;
            if ((s32)(i + 1) == p->mCount) {
                s32 j;
                for (j = p->mCount - 2; j >= 0; j--) {
                    if (p->mActors[j] != 0) {
                        break;
                    }
                }
                p->mCount = j + 1;
            }
        }
    }
    fn_80456120(*(void**)(pool + 0x200c));
    (*(PoolLock**)(pool + 0x200c))->m31 = 1;
    *(s32*)(pool + 0x2010) = 0;
    *(s32*)(pool + 0x2014) = -1;
    *(s32*)(pool + 0x1008) = -1;
    ((PoolHolder2*)lbl_8053AAF8)->m4->m8[0x305c] = 0;
    *(s32*)(pool + 0x2018) = 0;
    pool[0x3041] = 0;
}

#include "JSystem/JKernel/JKRHeap.h"

struct PoolLockBase {
    u8 pad0[8];
    virtual void l0();
    virtual void l1();
    virtual void l2();
    virtual void l3();
    virtual void l4();
    virtual void l5();
    virtual void l6();
    virtual void l7();
    virtual void l8();
    virtual void l9();
    virtual void release(s32 flag);
};

typedef JKRHeap PoolHeap;

struct ActorPoolFull {
    virtual ~ActorPoolFull();
    PoolHeap* mHeap;
    ActorSlot2* mActors[0x400];
    s32 mCount;
    PoolLockBase* mLocks[0x400];
    PoolLockBase* mLock;
    u8 pad2010[0x304c - 0x2010];
    void* mBuf0;
    void* mBuf1;
    void* mBuf2;
    void* mBuf3;
};

extern void* lbl_804A5800[];

extern "C" ActorPoolFull* fn_801F8F6C(ActorPoolFull* self, s16 freeFlag) {
    if (self != NULL) {
        *(void***)self = lbl_804A5800;
        if (self->mLock != NULL) {
            self->mLock->release(1);
        }
        for (s32 i = 0x3ff; i >= 0; i--) {
            if (self->mLocks[i] != NULL) {
                self->mLocks[i]->release(1);
            }
        }
        for (s32 i = 0x3ff; i >= 0; i--) {
            if (self->mActors[i] != NULL) {
                if (self->mActors[i] != NULL) {
                    self->mActors[i]->destroy(1);
                }
                self->mActors[i] = NULL;
            }
        }
        delete[] (u8*)self->mBuf0;
        delete[] (u8*)self->mBuf1;
        delete[] (u8*)self->mBuf2;
        delete[] (u8*)self->mBuf3;
        self->mHeap->destroy();
        if (freeFlag > 0) {
            ::operator delete(self);
        }
    }
    return self;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
