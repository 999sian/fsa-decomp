#include "types.h"
#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry/Vec.h"
#include "sdk/stl/float.h"
#include "JSystem/JKernel/JKRArchive.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"

#pragma auto_inline off
static inline u32 RoomResourceTag802D(const char* name) {
    s32 a = name[0] - 0x20;
    s32 b = name[1] - 0x20;
    s32 c = name[2];
    u32 key = 0x4d202020;
    key += (a << 16) + (b << 8) + c;
    return key - 0x20;
}


#if defined(VERSION_G4SP01)
extern "C" int fn_801365A8(void);
extern "C" int fn_80045948(void);
#endif

struct RoomMaskEntry {
    u64 flags;
    u8 pad08[0x318];
};

struct RoomArrays {
    u8 pad00[0x60];
    u8 roomNumbers[10][10];
    u8 padC4[0x2C];
    f32 pairsF0[16][2];
    u8 pad170[8];
    u32 flags178[10][10];
    u8 counters308[32];
    u8 values328[32];
    u32 flags348[8][4];
    u64 masks3C8[4][10][10];
    union {
        u64 flags1048[10][10][8];
        u64 roomFlags1048[10][80];
    };
    u16 values2948[8][64];
    u32 flags2D48[4][128];
    u32 flags3548[10][10][32];
    s32 counts6748[8];
    u32 flags6768[10][10][32];
    u8 values9968[10][10][256];
    u32 flagsFD68[10][10][32];
    u32 flags12F68[32];
    u32 flags12FE8[32];
    u32 keys13068[8];
    JGeometry::TVec2<f32> positions13088[8];
    u32 owners130C8[8];
    JGeometry::TVec2<f32> positions130E8[8];
    s32 owners13128[8];
    JGeometry::TVec2<f32> positions13148[8];
    s32 owners13188[8];
    s32 owners131A8[4];
    u16 flags131B8[16];
    u8 values131D8[4];
    u8 pad131DC[0x70];
    f32 values1324C[4];
    f32 values1325C[4];
    f32 values1326C[4];
    u8 values1327C[4];
};

static inline bool roomPositionEquals(JGeometry::TVec2<f32>& a, JGeometry::TVec2<f32>& b) {
    bool same = false;
    bool equal = false;
    f32 eps = 32.0f * FLT_EPSILON;
    f32 dx = a.x - b.x;
    if (-eps <= dx && dx <= eps) equal = true;
    if (equal) {
        equal = false;
        f32 dy = a.y - b.y;
        if (-eps <= dy && dy <= eps) equal = true;
        if (equal) same = true;
    }
    return same;
}

extern char* lbl_8053AAF8;
inline RoomArrays* roomArrays() {
    return *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
}
inline u32* roomValueFlag(int i) {
    return &roomArrays()->flags12F68[i];
}
static inline void clearRoomFlag12F68(const unsigned int i) {
    roomArrays()->flags12F68[i] = 0;
}

inline u16* roomValueColumn(int i) {
    return &roomArrays()->values2948[0][i];
}
extern char* lbl_8053AB10;
extern u8 lbl_8050EC80[];
extern u8 lbl_80529DEC[];
extern const u32 lbl_8046E1CC[];
extern const char* lbl_804A9530[][4];
extern const char* lbl_804A9660[];
extern const char* lbl_804A96D0[];
extern void* lbl_804A9950[];
extern const char lbl_8046E7E8[];
extern const char lbl_8046E804[];
extern const char lbl_8054106C[1];
extern const char lbl_805410DC[2];
extern const char lbl_80541128[1];
extern const f32 lbl_8054111C;
extern const f32 lbl_80541124;
extern const f32 lbl_80541160;
extern const f32 lbl_80541164;
extern const f32 lbl_80541158;
extern const f32 lbl_8054115C;
extern void* lbl_8053AF80;
extern f32 lbl_8053A1A8;

extern "C" {
int sprintf(char*, const char*, ...);
void __dl__FPv(void*);
void* fn_8013C824();
void fn_8013C8CC(void*);
void* fn_801F856C();
void fn_801F7CAC(void*);
void fn_801F7E88(void*);
void fn_801F6204(void*, u8);
void fn_80231424();
void fn_80308D0C();
void fn_8030C85C(void*);
void fn_8030C928(void*, const f32*);
void fn_802D8328(char*, u8, u8);
void fn_802D8D50(char*, u8);
void fn_8030C9E4(void*, void*);
void fn_802D3A18(char*);
u8 fn_8023F264(s32);
s32 fn_8023DE58(s32);
void fn_8023CCE8(s32, s32);
void fn_8023CC5C(s32, s32);
void fn_80458880(void*, s32, s32);
void fn_8038D454();
void fn_8022BD70();
void fn_8037AE30(void*);
void fn_8023F1D4(int, void*, int, int, u8);
void* fn_8023E724(s32);
void fn_801F7B18();
void* fn_8023E724(s32);
s32 fn_8023CBC0(s32);
s32 fn_8023BCD4(s32);
void* fn_8023E604(s32);
s32 fn_80230498(s32, const void*, s32, s32, s32, s32, s32);
  u8 fn_802DCE5C(char*, s32);
  void fn_802DEE2C(void);
  void fn_8023F78C(void);
  void fn_8023F728(void);
      void fn_8043D834(void*);
    u32 fn_802F9908(void*, s32, s32);
    u32 fn_802DED40(s32, s32);
  }

struct FsaActorList {
    u8 pad0[8];
    u8* actors[0x400];
    s32 count;
    s32 getCount() const { return count; }
    u8* getActor(s32 index) const { return actors[index]; }
};
static inline u8 getRoomTransitionFlag() {
    char* manager = *(char**)(lbl_8053AB10 + 0x24);
    return *(u8*)(manager + 0x1e8);
}
static inline FsaActorList* getActorList() {
    return (FsaActorList*)fn_801F856C();
}

extern "C" void fn_802D39B8(char* p, s32 index, s32 value) {
    ((s32*)(p + 0x131A8))[index] = value;
}

extern "C" bool fn_802D39CC(char* p) {
    if (*(s32*)(p + 0x18) == *(s32*)(p + 0x10)
        && *(s32*)(p + 0x14) == *(s32*)(p + 0x0C))
        return true;
    return false;
}

extern "C" u8 fn_802D39FC(char* p) {
    RoomArrays* r = (RoomArrays*)p;
    s32 row = *(s32*)(p + 0x18);
    return r->roomNumbers[row][*(s32*)(p + 0x14)];
}

extern "C" u8 fn_8037F1E4(s32);
extern "C" void fn_8043D67C(void*, s32, s32, s32);
extern "C" void fn_8043EDE8(void*, s32);
extern "C" s32 Actor_CreateByID(void*, u32, u32, f32*, u32, s32, s32);
extern void* lbl_8053AED0;
#pragma opt_propagation off
extern "C" void fn_802D3A18(char* p) {
    u8 flag = *(u8*)(lbl_8053AAF8 + 0x94);
    if (*(u8*)(lbl_8053AAF8 + 0x96) != 0) {
        flag = 1;
    }
    if (*(u8*)(lbl_8053AAF8 + 0x7e) == 0 && fn_8037F1E4(0)) {
        flag = 1;
    }
    if (*(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0xc) + 0x131f0) == 1) {
        if (*(s32*)(p + 0xc4) != 0 && flag == 0) {
            *(s32*)(p + 0xc4) -= 1;
            s32 t = *(s32*)(p + 0xc4);
            if (t == 0x708) {
                if (*(u8*)(lbl_8053AAF8 + 0x7f) != 0) {
                    fn_8043D67C(lbl_8053AED0, 0x146, 0, 0);
                } else {
                    fn_8043D67C(lbl_8053AED0, 0x195, 0, 0);
                }
                fn_80458880(lbl_8053AF80, 0x30, -1);
            } else if (t == 0x294) {
                if (*(u8*)(lbl_8053AAF8 + 0x7f) != 0) {
                    fn_8043D67C(lbl_8053AED0, 0x147, 0, 0);
                } else {
                    fn_8043D67C(lbl_8053AED0, 0x196, 0, 0);
                }
                fn_80458880(lbl_8053AF80, 0x30, -1);
            } else if (t == 0x12c) {
                fn_8043EDE8(lbl_8053AED0, t / 60);
                fn_80458880(lbl_8053AF80, 0x31, -1);
            } else if (t == 0xf0) {
                fn_8043EDE8(lbl_8053AED0, t / 60);
                fn_80458880(lbl_8053AF80, 0x32, -1);
            } else if (t == 0xb4) {
                fn_8043EDE8(lbl_8053AED0, t / 60);
                fn_80458880(lbl_8053AF80, 0x33, -1);
            } else if (t == 0x78) {
                fn_8043EDE8(lbl_8053AED0, t / 60);
                fn_80458880(lbl_8053AF80, 0x34, -1);
            } else if (t == 0x3c) {
                fn_8043EDE8(lbl_8053AED0, t / 60);
                fn_80458880(lbl_8053AF80, 0x35, -1);
            } else if (t == 0) {
                f32 pos[3];
                f32 coordinate;
                f64 zero = lbl_8054111C;
                coordinate = -*(f32*)(*(char**)(lbl_8053AB10 + 0x24) + 0x10);
                pos[0] = coordinate;
                coordinate = -*(f32*)(*(char**)(lbl_8053AB10 + 0x24) + 0x20);
                pos[1] = coordinate;
                pos[2] = zero;
                pos[2] = zero;
                if (*(u8*)(lbl_8053AAF8 + 0x7f) != 0) {
                    Actor_CreateByID(fn_801F856C(), 0x5455544d, 0, pos, 0, -1, -1);
                    *(s32*)(p + 0xc4) = 36000;
                } else {
                    Actor_CreateByID(fn_801F856C(), 0x54554746, 0, pos, 0, -1, -1);
                }
            }
        }
    }
}
#pragma opt_propagation on
extern "C" u8* fn_80403328(const char*);
extern "C" void fn_80134DC0();
extern const char* lbl_804A9710[][4];
extern const char* lbl_804A9830[][4];
extern const char lbl_8046E7B8[];
extern const char lbl_8046E7C8[];
#pragma opt_propagation on
extern "C" void fn_802D3D48(char* p) {
    s32 index;
    s32 column;
    u8* text;
    *(s32*)(*(char**)(*(char**)(lbl_8053AAF8+4)+0xC)+0x1328C)=0;
    for (s32 i=0;i<10;i++)
        for (u32 j=0;j<10;j++)
            ((RoomArrays*)p)->roomNumbers[i][j]=255;
    index=0;
    column=0;
    if (*(u8*)(lbl_8053AAF8+0x7F)==1) {
        if (*(u8*)(lbl_8053AAF8+0x7E)==1)
            text=fn_80403328(lbl_804A9710[*(s32*)(p+4)][*(s32*)(p+8)]);
        else
            text=fn_80403328(lbl_804A9830[*(s32*)(p+4)][*(s32*)(p+8)]);
        u8* scan=text;
        for (;;) { if (*scan==0x2Cu) break; index++; scan++; }
        *(s32*)(p+0x14)=text[index+1]-'0';
        *(s32*)(p+0xC)=*(s32*)(p+0x14);
        *(s32*)(p+0x18)=text[index+3]-'0';
        *(s32*)(p+0x10)=*(s32*)(p+0x18);
        index+=5;
        *(s32*)(p+0x34)=text[index]-'0';
        if (text[index+1]!=0x2Cu && text[index+1]!=0xDu) {
            if (*(s32*)(p+0x34)==0) *(s32*)(p+0x34)=0;
            else if (*(s32*)(p+0x34)==1) *(s32*)(p+0x34)=10;
            else if (*(s32*)(p+0x34)==2) *(s32*)(p+0x34)=20;
            else *(s32*)(p+0x34)=30;
            *(s32*)(p+0x34)+=(u8)(text[index+1]-'0');
            ++index;
        }
        *(s32*)(p+0x38)=*(s32*)(p+0x34);
        *(s32*)(p+0x3C)=text[index+2]-'0';
        index+=4;
        *(s32*)(p+0x40)=text[index]-'0';
        if (text[index+1]!=0x2Cu && text[index+1]!=0xDu) {
            if (*(s32*)(p+0x40)==0) *(s32*)(p+0x40)=0;
            else if (*(s32*)(p+0x40)==1) *(s32*)(p+0x40)=10;
            else if (*(s32*)(p+0x40)==2) *(s32*)(p+0x40)=20;
            else *(s32*)(p+0x40)=30;
            *(s32*)(p+0x40)+=(u8)(text[index+1]-'0');
            ++index;
        }
        index+=2;
        *(s32*)(p+0x44)=text[index]-'0';
        if (text[index+1]!=0x2Cu && text[index+1]!=0xDu) {
            if (*(s32*)(p+0x44)==0) *(s32*)(p+0x44)=0;
            else if (*(s32*)(p+0x44)==1) *(s32*)(p+0x44)=10;
            else if (*(s32*)(p+0x44)==2) *(s32*)(p+0x44)=20;
            else *(s32*)(p+0x44)=30;
            *(s32*)(p+0x44)+=(u8)(text[index+1]-'0');
            ++index;
        }
        bool flag;
        if (*(u8*)(lbl_8053AAF8+0x7F)==0) flag=false;
        else {
            char* room=*(char**)(*(char**)(lbl_8053AAF8+4)+0xC);
            if (*(s32*)(room+4)==8 && *(s32*)(room+8)==3) flag=true;
            else flag=false;
        }
        if (!flag) *(s32*)(p+0x48)=0;
        else *(s32*)(p+0x48)=0;
        *(s32*)(p+0x4C)=1;
        index+=2;
        *(s32*)(p+0x50)=text[index]-'0';
        if (text[index+1]!=0x2Cu && text[index+1]!=0xDu) {
            if (*(s32*)(p+0x50)==0) *(s32*)(p+0x50)=0;
            else if (*(s32*)(p+0x50)==1) *(s32*)(p+0x50)=10;
            *(s32*)(p+0x50)+=(u8)(text[index+1]-'0');
            ++index;
        }
        *(s32*)(p+0x54)=text[index+2]-'0';
        if (*(s32*)(p+0x54)<2 || *(s32*)(p+0x54)>=8) *(s32*)(p+0x54)=5;
        index+=4;
        *(s32*)(p+0x58)=text[index]-'0';
        for (;;) {
            if (text[index]==0xDu && text[index+1]==0xAu) {index+=2;break;}
            index++;
        }
        RoomArrays* row=(RoomArrays*)p;
        for (;;) {
            u8* scan=text+index;
            u8 c=*scan;
            if (c=='e' && scan[1]=='n' && scan[2]=='d') break;
            if (c==0xDu && scan[1]==0xAu) {
                column=0; index+=2; row=(RoomArrays*)((char*)row+10);
            } else if (c==0x2Cu) {
                ++index;
            } else if (c=='N') {
                ++column;index+=4;
            } else {
                u8 next=scan[1];
                u8 value=c-'0';
                if (next!=0x2Cu && next!=0xDu) {
                    value = value <= 9 ? (u8)(value*10) : 0;
                    value += (u8)(next-'0');
                    ++index;
                }
                ++index;
                row->roomNumbers[0][column]=value;
                ++column;
            }
        }
    } else {
        fn_80134DC0();
        int count=0;
        for (int i=0;i<4;i++) {
            u32 flag=(*(u8*)(lbl_8053AAF8+0x82) & (u8)(1<<i))!=0;
            if (flag==1) count++;
        }
        int shift;
        int two;
        two=0;
        shift=0;
        for (int i=0;i<count;i++,shift+=2) {
            if (((*(u8*)(lbl_8053AAF8+0x83)>>shift)&3u)==2u) two++;
        }
        s32 line=*(s32*)(p+8)+*(s32*)(p+4)*4;
        if (two!=0) text=fn_80403328(lbl_8046E7B8);
        else text=fn_80403328(lbl_8046E7C8);
        *(s32*)(p+0x14)=1;
        *(s32*)(p+0x18)=1;
        s32 cursor=0;
        if (line!=0) {
            do {
                for (;;) {
                    if (text[cursor]==0xDu && text[cursor+1]==0xAu) {cursor+=2;column++;break;}
                    cursor++;
                }
            } while (line!=column);
        }
        u8 next;
        u8 value;
        value=text[cursor]-'0';
        next=text[cursor+1];
        if (next!=0x2Cu && next!=0xDu) {
            if (value==0) value=0;
            else if (value==1) value=10;
            else if (value==2) value=20;
            else value=30;
            value+=(u8)(next-'0');
            ++cursor;
        }
        ((u8*)p)[0x6B]=value;
        cursor+=2;
        *(s32*)(p+0x34)=text[cursor]-'0';
        if (text[cursor+1]!=0x2Cu && text[cursor+1]!=0xDu) {
            if (*(s32*)(p+0x34)==0) *(s32*)(p+0x34)=0;
            else if (*(s32*)(p+0x34)==1) *(s32*)(p+0x34)=10;
            else if (*(s32*)(p+0x34)==2) *(s32*)(p+0x34)=20;
            else *(s32*)(p+0x34)=30;
            *(s32*)(p+0x34)+=(u8)(text[cursor+1]-'0');
            ++cursor;
        }
        *(s32*)(p+0x38)=*(s32*)(p+0x34);
        *(s32*)(p+0x3C)=text[cursor+2]-'0';
        cursor+=4;
        *(s32*)(p+0x40)=text[cursor]-'0';
        if (text[cursor+1]!=0x2Cu && text[cursor+1]!=0xDu) {
            if (*(s32*)(p+0x40)==0) *(s32*)(p+0x40)=0;
            else if (*(s32*)(p+0x40)==1) *(s32*)(p+0x40)=10;
            else if (*(s32*)(p+0x40)==2) *(s32*)(p+0x40)=20;
            else *(s32*)(p+0x40)=30;
            *(s32*)(p+0x40)+=(u8)(text[cursor+1]-'0');
            ++cursor;
        }
        cursor+=2;
        *(s32*)(p+0x48)=text[cursor]-'0';
        if (text[cursor+1]!=0x2Cu && text[cursor+1]!=0xDu) {
            if (*(s32*)(p+0x48)==0) *(s32*)(p+0x48)=0;
            else if (*(s32*)(p+0x48)==1) *(s32*)(p+0x48)=10;
            *(s32*)(p+0x48)+=(u8)(text[cursor+1]-'0');
            ++cursor;
        }
        cursor+=2;
        *(s32*)(p+0x50)=text[cursor]-'0';
        if (text[cursor+1]!=0x2Cu && text[cursor+1]!=0xDu) {
            if (*(s32*)(p+0x50)==0) *(s32*)(p+0x50)=0;
            else if (*(s32*)(p+0x50)==1) *(s32*)(p+0x50)=10;
            *(s32*)(p+0x50)+=(u8)(text[cursor+1]-'0');
            ++cursor;
        }
        *(s32*)(p+0x4C)=text[cursor+2]-'0';
        if (*(s32*)(p+0x4C)!=1 && *(s32*)(p+0x4C)!=2) *(s32*)(p+0x4C)=1;
        *(s32*)(p+0x54)=text[cursor+4]-'0';
        if (*(s32*)(p+0x54)<2 || *(s32*)(p+0x54)>=8) *(s32*)(p+0x54)=5;
        *(s32*)(p+0x58)=text[cursor+6]-'0';
    }
}
#pragma opt_propagation reset
extern "C" bool fn_802D46D8(char*, int index, unsigned int bit, u8 set) {
    unsigned int word = bit / 32;
    if (!set) {
        RoomArrays* p = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        RoomArrays* row = (RoomArrays*)((char*)p + index * 0x200);
        return (lbl_8046E1CC[bit % 32] & row->flags2D48[0][word]) != 0;
    }
    RoomArrays* p = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    p->flags2D48[index][word] |= lbl_8046E1CC[bit % 32];
    return true;
}

extern "C" void fn_802D4768(u8* p, s32 x, u16 v, s32* out, u32* out2) {
    s32 base = (x < 8) ? 0 : x - 7;
    s32 idx = 0x3c;
    s32 i;
    for (i = 0; i < 15; i++) {
        if (roomArrays()->values2948[base][idx] == 0) {
            roomArrays()->values2948[base][idx] = v;
            break;
        }
        idx -= 4;
    }
    s32 n = 0xf - (idx >> 2);
    out[1] = n;
    out[0] = n >> 31;
    u32 a, b;
    if (x < 8) {
        u8* e = (u8*)roomArrays() + *(s32*)(p + 0x18) * 0x280 + *(s32*)(p + 0x14) * 0x40;
        a = *(u32*)(e + 0x1048);
        b = *(u32*)(e + 0x104c);
    } else {
        u8* e = (u8*)roomArrays() + *(s32*)(p + 0x18) * 0x280 + *(s32*)(p + 0x14) * 0x40 + (x << 3);
        a = *(u32*)(e + 0x1010);
        b = *(u32*)(e + 0x1014);
    }
    out2[1] = b;
    out2[0] = a;
}

extern "C" void fn_802D4874(u8* p, s32 x, u16 v, u32* out, u32* out2) {
    s32 base = (x < 8) ? 0 : x - 7;
    s32 idx;
    for (idx = 0; idx < 0x40; idx++) {
        u16* col = &roomArrays()->values2948[0][idx];
        if (col[base * 64] == 0) {
            roomArrays()->values2948[base][idx] = v;
            break;
        }
    }
    *(u64*)out = 1;
loop:
    if (idx != 0) {
        idx--;
        *(u64*)out <<= 1;
        goto loop;
    }
    u64 r;
    if (x < 8) {
        r = roomArrays()->flags1048[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][0];
    } else {
        r = roomArrays()->flags1048[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][x - 7];
    }
    *(u64*)out2 = r;
}

extern "C" bool fn_802D49A8(char* p, s32 x, u16 value) {
    s32 base = (x < 8) ? 0 : x - 7;
    s32 i;
    for (i = 0; i < 64; i++) {
        RoomArrays* rooms = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        if (rooms->values2948[base][i] == 0) {
            rooms->values2948[base][i] = value;
            break;
        }
    }
    u64 mask = 1;
    for (;;) {
        if (i == 0) {
            break;
        }
        mask <<= 1;
        i--;
    }
    u64 flags;
    if (x < 8) {
        RoomArrays* rooms = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        flags = rooms->flags1048[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][0];
    } else {
        RoomArrays* rooms = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        flags = rooms->flags1048[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][x - 7];
    }
    if ((mask & flags) != 0) {
        return true;
    }
    return false;
}

extern "C" bool fn_802D4ADC(char* p, s32 x, u16 v) {
    s32 base = x < 8 ? 0 : x - 7;
    s32 i;
    for (i = 0; i < 0x40; i++) {
        s32 off = base * 0x80;
        char* row = (char*)((*(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C))->values2948) + i * 2;
        if (v == *(u16*)(row + off)) {
            if (i >= 0x40) {
                return false;
            }
            u64 mask = 1;
            for (;;) {
                if (i == 0) {
                    break;
                }
                mask <<= 1;
                i--;
            }
            u64 word;
            if (x < 8) {
                word = (*(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C))->flags1048[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][0];
            } else {
                word = (*(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C))->flags1048[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][x - 7];
            }
            if ((mask & word) != 0) {
                return true;
            }
            return false;
        }
    }
    return false;
}

extern "C" s32 fn_802D4C10(char*, s32 index, u16 value) {
    index = index < 8 ? 0 : index - 7;
    for (int i = 0; i < 64; ++i) {
        if (((u16*)roomArrays() + i)[index * 64 + 0x14a4] == value) return i;
    }
    return -1;
}

extern "C" void fn_802D4CCC(char* p, s32 room) {
    char* arr = (char*)roomArrays();
    s32 n = 0, idx = 0, k;
    u32 lo, hi;
    if (room < 8) {
        lo = *(u32*)(arr + room * 0x280 + *(s32*)(arr + 0x14) * 0x40 + 0x1048);
        hi = *(u32*)(arr + room * 0x280 + *(s32*)(arr + 0x14) * 0x40 + 0x104C);
    } else {
        lo = *(u32*)(arr + room * 0x280 + *(s32*)(arr + 0x14) * 0x40 + (room - 7) * 8 + 0x1010);
        hi = *(u32*)(arr + room * 0x280 + *(s32*)(arr + 0x14) * 0x40 + (room - 7) * 8 + 0x1014);
    }
    *(u16*)(p + 0x131B8 + room * 2) = 0;
    *(u8*)(p + 0x131DF + room) = 0;
    for (k = 0; k < 0x800; k++) {
        u32 v = fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), room, k) & 0xffff;
        if (v == 0x17 || v == 0x16) {
            u32 r = fn_802DED40(room + 1, n);
            *(u16*)(arr + (0x3C - idx) * 2 + 0x2948) = (u16)k;
            n++; idx += 4;
        }
    }
}

extern "C" char* fn_802D6A9C() {
    return *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
}

extern "C" void fn_802D6AAC(char*, u8 value) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    *(u8*)(p + 0x131F9) = value;
}

extern "C" bool fn_802D6AC4(char* p, s32 bit) {
    u32 (*rows)[10][32] = (u32 (*)[10][32])(p + 0xFD68);
    return (rows[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][bit / 32] & (1 << (bit % 32))) != 0;
}

extern "C" void fn_802D6B24(char* p, s32 bit, u8 set) {
    s32 word = bit / 32;
    s32 shift = bit % 32;
    if (set) {
        char* q = (char*)((u32)(p + 0x10000) + *(s32*)(p + 0x18) * 0x500);
        q = (char*)(*(s32*)(p + 0x14) * 0x80 + (u32)q);
        q = (char*)((u32)(q - 0x298) + word * 4);
        *(u32*)q |= 1U << shift;
    } else {
        char* q = (char*)((u32)(p + 0x10000) + *(s32*)(p + 0x18) * 0x500);
        q = (char*)(*(s32*)(p + 0x14) * 0x80 + (u32)q);
        q = (char*)((u32)(q - 0x298) + word * 4);
        *(u32*)q &= (1U << shift) ^ 0xFFFFFFFF;
    }
}

extern "C" void fn_802D6BC8(char*, u8 value) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    *(u8*)(p + 0x131F4) = value;
}

extern "C" void fn_802D6BE0(char*, u8 value) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    *(u8*)(p + 0x131F3) = value;
}

extern "C" void fn_802D6BF8(char*, u8 value) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    *(u8*)(p + 0x131F2) = value;
}

extern f32 lbl_80541120;
extern "C" void fn_802D6C10(char* unused, f32* pos, u32 id) {
    for (s32 i = 0; i < 8; i++) {
        char* rooms = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        if (id == *(u32*)(rooms + i * 4 + 0x13188)) {
            f32* pair = (f32*)(rooms + i * 8 + 0x13148);
            bool bVar5 = false;
            f32 eps = lbl_80541120 * FLT_EPSILON;
            bool bVar4 = false;
            f32 dx = pair[0] - pos[0];
            if (-eps <= dx && dx <= eps) {
                bVar4 = true;
            }
            if (bVar4) {
                bVar4 = false;
                f32 dy = pair[1] - pos[1];
                if (-eps <= dy && dy <= eps) {
                    bVar4 = true;
                }
                if (bVar4) {
                    bVar5 = true;
                }
            }
            if (bVar5) {
                f32* dst = (f32*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + i * 8 + 0x130E8);
                dst[0] = lbl_8054111C;
                dst[1] = lbl_8054111C;
                *(s32*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + i * 4 + 0x13128) = -1;
                pair[0] = lbl_8054111C;
                pair[1] = lbl_8054111C;
                *(s32*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + i * 4 + 0x13188) = -1;
                return;
            }
        }
    }
}

extern "C" bool fn_802D6D70(void* unused, f32* a, f32* b, s32 owner, u32 key) {
    bool found = false;
    f32 eps = lbl_80541120 * FLT_EPSILON;
    s32 off4 = 0;
    s32 off8 = 0;
    s32 i;

    for (i = 0; i < 8; i++) {
        bool bVar4 = false;
        bool bVar5 = false;
        f32* pair = (f32*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + off8 + 0x13148);
        f32 dx = pair[0] - b[0];
        if (-eps <= dx && dx <= eps) {
            bVar4 = true;
        }
        if (bVar4) {
            bVar4 = false;
            f32 dy = pair[1] - b[1];
            if (-eps <= dy && dy <= eps) {
                bVar4 = true;
            }
            if (bVar4) {
                bVar5 = true;
            }
        }
        if (bVar5 && key == *(u32*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + off4 + 0x13188)) {
            found = true;
            break;
        }
        off4 += 4;
        off8 += 8;
    }
    if (!found) {
        off4 = 0;
        for (i = 0; i < 8; i++) {
            char* base = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
            if (*(s32*)(base + off4 + 0x13128) == -1) {
                f32* dst = (f32*)(base + i * 8 + 0x130E8);
                dst[0] = a[0];
                dst[1] = a[1];
                f32* pb = (f32*)(base + i * 8 + 0x13148);
                pb[0] = b[0];
                pb[1] = b[1];
                *(s32*)(base + off4 + 0x13128) = owner;
                *(s32*)(base + off4 + 0x13188) = key;
                break;
            }
            off4 += 4;
        }
    }
    return found;
}

#pragma opt_loop_invariants off
#pragma opt_common_subs on
extern "C" void fn_802D6F38(RoomArrays* p, u32 key, f32* pos, s32 owner, u8 mode) {
    s32 i = 0;
    if (mode == 1) {
        do {
            if (p->owners130C8[i] == (u32)-1) goto insert;
        ++i;
        } while(i < 8);
        {
        i = 7;
        for (s32 j = 0; j < 7; j++) {
            p->keys13068[j] = p->keys13068[j + 1];
            p->positions13088[j].x = p->positions13088[j+1].x;
            p->positions13088[j].y = p->positions13088[j+1].y;
            p->owners130C8[j] = p->owners130C8[j + 1];
        }
        }
insert:
        p->keys13068[i] = key;
        register f32 y;
 register f32 x;
 y=pos[1];
 x=pos[0];
 p->positions13088[i].x=x;
 p->positions13088[i].y=y;
        p->owners130C8[i] = owner;
        return;
    }

    RoomArrays* word = p;
    RoomArrays* pairBase = p;
    u32 maskedKey = key & 0xFFFFF07F;
    for (s32 idx = 0; idx < 8; idx++) {
        u32 k = word->keys13068[0] & 0xFFFFF07F;
        if (k == maskedKey) {
            bool bVar5 = roomPositionEquals(pairBase->positions13088[0], *(JGeometry::TVec2<f32>*)pos);
            if (bVar5 && word->owners130C8[0] == owner) {
                for (s32 j = idx; j < 7; j++) {
                    p->keys13068[j] = p->keys13068[j + 1];
                    p->positions13088[j].x = p->positions13088[j+1].x;
                    p->positions13088[j].y = p->positions13088[j+1].y;
                    p->owners130C8[j] = p->owners130C8[j + 1];
                }
                p->keys13068[7] = 0;
                p->positions13088[7].x = lbl_8054111C;
                p->positions13088[7].y = lbl_8054111C;
                p->owners130C8[7] = -1;
                return;
            }
        }
        word = (RoomArrays*)((u8*)word+4);
        pairBase = (RoomArrays*)((u8*)pairBase+8);
    }
}
#pragma opt_common_subs reset
#pragma opt_loop_invariants reset
extern "C" bool fn_802D72BC(char*, s32 bit) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    return (((u32*)(p + 0x12FE8))[bit / 32] & (1U << (bit % 32))) != 0;
}

extern "C" void fn_802D7310(char* p, s32 bit, u8 set) {
    s32 word = bit / 32;
    s32 shift = bit % 32;
    if (set)
        ((u32*)(p + 0x12FE8))[word] |= 1U << shift;
    else
        ((u32*)(p + 0x12FE8))[word] &= (1U << shift) ^ 0xFFFFFFFF;
}

extern "C" bool fn_802D7384(char* p, s32 bit) {
    int word = bit / 32;
    int shift = bit % 32;
    u32 flags = ((u32*)(p + 0x12F68))[word];
    return (flags & (1 << shift)) != 0;
}

extern "C" void fn_802D73CC(char* p, s32 bit, u8 set) {
    s32 word = bit / 32;
    s32 shift = bit % 32;
    if (set)
        ((u32*)(p + 0x12F68))[word] |= 1U << shift;
    else
        ((u32*)(p + 0x12F68))[word] &= (1U << shift) ^ 0xFFFFFFFF;
}

extern "C" void fn_802D7440(char*, u8 value) {
    if (value == 1) {
        u8 mode = *(u8*)(lbl_8053AAF8 + 0x7F);
        u8 enabled;
        if (mode != 0)
            enabled = lbl_8050EC80[*(s32*)(lbl_8050EC80 + 0x10) * 0xC8 + 0x7C];
        else
            enabled = lbl_8050EC80[*(s32*)(lbl_8050EC80 + 0x10) * 0xC8 + 0x7D];
        if (enabled != 1) {
            char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
            *(u8*)(p + 0x131F0) = 0;
        } else if (mode != 0) {
            if (*(u8*)(lbl_8053AAF8 + 0x7E) == 1) {
                char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
                *(u8*)(p + 0x131F0) = 1;
            } else {
                char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
                *(u8*)(p + 0x131F0) = 0;
            }
        } else {
            char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
            *(u8*)(p + 0x131F0) = 1;
        }
    } else {
        char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        *(u8*)(p + 0x131F0) = 0;
    }
}

extern "C" void fn_802D752C(char*, u8 value) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    *(u8*)(p + 0x131EF) = value;
}

extern "C" u8 fn_802D7544(char* p, s32 index) {
    if (index >= 0 && index < 256) {
        char* base = p + 0x10000;
        char* colp = base + *(s32*)(p + 0x18) * 0xa00;
        colp = *(s32*)(p + 0x14) * 0x100 + colp;
        colp += index;
        return *(u8*)(colp - 0x6698);
    }
    return 0;
}

extern "C" void fn_802D7584(char* p, s32 index, u8 value) {
    if (index >= 0 && index < 256) {
        char* base = p + 0x10000;
        char* rowp = base + *(const u32*)(p + 0x18) * 0xa00;
        u8* cell = (u8*)rowp;
        cell = cell + *(const u32*)(p + 0x14) * 0x100;
        cell = cell + (u32)index;
        cell[-0x6698] = value;
    }
}

extern "C" bool fn_802D75BC(char* p, s32 bit) {
    u32 (*flags)[10][32] = (u32 (*)[10][32])(p + 0x6768);
    u32* w = &flags[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][bit / 32];
    if (*w & (1 << (bit % 32))) {
        return true;
    }
    return false;
}

extern "C" void fn_802D7618(char* p, s32 bit) {
    u32 (*flags)[10][32] = (u32 (*)[10][32])(p + 0x6768);
    flags[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][bit / 32] |= 1 << (bit % 32);
}

extern "C" void fn_802D766C(char* p, u8 value, s32 index) {
    if (value != 0) {
        index = index < 8 ? 0 : index - 7;
        ++((s32*)(p + 0x6748))[index];
    }
}

extern "C" bool fn_802D76A8(char* p, s32 bit) {
    u32 (*flags)[10][32] = (u32 (*)[10][32])(p + 0x3548);
    u32* w = &flags[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][bit / 32];
    if (*w & (1 << (bit % 32))) {
        return true;
    }
    return false;
}

extern "C" void fn_802D7704(char* p, s32 bit, u8 value, s32 index) {
    char* q = p + *(s32*)(p + 0x18) * 0x500;
    q = (char*)(*(s32*)(p + 0x14) * 0x80 + (u32)q);
    q = (char*)((u32)(q + 0x3548) + (bit / 32) * 4);
    *(u32*)q |= 1U << (bit % 32);
    if (value != 0) {
        index = index < 8 ? 0 : index - 7;
        ++((s32*)(p + 0x6748))[index];
    }
}

extern "C" void fn_802D7790(char*, s32 index, u32 mask) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    ((u16*)(p + 0x131B8))[index] &= mask ^ 0xFF;
}

extern "C" void fn_802D77BC(char*, s32 index, u32 mask) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    ((u16*)(p + 0x131B8))[index] |= mask;
}

extern "C" void fn_802D77E4(char*, s32 index, u16 value) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    ((u16*)(p + 0x131B8))[index] = value;
}

#pragma scheduling off
extern "C" bool fn_802D7804(RoomArrays* p, s32 index, u16 mask) {
    u32 value = p->flags131B8[index];
    return (value & mask) != 0;
}
#pragma scheduling reset
extern "C" void fn_802D782C(char*, u8 value) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    *(u8*)(p + 0x131DE) = value;
}

extern "C" void fn_802D7844(char*, u8 value, s32 index) {
    if (index >= 0 && index < 4) {
        u8* p = (u8*)*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        p[0x131D8 + index] = value;
    }
}

extern "C" void fn_802D7870(char*, u16 value) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    *(u16*)(p + 0x131DC) = value;
}

extern "C" bool fn_802D7888(char*, s32 bit) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    return ((1U << bit) & *(u32*)(p + 0x174)) != 0;
}

extern "C" void fn_802D78B4(char*, s32 bit, u8 set) {
    if (set) {
        char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        *(u32*)(p + 0x174) |= 1U << bit;
    } else {
        char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        *(u32*)(p + 0x174) &= (1U << bit) ^ 0xFFFFFFFF;
    }
}

extern "C" void fn_802D790C(char*, u8 value) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    *(u8*)(p + 0x171) = value;
}

extern "C" void fn_802D7920(char*, u8 value) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    *(u8*)(p + 0x170) = value;
}

extern "C" void fn_802D7934(char*, s32 value) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    *(s32*)(p + 0x5C) = value;
}

extern "C" s32 fn_802D7948(char*) {
    s32 value;
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    value = *(s32*)(p + 0x5C);
    if (value == 0)
        return *(s32*)(p + 0x58);
    return value - 1;
}

extern "C" void fn_802D7970(char*, s32 value) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    *(s32*)(p + 0x34) = value;
    if (value < 17) {
        p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        *(s32*)(p + 0x1328C) = 0;
    }
}

extern "C" void fn_802D79A4(char* p, s32 index, f32 a, f32 b, f32 c) {
    RoomArrays* rooms = (RoomArrays*)p;
    if (rooms->values1327C[index] == 0 && lbl_8054111C == rooms->values1324C[index]) {
        rooms->values1324C[index] = a;
        rooms->values1325C[index] = b;
        rooms->values1326C[index] = c;
        rooms->values1327C[index] = 1;
    }
}

extern "C" void fn_802D79E8(char* p, s32 index, u8 value, f32 a, f32 b) {
    RoomArrays* rooms = (RoomArrays*)p;
    if (rooms->pairsF0[index][0] < b)
        rooms->pairsF0[index][0] = b;
    if (rooms->pairsF0[index][1] < a)
        rooms->pairsF0[index][1] = a;
    if (value == 0) {
        b = lbl_80541124 * b;
        a = lbl_80541124 * a;
        for (s32 i = 0; i < 16; ++i) {
            f32* entry = (f32*)(p + 0xF0 + i * 8);
            if (entry[0] < b)
                entry[0] = b;
            if (entry[1] < a)
                entry[1] = a;
        }
    }
}

extern "C" u64 fn_802D7AC4(char* p, s32 index) {
    if (index < 8) {
        RoomArrays* rooms = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        return rooms->flags1048[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][0];
    }
    RoomArrays* rooms = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    return rooms->flags1048[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][index - 7];
}

#pragma opt_propagation off
extern "C" u32 fn_802D7B34(char* p, s32 index, s32 digit) {
    s32 shift;
    s32 idx;
    idx = index < 8 ? 0 : index - 7;
    shift = 60 - digit * 4;
    u64 mask = (u64)15 << shift;
    RoomArrays* rooms = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    u64 value = rooms->flags1048[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][idx];
    return (mask & value) >> shift;
}
#pragma opt_propagation reset
extern "C" void fn_802D7BE8(char* p, s32 index, s32 bit, u32 value) {
    index = index < 8 ? 0 : index - 7;
    RoomArrays* rooms = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    rooms->flags1048[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][index] &= ~((u64)0xf << (0x3c - bit * 4));
    RoomArrays* rooms2 = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    rooms2->flags1048[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][index] |= (u64)value << (0x3c - bit * 4);
}

extern "C" void fn_802D7D00(char* p, s32 index, s32 bit, u8 set) {
    index = index < 8 ? 0 : index - 7;
    if (set) {
        u64 mask = (u64)1 << bit;
        RoomArrays* rooms = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        rooms->flags1048[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][index] |= mask;
    } else {
        u64 mask = (u64)1 << bit;
        RoomArrays* rooms = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        rooms->flags1048[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][index] &= mask ^ (u64)-1;
    }
}

extern "C" u8 fn_802D7E04(char*, s32 index) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    return (p + index)[0x308];
}

extern "C" u8 fn_802D7E1C(char*, s32 index) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    return (p + index)[0x328];
}

extern "C" void fn_802D7E34(char*, s32 index) {
    RoomArrays* p = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    if (p->counters308[index] < 255)
        ++p->counters308[index];
}

extern "C" u8 fn_802D7E5C(char*, u8 index, s32 bit) {
    return (roomArrays()->masks3C8[index][0][0] & (s64)(s32)(1U << bit)) != 0;
}

extern "C" void fn_802D7EB0(char*, u8 index, s32 bit, u8 set) {
    if (set) {
        char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        RoomMaskEntry* e = (RoomMaskEntry*)(p + 0x3C8);
        e[index].flags |= 1 << bit;
    } else {
        char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        RoomMaskEntry* e = (RoomMaskEntry*)(p + 0x3C8);
        e[index].flags &= (1U << bit) ^ 0xFFFFFFFF;
    }
}

extern "C" bool fn_802D7F40(char* p, s32 bit) {
    RoomArrays* rooms = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    return ((1U << bit) & rooms->flags348[*(u32*)(p + 4)][*(s32*)(p + 8)]) != 0;
}

extern "C" void fn_802D7F84(char* p, s32 bit, u8 set) {
    if (set) {
        char* base = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        u32(*grid)[4] = (u32(*)[4])(base + 0x348);
        grid[*(s32*)(p + 4)][*(s32*)(p + 8)] |= 1U << bit;
    } else {
        char* base = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        u32(*grid)[4] = (u32(*)[4])(base + 0x348);
        grid[*(s32*)(p + 4)][*(s32*)(p + 8)] &= (1U << bit) ^ 0xFFFFFFFF;
    }
}

extern "C" bool fn_802D800C(char* p, s32 bit) {
    RoomArrays* rooms = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    return ((1U << bit) & rooms->flags178[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)]) != 0;
}

extern "C" void fn_802D8050(char* p, s32 bit, u8 set, u8 value) {
    if (set) {
        RoomArrays* base = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        base->flags178[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)] |= 1U << bit;
        base = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        if (base->counters308[bit] < 255)
            ++base->counters308[bit];
        base = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        base->values328[bit] = value;
    } else {
        RoomArrays* base = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        base->flags178[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)] &= (1U << bit) ^ 0xFFFFFFFF;
        base = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        base->values328[bit] = 255;
    }
}

extern const u32 lbl_8046E178[6];
extern const char lbl_8046E820[];
extern const f32 lbl_8054112C;
extern const f32 lbl_80541130;
struct RoomActorRecord8328 {
    u8 id[4];
    u8 layer, x, y;
    u8 param[4];
};
inline bool roomSpecial8328() {
    if (*(u8*)(lbl_8053AAF8+0x7f)==0) return false;
    char* g = *(char**)(lbl_8053AAF8+4);
    if ((*(s32*)(*(char**)(g+0xc)+4)==9 && *(s32*)(*(char**)(g+0xc)+8)==3)
        || *(s32*)(*(char* volatile*)(g+0xc)+4)>=13) return true;
    return false;
}
inline bool stagePair8328(s32 stage, s32 part) {
    return *(s32*)(lbl_80529DEC+0x118)==stage && *(s32*)(lbl_80529DEC+0x11c)==part;
}
inline bool swordStage8328() {
    if (*(u8*)(lbl_8053AAF8+0x7f)==0) return false;
    if ((*(s32*)(lbl_80529DEC+0x118)==0 && *(s32*)(lbl_80529DEC+0x11c)==2)||(*(s32*)(lbl_80529DEC+0x118)==1 && *(s32*)(lbl_80529DEC+0x11c)==2)||(*(s32*)(lbl_80529DEC+0x118)==2 && *(s32*)(lbl_80529DEC+0x11c)==2)||(*(s32*)(lbl_80529DEC+0x118)==3 && *(s32*)(lbl_80529DEC+0x11c)==2)
      ||(*(s32*)(lbl_80529DEC+0x118)==4 && *(s32*)(lbl_80529DEC+0x11c)==2)||(*(s32*)(lbl_80529DEC+0x118)==5 && *(s32*)(lbl_80529DEC+0x11c)==2)||(*(s32*)(lbl_80529DEC+0x118)==6 && *(s32*)(lbl_80529DEC+0x11c)==2)||(*(s32*)(lbl_80529DEC+0x118)==7 && *(s32*)(lbl_80529DEC+0x11c)==1)
      ||(*(s32*)(lbl_80529DEC+0x118)==10 && *(s32*)(lbl_80529DEC+0x11c)==2)) return true;
    return false;
}

#pragma opt_propagation off
extern "C" char* fn_802D8128(char* p, s32 index) {
    s32 x = *(s32*)(p + 0x14);
    if (x >= 0 && x < 10) {
        s32 y = *(s32*)(p + 0x18);
        if (y >= 0 && y < 10) {
            const char* name;
            s32 col = *(s32*)(p + 8);
            s32 row = *(s32*)(p + 4);
            if (*(u8*)(lbl_8053AAF8 + 0x7F) == 1)
                name = lbl_804A9530[row][col];
            else
                name = lbl_80541128;
            char* cell = p + y * 10;
            char* cell2 = cell + x;
            s32 number = ((RoomArrays*)cell2)->roomNumbers[0][0];
            if (number == 255)
                number = 0;
            sprintf(p + 0x1321A, lbl_8046E7E8, name, number / 10, number % 10, index - 7);
            return p + 0x1321A;
        }
    }
    return 0;
}
#pragma opt_propagation off
extern "C" char* fn_802D8228(char* p, s32 index) {
    s32 x = *(s32*)(p + 0x14);
    if (x >= 0 && x < 10) {
        s32 y = *(s32*)(p + 0x18);
        if (y >= 0 && y < 10) {
            const char* name;
            s32 col = *(s32*)(p + 8);
            s32 row = *(s32*)(p + 4);
            if (*(u8*)(lbl_8053AAF8 + 0x7F) == 1)
                name = lbl_804A9530[row][col];
            else
                name = lbl_80541128;
            char* cell = p + y * 10;
            char* cell2 = cell + x;
            s32 number = ((RoomArrays*)cell2)->roomNumbers[0][0];
            if (number == 255)
                number = 0;
            sprintf(p + 0x131FA, lbl_8046E804, name, number / 10, number % 10, index - 7);
            return p + 0x131FA;
        }
    }
    return 0;
}
#pragma opt_propagation on
extern "C" u8* fn_804032E8(u32, const char*);
extern "C" char* fn_801E9AFC();
extern "C" void fn_801EA384(char*, u8);
extern "C" void* fn_80204638();
extern "C" void fn_80204ABC(void*, u8);
extern "C" char* fn_80212AC0();
extern "C" void* fn_8021F064();
extern "C" void GrowableArray_Reset(void*);
extern "C" void* fn_801DAC6C();
extern "C" void fn_801DAF4C(void*);
extern "C" void* fn_801C0D70();
extern "C" void fn_801C151C(void*);
extern "C" void* fn_8020D58C();
extern "C" void fn_8020D690(void*);
extern "C" void* fn_801283E8();
extern "C" void fn_801283BC(void*);
extern "C" void* fn_8012F554();
extern "C" void fn_8012F494(void*);
extern "C" void* fn_8012FF9C();
extern "C" void fn_801300D8(void*);
extern "C" void* fn_80131F0C();
extern "C" void fn_80131EF8(void*);
extern "C" char* fn_801F666C(void*, s32);
extern "C" u32 fn_801F620C(void*, u32, u32);
extern "C" void fn_801EA594(char*);
extern "C" u8 lbl_8053AC30;
#pragma opt_lifetimes off
extern "C" void fn_802D8328(char* p, u8 reset, u8 flag) {
    u8* data;
    s32* out;
    s32* end;
    u32 tag;
    s32 number = 0;
    s32 count;
    s32 pass;
    s32 offset;
    s32 room;
    u32 id;
    u32 param;
    *(u8*)(p+0x131f6) = flag;
    if (*(s32*)(p+0x14)>=0 && *(s32*)(p+0x14)<10
        && *(s32*)(p+0x18)>=0 && *(s32*)(p+0x18)<10) {
        *(u16*)((char*)roomArrays()+0x131dc)=0;
        s32 col=*(s32*)(p+8), row=*(s32*)(p+4);
        
        if (*(u8*)(lbl_8053AAF8+0x7f)==1) data=(u8*)lbl_804A9530[row][col];
        else data=(u8*)lbl_80541128;
        s32 cellIndex=*(s32*)(p+0x18)*10;
        cellIndex+=*(s32*)(p+0x14);
        s32 roomNo=((u8*)p)[cellIndex+0x60];
        if (roomNo==255) roomNo=0;
        char buf[32];
        tag=0x42202020;
        sprintf(buf,lbl_8046E820,(char*)data,roomNo/10,roomNo%10);
        s32 c,b,a;
        a=((char*)data)[0]-0x20;
        b=((char*)data)[1]-0x20;
        c=((char*)data)[2];
        a <<= 16; b <<= 8; a += b; a += c; tag += a - 0x20;
        data=fn_804032E8(tag,buf);
        count=0;
        s32 ids[1025];
        fn_801EA384(fn_801E9AFC(),reset);
        fn_80204ABC(fn_80204638(),reset);
        char* registry=fn_80212AC0();
        *(s32*)(registry+0x80)=0;
        GrowableArray_Reset(fn_8021F064());
        fn_801DAF4C(fn_801DAC6C());
        fn_801C151C(fn_801C0D70());
        fn_8020D690(fn_8020D58C());
        fn_801283BC(fn_801283E8());
        fn_8012F494(fn_8012F554());
        fn_801300D8(fn_8012FF9C());
        if (reset) { fn_80131EF8(fn_80131F0C()); lbl_8053AC30=0; }
        end=ids;
        for (pass=0;pass<2;pass++) {
            offset=0;
            out=end;
            for (;;) {
                const RoomActorRecord8328* rec=(const RoomActorRecord8328*)(data+offset);
                id=(u32)rec->id[0]<<24|(u32)rec->id[1]<<16|(u32)rec->id[2]<<8|(u32)rec->id[3];
                if (id==0x20202020) break;
                param=(u32)rec->param[0]<<24|(u32)rec->param[1]<<16|(u32)rec->param[2]<<8|(u32)rec->param[3];
                u8 layer=rec->layer;
                u16 y;
                u16 x;
                x=rec->x;y=rec->y;
                offset+=11;
                bool first=false;
                for (s32 j=0;j<6;j++) {
                    if (id==lbl_8046E178[j]) {first=true;break;}
                }
                if ((first && pass==0)||(!first && pass!=0)) {
                    f32 ox,oy;
                    if (layer==0) {ox=*(f32*)(p+0xcc);oy=*(f32*)(p+0xd0);room=0;}
                    else {ox=oy=0.0f;room=layer+7;}
                    RoomArrays* rooms=roomArrays();
                    char* base=(char*)rooms;
                    if (!(rooms->flags3548[*(s32*)(base+0x18)][*(s32*)(base+0x14)][number/32] & (1<< (number%32)))) {
                        JGeometry::TVec3<f32> pos;
            pos.set(8.0f*(u16)x+ox,8.0f*(u16)y+oy,0.0f);
                        *out++=Actor_CreateByID(fn_801F856C(),id,room,(f32*)&pos,param,number,-1);
                        end++;count++;
                    } else {
                        bool destroyed=fn_801F620C(fn_801F856C(),id,0x64737472)!=0;
                        s32 idx=room<8 ? 0 : room-7;
                        if (destroyed) ((RoomArrays*)p)->counts6748[idx]++;
                    }
                    number++;
                }
            }
        }
        s32 actorId;
        s32* next=ids;
        for (s32 i=0;i<count;i++,next++) {
            actorId=*next;
            if (actorId>=0) {
                Actor* actor=(Actor*)fn_801F666C(fn_801F856C(),actorId);
                if (actor) actor->v02();
            }
        }
        char* mgr=fn_801E9AFC();
        fn_801EA594(mgr+*(u8*)(mgr+0xf0)*0x78);
        if (*(u8*)(lbl_8053AAF8+0x7f)!=0 && !roomSpecial8328()
            && !(*(s32*)(lbl_80529DEC+0x118)==0 && *(s32*)(lbl_80529DEC+0x11c)==1) && !(*(s32*)(lbl_80529DEC+0x118)==0 && *(s32*)(lbl_80529DEC+0x11c)==3) && !(*(s32*)(lbl_80529DEC+0x118)==1 && *(s32*)(lbl_80529DEC+0x11c)==3)
            && !(*(s32*)(lbl_80529DEC+0x118)==2 && *(s32*)(lbl_80529DEC+0x11c)==3) && !(*(s32*)(lbl_80529DEC+0x118)==3 && *(s32*)(lbl_80529DEC+0x11c)==3) && !(*(s32*)(lbl_80529DEC+0x118)==4 && *(s32*)(lbl_80529DEC+0x11c)==3)
            && !(*(s32*)(lbl_80529DEC+0x118)==5 && *(s32*)(lbl_80529DEC+0x11c)==1) && !(*(s32*)(lbl_80529DEC+0x118)==5 && *(s32*)(lbl_80529DEC+0x11c)==3) && !(*(s32*)(lbl_80529DEC+0x118)==6 && *(s32*)(lbl_80529DEC+0x11c)==1)
            && !(*(s32*)(lbl_80529DEC+0x118)==6 && *(s32*)(lbl_80529DEC+0x11c)==3) && !(*(s32*)(lbl_80529DEC+0x118)==7 && *(s32*)(lbl_80529DEC+0x11c)==0) && !(*(s32*)(lbl_80529DEC+0x118)==7 && *(s32*)(lbl_80529DEC+0x11c)==2) && !(*(s32*)(lbl_80529DEC+0x118)==7 && *(s32*)(lbl_80529DEC+0x11c)==3)) {
            JGeometry::TVec3<f32> pos;
            pos.set(100.0f+*(f32*)(p+0xcc),100.0f+*(f32*)(p+0xd0),0.0f);
            Actor_CreateByID(fn_801F856C(),0x54494e4b,0,(f32*)&pos,0,-1,-1);
        }
    }
    {
        JGeometry::TVec3<f32> pos;
            pos.set(*(f32*)(p+0xcc),*(f32*)(p+0xd0),0.0f);
        Actor_CreateByID(fn_801F856C(),0x4c46474e,0,(f32*)&pos,0,-1,-1);
    }
    {
        JGeometry::TVec3<f32> pos;
            pos.set(*(f32*)(p+0xcc),*(f32*)(p+0xd0),0.0f);
        Actor_CreateByID(fn_801F856C(),0x5442474e,0,(f32*)&pos,number,-1,-1);
    }
    if (*(u8*)(lbl_8053AAF8+0x7f)==1 && !swordStage8328()) {
        JGeometry::TVec3<f32> pos;
            pos.set(*(f32*)(p+0xcc),*(f32*)(p+0xd0),0.0f);
        Actor_CreateByID(fn_801F856C(),0x5357444c,0,(f32*)&pos,0,-1,-1);
    }
    {
    char* infoBase=p;
    char* posBase=p;
    for (s32 i=0;i<8;i++,infoBase+=4,posBase+=8) {
        u32 info=*(u32*)(infoBase+0x130c8);
        s32 tileX=(info>>16)&255;
        s32 tileY=(info>>8)&255;
        if (tileX==*(s32*)(p+0x14) && tileY==*(s32*)(p+0x18)) {
            u32 param=*(u32*)(infoBase+0x13068);
            JGeometry::TVec3<f32> pos;
            pos.set(*(f32*)(posBase+0x13088),*(f32*)(posBase+0x1308c),0.0f);
            Actor_CreateByID(fn_801F856C(),0x4c535449,info&255,(f32*)&pos,param|0x80|((info>>7)&0x1fe0000),-1,-1);
        }
    }
    }
    {
    s32 createdId;
    char* infoBase=p;
    char* posBase=p;
    for (s32 i=0;i<8;i++,infoBase+=4,posBase+=8) {
        u32 info=*(u32*)(infoBase+0x13128);
        s32 tileX=(info>>16)&255;
        s32 tileY=(info>>8)&255;
        if (tileX==*(s32*)(p+0x14) && tileY==*(s32*)(p+0x18)) {
            JGeometry::TVec3<f32> pos;
            pos.set(*(f32*)(posBase+0x130e8),*(f32*)(posBase+0x130ec),0.0f);
            createdId=Actor_CreateByID(fn_801F856C(),0x4b455930,info&255,(f32*)&pos,((info>>24)&63)|0x980,-1,-1);
            char* actor=fn_801F666C(fn_801F856C(),createdId);
            *(f32*)(actor+0x230)=*(f32*)(posBase+0x13148);
            *(f32*)(actor+0x234)=*(f32*)(posBase+0x1314c);
            *(u32*)(actor+0x238)=*(u32*)(infoBase+0x13188);
            *(u32*)(actor+0x23c)=info>>30;
        }
    }
    }
    fn_801F6204(fn_801F856C(),0);
    *(s32*)(p+0xec)=50;
}
#pragma opt_lifetimes reset
static inline char* RoomExtraPath802D(char* p, s32 index, const char* format, s32 offset) {
    s32 col;
    s32 row;
    s32 x = *(s32*)(p + 0x14);
    if (x >= 0 && x < 10) {
        s32 y = *(s32*)(p + 0x18);
        if (y >= 0 && y < 10) {
            const char* name;
            col = *(s32*)(p + 8);
            row = *(s32*)(p + 4);
            if (*(u8*)(lbl_8053AAF8 + 0x7F) == 1) name = lbl_804A9530[row][col];
            else name = lbl_80541128;
            s32 no = ((u8*)p)[y * 10 + x + 0x60];
            if (no == 255) no = 0;
            sprintf(p + offset, format, name, no / 10, no % 10, index + 1);
            return p + offset;
        }
    }
    return 0;
}
extern "C" void fn_802D8D50(char* this_, u8 flag) {
    extern void fn_802D4CCC(char* p, s32 index);
    extern void fn_802F6BBC(char* base, s32 src, s32 dst);
    extern void fn_802F99DC(char* this_, char* src, u32 a, s32 idx, u32 dst, u32 size);
    extern const char lbl_8046E148[];
    extern const char lbl_80540FDC[1];
    extern const f32 lbl_80541140;
    extern const f32 lbl_80541144;
    extern const f32 lbl_80541148;

    char* tbl;
    const char* fmt;
    const char* name;
    s32 tens;
    s32 ones;
    s32 key;
    s32 number;
    char buf104[32];
    char buf32[32];

    fmt = lbl_8046E148;
    name = lbl_80540FDC;
    number = 0;
    *(s32*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0xc) + 0x5c) = 0;
    {
        s32 col;
        s32 row;
        s32 x = *(s32*)(this_ + 0x14);
        if (x >= 0 && x < 10) {
            s32 y = *(s32*)(this_ + 0x18);
            if (y >= 0 && y < 10) {
                col = *(s32*)(this_ + 8);
                row = *(s32*)(this_ + 4);
                if (*(u8*)(lbl_8053AAF8 + 0x7f) == 1) {
                    name = lbl_804A9530[row][col];
                } else {
                    name = lbl_80541128;
                }
                number = ((u8*)(this_ + y * 10))[x + 0x60];
                if (number == 0xff) {
                    number = 0;
                }
            }
        }
    }
    tens = number / 10;
    ones = number % 10;
    key = RoomResourceTag802D(name);
    sprintf(buf104, fmt + 0x6f0, name, tens, ones);
    sprintf(buf32, fmt + 0x70c, name, tens, ones);
    if (flag != 0) {
        fn_802F6BBC(*(char**)(lbl_8053AB10 + 0x20), 0, 4);
        fn_802F6BBC(*(char**)(lbl_8053AB10 + 0x20), 1, 5);
    }

    tbl = (char*)lbl_80529DEC;
    {
        char* base = *(char**)(lbl_8053AB10 + 0x20);
        fn_802F99DC(base, (char*)((JKRArchive*)*(void**)(tbl + 0x10))->getResource(key, buf104), 0, 0, 0, 0);
    }
    {
        char* base = *(char**)(lbl_8053AB10 + 0x20);
        fn_802F99DC(base, (char*)((JKRArchive*)*(void**)(tbl + 0x10))->getResource(key, buf32), 0, 1, 0, 0);
    }

    *(u8*)(*(char**)(lbl_8053AB10 + 0x20) + 0x235c) = 1;
    *(u8*)(*(char**)(lbl_8053AB10 + 0x20) + 0x235d) = 1;
    fn_802D4CCC(this_, 0);

    bool skip;
    if (*(u8*)(lbl_8053AAF8 + 0x7f) == 0) {
        skip = false;
    } else {
        char* g4 = *(char**)(lbl_8053AAF8 + 4);
        if ((*(s32*)(*(char**)(g4 + 0xc) + 4) == 9 && *(s32*)(*(char**)(g4 + 0xc) + 8) == 3) ||
            *(s32*)((char*)roomArrays() + 4) >= 0xd) {
            skip = true;
        } else {
            skip = false;
        }
    }
    if (!skip) {
        for (s32 i = 0; i < 7; i++) {
            char* s1 = RoomExtraPath802D(this_, i, fmt + 0x6bc, 0x131fa);
            char* s2 = RoomExtraPath802D(this_, i, fmt + 0x6a0, 0x1321a);
            if (s1 != 0) {
                {
                    char* base = *(char**)(lbl_8053AB10 + 0x20);
                    fn_802F99DC(base, (char*)((JKRArchive*)*(void**)(tbl + 0x10))->getResource(key, s1), 0, i + 8, 0, 0);
                }
                {
                    char* base = *(char**)(lbl_8053AB10 + 0x20);
                    fn_802F99DC(base, (char*)((JKRArchive*)*(void**)(tbl + 0x10))->getResource(key, s2), 0, i + 0x10, 0, 0);
                }
                fn_802D4CCC(this_, i + 8);
            }
        }
    }

    f32 t;
    f32 l;
    l = lbl_80541144 * (f32)*(s32*)(this_ + 0x14);
    t = lbl_80541140 * (f32)*(s32*)(this_ + 0x18);
    *(f32*)(this_ + 0xcc) = l;
    *(f32*)(this_ + 0xd0) = t;
    *(f32*)(this_ + 0xd4) = lbl_80541144 + l;
    *(f32*)(this_ + 0xd8) = lbl_80541140 + t;
    char* base = *(char**)(lbl_8053AB10 + 0x20);
    s32 w = (s32)(lbl_80541148 * (*(f32*)(this_ + 0xd4) - *(f32*)(this_ + 0xcc)));
    s32 h = (s32)(lbl_80541148 * (*(f32*)(this_ + 0xd8) - *(f32*)(this_ + 0xd0)));
    *(s32*)(base + 0x2380) = w;
    *(s32*)(base + 0x2384) = h;
}

extern "C" void fn_802FA160(void*,void*,int,int,int,int);
extern "C" void fn_802F9DA8(void*,void*,int,int,int,int,int);
extern "C" void fn_802F9BE8(void*,void*,int,int,int);
extern "C" void fn_802F9714(void*,void*,int,int,int,int);
extern "C" void fn_802F93F4(void*,void*,int,int,int,int,int);
#pragma opt_propagation off
extern "C" void fn_802D92F0(char* p) {
    extern const char lbl_8046E148[];
    const char* fmt = lbl_8046E148;
    const char* const resourceName = fmt + 0x760;
    const char* name;
    char buf[32];
    char cl[32];
    char cl2[32];
    { void* res = (*(JKRArchive**)(lbl_8053AAF8 + 0xA4))->getResource(0x53434820, resourceName); fn_802FA160(*(void**)(lbl_8053AB10 + 0x20), res, 0, 0, 24576, 0); }
    { void* res = (*(JKRArchive**)(lbl_8053AAF8 + 0xA4))->getResource(0x53434820, &fmt[0x760]); fn_802FA160(*(void**)(lbl_8053AB10 + 0x20), res, 0, 1, 24576, 0); }
    s32 index = *(s32*)(p + 0x40);
    if (index >= 0 && index < 28)
        name = lbl_804A9660[index];
    else
        name = lbl_8054106C;
    if (*(const u8*)name == 'u')
        *(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0xC) + 0x131F1) = 1;
    sprintf(buf, fmt + 0x770, name);
    sprintf(cl, fmt + 0x728, name);
    sprintf(cl2, fmt + 0x74C, name);
    { void* res = (*(JKRArchive**)(lbl_8053AAF8 + 0xA4))->getResource(0x53434820, buf); fn_802FA160(*(void**)(lbl_8053AB10 + 0x20), res, 0, 0, 0, 0); }
    if (*(const u8*)name == 'c') {
    { void* res = (*(JKRArchive**)(lbl_8053AAF8 + 0xA4))->getResource(0x53434820, fmt + 0x780); fn_802FA160(*(void**)(lbl_8053AB10 + 0x20), res, 0, 1, 0, 0); }
    } else {
    { void* res = (*(JKRArchive**)(lbl_8053AAF8 + 0xA4))->getResource(0x53434820, buf); fn_802FA160(*(void**)(lbl_8053AB10 + 0x20), res, 0, 1, 0, 0); }
    }
    { void* res = (*(JKRArchive**)(lbl_8053AAF8 + 0xA4))->getResource(0x53434C20, cl); fn_802F9DA8(*(void**)(lbl_8053AB10 + 0x20), res, 0, 0, 0, 0, 0); }
    { void* res = (*(JKRArchive**)(lbl_8053AAF8 + 0xA4))->getResource(0x53434C20, cl2); fn_802F9DA8(*(void**)(lbl_8053AB10 + 0x20), res, 0, 1, 0, 0, 0); }
    { void* res = (*(JKRArchive**)(lbl_8053AAF8 + 0xA4))->getResource(0x53434C20, cl2); fn_802F9DA8(*(void**)(lbl_8053AB10 + 0x20), res, 0, 2, 0, 0, 0); }
    { void* res = (*(JKRArchive**)(lbl_8053AAF8 + 0xA4))->getResource(0x53504C20, fmt + 0x790); fn_802F9BE8(*(void**)(lbl_8053AB10 + 0x20),res,0,0,0); }
    { void* res = (*(JKRArchive**)(lbl_8053AAF8 + 0xA4))->getResource(0x53434820, fmt + 0x7A0); fn_802F9714(*(void**)(lbl_8053AB10 + 0x20), res, 0, 0, 0, 0); }
    index = *(s32*)(p + 0x44);
    const char* other;
    if (index >= 0 && index < 16)
        other = lbl_804A96D0[index];
    else
        other = lbl_805410DC;
    sprintf(buf, fmt + 0x7B8, other);
    { void* res = (*(JKRArchive**)(lbl_8053AAF8 + 0xA4))->getResource(0x53434820, buf); fn_802F9714(*(void**)(lbl_8053AB10 + 0x20), res, 0, 0, 28672, 0); }
    { void* res = (*(JKRArchive**)(lbl_8053AAF8 + 0xA4))->getResource(0x53434C20, fmt + 0x7D0); fn_802F93F4(*(void**)(lbl_8053AB10 + 0x20), res, 0, 0, 0, 0, 0); }
    bool skip;
    if (*(u8*)(lbl_8053AAF8 + 0x7F) == 0) {
        skip = false;
    } else {
        char* g4 = *(char**)(lbl_8053AAF8 + 4);
        if ((*(s32*)(*(char**)(g4 + 0xC) + 4) == 9 && *(s32*)(*(char**)(g4 + 0xC) + 8) == 3) ||
            *(s32*)(*(char* volatile*)(g4 + 0xC) + 4) >= 13)
            skip = true;
        else
            skip = false;
    }
    if ((u8)skip == 1) {
    { void* res = (*(JKRArchive**)(lbl_8053AAF8 + 0xA4))->getResource(0x53434820, fmt + 0x7E8); fn_802F9714(*(void**)(lbl_8053AB10 + 0x20), res, 0, 1, 0, 0); }
    } else {
    { void* res = (*(JKRArchive**)(lbl_8053AAF8 + 0xA4))->getResource(0x53434820, fmt + 0x7F8); fn_802F9714(*(void**)(lbl_8053AB10 + 0x20), res, 0, 1, 0, 0); }
    }
    { void* res = (*(JKRArchive**)(lbl_8053AAF8 + 0xA4))->getResource(0x53434C20, fmt + 0x7D0); fn_802F93F4(*(void**)(lbl_8053AB10 + 0x20), res, 0, 1, 0, 0, 0); }
    { void* res = (*(JKRArchive**)(lbl_8053AAF8 + 0xA4))->getResource(0x53434820, fmt + 0x808); fn_802F9714(*(void**)(lbl_8053AB10 + 0x20), res, 0, 2, 0, 0); }
    { void* res = (*(JKRArchive**)(lbl_8053AAF8 + 0xA4))->getResource(0x53434820, fmt + 0x818); fn_802F9714(*(void**)(lbl_8053AB10 + 0x20), res, 0, 2, 16384, 0); }
    { void* res = (*(JKRArchive**)(lbl_8053AAF8 + 0xA4))->getResource(0x53434C20, fmt + 0x7D0); fn_802F93F4(*(void**)(lbl_8053AB10 + 0x20), res, 0, 2, 0, 0, 0); }
    { void* res = (*(JKRArchive**)(lbl_8053AAF8 + 0xA4))->getResource(0x53434820, fmt + 0x828); fn_802F9714(*(void**)(lbl_8053AB10 + 0x20), res, 0, 3, 0, 0); }
    { void* res = (*(JKRArchive**)(lbl_8053AAF8 + 0xA4))->getResource(0x53434C20, fmt + 0x7D0); fn_802F93F4(*(void**)(lbl_8053AB10 + 0x20), res, 0, 3, 0, 0, 0); }
    { void* res = (*(JKRArchive**)(lbl_8053AAF8 + 0xA4))->getResource(0x53434C20, fmt + 0x838); fn_802F93F4(*(void**)(lbl_8053AB10 + 0x20), res, 0, 4, 0, 0, 0); }
    { void* res = (*(JKRArchive**)(lbl_8053AAF8 + 0xA4))->getResource(0x53434C20, fmt + 0x838); fn_802F93F4(*(void**)(lbl_8053AB10 + 0x20), res, 0, 5, 0, 0, 0); }
    { void* res = (*(JKRArchive**)(lbl_8053AAF8 + 0xA4))->getResource(0x53434C20, fmt + 0x838); fn_802F93F4(*(void**)(lbl_8053AB10 + 0x20), res, 0, 6, 0, 0, 0); }
    { void* res = (*(JKRArchive**)(lbl_8053AAF8 + 0xA4))->getResource(0x53434C20, fmt + 0x838); fn_802F93F4(*(void**)(lbl_8053AB10 + 0x20), res, 0, 7, 0, 0, 0); }
    { void* res = (*(JKRArchive**)(lbl_8053AAF8 + 0xA4))->getResource(0x53434C20, fmt + 0x838); fn_802F93F4(*(void**)(lbl_8053AB10 + 0x20), res, 0, 8, 0, 0, 0); }
    { void* res = (*(JKRArchive**)(lbl_8053AAF8 + 0xA4))->getResource(0x53434C20, fmt + 0x838); fn_802F93F4(*(void**)(lbl_8053AB10 + 0x20), res, 0, 9, 0, 0, 0); }
    { void* res = (*(JKRArchive**)(lbl_8053AAF8 + 0xA4))->getResource(0x53434C20, fmt + 0x838); fn_802F93F4(*(void**)(lbl_8053AB10 + 0x20), res, 0, 10, 0, 0, 0); }
    { void* res = (*(JKRArchive**)(lbl_8053AAF8 + 0xA4))->getResource(0x53434C20, fmt + 0x838); fn_802F93F4(*(void**)(lbl_8053AB10 + 0x20), res, 0, 11, 0, 0, 0); }
    *(u8*)(*(char**)(lbl_8053AB10 + 0x20) + 0x2364) = 1;
}
#pragma opt_propagation reset
extern "C" const char* fn_802D9C1C(char* p) {
    s32 index = *(s32*)(p + 0x44);
    if (index >= 0 && index < 16)
        return lbl_804A96D0[index];
    return lbl_805410DC;
}

extern "C" const char* fn_802D9C4C(char* p) {
    s32 index = *(s32*)(p + 0x40);
    if (index >= 0 && index < 28)
        return lbl_804A9660[index];
    return lbl_8054106C;
}

extern "C" const char* fn_802D9C7C(char*, s32 a, s32 b) {
    if (*(u8*)(lbl_8053AAF8 + 0x7F) == 1)
        return lbl_804A9530[a][b];
    return lbl_80541128;
}

extern "C" void fn_802D9CB0(char*) {
    fn_8030C85C(*(void**)(lbl_8053AB10 + 0x24));
}

extern "C" void fn_802D3D48(char*);
extern "C" void fn_802D92F0(char*);
extern "C" void fn_801F7B18();
extern "C" void fn_8016A3AC();
extern "C" void fn_8016A330();
extern "C" void fn_80158B3C(void*);
void fn_802D3D48(char*);
void fn_802D92F0(char*);
void fn_8016A3AC();
void fn_8016A330();
void fn_80158B3C(void*);
#pragma opt_common_subs off
extern "C" void fn_802D9CD8(char* p) {
    fn_802D3D48(p);
    for (s32 i = 0; i < 10; i++) {
        for (s32 j = 0; j < 10; j++) {
            for (s32 k = 0; k < 32; k += 4) {
                RoomArrays* base = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
                base->flags3548[i][j][k] = 0;
                base = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
                base->flags6768[i][j][k] = 0;
                base = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
                base->flags3548[i][j][k + 1] = 0;
                base = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
                base->flags6768[i][j][k + 1] = 0;
                base = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
                base->flags3548[i][j][k + 2] = 0;
                base = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
                base->flags6768[i][j][k + 2] = 0;
                base = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
                base->flags3548[i][j][k + 3] = 0;
                base = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
                base->flags6768[i][j][k + 3] = 0;
            }
            for (s32 k = 0; k < 256; k += 8) {
                RoomArrays* base = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
                base->values9968[i][j][k] = 0;
                base = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
                base->values9968[i][j][k + 1] = 0;
                base = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
                base->values9968[i][j][k + 2] = 0;
                base = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
                base->values9968[i][j][k + 3] = 0;
                base = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
                base->values9968[i][j][k + 4] = 0;
                base = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
                base->values9968[i][j][k + 5] = 0;
                base = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
                base->values9968[i][j][k + 6] = 0;
                base = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
                base->values9968[i][j][k + 7] = 0;
            }
        }
    }
    fn_801F856C();
    fn_801F7B18();
    fn_8016A3AC();
    fn_8016A330();
    fn_80158B3C(*(void**)(*(char**)(lbl_8053AB10) + 0x2c));
    fn_802D92F0(p);
    fn_802D8D50(p, 0);
    fn_802D8328(p, 1, 0);
    Vec v = {*(f32*)(p + 0xcc), *(f32*)(p + 0xd0), lbl_8054111C};
    char* a = *(char**)(lbl_8053AB10 + 0x24);
    *(f32*)(a + 0x154) = *(f32*)(p + 0xcc);
    *(f32*)(a + 0x158) = *(f32*)(p + 0xd0);
    *(f32*)(a + 0x15c) = *(f32*)(p + 0xd4);
    *(f32*)(a + 0x160) = *(f32*)(p + 0xd8);
    *(Vec*)(*(char**)(lbl_8053AB10 + 0x20) + 0x2368) = v;
}
#pragma opt_common_subs reset
extern "C" void fn_802D9FBC(char* p) {
    if (*(u8*)(lbl_8053AAF8 + 0x7F) == 1)
        *(s32*)(p + 0xC4) = 0x8CA0;
    else
        *(s32*)(p + 0xC4) = 0x2A30;
}

extern "C" void fn_802D9FE8(char* p, s32 a, s32 b) {
    *(s32*)(p + 0x1C) = a;
    *(s32*)(p + 0x20) = b;
}

extern "C" void fn_802D9FF4(char* p, s32 a, s32 b) {
    *(s32*)(p + 0x24) = a;
    *(s32*)(p + 0x28) = b;
}

extern "C" u8 fn_802DA000(char*) {
    return *(u8*)(*(char**)(lbl_8053AB10 + 0x24) + 0x1E8);
}

#pragma opt_lifetimes off
extern "C" void fn_802DA010(char* p) {
    extern const f32 lbl_8046E148[];
    extern const f32 lbl_80541158;
    extern const f32 lbl_8054115C;
    extern void* lbl_8053AD70;
    JGeometry::TVec3<f32> w;
    f32 v[3];
    *(s32*)(p + 0x14) = *(s32*)(p + 0x24);
    *(s32*)(p + 0x18) = *(s32*)(p + 0x28);
    fn_801F7E88(fn_801F856C());
    *(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + 0x131EF) = 0;
    u8 flag = *(u8*)(lbl_8053AAF8 + 0x7F);
    u8 ok = (flag ? *(u8*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xC8 + 0x7C) : *(u8*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xC8 + 0x7D)) == 1;
    if (ok == 1) {
        if ((flag ? *(u8*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xC8 + 0x7C) : *(u8*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xC8 + 0x7D)) != 1) {
            *(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + 0x131F0) = 0;
        } else if (flag != 0) {
            if (*(u8*)(lbl_8053AAF8 + 0x7E) == 1) {
                *(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + 0x131F0) = 1;
            } else {
                *(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + 0x131F0) = 0;
            }
        } else {
            *(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + 0x131F0) = 1;
        }
    } else {
        *(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + 0x131F0) = 0;
    }
    RoomArrays* base = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    base->flags178[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)] &= 0xFFFF0000;
    for (unsigned int i = 0; i < 16; i++) {
        (*(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C))->counters308[i] = 0;
    }
    {
        unsigned int word = 0;
        for (unsigned int byte = 0; byte < 32; byte += 2) {
            roomArrays()->values328[byte + 0] = 0xff;
            clearRoomFlag12F68(word++);
            roomArrays()->values328[byte + 1] = 0xff;
            clearRoomFlag12F68(word++);
        }
    }
    for (s32 i = 0; i < 8; i++) {
        (*(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C))->counts6748[i] = 0;
        for (int k = 0; k < 64; k++) {
            roomValueColumn(k)[i * 64] = 0;
        }
    }
    fn_8038D454();
    fn_802D8D50(p, 0);
    fn_801F856C();
    fn_801F7B18();
    fn_801F6204(fn_801F856C(), 0);
    fn_80308D0C();
    if (*(u8*)(lbl_8053AAF8 + 0x7F) == 1) {
        *(s32*)(p + 0xC4) = 36000;
    } else {
        *(s32*)(p + 0xC4) = 0x2A30;
    }
    fn_8013C8CC(fn_8013C824());
    {
        s32 i;
        const f32* t = lbl_8046E148;
        *(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + 0x131DE) = i = 0;
        for (; i < 4; i++) {
            v[0] = t[0];
            v[1] = t[1];
            v[2] = t[2];
            v[0] += *(f32*)(p + 0xCC);
            v[1] += *(f32*)(p + 0xD0);
            fn_8023F1D4(i, v, 2, 0, 0);
            t += 3;
        }
    }
    fn_8022BD70();
    fn_8037AE30(lbl_8053AD70);
    fn_802D8328(p, 0, 0);
    {
        char* a = *(char**)(lbl_8053AB10 + 0x24);
        *(f32*)(a + 0x154) = *(f32*)(p + 0xCC);
        *(f32*)(a + 0x158) = *(f32*)(p + 0xD0);
        *(f32*)(a + 0x15C) = *(f32*)(p + 0xD4);
        *(f32*)(a + 0x160) = *(f32*)(p + 0xD8);
    }
    w.set(*(f32*)(p + 0xCC), *(f32*)(p + 0xD0), lbl_8054111C);
    JGeometry::setTVec3f(&w.x, (f32*)(*(char**)(lbl_8053AB10 + 0x20) + 0x2368));
    f32* pos = (f32*)fn_8023E724(0);
    u8* a = *(u8**)(lbl_8053AB10 + 0x24);
    if (a[0x840] == 0) {
        a[0x840] = 1;
        *(f32*)(a + 0x844) = *(f32*)(a + 0x84C) = pos[0];
        *(f32*)(a + 0x848) = *(f32*)(a + 0x850) = pos[1];
        *(f32*)(a + 0x854) = lbl_80541158;
        *(f32*)(a + 0x1D4) = lbl_8054115C;
        *(f32*)(a + 0x1D8) = lbl_8054115C;
    }
    if (*(u8*)(lbl_8053AAF8 + 0x7F) == 1) {
        *(s32*)(p + 0xC4) = 36000;
    } else {
        *(s32*)(p + 0xC4) = 0x2A30;
    }
}
#pragma opt_lifetimes reset
extern "C" u8 fn_802DA630(char* p) {
    u8 flag = getRoomTransitionFlag();
    if (flag == 0) {
        s32 count;
        s32 i;
        f32 offset;
        JGeometry::TVec3<f32> v;
        void* e;

        offset = *(s32*)(p + 0x2C) > 0 ? lbl_80541160 : lbl_80541164;
        for (i = 0; i < 4; i++) {
            v = *(JGeometry::TVec3<f32>*)fn_8023E724(i);
            v.x += offset;
            fn_80230498(i, &v, (u16)fn_8023CBC0(i), 0xff, -0x80, -0x80, 1);
        }
        count = getActorList()->getCount();
        for (i = 0; i < count; i++) {
            e = getActorList()->getActor(i);
            if (e != NULL && *(s32*)((char*)e + 0x1A0) == 0x4F53494E && *(s32*)((char*)e + 0x230) == 2) {
                v = *(JGeometry::TVec3<f32>*)((char*)e + 0xC);
                v.x += offset;
                *(JGeometry::TVec3<f32>*)((char*)e + 0xC) = v;
                break;
            }
        }
    }
    return flag;
}

extern "C" u8 fn_802DEDFC(s32 value);
extern "C" void fn_8038D454(void);
extern "C" void fn_8022BD70(void);
extern "C" void fn_8037AE30(void* p);
extern "C" void fn_8023F1D4(int idx, void* pos, int a, int b, u8 c);
extern void* lbl_8053AD70;
extern const f32 lbl_8046E148[];
extern "C" void fn_802DA788(char* p) {
    s32 j;
    f32 v[3];
    if (*(s32*)(p + 0x14) < *(s32*)(p + 0x1c)) {
        *(s32*)(p + 0x2c) = 1;
        *(s32*)(p + 0x30) = 0;
    } else {
        *(s32*)(p + 0x2c) = -1;
        *(s32*)(p + 0x30) = 0;
    }
    if (fn_802DEDFC((s32)(p + 0x2c))) {
        fn_8038D454();
        fn_801F7CAC(fn_801F856C());
        fn_801F6204(fn_801F856C(), 0);
        fn_80308D0C();
        *(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + 0x131DE) = 0;
        fn_8013C8CC(fn_8013C824());
        *(u8*)(p + 0xC9) = j = 0;
        for (; j < 4; j++) {
            v[0] = lbl_8046E148[j * 3 + 0];
            v[1] = lbl_8046E148[j * 3 + 1];
            v[2] = lbl_8046E148[j * 3 + 2];
            v[0] = v[0] + *(f32*)(p + 0xCC);
            v[1] = v[1] + *(f32*)(p + 0xD0);
            fn_8023F1D4(j, v, 2, 0, 0);
        }
        fn_8022BD70();
        fn_8037AE30(lbl_8053AD70);
        if (*(u8*)(lbl_8053AAF8 + 0x7F) == 1) {
            *(s32*)(p + 0xC4) = 36000;
        } else {
            *(s32*)(p + 0xC4) = 0x2A30;
        }
    }
}

#pragma opt_common_subs on
extern "C" void fn_802DA8DC(char* const p) {
    JGeometry::TVec3<f32> camera;
    f32 points[3];
    int k,j,i;
    *(s32*)(p+0x14)=*(s32*)(p+0x24);
    *(s32*)(p+0x18)=*(s32*)(p+0x28);
    fn_801F7E88(fn_801F856C());
    fn_802DEE2C();
    for(i=0;i<10;i++) for(j=0;j<10;j++) for(k=0;k<8;k++) roomArrays()->flags1048[i][j][k]=0;
    for(i=0;i<8;i++) for(j=0;j<64;j++) roomArrays()->values2948[i][j]=0;
    for(i=0;i<4;i++) for(j=0;j<128;j++) roomArrays()->flags2D48[i][j]=0;
    for(i=0;i<10;i++) for(j=0;j<10;j++){
      for(k=0;k<32;k+=4){roomArrays()->flags3548[i][j][k+0]=0;roomArrays()->flags6768[i][j][k+0]=0;roomArrays()->flags3548[i][j][k+1]=0;roomArrays()->flags6768[i][j][k+1]=0;roomArrays()->flags3548[i][j][k+2]=0;roomArrays()->flags6768[i][j][k+2]=0;roomArrays()->flags3548[i][j][k+3]=0;roomArrays()->flags6768[i][j][k+3]=0;}
      for(k=0;k<256;k++) roomArrays()->values9968[i][j][k]=0;
    }
    for(i=0;i<8;i++){
      roomArrays()->keys13068[i]=0;
      roomArrays()->positions13088[i].set(lbl_8054111C,lbl_8054111C);
      roomArrays()->owners130C8[i]=-1;
    }
    for(i=0;i<8;i++){
      roomArrays()->positions130E8[i].set(lbl_8054111C,lbl_8054111C);
      roomArrays()->owners13128[i]=-1;
      roomArrays()->positions13148[i].set(lbl_8054111C,lbl_8054111C);
      roomArrays()->owners13188[i]=-1;
    }

    ((u8*)roomArrays())[0x171]=1;
    *(s32*)((char*)roomArrays()+0x174)=0;
    for(i=0;i<16;i+=8){((RoomArrays*)p)->flags131B8[i+0]=0;*((u8*)p+(i+0+0x131DF))=0;((RoomArrays*)p)->flags131B8[i+1]=0;*((u8*)p+(i+1+0x131DF))=0;((RoomArrays*)p)->flags131B8[i+2]=0;*((u8*)p+(i+2+0x131DF))=0;((RoomArrays*)p)->flags131B8[i+3]=0;*((u8*)p+(i+3+0x131DF))=0;((RoomArrays*)p)->flags131B8[i+4]=0;*((u8*)p+(i+4+0x131DF))=0;((RoomArrays*)p)->flags131B8[i+5]=0;*((u8*)p+(i+5+0x131DF))=0;((RoomArrays*)p)->flags131B8[i+6]=0;*((u8*)p+(i+6+0x131DF))=0;((RoomArrays*)p)->flags131B8[i+7]=0;*((u8*)p+(i+7+0x131DF))=0;}
    ((u8*)roomArrays())[0x131DE]=0;
        *(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + 0x131EF) = 0;
        u8 v;
        if (*(u8*)(lbl_8053AAF8 + 0x7F) != 0) {
            v = *(u8*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xC8 + 0x7C);
        } else {
            v = *(u8*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xC8 + 0x7D);
        }
        u32 t = v == 1;
        if (t == 1) {
            u8 v2;
            if (*(u8*)(lbl_8053AAF8 + 0x7F) != 0) {
                v2 = *(u8*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xC8 + 0x7C);
            } else {
                v2 = *(u8*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xC8 + 0x7D);
            }
            if (v2 != 1) {
                *(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + 0x131F0) = 0;
            } else if (*(u8*)(lbl_8053AAF8 + 0x7F) != 0) {
                if (*(u8*)(lbl_8053AAF8 + 0x7E) == 1) {
                    *(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + 0x131F0) = 1;
                } else {
                    *(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + 0x131F0) = 0;
                }
            } else {
                *(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + 0x131F0) = 1;
            }
        } else {
            *(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + 0x131F0) = 0;
        }

    ((u8*)roomArrays())[0x131F1]=0;
    ((u8*)roomArrays())[0x131F2]=0;
    ((u8*)roomArrays())[0x131F3]=0;
    roomArrays()->flags178[*(s32*)(p+0x18)][*(s32*)(p+0x14)] &= 0xFFFF0000;
    for(i=0;i<16;i++) roomArrays()->counters308[i]=0;
    { u32 b=0; for(u32 w=0;w<32;w++,b++){*(u8*)((char*)roomArrays()+b+0x328)=0xFF;roomArrays()->flags12F68[w]=0;} }
    for(i=0;i<8;i++){
      roomArrays()->counts6748[i]=0;
      for(j=0;j<64;j++)roomArrays()->values2948[i][j]=0;
    }
    fn_8038D454();fn_802D8D50(p,0);
    fn_801F856C();fn_801F7B18();
    fn_801F6204(fn_801F856C(),0);
    fn_80308D0C();
    if(*(u8*)(lbl_8053AAF8+0x7F)==1) *(s32*)(p+0xC4)=36000;
    else *(s32*)(p+0xC4)=0x2A30;
    fn_8013C8CC(fn_8013C824());
    ((u8*)roomArrays())[0x131DE]=0;
    fn_8023F78C();fn_8023F728();
    fn_8043D834(lbl_8053AED0);
    for(i=0;i<4;i++){
      points[0]=lbl_8046E148[i*3];points[1]=lbl_8046E148[i*3+1];points[2]=lbl_8046E148[i*3+2];
      points[0]+=*(f32*)(p+0xCC);points[1]+=*(f32*)(p+0xD0);
      fn_8023F1D4(i,points,2,0,0);
    }
    fn_8022BD70();fn_8037AE30(lbl_8053AD70);fn_802D8328(p,0,0);
    char* m=*(char**)(lbl_8053AB10+0x24);
    *(f32*)(m+0x154)=*(f32*)(p+0xCC);*(f32*)(m+0x158)=*(f32*)(p+0xD0);
    *(f32*)(m+0x15C)=*(f32*)(p+0xD4);*(f32*)(m+0x160)=*(f32*)(p+0xD8);
    camera.set(*(f32*)(p+0xCC),*(f32*)(p+0xD0),lbl_8054111C);
    *(JGeometry::TVec3<f32>*)(*(char**)(lbl_8053AB10+0x20)+0x2368)=camera;
    if(*(u8*)(lbl_8053AAF8+0x7F)==1) *(s32*)(p+0xC4)=36000;
    else *(s32*)(p+0xC4)=0x2A30;

    fn_8023F78C();
    f32* src=(f32*)fn_8023E724(0);
    char* c=*(char**)(lbl_8053AB10+0x24);
    if(*(u8*)(c+0x840)==0){
      *(u8*)(c+0x840)=1;
      *(f32*)(c+0x844)=*(f32*)(c+0x84C)=src[0];
      *(f32*)(c+0x848)=*(f32*)(c+0x850)=src[1];
      *(f32*)(c+0x854)=lbl_80541158;
      *(f32*)(c+0x1D4)=lbl_8054115C;
      *(f32*)(c+0x1D8)=lbl_8054115C;
    }
}
#pragma opt_common_subs reset
extern "C" void fn_802DB6F0(char* p) {
    extern const f32 lbl_8046E148[];
    extern const f32 lbl_80541158;
    extern const f32 lbl_8054115C;
    extern void* lbl_8053AD70;
    int i;
    JGeometry::TVec3<f32> cam;
    *(s32*)(p + 0x14) = *(s32*)(p + 0x24);
    *(s32*)(p + 0x18) = *(s32*)(p + 0x28);
    fn_801F7E88(fn_801F856C());
    *(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + 0x131EF) = 0;
    u8 flag = *(u8*)(lbl_8053AAF8 + 0x7F);
    u8 sel = flag != 0 ? *(u8*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xC8 + 0x7C) : *(u8*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xC8 + 0x7D);
    u8 ok = sel == 1;
    if (ok == 1) {
        u8 sel2 = flag != 0 ? *(u8*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xC8 + 0x7C) : *(u8*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xC8 + 0x7D);
        if (sel2 != 1) {
            *(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + 0x131F0) = 0;
        } else if (flag != 0) {
            if (*(u8*)(lbl_8053AAF8 + 0x7E) == 1) {
                *(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + 0x131F0) = 1;
            } else {
                *(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + 0x131F0) = 0;
            }
        } else {
            *(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + 0x131F0) = 1;
        }
    } else {
        *(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + 0x131F0) = 0;
    }
    roomArrays()->flags178[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)] &= 0xFFFF0000;
    for (i = 0; i < 16; i++) {
        roomArrays()->counters308[i] = 0;
    }
    int byteIndex = 0;
    int wordOffset = 0;
    for (int n = 0; n < 8; n++) {
        roomArrays()->values328[byteIndex++] = 0xff;
        *(u32*)((char*)roomArrays() + 0x12f68 + wordOffset) = 0;
        wordOffset += 4;
        roomArrays()->values328[byteIndex++] = 0xff;
        *(u32*)((char*)roomArrays() + 0x12f68 + wordOffset) = 0;
        wordOffset += 4;
        roomArrays()->values328[byteIndex++] = 0xff;
        *(u32*)((char*)roomArrays() + 0x12f68 + wordOffset) = 0;
        wordOffset += 4;
        roomArrays()->values328[byteIndex++] = 0xff;
        *(u32*)((char*)roomArrays() + 0x12f68 + wordOffset) = 0;
        wordOffset += 4;
    }
    for (i = 0; i < 8; i++) {
        roomArrays()->counts6748[i] = 0;
        for (int k = 0; k < 64; k++) {
            roomValueColumn(k)[i * 64] = 0;
        }
    }
    fn_8038D454();
    fn_802D8D50(p, 0);
    fn_801F856C();
    fn_801F7B18();
    fn_801F6204(fn_801F856C(), 0);
    fn_80308D0C();
    if (*(u8*)(lbl_8053AAF8 + 0x7F) == 1) {
        *(s32*)(p + 0xC4) = 36000;
    } else {
        *(s32*)(p + 0xC4) = 0x2A30;
    }
    fn_8013C8CC(fn_8013C824());
    *(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + 0x131DE) = 0;
    for (s32 j = 0; j < 4; j++) {
        f32 v[3];
        v[0] = lbl_8046E148[j * 3 + 0];
        v[1] = lbl_8046E148[j * 3 + 1];
        v[2] = lbl_8046E148[j * 3 + 2];
        v[0] = v[0] + *(f32*)(p + 0xCC);
        v[1] = v[1] + *(f32*)(p + 0xD0);
        fn_8023F1D4(j, v, 2, 0, 0);
    }
    fn_8022BD70();
    fn_8037AE30(lbl_8053AD70);
    fn_802D8328(p, 0, 0);
    {
        char* a = *(char**)(lbl_8053AB10 + 0x24);
        *(f32*)(a + 0x154) = *(f32*)(p + 0xCC);
        *(f32*)(a + 0x158) = *(f32*)(p + 0xD0);
        *(f32*)(a + 0x15C) = *(f32*)(p + 0xD4);
        *(f32*)(a + 0x160) = *(f32*)(p + 0xD8);
    }
    cam.set(*(f32*)(p + 0xCC), *(f32*)(p + 0xD0), lbl_8054111C);
    *(JGeometry::TVec3<f32>*)(*(char**)(lbl_8053AB10 + 0x20) + 0x2368) = cam;
    if (*(u8*)(lbl_8053AAF8 + 0x7F) == 1) {
        *(s32*)(p + 0xC4) = 36000;
    } else {
        *(s32*)(p + 0xC4) = 0x2A30;
    }
    for (s32 j = 0; j < 4; j++) {
        s32 r = fn_8023BCD4(j);
        u16 id = fn_8023CBC0(j);
        fn_80230498(j, fn_8023E604(j), id, r, -0x80, -0x80, 1);
    }
    f32* pos = (f32*)fn_8023E604(0);
    u8* a = *(u8**)(lbl_8053AB10 + 0x24);
    if (a[0x840] == 0) {
        a[0x840] = 1;
        *(f32*)(a + 0x84C) = pos[0];
        *(f32*)(a + 0x844) = pos[0];
        *(f32*)(a + 0x850) = pos[1];
        *(f32*)(a + 0x848) = pos[1];
        *(f32*)(a + 0x854) = lbl_80541158;
        *(f32*)(a + 0x1D4) = lbl_8054115C;
        *(f32*)(a + 0x1D8) = lbl_8054115C;
    }
}

extern "C" void fn_80235918(s32);
extern "C" void fn_8023EE28(s32);
extern "C" void fn_80138B7C(void*);
extern "C" void fn_8022ADCC();
extern "C" void fn_8022ADE4();
extern "C" void fn_8023F6C4();
extern "C" void fn_8023077C();
extern "C" void fn_8022F9E4(s32,s32,s32,s32);
extern "C" void fn_802DBD60(char* p) {
    s32 k,j,i;
    *(s32*)(p + 0x14) = *(s32*)(p + 0x24);
    *(s32*)(p + 0x18) = *(s32*)(p + 0x28);
    fn_801F7E88(fn_801F856C());
    ((u8*)roomArrays())[0x131EF] = 0;
    u8 cVar1;
    if (*(u8*)(lbl_8053AAF8 + 0x7F) != 0) {
        const u8* data=lbl_8050EC80;
        s32 index=*(s32*)(data+0x10);
        cVar1=data[index*0xc8+0x7c];
    } else {
        const u8* data=lbl_8050EC80;
        s32 index=*(s32*)(data+0x10);
        cVar1=data[index*0xc8+0x7d];
    }
    cVar1 = cVar1 == 1;
    if (cVar1 == 1) {
        if (*(u8*)(lbl_8053AAF8 + 0x7F) != 0) {
            const u8* data=lbl_8050EC80;
        s32 index=*(s32*)(data+0x10);
        cVar1=data[index*0xc8+0x7c];
        } else {
            const u8* data=lbl_8050EC80;
        s32 index=*(s32*)(data+0x10);
        cVar1=data[index*0xc8+0x7d];
        }
        if (cVar1 != 1) {
            ((u8*)roomArrays())[0x131F0] = 0;
        } else if (*(u8*)(lbl_8053AAF8 + 0x7F) != 0) {
            if (*(u8*)(lbl_8053AAF8 + 0x7E) == 1) {
                ((u8*)roomArrays())[0x131F0] = 1;
            } else {
                ((u8*)roomArrays())[0x131F0] = 0;
            }
        } else {
            ((u8*)roomArrays())[0x131F0] = 1;
        }
    } else {
        ((u8*)roomArrays())[0x131F0] = 0;
    }
    s32 row=*(s32*)(p+0x18);
    s32 col=*(s32*)(p+0x14);
    roomArrays()->flags178[row][col] &= 0xffff0000;
    for (i = 0; i < 16; i += 8) {
        roomArrays()->counters308[i + 0] = 0;
        roomArrays()->counters308[i + 1] = 0;
        roomArrays()->counters308[i + 2] = 0;
        roomArrays()->counters308[i + 3] = 0;
        roomArrays()->counters308[i + 4] = 0;
        roomArrays()->counters308[i + 5] = 0;
        roomArrays()->counters308[i + 6] = 0;
        roomArrays()->counters308[i + 7] = 0;
    }
    for(s32 i=0,k=0;i<32;) {
        roomArrays()->values328[i++]=0xff;
        roomArrays()->flags12F68[k++]=0;
        roomArrays()->values328[i++]=0xff;
        roomArrays()->flags12F68[k++]=0;
        roomArrays()->values328[i++]=0xff;
        roomArrays()->flags12F68[k++]=0;
        roomArrays()->values328[i++]=0xff;
        roomArrays()->flags12F68[k++]=0;
    }
    for (i = 0; i < 8; i++) {
        roomArrays()->counts6748[i] = 0;
        for (j = 0; j < 64; j += 8) {
            roomArrays()->values2948[i][j + 0] = 0;
            roomArrays()->values2948[i][j + 1] = 0;
            roomArrays()->values2948[i][j + 2] = 0;
            roomArrays()->values2948[i][j + 3] = 0;
            roomArrays()->values2948[i][j + 4] = 0;
            roomArrays()->values2948[i][j + 5] = 0;
            roomArrays()->values2948[i][j + 6] = 0;
            roomArrays()->values2948[i][j + 7] = 0;
        }
    }
    fn_8038D454();
    u8 cVar3 = ((u8*)roomArrays())[0x131F9];
    if (cVar3 == 2) {
        fn_802DEE2C();
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 10; j++) {
                for (k = 0; k < 8; k++) {
                    roomArrays()->flags1048[i][j][k] = 0;
                }
            }
        }
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 64; j += 8) {
                roomArrays()->values2948[i][j + 0] = 0;
                roomArrays()->values2948[i][j + 1] = 0;
                roomArrays()->values2948[i][j + 2] = 0;
                roomArrays()->values2948[i][j + 3] = 0;
                roomArrays()->values2948[i][j + 4] = 0;
                roomArrays()->values2948[i][j + 5] = 0;
                roomArrays()->values2948[i][j + 6] = 0;
                roomArrays()->values2948[i][j + 7] = 0;
            }
        }
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 128; j += 8) {
                roomArrays()->flags2D48[i][j + 0] = 0;
                roomArrays()->flags2D48[i][j + 1] = 0;
                roomArrays()->flags2D48[i][j + 2] = 0;
                roomArrays()->flags2D48[i][j + 3] = 0;
                roomArrays()->flags2D48[i][j + 4] = 0;
                roomArrays()->flags2D48[i][j + 5] = 0;
                roomArrays()->flags2D48[i][j + 6] = 0;
                roomArrays()->flags2D48[i][j + 7] = 0;
            }
        }
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 10; j++) {
                for(k=0;k<32;) {
                    roomArrays()->flags3548[i][j][k]=0;
                    roomArrays()->flags6768[i][j][k++]=0;
                    roomArrays()->flags3548[i][j][k]=0;
                    roomArrays()->flags6768[i][j][k++]=0;
                    roomArrays()->flags3548[i][j][k]=0;
                    roomArrays()->flags6768[i][j][k++]=0;
                    roomArrays()->flags3548[i][j][k]=0;
                    roomArrays()->flags6768[i][j][k++]=0;
                }
                for(k=0;k<256;k+=8) {
                    roomArrays()->values9968[i][j][k+0]=0;
                    roomArrays()->values9968[i][j][k+1]=0;
                    roomArrays()->values9968[i][j][k+2]=0;
                    roomArrays()->values9968[i][j][k+3]=0;
                    roomArrays()->values9968[i][j][k+4]=0;
                    roomArrays()->values9968[i][j][k+5]=0;
                    roomArrays()->values9968[i][j][k+6]=0;
                    roomArrays()->values9968[i][j][k+7]=0;
                }
            }
        }
        for(i=0;i<8;i++) {
            roomArrays()->keys13068[i]=0;
            roomArrays()->positions13088[i].set(0.0f,0.0f);
            roomArrays()->owners130C8[i]=0xffffffff;
        }
        for(i=0;i<8;i++) {
            roomArrays()->positions130E8[i].set(0.0f,0.0f);
            roomArrays()->owners13128[i]=-1;
            roomArrays()->positions13148[i].set(0.0f,0.0f);
            roomArrays()->owners13188[i]=-1;
        }
        ((u8*)roomArrays())[0x170] = 1;
        ((u8*)roomArrays())[0x171] = 1;
        *(s32*)((u8*)roomArrays() + 0x174) = 0;
        ((u8*)roomArrays())[0x131DE] = 0;
        ((u8*)roomArrays())[0x131F1] = 0;
        ((u8*)roomArrays())[0x131F2] = 0;
        ((u8*)roomArrays())[0x131F3] = 0;
        ((u8*)roomArrays())[0x131F4] = 0;
        ((u8*)roomArrays())[0x131F5] = 0;
        fn_80158B3C(*(void**)(lbl_8053AB10 + 0x2C));
        for (i = 0; i < 4; i++) {
            cVar3 = fn_8023F264(i);
            if (cVar3 != 0) {
                fn_80235918(i);
            }
            fn_8023EE28(i);
        }
        *(s32*)((u8*)roomArrays() + 0x1328C) = 0;
        s32 v = *(s32*)((u8*)roomArrays() + 0x38);
        *(s32*)((u8*)roomArrays() + 0x34) = v;
        if (v < 0x11) {
            *(s32*)((u8*)roomArrays() + 0x1328C) = 0;
        }
        fn_80138B7C(lbl_8053AAF8);
        fn_8022ADCC();
        fn_8016A3AC();
        fn_8016A330();
        fn_802D92F0(p);
    } else if (cVar3 == 3) {
        fn_80158B3C(*(void**)(lbl_8053AB10 + 0x2C));
        char* b = (char*)roomArrays();
        if (*(s32*)(b + 4) != 7 || *(s32*)(b + 8) != 3) {
            fn_8022ADE4();
        }
    }
    fn_802D8D50(p, 0);
    fn_801F856C();
    fn_801F7B18();
    void* uVar2 = fn_801F856C();
    fn_801F6204(uVar2, 0);
    fn_80308D0C();
    if (*(u8*)(lbl_8053AAF8 + 0x7F) == 1) {
        *(s32*)(p + 0xC4) = 36000;
    } else {
        *(s32*)(p + 0xC4) = 0x2A30;
    }
    fn_8013C8CC(fn_8013C824());
    const f32* pf = lbl_8046E148;
    f32 pos[3];
    ((u8*)roomArrays())[0x131DE] = 0;
    for (i = 0; i < 4; i++) {
        pos[0]=pf[0];pos[1]=pf[1];pos[2]=pf[2];
        pos[0]+=*(f32*)(p+0xCC);pos[1]+=*(f32*)(p+0xD0);
        fn_8023F1D4(i, pos, 2, 0, 0);
        pf += 3;
    }
    fn_8022BD70();
    fn_8037AE30(lbl_8053AD70);
    fn_802D8328(p, 0, 0);
    u8 cVar5 = ((u8*)roomArrays())[0x131F9];
    if (cVar5 == 2 || cVar5 == 3) {
        f32* src = (f32*)fn_8023E724(0);
        Vec vec;
        JGeometry::setTVec3f(src,(f32*)&vec);
        vec.z=lbl_8054111C;
        Actor_CreateByID(fn_801F856C(), 0x474c5750, 0, (f32*)&vec, 0x100, -1, -1);
    }
    {
        char* m = *(char**)(lbl_8053AB10 + 0x24);
        *(f32*)(m + 0x154) = *(f32*)(p + 0xCC);
        *(f32*)(m + 0x158) = *(f32*)(p + 0xD0);
        *(f32*)(m + 0x15C) = *(f32*)(p + 0xD4);
        *(f32*)(m + 0x160) = *(f32*)(p + 0xD8);
        Vec position;
        position.x=*(f32*)(p+0xCC);position.y=*(f32*)(p+0xD0);position.z=lbl_8054111C;
        JGeometry::setTVec3f((f32*)&position,(f32*)(*(char**)(lbl_8053AB10+0x20)+0x2368));
        if (*(u8*)(lbl_8053AAF8 + 0x7F) == 1) {
            *(s32*)(p + 0xC4) = 36000;
        } else {
            *(s32*)(p + 0xC4) = 0x2A30;
        }
        fn_8023F78C();
        u8 state=((u8*)roomArrays())[0x131F9];
        if(state>=2) {
            if(state==2) fn_8023F6C4();
            fn_8023077C();
            ((u8*)roomArrays())[0x131F9]=1;
        }
        for(i=0;i<4;i++) {
            s32 value=*(s32*)(p+0x131a8+i*4);
            if(value>=0)fn_8022F9E4(i,value,0,1);
        }
        f32* player=(f32*)fn_8023E724(0);
        u8* camera=*(u8**)(lbl_8053AB10+0x24);
        if(!camera[0x840]) {
            camera[0x840]=1;
            *(f32*)(camera+0x84c)=player[0];*(f32*)(camera+0x844)=player[0];
            *(f32*)(camera+0x850)=player[1];*(f32*)(camera+0x848)=player[1];
            *(f32*)(camera+0x854)=lbl_80541158;
            *(f32*)(camera+0x1d4)=lbl_8054115C;
            *(f32*)(camera+0x1d8)=lbl_8054115C;
        }
    }
}

extern "C" u8 fn_802DCD0C(char*) {
    return *(u8*)(*(char**)(lbl_8053AB10 + 0x24) + 0x1E8);
}

extern "C" u8 fn_802DCD1C(char* p, const s32* direction) {
    s32 result = 0;
    if (*(u8*)(*(char**)(lbl_8053AB10 + 0x24) + 0x1E8) == 0) {
        if (direction[0] > 0)
            ++*(s32*)(p + 0x14);
        else if (direction[0] < 0)
            --*(s32*)(p + 0x14);
        else if (direction[1] > 0)
            ++*(s32*)(p + 0x18);
        else
            --*(s32*)(p + 0x18);
        fn_80231424();
        fn_801F7E88(fn_801F856C());
        fn_802D8D50(p, 1);
        fn_802D8328(p, 0, 0);
        fn_8030C928(*(void**)(lbl_8053AB10 + 0x24), (const f32*)(p + 0xCC));
        result = 1;
    }
    return result;
}

extern "C" void fn_802DCDF4(char* p) {
    fn_801F7CAC(fn_801F856C());
    fn_801F6204(fn_801F856C(), 0);
    fn_80308D0C();
    char* base = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    *(u8*)(base + 0x131DE) = 0;
    fn_8013C8CC(fn_8013C824());
    *(u8*)(p + 0xC9) = 0;
}

extern "C" u8 fn_802DCE5C(char* p, s32 value) {
    int i;
    int j;
    u32 ret = 0;
    if (*(u8*)(*(char**)(lbl_8053AB10 + 0x24) + 0x1E8) == 0) {
        *(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + 0x131EF) = 0;
        u8 v;
        if (*(u8*)(lbl_8053AAF8 + 0x7F) != 0) {
            v = *(u8*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xC8 + 0x7C);
        } else {
            v = *(u8*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xC8 + 0x7D);
        }
        u32 t = v == 1;
        if (t == 1) {
            u8 v2;
            if (*(u8*)(lbl_8053AAF8 + 0x7F) != 0) {
                v2 = *(u8*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xC8 + 0x7C);
            } else {
                v2 = *(u8*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xC8 + 0x7D);
            }
            if (v2 != 1) {
                *(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + 0x131F0) = 0;
            } else if (*(u8*)(lbl_8053AAF8 + 0x7F) != 0) {
                if (*(u8*)(lbl_8053AAF8 + 0x7E) == 1) {
                    *(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + 0x131F0) = 1;
                } else {
                    *(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + 0x131F0) = 0;
                }
            } else {
                *(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + 0x131F0) = 1;
            }
        } else {
            *(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + 0x131F0) = 0;
        }
        char* e = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + *(s32*)(p + 0x18) * 0x28;
        e += *(s32*)(p + 0x14) * 4;
        *(u32*)(e + 0x178) &= 0xFFFF0000;
        for (i = 0; i < 16; i++) {
            (*(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C))->counters308[i] = 0;
        }
        u32 b = 0;
        for (u32 w = 0; w < 32; w++, b++) {
            *(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0c) + b + 0x328) = 0xff;
            (*(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0c))->flags12F68[w] = 0;
        }
        for (i = 0; i < 8; i++) {
            ((RoomArrays*)*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C))->counts6748[i] = 0;
            for (j = 0; j < 64; j++) {
                ((RoomArrays*)*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C))->values2948[i][j] = 0;
            }
        }
        if (((s32*)value)[0] > 0) {
            *(s32*)(p + 0x14) += 1;
            *(u8*)(p + 0xC8) = 1;
        } else if (((s32*)value)[0] < 0) {
            *(s32*)(p + 0x14) -= 1;
            *(u8*)(p + 0xC8) = 2;
        } else if (((s32*)value)[1] > 0) {
            *(s32*)(p + 0x18) += 1;
            *(u8*)(p + 0xC8) = 4;
        } else {
            *(s32*)(p + 0x18) -= 1;
            *(u8*)(p + 0xC8) = 8;
        }
        if (*(u8*)(lbl_8053AAF8 + 0x7F) == 1) {
            *(s32*)(p + 0xC4) = 36000;
        } else {
            *(s32*)(p + 0xC4) = 0x2A30;
        }
        fn_80231424();
        fn_801F7E88(fn_801F856C());
        fn_802D8D50(p, 1);
        *(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + 0x131F3) = 0;
        *(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + 0x131F4) = 0;
        fn_802D8328(p, 0, 0);
        *(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + 0x131F2) = 0;
        fn_8030C9E4(*(char**)(lbl_8053AB10 + 0x24), p + 0xCC);
        ret = 1;
    }
    return (u8)ret;
}

#pragma opt_propagation off
extern "C" u8 fn_802DD3D4(char* p, s32* param_2) {
    s32 col = *(s32*)(p + 0x14);
    s32 row = *(s32*)(p + 0x18);
    u32 result = 0;
    u32 mask = 0xf;
    *(u8*)(p + 0xc9) = 0;
    if (*(u8*)(*(char**)(lbl_8053AB10 + 0x24) + 0x1e8) == 0) {
        s32 count = *(s32*)((char*)fn_801F856C() + 0x1008);
        s32 off = 0;
        for (s32 i = 0; i < count; i++) {
            char* e = *(char**)((char*)fn_801F856C() + off + 8);
            if (e != 0 && *(s32*)(e + 0x1a0) == 0x5344534d) {
                mask = *(u32*)(e + 0x90) >> 4;
                break;
            }
            off += 4;
        }
        if (*param_2 > 0) {
            col++;
            *(u8*)(p + 0xc8) = 1;
        } else if (*param_2 < 0) {
            col--;
            *(u8*)(p + 0xc8) = 2;
        } else if (param_2[1] > 0) {
            row++;
            *(u8*)(p + 0xc8) = 4;
        } else {
            row--;
            *(u8*)(p + 0xc8) = 8;
        }
        if (row >= 0 && row < 10 && col >= 0 && col < 10) {
            u8* cell = (u8*)(p + row * 10);
            u8* cell2 = cell + col;
            if (cell2[0x60] != 0xff) {
                if ((mask & *(u8*)(p + 0xc8)) != 0) {
                    result = 1;
                } else {
                    *(u8*)(p + 0xc9) = 1;
                }
            } else if ((mask & *(u8*)(p + 0xc8)) == 0) {
                *(u8*)(p + 0xc9) = 1;
            }
        }
    }
    return result;
}
#pragma opt_propagation reset
extern "C" void fn_802DD548(void) {
}

extern "C" void fn_802DD54C(char* p) {
    f32 x = *(f32*)(p + 0xf0);
    f32 y = *(f32*)(p + 0xf4);
    if (*(s32*)(lbl_8053AAF8 + 0x5c) & 2) {
        y = -y;
        x = -x;
    }
    char* q = *(char**)(lbl_8053AB10 + 0x24);
    *(f32*)(q + 0x1dc) = x;
    *(f32*)(q + 0x1e0) = y;
    *(f32*)(q + 0x1e4) = 0.0f;

    for (s32 i = 0; i < 4; i++) {
        if (fn_8023F264(i)) {
            s32 x2 = (s32)*(f32*)(p + fn_8023DE58(i) * 8 + 0xf0);
            s32 y2 = (s32)*(f32*)(p + fn_8023DE58(i) * 8 + 0xf4);
            if (*(s32*)(lbl_8053AAF8 + 0x5c) & 2) {
                y2 = -y2;
                x2 = -x2;
            }
            fn_8023CCE8(i, x2);
            fn_8023CC5C(i, y2 + (s32)*(f32*)(p + i * 4 + 0x1323c));
        }
    }

    for (s32 j = 0; j < 16; j++) {
        if (*(f32*)(p + j * 8 + 0xf0) > lbl_8053A1A8) {
            *(f32*)(p + j * 8 + 0xf0) -= lbl_8053A1A8;
            fn_80458880(lbl_8053AF80, 0x4f, -1);
        } else {
            *(f32*)(p + j * 8 + 0xf0) = 0.0f;
        }
        if (*(f32*)(p + j * 8 + 0xf4) > lbl_8053A1A8) {
            *(f32*)(p + j * 8 + 0xf4) -= lbl_8053A1A8;
            fn_80458880(lbl_8053AF80, 0x4f, -1);
        } else {
            *(f32*)(p + j * 8 + 0xf4) = 0.0f;
        }
    }

    if (*(s32*)(lbl_8053AAF8 + 0x4c) == 7) {
        bool bVar3;
        if (*(u8*)(lbl_8053AAF8 + 0x7f) == 0) {
            bVar3 = false;
        } else {
            char* t;
            char* s = *(char**)(lbl_8053AAF8 + 0x4);
            t = *(char* volatile*)(s + 0xc);
            if (*(s32*)(t + 0x4) == 9 && *(s32*)(t + 0x8) == 3) goto active;
            if (*(s32*)(*(char* volatile*)(s + 0xc) + 0x4) >= 0xd) {
active:
                bVar3 = true;
            } else {
                bVar3 = false;
            }
        }
        if (!bVar3 && *(u8*)(*(char**)(lbl_8053AB10 + 0x24) + 0x1e8) == 0) {
            fn_802D3A18(p);
        }
    }

    for (s32 i = 0; i < 4; i++) {
        if (*(u8*)(p + i + 0x1327c) == 1) {
            *(f32*)(p + i * 4 + 0x1323c) += *(f32*)(p + i * 4 + 0x1324c);
            if (*(f32*)(p + i * 4 + 0x1323c) <= 0.0f) {
                *(f32*)(p + i * 4 + 0x1323c) = 0.0f;
                *(u8*)(p + i + 0x1327c) = 0;
            }
            *(f32*)(p + i * 4 + 0x1324c) -= *(f32*)(p + i * 4 + 0x1325c);
        } else if (0.0f != *(f32*)(p + i * 4 + 0x1324c)) {
            *(f32*)(p + i * 4 + 0x1324c) += *(f32*)(p + i * 4 + 0x1326c);
            if (*(f32*)(p + i * 4 + 0x1324c) > 0.0f) {
                *(f32*)(p + i * 4 + 0x1324c) = 0.0f;
            }
        }
    }
}

extern "C" void fn_802DEE2C(void);
extern "C" void fn_802D3D48(char* p);
extern "C" void fn_802D92F0(char* p);
extern "C" void fn_802D8D50(char* p, u8 v);
extern "C" void fn_802D8328(char* p, u8 a, u8 b);
extern "C" void fn_80134D14(void* p, u8 v);
extern "C" void fn_8023F1D4(int, void*, int, int, u8);
extern "C" u32 fn_8030AAF4(s32 i);
extern "C" u8 fn_8030A308(void* a, u32 b);
extern "C" void fn_80303870(s32 i);
extern "C" void fn_80134FE0(void*,u8);
extern "C" void fn_80134FBC(void*,u8);
extern "C" u8 fn_803B8EBC(s32);
extern void* lbl_8053AD30;
extern "C" void fn_802DD808(char* p) {
    f32 spawnRank[3];
    f32 spawnGBA[3];
    JGeometry::TVec3<f32> camera;
    f32 points[3];
    int k; int j; int i;
    *(s32*)((char*)roomArrays()+0x1328C)=0;
    fn_802DEE2C();
    for(i=0;i<10;i++) for(j=0;j<80;j++) roomArrays()->roomFlags1048[i][j]=0;
    for(i=0;i<8;i++) for(j=0;j<64;j++) roomArrays()->values2948[i][j]=0;
    for(i=0;i<4;i++) for(j=0;j<128;j++) roomArrays()->flags2D48[i][j]=0;
    for(i=0;i<10;i++) for(j=0;j<10;j++){
      for(k=0;k<32;k+=4){roomArrays()->flags3548[i][j][k+0]=0;roomArrays()->flags6768[i][j][k+0]=0;roomArrays()->flags3548[i][j][k+1]=0;roomArrays()->flags6768[i][j][k+1]=0;roomArrays()->flags3548[i][j][k+2]=0;roomArrays()->flags6768[i][j][k+2]=0;roomArrays()->flags3548[i][j][k+3]=0;roomArrays()->flags6768[i][j][k+3]=0;}
      for(k=0;k<256;k++) roomArrays()->values9968[i][j][k]=0;
    }
    for(i=0;i<8;i++){
      roomArrays()->keys13068[i]=0;
      roomArrays()->positions13088[i].set(lbl_8054111C,lbl_8054111C);
      roomArrays()->owners130C8[i]=-1;
    }
    for(i=0;i<8;i++){
      roomArrays()->positions130E8[i].set(lbl_8054111C,lbl_8054111C);
      roomArrays()->owners13128[i]=-1;
      roomArrays()->positions13148[i].set(lbl_8054111C,lbl_8054111C);
      roomArrays()->owners13188[i]=-1;
    }
    for(i=0;i<16;i++) ((JGeometry::TVec2<f32>*)(p+0xF0))[i].set(lbl_8054111C,lbl_8054111C);
    fn_802D3D48(p);
    for(i=0;i<4;i++){
      u32 active=((u8)(1<<i)&*(u8*)(lbl_8053AAF8+0x82))!=0;
      if(active==1 && fn_8030A308(lbl_8053AD30,fn_8030AAF4(i))==1){
        if(*(u8*)(lbl_8053AAF8+0x7F)==0 || *(s32*)(lbl_80529DEC+0x118)!=10 || *(s32*)(lbl_80529DEC+0x11C)!=2) fn_80303870(i);
      }
      ((RoomArrays*)p)->owners131A8[i]=-1;
    }
    ((u8*)roomArrays())[0x170]=1;
    ((u8*)roomArrays())[0x171]=1;
    *(s32*)((char*)roomArrays()+0x174)=0;
    for(i=0;i<16;i+=8){((RoomArrays*)p)->flags131B8[i+0]=0;*((u8*)p+(i+0+0x131DF))=0;((RoomArrays*)p)->flags131B8[i+1]=0;*((u8*)p+(i+1+0x131DF))=0;((RoomArrays*)p)->flags131B8[i+2]=0;*((u8*)p+(i+2+0x131DF))=0;((RoomArrays*)p)->flags131B8[i+3]=0;*((u8*)p+(i+3+0x131DF))=0;((RoomArrays*)p)->flags131B8[i+4]=0;*((u8*)p+(i+4+0x131DF))=0;((RoomArrays*)p)->flags131B8[i+5]=0;*((u8*)p+(i+5+0x131DF))=0;((RoomArrays*)p)->flags131B8[i+6]=0;*((u8*)p+(i+6+0x131DF))=0;((RoomArrays*)p)->flags131B8[i+7]=0;*((u8*)p+(i+7+0x131DF))=0;}
    ((u8*)roomArrays())[0x131DE]=0;
        *(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + 0x131EF) = 0;
        u8 v;
        if (*(u8*)(lbl_8053AAF8 + 0x7F) != 0) {
            v = *(u8*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xC8 + 0x7C);
        } else {
            v = *(u8*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xC8 + 0x7D);
        }
        u32 t = v == 1;
        if (t == 1) {
            u8 v2;
            if (*(u8*)(lbl_8053AAF8 + 0x7F) != 0) {
                v2 = *(u8*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xC8 + 0x7C);
            } else {
                v2 = *(u8*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xC8 + 0x7D);
            }
            if (v2 != 1) {
                *(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + 0x131F0) = 0;
            } else if (*(u8*)(lbl_8053AAF8 + 0x7F) != 0) {
                if (*(u8*)(lbl_8053AAF8 + 0x7E) == 1) {
                    *(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + 0x131F0) = 1;
                } else {
                    *(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + 0x131F0) = 0;
                }
            } else {
                *(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + 0x131F0) = 1;
            }
        } else {
            *(u8*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + 0x131F0) = 0;
        }
    ((u8*)roomArrays())[0x131F1]=0;
    ((u8*)roomArrays())[0x131F2]=0;
    ((u8*)roomArrays())[0x131F3]=0;
    ((u8*)roomArrays())[0x131F4]=0;
    ((u8*)roomArrays())[0x131F9]=0;
    ((u8*)roomArrays())[0x131F5]=0;
    fn_80134D14(lbl_8053AAF8,0);
    fn_802D92F0(p);
    fn_802D8D50(p,0);
    for(i=0;i<4;i++){

      points[0]=lbl_8046E148[i*3];points[1]=lbl_8046E148[i*3+1];points[2]=lbl_8046E148[i*3+2];
      points[0]+=*(f32*)(p+0xCC);points[1]+=*(f32*)(p+0xD0);
      fn_8023F1D4(i,points,2,0,0);
    }
    fn_802D8328(p,1,1);
    spawnRank[0]=lbl_8054111C;spawnRank[1]=lbl_8054111C;spawnRank[2]=lbl_8054111C;Actor_CreateByID(fn_801F856C(),0x52414E4B,0,spawnRank,0,-1,-1);
    spawnGBA[0]=lbl_8054111C;spawnGBA[1]=lbl_8054111C;spawnGBA[2]=lbl_8054111C;Actor_CreateByID(fn_801F856C(),0x4742414F,0,spawnGBA,0,-1,-1);
    char* m=*(char**)(lbl_8053AB10+0x24);
    *(f32*)(m+0x154)=*(f32*)(p+0xCC);*(f32*)(m+0x158)=*(f32*)(p+0xD0);
    *(f32*)(m+0x15C)=*(f32*)(p+0xD4);*(f32*)(m+0x160)=*(f32*)(p+0xD8);
    camera.set(*(f32*)(p+0xCC),*(f32*)(p+0xD0),lbl_8054111C);
    *(JGeometry::TVec3<f32>*)(*(char**)(lbl_8053AB10+0x20)+0x2368)=camera;
    if(*(u8*)(lbl_8053AAF8+0x7F)==1) *(s32*)(p+0xC4)=36000;
    else *(s32*)(p+0xC4)=0x2A30;
    for(i=0;i<4;i++){
      *(f32*)(p+0x1323C+i*4)=lbl_8054111C;*(f32*)(p+0x1324C+i*4)=lbl_8054111C;
      *(f32*)(p+0x1325C+i*4)=lbl_8054111C;*(f32*)(p+0x1326C+i*4)=lbl_8054111C;
      *(u8*)(p+0x1327C+i)=0;
    }
    fn_80134FE0(lbl_8053AAF8,0);fn_80134FBC(lbl_8053AAF8,0);
    for(i=0;i<4;i++) *(u8*)(p+0x131D8+i)=0;
    if(*(u32*)(lbl_8050EC80+*(s32*)(lbl_8050EC80+0x10)*0xC8+0x28)&0x1000) *(u8*)(p+0x131F7)|=1;
    if(*(u32*)(lbl_8050EC80+*(s32*)(lbl_8050EC80+0x10)*0xC8+0x28)&0x20000) *(u8*)(p+0x131F7)|=2;
    if(*(u32*)(lbl_8050EC80+*(s32*)(lbl_8050EC80+0x10)*0xC8+0x28)&0x100000) *(u8*)(p+0x131F7)|=4;
    if(*(u32*)(lbl_8050EC80+*(s32*)(lbl_8050EC80+0x10)*0xC8+0x28)&0x1000000) *(u8*)(p+0x131F7)|=8;
    for(i=0;i<8;i++) if(fn_803B8EBC(i)) *(u8*)(p+0x131F8)|=(u8)(1<<i);
}

extern "C" void* fn_802DE604(void* p, s16 freeFlag) {
    if (p != 0) {
        *(void**)p = lbl_804A9950;
        if (freeFlag > 0)
            __dl__FPv(p);
    }
    return p;
}

extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void __ct__Q29JGeometry8TVec2_f_Fv();
extern const f32 lbl_80541144;
extern "C" void* fn_802DE64C(char* p) {
    *(void**)p = lbl_804A9950;
    __construct_array(p + 0xf0, (void*)__ct__Q29JGeometry8TVec2_f_Fv, 0, 8, 0x10);
    __construct_array(p + 0x13088, (void*)__ct__Q29JGeometry8TVec2_f_Fv, 0, 8, 8);
    __construct_array(p + 0x130e8, (void*)__ct__Q29JGeometry8TVec2_f_Fv, 0, 8, 8);
    __construct_array(p + 0x13148, (void*)__ct__Q29JGeometry8TVec2_f_Fv, 0, 8, 8);
    *(s32*)(p + 0x4) = 0;
    *(s32*)(p + 0x8) = 0;
    *(s32*)(p + 0x14) = 0;
    *(s32*)(p + 0x18) = 0;
    *(s32*)(p + 0x34) = 0;
    *(s32*)(p + 0x38) = 0;
    *(s32*)(p + 0x3c) = 0;
    *(s32*)(p + 0x40) = 0;
    *(s32*)(p + 0x44) = 0;
    *(s32*)(p + 0x48) = 0;
    *(s32*)(p + 0x4c) = 0;
    *(s32*)(p + 0x50) = 0;
    *(s32*)(p + 0x54) = 0;
    *(s32*)(p + 0x58) = 0;
    *(s32*)(p + 0xec) = 0;
    *(f32*)(p + 0xdc) = lbl_8054111C;
    *(f32*)(p + 0xe0) = lbl_8054111C;
    *(f32*)(p + 0xe4) = lbl_80541144;
    *(f32*)(p + 0xe8) = lbl_80541144;
    *(u8*)(p + 0x131f7) = 0;
    *(u8*)(p + 0x131f8) = 0;
    return p;
}

extern "C" bool fn_802DE764(s32 a, s32 b, s32 c) {
    if (*(u8*)(lbl_8053AAF8 + 0x7F) == 0)
        return false;
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    if (a == *(s32*)(p + 4) && b == *(s32*)(p + 8)
        && c == (u8)(p + *(s32*)(p + 0x18) * 10)[*(s32*)(p + 0x14) + 0x60])
        return true;
    return false;
}

extern "C" bool fn_802DE7CC() {
    if (*(u8*)(lbl_8053AAF8 + 0x7F) == 0)
        return false;
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    if (*(s32*)(p + 4) == 0 && *(s32*)(p + 8) == 0)
        return true;
    return false;
}

extern "C" bool fn_802DE814(void) {
    if (*(u8*)(lbl_8053AAF8 + 0x7F) == 0)
        return false;
    s32 state = *(s32*)(lbl_80529DEC + 0x118);
    if ((state == 0 && *(s32*)(lbl_80529DEC + 0x11C) == 2)
        || (state == 1 && *(s32*)(lbl_80529DEC + 0x11C) == 2)
        || (state == 2 && *(s32*)(lbl_80529DEC + 0x11C) == 2)
        || (state == 3 && *(s32*)(lbl_80529DEC + 0x11C) == 2)
        || (state == 4 && *(s32*)(lbl_80529DEC + 0x11C) == 2)
        || (state == 5 && *(s32*)(lbl_80529DEC + 0x11C) == 2)
        || (state == 6 && *(s32*)(lbl_80529DEC + 0x11C) == 2)
        || (state == 7 && *(s32*)(lbl_80529DEC + 0x11C) == 1)
        || (state == 10 && *(s32*)(lbl_80529DEC + 0x11C) == 2))
        return true;
    return false;
}

extern "C" bool fn_802DE93C() {
    if (*(u8*)(lbl_8053AAF8 + 0x7F) != 0) {
        char* p;
        char* q = *(char**)(lbl_8053AAF8 + 4);
        p = *(char**)(q + 0xC);
        if (*(s32*)(p + 4) == 4 && *(s32*)(p + 8) == 0)
            goto yes;
        p = *(char* volatile*)(q + 0xC);
        if (*(s32*)(p + 4) == 7 && *(s32*)(p + 8) == 2) {
yes:
            return true;
        }
        return false;
    }
    return false;
}

extern "C" bool fn_802DE9A0() {
    if (*(u8*)(lbl_8053AAF8 + 0x7F) != 0) {
        char* q = *(char**)(lbl_8053AAF8 + 4);
        if ((*(s32*)(*(char**)(q + 0xC) + 4) == 2 && *(s32*)(*(char**)(q + 0xC) + 8) == 3) ||
            (*(s32*)(*(u32*)(q + 0xC) + 4) == 7 && *(s32*)(*(u32*)(q + 0xC) + 8) == 1))
            return true;
        return false;
    }
    s32 index = *(s32*)(lbl_80529DEC + 0x12C) + *(s32*)(lbl_80529DEC + 0x128) * 4;
    if (index == 1 || index == 6)
        return true;
    return false;
}

extern "C" bool fn_802DEA34() {
    char* p;
    if (*(u8*)(lbl_8053AAF8 + 0x7F) != 0) {
        char* root = *(char**)(lbl_8053AAF8 + 4);
        p = *(char**)(root + 0x0C);
        if (*(s32*)(p + 4) == 6 && *(s32*)(p + 8) == 0)
            return true;
        p = *(char**)(root + (unsigned short)0x0C);
        s32 type = *(s32*)(p + 4);
        if (type == 6 && *(s32*)(p + 8) == 1)
            return true;
        if (type == 6 && *(s32*)(p + 8) == 3)
            return true;
        return false;
    }
    return false;
}

extern "C" bool fn_802DEABC() {
    if (*(u8*)(lbl_8053AAF8 + 0x7F) != 0) {
        char* p;
        char* root = *(char**)(lbl_8053AAF8 + 4);
        p = *(char**)(root + 0x0C);
        if (*(s32*)(p + 4) == 7 && *(s32*)(p + 8) == 0)
            return true;
        p = *(char**)(root + (unsigned short)0x0C);
        if (*(s32*)(p + 4) == 7 && *(s32*)(p + 8) == 2)
            return true;
        return false;
    }
    long index = *(s32*)(lbl_80529DEC + 0x12C) + *(s32*)(lbl_80529DEC + 0x128) * 4;
    if (index == 4 || index == 9)
        return true;
    return false;
}

extern "C" bool fn_802DEB58() {
    if (*(u8*)(lbl_8053AAF8 + 0x7F) == 0)
        return false;
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    if (*(s32*)(p + 4) == 3 && *(s32*)(p + 8) == 1)
        return true;
    return false;
}

extern "C" bool fn_802DEBA0() {
    char* p;
    char* root;
    if (*(u8*)(lbl_8053AAF8 + 0x7F) == 0)
        return false;
    root = *(char**)(lbl_8053AAF8 + 4);
    p = *(char* volatile*)(root + 0x0C);
    if ((*(s32*)(p + 4) == 9 && *(s32*)(p + 8) == 3) ||
        *(s32*)(*(char* volatile*)(root + 0x0C) + 4) >= 13)
        return true;
    return false;
}

extern "C" bool fn_802DEBF8() {
    if (*(u8*)(lbl_8053AAF8 + 0x7F) == 0)
        return false;
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    if (*(s32*)(p + 4) == 8 && *(s32*)(p + 8) == 3)
        return true;
    return false;
}

extern "C" void fn_802DEC40(s32 index, s32 digit, u32 value) {
    u8* p;
    u32 idx;
    char* root;
    s32 shift;
    idx = index < 8 ? 0 : index - 7;
    root = *(char**)(lbl_8053AAF8 + 4);
    p = *(u8**)(root + 0x0C);
    shift = 60 - digit * 4;
    u64 mask = (u64)15 << shift;
    RoomArrays* base = (RoomArrays*)*(u32*)(root + 0x0C);
    base->flags1048[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][idx] &= mask ^ 0xFFFFFFFFFFFFFFFFULL;
    u64 bits = (u64)value << shift;
    base = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    base->flags1048[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][idx] |= bits;
}

#pragma opt_propagation off
extern "C" u32 fn_802DED40(s32 index, s32 digit) {
    s32 idx;
    char* p;
    char* root;
    s32 shift;
    idx = index < 8 ? 0 : index - 7;
    shift = 60 - digit * 4;
    root = *(char* volatile*)(lbl_8053AAF8 + 4);
    p = *(char* volatile*)(root + 0x0C);
    u64 mask = (u64)15 << shift;
    RoomArrays* rooms = *(RoomArrays**)(root + (unsigned short)0x0C);
    u64 value = rooms->flags1048[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][idx];
    return (mask & value) >> shift;
}
#pragma opt_propagation reset
extern "C" u8 fn_802DEDFC(s32 value) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    return fn_802DCE5C(p, value);
}

extern "C" void fn_802DEE2C(void) {
    for (s32 i = 0; i < 10; i++) {
        for (s32 j = 0; j < 10; j++) {
            roomArrays()->flags178[i][j] = 0;
            roomArrays()->masks3C8[0][i][j] = 0;
            roomArrays()->masks3C8[1][i][j] = 0;
            roomArrays()->masks3C8[2][i][j] = 0;
            roomArrays()->masks3C8[3][i][j] = 0;
        }
    }
    for (s32 i = 0; i < 32; i++) {
        roomArrays()->counters308[i] = 0;
        roomArrays()->values328[i] = 255;
        roomArrays()->flags12F68[i] = 0;
        roomArrays()->flags12FE8[i] = 0;
    }
    for (s32 i = 0; i < 8; i++) {
        for (s32 j = 0; j < 4; j++) roomArrays()->flags348[i][j] = 0;
    }
    for (s32 i = 0; i < 8; i++) roomArrays()->counts6748[i] = 0;
    for (s32 i = 0; i < 10; i++) {
        for (s32 j = 0; j < 10; j++) {
            for (int k = 0; k < 32; k++) roomArrays()->flagsFD68[i][j][k] = 0;
        }
    }
}

extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __register_global_object(void*, void*, void*);
extern "C" char lbl_804D4068[];
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
void __sinit_tu_802D39B8_cpp() {}

// Keep regional definitions that were present before source-tree consolidation.
#if defined(VERSION_G4SP01)
extern "C" void fn_802E0BD0(char* p)
{
    if (lbl_8053AAF8[0x7f] == 1) {
        if (fn_801365A8() == 1 && fn_80045948() != 1) {
            *(int*)(p + 0xc4) = 30000;
        } else {
            *(int*)(p + 0xc4) = 36000;
        }
    } else {
        if (fn_801365A8() == 1 && fn_80045948() != 1) {
            *(int*)(p + 0xc4) = 9000;
        } else {
            *(int*)(p + 0xc4) = 10800;
        }
    }
}
#endif
