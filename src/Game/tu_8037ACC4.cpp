#include "types.h"


extern void* lbl_80557E40;
extern void* lbl_80558260;
extern void* lbl_80558268;
extern void* lbl_80558098;
extern void* lbl_804CA240[];
extern "C" void fn_8044AA04(void*);
extern "C" void fn_8044CD80(void*);
void operator delete(void*);
void* operator new(unsigned long);

typedef void (*DtorFn)(void*, s32);
struct VObj {
    void** vtbl;
};
struct Obj8044AA04 {
    Obj8044AA04() { fn_8044AA04(this); }
    u8 pad[0x188];
};
struct Obj8044CD80 {
    Obj8044CD80() { fn_8044CD80(this); }
    u8 pad[0x5c];
};
struct VBase {
    virtual ~VBase();
};
extern "C" void fn_80444988(void*);
extern "C" u32 fn_80444980(void*);
extern "C" u32 fn_8037ACC4(void)
{
    if (*((u8*)lbl_80557E40 + 0x7f) != 0) {
        return fn_80444980(lbl_80558260);
    }
    return 0;
}

extern "C" void fn_8037AD00(void)
{
    if (*((u8*)lbl_80557E40 + 0x7f) != 0) {
        fn_80444988(lbl_80558260);
    }
}

extern "C" u32 fn_80445110(void*);
extern "C" u32 fn_8037AD34(void)
{
    if (*((u8*)lbl_80557E40 + 0x7f) != 0) {
        return fn_80445110(lbl_80558260);
    }
    return 0;
}

extern "C" void fn_80445118(void*);
extern "C" void fn_8037AD70(void)
{
    if (*((u8*)lbl_80557E40 + 0x7f) != 0) {
        fn_80445118(lbl_80558260);
    }
}

extern "C" void fn_80445714(void*);
extern "C" void fn_8037ADA4(void)
{
    if (*((u8*)lbl_80557E40 + 0x7f) != 0) {
        fn_80445714(lbl_80558260);
    }
}

extern "C" u8 fn_8037ADD8(void)
{
    if (*((u8*)lbl_80557E40 + 0x7f) != 0) {
        return ((u8*)lbl_80558260)[0x13f];
    }
    return ((u8*)lbl_80558268)[0x54];
}

extern "C" void fn_8037AE00(void)
{
    if (*((u8*)lbl_80557E40 + 0x7f) != 0) {
        *((u8*)lbl_80558260 + 0x13f) = 0;
    } else {
        *((u8*)lbl_80558268 + 0x54) = 0;
    }
}

extern "C" void fn_8037AE30(void)
{
    if (*((u8*)lbl_80557E40 + 0x7f) != 0) {
        *((u8*)lbl_80558260 + 0x13f) = 1;
    } else {
        *((u8*)lbl_80558268 + 0x54) = 1;
    }
}

extern "C" void* lbl_80558098;
extern "C" u32 fn_804474E4(void);
extern "C" u32 fn_8044BA8C(void);
extern "C" u32 fn_80447500(void*);
extern "C" u32 fn_8044BAA8(void*);
extern "C" void fn_8044A28C(void*);
extern "C" void fn_8044C994(void*);
extern "C" u32 fn_8037AE60(void)
{
    u32 ret;
    if (lbl_80558098 != NULL) {
        if (*((u8*)lbl_80557E40 + 0x7f) != 0) {
            ret = fn_804474E4();
        } else {
            ret = fn_8044BA8C();
        }
    } else {
        ret = 9;
    }
    return ret;
}

extern "C" u32 fn_8037AEAC(void* arg)
{
    s32 ret;
    if (*((u8*)lbl_80557E40 + 0x7f) != 0) {
        ret = fn_80447500(lbl_80558260);
    } else {
        ret = fn_8044BAA8(lbl_80558268);
    }
    if ((s32)fn_8037AE60() != 9) {
        *((u8*)arg + 0xc) = 0;
    }
    return ret;
}

extern "C" void fn_8044A24C(void*);
extern "C" void fn_8037AF4C(void)
{
    if (*((u8*)lbl_80557E40 + 0x7f) != 0) {
        fn_8044A24C(lbl_80558260);
    }
}

extern "C" void fn_8037AF80(void)
{
    if (*((u8*)lbl_80557E40 + 0x7f) != 0) {
        fn_8044A28C(lbl_80558260);
    } else {
        fn_8044C994(lbl_80558268);
    }
}

extern "C" void fn_8044A2D4(void*);
extern "C" void fn_8044CA00(void*);
extern void* lbl_8053AAF8[2];
extern "C" void fn_80452350(void* subObj);
extern "C" void fn_80454A6C(void* subObj);
extern "C" void fn_8037AFC0(void* this_) {
    if (*(u8*)((char*)lbl_8053AAF8[0] + 0x7f) != 0) {
        fn_80452350(*(void**)((char*)this_ + 0x4));
    } else {
        fn_80454A6C(*(void**)((char*)this_ + 0x8));
    }
}

extern "C" void* fn_8037B000(VBase** self, s16 flag)
{
    if (self != NULL) {
        *(void**)self = lbl_804CA240;
        if (self[1] != NULL) {
            delete self[1];
            self[1] = NULL;
        }
        if (self[2] != NULL) {
            delete self[2];
            self[2] = NULL;
        }
        lbl_80558098 = NULL;
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}

extern "C" void* fn_8037B0B8(void** self)
{
    self[0] = lbl_804CA240;
    lbl_80558098 = self;
    self[1] = NULL;
    self[2] = NULL;
    *((u8*)self + 0xc) = 0;
    if (*((u8*)lbl_80557E40 + 0x7f) != 0) {
        self[1] = new Obj8044AA04;
    } else {
        self[2] = new Obj8044CD80;
    }
    return self;
}
#include "JSystem/JAudio/JASFakeMatchFSA.h"
