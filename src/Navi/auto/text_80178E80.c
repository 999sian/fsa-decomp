

extern "C" void fn_80184C58(UnkVObj_80184B60* self, void* unused, void* param_3) {
    void* obj = *(void**)((u8*)self + 0x168);
    if (*(void**)((u8*)obj + 0x28) == 0) {
        if (((s32 (*)(void*, void*))(*(void***)self)[0x9c / 4])(self, lbl_80301BF8) && param_3 != 0) {
            register UnkVObj_80184B60* sub = *(UnkVObj_80184B60**)((u8*)*(void**)((u8*)self + 0x168) + 0x70);
            if (sub->vA4(0) == 0) {
                sub = *(UnkVObj_80184B60**)((u8*)*(void**)((u8*)self + 0x168) + 0x70);
                sub->v98(0, param_3);
            }
        }
    }
}

extern "C" int fn_8018A064(void* self, s32* param_2) {
    register s32 local_14 = -1;
    register s32 local_10 = -1;
    if (fn_8018A318(self, &local_14, &local_10) == 0) {
        return 0;
    }
    s32 local_c;
    s32 local_18;
    local_18 = *param_2;
    local_c = local_14;
    void** vtbl = *(void***)self;
    return ((int (*)(void*, s32*, s32*))vtbl[0xac / 4])(self, &local_c, &local_18);
}

