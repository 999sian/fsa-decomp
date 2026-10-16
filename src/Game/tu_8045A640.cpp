#include "types.h"

extern void* lbl_804B2098;
extern f32 lbl_80543ED8;
extern f64 lbl_80543EE0;
extern void* lbl_80543F0C;
extern void* lbl_80495470;
extern void** sInstance__33JASGlobalInstance__12JAISoundInfo;
extern void __dt__16JAIStreamDataMgrFv(void*, int);
extern void __dt__12JAISoundInfoFv(void*, int);
extern void __dl__FPv(void*);

typedef struct {
    u32 id;
} JAISoundID;

extern void* getData__13JAUSoundTableCF10JAISoundID(void*, JAISoundID*);
extern u8 getTypeID__13JAUSoundTableCF10JAISoundID(void*, JAISoundID*);

extern "C" void* fn_8045A640(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        char* base = (char*)&lbl_804B2098;
        *(void**)p = (void*)base;
        *(void**)(p + 0x4) = (void*)(base + 0x24);
        *(void**)(p + 0x8) = (void*)(base + 0x34);
        __dt__16JAIStreamDataMgrFv((void*)(p + 0x8), 0);
        
        if (p + 0x4 != 0) {
            *(void**)(p + 0x4) = (void*)&lbl_80495470;
            if (p + 0x4 != 0) {
                if ((void*)(p + 0x4) == *sInstance__33JASGlobalInstance__12JAISoundInfo) {
                    *sInstance__33JASGlobalInstance__12JAISoundInfo = (void*)0;
                }
            }
        }
        __dt__12JAISoundInfoFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" s32 fn_8045A6F4(void) {
    return -1;
}

extern "C" void fn_8045A6FC(void) {
}

extern "C" u16 fn_8045ABC8(void* param_1, u8* param_2) {
    JAISoundID soundID;
    soundID = *(JAISoundID*)param_2;
    void* data = getData__13JAUSoundTableCF10JAISoundID(*(void**)((char*)param_1 + 0xc), &soundID);

    JAISoundID typeSoundID = *(JAISoundID*)param_2;
    u8 typeID = getTypeID__13JAUSoundTableCF10JAISoundID(*(void**)((char*)param_1 + 0xc), &typeSoundID);

    if (data == 0 || (typeID & 0xff) != 0x10) {
        return 0xffff;
    }

    JAISoundID flagSoundID = *(JAISoundID*)param_2;
    u32 flags = (*(u32 (**)(void*, JAISoundID*))(*(char**)param_1 + 0x50))(param_1, &flagSoundID);
    u16 result = 0xf0;
    if ((flags & 1) == 0) {
        result = 0x8f0;
    }
    if ((flags & 2) == 0) {
        result += 0x400;
    }
    if ((flags & 4) == 0) {
        result += 0x200;
    }
    if ((flags & 0x20) != 0) {
        result += 0x100;
    }
    if ((flags & 0x800000) != 0) {
        result += 1;
    }
    if (param_2[1] == 6) {
        result &= 0xff7f;
    }
    return result;
}

extern "C" u32 fn_8045ACDC(void* param_1, u8* param_2) {
    u8 val = param_2[0];
    if (val == 0x1) {
        u32 (*fn)(void) = *(u32 (**)(void))((char*)(*(void**)param_1) + 0x4c);
        u32 result = fn();
        return (result & 0xff) - 1;
    } else {
        return param_2[1];
    }
}

extern "C" s32 fn_8045AD30(void* param_1, u8* param_2) {
    u8 val = param_2[0];
    if (val == 1) {
        return 1;
    } else if (val == 0) {
        return 0;
    } else {
        return -1;
    }
}

extern "C" u16 fn_8045AD64(int param_1, u32 param_2_val) {
    void* table = *(void**)((char*)param_1 + 0xc);
    JAISoundID soundID;
    soundID.id = param_2_val;
    
    void* result = getData__13JAUSoundTableCF10JAISoundID(table, &soundID);
    
    if (result == 0) {
        return 0xffff;
    }
    
    u8 typeID = getTypeID__13JAUSoundTableCF10JAISoundID(table, &soundID);
    if ((typeID & 0xff) == 0x11) {
        return *(u16*)((char*)result + 0xa);
    }
    return 0xffff;
}

