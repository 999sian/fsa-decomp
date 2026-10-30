#include "Game/SinitPoolChain.h"
#include "types.h"
#include "JSystem/J2D/J2DPane.h"
#include "JSystem/J2D/J2DScreen.h"
#include "JSystem/J2D/J2DPicture.h"
#include "JSystem/JKernel/JKRHeap.h"
#include "dolphin/os/OSFastCast.h"

struct FsaNode {
    virtual void v0(void);
    virtual void v1(void);
    virtual void v2(void);
    virtual void v3(void);
    virtual void v4(void);
    virtual void v5(void);
    virtual void v6(void);
    virtual void v7(void);
    virtual void v8(void);
    virtual void v9(s32);
    virtual void v10(void);
    virtual void v11(void);
    virtual void v12(void);
    virtual void v13(void);
    virtual void v14(void);
    virtual FsaNode* v15(u64);
};

static inline bool fsaSelectionFlag(const u8* data, u8 mask) {
    return data[0x243] & mask;
}

struct FsaVt15 {
    void* v[15];
    FsaNode* (*v15)(void* a, u64 b);
};

static inline FsaNode* fsaV15(u8* obj, u64 key) {
    return (*(FsaVt15**)obj)->v15(obj, key);
}

struct FsaSlots {
    virtual void v0(void);
    virtual void v1(void);
    virtual void v2(void);
    virtual void v3(void);
    virtual void v4(void);
    virtual void v5(void);
    virtual void v6(void);
    virtual void v7(s32);
    virtual void v8(void);
    virtual void v9(void);
    virtual void v10(void);
    virtual void v11(void);
    virtual void v12(void);
    virtual void v13(void);
    virtual void v14(void);
    virtual void v15(void);
    virtual void v16(void);
    virtual void v17(void);
    virtual void v18(void);
    virtual void v19(void);
    virtual void v20(void);
    virtual void v21(void);
    virtual void v22(void);
    virtual void v23(void);
    virtual void v24(void);
    virtual void v25(void);
    virtual void v26(void);
    virtual void v27(void);
    virtual void v28(void);
    virtual void v29(void);
    virtual void v30(void);
    virtual void v31(void);
    virtual void v32(void);
    virtual void v33(void);
    virtual void v34(void);
    virtual void v35(void);
    virtual void v36(void);
    virtual void v37(void);
    virtual void v38(void);
    virtual void v39(void);
    virtual void v40(void);
    virtual void v41(void);
    virtual void v42(void);
    virtual void v43(void);
    virtual void v44(void);
    virtual void v45(void);
    virtual void v46(void);
    virtual void v47(void);
    virtual void v48(void);
    virtual void v49(void);
    virtual void v50(void);
    virtual void v51(void);
    virtual void v52(void);
    virtual void v53(void);
    virtual void v54(void);
    virtual void v55(void);
    virtual void v56(void);
    virtual void v57(s32, s32, s32, f32, f32, f32, f32);
    virtual void v58(void);
    virtual void v59(s32, s32, s32, f32, f32, f32, f32);
};

struct FsaNodeB {
    virtual void v0(void);
    virtual void v1(void);
    virtual void v2(void);
    virtual void v3(void);
    virtual void v4(void);
    virtual void v5(void);
    virtual void v6(void);
    virtual void v7(void);
    virtual void v8(void);
    virtual void v9(void);
    virtual void v10(void);
    virtual void v11(void);
    virtual void v12(void);
    virtual FsaSlots* v13(u64);
};

struct FsaDisposable {
    virtual void del(s32);
};


extern "C" void* lbl_8053AB10;
extern "C" void* lbl_8053AD68;
extern "C" const f32 lbl_80543534;
extern "C" f32 lbl_80543568;
extern "C" f32 lbl_8054356C;
extern "C" void fn_8013B490(void*);
extern "C" void fn_803D75B0(u8*);
extern "C" s32 fn_80138A30(void*);
extern "C" void fn_804310CC(void*);
extern "C" void fn_80402E08(void*, f32, f32);
extern "C" u8* fn_804030C4(u32, void*);
extern "C" void fn_80440D78(void*, void*);
extern "C" void fn_80440BF4(void*, s32);
extern "C" void fn_80458FF0(void*, u32, s32, s32);
extern "C" void* lbl_8053AEC0;
extern "C" void* lbl_8053AAF8;
extern "C" void* lbl_8053AED8;
extern "C" void* lbl_8053AF80;
extern "C" const char lbl_80476F80[];
extern "C" char lbl_80529DEC[];
extern "C" const f32 lbl_80543530;
extern "C" f32 lbl_80543538;
extern "C" f32 lbl_8054353C;
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(void*, f32, f32, void*);
extern "C" u8 fn_80402940(void*, s32, s32, f32, f32);
extern "C" f32* getBounds__7J2DPaneFv(void*);
extern "C" const u64 lbl_80477180[][16];
extern "C" const u64 lbl_80477408[];

struct FsaVtJ2D {
    virtual void v2(void);
    virtual void v3(void);
    virtual void v4(void);
    virtual void v5(void);
    virtual void v6(void);
    virtual void v7(void);
    virtual void v8(void);
    virtual void v9(void);
    virtual void v10(void);
    virtual void v11(void);
    virtual void v12(void);
    virtual void v13(void);
    virtual void v14(void);
    virtual void* search(u32, u32, u32);
    virtual void v16(void);
    virtual void v17(void);
    virtual void v18(void);
    virtual void v19(void);
    virtual void v20(void);
    virtual void v21(void);
    virtual void v22(void);
    virtual void v23(void);
    virtual void set24(void*);
    virtual void v25(void);
    virtual void v26(void);
    virtual void v27(void);
    virtual void set28(void*);
    virtual void v29(void);
    virtual void v30(void);
    virtual void v31(void);
    virtual void v32(void);
    virtual void v33(void);
    virtual void v34(void);
    virtual void v35(void);
    virtual void v36(void);
    virtual void v37(void);
    virtual void v38(void);
    virtual void set39(void*);
    virtual void v40(void);
    virtual void v41(void);
    virtual void v42(void);
    virtual void v43(void);
    virtual void v44(void);
    virtual void v45(void);
    virtual void v46(void);
    virtual void v47(void);
    virtual void v48(void);
    virtual void v49(void);
    virtual void v50(void);
    virtual void v51(void);
    virtual void v52(void);
    virtual void v53(void);
    virtual void v54(void);
    virtual void v55(void);
    virtual void v56(void);
    virtual void v57(void);
    virtual void v58(void);
    virtual void v59(void);
    virtual void v60(void);
    virtual void v61(void);
    virtual void v62(void);
    virtual void v63(void);
    virtual void v64(void);
    virtual void v65(void);
    virtual void v66(void);
    virtual void v67(void);
    virtual void v68(void);
    virtual void v69(void);
    virtual void v70(void);
    virtual void v71(void);
    virtual void v72(void);
    virtual void v73(void);
    virtual void v74(void);
    virtual void v75(void);
    virtual void set76(void*, void*);
};
extern "C" void fn_803D7098(u8* param_1) {
    f32 f28;
    f32 f29;
    f32 f30;
    f32 f31;
    f32 f0;
    u8* p;
    s32 i;
    u8* q;
    s32 j;
    s32 k;
    s16 b;
    s16 a;
    u8 flag0 = 0;
    u8 flag1 = 0;
    u8 flag2 = 0;
    u8 flag3 = 0;

    *(s32*)(param_1 + 0x60) += 1;
    if (*(s32*)(param_1 + 0x60) > 4) {
        flag0 = fn_80402940(*(void**)(param_1 + 0x30), 0x16, 0, lbl_80543530, lbl_80543534);
    }
    if (*(s32*)(param_1 + 0x60) > 0x10) {
        flag1 = fn_80402940(*(void**)(param_1 + 0x48), 0x18, 0, lbl_80543530, lbl_80543534);
    }
    if (*(s32*)(param_1 + 0x60) > 0) {
        i = 0;
        p = param_1;
        for (; i < 4; i++) {
            flag2 = fn_80402940(*(void**)(p + 0x34), 0x16, 0, lbl_80543538, lbl_80543534);
            p += 4;
        }
    }
    if (((u8*)lbl_8053AAF8)[0x7f] != 0) {
        flag3 = 1;
    } else {
        q = param_1;
        for (k = 0, j = 0; k < 2; k++, j += 5) {
            if (*(s32*)(param_1 + 0x60) > j) {
                flag3 = fn_80402940(*(void**)(q + 0x24), 0x10, 0, lbl_8054353C, lbl_80543534);
            }
            q += 4;
        }
    }

    if (flag0 && flag1 && flag2 && flag3) {
        (*(u8**)(*(u8**)(param_1 + 0x2c) + 4))[0xb0] = 1;
        param_1[0x78] = 0;
        param_1[0x79] = param_1[0x78];
        *(s16*)(param_1 + 0x6e) = 0;
        param_1[0x7a] = 3;
        param_1[0x7f] = 1;
        *(s16*)(param_1 + 0x70) = 1;
        a = *(s16*)(param_1 + 0x68);
        if (a >= 0 && a < 4) {
            b = *(s16*)(param_1 + 0x6a);
            if (b >= 0) {
                f32 baseX, tmpX, originX, targetX;
                tmpX = ((f32*)((J2DPane*)*(void**)(param_1 + 0x4))->search(lbl_80477180[0][0])->getBounds())[0];
                f0 = ((f32*)((J2DPane*)*(void**)(param_1 + 0x4))->search(lbl_80477408[0])->getBounds())[0];
                baseX = f0 + tmpX;
                tmpX = ((f32*)((J2DPane*)*(void**)(param_1 + 0x4))->search(lbl_80477180[a][b])->getBounds())[0];
                f0 = ((f32*)((J2DPane*)*(void**)(param_1 + 0x4))->search(lbl_80477408[*(s16*)(param_1 + 0x68)])->getBounds())[0];
                targetX = f0 + tmpX;
                originX = ((f32*)((J2DPane*)*(void**)(param_1 + 0x8))->search(0x0050306B616B3030ULL)->getBounds())[0];
                tmpX = ((f32*)((J2DPane*)*(void**)(param_1 + 0x4))->search(lbl_80477408[0])->getBounds())[0];
                f0 = ((f32*)((J2DPane*)*(void**)(param_1 + 0x4))->search(0x004E646174613033ULL)->getBounds())[0];
                tmpX = f0 + tmpX;
                f0 = ((f32*)((J2DPane*)*(void**)(param_1 + 0x4))->search(lbl_80477180[0][0])->getBounds())[0];
                f0 = f0 + tmpX;
                f0 = f0 - originX;
                f0 = f0 + targetX;
                f0 = f0 - baseX;
                *(f32*)(param_1 + 0x58) = f0;

                f28 = ((f32*)((J2DPane*)*(void**)(param_1 + 0x4))->search(lbl_80477180[0][0])->getBounds())[1];
                f0 = ((f32*)((J2DPane*)*(void**)(param_1 + 0x4))->search(lbl_80477408[0])->getBounds())[1];
                f28 = f0 + f28;
                f29 = ((f32*)((J2DPane*)*(void**)(param_1 + 0x4))->search(lbl_80477180[*(s16*)(param_1 + 0x68)][*(s16*)(param_1 + 0x6a)])->getBounds())[1];
                f0 = ((f32*)((J2DPane*)*(void**)(param_1 + 0x4))->search(lbl_80477408[*(s16*)(param_1 + 0x68)])->getBounds())[1];
                f29 = f0 + f29;
                f30 = ((f32*)((J2DPane*)*(void**)(param_1 + 0x8))->search(0x0050306B616B3030ULL)->getBounds())[1];
                f31 = ((f32*)((J2DPane*)*(void**)(param_1 + 0x4))->search(lbl_80477408[0])->getBounds())[1];
                f0 = ((f32*)((J2DPane*)*(void**)(param_1 + 0x4))->search(0x004E646174613033ULL)->getBounds())[1];
                f31 = f0 + f31;
                f0 = ((f32*)((J2DPane*)*(void**)(param_1 + 0x4))->search(lbl_80477180[0][0])->getBounds())[1];
                f0 = f0 + f31;
                f0 = f0 - f30;
                f0 = f0 + f29;
                f0 = f0 - f28;
                *(f32*)(param_1 + 0x5c) = f0;
            }
        }
    }
    fn_80402E08(*(void**)(param_1 + 0x44), *(f32*)(param_1 + 0x58), *(f32*)(param_1 + 0x5c));
}


extern "C" u32 fn_80309A9C(void*, s32, s32);
extern "C" void fn_80431A9C(void*, s32, s32, void*);
extern "C" s32 fn_804317AC(void*);
extern "C" s32 fn_80431740(void*);
extern "C" void fn_804310BC(void*);
extern "C" void* fn_8013CC50(s32, void*, s32, s32, s32, s32, s32, s32, f32);
extern "C" void* fn_8013C824();
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void*,void*);
extern "C" void fn_80431174(void*, u8);
extern "C" u32 fn_80309C4C(void*, s32, s32);
extern "C" void fn_80458880(void*, s32, s32);
extern "C" void* lbl_8053AD30;
#pragma opt_common_subs off
extern "C" void fn_803D75B0(u8* self) {
 const u64* tag;
 const u64* row;
 s32 i,j;
 f32 f30, f31, f29;
 register const char* base=lbl_80476F80;
 if(self[0x80]==1) {
  fn_80431174(lbl_8053AEC0,self[0x78]);
 }
  switch(self[0x7f]) {
  case 0:fn_803D7098(self);break;
  case 1:
   if(fn_80309C4C(lbl_8053AD30,1,-1)!=0) {
    if(self[0x78]!=0) {--self[0x78];self[0x79]=self[0x78];*(s16*)(self+0x6e)=1;fn_80458880(lbl_8053AF80,0x26,-1);}
   } else if(fn_80309C4C(lbl_8053AD30,2,-1)!=0) {
    if(self[0x78]<1) {++self[0x78];self[0x79]=self[0x78];*(s16*)(self+0x6e)=1;fn_80458880(lbl_8053AF80,0x26,-1);}
   } else if(fn_80309C4C(lbl_8053AD30,0x100,-1)!=0) {
    *(s16*)(self+0x72)=0;self[0x7a]=2;self[0x79]=self[0x78];
    if(self[0x78]==0) {self[0x76]=8;fn_80458880(lbl_8053AF80,11,-1);}
    else {fn_80431A9C(lbl_8053AEC0,0x10b,0,self+0x78);self[0x7f]=2;fn_80458880(lbl_8053AF80,12,-1);}
    *(s16*)(self+0x6e)=1;
   } break;
  case 2:
   if(self[0x81]>72) self[0x81]=80;else self[0x81]+=8;
   if(fn_804317AC(lbl_8053AEC0)!=0) {self[0x81]=80;self[0x7f]=3;}break;
  case 3:
   fn_80431174(lbl_8053AEC0,self[0x78]);
   if(fn_80309A9C(lbl_8053AD30,2,-1)!=0) {
    if(self[0x78]==0) {self[0x78]=1;fn_80458880(lbl_8053AF80,0,-1);}
   } else if(fn_80309A9C(lbl_8053AD30,1,-1)!=0) {
    if(self[0x78]==1) {self[0x78]=0;fn_80458880(lbl_8053AF80,0,-1);}
   } else if(fn_80309C4C(lbl_8053AD30,0x1100,-1)!=0) {self[0x7f]=4;fn_80458880(lbl_8053AF80,11,-1);}break;
  case 4:
   if(self[0x81]<8) self[0x81]=0;else self[0x81]-=8;
   if(fn_80431740(lbl_8053AEC0)!=0) {
    self[0x81]=0;
    if(self[0x78]==0) {fn_804310BC(lbl_8053AEC0);self[0x76]=7;}
    else self[0x7f]=1;
   }break;
  }
 if(*(s16*)(self+0x70)!=0) {
  ++*(s32*)(self+0x64);if(*(s32*)(self+0x64)>=140) *(s32*)(self+0x64)=20;
  if(self[0x7e]==0) {
   if(*(s32*)(self+0x64)<=20) {
    if(*(s16*)(self+0x6a)>=0) {
     f30=(f32)*(s32*)(self+0x64)/20.0f;
     (*(J2DPane**)(self+8))->search(0x50306b613030ULL)->setAlpha((f32)(u32)self[0x7b]*f30);
     ((J2DPicture*)(*(J2DPane**)(self+8))->search(0x50306b613030ULL))->setBlackWhite(((J2DPicture*)(*(J2DPane**)(self+4))->search(((const u64(*)[16])base)[*(s16*)(self+0x68)][*(s16*)(self+0x6a)]))->getBlack(),((J2DPicture*)(*(J2DPane**)(self+4))->search(((const u64(*)[16])base)[*(s16*)(self+0x68)][*(s16*)(self+0x6a)]))->getWhite());
     J2DPicture::TCornerColor colors;
     ((J2DPicture*)(*(J2DPane**)(self+4))->search(((const u64(*)[16])base)[*(s16*)(self+0x68)][*(s16*)(self+0x6a)]))->getCornerColor(colors);
     ((J2DPicture*)(*(J2DPane**)(self+8))->search(0x50306b613030ULL))->setCornerColor(colors);
     (*(J2DPane**)(self+8))->search(0x50737461726c69ULL)->setAlpha((f32)(u32)self[0x7d]*f30);
    }
   } else if(*(s32*)(self+0x64)<=40) {
    f30=(f32)(*(s32*)(self+0x64)-20)/20.0f;
    row=(const u64*)(base+0x200);
    for(i=0;i<4;i++) {tag=row; for(j=0;j<16;j++) {
     if(((*(J2DPane**)(self+4))->search(*tag))->isVisible())
      (*(J2DPane**)(self+4))->search(*tag)->setAlpha((f32)(u32)self[0x7c]*f30);
     ++tag;
    } row+=16;}
    if(*(s16*)(self+0x6a)>=0) (*(J2DPane**)(self+8))->search(0x50306b616b3030ULL)->setAlpha((f32)(u32)self[0x7c]*f30);
   } else self[0x7e]=1;
  }
  if(*(s16*)(self+0x6a)>=0) {
   f30=(*(J2DPane**)(self+8))->search(0x50306b613030ULL)->getWidth();
   f31=((f32*)(*(J2DPane**)(self+8))->search(0x50306b613030ULL)->getBounds())[0];
   f29=*(f32*)(self+0x58)+((f32*)(*(J2DPane**)(self+8))->search(0x50306b616b3030ULL)->getBounds())[0]+f31+f30*0.5f;
   f30=(*(J2DPane**)(self+8))->search(0x50306b613030ULL)->getHeight();
   f31=((f32*)(*(J2DPane**)(self+8))->search(0x50306b613030ULL)->getBounds())[1];
   f30=*(f32*)(self+0x5c)+((f32*)(*(J2DPane**)(self+8))->search(0x50306b616b3030ULL)->getBounds())[1]+f31+f30*0.5f;
   if(*(s32*)(self+0x64)==80&&*(void**)(self+0x54)==0) {
    Vec pos;pos.x=f29;pos.y=f30;pos.z=0.0f;
    *(void**)(self+0x54)=fn_8013CC50(0,&pos,0x4d0,0,0,0,0,1,1.0f);
    *(u32*)(*(u8**)(self+0x54)+0xf4)|=0x40;
   }
   *(f32*)(*(u8**)(self+0x10)+8)=*(s32*)(self+0x64);
   (*(J2DPane**)(self+8))->search(0x50306b616b3030ULL)->animationTransform();
   if(*(s32*)(self+0x64)>1&&*(s32*)(self+0x64)<20) {
    if(*(void**)(self+0x4c)==0) {
     Vec pos;pos.x=f29;pos.y=f30;pos.z=0.0f;
     *(void**)(self+0x4c)=fn_8013CC50(0,&pos,0x4cf,0,0,0,0,1,1.0f);
    }
    u8* e=*(u8**)(self+0x4c);
    *(f32*)(e+0xa4)=f29;*(f32*)(e+0xa8)=f30;*(f32*)(e+0xac)=0.0f;
    if(*(s32*)(self+0x64)==19&&*(void**)(self+0x50)==0) {
     Vec pos;pos.x=f29;pos.y=f30;pos.z=0.0f;
     *(void**)(self+0x50)=fn_8013CC50(0,&pos,0x4d1,0,0,0,0,1,1.0f);
     *(u32*)(*(u8**)(self+0x50)+0xf4)|=0x40;
    }
   } else {
    u8* e=*(u8**)(self+0x4c);
    if(e) {*(u32*)(e+0xf4)|=1;*(s32*)(e+0x24)=1;*(void**)(self+0x4c)=0;}
   }
   if(*(s32*)(self+0x64)>=20) {
    *(f32*)(*(u8**)(self+0x18)+8)=*(s32*)(self+0x64);
    (*(J2DScreen**)(self+8))->animation();
   }
  }
 }
  s16 group=*(s16*)(self+0x68);
  if(group>=0&&group<4) {
   ++*(s16*)(self+0x74);if(*(s16*)(self+0x74)>=120) *(s16*)(self+0x74)=0;
   s32 t=*(s16*)(self+0x74);s32 pulse=120-t;if(t<60) pulse=t;
   (*(J2DPane**)(self+4))->search(((const u64*)(base+0x400))[*(s16*)(self+0x68)])->setAlpha(80.0f*((f32)pulse/60.0f));
  }
 if(self[0x80]==2) {
  if(self[0x81]>72) self[0x81]=80;else self[0x81]+=8;
  if(fn_804317AC(lbl_8053AEC0)!=0) {self[0x81]=80;self[0x80]=1;}
 } else if(self[0x80]==3) {
  if(self[0x81]<8) self[0x81]=0;else self[0x81]-=8;
  if(fn_80431740(lbl_8053AEC0)!=0) {self[0x81]=0;self[0x80]=0;}
 }
 for(s32 i=1;i<3;i++) {
  u8* e=*(u8**)(self+0x4c+i*4);
  if(e) {
   u8 valid=0;
   if((*(u32*)(e+0xf4)&8)!=0&&*(s32*)(e+0xd0)+*(s32*)(e+0xdc)==0) valid=1;
   if(valid) {
    forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((u8*)fn_8013C824()+0xc),*(void**)(self+0x4c+i*4));
    *(void**)(self+0x4c+i*4)=0;
   }
  }
 }
}
#pragma opt_common_subs reset
extern "C" void fn_803D82EC(u8* param_1) {
    FsaSlots* obj;

    fn_8013B490(lbl_8053AB10);
    obj = *(FsaSlots**)(param_1 + 0x1c);
    obj->v7(param_1[0x77]);
    obj = *(FsaSlots**)(param_1 + 0x1c);
    obj->v57(0, 0, 0, lbl_80543534, lbl_80543534, lbl_80543568, lbl_8054356C);
}

extern "C" f32 lbl_80543548;
extern "C" f32 lbl_80543570;
extern "C" f32 lbl_80543574;
extern "C" f32 lbl_80543578;
extern "C" f32 lbl_8054357C;
extern "C" f32 lbl_80543580;
extern "C" f32 lbl_80543584;
extern "C" f32 lbl_80543588;
extern "C" void fn_804316EC(void*);
extern "C" void fn_80440EE8(void*);
#pragma opt_propagation off
extern "C" void fn_803D8364(u8* param_1) {
    f32 f31;
    f32 f30;
    s32 k;
    s32 t;

    if (param_1[0x7f] == 1 || (u8)(param_1[0x7f] - 2) <= 1 || param_1[0x7f] == 4) {
        f31 = lbl_80543534;
        if (*(s16*)(param_1 + 0x6e) > 0) {
            if (*(s16*)(param_1 + 0x6e) == 1) {
                *(s16*)(param_1 + 0x6c) = 0x1e;
            }
            t = *(s16*)(param_1 + 0x6e);
            k = t < 5 ? t : 10 - t;
            f31 = lbl_80543570 * (f32)(k * k) / lbl_80543574;
            if (t < 10) {
                *(s16*)(param_1 + 0x6e) += 1;
            } else {
                *(s16*)(param_1 + 0x6e) = 0;
            }
        }
        *(s16*)(param_1 + 0x6c) += 1;
        if (*(s16*)(param_1 + 0x6c) >= 0x3c) {
            *(s16*)(param_1 + 0x6c) = 0;
        }

        if (param_1[0x7f] == 2 || param_1[0x7f] == 3 || param_1[0x7f] == 4) {
            (*(FsaSlots**)(param_1 + 0x20))->v7(param_1[0x81]);
            (*(FsaSlots**)(param_1 + 0x20))->v57(0, 0, 0, lbl_80543578, lbl_80543578, lbl_8054357C, lbl_80543580);
            fn_804316EC(lbl_8053AEC0);
            f30 = lbl_80543584;
        } else {
            t = *(s16*)(param_1 + 0x6c);
            if (t < 30) {
                f30 = lbl_80543584 * ((f32)(t * t) / lbl_80543588);
            } else {
                k = t - 30;
                f30 = lbl_80543584 * (lbl_80543548 - (f32)(k * k) / lbl_80543588);
            }
            if (param_1[0x79] == 0) {
                fn_80402E08(*(void**)(param_1 + 0x2c), lbl_80543534, f31);
                fn_80402E08(*(void**)(param_1 + 0x24), lbl_80543534, f31);
                fn_80402E08(*(void**)(param_1 + 0x28), lbl_80543534, lbl_80543534);
            } else {
                fn_80402E08(*(void**)(param_1 + 0x2c), *(f32*)(*(u8**)(param_1 + 0x28) + 8) - *(f32*)(*(u8**)(param_1 + 0x24) + 8), f31);
                fn_80402E08(*(void**)(param_1 + 0x24), lbl_80543534, lbl_80543534);
                fn_80402E08(*(void**)(param_1 + 0x28), lbl_80543534, f31);
            }
            if (lbl_80543534 == f31) {
                if (param_1[0x79] != param_1[0x78]) {
                    param_1[0x79] = param_1[0x78];
                    u8* o = *(u8**)(param_1 + 0x2c);
                    (*(FsaSlots**)(o + 4))->v7((s32)f30);
                }
            }
        }
        ((*(FsaNodeB**)(param_1 + 4))->v13(0x5061636375723031ULL))->v7((s32)f30);
        fn_80440EE8(lbl_8053AED8);
    }
}
#pragma opt_propagation reset
extern "C" void fn_803D8670(u8* param_1) {
    FsaSlots* obj;

    fn_8013B490(lbl_8053AB10);
    draw__9J2DScreenFffPC14J2DGrafContext(*(void**)(param_1 + 4), lbl_80543534, lbl_80543534, *(void**)((u8*)lbl_8053AB10 + 0x10));
    draw__9J2DScreenFffPC14J2DGrafContext(*(void**)(param_1 + 8), lbl_80543534, lbl_80543534, *(void**)((u8*)lbl_8053AB10 + 0x10));
    obj = *(FsaSlots**)(param_1 + 0x1c);
    obj->v7(param_1[0x77]);
    obj = *(FsaSlots**)(param_1 + 0x1c);
    obj->v57(0, 0, 0, lbl_80543534, lbl_80543534, lbl_80543568, lbl_8054356C);
}

extern "C" void fn_803D8718(u8* param_1) {
    s32 bVar1 = param_1[0x76];

    switch (bVar1) {
    case 6:
        if (param_1[0x77] >= 0xf5) {
            param_1[0x77] = 0xff;
            param_1[0x76] = 5;
        } else {
            param_1[0x77] += 10;
        }
        break;
    case 5:
        if (param_1[0x77] <= 10) {
            param_1[0x77] = 0;
            ((u8*)lbl_8053AD68)[0x1d] = 1;
            param_1[0x76] = 2;
        } else {
            param_1[0x77] -= 10;
        }
        break;
    case 2:
        fn_803D75B0(param_1);
        break;
    }
}

extern "C" void fn_803D87C0(u8* param_1) {
    u8 mask;
    u8* lbl;
    register u8* base = (u8*)lbl_80476F80;
    s32 j;
    s32 count;
    const u64* k26;
    const u64* k25;
    s32* cnt;
    const u64* k23;
    const u64* k22;
    const u64* k19;
    const u64* k20;
    const u64* k21;
    const u64* k26o;
    const u64* k25o;
    s32 n;
    J2DPane* p;

    fn_804310CC(lbl_8053AEC0);
    k19 = (const u64*)(base + 0x420);
    k20 = (const u64*)(base + 0x438);
    k21 = (const u64*)(base + 0x450);
    for (n = 0; n < 3; n++) {
        if (n >= fn_80138A30(lbl_8053AAF8) - 1) {
            p = (*(J2DPane**)(param_1 + 4))->search(*k19);
            p->show();
            p = (*(J2DPane**)(param_1 + 4))->search(*k20);
            p->hide();
            p = (*(J2DPane**)(param_1 + 4))->search(*k21);
            p->hide();
        } else {
            p = (*(J2DPane**)(param_1 + 4))->search(*k19);
            p->hide();
            p = (*(J2DPane**)(param_1 + 4))->search(*k20);
            p->show();
            p = (*(J2DPane**)(param_1 + 4))->search(*k21);
            p->show();
        }
        k19++;
        k20++;
        k21++;
    }

    lbl = (u8*)lbl_80529DEC;
    k23 = (const u64*)(base + 0x468);
    k22 = (const u64*)(base + 0x400);
    cnt = (s32*)lbl;
    k26o = (const u64*)((u8*)k23 - 0x468);
    k25o = (const u64*)(base + 0x200);
    for (s32 i = 0; i < 4; i++) {
        mask = (u8)(1 << i);
        count = *(s32*)((u8*)cnt + 0x140);
        if (fsaSelectionFlag(lbl, mask) & 1) {
            *(s16*)(param_1 + 0x68) = i;
            p = (*(J2DPane**)(param_1 + 4))->search(*k23);
            p->show();
            p = (*(J2DPane**)(param_1 + 4))->search(*k22);
            p->show();
        } else {
            p = (*(J2DPane**)(param_1 + 4))->search(*k23);
            p->hide();
            p = (*(J2DPane**)(param_1 + 4))->search(*k22);
            p->hide();
        }
        k26 = k26o;
        k25 = k25o;
        for (j = 0; j < 16; j++) {
            if (j < count && (((u8*)lbl_8053AAF8)[0x82] & mask)) {
                if ((lbl[0x243] & mask) && j == count - 1) {
                    *(s16*)(param_1 + 0x6a) = j;
                    p = (*(J2DPane**)(param_1 + 4))->search(*k26);
                    p->hide();
                    p = (*(J2DPane**)(param_1 + 4))->search(*k25);
                    p->hide();
                } else {
                    p = (*(J2DPane**)(param_1 + 4))->search(*k26);
                    p->show();
                    p = (*(J2DPane**)(param_1 + 4))->search(*k25);
                    p->show();
                    p = (*(J2DPane**)(param_1 + 4))->search(*k25);
                    p->setAlpha(0);
                }
            } else {
                p = (*(J2DPane**)(param_1 + 4))->search(*k26);
                p->hide();
                p = (*(J2DPane**)(param_1 + 4))->search(*k25);
                p->hide();
            }
            k26++;
            k25++;
        }
        cnt++;
        k23++;
        k22++;
        k26o += 0x10;
        k25o += 0x10;
    }

    p = (*(J2DPane**)(param_1 + 8))->search(0x0050306b616b3030ULL);
    p->setAlpha(0);
    p = (*(J2DPane**)(param_1 + 8))->search(0x000050306b613030ULL);
    p->setAlpha(0);
    p = (*(J2DPane**)(param_1 + 8))->search(0x0050737461726c69ULL);
    p->setAlpha(0);
    fn_80402E08(*(u8**)(param_1 + 0x30), lbl_80543534, lbl_80543530);
    *(u16*)(*(u8**)(param_1 + 0x30) + 0x22) = 0;
    fn_80402E08(*(u8**)(param_1 + 0x48), lbl_80543534, lbl_80543530);
    *(u16*)(*(u8**)(param_1 + 0x48) + 0x22) = 0;
    for (s32 i = 0; i < 4; i++) {
        fn_80402E08(*(u8**)(param_1 + 0x34 + i * 4), lbl_80543534, lbl_80543538);
        *(u16*)(*(u8**)(param_1 + 0x34 + i * 4) + 0x22) = 0;
    }
    void* resource = fn_804030C4(0x54494d47, (void*)(base + 0x4a8));
    fn_80440D78(lbl_8053AED8, resource);
    fn_804030C4(0x54494d47, (void*)(base + 0x4bc));
    fn_80440BF4(lbl_8053AED8, 0);
    (*(u8**)(*(u8**)(param_1 + 0x2c) + 4))[0xb0] = 0;
    p = (J2DPane*)*(u8**)(*(u8**)(param_1 + 0x2c) + 4);
    p->setAlpha(0);
    p = (*(J2DPane**)(param_1 + 4))->search(0x5061636375723031ULL);
    p->setAlpha(0);
    for (s32 i = 0; i < 2; i++) {
        fn_80402E08(*(u8**)(param_1 + 0x24 + i * 4), lbl_80543534, lbl_8054353C);
        *(u16*)(*(u8**)(param_1 + 0x24 + i * 4) + 0x22) = 0;
    }
    lbl[0x243] = 0;
    fn_80458FF0(lbl_8053AF80, 0x1000005, 1, 0);
}

extern "C" char lbl_804B03D8[];
extern "C" char lbl_80529DEC[];
extern "C" void* lbl_8053ADC0;
extern "C" void getTotalFreeSize__7JKRHeapFv(void*);
extern "C" void* fn_8013C824(void);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void*, void*);
extern "C" void __dl__FPv(void*);
extern "C" u8* fn_803D8D74(u8* param_1, s16 param_2) {
    void** slot;
    u8* obj;

    if (param_1 != 0) {
        *(void**)param_1 = lbl_804B03D8;
        getTotalFreeSize__7JKRHeapFv(*(void**)(lbl_80529DEC + 8));
        obj = *(u8**)(param_1 + 0x4c);
        if (obj != 0) {
            *(u32*)(obj + 0xf4) |= 1;
            *(s32*)(obj + 0x24) = 1;
            *(void**)(param_1 + 0x4c) = 0;
        }
        slot = (void**)(param_1 + 4);
        for (int i = 1; i < 3; i++, slot++) {
            if (slot[0x13] != 0) {
                void* manager = *(void**)((u8*)fn_8013C824() + 0xc);
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(manager, slot[0x13]);
                slot[0x13] = 0;
            }
        }
        obj = *(u8**)(param_1 + 0x4);
        if (obj != 0) {
            ((FsaDisposable*)obj)->del(1);
        }
        *(void**)(param_1 + 0x4) = 0;
        obj = *(u8**)(param_1 + 0x8);
        if (obj != 0) {
            ((FsaDisposable*)obj)->del(1);
        }
        *(void**)(param_1 + 0x8) = 0;
        obj = *(u8**)(param_1 + 0x1c);
        if (obj != 0) {
            ((FsaDisposable*)obj)->del(1);
        }
        *(void**)(param_1 + 0x1c) = 0;
        obj = *(u8**)(param_1 + 0x20);
        if (obj != 0) {
            ((FsaDisposable*)obj)->del(1);
        }
        *(void**)(param_1 + 0x20) = 0;
        slot = (void**)param_1;
        for (int i = 0; i < 2; i++, slot++) {
            obj = *(u8**)(slot + 9);
            if (obj != 0) {
                ((FsaDisposable*)obj)->del(1);
            }
            slot[9] = 0;
        }
        obj = *(u8**)(param_1 + 0x2c);
        if (obj != 0) {
            ((FsaDisposable*)obj)->del(1);
        }
        *(void**)(param_1 + 0x2c) = 0;
        obj = *(u8**)(param_1 + 0x30);
        if (obj != 0) {
            ((FsaDisposable*)obj)->del(1);
        }
        *(void**)(param_1 + 0x30) = 0;
        slot = (void**)param_1;
        for (int i = 0; i < 4; i++, slot++) {
            obj = *(u8**)(slot + 13);
            if (obj != 0) {
                ((FsaDisposable*)obj)->del(1);
            }
            slot[13] = 0;
        }
        obj = *(u8**)(param_1 + 0x44);
        if (obj != 0) {
            ((FsaDisposable*)obj)->del(1);
        }
        *(void**)(param_1 + 0x44) = 0;
        obj = *(u8**)(param_1 + 0x10);
        if (obj != 0) {
            ((FsaDisposable*)obj)->del(1);
        }
        *(void**)(param_1 + 0x10) = 0;
        obj = *(u8**)(param_1 + 0x18);
        if (obj != 0) {
            ((FsaDisposable*)obj)->del(1);
        }
        *(void**)(param_1 + 0x18) = 0;
        lbl_8053ADC0 = 0;
        if (param_2 > 0) {
            __dl__FPv(param_1);
        }
    }
    return param_1;
}

typedef void* (*FsaFind)(void*, u32, u32, u32);
typedef void (*FsaSet1)(void*, void*);
typedef void (*FsaSet2)(void*, void*, void*);
extern "C" char lbl_804AF86C[];
extern "C" void* lbl_8053AD78;
extern "C" void* __nw__FUl(u32);
extern "C" void fn_80402F04(void*, void*);
extern "C" void* fn_80403144(u32, void*);
extern "C" void* load__20J2DAnmLoaderDataBaseFPCv(void*);
extern "C" void fn_803832BC(void*, u32, s32, s32, s32);
extern "C" void __ct__9J2DScreenFv(void*);
extern "C" void __ct__10J2DPictureFPC7ResTIMG(void*, void*);
extern "C" u8* fn_803D901C(register u8* p) {
    const char* base = (const char*)lbl_80476F80;
    u8* n;
    JUTFont* font;

    *(void**)p = lbl_804B03D8;
    ((JKRHeap*)*(void**)((u8*)lbl_80529DEC + 8))->getTotalFreeSize();
    lbl_8053ADC0 = p;

    *(J2DScreen**)(p + 4) = new J2DScreen();
    (*(J2DScreen**)(p + 4))->setPriority(base + 0x4d0, 0x1100000, (JKRArchive*)*(void**)((u8*)lbl_8053AD68 + 0x14));
    *(J2DScreen**)(p + 8) = new J2DScreen();
    (*(J2DScreen**)(p + 8))->setPriority(base + 0x4dc, 0x1100000, (JKRArchive*)*(void**)((u8*)lbl_8053AD68 + 0x14));

    const ResTIMG* tex = (const ResTIMG*)fn_804030C4(0x54494D47, (void*)(base + 0x4ec));
    *(J2DPicture**)(p + 0x1c) = new J2DPicture(tex);
    (*(J2DPicture**)(p + 0x1c))->setBlackWhite(JUtility::TColor(0xff), JUtility::TColor(0));
    *(J2DPicture**)(p + 0x20) = new J2DPicture(tex);
    (*(J2DPicture**)(p + 0x20))->setBlackWhite(JUtility::TColor(0xff), JUtility::TColor(0));

    font = *(JUTFont**)((u8*)lbl_8053AD78 + 0x154);
    ((J2DTextBox*)(*(J2DPane**)(p + 4))->search(0x546e6f3031ULL))->setFont(font);
    font = *(JUTFont**)((u8*)lbl_8053AD78 + 0x154);
    ((J2DTextBox*)(*(J2DPane**)(p + 4))->search(0x547965733031ULL))->setFont(font);
    fn_803832BC(((J2DTextBox*)(*(J2DPane**)(p + 4))->search(0x547965733031ULL))->getStringPtr(), 0x10c, 0, 0, 0);
    fn_803832BC(((J2DTextBox*)(*(J2DPane**)(p + 4))->search(0x546e6f3031ULL))->getStringPtr(), 0x10d, 0, 0, 0);

    n = (u8*)__nw__FUl(0x2c);
    if (n != 0) {
        *(void**)n = lbl_804AF86C;
    }
    *(void**)(p + 0x24) = n;
    fn_80402F04(*(void**)(p + 0x24), (*(J2DPane**)(p + 4))->search(0x50796573623034ULL));

    n = (u8*)__nw__FUl(0x2c);
    if (n != 0) {
        *(void**)n = lbl_804AF86C;
    }
    *(void**)(p + 0x28) = n;
    fn_80402F04(*(void**)(p + 0x28), (*(J2DPane**)(p + 4))->search(0x506e6f623034ULL));

    n = (u8*)__nw__FUl(0x2c);
    if (n != 0) {
        *(void**)n = lbl_804AF86C;
    }
    *(void**)(p + 0x2c) = n;
    fn_80402F04(*(void**)(p + 0x2c), (*(J2DPane**)(p + 4))->search(0x5061636375723032ULL));

    n = (u8*)__nw__FUl(0x2c);
    if (n != 0) {
        *(void**)n = lbl_804AF86C;
    }
    *(void**)(p + 0x30) = n;
    fn_80402F04(*(void**)(p + 0x30), (*(J2DPane**)(p + 4))->search(0x5074746c626b3035ULL));

    n = (u8*)__nw__FUl(0x2c);
    if (n != 0) {
        *(void**)n = lbl_804AF86C;
    }
    *(void**)(p + 0x34) = n;
    fn_80402F04(*(void**)(p + 0x34), (*(J2DPane**)(p + 4))->search(0x4e646174613033ULL));

    n = (u8*)__nw__FUl(0x2c);
    if (n != 0) {
        *(void**)n = lbl_804AF86C;
    }
    *(void**)(p + 0x38) = n;
    fn_80402F04(*(void**)(p + 0x38), (*(J2DPane**)(p + 4))->search(0x50626c6b3033ULL));

    n = (u8*)__nw__FUl(0x2c);
    if (n != 0) {
        *(void**)n = lbl_804AF86C;
    }
    *(void**)(p + 0x3c) = n;
    fn_80402F04(*(void**)(p + 0x3c), (*(J2DPane**)(p + 4))->search(0x50626c6b3032ULL));

    n = (u8*)__nw__FUl(0x2c);
    if (n != 0) {
        *(void**)n = lbl_804AF86C;
    }
    *(void**)(p + 0x40) = n;
    fn_80402F04(*(void**)(p + 0x40), (*(J2DPane**)(p + 4))->search(0x50626c6b3031ULL));

    ((u8*)(*(J2DPane**)(p + 4))->search(0x4e646174613035ULL))[0xb0] = 0;

    n = (u8*)__nw__FUl(0x2c);
    if (n != 0) {
        *(void**)n = lbl_804AF86C;
    }
    *(void**)(p + 0x44) = n;
    fn_80402F04(*(void**)(p + 0x44), (*(J2DPane**)(p + 8))->search(0x524f4f54ULL));

    *(void**)(p + 0x48) = *(void**)((u8*)lbl_8053AED8 + 8);

    OSInitFastCast();

    *(void**)(p + 0xc) = fn_80403144(0x5343524e, (void*)(base + 0x4fc));
    *(void**)(p + 0x10) = load__20J2DAnmLoaderDataBaseFPCv(*(void**)(p + 0xc));
    (*(J2DPane**)(p + 8))->search(0x50306b616b3030ULL)->setAnimation(*(J2DAnmTransform**)(p + 0x10));
    *(void**)(p + 0x14) = fn_80403144(0x5343524e, (void*)(base + 0x50c));
    *(void**)(p + 0x18) = load__20J2DAnmLoaderDataBaseFPCv(*(void**)(p + 0x14));
    (*(J2DScreen**)(p + 8))->setAnimation(*(J2DAnmTevRegKey**)(p + 0x18));

    *(u32*)(p + 0x4c) = 0;
    *(u32*)(p + 0x50) = 0;
    *(u32*)(p + 0x54) = 0;
    *(f32*)(p + 0x58) = lbl_80543534;
    *(f32*)(p + 0x5c) = lbl_80543534;
    *(u32*)(p + 0x60) = 0;
    *(u32*)(p + 0x64) = 0;
    *(s16*)(p + 0x74) = 0;
    *(s16*)(p + 0x68) = -1;
    *(s16*)(p + 0x6a) = -1;
    *(s16*)(p + 0x6c) = 0;
    *(s16*)(p + 0x6e) = 0;
    *(s16*)(p + 0x70) = 0;
    *(s16*)(p + 0x72) = 0;
    p[0x76] = 2;
    p[0x77] = 0;
    p[0x78] = 0;
    p[0x79] = 0;
    p[0x7a] = 0;

    p[0x7b] = ((u8*)(*(J2DPane**)(p + 4))->search(*(const u64*)base))[0xb2];
    p[0x7c] = ((u8*)(*(J2DPane**)(p + 4))->search(*(const u64*)(base + 0x200)))[0xb2];
    p[0x7d] = ((u8*)(*(J2DPane**)(p + 8))->search(0x50737461726c69ULL))[0xb2];
    p[0x7e] = 0;
    p[0x7f] = 0;
    p[0x80] = 0;
    p[0x81] = 0;
    return p;
}


