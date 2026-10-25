#include "Game/ItemBase.h"
#include "JSystem/JMath/JMath.h"
#include "std/math.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"

extern "C" void* fn_802D6A9C(void);
extern "C" s32 fn_8023DE58(s32 idx);
extern "C" void fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void __dl__FPv(void* p);
extern void* lbl_804AB8C0[];

extern "C" void* fn_801F856C(void);
extern "C" int fn_801F78F4(void* mgr, unsigned int code, int idx);
extern "C" void* fn_801F666C(void* mgr, int idx);
extern "C" unsigned char fn_801F6758(void* pos, int idx, float margin);
extern float lbl_80541EEC;
extern "C" int fn_8013CC50(int, char*, float, int, int, int, int, int, int);
extern "C" void fn_8013CB44(void*, void*, int, int, int);
extern float lbl_80541EBC;
extern float lbl_80541E98;
extern float lbl_80541E9C;
extern float lbl_80541EBC;
extern float lbl_80541ECC;
extern float lbl_80541EE4;
extern float lbl_80541EFC;
extern float lbl_80541F10;
extern "C" u8 fn_8023F264(s32);
extern "C" u8 fn_8022DCD8(s32);
extern "C" u8 fn_8022F478(s32);
extern "C" u8 fn_80236B50(s32);
extern "C" u8 fn_8022D534(s32);
extern "C" void* fn_8023E724(s32);
extern "C" s32 ClassifyBamAngleToQuadrant(u16 angle);
extern "C" void fn_8032F148(void* p1, s32 idx, u16* outAng, s32* outQuad, f32* outDist, s32* outFlag, s32 slot) {
    char* a = (char*)fn_801F666C(fn_801F856C(), idx);
    f32 dist = lbl_80541E98;
    s32 result = -1;
    u16 ang = 0;
    s32 mode;
    s32 room;
    f32 dx;
    f32 dy;
    f32 len;

    if (a == 0) {
        if (outQuad != 0) *outQuad = -1;
        if (outFlag != 0) *outFlag = -1;
        return;
    }
    mode = 0;
    if (fn_8023DE58(slot) < 8 && *(s32*)(a + 4) == 8) {
        mode = 2;
    } else {
        room = *(s32*)(a + 4);
        if (room == fn_8023DE58(slot)) {
            mode = 1;
        }
    }
    if (fn_8023F264(slot) && !fn_8022DCD8(slot) && mode != 0 && !fn_8022F478(slot) && !fn_80236B50(slot) && !fn_8022D534(slot)) {
        if (mode == 1) {
            dx = *(f32*)(a + 0xc) - ((f32*)fn_8023E724(slot))[0];
            dy = *(f32*)(a + 0x10) - ((f32*)fn_8023E724(slot))[1];
        } else {
            u32 tmp[4];
            s32 q = fn_8023DE58(slot);
            char* m = (char*)fn_802D6A9C();
            s32 n = fn_8023DE58(slot);
            if (q < 8) {
                ((u32*)tmp)[0] = ((u32*)(m + 0xcc))[0];
            }
            dx = *(f32*)(a + 0xc) - (((f32*)fn_8023E724(slot))[0] - *(f32*)&tmp[0]);
            dy = *(f32*)(a + 0x10) - (((f32*)fn_8023E724(slot))[1] - *(f32*)&tmp[1]);
        }
        len = std::sqrtf(dx * dx + dy * dy);
        dist = len;
        ang = (u16)(s32)(JMath::atanTable_.atan2_(-dx, -dy) * 10430.378f);
        result = slot;
    }
    if (result >= 0) {
        if (outAng != 0) *outAng = ang;
        if (outQuad != 0) *outQuad = ClassifyBamAngleToQuadrant(ang);
        if (outDist != 0) *outDist = dist;
        if (outFlag != 0) *outFlag = result;
    } else {
        if (outQuad != 0) *outQuad = -1;
        if (outFlag != 0) *outFlag = -1;
    }
}

extern "C" void fn_8032F4A8(char* this_) {
    extern unsigned char* lbl_8053AAF8;
    extern unsigned char lbl_80471A78[];
    extern unsigned short fn_8022461C(void* a, int b);
    extern int fn_8023CB24(int a);
    extern int fn_8023CA88(int a);
    extern void fn_801F06F0(char* a, void* p2, int p3, void* p4, int p5, float f6, float f7);
    extern void fn_803075AC(void* h, int room, void* pos, int idx, int a, int b, int c, int d, int e, int f);

    if (*(unsigned char*)(this_ + 0x2a7) != 1 && *(unsigned char*)(this_ + 0x288) != 0) {
        DrawRec rec;
        int bVar1 = 0;
        int uVar9 = 7;
        int iVar8 = 0;

        if (lbl_80541E9C == *(float*)(this_ + 0x14) && (int)fn_8022461C(this_ + 0xc, *(int*)(this_ + 4)) == 0x39) {
            uVar9 = 0;
        }
        rec.b20 = 0;
        if (*(unsigned char*)(this_ + 0x2a8) == 1) {
            int iVar2 = *(int*)(this_ + 0x25c);
            if (iVar2 >= 0 && iVar2 <= 3) {
                iVar8 = iVar2 + 1;
            }
        }
        switch (iVar8) {
        case 1:
            ((u8*)&rec)[0x15] = 0x14;
            ((u8*)&rec)[0x10] = 0xc8;
            ((u8*)&rec)[0x12] = 0x96;
            break;
        case 2:
            ((u8*)&rec)[0x14] = 0x14;
            ((u8*)&rec)[0x11] = 0xc8;
            ((u8*)&rec)[0x12] = 0xaa;
            break;
        case 3:
            ((u8*)&rec)[0x16] = 0x14;
            ((u8*)&rec)[0x10] = 0xb4;
            ((u8*)&rec)[0x11] = 0xc8;
            break;
        case 4:
            ((u8*)&rec)[0x14] = 0x14;
            ((u8*)&rec)[0x16] = 0x14;
            ((u8*)&rec)[0x11] = 0xc3;
            break;
        }
        if (*(int*)(this_ + 0x230) == 3) {
            rec.b1d = 1;
            rec.b1c = 1;
            if (*(int*)(this_ + 0x290) != 0 && (*(unsigned int*)(this_ + 0x26c) & 8) == 0) {
                rec.ids[0xb] = 9;
            }
        } else {
            if (*(int*)(this_ + 0x290) != 0 && *(int*)(this_ + 0x290) != 6) {
                rec.ids[0xb] = 9;
            }
            if (*(int*)(this_ + 0x23c) != 0) {
                rec.w30 = 0x11;
            }
        }
        if (*(unsigned char*)(this_ + 0xc4) != 0) {
            uVar9 = -1;
            ((u8*)&rec)[0x13] = *(unsigned char*)(this_ + 0x288);
            rec.b1d = fn_8023CB24(*(int*)(this_ + 0xc8)) + 1;
            rec.b1c = fn_8023CA88(*(int*)(this_ + 0xc8));
            bVar1 = 1;
        }
        if (*(int*)(this_ + 0x230) == 10) {
            if (lbl_8053AAF8[0x7f] == 1) {
                rec.b1d = fn_8023CB24(*(int*)(this_ + 0x25c)) + 1;
                rec.b1c = fn_8023CA88(*(int*)(this_ + 0x25c));
                if (*(int*)(this_ + 0x290) != 2) {
                    fn_801F06F0(this_, lbl_80471A78, *(int*)(this_ + 0x264) + 0x11, &rec, -1, lbl_80541EBC, lbl_80541EBC);
                    fn_803075AC(*(void**)(this_ + 0x198), *(int*)(this_ + 4), this_ + 0xc, 0x11, 0, 2, -1, 1, 0, 0);
                } else {
                    fn_801F06F0(this_, lbl_80471A78, *(int*)(this_ + 0x264) + 0x1d, &rec, -1, lbl_80541EBC, lbl_80541EBC);
                    fn_803075AC(*(void**)(this_ + 0x198), *(int*)(this_ + 4), this_ + 0xc, 0x1d, 0, 2, -1, 1, 0, 0);
                }
            }
        } else {
            int iVar3 = *(int*)(this_ + 0x290);
            if (iVar3 == 2 || ((iVar3 == 0 || iVar3 == 6 || iVar3 == 1) && *(unsigned char*)(this_ + 0x2a1) == 1)) {
                fn_801F06F0(this_, lbl_80471A78, *(int*)(this_ + 0x264) + 0x2c7, &rec, uVar9, lbl_80541EBC, lbl_80541EBC);
                fn_803075AC(*(void**)(this_ + 0x198), *(int*)(this_ + 4), this_ + 0xc, *(int*)(this_ + 0x264) + 0x2c7, 0, 2, -1, bVar1, 0, 0);
            } else {
                fn_801F06F0(this_, lbl_80471A78, *(int*)(this_ + 0x264) + 0x2af, &rec, uVar9, lbl_80541EBC, lbl_80541EBC);
                fn_803075AC(*(void**)(this_ + 0x198), *(int*)(this_ + 4), this_ + 0xc, *(int*)(this_ + 0x264) + 0x2af, 0, 2, -1, bVar1, 0, 0);
            }
        }
    }
}

extern "C" void fn_8032F96C(char* this_) {
    extern s32 fn_8022F9E4(s32 a, s32 b, s32 c, s32 d);
    s32 r;
    if (*(s32*)(this_ + 0x230) == 2) {
        r = fn_8022F9E4(*(s32*)(this_ + 0x25c), *(s32*)(this_ + 0x198), 0, 0);
        if ((u8)r == 1) {
            *(s32*)(this_ + 0x230) = 3;
        }
        return;
    }
}

extern "C" void fn_803319B8(char* this_) {
    extern unsigned char* lbl_8053AAF8;
    extern int fn_801F0E34(void* this_, unsigned int id, int c);
    extern float lbl_80541EFC;
    extern float lbl_80541EBC;
    int table[4] = {0, 1, 0, 1};
    *(int*)(this_ + 0x264) = table[*(int*)(this_ + 0x254)] + ((*(int*)(this_ + 0x98) & 1) << 1);
    if (*(int*)(this_ + 0x230) == 9) {
        if (lbl_8053AAF8[0x7f] == 1) {
            *(int*)(this_ + 0x264) += 4;
        } else {
            *(int*)(this_ + 0x264) += 8;
        }
    } else if (*(unsigned char*)(this_ + 0x2a3) == 1 && *(unsigned char*)(this_ + 0x2a8) == 0 &&
               (*(float*)(this_ + 0x14) > lbl_80541EFC || *(int*)(this_ + 0x230) == 1)) {
        if (*(int*)(this_ + 0x254) == 0) {
            if (*(int*)(this_ + 0x98) & 1) {
                *(int*)(this_ + 0x264) = 0xd;
            } else {
                *(int*)(this_ + 0x264) = 0xc;
            }
            fn_801F0E34(this_, 0x40001, 0);
        }
        if ((*(int*)(this_ + 0x254) & 1) == 0) {
            if (*(unsigned char*)(this_ + 0x2a1) == 0) {
                fn_8013CC50(*(int*)(this_ + 4), this_ + 0xc, lbl_80541EBC, 0x348, 0, 0, 0, 0, 1);
            } else {
                fn_8013CC50(*(int*)(this_ + 4), this_ + 0xc, lbl_80541EBC, 0xd2, 0, 0, 0, 0, 1);
            }
        }
    }
}

extern "C" void fn_80331B40(char* this_) {
    if (*(unsigned char*)(this_ + 0x2a3) == 1) {
        if (*(int*)(this_ + 0x230) == 1) {
            void* h = *(void**)(this_ + 0x2fc);
            if (h == 0) {
                *(int*)(this_ + 0x2fc) = fn_8013CC50(*(int*)(this_ + 4), this_ + 0xc, lbl_80541EBC, 0x116, 0, 3, 0, 0, 1);
            } else {
                fn_8013CB44(h, this_ + 0xc, 0, 3, 1);
            }
        } else {
            void* h = *(void**)(this_ + 0x2fc);
            if (h != 0) {
                *(unsigned int*)((char*)h + 0xf4) |= 1;
                *(int*)((char*)h + 0x24) = 1;
                *(int*)(this_ + 0x2fc) = 0;
            }
            h = *(void**)(this_ + 0x300);
            if (h != 0) {
                *(unsigned int*)((char*)h + 0xf4) |= 1;
                *(int*)((char*)h + 0x24) = 1;
                *(int*)(this_ + 0x300) = 0;
            }
        }
    }
}

extern "C" void fn_80331C24(char* this_) {
    extern unsigned short fn_8022461C(void* a, int b);
    extern int fn_801F0E34(void* this_, unsigned int id, int c);
    extern float lbl_80541EE8;
    if (*(int*)(this_ + 0x290) == 0 || *(int*)(this_ + 0x290) == 6) {
        int code = fn_8022461C(this_ + 0xc, *(int*)(this_ + 4));
        if (code == 0x39 &&
            ((*(int*)(this_ + 0x230) == 0 && *(int*)(this_ + 0x258) == 0) || *(int*)(this_ + 0x230) == 1) &&
            *(float*)(this_ + 0x14) < lbl_80541EE8) {
            fn_801F0E34(this_, 0x4007f, 0);
            void* h = *(void**)(this_ + 0x2f8);
            if (h == 0) {
                *(int*)(this_ + 0x2f8) = fn_8013CC50(*(int*)(this_ + 4), this_ + 0xc, lbl_80541EBC, 0x4d2, 0, 3, 0, 0, 1);
            } else {
                fn_8013CB44(h, this_ + 0xc, 0, 3, 1);
            }
        } else {
            void* h = *(void**)(this_ + 0x2f8);
            if (h != 0) {
                *(unsigned int*)((char*)h + 0xf4) |= 1;
                *(int*)((char*)h + 0x24) = 1;
                *(int*)(this_ + 0x2f8) = 0;
            }
        }
    }
}

extern "C" void fn_80331D38(char* this_) {
    extern unsigned char fn_8023F264(int idx);
    extern unsigned char fn_80239C00(int idx, void* box, int a2);
    extern unsigned char fn_8022F9E4(int idx, int a0, unsigned char a1, unsigned char a2);
    extern float lbl_80541EFC;
    float limit = lbl_80541EFC;
    float cur = *(float*)(this_ + 0x14);
    if (cur < limit && *(int*)(this_ + 0x268) > 0) {
        float box[4];
        int i = 0;
        box[0] = *(float*)(this_ + 0x60);
        box[1] = *(float*)(this_ + 0x64);
        box[2] = *(float*)(this_ + 0x68);
        box[3] = *(float*)(this_ + 0x6c);
        box[0] += *(float*)(this_ + 0xc);
        box[1] += *(float*)(this_ + 0x10);
        box[2] += *(float*)(this_ + 0xc);
        box[3] += *(float*)(this_ + 0x10);
        do {
            if (fn_8023F264(i) && fn_80239C00(i, box, *(int*)(this_ + 4)) &&
                fn_8022F9E4(i, *(int*)(this_ + 0x198), 1, 0)) {
                float zero = lbl_80541E9C;
                *(float*)(this_ + 0x14) = zero;
                *(int*)(this_ + 0x258) = 0;
                *(int*)(this_ + 0x238) = 0;
                *(int*)(this_ + 0x240) = 0;
                *(float*)(this_ + 0x2b8) = zero;
                *(float*)(this_ + 0x2bc) = zero;
                *(float*)(this_ + 0x2c0) = zero;
                *(float*)(this_ + 0x3c) = zero;
                *(float*)(this_ + 0x40) = zero;
                *(float*)(this_ + 0x44) = zero;
                *(int*)(this_ + 0x25c) = *(int*)(this_ + 0xc8);
                *(int*)(this_ + 0xb8) = 2;
                *(int*)(this_ + 0x230) = 3;
                return;
            }
            i++;
        } while (i < 4);
    }
}

extern "C" void fn_80331E6C(char* this_) {
    char* self = this_;
    char* o;
    s32 n;
    s32 off;
    s32 r27;
    s32 r26;
    s32 i;
    Vec pos;
    f32 mag;
    s32 kind;
    s32 room;
    s32 id;

    if (*(u8*)(self + 0x2a4) == 1) {
        r27 = -1;
        r26 = -1;
        if (*(s32*)(self + 0x230) == 3) {
            goto end;
        }
        n = *(s32*)((char*)fn_801F856C() + 0x1008);
        i = 0;
        off = 0;
        for (; i < n; i++, off += 4) {
            o = *(char**)((char*)fn_801F856C() + off + 8);
            if (o == 0) continue;
            id = *(s32*)(o + 0x1a0);
            if (id != 'WARP') {
                if (id != 'CIRC') continue;
                if (*(s32*)(o + 4) != *(s32*)(self + 4)) continue;
                {
                    f32 dx = *(f32*)(o + 0xc) - *(f32*)(self + 0xc);
                    f32 dy = *(f32*)(o + 0x10) - *(f32*)(self + 0x10);
                    f32 sx = dx * dx;
                    f32 sy = dy * dy;
                    f32 sq = sx + sy;
                    f32 len = lbl_80541E9C;
                    if (sq > lbl_80541E9C) {
                        f32 y = (f32)__frsqrte(sq);
                        len = sq * (lbl_80541EE4 * y * (lbl_80541ECC - sq * (y * y)));
                    }
                    if (len >= lbl_80541F10) continue;
                }
            }
            if (*(s32*)(o + 0x1a0) == 'WARP') {
                if (((int (*)(void*))(*(void***)o)[15])(o) != 0) {
                    if ((((int (*)(void*))(*(void***)o)[13])(o) & 0xff) == 1) {
                        r27 = *(s32*)(o + 0x198);
                        break;
                    }
                    continue;
                }
            }
            if (*(u8*)(o + 0x262) == 1) {
                r26 = *(s32*)(o + 0x198);
                break;
            }
        }
        if (r27 < 0 && r26 < 0) goto end;
        if (r27 >= 0) {
            o = (char*)fn_801F666C(fn_801F856C(), r27);
            if (o == 0) goto end;
            pos = *(Vec*)(o + 0x238);
            room = *(s32*)(self + 4);
            if (*(u8*)((char*)fn_802D6A9C() + room + 0x131df) == 0) {
                pos.z = *(f32*)(self + 0x14);
            }
            {
                s32 v = (*(s32*)(o + 0x90) >> 3) & 7;
                room = v != 0 ? v + 7 : 0;
            }
            kind = *(s32*)(o + 0x90) & 0x7f;
        } else {
            o = (char*)fn_801F666C(fn_801F856C(), r26);
            if (o == 0) goto end;
            pos = *(Vec*)(o + 0x268);
            room = *(s32*)(self + 4);
            if (*(u8*)((char*)fn_802D6A9C() + room + 0x131df) == 0) {
                pos.z = *(f32*)(self + 0x14);
            }
            {
                s32 v = (*(s32*)(o + 0x90) >> 3) & 7;
                room = v != 0 ? v + 7 : 0;
            }
            kind = 6;
        }

        if (kind == 6 || kind == 0x14 || kind == 4 || kind == 0x20 || kind == 0x24) {
            if (*(f32*)(self + 0x14) < lbl_80541EFC) goto end;
        } else if (kind == 0 || kind == 3 || kind == 0x15 || kind == 0x23) {
            if (*(f32*)(self + 0x40) >= lbl_80541E9C) goto end;
        } else if (kind == 1 || kind == 2) {
            if (*(f32*)(self + 0x40) <= lbl_80541E9C) goto end;
        } else if (kind == 0x17) {
            if (*(f32*)(self + 0x3c) <= lbl_80541E9C) goto end;
        } else if (kind == 0x18) {
            if (*(f32*)(self + 0x3c) < lbl_80541E9C) goto end;
        }

        *(Vec*)(self + 0xc) = pos;
        *(f32*)(self + 0x14) = pos.z;
        *(s32*)(self + 4) = room;
        *(s32*)(self + 0x284) = 0x14;
        *(Vec*)(self + 0x2e8) = pos;
        *(f32*)(self + 0x2f0) = pos.z;
        *(Vec*)(self + 0x2d0) = pos;
        *(f32*)(self + 0x2d8) = pos.z;
        *(u8*)(self + 0x2a4) = 0;
        *(u8*)(self + 0x2a5) = 0;
        mag = PSVECMag((Vec*)(self + 0x2b8));
        if (mag < lbl_80541EBC) {
            mag = lbl_80541EBC;
        } else if (mag > lbl_80541ECC) {
            mag = lbl_80541ECC;
        }
        if (kind != 6 && kind != 0x14) {
            *(f32*)(self + 0x44) = lbl_80541E9C;
            *(f32*)(self + 0x40) = lbl_80541E9C;
            *(f32*)(self + 0x3c) = lbl_80541E9C;
            *(f32*)(self + 0x2c0) = lbl_80541E9C;
            *(f32*)(self + 0x2bc) = lbl_80541E9C;
            *(f32*)(self + 0x2b8) = lbl_80541E9C;
        }
        *(s32*)(self + 0x238) = 0x14;
        *(s32*)(self + 0x258) = 0;
        switch (kind) {
        case 0:
        case 3:
            *(f32*)(self + 0x40) = mag * lbl_80541EE4;
            *(f32*)(self + 0x2bc) = mag;
            break;
        case 1:
        case 2:
            *(f32*)(self + 0x40) = -(mag * lbl_80541EE4);
            *(f32*)(self + 0x2bc) = -mag;
            break;
        case 0x17:
            *(f32*)(self + 0x3c) = mag * lbl_80541EE4;
            *(f32*)(self + 0x2b8) = mag;
            break;
        case 0x18:
            *(f32*)(self + 0x3c) = -(mag * lbl_80541EE4);
            *(f32*)(self + 0x2b8) = -mag;
            break;
        }
        if (*(s32*)(self + 0x23c) > 0) {
            *(s32*)(self + 0x23c) = 0x14;
        }
        goto end;
    }

    *(s32*)(self + 0x284) -= 1;
    if (*(s32*)(self + 0x284) > 0) goto end;
    {
        f32 dx = *(f32*)(self + 0x2e8) - *(f32*)(self + 0xc);
        f32 dy = *(f32*)(self + 0x2ec) - *(f32*)(self + 0x10);
        f32 sx = dx * dx;
        f32 sy = dy * dy;
        f32 sq = sx + sy;
        f32 dist = lbl_80541E9C;
        if (sq > lbl_80541E9C) {
            f32 y = (f32)__frsqrte(sq);
            dist = sq * (lbl_80541EE4 * y * (lbl_80541ECC - sq * (y * y)));
        }
        if (dist <= lbl_80541F10) goto end;
    }

end:
    *(u8*)(self + 0x2a4) = 1;
}

extern "C" unsigned char fn_801F2618(char* a, float* out, unsigned int c);
extern "C" int fn_801F11B4(char* a);
extern "C" void* fn_802D6A9C(void);
extern float lbl_80541E9C;
extern "C" unsigned char fn_80332378(char* this_) {
    char* p = this_;
    unsigned char r;
    float v[3];
    v[2] = lbl_80541E9C;
    v[1] = lbl_80541E9C;
    v[0] = lbl_80541E9C;
    r = fn_801F2618(p, v, 0);
    if (r == 1) {
        fn_801F11B4(p);
        int id = *(int*)(p + 4);
        if (((unsigned char*)fn_802D6A9C())[id + 0x131df] == 1 && v[1] < lbl_80541E9C) {
            *(float*)(p + 0x2bc) = lbl_80541E9C;
        }
    } else {
        int n = *(int*)(p + 0x270);
        if (n > 0) {
            if (n != *(int*)(p + 0x274)) {
                *(int*)(p + 0x274) = n;
                *(int*)(p + 0x278) = 5;
            } else {
                *(int*)(p + 0x278) = *(int*)(p + 0x278) - 1;
                if (*(int*)(p + 0x278) <= 0) {
                    *(int*)(p + 0x270) = 0;
                    *(int*)(p + 0x274) = 0;
                }
            }
        }
        int id = *(int*)(p + 4);
        if (((unsigned char*)fn_802D6A9C())[id + 0x131df] == 1 && *(unsigned char*)(p + 0x2a9) == 1 &&
            lbl_80541E9C == *(float*)(p + 0x2b4)) {
            *(float*)(p + 0x40) = lbl_80541E9C;
            *(float*)(p + 0x2bc) = lbl_80541E9C;
        }
    }
    return r;
}

extern "C" void fn_803324A8(char* this_) {
    extern unsigned char* lbl_8053AAF8;
    extern float lbl_80541E9C;
    extern float lbl_80541EBC;
    extern float lbl_80541ED0;
    extern float lbl_80541ED8;
    extern float lbl_80541EE0;
    extern float lbl_80541EE8;
    extern float lbl_80541EFC;
    extern float lbl_80541F14;
    extern float lbl_80541F18;
    extern float lbl_80541F1C;
    extern float lbl_80541F20;
    extern float lbl_80541F24;
    extern int fn_801EEC98(char* a, void* b, void* c, int* d, float* e, int f, int g, int h);
    extern void fn_801F0E34(char* a, u32 b, u32 c);
    extern s32 fn_8013CC50(u32 id, void* p, f32 f, u32 a, u32 b, u32 c, u32 d, u32 e, u32 g);
    extern unsigned char* fn_802D6A9C(void);
    extern float sincosTable___5JMath[];

    float b = 0.0f;
    int a = -1;
    u16 ang = 0;

    if (*(s32*)(this_ + 0x290) == 6 && *(s32*)(this_ + 0x230) == 0 && *(f32*)(this_ + 0x14) < lbl_80541EFC &&
        *(s32*)(this_ + 0x284) <= 0) {
        fn_801EEC98(this_, *(void**)(this_ + 0x198), 0, &a, &b, 0, 0, 0);
        if (b < lbl_80541ED8 && a >= 0) {
            if (*(u8*)(this_ + 0x2a2) == 1) {
                u32* seed = (u32*)(lbl_8053AAF8 + 0xb4);
                union {
                    f32 f;
                    u32 s;
                } r;
                f32 k = lbl_80541EBC;
                f32 m = lbl_80541F14;
                *seed = *seed * 0x19660d + 0x3c6ef35f;
                r.s = (*seed >> 9) | 0x3f800000;
                *(s32*)(this_ + 0x240) = (s32)(m * (r.f - k)) + 0xc8;
            } else {
                u32* seed = (u32*)(lbl_8053AAF8 + 0xb4);
                union {
                    f32 f;
                    u32 s;
                } r;
                f32 k = lbl_80541EBC;
                f32 m = lbl_80541F18;
                *seed = *seed * 0x19660d + 0x3c6ef35f;
                r.s = (*seed >> 9) | 0x3f800000;
                *(s32*)(this_ + 0x240) = (s32)(m * (r.f - k)) + 0x64;
            }
            if (*(u8*)(this_ + 0x2a1) == 0) {
                fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, lbl_80541EBC, 0x348, 0, 0, 0, 0, 1);
            } else {
                fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, lbl_80541EBC, 0xd2, 0, 0, 0, 0, 1);
            }
            fn_801F0E34(this_, 0x40001, 0);
            *(s32*)(this_ + 0x238) = 0;
            *(s32*)(this_ + 0x258) = 0;
            *(f32*)(this_ + 0x14) = lbl_80541E9C;
            *(f32*)(this_ + 0x44) = lbl_80541E9C;
            *(u64*)(this_ + 0x2dc) = *(u64*)(this_ + 0xc);
            *(f32*)(this_ + 0x2e4) = *(f32*)(this_ + 0x14);
            *(s32*)(this_ + 0x294) = *(s32*)(this_ + 4);
            *(s32*)(this_ + 0x230) = 1;
        } else {
        }
    }

    *(s32*)(this_ + 0x280) = 0;
    if (*(s32*)(this_ + 0x290) == 6 && *(s32*)(this_ + 0x230) == 1) {
        *(s32*)(this_ + 0x280) += 1;
        if (*(s32*)(this_ + 0x240) % 4 == 0) {
            if (*(s32*)(this_ + 0x290) == 6) {
                f32 dx = *(f32*)(this_ + 0xc) - *(f32*)(this_ + 0x2dc);
                f32 dy = *(f32*)(this_ + 0x10) - *(f32*)(this_ + 0x2e0);
                f32 dist = dx * dx + dy * dy;
                *(f32*)(this_ + 0x2dc) = *(f32*)(this_ + 0xc);
                *(f32*)(this_ + 0x2e0) = *(f32*)(this_ + 0x10);
                *(f32*)(this_ + 0x2e4) = *(f32*)(this_ + 0x14);
                *(s32*)(this_ + 0x294) = *(s32*)(this_ + 4);
                if (*(s32*)(this_ + 0x294) == *(s32*)(this_ + 4) && dist >= lbl_80541F1C) {
                    *(s32*)(this_ + 0x280) = 0;
                    return;
                }
            }
        }
    }

    if (*(u8*)(this_ + 0x2a3) == 1 && *(s32*)(this_ + 0x280) < 10) {
        return;
    }
    if (*(s32*)(this_ + 0x280) < 0x2d) {
        return;
    }
    fn_801EEC98(this_, *(void**)(this_ + 0x198), &ang, &a, &b, 0, 0, 0);
    if (a >= 0 && ((*(u8*)(this_ + 0x2a3) == 0 && b < lbl_80541EE0) ||
                   (*(u8*)(this_ + 0x2a3) == 1 && b < lbl_80541F20))) {
        *(s32*)(this_ + 0x238) = 0x32;
        if (*(u8*)(this_ + 0x2a2) == 1) {
            u32* seed = (u32*)(lbl_8053AAF8 + 0xb4);
            union {
                f32 f;
                u32 s;
            } r;
            f32 k = lbl_80541EBC;
            f32 m = lbl_80541F14;
            *seed = *seed * 0x19660d + 0x3c6ef35f;
            r.s = (*seed >> 9) | 0x3f800000;
            *(s32*)(this_ + 0x240) = (s32)(m * (r.f - k)) + 0xc8;
        } else {
            u32* seed = (u32*)(lbl_8053AAF8 + 0xb4);
            union {
                f32 f;
                u32 s;
            } r;
            f32 k = lbl_80541EBC;
            f32 m = lbl_80541F18;
            *seed = *seed * 0x19660d + 0x3c6ef35f;
            r.s = (*seed >> 9) | 0x3f800000;
            *(s32*)(this_ + 0x240) = (s32)(m * (r.f - k)) + 0x64;
        }
        if (*(u8*)(this_ + 0x2a1) == 0) {
            fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, lbl_80541EBC, 0x348, 0, 0, 0, 0, 1);
        } else {
            fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, lbl_80541EBC, 0xd2, 0, 0, 0, 0, 1);
        }
        fn_801F0E34(this_, 0x40001, 0);

        f32 f31 = lbl_80541ED0;
        if (*(u8*)(this_ + 0x2a3) == 1) {
            f31 = lbl_80541EE8;
        }
        s32 room = *(s32*)(this_ + 4);
        if (fn_802D6A9C()[room + 0x131df] != 0 && *(f32*)(this_ + 0x2b4) != 0.0f) {
            *(f32*)(this_ + 0x2b8) = f31 * sincosTable___5JMath[(ang >> 5) * 2];
        } else {
            u32* seed = (u32*)(lbl_8053AAF8 + 0xb4);
            union {
                f32 f;
                u32 s;
            } r;
            f32 k = lbl_80541EBC;
            *seed = *seed * 0x19660d + 0x3c6ef35f;
            r.s = (*seed >> 9) | 0x3f800000;
            ang = (u16)(ang + (s32)(lbl_80541F24 * (lbl_80541ED0 * (r.f - k) - k)));
            *(f32*)(this_ + 0x2b8) = f31 * sincosTable___5JMath[(ang >> 5) * 2];
            *(f32*)(this_ + 0x2bc) = f31 * sincosTable___5JMath[(ang >> 5) * 2 + 1];
        }
    }
    *(s32*)(this_ + 0x280) = 0;
}

extern "C" s32 fn_801F3D94(char* self, s32 n);
extern "C" s32 fn_801F82CC(void* mgr, char* a, u8 c, f32 f);
extern "C" void fn_801F3128(char* a, f32* out);
extern "C" u32 fn_801F37AC(char* a, u32 x, void* p, u32 d, u32 buf, u32 i);
extern "C" u32 fn_801F2DB4(char* a, u32 b, u32 c, void* buf);
extern "C" u8 fn_801F2FAC(char* a);
extern "C" void fn_801F0E34(char* a, u32 code, u32 z);
extern "C" s32 fn_801A4D1C(s32 h, void* p, void* q);
extern "C" s32 fn_801A6108(s32 h, void* p, void* q);
extern "C" s32 fn_801A4F5C(s32 h, void* p, void* q);
extern "C" s32 fn_801A46FC(s32 h, void* p, void* q);
extern float lbl_80541F28;
extern "C" void fn_80332A60(char* this_) {
    extern unsigned char* lbl_8053AAF8;
    extern float lbl_80541E9C;
    extern float lbl_80541EBC;
    extern float lbl_80541F28;
    extern float lbl_80541F14;
    extern float lbl_80541F18;
    char* a;
    f32 v[3];
    f32 box[4];
    s32 r31 = 0;
    s32 idx;
    s32 hit;
    u32 seed;
    u32 bits;
    s32 rnd;

    if (fn_801F3D94(this_, 1) == 0 && *(s32*)(this_ + 0x284) <= 0 && *(u8*)(this_ + 0xc4) == 0) {
        *(u32*)(this_ + 0xb0) = 0x41302;
        if (*(s32*)(this_ + 0x268) > 0) {
            box[0] = *(f32*)(this_ + 0x60) + *(f32*)(this_ + 0xc);
            box[1] = *(f32*)(this_ + 0x64) + *(f32*)(this_ + 0x10);
            box[2] = *(f32*)(this_ + 0x68) + *(f32*)(this_ + 0xc);
            box[3] = *(f32*)(this_ + 0x6c) + *(f32*)(this_ + 0x10);
            idx = fn_801F82CC(fn_801F856C(), this_, *(u8*)(this_ + 0x195), lbl_80541F28);
            if (idx >= 0 && idx != *(s32*)(this_ + 0x198)) {
                a = (char*)fn_801F666C(fn_801F856C(), idx);
                if (a != 0 && *(u32*)(a + 0x1a0) == 0x464c4d45) {
                    v[0] = lbl_80541E9C;
                    v[1] = lbl_80541E9C;
                    v[2] = lbl_80541E9C;
                    fn_801F3128(a, v);
                    v[0] = v[0] - *(f32*)(a + 0x3c);
                    v[1] = v[1] - *(f32*)(a + 0x40);
                    v[2] = v[2] - *(f32*)(a + 0x44);
                    hit = fn_801F37AC(this_, *(u32*)(a + 0x118), v, 0, *(u32*)(a + 0x168), *(u32*)(a + 0x110));
                    if (hit) {
                        *(u8*)(a + 0x164) = 1;
                        r31 = 2;
                    }
                }
            }
        }
        if (r31 > 0) {
            seed = *(u32*)(lbl_8053AAF8 + 0xb4) * 0x19660d + 0x3c6ef35f;
            *(u32*)(lbl_8053AAF8 + 0xb4) = seed;
            bits = (seed >> 9) | 0x3f800000;
            if (*(u8*)(this_ + 0x2a2) == 1) {
                rnd = (s32)((*(f32*)&bits - lbl_80541EBC) * lbl_80541F14);
                *(s32*)(this_ + 0x240) = rnd + 0xc8;
            } else {
                rnd = (s32)((*(f32*)&bits - lbl_80541EBC) * lbl_80541F18);
                *(s32*)(this_ + 0x240) = rnd + 0x64;
            }
        }
    }
}

extern "C" void fn_80333078(char* this_) {
    int h;
    int idx = -1;
    if (*(int*)(this_ + 0x16c) != -1) {
        for (;;) {
            h = fn_801F78F4(fn_801F856C(), 0x4e495741, idx);
            idx = h;
            if (h < 0) {
                break;
            }
            char* obj = (char*)fn_801F666C(fn_801F856C(), h);
            if (obj == 0) {
                continue;
            }
            if (*(int*)(obj + 0x198) == *(int*)(this_ + 0x198)) {
                continue;
            }
            if (*(int*)(obj + 0x16c) != *(int*)(this_ + 0x16c)) {
                continue;
            }
            if (fn_801F6758(obj + 0xc, *(int*)(obj + 0x4), lbl_80541EEC) != 0) {
                if (*(unsigned char*)(obj + 0xc4) != 1) {
                    continue;
                }
            }
            *(unsigned char*)(this_ + 0x11c) = 0;
            break;
        }
    }
}

extern "C" void fn_80333148(char* this_) {
    extern unsigned char* lbl_8053AAF8;
    extern char* fn_802D6A9C(void);
    extern int fn_80138A30(unsigned char* a);
    extern int fn_801EEC98(char* a, void* h, u16* p5, int p6, int p7, s32* p8, int p9, int p10);
    extern void fn_8023061C(int a);
    extern unsigned char fn_8022F9E4(int idx, int a0, unsigned char a1, unsigned char a2);

    struct VT14 {
        virtual void s00();
        virtual void s01();
        virtual void s02();
        virtual void s03();
        virtual void s04();
        virtual void s05();
        virtual void s06();
        virtual void s07();
        virtual void s08();
        virtual void s09();
        virtual void s10();
        virtual u8 s11();
        virtual void s12();
        virtual void s13();
    };

    s32 idx;
    s32 local_18;
    u16 local_8 = 0;
    char* obj = this_;

    *(float*)(this_ + 0x60) = -7.0f;
    *(float*)(this_ + 0x64) = -7.0f;
    *(float*)(this_ + 0x68) = 7.0f;
    *(float*)(this_ + 0x6c) = 7.0f;
    *(float*)(this_ + 0x80) = -7.0f;
    *(float*)(this_ + 0x84) = -7.0f;
    *(float*)(this_ + 0x88) = 7.0f;
    *(float*)(this_ + 0x8c) = 7.0f;
    *(s32*)(this_ + 0x254) = 0;
    *(s32*)(this_ + 0x258) = 0;
    *(s32*)(this_ + 0x25c) = 0;
    *(s32*)(this_ + 0x260) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(u16*)(this_ + 0x94) = (*(u32*)(this_ + 0x90) >> 4) & 0xf;
    *(s32*)(this_ + 0x25c) = (*(u32*)(this_ + 0x90) >> 8) & 3;
    this_[0x2a1] = (*(u32*)(this_ + 0x90) >> 12) & 1;
    this_[0x2a2] = (*(u32*)(this_ + 0x90) >> 13) & 1;
    this_[0x2a3] = (*(u32*)(this_ + 0x90) >> 15) & 1;
    this_[0x2a7] = (*(u32*)(this_ + 0x90) >> 14) & 1;
    this_[0x2a8] = 0;
    if (((VT14*)this_)->s11() == 1) {
        obj[0x2a7] = 0;
    }
    obj[0x2a4] = 1;
    obj[0x2a5] = 1;
    *(s32*)(obj + 0x290) = *(u32*)(obj + 0x90) & 0xf;
    *(s32*)(obj + 0x108) = 1000;
    *(s32*)(obj + 0x264) = 0;
    *(s32*)(obj + 0x26c) = 0;
    *(float*)(obj + 0x2d0) = *(float*)(obj + 0xc);
    *(float*)(obj + 0x2d4) = *(float*)(obj + 0x10);
    *(float*)(obj + 0x2d8) = *(float*)(obj + 0x14);
    *(u32*)(lbl_8053AAF8 + 0xb4) = *(u32*)(lbl_8053AAF8 + 0xb4) * 0x19660d + 0x3c6ef35f;
    {
        u32 a = (*(u32*)(lbl_8053AAF8 + 0xb4) >> 9) | 0x3f800000;
        *(s16*)(obj + 0x29c) = 65536.0f * (*(float*)&a - 1.0f);
    }
    *(s16*)(obj + 0x29e) = 0;
    obj[0x288] = (u8)0xff;
    *(float*)(obj + 0x2b0) = 0.0f;
    *(s32*)(obj + 0x2ac) = 0;
    *(s32*)(obj + 0x298) = 0;
    *(s32*)(obj + 0x270) = 0;
    *(s32*)(obj + 0x274) = 0;
    *(s32*)(obj + 0x278) = 0;
    *(s32*)(obj + 0x27c) = 50;
    *(s32*)(obj + 0x280) = 0;
    *(Vec*)(obj + 0x2dc) = *(Vec*)(obj + 0xc);
    *(s32*)(obj + 0x294) = *(s32*)(obj + 4);
    *(s32*)(obj + 0x268) = 10;
    *(s32*)(obj + 0x2f4) = 0;
    *(s32*)(obj + 0x2f8) = 0;
    *(s32*)(obj + 0x2fc) = 0;
    *(s32*)(obj + 0x300) = 0;
    obj[0x2a0] = 1;
    obj[0x2a9] = 1;
    *(float*)(obj + 0x2b4) = 0.3f;
    *(s32*)(obj + 0x28c) = 1;
    if (lbl_8053AAF8[0x7f] == 0) {
        *(s32*)(obj + 0x28c) = 4;
    }
    {
        s32 n = fn_80138A30(lbl_8053AAF8);
        s32 shift = 0;
        for (; n > 0; n--) {
            if (((lbl_8053AAF8[0x83] >> shift) & 3) == 2) {
                obj[0x2a0] = 0;
                break;
            }
            shift += 2;
        }
    }
    obj[0x2a6] = 0;
    *(float*)(obj + 0x2b8) = 0.0f;
    *(float*)(obj + 0x2bc) = 0.0f;
    *(float*)(obj + 0x2c0) = 0.0f;
    *(float*)(obj + 0x3c) = 0.0f;
    *(float*)(obj + 0x40) = 0.0f;
    *(float*)(obj + 0x44) = 0.0f;
    *(float*)(obj + 0x2cc) = 0.0f;
    *(float*)(obj + 0x2c8) = 0.0f;
    *(float*)(obj + 0x2c4) = 0.0f;
    *(float*)(obj + 0x184) = 20.0f;
    *(s32*)(obj + 0x284) = 0;
    *(Vec*)(obj + 0x2e8) = *(Vec*)(obj + 0xc);
    *(float*)(obj + 0x2f0) = *(float*)(obj + 0x14);

    switch (*(s32*)(obj + 0x290)) {
    case 1: {
        fn_801EEC98(obj, *(void**)(obj + 0x198), &local_8, 0, 0, &local_18, 0, *(s32*)(obj + 0x28c));
        *(s32*)(obj + 0x240) = 10;
        if (local_18 == -1) {
            char* m = fn_802D6A9C();
            float y = 0.5f * (*(float*)(m + 0xcc) - *(float*)(m + 0xd4)) + *(float*)(m + 0xd4) - *(float*)(obj + 0xc);
            float x = 0.5f * (*(float*)(m + 0xd0) - *(float*)(m + 0xd8)) + *(float*)(m + 0xd8) - *(float*)(obj + 0x10);
            local_8 = JMath::atanTable_.atan2_(y, x) * 10430.378f;
            *(float*)(obj + 0x2b8) = 3.0f * JMath::sincosTable_.mTable[local_8 >> 5].first;
            *(float*)(obj + 0x2bc) = 3.0f * JMath::sincosTable_.mTable[local_8 >> 5].second;
            *(s32*)(obj + 0x98) = (*(float*)(obj + 0x2b8) >= 0.0f) ? 1 : 0;
            obj[0x2a6] = 1;
            *(s32*)(obj + 0x230) = 7;
        } else {
            *(s32*)(obj + 0x290) = 1;
            *(s32*)(obj + 0x240) = 1000;
            *(s32*)(obj + 0x230) = 6;
        }
        break;
    }
    case 2:
    case 3:
    case 8:
        *(s32*)(obj + 0x230) = 3;
        break;
    case 4:
        *(s32*)(obj + 0xb8) = 2;
        *(s32*)(obj + 0x290) = 0;
        fn_8023061C(*(s32*)(obj + 0x25c));
        idx = *(s32*)(obj + 0x25c);
    case 5:
        if (fn_8022F9E4(idx, *(s32*)(obj + 0x198), 0, 0) == 1) {
            *(s32*)(obj + 0x230) = 3;
        } else {
            *(s32*)(obj + 0x230) = 2;
        }
        break;
    case 6:
    case 7:
    default:
        *(s32*)(obj + 0x230) = 0;
        *(s32*)(obj + 0xb8) = 2;
        if (*(s32*)(obj + 0x290) == 7) {
            *(s32*)(obj + 0x290) = 6;
            *(s32*)(obj + 0x230) = 1;
            if (obj[0x2a2] == 1) {
                u32 a = (*(u32*)(lbl_8053AAF8 + 0xb4) * 0x19660d + 0x3c6ef35f);
                *(u32*)(lbl_8053AAF8 + 0xb4) = a;
                a = (a >> 9) | 0x3f800000;
                *(s32*)(obj + 0x240) = (s32)(200.0f * (*(float*)&a - 1.0f)) + 0xc8;
            } else {
                u32 a = (*(u32*)(lbl_8053AAF8 + 0xb4) * 0x19660d + 0x3c6ef35f);
                *(u32*)(lbl_8053AAF8 + 0xb4) = a;
                a = (a >> 9) | 0x3f800000;
                *(s32*)(obj + 0x240) = (s32)(100.0f * (*(float*)&a - 1.0f)) + 0x64;
            }
        }
        break;
    }
}

extern "C" void* fn_803336B0(char* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AB8C0;
        fn_801EE434(*(void**)(this_ + 0x2f4));
        fn_801EE434(*(void**)(this_ + 0x2f8));
        fn_801EE434(*(void**)(this_ + 0x2fc));
        fn_801EE434(*(void**)(this_ + 0x300));
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" char lbl_805091F8[];
extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __register_global_object(void*, void (*)(void*), void*);
extern "C" char memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[];
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" char memPool___30JASPoolAllocObject_9JAIStream[];
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*);
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" char memPool___35JASPoolAllocObject_13JAISoundChild[];
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" char memPool___27JASPoolAllocObject_6JAISeq[];
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*);
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" char memPool___26JASPoolAllocObject_5JAISe[];
extern "C" void __dt__18JASMemPool_5JAISeFv(void*);
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;
extern "C" void fn_80333734(void) {
    if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, lbl_805091F8 + 0x0);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, lbl_805091F8 + 0xc);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, lbl_805091F8 + 0x18);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, lbl_805091F8 + 0x24);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, lbl_805091F8 + 0x30);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, lbl_805091F8 + 0x3c);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, lbl_805091F8 + 0x48);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, lbl_805091F8 + 0x54);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, lbl_805091F8 + 0x60);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}

