#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "Game/SinitPoolChain.h"
#include "Game/ItemBase.h"
#include "JSystem/JGeometry/Vec.h"


extern "C" u8 lbl_804A8F74[];
extern "C" void __dl__FPv(void* p);
extern "C" void __dt__5ActorFv(Actor* self, s16 flag);
extern u8* lbl_8053AAF8;
extern "C" u8 fn_802DEBF8(void);
extern "C" u8 fn_802DEBA0(void);
extern "C" u8 fn_802DE814(void);
extern "C" s32 fn_80237774(s32);
typedef f32 Mtx[3][4];
extern "C" u8* fn_802D6A9C(void);
extern "C" void fn_8022EA0C(s32 i, void* m);
extern "C" Vec* fn_8023E724(s32 i = 0);
extern "C" void* fn_804030C4(u32 tag, const char* name);
extern "C" void fn_802F745C(void* obj, Vec* pos, void* tex, u8* idx);
extern u8* lbl_8053AB10;
extern "C" u8 lbl_80540D88[4];
extern "C" u8 lbl_80540D8C[4];
extern "C" u8 lbl_80540D90[4];
extern "C" const char* lbl_804A8F50[];
extern "C" const char* lbl_804A8F60[];
extern "C" char lbl_8046D8CC[];
extern "C" char lbl_8046D8E0[];
extern "C" f32 lbl_80540D94;
extern "C" f32 lbl_80540D98;
extern "C" f32 lbl_80540D9C;
extern "C" f32 lbl_80540DA0;
extern "C" void fn_802CA284(u8* this_) {
    u8* p;
    s32 i;
    u8* self;

    self = this_;
    p = self;
    for (i = 0; i < 4; i++) {
        if (fn_802D6A9C()[0x131ef] == 0 && *(s32*)(p + 0x27c) != 0) {
            DrawRec rec;
            f32 mtx[3][4];
            u8* tag = (u8*)&rec.w10;
            u32 hit = (lbl_8053AAF8[0x82] & (u8)((u32)1 << i)) != 0;

            if (hit == 1) {
                switch (*(s32*)(p + 0x28c)) {
                case 1: {
                    JGeometry::TVec3<f32> pos;
                    void* tex;

                    rec.b1c = 0;
                    mtx[0][3] = lbl_80540D94;
                    mtx[1][3] = lbl_80540D94;
                    mtx[2][3] = lbl_80540D94;
                    rec.b1d = 0;
                    rec.b2d = 0;
                    tag[0] = lbl_80540D88[*(s32*)(p + 0x244)];
                    tag[1] = lbl_80540D8C[*(s32*)(p + 0x244)];
                    tag[2] = lbl_80540D90[*(s32*)(p + 0x244)];
                    tag[3] = self[0x274 + i];
                    mtx[0][0] = lbl_80540D98; mtx[0][1] = lbl_80540D94; mtx[0][2] = lbl_80540D94;
                    mtx[1][0] = lbl_80540D94; mtx[1][1] = lbl_80540D98; mtx[1][2] = lbl_80540D94;
                    mtx[2][0] = lbl_80540D94; mtx[2][1] = lbl_80540D94; mtx[2][2] = lbl_80540D98;
                    rec.w18 = mtx;
                    fn_8022EA0C(i, mtx);
                    *(JGeometry::TVec3<f32>*)(self + 0xc) = *(JGeometry::TVec3<f32>*)fn_8023E724();
                    tex = fn_804030C4(0x54494D47, lbl_804A8F50[*(s32*)(p + 0x244)]);
                    pos.x = *(f32*)(self + 0xc);
                    pos.y = *(f32*)(self + 0x10) - lbl_80540D9C;
                    pos.z = *(f32*)(self + 0x14);
                    if (*(s32*)(self + 4) < 8) {
                        fn_802F745C(*(void**)(lbl_8053AB10 + 0x20), &pos, tex, (u8*)&rec);
                    }
                    break;
                }
                case 2: {
                    JGeometry::TVec3<f32> pos;
                    void* tex;

                    rec.b1c = 0;
                    mtx[0][3] = lbl_80540D94;
                    mtx[1][3] = lbl_80540D94;
                    mtx[2][3] = lbl_80540D94;
                    rec.b1d = 0;
                    rec.b2d = 0;
                    tag[0] = 0xf2;
                    tag[1] = 0x49;
                    tag[2] = 0x12;
                    tag[3] = self[0x274 + i];
                    mtx[0][0] = lbl_80540D98; mtx[0][1] = lbl_80540D94; mtx[0][2] = lbl_80540D94;
                    mtx[1][0] = lbl_80540D94; mtx[1][1] = lbl_80540D98; mtx[1][2] = lbl_80540D94;
                    mtx[2][0] = lbl_80540D94; mtx[2][1] = lbl_80540D94; mtx[2][2] = lbl_80540D98;
                    rec.w18 = mtx;
                    fn_8022EA0C(i, mtx);
                    *(JGeometry::TVec3<f32>*)(self + 0xc) = *(JGeometry::TVec3<f32>*)fn_8023E724();
                    tex = fn_804030C4(0x54494D47, lbl_8046D8CC);
                    pos.x = *(f32*)(self + 0xc);
                    pos.y = *(f32*)(self + 0x10) - lbl_80540D9C;
                    pos.z = *(f32*)(self + 0x14);
                    if (*(s32*)(self + 4) < 8) {
                        fn_802F745C(*(void**)(lbl_8053AB10 + 0x20), &pos, tex, (u8*)&rec);
                    }
                    break;
                }
                case 3: {
                    JGeometry::TVec3<f32> pos;
                    void* tex;

                    rec.b1c = 0;
                    mtx[0][3] = lbl_80540D94;
                    mtx[1][3] = lbl_80540D94;
                    mtx[2][3] = lbl_80540D94;
                    rec.b1d = 0;
                    rec.b2d = 0;
                    tag[0] = 0xf2;
                    tag[1] = 0x49;
                    tag[2] = 0x12;
                    tag[3] = self[0x274 + i];
                    mtx[0][0] = lbl_80540D98; mtx[0][1] = lbl_80540D94; mtx[0][2] = lbl_80540D94;
                    mtx[1][0] = lbl_80540D94; mtx[1][1] = lbl_80540D98; mtx[1][2] = lbl_80540D94;
                    mtx[2][0] = lbl_80540D94; mtx[2][1] = lbl_80540D94; mtx[2][2] = lbl_80540D98;
                    rec.w18 = mtx;
                    fn_8022EA0C(i, mtx);
                    *(JGeometry::TVec3<f32>*)(self + 0xc) = *(JGeometry::TVec3<f32>*)fn_8023E724();
                    tex = fn_804030C4(0x54494D47, lbl_8046D8E0);
                    pos.x = *(f32*)(self + 0xc);
                    pos.y = *(f32*)(self + 0x10) - lbl_80540D9C;
                    pos.z = *(f32*)(self + 0x14);
                    if (*(s32*)(self + 4) < 8) {
                        fn_802F745C(*(void**)(lbl_8053AB10 + 0x20), &pos, tex, (u8*)&rec);
                    }
                    break;
                }
                case 4:
                case 5:
                case 6:
                case 7:
                case 8: {
                    JGeometry::TVec3<f32> pos;
                    void* tex;

                    rec.b1c = 0;
                    mtx[0][3] = lbl_80540D94;
                    mtx[1][3] = lbl_80540D94;
                    mtx[2][3] = lbl_80540D94;
                    rec.b1d = 0;
                    rec.b2d = 0;
                    tag[0] = 0xff;
                    tag[1] = 0xff;
                    tag[2] = 0xff;
                    tag[3] = self[0x274 + i];
                    mtx[0][0] = lbl_80540DA0; mtx[0][1] = lbl_80540D94; mtx[0][2] = lbl_80540D94;
                    mtx[1][0] = lbl_80540D94; mtx[1][1] = lbl_80540DA0; mtx[1][2] = lbl_80540D94;
                    mtx[2][0] = lbl_80540D94; mtx[2][1] = lbl_80540D94; mtx[2][2] = lbl_80540DA0;
                    rec.w18 = mtx;
                    fn_8022EA0C(i, mtx);
                    *(JGeometry::TVec3<f32>*)(self + 0xc) = *(JGeometry::TVec3<f32>*)fn_8023E724();
                    tex = fn_804030C4(0x54494D47, lbl_804A8F60[*(s32*)(p + 0x28c) - 4]);
                    pos.x = *(f32*)(self + 0xc);
                    pos.y = *(f32*)(self + 0x10) - lbl_80540D9C;
                    pos.z = *(f32*)(self + 0x14);
                    if (*(s32*)(self + 4) < 8) {
                        fn_802F745C(*(void**)(lbl_8053AB10 + 0x20), &pos, tex, (u8*)&rec);
                    }
                    break;
                }
                }
            }
        }
        p += 4;
    }
}

extern "C" u8 lbl_8050EC80[];
extern "C" s32 fn_80138A30(void* p);
extern "C" s32 fn_80236100(s32 i);
extern "C" s32 fn_80237774(s32 i);
extern "C" u8 fn_8022AF5C(void);
extern "C" s32 fn_8023DE58(s32 i);
extern "C" u8 fn_8023BE0C(s32 i);
extern "C" u8 fn_8022D75C(s32 i);
extern "C" u8 fn_8023BCD4(s32 i);
extern "C" u8 fn_802D46D8(u8* a, s32 i, s32 b, s32 c = 0);
extern "C" s32 fn_8013CC50(s32 a, Vec* b, s32 id, s32 c, s32 d, s32 e, s32 f, s32 g, f32 h);
extern "C" void fn_802CA7F4(u8* this_) {
    u8* p;
    u8* q;
    u8* o;
    s32 i;
    s32 k;
    s32 cnt;
    s32 j;
    s32 v;
    s32 arr1[8];
    s32 arr2[4];
    u8* ent;
    Vec tmpB;
    Vec tmpA;
    u8 hit;

    *(Vec*)(this_ + 0xc) = *fn_8023E724(0);

    if (lbl_8053AAF8[0x7e] == 1) {
        if (lbl_8053AAF8[0x7f] == 1) {
            for (i = 0; i < fn_80138A30(lbl_8053AAF8); i++) {
                arr1[i] = fn_80236100(i);
            }
            for (j = 0; j < fn_80138A30(lbl_8053AAF8); j++) {
                v = arr1[j];
                cnt = 0;
                for (k = 0; k < fn_80138A30(lbl_8053AAF8); k++) {
                    if (j != k && v < arr1[k]) {
                        cnt++;
                    }
                }
                *(s32*)(this_ + 0x244 + j * 4) = cnt;
            }
        } else {
            for (i = 0; i < 4; i++) {
                hit = (lbl_8053AAF8[0x82] & (u8)((u32)1 << i)) != 0;
                if (hit == 1) {
                    arr2[i] = fn_80237774(i);
                } else {
                    arr2[i] = 0;
                }
            }
            for (j = 0; j < 4; j++) {
                v = arr2[j];
                cnt = 0;
                for (k = 0; k < 4; k++) {
                    if (j != k && v < arr2[k]) {
                        cnt++;
                    }
                }
                *(s32*)(this_ + 0x244 + j * 4) = cnt;
            }
        }
    }

    p = this_;
    for (i = 0; i < 4; i++) {
        if (*(s32*)(p + 0x244) != *(s32*)(p + 0x254)) {
            if (this_[0x278] != 0 && !fn_8022AF5C()) {
                for (k = 0; k < 4; k++) {
                    q = this_ + k * 4;
                    hit = (lbl_8053AAF8[0x82] & (u8)((u32)1 << k)) != 0;
                    if (hit == 1) {
                        if (lbl_8053AAF8[0x7f] == 1) {
                            ent = lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xc8;
                            if (ent[0x88] == 0 && ent[0x89] != 0 && fn_8023DE58(k) < 8) {
                                *(s32*)(q + 0x27c) = 0xb4;
                                *(s32*)(q + 0x28c) = 1;
                                if (*(s32*)(q + 0x244) < *(s32*)(q + 0x254)) {
                                    if (*(s32*)(q + 0x234) != 0) {
                                        o = (u8*)*(s32*)(q + 0x234);
                                        *(s32*)(o + 0xf4) |= 1;
                                        *(s32*)(o + 0x24) = 1;
                                        *(s32*)(q + 0x234) = 0;
                                    }
                                    if (*(s32*)(q + 0x234) == 0) {
                                        tmpA.x = fn_8023E724(k)->x;
                                        tmpA.y = fn_8023E724(k)->y - lbl_80540D9C;
                                        tmpA.z = fn_8023E724(k)->z;
                                        *(s32*)(q + 0x234) = fn_8013CC50(0, &tmpA, 0x3a6, 0, 0, 0, 0, 1, lbl_80540D98);
                                    }
                                } else if (*(s32*)(q + 0x244) > *(s32*)(q + 0x254)) {
                                    if (*(s32*)(q + 0x234) != 0) {
                                        o = (u8*)*(s32*)(q + 0x234);
                                        *(s32*)(o + 0xf4) |= 1;
                                        *(s32*)(o + 0x24) = 1;
                                        *(s32*)(q + 0x234) = 0;
                                    }
                                    if (*(s32*)(q + 0x234) == 0) {
                                        tmpB.x = fn_8023E724(k)->x;
                                        tmpB.y = fn_8023E724(k)->y - lbl_80540D9C;
                                        tmpB.z = fn_8023E724(k)->z;
                                        *(s32*)(q + 0x234) = fn_8013CC50(0, &tmpB, 0x3a5, 0, 0, 0, 0, 1, lbl_80540D98);
                                    }
                                }
                            }
                        }
                    }
                }
                *(s32*)(p + 0x254) = *(s32*)(p + 0x244);
            }
        }
        if (fn_8023BE0C(i)) {
            if (fn_8023DE58(i) < 8) {
                if (fn_802D46D8(fn_802D6A9C(), i, 0xeb) == 1) {
                    *(s32*)(p + 0x27c) = 0x1e;
                    *(s32*)(p + 0x28c) = 2;
                }
            }
        }
        p += 4;
    }

    p = this_;
    for (i = 0; i < 4; i++) {
        this_[0x274 + i] = 0xff;
        if (fn_8022D75C(i)) {
            this_[0x274 + i] = fn_8023BCD4(i);
        }
        if (*(s32*)(p + 0x27c) != 0) {
            *(s32*)(p + 0x27c) = *(s32*)(p + 0x27c) - 1;
        } else {
            *(s32*)(p + 0x28c) = 0;
        }
        if (*(s32*)(p + 0x28c) == 1) {
            if (*(s32*)(p + 0x234) != 0) {
                f32 z = fn_8023E724(i)->z;
                f32 yy = fn_8023E724(i)->y - lbl_80540D9C;
                f32 x = fn_8023E724(i)->x;
                o = (u8*)*(s32*)(p + 0x234);
                *(f32*)(o + 0xa4) = x;
                *(f32*)(o + 0xa8) = yy;
                *(f32*)(o + 0xac) = z;
                *(f32*)(o + 0x98) = lbl_80540D98;
                *(f32*)(o + 0x9c) = lbl_80540D98;
                *(f32*)(o + 0xa0) = lbl_80540D98;
                *(f32*)(o + 0xb0) = lbl_80540D98;
                *(f32*)(o + 0xb4) = lbl_80540D98;
            }
        } else {
            if (*(s32*)(p + 0x234) != 0) {
                o = (u8*)*(s32*)(p + 0x234);
                *(s32*)(o + 0xf4) |= 1;
                *(s32*)(o + 0x24) = 1;
                *(s32*)(p + 0x234) = 0;
            }
        }
        p += 4;
    }

    *(s32*)(this_ + 0x27c) = 0;
    *(s32*)(this_ + 0x28c) = 0;
    *(s32*)(this_ + 0x280) = 0;
    *(s32*)(this_ + 0x290) = 0;
    *(s32*)(this_ + 0x284) = 0;
    *(s32*)(this_ + 0x294) = 0;
    *(s32*)(this_ + 0x288) = 0;
    *(s32*)(this_ + 0x298) = 0;
    this_[0x11f] = 1;
}

extern "C" void fn_802CADB0(u8* this_) {
    u8* p;
    s32 i;

    if (lbl_8053AAF8[0x7e] == 1 && !fn_802DEBF8() && !fn_802DEBA0() && !fn_802DE814()) {
        this_[0x278] = 1;
    } else {
        this_[0x278] = 0;
    }

    p = this_;
    for (i = 0; i < 4; i++) {
        *(s32*)(p + 0x234) = 0;
        *(s32*)(p + 0x244) = 0;
        *(s32*)(p + 0x254) = 0;
        this_[0x274 + i] = 0xff;
        if (lbl_8053AAF8[0x82] & (u8)(1 << i)) {
            *(s32*)(p + 0x264) = fn_80237774(i);
        } else {
            *(s32*)(p + 0x264) = 0;
        }
        p += 4;
    }

    *(s32*)(this_ + 0x27c) = 0;
    *(s32*)(this_ + 0x28c) = 0;
    *(s32*)(this_ + 0x280) = 0;
    *(s32*)(this_ + 0x290) = 0;
    *(s32*)(this_ + 0x284) = 0;
    *(s32*)(this_ + 0x294) = 0;
    *(s32*)(this_ + 0x288) = 0;
    *(s32*)(this_ + 0x298) = 0;
    this_[0x11f] = 1;
}

extern "C" Actor* fn_802CAEB0(Actor* self, s16 flag)
{
    struct SubObj802CA {
        u8 pad[0x24];
        s32 f24;
        u8 pad2[0xf4 - 0x28];
        u32 f0f4;
    };
    u8* p = (u8*)self;
    if (self != 0) {
        *(u8**)p = lbl_804A8F74;
        SubObj802CA* s;
        for (int i = 0; i < 2; i++) {
            s = *(SubObj802CA**)(p + 0x234 + i * 8);
            if (s != 0) {
                s->f0f4 |= 1;
                s->f24 = 1;
                *(SubObj802CA**)(p + 0x234 + i * 8) = 0;
            }
            s = *(SubObj802CA**)(p + 0x238 + i * 8);
            if (s != 0) {
                s->f0f4 |= 1;
                s->f24 = 1;
                *(SubObj802CA**)(p + 0x238 + i * 8) = 0;
            }
        }
        __dt__5ActorFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

extern "C" void fn_802CAFA0(void) {
}

