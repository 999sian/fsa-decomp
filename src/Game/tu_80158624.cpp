#include "types.h"

extern "C" void fn_80158B3C(char* p) {
    *(u8*)(p + 0x4) = 0xff;
    *(u8*)(p + 0x5) = 0xff;
    *(u8*)(p + 0x6) = 0xff;
    *(u8*)(p + 0x7) = 0;
    *(u8*)(p + 0xc) = 0xff;
}

extern "C" void fn_8015945C(char* p) {
    *(u8*)(p + 0x4) = 0xff;
    *(u8*)(p + 0x5) = 0xff;
    *(u8*)(p + 0x6) = 0xff;
    *(u8*)(p + 0x7) = 0;
    *(u8*)(p + 0xc) = 0xff;
    *(u8*)(p + 0xd) = 0;
    *(u8*)(p + 0xe) = 0xff;
}

extern "C" char lbl_804A0160[];
extern "C" char lbl_80465E28[];
extern "C" char* lbl_8053AAF8;
extern "C" void __dt__10JUTTextureFv(char* p, s32 flag);
extern "C" void __dl__FPv(void* p);
extern "C" void* __nw__FUlP7JKRHeapi(u32 size, void* heap, s32 align);
extern "C" void storeTIMG__10JUTTextureFPC7ResTIMGUc(char* self, const void* timg, u8 palette);
extern "C" char* fn_80159484(char* p, s16 param_2) {
    if (p != 0) {
        *(char**)p = lbl_804A0160;
        __dt__10JUTTextureFv(*(char**)(p + 0x8), 1);
        if (param_2 > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" char* fn_801594E8(char* p, void* heap) {
    struct VObj {
        virtual void v00();
        virtual void v01();
        virtual void v02();
        virtual void v03();
        virtual void* v04(u32, void*);
    };
    char* tex;
    VObj* sub;
    void* uVar2;

    *(char**)p = lbl_804A0160;
    *(s32*)(p + 0x4) = -1;
    tex = (char*)__nw__FUlP7JKRHeapi(0x40, heap, 0);
    if (tex != 0) {
        sub = *(VObj**)(lbl_8053AAF8 + 0xa4);
        uVar2 = sub->v04(0x3f3f3f3f, lbl_80465E28);
        *(s32*)(tex + 0x28) = 0;
        storeTIMG__10JUTTextureFPC7ResTIMGUc(tex, uVar2, 0);
        *(u8*)(tex + 0x3b) = *(u8*)(tex + 0x3b) & 2;
    }
    *(char**)(p + 0x8) = tex;
    return p;
}

