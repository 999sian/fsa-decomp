#include "Game/SinitPoolChain.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"
extern void* lbl_80557E40;
extern void* lbl_80558260;



typedef unsigned char u8;

struct VObj {
    virtual void v00(int);
    virtual void v01();
};
extern char lbl_804AF480[];
extern u8 lbl_80529DEC[];
extern "C" void getTotalFreeSize__7JKRHeapFv(void* heap);
extern "C" void __dl__FPv(void* p);
extern u8* lbl_8053AAF8;
extern u8* lbl_8053ADF8;
extern u8* lbl_8053AE00;
extern "C" void fn_8040F480(void*);
extern "C" void fn_80416BD0(void*);
extern u8* lbl_8053AD80;
extern u8* lbl_8053AB10;
extern u8* lbl_8053AF80;
extern char lbl_80475670[];
struct TResMgr {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void* get(u32 type, const char* name);
};
extern "C" void fn_80158B3C(void* obj);
extern "C" void fn_802FF798(void* mgr);
extern "C" void fn_802F9714(void* mgr, void* res, s32 a, s32 b, s32 c, s32 d);
extern "C" void fn_802F93F4(void* mgr, void* res, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void* __nw__FUl(u32 size);
extern "C" void fn_804122F4(void* obj);
extern "C" void fn_8041787C(void* obj);
extern "C" void fn_80458FF0(void* obj, u32 id, s32 a, s32 b);
extern "C" void fn_80458408(void* obj, u32 id, s32 a);
extern "C" u8 fn_804580DC(void* obj, s32 a);
extern "C" void fn_80458090(void* obj);
extern "C" int fn_8040F474(void);
extern "C" int fn_80414F6C(void);
extern "C" int fn_8039003C(void) {
    if (lbl_8053AD80 != 0) {
        if (*(u8*)(lbl_8053AAF8 + 0x7f)) {
            return fn_8040F474();
        } else {
            return fn_80414F6C();
        }
    }
    return 6;
}

extern void* lbl_80558268;
extern "C" void fn_8044A28C(void*);
extern "C" void fn_8044C994(void*);
extern "C" void fn_80390088(void)
{
    if (*((u8*)lbl_80557E40 + 0x7f) != 0) {
        fn_8044A28C(lbl_80558260);
    } else {
        fn_8044C994(lbl_80558268);
    }
}

extern "C" void fn_804108B4(void*);
extern "C" void fn_804170B0__10TU80414F6CFv(void*);
extern "C" void fn_803900C8(void) {
    if (*(u8*)(lbl_8053AAF8 + 0x7f)) {
        fn_804108B4(lbl_8053ADF8);
    } else {
        fn_804170B0__10TU80414F6CFv(lbl_8053AE00);
    }
}

extern "C" void fn_804111C4(void*);
extern void* lbl_80557E40;
extern void* lbl_80558260;
extern "C" void fn_80444988(void*);
extern "C" void fn_80390108(void)
{
    if (*((u8*)lbl_80557E40 + 0x7f) != 0) {
        fn_80444988(lbl_80558260);
    }
}

extern "C" void fn_80411230(void*);
extern "C" void fn_804170EC(void*);
extern "C" void fn_8039013C(void) {
    if (*(u8*)(lbl_8053AAF8 + 0x7f)) {
        fn_80411230(lbl_8053ADF8);
    } else {
        fn_804170EC(lbl_8053AE00);
    }
}

extern "C" void* fn_8039017C(void* this_, short flag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AF480;
        getTotalFreeSize__7JKRHeapFv(*(void**)(lbl_80529DEC + 0x8));
        *(unsigned int*)(lbl_80529DEC + 0xf8) = 0;
        *(unsigned int*)(lbl_80529DEC + 0xfc) = 0;
        *(unsigned int*)(lbl_80529DEC + 0x100) = 0;
        *(unsigned int*)(lbl_80529DEC + 0x104) = 0;
        void* p1 = *(void**)((u8*)this_ + 0x4);
        if (p1 != 0) {
            if (p1 != 0) {
                ((VObj*)p1)->v00(1);
            }
            *(void**)((u8*)this_ + 0x4) = 0;
        }
        void* p2 = *(void**)((u8*)this_ + 0x8);
        if (p2 != 0) {
            if (p2 != 0) {
                ((VObj*)p2)->v00(1);
            }
            *(void**)((u8*)this_ + 0x8) = 0;
        }
        ((VObj*)*(void**)(lbl_80529DEC + 0x34))->v01();
        lbl_8053AD80 = 0;
        if (flag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

struct MenuManager {
    void* vtable;
    void* standard;
    void* handheld;
};

#pragma opt_propagation off
extern "C" void* fn_8039027C(MenuManager* this_) {
    MenuManager* self = this_;
    self->vtable = lbl_804AF480;
    getTotalFreeSize__7JKRHeapFv(*(void**)(lbl_80529DEC + 0x8));
    lbl_8053AD80 = (u8*)self;
    self->standard = 0;
    self->handheld = 0;
    fn_80158B3C(*(void**)(lbl_8053AB10 + 0x2c));
    if (lbl_80529DEC[0x242] == 0) {
        lbl_80529DEC[0x242] = 1;
        fn_802FF798(*(void**)(lbl_8053AB10 + 0x20));
        void* res = ((TResMgr*)*(void**)(lbl_8053AAF8 + 0xa4))->get(0x53434820, "gb_ch_obj_base_sch.szs");
        fn_802F9714(*(void**)(lbl_8053AB10 + 0x20), res, 0, 0, 0, 0);
        res = ((TResMgr*)*(void**)(lbl_8053AAF8 + 0xa4))->get(0x53434820, "gb_ch_obj_tr_schE.szs");
        fn_802F9714(*(void**)(lbl_8053AB10 + 0x20), res, 0, 0, 0x7000, 0);
        res = ((TResMgr*)*(void**)(lbl_8053AAF8 + 0xa4))->get(0x53434c20, "cu_cl_obj_base_scl.szs");
        fn_802F93F4(*(void**)(lbl_8053AB10 + 0x20), res, 0, 0, 0, 0, 0);
        res = ((TResMgr*)*(void**)(lbl_8053AAF8 + 0xa4))->get(0x53434820, "player_sch.szs");
        fn_802F9714(*(void**)(lbl_8053AB10 + 0x20), res, 0, 2, 0, 0);
        res = ((TResMgr*)*(void**)(lbl_8053AAF8 + 0xa4))->get(0x53434c20, "cu_cl_obj_base_scl.szs");
        fn_802F93F4(*(void**)(lbl_8053AB10 + 0x20), res, 0, 2, 0, 0, 0);
        res = ((TResMgr*)*(void**)(lbl_8053AAF8 + 0xa4))->get(0x53434820, "gals_sch.szs");
        fn_802F9714(*(void**)(lbl_8053AB10 + 0x20), res, 0, 3, 0, 0);
        res = ((TResMgr*)*(void**)(lbl_8053AAF8 + 0xa4))->get(0x53434c20, "cu_cl_obj_base_scl.szs");
        fn_802F93F4(*(void**)(lbl_8053AB10 + 0x20), res, 0, 3, 0, 0, 0);
        *((u8*)*(void**)(lbl_8053AB10 + 0x20) + 0x2364) = 1;
    }
    if (lbl_8053AAF8[0x7f] != 0) {
        void* p = __nw__FUl(0x66c);
        if (p != 0) fn_804122F4(p);
        self->standard = p;
    } else {
        void* p = __nw__FUl(0x154);
        if (p != 0) fn_8041787C(p);
        self->handheld = p;
    }
    if (*(u32*)(lbl_8053AF80 + 0x58) != 0x100001a) {
        fn_80458FF0(lbl_8053AF80, 0x100001a, 1, 0);
        fn_80458408(lbl_8053AF80, 0x100001a, 1);
        lbl_80529DEC[0x248] = 1;
    } else if (lbl_80529DEC[0x248] != 1) {
        fn_80458408(lbl_8053AF80, 0x100001a, 1);
        lbl_80529DEC[0x248] = 1;
    }
    if (!fn_804580DC(*(void**)(lbl_80529DEC + 0xc), 3)) {
        fn_80458090(lbl_8053AF80);
    }
    return this_;
}
#pragma opt_propagation reset
void __sinit_tu_8039003C_cpp(void) {}

