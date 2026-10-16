

extern "C" char lbl_804AE8F4[];
extern "C" void __dt__5ActorFv(void* p, int flag);
extern "C" void __dl__FPv(void*);
extern "C" void* fn_80379078(void* param_1, short param_2) {
    if (param_1 != 0) {
        *(void**)param_1 = lbl_804AE8F4;
        __dt__5ActorFv(param_1, 0);
        if (param_2 > 0) {
            __dl__FPv(param_1);
        }
    }
    return param_1;
}
