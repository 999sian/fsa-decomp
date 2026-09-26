// Game TU 801DAC6C-801DB18C (unnamed). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
#include "Game/ItemBase.h"
#include "dolphin/mtx.h"

extern "C" {
}
extern "C" void* fn_801F856C();
extern "C" void* fn_801F666C(void* base, s32 id);
extern "C" void fn_801D8400(void* target);
extern "C" void fn_801F0E34(void* target, s32 soundId, s32 flag);

struct LinkMgr {
    /* 0x00 */ s32 mId0;
    /* 0x04 */ s32 mId1;
    /* 0x08 */ s32 mIds[30];
    /* 0x80 */ s32 mCount;
    /* 0x84 */ s16 m84;

    LinkMgr() {
        mId0 = -1;
        mId1 = -1;
        mCount = 0;
        m84 = 0;
    }
};

extern "C" LinkMgr* fn_801DAC6C(void) {
    static LinkMgr sMgr;
    return &sMgr;
}

extern const f32 lbl_8053F2D8;
extern "C" u8 fn_801DC264(void* actor);

extern "C" BOOL fn_801DACAC(const LinkMgr* mgr, Vec* out) {
    BOOL result = FALSE;
    s32 id = mgr->mId0;
    out->x = lbl_8053F2D8;
    out->y = lbl_8053F2D8;
    out->z = lbl_8053F2D8;
    if (id >= 0) {
        u8* actor = (u8*)fn_801F666C(fn_801F856C(), id);
        if (actor != 0) {
            *out = *(Vec*)(actor + 0xc);
        }
        result = TRUE;
    }
    return result;
}

extern "C" u8 fn_801DAD2C(const LinkMgr* mgr) {
    s32 id = mgr->mId1;
    u8 result = 0;
    if (id >= 0) {
        void* actor = fn_801F666C(fn_801F856C(), id);
        if (actor != 0) {
            result = fn_801DC264(actor);
        }
    }
    return result;
}

extern "C" void fn_801DAD88(void* record) {
    s32 id = *(s32*)record;
    if (id >= 0) {
        void* base = fn_801F856C();
        void* found = fn_801F666C(base, id);
        if (found != 0) {
            fn_801D8400(found);
        }
    }
}

extern "C" void fn_801DADD0(void* record) {
    s32 id = *(s32*)record;
    if (id >= 0) {
        void* base = fn_801F856C();
        void* found = fn_801F666C(base, id);
        if (found != 0) {
            fn_801F0E34(found, 0x40005, 0);
        }
    }
}

typedef void (*VFn)(void*);

extern "C" void fn_801DAE24(const LinkMgr* mgr) {
    s32 n = mgr->mCount;
    const s32* ids = mgr->mIds;
    for (s32 i = 0; i < n; i++) {
        ItemBase* actor = (ItemBase*)fn_801F666C(fn_801F856C(), ids[i]);
        if (actor != 0) {
            *(s32*)((u8*)actor + 0x10c) = -1;
            actor->v07();
        }
    }
}

extern "C" void fn_801DAEAC(LinkMgr* mgr, s32 id) {
    u8 found = 0;
    s32* ids = mgr->mIds;
    if (mgr->mCount <= 0) {
        return;
    }
    for (s32 i = 0; i < mgr->mCount; i++, ids++) {
        if (!found) {
            if (id == *ids) {
                found = 1;
            }
        } else {
            ids[-1] = *ids;
        }
    }
    if (found) {
        mgr->mCount--;
    }
}

extern "C" void fn_801DAF14(LinkMgr* mgr, s32 id) {
    if (mgr->mCount < 30) {
        mgr->mIds[mgr->mCount] = id;
        mgr->mCount++;
    }
}

extern "C" void fn_801DAF3C(LinkMgr* mgr, s32 id) { mgr->mId1 = id; }
extern "C" void fn_801DAF44(LinkMgr* mgr, s32 id) { mgr->mId0 = id; }

extern "C" void fn_801DAF4C(LinkMgr* mgr) {
    mgr->mId0 = -1;
    mgr->mId1 = -1;
    mgr->mCount = 0;
    mgr->m84 = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
