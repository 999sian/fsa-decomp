#include "types.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "Game/Actor.h"
extern "C" char* fn_802D6A9C();
extern "C" bool fn_802D800C(char*,s32);


extern "C" void __dt__5ActorFv(void* this_, s32 flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AC760[];
extern "C" void* fn_803481B8(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AC760;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_80348218(void) {}

extern "C" u8 fn_802DEBA0();
extern "C" void fn_801F0E34(void*,s32,s32);
extern "C" void fn_801F0D20(void*,s32);
extern "C" void fn_802D8050(char*,s32,u8,u8);
extern "C" u8* fn_801902C0();
extern "C" void fn_8034821C(u8* p) {
 switch (*(s32*)(p+0x230)) {
 case 0:
  if ((u8)((Actor*)p)->v11()==1) {
   *(s32*)(p+0x240)=0;
   *(s32*)(p+0x230)=1;
   switch (*(s32*)(p+0x234)) {
   case 0: if (!fn_802DEBA0()) fn_801F0E34(p,0x30043,0); break;
   case 1: if (!fn_802DEBA0()) fn_801F0E34(p,0x30044,0); break;
   }
  }
  break;
 case 1:
  switch (*(s32*)(p+0x234)) {
  case 0:
   if (*(s32*)(p+0x240)>=120) {
    if (!fn_802D800C(fn_802D6A9C(),*(s32*)(p+0x238))) fn_802D8050(fn_802D6A9C(),*(s32*)(p+0x238),1,255);
    *(s32*)(p+0x240)=120;
   }
   if (*(s32*)(p+0x240)<120) {
    ++*(s32*)(p+0x240);
    if (*(s32*)(p+0x240)==120 && !fn_802DEBA0()) fn_801F0D20(p,3);
   }
   break;
  case 1:
   if (*(s32*)(p+0x240)>=30) {
    if (!fn_802D800C(fn_802D6A9C(),*(s32*)(p+0x238))) fn_802D8050(fn_802D6A9C(),*(s32*)(p+0x238),1,255);
    *(s32*)(p+0x240)=30;
   }
   if (*(s32*)(p+0x240)<30) {
    ++*(s32*)(p+0x240);
    if (*(s32*)(p+0x240)==30 && !fn_802DEBA0()) fn_801F0D20(p,3);
   }
   break;
  case 2:
   if ((u8)((Actor*)p)->v11()==1) {
    if (*(s32*)(p+0x240)<120) {
     if (*(s32*)(p+0x244)!=1) {
      fn_801F0E34(p,0x30045,0);
      *(s32*)(p+0x244)=1;
     }
     ++*(s32*)(p+0x240);
     if (*(s32*)(p+0x240)>=60 && p[0x248]==0) {
      fn_801F0D20(p,3);
      p[0x248]=1;
     }
     if (*(s32*)(p+0x240)>=120) {
      *(s32*)(p+0x240)=120;
      *(s32*)(p+0x244)=0;
     }
    }
   } else {
    if (*(s32*)(p+0x240)>0) {
     if (*(s32*)(p+0x244)!=-1) {
      fn_801F0E34(p,0x30046,0);
      *(s32*)(p+0x244)=-1;
     }
     *(s32*)(p+0x240)-=4;
     if (*(s32*)(p+0x240)<=0) {
      *(s32*)(p+0x230)=0;
      *(s32*)(p+0x240)=0;
      *(s32*)(p+0x244)=0;
     }
    }
   }
   break;
  }
  break;
 }
 switch (*(s32*)(p+0x234)) {
 case 0: {
  f32 ratio=(f32)*(s32*)(p+0x240)/120.0f;
  u8* obj=fn_801902C0();
  if (*(u32*)(obj+0x2ec)!=0 && obj[0x2fc]==0) {
   obj[0x2fc]=1;
   *(f32*)(obj+0x2e0)=*(f32*)(p+0xc);
   *(f32*)(obj+0x2e4)=*(f32*)(p+0x10);
   *(f32*)(obj+0x2e8)=*(f32*)(p+0x14);
   *(f32*)(obj+0x2f4)=ratio;
  }
  break;
 }
 case 1: {
  if (!fn_802D800C(fn_802D6A9C(),*(s32*)(p+0x23c))) {
   f32 ratio=(f32)*(s32*)(p+0x240)/30.0f;
   u8* obj=fn_801902C0();
   if (*(u32*)(obj+0x30c)!=0 && obj[0x31c]==0) {
    obj[0x31c]=1;
    *(f32*)(obj+0x300)=*(f32*)(p+0xc);
    *(f32*)(obj+0x304)=*(f32*)(p+0x10);
    *(f32*)(obj+0x308)=*(f32*)(p+0x14);
    *(f32*)(obj+0x314)=ratio;
   }
  }
  break;
 }
 case 2: {
  f32 ratio=(f32)*(s32*)(p+0x240)/120.0f;
  u8* obj=fn_801902C0();
  if (*(u32*)(obj+0x32c)!=0 && obj[0x33c]==0) {
   obj[0x33c]=1;
   *(f32*)(obj+0x320)=*(f32*)(p+0xc);
   *(f32*)(obj+0x324)=*(f32*)(p+0x10);
   *(f32*)(obj+0x328)=*(f32*)(p+0x14);
   *(f32*)(obj+0x334)=ratio;
  }
  break;
 }
 }
}

extern "C" char* fn_802D6A9C();
extern "C" bool fn_802D800C(char* p, s32 bit);
extern "C" void fn_80348698(s32* this_) {
    this_[0x8D] = this_[0x24] & 0xF;
    this_[0x8E] = (u32)this_[0x24] >> 22 & 0x1F;
    this_[0x8F] = (u32)this_[0x24] >> 17 & 0x1F;
    this_[0x91] = 0;
    *(u8*)(this_ + 0x92) = 0;
    this_[0x90] = 0;
    char* rooms = fn_802D6A9C();
    if (fn_802D800C(rooms, this_[0x8E]) == 1) {
        switch (this_[0x8D]) {
        case 0:
            this_[0x90] = 0x78;
            break;
        case 1:
            this_[0x90] = 0x1E;
            break;
        case 2:
            this_[0x90] = 0x78;
            break;
        }
        this_[0x8C] = 1;
    } else {
        this_[0x90] = 0;
        this_[0x8C] = 0;
    }
    reinterpret_cast<Actor*>(this_)->v03();
}

