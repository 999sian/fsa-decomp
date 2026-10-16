#include "types.h"

extern "C" const float lbl_8053D628;
extern "C" char lbl_804A03A8[];
extern "C" char lbl_804661B0[];
extern "C" char lbl_804661BC[];
extern "C" void* lbl_8053AAF8;
struct FsaResMgr {
    virtual ~FsaResMgr() {}
    virtual void* slot2() { return 0; }
    virtual void* slot3() { return 0; }
    virtual void* slot4() { return 0; }
    virtual void* slot5() { return 0; }
    virtual void* getRes(u32 id, const char* name) { return 0; }
};
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void __ct__Q29JGeometry8TVec3_f_Fv();
extern "C" void getTotalFreeSize__7JKRHeapFv(void* heap);
extern "C" void* __nw__FUlP7JKRHeapi(u32 size, void* heap, s32 align);
extern "C" void storeTIMG__10JUTTextureFPC7ResTIMGUc(char* self, const void* timg, u8 palette);
extern "C" void __dt__10JUTTextureFv(void*, int);
void operator delete(void*);
extern "C" u8 fn_8015F8FC(char* p, s32 room, f32* pos, s32 flag) {
    u8 ret = 0;
    if (room < 8) {
        for (s32 i = 0; i < 0x20; i++) {
            if (*(s32*)(p + i * 4 + 0x204) == 0) {
                *(s32*)(p + i * 4 + 4) = flag;
                ret = 1;
                *(f32*)(p + i * 12 + 0x84) = pos[0];
                *(f32*)(p + i * 12 + 0x88) = pos[1];
                *(f32*)(p + i * 12 + 0x8c) = pos[2];
                switch (flag) {
                case 0:
                case 1:
                    *(s32*)(p + i * 4 + 0x204) = 0x1e;
                    break;
                case 4:
                    *(s32*)(p + i * 4 + 0x204) = 0x73;
                    break;
                default:
                    *(s32*)(p + i * 4 + 0x204) = 1;
                    break;
                }
                break;
            }
        }
    }
    return ret;
}

extern "C" void fn_801601E0(char* p) {
    u32* w = (u32*)(p + 0x204);
    for (int i = 0; i < 32; i++) w[i] = 0;
    p[0x284] = 0;
    *(float*)(p + 0x288) = lbl_8053D628;
    *(float*)(p + 0x28c) = lbl_8053D628;
}

extern "C" void* fn_80160278(void* p, s16 flag) {
    if (p != 0) {
        *(void**)p = lbl_804A03A8;
        __dt__10JUTTextureFv(*(void**)((char*)p + 0x294), 1);
        __dt__10JUTTextureFv(*(void**)((char*)p + 0x290), 1);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void* fn_801602E8(u8* p, void* heap) {
    *(void**)p = lbl_804A03A8;
    __construct_array(p + 0x84, (void*)__ct__Q29JGeometry8TVec3_f_Fv, 0, 0xc, 0x20);
    getTotalFreeSize__7JKRHeapFv(heap);
    u8* tex = (u8*)__nw__FUlP7JKRHeapi(0x40, heap, 0);
    if (tex != 0) {
        u8* g = (u8*)lbl_8053AAF8;
        void* res = ((void* (*)(void*, u32, void*))(*(void***)(*(void**)(g + 0xa4)))[6])(*(void**)(g + 0xa4), 0x3f3f3f3f, lbl_804661B0);
        *(u32*)(tex + 0x28) = 0;
        storeTIMG__10JUTTextureFPC7ResTIMGUc((char*)tex, res, 0);
        tex[0x3b] &= 2;
    }
    *(u8**)(p + 0x290) = tex;
    tex = (u8*)__nw__FUlP7JKRHeapi(0x40, heap, 0);
    if (tex != 0) {
        u8* g = (u8*)lbl_8053AAF8;
        void* res = ((void* (*)(void*, u32, void*))(*(void***)(*(void**)(g + 0xa4)))[6])(*(void**)(g + 0xa4), 0x3f3f3f3f, lbl_804661BC);
        *(u32*)(tex + 0x28) = 0;
        storeTIMG__10JUTTextureFPC7ResTIMGUc((char*)tex, res, 0);
        tex[0x3b] &= 2;
    }
    *(u8**)(p + 0x294) = tex;
    return p;
}

