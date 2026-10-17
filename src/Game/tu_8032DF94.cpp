#include "Game/Actor.h"


extern "C" char lbl_804AB850[];
extern "C" void fn_801EE434(void*);
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" u32 fn_8022461C(void*);
extern "C" float lbl_80541E40;
struct JMathSinCos { f32 sin; f32 cos; };
extern "C" const JMathSinCos sincosTable___5JMath[];
extern "C" void* lbl_8053AAF8;
extern "C" u32 fn_8032EB28(char* p, void* a, void* b) {
    int t = (u16)fn_8022461C(b);
    if (t == 12 || t == 3 || t == 14) {
        *(float*)(p + 0x3c) = *(float*)(p + 0x40) = *(float*)(p + 0x44) = lbl_80541E40;
        *(s32*)(p + 0x230) = 5;
        return 0;
    }
    if (t == 13) {
        *(s32*)(p + 0x248) = 0;
        *(float*)(p + 0x3c) = *(float*)(p + 0x40) = *(float*)(p + 0x44) = lbl_80541E40;
        *(s32*)(p + 0x230) = 6;
        return 0;
    }
    return t != 0;
}

extern "C" void fn_8032EBD0(Actor* p) {
    *(u16*)((char*)p + 0x94) = (*(u32*)((char*)p + 0x90) >> 16) & 0xff;
    *(s32*)((char*)p + 0x264) = *(u32*)((char*)p + 0x90) & 7;
    *(s32*)((char*)p + 0x284) = 0;
    *(s32*)((char*)p + 0x24c) = 0;
    *(s32*)((char*)p + 0x250) = 0;
    *(s32*)((char*)p + 0x254) = 0;
    *(s32*)((char*)p + 0x258) = 0;
    *(s32*)((char*)p + 0x240) = 0;
    *(s32*)((char*)p + 0x244) = 0;
    *(s32*)((char*)p + 0x248) = 0;
    *(u16*)((char*)p + 0x268) = 0;
    *(s32*)((char*)p + 0x108) = 10000;
    *(s32*)((char*)p + 0x25c) = 0;
    *(s32*)((char*)p + 0x260) = -1;
    *(s32*)((char*)p + 0x98) = 0;
    *(f32*)((char*)p + 0x278) = *(f32*)((char*)p + 0xc);
    *(f32*)((char*)p + 0x27c) = *(f32*)((char*)p + 0x10);
    *(f32*)((char*)p + 0x280) = *(f32*)((char*)p + 0x14);
    *(s32*)((char*)p + 0x258) = 100;
    *(f32*)((char*)p + 0x238) = 1.0f;
    *(f32*)((char*)p + 0x23c) = 0.0f;
    if ((u8)p->v11()) {
        p->detach();
        return;
    }
    *(f32*)((char*)p + 0x234) = 30.0f;
    *(s32*)((char*)p + 0x230) = 0;
    {
        char* g = (char*)lbl_8053AAF8;
        u32 s = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
        *(u32*)(g + 0xb4) = s;
        u32 b = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
        *(s32*)((char*)p + 0x254) = (s32)(65535.0f * (*(f32*)&b - 1.0f));
    }
    switch (*(u16*)((char*)p + 0x94)) {
    case 1:
        *(f32*)((char*)p + 0x14) = 24.0f;
        *(s32*)((char*)p + 0x98) = 2;
        {
            char* g = (char*)lbl_8053AAF8;
            u32 s = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
            *(u32*)(g + 0xb4) = s;
            u32 b = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
            *(s32*)((char*)p + 0x98) |= (s32)(1.99f * (*(f32*)&b - 1.0f));
        }
        break;
    case 2:
        *(f32*)((char*)p + 0x14) = 24.0f;
        {
            char* g = (char*)lbl_8053AAF8;
            u32 s = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
            *(u32*)(g + 0xb4) = s;
            u32 b = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
            *(s32*)((char*)p + 0x98) |= (s32)(1.99f * (*(f32*)&b - 1.0f));
        }
        break;
    case 3:
        *(s32*)((char*)p + 0x258) = -100;
        /* fallthrough */
    case 4:
        *(f32*)((char*)p + 0x14) = 24.0f;
        *(f32*)((char*)p + 0xc) = *(f32*)((char*)p + 0x234) * sincosTable___5JMath[(u16)*(s32*)((char*)p + 0x254) >> 5].sin + *(f32*)((char*)p + 0x278);
        *(f32*)((char*)p + 0x10) = *(f32*)((char*)p + 0x234) * sincosTable___5JMath[(u16)*(s32*)((char*)p + 0x254) >> 5].cos + *(f32*)((char*)p + 0x27c);
        break;
    case 6:
        *(s32*)((char*)p + 0x230) = 4;
        break;
    case 5:
        *(s32*)((char*)p + 0x230) = 3;
        break;
    }
    *(f32*)((char*)p + 0x26c) = 0.0f;
    *(f32*)((char*)p + 0x270) = 0.0f;
    *(f32*)((char*)p + 0x274) = 0.0f;
    *(f32*)((char*)p + 0x3c) = 0.0f;
    *(f32*)((char*)p + 0x40) = 0.0f;
    *(f32*)((char*)p + 0x44) = 0.0f;
    *(f32*)((char*)p + 0x80) = -8.0f;
    *(f32*)((char*)p + 0x84) = -8.0f;
    *(f32*)((char*)p + 0x88) = 8.0f;
    *(f32*)((char*)p + 0x8c) = 8.0f;
    *(f32*)((char*)p + 0x60) = -4.0f;
    *(f32*)((char*)p + 0x64) = -4.0f;
    *(f32*)((char*)p + 0x68) = 4.0f;
    *(f32*)((char*)p + 0x6c) = 4.0f;
}

extern "C" Actor* fn_8032EEB8(Actor* p, s16 n) {
    if (p != NULL) {
        *(void**)p = lbl_804AB850;
        fn_801EE434(*(void**)((char*)p + 0x284));
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}


