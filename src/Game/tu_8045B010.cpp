#include "types.h"


extern "C" void* fn_8045A640(void*);
extern "C" void fn_8045ABC8(void*);
extern "C" void fn_8045AD64(void*);
extern "C" void __ct__14WaveControllerFlll(void*, long, long, long);
extern "C" unsigned char lbl_804B20F8[];
#pragma mark fn_8045B010
extern "C" void fn_8045AD64(void* p);
extern "C" void fn_8045B010(void* p) {
    fn_8045AD64((char*)p - 4);
}
extern "C" void fn_8045ABC8(void* p);
extern "C" void fn_8045B018(void* p) {
    fn_8045ABC8((char*)p - 4);
}

#pragma mark fn_8045B010
extern "C" void fn_8045B020(void* p) {
    ((void (*)(void*))fn_8045A640)((char*)p - 8);
}

extern "C" void fn_80458880(void* a, u32 b, s32 c);
extern "C" void fn_80458F04(void* a, u32 b);
extern "C" void fn_80458FF0(void* a, u32 b, s32 c, s32 d);
extern "C" void* fn_80456334(void* a, u32* b, s32 c);
extern "C" void writePort__8JASTrackFUlUs(void* a, u32 b, u16 c);
extern void* lbl_8053AF80;
extern u32 lbl_8052DEE0[];
extern "C" void fn_8045B030(void* param_1, u8 param_2, s8 param_3) {
    u32 w;
    u8 sec;
    u32 local;
    void** piVar2 = 0;

    w = lbl_8052DEE0[param_2];
    sec = ((u8*)&w)[1];
    if (((u8*)&w)[0] == 1) {
        if (w == 0x1000002 || w == 0x1000023) {
            fn_80458F04(lbl_8053AF80, w);
        } else {
            fn_80458FF0(lbl_8053AF80, w, 1, 0);
        }
        return;
    }
    if (sec == 2 || sec == 1) {
        local = w;
        piVar2 = ((void** (*)(void*, u32*))(*(void***)((char*)param_1 + 8))[5])(param_1, &local);
    } else if (sec == 0) {
        fn_80458880(lbl_8053AF80, w, -1);
    } else {
        u32 tmp = w;
        piVar2 = (void**)fn_80456334(param_1, &tmp, 0);
    }
    if (param_3 != 0 && piVar2 != 0) {
        void* obj = *piVar2;
        if (obj != 0) {
            u32 r = ((u32 (*)(void*))(*(void***)obj)[8])(obj);
            writePort__8JASTrackFUlUs((void*)r, 9, param_3);
        }
    }
}

extern "C" char* fn_8045B46C(char* p, unsigned char value, long a, long b, long c) {
    __ct__14WaveControllerFlll(p, a, b, c);
    *(void**)(p + 8) = lbl_804B20F8;
    *(void**)(p + 0x18) = lbl_804B20F8 + 0x24;
    *(unsigned char*)(p + 0x5c) = value;
    return p;
}

