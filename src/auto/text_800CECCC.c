

extern void* lbl_8049AE38[];
extern void* lbl_8049AE24[];
extern void* lbl_8049AE10[];
extern void* lbl_8049AE4C[];
extern void* lbl_8049AE5C[];
extern void* __vt__10J3DAnmBase[];
extern void* __vt__15J3DAnmTransform[];
extern void __dl__FPv(void*);
extern "C" void fn_800D0204(void*, void*, void*);
extern "C" void fn_800D00F0(void*, void*, void*);
extern "C" void fn_800CFEF0(void*, void*, void*);
extern "C" void fn_800CF2B0(void*** p) {
    void** a = lbl_8049AE38;
    *p = a;
    *p = lbl_8049AE24;
}

extern "C" void fn_800CF370(void** p) {
    *p = lbl_8049AE10;
    *p = lbl_8049AE38;
}

extern "C" void fn_800CFEC8(void** self, void* data)
{
    fn_800CFEF0(self, self[1], data);
}

extern "C" void fn_800D00C8(void** self, void* data)
{
    fn_800D00F0(self, self[1], data);
}

extern "C" void fn_800D01DC(void** self, void* data)
{
    fn_800D0204(self, self[1], data);
}

extern "C" void* fn_800D05BC(void* param_1, short param_2)
{
    if (param_1 != 0) {
        void** p = (void**)param_1;
        *p = &lbl_8049AE4C;
        if (param_1 != 0) {
            p = (void**)param_1;
            *p = &__vt__10J3DAnmBase;
        }
        if (param_2 > 0) {
            __dl__FPv(param_1);
        }
    }
    return param_1;
}

extern "C" int fn_800D0618(void)
{
    return 6;
}

extern "C" void* fn_800D0620(void* param_1, short param_2)
{
    if (param_1 != 0) {
        ((void**)param_1)[0] = &lbl_8049AE5C;
        if (param_1 != 0) {
            ((void**)param_1)[0] = &__vt__15J3DAnmTransform;
        }
        if (param_1 != 0) {
            ((void**)param_1)[0] = &__vt__10J3DAnmBase;
        }
        if (param_2 > 0) {
            __dl__FPv(param_1);
        }
    }
    return param_1;
}

extern "C" int fn_800D068C(void)
{
    return 8;
}

extern "C" void fn_800D0204(void*, void*, void*);
extern "C" void fn_800D00F0(void*, void*, void*);
extern "C" void fn_800CFEF0(void*, void*, void*);
extern "C" void* fn_800D06B8(const void* ptr, const void* offset)
{
    if (offset == 0) {
        return 0;
    }
    return (unsigned char*)ptr + (unsigned int)offset;
}

