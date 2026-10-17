#include "types.h"
#include "JSystem/JGeometry/Vec.h"

#pragma auto_inline off

#define S32(p, off) (*(s32*)((p) + (off)))
#define U32(p, off) (*(u32*)((p) + (off)))
#define U8(p, off) (*(u8*)((p) + (off)))
#define F32(p, off) (*(f32*)((p) + (off)))
#define VEC(p, off) (*(JGeometry::TVec3<f32>*)((p) + (off)))

extern "C" {
void* fn_801F856C();
char* fn_801F666C(void*, s32);
u8 fn_801F36D4(char*, s32);
s32 fn_8022F340(u32);
bool Player_IsLinked(char*);
s32 fn_802486A0(char*);
void fn_80248FF0(char*);
void fn_8024F0E8(char*, s32);
u8 fn_80251AEC(char*, s32);
void fn_80258BBC(char*);
void fn_80259660(char*);
void fn_8025EB18(char*);
void fn_8025F698(char*, u8);
void fn_8026022C(char*);
u8 fn_802604CC(char*);
u8 fn_80260C08(char*);
void fn_80268B3C(char*);
s32 fn_80270A8C(char*);
void fn_8027221C(char*, s32);
void fn_80283D2C(char*);
u8 Player_GetField_0xce8(char*);
u8 Player_GetField_0x454(char*);
u8 fn_80241230(char*);
s32 Actor_CreateByID(void*, u32, u32, void*, u32, s32, s32);
void* fn_8023E724(s32);
void fn_8028414C(char*);
u16 fn_802265FC(JGeometry::TVec3<f32>*, s32);
}
extern const f32 lbl_80540150;
extern const f32 lbl_80540154;
extern const f32 lbl_80540180;
extern JGeometry::TVec3<f32> lbl_8046B400[];
extern char* lbl_8053AAF8;
extern JGeometry::TVec3<f32> lbl_8046B490[20];

extern "C" bool fn_8025EDD4(char* p, s32 id, const JGeometry::TVec3<f32>* pos) {
    if (S32(p, 0xd68) == id) {
        S32(p, 0xd68) = -1;
        VEC(p, 0xd78) = *pos;
        return true;
    }
    return false;
}

extern "C" void fn_8025EE0C(char* p, s32 id, const JGeometry::TVec3<f32>* pos) {
    if (S32(p, 0xd68) == id) {
        f32 x = pos->x;
        f32 y = pos->y;
        f32 z = pos->z;
        F32(p, 0x300) = x;
        F32(p, 0x304) = y;
        F32(p, 0x308) = z;
    }
}

extern "C" bool fn_8025EE34(char* p, s32 id) {
    return S32(p, 0xd68) == id;
}

extern "C" bool fn_8025EE48(char* p, s32 id) {
    bool ok;
    if ((u8)fn_80270A8C(p))
        return false;
    if ((u8)(U8(p, 0xd64) == 1) == 1)
        return false;
    if (((S32(p, 0xd70) < 0 || S32(p, 0xd70) >= 4) && S32(p, 0xd68) < 0) || U8(p, 0xd64) != 0)
        ok = true;
    else
        ok = false;
    if (!ok)
        return false;
    if (Player_GetField_0xce8(p))
        return false;
    if (fn_80241230(p))
        return false;
    if (Player_GetField_0x454(p))
        return false;
    if (S32(p, 0xd68) < 0 && fn_80251AEC(p, 0x19)) {
        S32(p, 0xd68) = id;
        return true;
    }
    return false;
}

extern "C" bool fn_8025EF68(char* p, s32 id) {
    if (S32(p, 0xd88) == id)
        return true;
    if (S32(p, 0xd88) >= 0)
        return false;
    char* actor = fn_801F666C(fn_801F856C(), id);
    if (actor) {
        if (fn_801F36D4(actor, S32(p, 4))) {
            S32(p, 0xd88) = id;
            return true;
        }
        return false;
    }
    return false;
}

extern "C" bool fn_8025F418(char* p) {
    if (S32(p, 0xd70) >= 0 && S32(p, 0xd70) < 4 && U8(p, 0xd64) == 0)
        return true;
    return false;
}

extern "C" bool fn_8025F448(char* p) {
    if (((S32(p, 0xd70) >= 0 && S32(p, 0xd70) < 4) || S32(p, 0xd68) >= 0) && U8(p, 0xd64) == 0)
        return true;
    return false;
}

extern "C" bool fn_8025F484(char* p) {
    if ((u8)(U8(p, 0xd64) == 1) == 1) {
        s32 id = S32(p, 0xd68);
        if (id >= 0) {
            char* actor = fn_801F666C(fn_801F856C(), id);
            if (actor && S32(actor, 0x1a4) > 0)
                return true;
            return false;
        }
    }
    return false;
}

extern "C" bool fn_8025F500(char* p) {
    if ((u8)(U8(p, 0xd64) == 1) == 1 && S32(p, 0xd68) >= 0)
        return true;
    return false;
}

extern "C" s32 fn_8025F534(char* p) {
    if (U8(p, 0xd64) != 1) {
        s32 id = S32(p, 0xd70);
        if (id >= 0 && id < 4)
            return id;
    }
    return -1;
}

extern "C" s32 fn_8025F55C(char* p) {
    if ((u8)(U8(p, 0xd64) == 1) == 1) {
        s32 id = S32(p, 0xd70);
        if (id >= 0 && id < 4)
            return id;
    }
    return -1;
}

extern "C" bool fn_8025F590(char* p) {
    if ((u8)(U8(p, 0xd64) == 1) == 1 && S32(p, 0xd70) >= 0 && S32(p, 0xd70) < 4)
        return true;
    return false;
}

extern "C" void fn_8025F5CC(char* p) {
    if (U8(p, 0xd64) != 0) {
        s32 id = S32(p, 0xd68);
        if (id >= 0) {
            char* actor = fn_801F666C(fn_801F856C(), id);
            if (actor) {
                actor[0x11c] = 0;
                U32(p, 0xd6c) = 'NULL';
                p[0xd64] = 0;
                S32(p, 0xd68) = -1;
            }
        }
    }
}

extern "C" u32 fn_8025F648(char* p) {
    if (U8(p, 0xd64) == 1)
        return U32(p, 0xd6c);
    return 'NULL';
}

extern "C" s32 fn_8025F668(char* p) {
    if (U8(p, 0xd64) == 1)
        return S32(p, 0xd68);
    return -1;
}

extern "C" int fn_8025F684(char* p) {
    return (u8)(U8(p, 0xd64) == 1);
}

extern "C" bool fn_8025FCC8(char* p) {
    s32 state = S32(p, 0x1244);
    if (state == 0x11 || (u32)(state - 0x12) <= 4 || state == 0x18 || (u32)(state - 0x1b) <= 2) {
        return false;
    }
    if (U8(p, 0xd64) == 1) {
        bool carrying = (u8)(U8(p, 0xd64) == 1) == 1 && S32(p, 0xd70) >= 0 && S32(p, 0xd70) < 4;
        if (!carrying && (u32)(state - 0x20) <= 5) {
            return false;
        }
    }
    if (S32(p, 0xd6c) == 0x4b455930 && (u32)(state - 0x1e) <= 1) {
        return false;
    }
    if (U8(p, 0xd64) == 1) {
        bool carrying = (u8)(U8(p, 0xd64) == 1) == 1 && S32(p, 0xd70) >= 0 && S32(p, 0xd70) < 4;
        if (!carrying) {
            if (state == 0x4c) {
                return false;
            }
            if (state == 0x4d) {
                return false;
            }
        }
    }
    return true;
}

extern "C" char* fn_8023E7B0(s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" char* fn_802D6A9C();
extern "C" bool fn_8025FDD0(char* p, JGeometry::TVec3<f32>* v) {
    *(JGeometry::TVec3<f32>*)(p + 0x8) = *(JGeometry::TVec3<f32>*)fn_8023E7B0(S32(p, 0xd70));
    s32 idx = fn_8023DE58(S32(p, 0xd70));
    char* r = fn_802D6A9C();
    f32* o = idx < 8 ? (f32*)(r + 0xcc) : (f32*)(r + 0xdc);
    f32 ox = o[0];
    f32 oy = o[1];
    s32 idx2 = S32(p, 0x3b4);
    r = fn_802D6A9C();
    o = idx2 < 8 ? (f32*)(r + 0xcc) : (f32*)(r + 0xdc);
    f32 x = o[0];
    f32 y = o[1];
    F32(p, 0x8) += x - ox;
    F32(p, 0xc) += y - oy;
    S32(p, 0xd70) = -1;
    S32(p, 0xd58) = 5;
    *(JGeometry::TVec3<f32>*)(p + 0xd78) = *v;
    return true;
}

extern "C" bool fn_8025FEDC(char* p) {
    u8 attached;
    if (((S32(p, 0xd70) >= 0 && S32(p, 0xd70) < 4) || S32(p, 0xd68) >= 0) && U8(p, 0xd64) == 0)
        attached = true;
    else
        attached = false;
    if (!attached)
        return false;
    fn_80251AEC(p, 0);
    f32 height = lbl_80540150;
    S32(p, 0xd70) = -1;
    bool ok = true;
    S32(p, 0xd68) = -1;
    F32(p, 0x10) = height;
    return ok;
}

extern "C" bool fn_8025FF70(char* p) {
    u8 carrying;
    if ((u8)(U8(p, 0xd64) == 1) == 1 && S32(p, 0xd70) >= 0 && S32(p, 0xd70) < 4)
        carrying = true;
    else
        carrying = false;
    if (!carrying)
        return false;
    fn_80251AEC(p, 0);
    p[0xd64] = 0;
    S32(p, 0xd70) = -1;
    U32(p, 0xd6c) = 'NULL';
    return true;
}

extern "C" void fn_8026000C(char* p) {
    fn_8025F698(p, 0);
    fn_80251AEC(p, 0);
}

extern "C" bool fn_80260048(char* p, s32 id) {
    if (!(u8)fn_80270A8C(p))
        return false;
    S32(p, 0xd70) = id;
    fn_80248FF0(p);
    return true;
}

u8 fn_8022E438(s32, u32);
s32 fn_8023DE58(u32);
s32 Player_GetLinkTargetIndex(char*);
void fn_80233F78(s32);
u8 fn_80243194(char*, s32);
void fn_80230C6C(s32);
extern "C" u8 fn_802600A0(char* p, u32 id) {
    if ((u8)fn_80270A8C(p)) {
        return 0;
    }
    if ((U8(lbl_8053AAF8, 0x82) & (u8)(1 << S32(p, 4))) == 0 && !fn_8022E438(S32(p, 4), id) &&
        (U8(lbl_8053AAF8, 0x7e) == 0 || fn_802486A0(p) != 4) &&
        (fn_8023DE58(id) != 8 || S32(p, 0x3b4) >= 8)) {
        S32(p, 0xd60) = fn_8022F340(id);
        S32(p, 0x11ec) = fn_8022F340(id);
        Actor_CreateByID(fn_801F856C(), 'TSNO', S32(p, 0x3b4), p + 8, (id & 3) | (S32(p, 4) << 2), -1, id);
        if ((s32)id > S32(p, 4)) {
            fn_80233F78(Player_GetLinkTargetIndex(p));
        }
    } else if (fn_80251AEC(p, 0x19)) {
        S32(p, 0xd70) = id;
        if (fn_802486A0(p) != 4) {
            for (s32 i = 0; i < 4; i++) {
                if (fn_80243194(p, i) && i != S32(p, 4)) {
                    fn_80230C6C(i);
                }
            }
        }
    } else {
        return 0;
    }
    fn_80248FF0(p);
    return 1;
}

extern "C" void fn_80261468(char* p) {
    if (S32(p, 0xd74) > 0)
        --S32(p, 0xd74);
}

extern "C" void fn_80261480(char* p) {
    if (S32(p, 0xc9c) > 0)
        return;
    if (S32(p, 0xd74) != 0)
        return;
    if (Player_IsLinked(p) && fn_802486A0(p) == 5)
        return;
    if (fn_80260C08(p)) {
        S32(p, 0xd74) = 3;
        p[0x1174] = 1;
    } else if (fn_802604CC(p)) {
        S32(p, 0xd74) = 3;
        p[0x1174] = 1;
    } else {
        fn_8026022C(p);
    }
}

extern "C" f32 lbl_8054017C;
extern "C" u8 lbl_8046B790[];
extern "C" f32 lbl_8046B7B0[];
extern "C" void fn_8026152C(char* p, u8 flag) {
    u8 inX = 0;
    u8 inY = 0;
    u8 inZ = 0;
    f32 eps = *(f32*)__float_epsilon * lbl_8054017C;
    f32 d = F32(p, 0x8) - F32(p, 0x14);
    if (-eps <= d && d <= eps) {
        inX = 1;
    }
    if (inX) {
        inX = 0;
        d = F32(p, 0xc) - F32(p, 0x18);
        if (-eps <= d && d <= eps) {
            inX = 1;
        }
        if (inX) {
            inY = 1;
        }
    }
    if (inY) {
        inY = 0;
        d = F32(p, 0x10) - F32(p, 0x1c);
        if (-eps <= d && d <= eps) {
            inY = 1;
        }
        if (inY) {
            inZ = 1;
        }
    }
    if (inZ) {
        if (VEC(p, 0x368).squared() <= lbl_8054017C * *(f32*)__float_epsilon) {
            U8(p, 0x3f8) = 0;
            goto done;
        }
    }
    U8(p, 0x3f8)++;
    if (flag == 0) {
        if (U8(p, 0x3f8) >= 0x18) {
            U8(p, 0x3f8) = 0;
        }
    } else if (U8(p, 0x3f8) >= 0x30) {
        U8(p, 0x3f8) = 0;
    }
done:
    if (flag == 0) {
        U8(p, 0x3f9) = ((u8*)lbl_8046B790)[U8(p, 0x3f8) / 3 + S32(p, 0x3dc) * 8];
    } else {
        U8(p, 0x3f9) = ((u8*)lbl_8046B790)[U8(p, 0x3f8) / 6 + S32(p, 0x3dc) * 8];
    }
    s32 idx = U8(p, 0x3f9) * 5;
    F32(p, 0x2f4) = ((f32*)lbl_8046B7B0)[idx] + F32(p, 0x8);
    F32(p, 0x2f8) = ((f32*)lbl_8046B7B0)[idx + 1] + F32(p, 0xc);
    F32(p, 0x2fc) = ((f32*)lbl_8046B7B0)[idx + 2] + F32(p, 0x10);
}

extern "C" void fn_8026173C(char* p) {
    p[0x121c] = 0;
    S32(p, 0xd84) = 20;
}

extern "C" void fn_80262188(char* p) {
    p[0x458] = 0;
    if (S32(p, 0x1248) != 0x33 && U8(p, 0xcfe) == 0)
        fn_8024F0E8(p, 0x10007);
    s32 id = S32(p, 0xd70);
    if (id >= 0 && U8(lbl_8053AAF8, 0x7e) != 0 &&
        !((u8)lbl_8053AAF8[0x82] & (u8)(1U << U32(p, 4))) && S32(p, 0xd60) < 0) {
        S32(p, 0x11ec) = fn_8022F340(id);
        S32(p, 0xd60) = fn_8022F340(S32(p, 0xd70));
    }
}

extern "C" void fn_80262234(char* p) {
    fn_80258BBC(p);
}

extern "C" void fn_80262B6C(char* p) {
    fn_80259660(p);
}

extern "C" void fn_80262B8C(char* p) {
    fn_80283D2C(p);
}

extern "C" void fn_80263078(char* p) {
    JGeometry::TVec3<f32> pos;
    fn_8028414C(p);
    if (U32(p, 0xd6c) == 0x4E495741 && U8(p, 0x441) == 0) {
        char* a = fn_801F666C(fn_801F856C(), S32(p, 0xd68));
        if (a != NULL && U8(a, 0x2a1) == 1) {
            s32 n = 2;
            pos.x = F32(p, 0x8);
            pos.y = F32(p, 0xc);
            do {
                if (F32(p, 0x344) > lbl_80540150) {
                    pos.x += lbl_80540154;
                } else {
                    pos.x -= lbl_80540154;
                }
                s32 id = S32(p, 0x3b4);
                char* base = fn_802D6A9C();
                if (id < 8) {
                    base += 0xcc;
                } else {
                    base += 0xdc;
                }
                if (pos.x >= F32(base, 0) || pos.y >= F32(base, 4) || pos.x >= F32(base, 8) ||
                    pos.y >= F32(base, 0xc)) {
                    break;
                }
                u16 r = fn_802265FC(&pos, S32(p, 0x3b4));
                if (r >= 0x10 && r <= 0x17) {
                    n--;
                }
            } while (n > 0);
            if (n == 0) {
                if (F32(p, 0x344) > lbl_80540150) {
                    pos.x += lbl_80540154;
                } else {
                    pos.x -= lbl_80540154;
                }
                F32(p, 0x324) = pos.x;
                F32(p, 0x328) = pos.y;
                F32(p, 0x34c) = lbl_80540180;
            } else {
                F32(p, 0x34c) = lbl_80540180;
                F32(p, 0x10) = F32(p, 0x328) - F32(p, 0xc);
                F32(p, 0xc) = F32(p, 0x328);
            }
            if (F32(p, 0x344) > lbl_80540150) {
                S32(p, 0x3dc) = 0;
                S32(p, 0x3e8) = 0;
            } else if (F32(p, 0x344) < lbl_80540150) {
                S32(p, 0x3dc) = 1;
                S32(p, 0x3e8) = 1;
            }
        }
    }
}

extern "C" void fn_802632A4(void) {}

extern "C" void fn_802635C8(char* p) {
    p[0x458] = 0;
}

extern "C" void fn_802635D4(void) {
}

extern "C" void fn_802635D8(char* p) {
    ++U8(p, 0x3fc);
    if (U8(p, 0x3fc) < 2) {
        p[0x3fd] = 2;
    } else if (U8(p, 0x3fc) < 10) {
        p[0x3fd] = 3;
    } else if (U8(p, 0x3fc) < 14) {
        p[0x3fd] = 4;
    } else {
        p[0x3fd] = 2;
        fn_80251AEC(p, 0);
    }
    const JGeometry::TVec3<f32>& pos = lbl_8046B490[S32(p, 0x3dc) * 5 + U8(p, 0x3fd)];
    f32 x = pos.x;
    f32 y = pos.y;
    F32(p, 0x2f4) = x;
    f32 z = pos.z;
    F32(p, 0x2f8) = y;
    F32(p, 0x2fc) = z;
    VEC(p, 0x2f4).add(VEC(p, 8));
    fn_8025EB18(p);
    fn_80268B3C(p);
}

extern "C" void fn_802636C4(char* p) {
    p[0x458] = 0;
}

extern "C" void fn_80263848(char* p) {
    p[0x458] = 0;
}

extern "C" void fn_80263854(char* p) {
    p[0x459] = 0;
}

extern "C" void fn_80263BA0(char* p) {
    p[0x458] = 0;
    p[0x459] = 0;
    u8 carrying;
    if ((u8)(U8(p, 0xd64) == 1) == 1 && S32(p, 0xd70) >= 0 && S32(p, 0xd70) < 4)
        carrying = true;
    else
        carrying = false;
    if (carrying) {
        fn_8027221C(p, 4);
    } else {
        char* actor = fn_801F666C(fn_801F856C(), S32(p, 0xd68));
        if (actor)
            fn_8027221C(p, S32(actor, 0x118));
        else
            fn_8027221C(p, 0);
    }
    fn_8024F0E8(p, 0x1000e);
}

extern "C" void fn_80264410(char* p) {
    p[0x458] = 0;
}

extern "C" void fn_80264768(char* p) {
    p[0x458] = 0;
}

extern "C" void fn_802636D4(char* p) {
    U8(p, 0x3fc)++;
    if (U8(p, 0x3fc) < 8) {
        U8(p, 0x3fd) = 0;
    } else if (U8(p, 0x3fc) < 10) {
        U8(p, 0x3fd) = 1;
    } else {
        U8(p, 0x3fd) = 2;
        if (fn_80251AEC(p, 0x17)) {
            u8 carrying;
            if ((u8)(U8(p, 0xd64) == 1) == 1 && S32(p, 0xd70) >= 0 && S32(p, 0xd70) < 4)
                carrying = true;
            else
                carrying = false;
            if (carrying) {
                u32 param = U32(p, 0x4) & 0xffff;
                s32 id = S32(p, 0xd70);
                void* pos = fn_8023E724(id);
                void* mgr = fn_801F856C();
                Actor_CreateByID(mgr, 0x5448434c, S32(p, 0x3b4), pos, id, -1, param);
            }
        }
    }
    const JGeometry::TVec3<f32>& pos = lbl_8046B400[S32(p, 0x3dc) * 3 + U8(p, 0x3fd)];
    f32 y = pos.y;
    f32 x = pos.x;
    F32(p, 0x2f4) = x;
    f32 z = pos.z;
    F32(p, 0x2f8) = y;
    F32(p, 0x2fc) = z;
    VEC(p, 0x2f4).add(VEC(p, 8));
    fn_8025EB18(p);
    fn_80268B3C(p);
}

#undef S32
#undef U8
#undef U32
#undef F32
#undef VEC

// Keep regional definitions that were present before source-tree consolidation.
#if defined(VERSION_G4SJ01)
extern "C" void fn_802636D0(void) {}

extern "C" void fn_802636D4(char* p) {
    U8(p, 0x3fc)++;
    if (U8(p, 0x3fc) < 8) {
        U8(p, 0x3fd) = 0;
    } else if (U8(p, 0x3fc) < 10) {
        U8(p, 0x3fd) = 1;
    } else {
        U8(p, 0x3fd) = 2;
        u8 carrying;
        if (fn_80251AEC(p, 0x17)) {
            if (U8(p, 0xd64) == 1 && S32(p, 0xd70) >= 0 && S32(p, 0xd70) < 4)
                carrying = true;
            else
                carrying = false;
        } else {
            carrying = false;
        }
        if (carrying) {
            u32 param = U32(p, 0x4) & 0xffff;
            s32 id = S32(p, 0xd70);
            void* pos = fn_8023E724(id);
            void* mgr = fn_801F856C();
            Actor_CreateByID(mgr, 0x5448434c, S32(p, 0x3b4), pos, id, -1, param);
        }
    }
    VEC(p, 0x2f4) = lbl_8046B400[U8(p, 0x3fd) + S32(p, 0x3dc) * 3];
    VEC(p, 0x2f4) += VEC(p, 0x8);
    fn_8025EB18(p);
    fn_80268B3C(p);
}

#endif
