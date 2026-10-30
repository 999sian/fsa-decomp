// TU 0x8038f9f4-0x8039003c — Actor 'KNBN' (Kanban / Signboard Interaction Actor).
#include "types.h"
#include "JSystem/JGeometry/Box.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AF428[];

struct KnbnMgr { u8 flag(u32 i) { return mFlags[i]; } u8 pad[0x131df]; u8 mFlags[1]; };
struct KnbnBox { f32 x0, y0, x1, y1; };

struct KnbnActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ JGeometry::TVec2<f32> mPosXY;
    /* 0x014 */ f32 mPosZ;
    /* 0x018 */ u8 _pad18[0x3C - 0x18];
    /* 0x03C */ f32 mVel[3];
    /* 0x048 */ u8 _pad48[0x60 - 0x48];
    /* 0x060 */ KnbnBox mBounds60;
    /* 0x070 */ u8 _pad70[0x90 - 0x70];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[0x11C - 0x94];
    /* 0x11C */ u8 mActiveFlag;
    /* 0x11D */ u8 _pad11D[0x198 - 0x11D];
    /* 0x198 */ u32 mRoomHandle;
    /* 0x19C */ u8 _pad19C[0x230 - 0x19C];
    /* 0x230 */ s32 mState;         // 0 = idle, 1 = reading sign
    /* 0x234 */ s32 mReaderPlayer;  // Player index reading sign (-1 = none)
};

extern "C" void* fn_8038F9F4(KnbnActor* this_, s16 freeFlag) {
    if (this_ != 0) {
        this_->mVtable = lbl_804AF428;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" {
void fn_8038FA54(void) {}
}

extern "C" u16 fn_80226850(void* pos, u32 id);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_8022FEB8(JGeometry::TBox2<f32>* box, u32 id, u32 p3, int p4, int p5);
extern "C" s32 fn_8022FD8C(u32 p);
extern "C" Vec* fn_8023E724(s32 obj);
extern "C" u8 fn_8038C678(s32 obj, u32 p2, u32 p3, u32 p4, JGeometry::TVec3<f32>* pos, u32 p6);
extern "C" s32 fn_80230CFC(s32 obj);
extern "C" u8 fn_80388CAC(s32 obj, u32 p);
extern "C" u8 fn_80138AB0(void);
extern u8* lbl_8053AAF8;

// KNBN update (vtable slot 3)
extern "C" void fn_8038FA58(KnbnActor* p) {
    u32 flag;
    u32 a, b;
    u32 id;
    int kind = fn_80226850(&p->mPosXY, p->mRoomId);
    if (kind == 0x1c7) {
        p->mBounds60.x0 = 0.0f;
        p->mBounds60.y0 = 0.0f;
        p->mBounds60.x1 = 32.0f;
        p->mBounds60.y1 = 32.0f;
    }
    JGeometry::TBox2<f32> box(2.0f + p->mBounds60.x0, p->mBounds60.y0, p->mBounds60.x1 - 2.0f, p->mBounds60.y1 - 2.0f);
    box.addPos(p->mPosXY);

    switch (p->mState) {
    case 0:
        if (kind == 0x71 || kind == 0x3c || kind == 0x1c7) {
            id = p->mRoomId;
            if (((KnbnMgr*)fn_802D6A9C())->flag(id) != 0) {
                fn_8022FEB8(&box, p->mRoomId, p->mRoomHandle, 1, 0);
            } else {
                fn_8022FEB8(&box, p->mRoomId, p->mRoomHandle, 1, 1);
            }
            p->mReaderPlayer = fn_8022FD8C(p->mRoomHandle);
            flag = (kind == 0x71) ? 0x200 : 0x400;
            u32 id2 = p->mRoomId;
            if (((KnbnMgr*)fn_802D6A9C())->flag(id2) != 0) {
                if (p->mReaderPlayer >= 0) {
                    a = p->mRoomHandle;
                    b = p->mRoomId;
                    JGeometry::TVec3<f32> pos(*fn_8023E724(p->mReaderPlayer));
                    if (fn_8038C678(p->mReaderPlayer, (p->mSpawnParam & 0xFFFF) + 0x12b, a, b, &pos, flag)) {
                        p->mState = 1;
                    }
                }
            } else {
                if (p->mReaderPlayer >= 0 && fn_80230CFC(p->mReaderPlayer) == 3
                    && p->mPosXY.y <= fn_8023E724(p->mReaderPlayer)->y) {
                    u32 a = p->mRoomHandle;
                    u32 b = p->mRoomId;
                    JGeometry::TVec3<f32> pos(*fn_8023E724(p->mReaderPlayer));
                    if (fn_8038C678(p->mReaderPlayer, (p->mSpawnParam & 0xFFFF) + 0x12b, a, b, &pos, flag)) {
                        p->mState = 1;
                    }
                }
            }
        } else {
            p->mActiveFlag = 0;
        }
        break;
    case 1:
        fn_8022FEB8(&box, p->mRoomId, p->mRoomHandle, 1, 0);
        if (fn_80388CAC(p->mReaderPlayer, p->mRoomHandle)) {
            p->mState = 0;
        }
        break;
    }
}

static inline void knbnKill(KnbnActor* p) { p->mActiveFlag = 0; }

// KNBN init (vtable slot 1)
extern "C" void fn_8038FD08(KnbnActor* p) {
    p->mBounds60.x0 = 0.0f;
    p->mBounds60.y0 = 0.0f;
    p->mBounds60.x1 = 16.0f;
    p->mBounds60.y1 = 16.0f;
    p->mVel[0] = 0.0f;
    p->mVel[1] = 0.0f;
    p->mVel[2] = 0.0f;
    p->mState = 0;
    p->mReaderPlayer = -1;
    if (lbl_8053AAF8[0x7e] == 1) {
        if (p->mSpawnParam & 0x80000000) {
            knbnKill(p);
        } else if (fn_80138AB0() == 1 && (p->mSpawnParam & 0x20000000)) {
            knbnKill(p);
        } else if (p->mSpawnParam & 0x10000000) {
            knbnKill(p);
        }
    } else {
        if (p->mSpawnParam & 0x40000000) {
            knbnKill(p);
        } else if (fn_80138AB0() == 1 && (p->mSpawnParam & 0x20000000)) {
            knbnKill(p);
        } else if (p->mSpawnParam & 0x10000000) {
            knbnKill(p);
        }
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
