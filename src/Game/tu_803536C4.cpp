#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "Game/ItemBase.h"
#include "JSystem/JGeometry/Vec.h"

struct FsaResourceManager {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void* getResource(u32 fourccType, const char* fileName); // slot 6 (+0x18)
};

extern "C" void fn_802F86CC(void*, void*, void*, s32, f32, f32, DrawRec*);
struct SpriteTables {
    s32 frames[8];
    s32 bodyFrames[4];
    char resourceName[24];
};
extern "C" s32 lbl_80472240[];
extern f32 lbl_80542710;
extern f32 lbl_80542714;
extern f32 lbl_80542718;
extern f32 lbl_8054271C;
extern u8* lbl_8053AB10;


extern "C" char lbl_804ACC68[];
extern u8* lbl_8053AAF8;
extern const f32 lbl_80542720;
extern const f32 lbl_80542724;
extern const f32 lbl_80542728;
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_803536C4(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804ACC68;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

#pragma opt_propagation off
extern "C" void fn_80353724(u8* p) {
    const SpriteTables* tbl = (SpriteTables*)lbl_80472240;
    JGeometry::TVec3f top = *(Vec*)(p + 0xc);
    DrawRec rec;
    int frame;
    rec.b2d = 1;
    rec.b1c = 2;
    rec.b1d = 1;
    if (*(s32*)(p + 0x24c) < 8) {
        JGeometry::TVec3f pos = *(Vec*)(p + 0xc);
        pos.x -= 8.0f;
        switch (*(s32*)(p + 0x24c)) {
        case 2:
        case 3:
            pos.y += lbl_80542714;
            break;
        case 4:
        case 5:
        case 6:
        case 7:
            pos.y += lbl_80542718;
            break;
        }
        switch (*(s32*)(p + 0x23c)) {
        case 1:
        case 3:
            pos.y += lbl_8054271C;
            break;
        case 2:
            pos.y += lbl_80542710;
            break;
        }
        int index = *(s32*)(p + 0x24c);
        const s32* __restrict frames = tbl->frames;
        frame = *(s32*)(p + 0x244) + frames[index];
        if (*(s32*)(p + 4) < 8) {
            void* res = (*(FsaResourceManager**)(lbl_8053AAF8 + 0xA4))->getResource(0x534F4220, tbl->resourceName);
            fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), &pos, res, frame, lbl_80542720, lbl_80542720, &rec);
        }
    }
    switch (*(s32*)(p + 0x248)) {
    case 0:
        rec.ids[2] = 2;
        break;
    case 1:
        rec.ids[2] = 3;
        break;
    case 2:
        rec.ids[2] = 4;
        break;
    case 3:
        rec.ids[2] = 9;
        break;
    }
    int index = *(s32*)(p + 0x23c);
    const s32* __restrict frames2 = tbl->bodyFrames;
    frame = frames2[index] + 0xc0;
    if (*(s32*)(p + 4) < 8) {
        void* res = (*(FsaResourceManager**)(lbl_8053AAF8 + 0xA4))->getResource(0x534F4220, tbl->resourceName);
        fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), p + 0xc, res, frame, lbl_80542720, lbl_80542720, &rec);
    }
}
#pragma opt_propagation reset
extern "C" void fn_80353A50(u8* p) {
    ((JGeometry::TVec3f*)(p + 0xc))->add(*(JGeometry::TVec3f*)(p + 0x3c));
    if (*(f32*)(p + 0x254) - lbl_80542724 > *(f32*)(p + 0xc)) {
        ((Actor*)p)->detach();
    }
    *(s32*)(p + 0x234) -= 1;
    *(s32*)(p + 0x238) -= 1;
    if (*(s32*)(p + 0x234) <= 0) {
        *(s32*)(p + 0x23c) += 1;
        *(s32*)(p + 0x23c) &= 3;
        *(s32*)(p + 0x234) = 9;
    }
    *(s32*)(p + 0x240) -= 1;
    if (*(s32*)(p + 0x240) <= 0) {
        *(s32*)(p + 0x244) += 1;
        *(s32*)(p + 0x244) &= 3;
        if (*(s32*)(p + 0x244) == 0) {
            u8* rng = lbl_8053AAF8;
            *(u32*)(rng + 0xb4) = *(u32*)(rng + 0xb4) * 0x19660d + 0x3c6ef35f;
            u32 bits = (*(u32*)(rng + 0xb4) >> 9) | 0x3f800000;
            *(s32*)(p + 0x240) = (s32)(lbl_80542728 * (*(f32*)&bits - lbl_80542720)) + 0x3c;
        } else {
            *(s32*)(p + 0x240) = 2;
        }
    }
}

extern "C" void fn_801F0E34(void*, s32, s32);
extern "C" void fn_80353B98(u8* p) {
    *(s32*)(p + 0x23c) = 0;
    *(s32*)(p + 0x234) = 9;
    *(s32*)(p + 0x238) = 300;
    *(u32*)(p + 0x248) = *(u32*)(p + 0x90) & 3;
    *(s32*)(p + 0x240) = 0x3c;
    *(s32*)(p + 0x244) = 0;
    *(u32*)(p + 0x24c) = (*(u32*)(p + 0x90) >> 4) & 0xf;
    *(bool*)(p + 0x250) = ((*(u32*)(p + 0x90) >> 8) & 3) != 0;
    if (*(bool*)(p + 0x250) == 0) {
        fn_801F0E34(p, 0x50050, 0);
    } else {
        fn_801F0E34(p, 0x50055, 0);
    }
    *(s32*)(p + 0x230) = 0;
}
#include "JSystem/JAudio/JASFakeMatchFSA.h"
