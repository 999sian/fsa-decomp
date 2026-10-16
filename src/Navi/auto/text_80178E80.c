

#include "types.h"
struct VObj_80185520 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual s32 vfc8(s32 a, s32 b, u8 c); virtual void v49();
};
struct VObj_80178E10 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual void vf20(int mode);
};

extern void* lbl_80286A1C[];
extern f32 lbl_80301C30;
extern f64 lbl_80301C58;
extern f32 __psq_l(void* p, int off, int w, int gqr);
static inline f32 s16ToF32(s16 v) {
    union {
        f64 d;
        u32 w[2];
    } u;
    u.w[0] = 0x43300000;
    u.w[1] = (u32)v ^ 0x80000000;
    return (f32)(u.d - lbl_80301C58);
}
extern "C" void* fn_80174BA0(void* base, u32 offset);
extern "C" void* fn_8018C278(void* base, u32 offset);
extern "C" void* fn_8018C290(void* base, u32 offset);
extern "C" void* fn_8018C2D8(void* base, u32 offset);


extern "C" void fn_8017FD80(void);
extern "C" void fn_8017FED0(void);
extern "C" s32 fn_801786BC(s32 a, f32 b);

extern "C" u8 fn_80183FC8(s32 a, s32* b, s32* c);

extern "C" void fn_801C5DA8(u32 a, u8* b, u8* c);
extern u8 lbl_802994F0[];
extern u8 lbl_80299504[];
extern u8 lbl_80299244[];
extern "C" u8 fn_801884B0(s32 a, s32* b, s32* c);

struct VObj_80185DA4 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual u32 v50(u32 a, u32 b, u8 c);
    virtual void v51(); virtual u32 v52(u8 a); virtual void v53(); virtual u32 v54(u8 a);
};

struct VObj_80186B6C {
    virtual void v0(); virtual void v1(); virtual void v2(u32 a, u8 b); virtual void v3();
    virtual void v4(u32 a, u8 b);
};

struct VObj_801878E4 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(u32 a, u8 b, u8 c);
    virtual void v16(); virtual void v17(u32 a, u8 b, u8 c);
};

struct VObj_80187FCC {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
    virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67();
    virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73();
    virtual s32 vf130(s32* a, s32* b);
};

extern "C" void fn_801DF2A4(u8* a, s32 b);
struct Vec4F {
    f32 x, y, z, w;
};

extern "C" void fn_80182764(u8* a, f32* b, u8* c);
extern "C" void fn_80177CA8(u8* a, u8* b);
extern "C" u8 fn_80185B00(void* self, s32 b);
extern "C" void fn_801857C8(void* self, f32 f, s32 b);

struct VObj_80187834 {
    virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void vf44(u8 a, u8 b);
    virtual void v18(); virtual void vf4c(u8 a, u8 b);
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void vf7c(u8 a, void* b, s32 c);
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36();
    virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41();
    virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46();
    virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual s32 vfd4(u8 a);
};

struct VObj_8017ED64 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64();
    virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
    virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74();
    virtual void v75(); virtual void v76(); virtual void v77();
    virtual void vf140(f32 a, f32 b, f32 c, f32 d);
};

struct VObj_8017EB2C {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64();
    virtual void v65(); virtual void v66(void* a, int b); virtual void v67();
    virtual void v68(void* a, void* b, int c);
};

struct VObj_8018939C {
    virtual void v0(s32 mode);
};

struct VObj_80189BD8 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35();
};

struct VObj_80183C4C {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual s32 vfA8(s32* a, s32* b);
};

struct VObj_80187ECC {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37();
    virtual int vfA0(u8 a);
};

struct VObj_801843 {
    virtual void* vf0();
    virtual void* vf4();
    virtual void* vf8();
    virtual void* vfC();
    virtual void* vf10();
    virtual void* vf14();
    virtual void* vf18();
    virtual void* vf1C();
    virtual void* vf20();
    virtual void* vf24();
    virtual void* vf28();
    virtual void* vf2C();
    virtual void* vf30();
    virtual void* vf34();
    virtual void* vf38();
    virtual void* vf3C();
    virtual void* vf40();
    virtual void* vf44();
    virtual void* vf48();
    virtual void* vf4C();
    virtual void* vf50();
    virtual void* vf54();
    virtual void* vf58();
    virtual void* vf5C();
    virtual void* vf60();
    virtual void* vf64();
    virtual void* vf68();
    virtual void* vf6C();
    virtual void* vf70();
    virtual void* vf74();
    virtual void* vf78();
    virtual void* vf7C();
    virtual void* vf80();
    virtual void* vf84();
    virtual void* vf88();
    virtual void* vf8C();
    virtual void* vf90();
    virtual void* vf94();
    virtual s32 vf98(u8);
    virtual void* vf9C();
    virtual void* vfA0();
    virtual void* vfA4();
    virtual void* vfA8();
    virtual void* vfAC();
    virtual void* vfB0();
    virtual void* vfB4();
    virtual void* vfB8();
    virtual void* vfBC();
    virtual void* vfC0();
    virtual void* vfC4();
};

struct VObj_80180980 {
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfC();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0(int, int, int);
    virtual void vfC4(int, int);
    virtual void vfC8(int, int, int);
    virtual void vfCC(int, int);
    virtual void vfD0();
    virtual void vfD4(int, int);
    virtual void vfD8(u8);
    virtual void vfDC(); virtual void vfE0(); virtual void vfE4(); virtual void vfE8(); virtual void vfEC();
    virtual void vfF0(f32*, f32*); virtual void vfF4(); virtual void vfF8(f32*, f32*); virtual void vfFC(); virtual void vf100(f32, f32, f32, f32, f32, f32, f32, f32); virtual void vf104(f32, f32, f32, f32, f32, f32, f32, f32);
    virtual void vf108(f32, f32, f32, f32, f32, f32, f32, f32);
    virtual void vf10C(f32, f32, f32, f32, f32, f32, f32, f32);
    virtual void vf118(void*, int, int); virtual void vf11C(); virtual void vf120(); virtual void vf124(); virtual void vf128(); virtual void vf12C(); virtual void vf130(); virtual void vf134(); virtual void vf138(); virtual void vf13C(); virtual void vf140();
    virtual void vf144(f32, f32, s16, s16, s16, s16, s16, s16, s16, s32, s32);
};

struct VObj_80180920 {
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfC();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8(int, int, int);
    virtual void vfCC(int, int, int);
    virtual void vfD0(int, int, int);
};

extern "C" void fn_80176550(void* self);
extern "C" void fn_8016A39C(void* p, void* obj);
extern "C" void fn_80178B74(void);

struct VObj_80180868 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(u32, u32, u8); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(u8, u32); virtual void v62(); virtual void v63(u8, u32);
};
extern "C" void fn_8017B07C(u32* self, int a, int b, int c);
extern void* lbl_80298DF0[];

extern "C" void fn_80177F0C(void);
extern "C" void fn_801813CC(u32*, int, int, int);

struct UnkVObj_80181CCC {
    virtual void vf8(int);
    virtual u16 vfC();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void* vf3C();
};
extern "C" u32 fn_80177E84(void);
extern "C" void fn_801670D0(int, void*, int);
extern "C" void fn_8016A0B4(void* p, void* obj);
extern "C" void fn_8016A1F8(void* p, void* obj);
extern "C" void fn_801788C0(void);
extern "C" void fn_80178990(void);
extern "C" void fn_8015AB1C(void* p);
extern "C" u8 fn_8018A318(void* self, s32* param_2, s32* param_3);
extern "C" void fn_8018BB74(void* self, void* dst, void* src);
extern "C" void fn_801801F4(void* self, void* p, s32 a, s32 b, s32 c, s32 d);
extern "C" void fn_80189D14(void* self, s32 value, s32 mode);
extern "C" void fn_8018BC30(void* self, void* dst, void* src);
extern "C" void fn_8018BFA4(void* self, void* dst, void* src);

struct VObj_80189C70 {
    virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual s32 v24(s32 mode);
};

struct VObj_80189FDC {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40();
    virtual s32 vfAC(s32* a, s32* b);
};
extern u8 lbl_80301BF8[];

struct VObj_80184164 {
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void v3(); virtual u8 v4(); virtual void v5();
    virtual u8 v6();
};

struct DtorVObj_80178F90 {
    virtual void Destroy(int);
};

struct Quad_8017C0A8 {
    u8 v[4];
};

struct VObj_8017C154 {
    virtual void vf8();
    virtual void vfC();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38(void* buf, f32 x, f32 y);
};

struct Tbl4_8017D014 {
    u32 v[4];
};

struct Tbl5_8017D090 {
    u32 v[5];
};

extern "C" void fn_801C5D48(void* p);
extern u8 lbl_802022C8[];
extern u8 lbl_802022D8[];
extern void* lbl_80286A30[];
extern void* lbl_80299634[];
extern void* lbl_80299540[];
extern void* lbl_80298D38[];
extern "C" void fn_80178F90(void*);
extern "C" void fn_80176FE8(void*, int);
extern "C" void fn_8017DEFC(void*);
extern "C" void fn_80177728(void*, f32*);
extern "C" void fn_80176698(void* self, s32 a, s32 b, s32 c, s32 d, u32 e, void* f);
extern "C" void* fn_80178E80(void* self) {
    f32 rect[6];
    s32 unused;
    u32 tag;
    rect[0] = 0.0f;
    rect[1] = 0.0f;
    rect[2] = 0.0f;
    rect[3] = 0.0f;
    rect[4] = 640.0f;
    rect[5] = 480.0f;
    tag = 0x726f6f74;
    fn_80176698(self, 0, 1, unused, 0, tag, &rect[2]);
    *(void**)self = lbl_80298D38;
    *(s32*)((u8*)self + 0x114) = -1;
    *(u16*)((u8*)self + 0x4) = 0xffff;
    *(u8*)((u8*)self + 0x100) = 0;
    *(u16*)((u8*)self + 0x102) = 0;
    *(s32*)((u8*)self + 0x104) = 0;
    *(s32*)((u8*)self + 0x108) = 0;
    *(s32*)((u8*)self + 0x10c) = 0;
    *(s32*)((u8*)self + 0x110) = 0;
    return self;
}

extern "C" void* fn_80178F28(void* p, s16 param_2) {
    if (p != nullptr) {
        *(void**)p = lbl_80298D38;
        fn_80178F90(p);
        fn_80176FE8(p, 0);
        if (param_2 > 0) {
            fn_8015AB1C(p);
        }
    }
    return p;
}

extern "C" void fn_801E0CC4(void* a, void* b);
extern "C" void fn_80169B1C(void);
extern "C" void fn_8015AB40(void* p);
extern "C" void fn_80178F90(void* self) {
    char* p = (char*)self;
    fn_801E0CC4(*(void**)(p + 0x104), (void*)fn_80169B1C);
    *(u16*)(p + 0x102) = 0;
    *(void**)(p + 0x104) = 0;
    fn_8015AB40(*(void**)(p + 0x108));
    *(void**)(p + 0x108) = 0;
    fn_8015AB40(*(void**)(p + 0x10c));
    *(void**)(p + 0x10c) = 0;
    if (*(void**)(p + 0x110) != 0) {
        fn_8015AB40(*(void**)(*(char**)(p + 0x110) + 4));
        DtorVObj_80178F90* o = *(DtorVObj_80178F90**)(p + 0x110);
        if (o != 0) {
            o->Destroy(1);
        }
        *(void**)(p + 0x110) = 0;
    }
}

extern "C" int fn_80179174(int, int, int, void*);
extern "C" int fn_80179144(int a, int b, int c, void* d) {
    if (d == 0) {
        return 0;
    }
    return fn_80179174(a, b, c, d);
}

extern "C" int fn_801792B4(void* param_1, int param_2) {
    u32 buf[8];
    fn_801670D0(param_2, buf, 0x20);
    if (buf[0] == 0x5343524e && (buf[1] == 0x626c6f31 || buf[1] == 0x626c6f32)) {
        return 1;
    }
    return 0;
}

extern "C" void fn_80118BD0(void* p, s32 x);
extern "C" int fn_80177D24(void);
extern "C" int fn_80179E80(s64 param_1, s64 param_2) {
    int result = 0;
    if (param_2 == result) {
    } else {
        result = fn_80177D24();
    }
    return result;
}

extern "C" void fn_8017A468(void) {
    fn_80177E84();
}

extern "C" void fn_8017A488(void) {
    fn_80177F0C();
}

extern "C" void* fn_8015FDA8(void*, void*);
extern "C" int fn_8018ECE4(void*, void*);
extern "C" void fn_8016A72C(void*);
extern void* lbl_802FF6A0;
#pragma dont_inline on
extern "C" void* fn_8017A4A8(void* param_1) {
    if (fn_8015FDA8(param_1, nullptr) == nullptr) {
        void* p = lbl_802FF6A0;
        if (p != nullptr) {
            fn_8018ECE4(p, param_1);
        }
    }
}

#pragma dont_inline reset
extern "C" void fn_8017A4F8(void* self) {
    void (*vfn)(void*, void*) = (void (*)(void*, void*))((*(void***)self)[0x90 / 4]);
    u16 i;
    vfn(self, *(void**)((u8*)self + 0xf8));
    for (i = 0; i < *(u16*)((u8*)self + 0x102); i++) {
        fn_8016A72C(*(u8**)((u8*)self + 0x104) + i * 0x88);
    }
}

extern "C" void fn_8017A56C(void* self, void* obj) {
    void (*vfn)(void*, void*) = (void (*)(void*, void*))((*(void***)obj)[0xc / 4]);
    u16 count;
    u16 i;
    vfn(obj, self);
    count = *(u16*)((u8*)obj + 0x18);
    for (i = 0; i < count; i++) {
        u16 idx = ((u16*)*(u8**)((u8*)obj + 0x1c))[i];
        if (idx < *(u16*)((u8*)self + 0x102)) {
            fn_8016A0B4(*(u8**)((u8*)self + 0x104) + idx * 0x88, obj);
        }
    }
}

extern "C" void fn_8017A610(void* param_1, void* param_2) {
    u16 count;
    u16 i;
    u16 idx;
    void* obj = param_2;
    void* fn = ((void**)*(void**)obj)[3];
    ((void (*)(void*, void*))fn)(obj, param_1);
    count = *(u16*)((u8*)obj + 0x14) / 3;
    for (i = 0; i < count; i++) {
        idx = ((u16*)*(u32*)((u8*)obj + 0x34))[i];
        if (idx < *(u16*)((u8*)param_1 + 0x102)) {
            fn_8016A1F8((u8*)*(u32*)((u8*)param_1 + 0x104) + idx * 0x88, obj);
        }
    }
}

extern "C" void fn_8017A6CC(void* self, void* obj) {
    void (*vfn)(void*, void*) = (void (*)(void*, void*))((*(void***)obj)[0xc / 4]);
    u16 count;
    u16 i;
    vfn(obj, self);
    count = *(u16*)((u8*)obj + 0x1a);
    for (i = 0; i < count; i++) {
        u16 idx = ((u16*)*(u8**)((u8*)obj + 0x1c))[i];
        if (idx < *(u16*)((u8*)self + 0x102)) {
            fn_8016A39C(*(u8**)((u8*)self + 0x104) + idx * 0x88, obj);
        }
    }
}

extern "C" void fn_8017A85C(void) {
    fn_80178B74();
}

extern "C" void fn_8017A908(void) {
    fn_80178990();
}

extern "C" void fn_8017A928(void) {
    fn_801788C0();
}

extern "C" void fn_8017A968(void) {}

extern "C" void* fn_8017AA68(u32* self, int a, int b, int c) {
    fn_80176550(self);
    *(void**)self = lbl_80298DF0;
    self[0x40] = 0;
    self[0x41] = 0;
    self[0x42] = 0;
    self[0x43] = 0;
    self[0x44] = 0;
    self[0x49] = 0;
    self[0x4a] = -1;
    self[0x4b] = -1;
    self[0x4c] = -1;
    self[0x4d] = -1;
    self[0x4e] = -1;
    self[0x4f] = -1;
    fn_8017B07C(self, a, b, c);
    return self;
}

extern "C" void* fn_8017B7E4(u32* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = lbl_80298DF0;
        fn_80118BD0((void*)param_1[0x40], 1);
        fn_80118BD0((void*)param_1[0x41], 1);
        fn_80118BD0((void*)param_1[0x42], 1);
        fn_80118BD0((void*)param_1[0x43], 1);
        fn_8015AB1C((void*)param_1[0x49]);
        fn_80118BD0((void*)param_1[0x44], 1);
        fn_80176FE8(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_8017C0A8(u8* self, u32* a, u32* b, u32* c, u32* d) {
    u32 va = *a;
    u32 vb = *b;
    u32 vc = *c;
    u32 vd = *d;
    u8* pa = (u8*)&va;
    u8* pb = (u8*)&vb;
    u8* pc = (u8*)&vc;
    u8* pd = (u8*)&vd;
    self[0x128] = pa[0];
    self[0x129] = pa[1];
    self[0x12a] = pa[2];
    self[0x12b] = pa[3];
    self[0x12c] = pb[0];
    self[0x12d] = pb[1];
    self[0x12e] = pb[2];
    self[0x12f] = pb[3];
    self[0x130] = pc[0];
    self[0x131] = pc[1];
    self[0x132] = pc[2];
    self[0x133] = pc[3];
    self[0x134] = pd[0];
    self[0x135] = pd[1];
    self[0x136] = pd[2];
    self[0x137] = pd[3];
}

extern "C" void fn_8017C154(VObj_8017C154* self, f32 x, f32 y) {
    u8 buf[48];
    fn_801C5D48(buf);
    self->vf38(buf, x, y);
}

extern "C" u32 fn_8017D014(char* self, u8 idx, u8 flag) {
    Tbl4_8017D014 tbl = *(Tbl4_8017D014*)lbl_802022C8;
    tbl.v[0] = *(u32*)(self + 0x100);
    tbl.v[1] = *(u32*)(self + 0x104);
    tbl.v[2] = *(u32*)(self + 0x108);
    tbl.v[3] = *(u32*)(self + 0x10c);
    u32 result = 0;
    if (idx < 4 && flag == 0) {
        result = tbl.v[idx];
    }
    return result;
}

extern "C" u32 fn_8017D090(char* self, u32 id) {
    Tbl5_8017D090 tbl = *(Tbl5_8017D090*)lbl_802022D8;
    tbl.v[0] = *(u32*)(self + 0x100);
    tbl.v[1] = *(u32*)(self + 0x104);
    tbl.v[2] = *(u32*)(self + 0x108);
    tbl.v[3] = *(u32*)(self + 0x10c);
    tbl.v[4] = *(u32*)(self + 0x110);
    u8 i = 0;
    while (i < 5) {
        u32 p = tbl.v[i];
        if (p != 0 && *(u32*)(p + 0x20) == id) {
            return 1;
        }
        i++;
    }
    return fn_80177E84();
}

extern "C" u32 fn_8017D148(void) {
    return 0x11;
}

extern "C" void fn_8017D150(void* param_1, f32 a, f32 b, f32 c, f32 d) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
        virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
        virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
        virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
        virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
        virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
        virtual void vf94(f32* rect);
    };
    f32 rect[4];
    rect[0] = a;
    rect[1] = b;
    rect[2] = a + c;
    rect[3] = b + d;
    ((Obj*)param_1)->vf94(rect);
}

extern "C" void fn_8017D198(void* param_1, void* param_2) {
    *(u32*)param_1 = *(u32*)((u8*)param_2 + 0x13c);
}

extern "C" int fn_8017D1E4()
{
	return 0;
}

extern "C" int fn_8017D1EC()
{
	return 0;
}

extern "C" void fn_8017D214(void) {}

extern "C" void fn_8017DE68(u32* param_1) {
    extern f32 lbl_80301BA0;
    f32 rect[4];
    u16* p;
    fn_8017DEFC(param_1);
    if (param_1[0x40] != 0) {
        p = *(u16**)((u8*)param_1[0x40] + 0x20);
        rect[0] = lbl_80301BA0;
        rect[1] = lbl_80301BA0;
        rect[2] = (f32)p[1];
        rect[3] = (f32)p[2];
        fn_80177728(param_1, rect);
    }
}

#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline on
extern "C" void* fn_8017E1A4(u32* param_1, s16 param_2) {
    extern void* lbl_80298ED8[];
    s32 i;
    if (param_1 != nullptr) {
        *(void**)param_1 = lbl_80298ED8;
        for (i = 0; i < 4; i++) {
            if (*((u8*)param_1 + 0x111) & (1 << i)) {
                fn_80118BD0((void*)param_1[0x40 + i], 1);
            }
        }
        fn_8015AB1C((void*)param_1[0x51]);
        fn_80176FE8(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}
#pragma pop

#pragma push
#pragma use_lmw_stmw off
extern "C" void fn_8017E65C(u32* self, void* a, f32 f, int b, int c) {
    void* p = fn_8017A4A8(a);
    ((void (*)(void*, void*, f32, int, int))(*(u32**)self)[50])(self, p, f, b, c);
}
#pragma pop
extern "C" void fn_8017E9DC(u32* self, u32 a) {
    u8 i;
    for (i = 0; i < *((u8*)self + 0x110); i++) {
        if (a == self[0x40 + i]) {
            break;
        }
    }
    void (*vfn)(void*, u8) = (void (*)(void*, u8))((*(void***)self)[54]);
    vfn(self, i);
}

extern "C" void fn_8017EB2C(u32* self, void* a, int b) {
    ((VObj_8017EB2C*)self)->v66(fn_8017A4A8(a), b);
}

#pragma push
#pragma use_lmw_stmw off
extern "C" void fn_8017EC94(u32* self, void* a, int b, int c) {
    ((VObj_80180980*)self)->vf118(fn_8017A4A8(a), b, c);
}
#pragma pop
extern "C" void fn_801C5D48(void* p);
extern "C" void fn_8017ECFC(VObj_8017C154* self, f32 x, f32 y) {
    u8 buf[48];
    fn_801C5D48(buf);
    self->vf38(buf, x, y);
}

extern "C" void fn_8017ED64(VObj_8017ED64* self, f32 x, f32 y) {
    u8* p = (u8*)self;
    if (*(u32*)(p + 0x100) != 0 && *(u8*)(p + 0x110) != 0) {
        self->vf140(*(f32*)(p + 0x30) + x, *(f32*)(p + 0x34) + y, *(f32*)(p + 0x28) - *(f32*)(p + 0x20), *(f32*)(p + 0x2c) - *(f32*)(p + 0x24));
    }
}

extern "C" void fn_8017EDD0(u32* self, s32 a) {
    u8* p = (u8*)self;
    if (*(u32*)(p + 0x100) != 0 && *(u8*)(p + 0x110) != 0) {
        ((VObj_80180980*)self)->vf144(*(f32*)(p + 0x20), *(f32*)(p + 0x24), *(s16*)(p + 0x112), *(s16*)(p + 0x114), *(s16*)(p + 0x116), *(s16*)(p + 0x118), *(s16*)(p + 0x11a), *(s16*)(p + 0x11c), *(s16*)(p + 0x11e), *(s16*)(p + 0x120), a);
    }
}

extern "C" u8 fn_8017FCEC(void* self);
extern "C" s32 fn_8017FC54(void* self) {
    s32 flags = 0;
    if (fn_8017FCEC(self)) {
        if (*(s16*)((u8*)self + 0x114) < *(s16*)((u8*)self + 0x120)) {
            flags |= 1;
        }
        if (*(s16*)((u8*)self + 0x112) > *(s16*)((u8*)self + 0x11e)) {
            flags |= 2;
        }
    } else {
        if (*(s16*)((u8*)self + 0x112) > *(s16*)((u8*)self + 0x11e)) {
            flags |= 2;
        }
        if (*(s16*)((u8*)self + 0x114) > *(s16*)((u8*)self + 0x120)) {
            flags |= 1;
        }
    }
    return flags;
}

extern "C" u8 fn_8017FCEC(void* self) {
    u8* p = (u8*)self;
    s16 x = *(s16*)(p + 0x120);
    u8 r = 0;
    if (*(s16*)(p + 0x116) == *(s16*)(p + 0x112) && *(s16*)(p + 0x118) == x) {
        r = 1;
    }
    return r;
}

extern "C" void fn_8017FD20(VObj_80180980* self, f32 a, f32 b, f32 c, f32 d) {
    *(f32*)((char*)self + 0x124) = a;
    *(f32*)((char*)self + 0x128) = b;
    *(f32*)((char*)self + 0x12c) = c;
    *(f32*)((char*)self + 0x130) = d;
    fn_8017FD80();
}

extern "C" void fn_8017FD50(void* self, f32 a, f32 b, f32 c, f32 d) {
    *(f32*)((char*)self + 0x134) = a;
    *(f32*)((char*)self + 0x138) = b;
    *(f32*)((char*)self + 0x13c) = c;
    *(f32*)((char*)self + 0x140) = d;
    fn_8017FED0();
}

extern "C" void fn_80180144(char* self, f32* p) {
    s32 i = 0;
    f32* src = p;
    char* dst = self;
    do {
        *(u16*)(dst + 0x112) = fn_801786BC(8, src[0]);
        *(u16*)(dst + 0x114) = fn_801786BC(8, src[1]);
        i++;
        src += 2;
        dst += 4;
    } while (i < 4);
}

extern "C" void fn_801801B8(void* self, s32 a, s32 b, s32 c, s32 d) {
    fn_801801F4(self, (u8*)self + 0x112, a, b, c, d);
}

extern "C" u32 fn_80180514(void* self, u32 a) {
    u8 i;
    for (i = 0; i < *((u8*)self + 0x110); i++) {
        u32* p = *(u32**)((u8*)self + 0x100 + i * 4);
        if (p != 0 && p[8] == a) {
            return 1;
        }
    }
    return fn_80177E84();
}

extern "C" u8 fn_80180648(s32 a, void* b, u32 c) {
    u32 s;
    u32 r;
    if (*(u16*)((u8*)b + 0xa) > 0x100) {
        s = (u8)c;
        s = s >> 31;
        r = (c << 30) - s;
        r = (r << 2) | (r >> 30);
        return r + s + 0x10;
    }
    return (u8)c;
}

extern "C" void fn_8018067C(void) {}

extern "C" void fn_80180680(u32* self, int a) {
    ((void (*)(void*, int, int))(*(u32**)self)[49])(self, a, *(u8*)((u8*)self + 0x110));
}

extern "C" void fn_801806B0(u32* self, int a, int b) {
    ((VObj_80180980*)self)->vfC0(a, 0, b);
}

extern "C" void fn_801806E4(u32* self, int a) {
    ((void (*)(void*, int, int))(*(u32**)self)[51])(self, a, *(u8*)((u8*)self + 0x110));
}

extern "C" void fn_80180714(u32* self, int a, int b) {
    ((VObj_80180980*)self)->vfC8(a, 0, b);
}

extern "C" void fn_80180748(void* self, int a) {
    ((VObj_80180980*)self)->vfCC(a, *((u8*)self + 0x110));
}

extern "C" void fn_80180778(void* self, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g, f32 h) {
    ((VObj_80180980*)self)->vf100(a, b, c, d, e, f, g, h);
    ((VObj_80180980*)self)->vf104(a, b, c, d, e, f, g, h);
}

extern "C" void* fn_80180814(void* self, u8 idx) {
    if (idx < 4) {
        return ((void**)((u8*)self + 0x100))[idx];
    }
    return NULL;
}

extern "C" void fn_80180838(void* self, u32 a, u32 b) {
    ((VObj_80180868*)self)->v48(a, b, ((u8*)self)[0x110]);
}

typedef void (*VFnA_80180868)(void*, u8, u32);
typedef void (*VFnB_80180838)(void*, u32, u32, u8);
extern "C" void fn_801191F0(void* p);
extern "C" void fn_80180868(void* self, u32 a) {
    ((VObj_80180868*)self)->v61((u8)a, a);
}

extern "C" void fn_8018089C(void* self, void* unused, u8 idx) {
    if (idx < ((u8*)self)[0x110] && idx < 4) {
        void* p = ((void**)((u8*)self + 0x100))[idx];
        if (p != NULL) {
            fn_801191F0(p);
        }
    }
}

extern "C" s32 fn_801808E8(void) {
    return 0x12;
}

extern "C" void fn_801808F0(void* self, int a, int b, int c) {
    ((VObj_80180920*)self)->vfC8(a, b, *((u8*)self + 0x110));
}

extern "C" void fn_80180920(void* self, int a, int b, int c) {
    ((VObj_80180920*)self)->vfCC(a, 0, c);
}

extern "C" void fn_80180950(void* self, int a, int b, int c) {
    ((VObj_80180920*)self)->vfC8(a, b, 0);
}

extern "C" void fn_80180980(VObj_80180980* self, int a) {
    self->vfC4(a, 0);
}

extern "C" void fn_801809B0(void* self, int a, int b) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
        virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
        virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
        virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
        virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
        virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
        virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
        virtual void vfC8(int, int, int);
    };
    ((Obj*)self)->vfC8(a, b, 0);
}

extern "C" void fn_801809E0(void* self, int a) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
        virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
        virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
        virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
        virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
        virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
        virtual void v44(); virtual void v45(); virtual void v46();
        virtual void vfC4(int, int);
    };
    ((Obj*)self)->vfC4(a, 0);
}

extern "C" void fn_80180A10(VObj_80180980* self) {
    u8 n = ((u8*)self)[0x110];
    self->vfD8((u8)(n - 1));
}

extern "C" void fn_80180A48(VObj_80180980* self, f32 x0, f32 y0, f32 dx0, f32 dy0, f32 x1, f32 y1, f32 dx1, f32 dy1) {
    f32 a[4];
    f32 b[4];
    b[0] = x1;
    b[1] = y1;
    b[2] = x1 + dx1;
    b[3] = y1 + dy1;
    a[0] = x0;
    a[1] = y0;
    a[2] = x0 + dx0;
    a[3] = y0 + dy0;
    self->vfF0(a, b);
}

extern "C" void fn_80180AAC(VObj_80180980* self, f32 x0, f32 y0, f32 dx0, f32 dy0, f32 x1, f32 y1) {
    f32 a[4];
    f32 b[4];
    f32 dx;
    f32 dy;
    u8* p = *(u8**)((u8*)self + 0x100);
    if (p != 0) {
        u16* q = *(u16**)(p + 0x20);
        dx = (s32)q[1];
        dy = (s32)q[2];
    }
    a[0] = x0;
    a[1] = y0;
    a[2] = x0 + dx0;
    a[3] = y0 + dy0;
    b[0] = x1;
    b[1] = y1;
    b[2] = x1 + dx;
    b[3] = y1 + dy;
    self->vfF0(a, b);
}

extern "C" u8 fn_80180B58(VObj_80180980* self) {
    return *((u8*)self + 0x110);
}

extern "C" int fn_80180B60(u8* self, u8* src) {
    u8 a = src[0];
    u8 b = src[1];
    self[0x14c] = a;
    u8 c = src[2];
    self[0x14d] = b;
    u8 d = src[3];
    self[0x14e] = c;
    self[0x14f] = d;
    return 1;
}

extern "C" void fn_80176550(void* self);
extern "C" void fn_8018119C(void* self, s32 a, s32 b, s32 c, s32 d, s32 e);
extern void* lbl_80299040[];
extern "C" void fn_80180B88(void) {
    fn_80177F0C();
}

extern "C" void fn_80180BA8(void) {
}

extern "C" void* fn_80180BAC(u32* self) {
    fn_80176550(self);
    *(void**)self = lbl_80299040;
    self[0x40] = 0;
    self[0x41] = -1;
    self[0x42] = -1;
    self[0x49] = 0;
    self[0x4a] = -1;
    self[0x4b] = -1;
    fn_8018119C(self, 0, 0, 0, 2, 2);
    return self;
}

extern "C" void* fn_80180C24(u32* self, int a, int b, int c) {
    fn_80176550(self);
    *(void**)self = lbl_80299040;
    self[0x40] = 0;
    self[0x41] = -1;
    self[0x42] = -1;
    self[0x49] = 0;
    self[0x4a] = -1;
    self[0x4b] = -1;
    fn_801813CC(self, a, b, c);
    return self;
}

extern "C" void fn_80176848(void*);
#pragma push
#pragma use_lmw_stmw off
extern "C" void* fn_80181108(u32* self, s32 p1, s32 p2, s32 p3, s32 p4, s32 a, s32 b, s32 c, s32 d, s32 e) {
    fn_80176848(self);
    *(void**)self = lbl_80299040;
    self[0x40] = 0;
    self[0x41] = -1;
    self[0x42] = -1;
    self[0x49] = 0;
    self[0x4a] = -1;
    self[0x4b] = -1;
    fn_8018119C(self, a, b, c, d, e);
    return self;
}

extern "C" void fn_801817BC(char* self, UnkVObj_80181CCC* obj) {
    if (obj != 0) {
        if (*(u8*)(self + 0x131) != 0) {
            UnkVObj_80181CCC* cur = *(UnkVObj_80181CCC**)(self + 0x100);
            if (cur != 0) {
                cur->vf8(1);
            }
        }
        *(UnkVObj_80181CCC**)(self + 0x100) = obj;
        *(u8*)(self + 0x131) = 0;
    }
}

#pragma pop
extern "C" int fn_80181BA0(char* self) {
    return *(int*)(self + 0x124);
}

extern "C" u8 fn_80181CCC(char* self, u8 v) {
    char* p = *(char**)(self + 0xec);
    if (p == 0) {
        return 0;
    }
    if ((*(UnkVObj_80181CCC**)(p + 0xc))->vfC() != 0x11) {
        return 0;
    }
    *(u8*)(self + 0xb5) = v;
    return v;
}

extern "C" void fn_80181D44(VObj_8017C154* self, f32 x, f32 y) {
    u8 buf[48];
    fn_801C5D48(buf);
    self->vf38(buf, x, y);
}

extern "C" int fn_80182058(char* self, void* v) {
    UnkVObj_80181CCC* o = *(UnkVObj_80181CCC**)(self + 0x100);
    if (o != 0 && o->vf3C() == v) {
        return 1;
    }
    return ((int (*)(char*, void*))fn_80177F0C)(self, v);
}

extern "C" int fn_801820EC()
{
	return 0;
}

extern "C" void fn_801820F4(void) {
    fn_80177E84();
}

extern "C" void fn_801826C4(u8* self, u32 param_2, f32 f1, f32 f2) {
    f32 pos[4];
    u8 buf[56];
    pos[0] = *(f32*)(self + 0x20);
    pos[1] = *(f32*)(self + 0x24);
    pos[2] = *(f32*)(self + 0x28);
    pos[3] = *(f32*)(self + 0x2c);
    pos[0] += f1;
    pos[1] += f2;
    pos[2] += f1;
    pos[3] += f2;
    fn_801C5DA8(param_2, self + 0x80, buf);
    fn_801DF2A4(buf, 0);
    fn_80182764(self, pos, self + 0x114);
    fn_80177CA8(self, self + 0x114);
}

extern "C" s32 fn_80183BC4(u32* self, s32* param_2) {
    s32 local_14 = -1;
    s32 local_10 = -1;
    if (fn_80183FC8((s32)self, &local_14, &local_10) == 0) {
        return 0;
    }
    s32 local_c = *param_2;
    s32 local_8 = local_10;
    return ((VObj_80183C4C*)self)->vfA8(&local_c, &local_8);
}

extern "C" s32 fn_80183C4C(VObj_80183C4C* self, s32* p) {
    s32 local_14;
    s32 local_10;
    s32 local_c;
    s32 local_18;
    local_14 = -1;
    local_10 = -1;
    if (!(fn_80183FC8((s32)self, &local_14, &local_10) & 0xff)) {
        return 0;
    }
    local_18 = *p;
    local_c = local_14;
    return self->vfA8(&local_c, &local_18);
}

extern "C" s32 fn_80184164(char* self, s32* a, s32* b) {
    char* p;
    s32 i;
    if (*a == 0 && (u32)*b == 0xFFFFFFFF) {
        return 1;
    }
    p = self;
    for (i = 0; i < 4; i++) {
        VObj_80184164* obj = *(VObj_80184164**)(*(char**)(p + 0x148) + 0x70);
        if (obj->v4() == 1) {
            return 0;
        }
        p += 4;
    }
    return 1;
}

extern "C" u8 fn_80183FC8(s32 a, s32* b, s32* c);

extern "C" void fn_801841FC(s32* self, s32 a) {
    s32 local_14;
    s32 local_18;
    local_14 = -1;
    local_18 = -1;
    if (!(fn_80183FC8(a, &local_14, &local_18) & 0xff)) {
        *self = 0;
    } else {
        *self = local_14;
    }
}

extern "C" void fn_8018425C(s32* self, s32 a) {
    s32 local_14;
    s32 local_18;
    local_14 = -1;
    local_18 = -1;
    if (!(fn_80183FC8(a, &local_14, &local_18) & 0xff)) {
        *self = -1;
    } else {
        *self = local_18;
    }
}

extern "C" void fn_801842BC(u8* self, u8 v) {
    u8* p;
    u8* q;
    self[0xb2] = v;
    p = *(u8**)(self + 0x148);
    if (p != 0) {
        p = p + 0x10;
        if (p != 0) {
            p[3] = v;
        }
    }
    p = *(u8**)(self + 0x14c);
    if (p != 0) {
        p = p + 0x10;
        if (p != 0) {
            p[3] = v;
        }
    }
    q = self + 8;
    p = *(u8**)(self + 0x150);
    if (p != 0) {
        p = p + 0x10;
        if (p != 0) {
            p[3] = v;
        }
    }
    p = *(u8**)(q + 0x14c);
    if (p != 0) {
        p = p + 0x10;
        if (p != 0) {
            p[3] = v;
        }
    }
    p = *(u8**)(self + 0x160);
    if (p == 0) {
        return;
    }
    p = p + 0x10;
    if (p == 0) {
        return;
    }
    p[3] = v;
}

extern "C" void fn_801780D4(char* self, u8 v);
extern "C" void fn_80184340(char* self, u8 v) {
    u8* p;
    char* q;
    self[0xb1] = v;
    p = *(u8**)(self + 0x148);
    if (p != 0) {
        p[0x22] = v;
    }
    p = *(u8**)(self + 0x14c);
    if (p != 0) {
        p[0x22] = v;
    }
    q = self + 8;
    p = *(u8**)(self + 0x150);
    if (p != 0) {
        p[0x22] = v;
    }
    p = *(u8**)(q + 0x14c);
    if (p != 0) {
        p[0x22] = v;
    }
    p = *(u8**)(self + 0x160);
    if (p != 0) {
        p[0x22] = v;
    }
    fn_801780D4(self, v);
}

extern "C" void fn_801843B8(void* self) {
    void* child = *(void**)((u8*)self + 0x160);
    if (child != 0) {
        *((u8*)self + 0xb2) = *((u8*)child + 0x13);
    }
}

extern "C" s32 fn_801843D0(void* self, int a, int b) {
    VObj_801843* p = (VObj_801843*)((VObj_801843*)self)->vfB8();
    if (p != 0) {
        void* q = *(void**)((u8*)p + 0x70);
        if (q != 0) {
            return ((VObj_801843*)q)->vf98((u8)b);
        }
    }
    return 0;
}

extern "C" s32 fn_80184438(void* self, int b) {
    VObj_801843* p = (VObj_801843*)((VObj_801843*)self)->vfBC();
    if (p != 0) {
        void* q = *(void**)((u8*)p + 0x70);
        if (q != 0) {
            return ((VObj_801843*)q)->vf98((u8)b);
        }
    }
    return 0;
}

extern "C" s32 fn_80184800(u8* self, u8 idx);
extern "C" void fn_801845C0(u8* self, void* obj) {
    u8 i;
    for (i = 0; i < 4; i++) {
        if ((u8)fn_80184800(self, i)) {
            fn_8016A0B4(*(void**)(self + i * 4 + 0x148), obj);
        }
    }
    if (*(void**)(self + 0x160) != 0) {
        fn_8016A0B4(*(void**)(self + 0x160), obj);
    }
}

extern "C" void fn_80184650(u8* self, void* obj) {
    u8 i;
    for (i = 0; i < 4; i++) {
        if ((u8)fn_80184800(self, i)) {
            fn_8016A1F8(*(void**)(self + i * 4 + 0x148), obj);
        }
    }
    if (*(void**)(self + 0x160) != 0) {
        fn_8016A1F8(*(void**)(self + 0x160), obj);
    }
}

extern "C" void fn_801846E0(u8* self, void* obj) {
    u8 i;
    for (i = 0; i < 4; i++) {
        if ((u8)fn_80184800(self, i)) {
            fn_8016A39C(*(void**)(self + i * 4 + 0x148), obj);
        }
    }
    if (*(void**)(self + 0x160) != 0) {
        fn_8016A39C(*(void**)(self + 0x160), obj);
    }
}

extern "C" void fn_8016A530(void* p, void* obj);
extern "C" void fn_80184770(u8* self, void* obj) {
    u8 i;
    for (i = 0; i < 4; i++) {
        if ((u8)fn_80184800(self, i)) {
            fn_8016A530(*(void**)(self + i * 4 + 0x148), obj);
        }
    }
    if (*(void**)(self + 0x160) != 0) {
        fn_8016A530(*(void**)(self + 0x160), obj);
    }
}

extern "C" s32 fn_80184800(u8* self, u8 idx) {
    u8 i;
    for (i = 0; i < idx; i++) {
        if (*(u32*)(self + (i << 2) + 0x148) == *(u32*)(self + (idx << 2) + 0x148)) {
            return 0;
        }
    }
    return *(u32*)(self + (idx << 2) + 0x148) != 0;
}

extern "C" void fn_8018485C(u8* self, u32 v) {
    *(u32*)(self + 0x174) = v;
}

extern "C" u32 fn_80184B08(u8* self, u8 idx) {
    u32* p;
    if (idx >= 4) {
        return 0;
    }
    p = (u32*)self + idx;
    return p[0x52];
}

extern "C" u32 fn_80184B2C(u8* self) {
    return *(u32*)(self + 0x160);
}

extern "C" void fn_80184B34(u8* self, u32* out) {
    u32 a = *(u32*)(self + 0x148);
    u32 b = *(u32*)(self + 0x14c);
    out[0] = a;
    a = *(u32*)(self + 0x150);
    out[1] = b;
    b = *(u32*)(self + 0x154);
    out[2] = a;
    a = *(u32*)(self + 0x160);
    out[3] = b;
    out[4] = a;
}

extern "C" void fn_80184B60(void* self, f32 x, f32 y, f32 w, f32 h) {
    f32 pos[2];
    f32 rect[4];
    pos[0] = x;
    pos[1] = y;
    rect[0] = pos[0];
    rect[1] = pos[1];
    rect[2] = x + w;
    rect[3] = y + h;
    ((void (*)(void*, f32*))(*(void***)self)[0x94 / 4])(self, rect);
}

extern "C" void fn_80184BB8(VObj_80178E10* self, u8 flag) {
    int mode = 0;
    if (flag) {
        mode = 2;
    }
    self->vf20(mode);
}

extern "C" void fn_80184BF4(void) {
    fn_80177F0C();
}

extern "C" void fn_80184C14(void) {
    fn_80178990();
}

extern "C" void fn_80184C34(void) {
    fn_801788C0();
}

extern "C" void fn_80184C54(void) {
}

extern "C" void fn_80184C58(void* self, void* unused, void* param_3) {
    void* obj = *(void**)((u8*)self + 0x168);
    if (*(void**)((u8*)obj + 0x28) == 0) {
        if (((u8 (*)(void*, f32))(*(void***)self)[0x9c / 4])(self, *(f32*)&lbl_80301BF8) && param_3 != 0) {
            void* sub = *(void**)((u8*)*(void**)((u8*)self + 0x168) + 0x70);
            if (((void* (*)(void*, s32))(*(void***)sub)[0xa4 / 4])(sub, 0) == 0) {
                sub = *(void**)((u8*)*(void**)((u8*)self + 0x168) + 0x70);
                ((void (*)(void*, s32, void*))(*(void***)sub)[0x98 / 4])(sub, 0, param_3);
            }
        }
    }
}

extern "C" void* fn_80184FA8(void* self, s16 param_2) {
    if (self != nullptr) {
        *(void**)self = lbl_80299244;
        if (*((u8*)self + 0x198) != 0) {
            VObj_8018939C* obj = *(VObj_8018939C**)((u8*)self + 0x168);
            if (obj != nullptr) {
                obj->v0(1);
            }
        }
        fn_8017E1A4((u32*)self, 0);
        if (param_2 > 0) {
            fn_8015AB1C(self);
        }
    }
    return self;
}
#pragma dont_inline reset
extern "C" void fn_801851FC(u32* self, s32 a) {
    u8* p = (u8*)self;
    ((VObj_80180980*)self)->vf144(*(f32*)(p + 0x20), *(f32*)(p + 0x24), *(s16*)(p + 0x112), *(s16*)(p + 0x114), *(s16*)(p + 0x116), *(s16*)(p + 0x118), *(s16*)(p + 0x11a), *(s16*)(p + 0x11c), *(s16*)(p + 0x11e), *(s16*)(p + 0x120), a);
}

extern "C" s32 fn_80185520(void* self, s32 a, s32 b) {
    void* obj = *(void**)((u8*)self + 0x168);
    if (obj == nullptr) {
        return 0;
    }
    return ((VObj_80185520*)self)->vfc8(a, b, (u8)*(u32*)((u8*)obj + 0x28));
}

extern "C" u32 fn_80185568(VObj_80185DA4* self, u32 a, u32 b) {
    u8* p = *(u8**)((u8*)self + 0x168);
    if (p == NULL) {
        return 0;
    }
    u32 n = *(u32*)(p + 0x28);
    return self->v50(a, b, (u8)n);
}

extern "C" s32 fn_801855B0(u8* self) {
    u8* p = *(u8**)(self + 0x168);
    if (p == NULL) {
        return 0;
    }
    return ((VObj_80187834*)self)->vfd4(*(u32*)(p + 0x28));
}

extern "C" s32 fn_801855F8(u8* self, void* p, s32 b, s32 c, f32 f) {
    if (p == NULL) {
        return 0;
    }
    if (fn_80185B00(self, c) == 0) {
        return 0;
    }
    fn_801857C8(self, f, c);
    VObj_80187834* obj = *(VObj_80187834**)(*(u8**)(self + 0x168) + 0x70);
    obj->vf7c((u8)c, p, b);
    return 1;
}

extern "C" u8 fn_80185B00(void* self, s32 b);
extern "C" void fn_801857C8(void* self, f32 f, s32 b);
extern "C" s32 fn_80185724(void* self, s32 a, f32 f, s32 b) {
    if (a == 0) {
        return 0;
    }
    if (fn_80185B00(self, b) == 0) {
        return 0;
    }
    fn_801857C8(self, f, b);
    void* obj = *(void**)((u8*)*(void**)((u8*)self + 0x168) + 0x70);
    (*(void (**)(void*, u32, s32))((u8*)*(void**)obj + 0x80))(obj, b & 0xff, a);
    return 1;
}

extern "C" u32 fn_80185DA4(VObj_80185DA4* self) {
    u8* p = *(u8**)((u8*)self + 0x168);
    if (p == NULL) {
        return 0;
    }
    if (*(void**)(p + 0x70) == NULL) {
        return 0;
    }
    u32 n = *(u32*)(p + 0x28);
    return self->v52((u8)((u8)n - 1));
}

extern "C" void fn_801DCCA0(s32);
extern "C" void fn_801DAF24(s32);
extern "C" void fn_801DEA4C(s32);
extern "C" void fn_801DE24C(s32);
extern "C" void fn_801DBAE4(s32);
extern "C" void fn_801DBB28(s32);
extern "C" void fn_801926E4(void);
extern "C" void fn_80192730(void*);
extern "C" void fn_801927DC(void*);
extern "C" void fn_801928E0(void*);
extern "C" void fn_80192984(void*);
extern "C" void fn_80192C8C(void*);
extern "C" void fn_80192D84(void*);
extern u8 lbl_802FE644;
extern u8 lbl_802FE64C;
extern "C" u32 fn_80185ED0(u8* self, u8 b) {
    u8* p = *(u8**)(self + 0x168);
    if (p == NULL) {
        return 0;
    }
    if (*(void**)(p + 0x70) == NULL) {
        return 0;
    }
    u32 n = *(u32*)(p + 0x28);
    if ((u8)n > b && (u8)n != 1) {
        return 1;
    }
    return 0;
}

extern "C" void fn_80186B6C(u8* self, u32 a, u32 b) {
    void* p = *(void**)(self + 0x168);
    if (p != NULL) {
        VObj_80186B6C* sub = *(VObj_80186B6C**)((u8*)p + 0x70);
        if (sub != NULL) {
            sub->v2(a, (u8)b);
        }
    }
}

extern "C" void fn_80187834(u8* self, u8 count) {
    u8 i;
    for (i = 0; i < count; i++) {
        if ((u8)i < 4) {
            VObj_80187834* p = *(VObj_80187834**)(*(u8**)(self + 0x168) + 0x70);
            p->vf44((u8)i, (u8)(0x1f - i * 4));
        } else {
            VObj_80187834* p = *(VObj_80187834**)(*(u8**)(self + 0x168) + 0x70);
            p->vf44((u8)i, (u8)(0x1e - (i - 4) * 4));
        }
    }
}

extern "C" void fn_801878E4(u8* self, u8 count) {
    u8 i;
    for (i = 0; i < count; i++) {
        if ((u8)i < 4) {
            VObj_80187834* p = *(VObj_80187834**)(*(u8**)(self + 0x168) + 0x70);
            p->vf4c((u8)i, (u8)(0x1d - i * 4));
        } else {
            VObj_80187834* p = *(VObj_80187834**)(*(u8**)(self + 0x168) + 0x70);
            p->vf4c((u8)i, (u8)(0x1c - (i - 4) * 4));
        }
    }
}

extern "C" void fn_80187388(u8* self, u8 mode);
extern "C" void fn_80187AAC(u8* self, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g, f32 h) {
    if (*(void**)(self + 0x168) != nullptr) {
        *(f32*)(self + 0x124) = a;
        *(f32*)(self + 0x128) = b;
        *(f32*)(self + 0x12c) = c;
        *(f32*)(self + 0x130) = d;
        *(f32*)(self + 0x178) = e;
        *(f32*)(self + 0x17c) = f;
        *(f32*)(self + 0x180) = g;
        *(f32*)(self + 0x184) = h;
        fn_80187388(self, *(u32*)(*(u8**)(self + 0x168) + 0x28));
    }
}

extern "C" void fn_80187B04(u8* self, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g, f32 h) {
    if (*(void**)(self + 0x168) != nullptr) {
        *(f32*)(self + 0x134) = a;
        *(f32*)(self + 0x138) = b;
        *(f32*)(self + 0x13c) = c;
        *(f32*)(self + 0x140) = d;
        *(f32*)(self + 0x188) = e;
        *(f32*)(self + 0x18c) = f;
        *(f32*)(self + 0x190) = g;
        *(f32*)(self + 0x194) = h;
        fn_80187388(self, *(u32*)(*(u8**)(self + 0x168) + 0x28));
    }
}

extern "C" void fn_80187CA4(u32* self, void* a, int b) {
    ((VObj_8017EB2C*)self)->v66(fn_8017A4A8(a), b);
}

extern "C" void fn_80187E64(u32* self, void* a, int b, int c) {
    ((VObj_80180980*)self)->vf118(fn_8017A4A8(a), b, c);
}

extern "C" int fn_80187ECC(u8* self, int arg) {
    if (*(u8**)(self + 0x168) == nullptr) {
        return 0;
    }
    VObj_80187ECC* obj = *(VObj_80187ECC**)(*(u8**)(self + 0x168) + 0x70);
    if (obj == nullptr) {
        return 0;
    }
    return obj->vfA0(arg);
}

extern "C" u32 fn_80187F24(void* self) {
    void* p = *(void**)((u8*)self + 0x168);
    if (p == 0) {
        return 0;
    }
    return *(u32*)((u8*)p + 0x28) & 0xff;
}

extern "C" s32 fn_80187F44(void* self, s32* param_2) {
    s32 local_14 = -1;
    s32 local_10 = -1;
    if (fn_801884B0((s32)self, &local_14, &local_10) == 0) {
        return 0;
    }
    s32 local_c;
    s32 local_18;
    local_c = *param_2;
    local_18 = local_10;
    return ((VObj_80187FCC*)self)->vf130(&local_c, &local_18);
}

extern "C" s32 fn_80187FCC(void* self, s32* param_2) {
    s32 local_14 = -1;
    s32 local_10 = -1;
    if (fn_801884B0((s32)self, &local_14, &local_10) == 0) {
        return 0;
    }
    s32 local_c;
    s32 local_18;
    local_18 = *param_2;
    local_c = local_14;
    return ((VObj_80187FCC*)self)->vf130(&local_c, &local_18);
}

extern "C" u8 fn_801884B0(s32 a, s32* b, s32* c);
extern "C" void fn_80188754(s32* self, s32 a) {
    s32 local_14;
    s32 local_18;
    local_14 = -1;
    local_18 = -1;
    if (!(fn_801884B0(a, &local_14, &local_18) & 0xff)) {
        *self = 0;
    } else {
        *self = local_14;
    }
}

extern "C" void fn_801887B4(s32* self, s32 a) {
    s32 local_14;
    s32 local_18;
    local_14 = -1;
    local_18 = -1;
    if (!(fn_801884B0(a, &local_14, &local_18) & 0xff)) {
        *self = -1;
    } else {
        *self = local_18;
    }
}

extern "C" void fn_80188814(u8* param_1, u8 param_2) {
    *(u8*)(param_1 + 0xb2) = param_2;
    void* p = *(void**)(param_1 + 0x168);
    if (p == nullptr) return;
    if (((u8*)p + 0x10) == 0) return;
    *(u8*)((u8*)p + 0x3) = param_2;
}

extern "C" void fn_80188928(u8* self, void* obj) {
    void* p = *(void**)(self + 0x168);
    if (p != nullptr) {
        fn_8016A0B4(p, obj);
    }
}

extern "C" void fn_80188954(u8* self, void* obj) {
    void* p = *(void**)(self + 0x168);
    if (p != nullptr) {
        fn_8016A1F8(p, obj);
    }
}

extern "C" void fn_80188980(u8* self, void* obj) {
    void* p = *(void**)(self + 0x168);
    if (p != nullptr) {
        fn_8016A39C(p, obj);
    }
}

extern "C" void fn_801889AC(u8* self, void* obj) {
    void* p = *(void**)(self + 0x168);
    if (p != nullptr) {
        fn_8016A530(p, obj);
    }
}

extern "C" void fn_80188DB0(void* self, int a, int b, int c) {
    ((VObj_80180920*)self)->vfCC(a, 0, c);
}

extern "C" void fn_80188DE0(void* self, int a, int b, int c) {
    ((VObj_80180920*)self)->vfC8(a, b, 0);
}

extern "C" void fn_80188E10(VObj_80180980* self, int a) {
    self->vfC4(a, 0);
}

extern "C" void fn_80188E40(void* self, int a, int b) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
        virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
        virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
        virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
        virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
        virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
        virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
        virtual void vfC8(int, int, int);
    };
    ((Obj*)self)->vfC8(a, b, 0);
}

extern "C" void fn_80188E70(void* self, int a) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
        virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
        virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
        virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
        virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
        virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
        virtual void v44(); virtual void v45(); virtual void v46();
        virtual void vfC4(int, int);
    };
    ((Obj*)self)->vfC4(a, 0);
}

extern "C" void fn_80188EA0(u32* self, int a, int b) {
    ((VObj_80180980*)self)->vfC8(a, 0, b);
}

extern "C" void fn_80188ED4(u32* self, int a, int b) {
    ((VObj_80180980*)self)->vfC0(a, 0, b);
}

extern "C" void fn_80188F48(VObj_80180980* self, f32 x0, f32 y0, f32 dx0, f32 dy0, f32 x1, f32 y1, f32 dx1, f32 dy1) {
    f32 a[4];
    f32 b[4];
    b[0] = x1;
    b[1] = y1;
    b[2] = x1 + dx1;
    b[3] = y1 + dy1;
    a[0] = x0;
    a[1] = y0;
    a[2] = x0 + dx0;
    a[3] = y0 + dy0;
    self->vfF0(a, b);
}

extern "C" void fn_80188FAC(void* self, u32 a) {
    ((VObj_80180868*)self)->v61((u8)a, a);
}

extern "C" void fn_80188FE0(VObj_80178E10* self, u8 flag) {
    int mode = 0;
    if (flag) {
        mode = 2;
    }
    self->vf20(mode);
}

extern "C" void fn_8018901C(void) {
    fn_80177F0C();
}

extern "C" void fn_80181724(void* self, s32 param_2);
extern void* lbl_802993CC[];
extern "C" void fn_8018903C(void) {
    fn_80178990();
}

extern "C" void fn_8018905C(void) {
    fn_801788C0();
}

extern "C" void* fn_8018939C(void* self, s16 param_2) {
    if (self != nullptr) {
        *(void**)self = lbl_802993CC;
        if (*((u8*)self + 0x140) != 0) {
            VObj_8018939C* obj = *(VObj_8018939C**)((u8*)self + 0x138);
            if (obj != nullptr) {
                obj->v0(1);
            }
        }
        fn_80181724(self, 0);
        if (param_2 > 0) {
            fn_8015AB1C(self);
        }
    }
    return self;
}

extern "C" void fn_80189BD8(void* self, u32 param_2) {
    if (param_2 != 0) {
        VObj_80189BD8* obj = *(VObj_80189BD8**)((u8*)self + 0x138);
        if (obj != nullptr) {
            VObj_80189BD8* sub = *(VObj_80189BD8**)((u8*)obj + 0x70);
            if (sub != nullptr) {
                sub->v35();
            }
        }
    }
}

extern "C" s32 fn_80189C24(u8* self) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
        virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
        virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
        virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
        virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
        virtual s32 v40();
    };
    u8* a = *(u8**)(self + 0x138);
    if (a != nullptr) {
        Obj* b = *(Obj**)(a + 0x70);
        if (b != nullptr) {
            return b->v40();
        }
    }
    return 0;
}

extern "C" void fn_80189D14(void* self, s32 value, s32 mode);
extern "C" void fn_80189C70(void* self, u8 flag) {
    void* obj = *(void**)((u8*)self + 0x138);
    VObj_80189C70* sub = *(VObj_80189C70**)((u8*)obj + 0x70);
    s32 val = sub->v24(0);
    if (flag == 0) {
        fn_80189D14(self, val, 0);
    } else {
        fn_80189D14(self, val, 1);
        sub = *(VObj_80189C70**)((u8*)*(void**)((u8*)self + 0x138) + 0x70);
        val = sub->v24(1);
        fn_80189D14(self, val, 2);
    }
}

extern "C" s32 fn_80189FDC(void* self, s32* param_2) {
    s32 local_14 = -1;
    s32 local_10 = -1;
    if (fn_8018A318(self, &local_14, &local_10) == 0) {
        return 0;
    }
    s32 local_c = *param_2;
    s32 local_18 = local_10;
    return ((s32 (*)(void*, s32*, s32*))(*(void***)self)[0xac / 4])(self, &local_c, &local_18);
}

extern "C" int fn_8018A064(void* self, s32* param_2) {
    s32 local_14 = -1;
    s32 local_10 = -1;
    if (fn_8018A318(self, &local_14, &local_10) == 0) {
        return 0;
    }
    s32 local_c;
    long local_18;
    local_18 = *param_2;
    local_c = local_14;
    return ((VObj_80189FDC*)self)->vfAC(&local_c, &local_18);
}

struct VObj_8018A4B4 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual u8 v4();
    virtual void v5();
    virtual u8 v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
};

extern "C" int fn_8018A4B4(u8* self, u32* p1, u32* p2) {
    VObj_8018A4B4* obj;
    if (*p1 == 0 && *p2 == 0xffffffff) {
        return 1;
    }
    obj = *(VObj_8018A4B4**)(*(u8**)(self + 0x138) + 0x70);
    obj->v20();
    obj = *(VObj_8018A4B4**)(*(u8**)(self + 0x138) + 0x70);
    if (obj->v4() == 1) {
        return 0;
    }
    return 1;
}

extern "C" void fn_8018A548(s32* self, void* a) {
    s32 local_14;
    s32 local_18;
    local_14 = -1;
    local_18 = -1;
    if (!(fn_8018A318(a, &local_14, &local_18) & 0xff)) {
        *self = 0;
    } else {
        *self = local_14;
    }
}

extern "C" void fn_8018A5A8(s32* self, void* a) {
    s32 local_14;
    s32 local_18;
    local_14 = -1;
    local_18 = -1;
    if (!(fn_8018A318(a, &local_14, &local_18) & 0xff)) {
        *self = -1;
    } else {
        *self = local_18;
    }
}

extern "C" void fn_8018A700(u8* self, void* obj) {
    void* p = *(void**)(self + 0x138);
    if (p != NULL) {
        fn_8016A0B4(p, obj);
    }
}

extern "C" void fn_8018A72C(u8* self, void* obj) {
    void* p = *(void**)(self + 0x138);
    if (p != NULL) {
        fn_8016A1F8(p, obj);
    }
}

extern "C" void fn_8018A758(u8* self, void* obj) {
    void* p = *(void**)(self + 0x138);
    if (p != NULL) {
        fn_8016A39C(p, obj);
    }
}

extern "C" void fn_8018A784(u8* self, void* obj) {
    void* p = *(void**)(self + 0x138);
    if (p != NULL) {
        fn_8016A530(p, obj);
    }
}

extern "C" void fn_8018A840(VObj_80178E10* self, u8 flag) {
    int mode = 0;
    if (flag) {
        mode = 2;
    }
    self->vf20(mode);
}

extern "C" void fn_8018A87C(void) {
    fn_80177E84();
}

extern "C" void fn_8018A8A0(void) {
    fn_80178990();
}

extern "C" void fn_8018A8C0(void) {
    fn_801788C0();
}

extern "C" void fn_8018B07C(void* ptr) {
    void* a = lbl_80299504;
    void* b = lbl_802994F0;
    *(void**)ptr = a;
    *(void**)ptr = b;
}

extern "C" void fn_80178990(void);
extern "C" void fn_801788C0(void);
extern "C" void fn_8015AB1C(void* p);
extern u8 lbl_802994F0[];
extern u8 lbl_80299504[];
extern "C" void* fn_8018B098(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802994F0;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299504;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_8018B384(void* self, void* dst, void* src);
extern "C" void fn_8018B35C(void* self, void* src) {
    fn_8018B384(self, *(void**)((u8*)self + 4), src);
}

extern "C" void fn_8018B448(void* self, void* dst, void* src);
extern "C" void fn_8018B420(void* self, void* src) {
    fn_8018B448(self, *(void**)((u8*)self + 4), src);
}

extern "C" void fn_8018B65C(void* self, void* dst, void* src);
extern "C" void fn_8018B634(void* self, void* src) {
    fn_8018B65C(self, *(void**)((u8*)self + 4), src);
}

extern "C" void fn_8018B770(void* self, void* dst, void* src);
extern "C" void fn_8018B748(void* self, void* src) {
    fn_8018B770(self, *(void**)((u8*)self + 4), src);
}

extern "C" void fn_8018B770(void* self, void* dst, void* src) {
    u8 flag = ((u8*)src)[8];
    *(s16*)((u8*)dst + 6) = *(s16*)((u8*)src + 10);
    u16 a = *(u16*)((u8*)src + 0xc);
    *(u8*)((u8*)dst + 4) = flag;
    u16 b = *(u16*)((u8*)src + 0xe);
    *(f32*)((u8*)dst + 8) = lbl_80301C30;
    *(u16*)((u8*)dst + 0x10) = a;
    u32 c = *(u32*)((u8*)src + 0x18);
    *(u16*)((u8*)dst + 0x12) = b;
    *(void**)((u8*)dst + 0x24) = fn_8018C290(src, c);
    *(void**)((u8*)dst + 0x28) = fn_8018C290(src, *(u32*)((u8*)src + 0x1c));
    *(void**)((u8*)dst + 0x14) = fn_8018C278(src, *(u32*)((u8*)src + 0x20));
    *(void**)((u8*)dst + 0x18) = fn_8018C278(src, *(u32*)((u8*)src + 0x24));
    *(void**)((u8*)dst + 0x1c) = fn_80174BA0(src, *(u32*)((u8*)src + 0x28));
    *(void**)((u8*)dst + 0x20) = fn_80174BA0(src, *(u32*)((u8*)src + 0x2c));
    *(void**)((u8*)dst + 0x2c) = fn_8018C2D8(src, *(u32*)((u8*)src + 0x30));
    *(void**)((u8*)dst + 0x30) = fn_8018C2D8(src, *(u32*)((u8*)src + 0x34));
    *(void**)((u8*)dst + 0x34) = fn_8018C2D8(src, *(u32*)((u8*)src + 0x38));
    *(void**)((u8*)dst + 0x38) = fn_8018C2D8(src, *(u32*)((u8*)src + 0x3c));
}

extern u8 lbl_802994BC[];
extern "C" void* fn_8018BAF0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802994BC;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299504;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_8018BB4C(void* self, void* src) {
    fn_8018BB74(self, *(void**)((u8*)self + 4), src);
}

extern "C" void fn_8018BC08(void* self, void* src) {
    fn_8018BC30(self, *(void**)((u8*)self + 4), src);
}

extern "C" void fn_8018BB74(void* self, void* dst, void* src);
extern "C" void fn_8018BC30(void* self, void* dst, void* src);
extern "C" void fn_8018BD24(void* self, void* dst, void* src);
extern "C" void fn_8018BCFC(void* self, void* src) {
    fn_8018BD24(self, *(void**)((u8*)self + 4), src);
}

extern f32 lbl_80301C30;
extern "C" void* fn_80174B40(void* base, u32 offset);
extern "C" void fn_8018BDF0(void* self, void* dst, void* src);
extern "C" void fn_8018BDC8(void* self, void* src) {
    fn_8018BDF0(self, *(void**)((u8*)self + 4), src);
}

extern "C" void fn_8018BF7C(void* self, void* src) {
    fn_8018BFA4(self, *(void**)((u8*)self + 4), src);
}

extern "C" void* fn_8018C1E8(void* base, u32 offset);
extern "C" void fn_8018BFA4(void* self, void* dst, void* src) {
    u8 flag = ((u8*)src)[8];
    *(s16*)((u8*)dst + 6) = *(s16*)((u8*)src + 10);
    u16 a = *(u16*)((u8*)src + 0xc);
    *(u8*)((u8*)dst + 4) = flag;
    u16 b = *(u16*)((u8*)src + 0xe);
    *(f32*)((u8*)dst + 8) = lbl_80301C30;
    *(u16*)((u8*)dst + 0x10) = a;
    u32 c = *(u32*)((u8*)src + 0x10);
    *(u16*)((u8*)dst + 0x12) = b;
    *(void**)((u8*)dst + 0x14) = fn_8018C1E8(src, c);
    *(void**)((u8*)dst + 0x18) = fn_80174B40(src, *(u32*)((u8*)src + 0x14));
}

extern "C" void fn_8018C048(void* unused, void* dest, void* src);
extern "C" void fn_8018C020(void* self, void* src) {
    fn_8018C048(self, *(void**)((u8*)self + 4), src);
}

extern "C" void* fn_8018C144(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299540;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80286A30;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_8018C1A0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299504;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_8018C1E8(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_8018C200(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_8018C230(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_8018C260(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_8018C278(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_8018C290(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_8018C2A8(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_8018C2C0(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_8018C2D8(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_8018C2F0(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_8018C308(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void fn_8018DEF0(void* self, u16 param_2, u8* param_3) {
    f32 pos = *(f32*)((u8*)self + 0x8);
    u8* table = *(u8**)((u8*)self + 0x14);
    u16 base = *(u16*)(table + param_2 * 4);
    if (pos < 0.0f) {
        u16 len = *(u16*)(table + param_2 * 4 + 2);
        *param_3 = (*(u8**)((u8*)self + 0x18))[len];
    } else if (pos >= (f32)base) {
        u16 len = *(u16*)(table + param_2 * 4 + 2);
        *param_3 = (*(u8**)((u8*)self + 0x18))[(s32)pos + len];
    } else {
        u16 len = *(u16*)(table + param_2 * 4 + 2);
        *param_3 = (*(u8**)((u8*)self + 0x18))[base + len - 1];
    }
}

extern f64 lbl_80301C58;
extern f32 __psq_l(void* p, int off, int w, int gqr);
extern "C" f32 fn_8018E63C(u16* hdr, s16* tbl, f32 key) {
    if (key < s16ToF32(tbl[0])) {
        return s16ToF32(tbl[1]);
    }
    return key;
}

extern "C" f32 fn_8018E870(u16* hdr, f32 t, f32* k) {
    if (t < k[0]) {
        return k[1];
    }
    if (hdr[2] == 0) {
        u32 n = hdr[0];
        if (k[(n - 1) * 3] <= t) {
            return k[(n - 1) * 3 + 1];
        }
        while (n > 1) {
            u32 half = n >> 1;
            u32 idx = half * 3;
            if (t >= k[idx]) {
                k += idx;
                n -= half;
            } else {
                n = half;
            }
        }
        f32 dt = t - k[0];
        f32 len = k[3] - k[0];
        f32 u = dt / len;
        f32 u2 = u * u;
        f32 dv = k[1] - k[4];
        f32 u2x = u + u;
        f32 w = u2 - u;
        f32 a = u2x * w - u2;
        f32 m0 = k[2];
        f32 m1 = k[5];
        f32 c = a * dv + k[1];
        f32 e = u * m0 - (m1 * w + (m0 * w + m0));
        return c - dt * e;
    } else {
        u32 n = hdr[0];
        if (k[(n - 1) * 4] <= t) {
            return k[(n - 1) * 4 + 1];
        }
        while (n > 1) {
            u32 half = n >> 1;
            if (t >= k[half * 4]) {
                k += half * 4;
                n -= half;
            } else {
                n = half;
            }
        }
        f32 dt = t - k[0];
        f32 len = k[4] - k[0];
        f32 u = dt / len;
        f32 u2 = u * u;
        f32 dv = k[1] - k[5];
        f32 u2x = u + u;
        f32 w = u2 - u;
        f32 a = u2x * w - u2;
        f32 m0 = k[3];
        f32 m1 = k[6];
        f32 c = a * dv + k[1];
        f32 e = u * m0 - (m1 * w + (m0 * w + m0));
        return c - dt * e;
    }
}

extern "C" void fn_8015AB1C(void*);
extern "C" void* fn_8018E9FC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299634;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299540;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_80286A30;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80299670[];
void fn_8015AB1C(void* ptr);
extern "C" void* fn_8018EA68(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299670;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299540;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_80286A30;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802996C0[];
extern void* lbl_8029970C[];
extern void* lbl_80286A4C[];
extern "C" void* fn_8018EAD4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802996C0;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029970C;
            if ((s32)ptr + 0x20 != 0) {
                ((void**)(ptr))[8] = lbl_80286A4C;
            }
            if (ptr != nullptr) {
                *(void**)ptr = lbl_80286A30;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802996F8[];
extern "C" void* fn_8018EB58(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802996F8;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029970C;
            if ((s32)ptr + 0x20 != 0) {
                ((void**)(ptr))[8] = lbl_80286A4C;
            }
            if (ptr != nullptr) {
                *(void**)ptr = lbl_80286A30;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80299764[];
extern "C" void* fn_8018EBDC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299764;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80286A1C;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_80286A30;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802997A4[];
extern void* lbl_80286A1C[];
extern u8 lbl_802FE624[8];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_8018EC78(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802997A4;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80286A1C;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_80286A30;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" int fn_801E6578(void* a, void* b);
extern "C" int fn_8018ECE4(void* self, void* arg) {
    void** node = *(void***)self;
    while (node != nullptr) {
        if (fn_801E6578(node[1], arg) == 0) {
            return (int)node[0];
        }
        node = (void**)node[2];
    }
    return 0;
}

extern "C" int fn_8018EE10(unsigned short* self, unsigned short index) {
    if (self[0] <= index) {
        return 0;
    }
    if (index == 0xffff) {
        return 0;
    }
    return (int)self + self[index + 1];
}

extern "C" void fn_8019054C(u32 idx, u32 a, u32 b, u32 c) {
    extern int* lbl_802FFA80;
    u32 w = ((a & 0xffff) - 1) | (((b & 0xffff) - 1) << 10) | (c << 20) | (lbl_802FE624[idx] << 24);
    *(*(u8**)&lbl_802FFA80[2])++ = 0x61;
    *(*(u8**)&lbl_802FFA80[2])++ = w >> 24;
    *(*(u8**)&lbl_802FFA80[2])++ = w >> 16;
    *(*(u8**)&lbl_802FFA80[2])++ = w >> 8;
    *(*(u8**)&lbl_802FFA80[2])++ = w;
}

extern u8 lbl_802FE62C[8];
extern u8 lbl_802FE634[8];
extern "C" void fn_801905F4(u32 idx, u32 addr) {
    extern int* lbl_802FFA80;
    u32 w = ((addr - 0x80000000) >> 5) | (lbl_802FE62C[idx] << 24);
    *(*(u8**)&lbl_802FFA80[2])++ = 0x61;
    *(*(u8**)&lbl_802FFA80[2])++ = w >> 24;
    *(*(u8**)&lbl_802FFA80[2])++ = w >> 16;
    *(*(u8**)&lbl_802FFA80[2])++ = w >> 8;
    *(*(u8**)&lbl_802FFA80[2])++ = w;
}

extern "C" void fn_80190758(u32 idx, u32 addr, u32 c) {
    extern int* lbl_802FFA80;
    u32 w = ((addr - 0x80000) >> 9) | (c << 10) | (lbl_802FE634[idx] << 24);
    *(*(u8**)&lbl_802FFA80[2])++ = 0x61;
    *(*(u8**)&lbl_802FFA80[2])++ = w >> 24;
    *(*(u8**)&lbl_802FFA80[2])++ = w >> 16;
    *(*(u8**)&lbl_802FFA80[2])++ = w >> 8;
    *(*(u8**)&lbl_802FFA80[2])++ = w;
}

extern "C" void fn_80191A60(u32* data, s32 index) {
    *(volatile u8*)0xCC008000 = 0x10;
    *(volatile u16*)0xCC008000 = 0xB;
    *(volatile u16*)0xCC008000 = (u16)(index << 2);
    *(volatile u32*)0xCC008000 = data[0];
    *(volatile u32*)0xCC008000 = data[1];
    *(volatile u32*)0xCC008000 = data[2];
    *(volatile u32*)0xCC008000 = data[3];
    *(volatile u32*)0xCC008000 = data[4];
    *(volatile u32*)0xCC008000 = data[5];
    *(volatile u32*)0xCC008000 = data[6];
    *(volatile u32*)0xCC008000 = data[7];
    *(volatile u32*)0xCC008000 = data[8];
    *(volatile u32*)0xCC008000 = data[9];
    *(volatile u32*)0xCC008000 = data[10];
    *(volatile u32*)0xCC008000 = data[11];
}

extern "C" void fn_80191AE0(u32* data, s32 index) {
    *(volatile u8*)0xCC008000 = 0x10;
    *(volatile u16*)0xCC008000 = 0x8;
    *(volatile u16*)0xCC008000 = (u16)(index * 3 + 0x400);
    *(volatile u32*)0xCC008000 = data[0];
    *(volatile u32*)0xCC008000 = data[1];
    *(volatile u32*)0xCC008000 = data[2];
    *(volatile u32*)0xCC008000 = data[4];
    *(volatile u32*)0xCC008000 = data[5];
    *(volatile u32*)0xCC008000 = data[6];
    *(volatile u32*)0xCC008000 = data[8];
    *(volatile u32*)0xCC008000 = data[9];
    *(volatile u32*)0xCC008000 = data[10];
}

extern "C" void fn_80191B4C(u32* data, s32 index) {
    *(volatile u8*)0xCC008000 = 0x10;
    *(volatile u16*)0xCC008000 = 0x8;
    *(volatile u16*)0xCC008000 = (u16)(index * 3 + 0x400);
    *(volatile u32*)0xCC008000 = data[0];
    *(volatile u32*)0xCC008000 = data[1];
    *(volatile u32*)0xCC008000 = data[2];
    *(volatile u32*)0xCC008000 = data[3];
    *(volatile u32*)0xCC008000 = data[4];
    *(volatile u32*)0xCC008000 = data[5];
    *(volatile u32*)0xCC008000 = data[6];
    *(volatile u32*)0xCC008000 = data[7];
    *(volatile u32*)0xCC008000 = data[8];
}

extern "C" void fn_80191BB8(u32* data, s32 index) {
    f32 z0 = 0.0f;
    f32 z1 = 0.0f;
    f32 z2 = 0.0f;
    *(volatile u8*)0xCC008000 = 0x10;
    *(volatile u16*)0xCC008000 = 0xB;
    *(volatile u16*)0xCC008000 = (u16)(index << 2);
    *(volatile u32*)0xCC008000 = data[0];
    *(volatile u32*)0xCC008000 = data[1];
    *(volatile u32*)0xCC008000 = data[2];
    *(volatile u32*)0xCC008000 = *(u32*)&z0;
    *(volatile u32*)0xCC008000 = data[4];
    *(volatile u32*)0xCC008000 = data[5];
    *(volatile u32*)0xCC008000 = data[6];
    *(volatile u32*)0xCC008000 = *(u32*)&z1;
    *(volatile u32*)0xCC008000 = data[8];
    *(volatile u32*)0xCC008000 = data[9];
    *(volatile u32*)0xCC008000 = data[10];
    *(volatile u32*)0xCC008000 = *(u32*)&z2;
}

extern f32 lbl_80301C6C;
extern "C" void fn_80191C50(u32* data, s32 index) {
    f32 z0 = lbl_80301C6C;
    f32 z1 = lbl_80301C6C;
    f32 z2 = lbl_80301C6C;
    *(volatile u8*)0xCC008000 = 0x10;
    *(volatile u16*)0xCC008000 = 0xB;
    *(volatile u16*)0xCC008000 = (u16)(index << 2);
    *(volatile u32*)0xCC008000 = data[0];
    *(volatile u32*)0xCC008000 = data[1];
    *(volatile u32*)0xCC008000 = data[2];
    *(volatile u32*)0xCC008000 = *(u32*)&z0;
    *(volatile u32*)0xCC008000 = data[3];
    *(volatile u32*)0xCC008000 = data[4];
    *(volatile u32*)0xCC008000 = data[5];
    *(volatile u32*)0xCC008000 = *(u32*)&z1;
    *(volatile u32*)0xCC008000 = data[6];
    *(volatile u32*)0xCC008000 = data[7];
    *(volatile u32*)0xCC008000 = data[8];
    *(volatile u32*)0xCC008000 = *(u32*)&z2;
}

extern "C" void fn_80191CE8(u32 p1, u32 p2, s32 p3, u32 p4, s32 p5) {
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = *((u8*)&lbl_802FE644 + p1) << 24 | (p3 + 3) << 18 | ((p2 >> 5) | (p3 + 3) << 15);
    if (p5 == 3) {
        return;
    }
    if (p4 >= 0x100000) {
        return;
    }
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = *((u8*)&lbl_802FE64C + p1) << 24 | (p5 + 3) << 18 | ((p4 >> 5) | (p5 + 3) << 15);
}

extern "C" void fn_80191E7C(u32 a, s16 b, u16 c) {
    *(volatile u8*)0xCC008000 = 0x20;
    *(volatile u16*)0xCC008000 = c;
    *(volatile u16*)0xCC008000 = (u16)(b * 0xc) | 0xb000;
}

extern "C" void fn_80191EA0(u32 a, s16 b, u16 c) {
    *(volatile u8*)0xCC008000 = 0x28;
    *(volatile u16*)0xCC008000 = c;
    *(volatile u16*)0xCC008000 = (u16)(b * 9 + 0x400) | 0x8000;
}

extern "C" void fn_80192688(void* p) {
    fn_801926E4();
    fn_80192730(p);
    fn_801927DC(p);
    fn_801928E0(p);
    fn_80192984(p);
    fn_80192C8C(p);
    fn_80192D84(p);
}

extern "C" void fn_801926E4(void) {
    fn_801DCCA0(0);
    fn_801DAF24(1);
    fn_801DEA4C(1);
    fn_801DE24C(0);
    fn_801DBAE4(2);
    fn_801DBB28(0);
}

