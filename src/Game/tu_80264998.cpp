

#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/Inline.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"


extern "C" int fn_802486A0(void*);
extern "C" int fn_80248778(void*);
extern "C" int fn_80240888(void*);
extern "C" unsigned char fn_8025F448(char* p);
extern "C" int fn_8023DE58(int idx);
extern "C" u16 fn_8022461C(void*, s32);
extern "C" s32 fn_8013CC50(s32 id, void* pos, s32 type, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
extern "C" void fn_8013CB44(void* obj, void* p, s32 a, s32 b, s32 c);
extern const f32 lbl_805401F0;
extern const f32 lbl_805401F4;
extern const f32 lbl_80540200;

static f32 fnDist(char* p, Vec* dst) {
    JGeometry::TVec3<f32> pos = *(JGeometry::TVec3<f32>*)(p + 8);
    JMathInlineVEC::PSVECSubtract(&pos, (Vec*)(p + 0x14), &pos);
    *(JGeometry::TVec3<f32>*)dst = *(JGeometry::TVec3<f32>*)&pos;
    return PSVECMag(dst);
}

extern "C" u8 fn_8023FC5C(u8* p);
extern "C" void* GetPtrField_0x4(void* p);
#include "Game/ItemBase.h"
struct PlayerSpriteRes64998 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* get(u32,const char*);
};
extern "C" char* lbl_8053AAF8;
extern "C" u8* lbl_8053AB10;
extern char lbl_8046B960[];
extern "C" void fn_802F86CC(void*,void*,void*,s32,f32,f32,DrawRec*);
static inline void playerSprite64998(s32 room,void* pos,const char* name,s32 index,DrawRec* rec) {
    if(room<8) {
        void* res=(*(PlayerSpriteRes64998**)(lbl_8053AAF8+0xa4))->get('SOB ',name);
        fn_802F86CC(*(void**)(lbl_8053AB10+0x20),pos,res,index,lbl_805401F4,lbl_805401F4,rec);
    }
}
extern "C" void fn_80264998(char* p)
{
    u8 r28;
    u8* r29;
    if (p[0xcac] == 0) {
        return;
    }
    if (p[0xcee] == 1) {
        return;
    }
    r28 = fn_8023FC5C((u8*)p);
    r29 = (u8*)GetPtrField_0x4(p);
    if (*(u16*)(p + 0x3c4) >= 0x3d5) {
        *(u16*)(p + 0x3c4) = 0x3d4;
    }
}

extern "C" void fn_80265AE4(char* p)
{
    Vec d1;
    Vec d2;
    if (*(unsigned short*)(p + 0x3c4) != *(unsigned short*)(p + 0x3c6) ||
        fnDist(p, &d1) > lbl_80540200) {
        *(int*)(p + 0x3d0) = *(int*)(p + 0x3d0) + 1;
        if (*(int*)(p + 0x3d0) >= 0x10) {
            *(int*)(p + 0x3d0) = 0;
        }
        *(int*)(p + 0x3cc) = 8;
        goto machine;
    }
    if (*(int*)(p + 0x3cc) > 0) {
        *(int*)(p + 0x3cc) = *(int*)(p + 0x3cc) - 1;
    } else {
        *(int*)(p + 0x3d0) = 0;
    }
machine:
    {
        int t = *(int*)(p + 0x3d0);
        if (t < 4) {
            *(short*)(p + 0x3c8) = 0x195;
        } else if (t < 8) {
            *(short*)(p + 0x3c8) = 0x196;
        } else if (t < 0xc) {
            *(short*)(p + 0x3c8) = 0x197;
        } else {
            *(short*)(p + 0x3c8) = 0x196;
        }
    }
    *(int*)(p + 0x3d4) = *(int*)(p + 0x3d4) + 1;
    if (*(int*)(p + 0x3d4) >= 0xc) {
        *(int*)(p + 0x3d4) = 0;
    }
    {
        int t = *(int*)(p + 0x3d4);
        if (t < 3) {
            *(short*)(p + 0x3ca) = 0x18f;
        } else if (t < 6) {
            *(short*)(p + 0x3ca) = 0x190;
        } else if (t < 9) {
            *(short*)(p + 0x3ca) = 0x191;
        } else {
            *(short*)(p + 0x3ca) = 0x190;
        }
    }
    if (*(f32*)(p + 0x10) <= lbl_805401F0 &&
        fn_8022461C(p + 8, *(int*)(p + 0x3b4)) == 0x39) {
        if (*(unsigned short*)(p + 0x3c4) != *(unsigned short*)(p + 0x3c6) ||
            fnDist(p, &d2) > lbl_80540200) {
            goto show;
        }
        goto hide;
    }
    goto hide;
show:
    if (*(unsigned int*)(p + 0x1384) == 0) {
        *(int*)(p + 0x1384) = fn_8013CC50(*(int*)(p + 0x3b4), p + 8, 0x4d2, 0, 0, 0, 0, 1,
                                          lbl_805401F4);
    } else {
        unsigned int em = *(unsigned int*)(p + 0x1384);
        fn_8013CB44((void*)em, p + 8, 0, 0, 1);
    }
    goto end;
hide:
    {
        unsigned int e = *(unsigned int*)(p + 0x1384);
        if (e != 0) {
            *(u32*)(e + 0xf4) |= 1;
            *(int*)(e + 0x24) = 1;
            *(int*)(p + 0x1384) = 0;
        }
    }
end:;
}

extern "C" void fn_80265D68(char* p)
{
    unsigned char v = *(unsigned char*)(p + 0xca0);
    if (v >= 8) {
        *(unsigned char*)(p + 0xca0) = v - 8;
        return;
    }
    *(unsigned char*)(p + 0xca0) = 0;
}

extern "C" void fn_80265D8C(char* p)
{
    unsigned char v = *(unsigned char*)(p + 0xca0);
    if (v <= 0xf7) {
        *(unsigned char*)(p + 0xca0) = v + 8;
        return;
    }
    *(unsigned char*)(p + 0xca0) = 0xff;
}

extern "C" void fn_80265DB0(char* p)
{
 unsigned short v=*(unsigned short*)(p+0x3c4);
 if(v==0x122 || (v>=0xb7 && v<0xbd) || *(int*)(p+0x3b4)>8) {
  *(unsigned char*)(p+0xca1)=0;return;
 }
 if(*(int*)(p+0x3b4)==8) {
  *(unsigned char*)(p+0xca1)=0xff;return;
 }
 if(fn_8025F448(p)!=0) {
  int n=*(int*)(p+0xd70);
  if(n<0 || fn_8023DE58(n)!=8) {
   if(*(unsigned char*)(p+0xca1)>=8) {
    *(unsigned char*)(p+0xca1)-=8;return;
   }
   *(unsigned char*)(p+0xca1)=0;return;
  }
 }
 if(*(unsigned char*)(p+0xca1)<=0xf7) {
  *(unsigned char*)(p+0xca1)+=8;return;
 }
 *(unsigned char*)(p+0xca1)=0xff;
}

extern "C" u8 Player_GetField_0x454(char* p);
extern "C" u8 fn_80241230(char* p);
extern "C" void fn_80268194(char* p);
extern "C" void fn_80265E88(char* p)
{
    *(unsigned short*)(p + 0x3c6) = *(unsigned short*)(p + 0x3c4);
    if (p[0xcfe] == 0) {
        if (p[0x456] == 1) {
            *(unsigned short*)(p + 0x3c4) = *(unsigned short*)(p + 0x450);
            p[0xca0] = p[0xca2];
            p[0x456] = 0;
            return;
        }
        if (Player_GetField_0x454(p) == 0) {
            if (fn_80241230(p) == 0 && *(int*)(p + 0x488) == 0 && (*(u32*)(p + 0x464) & 2) == 2) {
                *(unsigned short*)(p + 0x3c4) = 0x121;
                return;
            }
        } else {
            *(unsigned short*)(p + 0x3c4) = *(unsigned short*)(p + 0x450);
            p[0xca0] = p[0xca2];
            return;
        }
    } else {
        if (*(float*)(p + 0x10) <= lbl_805401F0) {
            *(unsigned short*)(p + 0x3c4) = 0xc3;
        } else {
            *(unsigned short*)(p + 0x3c4) = 0xc2;
        }
        return;
    }
    fn_80268194(p);
}

extern "C" void fn_80267018(char* p)
{
    int t;
    if (*(int*)(p + 0x3b4) < 8) {
        t = *(int*)(p + 0x3dc);
        if (t == 0) {
            *(short*)(p + 0x3c4) = 0x375;
        } else if (t == 1) {
            *(short*)(p + 0x3c4) = 0x37d;
        } else if (t == 2) {
            *(short*)(p + 0x3c4) = 0x385;
        } else {
            *(short*)(p + 0x3c4) = 0x38d;
        }
    } else {
        t = *(int*)(p + 0x3dc);
        if (t == 0) {
            *(short*)(p + 0x3c4) = 0x395;
        } else if (t == 1) {
            *(short*)(p + 0x3c4) = 0x39d;
        } else if (t == 2) {
            *(short*)(p + 0x3c4) = 0x3a5;
        } else {
            *(short*)(p + 0x3c4) = 0x3ad;
        }
    }
    *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
}

extern "C" void fn_802670CC(char* p)
{
    if (fn_802486A0(p) == 4) {
        int a = fn_80248778(p);
        int b = fn_80240888(p);
        if (b != a) {
            int t = *(int*)(p + 0x3dc);
            if (t == 0) {
                *(short*)(p + 0x3c4) = 0x1bf;
            } else if (t == 1) {
                *(short*)(p + 0x3c4) = 0x1c1;
            } else if (t == 2) {
                *(short*)(p + 0x3c4) = 0x1c3;
            } else {
                *(short*)(p + 0x3c4) = 0x1c3;
            }
            return;
        }
    }
    int t = *(int*)(p + 0x3dc);
    if (t == 0) {
        *(short*)(p + 0x3c4) = 0x20c;
    } else if (t == 1) {
        *(short*)(p + 0x3c4) = 0x214;
    } else if (t == 2) {
        *(short*)(p + 0x3c4) = 0x21c;
    } else {
        *(short*)(p + 0x3c4) = 0x224;
    }
    *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
}

extern "C" void fn_802671C8(char* p)
{
    int t;
    int r;
    int s;
    if (fn_802486A0(p) == 4) {
        r = fn_80248778(p);
        t = fn_80240888(p);
        if (t != r) {
            t = *(int*)(p + 0x3dc);
            if (t == 0) {
                *(unsigned short*)(p + 0x3c4) = 0x1bf;
            } else if (t == 1) {
                *(unsigned short*)(p + 0x3c4) = 0x1c1;
            } else if (t == 2) {
                *(unsigned short*)(p + 0x3c4) = 0x1c3;
            } else {
                *(unsigned short*)(p + 0x3c4) = 0x1c3;
            }
            return;
        }
    }
    s = *(unsigned char*)(p + 0x3fb);
    switch (s) {
    case 0:
        t = *(int*)(p + 0x3dc);
        if (t == 0) {
            *(unsigned short*)(p + 0x3c4) = 0x1e8;
        } else if (t == 1) {
            *(unsigned short*)(p + 0x3c4) = 0x1ec;
        } else if (t == 2) {
            *(unsigned short*)(p + 0x3c4) = 0x1f0;
        } else {
            *(unsigned short*)(p + 0x3c4) = 0x1f4;
        }
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
        break;
    case 1:
        *(unsigned short*)(p + 0x3c4) = 0x1f8;
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
        break;
    case 2:
        t = *(int*)(p + 0x3dc);
        if (t == 0) {
            *(unsigned short*)(p + 0x3c4) = 0x1fc;
        } else if (t == 1) {
            *(unsigned short*)(p + 0x3c4) = 0x200;
        } else if (t == 2) {
            *(unsigned short*)(p + 0x3c4) = 0x204;
        } else {
            *(unsigned short*)(p + 0x3c4) = 0x208;
        }
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
        break;
    case 3:
        *(unsigned short*)(p + 0x3c4) = 0x358;
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
        break;
    }
}

extern "C" void fn_80267384(char* p)
{
    if (fn_802486A0(p) == 4) {
        int a = fn_80248778(p);
        int b = fn_80240888(p);
        if (b != a) {
            int t = *(int*)(p + 0x3dc);
            if (t == 0) {
                *(short*)(p + 0x3c4) = 0x1bf;
            } else if (t == 1) {
                *(short*)(p + 0x3c4) = 0x1c1;
            } else if (t == 2) {
                *(short*)(p + 0x3c4) = 0x1c3;
            } else {
                *(short*)(p + 0x3c4) = 0x1c3;
            }
            return;
        }
    }
    int t = *(int*)(p + 0x3dc);
    if (t == 0) {
        *(short*)(p + 0x3c4) = 0x3c;
    } else if (t == 1) {
        *(short*)(p + 0x3c4) = 0x3d;
    } else if (t == 2) {
        *(short*)(p + 0x3c4) = 0x3e;
    } else {
        *(short*)(p + 0x3c4) = 0x3f;
    }
}

extern "C" char* lbl_8053AAF8;
extern "C" unsigned char Player_IsLinked(char* p);
extern "C" void fn_80267470(char* p)
{
    if ((((unsigned char)lbl_8053AAF8[0x82]) & (unsigned char)(1 << *(int*)(p + 4))) == 0 && Player_IsLinked(p) == 0) {
        *(short*)(p + 0x3c4) = 0x31d;
    } else {
        if (fn_802486A0(p) == 4) {
            int a = fn_80248778(p);
            int b = fn_80240888(p);
            if (b != a) {
                int t = *(int*)(p + 0x3dc);
                if (t == 0) {
                    *(short*)(p + 0x3c4) = 0x1bf;
                } else if (t == 1) {
                    *(short*)(p + 0x3c4) = 0x1c1;
                } else if (t == 2) {
                    *(short*)(p + 0x3c4) = 0x1c3;
                } else {
                    *(short*)(p + 0x3c4) = 0x1c3;
                }
                return;
            }
        }
        int t = *(int*)(p + 0x3dc);
        if (t == 0) {
            *(short*)(p + 0x3c4) = 0x3c;
        } else if (t == 1) {
            *(short*)(p + 0x3c4) = 0x3d;
        } else if (t == 2) {
            *(short*)(p + 0x3c4) = 0x3e;
        } else {
            *(short*)(p + 0x3c4) = 0x3f;
        }
    }
}

extern "C" void fn_80267598(char* p)
{
    if (fn_802486A0(p) == 4) {
        int a = fn_80248778(p);
        int b = fn_80240888(p);
        if (b != a) {
            int t = *(int*)(p + 0x3dc);
            if (t == 0) {
                *(short*)(p + 0x3c4) = 0x1bf;
            } else if (t == 1) {
                *(short*)(p + 0x3c4) = 0x1c1;
            } else if (t == 2) {
                *(short*)(p + 0x3c4) = 0x1c3;
            } else {
                *(short*)(p + 0x3c4) = 0x1c3;
            }
            return;
        }
    }
    int t = *(int*)(p + 0x3dc);
    if (t == 0) {
        *(short*)(p + 0x3c4) = 0x3c;
    } else if (t == 1) {
        *(short*)(p + 0x3c4) = 0x3d;
    } else if (t == 2) {
        *(short*)(p + 0x3c4) = 0x3e;
    } else {
        *(short*)(p + 0x3c4) = 0x3f;
    }
}

extern "C" void fn_80267684(char* p)
{
    int t;
    if (*(unsigned char*)(p + 0x458) == 1) {
        t = *(int*)(p + 0x3dc);
        if (t == 0) {
            *(short*)(p + 0x3c4) = 0x262;
        } else if (t == 1) {
            *(short*)(p + 0x3c4) = 0x268;
        } else if (t == 2) {
            *(short*)(p + 0x3c4) = 0x26e;
        } else {
            *(short*)(p + 0x3c4) = 0x274;
        }
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fb);
        return;
    }
    t = *(int*)(p + 0x3dc);
    if (t == 0) {
        *(short*)(p + 0x3c4) = 0xf1;
    } else if (t == 1) {
        *(short*)(p + 0x3c4) = 0xf9;
    } else if (t == 2) {
        *(short*)(p + 0x3c4) = 0x101;
    } else {
        *(short*)(p + 0x3c4) = 0x109;
    }
    *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fb);
}

extern "C" void fn_80267748(char* p)
{
    int t;
    if (*(unsigned char*)(p + 0xb84) != 0 && *(unsigned char*)(p + 0x3fb) >= 5) {
        t = *(int*)(p + 0x3dc);
        if (t == 0) {
            *(short*)(p + 0x3c4) = 0x1d2;
        } else if (t == 1) {
            *(short*)(p + 0x3c4) = 0x1d6;
        } else if (t == 2) {
            *(short*)(p + 0x3c4) = 0x1da;
        } else {
            *(short*)(p + 0x3c4) = 0x1e1;
        }
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
        return;
    }
    t = *(int*)(p + 0x3dc);
    if (t == 0) {
        *(short*)(p + 0x3c4) = 0x18b;
    } else if (t == 1) {
        *(short*)(p + 0x3c4) = 0x191;
    } else if (t == 2) {
        *(short*)(p + 0x3c4) = 0x197;
    } else {
        *(short*)(p + 0x3c4) = 0x19d;
    }
    *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fb);
}

extern "C" void fn_80267818(char* p)
{
    int t;
    if (*(unsigned char*)(p + 0xb9b) == 1) {
        t = *(int*)(p + 0x3dc);
        if (t == 0) {
            *(short*)(p + 0x3c4) = 0x16b;
        } else if (t == 1) {
            *(short*)(p + 0x3c4) = 0x173;
        } else if (t == 2) {
            *(short*)(p + 0x3c4) = 0x17b;
        } else {
            *(short*)(p + 0x3c4) = 0x183;
        }
    } else {
        t = *(int*)(p + 0x3dc);
        if (t == 0) {
            *(short*)(p + 0x3c4) = 0x123;
        } else if (t == 1) {
            *(short*)(p + 0x3c4) = 0x12a;
        } else if (t == 2) {
            *(short*)(p + 0x3c4) = 0x131;
        } else {
            *(short*)(p + 0x3c4) = 0x138;
        }
    }
    *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fb);
}

extern "C" void fn_802678CC(char* p)
{
    int t;
    if (*(unsigned char*)(p + 0x3fb) == 1) {
        t = *(int*)(p + 0x3dc);
        if (t == 0) {
            *(short*)(p + 0x3c4) = 0x2f6;
        } else if (t == 1) {
            *(short*)(p + 0x3c4) = 0x2f9;
        } else if (t == 2) {
            *(short*)(p + 0x3c4) = 0x2fc;
        } else {
            *(short*)(p + 0x3c4) = 0x2ff;
        }
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
        return;
    }
    t = *(int*)(p + 0x3dc);
    if (t == 0) {
        *(short*)(p + 0x3c4) = 0x2e6;
    } else if (t == 1) {
        *(short*)(p + 0x3c4) = 0x2ea;
    } else if (t == 2) {
        *(short*)(p + 0x3c4) = 0x2ee;
    } else {
        *(short*)(p + 0x3c4) = 0x2f2;
    }
    *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fb);
}

extern "C" void fn_80267990(char* p)
{
    int t;
    if (*(unsigned char*)(p + 0x3fb) == 1) {
        t = *(int*)(p + 0x3dc);
        if (t == 0) {
            *(short*)(p + 0x3c4) = 0x14f;
        } else if (t == 1) {
            *(short*)(p + 0x3c4) = 0x152;
        } else if (t == 2) {
            *(short*)(p + 0x3c4) = 0x155;
        } else {
            *(short*)(p + 0x3c4) = 0x158;
        }
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
        return;
    }
    t = *(int*)(p + 0x3dc);
    if (t == 0) {
        *(short*)(p + 0x3c4) = 0x13f;
    } else if (t == 1) {
        *(short*)(p + 0x3c4) = 0x143;
    } else if (t == 2) {
        *(short*)(p + 0x3c4) = 0x147;
    } else {
        *(short*)(p + 0x3c4) = 0x14b;
    }
    *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fb);
}

extern "C" void fn_80267A54(char* p)
{
    int t;
    if (*(unsigned char*)(p + 0x3fb) == 0) {
        t = *(int*)(p + 0x3dc);
        if (t == 0) {
            *(short*)(p + 0x3c4) = 0;
        } else if (t == 1) {
            *(short*)(p + 0x3c4) = 8;
        } else if (t == 2) {
            *(short*)(p + 0x3c4) = 0x10;
        } else {
            *(short*)(p + 0x3c4) = 0x18;
        }
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
        return;
    }
    t = *(int*)(p + 0x3dc);
    if (t == 0) {
        *(short*)(p + 0x3c4) = 0xc5;
    } else if (t == 1) {
        *(short*)(p + 0x3c4) = 0xc9;
    } else if (t == 2) {
        *(short*)(p + 0x3c4) = 0xcd;
    } else {
        *(short*)(p + 0x3c4) = 0xd4;
    }
    *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
}

extern "C" void fn_80267B18(char* p)
{
    int t;
    if (*(int*)(p + 0xcf4) == 0xd) {
        *(short*)(p + 0x3c4) = 0x121;
        return;
    }
    if (*(unsigned char*)(p + 0x3fb) == 0) {
        *(short*)(p + 0x3c4) = *(unsigned char*)(p + 0x3fd) + 0xb7;
        return;
    }
    t = *(int*)(p + 0x3dc);
    if (t == 0) {
        *(short*)(p + 0x3c4) = 0xa7;
    } else if (t == 1) {
        *(short*)(p + 0x3c4) = 0xab;
    } else if (t == 2) {
        *(short*)(p + 0x3c4) = 0xaf;
    } else {
        *(short*)(p + 0x3c4) = 0xb3;
    }
    *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fd);
}

extern "C" void fn_80267BA8(char* p)
{
    int t;
    if (*(unsigned char*)(p + 0x3fb) == 1) {
        t = *(int*)(p + 0x3dc);
        if (t == 0) {
            *(short*)(p + 0x3c4) = 0x322;
        } else if (t == 1) {
            *(short*)(p + 0x3c4) = 0x327;
        } else if (t == 2) {
            *(short*)(p + 0x3c4) = 0x32c;
        } else {
            *(short*)(p + 0x3c4) = 0x331;
        }
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fd);
        return;
    }
    t = *(int*)(p + 0x3dc);
    if (t == 0) {
        *(short*)(p + 0x3c4) = 0x36d;
    } else if (t == 1) {
        *(short*)(p + 0x3c4) = 0x36f;
    } else if (t == 2) {
        *(short*)(p + 0x3c4) = 0x371;
    } else {
        *(short*)(p + 0x3c4) = 0x373;
    }
    *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
}

extern "C" void fn_80267C6C(char* p)
{
    int t;
    if (*(unsigned char*)(p + 0x3fd) == 1) {
        t = *(int*)(p + 0x3dc);
        if (t == 0) {
            *(short*)(p + 0x3c4) = 0x33a;
        } else if (t == 1) {
            *(short*)(p + 0x3c4) = 0x33d;
        } else if (t == 2) {
            *(short*)(p + 0x3c4) = 0x340;
        } else {
            *(short*)(p + 0x3c4) = 0x343;
        }
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fb);
        return;
    }
    t = *(int*)(p + 0x3dc);
    if (t == 0) {
        *(short*)(p + 0x3c4) = 0x346;
    } else if (t == 1) {
        *(short*)(p + 0x3c4) = 0x34a;
    } else if (t == 2) {
        *(short*)(p + 0x3c4) = 0x34e;
    } else {
        *(short*)(p + 0x3c4) = 0x352;
    }
    *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fb);
}

extern "C" void fn_80267D30(char* p)
{
    unsigned char b;
    int t = *(int*)(p + 0x3dc);
    if (t == 0) {
        b = *(unsigned char*)(p + 0x3fb);
        if (b < 8) {
            *(unsigned short*)(p + 0x3c4) = (unsigned char)((b & 7) + 0x8f);
        } else {
            *(unsigned short*)(p + 0x3c4) = (unsigned char)(b + 0x8f);
        }
    } else if (t == 1) {
        b = *(unsigned char*)(p + 0x3fb);
        if (b < 8) {
            *(unsigned short*)(p + 0x3c4) = (unsigned char)(((b + 4) & 7) + 0x8f);
        } else {
            *(unsigned short*)(p + 0x3c4) = (unsigned char)(b + 0x93);
        }
    } else if (t == 2) {
        b = *(unsigned char*)(p + 0x3fb);
        if (b < 8) {
            *(unsigned short*)(p + 0x3c4) = (unsigned char)(((b + 2) & 7) + 0x8f);
        } else {
            *(unsigned short*)(p + 0x3c4) = (unsigned char)(b + 0x97);
        }
    } else {
        b = *(unsigned char*)(p + 0x3fb);
        if (b < 8) {
            *(unsigned short*)(p + 0x3c4) = (unsigned char)(((b + 6) & 7) + 0x8f);
        } else {
            *(unsigned short*)(p + 0x3c4) = (unsigned char)(b + 0x9b);
        }
    }
}

extern "C" void fn_80267E18(char* p)
{
    int t;
    if (*(unsigned char*)(p + 0x403) >= 0xa8) {
        t = *(int*)(p + 0x3dc);
        if (t == 0) {
            *(short*)(p + 0x3c4) = 0x6f;
        } else if (t == 1) {
            *(short*)(p + 0x3c4) = 0x77;
        } else if (t == 2) {
            *(short*)(p + 0x3c4) = 0x7f;
        } else {
            *(short*)(p + 0x3c4) = 0x87;
        }
    } else {
        t = *(int*)(p + 0x3dc);
        if (t == 0) {
            *(short*)(p + 0x3c4) = 0x43;
        } else if (t == 1) {
            *(short*)(p + 0x3c4) = 0x4b;
        } else if (t == 2) {
            *(short*)(p + 0x3c4) = 0x53;
        } else {
            *(short*)(p + 0x3c4) = 0x61;
        }
    }
    *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
}

extern "C" void fn_80267ECC(char* p)
{
    int t;
    if (*(unsigned char*)(p + 0x3fb) >= 8) {
        if (fn_802486A0(p) == 4) {
            int a = fn_80248778(p);
            int b = fn_80240888(p);
            if (b != a) {
                t = *(int*)(p + 0x3dc);
                if (t == 0) {
                    *(short*)(p + 0x3c4) = 0x1bf;
                } else if (t == 1) {
                    *(short*)(p + 0x3c4) = 0x1c1;
                } else if (t == 2) {
                    *(short*)(p + 0x3c4) = 0x1c3;
                } else {
                    *(short*)(p + 0x3c4) = 0x1c3;
                }
                return;
            }
        }
        t = *(int*)(p + 0x3dc);
        if (t == 0) {
            *(short*)(p + 0x3c4) = 0x3c;
        } else if (t == 1) {
            *(short*)(p + 0x3c4) = 0x3d;
        } else if (t == 2) {
            *(short*)(p + 0x3c4) = 0x3e;
        } else {
            *(short*)(p + 0x3c4) = 0x3f;
        }
    } else {
        switch (*(int*)(p + 0x45c)) {
        case 0:
            t = *(int*)(p + 0x3dc);
            if (t == 0) {
                *(short*)(p + 0x3c4) = 0x20;
            } else if (t == 1) {
                *(short*)(p + 0x3c4) = 0x27;
            } else if (t == 2) {
                *(short*)(p + 0x3c4) = 0x2e;
            } else {
                *(short*)(p + 0x3c4) = 0x35;
            }
            break;
        case 1:
            t = *(int*)(p + 0x3dc);
            if (t == 0) {
                *(short*)(p + 0x3c4) = 0x232;
            } else if (t == 1) {
                *(short*)(p + 0x3c4) = 0x23a;
            } else if (t == 2) {
                *(short*)(p + 0x3c4) = 0x242;
            } else {
                *(short*)(p + 0x3c4) = 0x24a;
            }
            break;
        case 2:
            t = *(int*)(p + 0x3dc);
            if (t == 0) {
                *(short*)(p + 0x3c4) = 0x252;
            } else if (t == 1) {
                *(short*)(p + 0x3c4) = 0x256;
            } else if (t == 2) {
                *(short*)(p + 0x3c4) = 0x25a;
            } else {
                *(short*)(p + 0x3c4) = 0x25e;
            }
            break;
        case 3:
            t = *(int*)(p + 0x3dc);
            if (t == 0) {
                *(short*)(p + 0x3c4) = 0x27a;
            } else if (t == 1) {
                *(short*)(p + 0x3c4) = 0x27e;
            } else if (t == 2) {
                *(short*)(p + 0x3c4) = 0x282;
            } else {
                *(short*)(p + 0x3c4) = 0x286;
            }
            break;
        case 4:
            t = *(int*)(p + 0x3dc);
            if (t == 0) {
                *(short*)(p + 0x3c4) = 0x262;
            } else if (t == 1) {
                *(short*)(p + 0x3c4) = 0x268;
            } else if (t == 2) {
                *(short*)(p + 0x3c4) = 0x26e;
            } else {
                *(short*)(p + 0x3c4) = 0x274;
            }
            *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fb);
            return;
        }
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fb);
    }
}

extern "C" void fn_80268194(char* p)
{
    if (fn_802486A0(p) == 4) {
        int a = fn_80248778(p);
        int b = fn_80240888(p);
        if (b != a) {
            int t = *(int*)(p + 0x3dc);
            if (t == 0) {
                *(short*)(p + 0x3c4) = 0x1bf;
            } else if (t == 1) {
                *(short*)(p + 0x3c4) = 0x1c1;
            } else if (t == 2) {
                *(short*)(p + 0x3c4) = 0x1c3;
            } else {
                *(short*)(p + 0x3c4) = 0x1c3;
            }
            return;
        }
    }
    int t = *(int*)(p + 0x3dc);
    if (t == 0) {
        *(short*)(p + 0x3c4) = 0x3c;
    } else if (t == 1) {
        *(short*)(p + 0x3c4) = 0x3d;
    } else if (t == 2) {
        *(short*)(p + 0x3c4) = 0x3e;
    } else {
        *(short*)(p + 0x3c4) = 0x3f;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
