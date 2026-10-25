#include "types.h"
#include "Game/SinitPoolChain.h"
#include "Game/ItemBase.h"
#include "JSystem/JGeometry/Vec.h"

struct Box4 {
    f32 a, b, c, d;
};

struct Vec3f {
    f32 x, y, z;
};

extern "C" u8 fn_801F2B7C(void* this_, s32 a, s32 b, s32 c);
extern f32 lbl_804A0AD8[];
extern Box4 lbl_804A0B10[];
extern const f32 lbl_8053DAC0;
extern const f32 lbl_8053DAC8;
extern "C" s32 fn_801F285C(void* this_, s32 a, s32 b, s32 c, s32 d);
extern "C" void fn_801EF510(void* this_);
extern "C" u8 fn_80235448(void);
extern "C" u8 fn_80237948(s32 idx, f32* pos);
extern "C" void fn_80230FD0(s32 idx, s32 id);
extern "C" s32 fn_8013CC50(u32 id, void* pos, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, f32 g);
extern "C" void* fn_802D6A9C(void);
extern Box4 lbl_804A0A58[];
extern const f32 lbl_8053DB48;

extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void* base, u32 fourCC, u32 owner, void* posPtr, s32 a, s32 b, s32 c);
extern "C" void* fn_801F666C(void* base, s32 id);
extern "C" s32 fn_8023DE58(s32 a);
extern u8 lbl_80529DEC[];
extern const f32 lbl_8053DB4C;
extern const f32 lbl_8053DB00;
extern const f32 lbl_8053DB04;
extern const f32 lbl_8053DB20;
extern const f32 lbl_8053DB24;
extern const f32 lbl_8053DB28;
extern const f32 lbl_8053DB2C;
extern const f32 lbl_8053DB30;
extern const f32 lbl_8053DB34;
extern const f32 lbl_8053DB38;
extern const f32 lbl_8053DB3C;
extern const f32 lbl_8053DB40;
extern const f32 lbl_8053DB44;
extern const f32 lbl_8053DACC;
extern const f32 lbl_8053DAD0;
extern s32 lbl_804A0AF8[];
extern u8 lbl_80539F78[8];
extern "C" u8 fn_802DE814(void);
extern "C" void fn_801746DC(void* this_);
extern u8 lbl_8053AB60;
extern const f32 lbl_8053DAB8;
extern const f32 lbl_8053DABC;
extern const f32 lbl_8053DAC0;
extern char lbl_80466808[];
extern "C" void fn_80172BC8(void* this_);
extern "C" void fn_801F02BC(void* this_, char* name, s32 id, DrawRec* rec, s32 a, s32 b, s32 c, f32 s0, f32 s1);
extern "C" void fn_801EF574(void* a, void* b, f32* v, DrawRec* rec);
extern "C" void fn_803075AC(void*, s32, void*, s32, s32, s32, s32, s32, s32, s32);
struct PukuResMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* get(u32 type, const char* name);
};
struct PukuGameRes {
    u8 pad[0xa4];
    PukuResMgr* res;
};
extern "C" void fn_802F86CC(void* layer, void* pos, void* res, s32 id, f32 sx, f32 sy, DrawRec* rec);
extern void* lbl_8053AAF8;
extern u8* lbl_8053AB10;
extern const f32 lbl_8053DAB8;
extern const f32 lbl_8053DABC;
extern const f32 lbl_8053DAC0;
extern char lbl_80466808[];
extern "C" void v07__5ActorFv(void* this_);
extern "C" void fn_80172894(void* this_) {
    char* p = (char*)this_;
    if ((s32)(*(u32*)(p + 0x90) & 0xff) == 6) {
        *(s32*)(p + 0x18c) = 0;
        Actor_CreateByID(fn_801F856C(), 0x48415254, *(u32*)(p + 0x4), p + 0xc, 0, -1, -1);
    }
    v07__5ActorFv(this_);
}

extern "C" void fn_80172900(void* this_) {
    char* p = (char*)this_;
    DrawRec rec;
    f32 mtx[3][4];
    Vec3f v;

    mtx[0][3] = lbl_8053DAB8;
    mtx[1][3] = lbl_8053DAB8;
    mtx[2][3] = lbl_8053DAB8;
    if (lbl_8053AB60 != 1) {
        s32 mode = *(u32*)(p + 0x90) & 0xff;
        if (mode == 7 || mode == 8) {
            fn_80172BC8(this_);
        } else {
            BOOL bVar1 = 0;
            rec.ids[1] = *(u8*)(p + 0x234);
            if (*(s32*)(p + 0x230) == 6 && *(s32*)(p + 0x264) >= 3) {
                rec.w30 = 0x11;
            }
            if (*(s32*)(p + 0x4) >= 8) {
                if (*(s32*)(p + 0x23c) == 1) {
                    bVar1 = 1;
                    mtx[0][0] = lbl_8053DABC;
                    mtx[0][1] = lbl_8053DAB8;
                    mtx[0][2] = lbl_8053DAB8;
                    mtx[1][0] = lbl_8053DAB8;
                    mtx[1][1] = lbl_8053DABC;
                    mtx[1][2] = lbl_8053DAB8;
                    mtx[2][0] = lbl_8053DAB8;
                    mtx[2][1] = lbl_8053DAB8;
                    mtx[2][2] = lbl_8053DABC;
                    rec.w18 = mtx;
                }
                {
                    Box4 box = *(Box4*)((char*)fn_802D6A9C() + 0xcc);
                    v.x = *(f32*)(p + 0xc) + box.a;
                    v.y = *(f32*)(p + 0x10) + box.b;
                    v.z = *(f32*)(p + 0x14);
                }
                if ((*(u32*)(p + 0x90) & 0xff) != 6) {
                    fn_801EF574(lbl_80466808, (void*)(*(s32*)(p + 0x280) + 0x226), (f32*)&v, &rec);
                }
                fn_803075AC(*(void**)(p + 0x198), *(s32*)(p + 0x4), p + 0xc, *(s32*)(p + 0x280) + 0x318, bVar1, 2, -1, 0, 0, 0);
            } else {
                fn_801F02BC(this_, lbl_80466808, *(s32*)(p + 0x280) + 0x226, &rec, 7, 0, 0, lbl_8053DAC0, lbl_8053DAC0);
            }
        }
    }
}

extern "C" void fn_80172BC8(void* this_) {
    char* p = (char*)this_;
    DrawRec rec;
    f32 mtx[3][4];
    mtx[0][3] = lbl_8053DAB8;
    mtx[1][3] = lbl_8053DAB8;
    mtx[2][3] = lbl_8053DAB8;
    if (*(u32*)(p + 0x90) != 7) {
        mtx[0][0] = lbl_8053DABC;
        mtx[0][1] = lbl_8053DAB8;
        mtx[0][2] = lbl_8053DAB8;
        mtx[1][0] = lbl_8053DAB8;
        mtx[1][1] = lbl_8053DABC;
        mtx[1][2] = lbl_8053DAB8;
        mtx[2][0] = lbl_8053DAB8;
        mtx[2][1] = lbl_8053DAB8;
        mtx[2][2] = lbl_8053DABC;
        if (*(s32*)(p + 0x23c) == 0) {
            mtx[0][0] = lbl_8053DAC0;
            mtx[0][1] = lbl_8053DAB8;
            mtx[0][2] = lbl_8053DAB8;
            mtx[1][0] = lbl_8053DAB8;
            mtx[1][1] = lbl_8053DAC0;
            mtx[1][2] = lbl_8053DAB8;
            mtx[2][0] = lbl_8053DAB8;
            mtx[2][1] = lbl_8053DAB8;
            mtx[2][2] = lbl_8053DAC0;
        }
        rec.w18 = mtx;
    }
    s32 id = *(s32*)(p + 0x280) + 0x3fd;
    if (*(s32*)(p + 4) < 8) {
        void* res = ((PukuGameRes*)lbl_8053AAF8)->res->get('SOB ', lbl_80466808);
        fn_802F86CC(*(void**)((char*)lbl_8053AB10 + 0x20), p + 0xc, res, id, lbl_8053DAC0, lbl_8053DAC0, &rec);
    }
}

extern "C" void fn_80174220(void* this_) {
    char* p = (char*)this_;
    s32 idx = *(s32*)(p + 0x98);
    s32 n = idx;
    s32 id;
    s32 i;
    f32 ox, oy, oz;
    if ((s32)(u8)*(u32*)(p + 0x90) == 8 && *(s32*)(p + 0x23c) != 0) {
        n = idx + 4;
    }
    if (n < 4) {
        f32 x = *(f32*)(p + 0xc);
        ox = *(f32*)(p + 0xc);
        oy = *(f32*)(p + 0x10);
        oz = *(f32*)(p + 0x14);
        *(f32*)(p + 0xc) = x + lbl_804A0AD8[idx * 2];
        *(f32*)(p + 0x10) = *(f32*)(p + 0x10) + lbl_804A0AD8[*(s32*)(p + 0x98) * 2 + 1];
    }
    {
        Box4* b = &lbl_804A0B10[n];
        f32 a0 = b->a;
        f32 a1 = b->b;
        f32 a2 = b->c;
        f32 a3 = b->d;
        *(f32*)(p + 0x60) = a0;
        *(f32*)(p + 0x64) = a1;
        *(f32*)(p + 0x68) = a2;
        *(f32*)(p + 0x6c) = a3;
    }
    if (*(u16*)(p + 0x94) == 0 || *(u16*)(p + 0x94) == 2) {
        id = *(s32*)(p + 0x238);
        if (id >= 0) {
            void* obj = fn_801F666C(fn_801F856C(), id);
            if (obj != 0 && *(s32*)((char*)obj + 0xd8) == 0) {
                if (*(u16*)(p + 0x94) == 0) {
                    fn_801F2B7C(p, *(s32*)(p + 0x114), -1, 1);
                } else {
                    fn_801F2B7C(p, 4, -1, 3);
                }
            }
        }
        *(s32*)(p + 0x108) = 10000;
        fn_801EF510(p);
        for (i = 0; i < 4; i++) {
            s32 slot = fn_801F285C(p, 0, 0, 1, i);
            f32 v[2];
            if (slot < 0) continue;
            if (fn_80235448()) continue;
            {
                f32 t = lbl_8053DAC8;
                f32 py = *(f32*)(p + 0x10);
                f32 y0 = *(f32*)(p + 0x64) + py;
                f32 y1 = *(f32*)(p + 0x6c) + py;
                f32 px = *(f32*)(p + 0xc);
                f32 x0 = *(f32*)(p + 0x60) + px;
                f32 x1 = *(f32*)(p + 0x68) + px;
                v[1] = t * (y0 - y1) + y1;
                v[0] = t * (x0 - x1) + x1;
            }
            if (!fn_80237948(slot, v)) continue;
            fn_80230FD0(slot, 0x20002);
            id = *(s32*)(p + 0x238);
            if (id < 0) continue;
            {
                void* obj = fn_801F666C(fn_801F856C(), id);
                if (obj == 0) continue;
                *(s16*)((char*)obj + 0x94) = (s16)(slot + 1);
            }
            fn_8013CC50(*(u32*)(p + 4), p + 0xc, 0x473, 0, 1, 0, 0, 1, lbl_8053DAC0);
            fn_8013CC50(*(u32*)(p + 4), p + 0xc, 0x474, 0, 1, 0, 0, 1, lbl_8053DAC0);
        }
    }
    *(f32*)(p + 0xc) = ox;
    *(f32*)(p + 0x10) = oy;
    *(f32*)(p + 0x14) = oz;
}

extern "C" void* fn_801F666C(void* a, s32 b);
extern "C" void fn_801F0E34(void* this_, u32 id, s32 b);
extern "C" void fn_80458FF0(void* a, u32 b, s32 c, s32 d);
extern void* lbl_8053AAF8;
extern void* lbl_8053AF80;
extern "C" s32 fn_801F285C(void* this_, s32 a, s32 b, s32 c, s32 d);
extern "C" void fn_801EF510(void* this_);
extern "C" u8 fn_80235448(void);
extern "C" u8 fn_80237948(s32 idx, f32* pos);
extern "C" void fn_80230FD0(s32 idx, s32 id);
extern "C" s32 fn_8013CC50(u32 id, void* pos, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, f32 g);
extern f32 lbl_804A0AD8[];
extern Box4 lbl_804A0B10[];
extern const f32 lbl_8053DAC0;
extern const f32 lbl_8053DAC8;
extern "C" void fn_801744E4(void* this_) {
    char* p = (char*)this_;
    if (*(u32*)(p + 0x90) == 2 || *(u32*)(p + 0x90) == 3) {
        *(u32*)(p + 0x90) += 2;
        *(s32*)(p + 0x240) = 0;
        *(s32*)(p + 0x264) = 0;
        *(s32*)(p + 0x250) = 0x14;
        if (*(s32*)(p + 0x23c) == 0 && *(u8*)((char*)lbl_8053AAF8 + 0x7f) == 1) {
            fn_80458FF0(lbl_8053AF80, 0x1000021, 0, 0);
        }
        *(s32*)(p + 0x288) = 2;
        if (*(u8*)(p + 0x2a5) == 1) {
            fn_801F0E34(this_, 0x5001f, 0);
        }
        *(s32*)(p + 0x230) = 2;
    }
    s32 state = *(u32*)(p + 0x90) & 0xff;
    if (state != 7 && state != 8 && *(s32*)(p + 0x108) <= 0) {
        s32 idx = *(s32*)(p + 0x238);
        if (idx >= 0) {
            void* obj = fn_801F666C(fn_801F856C(), idx);
            if (obj != 0) {
                *(u8*)((char*)obj + 0x11c) = 0;
            }
        }
        *(s32*)(p + 0x238) = -1;
    }
}

extern void* lbl_804A0B90[];
extern "C" void __dt__5ActorFv(void* this_, s32 flag);
void __dl__FPv(void*);
extern "C" void fn_80138B7C(void* mgr);
extern "C" void __dl__FPv(void*);
extern "C" void* fn_80174600(void* this_, s16 flag) {
    char* p = (char*)this_;
    if (this_ != 0) {
        *(void**)this_ = lbl_804A0B90;
        s32 mode = *(u32*)(p + 0x90) & 0xff;
        if (mode != 7 && mode != 8) {
            if (mode != 6) {
                s32 st = *(s32*)((char*)lbl_8053AAF8 + 0x4c);
                if (st != 9 && st != 0xb && *(s32*)(p + 0x108) != 0) {
                    fn_80138B7C(lbl_8053AAF8);
                }
            }
            s32 id = *(s32*)(p + 0x238);
            if (id >= 0) {
                void* obj = fn_801F666C(fn_801F856C(), id);
                if (obj != 0) {
                    *(u8*)((char*)obj + 0x11c) = 0;
                }
            }
        }
        __dt__5ActorFv(this_, 0);
        if (flag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern u8 lbl_804A08C0[];
struct Slr4AnimTables {
    f32 offsets[4][2];
    s32 idle[20];
    s32 waits[4];
    s32 attack[40];
    s32 anim[24];
    s32 times[6];
    s32 idleAt(s32 n) { return idle[n]; }
    s32 waitAt(s32 n) { return waits[n]; }
    s32 attackAt(s32 n) { return attack[n]; }
    s32 animAt(s32 n) { return anim[n]; }
    s32 timeAt(s32 n) { return times[n]; }
    f32* offsetAt(s32 n) { return offsets[n]; }
};
extern const f32 lbl_8053DB10;
extern "C" void fn_801746DC(void* this_) {
    char* tbl = (char*)lbl_804A08C0;
    char* p = (char*)this_;

    if (*(s32*)(p + 0x29c) != *(s32*)(p + 0x2a0)) {
        *(s32*)(p + 0x2a0) = *(s32*)(p + 0x29c);
        *(u8*)(p + 0x2a4) = 0;
        *(s32*)(p + 0x240) = 0;
        *(s32*)(p + 0x264) = 0;
        *(s32*)(p + 0x274) = 0;
        *(s32*)(p + 0x25c) = 0;
        if (*(s32*)(p + 0x29c) == 3) {
            *(s32*)(p + 0x264) = 5;
        }
    }

    switch (*(s32*)(p + 0x29c)) {
    case 0:
        if (*(s32*)(p + 0x240) == 0) {
            s32* t = (s32*)(tbl + 0x70);
            *(s32*)(p + 0x240) = t[*(s32*)(p + 0x264)];
            t = (s32*)(tbl + 0x20);
            *(s32*)(p + 0x280) = t[*(s32*)(p + 0x98) * 4 + *(s32*)(p + 0x264)];
            *(s32*)(p + 0x264) += 1;
            *(volatile s32*)(p + 0x264) &= 3;
        }
        break;
    case 1:
        if (*(s32*)(p + 0x240) == 0) {
            s32* t = (s32*)(tbl + 0x80);
            *(s32*)(p + 0x240) = t[*(s32*)(p + 0x264)];
            *(s32*)(p + 0x280) = t[*(s32*)(p + 0x98) * 8 + *(s32*)(p + 0x264)];
            *(s32*)(p + 0x264) += 1;
            *(volatile s32*)(p + 0x264) &= 7;
            if (*(s32*)(p + 0x264) == 0) {
                *(u8*)(p + 0x2a4) = 1;
            }
        }
        break;
    case 2:
        if (*(s32*)(p + 0x240) == 0) {
            if (*(s32*)(p + 0x264) >= 6) {
                *(u8*)(p + 0x2a4) = 1;
                break;
            }
            *(s32*)(p + 0x240) = ((s32*)(tbl + 0x180))[*(s32*)(p + 0x264)];
            if (*(s32*)(p + 4) >= 8 && *(s32*)(p + 0x23c) == 1) {
                *(s32*)(p + 0x240) = (s32)(lbl_8053DAC8 * (f32)*(s32*)(p + 0x240));
            }
            if (*(s32*)(p + 0x264) == 1) {
                Vec3f pos;
                *(s32*)(p + 0x240) += 10;
                pos = *(Vec3f*)(p + 0xc);
                f32* offset = ((f32*)tbl)+*(s32*)(p+0x98)*2;
                pos.x += offset[0];
                pos.y += offset[1];
                fn_8013CC50(*(u32*)(p + 4), &pos, 0xcb, 0, 3, 0, 0, 1, lbl_8053DAC0);
                fn_8013CC50(*(u32*)(p + 4), &pos, 0xcc, 0, 3, 0, 0, 1, lbl_8053DAC0);
            }
            *(s32*)(p + 0x280) = ((s32*)(tbl + 0x120))[*(s32*)(p + 0x98) * 6 + *(s32*)(p + 0x264)];
            *(s32*)(p + 0x264) += 1;
            if (*(s32*)(p + 0x264) == 6) {
                *(s32*)(p + 0x240) += 0xf;
            }
            if (*(s32*)(p + 0x264) == 4) {
                fn_801F0E34(this_, 0x4008b, 0);
                switch (*(s32*)(p + 0x98)) {
                case 0:
                    *(f32*)(p + 0x3c) = lbl_8053DB10;
                    *(f32*)(p + 0x40) = 0.0f;
                    *(f32*)(p + 0x44) = 0.0f;
                    break;
                case 1:
                    *(f32*)(p + 0x3c) = -lbl_8053DB10;
                    *(f32*)(p + 0x40) = 0.0f;
                    *(f32*)(p + 0x44) = 0.0f;
                    break;
                case 2:
                    *(f32*)(p + 0x3c) = 0.0f;
                    *(f32*)(p + 0x40) = lbl_8053DB10;
                    *(f32*)(p + 0x44) = 0.0f;
                    break;
                case 3:
                    *(f32*)(p + 0x3c) = 0.0f;
                    *(f32*)(p + 0x40) = -lbl_8053DB10;
                    *(f32*)(p + 0x44) = 0.0f;
                    break;
                }
            }
        }
        if (*(s32*)(p + 0x25c) == 0) {
            *(s32*)(p + 0x25c) = 4;
            *(s32*)(p + 0x274) += 1;
            if (*(s32*)(p + 0x274) > 5) {
                *(s32*)(p + 0x274) = 0;
            }
        }
        break;
    case 3:
        if (*(s32*)(p + 0x240) == 0) {
            if (*(s32*)(p + 0x264) <= 0) {
                *(u8*)(p + 0x2a4) = 1;
                break;
            }
            *(s32*)(p + 0x240) = ((s32*)(tbl + 0x180))[*(s32*)(p + 0x264)];
            *(s32*)(p + 0x280) = ((s32*)(tbl + 0x120))[*(s32*)(p + 0x98) * 6 + *(s32*)(p + 0x264)];
            *(s32*)(p + 0x264) -= 1;
        }
        if (*(s32*)(p + 0x25c) == 0) {
            *(s32*)(p + 0x25c) = (6 - *(s32*)(p + 0x264)) * 2;
            *(s32*)(p + 0x274) += 1;
            if (*(s32*)(p + 0x274) > 5) {
                *(s32*)(p + 0x274) = 0;
            }
        }
        break;
    case 9:
        break;
    }
}

extern "C" void fn_80174B44(void* this_) {
    char* p = (char*)this_;
    char* rng;
    s32 mode;
    s32 room;
    s32 a;
    void* obj;
    u32 bits;

    *(f32*)(p + 0x60) = lbl_8053DB20;
    *(f32*)(p + 0x64) = lbl_8053DB24;
    *(f32*)(p + 0x68) = lbl_8053DB28;
    *(f32*)(p + 0x6c) = lbl_8053DB2C;
    *(f32*)(p + 0x80) = lbl_8053DAD0;
    *(f32*)(p + 0x84) = lbl_8053DAD0;
    *(f32*)(p + 0x88) = lbl_8053DACC;
    *(f32*)(p + 0x8c) = lbl_8053DACC;
    *(s32*)(p + 0x264) = 0;
    *(s32*)(p + 0x268) = 0;
    *(s32*)(p + 0x26c) = 0;
    *(s32*)(p + 0x270) = 0;
    *(s32*)(p + 0x274) = 0;
    *(s32*)(p + 0x278) = 0;
    *(s32*)(p + 0x27c) = 0;
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = 0;
    *(s32*)(p + 0x254) = 0;
    *(s32*)(p + 0x258) = 0;
    *(s32*)(p + 0x25c) = 0;
    *(s32*)(p + 0x260) = 0;
    *(s32*)(p + 0x2c0) = -1;
    *(s32*)(p + 0x2c4) = -1;
    *(s32*)(p + 0x2c8) = -1;
    *(s32*)(p + 0x2cc) = -1;
    *(s32*)(p + 0x278) = 3;
    *(s32*)(p + 0x298) = ((*(u32*)(p + 0x90) >> 8) & 0xf) * 0x14;
    *(s32*)(p + 0x294) = ((*(u32*)(p + 0x90) >> 12) & 0xf) * 0x14;
    *(u8*)(p + 0x2a5) = 0;
    *(s32*)(p + 0x29c) = 0;
    *(s32*)(p + 0x2a0) = 0;
    *(s32*)(p + 0x23c) = (*(u32*)(p + 0x90) >> 16) & 0xff;
    if (*(s32*)(p + 0x23c) != 0) {
        *(u8*)(p + 0x196) = 1;
        *(s32*)(p + 0x190) = 0;
    }
    *(u8*)(p + 0x2a4) = 0;
    rng = (char*)lbl_8053AAF8;
    *(u32*)(rng + 0xb4) = *(u32*)(rng + 0xb4) * 0x19660d + 0x3c6ef35f;
    bits = (*(u32*)(rng + 0xb4) >> 9) | 0x3f800000;
    *(s32*)(p + 0x98) = (s32)(lbl_8053DB30 * (*(f32*)&bits - lbl_8053DAC0)) & 3;
    *(f32*)(p + 0x2b4) = *(f32*)(p + 0xc);
    *(f32*)(p + 0x2b8) = *(f32*)(p + 0x10);
    *(f32*)(p + 0x2bc) = *(f32*)(p + 0x14);
    *(s32*)(p + 0x284) = 10000;
    *(s32*)(p + 0x238) = -1;
    mode = *(u32*)(p + 0x90) & 0xff;
    if (mode != 7 && mode != 8 && mode != 6) {
        mode = *(u32*)(p + 0x90) & 0xff;
        if (mode != 2 && mode != 3 && *(s32*)(p + 0x23c) == 0 && *(u8*)((char*)lbl_8053AAF8 + 0x7f) == 1) {
            fn_80458FF0(lbl_8053AF80, 0x1000021, 0, 0);
        }
        *(s32*)(p + 0x108) = lbl_804A0AF8[*(u32*)(p + 0x90) & 0xff] << 1;
        if (fn_802DE814() == 1) {
            *(s32*)(p + 0x108) = lbl_804A0AF8[*(u32*)(p + 0x90) & 0xff];
        }
        room = *(s32*)(p + 0x4);
        a = 7;
        if (room >= 8) {
            a = 8;
            room = 0;
        }
        *(s32*)(p + 0x238) = Actor_CreateByID(fn_801F856C(), 0x534c5234, room, p + 0xc, a, -1, -1);
        mode = *(s32*)(p + 0x238);
        if (mode >= 0) {
            obj = fn_801F666C(fn_801F856C(), mode);
            if (obj != 0) {
                *(s32*)((char*)obj + 0x114) = *(s32*)(p + 0x114);
                *(s32*)((char*)obj + 0x238) = *(s32*)(p + 0x198);
                *(s32*)((char*)obj + 0x23c) = *(s32*)(p + 0x23c);
            }
        }
    }
    mode = *(u32*)(p + 0x90) & 0xff;
    if (mode != 7 && mode != 8 && mode != 6 && *(s32*)(p + 0x4) >= 8) {
        *(s32*)(p + 0x108) = 0x32;
        if (*(s32*)(p + 0x23c) == 1) {
            *(f32*)(p + 0x60) = lbl_8053DB00;
            *(f32*)(p + 0x64) = lbl_8053DB00;
            *(f32*)(p + 0x68) = lbl_8053DB04;
            *(f32*)(p + 0x6c) = lbl_8053DB04;
        } else {
            *(s32*)(p + 0x108) = 0x19;
            *(f32*)(p + 0x60) = lbl_8053DB34;
            *(f32*)(p + 0x64) = lbl_8053DB34;
            *(f32*)(p + 0x68) = lbl_8053DB38;
            *(f32*)(p + 0x6c) = lbl_8053DB38;
            *(f32*)(p + 0x80) = lbl_8053DB34;
            *(f32*)(p + 0x84) = lbl_8053DB34;
            *(f32*)(p + 0x88) = lbl_8053DB38;
            *(f32*)(p + 0x8c) = lbl_8053DB38;
        }
    }
    *(s32*)(p + 0x284) = *(s32*)(p + 0x108);
    mode = *(u32*)(p + 0x90) & 0xff;
    if (mode != 6 && *(s32*)(p + 0x4) >= 8 && *(s32*)(p + 0x23c) == 1) {
        *(s32*)(p + 0x108) = 10000;
    }
    *(s32*)(p + 0x280) = 0;
    *(s32*)(p + 0x288) = 0;
    *(s32*)(p + 0x28c) = *(u32*)(p + 0x90) >> 24;
    if (*(s32*)(p + 0x28c) == 0) {
        *(s32*)(p + 0x28c) = -1;
    }
    *(u32*)(p + 0x90) = *(u32*)(p + 0x90) & 0xff;
    *(u8*)(p + 0x234) = lbl_80539F78[*(u32*)(p + 0x90) >> 1];
    *(f32*)(p + 0x2b0) = lbl_8053DAB8;
    *(f32*)(p + 0x2ac) = lbl_8053DAB8;
    *(f32*)(p + 0x2a8) = lbl_8053DAB8;
    *(s32*)(p + 0x290) = 0;
    *(s32*)(p + 0x244) = 10;
    *(s16*)(p + 0x236) = 0;
    *(s32*)(p + 0xb0) = 0xa042209;
    *(s32*)(p + 0xb8) = 1;
    if (*(u32*)(p + 0x90) == 2 || *(u32*)(p + 0x90) == 3) {
        *(s32*)(p + 0x98) = 3;
    }
    *(s32*)(p + 0x230) = 0;
    fn_801746DC(p);
    *(s32*)(p + 0xc0) = 3;
    *(s32*)(p + 0xbc) = 3;
    if (*(u32*)(p + 0x90) == 4 || *(u32*)(p + 0x90) == 5 || *(u32*)(p + 0x90) == 6) {
        *(s32*)(p + 0x230) = 2;
    }
    mode = *(u32*)(p + 0x90) & 0xff;
    if (mode == 7 || mode == 8) {
        *(u8*)(p + 0x1a8) = 0;
        *(s32*)(p + 0xb0) = 0xa040004;
        *(s32*)(p + 0x108) = 10000;
        *(s32*)(p + 0xb8) = 0;
        *(f32*)(p + 0x60) = lbl_8053DB3C;
        *(f32*)(p + 0x64) = lbl_8053DB3C;
        *(f32*)(p + 0x68) = lbl_8053DB40;
        *(f32*)(p + 0x6c) = lbl_8053DB40;
        *(f32*)(p + 0x80) = lbl_8053DAC0;
        *(f32*)(p + 0x84) = lbl_8053DAC0;
        *(f32*)(p + 0x88) = lbl_8053DB44;
        *(f32*)(p + 0x8c) = lbl_8053DB44;
        *(s32*)(p + 0x230) = 10;
    }
}

extern "C" void fn_80175024(void* this_) {
    char* p = (char*)this_;
    if ((s32)(*(u32*)(p + 0x90) & 0xff) != 6) {
        void* obj;
        s32 idx = *(s32*)(p + 0x238);
        if (idx >= 0) {
            obj = fn_801F666C(fn_801F856C(), idx);
            if (obj == 0) {
                s32 a = 7;
                s32 room = *(s32*)(p + 0x4);
                if (room >= 8) {
                    a = 8;
                    room = 0;
                }
                *(s32*)(p + 0x238) = Actor_CreateByID(fn_801F856C(), 0x534c5234, room, p + 0xc, a, -1, -1);
                idx = *(s32*)(p + 0x238);
                if (idx >= 0) {
                    obj = fn_801F666C(fn_801F856C(), idx);
                    if (obj != 0) {
                        *(s32*)((char*)obj + 0x114) = *(s32*)(p + 0x114);
                        *(s32*)((char*)obj + 0x238) = *(s32*)(p + 0x198);
                        *(s32*)((char*)obj + 0x23c) = *(s32*)(p + 0x23c);
                    }
                }
            } else {
                switch (*(s32*)(p + 0x29c)) {
                case 2:
                    if (*(s32*)(p + 0x264) >= 4) {
                        if (*(f32*)(p + 0x3c) < lbl_8053DB48 && *(f32*)(p + 0x40) < lbl_8053DB48) {
                            *(s16*)((char*)obj + 0x94) = 0;
                            if (*(s32*)(p + 0x4) >= 8 && *(s32*)(p + 0x23c) == 1) {
                                *(Box4*)(p + 0x60) = lbl_804A0A58[*(s32*)(p + 0x98)];
                            }
                            fn_801F2B7C(p, -100, -1, 1);
                        } else {
                            fn_801F2B7C(p, 4, -1, 3);
                            *(s16*)((char*)obj + 0x94) = 2;
                        }
                    } else {
                        *(s16*)((char*)obj + 0x94) = 1;
                    }
                case 0:
                case 1:
                case 3:
                    if (*(s32*)(p + 0x29c) != 2) {
                        *(s16*)((char*)obj + 0x94) = 0;
                    }
                    if (*(s32*)(p + 0x29c) == 3) {
                        *(s16*)((char*)obj + 0x94) = 1;
                    }
                    {
                        JGeometry::TVec3f v;
                        if (*(u32*)((char*)obj + 0x90) == 7) {
                            v.x = *(f32*)(p + 0xc);
                            v.y = *(f32*)(p + 0x10);
                            v.z = *(f32*)(p + 0x14);
                        } else {
                            s32 room = *(s32*)((char*)obj + 0x4);
                            char* base = (char*)fn_802D6A9C();
                            Box4* src;
                            if (room < 8) {
                                src = (Box4*)(base + 0xcc);
                            } else {
                                src = (Box4*)(base + 0xdc);
                            }
                            Box4 box = *src;
                            v.x = *(f32*)(p + 0xc);
                            v.y = *(f32*)(p + 0x10);
                            v.z = *(f32*)(p + 0x14);
                            v.x += box.a;
                            v.y += box.b;
                        }
                        *(JGeometry::TVec3f*)((char*)obj + 0xc) = v;
                    }
                    *(u32*)((char*)obj + 0x98) = *(u32*)(p + 0x98);
                    break;
                }
                if (*(u32*)((char*)obj + 0x90) == 8) {
                    *(s32*)((char*)obj + 0x280) = *(s32*)(p + 0x280);
                }
            }
        }
    }
}

extern "C" void fn_801752D8(void* this_) {
    char* p = (char*)this_;
    char* q;
    char* e;
    s16 rot;
    s32 cnt;
    s32 i;
    s32 n;
    if (*(s32*)(p + 0x4) >= 8 && *(s32*)(p + 0x23c) == 1 && *(s32*)(lbl_80529DEC + 0x118) == 6) {
        cnt = 0;
        q = p;
        for (i = 0; i < 4; i++, q += 4) {
            s32 id = *(s32*)(q + 0x2c0);
            if (id < 0) {
                cnt++;
            } else {
                void* a = fn_801F666C(fn_801F856C(), id);
                if (a == 0) {
                    *(s32*)(q + 0x2c0) = -1;
                    cnt++;
                } else {
                    JGeometry::TVec3f pos = *(JGeometry::TVec3f*)(p + 0xc);
                    ((JGeometry::TVec3f*)((char*)a + 0x280))->x = pos.x;
                    ((JGeometry::TVec3f*)((char*)a + 0x280))->y = pos.y;
                    ((JGeometry::TVec3f*)((char*)a + 0x280))->z = pos.z;
                    *(s32*)(p + 0x260) = 0x384;
                }
            }
        }
        if (*(s32*)(p + 0x260) == 0 && cnt == 4) {
            s32 room = *(s32*)(p + 0x4);
            if (room == fn_8023DE58(0)) {
                n = 0;
                rot = 0;
                e = p;
                for (i = 0; i < 4; i++, e += 4) {
                    *(s32*)(e + 0x2c0) = Actor_CreateByID(fn_801F856C(), 0x4b455448, *(u32*)(p + 0x4), p + 0xc, 4, -1, -1);
                    s32 id = *(s32*)(e + 0x2c0);
                    if (id >= 0) {
                        void* a = fn_801F666C(fn_801F856C(), id);
                        if (a != 0) {
                            n++;
                            *(s16*)((char*)a + 0x268) = rot;
                            *(f32*)((char*)a + 0x270) = lbl_8053DB4C;
                            if (n >= 4) {
                                *(s32*)(p + 0x260) = 0x384;
                            }
                        }
                    }
                    rot += 0x4000;
                }
            }
        }
    }
}

void __sinit_SLR4_80172894_cpp(void) {
}

