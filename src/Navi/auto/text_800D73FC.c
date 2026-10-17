#include "types.h"
extern "C" void fn_800E927C(u8* p);
extern "C" s32 fn_800EE044(void);
extern "C" void fn_8002F358(s32, s32);
extern "C" void fn_8017A4F8(void* p);
extern "C" char lbl_802B7CA0[];
extern "C" void fn_80060794(void*, void*, void*, void*);
struct VObj_800A1A64 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800d73fc-0x800ee3f0 (167 functions). split_file divides it into the game's real files.

extern void* lbl_8028B80C[];
extern "C" char lbl_802BB0FC[];
extern "C" void fn_8015AB1C(void* ptr);
extern char lbl_802B7CA0[];
extern f32 lbl_80301058;
extern "C" void fn_80179CB4(void*, void*, f32, f32);
extern "C" void fn_8015FDA8(void*, void*);
extern "C" int fn_8002F0A8(int);
struct NaviSlot_802C04D0 {
    s32 bit;
    s32 unk4;
    s32 id;
};
extern NaviSlot_802C04D0 lbl_802C04D0[];
extern "C" u32 lbl_8028A8D8[];
extern "C" int fn_80057530(int id);
extern "C" s32 fn_800EE044(void);
extern "C" void fn_8002F458(s32 a, s32 b);
extern "C" void fn_800E7F50(void*, s32, s32, s32);
extern char lbl_802C57D4[];
extern "C" s32 fn_800ECFD0(void*, s32, u8, s32, s32, f32, f32);
extern "C" void fn_8002F358(s32 a, s32 b);
extern "C" void fn_800EBD88(char* p);
extern "C" BOOL fn_800DDA6C(void* p, u8* src) {
    u8* c = (u8*)p;
    u8 a;
    u8 b;
    b = src[1];
    c[0x128] = src[0];
    a = src[2];
    c[0x129] = b;
    b = src[3];
    c[0x12a] = a;
    c[0x12b] = b;
    return 1;
}

extern "C" void fn_800E29F4(u8* p);
extern "C" void fn_800E29CC(u8* p) {
    p[0xb11] = 0;
    fn_800E29F4(p);
}

extern "C" void fn_800E347C(u8* p) {
    s32 i;
    for (i = 0; i < 4; i++) {
        p[0xa78 + i] = 0xff;
        if (*(u32*)(lbl_802B7CA0 + 0x3448) & (1 << i)) {
            p[0xa78 + i] = fn_80057530(i);
        }
    }
}

extern "C" s32 fn_800E3638(void* param_1, s32 param_2) {
    NaviSlot_802C04D0* s = lbl_802C04D0;
    u32 flags = *(u32*)(lbl_802B7CA0 + 0x3448);
    s32 i;
    for (i = 0; i < 4; s++, i++) {
        if (flags & (1 << s->bit)) {
            if (param_2 == s->id) {
                return lbl_802C04D0[i].bit;
            }
        }
    }
    return -1;
}

extern "C" void fn_800E38B8(void) {}

extern "C" void fn_800E3EF0(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0xa9c) != 0) {
        *(u16*)((u8*)param_1 + 0xa9c) = *(u16*)((u8*)param_1 + 0xa9c) - 1;
        return;
    }
    *(u8*)((u8*)param_1 + 0xa76) = 0;
    *(u32*)(lbl_802BB0FC + 0x100) |= 0x4;
}

extern "C" void fn_800E3F28(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0xa9c) != 0) {
        *(u16*)((u8*)param_1 + 0xa9c) = *(u16*)((u8*)param_1 + 0xa9c) - 1;
        return;
    }
    *(u8*)((u8*)param_1 + 0xa76) = 0x14;
}

extern "C" void fn_800E3F4C(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0xa9c) != 0) {
        *(u16*)((u8*)param_1 + 0xa9c) = *(u16*)((u8*)param_1 + 0xa9c) - 1;
        return;
    }
    *(u8*)((u8*)param_1 + 0xb11) = 2;
    *(u16*)((u8*)param_1 + 0xa9c) = 10;
    *(u8*)((u8*)param_1 + 0xa76) = 0x15;
}

extern "C" void fn_800E3F80(void* param_1) {
    u8* p = (u8*)param_1;
    u16 v = *(u16*)(p + 0xa9c);
    if (v != 0) {
        *(u16*)(p + 0xa9c) = v - 1;
        return;
    }
    if (fn_800EE044() != 0) {
        fn_8002F358(0xa5, 0);
        p[0xb11] = 1;
        *(u16*)(p + 0xa9c) = 10;
        p[0xa76] = 0x16;
    }
}

extern "C" void fn_800E3FF0(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0xa9c) != 0) {
        *(u16*)((u8*)param_1 + 0xa9c) = *(u16*)((u8*)param_1 + 0xa9c) - 1;
        return;
    }
    *(u8*)((u8*)param_1 + 0xa76) = 0;
    *(u32*)(lbl_802BB0FC + 0x100) |= 0x800;
}

extern "C" void fn_800E41F8(u8* p) {
    if (*(u16*)(p + 0xa9c) != 0) {
        *(u16*)(p + 0xa9c) = *(u16*)(p + 0xa9c) - 1;
    } else {
        fn_8002F0A8(lbl_8028A8D8[*(u32*)(lbl_802BB0FC + 0x420)]);
        *(u32*)(lbl_802BB0FC + 0xf8) |= 0x20000000;
        *(u16*)(p + 0xa9c) = 0x78;
        p[0xa76] = 0x1a;
    }
}

extern "C" void fn_800E46F4(void* param_1) {
    u8* p = (u8*)param_1;
    if (*(u16*)(p + 0xa9c) != 0) {
        *(u16*)(p + 0xa9c) = *(u16*)(p + 0xa9c) - 1;
    }
    s32 r = fn_800ECFD0(param_1, *(s16*)(p + 0xb12), (u8)lbl_802C57D4[0x18], 0, 0, *(f32*)(lbl_802C57D4 + 0x20), lbl_80301058);
    *(s16*)(p + 0xb12) = *(s16*)(p + 0xb12) + 1;
    if (r == 1 && *(u16*)(p + 0xa9c) == 0) {
        if (*(s32*)(lbl_802BB0FC + 0x3f0) == 0x64) {
            p[0x5dc] = 1;
        }
        *(u16*)(p + 0xb12) = 0;
        *(u16*)(p + 0xa9c) = (u8)lbl_802C57D4[0x93];
        p[0xa76] = 0x1d;
    }
}

extern "C" s32 fn_80030668(s32);
extern "C" void fn_800E47B4(u8* p) {
    if (*(u16*)(p + 0xa9c) != 0) {
        *(u16*)(p + 0xa9c) = *(u16*)(p + 0xa9c) - 1;
    }
    *(s32*)(p + 0xb50) = fn_80030668(*(s32*)(p + 0xb54));
    *(u32*)(lbl_802BB0FC + 0xf8) &= 0xdfffffff;
    *(u16*)(p + 0xa9c) = (u8)lbl_802C57D4[0x93];
    p[0xa76] = 0x1e;
}

extern "C" u8* fn_800306DC(int);
extern "C" void fn_800E4828(u8* p) {
    if (fn_800306DC(*(s32*)(p + 0xb50)) == 0) {
        if (*(u16*)(p + 0xa9c) == 0) {
            p[0xb11] = 2;
            *(u16*)(p + 0xa9c) = 10;
            p[0xa76] = 0x1f;
        } else {
            *(u16*)(p + 0xa9c) = *(u16*)(p + 0xa9c) - 1;
        }
    }
}

extern "C" void fn_80130974(void*);
extern "C" void fn_800E5458(u8* p) {
    if (*(u8**)(p + 0xb38) != 0) {
        fn_80130974(*(u8**)(p + 0xb38));
        u8* q = *(u8**)(p + 0xb38);
        *(u32*)(q + 0xf4) |= 1;
        *(u32*)(q + 0x24) = 1;
        *(u32*)(p + 0xb38) = 0;
    }
}

extern "C" void fn_800E6620(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0xa9c) != 0) {
        *(u16*)((u8*)param_1 + 0xa9c) = *(u16*)((u8*)param_1 + 0xa9c) - 1;
        return;
    }
    *(u8*)((u8*)param_1 + 0xa76) = 7;
}

extern "C" void fn_800E6A4C(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0xa9c) != 0) {
        *(u16*)((u8*)param_1 + 0xa9c) = *(u16*)((u8*)param_1 + 0xa9c) - 1;
        return;
    }
    *(u16*)((u8*)param_1 + 0xa9c) = 10;
    *(u8*)((u8*)param_1 + 0xb11) = 2;
    *(u8*)((u8*)param_1 + 0xa76) = 0x2a;
}

extern "C" void fn_800E71CC(u8* p) {
    if (*(u16*)(p + 0xa9c) != 0) {
        *(u16*)(p + 0xa9c) = *(u16*)(p + 0xa9c) - 1;
        return;
    }
    *(u32*)(lbl_802BB0FC + 0x100) |= 0x100000;
    *(u32*)(lbl_802BB0FC + 0x100) &= 0xFFFFF87F;
    *(u8*)(p + 0xa4c) = 1;
    *(u8*)(p + 0xa76) = 0;
}

extern "C" void fn_800E79EC(u8* p) {
    if (*(u16*)(p + 0xa9c) != 0) {
        *(u16*)(p + 0xa9c) = *(u16*)(p + 0xa9c) - 1;
    } else {
        fn_8002F358(0xf2, 0);
        *(u8*)(*(u8**)(p + 0x564) + 0xb0) = 1;
        *(u16*)(p + 0xa9c) = (u8)lbl_802C57D4[0x64];
        p[0xa76] = 0x21;
    }
}

extern "C" void fn_800E7A5C(u8* p) {
    if (*(u16*)(p + 0xa9c) != 0) {
        *(u16*)(p + 0xa9c) = *(u16*)(p + 0xa9c) - 1;
    } else {
        fn_8002F358(0xf3, 0);
        p[0x4f4] = 0;
        *(u16*)(p + 0xa9c) = *(s16*)(lbl_802C57D4 + 0x60);
        p[0xa76] = 0x22;
    }
}

extern "C" void fn_800E7AC8(u8* p)
{
    s16 n;
    (*(u16*)(p + 0xa9c))--;
    p[0x574]++;
    n = *(s16*)(*(u8**)(p + 0x570) + 6);
    if (p[0x574] >= n) {
        p[0x574] -= n;
    }
    *(f32*)(*(u8**)(p + 0x570) + 8) = p[0x574];
    fn_8017A4F8(*(void**)(p + 0x1c));
    if (*(u16*)(p + 0xa9c) == 0) {
        *(u8*)(*(u8**)(p + 0x564) + 0xb0) = 0;
        *(u16*)(p + 0xa9c) = 0x1e;
        p[0xa76] = 0x23;
    }
}

extern "C" void fn_800E7B7C(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0xa9c) != 0) {
        *(u16*)((u8*)param_1 + 0xa9c) = *(u16*)((u8*)param_1 + 0xa9c) - 1;
        return;
    }
    *(u8*)((u8*)param_1 + 0xa76) = 0;
    *(u32*)(lbl_802BB0FC + 0x100) |= 0x10;
}

extern "C" void fn_800E7D44(void* p) {
    if (*(u16*)((u8*)p + 0xa9c) != 0) {
        *(u16*)((u8*)p + 0xa9c) = *(u16*)((u8*)p + 0xa9c) - 1;
        return;
    }
    *(u8*)((u8*)p + 0xa76) = 0;
    *(u32*)(lbl_802BB0FC + 0x100) |= 0x8000;
}

extern "C" void fn_800E88D0(u8* p) {
    u8* obj = *(u8**)(p + 0xb34);
    if (obj != nullptr) {
        *(u32*)(obj + 0xf4) |= 1;
        *(s32*)(obj + 0x24) = 1;
    }
    *(u8*)(p + 0x5dd) = 0;
}

extern "C" void fn_800E8A08(u8* p) {
    if (p[0xb14] != 0) {
        p[0xb14]--;
    } else if (*(u32*)(lbl_802BB0FC + 0x100) & 1) {
        fn_800E927C(p);
        p[0xb14] = 0x3c;
        p[0xa76] = 0x32;
    }
}

extern "C" void fn_800E8A70(void* param_1) {
    u8* p = (u8*)param_1;
    u8 v = p[0xb14];
    if (v != 0) {
        p[0xb14] = v - 1;
        return;
    }
    *(u32*)(lbl_802BB0FC + 0x100) |= 0x1000;
    *(u32*)(lbl_802BB0FC + 0xf8) |= 0x80000000;
    p[0xa76] = 0;
}

extern "C" void fn_800E8AB4(u8* p) {
    u8 v = p[0xb14];
    if (v != 0) {
        p[0xb14] = v - 1;
    } else if (fn_800EE044() != 0) {
        fn_8002F358(0xa5, 0);
        p[0xb11] = 1;
        p[0xb14] = 0xe;
        p[0xa76] = 0x34;
    }
}

extern "C" void fn_800E8B24(u8* p) {
    if (p[0xb14] != 0) {
        p[0xb14]--;
    } else {
        p[0x4c4] = 0;
        p[0xa76] = 0x35;
    }
}

extern "C" void fn_800E927C(u8* p);
extern "C" s32 fn_800EE044(void);
extern "C" void fn_800E9098(u8* p) {
    if (p[0xb14] != 0) {
        p[0xb14]--;
        return;
    }
    if (p[0x4e9] != 0) {
        u8* q = p + p[0x4e9] * 4;
        *(u8*)(*(u8**)(q + 0x4a8) + 0xb0) = 0;
    }
    *(u8*)(*(u8**)(p + 0x4a4) + 0xb0) = 1;
    *(u8*)(*(u8**)(p + 0x4b8) + 0xb0) = 1;
    p[0x4c4] = 1;
    *(u32*)(p + 0x4c0) = 0;
    *(u8*)(*(u8**)(p + p[0x4e8] * 4 + 0x4ac) + 0xb0) = 1;
    p[0x4d0] = 1;
    *(u32*)(p + 0x4cc) = 0;
    *(u32*)(lbl_802BB0FC + 0x100) |= 0x2000;
    p[0xa76] = 0;
}

extern "C" void fn_800E927C(u8* p) {
    u32** slot = (u32**)(p + 0xb18);
    u32* obj;
    s32 i;
    for (i = 0; i < 2; i++) {
        obj = slot[i];
        if (obj != 0) {
            obj[0xf4 / 4] |= 1;
            obj[0x24 / 4] = 1;
            slot[i] = 0;
        }
    }
    p += 8;
    obj = *(u32**)(p + 0xb18);
    if (obj != 0) {
        obj[0xf4 / 4] |= 1;
        obj[0x24 / 4] = 1;
        *(u32*)(p + 0xb18) = 0;
    }
    obj = *(u32**)(p + 0xb1c);
    if (obj != 0) {
        obj[0xf4 / 4] |= 1;
        obj[0x24 / 4] = 1;
        *(u32*)(p + 0xb1c) = 0;
    }
    obj = *(u32**)(p + 0xb20);
    if (obj != 0) {
        obj[0xf4 / 4] |= 1;
        obj[0x24 / 4] = 1;
        *(u32*)(p + 0xb20) = 0;
    }
}

extern "C" void fn_800EB018(void);
extern "C" void fn_800EA20C(u8* p) {
    if (p[0xb14] != 0) {
        p[0xb14]--;
    } else {
        fn_800EB018();
        p[0xa76] = 0x3c;
    }
}

extern "C" void fn_8002F358(s32 a, s32 b);
extern "C" void fn_800EA4BC(void* param_1) {
    s8 v = *(s8*)((u8*)param_1 + 0xa6a);
    if (v == 0) {
        fn_8002F358(0xe5, 0);
    } else if (v < 3) {
        fn_8002F358(0xe6, 0);
    } else if (v < 5) {
        fn_8002F358(0xe7, 0);
    } else if (v < 7) {
        fn_8002F358(0xe3, 0);
    } else if (v < 10) {
        fn_8002F358(0xe4, 0);
    } else {
        fn_8002F358(0xed, 0);
    }
}

extern "C" void fn_800EA564(void* param_1) {
    u8* p = (u8*)param_1;
    u8 v = p[0xb14];
    if (v != 0) {
        p[0xb14] = v - 1;
        return;
    }
    *(u32*)(lbl_802BB0FC + 0x100) |= 0x4000000;
    p[0xa76] = 0;
}

extern "C" s32 fn_800EA6D0(void* param_1, s32 param_2);
extern "C" void fn_800EA59C(void* param_1) {
    u8* p = (u8*)param_1;
    *(s32*)(p + 0xa88) = fn_800EA6D0(param_1, (s8)p[0xa6a] + 1);
    p[0xa76] = 0x3f;
}

extern "C" void fn_800EA848(u8* p) {
    if (p[0xb14] != 0) {
        p[0xb14]--;
    } else {
        p[0xb14] = lbl_802C57D4[0x81];
        fn_8002F0A8(*(int*)(p + 0xa88));
        p[0xa76] = 0x41;
    }
}

extern "C" void fn_800EAA4C(u8* p) {
    ((s8*)p)[0xa4d]--;
    fn_800E7F50(p, p[0xa4e], ((s8*)p)[0xa4d], 0);
    fn_8002F458(0xa7, 0);
    p[0xa76] = 0x4b;
    p[0xa77] = 0x43;
}

extern "C" void fn_800EAAB0(u8* p) {
    *(u16*)(p + 0xa9c) = (u8)lbl_802C57D4[0x95];
    p[0xa76] = 0x49;
}

extern "C" void fn_800EAFA8(void* p) {
    *(u32*)(lbl_802BB0FC + 0x100) |= 0x4000000;
    *(u8*)((u8*)p + 0xa8c) = 0;
    *(u8*)((u8*)p + 0xa76) = 0;
}

extern "C" s32 fn_8002F168(u8* p);
extern "C" void fn_800EAFCC(u8* p) {
    if (fn_8002F168(p) != 1) {
        *(u16*)(p + 0xa9c) = (u8)lbl_802C57D4[0x95];
        p[0xa76] = 0x49;
    }
}

extern "C" void fn_800EB6E0(char* p) {
    if (*(u16*)(p + 0xa9c) != 0) {
        *(u16*)(p + 0xa9c) = *(u16*)(p + 0xa9c) - 1;
    } else {
        fn_800EBD88(p);
        p[0xa76] = 0x4a;
    }
}

extern "C" void fn_800EBD88(char* p) {
    p[0xb11] = 2;
    p[0xb14] = 10;
    *(unsigned char*)(*(char**)(p + 0x9e8) + 0xb0) = 1;
    p[0xa00] = lbl_802C57D4[0x80];
    p[0xa01] = 0;
}

extern "C" void fn_800EC0E4(void* param_1) {
    if (*(u8*)((u8*)param_1 + 0xb14) != 0) {
        *(u8*)((u8*)param_1 + 0xb14) = *(u8*)((u8*)param_1 + 0xb14) - 1;
        return;
    }
    *(u8*)((u8*)param_1 + 0xa76) = *(u8*)((u8*)param_1 + 0xa77);
}

extern "C" void fn_800EDBB4(u8* p) {
    s32 v = p[0xb48];
    if (v != 1 && v >= 1 && v < 5) {
        char* base = lbl_802B7CA0 + 0x1424;
        fn_80060794(base, base + 0x204, base + 0x208, p + 8);
    }
}

extern "C" void fn_800EE0F0(void* param_1, void* param_2) {
    fn_8015FDA8(param_2, *(void**)((u8*)param_1 + 4));
}

extern "C" void fn_800EE344(void* param_1) {
    VObj_800A1A64* obj = *(VObj_800A1A64**)(lbl_802B7CA0 + 0x1394);
    obj->v3();
    f32 c = lbl_80301058;
    fn_80179CB4(*(void**)((char*)param_1 + 4), obj, c, c);
}

extern "C" void* fn_800EE3A8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028B80C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
