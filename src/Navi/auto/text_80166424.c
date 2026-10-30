

#include "types.h"

struct Link_80167A94 {
    Link_80167A94* next;
    Link_80167A94* prev;
};

struct List_80167A94 {
    u32 count;
    Link_80167A94 head;
};

struct Vec4_80177B10 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
};
extern void* lbl_802988A8[];
extern "C" void fn_80118BD0(void* p, int b);

struct Vec_80174620 {
    f32 x, y, z;
    Vec_80174620() {}
    Vec_80174620(const Vec_80174620& o) { x = o.x; y = o.y; z = o.z; }
};
struct Rec_80174620 {
    Vec_80174620 a, b;
    u8 g;
};
struct Slot_80174620 {
    u8 active;
    u8 pad[0xb];
    Rec_80174620 recs[10];
    u8 pad2[4];
};
struct Owner_80174620 {
    u8 pad[0xc];
    Slot_80174620* slots;
};
extern const Rec_80174620 lbl_8020225C;

struct RGB8_8017261C { u8 r, g, b; };
struct Color4_8017261C { u8 r, g, b, a; };
struct Entry_8017261C { u8 pad[0x16]; Color4_8017261C colors[1]; };
struct E1_8017261C { u8 a; RGB8_8017261C c; };
struct S1_8017261C { u8 pad[0x15]; E1_8017261C e[1]; };

struct VObj_80174F08 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual s32 vf10();
    virtual s32 vf11();
    virtual s32 vf12();
    virtual s32 vf13();
};
extern void* lbl_8029839C[];

extern void* lbl_80298390[];


extern "C" void fn_8015AB1C(void* p);

struct VObj_80178E10 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual void vf20(int mode);
};
extern "C" s32 fn_80166A54(void);
extern "C" void fn_801667B4(void* a, u32 b, u32 c, u32 d);
extern "C" void fn_80166970(void* a, u32 b, u32 c, u32 d);
extern "C" void fn_80176728(void* self, void* other, u8 b, u32 unused, u32 c, u32 d, f32* f);
extern "C" void fn_801768C8(void* self, u32 a, u32 b, u32 c);
struct Rgba4_80166424 {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
};
extern "C" u32 lbl_80301AF4;
extern "C" u32 lbl_80302388;
extern "C" u32 lbl_8030238C;

typedef void VFn_80169B1C(u32*, int);
extern "C" void fn_80172264(void* p);
extern "C" void* fn_801721FC(void* self);
extern "C" char lbl_80202278[];
extern "C" u8 lbl_80301AC8[2];
extern "C" void* fn_801749F0(void* p, void* q);
struct VObj_8016C34C {
    virtual void v0(s32 a);
};
struct VObj_8017814C {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9();
};
struct UnkVObj_80166424 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6(u8);
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual u8 vf18(void*);
};
struct DtorVObj_80166424 {
    virtual void Destroy(int);
};
struct VObj_801788C0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28();
};
struct Msg_801788C0 {
    u8 pad[0xc];
    u32 kind;
};
extern "C" void* lbl_80298644[];
extern "C" void* lbl_80298600[];
extern "C" u8 lbl_80298660[];
extern "C" void fn_8015AB1C(void*);
extern "C" void fn_8016B170(u32*, int);
extern "C" void fn_8015D29C(void*, int);
extern "C" void* fn_8015D13C(void*, int, int, void*);
extern "C" void fn_801C0EEC(void*);
extern "C" u8 lbl_80298304[];

struct VObj_8016CF64 {
    virtual void vf0(); virtual void vf1(); virtual void vf2(); virtual void vf3();
    virtual void vf4(); virtual void vf5(); virtual void vf6(); virtual void vf7();
    virtual void vf8(); virtual void vf9(); virtual void vf10(); virtual void vf11();
    virtual void vf12(); virtual void vf13(); virtual void vf14(); virtual void vf15();
    virtual void vf16(); virtual void vf17(); virtual void vf18(); virtual void vf19();
    virtual void vf20(); virtual void vf21(); virtual void vf22(); virtual void vf23();
    virtual void vf24(); virtual void vf25(); virtual void vf26(); virtual void vf27();
    virtual void vf28(); virtual void vf29(); virtual void vf30(); virtual void vf31();
    virtual void vf32(); virtual void vf33(); virtual void vf34(); virtual void vf35();
    virtual void vf36(); virtual void vf37(); virtual void vf38(); virtual void vf39();
    virtual void vf40(); virtual void vf41(u8, u32); virtual void vf41(u8, u32, u32);
};

struct Unk80174858Pair {
    u8 x;
    u8 y;
};

struct UnkVObj_801671B0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual u32 vf5();
    virtual s32 vf6(u32, u32);
    virtual u32 vf7();
    virtual s32 vf8(u32, u32);
};

struct UnkVObj_80167128 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual u32 vf5(void*, u32);
};

struct UnkVObj_801670D0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual u32 vf5();
};

extern "C" void fn_801BDDBC(void*, void*, int);
extern "C" u8* fn_80166ACC(u8* p);
extern "C" void* fn_80166B1C(void* ptr, s16 param_2);
extern "C" void* fn_8015A9A8(int, void*, int);
extern "C" void fn_801BDE1C(void*, void*, int);
extern "C" void fn_801BDEE4(void*, void*, int);
extern "C" u8 lbl_802982A0[];
extern "C" void* lbl_802FF540;
extern "C" void* lbl_802FF688;
extern "C" void* fn_801664D8(void* ptr, void* param_2);
extern "C" void fn_80166C08(void*, int);
struct Stream_80167618 {
    virtual void vf0(); virtual void vf1(); virtual void vf2();
    virtual s32 vf3(void* buf, s32 len, u32 pos);
    virtual void vf4();
    virtual u32 vf5();
    u8 pad[0x14];
    u8 flag;
};
struct Self_80167618 {
    u8 pad[8];
    Stream_80167618* stream;
    u32 pos;
};
struct Slot_8016AFCC {
    RGB8_8017261C c;
    u8 pad;
};
struct Blk_8016AFCC {
    u32 w0;
    Slot_8016AFCC s[8];
    u32 tail[8];
};
struct VObj_801693F4 {
    virtual void vf0(); virtual void vf1(); virtual void vf2(); virtual void vf3();
    virtual void vf4(); virtual void vf5(); virtual void vf6(); virtual void vf7();
    virtual void vf8(); virtual void vf9();
};
struct Obj_801693F4 {
    void** vt;
    u8 pad[0xCC];
};
extern "C" void* fn_80166424(void* param_1, s16 param_2) {
    if (param_1) {
        fn_80166C08(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void* fn_80166478(void* param_1) {
    if (lbl_802FF688 == nullptr) {
        void* p = fn_8015A9A8(0x7c, lbl_802FF540, 0);
        if (p != nullptr) {
            p = fn_801664D8(p, param_1);
        }
        lbl_802FF688 = p;
    }
    return lbl_802FF688;
}

extern "C" void* fn_801664D8(void* ptr, void* param_2)
{
    void* r31 = ptr;
    fn_8015D13C(ptr, 0x4000, 0x10, param_2);
    *(void**)r31 = (void*)lbl_80298304;
    fn_801C0EEC(((void**)r31)[0xb]);
    return r31;
}

extern "C" void* fn_80166528(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_80298304;
        fn_8015D29C(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_8015F228(void* a);
extern "C" void fn_80166728(void* a, u32 b, u32 c, u32 d);
extern "C" u8 lbl_80298290[];
extern "C" void fn_80166588(void) {
    void* sp8;
    u8* self;
    u8* base;
    fn_801BDDBC(lbl_802982A0, lbl_80298290, 4);
    base = lbl_802982A0;
    fn_801BDEE4(base, &sp8, 1);
    self = (u8*)sp8;
    fn_80166728(*(void**)(self + 0x4), *(u32*)(self + 0x8), *(u32*)(self + 0xc), *(u32*)(self + 0x10));
    if (*(s32*)(self + 0x20) != 0) {
        if (*(s32*)(self + 0x20) == 1) {
            fn_8015F228(*(void**)(self + 0x24));
        }
    } else {
        void (*fn)(void*) = *(void (**)(void*))(self + 0x14);
        if (fn) {
            fn(self);
        } else if (*(void**)(self + 0x1c)) {
            fn_801BDE1C(*(void**)(self + 0x1c), (void*)1, 0);
        } else {
            fn_801BDE1C(self + 0x28, (void*)1, 0);
        }
    }
}

extern "C" void fn_80166650(void* p)
{
    fn_801BDE1C(lbl_802982A0, p, 1);
}

#pragma use_lmw_stmw off
extern "C" s32 fn_80166680(u32 a, u32 b, u32 c, u32 d)
{
    u8 buf[0x8];
    u8* p = (u8*)fn_8015A9A8(0x4c, lbl_802FF540, -4);
    if (p != nullptr) {
        p = (u8*)fn_80166ACC(p);
    }
    *(u32*)(p + 0x4) = a;
    *(u32*)(p + 0x8) = b;
    *(u32*)(p + 0xc) = c;
    *(u32*)(p + 0x10) = d;
    *(u32*)(p + 0x14) = 0;
    fn_801BDE1C(lbl_802982A0, p, 1);
    fn_801BDEE4(p + 0x28, buf, 1);
    fn_80166B1C(p, 1);
    return 1;
}

extern "C" void fn_80166728(void* a, u32 b, u32 c, u32 d)
{
    s32 r = fn_80166A54();
    if (r == 1) {
        fn_801667B4(a, b, c, d);
    } else if (r == 2) {
        fn_80166970(a, b, c, d);
    }
}

extern "C" void fn_80166970(void* a, u32 b, u32 c, u32 d) {
    u8* self = (u8*)a;
    u8* src;
    u8* dst = (u8*)b;
    u8* end;
    u8* back;
    s32 bits = 0;
    u32 flags;
    s32 len;
    u32 count = c;
    u32 skip = d;

    end = dst + *(u32*)(self + 4) - skip;
    if (count == 0) {
        return;
    }
    if (skip > *(u32*)self) {
        return;
    }
    src = self + 0x10;
    for (;;) {
        if (bits == 0) {
            bits = 8;
            flags = *src++;
        }
        if (flags & 0x80) {
            if (skip == 0) {
                count--;
                *dst++ = *src;
                if (count == 0) {
                    return;
                }
            } else {
                skip--;
            }
            src++;
        } else {
            u8 b1;
            u8 b0 = src[0];
            b1 = src[1];
            src += 2;
            back = dst - (((b0 << 8) & 0xf00) | b1);
            len = b0 >> 4;
            if (len == 0) {
                len = *src++ + 0x12;
            } else {
                len += 2;
            }
            do {
                if (skip == 0) {
                    count--;
                    *dst++ = back[-1];
                    if (count == 0) {
                        return;
                    }
                } else {
                    skip--;
                }
                back++;
                len--;
            } while (len != 0);
        }
        flags <<= 1;
        bits--;
        if (dst == end) {
            return;
        }
    }
}

#pragma use_lmw_stmw reset

extern "C" u8* fn_80166ACC(u8* p)
{
    fn_801BDDBC(p + 0x28, p + 0x48, 1);
    *(u32*)(p + 0x14) = 0;
    *(u32*)(p + 0x1c) = 0;
    *(u8**)(p + 0x18) = p;
    *(u32*)(p + 0x20) = 0;
    return p;
}

extern "C" void* fn_80166B1C(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

#pragma dont_inline on
extern "C" void fn_80166B58(u32* param_1, u32 param_2)
{
	param_1[1] = 0;
	*param_1 = param_2;
	param_1[2] = 0;
	param_1[3] = 0;
}

#pragma dont_inline reset
extern "C" u32 fn_80166FC4(void*, void*);
extern "C" void* fn_80166B70(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        if (*(void**)((u8*)param_1 + 4) != nullptr) {
            fn_80166FC4(*(void**)((u8*)param_1 + 4), param_1);
        }
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

#pragma dont_inline on
extern "C" void fn_80166C70(void* param_1) {
    *(u32*)param_1 = 0;
    *(u32*)((u8*)param_1 + 4) = 0;
    *(u32*)((u8*)param_1 + 8) = 0;
}
#pragma dont_inline reset

extern "C" u32 fn_80166D3C(void** param_1, void* param_2) {
    u32 uVar1 = (*(void**)((u8*)param_2 + 4) == nullptr);
    if (!uVar1) {
        uVar1 = fn_80166FC4(*(void**)((u8*)param_2 + 4), param_2);
    }
    if ((uVar1 & 0xff) != 0) {
        if ((u32)param_1[2] == 0) {
            *(void***)((u8*)param_2 + 4) = param_1;
            *(u32*)((u8*)param_2 + 8) = 0;
            *(u32*)((u8*)param_2 + 0xc) = 0;
            param_1[1] = param_2;
            *param_1 = param_2;
            param_1[2] = (void*)1;
        } else {
            *(void***)((u8*)param_2 + 4) = param_1;
            *(u32*)((u8*)param_2 + 8) = 0;
            *(void**)((u8*)param_2 + 0xc) = *param_1;
            *(void**)((u8*)*param_1 + 8) = param_2;
            *param_1 = param_2;
            param_1[2] = (void*)((u32)param_1[2] + 1);
        }
    }
    return uVar1;
}

extern "C" u32 fn_80166FC4(void* p_list, void* p_node)
{
    u32* list = (u32*)p_list;
    u32* node = (u32*)p_node;
    u32 r = __cntlzw((u32)list - node[1]);
    if ((u8)(r >> 5)) {
        if (list[2] == 1) {
            list[0] = 0;
            list[1] = 0;
        } else if ((u32)node == list[0]) {
            ((u32*)node[3])[2] = 0;
            list[0] = node[3];
        } else if ((u32)node == list[1]) {
            ((u32*)node[2])[3] = 0;
            list[1] = node[2];
        } else {
            ((u32*)node[2])[3] = node[3];
            ((u32*)node[3])[2] = node[2];
        }
        node[1] = 0;
        list[2] = list[2] - 1;
    }
    return r >> 5;
}

#pragma dont_inline on
extern "C" void* fn_80167074(void* ptr, s16 param_2) {
    extern void* lbl_8029839C[];
    extern void* lbl_80298390[];
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029839C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80298390;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
#pragma dont_inline reset

extern "C" void fn_801670D0(UnkVObj_801670D0* self, u32 unused, s32 n)
{
    s32 v = self->vf5();
    if (v != n) {
        *((u8*)self + 4) |= 1;
    }
}

extern "C" s32 fn_80167128(UnkVObj_80167128* self, s32 n)
{
    s32 i;
    u8 buf[8];
    for (i = 0; i < n; i++) {
        if (self->vf5(buf, 1) != 1) {
            *((u8*)self + 4) |= 1;
            break;
        }
    }
    return i;
}

extern "C" s32 fn_801671B0(UnkVObj_801671B0* param_1, u32 param_2) {
    u32 size = param_1->vf5();
    u32 aligned = param_2 + size;
    aligned = (aligned - 1) & ~(param_2 - 1);
    s32 diff = aligned - size;
    if (diff != 0) {
        s32 r = param_1->vf6(aligned, 0);
        if (r != diff) {
            *((u8*)param_1 + 4) |= 1;
        }
    }
    return diff;
}

extern void* lbl_8029836C[];
extern "C" void* fn_80167398(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029836C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029839C;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_80298390;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_80167404(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80298390;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_8016744C(int param_1, int param_2, int param_3)
{
	*(int*)(param_1 + 0x8) = param_2;
	*(int*)(param_1 + 0xc) = param_3;
	*(int*)(param_1 + 0x10) = 0;
}

extern "C" void* memcpy(void*, const void*, unsigned long);
extern "C" int fn_80167460(int param_1, void* param_2, int param_3)
{
	int pos = *(int*)(param_1 + 0x10);
	int cap = *(int*)(param_1 + 0xc);

	if (pos + param_3 > cap) {
		param_3 = cap - pos;
	}

	if (param_3 > 0) {
		memcpy(param_2, (void*)(*(int*)(param_1 + 0x8) + pos), param_3);
		*(int*)(param_1 + 0x10) = *(int*)(param_1 + 0x10) + param_3;
	}

	return param_3;
}

extern "C" int fn_80167554(int p) { return *(int*)(p + 0xc); }

extern "C" int fn_8016755C(int param_1) {
  return *(int *)(param_1 + 0x10);
}

extern char lbl_80298440[];
extern "C" void* fn_80167564(void** param_1, s16 param_2) {
    if (param_1 != nullptr) {
        param_1[0] = (void*)lbl_80298440;
        if (param_1 != nullptr) {
            param_1[0] = (void*)lbl_8029836C;
            fn_80167074(param_1, 0);
        }
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" s32 fn_80167618(Self_80167618* self, void* buf, s32 len) {
    s32 result = 0;
    if (self->stream->flag != 0) {
        if ((u32)(self->pos + len) > self->stream->vf5()) {
            len = self->stream->vf5() - self->pos;
        }
        if (len > 0) {
            result = self->stream->vf3(buf, len, self->pos);
            if (result < 0) {
                return 0;
            }
            self->pos += result;
        }
    }
    return result;
}

extern "C" s32 fn_801676F8(Self_80167618* self, s32 arg1, s32 mode) {
    s32 old = self->pos;
    switch (mode) {
    case 0:
        self->pos = arg1;
        break;
    case 2:
        self->pos = self->stream->vf5() - arg1;
        break;
    case 1:
        self->pos = old + arg1;
        break;
    }
    if ((s32)self->pos < 0) {
        self->pos = 0;
    }
    if ((s32)self->pos > (s32)self->stream->vf5()) {
        self->pos = self->stream->vf5();
    }
    return (s32)self->pos - old;
}

extern "C" int fn_80167810(int p) { return *(int*)(p + 0xc); }

extern void* lbl_802911A0[];
extern "C" void* fn_80167880(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802911A0;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_801679DC(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_80167A94(List_80167A94* self, u32* arg1) {
    List_80167A94 tmp;
    Link_80167A94* cur;
    Link_80167A94* nx;
    Link_80167A94* target;

    target = (Link_80167A94*)*arg1;
    tmp.head.next = &tmp.head;
    tmp.head.prev = &tmp.head;
    tmp.count = 0;
    cur = self->head.next;
    while (cur != &self->head) {
        if (cur == target) {
            nx = cur->next;
            if (cur != &tmp.head && nx != &tmp.head) {
                nx->prev = cur->prev;
                cur->prev->next = nx;
                self->count -= 1;
                cur->next = &tmp.head;
                cur->prev = tmp.head.prev;
                tmp.head.prev->next = cur;
                tmp.head.prev = cur;
                tmp.count += 1;
            }
            cur = nx;
        } else {
            cur = cur->next;
        }
    }
}

extern "C" s32 fn_80167B7C(void* a, s32 b) { return b << 1; }

extern "C" void fn_80168280(void);
extern "C" void* fn_80167E08(void);
extern "C" void fn_80167CB8(void) {
    fn_80168280();
}

extern "C" void* fn_80167CD8(u8* param_1, u32* param_2, u32* param_3) {
    u32* dst = param_2;
    u32 n = ((u32)*(u32**)(param_1 + 8) + 3 - (u32)param_3) >> 2;
    if (param_3 < *(u32**)(param_1 + 8)) {
        for (u32 i = n >> 3; i != 0; i--) {
            dst[0] = param_3[0];
            dst[1] = param_3[1];
            dst[2] = param_3[2];
            dst[3] = param_3[3];
            dst[4] = param_3[4];
            dst[5] = param_3[5];
            dst[6] = param_3[6];
            dst[7] = param_3[7];
            param_3 += 8;
            dst += 8;
        }
        n &= 7;
        for (; n != 0; n--) {
            *dst++ = *param_3++;
        }
    }
    for (u32* p = dst; p != *(u32**)(param_1 + 8); p++) {
    }
    *(u32**)(param_1 + 8) = dst;
    return param_2;
}

extern "C" void fn_80167D90(u8* param_1, u32 param_2, u32 param_3, u32* param_4) {
    if (param_3 != 0) {
        u32* p = (u32*)fn_80167E08();
        if (p != *(u32**)(param_1 + 8)) {
            u32 v = *param_4;
            for (u32 i = param_3; i != 0; i--) {
                if (p != nullptr) {
                    *p = v;
                }
                p++;
            }
        }
    }
}

extern "C" void fn_8015AB1C(void* ptr);
extern void* lbl_80298520[];
extern "C" void* fn_80168D68(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80298520;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" f32 lbl_80301AF8;
extern "C" f32 lbl_80301B20;
extern "C" void* lbl_80298C88[];
extern "C" void fn_80176610(void* p);
extern "C" void fn_80176E24(void* p, int mode);
extern "C" int fn_80168DF8()
{
	return 0;
}

extern "C" void fn_80168E00(void)
{
}

extern "C" void fn_801682D8(void* p, f32 a, f32 b, f32 c, f32 d);
extern "C" void* lbl_80298574[];
extern "C" f32 lbl_80301A90;
extern "C" void* fn_80168E64(void* self, f32 unused0, f32 unused1, f32 a, f32 b, f32 c, f32 d) {
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp;

    fn_801682D8(self, unused0, unused1, a, b);
    sp10 = a;
    temp = -d;
    sp8 = lbl_80301A90;
    spC = lbl_80301A90;
    *(void**)self = lbl_80298574;
    *(u32*)((u8*)self + 0xbc) = *(u32*)&sp8;
    sp14 = b;
    *(u32*)((u8*)self + 0xc0) = *(u32*)&spC;
    *(u32*)((u8*)self + 0xc4) = *(u32*)&sp10;
    *(u32*)((u8*)self + 0xc8) = *(u32*)&sp14;
    *(f32*)((u8*)self + 0xcc) = temp;
    *(f32*)((u8*)self + 0xd0) = -c;
    ((UnkVObj_80166424*)self)->vf7();
    return self;
}

extern "C" void fn_801688F0(void* p, u32* a, u32* b, u32* c, u32* d);
extern "C" void fn_80168A0C(void* p, s32 v);
extern "C" void fn_80168B40(void* p, s32 v);
extern "C" void fn_801693F4(void* a, s32* b, s32 c) {
    s32 vals[5];
    Obj_801693F4 obj;
    Obj_801693F4* p = &obj;
    s32 v;

    fn_801682D8(p, lbl_80301A90, lbl_80301A90, lbl_80301A90, lbl_80301A90);
    p->vt = lbl_80298574;
    ((VObj_801693F4*)p)->vf7();
    v = *b;
    vals[4] = v;
    vals[3] = v;
    vals[2] = v;
    vals[1] = v;
    vals[0] = v;
    fn_801688F0(p, (u32*)&vals[0], (u32*)&vals[1], (u32*)&vals[2], (u32*)&vals[3]);
    fn_80168A0C(p, c);
    fn_80168B40(p, (s32)a);
    p->vt = lbl_80298574;
    p->vt = lbl_80298520;
}

extern "C" BOOL fn_801694D8(void);
extern "C" BOOL fn_801694D8(void)
{
    return TRUE;
}

extern "C" void fn_801DF378(unsigned char*, int, unsigned char);
extern "C" void fn_801694E0(unsigned char *param_1, int param_2)
{
	fn_801DF378(param_1 + 0x24, param_2 * 3 + 0x1e, *param_1);
}

extern "C" void fn_801DE01C(u8 a, u8 b, u8 c);
extern "C" void fn_8016991C(u8* p, s32 x)
{
    fn_801DE01C((u8)x, p[0], p[1]);
}

extern "C" void fn_801DE160(u8 a, u8 b, u8 c);
extern "C" void fn_8016994C(u8* p, s32 x)
{
    fn_801DE160((u8)x, p[0], p[1]);
}

extern "C" int fn_8016997C()
{
	return 0;
}

extern "C" int fn_80169984()
{
	return 0;
}

extern "C" int fn_8016998C()
{
	return 0;
}

extern "C" int fn_80169994()
{
	return 0;
}

extern "C" int fn_8016999C()
{
	return 0;
}

extern "C" int fn_801699A4()
{
	return 0;
}

extern "C" int fn_801699AC()
{
	return 0;
}

extern "C" int fn_801699B4(void) {
    return 0xFFFF;
}

extern "C" int fn_801699C0(void) {
    return 0xFFFF;
}

extern "C" int fn_801699CC(void)
{
    return 1;
}

extern "C" int fn_801699D4()
{
	return 0;
}

extern "C" int fn_801699DC()
{
	return 0;
}

extern "C" int fn_801699E4()
{
	return 0;
}

extern "C" int fn_801699EC()
{
	return 0;
}

extern "C" int fn_801699F4()
{
	return 0;
}

extern "C" u32* fn_80169B1C(u32* self, short param_2)
{
    if (self != NULL) {
        self[0] = (u32)lbl_80298644;
        u32* p = (u32*)self[0x1c];
        if (p != NULL) {
            VFn_80169B1C** vt = (VFn_80169B1C**)*p;
            vt[0xb8 / 4](p, 1);
        }
        p = (u32*)self[0x1d];
        if (p != NULL) {
            ((VFn_80169B1C**)*p)[0x34 / 4](p, 1);
        }
        fn_8015AB1C((void*)self[0x21]);
        fn_8016B170(self + 10, -1);
        if ((u8*)self + 0x10 != NULL) {
            self[9] = (u32)lbl_80298660;
        }
        if (param_2 > 0) {
            fn_8015AB1C(self);
        }
    }
    return self;
}

extern "C" void* fn_8015A90C(u32 size);
extern "C" void fn_80169FEC(void* param_1)
{
    u8* p;
    if (*(void**)((u8*)param_1 + 0x84) == nullptr) {
        p = (u8*)fn_8015A90C(0x44);
        if (p != nullptr) {
            *(u32*)(p + 0x0) = 0;
            *(u16*)(p + 0x10) = 0xFFFF;
            *(u32*)(p + 0x4) = 0;
            *(u16*)(p + 0x12) = 0xFFFF;
            *(u16*)(p + 0x14) = 0xFFFF;
            *(u16*)(p + 0x16) = 0xFFFF;
            *(u16*)(p + 0x18) = 0xFFFF;
            *(u16*)(p + 0x1a) = 0xFFFF;
            *(u16*)(p + 0x1c) = 0xFFFF;
            *(u16*)(p + 0x1e) = 0xFFFF;
            *(u16*)(p + 0x20) = 0xFFFF;
            *(u32*)(p + 0x8) = 0;
            *(u16*)(p + 0x22) = 0xFFFF;
            *(u16*)(p + 0x24) = 0xFFFF;
            *(u16*)(p + 0x26) = 0xFFFF;
            *(u16*)(p + 0x28) = 0xFFFF;
            *(u16*)(p + 0x2a) = 0xFFFF;
            *(u16*)(p + 0x2c) = 0xFFFF;
            *(u16*)(p + 0x2e) = 0xFFFF;
            *(u16*)(p + 0x30) = 0xFFFF;
            *(u32*)(p + 0xc) = 0;
            *(u16*)(p + 0x32) = 0xFFFF;
            *(u16*)(p + 0x34) = 0xFFFF;
            *(u16*)(p + 0x36) = 0xFFFF;
            *(u16*)(p + 0x38) = 0xFFFF;
            *(u16*)(p + 0x3a) = 0xFFFF;
            *(u16*)(p + 0x3c) = 0xFFFF;
            *(u16*)(p + 0x3e) = 0xFFFF;
            *(u16*)(p + 0x40) = 0xFFFF;
        }
        *(void**)((u8*)param_1 + 0x84) = p;
    }
}

extern "C" void* fn_8016ABEC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80298600;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80298B14[];
extern "C" void* fn_8016AC34(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80298B14;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_8016AC7C(void)
{
}

extern "C" void fn_8016AC80(void)
{
}

extern "C" void fn_8016AC84(void)
{
}

extern "C" void fn_8016AC88(void)
{
}

extern "C" void fn_8016AC8C(void)
{
}

extern "C" void fn_8016AC90(void)
{
}

extern "C" u32 fn_8016AC94(void) {
    return 0x49424C4E;
}

extern void* lbl_802985C8[];
extern void* lbl_80298600[];
extern "C" void* fn_8016ACA0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802985C8;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80298600;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_8016ACFC(void) {
}

extern "C" void fn_8016AD00(void) {
}

extern "C" void fn_8016AD04() {}

extern "C" void fn_8016AD08() {}

extern "C" void fn_8016AD0C() {}

extern const u8 lbl_80202218[32];
extern "C" void fn_8016AD10(u8* p) {
    p[0] = lbl_80202218[0];
    p[1] = lbl_80202218[1];
    p[2] = lbl_80202218[2];
}

extern "C" void* fn_8016AD40(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern u8 lbl_80301AC0[2];
extern "C" void fn_8016AD7C(u8* p) {
    p[0] = lbl_80301AC0[0];
    p[1] = lbl_80301AC0[1];
}

extern "C" void* fn_8016AD94(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern u8 lbl_80301AB4[2];
extern "C" void fn_8016AE10(u8* p) {
    p[0] = lbl_80301AB4[0];
    p[1] = lbl_80301AB4[1];
}

extern "C" void fn_8016AE28(void) {
}

extern "C" void fn_801DCBB0(s32, s32*);
extern "C" void fn_801DCCA0(u8);
extern "C" void fn_801DCCDC(s32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_801DBAE4(u8);
extern "C" s32 lbl_80202298[4];
extern "C" void fn_8016AED8(void* arg0) {
    u8* self = (u8*)arg0;
    s32 sp8;
    s32 spC[4];
    u16* q;
    u32* r31;
    s32 i;
    s32 j;
    s32* r30;

    i = 0;
    r31 = (u32*)arg0;
    do {
        sp8 = *r31;
        fn_801DCBB0(i + 4, &sp8);
        i++;
        r31++;
    } while (i < 2);
    fn_801DCCA0(self[8]);
    q = (u16*)arg0;
    r30 = spC;
    j = 0;
    spC[0] = lbl_80202298[0];
    spC[1] = lbl_80202298[1];
    spC[2] = lbl_80202298[2];
    spC[3] = lbl_80202298[3];
    while (j < (s32)(self[8] * 2)) {
        fn_801DCCDC(*r30, 0, 0, q[5] & 1, 0, 0, 2);
        q++;
        r30++;
        j++;
    }
    fn_801DBAE4(self[0x12]);
}

extern "C" void fn_8016AFCC(void* p) {
    Blk_8016AFCC* b = (Blk_8016AFCC*)p;
    b->w0 = 0;
    for (int i = 0; i < 8; i++) {
        b->s[i].c = *(RGB8_8017261C*)lbl_80202218;
    }
    for (int i = 0; i < 8; i++) {
        b->tail[i] = 0;
    }
}

extern "C" int fn_8016B410()
{
	return 0;
}

extern "C" void fn_80177728(void* self, f32* rect);
extern "C" void fn_80177C20(void* self, f32 c);
extern "C" int fn_8016B418()
{
	return 0;
}

extern "C" void fn_80118BD0(void*, int);
extern "C" int fn_8016BC8C(u8* p, void* a, void* b)
{
    if (a != 0) {
        return 0;
    }
    if (p[0x5c] & 1) {
        fn_80118BD0(*(void**)(p + 0x50), 1);
    }
    *(void**)(p + 0x50) = b;
    p[0x5c] &= 0x80;
    fn_8015AB1C(*(void**)(p + 0x54));
    *(void**)(p + 0x54) = 0;
    *(u16*)(p + 4) = 0xffff;
    return 1;
}

extern "C" int fn_8016BD18(u8* p, u32 a)
{
    if (a >= 1) {
        return 0;
    }
    if (p[0x5c] & 1) {
        fn_80118BD0(*(void**)(p + 0x50), 1);
    }
    *(void**)(p + 0x50) = 0;
    p[0x5c] &= 0x80;
    fn_8015AB1C(*(void**)(p + 0x54));
    *(u16*)(p + 4) = 0xffff;
    return 1;
}

extern "C" void* fn_8015A90C(u32);
extern "C" void* fn_80119904(void*, void*, int);
extern "C" int fn_8016BD94(u8* p, void* src)
{
    void* obj;
    DtorVObj_80166424* old;
    if (src == 0) {
        return 0;
    }
    obj = fn_8015A90C(0x70);
    if (obj != 0) {
        obj = fn_80119904(obj, src, 0);
    }
    if (obj == 0) {
        return 0;
    }
    if (p[0x5c] & 0x80) {
        old = *(DtorVObj_80166424**)(p + 0x58);
        if (old != 0) {
            old->Destroy(1);
        }
    }
    *(void**)(p + 0x58) = obj;
    p[0x5c] = (p[0x5c] & 0x7f) | 0x80;
    return 1;
}

extern "C" int fn_8016BE50(u8* p, void* obj)
{
    DtorVObj_80166424* old;
    if (obj == 0) {
        return 0;
    }
    if (p[0x5c] & 0x80) {
        old = *(DtorVObj_80166424**)(p + 0x58);
        if (old != 0) {
            old->Destroy(1);
        }
    }
    *(void**)(p + 0x58) = obj;
    p[0x5c] &= 0x7f;
    return 1;
}

extern "C" void fn_80119240(void* p, u32 a, u32 b);
extern "C" void fn_80118F5C(void* a, void* b);
extern "C" s32 fn_8016BED0(u8* self, u32 a, u32 c)
{
    if (a != 0) {
        return 0;
    }
    if (c != 0) {
        if (*(void**)(self + 0x54) == nullptr) {
            void* p = fn_8015A90C(0x18);
            if (p != nullptr) {
                fn_80119240(p, 0, c);
            }
            *(void**)(self + 0x54) = p;
            if (*(void**)(self + 0x54) == nullptr) {
                return 0;
            }
        } else {
            fn_80119240(*(void**)(self + 0x54), 0, c);
        }
        if (*(void**)(self + 0x50) != nullptr) {
            fn_80118F5C(*(void**)(self + 0x50), *(void**)(self + 0x54));
        }
    } else {
        fn_8015AB1C(*(void**)(self + 0x54));
        *(void**)(self + 0x54) = nullptr;
    }
    return 1;
}

extern "C" void fn_8016BF98(u8* p)
{
    p[0x5c] &= 0x80;
}

extern "C" void fn_801191F0(void*);
extern "C" void fn_8016C1F4(u8* p, int unused, u32 idx)
{
    u8* obj;
    if (idx != 0) {
        return;
    }
    obj = ((u8**)(p + 0x50))[idx];
    if (obj != 0 && *(void**)(obj + 0x20) != 0) {
        fn_801191F0(obj);
    }
}

extern "C" void* lbl_80298980[];
extern "C" void* lbl_80298B14[];
extern "C" void* fn_8016C34C(void* self, s16 param_2) {
    if (self != nullptr) {
        *(void**)self = lbl_80298980;
        if (*((u8*)self + 0x78) & 1) {
            fn_80118BD0(*(void**)((u8*)self + 0x64), 1);
        }
        if (*((u8*)self + 0x78) & 2) {
            fn_80118BD0(*(void**)((u8*)self + 0x68), 1);
        }
        fn_8015AB1C(*(void**)((u8*)self + 0x6c));
        fn_8015AB1C(*(void**)((u8*)self + 0x70));
        if (*((u8*)self + 0x78) & 0x80) {
            VObj_8016C34C* obj = *(VObj_8016C34C**)((u8*)self + 0x74);
            if (obj != nullptr) {
                obj->v0(1);
            }
        }
        if (self != nullptr) {
            *(void**)self = lbl_80298B14;
        }
        if (param_2 > 0) {
            fn_8015AB1C(self);
        }
    }
    return self;
}

extern "C" s32 fn_8016C774(void* self, u8 count) {
    u8 i = 0;
    while (i < count) {
        if (i >= 2) {
            return 0;
        }
        u32 off = i * 4 + 0x64;
        if (*(void**)((u8*)self + off) == nullptr) {
            void* p = fn_8015A90C(0x40);
            if (p != nullptr) {
                *(u8*)((u8*)p + 0x3b) = *(u8*)((u8*)p + 0x3b) & 2;
                *(u32*)((u8*)p + 0x28) = 0;
                *(u32*)((u8*)p + 0x20) = 0;
            }
            *(void**)((u8*)self + off) = p;
            if (*(void**)((u8*)self + off) == nullptr) {
                return 0;
            }
        }
        *(u8*)((u8*)self + 0x78) = *(u8*)((u8*)self + 0x78) | (1 << i);
        i++;
    }
    return 1;
}

#pragma use_lmw_stmw off
extern "C" int fn_8016CEB4(u8* p, u32 idx, void* val)
{
    int mask;
    if (idx >= 2) {
        return 0;
    }
    if (p[0x78] & (mask = 1 << idx)) {
        fn_80118BD0(((void**)(p + 0x64))[idx], 1);
    }
    ((void**)(p + 0x64))[idx] = val;
    p[0x78] &= ~mask;
    fn_8015AB1C(((void**)(p + 0x6c))[idx]);
    ((void**)(p + 0x6c))[idx] = 0;
    ((u16*)(p + 4))[idx] = 0xFFFF;
    return 1;
}

extern "C" int fn_8016CF64(u8* p, u32 idx) {
    if (idx >= 2) {
        return 0;
    }
    if (p[0x78] & (1 << idx)) {
        fn_80118BD0(((void**)(p + 0x64))[idx], 1);
    }
    fn_8015AB1C(((void**)(p + 0x6c))[idx]);
    if (idx == 0) {
        *(void**)(p + 0x64) = *(void**)(p + 0x68);
        *(void**)(p + 0x6c) = *(void**)(p + 0x70);
        *(u16*)(p + 4) = *(u16*)(p + 6);
    }
    *(void**)(p + 0x68) = 0;
    *(void**)(p + 0x70) = 0;
    *(u16*)(p + 6) = 0xFFFF;
    ((VObj_8016CF64*)p)->vf41((u8)idx, 0);
    return 1;
}

#pragma use_lmw_stmw reset

extern "C" int fn_8016D038(u8* p, void* src)
{
    void* obj;
    DtorVObj_80166424* old;
    if (src == 0) {
        return 0;
    }
    obj = fn_8015A90C(0x70);
    if (obj != 0) {
        obj = fn_80119904(obj, src, 0);
    }
    if (obj == 0) {
        return 0;
    }
    if (p[0x78] & 0x80) {
        old = *(DtorVObj_80166424**)(p + 0x74);
        if (old != 0) {
            old->Destroy(1);
        }
    }
    *(void**)(p + 0x74) = obj;
    p[0x78] = (p[0x78] & 0x7f) | 0x80;
    return 1;
}

extern "C" int fn_8016D0F4(u8* p, void* obj)
{
    DtorVObj_80166424* old;
    if (obj == 0) {
        return 0;
    }
    if (p[0x78] & 0x80) {
        old = *(DtorVObj_80166424**)(p + 0x74);
        if (old != 0) {
            old->Destroy(1);
        }
    }
    *(void**)(p + 0x74) = obj;
    p[0x78] &= 0x7f;
    return 1;
}

#pragma use_lmw_stmw off
extern "C" s32 fn_8016D174(u8* self, u32 a, u32 c)
{
    u8* base = self;
    u32 idx = a;
    u32 flag = c;

    if (idx >= 2) {
        return 0;
    }
    if (flag != 0) {
        if (*(void**)(base + idx * 4 + 0x6c) == nullptr) {
            void* p = fn_8015A90C(0x18);
            if (p != nullptr) {
                fn_80119240(p, idx, flag);
            }
            *(void**)(base + idx * 4 + 0x6c) = p;
            if (*(void**)(base + idx * 4 + 0x6c) == nullptr) {
                return 0;
            }
        } else {
            fn_80119240(*(void**)(base + idx * 4 + 0x6c), 0, flag);
        }
        if (*(void**)(base + idx * 4 + 0x64) != nullptr) {
            fn_80118F5C(*(void**)(base + idx * 4 + 0x64), *(void**)(base + idx * 4 + 0x6c));
        }
    } else {
        fn_8015AB1C(*(void**)(base + idx * 4 + 0x6c));
        *(void**)(base + idx * 4 + 0x6c) = nullptr;
    }
    return 1;
}
#pragma use_lmw_stmw reset
extern "C" void fn_8016D24C(u8* p, u8 n, u8 flag)
{
    u8 top = p[0x78] & 0x80;
    p[0x78] &= 0x7f;
    if (flag) {
        int mask = (1 << n) - 1;
        p[0x78] = (p[0x78] & mask) | ((p[0x78] & ~mask) << 1);
    } else {
        p[0x78] = (p[0x78] & ((1 << n) - 1)) | ((int)(p[0x78] & ~((1 << (n + 1)) - 1)) >> 1);
    }
    p[0x78] |= top;
}

extern "C" void fn_8016D5BC(u8* p, int unused, u32 idx)
{
    u8* obj;
    if (idx >= 2) {
        return;
    }
    obj = ((u8**)(p + 0x64))[idx];
    if (obj != 0 && *(void**)(obj + 0x20) != 0) {
        fn_801191F0(obj);
    }
}

extern "C" void* fn_8016D71C(void* param_1, s16 param_2) {
    s32 i;
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_802988A8;
        for (i = 0; i < 4; i++) {
            if (*((u8*)param_1 + 0xb0) & (1 << i)) {
                fn_80118BD0(((void**)param_1)[0x8c / 4 + i], 1);
            }
            fn_8015AB1C(((void**)param_1)[0x9c / 4 + i]);
        }
        if (*((u8*)param_1 + 0xb0) & 0x80) {
            void* obj = ((void**)param_1)[0xac / 4];
            if (obj != nullptr) {
                void** vt = *(void***)obj;
                ((void (*)(void*, int))vt[2])(obj, 1);
            }
        }
        *(void**)param_1 = (void*)lbl_80298B14;
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" BOOL fn_8016DBC8(void* self, u8 count) {
    struct S {
        u8 pad[0x8c];
        void* slots[4];
        u8 pad2[0xb0 - 0x9c];
        u8 mask;
    };
    S* s = (S*)self;
    for (u8 i = 0; i < count; i++) {
        if (i >= 4) {
            return FALSE;
        }
        if (s->slots[i] == nullptr) {
            u8* p = (u8*)fn_8015A90C(0x40);
            if (p != nullptr) {
                p[0x3b] &= 2;
                *(u32*)(p + 0x28) = 0;
                *(u32*)(p + 0x20) = 0;
            }
            s->slots[i] = p;
            if (s->slots[i] == nullptr) {
                return FALSE;
            }
            s->mask |= 1 << i;
        }
    }
    return TRUE;
}

#pragma push
#pragma use_lmw_stmw off
extern "C" int fn_8016E4E0(u8* p, u32 idx, void* val)
{
    int mask;
    if (idx >= 4) {
        return 0;
    }
    if (p[0xb0] & (mask = 1 << idx)) {
        fn_80118BD0(((void**)(p + 0x8c))[idx], 1);
    }
    ((void**)(p + 0x8c))[idx] = val;
    p[0xb0] &= ~mask;
    fn_8015AB1C(((void**)(p + 0x9c))[idx]);
    ((void**)(p + 0x9c))[idx] = 0;
    ((u16*)(p + 4))[idx] = 0xFFFF;
    return 1;
}

extern "C" int fn_8016E7A0(u8* p, void* src)
{
    void* obj;
    DtorVObj_80166424* old;
    if (src == 0) {
        return 0;
    }
    obj = fn_8015A90C(0x70);
    if (obj != 0) {
        obj = fn_80119904(obj, src, 0);
    }
    if (obj == 0) {
        return 0;
    }
    if (p[0xb0] & 0x80) {
        old = *(DtorVObj_80166424**)(p + 0xac);
        if (old != 0) {
            old->Destroy(1);
        }
    }
    *(void**)(p + 0xac) = obj;
    p[0xb0] = (p[0xb0] & 0x7f) | 0x80;
    return 1;
}

extern "C" int fn_8016E85C(u8* p, void* obj)
{
    DtorVObj_80166424* old;
    if (obj == 0) {
        return 0;
    }
    if (p[0xb0] & 0x80) {
        old = *(DtorVObj_80166424**)(p + 0xac);
        if (old != 0) {
            old->Destroy(1);
        }
    }
    *(void**)(p + 0xac) = obj;
    p[0xb0] &= 0x7f;
    return 1;
}

extern "C" s32 fn_8016E8DC(u8* self, u32 idx, u32 c)
{
    u32 off;
    void** slot;

    if (idx >= 4) {
        return 0;
    }
    if (c != 0) {
        off = idx * 4;
        slot = (void**)(self + off + 0x9c);
        if (*slot == nullptr) {
            void* p = fn_8015A90C(0x18);
            if (p != nullptr) {
                fn_80119240(p, idx, c);
            }
            *slot = p;
            if (*slot == nullptr) {
                return 0;
            }
        } else {
            fn_80119240(*slot, 0, c);
        }
        if (*(void**)(self + off + 0x8c) != nullptr) {
            fn_80118F5C(*(void**)(self + off + 0x8c), *slot);
        }
    } else {
        slot = (void**)(self + idx * 4 + 0x9c);
        fn_8015AB1C(*slot);
        *slot = nullptr;
    }
    return 1;
}

extern "C" void fn_8016E9B4(u8* p, u8 n, u8 flag)
{
    u8 top = p[0xb0] & 0x80;
    p[0xb0] &= 0x7f;
    if (flag) {
        int mask = (1 << n) - 1;
        p[0xb0] = (p[0xb0] & mask) | ((p[0xb0] & ~mask) << 1);
    } else {
        p[0xb0] = (p[0xb0] & ((1 << n) - 1)) | ((int)(p[0xb0] & ~((1 << (n + 1)) - 1)) >> 1);
    }
    p[0xb0] |= top;
}

extern "C" void fn_8016ED24(u8* p, int unused, u32 idx)
{
    u8* obj;
    if (idx >= 4) {
        return;
    }
    obj = ((u8**)(p + 0x8c))[idx];
    if (obj != 0 && *(void**)(obj + 0x20) != 0) {
        fn_801191F0(obj);
    }
}

extern "C" void* lbl_802987D0[];
extern "C" void* fn_8016EE94(u8* self, s16 param_2) {
    if (self != nullptr) {
        s32 i;
        *(void**)self = lbl_802987D0;
        for (i = 0; i < 8; i++) {
            if (self[0x120] & (1 << i)) {
                fn_80118BD0(*(void**)(self + 0xdc + i * 4), 1);
            }
            fn_8015AB1C(*(void**)(self + 0xfc + i * 4));
        }
        if (self[0x121] != 0) {
            void* p = *(void**)(self + 0x11c);
            if (p != nullptr) {
                ((VObj_8016C34C*)p)->v0(1);
            }
        }
        if (self != nullptr) {
            *(void**)self = lbl_80298B14;
        }
        if (param_2 > 0) {
            fn_8015AB1C(self);
        }
    }
    return self;
}

extern "C" s32 fn_8016F424(u8* self, u8 count)
{
    u8 i;
    for (i = 0; i < count; i++) {
        if (i >= 8) {
            return 0;
        }
        if (((void**)(self + 0xdc))[i] == nullptr) {
            u8* p = (u8*)fn_8015A90C(0x40);
            if (p != nullptr) {
                p[0x3b] = p[0x3b] & 2;
                *(u32*)(p + 0x28) = 0;
                *(u32*)(p + 0x20) = 0;
            }
            ((void**)(self + 0xdc))[i] = p;
            if (((void**)(self + 0xdc))[i] == nullptr) {
                return 0;
            }
        }
        self[0x120] = self[0x120] | (1 << i);
    }
    return 1;
}

#pragma use_lmw_stmw off
extern "C" int fn_8016FD58(u8* p, u32 idx, void* val)
{
    int mask;
    if (idx >= 8) {
        return 0;
    }
    if (p[0x120] & (mask = 1 << idx)) {
        fn_80118BD0(((void**)(p + 0xdc))[idx], 1);
    }
    ((void**)(p + 0xdc))[idx] = val;
    p[0x120] &= ~mask;
    fn_8015AB1C(((void**)(p + 0xfc))[idx]);
    ((void**)(p + 0xfc))[idx] = 0;
    ((u16*)(p + 4))[idx] = 0xFFFF;
    return 1;
}
#pragma use_lmw_stmw reset

extern "C" int fn_80170018(u8* p, void* src)
{
    void* obj;
    DtorVObj_80166424* old;
    if (src == 0) {
        return 0;
    }
    obj = fn_8015A90C(0x70);
    if (obj != 0) {
        obj = fn_80119904(obj, src, 0);
    }
    if (obj == 0) {
        return 0;
    }
    if (p[0x121]) {
        old = *(DtorVObj_80166424**)(p + 0x11c);
        if (old != 0) {
            old->Destroy(1);
        }
    }
    *(void**)(p + 0x11c) = obj;
    p[0x121] = 1;
    return 1;
}

extern "C" int fn_801700CC(u8* p, void* obj)
{
    DtorVObj_80166424* old;
    if (obj == 0) {
        return 0;
    }
    if (p[0x121]) {
        old = *(DtorVObj_80166424**)(p + 0x11c);
        if (old != 0) {
            old->Destroy(1);
        }
    }
    *(void**)(p + 0x11c) = obj;
    p[0x121] = 0;
    return 1;
}

extern "C" s32 fn_80170148(u8* self, u32 idx, u32 c)
{
    if (idx >= 8) {
        return 0;
    }
    if (c != 0) {
        if (((void**)(self + 0xfc))[idx] == nullptr) {
            void* p = fn_8015A90C(0x18);
            if (p != nullptr) {
                fn_80119240(p, idx, c);
            }
            ((void**)(self + 0xfc))[idx] = p;
            if (((void**)(self + 0xfc))[idx] == nullptr) {
                return 0;
            }
        } else {
            fn_80119240(((void**)(self + 0xfc))[idx], 0, c);
        }
        if (((void**)(self + 0xdc))[idx] != nullptr) {
            fn_80118F5C(((void**)(self + 0xdc))[idx], ((void**)(self + 0xfc))[idx]);
        }
    } else {
        fn_8015AB1C(((void**)(self + 0xfc))[idx]);
        ((void**)(self + 0xfc))[idx] = nullptr;
    }
    return 1;
}

extern "C" void fn_80170220(u8* p, u32 bit, u8 flag) {
    if (flag != 0) {
        u32 mask = (1 << (u8)bit) - 1;
        u8 v = p[0x120];
        p[0x120] = (v & mask) | ((v & ~mask) << 1);
        return;
    }
    {
        u32 mask = (1 << ((u8)bit + 1)) - 1;
        u8 v = p[0x120];
        p[0x120] = (v & ((1 << (u8)bit) - 1)) | ((s32)(v & ~mask) >> 1);
    }
}

extern "C" void fn_80170574(u8* p, int unused, u32 idx) {
    u8* obj;
    if (idx >= 8) {
        return;
    }
    obj = ((u8**)(p + 0xdc))[idx];
    if (obj != 0 && *(void**)(obj + 0x20) != 0) {
        fn_801191F0(obj);
    }
}

extern "C" void* lbl_802986F8[];
extern "C" void* fn_801706E4(u8* self, s16 param_2)
{
	if (self != nullptr) {
		s32 i;
		*(void**)self = lbl_802986F8;
		for (i = 0; i < 8; i++) {
			if (self[0x1b0] & (1 << i)) {
				fn_80118BD0(*(void**)(self + 0x16c + i * 4), 1);
			}
			fn_8015AB1C(*(void**)(self + 0x18c + i * 4));
		}
		if (self[0x1b1] != 0) {
			void* p = *(void**)(self + 0x1ac);
			if (p != nullptr) {
				((VObj_8016C34C*)p)->v0(1);
			}
		}
		if (self != nullptr) {
			*(void**)self = lbl_80298B14;
		}
		if (param_2 > 0) {
			fn_8015AB1C(self);
		}
	}
	return self;
}

extern "C" s32 fn_80170D0C(u8* self, u8 count) {
    u8 i;

    for (i = 0; i < count; i++) {
        u32 off;
        u8* obj;

        if (i >= 8) {
            return 0;
        }
        off = (i * 4) + 0x16c;
        if (*(void**)((u32)self + off) == nullptr) {
            obj = (u8*)fn_8015A90C(0x40);
            if (obj != nullptr) {
                obj[0x3b] = obj[0x3b] & 2;
                *(u32*)(obj + 0x28) = 0;
                *(u32*)(obj + 0x20) = 0;
            }
            *(void**)((u32)self + off) = obj;
            if (*(void**)((u32)self + off) == nullptr) {
                return 0;
            }
            self[0x1b0] = self[0x1b0] | (1 << (u8)i);
        }
    }
    return 1;
}

extern "C" int fn_80171640(u8* p, u32 idx, void* val)
{
    int mask;
    if (idx >= 8) {
        return 0;
    }
    if (p[0x1b0] & (mask = 1 << idx)) {
        fn_80118BD0(((void**)(p + 0x16c))[idx], 1);
    }
    ((void**)(p + 0x16c))[idx] = val;
    p[0x1b0] &= ~mask;
    fn_8015AB1C(((void**)(p + 0x18c))[idx]);
    ((void**)(p + 0x18c))[idx] = 0;
    ((u16*)(p + 4))[idx] = 0xFFFF;
    return 1;
}

extern "C" int fn_80171900(u8* p, void* src)
{
    void* obj;
    DtorVObj_80166424* old;
    if (src == 0) {
        return 0;
    }
    obj = fn_8015A90C(0x70);
    if (obj != 0) {
        obj = fn_80119904(obj, src, 0);
    }
    if (obj == 0) {
        return 0;
    }
    if (p[0x1b1]) {
        old = *(DtorVObj_80166424**)(p + 0x1ac);
        if (old != 0) {
            old->Destroy(1);
        }
    }
    *(void**)(p + 0x1ac) = obj;
    p[0x1b1] = 1;
    return 1;
}

#pragma pop
extern "C" int fn_801719B4(u8* p, DtorVObj_80166424* obj) {
    DtorVObj_80166424* old;
    if (obj == 0) {
        return 0;
    }
    if (p[0x1b1]) {
        old = *(DtorVObj_80166424**)(p + 0x1ac);
        if (old != 0) {
            old->Destroy(1);
        }
    }
    *(void**)(p + 0x1ac) = obj;
    p[0x1b1] = 0;
    return 1;
}

extern "C" s32 fn_80171A30(u8* self, u32 a, u32 c)
{
    void* q;
    u8* p;
    u32 idx;

    if (a >= 8) {
        return 0;
    }
    if (c != 0) {
        idx = a * 4;
        p = self + idx;
        if (*(void**)(p + 0x18c) == nullptr) {
            q = fn_8015A90C(0x18);
            if (q != nullptr) {
                fn_80119240(q, a, c);
            }
            *(void**)(p + 0x18c) = q;
            if (*(void**)(p + 0x18c) == nullptr) {
                return 0;
            }
        } else {
            fn_80119240(*(void**)(p + 0x18c), 0, c);
        }
        if (*(void**)(self + idx + 0x16c) != nullptr) {
            fn_80118F5C(*(void**)(self + idx + 0x16c), *(void**)(p + 0x18c));
        }
    } else {
        fn_8015AB1C(*(void**)(self + a * 4 + 0x18c));
        *(void**)(self + a * 4 + 0x18c) = nullptr;
    }
    return 1;
}

extern "C" void fn_801191F0(void* p);
extern "C" void fn_80171B08(u8* p, u32 bit, u8 flag) {
    if (flag != 0) {
        u32 mask = (1 << (u8)bit) - 1;
        u8 v = p[0x1b0];
        p[0x1b0] = (v & mask) | ((v & ~mask) << 1);
        return;
    }
    {
        u32 mask = (1 << ((u8)bit + 1)) - 1;
        u8 v = p[0x1b0];
        p[0x1b0] = (v & ((1 << (u8)bit) - 1)) | ((s32)(v & ~mask) >> 1);
    }
}

extern "C" void fn_80171E5C(u8* p, u32 unused, u32 idx) {
    u8* obj;
    if (idx >= 8) {
        return;
    }
    obj = ((u8**)(p + 0x16c))[idx];
    if (obj != 0 && *(void**)(obj + 0x20) != 0) {
        fn_801191F0(obj);
    }
}

extern "C" void fn_801DE24C(s32);
extern "C" void fn_801698EC(u8* p, s32 x);
extern "C" void fn_8016991C(u8* p, s32 x);
extern "C" void fn_8016994C(u8* p, s32 x);
#pragma dont_inline on
extern "C" void fn_80171FEC(void* param_1)
{
    u8* self = (u8*)param_1;
    u32 i;
    fn_801DE24C(self[4]);
    for (i = 0; (u8)i < self[4]; i++) {
        fn_801698EC(self + 0x10 + (u8)i * 0x1c, i);
    }
    for (i = 0; (u8)i < self[4]; i++) {
        fn_8016991C(self + 0x64 + (u8)i * 2, i);
    }
    for (i = 0; (u8)i < self[4]; i++) {
        fn_8016994C(self + 0x5 + (u8)i * 2, i);
    }
}
#pragma dont_inline reset
extern "C" u8 lbl_80301ADC;
extern "C" void fn_801721F0(u8* p) {
    *p = lbl_80301ADC;
}

extern "C" void* fn_801721FC(void* self) {
    void fn_80172264(void* p, char* q);
    fn_80172264(self, lbl_80202278);
    u8* p = (u8*)self;
    p[7] = (p[7] & ~0x0c) | (((u8)lbl_80301AC8[1]) << 2);
    p[7] = (p[7] & ~3) | lbl_80301AC8[0];
    return self;
}

extern "C" void fn_80172464(void)
{
}

extern "C" u32 fn_80172468(void)
{
    return 0x49424c46;
}

extern "C" void fn_80172474(int param_1, u8 param_2)
{
    *(u8*)(param_1 + 4) = param_2;
}

extern "C" u8 fn_8017247C(int param_1)
{
    return *(u8*)(param_1 + 4);
}

extern "C" u32 fn_801725D8(void) { return 0x54563136; }

extern "C" u32 fn_801725E4(void) { return 0x10; }

extern "C" void fn_801725EC(u8* p, s32 i, u16 v) { ((u16*)(p + 4))[i] = v; }

extern "C" u16 fn_801725FC(u8* p, s32 i) {
    return ((u16*)(p + 4))[i];
}

extern "C" void fn_8017260C(void* param_1, s16 param_2)
{
	*(s16*)((u8*)param_1 + 0x14) = param_2;
}

extern "C" unsigned short fn_80172614(int param_1) {
    return *(unsigned short*)(param_1 + 0x14);
}

extern "C" void fn_8017261C(u8* p1, s32 p2, u8* p3) {
    u8* p = p1 + (p2 << 2);
    u8 a = p3[0];
    p[0x16] = a;
    p[0x17] = p3[1];
    p[0x18] = p3[2];
}

extern "C" s32 fn_80172640(s32 p, s32 i) {
    return p + i * 4 + 0x16;
}

extern "C" int fn_80172680(int param_1, int param_2) {
    return param_1 + param_2 * 8 + 0x56;
}

extern "C" void fn_801726D4(int param_1, int param_2, unsigned char param_3) {
    param_1 = param_1 + param_2;
    *(unsigned char*)(param_1 + 0x108) = param_3;
}

extern "C" unsigned char fn_801726E0(int param_1, int param_2) {
    return ((unsigned char*)param_2 + param_1)[0x108];
}

extern "C" void fn_801726EC(unsigned char* p, int i, unsigned char v) { p += i; p[0x118] = v; }

extern "C" void fn_80172704(u8* param_1, u8 param_2) {
    *(u8*)(param_1 + 0x76) = param_2;
}

extern "C" u8 fn_8017270C(u8* param_1) {
    return *(u8*)(param_1 + 0x76);
}

extern "C" int fn_801727AC(int param_1, int param_2) {
    return param_1 + param_2 + 0x128;
}

extern "C" s32 fn_801727D0(s32 p, s32 i) {
    return p + i * 4 + 0x12c;
}

extern "C" void fn_801727E4(void* self, int a, int b) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
        virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
        virtual void v28();
        virtual void vf7C(int, int, int);
    };
    ((Obj*)self)->vf7C(a, b, 0);
}

extern "C" u32 fn_80172854(u8* param_1) {
    return *(u32*)(param_1 + 0x1ac);
}

extern "C" void fn_8017285C(u8* param_1, u8 param_2) {
    param_1[0x1b0] &= param_2;
}

extern "C" int fn_80172884(void) {
    return 8;
}

extern "C" void fn_8017288C(u8* p, s32 i, u16 v) { ((u16*)(p + 4))[i] = v; }

extern "C" u16 fn_8017289C(u8* p, s32 i) {
    return ((u16*)(p + 4))[i];
}

extern "C" void fn_801728AC(void* param_1, s16 param_2)
{
	*(s16*)((u8*)param_1 + 0x14) = param_2;
}

extern "C" unsigned short fn_801728B4(int param_1) {
    return *(unsigned short*)(param_1 + 0x14);
}

extern "C" s32 fn_801728E0(s32 p, s32 i) {
    return p + i * 4 + 0x16;
}

extern "C" void fn_80172974(u8* p, s32 i, u8 v) {
    p[i + 0xa8] = v;
}

extern "C" u8 fn_80172980(u8* p, s32 i) {
    return p[i + 0xa8];
}

extern "C" void fn_8017298C(u8* p, s32 i, u8 v) {
    p[i + 0xb0] = v;
}

extern "C" unsigned char fn_80172998(int param_1, int param_2) {
    return ((unsigned char*)(param_1 + 0xb0))[param_2];
}

extern "C" void fn_801729A4(int param_1, unsigned char param_2) {
    *(unsigned char*)(param_1 + 0x56) = param_2;
}

extern "C" unsigned char fn_801729AC(int param_1) {
    return *(unsigned char*)(param_1 + 0x56);
}

extern "C" void fn_801729B4(u8* p, s32 i, u8* src) {
    u8* d = p + i * 8;
    d[0x58] = src[1];
    d[0x59] = src[2];
    d[0x5a] = src[3];
    d[0x5c] = src[5];
    d[0x5d] = src[6];
    d[0x5e] = src[7];
}

extern "C" s32 fn_801729F0(s32 p, s32 i) {
    return p + i * 8 + 0x57;
}

extern "C" void fn_80172A04(u8* p, s32 i, s8* src) {
    p += i * 8;
    u8 a = src[0];
    p[0x5e] = (p[0x5e] & ~0xC) | ((u8)src[1] << 2);
    p[0x5e] = (p[0x5e] & ~0x3) | a;
}

extern "C" void fn_80172A3C(u8* p1, s32 p2, u8* p3) {
    p1[p2 + 0xb8] = *p3;
}

extern "C" s32 fn_80172A4C(s32 p1, s32 p2) {
    return p1 + p2 + 0xb8;
}

extern "C" void fn_80172A5C(u8* p1, s32 p2, u32* p3) {
    ((u32*)(p1 + 0xbc))[p2] = *p3;
}

extern "C" s32 fn_80172A70(s32 p, s32 i)
{
    return p + i * 4 + 0xbc;
}

extern "C" void fn_80172A84(void* self, int a, int b) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
        virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
        virtual void v28();
        virtual void vf7C(int, int, int);
    };
    ((Obj*)self)->vf7C(a, b, 0);
}

extern "C" u32 fn_80172AF4(u8* p) {
    return *(u32*)(p + 0x11c);
}

extern "C" s32 fn_80172B18(void) {
    return 0x54564234;
}

extern "C" int fn_80172B24(void) {
    return 4;
}

extern "C" void fn_80172B2C(u8* p, s32 i, u16 v) { ((u16*)(p + 4))[i] = v; }

extern "C" u16 fn_80172B3C(u8* p, s32 i) {
    return ((u16*)(p + 4))[i];
}

extern "C" void fn_80172B4C(u8* p, u16 v) { *(u16*)(p + 0xc) = v; }

extern "C" u16 fn_80172B54(u8* p) { return *(u16*)(p + 0xc); }

extern "C" s32 fn_80172B80(s32 p, s32 i)
{
    return p + i * 4 + 0xe;
}

extern "C" void fn_80172B94(u8* self, s32 idx, s16* src) {
    s16* p = (s16*)(self + (idx << 3));
    p[0xf] = src[0];
    p[0x10] = src[1];
    p[0x11] = src[2];
    p[0x12] = src[3];
}

extern "C" s32 fn_80172BC0(s32 param_1, s32 param_2) {
    return param_1 + param_2 * 8 + 0x1e;
}

extern "C" s32 fn_80172C00(s32 param_1, s32 param_2) {
    return param_1 + param_2 * 4 + 0x60;
}

extern "C" void fn_80172C2C(u8* param_1, u32 param_2, u8 param_3) {
    (param_1 + param_2)[0x74] = param_3;
}

extern "C" u8 fn_80172C38(u8* param_1, u32 param_2) {
    return (param_1 + param_2)[0x74];
}

extern "C" void fn_80172C44(u8* self, u8 v) {
    *(u8*)(self + 0x3e) = v;
}

extern "C" u8 fn_80172C4C(u8* self) {
    return *(u8*)(self + 0x3e);
}

extern "C" void fn_80172C54(s32 param_1, s32 param_2, u8* param_3) {
    u8 uVar1;
    u8 uVar2;
    param_1 = param_1 + param_2 * 8;
    uVar1 = param_3[2];
    *(u8*)(param_1 + 0x40) = param_3[1];
    uVar2 = param_3[3];
    *(u8*)(param_1 + 0x41) = uVar1;
    uVar1 = param_3[5];
    *(u8*)(param_1 + 0x42) = uVar2;
    uVar2 = param_3[6];
    *(u8*)(param_1 + 0x44) = uVar1;
    uVar1 = param_3[7];
    *(u8*)(param_1 + 0x45) = uVar2;
    *(u8*)(param_1 + 0x46) = uVar1;
}

extern "C" s32 fn_80172C90(s32 param_1, s32 param_2) {
    return param_1 + param_2 * 8 + 0x3f;
}

extern "C" void fn_80172CA4(u8* param_1, s32 param_2, u8* param_3) {
    u8* p = param_1 + param_2 * 8;
    u32 b = param_3[1] & 0xff;
    u8 a = param_3[0];
    u8 x = p[0x46];
    p[0x46] = (x & ~0x0c) | (b << 2);
    x = p[0x46];
    p[0x46] = (x & ~3) | a;
}

extern "C" void fn_80172CDC(u8* p, s32 i, u8* src) {
    p[i + 0x78] = *src;
}

extern "C" s32 fn_80172CEC(s32 p, s32 i) {
    return p + i + 0x78;
}

extern "C" void fn_80172CFC(u8* p1, int p2, u32* p3) { ((u32*)(p1 + 0x7c))[p2] = *p3; }

extern "C" s32 fn_80172D10(s32 p, s32 i) {
    return p + i * 4 + 0x7c;
}

extern "C" void fn_80172D24(void* self, int a, int b) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
        virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
        virtual void v28();
        virtual void vf7C(int, int, int);
    };
    ((Obj*)self)->vf7C(a, b, 0);
}

extern "C" s32 fn_80172D94(u8* p) { return *(s32*)(p + 0xac); }

extern "C" u32 fn_80172DBC(void) { return 0x54564232; }

extern "C" int fn_80172DC8(void) {
    return 2;
}

extern "C" void fn_80172DD0(u8* p, s32 i, u16 v) { ((u16*)(p + 4))[i] = v; }

extern "C" u16 fn_80172DE0(u8* p, s32 i) {
    return ((u16*)(p + 4))[i];
}

extern "C" void fn_80172DF0(u8* p, u16 v) { *(u16*)(p + 8) = v; }

extern "C" u16 fn_80172DF8(u8* p) { return *(u16*)(p + 8); }

extern "C" u8* fn_80172E24(u8* p, s32 i) { return p + i * 4 + 10; }

extern "C" u8 fn_80172EC4(u8* p, s32 i) { return *(p + i + 0x54); }

extern "C" void fn_80172ED0(u8* p, s32 i, u8 v) { *(p + i + 0x56) = v; }

extern "C" u8 fn_80172EDC(u8* p, s32 i) { return *(p + i + 0x56); }

extern "C" void fn_80172EE8(u8* p, u8 v) {
    p[0x32] = v;
}

extern "C" u8 fn_80172EF0(u8* p)
{
    return p[0x32];
}

extern "C" void fn_80172EF8(s32 param_1, s32 param_2, u8* param_3) {
    u8 a;
    u8 b;
    param_1 = param_1 + param_2 * 8;
    a = param_3[2];
    *(u8*)(param_1 + 0x34) = param_3[1];
    b = param_3[3];
    *(u8*)(param_1 + 0x35) = a;
    a = param_3[5];
    *(u8*)(param_1 + 0x36) = b;
    b = param_3[6];
    *(u8*)(param_1 + 0x38) = a;
    a = param_3[7];
    *(u8*)(param_1 + 0x39) = b;
    *(u8*)(param_1 + 0x3a) = a;
}

extern "C" s32 fn_80172F34(s32 p, s32 i)
{
    return p + i * 8 + 0x33;
}

extern "C" void fn_80172F48(s32 param_1, s32 param_2, u8* param_3) {
    s32 p = param_1 + param_2 * 8;
    u8 a = param_3[1];
    u8 b = param_3[0];
    *(u8*)(p + 0x3a) = (*(u8*)(p + 0x3a) & ~0x0C) | (a << 2);
    *(u8*)(p + 0x3a) = (*(u8*)(p + 0x3a) & ~3) | b;
}

extern "C" void fn_80172F80(u8* p, s32 i, u8* src) {
    p[i + 0x58] = *src;
}

extern "C" s32 fn_80172F90(s32 p, s32 i) {
    return p + i + 0x58;
}

extern "C" void fn_80172FA0(u8* p, s32 i, u32* src)
{
	((u32*)(p + 0x5c))[i] = *src;
}

extern "C" s32 fn_80172FB4(s32 p, s32 i)
{
	return p + i * 4 + 0x5c;
}

extern "C" void fn_80172FC8(void* self, int a, int b) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
        virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
        virtual void v28();
        virtual void vf7C(int, int, int);
    };
    ((Obj*)self)->vf7C(a, b, 0);
}

extern "C" u32 fn_80172FF8(int param_1, u32 param_2) {
    if (param_2 >= 2) {
        return 0;
    }
    u32* p = (u32*)(param_1 + param_2 * 4);
    return p[0x64 / 4];
}

extern "C" u32 fn_80173018(int param_1, u32 param_2) {
    if (param_2 >= 2) {
        return 0;
    }
    u8* p = (u8*)param_1 + param_2 * 4;
    return *(u32*)(p + 0x6c);
}

extern "C" u32 fn_80173038(u8* p) { return *(u32*)(p + 0x74); }

extern "C" void fn_80173040(void* param_1, u8 param_2) {
    u8 val = *(u8*)((u8*)param_1 + 0x78);
    val &= param_2;
    *(u8*)((u8*)param_1 + 0x78) = val;
}

extern "C" unsigned int fn_80173060(void) {
    return 0x54564231;
}

extern "C" BOOL fn_8017306C(void)
{
    return TRUE;
}

extern "C" void fn_80173074(u8* p, s32 i, u16 v) { ((u16*)(p + 4))[i] = v; }

extern "C" u16 fn_80173084(u8* p, s32 i) {
    return ((u16*)(p + 4))[i];
}

extern "C" void fn_80173094(u8* p, u16 v) { *(u16*)(p + 6) = v; }

extern "C" u16 fn_8017309C(u8* p) { return *(u16*)(p + 6); }

extern "C" void fn_801730A4(int param_1, int param_2, u8* param_3) {
    u8 uVar0 = param_3[0];
    u8* p = (u8*)(param_1 + param_2 * 4);
    p[8] = uVar0;
    p[9] = param_3[1];
    p[10] = param_3[2];
}

extern "C" s32 fn_801730C8(s32 p, s32 i)
{
	return p + i * 4 + 8;
}

extern "C" void fn_801730DC(u8* p, s32 i, s16* src)
{
	s16 v0;
	s16 v1;
	s16 v2;
	s16 v3;
	s16* q;

	v0 = src[0];
	q = (s16*)(p + i * 8);
	v1 = src[1];
	q[6] = v0;
	v2 = src[2];
	q[7] = v1;
	v3 = src[3];
	q[8] = v2;
	q[9] = v3;
}

extern "C" u8* fn_80173108(u8* p, s32 i)
{
    return p + i * 8 + 0xc;
}

extern "C" void fn_8017311C(u8* p, s32 i, u8* src)
{
    u8* dst = p + i * 4;
    dst[0x34] = src[0];
    dst[0x35] = src[1];
    dst[0x36] = src[2];
    dst[0x37] = src[3];
}

extern "C" void fn_8017318C(void)
{
}

extern "C" BOOL fn_80173190(void)
{
    return TRUE;
}

extern "C" void fn_80173268(void* self, int a, int b) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
        virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
        virtual void v28();
        virtual void vf7C(int, int, int);
    };
    ((Obj*)self)->vf7C(a, b, 0);
}

extern "C" u32 fn_801732D8(void* param_1) {
    return *(u32*)((u8*)param_1 + 0x58);
}

extern "C" void fn_801732E0(void* param_1, u8 param_2) {
    u8 val = *(u8*)((u8*)param_1 + 0x5c);
    val &= param_2;
    *(u8*)((u8*)param_1 + 0x5c) = val;
}

extern "C" void fn_801732F0(void* param_1) {
    u8 val = *(u8*)((u8*)param_1 + 0x5c);
    val &= 0x7f;
    *(u8*)((u8*)param_1 + 0x5c) = val;
}

extern "C" void fn_80173300(void)
{
}

extern "C" void fn_80173304(void)
{
}

extern "C" void fn_80173308(void)
{
}

extern "C" void fn_8017330C(void)
{
}

extern "C" void fn_80173310(void)
{
}

extern "C" void fn_80173314(void)
{
}

extern "C" void fn_80173318(void) {
}

extern "C" void fn_8017331C(void) {}

extern "C" void fn_80173320(void) {}

extern "C" void fn_80173324(void) {}

extern "C" void fn_80173328(void) {}

extern "C" int fn_8017332C()
{
	return 0;
}

extern "C" int fn_80173334()
{
	return 0;
}

extern "C" int fn_8017333C()
{
	return 0;
}

extern "C" int fn_80173344()
{
	return 0;
}

extern "C" int fn_8017334C()
{
	return 0;
}

extern "C" int fn_80173354()
{
	return 0;
}

extern "C" int fn_8017335C()
{
	return 0;
}

extern "C" int fn_80173364()
{
	return 0;
}

extern "C" int fn_8017336C()
{
	return 0;
}

extern "C" int fn_80173374()
{
	return 0;
}

extern "C" int fn_8017337C()
{
	return 0;
}

extern "C" void fn_80173384(void)
{
}

extern "C" void fn_80173388(void) {}

extern "C" void fn_8017338C(void) {}

extern u32 lbl_80301AF0;
extern "C" u32 lbl_80301AF0;
extern "C" void fn_80173F24(Rgba4_80166424* dst, u8* src, s32 i, s32 j) {
    u32 tmp = lbl_80301AF0;
    Rgba4_80166424 d = *(Rgba4_80166424*)&tmp;
    u16 v = ((u16*)*(u8**)(src + 8))[i];
    u16 w = *(u16*)(*(u8**)(src + 4) + v * 0xe8 + 8 + j * 2);
    if (w != 0xffff) {
        u32 t = ((u32*)*(u8**)(src + 0x10))[w];
        *dst = *(Rgba4_80166424*)&t;
        return;
    }
    *(u32*)dst = *(u32*)&d;
}

extern "C" int fn_80173FC0(int p, int i)
{
	u8 b = *(u8*)(*(int*)(p + 4) + (*(u16*)(*(int*)(p + 8) + i * 2)) * 0xe8 + 2);
	if (b != 0xff) {
		return *(u8*)(*(int*)(p + 0x14) + b);
	}
	return 0;
}

extern u8 lbl_80301AD8;
extern "C" void fn_80173FF8(u16* out, int p, int i, int j)
{
	u16 v = *(u16*)(*(int*)(p + 4) + (*(u16*)(*(int*)(p + 8) + i * 2)) * 0xe8 + 0xc + j * 2);
	if (v != 0xffff) {
		*out = *(u8*)(*(int*)(p + 0x18) + (u32)v * 4 + 1);
		return;
	}
	*out = *(u8*)((u8*)&lbl_80301AD8 + 1);
}

extern "C" int fn_8017404C(int p, int i)
{
	u8 b = *(u8*)(*(int*)(p + 4) + (*(u16*)(*(int*)(p + 8) + i * 2)) * 0xe8 + 3);
	if (b != 0xff) {
		return *(u8*)(*(int*)(p + 0x1c) + b);
	}
	return 0;
}

extern const u8 lbl_80202218[];
extern "C" void fn_80174084(u8* p, u8* s, u32 a, u32 b) {
    u16 row = ((u16*)*(u8**)(s + 8))[a];
    u16* tbl = (u16*)(*(u8**)(s + 4) + row * 0xe8 + 0x14);
    u16 idx = tbl[b];
    if (idx != 0xffff) {
        u8* t = *(u8**)(s + 0x20) + idx * 4;
        p[0] = t[0];
        p[1] = t[1];
        p[2] = t[2];
    } else {
        p[0] = lbl_80202218[0];
        p[1] = lbl_80202218[1];
        p[2] = lbl_80202218[2];
    }
}

extern "C" u8 fn_801741E4(u8* p, s32 idx)
{
    u16* ids = *(u16**)(p + 8);
    u8* tbl = *(u8**)(p + 4);
    u8 v = *(tbl + (ids[idx] * 0xe8 + 1));
    if (v != 0xff) {
        u32* arr = *(u32**)(p + 0x30);
        return arr[v];
    }
    return 0xff;
}

extern "C" u16 fn_80174224(u8* s, u32 a, u32 b) {
    u16 row = ((u16*)*(u8**)(s + 8))[a];
    u16* tbl = (u16*)(*(u8**)(s + 4) + row * 0xe8 + 0x38);
    u16 idx = tbl[b];
    if (idx != 0xffff) {
        return ((u16*)*(u8**)(s + 0x28))[idx];
    }
    return 0xffff;
}

extern "C" u16 fn_8017426C(u8* s, u32 a) {
    u16 row = ((u16*)*(u8**)(s + 8))[a];
    u16 idx = *(u16*)(*(u8**)(s + 4) + row * 0xe8 + 0x48);
    if (idx != 0xffff) {
        return ((u16*)*(u8**)(s + 0x2c))[idx];
    }
    return 0xffff;
}

extern "C" u8 lbl_80301AB0[4];
extern "C" void fn_801742AC(u8* p, u8* s, u32 a, u32 b) {
    u16 row = ((u16*)*(u8**)(s + 8))[a];
    u16* tbl = (u16*)(*(u8**)(s + 4) + row * 0xe8 + 0x72);
    u16 idx = tbl[b];
    if (idx != 0xffff) {
        u8* t = *(u8**)(s + 0x34) + idx * 4;
        p[0] = t[0];
        p[1] = t[1];
        p[2] = t[2];
    } else {
        p[0] = lbl_80301AB0[0];
        p[1] = lbl_80301AB0[1];
        p[2] = lbl_80301AB0[2];
    }
}

extern "C" void fn_80174320(s16* out, u8* p, u32 index, u32 subindex) {
    s16 fallback[4];
    u16* table = *(u16**)(p + 8);
    u8* base = *(u8**)(p + 4);
    *(u32*)fallback = lbl_80302388;
    *(u32*)(fallback + 2) = lbl_8030238C;
    u16 uVar1 = *(u16*)(base + (table[index] * 0xe8 + 0x92 + subindex * 2));
    if (uVar1 != 0xffff) {
        s16* entry = (s16*)(*(u8**)(p + 0x38) + uVar1 * 8);
        out[0] = entry[0];
        out[1] = entry[1];
        out[2] = entry[2];
        out[3] = entry[3];
    } else {
        out[0] = fallback[0];
        out[1] = fallback[1];
        out[2] = fallback[2];
        out[3] = fallback[3];
    }
}

extern "C" void fn_801743B8(u32* out, u8* p, u32 index, u32 subindex) {
    u16* table = *(u16**)(p + 8);
    u8* base = *(u8**)(p + 4);
    u16 uVar1 = *(u16*)(base + (table[index] * 0xe8 + 0x4a + subindex * 2));
    if (uVar1 != 0xffff) {
        *out = *(u32*)(*(u8**)(p + 0x3c) + (u16)uVar1 * 4);
    } else {
        *out = lbl_80301AF4;
    }
}

extern "C" u8 fn_80174454(u8* param_1, u32 param_2) {
    u8* base = *(u8**)(param_1 + 4);
    u16* table = *(u16**)(param_1 + 8);
    u32 off = table[param_2] * 0xe8;
    u8 bVar1 = base[off + 4];
    if (bVar1 != 0xff) {
        return (*(u8**)(param_1 + 0x40))[bVar1];
    }
    return 0xff;
}

extern "C" void fn_8017448C(u8* p, u8* s, u32 a, u32 b) {
    u16* table = *(u16**)(s + 8);
    u16 row = table[a];
    u16* tbl = (u16*)(*(u8**)(s + 4) + row * 0xe8 + 0x9a);
    u16 idx = tbl[b];
    if (idx != 0xffff) {
        fn_801749F0(p, *(u8**)(s + 0x44) + idx * 0x14);
    } else {
        fn_801721FC(p);
    }
}

extern "C" u8 lbl_80301ACC[4];
extern "C" void fn_801744EC(u8* p, u8* s, u32 a, u32 b) {
    u16 row = ((u16*)*(u8**)(s + 8))[a];
    u16* tbl = (u16*)(*(u8**)(s + 4) + row * 0xe8 + 0xda);
    u16 idx = tbl[b];
    if (idx != 0xffff) {
        u8* t = *(u8**)(s + 0x4c) + idx * 4;
        p[0] = ((u8)t[0] << 6) + ((u8)t[1] << 4) + ((u8)t[2] << 2) + (u8)t[3];
    } else {
        p[0] = ((u8)lbl_80301ACC[0] << 6) + ((u8)lbl_80301ACC[1] << 4) + ((u8)lbl_80301ACC[2] << 2) + (u8)lbl_80301ACC[3];
    }
}

extern "C" void* fn_801749F0(void* p, void* q);
extern "C" u8 lbl_80301AB4[];
extern "C" u8 lbl_80301AC8[2];
extern "C" u8 fn_80174588(u8* p, u32 n) {
    if (*(u8**)(p + 0xc) != nullptr && (*(u8**)(p + 0xc))[n * 0x128] == 1) {
        return (*(u8**)(p + 0xc))[n * 0x128 + 1];
    }
    return 0;
}

extern "C" void fn_801745B8(u8* out, u8* p, u32 index, u32 subindex) {
    u8 fallback[2];
    fallback[0] = lbl_80301AB4[0];
    fallback[1] = lbl_80301AB4[1];
    u8* data = *(u8**)(p + 0xc);
    if (data != nullptr && data[index * 0x128] == 1) {
        u8* entry = data + index * 0x128 + subindex * 2 + 4;
        out[0] = entry[0];
        out[1] = entry[1];
    } else {
        *(u16*)out = *(u16*)fallback;
    }
}

extern "C" Rec_80174620 fn_80174620(Owner_80174620* owner, int slot, int idx) {
    Rec_80174620 def = lbl_8020225C;
    Slot_80174620* slots = owner->slots;
    if (slots != nullptr) {
        Slot_80174620* s = &slots[slot];
        if (s->active == 1) {
            return s->recs[idx];
        }
    }
    return def;
}

extern "C" void fn_80174858(Unk80174858Pair* out, void* ptr, u32 index, u32 subindex) {
    Unk80174858Pair fallback;
    fallback.x = lbl_80301AC0[0];
    fallback.y = lbl_80301AC0[1];
    u8* data = *(u8**)((u8*)ptr + 0xc);
    if (data != nullptr && data[index * 0x128] == 1) {
        Unk80174858Pair* entry = (Unk80174858Pair*)(data + index * 0x128 + subindex * 2 + 0x60);
        out->x = entry->x;
        out->y = entry->y;
    } else {
        *(u16*)out = *(u16*)&fallback;
    }
}

extern "C" u16 lbl_80301ADE;
extern "C" void fn_801748C0(u16* out, void* ptr, u32 index) {
    u8* data = *(u8**)((u8*)ptr + 4);
    u16* indices = *(u16**)((u8*)ptr + 8);
    u16 value = *(u16*)(data + indices[index] * 0xe8 + 0xe2);
    if (value != 0xffff) {
        u8* entry = *(u8**)((u8*)ptr + 0x50) + (u16)value * 8;
        out[0] = ((u8)entry[0] << 5 | (u8)entry[2] << 3) | entry[3];
        ((u8*)out)[2] = entry[1];
        ((u8*)out)[3] = entry[4];
    } else {
        out[0] = lbl_80301ADE;
        ((u8*)out)[2] = 0;
        ((u8*)out)[3] = 0;
    }
}

extern "C" void* fn_801749F0(void* param_1, void* param_2) {
    u8* p = (u8*)param_1;
    fn_80172264(param_1);
    p[7] = (p[7] & ~0x0c) | (((u8)lbl_80301AC8[1]) << 2);
    p[7] = (p[7] & ~3) | lbl_80301AC8[0];
    return param_1;
}

extern "C" void* fn_80174A50(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174A68(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174A80(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174A98(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174AB0(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174AC8(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174AE0(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174AF8(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174B10(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174B28(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174B40(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174B58(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174B70(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174B88(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174BA0(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174BB8(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern void* lbl_80298C5C[];
extern "C" void* fn_80174C64(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80298C5C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* lbl_802FF540;
extern "C" void* lbl_802FF690;
extern "C" void* lbl_802FF698;
extern "C" u8 lbl_802FF694;
extern "C" int fn_8015AAB0(void*, void*, int);
extern "C" void* fn_80174E9C(void* param_1) {
    void* old = lbl_802FF690;
    if (lbl_802FF694 != 0) {
        fn_8015AB1C(lbl_802FF690);
    }
    lbl_802FF690 = (void*)fn_8015AAB0(param_1, lbl_802FF540, 0);
    lbl_802FF698 = param_1;
    lbl_802FF694 = 1;
    return old;
}

extern "C" void fn_80174F08(u8* p)
{
    if (*(VObj_80174F08**)(p + 4) != 0) {
        *(f32*)(p + 0x50) = (f32)(*(VObj_80174F08**)(p + 4))->vf10();
        *(f32*)(p + 0x54) = (f32)(*(VObj_80174F08**)(p + 4))->vf11();
    }
}

extern "C" void fn_80174FA0(void* param_1, f32 param_2, f32 param_3)
{
	f32 c;
	*(f32*)((u8*)param_1 + 0x24) = param_2;
	c = lbl_80301AF8;
	*(f32*)((u8*)param_1 + 0x28) = param_3;
	*(f32*)((u8*)param_1 + 0x2c) = param_2;
	*(f32*)((u8*)param_1 + 0x30) = param_3;
	*(f32*)((u8*)param_1 + 0x34) = c;
}

extern "C" void fn_80176294(void* param_1)
{
	u8* p = (u8*)param_1;
	*(u8*)(p + 0x8) = *(u8*)(p + 0x40);
	*(u8*)(p + 0x9) = *(u8*)(p + 0x41);
	*(u8*)(p + 0xa) = *(u8*)(p + 0x42);
	*(u8*)(p + 0xb) = *(u8*)(p + 0x43);
	*(u8*)(p + 0xc) = *(u8*)(p + 0x44);
	*(u8*)(p + 0xd) = *(u8*)(p + 0x45);
	*(u8*)(p + 0xe) = *(u8*)(p + 0x46);
	*(u8*)(p + 0xf) = *(u8*)(p + 0x47);
	*(f32*)(p + 0x10) = *(f32*)(p + 0x48);
	*(f32*)(p + 0x14) = *(f32*)(p + 0x4c);
	*(u8*)(p + 0x22) = *(u8*)(p + 0x5a);
	*(s16*)(p + 0x20) = *(s16*)(p + 0x58);
	*(f32*)(p + 0x18) = *(f32*)(p + 0x50);
	*(f32*)(p + 0x1c) = *(f32*)(p + 0x54);
}

extern "C" void fn_80166C70(void* p);
extern "C" void* fn_80176550(void* param_1)
{
	u8* sub;
	u8* self = (u8*)param_1;
	sub = self + 0xdc;
	*(void**)self = (void*)lbl_80298C88;
	fn_80166C70(sub);
	fn_80166B58((u32*)(sub + 0xc), (u32)self);
	*(u32*)(self + 0xf8) = 0;
	*(u32*)(self + 0x8) = 0x50414e31;
	*(u8*)(self + 0xb0) = 1;
	*(u32*)(self + 0x14) = 0;
	*(u32*)(self + 0x10) = 0;
	*(u32*)(self + 0x1c) = 0;
	*(u32*)(self + 0x18) = 0;
	*(f32*)(self + 0x20) = lbl_80301B20;
	*(f32*)(self + 0x24) = lbl_80301B20;
	*(f32*)(self + 0x28) = lbl_80301B20;
	*(f32*)(self + 0x2c) = lbl_80301B20;
	fn_80176610(self);
	fn_80176E24(self, 0);
	((UnkVObj_80166424*)self)->vf9();
	return self;
}

extern f32 lbl_80301B20;
extern f32 lbl_80301B24;
extern "C" void fn_80176610(void* p_self)
{
    u32* self = (u32*)p_self;
    u8* b = (u8*)p_self;
    f32 f0 = lbl_80301B24;
    f32 f1 = lbl_80301B20;

    *(u16*)(b + 0x4) = 0xffff;
    ((f32*)self)[0x2e] = f1;
    ((f32*)self)[0x2f] = f1;
    ((f32*)self)[0x30] = f1;
    ((f32*)self)[0x31] = f1;
    ((f32*)self)[0x32] = f1;
    b[0xb7] = 0;
    b[0xb6] = 0x7a;
    ((f32*)self)[0x33] = f0;
    ((f32*)self)[0x34] = f0;
    b[0xb1] = 0;
    b[0xb2] = 0xff;
    b[0xb4] = 1;
    b[0xb3] = 0xff;
    b[0xb5] = 0;
    ((void (*)(void*))((u32**)self)[0][11])(p_self);
}

#pragma push
#pragma use_lmw_stmw off
extern "C" void* fn_80176698(void* p_self, void* p_other, u8 b, u32 r6, u32 c, u32 d, f32* f)
{
    u32 unused;
    u32* self = (u32*)p_self;
    u8* sub = (u8*)p_self + 0xdc;
    *(void**)p_self = lbl_80298C88;
    fn_80166C70(sub);
    fn_80166B58((u32*)(sub + 0xc), (u32)p_self);
    self[0x3e] = 0;
    fn_80176728(p_self, p_other, b, unused, c, d, f);
    return p_self;
}
#pragma use_lmw_stmw off
extern "C" void* fn_80176848(void* p_self, u32 unused, u32 a, u32 b, u32 c)
{
    u32* self = (u32*)p_self;
    u8* sub = (u8*)p_self + 0xdc;
    *(void**)p_self = lbl_80298C88;
    fn_80166C70(sub);
    fn_80166B58((u32*)(sub + 0xc), (u32)p_self);
    self[0x3e] = 0;
    fn_801768C8(p_self, a, b, c);
    return p_self;
}

#pragma dont_inline on
extern "C" void* fn_80176FE8(u8* self, s16 param_2) {
    if (self) {
        *(void**)self = (void*)lbl_80298C88;
        u8* p = *(u8**)(self + 0xdc);
        if (p) {
            p -= 0xc;
        }
        while (p) {
            u8* next = *(u8**)(p + 0x18);
            if (next) {
                next -= 0xc;
            }
            VObj_8016C34C* child = *(VObj_8016C34C**)(p + 0xc);
            p = next;
            if (child) {
                child->v0(1);
            }
        }
        if (self + 0xdc) {
            if (self + 0xe8) {
                fn_80166B70(self + 0xe8, 0);
            }
            if (self + 0xdc) {
                fn_80166C08(self + 0xdc, 0);
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(self);
        }
    }
    return self;
}
#pragma dont_inline reset
extern "C" void fn_80177970(void* self, f32 a, f32 b) {
    f32 w = *(f32*)((char*)self + 0x28) - *(f32*)((char*)self + 0x20);
    f32 h = *(f32*)((char*)self + 0x2c) - *(f32*)((char*)self + 0x24);
    f32 rect[4];
    rect[0] = a;
    rect[1] = b;
    rect[2] = a + w;
    rect[3] = b + h;
    fn_80177728(self, rect);
}

extern "C" void fn_801779C4(void* self, f32 a, f32 b) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
        virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
        virtual void vf2c();
    };
    *(f32*)((char*)self + 0xd4) += a;
    *(f32*)((char*)self + 0xd8) += b;
    ((Obj*)self)->vf2c();
}

extern "C" f32 lbl_802EE358[];
extern "C" void* fn_80178494(void* self, u32 v, f32 a, f32 b, f32 c, f32 d, f32 e);
extern "C" void* fn_80177B10(void* self) {
    u32 v;
    f32* lbl = lbl_802EE358;
    v = *(u32*)((u8*)self + 0x28);
    *(u32*)&lbl[0] = *(u32*)((u8*)self + 0x20);
    *(u32*)&lbl[1] = *(u32*)((u8*)self + 0x24);
    *(u32*)&lbl[2] = v;
    *(u32*)&lbl[3] = *(u32*)((u8*)self + 0x2c);
    lbl[0] = lbl[0] + *(f32*)((u8*)self + 0xd4);
    lbl[1] = lbl[1] + *(f32*)((u8*)self + 0xd8);
    lbl[2] = lbl[2] + *(f32*)((u8*)self + 0xd4);
    lbl[3] = lbl[3] + *(f32*)((u8*)self + 0xd8);
    if (fn_80178494(self, v, lbl[2], lbl[1], lbl[0], *(f32*)((u8*)self + 0xd4), *(f32*)((u8*)self + 0xd8)) != nullptr) {
    }
    return lbl;
}

extern "C" void fn_80177BF0(void* self, s8 flag, f32 a, f32 b, f32 c) {
    *(f32*)((char*)self + 0xc4) = a;
    *(f32*)((char*)self + 0xc8) = b;
    *(s8*)((char*)self + 0xb6) = flag;
    fn_80177C20(self, c);
}

extern "C" void fn_80177C20(void* param_1, f32 v) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
        virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void vf2c();
        u8 pad[0xb2];
        s8 axis;
        u8 pad2;
        f32 x;
        f32 y;
        f32 z;
    };
    Obj* o = (Obj*)param_1;
    if (o->axis == 'x') {
        o->x = v;
    } else if (o->axis == 'y') {
        o->y = v;
    } else {
        o->z = v;
    }
    o->vf2c();
}

extern "C" f32 fn_80177C78(void* self) {
    s8 axis = *(s8*)((char*)self + 0xb6);
    if (axis == 'x') {
        return *(f32*)((char*)self + 0xb8);
    } else if (axis == 'y') {
        return *(f32*)((char*)self + 0xbc);
    }
    return *(f32*)((char*)self + 0xc0);
}

extern "C" void fn_80177CA8(void* self, f32* r) {
    f32* p = (f32*)self;
    f32 t[4];
    t[0] = r[0];
    t[1] = r[1];
    t[2] = r[2];
    t[3] = r[3];
    t[0] += p[12];
    t[2] += p[12];
    t[1] += p[13];
    t[3] += p[13];
    if (p[16] <= t[0]) p[16] = t[0];
    if (p[17] <= t[1]) p[17] = t[1];
    if (p[18] >= t[2]) p[18] = t[2];
    if (p[19] >= t[3]) p[19] = t[3];
}

extern "C" void* fn_80177D24(char* self, u64 id)
{
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
        virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
        virtual void v10(); virtual void v11(); virtual void v12();
        virtual void* vf3c(u64 id);
    };
    char* n;
    void* r;
    if (id == *(u64*)(self + 0x10)) {
        return self;
    }
    n = *(char**)(self + 0xdc);
    if (n != 0) {
        n -= 0xc;
    }
    while (n != 0) {
        r = (*(Obj**)(n + 0xc))->vf3c(id);
        if (r != 0) {
            return r;
        }
        n = *(char**)(n + 0x18);
        if (n != 0) {
            n -= 0xc;
        }
    }
    return 0;
}

extern "C" void* fn_80177DD4(char* self, u64 id)
{
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
        virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
        virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
        virtual void* vf40(u64 id);
    };
    char* n;
    void* r;
    if (id == *(u64*)(self + 0x18)) {
        return self;
    }
    n = *(char**)(self + 0xdc);
    if (n != 0) {
        n -= 0xc;
    }
    while (n != 0) {
        r = (*(Obj**)(n + 0xc))->vf40(id);
        if (r != 0) {
            return r;
        }
        n = *(char**)(n + 0x18);
        if (n != 0) {
            n -= 0xc;
        }
    }
    return 0;
}

extern "C" u8 fn_80177E84(char* self, void* arg)
{
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
        virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
        virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
        virtual void v15(); virtual void v16();
        virtual u8 vf4c(void* arg);
    };
    char* n = *(char**)(self + 0xdc);
    if (n != 0) {
        n -= 0xc;
    }
    while (n != 0) {
        if ((*(Obj**)(n + 0xc))->vf4c(arg)) {
            return 1;
        }
        n = *(char**)(n + 0x18);
        if (n != 0) {
            n -= 0xc;
        }
    }
    return 0;
}

extern "C" u8 fn_80177F0C(char* self, void* arg)
{
    char* n = *(char**)(self + 0xdc);
    if (n != 0) {
        n -= 0xc;
    }
    while (n != 0) {
        if ((*(UnkVObj_80166424**)(n + 0xc))->vf18(arg)) {
            return 1;
        }
        n = *(char**)(n + 0x18);
        if (n != 0) {
            n -= 0xc;
        }
    }
    return 0;
}

extern "C" void fn_801780D4(char* self, u8 v)
{
    char* n;
    *(u8*)(self + 0xb1) = v;
    n = *(char**)(self + 0xdc);
    if (n != 0) {
        n -= 0xc;
    }
    while (n != 0) {
        (*(UnkVObj_80166424**)(n + 0xc))->vf6(v);
        n = *(char**)(n + 0x18);
        if (n != 0) {
            n -= 0xc;
        }
    }
}

extern f32 lbl_80301B38;
extern "C" void fn_8017814C(void* p, s32 arg1) {
    VObj_8017814C* self = (VObj_8017814C*)p;
    s32 temp_r0;
    u32 temp_r0_2;
    *(u8*)((u8*)self + 0xb7) = arg1;
    *(u8*)((u8*)self + 0xb6) = 0x7A;
    *(f32*)((u8*)self + 0xc4) = lbl_80301B20;
    temp_r0 = arg1 % 3;
    if (temp_r0 == 1) {
        *(f32*)((u8*)self + 0xc4) = (*(f32*)((u8*)self + 0x28) - *(f32*)((u8*)self + 0x20)) * lbl_80301B38;
    } else if (temp_r0 == 2) {
        *(f32*)((u8*)self + 0xc4) = *(f32*)((u8*)self + 0x28) - *(f32*)((u8*)self + 0x20);
    }
    *(f32*)((u8*)self + 0xc8) = lbl_80301B20;
    temp_r0_2 = arg1 / 3;
    if ((s32)temp_r0_2 == 1) {
        *(f32*)((u8*)self + 0xc8) = (*(f32*)((u8*)self + 0x2c) - *(f32*)((u8*)self + 0x24)) * lbl_80301B38;
    } else if ((s32)temp_r0_2 == 2) {
        *(f32*)((u8*)self + 0xc8) = *(f32*)((u8*)self + 0x2c) - *(f32*)((u8*)self + 0x24);
    }
    self->v9();
}

extern "C" void* fn_80178424(char* self)
{
    char* l = *(char**)(self + 0xdc);
    char* n = l;
    if (l != 0) {
        n = l - 0xc;
    }
    if (n == 0) {
        return 0;
    }
    if (l != 0) {
        l -= 0xc;
    }
    return *(void**)(l + 0xc);
}

extern "C" void fn_801788C0(VObj_801788C0* self, Msg_801788C0* p)
{
    if (p != nullptr) {
        switch (p->kind) {
        case 0:
            self->v22();
            break;
        case 1:
            self->v23();
            break;
        case 7:
            self->v28();
            break;
        case 4:
            self->v25();
            break;
        case 2:
            self->v24();
            break;
        case 6:
            self->v27();
            break;
        case 5:
            self->v26();
            break;
        case 3:
        default:
            break;
        }
    }
}

extern "C" void fn_80178990(u8* p, u32 v) { *(u32*)(p + 0xf8) = v; }

extern "C" void fn_80178DA4(void* param_1)
{
}

extern "C" void fn_80178DA8(void)
{
}

extern "C" void fn_80178DAC(void)
{
}

extern "C" void fn_80178DB0(void* param_1) {
    register void* vtable = *(void**)param_1;
    void (*func)(void) = *(void(**)(void))((u8*)vtable + 0x74);
    func();
}

extern "C" u32 fn_80178E08(void) { return 0x10; }

extern "C" void fn_80178E10(VObj_80178E10* self, u8 flag) {
    int mode = 0;
    if (flag) {
        mode = 2;
    }
    self->vf20(mode);
}

extern "C" int fn_80178E4C(int param_1) {
    *(u8*)(param_1 + 0xb5) = 0;
    return 0;
}

extern "C" void fn_80178E5C(void* param_1)
{
}

extern "C" void fn_80178E60(void) {
}

