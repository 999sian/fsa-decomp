#include "types.h"

extern "C" const f32 lbl_8053D43C;
extern "C" f32 lbl_8053D450;

static inline void GXPosition3f32(f32 x, f32 y, f32 z) {
    *(volatile f32*)0xCC008000 = x;
    *(volatile f32*)0xCC008000 = y;
    *(volatile f32*)0xCC008000 = z;
}

static inline void GXTexCoord2f32(f32 s, f32 t) {
    *(volatile f32*)0xCC008000 = s;
    *(volatile f32*)0xCC008000 = t;
}

extern "C" char* lbl_8053AAF8;
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802DCD0C(void* room);

extern "C" char* lbl_8053AB10;
extern "C" void fn_8013B438(char* p);
extern "C" const f32 lbl_8053D430;
extern "C" const f32 lbl_8053D434;
extern "C" const f32 lbl_8053D438;
extern "C" const f32 lbl_8053D440;
extern "C" const f32 lbl_8053D444;
extern "C" void GXClearVtxDesc(void);
extern "C" void GXSetVtxDesc(s32 attr, s32 type);
extern "C" void GXSetVtxAttrFmt(s32 vtxfmt, s32 attr, s32 cnt, s32 fmt, s32 frac);
extern "C" void GXSetChanCtrl(s32 chan, s32 enable, s32 amb, s32 mat, s32 mask, s32 diff, s32 attn);
extern "C" void GXSetNumChans(s32 n);
extern "C" void GXSetNumTexGens(s32 n);
extern "C" void GXSetTevColor(s32 id, u32* color);
extern "C" void GXSetTevOrder(s32 stage, s32 coord, s32 map, s32 color);
extern "C" void GXSetTevColorIn(s32 stage, s32 a, s32 b, s32 c, s32 d);
extern "C" void GXSetTevAlphaIn(s32 stage, s32 a, s32 b, s32 c, s32 d);
extern "C" void GXSetTevColorOp(s32 stage, s32 op, s32 bias, s32 scale, s32 clamp, s32 reg);
extern "C" void GXSetTevAlphaOp(s32 stage, s32 op, s32 bias, s32 scale, s32 clamp, s32 reg);
extern "C" void GXSetNumTevStages(s32 n);
extern "C" void GXSetBlendMode(s32 type, s32 src, s32 dst, s32 op);
extern "C" void GXSetZMode(s32 enable, s32 func, s32 update);
extern "C" void GXSetZCompLoc(s32 before);
extern "C" void GXSetAlphaCompare(s32 comp0, s32 ref0, s32 op, s32 comp1, s32 ref1);
extern "C" void GXSetColorUpdate(u8 enable);
extern "C" void GXSetAlphaUpdate(s32 enable);
extern "C" void GXSetCullMode(s32 mode);
extern "C" void GXBegin(s32 prim, s32 fmt, s32 nverts);
struct FscVec3 {
    f32 x;
    f32 y;
    f32 z;
};

#include "JSystem/JMath/Inline.h"
extern "C" double sin(double x);
extern "C" double cos(double x);
static inline void GXColor4u8(u8 r, u8 g, u8 b, u8 a) {
*(volatile u8*)0xCC008000 = r;
*(volatile u8*)0xCC008000 = g;
*(volatile u8*)0xCC008000 = b;
*(volatile u8*)0xCC008000 = a;
}
#pragma opt_propagation off
extern "C" void fn_80158624(char* p, const f32* pos1, f32 size, const f32* pos2, u8* col) {
    f32 dst1[3], dst2[3], src1[3], src2[3];
    Mtx m1, m2;
    f32 c;
    f32 ang;
    f32 s;
    s32 i;
    if (*(u8*)(p + 0xc) < 0xff) {
        u32 tevColor;


        fn_8013B438(lbl_8053AB10);
        GXClearVtxDesc();
        GXSetVtxDesc(9, 1);
        GXSetVtxDesc(0xb, 1);
        GXSetVtxAttrFmt(0, 9, 1, 4, 0);
        GXSetVtxAttrFmt(0, 0xb, 1, 5, 0);
        GXSetChanCtrl(4, 0, 0, 1, 0, 0, 2);
        GXSetNumChans(1);
        GXSetNumTexGens(0);
        tevColor = *(u32*)col;
        GXSetTevColor(1, &tevColor);
        GXSetTevOrder(0, 0xff, 0xff, 4);
        GXSetTevColorIn(0, 0xf, 2, 0xa, 0xf);
        GXSetTevAlphaIn(0, 7, 1, 5, 7);
        GXSetTevColorOp(0, 0, 0, 0, 1, 0);
        GXSetTevAlphaOp(0, 0, 0, 1, 1, 0);
        GXSetNumTevStages(1);
        GXSetBlendMode(1, 1, 1, 0xf);
        GXSetZMode(0, 3, 0);
        GXSetZCompLoc(1);
        GXSetAlphaCompare(7, 0, 0, 7, 0);
        GXSetColorUpdate(1);
        GXSetAlphaUpdate(1);
        GXSetCullMode(2);

        GXBegin(0xa0, 0, 0x22);
        *(volatile f32*)0xCC008000 = pos1[0];
        *(volatile f32*)0xCC008000 = pos1[1];
        *(volatile f32*)0xCC008000 = pos1[2];
        GXColor4u8(0, 0, 0, 0);
        for (i = 0; i < 0x21; i++) {
            ang = 2.0f * ((f32)i * 3.14159265f) / 32.0f;
            s = sin(ang);
            c = cos(ang);
            m1[1][0] = s;
            m1[2][2] = 1.0f;
            m1[0][0] = c;
            m1[0][1] = -s;
            m1[1][1] = c;
            m1[2][1] = 0.0f;
            m1[1][2] = 0.0f;
            m1[2][0] = 0.0f;
            m1[0][2] = 0.0f;
            m1[0][3] = 0.0f;
            m1[1][3] = 0.0f;
            m1[2][3] = 0.0f;
            src1[0] = 0.0f;
            src1[1] = size;
            src1[2] = 0.0f;
            PSMTXMultVec(m1, (Vec*)src1, (Vec*)dst1);
            dst1[1] *= 0.5f;
            JMathInlineVEC::PSVECAdd((Vec*)dst1, (Vec*)pos2, (Vec*)dst1);
            *(volatile f32*)0xCC008000 = dst1[0];
            *(volatile f32*)0xCC008000 = dst1[1];
            *(volatile f32*)0xCC008000 = dst1[2];
            GXColor4u8(col[3], col[3], col[3], col[3]);
        }
    
    {


        GXBegin(0xa0, 0, 0x22);
        *(volatile f32*)0xCC008000 = pos2[0];
        *(volatile f32*)0xCC008000 = pos2[1];
        *(volatile f32*)0xCC008000 = pos2[2];
        GXColor4u8(col[3], col[3], col[3], col[3]);
        for (i = 0; i < 0x21; i++) {
            ang = 2.0f * ((f32)i * 3.14159265f) / 32.0f;
            s = sin(ang);
            c = cos(ang);
            m2[1][0] = s;
            m2[2][2] = 1.0f;
            m2[0][0] = c;
            m2[0][1] = -s;
            m2[1][1] = c;
            m2[2][1] = 0.0f;
            m2[1][2] = 0.0f;
            m2[2][0] = 0.0f;
            m2[0][2] = 0.0f;
            m2[0][3] = 0.0f;
            m2[1][3] = 0.0f;
            m2[2][3] = 0.0f;
            src2[0] = 0.0f;
            src2[1] = size;
            src2[2] = 0.0f;
            PSMTXMultVec(m2, (Vec*)src2, (Vec*)dst2);
            dst2[1] *= 0.5f;
            JMathInlineVEC::PSVECAdd((Vec*)dst2, (Vec*)pos2, (Vec*)dst2);
            *(volatile f32*)0xCC008000 = dst2[0];
            *(volatile f32*)0xCC008000 = dst2[1];
            *(volatile f32*)0xCC008000 = dst2[2];
            GXColor4u8(col[3], col[3], col[3], col[3]);
        }
    }
}
}
#pragma opt_propagation reset
extern "C" void fn_80158B3C(char* p) {
    *(u8*)(p + 0x4) = 0xff;
    *(u8*)(p + 0x5) = 0xff;
    *(u8*)(p + 0x6) = 0xff;
    *(u8*)(p + 0x7) = 0;
    *(u8*)(p + 0xc) = 0xff;
}


extern "C" char* lbl_8053AB10;
extern "C" void fn_8013B438(char* p);
extern "C" void load__10JUTTextureF11_GXTexMapID(char* self, s32 id);
extern "C" void GXClearVtxDesc(void);
extern "C" void GXSetVtxDesc(s32 attr, s32 type);
extern "C" void GXSetVtxAttrFmt(s32 vtxfmt, s32 attr, s32 cnt, s32 fmt, s32 frac);
extern "C" void GXSetChanCtrl(s32 chan, s32 enable, s32 amb, s32 mat, s32 mask, s32 diff, s32 attn);
extern "C" void GXSetNumChans(s32 n);
extern "C" void GXSetTexCoordGen2(s32 coord, s32 type, s32 src, s32 mtx, s32 normalize, s32 post);
extern "C" void GXSetNumTexGens(s32 n);
extern "C" void GXSetTevColor(s32 id, u32* color);
extern "C" void GXSetTevOrder(s32 stage, s32 coord, s32 map, s32 color);
extern "C" void GXSetTevColorIn(s32 stage, s32 a, s32 b, s32 c, s32 d);
extern "C" void GXSetTevAlphaIn(s32 stage, s32 a, s32 b, s32 c, s32 d);
extern "C" void GXSetTevColorOp(s32 stage, s32 op, s32 bias, s32 scale, s32 clamp, s32 reg);
extern "C" void GXSetTevAlphaOp(s32 stage, s32 op, s32 bias, s32 scale, s32 clamp, s32 reg);
extern "C" void GXSetTevSwapMode(s32 stage, s32 ras, s32 tex);
extern "C" void GXSetTevSwapModeTable(s32 id, s32 r, s32 g, s32 b, s32 a);
extern "C" void GXSetNumTevStages(s32 n);
extern "C" void GXSetBlendMode(s32 type, s32 src, s32 dst, s32 op);
extern "C" void GXSetZMode(s32 enable, s32 func, s32 update);
extern "C" void GXSetZCompLoc(s32 before);
extern "C" void GXSetAlphaCompare(s32 comp0, s32 ref0, s32 op, s32 comp1, s32 ref1);
extern "C" void GXSetColorUpdate(u8 enable);
extern "C" void GXSetAlphaUpdate(s32 enable);
extern "C" void GXSetCullMode(s32 mode);
extern "C" void GXBegin(s32 prim, s32 fmt, s32 nverts);
#pragma opt_propagation off
extern "C" void fn_80158B5C(char* p, s32 kind, f32 size, f32* pos, u8* col) {
    if (kind >= 8) {
        return;
    }
    if (*(u8*)(p + 0xc) >= 0xff) {
        if (*(u32*)(p + 0x4) == 0xFFFFFF00) {
            return;
        }
    }
    fn_8013B438(lbl_8053AB10);
    GXClearVtxDesc();
    GXSetVtxDesc(9, 1);
    GXSetVtxDesc(0xd, 1);
    GXSetVtxAttrFmt(0, 9, 1, 4, 0);
    GXSetVtxAttrFmt(0, 0xd, 1, 4, 0);
    GXSetChanCtrl(4, 0, 0, 0, 0, 0, 2);
    GXSetNumChans(1);
    GXSetTexCoordGen2(0, 1, 4, 0x3c, 0, 0x7d);
    GXSetNumTexGens(1);
    if (*(u8*)(p + 0xe) < 0xff) {
        u32 c;
        u8 tmp[4];
        tmp[0] = col[0];
        tmp[1] = col[1];
        tmp[2] = col[2];
        tmp[3] = col[3] * *(u8*)(p + 0xe) / 255;
        c = *(u32*)tmp;
        GXSetTevColor(1, &c);
    } else {
        u32 c = *(u32*)col;
        GXSetTevColor(1, &c);
    }
    GXSetTevOrder(0, 0, 0, 0xff);
    GXSetTevColorIn(0, 0xf, 2, 8, 0xf);
    GXSetTevAlphaIn(0, 7, 1, 4, 7);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaOp(0, 0, 0, 1, 1, 0);
    GXSetTevSwapMode(0, 0, 1);
    GXSetTevSwapModeTable(1, 0, 0, 0, 0);
    GXSetNumTevStages(1);
    GXSetBlendMode(1, 1, 1, 0xf);
    GXSetZMode(0, 3, 0);
    GXSetZCompLoc(1);
    GXSetAlphaCompare(7, 0, 0, 7, 0);
    GXSetColorUpdate(0);
    GXSetAlphaUpdate(1);
    GXSetCullMode(0);
    load__10JUTTextureF11_GXTexMapID(*(char**)(p + 0x8), 0);
    GXBegin(0x80, 0, 4);
    volatile f32* fifo = (volatile f32*)0xCC008000;
    f32 s0;
    f32 right;
    f32 s1;
    f32 left;
    f32 z;
    f32 y;
    f32 front;
    f32 x;
    s0 = 1.0f;
    s1 = 0.0f;
    x = pos[0];
    z = pos[2];
    left = x - size;
    y = pos[1];
    front = z + size;
    right = x + size;
    *fifo = left;
    *fifo = y;
    *fifo = front;
    *fifo = s1;
    *fifo = s1;
    z -= size;
    *fifo = right;
    *fifo = y;
    *fifo = front;
    *fifo = s0;
    *fifo = s1;
    *fifo = right;
    *fifo = y;
    *fifo = z;
    *fifo = s0;
    *fifo = s0;
    *fifo = left;
    *fifo = y;
    *fifo = z;
    *fifo = s1;
    *fifo = s0;
}
#pragma opt_propagation reset
extern "C" char lbl_804BFB60[];
extern "C" const f32 lbl_8053D440;
extern "C" const f32 lbl_8053D43C;
extern "C" const f32 lbl_8053D454;
extern "C" const f32 lbl_8053D458;
extern "C" u32 lbl_8053D420;
extern "C" u32 lbl_8053D424;
extern "C" u32 lbl_8053D428;
extern "C" u32 lbl_8053D42C;
extern "C" void GXInitLightPos(char* light, f32 x, f32 y, f32 z);
extern "C" void GXInitLightAttn(char* light, f32 a0, f32 a1, f32 a2, f32 k0, f32 k1, f32 k2);
extern "C" void GXInitLightColor(char* light, u32* color);
extern "C" void GXLoadLightObjImm(char* light, s32 chan);
extern "C" void GXSetChanAmbColor(s32 chan, u32* color);
extern "C" void GXSetChanMatColor(s32 chan, u32* color);
extern "C" void fn_80158E88(void) {
    u32 c1;
    u32 c2;
    u32 c3;
    u32 c4;
    GXInitLightPos(lbl_804BFB60, lbl_8053D454, lbl_8053D454, lbl_8053D458);
    GXInitLightAttn(lbl_804BFB60, lbl_8053D43C, lbl_8053D440, lbl_8053D440, lbl_8053D43C, lbl_8053D440, lbl_8053D440);
    c1 = lbl_8053D420;
    GXInitLightColor(lbl_804BFB60, &c1);
    GXLoadLightObjImm(lbl_804BFB60, 1);
    GXInitLightPos(lbl_804BFB60, lbl_8053D458, lbl_8053D454, lbl_8053D458);
    c2 = lbl_8053D424;
    GXInitLightColor(lbl_804BFB60, &c2);
    GXLoadLightObjImm(lbl_804BFB60, 2);
    c3 = lbl_8053D428;
    GXSetChanAmbColor(4, &c3);
    c4 = lbl_8053D42C;
    GXSetChanMatColor(4, &c4);
}

extern "C" u8* sManager__8JUTVideo;
extern "C" u32 lbl_80543F28;
extern "C" void fn_8013B460(void* this_);
extern "C" void fn_80158F70(char* p) {
    f32 w;
    f32 h;

    if (*(u32*)(p + 0x4) == 0xFFFFFF00) {
        if (*(u8*)(p + 0xc) >= 0xff) return;
    }
    w = (f32)(s32)*(u16*)(*(u8**)(sManager__8JUTVideo + 0x4) + 0x4);
    h = (f32)(s32)*(u16*)(*(u8**)(sManager__8JUTVideo + 0x4) + 0x6);
    fn_8013B460(lbl_8053AB10);
    GXClearVtxDesc();
    GXSetVtxDesc(9, 1);
    GXSetVtxAttrFmt(0, 9, 1, 4, 0);
    GXSetChanCtrl(4, 0, 0, 0, 0, 0, 2);
    GXSetNumChans(1);
    GXSetNumTexGens(0);
    GXSetTevOrder(0, 0xff, 0xff, 0xff);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
    GXSetTevSwapMode(0, 0, 0);
    GXSetNumTevStages(1);
    GXSetZMode(0, 3, 0);
    GXSetZCompLoc(1);
    GXSetAlphaCompare(7, 0, 0, 7, 0);
    GXSetCullMode(0);
    u8 alpha = *(u8*)(p + 0xc);
    if (alpha < 0xff) {
        u32 c;
        u8 tmp[4];
        *(u32*)tmp = lbl_80543F28;
        tmp[3] = alpha;
        c = *(u32*)tmp;
        GXSetTevColor(1, &c);
    GXSetTevColorIn(0, 0xf, 0xf, 0xf, 0xf);
    GXSetTevAlphaIn(0, 7, 7, 7, 1);
    GXSetBlendMode(1, 1, 1, 0xf);
    GXSetColorUpdate(0);
    GXSetAlphaUpdate(1);
    GXBegin(0x80, 0, 4);
    {
        f32 z = 0.0f;
        GXPosition3f32(z, z, z);
        GXPosition3f32(w, z, z);
        GXPosition3f32(w, h, z);
        GXPosition3f32(z, h, z);
    }
    GXSetColorUpdate(1);
    GXSetAlphaUpdate(0);
    }
    if (*(u32*)(p + 0x4) != 0xFFFFFF00) {
        u32 c = *(u32*)(p + 0x4);
        GXSetTevColor(1, &c);
        GXSetTevColorIn(0, 0xf, 0xf, 0xf, 2);
        GXSetTevAlphaIn(0, 7, 7, 7, 1);
        if (*(u8*)(p + 0xd) != 0) {
            GXSetBlendMode(1, 2, 6, 0xf);
        } else {
            GXSetBlendMode(1, 4, 2, 0xf);
        }
        GXBegin(0x80, 0, 4);
        f32 z2 = lbl_8053D440;
        GXPosition3f32(z2, z2, z2);
        GXPosition3f32(w, z2, z2);
        GXPosition3f32(w, h, z2);
        GXPosition3f32(z2, h, z2);
    }
    if (*(u8*)(p + 0xc) >= 0xff) {
        return;
    }
    GXSetBlendMode(1, 0, 6, 0xf);
    GXSetColorUpdate(1);
    GXSetAlphaUpdate(0);
    GXBegin(0x80, 0, 4);
    f32 z3 = lbl_8053D440;
    GXPosition3f32(z3, z3, z3);
    GXPosition3f32(w, z3, z3);
    GXPosition3f32(w, h, z3);
    GXPosition3f32(z3, h, z3);
}

extern "C" void fn_80159330(char* p) {
    s32 kind = *(s32*)(lbl_8053AAF8 + 0x4c);
    bool flag;
    if (kind == 0xc) {
        return;
    }
    if (*(u8*)(lbl_8053AAF8 + 0x7f) != 0) {
        u8 selected = 0;
        if (kind == 7) goto set;
        if (kind == 8) goto set;
        if (kind == 9) goto set;
        if (kind == 0x16) goto set;
        if (kind == 0xa) goto set;
        if (kind == 0xb) goto set;
        goto done;
    set:
        selected = 1;
    done:
        flag = selected;
    } else {
        u8 selected = 0;
        if (kind == 7) goto set2;
        if (kind == 8) goto set2;
        if (kind == 9) goto set2;
        if (kind == 0x16) goto set2;
        if (kind == 0xa) goto set2;
        if (kind == 0xb) goto set2;
        if (kind == 0xc) goto set2;
        goto done2;
    set2:
        selected = 1;
    done2:
        flag = selected;
    }
    if (flag) {
        if (fn_802DCD0C(fn_802D6A9C())) {
            goto end;
        }
    }
    if (*(u8*)(lbl_8053AAF8 + 0x94) == 0 && *(u8*)(lbl_8053AAF8 + 0x96) == 0) {
        *(u8*)(p + 0xd) = 0;
    }
end:
    *(u8*)(p + 0xe) = 0xff;
}

extern "C" void fn_8015945C(char* p) {
    *(u8*)(p + 0x4) = 0xff;
    *(u8*)(p + 0x5) = 0xff;
    *(u8*)(p + 0x6) = 0xff;
    *(u8*)(p + 0x7) = 0;
    *(u8*)(p + 0xc) = 0xff;
    *(u8*)(p + 0xd) = 0;
    *(u8*)(p + 0xe) = 0xff;
}

extern "C" char lbl_804A0160[];
extern "C" char lbl_80465E28[];
extern "C" char* lbl_8053AAF8;
extern "C" void __dt__10JUTTextureFv(char* p, s32 flag);
extern "C" void __dl__FPv(void* p);
extern "C" void* __nw__FUlP7JKRHeapi(u32 size, void* heap, s32 align);
extern "C" void storeTIMG__10JUTTextureFPC7ResTIMGUc(char* self, const void* timg, u8 palette);
extern "C" char* fn_80159484(char* p, s16 param_2) {
    if (p != 0) {
        *(char**)p = lbl_804A0160;
        __dt__10JUTTextureFv(*(char**)(p + 0x8), 1);
        if (param_2 > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" char* fn_801594E8(char* p, void* heap) {
    struct VObj {
        virtual void v00();
        virtual void v01();
        virtual void v02();
        virtual void v03();
        virtual void* v04(u32, void*);
    };
    char* tex;
    VObj* sub;
    void* uVar2;

    *(char**)p = lbl_804A0160;
    *(s32*)(p + 0x4) = -1;
    tex = (char*)__nw__FUlP7JKRHeapi(0x40, heap, 0);
    if (tex != 0) {
        sub = *(VObj**)(lbl_8053AAF8 + 0xa4);
        uVar2 = sub->v04(0x3f3f3f3f, lbl_80465E28);
        *(s32*)(tex + 0x28) = 0;
        storeTIMG__10JUTTextureFPC7ResTIMGUc(tex, uVar2, 0);
        *(u8*)(tex + 0x3b) = *(u8*)(tex + 0x3b) & 2;
    }
    *(char**)(p + 0x8) = tex;
    return p;
}

static void __sinit_tu_80158624_cpp(void) {
}

struct JASGenericMemPool {
    JASGenericMemPool();
    ~JASGenericMemPool();

    void* mRunner;
    int mFreeMemCount;
    int mTotalMemCount;
    u32 mUsedMemCount;
};

template <typename T>
struct JASMemPool : public JASGenericMemPool {
    JASMemPool<T>() : JASGenericMemPool() {}
    ~JASMemPool<T>() {}
};

template <typename T>
struct JASMemPool_MultiThreaded : public JASGenericMemPool {};

class JASTrack {
public:
    class TChannelMgr;
};
class JASChannel;
class JAIStream;
class JAISoundChild;
class JAISeq;
class JAISe;
class JASPoolObj3_FSA;
class JASPoolObj4_FSA;

template <typename T>
struct JASPoolAllocObject {
    static JASMemPool<T> memPool_;
};

template <typename T>
struct JASPoolAllocObject_MultiThreaded {
    static JASMemPool_MultiThreaded<T> memPool_;
};

template <>
JASMemPool_MultiThreaded<JASTrack::TChannelMgr> JASPoolAllocObject_MultiThreaded<JASTrack::TChannelMgr>::memPool_;
template <>
JASMemPool_MultiThreaded<JASTrack> JASPoolAllocObject_MultiThreaded<JASTrack>::memPool_;
template <>
JASMemPool_MultiThreaded<JASChannel> JASPoolAllocObject_MultiThreaded<JASChannel>::memPool_;
template <>
JASMemPool<JASPoolObj3_FSA> JASPoolAllocObject<JASPoolObj3_FSA>::memPool_;
template <>
JASMemPool<JASPoolObj4_FSA> JASPoolAllocObject<JASPoolObj4_FSA>::memPool_;
template <>
JASMemPool<JAIStream> JASPoolAllocObject<JAIStream>::memPool_;
template <>
JASMemPool<JAISoundChild> JASPoolAllocObject<JAISoundChild>::memPool_;
template <>
JASMemPool<JAISeq> JASPoolAllocObject<JAISeq>::memPool_;
template <>
JASMemPool<JAISe> JASPoolAllocObject<JAISe>::memPool_;