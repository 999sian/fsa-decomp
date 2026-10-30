// Game TU 801B4D0C-801B6634 (TLWP). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JGeometry/Box.h"
#include "JSystem/JMath/JMath.h"

extern "C" void* fn_8013C824(void);
extern "C" void fn_800EC240(void* a, void* b);
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A38D4[];

extern "C" void* fn_801B609C(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804A38D4;
        char* p = (char*)this_;
        int i = 0;
        do {
            if (*(void**)(p + 0x294)) {
                void* base = fn_8013C824();
                void* a = *(void**)((char*)base + 0xc);
                fn_800EC240(a, *(void**)(p + 0x294));
                *(void**)(p + 0x294) = 0;
            }
            i++;
            p += 4;
        } while (i < 3);
        p = (char*)this_;
        int j = 0;
        do {
            if (*(void**)(p + 0x2a0)) {
                void* base = fn_8013C824();
                void* a = *(void**)((char*)base + 0xc);
                fn_800EC240(a, *(void**)(p + 0x2a0));
                *(void**)(p + 0x2a0) = 0;
            }
            j++;
            p += 4;
        } while (j < 0x14);
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

#include "Game/TlwpDrawParam.h"
struct TlwpSave { u8 pad[0x10]; s32 cur; u8 pad2[0x7a - 0x14]; u8 mask; };
extern TlwpSave lbl_8050EC80;
extern const char lbl_804690F8[];
extern const f32 lbl_8053EA10;
extern "C" void fn_801F02BC(void* this_, const char* name, s32 id, TlwpDrawParam* param, s32 a, s32 b, s32 c, f32 s0, f32 s1);
extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, TlwpDrawParam* param, s32 a, f32 s0, f32 s1);
extern "C" void fn_801B4EC8(char* p);
extern "C" void fn_801B56A0(char* p);
extern "C" void fn_801B5228(char* p);

extern "C" void fn_801B4D0C(char* p) {
    switch (*(s32*)(p + 0x250)) {
    case 0: {
        u8 m = 1 << *(s32*)(p + 0x254);
        if (((TlwpSave*)((u8*)&lbl_8050EC80 + lbl_8050EC80.cur * 0xc8))->mask & m) {
            TlwpDrawParam param;
            *(s8*)&param.color = -1;
            fn_801F06F0(p, lbl_804690F8, 0x431, &param, -1, lbl_8053EA10, lbl_8053EA10);
            fn_801F02BC(p, lbl_804690F8, 0x431, &param, -1, 0, 0, lbl_8053EA10, lbl_8053EA10);
        }
        break;
    }
    case 1:
    case 2:
    case 3:
        fn_801B4EC8(p);
        break;
    }
}

extern "C" void fn_801B5198(char* p) {
    switch (*(s32*)(p + 0x250)) {
    case 0:
        fn_801B56A0(p);
        break;
    case 1:
    case 2:
    case 3:
        fn_801B5228(p);
        break;
    }
    for (s32 i = 0; i < 3; i++) {
        if (*(s32*)(p + i * 4 + 0x234) > 0) {
            (*(s32*)(p + i * 4 + 0x234))--;
        }
    }
}

struct TlwpVec { f32 x, y, z; };
struct TlwpRect { f32 x0, y0, x1, y1; };
extern const f32 lbl_8053EA7C;
extern const f32 lbl_8053EA80;
extern const f32 lbl_8053EA84;
extern const f32 lbl_8053EA3C;
extern const f32 lbl_8053EA88;
extern const f32 lbl_8053EA8C;
extern const f32 lbl_8053EA90;
extern const f32 lbl_8053EA18;
extern const f32 lbl_8053EA58;
extern u8 lbl_8053ABF8;
extern s32 lbl_8053A118;
struct TlwpData {
    u16 ids[20];      // 0x00
    s32 unk_0x28[8];
    s32 unk_0x48[8];
    s32 unk_0x68[8];
    s32 model[3][4];  // 0x88
    s32 timer[3][4];  // 0xb8
    s32 kind[3];      // 0xe8
};
extern TlwpData lbl_804A37E0;
extern "C" char* fn_802D6A9C(void);
extern "C" s32 fn_8013CC50(s32 room, TlwpVec* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);

static inline void tlwpSet(TlwpVec* v, f32 x, f32 y, f32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline void tlwpLerp(TlwpVec* v, const TlwpRect* r, f32 t, f32 z) {
    tlwpSet(v, r->x0 + t * (r->x1 - r->x0), r->y0 + t * (r->y1 - r->y0), z);
}

extern "C" void fn_801B6170(char* p) {
    *(f32*)(p + 0x60) = lbl_8053EA7C;
    *(f32*)(p + 0x64) = lbl_8053EA7C;
    *(f32*)(p + 0x68) = lbl_8053EA80;
    *(f32*)(p + 0x6c) = lbl_8053EA80;
    *(f32*)(p + 0x80) = lbl_8053EA84;
    *(f32*)(p + 0x84) = lbl_8053EA84;
    *(f32*)(p + 0x88) = lbl_8053EA3C;
    *(f32*)(p + 0x8c) = lbl_8053EA3C;
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x23c) = 0;
    *(s32*)(p + 0x294) = 0;
    *(s32*)(p + 0x298) = 0;
    *(s32*)(p + 0x29c) = 0;
    *(s32*)(p + 0x2a0) = 0;
    *(s32*)(p + 0x2a4) = 0;
    *(s32*)(p + 0x2a8) = 0;
    *(s32*)(p + 0x2ac) = 0;
    *(s32*)(p + 0x2b0) = 0;
    *(s32*)(p + 0x2b4) = 0;
    *(s32*)(p + 0x2b8) = 0;
    *(s32*)(p + 0x2bc) = 0;
    *(s32*)(p + 0x2c0) = 0;
    *(s32*)(p + 0x2c4) = 0;
    *(s32*)(p + 0x2c8) = 0;
    *(s32*)(p + 0x2cc) = 0;
    *(s32*)(p + 0x2d0) = 0;
    *(s32*)(p + 0x2d4) = 0;
    *(s32*)(p + 0x2d8) = 0;
    *(s32*)(p + 0x2dc) = 0;
    *(s32*)(p + 0x2e0) = 0;
    *(s32*)(p + 0x2e4) = 0;
    *(s32*)(p + 0x2e8) = 0;
    *(s32*)(p + 0x2ec) = 0;
    lbl_8053ABF8 = 0;
    *(f32*)(p + 0x25c) = lbl_8053EA10;
    *(s32*)(p + 0x250) = (*(u32*)(p + 0x90) >> 4) & 0xf;
    *(s32*)(p + 0x254) = *(u32*)(p + 0x90) & 0xf;
    if (*(s32*)(p + 0x250) == 0 && *(s32*)(p + 0x254) == 0) {
        char* cfg = fn_802D6A9C();
        TlwpRect r = *(TlwpRect*)(cfg + 0xcc);
        TlwpVec v;
        TlwpVec* pos = (TlwpVec*)(p + 0xc);
        v.x = pos->x;
        v.y = pos->y;
        tlwpLerp(&v, &r, lbl_8053EA88, pos->z);
        tlwpSet(&v, pos->x, pos->y, pos->z);
        v.x += lbl_8053EA8C;
        v.y += lbl_8053EA90;
        for (s32 i = 0; i < 20; i++) {
            *(s32*)(p + i * 4 + 0x2a0) = fn_8013CC50(*(s32*)(p + 0x4), &v, lbl_804A37E0.ids[i], 0, 0, 0, 0, 1, lbl_8053EA10);
        }
    }
    *(s32*)(p + 0x24c) = 0;
    *(TlwpVec*)(p + 0x264) = *(TlwpVec*)(p + 0xc);
    *(TlwpVec*)(p + 0x270) = *(TlwpVec*)(p + 0xc);
    *(TlwpVec*)(p + 0x27c) = *(TlwpVec*)(p + 0xc);
    *(TlwpVec*)(p + 0x288) = *(TlwpVec*)(p + 0xc);
    *(f32*)(p + 0x258) = lbl_8053EA18;
    *(u16*)(p + 0x260) = 0;
    if (*(s32*)(p + 0x250) == 0) {
        lbl_8053A118 = 3;
        *(s32*)(p + 0x230) = 0;
    } else {
        *(f32*)(p + 0x14) = lbl_8053EA58;
        *(s32*)(p + 0x230) = 8;
    }
}

extern "C" double sin(double);
extern "C" double cos(double);
extern const char lbl_8046910C[];
extern const f32 lbl_8053EA14;



extern "C" void fn_801B4EC8(char* p) {
    TlwpDrawParam param;
    f32 m[3][4];
    switch (*(s32*)(p + 0x250)) {
    case 2:
        param.color = 1;
        param.map[2] = 9;
        break;
    case 1:
        param.color = 1;
        param.map[2] = 3;
        break;
    case 3:
        param.color = 1;
        param.map[2] = 4;
        break;
    }
    tlwpRotMtx(m, lbl_8053EA18, (f32)*(u16*)(p + 0x260) / lbl_8053EA14, lbl_8053EA18, lbl_8053EA10);
    param.c = m;
    fn_801F06F0(p, lbl_8046910C, *(s32*)(p + 0x24c) + 0xc0, &param, 7, lbl_8053EA10, lbl_8053EA10);
}

#include <std/math.h>
extern const f32 lbl_8053EA28;
extern const f32 lbl_8053EA2C;
extern const f32 lbl_8053EA30;
extern const f32 lbl_8053EA34;
extern const f32 lbl_8053EA38;
extern const f32 lbl_8053EA5C;
extern const f32 lbl_8053EA60;
extern "C" void fn_801F71A4(f32* v, f32 target, f32 a, f32 b);
extern "C" u8 fn_8023F264(s32 id);
extern "C" s32 fn_8023DE58(s32 id);
extern "C" TlwpVec* fn_8023E724(s32 id);
extern "C" void fn_80230498(s32 player, TlwpVec* pos, s32 id, s32 a, s32 b, s32 c, s32 d);
extern "C" void fn_801F0E34(void* target, u32 effectId, s32 flag);

extern "C" void fn_801B5228(char* p) {
    char* q9;
    char* q10;
    char* q;
    s32 room;
    TlwpData* d = &lbl_804A37E0;
    fn_801F71A4((f32*)(p + 0x14), *(f32*)(p + 0x258), lbl_8053EA28, *(f32*)(p + 0x25c));
    switch (*(s32*)(p + 0x230)) {
    case 8: {
        s32* kinds = d->kind;
        u32 offset = *(s32*)(p + 0x250) * 4;
        kinds = (s32*)((u8*)kinds + offset);
        *(s32*)(p + 0x98) = kinds[-1];
        q = p;
        for (s32 i = 0; i < 4; i++) {
            if (fn_8023F264(i)) {
                room = *(s32*)(p + 0x4);
                if (room == fn_8023DE58(i)) {
                    *(TlwpVec*)(q + 0x264) = *fn_8023E724(i);
                    if (i == 0) {
                        *(f32*)(q + 0x268) += lbl_8053EA2C;
                    }
                }
            }
            q += 0xc;
        }
        *(f32*)(p + 0x25c) = lbl_8053EA30;
        *(s32*)(p + 0x230) = 9;
    }
    case 9: {
        TlwpVec* pos = fn_8023E724(0);
        f32 x = pos->x;
        f32 y = pos->y;
        *(f32*)(p + 0x258) = lbl_8053EA34;
        if (*(s32*)(p + 0x250) == 1) {
            *(u16*)(p + 0x260) = 3000;
            x -= lbl_8053EA38;
            *(f32*)(p + 0x258) = lbl_8053EA3C;
        }
        if (*(s32*)(p + 0x250) == 3) {
            *(u16*)(p + 0x260) = 0x10000 - 3000;
            x += lbl_8053EA38;
            *(f32*)(p + 0x258) = lbl_8053EA3C;
        }
        fn_801F71A4((f32*)(p + 0xc), x, lbl_8053EA28, *(f32*)(p + 0x25c));
        *(f32*)(p + 0x10) = y;
        f32 dx = fabs(*(f32*)(p + 0xc) - x);
        f32 dz = fabs(*(f32*)(p + 0x14) - *(f32*)(p + 0x258));
        if (std::sqrtf(dx * dx + dz * dz) < lbl_8053EA10) {
            if (--lbl_8053A118 == 0) {
                s32 i = 0;
                q9 = p;
                for (; i < 4; i++, q9 += 0xc) {
                    if (fn_8023F264(i)) {
                        room = *(s32*)(p + 0x4);
                        if (room == fn_8023DE58(i)) {
                            fn_80230498(i, (TlwpVec*)(q9 + 0x264), 0x3e, 0xff, -0x80, -0x80, 1);
                        }
                    }
                }
                fn_801F0E34(p, 0x50052, 0);
            }
            *(s32*)(p + 0x230) = 10;
        }
        break;
    }
    case 10:
        if (lbl_8053A118 <= 0) {
            if (lbl_8053EA58 != *(f32*)(p + 0x258)) {
                *(f32*)(p + 0x258) = lbl_8053EA58;
                *(f32*)(p + 0x25c) = lbl_8053EA5C;
            } else if (*(s32*)(p + 0x250) == 2) {
                f32 z = *(f32*)(p + 0x14);
                q10 = p;
                for (s32 i = 0; i < 4; i++, q10 += 0xc) {
                    if (fn_8023F264(i)) {
                        room = *(s32*)(p + 0x4);
                        if (room == fn_8023DE58(i)) {
                        fn_801F71A4((f32*)(q10 + 0x26c), z, lbl_8053EA28, *(f32*)(p + 0x25c));
                        fn_80230498(i, (TlwpVec*)(q10 + 0x264), 0xb0, 0xff, -0x80, -0x80, 1);
                        }
                    }
                }
                if ((f32)fabs(*(f32*)(p + 0x14) - *(f32*)(p + 0x258)) < lbl_8053EA60) {
                    lbl_8053A118 = 0x309;
                }
            }
        }
        break;
    }
    if (*(s32*)(p + 0x234) == 0) {
        s32 index;
        s32* model;
        s32* timer;
        s32 frame;
        u32 offset;
        index = *(s32*)(p + 0x98);
        frame = *(s32*)(p + 0x240);
        model = (s32*)d->model;
        timer = (s32*)d->timer;
        index *= 4;
        offset = index + frame;
        offset *= 4;
        model = (s32*)((u8*)model + offset);
        *(s32*)(p + 0x24c) = *model;
        index = *(s32*)(p + 0x98);
        frame = *(s32*)(p + 0x240);
        index *= 4;
        offset = index + frame;
        offset *= 4;
        timer = (s32*)((u8*)timer + offset);
        *(s32*)(p + 0x234) = *timer;
        (*(s32*)(p + 0x240))++;
        *(s32*)(p + 0x240) &= 3;
    }
}


extern "C" {
extern char* lbl_8053AAF8;
extern void* lbl_8053AD30;
extern u8 lbl_80529DEC[];
void* fn_80309C4C(void*, s32, s32);
void fn_801EEC98(void*, s32, void*, void*, void*, void*, s32, s32);
void fn_8022FEB8(void*, s32, s32, s32, s32);
s32 fn_8022FD8C(s32);
u8 fn_802300EC(s32);
u8 fn_8038AD24(s32, s32, s32, s32, JGeometry::TVec3f, s32);
void fn_8022FE80(s32, s32, s32, s32, s32);
u8 fn_803865B8(s32);
void fn_80384C58(s32, s32);
s32 fn_8037EFB4(s32);
void fn_80230534(s32);
s32 fn_80138A30(void*);
void* fn_801F856C();
s32 fn_801F68E0(void*);
s32 fn_8022F3DC(s32);
void fn_8022CA6C(s32, s32, s32);
u8 fn_80236B50(s32);
void fn_8023764C(s32, s32);
s32 ClassifyBamAngleToQuadrant(u16);
void fn_80230BF4(s32, s32);
void fn_802303FC(s32, void*, s32);
void* Actor_CreateByID(void*, u32, s32, void*, u32, s32, s32);
void fn_801365E8(void*, s32, s32, s32);
}
extern const f32 lbl_8053EA64, lbl_8053EA68, lbl_8053EA6C, lbl_8053EA70, lbl_8053EA74, lbl_8053EA78;



static inline u16 tlwpAngle(f32 dx, f32 dy) {
    f32 angle = JMath::atanTable_.atan2_(-dx, -dy);
    angle *= lbl_8053EA70;
    return (s32)angle;
}

static inline u8 tlwpReady() {
    if ((u8)lbl_8053AAF8[0x7e] != 0) return 1;
    return 0;
}
static inline void tlwpArrival(bool arrived) {}

static inline u8 tlwpSendPosition(char* p, const s32* table, const JGeometry::TVec3f& pos) {
    s32 handle=*(s32*)(p+0x198);
    s32 room=*(s32*)(p+4);
    return fn_8038AD24(*(s32*)(p+0x244), table[*(s32*)(p+0x254)], handle, room, pos, 0x100);
}


#pragma opt_common_subs off
#pragma opt_propagation on
#pragma opt_dead_assignments off
#pragma opt_dead_code off
extern "C" void fn_801B56A0(char* p) {
    TlwpVec target;
    JGeometry::TBox2f box;
    JGeometry::TVec3f pos;
    s32 collisionFlags;
    s32 extra;
    f32 collisionFloat;
    TlwpData* d = &lbl_804A37E0;
    TlwpSave* save = (TlwpSave*)((u8*)&lbl_8050EC80 + lbl_8050EC80.cur * 0xc8);
    box.i.x=*(f32*)(p+0x60); box.i.y=*(f32*)(p+0x64); box.f.x=*(f32*)(p+0x68); box.f.y=*(f32*)(p+0x6c);
    pos = *(JGeometry::TVec3f*)(p+0xc);
    box.addPos(*(JGeometry::TVec2f*)(p+0xc));
    u8 mask = 1 << *(s32*)(p+0x254);
    if (!(mask & save->mask)) return;
    if ((u8)lbl_8053AAF8[0x7e] != 0) {
    } else return;
    if (*(s32*)(p+0x230)==5 || *(s32*)(p+0x230)==6 || *(s32*)(p+0x230)==7) {
        if (fn_80309C4C(lbl_8053AD30, 0x1000, -1)) {
            lbl_8053A118=0x309;
            *(s32*)(p+0x230)=7;
        }
    }
    fn_801EEC98(p, *(s32*)(p+0x198), 0, &collisionFlags, &collisionFloat, &extra, 0, 0);
    switch (*(s32*)(p+0x230)) {
    case 0:
        *(s32*)(p+0x294)=fn_8013CC50(*(s32*)(p+4),(TlwpVec*)(p+0xc),0x48b,0,0,0,0,1,lbl_8053EA10);
        *(s32*)(p+0x298)=fn_8013CC50(*(s32*)(p+4),(TlwpVec*)(p+0xc),0x48c,0,0,0,0,1,lbl_8053EA10);
        *(s32*)(p+0x230)=1;
    case 1:
        fn_8022FEB8(&box,*(s32*)(p+4),*(s32*)(p+0x198),0,0);
        *(s32*)(p+0x244)=fn_8022FD8C(*(s32*)(p+0x198));
        if (*(s32*)(p+0x244)<0) break;
        if (!fn_802300EC(*(s32*)(p+0x244))) break;
        pos.y -= lbl_8053EA64;
        if (!tlwpSendPosition(p,d->unk_0x68,pos)) break;
        *(s32*)(p+0x230)=2;
    case 2:
        fn_8022FE80(*(s32*)(p+0x244),*(s32*)(p+4),*(s32*)(p+0x198),0,0);
        if (fn_803865B8(*(s32*)(p+0x244))) {
            fn_80384C58(*(s32*)(p+0x244),*(s32*)(p+0x198));
            switch (fn_8037EFB4(*(s32*)(p+0x244))) {
            case 0: *(s32*)(p+0x230)=4; break;
            case 1: fn_80230534(0); *(s32*)(p+0x230)=3; break;
            }
        }
        break;
    case 3: {
        s32 i=0;
        s32 count=0;
        for (; i<fn_80138A30(lbl_8053AAF8); i++) {
            f32 dx=fn_8023E724(i)->x-*(f32*)(p+0xc);
            f32 dy=fn_8023E724(i)->y-*(f32*)(p+0x10);
            f32 dist=dx*dx+dy*dy;
            if (dist>0.0f) {
f64 g=__frsqrte(dist);
g=0.5*g*(3.0-g*g*dist);
g=0.5*g*(3.0-g*g*dist);
g=0.5*g*(3.0-g*g*dist);
dist=dist*g;
} else if (dist<0.0) { dist=NAN; }
else if (isnan(dist)) { dist=NAN; }
            if(dist>lbl_8053EA68) count++;
        }
        if(count>=fn_80138A30(lbl_8053AAF8)) *(s32*)(p+0x230)=1;
        break;
    }
    case 4: {
        s32 room;
        char* q;
        s32 i;
        if (!fn_801F68E0(fn_801F856C())) break;
        i=0;
        q=p;
        for(;i<4;i++,q+=0xc) {
            if(fn_8023F264(i)) {
                room=*(s32*)(p+4);
                if(room==fn_8023DE58(i)) {
                    TlwpVec* v=fn_8023E724(i);
                    *(f32*)(q+0x264)=v->x;
                    *(f32*)(q+0x268)=v->y;
                    *(f32*)(q+0x26c)=v->z;
                    *(f32*)(q+0x26c)=lbl_8053EA18;
                    if(fn_8022F3DC(i)<0) fn_8022CA6C(i,5,0);
                    if(fn_80236B50(i)) fn_8023764C(i,1);
                }
            }
        }
        lbl_80529DEC[0x24e]=1;
        *(s32*)(p+0x230)=5;
    }
    case 5: {
        char* q;
        int i;
        s32 count;
        target.x=*(f32*)(p+0xc); target.y=*(f32*)(p+0x10); target.z=*(f32*)(p+0x14);
        q=p;
        count=0;
        i=count;
        for(;i<4;i++,q+=0xc) {
            if(fn_8023F264(i)) {
                if(i!=0) target.y-=lbl_8053EA6C;
                fn_801F71A4((f32*)(q+0x264),target.x,lbl_8053EA28,lbl_8053EA10);
                fn_801F71A4((f32*)(q+0x268),target.y,lbl_8053EA28,lbl_8053EA10);
                f32 dist;
                f32 dx;
                f32 dy;
                dy=*(f32*)(q+0x268)-target.y;
                dx=*(f32*)(q+0x264)-target.x;
                dist=dx*dx+dy*dy;
                if (dist>0.0f) {
f64 g=__frsqrte(dist);
g=0.5*g*(3.0-g*g*dist);
g=0.5*g*(3.0-g*g*dist);
g=0.5*g*(3.0-g*g*dist);
dist=dist*g;
} else if (dist<0.0) { dist=NAN; }
else if (isnan(dist)) { dist=NAN; }
                if(dist<lbl_8053EA10) {
                    count++;
                    fn_80230498(i,(TlwpVec*)(q+0x264),0x3f,0xff,-0x80,-0x80,1);
                } else {
                    u16 angle=tlwpAngle(dx,dy);
                    fn_80230BF4(i,ClassifyBamAngleToQuadrant(angle));
                    fn_802303FC(i,q+0x264,0xff);
                }
            } else count++;
        }
        if(count>=4) *(s32*)(p+0x230)=6;
        break;
    }
    case 6: {
        s32 room;
        char* q;
        s32 i;
        if(*(s32*)(p+0x234)!=0) break;
        target.x=*(f32*)(p+0xc); target.y=*(f32*)(p+0x10); target.z=*(f32*)(p+0x14);
        q=p;
        for(s32 i=0;i<4;i++,q+=0xc) {
            if(fn_8023F264(i)) {
                room=*(s32*)(p+4);
                if(room==fn_8023DE58(i)) {
                    if(i!=0) target.y-=lbl_8053EA6C;
                    fn_801F71A4((f32*)(q+0x264),target.x,lbl_8053EA28,lbl_8053EA10);
                    fn_801F71A4((f32*)(q+0x268),target.y,lbl_8053EA28,lbl_8053EA10);
                    f32 dx=(f32)fabs(*(f32*)(q+0x264)-target.x);
                    f32 dy=(f32)fabs(*(f32*)(q+0x268)-target.y);
                    f32 dist=dx*dx+dy*dy;
                    if (dist>0.0f) {
f64 g=__frsqrte(dist);
g=0.5*g*(3.0-g*g*dist);
g=0.5*g*(3.0-g*g*dist);
g=0.5*g*(3.0-g*g*dist);
dist=dist*g;
} else if (dist<0.0) { dist=NAN; }
else if (isnan(dist)) { dist=NAN; }
                    s32 arrived=!(dist>=lbl_8053EA60);
                    if(arrived) { }
                    if(*(s32*)(p+0x240)==0) fn_80230498(i,(TlwpVec*)(q+0x264),0x3c,0xff,-0x80,-0x80,1);
                    else fn_80230498(i,(TlwpVec*)(q+0x264),0x3e,0xff,-0x80,-0x80,1);
                }
            }
        }
        *(s32*)(p+0x234)=8;
        ++*(s32*)(p+0x240);
        if(*(s32*)(p+0x240)>1) {
            f32 offset=lbl_8053EA74;
            for(s32 i=0;i<3;i++) {
                target.x=*(f32*)(p+0xc); target.y=*(f32*)(p+0x10); target.z=*(f32*)(p+0x14);
                target.x+=offset;
                offset+=lbl_8053EA78;
                Actor_CreateByID(fn_801F856C(),0x544c5750,*(s32*)(p+4),&target,(i+1)<<4,-1,-1);
            }
            *(s32*)(p+0x230)=7;
        }
        break;
    }
    case 7:
        if(lbl_8053A118==0x309) {
            s32 index=*(s32*)(p+0x254);
            fn_801365E8(lbl_8053AAF8,d->unk_0x28[index],d->unk_0x48[index],0);
        }
        break;
    }
}
#pragma opt_common_subs reset
#pragma opt_propagation reset
#pragma opt_dead_assignments reset
#pragma opt_dead_code reset
#include "JSystem/JAudio/JASFakeMatchFSA.h"
