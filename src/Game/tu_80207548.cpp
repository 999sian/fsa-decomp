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
    Layout_80207548* o = (Layout_80207548*)p;
    if (o->entries[idx].m04 != 0) {
        return;
    }
    o->entries[idx].set(a, b, pos, c);
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
    if (allSet) {
        *(u8*)(p + 0x2aa) = lbl_8053F8C8[fn_80138A30(lbl_8053AAF8) - 1];
    } else if (noneSet && *(u8*)(p + 0x2aa) != 0) {
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
