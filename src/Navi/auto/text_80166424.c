#include <string.h>

extern "C" void fn_80172764(u8* param_1, int param_2, u8* param_3) {
    u32 b = param_3[1];
    u32 a = param_3[0];
    param_1[param_2 * 8 + 0x7e] = (param_1[param_2 * 8 + 0x7e] & ~0x3) | a;
    param_1[param_2 * 8 + 0x7e] = (param_1[param_2 * 8 + 0x7e] & ~0xc) | ((b & 0xff) << 2);
}

extern "C" void fn_80178AEC(void* param_1, void* param_2) {
    (*(void (**)(void*))(*(u8**)param_1 + 0x84))(param_1);
    register u8* it = *(u8**)((u8*)param_1 + 0xdc);
    if (it != NULL) {
        it -= 0xc;
    }
    while (it != NULL) {
        void* obj = *(void**)(it + 0xc);
        (*(void (**)(void*, void*))(*(u8**)obj + 0x80))(obj, param_2);
        it = *(u8**)(it + 0x18);
        if (it != NULL) {
            it -= 0xc;
        }
    }
}

extern "C" void fn_80178B74(void* param_1, void* param_2) {
    (*(void (**)(void*))(*(u8**)param_1 + 0x8c))(param_1);
    register u8* it = *(u8**)((u8*)param_1 + 0xdc);
    if (it != NULL) {
        it -= 0xc;
    }
    while (it != NULL) {
        void* obj = *(void**)(it + 0xc);
        (*(void (**)(void*, void*))(*(u8**)obj + 0x88))(obj, param_2);
        it = *(u8**)(it + 0x18);
        if (it != NULL) {
            it -= 0xc;
        }
    }
}

extern "C" void* fn_80178BFC(void* param_1, void* param_2) {
    if (*(void**)((u8*)param_1 + 0xf8) != NULL) {
        	register void* param_2 = *(void**)((u8*)param_1 + 0xf8);
    }
    u8* it = *(u8**)((u8*)param_1 + 0xdc);
    if (it != NULL) {
        it -= 0xc;
    }
    while (it != NULL) {
        void* obj = *(void**)(it + 0xc);
        (*(void (**)(void*, void*))(*(u8**)obj + 0x90))(obj, param_2);
        it = *(u8**)(it + 0x18);
        if (it != NULL) {
            it -= 0xc;
        }
    }
    fn_80178C9C(param_1, param_2);
    return param_2;
}

extern "C" void fn_80178DB0(void* param_1) {
      void* vtable = *(void**)param_1;
      void (*func)(void) = *(void(**)(void))((u8*)vtable + 0x74);
      func();
  }

