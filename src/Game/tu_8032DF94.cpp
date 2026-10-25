#include "Game/Actor.h"
#include "Game/ItemBase.h"
extern "C" double sin(double);
extern "C" double cos(double);
extern "C" f32 lbl_80541E44;
extern "C" s32 lbl_804AB810[];
extern "C" char lbl_80471A50[];
extern "C" void* lbl_8053AB10;
extern "C" void fn_802F86CC(void*, void*, void*, s32, DrawRec*, f32, f32);
extern "C" void fn_801F06F0(Actor*, void*, s32, DrawRec*, s32, f32, f32);
extern "C" void fn_803075AC(void*, s32, void*, s32, s32, s32, s32, s32, s32, s32);
struct FsaResourceManager {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void* getResource(u32, const char*);
};


extern "C" char lbl_804AB850[];
extern "C" void fn_801EE434(void*);
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" u32 fn_8022461C(void*);
extern "C" float lbl_80541E40;
struct JMathSinCos { f32 sin; f32 cos; };
extern "C" const JMathSinCos sincosTable___5JMath[];
extern "C" void* lbl_8053AAF8;
extern "C" void fn_801F71A4(void* v, f32 target, f32 a, f32 b);
extern "C" s32 fn_8023AF14(f32* box, u32 room, f32 z, u32 c);
extern "C" void fn_801EEC98(Actor* p, void* h, u16* a, s32* b, f32* c, s32* d, u32 e, u32 f);
extern "C" u8 fn_801F2618(Actor* p, u32 a, u32 b);
extern "C" void* fn_8023E724(s32 i);
extern "C" u8 fn_80234ECC(s32 i);
extern "C" void fn_802362C4(s32 i, void* f);
extern "C" u8 fn_8023F264(s32 i);
extern "C" s32 fn_8013CC50(u32 id, void* p, f32 f, u32 a, u32 b, u32 c, u32 d, u32 e, u32 g);
extern "C" void fn_801F0E34(Actor* a, u32 code, u32 z);
extern "C" void* lbl_804AB830[];
extern "C" void fn_8032DF94(Actor* p) {
    DrawRec rec;
    f32 m[3][4];
    u8* self = (u8*)p;
    s32 id;
    f32 ss;
    f32 cz;
    f32 cs, a0, a1, a2, a3, a4, a5, a6, a7, a8;
    f32 cc;
    f32 sx;
    f32 sy;
    f32 sz;
    f32 cx;
    f32 cy;
    f32 angle;
    f32 scale;
    rec.b2d = 1;
    rec.b1d = 1;
    s32 state = *(s32*)(self + 0x230);
    if (state == 5 || state == 6) {
        m[0][3] = lbl_80541E40;
        m[1][3] = lbl_80541E40;
        m[2][3] = lbl_80541E40;
        angle = *(f32*)(self + 0x23c);
        scale = *(f32*)(self + 0x238);
        sx = sin(lbl_80541E40);
        sy = sin(angle);
        sz = sin(lbl_80541E40);
        cx = cos(lbl_80541E40);
        cy = cos(angle);
        cz = cos(lbl_80541E40);
        rec.w18 = m;
        cc = cx * cz;
        ss = sx * sy;
        cs = cx * sz;
        a0 = cy * cz;
        a1 = cy * sz;
        a2 = -sy;
        a3 = ss * cz - cs;
        a4 = ss * sz + cc;
        a5 = sx * cy;
        a6 = cc * sy + sx * sz;
        a7 = cs * sy - sx * cz;
        a8 = cx * cy;
        m[0][0] = scale * a0;
        m[1][0] = scale * a1;
        m[2][0] = scale * a2;
        m[0][1] = scale * a3;
        m[1][1] = scale * a4;
        m[2][1] = scale * a5;
        m[0][2] = scale * a6;
        m[1][2] = scale * a7;
        m[2][2] = scale * a8;
        id = *(s32*)(self + 0x24c) + lbl_804AB810[*(s32*)(self + 0x264)];
        if (*(s32*)(self + 4) < 8) {
            void* res = ((FsaResourceManager*)*(void**)((u8*)lbl_8053AAF8 + 0xa4))->getResource(0x534f4220, lbl_80471A50);
            fn_802F86CC(*(void**)((u8*)lbl_8053AB10 + 0x20), self + 0xc, res, id, &rec, lbl_80541E44, lbl_80541E44);
        }
        return;
    }
    if (state != 2) {
        s32 flags = 2;
        if (*(s32*)(self + 0x264) >= 4) flags = 0;
        rec.b1d = 1;
        if (*(f32*)(self + 0x14) != lbl_80541E40) rec.b1c = 1;
        id = *(s32*)(self + 0x24c) + lbl_804AB810[*(s32*)(self + 0x264)];
        fn_801F06F0(p, lbl_80471A50, id, &rec, flags, lbl_80541E44, lbl_80541E44);
    } else {
        rec.b2d = 1;
        id = *(s32*)(self + 0x24c) + lbl_804AB810[*(s32*)(self + 0x264)];
        if (*(s32*)(self + 4) < 8) {
            void* res = ((FsaResourceManager*)*(void**)((u8*)lbl_8053AAF8 + 0xa4))->getResource(0x534f4220, lbl_80471A50);
            fn_802F86CC(*(void**)((u8*)lbl_8053AB10 + 0x20), self + 0xc, res, id, &rec, lbl_80541E44, lbl_80541E44);
        }
    }
    fn_803075AC(*(void**)(self + 0x198), *(s32*)(self + 4), self + 0xc,
        *(s32*)(self + 0x24c) + lbl_804AB810[*(s32*)(self + 0x264)], 0, 2, -1, 0, 0, 0);
}

extern "C" void fn_8032E3BC(Actor* p) {
    u8 flag = 0;
    u16 s8 = 0;
    s32 i18 = 0;
    f32 f14 = 0.0f;
    s32 i1c = 0;
    f32 box[4];
    f32 y = *(f32*)((char*)p + 0x10);
    f32 x = *(f32*)((char*)p + 0xc);
    if (*(u16*)((char*)p + 0x94) != 6) {
        fn_801F71A4((char*)p + 0x3c, *(f32*)((char*)p + 0x26c), 0.3f, 1.0f);
        fn_801F71A4((char*)p + 0x40, *(f32*)((char*)p + 0x270), 0.3f, 1.0f);
    }
    *(f32*)((char*)p + 0xc) += *(f32*)((char*)p + 0x3c);
    *(f32*)((char*)p + 0x10) += *(f32*)((char*)p + 0x40);
    *(f32*)((char*)p + 0x14) += *(f32*)((char*)p + 0x44);
    box[0] = *(f32*)((char*)p + 0x60);
    f32 b0 = box[0] + x;
    box[1] = *(f32*)((char*)p + 0x64);
    f32 b1 = box[1] + y;
    box[2] = *(f32*)((char*)p + 0x68);
    f32 b2 = box[2] + x;
    box[3] = *(f32*)((char*)p + 0x6c);
    f32 b3 = box[3] + y;
    box[0] = b0;
    box[1] = b1;
    box[2] = b2;
    box[3] = b3;
    switch (*(s32*)((char*)p + 0x230)) {
    case 0:
    case 3:
        break;
    case 4: {
        s32 r29 = fn_8023AF14(box, *(u32*)((char*)p + 0x4), *(f32*)((char*)p + 0x14), 0);
        if (*(s32*)((char*)p + 0x230) != 0) {
            fn_801EEC98(p, *(void**)((char*)p + 0x198), &s8, &i18, &f14, &i1c, 0, 0);
            if (*(u16*)((char*)p + 0x94) == 6 && *(f32*)((char*)p + 0x14) == 0.0f) {
                flag = fn_801F2618(p, 0, 0);
            }
        }
        if (r29 >= 0) {
            u16 sub = *(u16*)((char*)p + 0x94);
            if (sub != 5 && sub != 6 && !(((f32*)fn_8023E724(r29))[2] >= 20.0f)) {
                if (fn_80234ECC(r29)) {
                    fn_802362C4(r29, lbl_804AB830[*(s32*)((char*)p + 0x264)]);
                    *(s32*)((char*)p + 0x260) = r29;
                    *(s32*)((char*)p + 0x230) = 1;
                }
            }
        }
        break;
    }
    }
    switch (*(s32*)((char*)p + 0x230)) {
    case 0:
        fn_801F71A4((char*)p + 0x14, 24.0f + 4.0f * sincosTable___5JMath[(u16)*(s32*)((char*)p + 0x250) >> 5].sin, 0.3f, 1.0f);
        {
            char* g = (char*)lbl_8053AAF8;
            u32 s = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
            *(u32*)(g + 0xb4) = s;
            u32 b = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
            *(s32*)((char*)p + 0x250) += (s32)(256.0f * (*(f32*)&b - 1.0f)) + 0x200;
        }
        {
            u16 sub = *(u16*)((char*)p + 0x94);
            if (sub == 1 || sub == 2) {
                if (*(s32*)((char*)p + 0x244) == 0) {
                    switch (*(s32*)((char*)p + 0x98)) {
                    case 0:
                        *(f32*)((char*)p + 0x26c) = 0.3f;
                        *(f32*)((char*)p + 0x270) = 0.0f;
                        *(f32*)((char*)p + 0x274) = 0.0f;
                        break;
                    case 1:
                        *(f32*)((char*)p + 0x26c) = -0.3f;
                        *(f32*)((char*)p + 0x270) = 0.0f;
                        *(f32*)((char*)p + 0x274) = 0.0f;
                        break;
                    case 2:
                        *(f32*)((char*)p + 0x26c) = 0.0f;
                        *(f32*)((char*)p + 0x270) = 0.3f;
                        *(f32*)((char*)p + 0x274) = 0.0f;
                        break;
                    case 3:
                        *(f32*)((char*)p + 0x26c) = 0.0f;
                        *(f32*)((char*)p + 0x270) = -0.3f;
                        *(f32*)((char*)p + 0x274) = 0.0f;
                        break;
                    }
                    *(s32*)((char*)p + 0x244) = 500;
                    *(s32*)((char*)p + 0x98) ^= 1;
                }
            } else if (sub == 3 || sub == 4) {
                *(s32*)((char*)p + 0x254) += *(s32*)((char*)p + 0x258);
                *(f32*)((char*)p + 0xc) = *(f32*)((char*)p + 0x234) * sincosTable___5JMath[(u16)*(s32*)((char*)p + 0x254) >> 5].sin + *(f32*)((char*)p + 0x278);
                *(f32*)((char*)p + 0x10) = *(f32*)((char*)p + 0x234) * sincosTable___5JMath[(u16)*(s32*)((char*)p + 0x254) >> 5].cos + *(f32*)((char*)p + 0x27c);
            }
        }
        break;
    case 1:
        *(f32*)((char*)p + 0x44) = 0.0f;
        *(f32*)((char*)p + 0x40) = 0.0f;
        *(f32*)((char*)p + 0x3c) = 0.0f;
        *(f32*)((char*)p + 0x14) = 0.0f;
        *(s32*)((char*)p + 0x240) = 0;
        *(s32*)((char*)p + 0x244) = 30;
        *(f32*)((char*)p + 0x44) = 3.0f;
        *(s32*)((char*)p + 0x230) = 2;
        /* fallthrough */
    case 2:
        *(f32*)((char*)p + 0x44) -= 0.5f;
        if (*(f32*)((char*)p + 0x14) <= 0.0f && *(f32*)((char*)p + 0x44) < 0.0f) {
            *(f32*)((char*)p + 0x44) = 0.0f;
            *(f32*)((char*)p + 0x40) = 0.0f;
            *(f32*)((char*)p + 0x3c) = 0.0f;
            *(f32*)((char*)p + 0x14) = 0.0f;
            if (fn_8023F264(*(s32*)((char*)p + 0x260))) {
                *(f32*)((char*)p + 0xc) = *(f32*)fn_8023E724(*(s32*)((char*)p + 0x260));
                *(f32*)((char*)p + 0x10) = ((f32*)fn_8023E724(*(s32*)((char*)p + 0x260)))[1] - 24.0f;
            }
            if (*(s32*)((char*)p + 0x244) == 0) {
                p->v10(0xff, 1);
                p->detach();
            }
        }
        break;
    case 3:
        if (*(f32*)((char*)p + 0x14) < 100.0f) {
            *(s32*)((char*)p + 0x244) = 0;
            *(s32*)((char*)p + 0x230) = 4;
        }
        break;
    case 4:
        if (*(f32*)((char*)p + 0x14) > 0.0f) {
            *(f32*)((char*)p + 0x44) -= 0.3f;
        } else if (*(u16*)((char*)p + 0x94) == 6) {
            *(u16*)((char*)p + 0x94) = 5;
            *(f32*)((char*)p + 0x14) = 0.0f;
            *(f32*)((char*)p + 0x44) = 0.0f;
            if (*(f32*)&f14 >= 120.0f) {
                *(f32*)((char*)p + 0x26c) = 0.0f;
                *(f32*)((char*)p + 0x270) = 0.0f;
                *(f32*)((char*)p + 0x274) = 0.0f;
                *(s32*)((char*)p + 0x230) = 3;
            }
        }
        break;
    }
    if (*(s32*)((char*)p + 0x248) <= 0 && *(s32*)((char*)p + 0x284) == 0) {
        *(s32*)((char*)p + 0x284) = fn_8013CC50(*(u32*)((char*)p + 0x4), (char*)p + 0xc, 1.0f, 0x3d0, 0, 1, 0, 0, 1);
        fn_801F0E34(p, 0x30022, 0);
    }
    *(f32*)((char*)p + 0x23c) += 0.1f;
    *(f32*)((char*)p + 0x238) -= 0.01f;
    if (*(f32*)((char*)p + 0x238) < 0.1f) {
        if (*(s32*)((char*)p + 0x230) == 6 && *(s32*)((char*)p + 0x284) != 0) {
            *(s32*)(*(s32*)((char*)p + 0x284) + 0xf4) |= 1;
            *(s32*)(*(s32*)((char*)p + 0x284) + 0x24) = 1;
            p->detach();
        }
    }
    if (*(s32*)((char*)p + 0x240) > 0) {
        *(s32*)((char*)p + 0x240) -= 1;
    }
    if (*(s32*)((char*)p + 0x244) > 0) {
        *(s32*)((char*)p + 0x244) -= 1;
    }
    if (*(s32*)((char*)p + 0x248) > 0) {
        *(s32*)((char*)p + 0x248) -= 1;
    }
}

extern "C" u32 fn_8032EB28(char* p, void* a, void* b) {
    int t = (u16)fn_8022461C(b);
    if (t == 12 || t == 3 || t == 14) {
        *(float*)(p + 0x3c) = *(float*)(p + 0x40) = *(float*)(p + 0x44) = 0.0f;
        *(s32*)(p + 0x230) = 5;
        return 0;
    }
    if (t == 13) {
        *(s32*)(p + 0x248) = 0;
        *(float*)(p + 0x3c) = *(float*)(p + 0x40) = *(float*)(p + 0x44) = 0.0f;
        *(s32*)(p + 0x230) = 6;
        return 0;
    }
    return t != 0;
}

extern "C" void fn_8032EBD0(Actor* p) {
    *(u16*)((char*)p + 0x94) = (*(u32*)((char*)p + 0x90) >> 16) & 0xff;
    *(s32*)((char*)p + 0x264) = *(u32*)((char*)p + 0x90) & 7;
    *(s32*)((char*)p + 0x284) = 0;
    *(s32*)((char*)p + 0x24c) = 0;
    *(s32*)((char*)p + 0x250) = 0;
    *(s32*)((char*)p + 0x254) = 0;
    *(s32*)((char*)p + 0x258) = 0;
    *(s32*)((char*)p + 0x240) = 0;
    *(s32*)((char*)p + 0x244) = 0;
    *(s32*)((char*)p + 0x248) = 0;
    *(u16*)((char*)p + 0x268) = 0;
    *(s32*)((char*)p + 0x108) = 10000;
    *(s32*)((char*)p + 0x25c) = 0;
    *(s32*)((char*)p + 0x260) = -1;
    *(s32*)((char*)p + 0x98) = 0;
    *(f32*)((char*)p + 0x278) = *(f32*)((char*)p + 0xc);
    *(f32*)((char*)p + 0x27c) = *(f32*)((char*)p + 0x10);
    *(f32*)((char*)p + 0x280) = *(f32*)((char*)p + 0x14);
    *(s32*)((char*)p + 0x258) = 100;
    *(f32*)((char*)p + 0x238) = 1.0f;
    *(f32*)((char*)p + 0x23c) = 0.0f;
    if ((u8)p->v11()) {
        p->detach();
        return;
    }
    *(f32*)((char*)p + 0x234) = 30.0f;
    *(s32*)((char*)p + 0x230) = 0;
    {
        char* g = (char*)lbl_8053AAF8;
        u32 s = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
        *(u32*)(g + 0xb4) = s;
        u32 b = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
        *(s32*)((char*)p + 0x254) = (s32)(65535.0f * (*(f32*)&b - 1.0f));
    }
    switch (*(u16*)((char*)p + 0x94)) {
    case 1:
        *(f32*)((char*)p + 0x14) = 24.0f;
        *(s32*)((char*)p + 0x98) = 2;
        {
            char* g = (char*)lbl_8053AAF8;
            u32 s = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
            *(u32*)(g + 0xb4) = s;
            u32 b = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
            *(s32*)((char*)p + 0x98) |= (s32)(1.99f * (*(f32*)&b - 1.0f));
        }
        break;
    case 2:
        *(f32*)((char*)p + 0x14) = 24.0f;
        {
            char* g = (char*)lbl_8053AAF8;
            u32 s = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
            *(u32*)(g + 0xb4) = s;
            u32 b = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
            *(s32*)((char*)p + 0x98) |= (s32)(1.99f * (*(f32*)&b - 1.0f));
        }
        break;
    case 3:
        *(s32*)((char*)p + 0x258) = -100;
        /* fallthrough */
    case 4:
        *(f32*)((char*)p + 0x14) = 24.0f;
        *(f32*)((char*)p + 0xc) = *(f32*)((char*)p + 0x234) * sincosTable___5JMath[(u16)*(s32*)((char*)p + 0x254) >> 5].sin + *(f32*)((char*)p + 0x278);
        *(f32*)((char*)p + 0x10) = *(f32*)((char*)p + 0x234) * sincosTable___5JMath[(u16)*(s32*)((char*)p + 0x254) >> 5].cos + *(f32*)((char*)p + 0x27c);
        break;
    case 6:
        *(s32*)((char*)p + 0x230) = 4;
        break;
    case 5:
        *(s32*)((char*)p + 0x230) = 3;
        break;
    }
    *(f32*)((char*)p + 0x26c) = 0.0f;
    *(f32*)((char*)p + 0x270) = 0.0f;
    *(f32*)((char*)p + 0x274) = 0.0f;
    *(f32*)((char*)p + 0x3c) = 0.0f;
    *(f32*)((char*)p + 0x40) = 0.0f;
    *(f32*)((char*)p + 0x44) = 0.0f;
    *(f32*)((char*)p + 0x80) = -8.0f;
    *(f32*)((char*)p + 0x84) = -8.0f;
    *(f32*)((char*)p + 0x88) = 8.0f;
    *(f32*)((char*)p + 0x8c) = 8.0f;
    *(f32*)((char*)p + 0x60) = -4.0f;
    *(f32*)((char*)p + 0x64) = -4.0f;
    *(f32*)((char*)p + 0x68) = 4.0f;
    *(f32*)((char*)p + 0x6c) = 4.0f;
}

extern "C" Actor* fn_8032EEB8(Actor* p, s16 n) {
    if (p != NULL) {
        *(void**)p = lbl_804AB850;
        fn_801EE434(*(void**)((char*)p + 0x284));
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}


