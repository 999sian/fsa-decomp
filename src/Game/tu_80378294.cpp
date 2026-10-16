

extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void __dl__FPv(void* p);
extern "C" void fn_801EE434(void);
extern char lbl_804AE888[];
extern "C" void* fn_80378D18(void* param_1, short param_2) {
    if (param_1 != 0) {
        *(void**)param_1 = (void*)lbl_804AE888;
        void* val = *(void**)((char*)param_1 + 0x230);
        if (val != 0) {
            ((void (*)(void*))fn_801EE434)(val);
            *(void**)((char*)param_1 + 0x230) = 0;
        }
        __dt__5ActorFv(param_1, 0);
        if (param_2 > 0) {
            __dl__FPv(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_80378D94(void* param_1) {
    *(float*)((char*)param_1 + 0x60) = -92.0f;
    *(float*)((char*)param_1 + 0x64) = -16.0f;
    *(float*)((char*)param_1 + 0x68) = 92.0f;
    *(float*)((char*)param_1 + 0x6c) = 16.0f;
    *(float*)((char*)param_1 + 0x70) = *(float*)((char*)param_1 + 0x60);
    *(float*)((char*)param_1 + 0x74) = *(float*)((char*)param_1 + 0x64);
    *(float*)((char*)param_1 + 0x78) = *(float*)((char*)param_1 + 0x68);
    *(float*)((char*)param_1 + 0x7c) = *(float*)((char*)param_1 + 0x6c);
    *(float*)((char*)param_1 + 0x80) = *(float*)((char*)param_1 + 0x60);
    *(float*)((char*)param_1 + 0x84) = *(float*)((char*)param_1 + 0x64);
    *(float*)((char*)param_1 + 0x88) = *(float*)((char*)param_1 + 0x68);
    *(float*)((char*)param_1 + 0x8c) = *(float*)((char*)param_1 + 0x6c);
    *(int*)((char*)param_1 + 0xb8) = 1;
    *(int*)((char*)param_1 + 0xf8) = 2;
    *(int*)((char*)param_1 + 0xbc) = 3;
    *(int*)((char*)param_1 + 0x1a4) = 1;
    *(int*)((char*)param_1 + 0xb0) = 0xa040304;
    *(int*)((char*)param_1 + 0x234) = 0;
    *(float*)((char*)param_1 + 0x23c) = 1.0f;
    *(float*)((char*)param_1 + 0x238) = 1.0f;
    *(int*)((char*)param_1 + 0x230) = 0;
    *(int*)((char*)param_1 + 0x240) = 0;
    *(unsigned char*)((char*)param_1 + 0x250) = 0;
    *(unsigned char*)((char*)param_1 + 0x251) = 0;
    *(int*)((char*)param_1 + 0x244) = 0;
    *(int*)((char*)param_1 + 0x248) = -1;
    *(int*)((char*)param_1 + 0x24c) = 0;
}

