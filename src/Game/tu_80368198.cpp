

#include "types.h"
#include "JSystem/JGeometry/Vec.h"

struct Sub8036C69C {
    virtual void v0(int);
    virtual void v1();
    virtual void v2(int);
};
struct Sub8036C0EC {
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24(int);
};
struct Unk8036C300;
struct Vec3f {
    f32 x;
    f32 y;
    f32 z;
};
typedef void (Unk8036C300::*Unk8036C300Func)();
extern Unk8036C300Func lbl_804AE070[];
extern char lbl_804AE088[];
extern char lbl_8049CC34[];
extern "C" void __dt__13Base_8010E074Fv(void* this_, int how);
extern "C" void fn_8036A65C(void* this_);
extern "C" void fn_801F0E34(void* self, u32 msg, s32 flag);
extern "C" void fn_8010DF58(void* this_);
extern "C" void fn_803683AC(void* this_);
extern "C" void fn_8036A894(void* this_);
extern "C" void fn_8036AC58(void* this_, void* param);
extern "C" void fn_80368660(void* this_);
extern void* lbl_80474C48[];

extern "C" u8 fn_8036B018(u8* this_) {
    s32 v = *(s32*)(this_ + 0x240);
    if (v == 0x11 || v == 0x26) {
        return 1;
    }
    return 0;
}

extern "C" void fn_8036C0EC(Sub8036C0EC* this_) {
    extern void* fn_8011921C(void);
    char* self = (char*)this_;
    s32 id;
    s32 v = *(s32*)((char*)fn_8011921C() + 8);
    if (*(u8*)(self + 0x270) != 1) {
        if (*(s32*)(self + 0x23c) == 4) {
            if (v == 0) {
                id = 2;
            } else if (v == 0x96) {
                id = 3;
            } else if (v == 0x1fe) {
                id = 4;
            } else if (v == 0x32a) {
                id = 5;
            } else if (v == 0x3f2) {
                id = 0xe;
            } else if (v == 0x51e) {
                id = 0xf;
            } else if (v == 0x5b4) {
                id = 0x10;
            } else if (v == 0x6e0) {
                id = 0x11;
            } else {
                return;
            }
        } else {
            if (v == 0) {
                id = 0x15;
            } else if (v == 0x96) {
                id = 0x16;
            } else if (v == 0x1fe) {
                id = 0x17;
            } else if (v == 0x32a) {
                id = 0x18;
            } else if (v == 0x3f2) {
                id = 0x1a;
            } else if (v == 0x51e) {
                id = 0x1b;
            } else if (v == 0x5b4) {
                id = 0x1c;
            } else if (v == 0x6e0) {
                id = 0x26;
            } else {
                return;
            }
        }
        this_->v24(id);
    }
}

extern "C" void fn_8036C250(char* self) {
    JGeometry::TVec3<f32> saved = *(JGeometry::TVec3<f32>*)(self + 0xc);
    if (*(s32*)(self + 0x23c) == 5 && *(s32*)(self + 0x240) >= 0x24 && *(s32*)(self + 0x240) != 0x26) {
        fn_803683AC(self);
    } else {
        fn_8010DF58(self);
        fn_8036A894(self);
        if (*(u8*)(self + 0x236) != 0) {
            fn_8036AC58(self, lbl_80474C48[*(s32*)(self + 0x23c)]);
        }
        fn_80368660(self);
    }
    *(JGeometry::TVec3<f32>*)(self + 0xc) = saved;
}

extern "C" void fn_8036C300(Unk8036C300* this_) {
    char* self = (char*)this_;
    if (*(s32*)(self + 0x2f0) != 0) {
        *(s32*)(self + 0x2f0) = *(s32*)(self + 0x2f0) - 1;
        if (*(s32*)(self + 0x2f0) == 0xe1) {
            fn_801F0E34(self, 0x30082, 0);
        } else if (*(s32*)(self + 0x2f0) == 0xb4) {
            fn_801F0E34(self, 0x30082, 0);
            fn_801F0E34(self, 0x30083, 0);
        }
    }
    (this_->*lbl_804AE070[*(s32*)(self + 0x23c) - 4])();
}

extern "C" void* fn_8036C69C(void* this_, short how) {
    if (this_) {
        *(void**)this_ = (void*)lbl_804AE088;
        Sub8036C69C* sub = *(Sub8036C69C**)((char*)this_ + 0x314);
        if (sub && (void*)sub != 0) {
            sub->v0(1);
        }
        *(void**)((char*)this_ + 0x314) = 0;
        fn_8036A65C(this_);
        if ((s32)this_ + 0x318 != 0) {
            if ((s32)this_ + 0x33c != 0) {
                *(void**)((char*)this_ + 0x33c) = (void*)lbl_8049CC34;
            }
        }
        __dt__13Base_8010E074Fv(this_, 0);
        if (how > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" s32 fn_8036C8F4(void* this_) {
    return *(s32*)((char*)this_ + 0x240);
}

void fn_8036C8FC(void)
{
  extern void __ct__17JASGenericMemPoolFv(void);
  extern void __register_global_object(void*, void*, void*);
  extern char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;

  if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
    __ct__17JASGenericMemPoolFv();
    __register_global_object(0, 0, 0);
  }
}
