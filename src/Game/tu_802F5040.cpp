#include "types.h"
#include "JSystem/JKernel/JKRArchive.h"
#include "Game/ItemBase.h"
#include "Game/ActorDrawRec.h"
// One byte of a BG scroll register pair: high nibble, then a single bit.
struct ScrollByte802F {
    u8 hi : 4;
    u8 bit : 1;
    u8 lo : 3;
};

struct SpriteOam802F {
    u8 y;
    u8 affine : 2;
    u8 mode : 2;
    u8 mosaic : 1;
    u8 color : 1;
    u8 shape : 2;
    u16 x : 9;
    u16 rotation : 3;
    u16 flipX : 1;
    u16 flipY : 1;
    u16 size : 2;
    u16 tile : 10;
    u16 priority : 2;
    u16 palette : 4;
    u16 pad;
};
struct SpriteTables802F {
    u8 pad[0x1620];
    u32 maps[8];
    u32 tluts[16];
    s32 sizes[4][4][2];
};
extern "C" void fn_802F8F0C(void*, u8*);
extern "C" void fn_802F91AC(void*, f32*, u8*, u8*, f32);
extern "C" u8 lbl_8046F940[];
extern "C" f32 lbl_80541548;
extern "C" const f32 lbl_8054154C;
extern "C" const f32 lbl_80541550;
#include "JSystem/JKernel/JKRDecomp.h"
#include <dolphin/mtx.h>
#include "JSystem/JMath/Inline.h"
#include "JSystem/JKernel/JKRHeap.h"
#include "JSystem/JUtility/JUTTexture.h"
#include "JSystem/JUtility/TColor.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" s32 checkCompressed__9JKRDecompFPUc(u8*);
extern "C" void decode__9JKRDecompFPUcPUcUlUl(u8*, u8*, u32, u32);

extern "C" void __dt__10JUTTextureFv(void*, s32);
extern "C" void __dl__FPv(void*);
extern "C" void __dla__FPv(void*);
extern "C" u8 lbl_804AA858[];
extern "C" void* fn_802D6A9C();
extern "C" void load__10JUTTextureF11_GXTexMapID(void*,s32);
extern "C" void fn_803004C0(void);
struct Tu802F5040ResMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* getResource(u32 type, const char* name);
};
extern "C" void fn_803003AC(void* p);
extern "C" void fn_803003A8(void);
extern "C" void fn_8030029C(u8* p);

extern "C" f32 lbl_805414F8;
extern "C" f32 lbl_80541500;
extern "C" f32 lbl_805414FC;
extern "C" f64 lbl_80541508;
extern "C" f64 lbl_80541558;
extern "C" f32 lbl_8054152C;
extern "C" f32 lbl_80541534;
extern "C" const f32 lbl_80541520;
extern "C" f32 lbl_80541598;
extern "C" const f32 lbl_80541510;
extern "C" f32 lbl_80541514;
extern "C" f32 lbl_80541518;

extern void* lbl_8053AB10;
extern "C" void fn_8013B3CC(void* mgr, void* mtx);
extern "C" void fn_8013B3F0(void* mgr);
extern void* sManager__8JUTVideo;
extern "C" void fn_802FC80C(u8* this_);
static inline void WarpMatrixSet802F(MtxPtr m, f32 xx, f32 yx, f32 zx, f32 tx, f32 xy, f32 yy, f32 zy, f32 ty, f32 xz, f32 yz, f32 zz, f32 tz) {
    m[0][0]=xx; m[0][1]=yx; m[0][2]=zx; m[0][3]=tx;
    m[1][0]=xy; m[1][1]=yy; m[1][2]=zy; m[1][3]=ty;
    m[2][0]=xz; m[2][1]=yz; m[2][2]=zz; m[2][3]=tz;
}
extern "C" u8 fn_802F58A8(u8* this_, f32* src, MtxPtr mtx);

extern "C" GXColor lbl_805414F0;
extern "C" GXColor lbl_80543F50;
extern "C" u32 lbl_8046FA30[16];
extern "C" const f32 lbl_8054157C;
extern "C" const f32 lbl_80541580;
extern "C" const f32 lbl_80541584;
static inline GXColor TileShade802F(u8 shade,u8 alpha) {
    JUtility::TColor color(*(u32*)&lbl_80543F50);
    color.r=shade;color.g=shade;color.b=shade;color.a=alpha;
    return color;
}
static inline void WarpTileQuad802F(u16 tile, f32 x, f32 y, f32 top, f32 bottom) {
    u16 index=tile&0xfff;
    GXWGFifo.f32=x+top;GXWGFifo.f32=y;GXWGFifo.f32=lbl_805414F8;GXWGFifo.u16=index;
    GXWGFifo.f32=lbl_80541510+x+top;GXWGFifo.f32=y;GXWGFifo.f32=lbl_805414F8;GXWGFifo.u16=index^0x400;
    GXWGFifo.f32=lbl_80541510+x+bottom;GXWGFifo.f32=lbl_80541510+y;GXWGFifo.f32=lbl_805414F8;GXWGFifo.u16=index^0xc00;
    GXWGFifo.f32=x+bottom;GXWGFifo.f32=lbl_80541510+y;GXWGFifo.f32=lbl_805414F8;GXWGFifo.u16=index^0x800;
}
static inline void PlainTileQuad802F(u16 tile, f32 x, f32 y) {
    u16 index=tile&0xfff;
    GXWGFifo.f32=x;GXWGFifo.f32=y;GXWGFifo.f32=lbl_805414F8;GXWGFifo.u16=index;
    GXWGFifo.f32=lbl_80541510+x;GXWGFifo.f32=y;GXWGFifo.f32=lbl_805414F8;GXWGFifo.u16=index^0x400;
    GXWGFifo.f32=lbl_80541510+x;GXWGFifo.f32=lbl_80541510+y;GXWGFifo.f32=lbl_805414F8;GXWGFifo.u16=index^0xc00;
    GXWGFifo.f32=x;GXWGFifo.f32=lbl_80541510+y;GXWGFifo.f32=lbl_805414F8;GXWGFifo.u16=index^0x800;
}

extern "C" f32 lbl_80541574;
extern "C" u8* lbl_8053AEC8;
static inline u8 RendererFadeAlpha802F() {
    return lbl_8053AEC8 ? lbl_8053AEC8[0x5c] : 0;
}
static inline void ScreenMaskQuad802F(const s32* r) {
    s32 left=r[0],top=r[1],right=r[0]+r[2],bottom=r[1]+r[3];
    GXWGFifo.f32=(f32)left;GXWGFifo.f32=(f32)top;GXWGFifo.f32=0.0f;
    GXWGFifo.f32=-1.0f;GXWGFifo.f32=-1.0f;
    GXWGFifo.f32=(f32)right;GXWGFifo.f32=(f32)top;GXWGFifo.f32=0.0f;
    GXWGFifo.f32=1.0f;GXWGFifo.f32=-1.0f;
    GXWGFifo.f32=(f32)right;GXWGFifo.f32=(f32)bottom;GXWGFifo.f32=0.0f;
    GXWGFifo.f32=1.0f;GXWGFifo.f32=1.0f;
    GXWGFifo.f32=(f32)left;GXWGFifo.f32=(f32)bottom;GXWGFifo.f32=0.0f;
    GXWGFifo.f32=-1.0f;GXWGFifo.f32=1.0f;
}

extern void* lbl_8053AAF8;
static inline u8 RendererStage11_802F() {
    return *(s32*)((u8*)lbl_8053AAF8+0x4c)==11;
}

static inline f32 TileTexCoord(f32 coordinate, f32 scale, f32 offset) { return coordinate * scale + offset; }
#include "sdk/stl/math.h"
static inline void DrawTileQuad(u16 t, s32 px, s32 py, f32 ox, f32 oy, f32 oz) {
f32 vx=(f32)px+ox;
f32 vy=(f32)py+oy;
f32 u=(f32)(int)(t&15);
f32 v=(f32)(int)((t>>4)&63);
u=8.0f*u+0.501f;
v=8.0f*v+0.501f;
u*=0.0078125f;
v*=0.001953125f;
f32 su=__fmadds((f32)px,0.0078125f,0.0f);
f32 sv=__fmadds((f32)py,0.0078125f,0.0f);
f32 eu=0.0625f+su;
f32 ev=0.0625f+sv;
f32 u2,v2;
if(t&0x400) {u2=u;u+=6.98f/128.0f;} else u2=u+6.98f/128.0f;
if(t&0x800) {v2=v;v+=6.98f/512.0f;} else v2=v+6.98f/512.0f;
GXWGFifo.f32=vx; GXWGFifo.f32=vy; GXWGFifo.f32=oz;
GXWGFifo.f32=u; GXWGFifo.f32=v; GXWGFifo.f32=su; GXWGFifo.f32=sv;
GXWGFifo.f32=vx+8.0f; GXWGFifo.f32=vy; GXWGFifo.f32=oz;
GXWGFifo.f32=u2; GXWGFifo.f32=v; GXWGFifo.f32=eu; GXWGFifo.f32=sv;
GXWGFifo.f32=vx+8.0f; GXWGFifo.f32=vy+8.0f; GXWGFifo.f32=oz;
GXWGFifo.f32=u2; GXWGFifo.f32=v2; GXWGFifo.f32=eu; GXWGFifo.f32=ev;
GXWGFifo.f32=vx; GXWGFifo.f32=vy+8.0f; GXWGFifo.f32=oz;
GXWGFifo.f32=u; GXWGFifo.f32=v2; GXWGFifo.f32=su; GXWGFifo.f32=ev;
}
struct Tu802F5040Ids { u8 ids[16]; };

struct Tu802F5040Rect {
    s32 m00;
    s32 m04;
    s32 m08;
    s32 m0c;
};

struct Tu802F5040Mtx {
    f32 v[12];
};

struct Tu802F5040Effect {
    s32 type;
    JGeometry::TVec3<f32> pos;
    s32 timer;
    f32 a;
    f32 b;
    JGeometry::TVec3<f32> direction;
};
struct Tu802F5040Effects {
    u8 pad[0xbf9c];
    Tu802F5040Effect entries[16];
};
struct Tu802F5040Tbl {
    u8 pad0[0x28];
    u8* m_tbl[8];
};

extern "C" void fn_802FA3FC(void* mgr);
extern "C" void fn_802FF798(void* mgr);
extern "C" void fn_8013B438(void* mgr);
extern "C" void* fn_802D9C4C(void*);
extern "C" void storeTIMG__10JUTTextureFPC7ResTIMGUc(char* self, const void* timg, u8 palette);
extern "C" f32 lbl_80541560;
extern "C" void fn_80432750(void* obj, u32 flag, f32 a, f32 b, f32 c, f32 d);
extern "C" void fn_80432638(void* obj);
extern "C" u8 fn_80301D30(s32 i);
extern "C" s32 fn_8030AAF4(s32 i);
extern "C" s32 AnimTable_IsField0xe0LessThan3(void* table, s32 slot);

extern void* lbl_8053AD30;
extern u8 lbl_8053ACF0[4];
extern u8 lbl_80506D88[];
extern u8 lbl_80506D98[];
extern void* lbl_8053AAF8;
extern "C" f32 lbl_80541514;
extern "C" f32 lbl_80541518;
extern "C" f32 fn_802F5FF4(f32 x);
static inline f32 SpriteDepthScale802F(f32 x) {
    f32 a = lbl_805414FC;
    f32 v = (x >= lbl_80541500) ? lbl_80541500 : x;
    return a / (a - v);
}
static inline u8 SpriteDepthEnabled802F(u8* ent) {
    u8 flag = *(u8*)(*(u8**)((u8*)lbl_8053AB10 + 0x20) + 0xe461);
    if (flag) flag = ent[0x20];
    return flag;
}
static inline f32 SpriteDepthOffset802F(f32* pos, u8* ent) {
    s32 a, b;
    u8 flag = SpriteDepthEnabled802F(ent);
    if (flag) flag = pos[2] > lbl_805414F8;
    a = ((s8*)ent)[0x1c];
    b = ((s8*)ent)[0x1d];
    if (flag && a < 1) {
        a++;
        b--;
    }
    return (f32)((a << 10) + (b << 7));
}
extern "C" void fn_8013B1E8(void* mgr);
static inline int Tu802F93F4_c5(int v) {
    f32 f = __fmadds((f32)v, lbl_80541518, lbl_805414F8);
    int r = (int)f;
    if (r < 0) {
        r = 0;
    } else if (r > 0x1f) {
        r = 0x1f;
    }
    return r;
}

extern "C" void fn_802F5040(f32* __restrict pos, u8* ent, f32* out) {
    f32 t;
    s32 a;
    s32 b;
    s32 i;
    s32 small;
    bool zpos;
    Mtx m;
    f32 s;
    u32 c;

    if(ent) t = SpriteDepthOffset802F(pos, ent);
    else t = lbl_805414F8;

    if (!(ent && *(void**)(ent+0x18) && ent[0x25]) &&
        ((ent && *(void**)(ent+0x18)) || (lbl_805414F8 != pos[2] && (!ent || ent[0x1f])))) {
        if (ent != NULL && *(void**)(ent + 0x18) != NULL) {
            JMath::gekko_ps_copy12(m, *(void**)(ent + 0x18));
        } else {
            PSMTXIdentity(m);
        }
        if (lbl_805414F8 != pos[2] && (ent == NULL || ent[0x1f] != 0)) {
            s = SpriteDepthScale802F(pos[2]);
            m[0][0] *= s; m[1][0] *= s; m[2][0] *= s;
            m[0][1] *= s; m[1][1] *= s; m[2][1] *= s;
            m[0][2] *= s; m[1][2] *= s; m[2][2] *= s;
            m[0][3] *= s; m[1][3] *= s; m[2][3] *= s;
        }
        m[0][3] += pos[0];
        m[1][3] += pos[1] + t;
        m[2][3] += pos[2] + t;
        fn_8013B3CC(lbl_8053AB10, m);
        out[0] = out[1] = out[2] = lbl_805414F8;
    } else {
        fn_8013B3F0(lbl_8053AB10);
        f32 x=pos[0];
        f32 y=pos[1];
        f32 z=pos[2];
        out[0]=x;
        out[1]=y+t;
        out[2]=z+t;
    }
    fn_8013B1E8(lbl_8053AB10);

    if (ent != NULL && *(s32*)(ent + 0x34) == 1) {
        GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_ONE, GX_LO_NOOP);
    } else if (ent != NULL && *(s32*)(ent + 0x34) == 2) {
        GXSetBlendMode(GX_BM_BLEND, GX_BL_DSTALPHA, GX_BL_INVDSTALPHA, GX_LO_NOOP);
    } else {
        GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_NOOP);
    }
    if (ent != NULL) {
        GXSetTevColor(GX_TEVREG0, *(GXColor*)(ent+0x10));
        GXSetTevColor(GX_TEVREG1, *(GXColor*)(ent+0x14));
        GXSetZMode(ent[0x26], GX_LEQUAL, ent[0x2c]);
    }
    if (ent != NULL && ent[0x2d] != 0) {
        GXSetAlphaUpdate(GX_TRUE);
    }
}

extern "C" void fn_803068D0(void* hdr);
extern "C" s32 fn_8022EA0C(s32 idx);
extern "C" void fn_802F53F4(u8* this_, s32 idx, u8* data);
extern u8 lbl_80506DA8[];
extern u8 lbl_80506DB8[];
extern u8 lbl_80506DC8[];
extern u8 lbl_80506DD8[];
extern "C" void fn_802F53F4(u8* this_, s32 idx, u8* data) {
    if (((data[2] >> 2) & 7) != 0) {
        u32 kind = (data[3] >> 4) & 0xf;
        if (kind == 5 || kind == 0xe) {
            u32* s = (u32*)data - 1;
            u32* d = *(u32**)(this_ + idx * 4 + 0x11c) - 1;
            s32 n = 13;
            do {
                d[1] = s[1];
                d[2] = s[2];
                s += 2;
                d += 2;
            } while (--n != 0);
            if (((data[2] >> 6) & 3) == 2) {
                this_[idx + 0x134] = (data[5] >> 7) & 1;
            } else if (((data[2] >> 6) & 3) == 3) {
                this_[idx + 0x130] = (data[4] >> 5) & 3;
            }
            if (((data[2] >> 6) & 1) != 0) {
                u32* dd = (u32*)lbl_80506DD8;
                u8* c = lbl_80506DC8 + idx * 4;
                u8* b = lbl_80506DB8 + idx * 4;
                u8* a = lbl_80506DA8 + idx * 4;
                for (s32 i = 0; i < 4; i++) {
                    a[i] = (data[6] >> (i * 2)) & 3;
                    b[i] = ((data[7] >> 4) >> i) & 1;
                    c[i] = ((data[7] & 0xf) >> i) & 1;
                    dd[idx] = fn_8022EA0C(idx);
                }
            }
        }
        this_[idx + 0x12c] = 1;
        fn_803068D0(*(void**)(this_ + idx * 4 + 0x11c));
    }
}

#pragma opt_common_subs off
extern "C" void fn_802F5570(u8* this_, f32* __restrict src, u8* ent, f32* outPos, u8** outEnt, MtxPtr mtx, u8* dst) {
    if (ent == NULL || *(s32*)(ent + 0x38) == 2) {
        if (fn_802F58A8(this_, src, mtx) != 0) {
            if (ent != NULL) {
            *(Tu802F5040Ids*)dst=*(Tu802F5040Ids*)ent;
            dst[0x10] = ent[0x10];
            dst[0x11] = ent[0x11];
            dst[0x12] = ent[0x12];
            dst[0x13] = ent[0x13];
            dst[0x14] = ent[0x14];
            dst[0x15] = ent[0x15];
            dst[0x16] = ent[0x16];
            dst[0x17] = ent[0x17];
            *(u32*)(dst + 0x18) = *(u32*)(ent + 0x18);
            dst[0x1c] = ent[0x1c];
            dst[0x1d] = ent[0x1d];
            dst[0x1e] = ent[0x1e];
            dst[0x1f] = ent[0x1f];
            dst[0x20] = ent[0x20];
            dst[0x21] = ent[0x21];
            dst[0x22] = ent[0x22];
            dst[0x23] = ent[0x23];
            dst[0x24] = ent[0x24];
            dst[0x25] = ent[0x25];
            dst[0x26] = ent[0x26];
            *(u32*)(dst + 0x28) = *(u32*)(ent + 0x28);
            dst[0x2c] = ent[0x2c];
            dst[0x2d] = ent[0x2d];
            dst[0x2e] = ent[0x2e];
            *(u32*)(dst + 0x30) = *(u32*)(ent + 0x30);
            *(u32*)(dst + 0x34) = *(u32*)(ent + 0x34);
            *(u32*)(dst + 0x38) = *(u32*)(ent + 0x38);
            if (*(MtxPtr*)(dst + 0x18) != NULL) {
                PSMTXConcat(*(MtxPtr*)(dst + 0x18), mtx, mtx);
                *(MtxPtr*)(dst + 0x18) = mtx;
            }
            }
            *outEnt = dst;
        } else {
            *outEnt = ent;
        }
        f32 y; f32 x; x=src[0]; y=src[1]; outPos[0]=x; f32 z=src[2]; outPos[1]=y; outPos[2]=z;
    } else {
        if (*(s32*)(ent+0x38)==1) {
            f32 z=src[2], height=z;
            if (*(s32*)(this_+0xc21c)>0) {
                f32 loX; f32 x;
                x=src[0]; loX=*(f32*)(this_+0x2368);
                if (x>=loX && x<lbl_80541510*(f32)*(s32*)(this_+0x2380)+loX) {
                    f32 loY; f32 y;
                    y=src[1];loY=*(f32*)(this_+0x236c);
                    if (y>=loY && y<lbl_80541510*(f32)*(s32*)(this_+0x2384)+loY) {
                        f32 dx=x-loX; f32 dy=y-loY;
                        int iy; int ix;
                        ix=(s32)(0.125f*dx); iy=(s32)(0.125f*dy);
                        u8* table=this_; table+=*(s32*)(this_+0x2388)*4;
                        Vec (*grid)[65]=*(Vec(**)[65])(table+0x100);
                        u8* cell=(u8*)&grid[iy][ix];
                        f32 fx=(dx-lbl_80541510*(f32)ix)*0.125f;
                        f32 fy=(dy-lbl_80541510*(f32)iy)*0.125f;
                        height+= (1.0f-fy)*(*(f32*)(cell+8)*(1.0f-fx)+*(f32*)(cell+0x14)*fx) + fy*((1.0f-fx)**(f32*)(cell+0x314)+fx**(f32*)(cell+0x320));
                    }
                }
            }
            f32 y; f32 x; x=src[0]; y=src[1]; outPos[0]=x; outPos[1]=y; outPos[2]=z+height;
            *outEnt=ent;
        } else {
            f32 y; f32 x; x=src[0]; y=src[1]; outPos[0]=x; f32 z=src[2];outPos[1]=y;outPos[2]=z;
            *outEnt=ent;
        }
    }
}
#pragma opt_common_subs reset
extern "C" u8 fn_802F58A8(u8* this_, f32* src, MtxPtr mtx) {
    typedef JGeometry::TVec3<f32> V3;
    V3 temp, left, pos, n1, n2;
    bool ret;
    ret = false;
    if (*(s32*)(this_ + 0xc21c) > 0) {
        f32 loX; f32 x;
        x = src[0]; loX = *(f32*)(this_ + 0x2368);
        if (x >= loX && x < lbl_80541510 * (f32)*(s32*)(this_ + 0x2380) + loX) {
            f32 loY; f32 y;
            y = src[1]; loY = *(f32*)(this_ + 0x236c);
            if (y >= loY && y < lbl_80541510 * (f32)*(s32*)(this_ + 0x2384) + loY) {
                f32 dx = x - loX;
                f32 dy = y - loY;
                int ix; int iy;
                ix = (s32)(0.125f * dx);
                iy = (s32)(0.125f * dy);
                u8* table = this_;
                table += *(s32*)(this_ + 0x2388) * 4;
                V3 (*grid)[65] = *(V3(**)[65])(table + 0x100);
                V3* cell = &grid[iy][ix];
                f32 fx = 0.125f * (dx - lbl_80541510 * (f32)ix);
                f32 fy = 0.125f * (dy - lbl_80541510 * (f32)iy);
                f32 oneX = 1.0f - fx;
                f32 oneY = 1.0f - fy;
                temp.set(cell[0]);
                temp.scale(oneX);
                left.set(cell[1]);
                left.scale(fx);
                left.add(temp);
                left.scale(oneY);
                temp.set(cell[65]);
                temp.scale(oneX);
                pos.set(cell[66]);
                pos.scale(fx);
                pos.add(temp);
                pos.scale(fy);
                pos.add(left);
                temp.sub(cell[1], cell[0]);
                n1.cross(temp, V3(0.0f, 1.0f, 0.0f));
                n1.normalize();
                n1.scale(oneY);
                temp.sub(cell[66], cell[65]);
                n2.cross(temp, V3(0.0f, 1.0f, 0.0f));
                n2.normalize();
                n2.scale(fy);
                n2.add(n1);
                n2.y = 0.0f;
                n2.normalize();
                n1.cross(V3(0.0f, 1.0f, 0.0f), n2);
                WarpMatrixSet802F(mtx, n1.x, 0.0f, n2.x, pos.x - dx,
                                  n1.y, 1.0f, n2.y, pos.y - dy,
                                  n1.z, 0.0f, n2.z, pos.z);
                ret = true;
            }
        }
    }
    return (u8)ret;
}

extern "C" f32 fn_802F5E9C(u8* this_, f32* pos) {
    f32 z = pos[2];
    if (*(s32*)(this_ + 0xc21c) > 0) {
        f32 lo_x;
        f32 x = pos[0];
        lo_x = *(f32*)(this_ + 0x2368);
        if (x >= lo_x && x < lbl_80541510 * (f32)*(s32*)(this_ + 0x2380) + lo_x) {
            f32 lo_y;
            f32 y = pos[1];
            lo_y = *(f32*)(this_ + 0x236c);
            if (y >= lo_y && y < lbl_80541510 * (f32)*(s32*)(this_ + 0x2384) + lo_y) {
                f32 scale = lbl_80541514;
                s32 ix = (s32)((x - lo_x) * scale);
                s32 iy = (s32)((y - lo_y) * scale);
                f32 fx = scale * ((x - lo_x) - lbl_80541510 * (f32)ix);
                f32 fy = scale * ((y - lo_y) - lbl_80541510 * (f32)iy);
                u8* p = this_ + *(s32*)(this_ + 0x2388) * 4;
                u8* tbl = *(u8**)(p + 0x100);
                u8* cell = tbl + iy * 0x30c + ix * 0xc;
                f32 a = *(f32*)(cell + 0x8);
                f32 b = *(f32*)(cell + 0x14);
                f32 c = *(f32*)(cell + 0x314);
                f32 d = *(f32*)(cell + 0x320);
                f32 r0 = a * (lbl_80541518 - fx) + b * fx;
                f32 r1 = c * (lbl_80541518 - fx) + d * fx;
                z = z + (r0 * (lbl_80541518 - fy) + r1 * fy);
            }
        }
    }
    return z;
}

extern "C" f32 fn_802F5FF4(f32 x) {
    f32 a = lbl_805414FC;
    f32 v = (x >= lbl_80541500) ? lbl_80541500 : x;
    return a / (a - v);
}

#include "JSystem/JMath/JMath.h"
extern f64 __frsqrte(f64);

static inline f32 Tu802F5040_invSqrt(const f32 x) {
    if (x <= 0.0f) return x;
    f32 y = __frsqrte(x);
    const f32 result = 0.5f * y * (3.0f - x * (y * y));
    return result;
}
static inline void Tu802F5040_setVec(f32* dst, f32 x, f32 y, f32 z) {
    dst[0] = x;
    dst[1] = y;
    dst[2] = z;
}
#pragma opt_propagation off
extern "C" void fn_802F601C(Tu802F5040Effects* this_, f32* src, s32 type, f32* __restrict src2, f32 f1, f32 f2) {
    f32 r;
    f32 scale;
    f32 mag;
    f32 z;
    f32 y;
    f32 x;
    u8* p;
    s32 best;
    s32 bestIdx;
    s32 slot;
    s32 i;
    Tu802F5040Effect* e;
    u8* q;
    p = (u8*)this_;
    best = -1;
    bestIdx = 0;
    slot = -1;
    for (i=0; i<16; i++) {
        q=p+0x10000;
        if (*(s32*)(q-0x4064)==0) { slot=i; break; }
        if (best < 0 || best > *(s32*)(q-0x4054)) {
            best=*(s32*)(q-0x4054);
            bestIdx=i;
        }
        p+=0x28;
    }
    if (slot<0) slot=bestIdx;
    x=src[0];
    y=src[1];
    z=src[2];
    e=&this_->entries[slot];
    e->type=type;
    e->pos.set(x,y,z);
    e->a=f1;
    e->b=f2;
    switch(type) {
    case 2: e->timer=60; break;
    case 1: e->timer=5; break;
    case 3:
        e->timer=18;
        e->direction.set(*(JGeometry::TVec3<f32>*)src2);
        f32 squared=e->direction.squared();
        mag=squared;
        if (mag <= JGeometry::TUtilf::epsilon()) return;
        scale=Tu802F5040_invSqrt(mag);
        e->direction.scale(scale);
        break;
    case 4: e->type=5; e->a=-e->a; e->timer=1; break;
    case 5: e->timer=1; break;
    case 6: e->timer=300; break;
    }
}
#pragma opt_propagation reset
extern "C" u8 fn_802F6298(u8* self, Vec* __restrict pos, s32 a, s32 b, s32 c, s32 d, u8* src) {
    struct Quad {
        s32 v[4];
    };
    BOOL ret = FALSE;
    s32 n = *(s32*)(self + 0xe424);
    if (n < 0x20) {
        u8* e = self + n * 0x88 + 0xd324;
        u8 i;
        *(Vec*)e = *pos;
        *(s32*)(e + 0xc) = a;
        *(s32*)(e + 0x10) = b;
        *(s32*)(e + 0x14) = c;
        *(s32*)(e + 0x18) = d;
        if (src != NULL) {
            *(Quad*)(e + 0x1c) = *(Quad*)src;
            e[0x2c] = src[0x10];
            e[0x2d] = src[0x11];
            e[0x2e] = src[0x12];
            e[0x2f] = src[0x13];
            e[0x30] = src[0x14];
            e[0x31] = src[0x15];
            e[0x32] = src[0x16];
            e[0x33] = src[0x17];
            *(s32*)(e + 0x34) = *(s32*)(src + 0x18);
            e[0x38] = src[0x1c];
            e[0x39] = src[0x1d];
            e[0x3a] = src[0x1e];
            e[0x3b] = src[0x1f];
            e[0x3c] = src[0x20];
            e[0x3d] = src[0x21];
            e[0x3e] = src[0x22];
            e[0x3f] = src[0x23];
            e[0x40] = src[0x24];
            e[0x41] = src[0x25];
            e[0x42] = src[0x26];
            *(s32*)(e + 0x44) = *(s32*)(src + 0x28);
            e[0x48] = src[0x2c];
            e[0x49] = src[0x2d];
            e[0x4a] = src[0x2e];
            *(s32*)(e + 0x4c) = *(s32*)(src + 0x30);
            *(s32*)(e + 0x50) = *(s32*)(src + 0x34);
            *(s32*)(e + 0x54) = *(s32*)(src + 0x38);
            e[0x3e] = 0;
            if (*(u8**)(src + 0x18) != NULL) {
                JMath::gekko_ps_copy12(e + 0x58, *(u8**)(src + 0x18));
                *(u8**)(e + 0x34) = e + 0x58;
            }
        } else {
            for (i = 0; i < 0x10; i++) {
                e[i + 0x1c] = i;
            }
            *(s32*)(e + 0x2c) = -1;
            *(s32*)(e + 0x30) = 0;
            *(s32*)(e + 0x34) = 0;
            e[0x38] = 0;
            e[0x39] = 0;
            e[0x3a] = 0;
            e[0x3b] = 1;
            e[0x3c] = 1;
            e[0x3d] = 0;
            e[0x3e] = 0;
            e[0x3f] = 0;
            e[0x40] = 0;
            e[0x41] = 0;
            e[0x42] = 1;
            *(s32*)(e + 0x44) = 3;
            e[0x48] = 1;
            e[0x49] = 0;
            e[0x4a] = 0;
            *(s32*)(e + 0x4c) = -1;
            *(s32*)(e + 0x50) = 0;
            *(s32*)(e + 0x54) = 2;
        }
        ret = TRUE;
        *(s32*)(self + 0xe424) = *(s32*)(self + 0xe424) + 1;
    }
    return ret;
}

extern "C" u8 fn_802F654C(u8* self, f32* __restrict pos, s32 a, s32 b, s32 c, s32 d, u8* src) {
    struct Quad {
        s32 v[4];
    };
    BOOL ret = FALSE;
    s32 n = *(s32*)(self + 0xd320);
    if (n < 0x20) {
        u8* e = self + n * 0x88 + 0xc220;
        u8 i;
        *(Vec*)e = *(Vec*)pos;
        *(s32*)(e + 0xc) = a;
        *(s32*)(e + 0x10) = b;
        *(s32*)(e + 0x14) = c;
        *(s32*)(e + 0x18) = d;
        if (src != NULL) {
            *(Quad*)(e + 0x1c) = *(Quad*)src;
            e[0x2c] = src[0x10];
            e[0x2d] = src[0x11];
            e[0x2e] = src[0x12];
            e[0x2f] = src[0x13];
            e[0x30] = src[0x14];
            e[0x31] = src[0x15];
            e[0x32] = src[0x16];
            e[0x33] = src[0x17];
            *(s32*)(e + 0x34) = *(s32*)(src + 0x18);
            e[0x38] = src[0x1c];
            e[0x39] = src[0x1d];
            e[0x3a] = src[0x1e];
            e[0x3b] = src[0x1f];
            e[0x3c] = src[0x20];
            e[0x3d] = src[0x21];
            e[0x3e] = src[0x22];
            e[0x3f] = src[0x23];
            e[0x40] = src[0x24];
            e[0x41] = src[0x25];
            e[0x42] = src[0x26];
            *(s32*)(e + 0x44) = *(s32*)(src + 0x28);
            e[0x48] = src[0x2c];
            e[0x49] = src[0x2d];
            e[0x4a] = src[0x2e];
            *(s32*)(e + 0x4c) = *(s32*)(src + 0x30);
            *(s32*)(e + 0x50) = *(s32*)(src + 0x34);
            *(s32*)(e + 0x54) = *(s32*)(src + 0x38);
            e[0x3d] = 0;
            if (*(u8**)(src + 0x18) != NULL) {
                JMath::gekko_ps_copy12(e + 0x58, *(u8**)(src + 0x18));
                *(u8**)(e + 0x34) = e + 0x58;
            }
        } else {
            for (i = 0; i < 0x10; i++) {
                e[i + 0x1c] = i;
            }
            *(s32*)(e + 0x2c) = -1;
            *(s32*)(e + 0x30) = 0;
            *(s32*)(e + 0x34) = 0;
            e[0x38] = 0;
            e[0x39] = 0;
            e[0x3a] = 0;
            e[0x3b] = 1;
            e[0x3c] = 1;
            e[0x3d] = 0;
            e[0x3e] = 0;
            e[0x3f] = 0;
            e[0x40] = 0;
            e[0x41] = 0;
            e[0x42] = 1;
            *(s32*)(e + 0x44) = 3;
            e[0x48] = 1;
            e[0x49] = 0;
            e[0x4a] = 0;
            *(s32*)(e + 0x4c) = -1;
            *(s32*)(e + 0x50) = 0;
            *(s32*)(e + 0x54) = 2;
        }
        ret = TRUE;
        *(s32*)(self + 0xd320) = *(s32*)(self + 0xd320) + 1;
    }
    return ret;
}

extern "C" u8 lbl_8046F940[];
extern "C" void* lbl_8053AAF8;
#pragma opt_common_subs on
extern "C" u8 fn_802F6800(u8* this_, f32* src, s32 param_3, s32 param_4, s32 param_5, s32 param_6, u8* __restrict param_7) {
    u8* table = lbl_8046F940;
    s32 i;
    u8* p;
    u8* c1;
    u8* c2;
    s32 off;
    s32 div;
    BOOL done;
    s32 t;
    u8 a0;
    u8 a1;
    u8 a2;
    u8 a3;

    done = 0;
    s32 index = *(s32*)(param_7 + 0x30);
    off = index * 4;
    div = ((s32*)(table + 0x1840))[index];
    if (this_[0xbf98] != 0 && (u32)(param_3 + (param_5 + param_6)) % (u32)div == *(s32*)((u8*)lbl_8053AAF8 + 0x5c) % div) {
        p = this_;
        for (i = 0; i < 0x100; i++) {
            if (*(s32*)(p + 0x2398) == 0) {
                c1 = table + 0x1720 + off;
                c2 = table + 0x1768 + off;
                *(s32*)(p + 0x2398) = ((s32*)(table + 0x17b0))[index];
                *(f32*)(p + 0x23a0) = ((f32*)(table + 0x17f8))[*(s32*)(param_7 + 0x30)];
                int alpha = (param_7[0x13] * c1[3]) / 255;
                int green = (param_7[0x11] * c1[1]) / 255;
                int blue = (param_7[0x12] * c1[2]) / 255;
                int red = (param_7[0x10] * c1[0]) / 255;
                *(s32*)(p + 0x239c) = *(s32*)(p + 0x2398);
                *(f32*)(p + 0x23a4) = src[0];
                *(f32*)(p + 0x23a8) = src[1];
                *(f32*)(p + 0x23ac) = src[2];
                *(s32*)(p + 0x23b0) = param_3;
                *(s32*)(p + 0x23b4) = param_4;
                *(s32*)(p + 0x23b8) = param_5;
                *(s32*)(p + 0x23bc) = param_6;
                ((JUtility::TColor*)(p + 0x242c))->set(red, green, blue, alpha);
                a3 = 0xff;
                t = param_7[0x17] + c2[3];
                if (t < 0xff) {
                    a3 = t;
                }
                a2 = 0xff;
                t = param_7[0x16] + c2[2];
                if (t < 0xff) {
                    a2 = t;
                }
                a1 = 0xff;
                t = param_7[0x15] + c2[1];
                if (t < 0xff) {
                    a1 = t;
                }
                a0 = 0xff;
                t = param_7[0x14] + c2[0];
                if (t < 0xff) {
                    a0 = t;
                }
                *(u8*)(p + 0x2430) = a0;
                *(u8*)(p + 0x2431) = a1;
                *(u8*)(p + 0x2432) = a2;
                *(u8*)(p + 0x2433) = a3;
                void* matrix = *(void**)(param_7 + 0x18);
                u8 layer = param_7[0x1c];
                u8 priority = param_7[0x1d];
                *(u32*)(p + 0x23c0) = *(u32*)(param_7 + 0x0);
                *(u32*)(p + 0x23c4) = *(u32*)(param_7 + 0x4);
                *(u32*)(p + 0x23c8) = *(u32*)(param_7 + 0x8);
                *(u32*)(p + 0x23cc) = *(u32*)(param_7 + 0xc);
                *(u8*)(p + 0x23d0) = param_7[0x10];
                *(u8*)(p + 0x23d1) = param_7[0x11];
                *(u8*)(p + 0x23d2) = param_7[0x12];
                *(u8*)(p + 0x23d3) = param_7[0x13];
                *(u8*)(p + 0x23d4) = param_7[0x14];
                *(u8*)(p + 0x23d5) = param_7[0x15];
                *(u8*)(p + 0x23d6) = param_7[0x16];
                *(u8*)(p + 0x23d7) = param_7[0x17];
                *(u32*)(p + 0x23d8) = *(u32*)(param_7 + 0x18);
                *(u8*)(p + 0x23dc) = param_7[0x1c];
                *(u8*)(p + 0x23dd) = param_7[0x1d];
                *(u8*)(p + 0x23de) = param_7[0x1e];
                *(u8*)(p + 0x23df) = param_7[0x1f];
                *(u8*)(p + 0x23e0) = param_7[0x20];
                *(u8*)(p + 0x23e1) = param_7[0x21];
                *(u8*)(p + 0x23e2) = param_7[0x22];
                *(u8*)(p + 0x23e3) = param_7[0x23];
                *(u8*)(p + 0x23e4) = param_7[0x24];
                *(u8*)(p + 0x23e5) = param_7[0x25];
                *(u8*)(p + 0x23e6) = param_7[0x26];
                *(u32*)(p + 0x23e8) = *(u32*)(param_7 + 0x28);
                *(u8*)(p + 0x23ec) = param_7[0x2c];
                *(u8*)(p + 0x23ed) = param_7[0x2d];
                *(u8*)(p + 0x23ee) = param_7[0x2e];
                *(u32*)(p + 0x23f0) = *(u32*)(param_7 + 0x30);
                *(u32*)(p + 0x23f4) = *(u32*)(param_7 + 0x34);
                *(u32*)(p + 0x23f8) = *(u32*)(param_7 + 0x38);
                *(u8*)(p + 0x23ec) = 0;
                *(u8*)(p + 0x23ed) = 1;
                *(u8*)(p + 0x23ee) = 0;
                *(s32*)(p + 0x23f0) = -1;
                *(s32*)(p + 0x23f8) = 0;
                *(u8*)(p + 0x23dc) = layer;
                *(u8*)(p + 0x23dd) = priority - 1;
                if (matrix != 0) {
                    JMath::gekko_ps_copy12(p + 0x23fc, matrix);
                    *(u32*)(p + 0x23d8) = (u32)(p + 0x23fc);
                } else if (lbl_80541518 != *(f32*)(p + 0x23a0)) {
                    PSMTXIdentity((MtxPtr)(p + 0x23fc));
                    *(u32*)(p + 0x23d8) = (u32)(p + 0x23fc);
                }
                done = 1;
                break;
            }
            p += 0x9c;
        }
    }
    return done;
}
#pragma opt_common_subs on
extern "C" void fn_802F6BBC(Tu802F5040Tbl* base, s32 src, s32 dst) {
    u16* s;
    u16* d;
    s32 n;
    if (src >= 0 && src < 4) {
        s = (u16*)base->m_tbl[src];
    } else if (src >= 4 && src < 8) {
        s = (u16*)base->m_tbl[src];
    } else {
        s = (u16*)base->m_tbl[src];
    }
    if (dst >= 0 && dst < 4) {
        d = (u16*)base->m_tbl[dst];
    } else if (dst >= 4 && dst < 8) {
        d = (u16*)base->m_tbl[dst];
    } else {
        d = (u16*)base->m_tbl[dst];
    }
    n = 0x100;
    do {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
        d[3] = s[3];
        d[4] = s[4];
        d[5] = s[5];
        d[6] = s[6];
        d[7] = s[7];
        d[8] = s[8];
        d[9] = s[9];
        d[10] = s[10];
        d[11] = s[11];
        d[12] = s[12];
        d[13] = s[13];
        d[14] = s[14];
        d[15] = s[15];
        s += 16;
        d += 16;
    } while (--n != 0);
}
#pragma opt_unroll_loops reset
extern "C" u32 lbl_80471020[];
extern "C" f32 lbl_80541528, lbl_80541530, lbl_80541538, lbl_8054153C;
extern "C" void fn_802F6CF4(Tu802F5040Tbl* base, void* elem, s32 a, void* ptr) {
u8* tiles=(u8*)a;
f32* pos=(f32*)elem;
u8* this_=(u8*)base;
u8* ent=(u8*)ptr;
f32 origin[3];
GXTexObj texObj;
int counts[16];
GXTlutObj tlut[16];
int i,row,col,y,x;
u8* mgr;
bool flag;
s32 idx;
if(this_[0x2364]) {
if(ent && ent[0x21]) {if(fn_802F654C(this_,pos,0,0,0,(s32)tiles,ent)) return;}
if(ent && ent[0x22]) {if(fn_802F6298(this_,(Vec*)pos,0,0,0,(s32)tiles,ent)) return;}
fn_8013B1E8(lbl_8053AB10);
fn_802F5040(pos,ent,origin);
GXClearVtxDesc();
GXSetVtxDesc((GXAttr)9,(GXAttrType)1);
GXSetVtxDesc((GXAttr)13,(GXAttrType)1);
GXSetVtxDesc((GXAttr)14,(GXAttrType)1);
GXSetVtxAttrFmt((GXVtxFmt)0,(GXAttr)9,(GXCompCnt)1,(GXCompType)4,0);
GXSetVtxAttrFmt((GXVtxFmt)0,(GXAttr)13,(GXCompCnt)1,(GXCompType)4,0);
GXSetVtxAttrFmt((GXVtxFmt)0,(GXAttr)14,(GXCompCnt)1,(GXCompType)4,0);
GXSetTexCoordGen2((GXTexCoordID)1,(GXTexGenType)1,(GXTexGenSrc)5,(GXTexMtx)0x3c,(GXBool)0,(GXPTTexMtx)0x7d);
GXSetNumTexGens(2);
    if (this_[0xe450] != 0) {
        mgr = (u8*)lbl_8053AAF8;
        if (mgr[0x7f] != 0) {
            flag = (*(s32*)(mgr + 0x4c) == 0x7 || *(s32*)(mgr + 0x4c) == 0x8 || *(s32*)(mgr + 0x4c) == 0x9 || *(s32*)(mgr + 0x4c) == 0x16 || *(s32*)(mgr + 0x4c) == 0xa || *(s32*)(mgr + 0x4c) == 0xb) ? true : false;
        } else {
            flag = (*(s32*)(mgr + 0x4c) == 0x7 || *(s32*)(mgr + 0x4c) == 0x8 || *(s32*)(mgr + 0x4c) == 0x9 || *(s32*)(mgr + 0x4c) == 0x16 || *(s32*)(mgr + 0x4c) == 0xa || *(s32*)(mgr + 0x4c) == 0xb || *(s32*)(mgr + 0x4c) == 0xc) ? true : false;
        }
        if (flag && *(void**)(mgr + 0x4) != NULL) {
            idx = *(s32*)((u8*)fn_802D6A9C() + 0x50);
        } else {
            idx = 0;
        }
        load__10JUTTextureF11_GXTexMapID(((void**)(this_ + 0xE428))[idx], 1);
        GXSetTevOrder((GXTevStageID)1, (GXTexCoordID)1, (GXTexMapID)1, (GXChannelID)0xff);
        GXSetTevColorIn((GXTevStageID)1, (GXTevColorArg)0xf, (GXTevColorArg)0, (GXTevColorArg)8, (GXTevColorArg)0xf);
        GXSetTevAlphaIn((GXTevStageID)1, (GXTevAlphaArg)7, (GXTevAlphaArg)7, (GXTevAlphaArg)7, (GXTevAlphaArg)0);
        GXSetTevColorOp((GXTevStageID)1, (GXTevOp)0, (GXTevBias)0, (GXTevScale)0, (GXBool)1, (GXTevRegID)0);
        GXSetTevAlphaOp((GXTevStageID)1, (GXTevOp)0, (GXTevBias)0, (GXTevScale)0, (GXBool)1, (GXTevRegID)0);
        GXSetTevSwapMode((GXTevStageID)1, (GXTevSwapSel)0, (GXTevSwapSel)0);
        GXSetTevDirect((GXTevStageID)1);

GXSetNumTevStages(2);
}
for(i=0;i<16;i++) {
GXInitTlutObj(&tlut[i],*(u8**)(this_+0x18)+i*0x20,(GXTlutFmt)2,16);
GXLoadTlut(&tlut[i],lbl_80471020[i]);
}
for(int n=0;n<16;n++) counts[n]=0;
for(int countRow=0;countRow<16;countRow++) {
for(int countCol=0;countCol<16;countCol++) {
u16 tile=tiles[(countRow*16+countCol)*2]|tiles[(countRow*16+countCol)*2+1]<<8;
if(tile) {
u16* list=*(u16**)(this_+0x24);
for(int dy=0;dy<2;dy++) { for(int dx=0;dx<2;dx++) counts[(list[tile*4+dy*2+dx]>>12)&15]++; }
}
}
}
for(i=0;i<16;i++) {
if(counts[i]>0) {
GXInitTexObjCI(&texObj,*(void**)(this_+4),128,512,(GXCITexFmt)8,(GXTexWrapMode)0,(GXTexWrapMode)0,0,lbl_80471020[i]);
GXLoadTexObj(&texObj,(GXTexMapID)0);
GXBegin((GXPrimitive)0x80,(GXVtxFmt)0,counts[i]*4);
f32 oz=origin[2];
f32 ox=origin[0];
f32 oy=origin[1];
for(row=0;row<16;row++) {
for(col=0;col<16;col++) {
u16 tile=tiles[(row*16+col)*2]|tiles[(row*16+col)*2+1]<<8;
if(tile) {
for(y=0;y<2;y++) {
for(x=0;x<2;x++) {
u16 t=(*(u16**)(this_+0x24))[tile*4+y*2+x];
if(((t>>12)&15)==i) {
int px=(col*2+x)*8;
int py=(row*2+y)*8;
const f32 vx=(f32)px+ox;
const f32 vy=(f32)py+oy;
f32 v;
f32 u2,v2;
const f32 unit=0.0078125f;
const f32 halfPixel=0.501f;
f32 rawU=(f32)(int)(t&15);
v=(f32)(int)((t>>4)&63);
rawU=8.0f*rawU+halfPixel;
v=8.0f*v+halfPixel;
f32 u=rawU*0.0078125f;
v*=0.001953125f;
f32 su=__fmadds((f32)px,unit,0.0f);
f32 sv=__fmadds((f32)py,unit,0.0f);
f32 eu=0.0625f+su;
f32 ev=0.0625f+sv;
if(t&0x400) {u2=u;u=6.98f/128.0f+u;} else u2=u+6.98f/128.0f;
if(t&0x800) {v2=v;v=6.98f/512.0f+v;} else v2=v+6.98f/512.0f;
GXWGFifo.f32=vx; GXWGFifo.f32=vy; GXWGFifo.f32=oz;
GXWGFifo.f32=u; GXWGFifo.f32=v; GXWGFifo.f32=su; GXWGFifo.f32=sv;
GXWGFifo.f32=vx+8.0f; GXWGFifo.f32=vy; GXWGFifo.f32=oz;
GXWGFifo.f32=u2; GXWGFifo.f32=v; GXWGFifo.f32=eu; GXWGFifo.f32=sv;
GXWGFifo.f32=vx+8.0f; GXWGFifo.f32=vy+8.0f; GXWGFifo.f32=oz;
GXWGFifo.f32=u2; GXWGFifo.f32=v2; GXWGFifo.f32=eu; GXWGFifo.f32=ev;
GXWGFifo.f32=vx; GXWGFifo.f32=vy+8.0f; GXWGFifo.f32=oz;
GXWGFifo.f32=u; GXWGFifo.f32=v2; GXWGFifo.f32=su; GXWGFifo.f32=ev;
}
}
}
}
}
}
}
}
if(ent && *(s32*)(ent+0x30)!=-1) fn_802F6800(this_,pos,0,0,0,(s32)tiles,ent);
}
}

static inline void WarpTextureVertex802F(u8* self,s32 index,f32 depth,f32 u,f32 v,f32 s,f32 t) {
    u32 buffer=*(s32*)(self+0x2388);
    f32* vertex=*(f32**)(self+0x100+buffer*4)+index*3;
    u8* color=*(u8**)(self+0x108+buffer*4)+index*4;
    f32 y=vertex[1]+*(f32*)(self+0x236c);
    f32 x=vertex[0]+*(f32*)(self+0x2368);
    f32 z=vertex[2]+depth;
    u8 r=color[0],g=color[1],b=color[2],a=color[3];
    GXWGFifo.f32=x;GXWGFifo.f32=depth+y;GXWGFifo.f32=z;
    GXWGFifo.u8=r;GXWGFifo.u8=g;GXWGFifo.u8=b;GXWGFifo.u8=a;
    GXWGFifo.f32=u;GXWGFifo.f32=v;GXWGFifo.f32=s;GXWGFifo.f32=t;
}
extern "C" void fn_802F745C(Tu802F5040Tbl* base, void* elem, s32 a, void* ptr) {
    u8* ent=(u8*)ptr;
    u8* timg=(u8*)a;
    f32* pos=(f32*)elem;
    u8* this_=(u8*)base;
    f32 origin[3];
    u8 tex[0x40];
    u8* img;
    s32 useTex=0;
    f32 w,h,f27,f26,f30,f31;
    if(!this_[0x2364]) return;
    if(ent && ent[0x21]) {if(fn_802F654C(this_,pos,0,0,(s32)timg,0,ent)) return;}
    if(ent && ent[0x22]) {if(fn_802F6298(this_,(Vec*)pos,0,0,(s32)timg,0,ent)) return;}
    storeTIMG__10JUTTextureFPC7ResTIMGUc((char*)tex,timg,0);
    tex[0x3b]&=2;
    img=*(u8**)(tex+0x20);
    w=(f32)*(u16*)(img+2);
    h=(f32)*(u16*)(img+4);
    if(ent && ent[0x24] && this_[0x2450]) {
        useTex=1;
        fn_8013B1E8(lbl_8053AB10);
        load__10JUTTextureF11_GXTexMapID(tex,0);
    }
    fn_802F5040(pos,ent,origin);
    f30=lbl_80541520*w;
    f31=lbl_80541520*h;
    f27=pos[0]-f30;
    f26=pos[1]-f31;
    if(ent && ent[0x23]) {
        if(*(void**)(ent+0x18)) {
            f27+=((f32*)*(u8**)(ent+0x18))[3];
            f26+=((f32*)*(u8**)(ent+0x18))[7];
        }
    }
    f27*=lbl_8054152C;
    f26*=lbl_8054152C;
    GXClearVtxDesc();
    GXSetVtxDesc((GXAttr)9,(GXAttrType)1);
    GXSetVtxDesc((GXAttr)11,(GXAttrType)1);
    GXSetVtxDesc((GXAttr)13,(GXAttrType)1);
    GXSetVtxDesc((GXAttr)14,(GXAttrType)1);
    GXSetVtxAttrFmt((GXVtxFmt)0,(GXAttr)9,(GXCompCnt)1,(GXCompType)4,0);
    GXSetVtxAttrFmt((GXVtxFmt)0,(GXAttr)11,(GXCompCnt)0,(GXCompType)5,0);
    GXSetVtxAttrFmt((GXVtxFmt)0,(GXAttr)13,(GXCompCnt)1,(GXCompType)4,0);
    GXSetVtxAttrFmt((GXVtxFmt)0,(GXAttr)14,(GXCompCnt)1,(GXCompType)4,0);
    GXSetChanCtrl((GXChannelID)4,(GXBool)0,(GXColorSrc)0,(GXColorSrc)1,(GXLightID)0,(GXDiffuseFn)0,(GXAttnFn)2);
    GXSetNumChans(1);
    GXSetTevOrder((GXTevStageID)1,(GXTexCoordID)0xff,(GXTexMapID)0xff,(GXChannelID)4);
    GXSetTevColorIn((GXTevStageID)1,(GXTevColorArg)0xf,(GXTevColorArg)0xc,(GXTevColorArg)0xa,(GXTevColorArg)0);
    GXSetTevAlphaIn((GXTevStageID)1,(GXTevAlphaArg)7,(GXTevAlphaArg)6,(GXTevAlphaArg)5,(GXTevAlphaArg)0);
    GXSetTevColorOp((GXTevStageID)1,(GXTevOp)0,(GXTevBias)2,(GXTevScale)0,(GXBool)1,(GXTevRegID)0);
    GXSetTevAlphaOp((GXTevStageID)1,(GXTevOp)0,(GXTevBias)2,(GXTevScale)0,(GXBool)1,(GXTevRegID)0);
    GXSetTevSwapMode((GXTevStageID)1,(GXTevSwapSel)0,(GXTevSwapSel)0);
    GXSetTevDirect((GXTevStageID)1);
    GXSetNumTevStages(2);
    if(useTex) {
        GXSetTexCoordGen2((GXTexCoordID)1,(GXTexGenType)1,(GXTexGenSrc)5,(GXTexMtx)0x3c,(GXBool)0,(GXPTTexMtx)0x7d);
        GXSetNumTexGens(2);
    }
    GXSetTevOrder((GXTevStageID)2,(GXTexCoordID)1,(GXTexMapID)1,(GXChannelID)0xff);
    GXSetTevColorIn((GXTevStageID)2,(GXTevColorArg)0xf,(GXTevColorArg)0,(GXTevColorArg)8,(GXTevColorArg)0xf);
    GXSetTevAlphaIn((GXTevStageID)2,(GXTevAlphaArg)7,(GXTevAlphaArg)7,(GXTevAlphaArg)7,(GXTevAlphaArg)0);
    GXSetTevColorOp((GXTevStageID)2,(GXTevOp)0,(GXTevBias)0,(GXTevScale)0,(GXBool)1,(GXTevRegID)0);
    GXSetTevAlphaOp((GXTevStageID)2,(GXTevOp)0,(GXTevBias)0,(GXTevScale)0,(GXBool)1,(GXTevRegID)0);
    GXSetTevSwapMode((GXTevStageID)2,(GXTevSwapSel)0,(GXTevSwapSel)0);
    GXSetTevDirect((GXTevStageID)2);
    GXSetNumTevStages(3);
    GXBegin((GXPrimitive)0x80,(GXVtxFmt)0,0);
}

extern "C" void fn_802F86CC(Tu802F5040Tbl* base, void* elem, s32 a, s32 frame, void* ptr, f32 scaleX, f32 scaleY) {
    u8* data=(u8*)a;
    u8* ent=(u8*)ptr;
    u8* self=(u8*)base;
    f32* pos=(f32*)elem;
    Mtx matrix;
    f32 origin[3];
    u8* resolved;
    SpriteOam802F object;
    u8 transformed;
    SpriteTables802F* tables = (SpriteTables802F*)lbl_8046F940;
    if (!self[0x2364]) return;
    if (ent && ent[0x21]) {
        if (fn_802F654C(self,pos,(s32)data,frame,0,0,ent)) return;
    }
    if (ent && ent[0x22]) {
        if (fn_802F6298(self,(Vec*)pos,(s32)data,frame,0,0,ent)) return;
    }
    u8* header = data + frame*2;
    s32 start = header[2] | (header[3]<<8);
    s32 count = ((header[4] | (header[5]<<8))-start)/6;
    DrawRec record;
    s32 lastPriority = -1;
    s32 lastPalette = -1;
    fn_802F5570(self,pos,ent,origin,&resolved,matrix,(u8*)&record);
    f32 depth;
    if (resolved) {
        u8 adjust;
        if (!(*(u8**)((u8*)lbl_8053AB10+0x20))[0xe461] || (adjust = resolved[0x20]) != 0) adjust=origin[2]>lbl_805414F8;
        s32 layer=(s8)resolved[0x1c];
        s32 sub=(s8)resolved[0x1d];
        if (adjust && layer<1) { layer++; sub--; }
        depth=(layer<<10)+(sub<<7);
    } else depth=lbl_805414F8;
    fn_802F91AC(self,origin,resolved,&transformed,depth);
    fn_802F8F0C(self,resolved);
    s32 offsetY=lbl_80541548*(lbl_80541518-scaleY);
    s32 offsetX=lbl_80541548*(lbl_80541518-scaleX);
    s32 (*sizes)[4][2] = tables->sizes;
    u8* source = data + start + (count-1)*6;
    for (s32 index=count-1;index>=0;index--,source-=6) {
        object.y=source[0];
        object.affine=source[1]&3;
        object.mode=(source[1]>>2)&3;
        object.mosaic=(source[1]>>4)&1;
        object.color=(source[1]>>5)&1;
        object.shape=(source[1]>>6)&3;
        object.x=source[2] | ((source[2]&0x80)<<1);
        if (index!=0) {
            object.y+=offsetY;
            object.x+=offsetX;
        }
        object.rotation=(source[3]>>1)&7;
        object.flipX=(source[3]>>4)&1;
        object.flipY=(source[3]>>5)&1;
        object.size=(source[3]>>6)&3;
        object.tile=source[4]|((source[5]&3)<<8);
        object.priority=(source[5]>>2)&3;
        if (resolved) object.palette=resolved[(u32)source[5]>>4];
        else object.palette=(u32)source[5]>>4;
        object.pad=0;
        s32 priority=(((u32)*((u8*)&object+5)>>4)&3);
        if (lastPriority!=priority || lastPalette!=(*((u8*)&object+5)&15)) {
            lastPriority=priority;
            lastPalette=*((u8*)&object+5)&15;
            s32 bank=0;
            if (resolved) bank=resolved[0x1e];
            u32* tluts = tables->tluts;
            GXLoadTlut((GXTlutObj*)(self+0x25c+bank*0x300+priority*0xc0+lastPalette*0xc), (GXTlut)tluts[lastPalette]);
            u32* maps = tables->maps;
            u32 map=(((lastPalette&1)<<2)|priority);
            GXLoadTexObj((GXTexObj*)(self+0xb5c+(bank<<11)+(priority<<9)+(lastPalette<<5)), (GXTexMapID)maps[map]);
            GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,(GXTexMapID)maps[map],GX_COLOR_NULL);
        }
        f32 x, z, y, u, v, u2, v2, width, height;
        s32* size = sizes[*((u8*)&object+1)&3][*((u8*)&object+3)&3];
        width=size[0]*8;
        height=size[1]*8;
        if (((u32)*(u16*)((u8*)&object+2)>>7)&0x100) x=(s16)(((u32)*(u16*)((u8*)&object+2)>>7)|0xfe00);
        else x=(u8)((u32)*(u16*)((u8*)&object+2)>>7);
        z=lbl_805414F8;
        y=-(f32)(s8)(*(u8*)&object);
        if (!transformed) {
            x+=origin[0];
            z+=origin[1]+depth;
            y+=origin[2]+depth;
        }
        v=((lbl_80541510*(f32)(int)(((u32)*(u16*)((u8*)&object+4)>>6)&0x3e0))*lbl_80541550+lbl_80541520)*lbl_8054154C;
        u=(lbl_80541510*(f32)(int)(((u32)*(u16*)((u8*)&object+4)>>6)&31)+lbl_80541520)*lbl_8054154C;
        if ((((*((u8*)&object+3))>>3)&1)) {u2=u;u+=(width-lbl_80541518)*lbl_8054154C;}
        else u2=u+(width-lbl_80541518)*lbl_8054154C;
        if ((((*((u8*)&object+3))>>2)&1)) {v2=v;v+=(height-lbl_80541518)*lbl_8054154C;}
        else v2=v+(height-lbl_80541518)*lbl_8054154C;
        GXBegin(GX_QUADS,GX_VTXFMT0,4);
        GXWGFifo.f32=x; GXWGFifo.f32=z; GXWGFifo.f32=y; GXWGFifo.f32=u; GXWGFifo.f32=v;
        GXWGFifo.f32=x+width*scaleX; GXWGFifo.f32=z; GXWGFifo.f32=y; GXWGFifo.f32=u2; GXWGFifo.f32=v;
        GXWGFifo.f32=x+width*scaleX; GXWGFifo.f32=z; GXWGFifo.f32=y-height*scaleY; GXWGFifo.f32=u2; GXWGFifo.f32=v2;
        GXWGFifo.f32=x; GXWGFifo.f32=z; GXWGFifo.f32=y-height*scaleY; GXWGFifo.f32=u; GXWGFifo.f32=v2;
    }
    if (ent && *(s32*)(ent+0x30)!=-1) fn_802F6800(self,pos,(s32)data,frame,0,0,ent);
}

extern GXColor lbl_805414F4;
extern GXColor lbl_80543F60;
#pragma opt_propagation off
extern "C" void fn_802F8F0C(void*, u8* p) {
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);
    GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_REG, GX_SRC_REG, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetNumChans(1);
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
    GXSetNumTexGens(1);
    if (p != NULL) {
        GXSetTevColor(GX_TEVREG0, *(GXColor*)(p + 0x10));
        GXSetTevColor(GX_TEVREG1, *(GXColor*)(p + 0x14));
    } else {
        GXSetTevColor(GX_TEVREG0, lbl_805414F4);
        GXSetTevColor(GX_TEVREG1, lbl_80543F60);
    }
    GXSetTevColorIn(GX_TEVSTAGE0, (GXTevColorArg)0xf, (GXTevColorArg)8, (GXTevColorArg)2, (GXTevColorArg)4);
    GXSetTevAlphaIn(GX_TEVSTAGE0, (GXTevAlphaArg)7, (GXTevAlphaArg)4, (GXTevAlphaArg)1, (GXTevAlphaArg)2);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevSwapMode(GX_TEVSTAGE0, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetNumTevStages(1);
    GXSetNumIndStages(0);
    if (p != NULL && *(s32*)(p + 0x34) == 1) {
        GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_ONE, GX_LO_NOOP);
    } else if (p != NULL && *(s32*)(p + 0x34) == 2) {
        GXSetBlendMode(GX_BM_BLEND, GX_BL_DSTALPHA, GX_BL_INVDSTALPHA, GX_LO_NOOP);
    } else {
        GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_NOOP);
    }
    if (p != NULL) {
        u8 enable = p[0x26];
        u8 update = p[0x2c];
        GXCompare compare = *(GXCompare*)(p + 0x28);
        GXSetZMode(enable, compare, update);
    } else {
        GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
    }
    GXSetZCompLoc(GX_FALSE);
    GXSetColorUpdate(GX_TRUE);
    if (p != NULL) {
        GXSetAlphaUpdate(*(u8*)(p + 0x2d));
        GXSetAlphaCompare(GX_GREATER, *(u8*)(p + 0x2e), GX_AOP_AND, GX_ALWAYS, 0);
    } else {
        GXSetAlphaUpdate(GX_FALSE);
        GXSetAlphaCompare(GX_GREATER, 0, GX_AOP_AND, GX_ALWAYS, 0);
    }
    GXSetCullMode(GX_CULL_NONE);
}
#pragma opt_propagation reset
extern "C" void fn_802F91AC(void* self, f32* __restrict p, u8* o, u8* out, f32 f) {
    Mtx m;
    *out = 0;
    if ((o && *(void**)(o+0x18)) || (0.0f != p[2] && (!o || o[0x1f]))) {
        if (o && *(void**)(o+0x18)) {
            JMath::gekko_ps_copy12(m, *(void**)(o+0x18));
            if (0.0f == m[0][0] && 0.0f == m[1][1] && 0.0f == m[2][2]) {
                m[0][0] = lbl_80541518;
                m[1][1] = lbl_80541518;
                m[2][2] = lbl_80541518;
            }
        } else PSMTXIdentity(m);
        if (0.0f != p[2] && (!o || o[0x1f])) {
            f32 s = fn_802F5FF4(p[2]);
            m[0][0] *= s; m[1][0] *= s; m[2][0] *= s;
            m[0][1] *= s; m[1][1] *= s; m[2][1] *= s;
            m[0][2] *= s; m[1][2] *= s; m[2][2] *= s;
            m[0][3] *= s; m[1][3] *= s; m[2][3] *= s;
        }
        m[0][3] += p[0];
        m[1][3] += p[1] + f;
        m[2][3] += p[2] + f;
        fn_8013B3CC(lbl_8053AB10,m);
        *out = 1;
    } else fn_8013B3F0(lbl_8053AB10);
}

#pragma opt_lifetimes off
#pragma opt_common_subs on
#pragma opt_propagation off
extern "C" void fn_802F93F4(u8* this_, u8* src, u32 srcOff, u32 idx, u32 dstOff, u32 n, u8 flag) {
    u8 swap = flag;
    u8* self = this_;
    u32 index;
    u8* dst;
    u8* slot;
    u32 size;
    u32 entry = idx;


    if (n == 0) {
        s32 result;
        if (checkCompressed__9JKRDecompFPUc(src)) {
            result = (src[4] << 24) | (src[5] << 16) | (src[6] << 8) | src[7];
        } else {
            result = (*(JKRArchive**)((u8*)lbl_8053AAF8 + 0xa4))->getResSize(src);
        }
        if (result < 0) size = 0x200;
        else size = result;
    } else {
        size = n;
    }
    index = entry * 4;
    slot = self + index;
    dst = *(u8**)(slot + 0x98) + dstOff;
    u8* data;
    if (checkCompressed__9JKRDecompFPUc(src)) {
        decode__9JKRDecompFPUcPUcUlUl(src, *(u8**)(self + 0xf8), 0x8000, 0);
        data = *(u8**)(self + 0xf8);
    } else {
        data = src;
    }
    u32 length = size;
    s32 k;
    u8* input = data + srcOff;
    for (k = 0; (u32)k < size; k += 2) {
        u16 v;
        if (k != 0 && !(k & 0x1f)) {
            v = 0;
        } else {
            u16 t = (input[k + 1] << 8) | input[k];
            v = ((t & 31) << 10) | (t & 0x3e0) | ((t >> 10) & 31) | 0x8000;
            if (k == 0) v = 0;
        }
        dst[k] = v >> 8;
        dst[k+1] = v;
    }
    u8* output = ((u8**)(self + 0xc8))[entry] + dstOff;
    u8* colors = *(u8**)(slot + 0x98) + dstOff;
    for (k = 0; (u32)k < length; k += 2) {
        u16 v = (colors[k] << 8) | colors[k+1];
        if (v & 0x8000) {
            u8 a = Tu802F93F4_c5((v >> 10) & 31);
            u8 b = Tu802F93F4_c5((v >> 5) & 31);
            u8 c = Tu802F93F4_c5(v & 31);
            if (swap) v = 0x8000 | (c << 10) | (a << 5) | b;
            else v = 0x8000 | (a << 10) | (b << 5) | c;
        }
        output[k] = v >> 8;
        output[k+1] = v;
    }
    DCFlushRange(output, length);
}
#pragma opt_propagation on
#pragma opt_lifetimes on
extern "C" void fn_802F9714(u8* this_, u8* src, u32 a, s32 idx, u8* dst, u32 size) {
    u8* base;
    u8* s;
    u8* d;
    u32 i;
    u32 len;
    s32 n;
    u8* self = this_;
    if (size == 0) {
        s32 r;
        if (JKRDecomp::checkCompressed(src)) {
            r = (src[4] << 24) | (src[5] << 16) | (src[6] << 8) | src[7];
        } else {
            void* obj = *(void**)((u8*)lbl_8053AAF8 + 0xa4);
            void** vt = *(void***)obj;
            r = ((s32 (*)(void*, u8*))vt[12])(obj, src);
        }
        if (r < 0) {
            len = 0x8000;
        } else {
            len = r;
        }
    } else {
        len = size;
    }
    dst += *(u32*)(self + idx * 4 + 0x88);
    if (JKRDecomp::checkCompressed(src)) {
        JKRDecomp::decode(src, *(u8**)(self + 0xf8), 0x8000, 0);
        base = *(u8**)(self + 0xf8);
    } else {
        base = src;
    }
    base += a;
    i = 0;
    if (len != 0) {
        if (len > 8) {
            for (n = len - 8; n > 0; n -= 8) {
                s = base + i;
                d = dst + i;
                d[0] = (s[0] >> 4) | (s[0] << 4);
                d[1] = (s[1] >> 4) | (s[1] << 4);
                d[2] = (s[2] >> 4) | (s[2] << 4);
                d[3] = (s[3] >> 4) | (s[3] << 4);
                d[4] = (s[4] >> 4) | (s[4] << 4);
                d[5] = (s[5] >> 4) | (s[5] << 4);
                d[6] = (s[6] >> 4) | (s[6] << 4);
                d[7] = (s[7] >> 4) | (s[7] << 4);
                i += 8;
            }
        }
        s = base + i;
        d = dst + i;
        for (n = len - i; n > 0; n--) {
            u8 b = *s++;
            *d++ = (b >> 4) | (b << 4);
        }
    }
    DCFlushRange(dst, len);
}

extern f32 lbl_80541518;
extern "C" void fn_802F86CC(Tu802F5040Tbl* base, void* elem, s32 a, s32 b, void* ptr, f32 f1, f32 f2);
extern "C" void fn_802F745C(Tu802F5040Tbl* base, void* elem, s32 a, void* ptr);
extern "C" void fn_802F6CF4(Tu802F5040Tbl* base, void* elem, s32 a, void* ptr);
extern "C" void fn_802FEE68(Tu802F5040Tbl* base);
extern "C" u16 fn_802F9908(Tu802F5040Tbl* base, s32 idx, s32 off) {
    s32 v;
    if (idx >= 0 && idx < 4) {
        v = *(u16*)(base->m_tbl[idx] + off * 2);
    } else if (idx >= 4 && idx < 8) {
        v = *(u16*)(base->m_tbl[idx] + off * 2);
    } else {
        v = *(u16*)(base->m_tbl[idx] + off * 2);
    }
    return (u16)v;
}

extern "C" void fn_802F9974(Tu802F5040Tbl* base, s32 idx, s32 off, u16 val) {
    if (idx >= 0 && idx < 4) {
        *(u16*)(base->m_tbl[idx] + off * 2) = val;
    } else if (idx >= 4 && idx < 8) {
        *(u16*)(base->m_tbl[idx] + off * 2) = val;
    } else {
        *(u16*)(base->m_tbl[idx] + off * 2) = val;
    }
}

#pragma opt_propagation off
extern "C" void fn_802F99DC(Tu802F5040Tbl* this_, u8* src, u32 a, s32 idx, u32 dst, u32 size) {
    u8* buf;
    u8* base;
    u16* d;
    u32 i;
    u32 len;
    if (size == 0) {
        s32 r;
        if (JKRDecomp::checkCompressed(src)) {
            r = (src[4] << 24) | (src[5] << 16) | (src[6] << 8) | src[7];
        } else {
            JKRArchive* obj = *(JKRArchive**)((u8*)lbl_8053AAF8 + 0xa4);
            r = obj->getResSize(src);
        }
        if (r < 0) len = 0x2000;
        else len = r;
    } else len = size;
    if (JKRDecomp::checkCompressed(src)) {
        JKRDecomp::decode(src, *(u8**)((u8*)this_ + 0xf8), 0x8000, 0);
        buf = *(u8**)((u8*)this_ + 0xf8);
    } else buf = src;
    base = buf + a;
    if (idx >= 0 && idx < 4) {
        d = (u16*)this_->m_tbl[idx] + dst / 2;
    } else if (idx >= 4 && idx < 8) {
        d = (u16*)this_->m_tbl[idx] + dst / 2;
    } else {
        d = (u16*)this_->m_tbl[idx] + dst / 2;
    }
    for (i = 0; i < len; i += 2) {
        u16 value = (base[i+1] << 8) | base[i];
        d[i / 2] = value;
    }
}
#pragma opt_propagation reset
extern "C" void fn_802F9BE8(u8* param_1, u8* param_2, s32 param_3, u32 param_4, u32 param_5)
{
  u32 size;
  s32 sz;
  u8* buf;
  u8* p;
  u32 i;

  if (param_5 == 0) {
    if (checkCompressed__9JKRDecompFPUc(param_2) != 0) {
      sz = ((u32)param_2[4] << 24) | ((u32)param_2[5] << 16) | ((u32)param_2[6] << 8) | (u32)param_2[7];
    } else {
      void* obj = *(void**)((u8*)lbl_8053AAF8 + 0xa4);
      sz = ((s32 (*)(void*, u8*))(*(void***)obj)[12])(obj, param_2);
    }
    if (sz < 0) {
      size = 0x2000;
    } else {
      size = sz;
    }
  } else {
    size = param_5;
  }
  if (checkCompressed__9JKRDecompFPUc(param_2) != 0) {
    decode__9JKRDecompFPUcPUcUlUl(param_2, *(u8**)(param_1 + 0xf8), 0x8000, 0);
    buf = *(u8**)(param_1 + 0xf8);
  } else {
    buf = param_2;
  }
  p = buf + param_3;
  for (i = param_4; i < size; i += 2) {
    (*(u16**)(param_1 + 0x24))[i >> 1] = ((p + i)[1] << 8) | (p + i)[0];
  }
}

#pragma opt_propagation off
extern "C" void fn_802F9DA8(u8* this_, u8* src, u32 srcOff, s32 idx, u32 dstOff, u32 size, u8 flag) {
    u8* base;
    int i;
    u8* __restrict d;
    u8* __restrict s;
    s32 len;
    u16 keep;
    if (size == 0) {
        s32 r;
        if (JKRDecomp::checkCompressed(src)) {
            r = (src[4] << 24) | (src[5] << 16) | (src[6] << 8) | src[7];
        } else {
            r = (*(JKRArchive**)((u8*)lbl_8053AAF8+0xa4))->getResSize(src);
        }
        if (r < 0) {
            len = 0x200;
        } else {
            len = r;
        }
    } else {
        len = size;
    }
    if (JKRDecomp::checkCompressed(src)) {
        JKRDecomp::decode(src, *(u8**)(this_ + 0xf8), 0x8000, 0);
        base = *(u8**)(this_ + 0xf8);
    } else {
        base = src;
    }
    s32 offset = idx * 4;
    u8* table = this_ + offset;
    u32 length = len;
    d = *(u8**)(table + 0xc) + dstOff;
    s = (u8*)(srcOff + (u32)base);
    for (i = 0; (u32)i < length; i += 2) {
        u16 v;
        if (i != 0 && !(i & 0x1f)) v=0;
        else {
            u16 w=s[0] | (s[1]<<8);
            v=((w & 0x1f)<<10) | (w & 0x3e0) | ((w>>10)&0x1f) | 0x8000;
            if (i==0) {keep=v; v=0;}
        }
        d[i] = v >> 8;
        d[i + 1] = v;
        s += 2;
    }
    u8* timer = this_ + idx * 2;
    *(u16*)(timer + 0x114) = keep;
    {
        u8* t = *(u8**)(table + 0xc);
        u16 w = (t[0x1b0] << 8) | t[0x1b1];
        s32 x = (u16)(((w >> 3) & 0xf00) | 0x4000 | ((w >> 2) & 0xf0) | ((w >> 1) & 0xf));
        t[0x1b0] = (s32)x >> 8;
        t[0x1b1] = x;
    }
    {
        u8* t = *(u8**)(table + 0xc);
        u16 w = (t[0x1b2] << 8) | t[0x1b3];
        s32 x = (u16)(((w >> 3) & 0xf00) | 0x4000 | ((w >> 2) & 0xf0) | ((w >> 1) & 0xf));
        t[0x1b2] = x >> 8;
        t[0x1b3] = x;
    }
    {
        u8* t = *(u8**)(table + 0xc);
        u16 w = (t[0x1b4] << 8) | t[0x1b5];
        s32 x = (u16)(((w >> 3) & 0xf00) | 0x4000 | ((w >> 2) & 0xf0) | ((w >> 1) & 0xf));
        t[0x1b4] = x >> 8;
        t[0x1b5] = x;
    }
    s = *(u8**)(table + 0xc) + dstOff;
    u8* outputTable = this_;
    outputTable += offset;
    d = *(u8**)(outputTable + 0x18) + dstOff;
    for (i = 0; (u32)i < length; i += 2) {
        u16 v = (s[i] << 8) | s[i + 1];
        if (v & 0x8000) {
            s32 r;
            u8 c,b,a;
            u16 pixel = v;
            r=(s32)__fmadds((f32)((pixel>>10)&31),lbl_80541518,lbl_805414F8);
            if(r<0) r=0; else if(r>31) r=31;
            a=r;
            r=(s32)__fmadds((f32)((pixel>>5)&31),lbl_80541518,lbl_805414F8);
            if(r<0) r=0; else if(r>31) r=31;
            b=r;
            r=(s32)__fmadds((f32)(pixel&31),lbl_80541518,lbl_805414F8);
            if(r<0) r=0; else if(r>31) r=31;
            c=r;
            if (flag != 0) {
                v = 0x8000 | (c << 10) | (a << 5) | b;
            } else {
                v = 0x8000 | (a << 10) | (b << 5) | c;
            }
        }
        d[i] = v >> 8;
        d[i + 1] = v;
    }
    DCFlushRange(d, length);
}
#pragma opt_propagation reset
extern "C" void fn_802FA160(u8* this_, const u8* src, u32 a, s32 idx, u8* dst, u32 size) {
    u8* __restrict out; u8* self; s32 index;
    self=this_; index=idx; out=dst;
    s32 len;
    const u8* __restrict base;
    if(size==0) {
        s32 r;
        if(JKRDecomp::checkCompressed((u8*)src)) r=(src[4]<<24)|(src[5]<<16)|(src[6]<<8)|src[7];
        else r=(*(JKRArchive**)((u8*)lbl_8053AAF8+0xa4))->getResSize(src);
        if(r<0) len=0x8000;
        else len=r;
    } else len=size;
    u32* __restrict table=(u32*)(self+index*4);
    out= (u8*)table[1]+(u32)out;
    if(JKRDecomp::checkCompressed((u8*)src)) {
        JKRDecomp::decode((u8*)src,*(u8**)(self+0xf8),0x8000,0);
        base=*(u8**)(self+0xf8);
    } else base=src;
    base+=a;
    for(u32 i=0;i<(u32)len;i++) {
        u32 b=base[i];
        out[i]=((b&240)>>4)|((b&15)<<4);
    }
    DCFlushRange(out,len);
    if(index==1) {
        u8* p=*(u8**)(self+8)+0x200;
        u8* q=*(u8**)(self+0x238c);
        for(u32 i=0;i<0x100;i++) *q++=*p++;
    }
}
extern "C" f32 lbl_80541524;
extern "C" f32 lbl_80541564;
extern "C" f32 lbl_80541568;
extern "C" f32 lbl_8054156C;
extern "C" f32 lbl_80541570;
extern "C" f32 lbl_80541578;
extern "C" GXColor lbl_80543F54;
extern "C" GXColor lbl_80543F58;
extern "C" GXColor lbl_80543F5C;
extern "C" void fn_802FA3FC(void* mgr) {
    f32 k;
    u8* cur;
    s32 cnt;
    s32 c;
    u16* map;
    s32 row;
    s32 col;
    u16 key;
    s32 j;
    u8* ent;
    f32 ox;
    f32 oy;
    f32 ex;
    f32 ey;
    f32 px;
    f32 py;
    s32 n;
    s32 a;
    s32 b;
    u8 alpha;
    void* res;
    char tex[0x40];
    u8* p = (u8*)mgr;
    u8* base = lbl_8046F940;

    k = lbl_80541518;
    c = (s8)*(u8*)fn_802D9C4C(fn_802D6A9C());
    res = ((Tu802F5040ResMgr*)*(void**)((u8*)lbl_8053AAF8 + 0xa4))->getResource(0x54494D47, (const char*)(base + 0x1888));
    *(s32*)(tex + 0x28) = 0;
    storeTIMG__10JUTTextureFPC7ResTIMGUc(tex, res, 0);
    tex[0x3b] &= 2;
    switch (c) {
    case 0x63:
        cur = base + 0xba8;
        cnt = 6;
        break;
    case 0x62:
        cur = base + 0x680;
        cnt = 0x21;
        break;
    case 0x65:
        cur = base + 0xc98;
        cnt = 0x25;
        break;
    case 0x66:
        k = lbl_80541560;
        cur = base + 0x130;
        cnt = 0x22;
        break;
    case 0x69:
        cur = base + 0x1260;
        cnt = 0x18;
        break;
    default:
        cur = base + 0x130;
        cnt = 0x22;
        break;
    }
    fn_8013B438(lbl_8053AB10);
    fn_8013B1E8(lbl_8053AB10);
    GXSetTevSwapMode(GX_TEVSTAGE0, GX_TEV_SWAP0, GX_TEV_SWAP1);
    GXSetTevSwapModeTable(GX_TEV_SWAP1, GX_CH_ALPHA, GX_CH_ALPHA, GX_CH_ALPHA, GX_CH_RED);
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_SET);
    load__10JUTTextureF11_GXTexMapID(tex, GX_TEXMAP0);
    for (n = 0; n < 2; n++) {
        if (n == 0) {
            ox = *(f32*)(p + 0x2368);
            oy = *(f32*)(p + 0x236c);
            map = *(u16**)(p + 0x28);
        } else {
            ox = *(f32*)(p + 0x2374);
            oy = *(f32*)(p + 0x2378);
            map = *(u16**)(p + 0x38);
        }
        if ((n == 0 && p[0x235c]) || (n == 1 && p[0x2361])) {
            for (a = 0; a < 2; a++) {
                for (b = 0; b < 2; b++) {
                    for (row = 0; row < 16 && a * 16 + row < *(s32*)(p + 0x2384) / 2; row++) {
                        py = 614.4f + (16.0f * (f32)(a * 16 + row) + oy);
                        for (col = 0; col < 16 && b * 16 + col < *(s32*)(p + 0x2380) / 2; col++) {
                            key = map[((a * 2 + b) * 16 + row) * 16 + col];
                            px = 16.0f * (f32)(b * 16 + col) + ox;
                            ent = cur;
                            for (j = 0; j < cnt; j++, ent += 0x28) {
                                if (*(u16*)ent != key) {
                                    continue;
                                }
                                ex = px + *(f32*)(ent + 0xc);
                                ey = py + *(f32*)(ent + 0x10);
                                alpha = (u8)((f32)ent[0xb] * k);
                                if (c == 0x62) {
                                    if (*(f32*)(ent + 0xc) < 8.0f) {
                                        ex += 3.0f;
                                    } else {
                                        ex -= 3.0f;
                                    }
                                    if (*(f32*)(ent + 0x10) < 8.0f) {
                                        ey += 3.0f;
                                    } else {
                                        ey -= 3.0f;
                                    }
                                }
                                switch (*(s32*)(ent + 0x14)) {
                                case 0: {
                                    GXColor color = lbl_80543F54;
                                    color.a = alpha;
                                    f32 ux = *(f32*)(ent + 0x18) * lbl_80541500;
                                    f32 uy = *(f32*)(ent + 0x1c) * lbl_80541500;
                                    f32 vx = *(f32*)(ent + 0x20) * lbl_80541500;
                                    f32 vy = *(f32*)(ent + 0x24) * lbl_80541500;
                                    GXSetTevColor(GX_TEVREG0, color);
                                    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
                                    GXWGFifo.f32 = ex; GXWGFifo.f32 = ey; GXWGFifo.f32 = 614.4f;
                                    GXWGFifo.f32 = 0.0f; GXWGFifo.f32 = 0.0f;
                                    GXWGFifo.f32 = ex + ux; GXWGFifo.f32 = ey + uy; GXWGFifo.f32 = 614.4f;
                                    GXWGFifo.f32 = 1.0f; GXWGFifo.f32 = 0.0f;
                                    GXWGFifo.f32 = vx + (ex + ux); GXWGFifo.f32 = vy + (ey + uy); GXWGFifo.f32 = 614.4f;
                                    GXWGFifo.f32 = 1.0f; GXWGFifo.f32 = 1.0f;
                                    GXWGFifo.f32 = ex + vx; GXWGFifo.f32 = ey + vy; GXWGFifo.f32 = 614.4f;
                                    GXWGFifo.f32 = 0.0f; GXWGFifo.f32 = 1.0f;
                                    break;
                                }
                                case 1: {
                                    GXColor color = lbl_80543F58;
                                    color.a = alpha;
                                    f32 ux = *(f32*)(ent + 0x18) * lbl_8054156C;
                                    f32 uy = *(f32*)(ent + 0x1c) * lbl_8054156C;
                                    f32 hx = *(f32*)(ent + 0x20) * lbl_80541570;
                                    f32 hy = *(f32*)(ent + 0x24) * lbl_80541570;
                                    GXSetTevColor(GX_TEVREG0, color);
                                    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
                                    f32 x0 = ex - hx;
                                    f32 y0 = ey - hy;
                                    f32 x1 = ex + hx;
                                    f32 y1 = ey + hy;
                                    GXWGFifo.f32 = x0; GXWGFifo.f32 = y0; GXWGFifo.f32 = 614.4f;
                                    GXWGFifo.f32 = 0.0f; GXWGFifo.f32 = -1.0f;
                                    GXWGFifo.f32 = ux + x0; GXWGFifo.f32 = uy + y0; GXWGFifo.f32 = 614.4f;
                                    GXWGFifo.f32 = 1.0f; GXWGFifo.f32 = -1.0f;
                                    GXWGFifo.f32 = ux + x1; GXWGFifo.f32 = uy + y1; GXWGFifo.f32 = 614.4f;
                                    GXWGFifo.f32 = 1.0f; GXWGFifo.f32 = 1.0f;
                                    GXWGFifo.f32 = x1; GXWGFifo.f32 = y1; GXWGFifo.f32 = 614.4f;
                                    GXWGFifo.f32 = 0.0f; GXWGFifo.f32 = 1.0f;
                                    break;
                                }
                                case 2: {
                                    GXColor color = lbl_80543F5C;
                                    f32 ux = *(f32*)(ent + 0x18);
                                    f32 uy = *(f32*)(ent + 0x1c);
                                    f32 wx = ux;
                                    f32 wy = uy;
                                    color.a = alpha;
                                    ux *= lbl_8054156C;
                                    uy *= lbl_8054156C;
                                    f32 hx = *(f32*)(ent + 0x20) * lbl_80541570;
                                    f32 hy = *(f32*)(ent + 0x24) * lbl_80541570;
                                    wx *= lbl_80541578;
                                    wy *= lbl_80541578;
                                    GXSetTevColor(GX_TEVREG0, color);
                                    GXBegin(GX_QUADS, GX_VTXFMT0, 8);
                                    f32 x0 = ex - hx;
                                    f32 y0 = ey - hy;
                                    f32 x1 = ex + hx;
                                    f32 y1 = ey + hy;
                                    GXWGFifo.f32 = x0; GXWGFifo.f32 = y0; GXWGFifo.f32 = 614.4f;
                                    GXWGFifo.f32 = 0.0f; GXWGFifo.f32 = -1.0f;
                                    GXWGFifo.f32 = ux + x0; GXWGFifo.f32 = uy + y0; GXWGFifo.f32 = 614.4f;
                                    GXWGFifo.f32 = 1.0f; GXWGFifo.f32 = -1.0f;
                                    GXWGFifo.f32 = ux + x1; GXWGFifo.f32 = uy + y1; GXWGFifo.f32 = 614.4f;
                                    GXWGFifo.f32 = 1.0f; GXWGFifo.f32 = 1.0f;
                                    GXWGFifo.f32 = x1; GXWGFifo.f32 = y1; GXWGFifo.f32 = 614.4f;
                                    GXWGFifo.f32 = 0.0f; GXWGFifo.f32 = 1.0f;
                                    GXWGFifo.f32 = x0; GXWGFifo.f32 = y0; GXWGFifo.f32 = 614.4f;
                                    GXWGFifo.f32 = 0.0f; GXWGFifo.f32 = -1.0f;
                                    GXWGFifo.f32 = wx + x0; GXWGFifo.f32 = wy + y0; GXWGFifo.f32 = 614.4f;
                                    GXWGFifo.f32 = 1.0f; GXWGFifo.f32 = -1.0f;
                                    GXWGFifo.f32 = wx + x1; GXWGFifo.f32 = wy + y1; GXWGFifo.f32 = 614.4f;
                                    GXWGFifo.f32 = 1.0f; GXWGFifo.f32 = 1.0f;
                                    GXWGFifo.f32 = x1; GXWGFifo.f32 = y1; GXWGFifo.f32 = 614.4f;
                                    GXWGFifo.f32 = 0.0f; GXWGFifo.f32 = 1.0f;
                                    break;
                                }
                                }
                                if (ent[0xa] == 0) {
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    __dt__10JUTTextureFv(tex, -1);
}

#pragma opt_loop_invariants off
extern "C" void fn_802FAC10(u8* self, s32 plane, s32 scrollX, s32 scrollY, s32 paletteFlag, u8 shade, u8 alpha, s32* wave) {
    GXTexObj texture;
    s32 counts[16];
    GXTlutObj tluts[16];
    f32 shifts[3];
    if (scrollX>0x180) scrollX-=0x200;
    if (scrollY>0x180) scrollY-=0x200;
    f32 ox=-scrollX;
    f32 oy=-scrollY;
    fn_8013B1E8(lbl_8053AB10);
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
    GXSetVtxDesc(GX_VA_TEX0,GX_INDEX16);
    GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_POS_XYZ,GX_F32,0);
    GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_TEX_ST,GX_F32,0);
    GXSetArray(GX_VA_TEX0,*(void**)(self+0x110),8);
    if (shade==255 && alpha==255) {
        GXSetTevColor(GX_TEVREG0,lbl_805414F0);
        GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
        GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO,GX_CC_TEXC);
        GXSetTevAlphaIn(GX_TEVSTAGE0,(GXTevAlphaArg)4,(GXTevAlphaArg)1,(GXTevAlphaArg)6,GX_CA_ZERO);
        GXSetTevAlphaOp(GX_TEVSTAGE0,(GXTevOp)14,GX_TB_ZERO,GX_CS_SCALE_1,GX_TRUE,GX_TEVPREV);
    } else {
        GXSetTevColor(GX_TEVREG0,TileShade802F(shade,alpha));
        GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
        GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_ZERO,(GXTevColorArg)8,(GXTevColorArg)9,GX_CC_ZERO);
        GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO);
        GXSetTevOrder(GX_TEVSTAGE1,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
        GXSetTevColorIn(GX_TEVSTAGE1,GX_CC_ZERO,(GXTevColorArg)0,(GXTevColorArg)2,GX_CC_ZERO);
        GXSetTevAlphaIn(GX_TEVSTAGE1,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,(GXTevAlphaArg)1);
        GXSetTevColorOp(GX_TEVSTAGE1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,GX_TRUE,GX_TEVPREV);
        GXSetTevAlphaOp(GX_TEVSTAGE1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,GX_TRUE,GX_TEVPREV);
        GXSetTevSwapMode(GX_TEVSTAGE1,GX_TEV_SWAP0,GX_TEV_SWAP0);
        GXSetTevDirect(GX_TEVSTAGE1);
        GXSetNumTevStages(2);
    }
    GXSetBlendMode(GX_BM_BLEND,GX_BL_ONE,GX_BL_SRCALPHA,(GXLogicOp)5);
    GXSetZMode(GX_FALSE,GX_LEQUAL,GX_FALSE);
    GXSetCullMode(GX_CULL_NONE);
    u16* map=((u16**)(self+0x48))[plane];
    s32 palette;
    if ((plane&7)==0 || paletteFlag) palette=1;
    else palette=2;
    int paletteOffset=palette*4+0x18;
    GXTlutObj* tlut=tluts;
    for (int i=0;i<16;i++,tlut++) {
        GXInitTlutObj(tlut,*(u8**)(self+paletteOffset)+i*0x20,GX_TL_RGB5A3,16);
        GXLoadTlut(tlut,lbl_8046FA30[i]);
    }
    s32* paletteCounts=counts;
    counts[0]=0;
    counts[1]=0;
    counts[2]=0;
    counts[3]=0;
    counts[4]=0;
    counts[5]=0;
    counts[6]=0;
    counts[7]=0;
    counts[8]=0;
    counts[9]=0;
    counts[10]=0;
    counts[11]=0;
    counts[12]=0;
    counts[13]=0;
    counts[14]=0;
    counts[15]=0;
    for (int sy=0;sy<2;sy++) {
        for (int sx=0;sx<2;sx++) {
            for (int row=0;row<16;row++) {
                s32 py=(sy*32+row*2)*8-scrollY;
                if (py<=-16 || py>=160) continue;
                for (int col=0;col<16;col++) {
                    s32 px=(sx*32+col*2)*8-scrollX;
                    if (wave || (px>-16 && px<240)) {
                        u16 tile=map[((sy*2+sx)*16+row)*16+col];
                        if (tile) {
                            u16* list=*(u16**)(self+0x24);
                            for (int dy=0;dy<2;dy++) {
                                for (int dx=0;dx<2;dx++) counts[(list[tile*4+dy*2+dx]>>12)&15]++;
                            }
                        }
                    }
                }
            }
        }
    }
    for (int pal=0;pal<16;pal++) {
        if (paletteCounts[pal]<=0) continue;
        GXInitTexObjCI(&texture,*(void**)(self+8),128,512,GX_TF_C4,GX_CLAMP,GX_CLAMP,GX_FALSE,lbl_8046FA30[pal]);
        GXLoadTexObj(&texture,GX_TEXMAP0);
        GXBegin(GX_QUADS,GX_VTXFMT0,paletteCounts[pal]*4);
        for (int sy=0;sy<2;sy++) {
            for (int sx=0;sx<2;sx++) {
                for (int row=0;row<16;row++) {
                    s32 ty=sy*32+row*2;
                    s32 py=ty*8-scrollY;
                    if (py<=-16 || py>=160) continue;
                    if (wave) {
                        for (int j=0;j<3;j++) {
                            shifts[j]=lbl_805414F8;
                            s32 y=py+j*8;
                            for (int n=0;n<8;n++,y++) {
                                s32 idx;
                                if (y<0) idx=0;else if (y>159) idx=159;else idx=y;
                                shifts[j]-=wave[idx];
                            }
                            shifts[j]*=lbl_80541514;
                        }
                        f32 shiftTop=shifts[0];
                        f32 shiftMiddle=shifts[1];
                        f32 shiftBottom=shifts[2];
                        for (int col=0;col<16;col++) {
                            u16 tile=map[((sy*2+sx)*16+row)*16+col];
                            if (!tile) continue;
                            s32 tx=sx*32+col*2;
                            f32 x=ox+(f32)(tx*8);
                            if (x+shiftTop<lbl_8054157C && x+shiftMiddle<lbl_8054157C && x+shiftBottom<lbl_8054157C) x+=lbl_80541580;
                            else if (x+shiftTop>lbl_80541584 && x+shiftMiddle>lbl_80541584 && x+shiftBottom>lbl_80541584) x-=lbl_80541580;
                            s32 subY=ty;
                            for (int dy=0;dy<2;dy++,subY++) {
                                f32 y=oy+(f32)(subY*8);
                                for (int dx=0;dx<2;dx++) {
                                    u16 t=(*(u16**)(self+0x24))[tile*4+dy*2+dx];
                                    if (((t>>12)&15)==pal) {
                                        WarpTileQuad802F(t,x+(f32)(dx*8),y,shifts[dy],shifts[dy+1]);
                                    }
                                }
                            }
                        }
                    } else {
                        for (int col=0;col<16;col++) {
                            s32 tx=sx*32+col*2;
                            s32 px=tx*8-scrollX;
                            if (px<=-16 || px>=240) continue;
                            u16 tile=map[((sy*2+sx)*16+row)*16+col];
                            if (!tile) continue;
                            s32 subY=ty;
                            for (int dy=0;dy<2;dy++,subY++) {
                                f32 y=oy+(f32)(subY*8);
                                s32 subX=tx;
                                for (int dx=0;dx<2;dx++,subX++) {
                                    u16 t=(*(u16**)(self+0x24))[tile*4+dy*2+dx];
                                    if (((t>>12)&15)==pal) PlainTileQuad802F(t,ox+(f32)(subX*8),y);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

extern "C" void fn_8013B414(void*, void*, s32);
extern "C" void fn_8013B004(void*, const GXColor*);
extern "C" void* fn_8022BCD4(s32);
extern "C" s32* fn_8030B1E8(void*, s32, s32, u16);
extern "C" void fn_8030275C(u8*, s32, u8, u8);
extern "C" void fn_803022C4(u8*, s32, u8, u8);
extern "C" GXColor lbl_805414EC;
extern "C" void fn_802FAC10(u8*, s32, s32, s32, s32, u8, u8, s32*);
#pragma opt_loop_invariants reset
#pragma opt_common_subs on
extern "C" const f32 lbl_80541588,lbl_8054158C,lbl_80541590,lbl_80541594;
extern "C" void fn_8030DFE8(void*,s32);
#pragma opt_common_subs on
#pragma opt_strength_reduction off
extern "C" void fn_802FB69C(u8* self, s32 player, s32 registerPtr, u8* rectData, u8* viewportData, u8 enabled, s32 effect, u8 opacity) {
    s32* rect=(s32*)rectData;
    s32* viewport=(s32*)viewportData;
    JGeometry::TBox2<f32> box;
    box.set((f32)rect[0],(f32)rect[1],(f32)(rect[0]+rect[2]),(f32)(rect[1]+rect[3]));
    fn_8013B414(lbl_8053AB10,&box,0);
    GXSetViewport(viewport[0],viewport[1],viewport[2],viewport[3],lbl_805414F8,lbl_80541518);
    GXSetScissor(viewport[0],viewport[1],viewport[2],viewport[3]);
    ScrollByte802F* sb=(ScrollByte802F*)registerPtr;
    s32 scrollX=(sb[0xb].hi<<5)|(sb[0xb].bit<<4)|sb[0xf].hi;
    s32 scrollY=(sb[0x13].hi<<5)|(sb[0x13].bit<<4)|sb[0x17].hi;
    s32* wave=NULL;
    void* controller=fn_8022BCD4(player);
    if (enabled) {
        u8 special=0;
        if (((((((u8*)registerPtr)[2]>>2)&7)-1)&7)==0 || self[0x134+player]!=0) special=1;
        u16 color=((u16*)(self+0x114))[special ? 1 : 2];
        fn_8013B3F0(lbl_8053AB10);
        JGeometry::TBox2<f32> bg;
        bg.set((f32)rect[0],(f32)rect[1],(f32)(rect[0]+rect[2]),(f32)(rect[1]+rect[3]));
        GXColor rgb;
        s32 red=color&0x7c00;
        rgb.r=(red>>7)|(red>>12);
        s32 green=(color>>5)&31;
        s32 blue=color&31;
        rgb.g=(green<<3)|(green>>2);
        rgb.b=(blue<<3)|(blue>>2);
        rgb.a=255;
        fn_8013B004(&bg,&rgb);
        if ((((u8*)registerPtr)[0x17]>>3)&1) {
            u8* game=(u8*)lbl_8053AAF8;
            if ((!RendererStage11_802F() && game[0x88]==0) || RendererFadeAlpha802F()<255) {
                s32 mode=(((u8*)registerPtr)[2]>>2)&7;
                s32 selector=6;
                if ((u32)mode<=1 || self[0x134+player]) selector=5;
                else if (((((u8*)registerPtr)[2]>>6)&3)==3) selector=(((u8*)registerPtr)[5]>>4)&3;
                if (controller) wave=fn_8030B1E8(controller,mode,selector,(u16)scrollY);
                fn_802FAC10(self,((((u8*)registerPtr)[2]>>2)&7)-1,scrollX,scrollY,self[0x134+player],255,255,wave);
            }
        }
    } else {
        fn_8013B1E8(lbl_8053AB10);
        load__10JUTTextureF11_GXTexMapID(*(void**)(self+0xe454),0);
        GXSetZMode(GX_FALSE,GX_LEQUAL,GX_FALSE);
        GXSetColorUpdate(GX_FALSE);
        GXSetAlphaUpdate(GX_TRUE);
        GXSetAlphaCompare(GX_ALWAYS,0,GX_AOP_AND,GX_ALWAYS,0);
        GXSetBlendMode(GX_BM_BLEND,GX_BL_ONE,GX_BL_ZERO,(GXLogicOp)5);
        GXSetTevColor(GX_TEVREG0,lbl_805414EC);
        GXBegin(GX_QUADS,GX_VTXFMT0,4);
        ScreenMaskQuad802F(rect);
        GXSetColorUpdate(GX_TRUE);
        GXSetAlphaUpdate(GX_FALSE);
        GXSetAlphaCompare(GX_GREATER,0,GX_AOP_AND,GX_ALWAYS,0);
    }
    fn_8030275C((u8*)registerPtr,player,enabled,self[0x134+player]!=0);
    if (enabled) {
        fn_8013B3F0(lbl_8053AB10);
        if ((((u8*)registerPtr)[0x17]>>3)&1) {
            u8* game=(u8*)lbl_8053AAF8;
            if ((!RendererStage11_802F() && game[0x88]==0) || RendererFadeAlpha802F()<255) {
                if (self[0x130+player]==1)
                    fn_802FAC10(self,((((u8*)registerPtr)[2]>>2)&7)+7,scrollX,scrollY,self[0x134+player],128,255,wave);
                else if (self[0x130+player]==2)
                    fn_802FAC10(self,((((u8*)registerPtr)[2]>>2)&7)+7,scrollX,scrollY,self[0x134+player],0,192,wave);
                else fn_802FAC10(self,((((u8*)registerPtr)[2]>>2)&7)+7,scrollX,scrollY,self[0x134+player],255,255,wave);
            }
        }
        u8* game=(u8*)lbl_8053AAF8;
        bool fade;
        if (*(s32*)(game+0x4c)==11) fade=true;
        else fade=game[0x88]==2;
        if (fade) {
            fn_8013B3F0(lbl_8053AB10);
            JGeometry::TBox2<f32> overlay;
            overlay.set((f32)rect[0],(f32)rect[1],(f32)(rect[0]+rect[2]),(f32)(rect[1]+rect[3]));
            GXColor black;
            black.a=RendererFadeAlpha802F();
            black.r=0;black.g=0;black.b=0;
            fn_8013B004(&overlay,&black);
        }
    }
    fn_803022C4((u8*)registerPtr,player,enabled,self[0x134+player]!=0);
    if (effect) {
        s32 step=effect+1;
        fn_8013B3F0(lbl_8053AB10);
        GXClearVtxDesc();
        GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
        GXSetVtxDesc(GX_VA_CLR0,GX_DIRECT);
        GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_POS_XYZ,GX_F32,0);
        GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_CLR0,(GXCompCnt)0,(GXCompType)5,0);
        GXSetChanCtrl((GXChannelID)4,GX_FALSE,GX_SRC_REG,GX_SRC_VTX,0,GX_DF_NONE,GX_AF_NONE);
        GXSetNumChans(1);
        GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,(GXChannelID)4);
        GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO,(GXTevColorArg)10);
        GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,(GXTevAlphaArg)6);
        GXSetNumTevStages(1);
        GXSetBlendMode(GX_BM_BLEND,GX_BL_ONE,GX_BL_ZERO,(GXLogicOp)5);
        GXSetZMode(GX_FALSE,GX_LEQUAL,GX_FALSE);
        GXSetZCompLoc(GX_FALSE);
        GXSetAlphaCompare(GX_ALWAYS,0,GX_AOP_AND,GX_ALWAYS,0);
        GXSetColorUpdate(GX_TRUE);GXSetAlphaUpdate(GX_FALSE);GXSetCullMode(GX_CULL_NONE);
        ((void(*)(s32,s32))GXSetPointSize)((s32)((f32)(viewport[2]*step*6)/lbl_80541584),(GXTexOffset)0);
        GXDrawDone();
        GXBegin((GXPrimitive)0xb8,GX_VTXFMT0,
            (s32)(lbl_80541588+lbl_8054158C/(f32)step)*(s32)(lbl_80541588+lbl_80541584/(f32)step));
        s32 half=step>>1;
        s32 left=viewport[0],top=viewport[1],width=viewport[2],height=viewport[3];
        for (s32 y=half;y<half+160;y+=step) {
            s32 sampleY=(s32)(lbl_80541590*(f32)(height*y)+(f32)top);
            for (s32 x=half;x<half+240;x+=step) {
                u8 color[4];
                s32 sampleX=(s32)(lbl_80541594*(f32)(width*x)+(f32)left);
                ((void(*)(s32,s32,u32*))GXPeekARGB)(sampleX,sampleY,(u32*)color);
                GXWGFifo.f32=(f32)x;
                GXWGFifo.f32=(f32)y;
                GXWGFifo.f32=0.0f;
                GXWGFifo.u8=color[1];GXWGFifo.u8=color[2];GXWGFifo.u8=color[3];GXWGFifo.u8=color[0];
            }
        }
    }
    if (enabled && opacity<255) {
        fn_8013B3F0(lbl_8053AB10);
        JGeometry::TBox2<f32> overlay;
        overlay.set((f32)rect[0],(f32)rect[1],(f32)(rect[0]+rect[2]),(f32)(rect[1]+rect[3]));
        GXColor black={0,0,0,255-opacity};
        fn_8013B004(&overlay,&black);
    }
    fn_8030DFE8(*(void**)((u8*)lbl_8053AB10+0x24),1);
}
#pragma opt_common_subs reset
#pragma opt_strength_reduction reset
extern "C" u32 lbl_8046F9F0[];
extern "C" f32 lbl_80541598;
#pragma opt_lifetimes off
extern "C" void fn_802FC268(u8* self, u8* arr, s32 a, u32 v) {
    JGeometry::TVec3<f32> trans(*(JGeometry::TVec3<f32>*)arr);
    GXTexObj texObj;
    Mtx m;
    s32 cnt[16];
    GXTlutObj tlut[16];
    f32* pos=(f32*)arr;
    u16* idx=(u16*)v;
    f32 k=lbl_80541598*((f32)a-lbl_80541520);
    trans.y+=k;
    trans.z+=k;
    PSMTXTrans(m,trans.x,trans.y,trans.z);
    fn_8013B3CC(lbl_8053AB10,m);
    for(int i=0;i<16;i++) {
        GXInitTlutObj(&tlut[i],*(u8**)(self+0x18)+i*0x20,GX_TL_RGB5A3,16);
        GXLoadTlut(&tlut[i],lbl_8046F9F0[i]);
    }
    for(int i=0;i<16;i++) cnt[i]=0;
    for(int by=0;by<2;by++) {
        for(int bx=0;bx<2;bx++) {
            for(int y=0;y<16 && by*16+y<*(s32*)(self+0x2384)/2;y++) {
                for(int x=0;x<16 && bx*16+x<*(s32*)(self+0x2380)/2;x++) {
                    u16 id=idx[((by*2+bx)*16+y)*16+x];
                    if(id) {
                        u16* lut=*(u16**)(self+0x24);
                        for(int sy=0;sy<2;sy++) for(int sx=0;sx<2;sx++) cnt[(lut[id*4+sy*2+sx]>>12)&15]++;
                    }
                }
            }
        }
    }
    for(int pal=0;pal<16;pal++) {
        if(cnt[pal]>0) {
            GXInitTexObjCI(&texObj,*(void**)(self+4),0x80,0x200,GX_TF_C4,GX_CLAMP,GX_CLAMP,GX_FALSE,lbl_8046F9F0[pal]);
            GXLoadTexObj(&texObj,GX_TEXMAP0);
            GXBegin(GX_QUADS,GX_VTXFMT0,cnt[pal]*4);
            for(int by=0;by<2;by++) {
                for(int bx=0;bx<2;bx++) {
                    for(int y=0;y<16 && by*16+y<*(s32*)(self+0x2384)/2;y++) {
                        for(int x=0;x<16 && bx*16+x<*(s32*)(self+0x2380)/2;x++) {
                            u16 id=idx[((by*2+bx)*16+y)*16+x];
                            if(id) {
                                for(int sy=0;sy<2;sy++) {
                                    for(int sx=0;sx<2;sx++) {
                                        u16 tile=(*(u16**)(self+0x24))[id*4+sy*2+sx];
                                        if(((tile>>12)&15)==pal) {
                                            int px=bx*32+x*2+sx;
                                            int py=by*32+y*2+sy;
                                            u16 vertex=py*65+px;
                                            u16 b=vertex+1;
                                            u16 c=b+65;
                                            u16 d=c-1;
                                            u16 flags=tile&0xfff;
                                            f32 tx=pos[0]+(f32)(px*8);
                                            f32 ty=pos[1]+(f32)(py*8);
                                            f32 scale=lbl_8054152C;
                                            f32 step=lbl_80541534;
                                            tx*=scale;
                                            ty*=scale;
                                            f32 tx1=step+tx;
                                            f32 ty1=step+ty;
                                            (*(volatile PPCWGPipe*)GXFIFO_ADDR).u16=vertex; (*(volatile PPCWGPipe*)GXFIFO_ADDR).u16=vertex; (*(volatile PPCWGPipe*)GXFIFO_ADDR).u16=flags;
                                            (*(volatile PPCWGPipe*)GXFIFO_ADDR).f32=tx; (*(volatile PPCWGPipe*)GXFIFO_ADDR).f32=ty;
                                            (*(volatile PPCWGPipe*)GXFIFO_ADDR).u16=b; (*(volatile PPCWGPipe*)GXFIFO_ADDR).u16=b; (*(volatile PPCWGPipe*)GXFIFO_ADDR).u16=flags^0x400;
                                            (*(volatile PPCWGPipe*)GXFIFO_ADDR).f32=tx1; (*(volatile PPCWGPipe*)GXFIFO_ADDR).f32=ty;
                                            (*(volatile PPCWGPipe*)GXFIFO_ADDR).u16=c; (*(volatile PPCWGPipe*)GXFIFO_ADDR).u16=c; (*(volatile PPCWGPipe*)GXFIFO_ADDR).u16=flags^0xc00;
                                            (*(volatile PPCWGPipe*)GXFIFO_ADDR).f32=tx1; (*(volatile PPCWGPipe*)GXFIFO_ADDR).f32=ty1;
                                            (*(volatile PPCWGPipe*)GXFIFO_ADDR).u16=d; (*(volatile PPCWGPipe*)GXFIFO_ADDR).u16=d; (*(volatile PPCWGPipe*)GXFIFO_ADDR).u16=flags^0x800;
                                            (*(volatile PPCWGPipe*)GXFIFO_ADDR).f32=tx; (*(volatile PPCWGPipe*)GXFIFO_ADDR).f32=ty1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
#pragma opt_lifetimes reset
extern "C" void fn_8013B438(void* mgr);
extern "C" void* fn_802D6A9C();
extern "C" void load__10JUTTextureF11_GXTexMapID(void* tex, s32 id);
extern "C" void fn_802FC268(u8* this_, u8* arr, s32 i, u32 v);
extern "C" u32 lbl_805414E8;
extern "C" void fn_802FC80C(u8* this_) {
    s32 i;
    u8* mgr;
    bool flag;
    s32 idx;

    fn_8013B1E8(lbl_8053AB10);
    fn_8013B438(lbl_8053AB10);
    GXClearVtxDesc();
    GXSetVtxDesc((GXAttr)9, (GXAttrType)3);
    GXSetVtxDesc((GXAttr)0xb, (GXAttrType)3);
    GXSetVtxDesc((GXAttr)0xd, (GXAttrType)3);
    GXSetVtxDesc((GXAttr)0xe, (GXAttrType)1);
    GXSetVtxAttrFmt((GXVtxFmt)0, (GXAttr)9, (GXCompCnt)1, (GXCompType)4, 0);
    GXSetVtxAttrFmt((GXVtxFmt)0, (GXAttr)0xb, (GXCompCnt)0, (GXCompType)5, 0);
    GXSetVtxAttrFmt((GXVtxFmt)0, (GXAttr)0xd, (GXCompCnt)1, (GXCompType)4, 0);
    GXSetVtxAttrFmt((GXVtxFmt)0, (GXAttr)0xe, (GXCompCnt)1, (GXCompType)4, 0);
    GXSetArray((GXAttr)9, ((void**)(this_ + 0x100))[*(s32*)(this_ + 0x2388)], 0xc);
    GXSetArray((GXAttr)0xb, ((void**)(this_ + 0x108))[*(s32*)(this_ + 0x2388)], 4);
    GXSetArray((GXAttr)0xd, *(void**)(this_ + 0x110), 8);
    GXSetChanCtrl((GXChannelID)4, (GXBool)0, (GXColorSrc)0, (GXColorSrc)1, 0, (GXDiffuseFn)0, (GXAttnFn)2);
    GXSetNumChans(1);
    GXSetTexCoordGen2((GXTexCoordID)1, (GXTexGenType)1, (GXTexGenSrc)5, (GXTexMtx)0x3c, (GXBool)0, (GXPTTexMtx)0x7d);
    GXSetNumTexGens(2);
    GXSetTevOrder((GXTevStageID)0, (GXTexCoordID)0, (GXTexMapID)0, (GXChannelID)4);
    GXSetTevColorIn((GXTevStageID)0, (GXTevColorArg)0xf, (GXTevColorArg)0xc, (GXTevColorArg)0xa, (GXTevColorArg)8);
    GXSetTevAlphaIn((GXTevStageID)0, (GXTevAlphaArg)7, (GXTevAlphaArg)6, (GXTevAlphaArg)5, (GXTevAlphaArg)4);
    GXSetTevColorOp((GXTevStageID)0, (GXTevOp)0, (GXTevBias)2, (GXTevScale)0, (GXBool)1, (GXTevRegID)0);
    GXSetTevAlphaOp((GXTevStageID)0, (GXTevOp)0, (GXTevBias)2, (GXTevScale)0, (GXBool)1, (GXTevRegID)0);
    GXSetTevSwapMode((GXTevStageID)0, (GXTevSwapSel)0, (GXTevSwapSel)0);
    GXSetTevDirect((GXTevStageID)0);
    if (this_[0xe450] != 0) {
        mgr = (u8*)lbl_8053AAF8;
        if (mgr[0x7f] != 0) {
            flag = (*(s32*)(mgr + 0x4c) == 0x7 || *(s32*)(mgr + 0x4c) == 0x8 || *(s32*)(mgr + 0x4c) == 0x9 || *(s32*)(mgr + 0x4c) == 0x16 || *(s32*)(mgr + 0x4c) == 0xa || *(s32*)(mgr + 0x4c) == 0xb) ? true : false;
        } else {
            flag = (*(s32*)(mgr + 0x4c) == 0x7 || *(s32*)(mgr + 0x4c) == 0x8 || *(s32*)(mgr + 0x4c) == 0x9 || *(s32*)(mgr + 0x4c) == 0x16 || *(s32*)(mgr + 0x4c) == 0xa || *(s32*)(mgr + 0x4c) == 0xb || *(s32*)(mgr + 0x4c) == 0xc) ? true : false;
        }
        if (flag && *(void**)(mgr + 0x4) != NULL) {
            idx = *(s32*)((u8*)fn_802D6A9C() + 0x50);
        } else {
            idx = 0;
        }
        load__10JUTTextureF11_GXTexMapID(((void**)(this_ + 0xE428))[idx], 1);
        GXSetTevOrder((GXTevStageID)1, (GXTexCoordID)1, (GXTexMapID)1, (GXChannelID)0xff);
        GXSetTevColorIn((GXTevStageID)1, (GXTevColorArg)0xf, (GXTevColorArg)0, (GXTevColorArg)8, (GXTevColorArg)0xf);
        GXSetTevAlphaIn((GXTevStageID)1, (GXTevAlphaArg)7, (GXTevAlphaArg)7, (GXTevAlphaArg)7, (GXTevAlphaArg)0);
        GXSetTevColorOp((GXTevStageID)1, (GXTevOp)0, (GXTevBias)0, (GXTevScale)0, (GXBool)1, (GXTevRegID)1);
        GXSetTevAlphaOp((GXTevStageID)1, (GXTevOp)0, (GXTevBias)0, (GXTevScale)0, (GXBool)1, (GXTevRegID)0);
        GXSetTevSwapMode((GXTevStageID)1, (GXTevSwapSel)0, (GXTevSwapSel)0);
        GXSetTevDirect((GXTevStageID)1);
        GXSetTevOrder((GXTevStageID)2, (GXTexCoordID)0xff, (GXTexMapID)0xff, (GXChannelID)0xff);
        GXSetTevColorIn((GXTevStageID)2, (GXTevColorArg)0xf, (GXTevColorArg)0xc, (GXTevColorArg)2, (GXTevColorArg)0);
        GXSetTevAlphaIn((GXTevStageID)2, (GXTevAlphaArg)7, (GXTevAlphaArg)7, (GXTevAlphaArg)7, (GXTevAlphaArg)0);
        GXSetTevColorOp((GXTevStageID)2, (GXTevOp)1, (GXTevBias)0, (GXTevScale)0, (GXBool)1, (GXTevRegID)0);
        GXSetTevAlphaOp((GXTevStageID)2, (GXTevOp)0, (GXTevBias)0, (GXTevScale)0, (GXBool)1, (GXTevRegID)0);
        GXSetTevSwapMode((GXTevStageID)2, (GXTevSwapSel)0, (GXTevSwapSel)0);
        GXSetTevDirect((GXTevStageID)2);
        GXSetTevColor((GXTevRegID)2, *(GXColor*)&lbl_805414E8);
        GXSetTevOrder((GXTevStageID)3, (GXTexCoordID)0xff, (GXTexMapID)0xff, (GXChannelID)0xff);
        GXSetTevColorIn((GXTevStageID)3, (GXTevColorArg)5, (GXTevColorArg)1, (GXTevColorArg)0, (GXTevColorArg)2);
        GXSetTevAlphaIn((GXTevStageID)3, (GXTevAlphaArg)7, (GXTevAlphaArg)7, (GXTevAlphaArg)7, (GXTevAlphaArg)0);
        GXSetTevColorOp((GXTevStageID)3, (GXTevOp)8, (GXTevBias)0, (GXTevScale)0, (GXBool)1, (GXTevRegID)0);
        GXSetTevAlphaOp((GXTevStageID)3, (GXTevOp)0, (GXTevBias)0, (GXTevScale)0, (GXBool)1, (GXTevRegID)0);
        GXSetTevSwapMode((GXTevStageID)3, (GXTevSwapSel)0, (GXTevSwapSel)0);
        GXSetTevDirect((GXTevStageID)3);
        GXSetNumTevStages(4);
    } else {
        GXSetNumTevStages(1);
    }
    GXSetNumIndStages(0);
    GXInvalidateVtxCache();
    GXSetCullMode((GXCullMode)0);
    for (i = 0; i <= 8; i++) {
        if (i < 4 && this_[i + 0x235c] != 0) {
            if (i == 0 && this_[0x2365] != 0) {
                GXSetAlphaCompare((GXCompare)2, 0xff, (GXAlphaOp)1, (GXCompare)0, 0);
                GXSetZMode((GXBool)1, (GXCompare)3, (GXBool)1);
            } else {
                GXSetAlphaCompare((GXCompare)4, 0, (GXAlphaOp)0, (GXCompare)7, 0);
                GXSetZMode((GXBool)1, (GXCompare)3, (GXBool)1);
            }
            fn_802FC268(this_, this_ + 0x2368, i, *(u32*)(this_ + i * 4 + 0x28));
        } else if (i >= 4 && i < 8 && this_[i + 0x235c] != 0) {
            GXSetAlphaCompare((GXCompare)4, 0, (GXAlphaOp)0, (GXCompare)7, 0);
            GXSetZMode((GXBool)1, (GXCompare)3, (GXBool)1);
            fn_802FC268(this_, this_ + 0x2374, i - 4, *(u32*)(this_ + i * 4 + 0x28));
        } else if (this_[0x2365] != 0 && i == 8 && this_[0x235c] != 0) {
            GXSetAlphaCompare((GXCompare)1, 0xff, (GXAlphaOp)0, (GXCompare)4, 0);
            GXSetZMode((GXBool)1, (GXCompare)3, (GXBool)0);
            fn_802FC268(this_, this_ + 0x2368, 0, *(u32*)(this_ + 0x28));
        }
    }
}

#pragma dont_inline on
extern "C" s32 fn_8023E10C(s32);
extern "C" Vec* fn_8023E214(s32);
extern "C" Vec* fn_8023E32C(s32);
extern "C" void fn_8030C5F0(void*, Vec*, s32, s32, Vec*);
extern "C" u8 fn_8022C8EC(s32);
extern "C" void fn_80433718(void*);
extern "C" void fn_80432AF8(void*);
extern "C" const f32 sincosTable___5JMath[];
extern "C" void* lbl_8053AF80;
extern "C" void fn_80458880(void*,s32,s32);
extern "C" f32 lbl_8054159C, lbl_805415A0, lbl_805415A4, lbl_805415A8;
extern "C" f32 lbl_805415AC, lbl_805415B0, lbl_805415B4, lbl_80541530;
#pragma dont_inline reset
static inline void WarpBounds802F(s32* dst, u8* pane, s32 off, s32 tx, s32 ty, f32 x, f32 y, f32 sx, f32 sy, const Vec& pos) {
    s32 w = *(f32*)(pane+off) * sx;
    s32 h = *(f32*)(pane+off+8) * sy;
    s32 cx = ((s32)*(f32*)(pane+off)-w)>>1;
    s32 cy = ((s32)*(f32*)(pane+off+8)-h)>>1;
    u8* point = pane + 0x40 + pane[0xa4]*12 + (off<0x80 ? 0 : 0x18);
    dst[0] = (pos.x+(f32)w*x)*(lbl_80541518-sx) + sx*((f32)tx+((f32)cx+*(f32*)point));
    dst[1] = (pos.y+(f32)h*y)*(lbl_80541518-sy) + sy*((f32)ty+((f32)cy+*(f32*)(point+4)));
    dst[2] = w;
    dst[3] = h;
}

#pragma dont_inline on
#pragma inline_depth(3)
#pragma inline_max_size(500)
#pragma inline_max_total_size(10000)
extern "C" void fn_802FCE74(u8* this_) {
    u8* p=this_;
    const u8* table=lbl_8046F940;
    for(int i=0;i<4;i++) {
        s32* timer=(s32*)(p+0x138+i*4);
        if(p[0x12c+i] && !p[0x216] && *(s32*)(p+0x230)==*(s32*)(p+0x22c)) {
            if(*timer<40) {
                ++*timer;
                u32 mode=(*(u8*)((u8*)lbl_8053AAF8+0x83)>>(i*2))&3;
                if(((mode==2 && i==0)||(mode==1 && i==*(s32*)(p+0x230))) && !p[0x215]) {
                    fn_80458880(lbl_8053AF80,0x52,-1);
                    p[0x215]=1;
                }
            }
        } else if(*timer>0) {
            --*timer;
            if(p[0x215]==1) {
                s32 stage=*(s32*)((u8*)lbl_8053AAF8+0x4c);
                if(stage!=10 && stage!=12) fn_80458880(lbl_8053AF80,0x53,-1);
                p[0x215]=0;
            }
        }
        p[0x12c+i]=0;
    }
    p[0x216]=0;
    int current=*(s32*)(p+0x230);
    int next=*(s32*)(p+0x22c);
    if(*(s32*)(p+0x230)==-1 && next!=-1 && ((*(u8*)((u8*)lbl_8053AAF8+0x83)>>(next*2))&3)==1)
        *(s32*)(p+0x138+next*4)=0;
    if(*(s32*)(p+0x230)==-1 || *(s32*)(p+0x138+*(s32*)(p+0x230)*4)<=0) {
        if(next==-1 || *(s32*)(p+0x138+next*4)<=0) *(s32*)(p+0x230)=next;
    }
    *(s32*)(p+0x22c)=-1;
    p[0x248]=0;
    p[0x214]=0;
    f32 scale[4],other[4];
    for(int i=0;i<4;i++) {
        f32 t=lbl_8054159C*(f32)(*(s32*)(p+0x138+i*4)-20);
        if(lbl_805414F8>=t) t=lbl_805414F8;
        f32 angle=lbl_805415A8*t;
        f32 v;
        if(angle<lbl_805414F8) v=-sincosTable___5JMath[((s32)(lbl_805415A0*angle)&0x7ff)*2];
        else v=sincosTable___5JMath[((s32)(lbl_805415A4*angle)&0x7ff)*2];
        scale[i]=v; other[i]=scale[i];
        p[0x148+i]=0; p[0x14c+i]=0; p[0x210+i]=0;
    }
    if(*(u8*)((u8*)lbl_8053AAF8+0x7e)) {
        s32 width=lbl_80541584, height=lbl_8054158C;
        for(int i=0;i<4;i++) {
            if(*(s32*)(p+0x138+i*4)>0) {
                if(*(s32*)(p+0x230)==i) {
                    s32 actor=fn_8022EA0C(i);
                    Vec pos;
                    Vec out;
                    Vec* src;
                    if(fn_8023E10C(actor)<8) {src=fn_8023E214(actor);pos.x=src->x;pos.y=src->y;pos.z=src->z;}
                    else {src=fn_8023E32C(actor);pos.x=src->x;pos.y=src->y;pos.z=src->z;}
                    fn_8030C5F0(*(void**)((u8*)lbl_8053AB10+0x24),&pos,0,0,&out);
                    f32 x=pos.x-lbl_80541580*(f32)(s32)(lbl_80541530*pos.x)<lbl_805415AC ? lbl_80541574 : lbl_805414F8;
                    f32 y=pos.y-lbl_805415B0*(f32)(s32)(lbl_805415B4*pos.y)<lbl_805414FC ? lbl_80541574 : lbl_805414F8;
                    u8* pane=*(u8**)(p+0xfc);
                    s32 tx=((s16*)(table+0x40))[*(s32*)(p+0x234)];
                    s32 ty=((s16*)(table+0x54))[*(s32*)(p+0x234)];
                    p[0x214]=1;
                    {
    s32 w = *(f32*)((pane)+(0x70+pane[0xa4]*4)) * (scale[i]);
    s32 h = *(f32*)((pane)+(0x70+pane[0xa4]*4)+8) * (other[i]);
    s32 cx = ((s32)*(f32*)((pane)+(0x70+pane[0xa4]*4))-w)>>1;
    s32 cy = ((s32)*(f32*)((pane)+(0x70+pane[0xa4]*4)+8)-h)>>1;
    u8* point = (pane) + 0x40 + (pane)[0xa4]*12 + ((0x70+pane[0xa4]*4)<0x80 ? 0 : 0x18);
    ((s32*)(p+0x21c))[0] = ((out).x+(f32)w*(x))*(lbl_80541518-(scale[i])) + (scale[i])*((f32)(tx)+((f32)cx+*(f32*)point));
    ((s32*)(p+0x21c))[1] = ((out).y+(f32)h*(y))*(lbl_80541518-(other[i])) + (other[i])*((f32)(ty)+((f32)cy+*(f32*)(point+4)));
    ((s32*)(p+0x21c))[2] = w;
    ((s32*)(p+0x21c))[3] = h;
}
                    p[0x148+i]=1;
                    *(s32*)(p+0x150+i*16)=0;*(s32*)(p+0x154+i*16)=0;
                    *(s32*)(p+0x158+i*16)=width;*(s32*)(p+0x15c+i*16)=height;
                    {
    s32 w = *(f32*)((pane)+(0x80+pane[0xa4]*4)) * (scale[i]);
    s32 h = *(f32*)((pane)+(0x80+pane[0xa4]*4)+8) * (other[i]);
    s32 cx = ((s32)*(f32*)((pane)+(0x80+pane[0xa4]*4))-w)>>1;
    s32 cy = ((s32)*(f32*)((pane)+(0x80+pane[0xa4]*4)+8)-h)>>1;
    u8* point = (pane) + 0x40 + (pane)[0xa4]*12 + ((0x80+pane[0xa4]*4)<0x80 ? 0 : 0x18);
    ((s32*)(p+0x190+i*16))[0] = ((out).x+(f32)w*(x))*(lbl_80541518-(scale[i])) + (scale[i])*((f32)(tx)+((f32)cx+*(f32*)point));
    ((s32*)(p+0x190+i*16))[1] = ((out).y+(f32)h*(y))*(lbl_80541518-(other[i])) + (other[i])*((f32)(ty)+((f32)cy+*(f32*)(point+4)));
    ((s32*)(p+0x190+i*16))[2] = w;
    ((s32*)(p+0x190+i*16))[3] = h;
}
                    p[0x210+i]=1;
                } else if(!p[0x217+i]) {
                    u8* data=*(u8**)(p+0x11c+i*4)+8+((s32*)lbl_80506DD8)[i]*4;
                    s32 x=((s32)data[2]|((data[3]&1)<<8))-24;
                    s32 y=(s32)data[1]-32;
                    x=x>0?x:0;y=y>0?y:0;
                    x+=48;y+=40;
                    x=x>240?240:x;y=y>160?160:y;
                    x-=48;y-=40;
                    s32 h=*(s32*)(p+0x1dc+i*16);
                    s32 w=*(s32*)(p+0x1d8+i*16);
                    s32 sh=(f32)h*other[i],sw=(f32)w*scale[i];
                    p[0x148+i]=1;p[0x14c+i]=1;
                    *(s32*)(p+0x150+i*16)=x;*(s32*)(p+0x154+i*16)=y;
                    *(s32*)(p+0x158+i*16)=48;*(s32*)(p+0x15c+i*16)=48;
                    *(s32*)(p+0x190+i*16)=((w-sw)>>1)+*(s32*)(p+0x1d0+i*16);
                    *(s32*)(p+0x194+i*16)=((h-sh)>>1)+*(s32*)(p+0x1d4+i*16);
                    *(s32*)(p+0x198+i*16)=sw;*(s32*)(p+0x19c+i*16)=sh;
                }
            }
            p[0x217+i]=0;
        }
    } else if(*(s32*)(p+0x138)>0 && !fn_8022C8EC(0)) {
        s32 actor=fn_8022EA0C(0);
        Vec pos,out;
        Vec* src;
        if(fn_8023E10C(actor)<8){src=fn_8023E214(actor);pos.x=src->x;pos.y=src->y;pos.z=src->z;}else {src=fn_8023E32C(actor);pos.x=src->x;pos.y=src->y;pos.z=src->z;}
        fn_8030C5F0(*(void**)((u8*)lbl_8053AB10+0x24),&pos,0,0,&out);
        f32 x=pos.x-lbl_80541580*(f32)(s32)(lbl_80541530*pos.x)<lbl_805415AC ? lbl_80541574 : lbl_805414F8;
        f32 y=pos.y-lbl_805415B0*(f32)(s32)(lbl_805415B4*pos.y)<lbl_805414FC ? lbl_80541574 : lbl_805414F8;
        fn_80433718(*(void**)(p+0xfc));
        u8* pane=*(u8**)(p+0xfc);
        p[0x214]=1;
        u16 tag=0;
        s32 stage=*(s32*)((u8*)lbl_8053AAF8+0x4c);
        bool sel;
        if(*(u8*)((u8*)lbl_8053AAF8+0x7f)) {u8 flag=stage==7||stage==8||stage==9||stage==22||stage==10||stage==11;sel=flag!=0;}
        else {u8 flag=stage==7||stage==8||stage==9||stage==22||stage==10||stage==11||stage==12;sel=flag!=0;}
        if(sel)tag=*(u16*)(pane+0x9e);
        u8* camera=*(u8**)((u8*)lbl_8053AB10+0x24);
        if(!camera[0x7f4])camera[0x7f5]=1;
        s32 tx=*(s16*)(table+0x68+pane[0xa4]*18+tag*2);
        s32 ty=*(s16*)(table+0x8c+pane[0xa4]*18+tag*2);
        {
    s32 w = *(f32*)((pane)+(0x70+pane[0xa4]*4)) * (scale[0]);
    s32 h = *(f32*)((pane)+(0x70+pane[0xa4]*4)+8) * (other[0]);
    s32 cx = ((s32)*(f32*)((pane)+(0x70+pane[0xa4]*4))-w)>>1;
    s32 cy = ((s32)*(f32*)((pane)+(0x70+pane[0xa4]*4)+8)-h)>>1;
    u8* point = (pane) + 0x40 + (pane)[0xa4]*12 + ((0x70+pane[0xa4]*4)<0x80 ? 0 : 0x18);
    ((s32*)(p+0x21c))[0] = ((out).x+(f32)w*(x))*(lbl_80541518-(scale[0])) + (scale[0])*((f32)(tx)+((f32)cx+*(f32*)point));
    ((s32*)(p+0x21c))[1] = ((out).y+(f32)h*(y))*(lbl_80541518-(other[0])) + (other[0])*((f32)(ty)+((f32)cy+*(f32*)(point+4)));
    ((s32*)(p+0x21c))[2] = w;
    ((s32*)(p+0x21c))[3] = h;
}
        p[0x148]=1;*(s32*)(p+0x150)=0;*(s32*)(p+0x154)=0;
        *(s32*)(p+0x158)=(s32)lbl_80541584;*(s32*)(p+0x15c)=(s32)lbl_8054158C;
        {
    s32 w = *(f32*)((pane)+(0x80+pane[0xa4]*4)) * (scale[0]);
    s32 h = *(f32*)((pane)+(0x80+pane[0xa4]*4)+8) * (other[0]);
    s32 cx = ((s32)*(f32*)((pane)+(0x80+pane[0xa4]*4))-w)>>1;
    s32 cy = ((s32)*(f32*)((pane)+(0x80+pane[0xa4]*4)+8)-h)>>1;
    u8* point = (pane) + 0x40 + (pane)[0xa4]*12 + ((0x80+pane[0xa4]*4)<0x80 ? 0 : 0x18);
    ((s32*)(p+0x190))[0] = ((out).x+(f32)w*(x))*(lbl_80541518-(scale[0])) + (scale[0])*((f32)(tx)+((f32)cx+*(f32*)point));
    ((s32*)(p+0x190))[1] = ((out).y+(f32)h*(y))*(lbl_80541518-(other[0])) + (other[0])*((f32)(ty)+((f32)cy+*(f32*)(point+4)));
    ((s32*)(p+0x190))[2] = w;
    ((s32*)(p+0x190))[3] = h;
}
        p[0x210]=1;
    }
    if(p[0x214])fn_80432AF8(*(void**)(p+0xfc));
    else {u8* pane=*(u8**)(p+0xfc);*(u16*)(pane+0xa0)=0xffff;pane[0xa4]=0;}
    if(++*(s32*)(p+0x2394)>=10) {
        *(s32*)(p+0x2394)=0;
        if(++*(s32*)(p+0x2390)>=4)*(s32*)(p+0x2390)=0;
        u8* dest=*(u8**)(p+8)+0x200;
        u8* src=*(u8**)(p+0x238c)+*(s32*)(p+0x2390)*64;
        for(int i=0;i<64;i++)*dest++=*src++;
    }
}
#pragma dont_inline reset
extern "C" f32 lbl_80541524;
static inline f32 WarpSqrt802F(f32 x) {
    if(x>lbl_805414F8) {
        f32 estimate=__frsqrte(x);
        f32 product=estimate*x;
        estimate=lbl_80541524-product*estimate;
        estimate=estimate*product;
        return estimate*lbl_80541520;
    }
    return x;
}
static inline f32 WarpCos802F(f32 angle) {
    if(angle<lbl_805414F8) angle=-angle;
    return sincosTable___5JMath[(((s32)(lbl_805415A4*angle))&0x7ff)*2+1];
}
static inline f32 WarpSin802F(f32 angle) {
    if(angle<lbl_805414F8) return -sincosTable___5JMath[(((s32)(lbl_805415A0*angle))&0x7ff)*2];
    return sincosTable___5JMath[(((s32)(lbl_805415A4*angle))&0x7ff)*2];
}
static inline f32 WarpLineDistance802F(const JGeometry::TVec3<f32>& point,const JGeometry::TVec3<f32>& start,const JGeometry::TVec3<f32>& dir) {
    JGeometry::TVec3<f32> delta;delta.sub(point,start);
    f32 length=dir.squared(), projection=dir.dot(delta), distance=delta.squared();
    f32 squared=(length*distance-projection*projection)/length;
    if(squared<=lbl_805414F8) return squared;
    f32 inv=__frsqrte(squared);
    inv=lbl_80541520*inv*(lbl_80541524-squared*(inv*inv));
    return squared*inv;
}
#pragma dont_inline on
extern "C" void fn_802FDDD4(u8* this_) {
    s32 counter;
    s32 i;
    s32 j;
    *(s32*)(this_ + 0x2388) = *(s32*)(this_ + 0x2388) + 1;
    if (*(s32*)(this_ + 0x2388) >= 2) {
        *(s32*)(this_ + 0x2388) = 0;
    }
    counter = *(s32*)(this_ + 0x2388);
    i = 0;
    do {
        j = 0;
        do {
            j++;
        } while (j <= *(s32*)(this_ + 0x2380));
        i++;
    } while (i <= *(s32*)(this_ + 0x2384));
}
#pragma dont_inline reset

#pragma opt_propagation off
extern "C" void fn_802FEE68(Tu802F5040Tbl* base) {
    u8* p;
    s32 i;
    f32 v;
    f32 s;
    f32 ratio;
    MtxPtr orig;
    Mtx m;
    s32 j;

    i = 0xff;
    p = (u8*)base + 0x9b64;
    do {
        if (*(s32*)(p + 0x2398) > 0) {
            ratio = (f32)*(s32*)(p + 0x2398) / (f32)*(s32*)(p + 0x239c);
            p[0x23d0] = p[0x242c];
            p[0x23d1] = p[0x242d];
            p[0x23d2] = p[0x242e];
            p[0x23d3] = (u8)(int)((f32)p[0x242f] * ratio);
            p[0x23d4] = p[0x2430];
            p[0x23d5] = p[0x2431];
            p[0x23d6] = p[0x2432];
            p[0x23d7] = (u8)(int)((f32)p[0x2433] * ratio);
            v = *(f32*)(p + 0x23a0);
            if (1.0f != v) {
                const void* __restrict src = *(MtxPtr*)(p + 0x23d8);
                orig = (MtxPtr)src;
                ratio = v - (v - 1.0f) * ratio;
                JMath::gekko_ps_copy12(m, src);
                m[0][0] *= ratio; m[1][0] *= ratio; m[2][0] *= ratio;
                m[0][1] *= ratio; m[1][1] *= ratio; m[2][1] *= ratio;
                m[0][2] *= ratio; m[1][2] *= ratio; m[2][2] *= ratio;
                m[0][3] *= ratio; m[1][3] *= ratio; m[2][3] *= ratio;
                *(MtxPtr*)(p + 0x23d8) = m;
            }
            if (*(u32*)(p + 0x23b0) != 0) {
                fn_802F86CC(base, p + 0x23a4, *(s32*)(p + 0x23b0), *(u32*)(p + 0x23b4), p + 0x23c0, 1.0f, 1.0f);
            } else if (*(u32*)(p + 0x23b8) != 0) {
                fn_802F745C(base, p + 0x23a4, *(s32*)(p + 0x23b8), p + 0x23c0);
            } else if (*(u32*)(p + 0x23bc) != 0) {
                fn_802F6CF4(base, p + 0x23a4, *(s32*)(p + 0x23bc), p + 0x23c0);
            }
            if (1.0f != *(f32*)(p + 0x23a0)) {
                *(MtxPtr*)(p + 0x23d8) = orig;
            }
        }
        i--;
        p -= 0x9c;
    } while (i >= 0);
}
#pragma opt_propagation reset
extern "C" void fn_802FF0EC(u8* p) {
    bool bVar2 = false;
    s32 i = 0;
    s32* pD88 = (s32*)lbl_80506D88;
    s32* pD98 = (s32*)lbl_80506D98;
    u8* pCell = p;
    u8* pVal = p;
    u8* pBias = lbl_8053ACF0;
    do {
        if (p[i + 0x148] != 0 && *(s32*)((u8*)lbl_8053AAF8 + 0x4c) != 0xc) {
            if (p[0x214] != 0) {
                s32 iVar1 = *(s32*)(p + 0x230);
                if (i == iVar1 || iVar1 == -1) {
                    s32 x0 = *(s32*)(p + 0x21c);
                    s32 x1 = *(s32*)(p + 0x220);
                    s32 x2 = *(s32*)(p + 0x224);
                    s32 x3 = *(s32*)(p + 0x228);
                    fn_80432750(*(void**)(p + 0xfc), (-1 - iVar1) ? 0 : 1, (f32)x0, (f32)x1, (f32)x2, (f32)x3);
                    bVar2 = true;
                }
            }
            u8 bVar11 = 0;
            s32 uVar12 = 0xff;
            if (fn_80301D30(i) == 1) {
                bVar11 = *pBias >> 1;
            } else if (fn_80301D30(i) == 2) {
                if (AnimTable_IsField0xe0LessThan3(lbl_8053AD30, fn_8030AAF4(i)) != 0 || *pD88 == *pD98) {
                    uVar12 = (0x10 - *pBias) * 0x10;
                    if (uVar12 > 0xff) {
                        uVar12 = 0xff;
                    }
                }
            }
            fn_802FB69C(p, i, *(s32*)(pVal + 0x11c), pCell + 0x150, pCell + 0x190, p[i + 0x210], bVar11, (u8)uVar12);
        }
        i++;
        pD88++;
        pD98++;
        pCell += 0x10;
        pVal += 4;
        pBias++;
    } while (i < 4);
    if (bVar2) {
        fn_80432638(*(void**)(p + 0xfc));
    }
    p[0xbf98] = 0;
}

extern "C" void fn_802FF2D8(u8* this_) {
    s32 i;
    u8* p;
    u8* e;
    p = this_;
    for (i = 0; i < *(s32*)(this_ + 0xe424); i++) {
        e = p + 0xd324;
        if (*(u32*)(e + 0xc) != 0) {
            fn_802F86CC((Tu802F5040Tbl*)this_, e, *(u32*)(e + 0xc), *(u32*)(e + 0x10), e + 0x1c, lbl_80541518, lbl_80541518);
        } else if (*(u32*)(e + 0x14) != 0) {
            fn_802F745C((Tu802F5040Tbl*)this_, e, *(u32*)(e + 0x14), e + 0x1c);
        } else if (*(u32*)(e + 0x18) != 0) {
            fn_802F6CF4((Tu802F5040Tbl*)this_, e, *(u32*)(e + 0x18), e + 0x1c);
        }
        p += 0x88;
    }
    *(s32*)(this_ + 0xe424) = 0;
    fn_802FEE68((Tu802F5040Tbl*)this_);
}

extern "C" void fn_802FF3B0(u8* this_) {
    if (this_[0xe451] != 0 && *(u32*)((u8*)lbl_8053AAF8 + 0x4) != 0) {
        fn_802FA3FC(this_);
    }
}

extern "C" void fn_802FF3F0(u8* this_) {
    s32 i;
    u8* p;
    u8* e;
    u8* mgr;
    u8* video;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    volatile Tu802F5040Rect rect;
    if (this_[0x248] != 0 && *(u32*)(this_ + 0x254) != 0) {
        s32 v = *(s32*)(this_ + 0x24c);
        mgr = *(u8**)((u8*)lbl_8053AB10 + 0x24);
        *(s32*)(mgr + 0x144) = v;
        *(s32*)(mgr + 0x148) = *(s32*)(this_ + 0x250);
        *(s32*)(mgr + 0x14c) = *(s32*)(this_ + 0x254);
        *(s32*)(mgr + 0x150) = *(s32*)(this_ + 0x258);
    } else {
        video = *(u8**)((u8*)sManager__8JUTVideo + 4);
        mgr = *(u8**)((u8*)lbl_8053AB10 + 0x24);
        d = *(u16*)(video + 6);
        c = *(u16*)(video + 4);
        a = 0;
        b = 0;
        rect.m00 = a;
        rect.m04 = b;
        rect.m08 = c;
        rect.m0c = d;
        *(s32*)(mgr + 0x144) = a;
        *(s32*)(mgr + 0x148) = b;
        *(s32*)(mgr + 0x14c) = c;
        *(s32*)(mgr + 0x150) = d;
    }
    fn_802FC80C(this_);
    p = this_;
    for (i = 0; i < *(s32*)(this_ + 0xd320); i++) {
        e = p + 0xc220;
        if (*(u32*)(e + 0xc) != 0) {
            fn_802F86CC((Tu802F5040Tbl*)this_, e, *(u32*)(e + 0xc), *(u32*)(e + 0x10), e + 0x1c, lbl_80541518, lbl_80541518);
        } else if (*(u32*)(e + 0x14) != 0) {
            fn_802F745C((Tu802F5040Tbl*)this_, e, *(u32*)(e + 0x14), e + 0x1c);
        } else if (*(u32*)(e + 0x18) != 0) {
            fn_802F6CF4((Tu802F5040Tbl*)this_, e, *(u32*)(e + 0x18), e + 0x1c);
        }
        p += 0x88;
    }
    *(s32*)(this_ + 0xd320) = 0;
}

extern "C" void fn_802FA3FC(void* mgr);
extern void* lbl_8053AAF8;
extern "C" void fn_802FA3FC(void* mgr);
extern "C" void fn_802FF548(void* mgr) {
    fn_802FF798(mgr);
}

extern "C" void fn_802FDDD4(u8* this_);
extern "C" void fn_802FCE74(u8* this_);
extern "C" u8 fn_8023F264(s32 i);
extern "C" void fn_802FF568(u8* this_) {
    u8* p;
    s32 i;
    bool f;
    s32 k;
    fn_802FDDD4(this_);
    if (((u8*)lbl_8053AAF8)[0x7f] != 0) {
        u8 flag = *(s32*)((u8*)lbl_8053AAF8 + 0x4c) == 7 || *(s32*)((u8*)lbl_8053AAF8 + 0x4c) == 8 || *(s32*)((u8*)lbl_8053AAF8 + 0x4c) == 9 || *(s32*)((u8*)lbl_8053AAF8 + 0x4c) == 0x16 || *(s32*)((u8*)lbl_8053AAF8 + 0x4c) == 0xa || *(s32*)((u8*)lbl_8053AAF8 + 0x4c) == 0xb;
        f = flag != 0;
    } else {
        u8 flag = *(s32*)((u8*)lbl_8053AAF8 + 0x4c) == 7 || *(s32*)((u8*)lbl_8053AAF8 + 0x4c) == 8 || *(s32*)((u8*)lbl_8053AAF8 + 0x4c) == 9 || *(s32*)((u8*)lbl_8053AAF8 + 0x4c) == 0x16 || *(s32*)((u8*)lbl_8053AAF8 + 0x4c) == 0xa || *(s32*)((u8*)lbl_8053AAF8 + 0x4c) == 0xb || *(s32*)((u8*)lbl_8053AAF8 + 0x4c) == 0xc;
        f = flag != 0;
    }
    if (f == 1) fn_802FCE74(this_);
    p = this_;
    for (i = 0; i < 0x100; i++) {
        if (*(s32*)(p + 0x2398) > 0) --*(s32*)(p + 0x2398);
        p += 0x9c;
    }
    this_[0xbf98] = 1;
    this_[0xe461] = 1;
    if (((u8*)lbl_8053AAF8)[0x7f] == 0) {
        s32 j = 0;
        k = 0;
        for (; j < 4; j++) {
            if (fn_8023F264(j) != 0 && ((((u8*)lbl_8053AAF8)[0x83] >> k) & 3U) == 2) {
                this_[0xe461] = 0;
                return;
            }
            k += 2;
        }
    }
}

extern "C" f32 lbl_80541528;
extern "C" f32 lbl_8054152C;
extern "C" f32 lbl_80541530;
extern "C" f32 lbl_80541538;
extern "C" f32 lbl_8054153C;
extern "C" f32 lbl_80541610;
extern "C" f32 lbl_80541614;
extern "C" void fn_802FF798(void* mgr) {
    s32 y;
    u8* rect;
    u8* p;
    u8* view;
    s32 v;
    s32 i;
    s32 j;
    s32 n;
    u8* this_ = (u8*)mgr;

    for (i = 0; i < 4; i++) {
        this_[0x235c + i] = 0;
        this_[0x2360 + i] = 0;
    }
    this_[0x2364] = 0;
    this_[0x2365] = 1;
    *(f32*)(this_ + 0x2368) = *(f32*)(this_ + 0x236c) = *(f32*)(this_ + 0x2370) = 0.0f;
    *(f32*)(this_ + 0x2374) = *(f32*)(this_ + 0x2378) = *(f32*)(this_ + 0x237c) = 0.0f;
    *(s32*)(this_ + 0x2380) = 0x40;
    *(s32*)(this_ + 0x2384) = 0x40;
    p = this_;
    for (i = 0; i < 0x20; i++) {
        for (j = 0; j < 8; j++) {
            *(s32*)(p + 0x2398 + j * 0x9c) = 0;
        }
        p += 0x4e0;
    }
    this_[0xbf98] = 0;
    *(s32*)(this_ + 0x2388) = 0;
    for (int k = 0; k < 0x10; k++) {
        *(s32*)(this_ + 0xbf9c + k * 0x28) = 0;
    }
    for (int row = 0; row < 0x40; row++) {
        for (int col = 0; col < 0x10; col++) {
            n = row * 0x10 + col;
            ((f32*)*(u8**)(this_ + 0x110))[n * 2] = 0.0078125f * (8.0f * (f32)col + 0.501f);
            ((f32*)*(u8**)(this_ + 0x110))[n * 2 + 1] = 0.001953125f * (8.0f * (f32)row + 0.501f);
            ((f32*)*(u8**)(this_ + 0x110))[n * 2 + 0x800] = 6.98f / 128.0f + ((f32*)*(u8**)(this_ + 0x110))[n * 2];
            ((f32*)*(u8**)(this_ + 0x110))[n * 2 + 0x801] = ((f32*)*(u8**)(this_ + 0x110))[n * 2 + 1];
            ((f32*)*(u8**)(this_ + 0x110))[n * 2 + 0x1000] = ((f32*)*(u8**)(this_ + 0x110))[n * 2];
            ((f32*)*(u8**)(this_ + 0x110))[n * 2 + 0x1001] = 6.98f / 512.0f + ((f32*)*(u8**)(this_ + 0x110))[n * 2 + 1];
            ((f32*)*(u8**)(this_ + 0x110))[n * 2 + 0x1800] = 6.98f / 128.0f + ((f32*)*(u8**)(this_ + 0x110))[n * 2];
            ((f32*)*(u8**)(this_ + 0x110))[n * 2 + 0x1801] = 6.98f / 512.0f + ((f32*)*(u8**)(this_ + 0x110))[n * 2 + 1];
        }
    }
    *(s32*)(this_ + 0xc21c) = 0;
    *(s32*)(this_ + 0xd320) = 0;
    *(s32*)(this_ + 0xe424) = 0;
    fn_802FDDD4(this_);
    p = this_;
    rect = this_;
    for (v = 0; v < 4; v++) {
        s32 x;
        view = this_ + v;
        view[0x12c] = 0;
        *(s32*)(p + 0x138) = 0;
        view[0x148] = 0;
        view[0x14c] = 0;
        view[0x210] = 0;
        if (v & 2) {
            y = *(u16*)(*(u8**)((u8*)sManager__8JUTVideo + 4) + 6) - 0x90;
        } else {
            y = 0x48;
        }
        if (v & 1) {
            x = *(u16*)(*(u8**)((u8*)sManager__8JUTVideo + 4) + 4) - 0x60;
        } else {
            x = 0x18;
        }
        *(s32*)(rect + 0x1d0) = x;
        *(s32*)(rect + 0x1d4) = y;
        *(s32*)(rect + 0x1d8) = 0x48;
        *(s32*)(rect + 0x1dc) = 0x48;
        view[0x217] = 0;
        p += 4;
        rect += 0x10;
    }
    this_[0x216] = 0;
    this_[0x214] = 0;
    this_[0x215] = 0;
    *(s32*)(this_ + 0x22c) = -1;
    *(s32*)(this_ + 0x230) = -1;
    *(s32*)(this_ + 0x234) = 0;
    this_[0x248] = 0;
    this_[0xe450] = 1;
    this_[0xe451] = 1;
    *(f32*)(this_ + 0xe458) = 1.8f;
    *(f32*)(this_ + 0xe45c) = -0.25f;
    *(s32*)(this_ + 0x2390) = 0;
    *(s32*)(this_ + 0x2394) = 0;
    this_[0xe461] = 1;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            for (n = 0; n < 0x10; n++) {
                GXInitTlutObj((GXTlutObj*)(this_ + 0x25c + i * 0x300 + j * 0xc0 + n * 0xc),
                              *(u8**)(this_ + 0xc8 + (i * 4 + j) * 4) + n * 0x20, (GXTlutFmt)2, 0x10);
                GXInitTexObjCI((GXTexObj*)(this_ + 0xb5c + i * 0x800 + j * 0x200 + n * 0x20),
                               *(void**)(this_ + 0x88 + j * 4), 0x100, 0x100, (GXCITexFmt)8, (GXTexWrapMode)0,
                               (GXTexWrapMode)0, 0, ((u32*)lbl_8046F940)[n]);
            }
        }
    }
}

extern "C" void* fn_802FFBF8(void* self, s16 flag) {
    struct VObj { virtual void Delete(s32); };
    u8* p = (u8*)self;
    if (p != NULL) {
        *(u8**)p = lbl_804AA858;
        __dt__10JUTTextureFv(*(void**)(p + 0xE454), 1);
        {
            u8* q; s32 i;
            i = 9; q = p + 0x24;
            do { __dt__10JUTTextureFv(*(void**)(q + 0xE428), 1); q -= 4; } while (--i >= 0);
        }
        {
            s32 i = 3; u8* q = p + 0xC;
            do { __dl__FPv(*(void**)(q + 0x11C)); q -= 4; } while (--i >= 0);
        }
        if (*(void**)(p + 0x110) != NULL) {
            __dla__FPv((u8*)*(void**)(p + 0x110) - 0x10);
        }
        {
            s32 i = 1; u8* q = p + 0x4;
            do {
                if (*(void**)(q + 0x108) != NULL) __dla__FPv((u8*)*(void**)(q + 0x108) - 0x10);
                if (*(void**)(q + 0x100) != NULL) __dla__FPv((u8*)*(void**)(q + 0x100) - 0x10);
                q -= 4;
            } while (--i >= 0);
        }
        __dla__FPv(*(void**)(p + 0xF8));
        {
            s32 i = 3; u8* q = p + 0xC;
            do {
                __dla__FPv(*(void**)(q + 0xC8));
                __dla__FPv(*(void**)(q + 0x98));
                __dla__FPv(*(void**)(q + 0x88));
                q -= 4;
            } while (--i >= 0);
        }
        {
            s32 i = 15; u8* q = p + 0x3C;
            do { __dla__FPv(*(void**)(q + 0x48)); q -= 4; } while (--i >= 0);
        }
        {
            s32 i = 3; u8* q = p + 0xC;
            do {
                __dla__FPv(*(void**)(q + 0x38));
                __dla__FPv(*(void**)(q + 0x28));
                q -= 4;
            } while (--i >= 0);
        }
        __dla__FPv(*(void**)(p + 0x24));
        {
            s32 i = 2; u8* q = p + 0x8;
            do {
                __dla__FPv(*(void**)(q + 0x18));
                __dla__FPv(*(void**)(q + 0xC));
                q -= 4;
            } while (--i >= 0);
        }
        {
            s32 i = 1; u8* q = p + 0x4;
            do { __dla__FPv(*(void**)(q + 0x4)); q -= 4; } while (--i >= 0);
        }
        if (*(VObj**)(p + 0xFC) != NULL) {
            (*(VObj**)(p + 0xFC))->Delete(1);
        }
        *(void**)(p + 0xFC) = NULL;
        __dl__FPv(*(void**)(p + 0x238C));
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_8043395C(void* p);
extern "C" char lbl_804711D4[];
extern "C" char lbl_804711E4[];
extern "C" void* fn_802FFDEC(u8* p, JKRHeap* heap) {
    s32 i;
    s32 j;
    s32 k;
    s32 n;
    char name[32];

    *(u8**)p = lbl_804AA858;
    __construct_array(p + 0x150, (void*)fn_803004C0, 0, 0x10, 4);
    __construct_array(p + 0x190, (void*)fn_803004C0, 0, 0x10, 4);
    __construct_array(p + 0x1d0, (void*)fn_803004C0, 0, 0x10, 4);
    __construct_array(p + 0x2398, (void*)fn_803003AC, 0, 0x9c, 0x100);
    __construct_array(p + 0xbf9c, (void*)fn_803003A8, 0, 0x28, 0x10);
    __construct_array(p + 0xc220, (void*)fn_8030029C, 0, 0x88, 0x20);
    __construct_array(p + 0xd324, (void*)fn_8030029C, 0, 0x88, 0x20);
    heap->getTotalFreeSize();
    for (i = 0; i < 2; i++) {
        *(void**)(p + 0x4 + i * 4) = ::operator new[](0x8000, heap, 0x20);
    }
    for (i = 0; i < 3; i++) {
        *(void**)(p + 0xc + i * 4) = ::operator new[](0x200, heap, 0x20);
        *(void**)(p + 0x18 + i * 4) = ::operator new[](0x200, heap, 0x20);
    }
    *(void**)(p + 0x24) = ::operator new[](0x2000, heap, 0x20);
    for (i = 0; i < 4; i++) {
        *(void**)(p + 0x28 + i * 4) = ::operator new[](0x2000, heap, 0x20);
        *(void**)(p + 0x38 + i * 4) = ::operator new[](0x2000, heap, 0x20);
    }
    for (i = 0; i < 16; i++) {
        *(void**)(p + 0x48 + i * 4) = ::operator new[](0x2000, heap, 0x20);
    }
    for (i = 0; i < 4; i++) {
        *(void**)(p + 0x88 + i * 4) = ::operator new[](0x8000, heap, 0x20);
    }
    for (i = 0; i < 12; i++) {
        *(void**)(p + 0x98 + i * 4) = ::operator new[](0x200, heap, 0x20);
        *(void**)(p + 0xc8 + i * 4) = ::operator new[](0x200, heap, 0x20);
    }
    *(void**)(p + 0xf8) = ::operator new[](0x8000, heap, 0x20);
    for (j = 0; j < 2; j++) {
        *(JGeometry::TVec3<f32>**)(p + 0x100 + j * 4) = new (heap, 0) JGeometry::TVec3<f32>[0x1081];
        *(JUtility::TColor**)(p + 0x108 + j * 4) = new (heap, 0) JUtility::TColor[0x1081];
    }
    *(JGeometry::TVec2<f32>**)(p + 0x110) = new (heap, 0) JGeometry::TVec2<f32>[0x1000];
    for (k = 0; k < 4; k++) {
        *(void**)(p + 0x11c + k * 4) = ::operator new(0x68, heap, 0);
    }
    for (n = 0; n < 10; n++) {
        sprintf(name, lbl_804711D4, n == 0 ? 1 : n);
        *(JUTTexture**)(p + 0xe428 + n * 4) = new (heap, 0) JUTTexture(
            (ResTIMG*)(*(Tu802F5040ResMgr**)((u8*)lbl_8053AAF8 + 0xa4))->getResource(0x3f3f3f3f, name));
    }
    *(JUTTexture**)(p + 0xe454) = new (heap, 0) JUTTexture(
        (ResTIMG*)(*(Tu802F5040ResMgr**)((u8*)lbl_8053AAF8 + 0xa4))->getResource(0x3f3f3f3f, lbl_804711E4));
    {
        void* o = ::operator new(0xb0, heap, 0);
        if (o != NULL) {
            o = fn_8043395C(o);
        }
        *(void**)(p + 0xfc) = o;
    }
    *(void**)(p + 0x238c) = ::operator new[](0x100, heap, 0x20);
    return p;
}

extern "C" void fn_8030029C(u8* p) {
    *(s32*)(p + 0x2c) = -1;
    *(s32*)(p + 0x30) = -1;
    for (int i = 0; (u8)i < 0x10; i += 8) {
        p[(u8)(i + 0) + 0x1c] = i + 0;
        p[(u8)(i + 1) + 0x1c] = i + 1;
        p[(u8)(i + 2) + 0x1c] = i + 2;
        p[(u8)(i + 3) + 0x1c] = i + 3;
        p[(u8)(i + 4) + 0x1c] = i + 4;
        p[(u8)(i + 5) + 0x1c] = i + 5;
        p[(u8)(i + 6) + 0x1c] = i + 6;
        p[(u8)(i + 7) + 0x1c] = i + 7;
    }
    *(s32*)(p + 0x2c) = -1;
    *(s32*)(p + 0x30) = 0;
    *(s32*)(p + 0x34) = 0;
    p[0x38] = 0;
    p[0x39] = 0;
    p[0x3a] = 0;
    p[0x3b] = 1;
    p[0x3c] = 1;
    p[0x3d] = 0;
    p[0x3e] = 0;
    p[0x3f] = 0;
    p[0x40] = 0;
    p[0x41] = 0;
    p[0x42] = 1;
    *(s32*)(p + 0x44) = 3;
    p[0x48] = 1;
    p[0x49] = 0;
    p[0x4a] = 0;
    *(s32*)(p + 0x4c) = -1;
    *(s32*)(p + 0x50) = 0;
    *(s32*)(p + 0x54) = 2;
}

extern "C" void fn_803003A8(void) {}

extern "C" void fn_803003AC(void* p) {
    u8* b = (u8*)p;
    *(s32*)(b + 0x38) = -1;
    *(s32*)(b + 0x3c) = -1;
    for (int i = 0; (u8)i < 0x10; i += 8) {
        b[(u8)(i + 0) + 0x28] = i + 0;
        b[(u8)(i + 1) + 0x28] = i + 1;
        b[(u8)(i + 2) + 0x28] = i + 2;
        b[(u8)(i + 3) + 0x28] = i + 3;
        b[(u8)(i + 4) + 0x28] = i + 4;
        b[(u8)(i + 5) + 0x28] = i + 5;
        b[(u8)(i + 6) + 0x28] = i + 6;
        b[(u8)(i + 7) + 0x28] = i + 7;
    }
    *(s32*)(b + 0x38) = -1;
    *(s32*)(b + 0x3c) = 0;
    *(s32*)(b + 0x40) = 0;
    b[0x44] = 0;
    b[0x45] = 0;
    b[0x46] = 0;
    b[0x47] = 1;
    b[0x48] = 1;
    b[0x49] = 0;
    b[0x4a] = 0;
    b[0x4b] = 0;
    b[0x4c] = 0;
    b[0x4d] = 0;
    b[0x4e] = 1;
    *(s32*)(b + 0x50) = 3;
    b[0x54] = 1;
    b[0x55] = 0;
    b[0x56] = 0;
    *(s32*)(b + 0x58) = -1;
    *(s32*)(b + 0x5c) = 0;
    *(s32*)(b + 0x60) = 2;
    *(s32*)(b + 0x94) = -1;
    *(s32*)(b + 0x98) = -1;
}

extern "C" void fn_803004C0(void) {}

void __sinit_tu_802F5040_cpp() {}

extern "C" void __register_global_object(void*, void*, void*);
extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" u8 memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[0x10];
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" u8 memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[0x10];
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" u8 memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[0x10];
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" u8 memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[0x10];
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" u8 memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[0x10];
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" u8 memPool___30JASPoolAllocObject_9JAIStream[0x10];
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*);
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" u8 memPool___35JASPoolAllocObject_13JAISoundChild[0x10];
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" u8 memPool___27JASPoolAllocObject_6JAISeq[0x10];
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*);
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;
extern "C" u8 memPool___26JASPoolAllocObject_5JAISe[0x10];
extern "C" void __dt__18JASMemPool_5JAISeFv(void*);
extern "C" u8 lbl_804D69B8[];
#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "sdk/stl/math.h"
#include "JSystem/JGeometry/Box.h"

