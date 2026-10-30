#include "JSystem/J2D/J2DPane.h"
#include "JSystem/J2D/J2DScreen.h"
#include "JSystem/J2D/J2DPicture.h"
#include "Game/SinitPoolChain.h"


extern "C" void fn_8013B490(void*);
extern unsigned char* lbl_8053AB10;
extern float lbl_80543DA8;
struct J2DGrafContext;
struct J2DScreen;
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(J2DScreen*, float, float, const J2DGrafContext*);
extern "C" const u64 lbl_80490940[];
extern "C" const u8 lbl_80490B00[];
extern "C" u8 lbl_804B1C68[];
extern "C" void* fn_804030C4(u32, u32);
struct fn_80449494_Obj {
    virtual void Release(int);
};

extern u8* lbl_8053AED0;
extern "C" f32 fn_8043D514(u8*);
extern "C" f32 fn_8043D57C(u8*);
extern "C" void fn_80402E08(void*, f32, f32);
#pragma opt_propagation off
extern "C" void fn_80448940(u8* self) {
    u8* ptr;
    const u64* entry;
    int i;
    J2DPane* pane;
    void* handle;
    int ones;
    fn_80402E08(*(void**)(self + 8), lbl_80543DA8, fn_8043D514(lbl_8053AED0));
    entry = lbl_80490940;
    ptr = self;
    for (i = 0; i < 4; ++i, ptr += 4, entry += 14) {
        if (i < 2) {
            fn_80402E08(*(void**)(ptr + 0xc), lbl_80543DA8, fn_8043D514(lbl_8053AED0));
            fn_80402E08(*(void**)(ptr + 0x1c), lbl_80543DA8, fn_8043D514(lbl_8053AED0));
        } else {
            fn_80402E08(*(void**)(ptr + 0xc), lbl_80543DA8, fn_8043D57C(lbl_8053AED0));
            fn_80402E08(*(void**)(ptr + 0x1c), lbl_80543DA8, fn_8043D57C(lbl_8053AED0));
        }
        if (self[0x32] & (u8)(1 << i)) {
            if (((u8*)(*(J2DScreen**)(self + 4))->search(entry[6]))[0xb0] == 0) {
                (*(J2DScreen**)(self + 4))->search(entry[6])->show();
                (*(J2DScreen**)(self + 4))->search(entry[13])->show();
            }
        } else {
            if (((u8*)(*(J2DScreen**)(self + 4))->search(entry[6]))[0xb0] != 0) {
                (*(J2DScreen**)(self + 4))->search(entry[6])->hide();
                (*(J2DScreen**)(self + 4))->search(entry[13])->hide();
            }
        }
        if (((u8*)(*(J2DScreen**)(self + 4))->search(entry[6]))[0xb0] != 0) {
            if (self[0x2c + i] >= 100) self[0x2c + i] = 99;
            int num = self[0x2c + i];
            ones = num - (num / 10L) * 10L;
            handle = fn_804030C4(0x54494d47, ((u32*)lbl_804B1C68)[num / 10]);
            pane = (*(J2DScreen**)(self + 4))->search(entry[9]);
            ((J2DPicture*)pane)->changeTexture((ResTIMG*)handle, 0);
            pane = (*(J2DScreen**)(self + 4))->search(entry[10]);
            ((J2DPicture*)pane)->changeTexture((ResTIMG*)handle, 0);
            handle = fn_804030C4(0x54494d47, ((u32*)lbl_804B1C68)[ones]);
            pane = (*(J2DScreen**)(self + 4))->search(entry[11]);
            ((J2DPicture*)pane)->changeTexture((ResTIMG*)handle, 0);
            pane = (*(J2DScreen**)(self + 4))->search(entry[12]);
            ((J2DPicture*)pane)->changeTexture((ResTIMG*)handle, 0);
        }
    }
    if (self[0x32] & 0x10) {
        if (((u8*)(*(J2DScreen**)(self + 4))->search(*(const u64*)(lbl_80490B00 + 0x60)))[0xb0] == 0)
            (*(J2DScreen**)(self + 4))->search(*(const u64*)(lbl_80490B00 + 0x60))->show();
    } else {
        if (((u8*)(*(J2DScreen**)(self + 4))->search(*(const u64*)(lbl_80490B00 + 0x60)))[0xb0] != 0)
            (*(J2DScreen**)(self + 4))->search(*(const u64*)(lbl_80490B00 + 0x60))->hide();
    }
    if (((u8*)(*(J2DScreen**)(self + 4))->search(*(const u64*)(lbl_80490B00 + 0x60)))[0xb0] != 0) {
        if (self[0x30] >= 100) { self[0x30] = 99; self[0x31] = 99; }
        if (self[0x31] >= 100) self[0x31] = 99;
        int first = self[0x30];
        int tens;
        int second = self[0x31];
        s32 remainder = first - (first / 10L) * 10L;
        tens = second / 10;
        handle = fn_804030C4(0x54494d47, ((u32*)lbl_804B1C68)[first / 10]);
        pane = (*(J2DScreen**)(self + 4))->search(*(const u64*)(lbl_80490B00 + 0x20));
            ((J2DPicture*)pane)->changeTexture((ResTIMG*)handle, 0);
        pane = (*(J2DScreen**)(self + 4))->search(*(const u64*)(lbl_80490B00 + 0x28));
            ((J2DPicture*)pane)->changeTexture((ResTIMG*)handle, 0);
        handle = fn_804030C4(0x54494d47, ((u32*)lbl_804B1C68)[remainder]);
        pane = (*(J2DScreen**)(self + 4))->search(*(const u64*)(lbl_80490B00 + 0x30));
            ((J2DPicture*)pane)->changeTexture((ResTIMG*)handle, 0);
        pane = (*(J2DScreen**)(self + 4))->search(*(const u64*)(lbl_80490B00 + 0x38));
            ((J2DPicture*)pane)->changeTexture((ResTIMG*)handle, 0);
        handle = fn_804030C4(0x54494d47, ((u32*)lbl_804B1C68)[tens]);
        pane = (*(J2DScreen**)(self + 4))->search(*(const u64*)(lbl_80490B00 + 0x40));
            ((J2DPicture*)pane)->changeTexture((ResTIMG*)handle, 0);
        pane = (*(J2DScreen**)(self + 4))->search(*(const u64*)(lbl_80490B00 + 0x48));
            ((J2DPicture*)pane)->changeTexture((ResTIMG*)handle, 0);
        handle = fn_804030C4(0x54494d47, ((u32*)lbl_804B1C68)[second % 10]);
        pane = (*(J2DScreen**)(self + 4))->search(*(const u64*)(lbl_80490B00 + 0x50));
            ((J2DPicture*)pane)->changeTexture((ResTIMG*)handle, 0);
        pane = (*(J2DScreen**)(self + 4))->search(*(const u64*)(lbl_80490B00 + 0x58));
            ((J2DPicture*)pane)->changeTexture((ResTIMG*)handle, 0);
    }
    self[0x32] = 0;
}
#pragma opt_propagation reset
extern "C" void fn_80449070(void* self_) {
    u8* self = (u8*)self_;
    fn_8013B490(lbl_8053AB10);
    f32 f = lbl_80543DA8;
    draw__9J2DScreenFffPC14J2DGrafContext(*(J2DScreen**)(self + 4), f, f, *(const J2DGrafContext**)(lbl_8053AB10 + 0x10));
}

#pragma opt_propagation off
extern "C" void fn_804490B8(void* self_) {
    const u64* base = lbl_80490940;
    u8* self = (u8*)self_;
    const u64* entry = base;
    ResTIMG* handle;
    J2DPane* pane;
    s32 i;

    for (i = 0; i < 4; i++) {
        self[0x32] &= ~(u8)(1 << i);
        handle = (ResTIMG*)fn_804030C4(0x54494D47, *(u32*)&lbl_804B1C68);
        pane = (*(J2DScreen**)(self + 4))->search(*(u64*)(entry + 9));
        ((J2DPicture*)pane)->changeTexture((ResTIMG*)handle, 0);
        pane = (*(J2DScreen**)(self + 4))->search(*(u64*)(entry + 10));
        ((J2DPicture*)pane)->changeTexture((ResTIMG*)handle, 0);
        pane = (*(J2DScreen**)(self + 4))->search(*(u64*)(entry + 11));
        ((J2DPicture*)pane)->changeTexture((ResTIMG*)handle, 0);
        pane = (*(J2DScreen**)(self + 4))->search(*(u64*)(entry + 12));
        ((J2DPicture*)pane)->changeTexture((ResTIMG*)handle, 0);
        entry += 14;
    }

    self[0x32] &= ~0x10;
    handle = (ResTIMG*)fn_804030C4(0x54494D47, *(u32*)&lbl_804B1C68);
    pane = (*(J2DScreen**)(self + 4))->search(*(u64*)(lbl_80490B00 + 0x20));
    ((J2DPicture*)pane)->changeTexture((ResTIMG*)handle, 0);
    pane = (*(J2DScreen**)(self + 4))->search(*(u64*)(lbl_80490B00 + 0x28));
    ((J2DPicture*)pane)->changeTexture((ResTIMG*)handle, 0);
    pane = (*(J2DScreen**)(self + 4))->search(*(u64*)(lbl_80490B00 + 0x30));
    ((J2DPicture*)pane)->changeTexture((ResTIMG*)handle, 0);
    pane = (*(J2DScreen**)(self + 4))->search(*(u64*)(lbl_80490B00 + 0x38));
    ((J2DPicture*)pane)->changeTexture((ResTIMG*)handle, 0);
    pane = (*(J2DScreen**)(self + 4))->search(*(u64*)(lbl_80490B00 + 0x40));
    ((J2DPicture*)pane)->changeTexture((ResTIMG*)handle, 0);
    pane = (*(J2DScreen**)(self + 4))->search(*(u64*)(lbl_80490B00 + 0x48));
    ((J2DPicture*)pane)->changeTexture((ResTIMG*)handle, 0);
    pane = (*(J2DScreen**)(self + 4))->search(*(u64*)(lbl_80490B00 + 0x50));
    ((J2DPicture*)pane)->changeTexture((ResTIMG*)handle, 0);
    pane = (*(J2DScreen**)(self + 4))->search(*(u64*)(lbl_80490B00 + 0x58));
    ((J2DPicture*)pane)->changeTexture((ResTIMG*)handle, 0);

    for (i = 0; i < 4; i++) {
        pane = (*(J2DScreen**)(self + 4))->search(*(u64*)(base + 6));
        ((u8*)pane)[0xb0] = 0;
        pane = (*(J2DScreen**)(self + 4))->search(*(u64*)(base + 13));
        ((u8*)pane)[0xb0] = 0;
        base += 14;
    }

    pane = (*(J2DScreen**)(self + 4))->search(*(u64*)(lbl_80490B00 + 0x60));
    ((u8*)pane)[0xb0] = 0;
}
#pragma opt_propagation reset
extern "C" void __dl__FPv(void*);
extern "C" u8 lbl_804B1C90[];
extern u8* lbl_8053AF18;
extern "C" void* fn_80449494(void* param_1, short param_2) {
    void* result = param_1;

    if (result != 0) {
        *(void**)result = (void*)lbl_804B1C90;

        if (((fn_80449494_Obj**)result)[1] != 0) {
            ((fn_80449494_Obj**)result)[1]->Release(1);
        }
        ((fn_80449494_Obj**)result)[1] = 0;

        if (((fn_80449494_Obj**)result)[2] != 0) {
            ((fn_80449494_Obj**)result)[2]->Release(1);
        }
        ((fn_80449494_Obj**)result)[2] = 0;

        fn_80449494_Obj** ptr = (fn_80449494_Obj**)result;
        int i = 0;
        do {
            if (ptr[3] != 0) {
                ptr[3]->Release(1);
            }
            ptr[3] = 0;
            if (ptr[7] != 0) {
                ptr[7]->Release(1);
            }
            i++;
            ptr[7] = 0;
            ptr++;
        } while (i < 4);

        lbl_8053AF18 = 0;

        if (param_2 > 0) {
            __dl__FPv(result);
        }
    }

    return result;
}

extern "C" void* __nw__FUl(unsigned long);
extern "C" void fn_80402F04(void* obj, J2DPane* pane);
extern "C" u8 lbl_804AF86C[];
extern "C" const char lbl_80490C30[];
extern "C" u8 lbl_80529DEC[];
extern "C" const u64 lbl_80490940[];
extern "C" void* fn_804495B8(void* param_1) {
    void** result = (void**)param_1;

    *result = (void*)lbl_804B1C90;
    lbl_8053AF18 = (u8*)result;

    J2DScreen* screen = new J2DScreen();
    result[1] = screen;
    ((J2DScreen*)result[1])->setPriority(lbl_80490C30, 0x1100000, *(JKRArchive**)(lbl_80529DEC + 0x10));

    void* obj = __nw__FUl(0x2c);
    if (obj != 0) {
        *(void**)obj = lbl_804AF86C;
    }
    result[2] = obj;
    fn_80402F04(result[2], ((J2DScreen*)result[1])->search(0x004E646174613030ULL));

    void** ptr = result;
    int i = 0;
    do {
        u8* entry = (u8*)lbl_80490940 + i * 0x70;
        void* p3 = __nw__FUl(0x2c);
        if (p3 != 0) {
            *(void**)p3 = lbl_804AF86C;
        }
        ptr[3] = p3;
        u64 name1 = *(u64*)(entry + 0x30);
        fn_80402F04(ptr[3], ((J2DScreen*)result[1])->search(name1));

        void* p7 = __nw__FUl(0x2c);
        if (p7 != 0) {
            *(void**)p7 = lbl_804AF86C;
        }
        ptr[7] = p7;
        u64 name2 = *(u64*)(entry + 0x68);
        fn_80402F04(ptr[7], ((J2DScreen*)result[1])->search(name2));

        i++;
        ptr++;
    } while (i < 4);

    ((u8*)result)[0x2c] = 0;
    ((u8*)result)[0x2d] = 0;
    ((u8*)result)[0x2e] = 0;
    ((u8*)result)[0x2f] = 0;
    ((u8*)result)[0x30] = 0;
    ((u8*)result)[0x31] = 0;
    ((u8*)result)[0x32] = 0;
    return result;
}

