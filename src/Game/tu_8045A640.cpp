#include "types.h"
#include "Game/SinitPoolChain.h"

extern char lbl_804B2098[];
extern f32 lbl_80543ED8;
extern f64 lbl_80543EE0;
extern void* lbl_80543F0C;
extern char lbl_80495470[];
extern void* sInstance__33JASGlobalInstance__12JAISoundInfo;
extern void __dt__16JAIStreamDataMgrFv(void*, int);
extern void __dt__12JAISoundInfoFv(void*, int);
extern void __dl__FPv(void*);

#include "JSystem/JAudio/Interface/JAISound.h"

extern "C" void* getData__13JAUSoundTableCF10JAISoundID(void*, JAISoundID);
extern "C" u8 getTypeID__13JAUSoundTableCF10JAISoundID(void*, JAISoundID);

extern "C" void* fn_8045A640(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        char* base = lbl_804B2098;
        *(void**)p = (void*)base;
        *(void**)(p + 0x4) = (void*)(base + 0x24);
        *(void**)(p + 0x8) = (void*)(base + 0x34);
        __dt__16JAIStreamDataMgrFv((void*)(p + 0x8), 0);

        if (p + 0x4 != 0) {
            *(void**)(p + 0x4) = (void*)lbl_80495470;
            if (p + 0x4 != 0) {
                if (sInstance__33JASGlobalInstance__12JAISoundInfo == (void*)(p + 0x4)) {
                    sInstance__33JASGlobalInstance__12JAISoundInfo = 0;
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

extern "C" void fn_8045A700(void* this_, JAISoundID* param_2, void* param_3) {
    JAISoundID typeSoundID;
    JAISoundID soundID;
    u32 id = param_2->mId.mFullId;
    soundID.mId.mFullId = id;
    void* result = getData__13JAUSoundTableCF10JAISoundID(*(void**)((char*)this_ + 0xc), soundID);
    typeSoundID.mId.mFullId = id;
    u8 typeID = getTypeID__13JAUSoundTableCF10JAISoundID(*(void**)((char*)this_ + 0xc), typeSoundID);
    if (result != 0) {
        switch (typeID) {
        case 0x10:
            *(f32*)((char*)param_3 + 0x3c) = ((u8*)result)[2] / lbl_80543ED8;
            break;
        case 0x12:
            *(f32*)((char*)param_3 + 0x3c) = ((u8*)result)[2] / lbl_80543ED8;
            break;
        case 0x11:
            *(f32*)((char*)param_3 + 0x3c) = ((u8*)result)[2] / lbl_80543ED8;
            break;
        }
    }
}

extern "C" void fn_8045A81C(void* this_, JAISoundID* param_2, void* param_3) {
    char* p = (char*)param_3;
    if (p) p += 0x10;
    u32 id = param_2->mId.mFullId;
    void* data = getData__13JAUSoundTableCF10JAISoundID(*(void**)((char*)this_ + 0xc), JAISoundID(id));
    u8 typeID = getTypeID__13JAUSoundTableCF10JAISoundID(*(void**)((char*)this_ + 0xc), JAISoundID(id));
    if (data != 0) {
        switch (typeID) {
        case 0x10: *(f32*)(p + 0x3c) = ((u8*)data)[2] / lbl_80543ED8; break;
        case 0x12: *(f32*)(p + 0x3c) = ((u8*)data)[2] / lbl_80543ED8; break;
        case 0x11: *(f32*)(p + 0x3c) = ((u8*)data)[2] / lbl_80543ED8; break;
        }
    }
}

extern "C" s32 fn_8045A944(void* this_, JAISoundID* param_2) {
    u32 id = param_2->mId.mFullId;
    JAISoundID soundID;
    soundID.mId.mFullId = id;
    void* data = getData__13JAUSoundTableCF10JAISoundID(*(void**)((char*)this_ + 0xc), soundID);
    JAISoundID typeSoundID = *param_2;
    u8 typeID = getTypeID__13JAUSoundTableCF10JAISoundID(*(void**)((char*)this_ + 0xc), typeSoundID);
    if (data != 0) {
        switch (typeID) {
        case 0x10:
            return 0xff - ((u8*)data)[1];
        case 0x12:
            return 0xff - ((u8*)data)[1];
        case 0x11:
            return 0xff - ((u8*)data)[1];
        }
    }
    return 0;
}

extern "C" u32 fn_8045A9FC(void* this_, JAISoundID* param_2) {
    JAISoundID soundID;
    soundID.mId.mFullId = param_2->mId.mFullId;
    u8* data = (u8*)getData__13JAUSoundTableCF10JAISoundID(*(void**)((char*)this_ + 0xc), soundID);
    JAISoundID typeSoundID = *param_2;
    u8 typeID = getTypeID__13JAUSoundTableCF10JAISoundID(*(void**)((char*)this_ + 0xc), typeSoundID);
    if (data != 0) {
        if (typeID & 0x10) {
            return (*data >> 2) != 0;
        }
        if (typeID & 0x12) {
            return (*data >> 2) != 0;
        }
    }
    return 0;
}

extern "C" s32 fn_8045AAAC(void* this_, JAISoundID* param_2) {
    void* table = *(void**)((char*)this_ + 0xc);
    JAISoundID soundID = *param_2;
    void* result = getData__13JAUSoundTableCF10JAISoundID(table, soundID);
    JAISoundID typeSoundID = *param_2;
    u8 typeID = getTypeID__13JAUSoundTableCF10JAISoundID(*(void**)((char*)this_ + 0xc), typeSoundID);
    if (result != 0) {
        switch (typeID) {
        case 0x11:
            return *(s32*)((char*)result + 0x4);
        case 0x10:
            return *(s32*)((char*)result + 0x4);
        default:
            break;
        }
    }
    return -1;
}

extern "C" u8 fn_8045AB44(void* param_1, JAISoundID* param_2) {
    JAISoundID soundID = *param_2;
    void* data = getData__13JAUSoundTableCF10JAISoundID(*(void**)((char*)param_1 + 0xc), soundID);
    JAISoundID typeSoundID = *param_2;
    u8 typeID = getTypeID__13JAUSoundTableCF10JAISoundID(*(void**)((char*)param_1 + 0xc), typeSoundID);
    if (data != 0) {
        if ((s32)typeID != 0x11) {
            return 0xff;
        }
        return ((u8*)data)[8];
    }
    return 0xff;
}

extern "C" u16 fn_8045ABC8(void* param_1, JAISoundID* param_2) {
    JAISoundID soundID;
    soundID.mId.mFullId = param_2->mId.mFullId;
    void* data = getData__13JAUSoundTableCF10JAISoundID(*(void**)((char*)param_1 + 0xc), soundID);

    JAISoundID typeSoundID;
    typeSoundID.mId.mFullId = param_2->mId.mFullId;
    u8 typeID = getTypeID__13JAUSoundTableCF10JAISoundID(*(void**)((char*)param_1 + 0xc), typeSoundID);

    if (data != 0) {
        switch (typeID) {
            case 0x10: {
                u16 result = 0xf0;
                JAISoundID flagSoundID;
                flagSoundID.mId.mFullId = param_2->mId.mFullId;
                u32 flags = (*(u32 (**)(void*, JAISoundID*))(*(char**)param_1 + 0x50))(param_1, &flagSoundID);
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
                if (((u8*)param_2)[1] == 6) {
                    result &= 0xff7f;
                }
                return result;
            }
            default:
                break;
        }
    }
    return 0xffff;
}

extern "C" u32 fn_8045ACDC(void* param_1, u8* param_2) {
    if (param_2[0] == 0x1) {
        u32 tmp = *(u32*)param_2;
        return (((u8 (***)(void*, void*))param_1)[0][19](param_1, &tmp) & 0xff) - 1;
    }
    return param_2[1];
}

extern "C" s32 fn_8045AD30(void* param_1, u8* param_2) {
    switch (param_2[0]) {
    case 0:
        return 0;
    case 1:
        return 1;
    default:
        return -1;
    }
}

extern "C" u16 fn_8045AD64(void* param_1, JAISoundID* param_2) {
    void* result = getData__13JAUSoundTableCF10JAISoundID(*(void**)((char*)param_1 + 0xc), *param_2);
    JAISoundID typeSoundID = *param_2;
    u8 typeID = getTypeID__13JAUSoundTableCF10JAISoundID(*(void**)((char*)param_1 + 0xc), typeSoundID);
    if (result != 0) {
        if ((typeID & 0xff) == 0x11) {
            return *(u16*)((char*)result + 0xa);
        }
    }
    return 0xffff;
}

void fn_8045ADEC(void) {}

