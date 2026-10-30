// TU 0x801f68e0-0x801f9484.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"
#include "float.h"
#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"

#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JGeometry/Box.h"

extern "C" u8* fn_802D6A9C(void);
extern "C" void fn_802D39B8(void* mgr, s32 idx, s32 value);
extern "C" u8 fn_8023EBB8(s32 idx);
extern "C" s32 fn_8023EF50(s32 idx);
extern "C" u8* fn_80204638(void);
extern "C" void fn_802048F4(void);
extern "C" void fn_801F6068(void);
extern "C" void fn_801F6A4C(void* pool);
extern "C" u8 fn_80239D38(void);
extern "C" u8* fn_8020D58C(void);
extern "C" void fn_8020D660(void);
extern "C" void fn_8021F064(void);
extern "C" void fn_8021F130(void);
extern "C" void fn_801C0D70(void);
extern "C" void fn_801C0DCC(void);
extern "C" u8 fn_802DCD0C(void);
extern "C" void fn_801F32F4(void* actor);
extern "C" void fn_801EAB0C(void* p);
extern "C" s32 fn_801A6160(void* actor);
extern "C" void fn_801F33C4(void* actor);
extern "C" void fn_801EE508(void* actor);
extern "C" void fn_80456154(void* handle);
extern "C" u8 fn_8020D6AC(u8* a, s32 room, void* pos, s32 handle, s32 flag);

class JKRHeap;
class WaveController {
public:
	WaveController(s32 a, s32 b, s32 c);
private:
	unsigned char pad[0x5c];
};
extern void* lbl_804A5800[];
extern u8 lbl_80529DEC[];
static f32 lbl_804CABD8[3];
extern f32 lbl_8053F828;
extern "C" char* fn_80085A10(u32 minSize, u32 size, u32 align, void* heap, u8 a5);
extern "C" void fn_801F62AC(u8* this_, JKRHeap* heap);

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
    void* mHandles[0x400];
    void* mFinalHandle;
    u8 pad2010[8];
    LinkActor* mHead;
    s32 mPending[0x400];
    s32 mPendingCount;
    s32 getNum() { return mCount; }
    PoolActor* get(s32 i) { return mActors[i]; }
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

#pragma opt_common_subs off
extern "C" s32 fn_801F7AB8(const ActorPool* pool, u32 type, s32 exceptId) {
    s32 n = 0;
    s32 count = pool->mCount;
    for (s32 i=0;i<count;++i) {
        if(pool->mActors[i] && pool->mActors[i]->mActive &&
           type==pool->mActors[i]->mType && exceptId!=pool->mActors[i]->mId) {
            *(bool*)&pool->mActors[i]->mActive=false;
            ++n;
        }
    }
    return n;
}
#pragma opt_common_subs reset
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

extern "C" void fn_802D39B8(void*, s32, s32);
extern "C" u8 fn_8023EBB8(s32);
extern "C" s32 fn_8023EF50(s32);
extern "C" void fn_801F7CAC(u8* mgr) {
    u8* cfg = fn_802D6A9C();
    u8* it;
    s32 i;
    s32 n;
    s32 c;
    for (c = 0; c < 4; c++) {
        fn_802D39B8(fn_802D6A9C(), c, -1);
        if (fn_8023EBB8(c)) {
            s32 v = fn_8023EF50(c);
            fn_802D39B8(fn_802D6A9C(), c, v);
        }
    }
    n = *(s32*)(mgr + 0x1008);
    it = mgr;
    for (i = 0; i < n; it += 4, i++) {
        u8* a = *(u8**)(it + 8);
        if (a == NULL || a[0x11c] == 0 || *(s32*)(a + 4) != 0) {
            continue;
        }
        u32 id = *(u32*)(a + 0x1a0);
        if (id == 'TZOK' || id == 'FAZR' || id == 'DMGA') {
            continue;
        }
        bool in = false;
        f32 y;
        f32 x = *(f32*)(a + 0xc);
        if (x >= *(f32*)(cfg + 0xcc) && (y = *(f32*)(a + 0x10)) >= *(f32*)(cfg + 0xd0) &&
            x < *(f32*)(cfg + 0xd4) && y < *(f32*)(cfg + 0xd8)) {
            in = true;
        }
        if (in) {
            continue;
        }
        s32 room = *(s32*)(a + 0x198);
        if (room == *(s32*)(fn_802D6A9C() + 0x131a8) || room == *(s32*)(fn_802D6A9C() + 0x131ac) ||
            room == *(s32*)(fn_802D6A9C() + 0x131b0) || room == *(s32*)(fn_802D6A9C() + 0x131b4)) {
            continue;
        }
        u8* b = *(u8**)(it + 8);
        id = *(u32*)(b + 0x1a0);
        if (id == 'RANK' || id == 'GBAO') {
            continue;
        }
        if (id == 'RASN') {
            if (*(s32*)(b + 0x230) == 0) {
                b[0x11c] = 0;
            }
        } else {
            b[0x11c] = 0;
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

#pragma opt_common_subs off
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
#pragma opt_common_subs reset
extern "C" s32 fn_801F7664(ActorPool* pool, f32* pos, f32* outDist) {
    s32 id = -1;
    f32 best = 1000000.0f;
    for (s32 i = 0; i < pool->mCount; i++) {
        if (pool->mActors[i] != NULL && pool->mActors[i]->mActive && pool->mActors[i]->m1a8 == 1) {
            f32 dx = pos[0] - pool->mActors[i]->mX;
            f32 dx2 = dx * dx;
            f32 dy = pos[1] - pool->mActors[i]->mY;
            f32 dy2 = dy * dy;
            f32 d = dx2 + dy2;
            if (d < best) {
                id = pool->mActors[i]->mId;
                best = d;
            }
        }
    }
    if (outDist != NULL) *outDist = best;
    return id;
}
#pragma fp_contract reset
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

extern "C" s32 fn_801F7464(const ActorPool* pool, s32 param, s32 exceptId) {
    s32 count = pool->mCount;
    PoolActor** cur = (PoolActor**)pool;
    s32 id = -1;
    s32 i;
    for (i = 0; i < count; cur++, i++) {
        PoolActor* a = cur[2];
        if (a != NULL && a->mActive && param == a->mParam && exceptId != a->mId && fn_801CC960(a)) {
            id = pool->mActors[i]->mId;
            break;
        }
    }
    return id;
}
extern "C" s32 fn_801F750C(const ActorPool* pool, s32 param, s32 exceptId) {
    s32 count = pool->mCount;
    PoolActor** cur = (PoolActor**)pool;
    s32 id = -1;
    s32 i;
    for (i = 0; i < count; cur++, i++) {
        PoolActor* a = cur[2];
        if (a != NULL && a->mActive && param == a->mParam && exceptId != a->mId && fn_801CC910(a)) {
            id = pool->mActors[i]->mId;
            break;
        }
    }
    return id;
}

#pragma opt_propagation off
extern "C" s32 fn_801F7274(const ActorPool* pool, s32 param, PoolActor** out, s32 exceptId) {
    s32 count = pool->mCount;
    PoolActor** cur = (PoolActor**)pool;
    s32 n = 0;
    s32 i;
    for (i = 0; i < count; cur++, i++) {
        PoolActor* a = cur[2];
        if (a != NULL && a->mActive && param == a->mParam &&
            exceptId != a->mId && a->mZ <= 16.0f && fn_801CC9B0(a)) {
            n++;
            *out++ = cur[2];
        }
    }
    return n;
}
#pragma opt_propagation reset
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
            }
            fn_801A3CFC(pool->mActors[i]);
            ((Actor*)pool->mActors[i])->v06();
        }
    }
    if (!paused) {
        fn_801E9AFC();
        fn_801E9C74();
    }
}

static inline bool unlinkPoolNode(LinkActor* const actor, LinkPool* const pool)
{
    LinkActor* node = actor;
    bool removed = false;
    LinkActor* prev = node->mPrev;
    if (prev != NULL) {
        prev->mNext = node->mNext;
        if (node->mNext != NULL) node->mNext->mPrev = node->mPrev;
        removed = true;
    } else if (node == pool->mHead) {
        pool->mHead = node->mNext;
        if (pool->mHead != NULL) pool->mHead->mPrev = NULL;
        removed = true;
    }
    if (removed) {
        node->mPrev = NULL;
        node->mNext = NULL;
    }
    return removed;
}
static inline bool updatePoolActorDuringPause(u8 paused, const Actor* actor)
{
    if (paused) {
        u32 fc = actor->field_1A0;
        return fc == 'FORM' || fc == 'ALCE' || fc == 'IMUP' ||
            fc == 'SWEV' || fc == 'SEV2' || fc == 'LTEV' || fc == 'PRTC' ||
            fc == 'STPN' || fc == 'TUGF' || (u32)(fc - 'TUTL') <= 1 ||
            fc == 'PEFF' || fc == 'SWDL';
    }
    return false;
}
extern "C" void fn_801F871C(ActorPool* base) {
    u8* n;
    bool bVar;
    u8* next;
    u8* prev;
    u8* pa;
    u8* ph;
    u8* liveSlot;
    u8* slot;
    s32 nPending;
    u8 bVar8;
    u8 cVar13;
    u32 i;
    u32 index;
    u8* a;
    void* handle;
    s32 room;
    u8* act;
    s32 j;

    nPending = 0;
    fn_801F6068();
    ((u8*)base)[0x3040] = 0;
    for (u32 k = 0; k < 0x400; k++) base->mPending[k] = -1;
    bVar8 = 0;
    *(s32*)((u8*)base + 0x301c) = 0;
    if ((((u8*)lbl_8053AAF8)[0x7f] != 0 && (fn_80239D38() != 0 || fn_80134CC8(lbl_8053AAF8) != 0)) || lbl_80529DEC[0x240] != 0) {
        bVar8 = 1;
    }
    cVar13 = ((u8*)lbl_8053AAF8)[0x94];
    if (((u8*)lbl_8053AAF8)[0x96] != 0) {
        cVar13 = 1;
    }
    fn_8020D58C();
    fn_8020D660();
    fn_8021F064();
    fn_8021F130();
    u8* o = fn_80204638();
    *(s32*)(o + 0x54) = 0;
    if (!bVar8) {
        fn_801C0D70();
        fn_801C0DCC();
    }
    fn_802D6A9C();
    if (fn_802DCD0C() != 0) {
        pa = (u8*)base;
        ph = (u8*)base;
        for (i = 0; i < 0x400; i++) {
            a = *(u8**)(pa + 8);
            if (a != 0) {
                if (a[0x11c] != 0) {
                    u8 need = (a[0x11e] != 0 || a[0xc4] != 0 || a[0xcc] != 0);
                    if (need) {
                        fn_801F32F4(a);
                        fn_801EAB0C((*(u8**)(pa + 8)) + 0x1dc);
                        ((Actor*)*(u8**)(pa + 8))->v05();
                        fn_801F33C4(*(u8**)(pa + 8));
                        ((Actor*)*(u8**)(pa + 8))->v03();
                        fn_801EE508(*(u8**)(pa + 8));
                    }
                    fn_80456154(*(void**)(pa + 0x100c));
                    a = *(u8**)(pa + 8);
                    if (*(s32*)(a + 8) == 0 && a[0x1a8] == 1) {
                        nPending++;
                    }
                }
                a = *(u8**)(pa + 8);
                if (a[0x11c] == 0 && *(void**)(ph + 8) != 0) {
                    fn_80456120(*(void**)(ph + 0x100c));
                    a = *(u8**)(ph + 8);
                    if (a != 0) {
                        ((ActorSlot2*)a)->destroy(1);
                    }
                    *(void**)(ph + 8) = 0;
                    if ((s32)(i + 1) == *(s32*)((u8*)base + 0x1008)) {
                        j = *(s32*)((u8*)base + 0x1008) - 2;
                        while (j >= 0) {
                            if (*(void**)((u8*)base + 8 + j * 4) != 0) break;
                            j--;
                        }
                        *(s32*)((u8*)base + 0x1008) = j + 1;
                    }
                }
            }
            pa += 4;
            ph += 4;
        }
        fn_80456154(*(void**)((u8*)base + 0x200c));
    } else {
        liveSlot = (u8*)base;
        slot = (u8*)base;
        for (index = 0; index < 0x400; index++) {
            a = *(u8**)(liveSlot + 8);
            if (a != 0) {
                if (a[0x11c] != 0) {
                    int bVar1 = 0;
                    if (bVar8 == 1) {
                        bVar1 = 1;
                        if (a[0x11f] != 0) bVar1 = 0;
                        if (*(s32*)(a + 8) == 0 && a[0x1a8] == 1) {
                            nPending++;
                        }
                        if (((u8*)lbl_8053AAF8)[0x88] == 2 && *(u32*)(a + 0x1a0) == 0x5357444c) {
                            bVar1 = 0;
                        }
                    }
                    if (!bVar1) {
                        if (cVar13 == 0) goto updateActor;
                        if (cVar13 != 0) {
                            u32 fc = *(u32*)(a + 0x1a0);
                            if (fc == 0x464f524d || fc == 0x414c4345 || fc == 0x494d5550 ||
                            fc == 0x53574556 || fc == 0x53455632 || fc == 0x4c544556 || fc == 0x50525443 ||
                            fc == 0x5354504e || fc == 0x54554746 || (u32)(fc - 0x5455544c) <= 1 ||
                            fc == 0x50454646 || fc == 0x5357444c) goto updateActor;
                        }
                        goto afterActorUpdate;
                        updateActor: {
                            fn_801F32F4(a);
                            fn_801EAB0C((*(u8**)(liveSlot + 8)) + 0x1dc);
                            if (fn_801A6160(*(u8**)(liveSlot + 8)) == 0) {
                                ((Actor*)*(u8**)(liveSlot + 8))->v05();
                                fn_801F33C4(*(u8**)(liveSlot + 8));
                                ((Actor*)*(u8**)(liveSlot + 8))->v03();
                            } else if (*(s32*)((*(u8**)(liveSlot + 8)) + 0xa4) != 0) {
                                ((Actor*)*(u8**)(liveSlot + 8))->v04();
                            }
                            fn_801EE508(*(u8**)(liveSlot + 8));
                        }
                        afterActorUpdate:
                        a = *(u8**)(liveSlot + 8);
                        u8 kind = *(u32*)(a + 0xb8);
                        if (kind == 1 || kind == 2) {
                            s32 idx = *(s32*)((u8*)base + 0x301c);
                            if (*(s32*)((u8*)base + 0x201c + idx * 4) == -1) {
                                *(s32*)((u8*)base + 0x201c + idx * 4) = *(s32*)(a + 0x198);
                                *(s32*)((u8*)base + 0x301c) += 1;
                            }
                        }
                        fn_80456154(*(void**)(liveSlot + 0x100c));
                        a = *(u8**)(liveSlot + 8);
                        if (*(s32*)(a + 8) == 0 && a[0x1a8] == 1) {
                            nPending++;
                        }
                    }
                }
                act = *(u8**)(liveSlot + 8);
                if (act[0x11c] == 0) {
                    if (*(void**)(slot + 8) != 0) {
                        fn_80456120(*(void**)(slot + 0x100c));
                        a = *(u8**)(slot + 8);
                        if (a != 0) {
                            ((ActorSlot2*)a)->destroy(1);
                        }
                        *(void**)(slot + 8) = 0;
                        if ((s32)(index + 1) == *(s32*)((u8*)base + 0x1008)) {
                            j = *(s32*)((u8*)base + 0x1008) - 2;
                            while (j >= 0) {
                                if (*(void**)((u8*)base + 8 + j * 4) != 0) break;
                                j--;
                            }
                            *(s32*)((u8*)base + 0x1008) = j + 1;
                        }
                    }
                } else if (act[0x1a8] != 0 && act[0x196] == 0 && *(f32*)(act + 0x88) - *(f32*)(act + 0x80) > lbl_8053F828 &&
                           *(f32*)(act + 0x8c) - *(f32*)(act + 0x84) > lbl_8053F828 && *(s32*)(act + 0x108) > 0) {
                    handle = *(void**)(act + 0x198);
                    room = *(s32*)(act + 4);
                    u8* sys = (u8*)fn_8020D58C();
                    if (fn_8020D6AC(sys + sys[1] * 0x784 + 4, room, act + 0xc, (s32)handle, 0)) {
                        ((Actor*)*(u8**)(liveSlot + 8))->v07();
                    }
                }
            }
            liveSlot += 4;
            slot += 4;
        }
        fn_80456154(*(void**)((u8*)base + 0x200c));
    }
    fn_801F6A4C(base);
    n = *(u8**)((u8*)base + 0x2018);
    while (n != 0) {
        next = *(u8**)(n + 0x160);
        if (n[0x11c] != 0) {
            if (n[0x165] == 0) {
                bVar = false;
                u8* self = *(u8**)(*(u8**)((u8*)lbl_8053AAF8 + 4) + 8);
                prev = *(u8**)(n + 0x15c);
                if (prev != 0) {
                    *(u8**)(prev + 0x160) = next;
                    if (*(u8**)(n + 0x160) != 0) {
                        *(void**)(*(u8**)(n + 0x160) + 0x15c) = *(void**)(n + 0x15c);
                    }
                    bVar = true;
                } else {
                    if (n == *(u8**)(self + 0x2018)) {
                        *(u8**)(self + 0x2018) = next;
                        if (*(u8**)(self + 0x2018) != 0) {
                            *(u8**)(*(u8**)(self + 0x2018) + 0x15c) = prev;
                        }
                        bVar = true;
                    }
                }
                if (bVar) {
                    *(void**)(n + 0x15c) = 0;
                    *(void**)(n + 0x160) = 0;
                }
            } else {
                n[0x165] = 0;
            }
        }
        n = next;
    }
    if (nPending == 0) {
        u8* self = *(u8**)(*(u8**)((u8*)lbl_8053AAF8 + 4) + 8);
        self[0x305c] = 1;
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

extern "C" s32 fn_801F7F58(ActorPool* pool, PoolActor* a, u32* types, s32 excludeId, f32 f) {
    s32 param = a->mParam;
    s32 result = -1;
    u8* base = (u8*)fn_802D6A9C();
    u8 kind = base[param + 0x131df];
    s32 count = pool->mCount;
    for (s32 i = 0; i < count; i++) {
        PoolActor* p = pool->mActors[i];
        if (p != NULL && p->mActive && p->mParam == a->mParam && excludeId != p->mId) {
            if (kind == 0 && __fabs(a->mZ - p->mZ) > f) {
                continue;
            }
            for (u32* t = types; *t != 'NULL'; t++) {
                if (*t == p->mType) {
                    f32 pos[4];
                    f32 other[4];
                    fn_801F31C4((Actor*)a, pos);
                    fn_801F31C4((Actor*)p, other);
                    f32 v0 = pos[0];
                    f32 v1 = pos[1];
                    f32 v2 = pos[2];
                    f32 v3 = pos[3];
                    if (pos[0] <= other[0]) v0 = other[0];
                    if (pos[1] <= other[1]) v1 = other[1];
                    if (pos[2] >= other[2]) v2 = other[2];
                    if (pos[3] >= other[3]) v3 = other[3];
                    bool hit = false;
                    if (v2 >= v0 && v3 >= v1) {
                        hit = true;
                    }
                    if (hit) {
                        result = p->mId;
                        break;
                    }
                }
            }
            if (result >= 0) {
                break;
            }
        }
    }
    return result;
}

extern "C" s32 fn_801F8108(Actor* self, u32 type, s32 handle, f32 radius) {
    s32 i;
    s32 best;
    u8* pool;
    u8 near;
    u8* slot;
    s32 room;
    u32 types[2];
    f32 boxB[4];
    f32 boxA[4];

    room = self->field_04;
    pool = *(u8**)(*(u8**)((u8*)lbl_8053AAF8 + 4) + 8);
    best = -1;
    types[0] = type;
    types[1] = 'NULL';
    near = fn_802D6A9C()[0x131df + room];
    slot = pool;
    for (i = 0; i < *(s32*)(pool + 0x1008); i++, slot += 4) {
        Actor* e = *(Actor**)(slot + 8);
        if (e == NULL || e->field_11C == 0 || (s32)e->field_04 != (s32)self->field_04 || handle == e->field_198) {
            continue;
        }
        if (near == 0) {
            if (__fabs(self->field_0C.z - e->field_0C.z) > radius) {
                continue;
            }
        }
        u32* p = types;
        while (*p != 'NULL') {
            if (*p == e->field_1A0) {
                fn_801F31C4(self, boxA);
                fn_801F31C4(e, boxB);
                f32 y1 = boxA[3];
                f32 x1 = boxA[2];
                f32 y0 = boxA[1];
                f32 x0 = boxA[0];
                if (x0 <= boxB[0]) x0 = boxB[0];
                if (y0 <= boxB[1]) y0 = boxB[1];
                if (x1 >= boxB[2]) x1 = boxB[2];
                if (y1 >= boxB[3]) y1 = boxB[3];
                if (x1 >= x0 && y1 >= y0) {
                    best = e->field_198;
                    break;
                }
            }
            p++;
        }
        if (best >= 0) {
            return best;
        }
    }
    return best;
}

extern "C" void fn_801F31C4(const Actor* a, f32* out);
extern "C" s32 fn_801F82CC(void* mgr, Actor* a, u8 c, f32 f) {
    f32 other[4];
    f32 pos[4];
    s32 id;
    s32 result = -1;
    fn_801F31C4(a, pos);
    id = a->field_04;
    u8* tbl = (u8*)fn_802D6A9C();
    u8 kind = tbl[id + 0x131df];
    PoolActor* p = *(PoolActor**)((u8*)mgr + 0x2018);
    while (p != NULL) {
        if (*((u8*)p + 0x11c) != 0 && p->mParam == (s32)a->field_04 && *((u8*)p + 0xc4) == 0) {
            if (c != 0 || p->mType != 0x4152494A) {
                if (kind == 0 && __fabs(a->field_0C.z - p->mZ) > f) {
                } else {
                    fn_801F31C4((Actor*)p, other);
                    f32 v0 = other[0];
                    f32 v1 = other[1];
                    f32 v2 = other[2];
                    f32 v3 = other[3];
                    if (other[0] <= pos[0]) v0 = pos[0];
                    if (other[1] <= pos[1]) v1 = pos[1];
                    if (other[2] >= pos[2]) v2 = pos[2];
                    if (other[3] >= pos[3]) v3 = pos[3];
                    u8 hit = 0;
                    if (v0 <= v2 && v3 <= v1) {
                        hit = 1;
                    }
                    if (hit) {
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

extern "C" u8 fn_801F23BC(void* a, u32 id, void* f0C, void* f18, void* p80, f32* out1, f32* out2, u32 c);
extern const f32 lbl_8053F80C;
extern const f32 lbl_8053F810;
extern const f32 lbl_8053F814;
extern const f32 lbl_8053F818;
extern f32 lbl_8053F81C;


inline void addCollisionPosition(JGeometry::TBox2<f32>& box, const u8* actor) {
    const f32* pos = (const f32*)(actor + 0xc);
    f32 y;
    f32 x = *pos++;
    y = *pos;
    box.addPos(x, y);
}

inline u8* findCollisionActorInPool(s32 handle, ActorPool* pool) {
    PoolActor* scanActor;
    PoolActor* result = NULL;
    if (handle >= 0) {
        s32 cached = *(s32*)((u8*)pool + 0x2014);
        if (cached >= 0) {
            PoolActor* actor = pool->mActors[cached];
            if (actor && actor->mActive && handle == actor->mId) {
                result = actor;
                goto done;
            }
        }
        s32 count = pool->mCount;
        PoolActor** cur = (PoolActor**)pool;
        for (s32 i = 0; i < count; cur++, i++) {
            scanActor = cur[2];
            if (scanActor && scanActor->mActive && handle == scanActor->mId) {
                result = pool->mActors[i];
                break;
            }
        }
    }
done:
    return (u8*)result;
}

inline f32 collisionSine(f32 dx, f32 dy) {
    f32 angle = JMath::atanTable_.atan2_(dx, dy);
    return JMath::sincosTable_.mTable[(u16)(s32)(angle * lbl_8053F80C) >> 5].first;
}
inline f32 collisionCosine(f32 dx, f32 dy) {
    f32 angle = JMath::atanTable_.atan2_(dx, dy);
    return JMath::sincosTable_.mTable[(u16)(s32)(angle * lbl_8053F80C) >> 5].second;
}
inline JGeometry::TVec3<f32> collisionVelocity(f32 sine, f32 cosine, f32 z) {
    return JGeometry::TVec3<f32>(lbl_8053F81C * sine, lbl_8053F81C * cosine, z);
}

inline void copyCollisionBox(JGeometry::TBox2<f32>& box, const u8* actor) {
    const f32* src = (const f32*)(actor + 0x60);
    f32 x0 = *src++;
    f32 y0 = *src++;
    f32 x1 = *src++;
    f32 y1 = *src;
    box.set(x0, y0, x1, y1);
}

inline bool collisionBoxesOverlap(const JGeometry::TBox2<f32>& a, const JGeometry::TBox2<f32>& b) {
    JGeometry::TBox2<f32> intersection(a);
    return intersection.intersect(b);
}

extern "C" void fn_801F6A4C(void* pool) {
	u8* b;
	u8* a;
	s32 retry;
	s32 i;
	s32 j;
	s32 k;
	u8* self = (u8*)pool;
	JGeometry::TVec3<f32> tp;
	JGeometry::TBox2<f32> bb;
	JGeometry::TBox2<f32> bx;
	for (i = 0; i <= *(s32*)(self + 0x301c); i++) {
		s32 handle = *(s32*)(self + 0x201c + i * 4);
		if (handle == -1) {
			continue;
		}
		a = findCollisionActorInPool(handle, (ActorPool*)lbl_8053AAF8->m4->m8);
		if (a == NULL || a[0x11c] == 0) {
			continue;
		}

		bx = *(JGeometry::TBox2<f32>*)(a + 0x60);
		addCollisionPosition(bx, a);
		*(s32*)(a + 0x9c) = -1;

		for (j = 0; j < *(s32*)(self + 0x301c); j++) {
			s32 hb = *(s32*)(self + 0x201c + j * 4);
			b = findCollisionActorInPool(hb, (ActorPool*)lbl_8053AAF8->m4->m8);
			if (b == NULL || b[0x11c] == 0) {
				continue;
			}
			if (*(s32*)(a + 4) != *(s32*)(b + 4)) {
				continue;
			}
			if (*(s32*)(a + 0x198) == *(s32*)(b + 0x198)) {
				continue;
			}
			if (*(s32*)(a + 0xbc) > *(s32*)(b + 0xbc)) {
				continue;
			}

		bb = *(JGeometry::TBox2<f32>*)(b + 0x60);
		addCollisionPosition(bb, b);

			if ((*(u32*)(a + 0xb8) & 0xff) == 2) {
				if (collisionBoxesOverlap(bx, bb)) {
					*(s32*)(a + 0x9c) = *(s32*)(b + 0x198);
					j = 0x400;
				}
				continue;
			}

			retry = 0;
			while (collisionBoxesOverlap(bx, bb) && retry < 8) {
				*(s32*)(a + 0x9c) = *(s32*)(b + 0x198);
				tp = *(JGeometry::TVec3<f32>*)(a + 0xc);
				f32 dx = *(f32*)(a + 0xc) - *(f32*)(b + 0xc);
				f32 dy = *(f32*)(a + 0x10) - *(f32*)(b + 0x10);
				copyCollisionBox(bx, a);

				f32 ang = JMath::atanTable_.atan2_(dx, dy);
				s32 ai = (s32)(ang * lbl_8053F80C);
				unsigned int* rng = (unsigned int*)lbl_8053AAF8;
				u32 seed = rng[0xb4/4] * 0x19660d + 0x3c6ef35f;
				rng[0xb4/4] = seed;
				u32 bits = (rng[0xb4/4] >> 9) | 0x3f800000;
				f32 rf = *(f32*)&bits - lbl_8053F818;
				s32 ri = (s32)(lbl_8053F810 - lbl_8053F814 * rf);
				s32 si = ai + ri;
				f32 sn = JMath::sincosTable_.mTable[(u16)si >> 5].first;
				f32 cs = JMath::sincosTable_.mTable[(u16)si >> 5].second;
				tp.x = tp.x + sn;
				tp.y = tp.y + cs;

				if (*(u32*)(b + 0x1a0) == 0x424f594f) {
                    *(JGeometry::TVec3<f32>*)(a + 0x3c) = collisionVelocity(collisionSine(dx, dy), collisionCosine(dx, dy), *(f32*)(a + 0x44));
                    *(u16*)(b + 0x94) = 1;
                }
				if (!fn_801F23BC(a, *(u32*)(a + 4), &tp, a + 0xc, a + 0x80, NULL, NULL, 0)) {
					*(JGeometry::TVec3<f32>*)(a + 0xc) = tp;
					retry++;
					addCollisionPosition(bx, a);
				} else {
					retry = 100;
				}
			}
		}
	}
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
    s32 j;
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

extern "C" u8* fn_801F9078(u8* self, JKRHeap* heap) {
	*(void***)self = lbl_804A5800;
	bool flag = false;
	s32 st = *(s32*)(lbl_80529DEC + 0x118);
	if ((st == 9 && *(s32*)(lbl_80529DEC + 0x11c) == 3) || (st == 8 && *(s32*)(lbl_80529DEC + 0x11c) == 2)) {
		flag = true;
	}
	u32 n = flag ? 0x200 : 0x400;
	*(char**)(self + 4) = fn_80085A10(n, (n << 10) + 0x1a8, 0x20, heap, 0);
	s32* p = (s32*)self;
	for (s32 i = 0x20; i > 0; i--) {
		p[2] = 0;
		p[3] = 0;
		p[4] = 0;
		p[5] = 0;
		p[6] = 0;
		p[7] = 0;
		p[8] = 0;
		p[9] = 0;
		p[10] = 0;
		p[11] = 0;
		p[12] = 0;
		p[13] = 0;
		p[14] = 0;
		p[15] = 0;
		p[16] = 0;
		p[17] = 0;
		p[18] = 0;
		p[19] = 0;
		p[20] = 0;
		p[21] = 0;
		p[22] = 0;
		p[23] = 0;
		p[24] = 0;
		p[25] = 0;
		p[26] = 0;
		p[27] = 0;
		p[28] = 0;
		p[29] = 0;
		p[30] = 0;
		p[31] = 0;
		p[32] = 0;
		p[33] = 0;
		p += 32;
	}
	f32 zero = lbl_8053F828;
	lbl_804CABD8[0] = zero;
	lbl_804CABD8[1] = zero;
	lbl_804CABD8[2] = zero;
	void** slot = (void**)self;
	for (u32 i = 0; i < 0x400; i++) {
		slot[0x403] = new (heap, 0) WaveController((s32)lbl_804CABD8, 0, 8);
		fn_80456120(slot[0x403]);
		slot++;
	}
	((void**)self)[0x803] = new (heap, 0) WaveController(0, 0, 0x18);
	fn_801F62AC(self, heap);
	return self;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
