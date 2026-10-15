

extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void __dl__FPv(void* p);
extern "C" void fn_801EE434(void);
extern "C" void* fn_8013C824(void);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(int a, int b);
extern char lbl_804AE678[];
extern "C" void __dt__5ActorFv(void* p, int how);
extern "C" void* fn_80375DBC(void* param_1, short param_2) {
    if (param_1 != 0) {
        *(void**)param_1 = (void*)lbl_804AE678;
        if (*(unsigned int*)((char*)param_1 + 0x230) != 0) {
            fn_801EE434();
            *(unsigned int*)((char*)param_1 + 0x230) = 0;
        }
        __dt__5ActorFv(param_1, 0);
        if (param_2 > 0) {
            __dl__FPv(param_1);
        }
    }
    return param_1;
}
