#include "types.h"
#include "Game/SinitPoolChain.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"
#include <float.h>

typedef JGeometry::TVec3<f32> Vec3f;

extern "C" void* GetCurrentSlotPtr(void* thisPtr);
extern "C" u8 fn_800FD894(void* ring, s32 id, u8* buf, s32 n);
extern "C" u8 fn_800FD5E8(void* ring, u8 i);
extern "C" u8 fn_800FD4C0(void* ring, u8 a, u8 b);
extern "C" s32 fn_800FE25C(void* ring, u8 i);
extern "C" Vec3f fn_800FE294(void* ring, u8 i);
extern "C" u8 fn_801CCBD0(const void* pos, s32 room);
extern "C" u8 fn_801CCB1C(const void* pos, s32 room);
extern "C" u8 fn_801CF888(void* this_, void* a, void* b, s32 room);
extern "C" u8 fn_801CAEF4(char* this_, void* p, s32 room);
extern "C" s32 fn_801C976C(char* this_);
extern "C" s32 fn_801CD664(s32 n);
extern "C" void* lbl_8053AAF8;
extern "C" f32 lbl_8053F080;
extern "C" f32 lbl_8053F084;
extern "C" f32 lbl_8053F088;
extern "C" f32 lbl_8053F08C;
extern "C" f32 lbl_8053F090;
extern "C" f32 lbl_8053F094;
extern "C" f32 lbl_8053F098;

static inline void tu801D3320_setCur(char* this_, u8 i) {
    u8* s = (u8*)GetCurrentSlotPtr(this_ + 0x358);
    if (i < s[2]) {
        s[3] = i;
    }
}

static inline u8 tu801D3320_isFreeAt(const Vec3f& pos, s32 room) {
    u8 ok = 1;
    if (fn_801CCBD0(&pos, room) || fn_801CCB1C(&pos, room)) {
        ok = 0;
    }
    return ok;
}

static inline u8 tu801D3320_isFree(Vec3f* pos, s32 room) {
    u8 ok = 1;
    if (fn_801CCBD0(pos, room) || fn_801CCB1C(pos, room)) {
        ok = 0;
    }
    return ok;
}

static inline u8 tu801D3320_farthest2(char* this_, u8* ids) {
    u8 n = fn_800FD894(GetCurrentSlotPtr(this_ + 0x358), *(s32*)(this_ + 0x4), ids, 0x30);
    u8 best = 0;
    f32 bestD = lbl_8053F080;
    for (int i = 0; i < n; i++) {
        if (fn_800FD5E8(GetCurrentSlotPtr(this_ + 0x358), ids[i])) {
            Vec3f p;
            p.set(fn_800FE294(GetCurrentSlotPtr(this_ + 0x358), ids[i]));
            if (tu801D3320_isFree(&p, *(s32*)(this_ + 0x4))) {
                f32 dx = p.x - *(f32*)(this_ + 0xc);
                f32 dy = p.y - *(f32*)(this_ + 0x10);
                f32 dx2 = dx * dx;
                f32 dy2 = dy * dy;
                f32 d = dx2 + dy2;
                if (d > bestD) {
                    bestD = d;
                    best = ids[i];
                }
            }
        }
    }
    return best;
}

static inline u8 tu801D3320_collect2(char* this_, u8* ids, u8* out) {
    u8 n = fn_800FD894(GetCurrentSlotPtr(this_ + 0x358), *(s32*)(this_ + 0x4), ids, 0x30);
    u8 count = 0;
    for (int i = 0; i < n; i++) {
        s32 room = *(s32*)(this_ + 0x4);
        if (tu801D3320_isFreeAt(fn_800FE294(GetCurrentSlotPtr(this_ + 0x358), ids[i]), room)) {
            count++;
            *out++ = ids[i];
        }
    }
    return count;
}

static inline u8 tu801D3320_farthest(char* this_, u8* ids, u8 n) {
    u8 best = 0;
    f32 bestD = lbl_8053F080;
    for (int i = 0; i < n; i++) {
        if (fn_800FD5E8(GetCurrentSlotPtr(this_ + 0x358), ids[i])) {
            Vec3f p;
            p.set(fn_800FE294(GetCurrentSlotPtr(this_ + 0x358), ids[i]));
            if (tu801D3320_isFree(&p, *(s32*)(this_ + 0x4))) {
                f32 dx = p.x - *(f32*)(this_ + 0xc);
                f32 dy = p.y - *(f32*)(this_ + 0x10);
                f32 dx2 = dx * dx;
                f32 dy2 = dy * dy;
                f32 d = dx2 + dy2;
                if (d > bestD) {
                    bestD = d;
                    best = ids[i];
                }
            }
        }
    }
    return best;
}

static inline u8 tu801D3320_collect(char* this_, u8* ids, u8 n, u8* out) {
    u8 count = 0;
    for (int i = 0; i < n; i++) {
        s32 room = *(s32*)(this_ + 0x4);
        if (tu801D3320_isFreeAt(fn_800FE294(GetCurrentSlotPtr(this_ + 0x358), ids[i]), room)) {
            count++;
            *out++ = ids[i];
        }
    }
    return count;
}

static inline u8 tu801D3320_contains(u8 id, u8* list, int n) {
    u8 found = 0;
    for (int i = 0; i < n; i++) {
        if (id == list[i]) {
            found = 1;
            break;
        }
    }
    return found;
}

static inline f32 tu801D3320_invSqrt(f32 x) {
    if (x <= lbl_8053F084) {
        return x;
    }
    f32 y = __frsqrte(x);
    y = lbl_8053F094 * y * (lbl_8053F098 - x * (y * y));
    return y;
}

static inline void tu801D3320_normalize(Vec3f& v) {
    f32 sq = v.squared();
    if (sq <= lbl_8053F088 * FLT_EPSILON) {
        return;
    }
    v.scale(tu801D3320_invSqrt(sq));
}

extern "C" void fn_801D3320(char* this_) {
    u8 free[0x30];
    u8 ids[0x30];
    u8 ids2[0x30];
    if (*(u32*)(this_ + 0x230) & 0x2000000) {
        u8 n = fn_800FD894(GetCurrentSlotPtr(this_ + 0x358), *(s32*)(this_ + 0x4), ids, 0x30);
        u8 best = tu801D3320_farthest(this_, ids, n);
        tu801D3320_setCur(this_, best);
        ((Vec3f*)(this_ + 0x32c))->set(fn_800FE294(GetCurrentSlotPtr(this_ + 0x358), 0xff));
        return;
    }

    u8 n = fn_800FD894(GetCurrentSlotPtr(this_ + 0x358), *(s32*)(this_ + 0x4), ids2, 0x30);
    u8 count = tu801D3320_collect(this_, ids2, n, free);
    int cnt = count;
    u8 sel = free[fn_801CD664(cnt)];
    tu801D3320_setCur(this_, sel);
    ((Vec3f*)(this_ + 0x32c))->set(fn_800FE294(GetCurrentSlotPtr(this_ + 0x358), 0xff));
    if (count == 1) {
        return;
    }
    u8 next = fn_801C976C(this_);
    s32 room = *(s32*)(this_ + 0x4);
    if (room != fn_800FE25C(GetCurrentSlotPtr(this_ + 0x358), next)) {
        return;
    }
    if (!tu801D3320_contains(next, free, cnt)) {
        return;
    }
    Vec3f cur;
    cur = *(Vec3f*)(this_ + 0x32c);
    Vec3f nxt;
    nxt = fn_800FE294(GetCurrentSlotPtr(this_ + 0x358), next);
    if (fn_800FD4C0(GetCurrentSlotPtr(this_ + 0x358), sel, next)) {
        if (fn_801CF888(this_, &cur, &nxt, *(s32*)(this_ + 0x4))) {
            return;
        }
    }
    Vec3f d = nxt;
    d.sub(cur);
    d.z = lbl_8053F084;
    if (d.squared() <= lbl_8053F088 * FLT_EPSILON) {
        return;
    }
    Vec3f dir = d;
    d.scale(((JMARandFast*)((u8*)lbl_8053AAF8 + 0xb4))->get_ufloat_1());
    u8 a = fn_800FD5E8(GetCurrentSlotPtr(this_ + 0x358), sel);
    u8 b = fn_800FD5E8(GetCurrentSlotPtr(this_ + 0x358), next);
    if (a) {
        if (d.squared() < lbl_8053F090) {
            d.set(dir);
            tu801D3320_normalize(d);
            d.scale(lbl_8053F088);
        }
    } else if (b) {
        f32 len = PSVECMag(&dir);
        if (PSVECMag(&d) > len - lbl_8053F088) {
            d.set(dir);
            tu801D3320_normalize(d);
            d.scale(len - lbl_8053F088);
        }
    }
    ((Vec3f*)(this_ + 0x32c))->add(d);
    if (!tu801D3320_isFree((Vec3f*)(this_ + 0x32c), *(s32*)(this_ + 0x4)) || fn_801CAEF4(this_, this_ + 0x32c, *(s32*)(this_ + 0x4))) {
        if (b) {
            ((Vec3f*)(this_ + 0x32c))->set(cur);
            return;
        }
        if (a) {
            tu801D3320_setCur(this_, next);
            ((Vec3f*)(this_ + 0x32c))->set(nxt);
            return;
        }
        ((Vec3f*)(this_ + 0x32c))->set(cur);
        if (fn_801CAEF4(this_, this_ + 0x32c, *(s32*)(this_ + 0x4))) {
            tu801D3320_setCur(this_, next);
            ((Vec3f*)(this_ + 0x32c))->set(nxt);
        }
    }
}

void __sinit_tu_801D3320_cpp(void) {}
