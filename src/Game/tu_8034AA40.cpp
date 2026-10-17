#include "types.h"
#include "Game/Actor.h"
#include "Game/SinitPoolChain.h"


extern "C" char __vt__4NWOK[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" char lbl_804720E8[];
extern "C" f32 lbl_80542518;
extern "C" f32 lbl_80542528;
extern "C" f32 lbl_8054252C;
extern "C" f32 lbl_80542530;
extern "C" f32 lbl_80542534;
extern "C" s32 lbl_80472158[];
extern "C" void* lbl_8053AED0;
extern "C" void* lbl_8053AF80;
extern "C" void fn_8043D67C(void* snd, s32 a, s32 b);
extern "C" void fn_80458508(void* obj, s32 a);
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F78F4(void* pool, u32 type, s32 afterId);
extern "C" void* fn_801F666C(void* reg, s32 id);
extern "C" void fn_801F06F0(void*, const char*, s32, f32, f32, s32, s32);
extern "C" Actor* fn_8034AA40(Actor* p, s16 n) {
    if (p) {
        *(void**)p = __vt__4NWOK;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void fn_8034AFE8(u8* p) {
    const char* str;
    s32 id;
    char* tbl = lbl_804720E8;
    switch (*(s32*)(p + 0x244)) {
    case 0:
        str = tbl + 0x7c;
        id = ((s32(*)[4])(tbl + 0x10))[*(s32*)(p + 0x23c)][*(s32*)(p + 0x238)] + 0x218;
        break;
    case 1:
        str = tbl + 0x90;
        id = ((s32(*)[2])(tbl + 0x50))[*(s32*)(p + 0x23c)][*(s32*)(p + 0x238)] + 0x2e6;
        break;
    }
    fn_801F06F0(p, str, id, lbl_80542518, lbl_80542518, 0, 0);
}

extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F78F4(void* mgr, u32 code, s32 idx);
extern "C" void* fn_801F666C(void* mgr, s32 idx);
extern "C" u8* lbl_8053AAF8;
extern "C" void fn_8034C358(void) {
    s32 list[30];
    s32 idx = -1;
    s32 count = 0;
    while (1) {
        s32 v = fn_801F78F4(fn_801F856C(), 0x4e495741, idx);
        idx = v;
        if (v < 0) break;
        if (count < 30) {
            list[count] = v;
            count++;
        }
    }
    u8* g = lbl_8053AAF8;
    *(u32*)(g + 0xb4) = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
    u32 bits = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
    void* mgr = fn_801F856C();
    f32 r = *(f32*)&bits;
    s32 n = (s32)((f32)count * (r - lbl_80542518));
    u8* p = (u8*)fn_801F666C(mgr, list[n]);
    if (p != 0) {
        p[0x2a3] = 1;
    }
}

void fn_8034C72C(void) {}

