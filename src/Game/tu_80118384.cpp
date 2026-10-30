#include "types.h"

static inline u8** copyActorPointers(u8** first, u8** last, u8** result) {
    for (; first < last;) {
        *result++ = *first++;
    }
    return result;
}
#include "JSystem/J2D/J2DPicture.h"
#include "JSystem/JUtility/JUTVideo.h"
#include "JSystem/JKernel/JKRFileLoader.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"


extern "C" void* fn_80119E5C(u8* self, s16 size);
extern "C" void* fn_8013CC50(s32 room, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
extern "C" void fn_801F856C(void);
extern "C" void fn_801F6884(void);
extern "C" void __register_global_object(void* obj, void (*dtor)(void*), void* handle);

extern "C" void* __nw__FUl(u32 size);
extern "C" void __ct__10J2DPictureFPC7ResTIMG(void* self, const void* res);
extern u8* lbl_8053AAF8;
extern u32 lbl_80539F10;

namespace JGadget {
namespace vector {
u32 extend_default(u32, u32, u32);
}
}

struct StaticVec {
    u8 m_00;
    u8 m_01;
    u8 m_02;
    s32 m_04;
    s32 m_08;
    u8 m_0c;
    s32 m_10;
    s32 m_14;
    s32 m_18;
    void* m_1c;
};

struct StaticVecAlloc {
    u8 m_00;
};

static inline void StaticVec_initVec(StaticVec* v, StaticVecAlloc alloc) {
    v->m_0c = alloc.m_00;
    v->m_10 = 0;
    v->m_14 = 0;
    v->m_18 = 0;
    v->m_1c = (void*)JGadget::vector::extend_default;
}

static inline void StaticVec_init2(StaticVec* v, const StaticVecAlloc& alloc) {
    v->m_00 = 0;
    v->m_01 = 0;
    v->m_02 = 0;
    v->m_04 = 0x13;
    v->m_08 = 0;
    StaticVec_initVec(v, alloc);
}


extern "C" StaticVec lbl_804BC540;
extern "C" char lbl_804BC534[];
extern "C" s8 lbl_8053AA92;
extern "C" u8 lbl_8053AA90;
extern "C" void fn_801192AC(u8* self, s16 param_2);
extern "C" void __register_global_object(void* obj, void (*dtor)(void*), void* handle);

extern "C" void fn_80118384(u8* self)
{
    void fn_801F856C(void);
    void fn_801F6884(void);
    fn_801F856C();
    fn_801F6884();
    self[0] = 0;
}

extern "C" void fn_801183BC(u8* self)
{
    extern s8 lbl_8053AA91;
    extern u8 lbl_804BC504[];
    extern u8 lbl_804BC4F8[];
    extern f32 lbl_8053C798;
    self[1] = 0;
    if (lbl_8053AA91 == 0) {
        lbl_804BC504[0] = 0;
        lbl_804BC504[1] = 0;
        lbl_804BC504[2] = 0;
        *(u32*)(lbl_804BC504 + 0x8) = 0;
        *(u32*)(lbl_804BC504 + 0xc) = 0;
        *(u32*)(lbl_804BC504 + 0x10) = 0;
        *(f32*)(lbl_804BC504 + 0x14) = lbl_8053C798;
        *(f32*)(lbl_804BC504 + 0x18) = lbl_8053C798;
        *(u32*)(lbl_804BC504 + 0x1c) = 0;
        *(u32*)(lbl_804BC504 + 0x20) = 0;
        *(u32*)(lbl_804BC504 + 0x24) = 0;
        *(u32*)(lbl_804BC504 + 0x28) = 0;
        *(u32*)(lbl_804BC504 + 0x2c) = 0;
        __register_global_object(lbl_804BC504, (void (*)(void*))fn_80119E5C, lbl_804BC4F8);
        lbl_8053AA91 = 1;
    }
    lbl_804BC504[1] = 0;
}

extern "C" void fn_80118454(u8* self)
{
    extern s8 lbl_8053AA91;
    extern u8 lbl_804BC504[];
    extern u8 lbl_804BC4F8[];
    extern f32 lbl_8053C798;
    self[1] = 1;
    if (lbl_8053AA91 == 0) {
        lbl_804BC504[0] = 0;
        lbl_804BC504[1] = 0;
        lbl_804BC504[2] = 0;
        *(u32*)(lbl_804BC504 + 0x8) = 0;
        *(u32*)(lbl_804BC504 + 0xc) = 0;
        *(u32*)(lbl_804BC504 + 0x10) = 0;
        *(f32*)(lbl_804BC504 + 0x14) = lbl_8053C798;
        *(f32*)(lbl_804BC504 + 0x18) = lbl_8053C798;
        *(u32*)(lbl_804BC504 + 0x1c) = 0;
        *(u32*)(lbl_804BC504 + 0x20) = 0;
        *(u32*)(lbl_804BC504 + 0x24) = 0;
        *(u32*)(lbl_804BC504 + 0x28) = 0;
        *(u32*)(lbl_804BC504 + 0x2c) = 0;
        __register_global_object(lbl_804BC504, (void (*)(void*))fn_80119E5C, lbl_804BC4F8);
        lbl_8053AA91 = 1;
    }
    lbl_804BC504[1] = 1;
}

extern "C" BOOL fn_801184F0(u8* self, u8 arg)
{
    extern u8 lbl_804BC504[];
    extern u8 lbl_804BC4F8[];
    extern s8 lbl_8053AA91;
    extern const f32 lbl_8053C798;
    u8** dst;
    u8** src;
    u8** end;
    u8** it;
    u32 count;
    u32 n;

    fn_801F856C();
    fn_801F6884();
    self[0] = 0;
    if (arg != 0) {
        if (lbl_8053AA91 == 0) {
            lbl_804BC504[0] = 0;
            lbl_804BC504[1] = 0;
            lbl_804BC504[2] = 0;
            *(u32*)(lbl_804BC504 + 0x8) = 0;
            *(u32*)(lbl_804BC504 + 0xc) = 0;
            *(u32*)(lbl_804BC504 + 0x10) = 0;
            *(f32*)(lbl_804BC504 + 0x14) = lbl_8053C798;
            *(f32*)(lbl_804BC504 + 0x18) = lbl_8053C798;
            *(u32*)(lbl_804BC504 + 0x1c) = 0;
            *(u32*)(lbl_804BC504 + 0x20) = 0;
            *(u32*)(lbl_804BC504 + 0x24) = 0;
            *(u32*)(lbl_804BC504 + 0x28) = 0;
            *(u32*)(lbl_804BC504 + 0x2c) = 0;
            __register_global_object(lbl_804BC504, (void (*)(void*))fn_80119E5C, lbl_804BC4F8);
            lbl_8053AA91 = 1;
        }
        lbl_804BC504[0] = 0;
        lbl_804BC504[1] = 0;
        lbl_804BC504[2] = 0;
        *(u32*)(lbl_804BC504 + 0x4) = 0;
        *(u32*)(lbl_804BC504 + 0x8) = 0;
        *(u32*)(lbl_804BC504 + 0xc) = 0;
        *(f32*)(lbl_804BC504 + 0x14) = lbl_8053C798;
        *(f32*)(lbl_804BC504 + 0x18) = lbl_8053C798;
        *(u32*)(lbl_804BC504 + 0x1c) = 0;
        *(u32*)(lbl_804BC504 + 0x20) = 0;
        *(u32*)(lbl_804BC504 + 0x24) = 0;
        *(u32*)(lbl_804BC504 + 0x28) = 0;
        *(u32*)(lbl_804BC504 + 0x10) = 0;
    }
    end = src = *(u8***)(self + 0x14);
    dst = *(u8***)(self + 0x10);
    count = ((u32)end + 3 - (u32)src) >> 2;
    if ((u32)src < (u32)end) {
        if ((n = count >> 3) != 0) {
            do {
                dst[0] = src[0];
                dst[1] = src[1];
                dst[2] = src[2];
                dst[3] = src[3];
                dst[4] = src[4];
                dst[5] = src[5];
                dst[6] = src[6];
                dst[7] = src[7];
                src += 8;
                dst += 8;
            } while (--n != 0);
        }
        n = count & 7;
        while (n != 0) {
            *dst++ = *src++;
            n--;
        }
    }
    for (it = dst; it != *(u8***)(self + 0x14); it++) {
    }
    *(u8***)(self + 0x14) = dst;
    self[0] = 0;
    self[1] = 0;
    self[2] = 0;
    *(u32*)(self + 0x4) = 0x13;
    *(u32*)(self + 0x8) = 0;
    return 1;
}

extern "C" BOOL fn_801186B0(u8* self, u32 param)
{
    void fn_801F856C(void);
    int fn_801F68E0(void);
    fn_801F856C();
    if (fn_801F68E0() != 0) {
        self[0] = 1;
        self[1] = 0;
        self[2] = 0;
        *(u32*)(self + 0x4) = param;
        *(u32*)(self + 0x8) = 0;
        return 1;
    }
    return 0;
}

extern "C" u8** fn_8011871C(u8* self, u8** param_2, u32 param_3)
{
    u8** begin = *(u8***)(self + 0x10);
    u8** end;
    u32 count;
    u8** it;
    if (begin == 0) count = 0;
    else count = ((int)*(u8***)(self + 0x14) - (int)begin) / 4;
    if (count == 0) return *(u8***)(self + 0x14);
    end = *(u8***)(self + 0x14);
    if (param_2 == end) return end;
    volatile u32 values[2];
    values[0] = param_3;
    values[1] = param_3;
    it = param_2;
    goto cond;
inc:
    it++;
cond:
    if (it == end) goto done;
    if (param_3 == *(u32*)(*it + 0x1a0)) goto done;
    goto inc;
done:
    return it;
}

extern "C" void fn_80118798(u8* self, u8* param_2)
{
    s32 key = *(s32*)(param_2 + 0x198);
    volatile s32 v[2];
    u8** it;
    u8** end = *(u8***)(self + 0x14);

    v[0] = key;
    it = *(u8***)(self + 0x10);
    v[1] = key;
    while (it != end && key != *(s32*)(*it + 0x198)) {
        it++;
    }
    if (it == end) {
        return;
    }
    for (u8** src = it + 1; src < end; src++) {
        *it++ = *src;
    }
    for (u8** p = it; p != *(u8***)(self + 0x14); p++) {
    }
    *(u8***)(self + 0x14) = it;
}

extern "C" void fn_8011888C(u8* self, u32 val)
{
    u32 local = val;
    void fn_801188B8(u8* self, u32* ptr);
    fn_801188B8(self + 0xc, &local);
}

extern "C" void fn_801188B8(u8* self, void* ptr)
{
    u32* fn_801188E0(u8* self, u32 p, void* q);
    fn_801188E0(self, *(u32*)(self + 8), ptr);
}

extern "C" u32* fn_801188E0(u8* self, u32 p, void* q)
{
    void fn_80118938(u8* self, u32 unused, u32 count, void* src);
    s32 idx = ((s32)p - *(s32*)(self + 4)) / 4;
    fn_80118938(self, p, 1, q);
    return *(u32**)(self + 4) + idx;
}

extern "C" void fn_80118938(u8* self, u32 unused, u32 count, void* src)
{
    u32* fn_801189B0(void);
    if (count != 0) {
        u32* dst = fn_801189B0();
        if (dst != *(u32**)(self + 8)) {
            u32 val = *(u32*)src;
            while (count != 0) {
                if (dst != 0) {
                    *dst = val;
                }
                dst++;
                count--;
            }
        }
    }
}

extern "C" void __dl__FPv(void*);
extern "C" u32* fn_801189B0(u8* selfArg, void* positionArg, u32 amountArg) {
    u8* self = selfArg;
    u32 amount = amountArg;
    u32 capacity;
    u32* position = (u32*)positionArg;
    u32* result;
    u32 needed;
    u32* buffer;
    register u32* first;
    u32* last;
    register u32* src;
    register u32* dst;
    u32* split;
    u32* it;
    u32* volatile guard;
    u8* volatile owner;
    if (amount == 0) return position;
    first = *(u32**)(self + 4);
    needed = first == 0 ? 0 : ((s32)*(u32**)(self + 8) - (s32)first) / 4;
    if (amount + needed <= *(u32*)(self + 0xc)) {
        last = *(u32**)(self + 8);
        split = position + amount;
        if (split < last) {
            src = last - amount;
            dst = last;
            u32* end = last;
            u32* start = src;
            while (src < end) *dst++ = *src++;
            src = start;
            dst = *(u32**)(self + 8);
            while (src > position) *--dst = *--src;
            for (it = position; it != split; ++it) {}
            *(u32**)(self + 8) += amount;
            return position;
        } else {
            src = position;
            dst = split;
            while (src < last) *dst++ = *src++;
            for (it = position; it != *(u32**)(self + 8); ++it) {}
        }
        *(u32**)(self + 8) += amount;
        return position;
    }
    needed = first == 0 ? 0 : ((s32)*(u32**)(self + 8) - (s32)first) / 4;
    u32 newSize = needed + amount;
    capacity = ((u32(*)(u32,u32,u32))*(void**)(self + 0x10))(*(u32*)(self + 0xc), needed, amount);
    capacity = newSize > capacity ? newSize : capacity;
    buffer = (u32*)__nw__FUl(capacity * 4);
    if (buffer == 0) return *(u32**)(self + 8);
    src = *(u32**)(self + 4);
    dst = buffer;
    owner = self;
    guard = buffer;
    while (src < position) *dst++ = *src++;
    result = dst;
    src = position;
    dst += amount;
    last = *(u32**)(self + 8);
    while (src < last) *dst++ = *src++;
    first = *(u32**)(self + 4);
    last = *(u32**)(self + 8);
    for (it = first; it != last; ++it) {}
    guard = first;
    *(u32**)(self + 8) = buffer + (amount + (((s32)*(u32* volatile*)(self + 8) - (s32)*(u32* volatile*)(self + 4)) / 4));
    *(u32**)(self + 4) = buffer;
    *(u32*)(self + 0xc) = capacity;
    __dl__FPv(first);
    return result;
}

extern "C" void fn_80118E20(u8* self)
{
    extern u8* lbl_8053AED0;
    extern u32 lbl_8053AB10;
    extern f32 lbl_8053C79C;
    extern const f32 lbl_8053C798;
    extern u8 lbl_804BC504[];
    extern u8 lbl_804BC4F8[];
    extern s8 lbl_8053AA91;
    struct VElem {
        virtual void v00(void);
        virtual void v01(void);
        virtual void v02(void);
        virtual void v03(void);
        virtual void v04(void);
        virtual void v05(void);
        virtual void v06(void);
        virtual void v07(void);
        virtual void v08(void);
        virtual void v09(void);
        virtual void v10(void);
        virtual void v11(void);
        virtual void v12(void);
        virtual void v13(void);
        virtual void v14(void);
        virtual void v15(void);
        virtual void v16(void);
        virtual void v17(void);
        virtual void v18(void);
        virtual void v19(void);
        virtual void v20(void);
        virtual u8 v21(void);
    };
    u8 ok;
    u8** it;
    VElem* elem;
    u8 c;
    u8** dst;
    u8** src;
    u8** end;
    u32 count;
    u32 n;

    if (self[0] != 0) {
        lbl_8053AED0[0xdd] &= 0xfe;
        lbl_8053AED0[0xdd] &= ~0x02;
        lbl_8053AED0[0xdd] &= ~0x04;
        lbl_8053AED0[0xdd] &= ~0x08;
        if (self[2] != 0) {
            u8* p = *(u8**)(lbl_8053AB10 + 0x30);
            if (p[0x284] == 0) {
                p[0x284] = 1;
                *(f32*)(p + 0x28c) = 1.0f;
            }
        }
        if (self[1] == 0) {
            ok = 1;
            for (it = *(u8***)(self + 0x10); it != *(u8***)(self + 0x14); it++) {
                elem = (VElem*)*it;
                if (elem != 0) {
                    elem->v19();
                    c = elem->v21();
                    if (c == 0) {
                        ok = 0;
                    }
                }
            }
            if (ok && *(s32*)(self + 4) < 0xe) {
                fn_801F856C();
                fn_801F6884();
                self[0] = 0;
                if (lbl_8053AA91 == 0) {
                    lbl_804BC504[0] = 0;
                    lbl_804BC504[1] = 0;
                    lbl_804BC504[2] = 0;
                    *(u32*)(lbl_804BC504 + 0x8) = 0;
                    *(u32*)(lbl_804BC504 + 0xc) = 0;
                    *(u32*)(lbl_804BC504 + 0x10) = 0;
                    *(f32*)(lbl_804BC504 + 0x14) = lbl_8053C798;
                    *(f32*)(lbl_804BC504 + 0x18) = lbl_8053C798;
                    *(u32*)(lbl_804BC504 + 0x1c) = 0;
                    *(u32*)(lbl_804BC504 + 0x20) = 0;
                    *(u32*)(lbl_804BC504 + 0x24) = 0;
                    *(u32*)(lbl_804BC504 + 0x28) = 0;
                    *(u32*)(lbl_804BC504 + 0x2c) = 0;
                    __register_global_object(lbl_804BC504, (void (*)(void*))fn_80119E5C, lbl_804BC4F8);
                    lbl_8053AA91 = 1;
                }
                lbl_804BC504[0] = 0;
                lbl_804BC504[1] = 0;
                lbl_804BC504[2] = 0;
                *(u32*)(lbl_804BC504 + 0x4) = 0;
                *(u32*)(lbl_804BC504 + 0x8) = 0;
                *(u32*)(lbl_804BC504 + 0xc) = 0;
                *(f32*)(lbl_804BC504 + 0x14) = lbl_8053C798;
                *(f32*)(lbl_804BC504 + 0x18) = lbl_8053C798;
                *(u32*)(lbl_804BC504 + 0x1c) = 0;
                *(u32*)(lbl_804BC504 + 0x20) = 0;
                *(u32*)(lbl_804BC504 + 0x24) = 0;
                *(u32*)(lbl_804BC504 + 0x28) = 0;
                *(u32*)(lbl_804BC504 + 0x10) = 0;

                end = *(u8***)(self + 0x14);
                src = *(u8***)(self + 0x14);
                dst = *(u8***)(self + 0x10);
                dst = copyActorPointers(src, end, dst);
                for (it = dst; it != *(u8***)(self + 0x14); it++) {
                }
                *(u8***)(self + 0x14) = dst;
                self[0] = 0;
                self[1] = 0;
                self[2] = 0;
                *(u32*)(self + 0x4) = 0x13;
                *(u32*)(self + 0x8) = 0;
            }
            *(u32*)(self + 0x8) = *(u32*)(self + 0x8) + 1;
        }
    }
}

extern "C" void fn_801190E4(u8* self)
{
    void __dl__FPv(void* p);
    u8** volatile b;
    u8* volatile a;
    u8** begin;
    u8** end;
    u8** src;
    u8** dst;
    u8** it;
    u8** buf;
    u32 count;
    u32 n;

    if (*(u32*)(self + 0x18) >= 0x14) {
        return;
    }
    buf = (u8**)__nw__FUl(0x50);
    if (buf == 0) {
        return;
    }
    end = *(u8***)(self + 0x14);
    a = self + 0xc;
    src = *(u8***)(self + 0x10);
    dst = buf;
    count = ((u32)end + 3 - (u32)src) >> 2;
    b = buf;
    if (src < end) {
        if ((n = count >> 3) != 0) {
            do {
                dst[0] = src[0];
                dst[1] = src[1];
                dst[2] = src[2];
                dst[3] = src[3];
                dst[4] = src[4];
                dst[5] = src[5];
                dst[6] = src[6];
                dst[7] = src[7];
                src += 8;
                dst += 8;
            } while (--n != 0);
        }
        n = count & 7;
        while (n != 0) {
            *dst++ = *src++;
            n--;
        }
    }
    begin = *(u8***)(self + 0x10);
    b = begin;
    for (it = begin; it != *(u8***)(self + 0x14); it++) {
    }
    *(u8***)(self + 0x14) = buf + (((int)*(u8***)(self + 0x14) - (int)*(u8***)(self + 0x10)) / 4);
    *(u8***)(self + 0x10) = buf;
    *(u32*)(self + 0x18) = 0x14;
    __dl__FPv(begin);
}

extern "C" void* fn_8011921C(void)
{
    if (lbl_8053AA92 == 0) {
        StaticVec_init2(&lbl_804BC540, *(StaticVecAlloc*)&lbl_8053AA90);
        __register_global_object(&lbl_804BC540, (void (*)(void*))fn_801192AC, lbl_804BC534);
        lbl_8053AA92 = 1;
    }
    return &lbl_804BC540;
}

extern "C" void fn_801192AC(u8* self, s16 param_2)
{
    u8** end;
    u8** src;
    u8** dst;
    u8** it;
    s32 count;
    s32 n;

    if (self != 0) {
        dst = *(u8***)(self + 0x10);
        src = end = *(u8***)(self + 0x14);
        count = ((u32)end + 3 - (u32)src) >> 2;
        if (src < end) {
            if ((n = count >> 3) != 0) {
                do {
                    dst[0] = src[0];
                    dst[1] = src[1];
                    dst[2] = src[2];
                    dst[3] = src[3];
                    dst[4] = src[4];
                    dst[5] = src[5];
                    dst[6] = src[6];
                    dst[7] = src[7];
                    src += 8;
                    dst += 8;
                } while (--n != 0);
            }
            n = count & 7;
            while (n != 0) {
                *dst++ = *src++;
                n--;
            }
        }
        for (it = dst; it != *(u8***)(self + 0x14); it++) {
        }
        *(u8***)(self + 0x14) = dst;
        if (self + 0xc != 0) {
            dst = *(u8***)(self + 0x10);
            src = end = *(u8***)(self + 0x14);
            count = ((u32)end + 3 - (u32)src) >> 2;
            if (src < end) {
                if ((n = count >> 3) != 0) {
                    do {
                        dst[0] = src[0];
                        dst[1] = src[1];
                        dst[2] = src[2];
                        dst[3] = src[3];
                        dst[4] = src[4];
                        dst[5] = src[5];
                        dst[6] = src[6];
                        dst[7] = src[7];
                        src += 8;
                        dst += 8;
                    } while (--n != 0);
                }
                n = count & 7;
                while (n != 0) {
                    *dst++ = *src++;
                    n--;
                }
            }
            for (it = dst; it != *(u8***)(self + 0x14); it++) {
            }
            *(u8***)(self + 0x14) = dst;
        }
        __dl__FPv(*(void**)(self + 0x10));
        if (param_2 > 0) {
            __dl__FPv(self);
        }
    }
}

struct VObj {
    virtual void v00(int);
    virtual void v04(void);
    virtual void v08(int);
};

extern "C" void __dl__FPv(void* p);

extern "C" void fn_80119468(u32 a, u32 b, s32 c)
{
    void fn_80119998(u32 a, u32 b, u32 c, s32 d, u32 e, u32 f, u32 g, u32 h);
    u32 v;
    switch (c) {
    case 0:
    case 1:
        v = 0x23;
        break;
    case 2:
    default:
        v = 0x46;
        break;
    }
    fn_80119998(a, v, 0, c, 0, 2, 0, b);
}

extern "C" void fn_8013B490(u32 a);
extern u32 lbl_8053AB10;
extern const f32 lbl_8053C798;
extern u8* sManager__8JUTVideo;
extern "C" void fn_801194C4(u8* self) {
    if (self[0] != 0 && *(s32*)(self + 0x24) != 2 && lbl_8053C798 != *(f32*)(self + 0x14)) {
        fn_8013B490(lbl_8053AB10);
        switch (*(s32*)(self + 0x24)) {
        case 1:
            (*(J2DPicture**)(self + 0x2c))->setBlackWhite(JUtility::TColor(0xffffffff), JUtility::TColor(0));
            break;
        case 0:
        default:
            (*(J2DPicture**)(self + 0x2c))->setBlackWhite(JUtility::TColor(0xff), JUtility::TColor(0));
            break;
        }
        (*(J2DPicture**)(self + 0x2c))->setAlpha(*(f32*)(self + 0x14));
        (*(J2DPicture**)(self + 0x2c))->draw(0.0f, 0.0f, (int)JUTVideo::getManager()->getFbWidth(), (int)JUTVideo::getManager()->getEfbHeight(), false, false, false);
    }
}

extern "C" void fn_80119628(u8* self)
{
    extern const f32 lbl_8053C798;
    extern const f32 lbl_8053C7A0;
    extern const f32 lbl_8053C7B0;
    f32 pos[3];
    s32 state;

    state = *(s32*)(lbl_8053AAF8 + 0x4c);
    switch (state) {
    case 0x16:
    case 9:
        break;
    default:
        goto process;
    }
    return;
process:
        if (self[0] != 0) {
            if (self[1] != 0) {
                if (self[2] != 0) {
                    *(s32*)(self + 0x10) = *(s32*)(self + 0x10) - 1;
                    if (*(s32*)(self + 0x10) <= 0) {
                        self[1] = 0;
                    }
                }
            } else {
                *(s32*)(self + 0x4) = *(s32*)(self + 0x4) + 1;
                switch (*(s32*)(self + 0x1c)) {
                case 0:
                    if (self[2] != 0 && *(s32*)(self + 0x10) > 0) {
                        self[1] = 1;
                    }
                    *(f32*)(self + 0x14) = *(f32*)(self + 0x14) - *(f32*)(self + 0x18);
                    break;
                case 1:
                    *(f32*)(self + 0x14) = *(f32*)(self + 0x14) + *(f32*)(self + 0x18);
                    break;
                case 2:
                    if (*(s32*)(self + 0x24) == 2 && *(s32*)(self + 0x4) == *(s32*)(self + 0x8) / 2) {
                        pos[0] = lbl_8053C798;
                        pos[1] = lbl_8053C798;
                        pos[2] = lbl_8053C798;
                        fn_8013CC50(0, pos, 0x3ec, 0, 0, 0, 0, 1, lbl_8053C7A0);
                        fn_8013CC50(0, pos, 0x3ed, 0, 0, 0, 0, 1, lbl_8053C7A0);
                        fn_8013CC50(0, pos, 0x3ee, 0, 0, 0, 0, 1, lbl_8053C7A0);
                        fn_8013CC50(0, pos, 0x3ef, 0, 0, 0, 0, 1, lbl_8053C7A0);
                    }
                    if (*(s32*)(self + 0x4) >= *(s32*)(self + 0x8) / 2 + 1) {
                        if (self[2] != 0 && *(s32*)(self + 0x10) > 0) {
                            self[1] = 1;
                        } else {
                            *(f32*)(self + 0x14) = *(f32*)(self + 0x14) - *(f32*)(self + 0x18);
                        }
                    } else {
                        *(f32*)(self + 0x14) = *(f32*)(self + 0x14) + *(f32*)(self + 0x18);
                    }
                    break;
                }
                if (*(f32*)(self + 0x14) >= lbl_8053C7B0) {
                    *(f32*)(self + 0x14) = lbl_8053C7B0;
                } else if (*(f32*)(self + 0x14) <= lbl_8053C798) {
                    *(f32*)(self + 0x14) = lbl_8053C798;
                }
                if (*(s32*)(self + 0x4) > *(s32*)(self + 0x8)) {
                    if (self[2] != 0) {
                        if (*(s32*)(self + 0x10) <= 0) {
                            self[0] = 0;
                            self[1] = 0;
                            self[2] = 0;
                            *(u32*)(self + 0x4) = 0;
                            *(u32*)(self + 0x8) = 0;
                            *(u32*)(self + 0xc) = 0;
                            *(f32*)(self + 0x14) = lbl_8053C798;
                            *(f32*)(self + 0x18) = lbl_8053C798;
                            *(u32*)(self + 0x1c) = 0;
                            *(u32*)(self + 0x20) = 0;
                            *(u32*)(self + 0x24) = 0;
                            *(u32*)(self + 0x28) = 0;
                            *(u32*)(self + 0x10) = 0;
                        } else {
                            self[1] = 1;
                        }
                    } else {
                        self[0] = 0;
                        self[1] = 0;
                        self[2] = 0;
                        *(u32*)(self + 0x4) = 0;
                        *(u32*)(self + 0x8) = 0;
                        *(u32*)(self + 0xc) = 0;
                        *(f32*)(self + 0x14) = lbl_8053C798;
                        *(f32*)(self + 0x18) = lbl_8053C798;
                        *(u32*)(self + 0x1c) = 0;
                        *(u32*)(self + 0x20) = 0;
                        *(u32*)(self + 0x24) = 0;
                        *(u32*)(self + 0x28) = 0;
                        *(u32*)(self + 0x10) = 0;
                    }
                }
            }
        }
}

extern "C" void fn_80119958(u8* self)
{
    self[0] = 0;
    self[1] = 0;
    self[2] = 0;
    *(u32*)(self + 0x4) = 0;
    *(u32*)(self + 0x8) = 0;
    *(u32*)(self + 0xc) = 0;
    *(f32*)(self + 0x14) = 0.0f;
    *(f32*)(self + 0x18) = 0.0f;
    *(u32*)(self + 0x1c) = 0;
    *(u32*)(self + 0x20) = 0;
    *(u32*)(self + 0x24) = 0;
    *(u32*)(self + 0x28) = 0;
    *(u32*)(self + 0x10) = 0;
}

extern "C" void fn_80119998(u8* self, u32 frames, u32 b, s32 mode, u32 d, u32 e, s32 f, u32 g)
{
    extern const f32 lbl_8053C798;
    extern const f32 lbl_8053C7A0;
    extern const f32 lbl_8053C7B0;
    extern const f32 lbl_8053C7B4;

    self[0] = 1;
    self[1] = 0;
    self[2] = 0;
    *(u32*)(self + 0x4) = 0;
    *(u32*)(self + 0x8) = frames;
    *(u32*)(self + 0xc) = b;
    *(s32*)(self + 0x1c) = mode;
    *(u32*)(self + 0x20) = d;
    *(u32*)(self + 0x24) = e;
    *(u32*)(self + 0x28) = g;
    *(s32*)(self + 0x10) = f;
    if (*(s32*)(self + 0x10) > 0) {
        self[2] = 1;
    } else {
        self[2] = 0;
    }
    if (*(s32*)(self + 0x24) == 2) {
        u32 duration;
        switch(mode) {
        case 0: case 1: duration=0x23; break;
        case 2: default: duration=0x46; break;
        }
        *(u32*)(self+8)=duration;
    }
    switch (*(s32*)(self + 0x1c)) {
    case 0:
        if (*(s32*)(self + 0x24) == 2) {
            f32 pos[3];
            pos[0] = lbl_8053C798;
            pos[1] = lbl_8053C798;
            pos[2] = lbl_8053C798;
            fn_8013CC50(0, pos, 0x3ec, 0, 0, 0, 0, 1, lbl_8053C7A0);
            fn_8013CC50(0, pos, 0x3ed, 0, 0, 0, 0, 1, lbl_8053C7A0);
            fn_8013CC50(0, pos, 0x3ee, 0, 0, 0, 0, 1, lbl_8053C7A0);
            fn_8013CC50(0, pos, 0x3ef, 0, 0, 0, 0, 1, lbl_8053C7A0);
        }
        *(f32*)(self + 0x14) = lbl_8053C7B0;
        *(f32*)(self + 0x18) = lbl_8053C7B0 / (f32)(*(s32*)(self + 0x8) - 1);
        break;
    case 1:
        if (*(s32*)(self + 0x24) == 2) {
            f32 pos[3];
            pos[0] = lbl_8053C798;
            pos[1] = lbl_8053C798;
            pos[2] = lbl_8053C798;
            fn_8013CC50(0, pos, 0x3f0, 0, 0, 0, 0, 1, lbl_8053C7A0);
            fn_8013CC50(0, pos, 0x3f1, 0, 0, 0, 0, 1, lbl_8053C7A0);
            fn_8013CC50(0, pos, 0x3f2, 0, 0, 0, 0, 1, lbl_8053C7A0);
            fn_8013CC50(0, pos, 0x3f3, 0, 0, 0, 0, 1, lbl_8053C7A0);
        }
        *(f32*)(self + 0x14) = lbl_8053C798;
        *(f32*)(self + 0x18) = lbl_8053C7B0 / (f32)(*(s32*)(self + 0x8) - 1);
        break;
    case 2:
        if (*(s32*)(self + 0x24) == 2) {
            f32 pos[3];
            pos[0] = lbl_8053C798;
            pos[1] = lbl_8053C798;
            pos[2] = lbl_8053C798;
            fn_8013CC50(0, pos, 0x3f0, 0, 0, 0, 0, 1, lbl_8053C7A0);
            fn_8013CC50(0, pos, 0x3f1, 0, 0, 0, 0, 1, lbl_8053C7A0);
            fn_8013CC50(0, pos, 0x3f2, 0, 0, 0, 0, 1, lbl_8053C7A0);
            fn_8013CC50(0, pos, 0x3f3, 0, 0, 0, 0, 1, lbl_8053C7A0);
        }
        *(f32*)(self + 0x14) = lbl_8053C798;
        *(f32*)(self + 0x18) = lbl_8053C7B4 / (f32)(*(s32*)(self + 0x8) - 1);
        break;
    }
}

#pragma opt_propagation on
extern "C" void fn_80119D48(u8* self) {
    const ResTIMG* res;
    if (*(J2DPicture**)(self + 0x2c) == 0) {
        JKRFileLoader* obj = *(JKRFileLoader**)(lbl_8053AAF8 + 0xa4);
        res = (const ResTIMG*)obj->getResource(0x3f3f3f3f, (const char*)lbl_80539F10);
        *(J2DPicture**)(self + 0x2c) = new J2DPicture(res);
    }
}
#pragma opt_propagation reset
extern "C" void* fn_80119DD0(void)
{
    extern s8 lbl_8053AA91;
    extern u8 lbl_804BC504[];
    extern u8 lbl_804BC4F8[];
    if (lbl_8053AA91 == 0) {
        lbl_804BC504[0] = 0;
        lbl_804BC504[1] = 0;
        lbl_804BC504[2] = 0;
        *(u32*)(lbl_804BC504 + 0x8) = 0;
        *(u32*)(lbl_804BC504 + 0xc) = 0;
        *(u32*)(lbl_804BC504 + 0x10) = 0;
        *(f32*)(lbl_804BC504 + 0x14) = lbl_8053C798;
        *(f32*)(lbl_804BC504 + 0x18) = lbl_8053C798;
        *(u32*)(lbl_804BC504 + 0x1c) = 0;
        *(u32*)(lbl_804BC504 + 0x20) = 0;
        *(u32*)(lbl_804BC504 + 0x24) = 0;
        *(u32*)(lbl_804BC504 + 0x28) = 0;
        *(u32*)(lbl_804BC504 + 0x2c) = 0;
        __register_global_object(lbl_804BC504, (void (*)(void*))fn_80119E5C, lbl_804BC4F8);
        lbl_8053AA91 = 1;
    }
    return lbl_804BC504;
}

extern "C" void* fn_80119E5C(u8* self, s16 size)
{
    VObj* obj;
    if (self != 0) {
        obj = *(VObj**)(self + 0x2c);
        if (obj != 0 && obj != 0) {
            obj->v00(1);
        }
        *(VObj**)(self + 0x2c) = 0;
        if (size > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

extern "C" void fn_80119ED4(void)
{
}

