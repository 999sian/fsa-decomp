// TU 0x80207548-0x80207d84.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"
#include "Game/ItemBase.h"
#include "Game/Actor.h"

extern "C" void detach__5ActorFv(void* this_);
extern int __float_epsilon[];

class ActorV19 : public Actor {
public:
    virtual u8 v19(s32 a, f32* b);
};

static inline f32 blkInvSqrt(f32 x) {
    if (x <= 0.0f) {
        return x;
    }
    f32 y = __frsqrte(x);
    y = 0.5f * y * (3.0f - (x * (y * y)));
    return y;
}

// ---- fn_80207548_dtor.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A5B28[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_80207548(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A5B28;
        if (this_ != 0) {
            *(void**)p = lbl_804A4808;
            if (p + 0x270 != 0) {
                if (p + 0x294 != 0) {
                    *(void**)(p + 0x294) = lbl_8049CC34;
                }
            }
            __dt__5ActorFv(this_, 0);
        }
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* mgr, s32 id);
extern "C" s32 fn_801CB434(s32 a, f32* b, s32 c);
extern "C" s32 fn_8023DE58(s32 i);
extern "C" f32* fn_8023E724(s32 i);
extern "C" void fn_802075D8(void* this_, u16 idx) {
    struct V3c { f32 x, y, z; };
    char* p = (char*)this_;
    s32 i = idx;
    s32 off = i * 0x24;
    u8 ok = 1;

    *(u8*)(p + off + 0x2d0) = 1;
    if (0 != i && *(u8*)(p + 0x2d0) == 0) {
        ok = 0;
    }
    if (1 != i && *(u8*)(p + 0x2f4) == 0) {
        ok = 0;
    }
    if (2 != i && *(u8*)(p + 0x318) == 0) {
        ok = 0;
    }
    if (3 != i && *(u8*)(p + 0x33c) == 0) {
        ok = 0;
    }
    if (*(u8*)(p + 0x2a8) != 0 && (*(u8*)(p + 0x2a9) & (1 << i))) {
        V3c v = *(V3c*)(p + 0xc);
        Actor* obj = (Actor*)fn_801F666C(fn_801F856C(), *(s32*)(p + off + 0x2b0));
        if (obj != 0) {
            v.x = obj->field_0C.x;
            v.y = obj->field_0C.y;
            v.z = obj->field_0C.z;
        }
        s32 id = fn_801CB434(*(s32*)(p + 4), (f32*)&v, 1);
        s32 kind = *(s32*)(p + off + 0x2b8);
        if (kind >= 0 && kind < 4 && *(s32*)(p + 4) == fn_8023DE58(kind)) {
            if (((ActorV19*)this_)->v19(*(s32*)(p + 4), (f32*)&v)) {
                Actor* a = (Actor*)fn_801F666C(fn_801F856C(), id);
                if (a != 0) {
                    f32 dy = fn_8023E724(kind)[1] - v.y;
                    f32 dx = fn_8023E724(kind)[0] - v.x;
                    f32 len2 = dx * dx + dy * dy;
                    if (len2 > 32.0f * *(f32*)__float_epsilon) {
                        f32 inv = blkInvSqrt(len2);
                        dx = dx * inv;
                        dy = dy * inv;
                    }
                    dx = dx * 2.0f;
                    dy = dy * 2.0f;
                    Vec n;
                    n.x = dx;
                    n.y = dy;
                    n.z = a->field_3C.z;
                    a->field_3C = n;
                }
            }
        }
    }
    if (ok) {
        detach__5ActorFv(this_);
    }
}

// ---- small members ----
class Obj_80207548 : public ItemBase {
public:
    virtual void v39();
    virtual void v40();
};

extern "C" {
void fn_80207A60(void* this_) {
    char* p = (char*)this_;
    if (*(u8*)(p + 0x2aa) != 0) {
        (*(u8*)(p + 0x2aa))--;
        if (*(u8*)(p + 0x2aa) == 0 && *(u8*)(p + 0x2a8) == 0) {
            ((Obj_80207548*)this_)->v39();
        }
    }
}

void fn_80207AB8(void) {}

void fn_80207ABC(void) {}

struct V3_80207548 { f32 x, y, z; };

struct Entry_80207548 {
    s32 m00;
    u8 m04;
    s32 m08;
    s32 m0C;
    f32 m10[3];
    s32 m1C;
    u8 m20;
    void set(s32 a, s32 b, const f32* pos, s32 c) {
        m04 = 1;
        m08 = a;
        m0C = b;
                  *(V3_80207548*)m10 = *(const V3_80207548*)pos;
        m1C = c;
    }
};

Entry_80207548* fn_80207B2C(Entry_80207548* e) {
    e->m00 = -1;
    e->m04 = 0;
    e->m08 = -1;
    e->m0C = 0;
    e->m10[0] = 0.0f;
    e->m10[1] = 0.0f;
    e->m10[2] = 0.0f;
    e->m1C = 0;
    e->m20 = 0;
    return e;
}
}

extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_801D0F40(void* this_);

extern "C" void* fn_80207AC0(char* p) {
    fn_801D0F40(p);
    *(void**)p = lbl_804A5B28;
    *(u8*)(p + 0x2a8) = 0;
    *(u8*)(p + 0x2a9) = 0;
    *(u8*)(p + 0x2aa) = 0;
    *(u32*)(p + 0x2ac) = 0;
    __construct_array(p + 0x2b0, (void*)fn_80207B2C, 0, 0x24, 4);
    return p;
}

extern "C" s32 fn_80138A30(void* mgr);
extern "C" s32 fn_801CD664(s32 n);
extern char* lbl_8053AAF8;
extern const u8 lbl_8053F8C8[4];

struct Layout_80207548 {
    u8 pad[0x2b0];
    Entry_80207548 entries[4];
};

extern "C" void fn_80207830(char* p, u16 idx, s32 a, s32 b, f32* pos, s32 c) {
    Layout_80207548* lo = (Layout_80207548*)(p + idx * 0x24);
    if (lo->entries[0].m04 != 0) {
        return;
    }
    lo->entries[0].m04 = 1;
    lo->entries[0].m08 = a;
    f32 x = pos[0];
    f32 y = pos[1];
    lo->entries[0].m0C = b;
    f32 z = pos[2];
    lo->entries[0].m10[0] = x;
    lo->entries[0].m10[1] = y;
    lo->entries[0].m10[2] = z;
    lo->entries[0].m1C = c;
    Layout_80207548* o = (Layout_80207548*)p;
    bool noneSet = true;
    bool allSet = true;
    for (int i = 0; i < 4; i++) {
        if (i != idx) {
            if (o->entries[i].m04 != 0) {
                noneSet = false;
            } else {
                allSet = false;
            }
        }
    }
    if (noneSet) {
        *(u8*)(p + 0x2aa) = lbl_8053F8C8[fn_80138A30(lbl_8053AAF8) - 1];
    } else if (allSet && *(u8*)(p + 0x2aa) != 0) {
        s32 n = 1;
        *(u8*)(p + 0x2a8) = 1;
        switch (fn_80138A30(lbl_8053AAF8)) {
        case 3:
            n = 2;
            break;
        case 4:
            n = 3;
            break;
        }
        s32 pool[4];
        pool[0] = 0;
        pool[1] = 1;
        pool[2] = 2;
        pool[3] = 3;
        s32 remaining = 4;
        for (int i = 0; i < n; i++) {
            s32 v = pool[fn_801CD664(remaining)];
            *(u8*)(p + 0x2a9) |= 1 << v;
            bool found = false;
            for (int j = 0; j < remaining; j++) {
                if (!found) {
                    if (v == pool[j]) {
                        found = true;
                    }
                } else {
                    pool[j - 1] = pool[j];
                }
            }
            if (found) {
                remaining--;
            }
        }
        ((Obj_80207548*)p)->v40();
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
