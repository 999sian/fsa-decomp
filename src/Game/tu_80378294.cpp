

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
