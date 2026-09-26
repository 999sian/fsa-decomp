// PUKU actor. TU 8017B140-8017C01C.
// Functions: dtor, draw (slot 6, TODO), update (slot 3, TODO), tile check, init (slot 1).
#include "types.h"
#include "Game/ItemBase.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" u16 fn_8022461C(void* pos);
extern void* lbl_804A11B8[];

struct PukuRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
};
struct PukuGame { u8 pad[0xb4]; PukuRandom rnd; };
extern PukuGame* lbl_8053AAF8;

// PUKU destructor
extern "C" void* fn_8017B140(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A11B8;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

struct PukuResMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* get(u32 type, const char* name);
};
struct PukuGameRes { u8 pad[0xa4]; PukuResMgr* res; };
extern "C" void fn_802F86CC(void* layer, void* pos, void* res, s32 id, f32 sx, f32 sy, DrawRec* rec);
extern "C" void fn_803075AC(void* a, s32 room, void* pos, s32 id, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
extern u8* lbl_8053AB10;
extern const char lbl_804668A8[];

// PUKU draw (vtable slot 6)
extern "C" void fn_8017B1A0(char* this_) {
    DrawRec rec;
    f32 mtx[3][4];
    s32 scaled = 0;
    mtx[0][3] = 0.0f;
    mtx[1][3] = 0.0f;
    mtx[2][3] = 0.0f;
    if (*(s32*)(this_ + 0x258) == 1) {
        scaled = 1;
        mtx[0][0] = 2.0f;
        mtx[0][1] = 0.0f;
        mtx[0][2] = 0.0f;
        mtx[1][0] = 0.0f;
        mtx[1][1] = 2.0f;
        mtx[1][2] = 0.0f;
        mtx[2][0] = 0.0f;
        mtx[2][1] = 0.0f;
        mtx[2][2] = 2.0f;
        rec.w18 = mtx;
    }
    s32 id = *(s32*)(this_ + 0x250) + 0x143;
    if (*(s32*)(this_ + 4) < 8) {
        void* res = ((PukuGameRes*)lbl_8053AAF8)->res->get('SOB ', lbl_804668A8);
        fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), this_ + 0xc, res, id, 1.0f, 1.0f, &rec);
    }
    fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xc,
                *(s32*)(this_ + 0x250) + 0x143, scaled != 0, 2, -1, 0, 0, 0);
}

// PUKU: can it move onto the tile at pos? (tile types 0x3b, 0, 2, 3 block)
extern "C" BOOL fn_8017BBA8(void* this_, void* arg1, void* pos) {
    s32 t = (u16)fn_8022461C(pos);
    BOOL ret;
    if (t != 0x3b && t != 0 && t != 2 && t != 3) {
        ret = TRUE;
    } else {
        ret = FALSE;
    }
    return ret;
}

// PUKU init (vtable slot 1)
static inline f32 puku_zero() { return 0.0f; }
extern "C" void fn_8017BBFC(char* this_) {
    *(f32*)(this_ + 0x60) = -8.0f;
    *(f32*)(this_ + 0x64) = -8.0f;
    *(f32*)(this_ + 0x68) = 8.0f;
    *(f32*)(this_ + 0x6c) = 8.0f;
    *(f32*)(this_ + 0x80) = -8.0f;
    *(f32*)(this_ + 0x84) = -8.0f;
    *(f32*)(this_ + 0x88) = 8.0f;
    *(f32*)(this_ + 0x8c) = 8.0f;
    *(u32*)(this_ + 0x258) = *(u32*)(this_ + 0x90) & 1;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x254) = 0;
    *(s16*)(this_ + 0x25c) = 0;
    *(f32*)(this_ + 0x260) = 8.0f * (f32)((*(u32*)(this_ + 0x90) >> 8) & 0xff);
    *(f32*)(this_ + 0x26c) = 0.0f;
    *(f32*)(this_ + 0x268) = 0.0f;
    *(f32*)(this_ + 0x264) = 0.0f;
    *(f32*)(this_ + 0x44) = 0.0f;
    *(f32*)(this_ + 0x40) = 0.0f;
    *(f32*)(this_ + 0x3c) = 0.0f;
    *(f32*)(this_ + 0x270) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x274) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x278) = *(f32*)(this_ + 0x14);
    *(s32*)(this_ + 0x98) = (s32)(1.99f * lbl_8053AAF8->rnd.get_ufloat_1());
    if (*(s32*)(this_ + 0x258) == 1) {
        PukuGame* g = lbl_8053AAF8;
        *(s32*)(this_ + 0x254) = (s32)(1.99f * g->rnd.get_ufloat_1());
        *(s32*)(this_ + 0x114) = 4;
        *(f32*)(this_ + 0x60) = -16.0f;
        *(f32*)(this_ + 0x64) = -16.0f;
        *(f32*)(this_ + 0x68) = 16.0f;
        *(f32*)(this_ + 0x6c) = 16.0f;
        *(f32*)(this_ + 0x80) = -16.0f;
        *(f32*)(this_ + 0x84) = -10.0f;
        *(f32*)(this_ + 0x88) = 16.0f;
        *(f32*)(this_ + 0x8c) = 10.0f;
    }
    *(s32*)(this_ + 0x230) = 0;
    if ((*(u32*)(this_ + 0x90) >> 4) & 0xff) {
        if (*(f32*)(this_ + 0x260) == puku_zero()) {
            *(f32*)(this_ + 0x260) = 16.0f;
        }
        *(u32*)(this_ + 0x98) = (*(u32*)(this_ + 0x90) >> 4) & 0xf;
        *(s32*)(this_ + 0x98) = *(s32*)(this_ + 0x98) - 1;
        *(u32*)(this_ + 0x98) = *(u32*)(this_ + 0x98) & 3;
        *(s32*)(this_ + 0x230) = 4;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
