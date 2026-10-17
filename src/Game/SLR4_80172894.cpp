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
extern "C" void* fn_802D6A9C(void);
extern Box4 lbl_804A0A58[];
extern const f32 lbl_8053DB48;

extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void* base, u32 fourCC, u32 owner, void* posPtr, s32 a, s32 b, s32 c);
extern "C" void* fn_801F666C(void* base, s32 id);
extern "C" s32 fn_8023DE58(s32 a);
extern u8 lbl_80529DEC[];
extern const f32 lbl_8053DB4C;
extern u8 lbl_8053AB60;
extern const f32 lbl_8053DAB8;
extern const f32 lbl_8053DABC;
extern const f32 lbl_8053DAC0;
extern char lbl_80466808[];
extern "C" void fn_80172BC8(void* this_);
extern "C" void fn_801F02BC(void* this_, char* name, s32 id, DrawRec* rec, s32 a, s32 b, s32 c, f32 s0, f32 s1);
extern "C" void fn_801EF574(void* a, void* b, f32* v, DrawRec* rec);
extern "C" void fn_803075AC(void*, s32, void*, s32, s32, s32, s32, s32, s32, s32);
extern "C" void v07__5ActorFv(void* this_);
extern "C" void fn_80172894(void* this_) {
    char* p = (char*)this_;
    if ((s32)(*(u32*)(p + 0x90) & 0xff) == 6) {
        *(s32*)(p + 0x18c) = 0;
        Actor_CreateByID(fn_801F856C(), 0x48415254, *(u32*)(p + 0x4), p + 0xc, 0, -1, -1);
    }
    v07__5ActorFv(this_);
}

extern "C" void fn_80174220(void* this_) {
    char* p = (char*)this_;
    s32 idx = *(s32*)(p + 0x98);
    s32 i;
    if ((u8)(*(u32*)(p + 0x90)) == 8 && *(s32*)(p + 0x23c) != 0) {
        idx += 4;
        if (idx < 4) {
        }
    }
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

extern "C" void fn_80175024(void* this_) {
    char* p = (char*)this_;
    if ((s32)(*(u32*)(p + 0x90) & 0xff) != 6) {
        s32 idx = *(s32*)(p + 0x238);
        if (idx >= 0) {
            void* obj = fn_801F666C(fn_801F856C(), idx);
            if (obj == 0) {
                s32 room = *(s32*)(p + 0x4);
                s32 a = 7;
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
                            v = *(JGeometry::TVec3f*)(p + 0xc);
                        } else {
                            s32 room = *(s32*)((char*)obj + 0x4);
                            Box4 box = *(Box4*)((char*)fn_802D6A9C() + (room < 8 ? 0xcc : 0xdc));
                            v = *(JGeometry::TVec3f*)(p + 0xc);
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
    if (*(s32*)(p + 0x4) >= 8 && *(s32*)(p + 0x23c) == 1 && *(s32*)(lbl_80529DEC + 0x118) == 6) {
        s32 cnt = 0;
        s32 i;
        for (i = 0; i < 4; i++) {
            s32 id = *(s32*)(p + 0x2c0 + i * 4);
            if (id >= 0) {
                void* a = fn_801F666C(fn_801F856C(), id);
                if (a == 0) {
                    *(s32*)(p + 0x2c0 + i * 4) = -1;
                    cnt++;
                } else {
                    *(f32*)((char*)a + 0x280) = *(f32*)(p + 0xc);
                    *(f32*)((char*)a + 0x284) = *(f32*)(p + 0x10);
                    *(f32*)((char*)a + 0x288) = *(f32*)(p + 0x14);
                    *(s32*)(p + 0x260) = 0x384;
                }
            } else {
                cnt++;
            }
        }
        if (*(s32*)(p + 0x260) == 0 && cnt == 4 && *(s32*)(p + 0x4) == fn_8023DE58(0)) {
            s32 n = 0;
            s16 rot = 0;
            for (i = 0; i < 4; i++) {
                s32 id = Actor_CreateByID(fn_801F856C(), 0x4b455448, *(u32*)(p + 0x4), p + 0xc, 4, -1, -1);
                *(s32*)(p + 0x2c0 + i * 4) = id;
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

void __sinit_SLR4_80172894_cpp(void) {
}

