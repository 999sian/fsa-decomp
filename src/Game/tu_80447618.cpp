#include "types.h"

struct JKRArchive;
struct J2DPane;
struct J2DScreen {
    J2DScreen();
    void setPriority(const char*, unsigned long, JKRArchive*);
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual J2DPane* search(u64);
    u8 pad[0x114];
};
struct TagEntry {
    u8 pad[0x30];
    u64 tag0;
    u8 pad2[0x30];
    u64 tag1;
};
struct ArcHolder {
    u8 pad[0x10];
    JKRArchive* arc;
};
extern "C" {
extern TagEntry lbl_80490410[];
extern ArcHolder lbl_80529DEC_;
}
struct PaneCtrl {
    PaneCtrl();
    void* vt;
    u8 pad[0x28];
};
struct Obj80447C30 {
    void* vt;
    J2DScreen* screen;
    PaneCtrl* a[4];
    PaneCtrl* b[4];
    u8 f28, f29, f2a, f2b, f2c;
};

extern "C" {
extern void* lbl_804B1C20;
extern void* lbl_8053AF08;
extern void* lbl_80490698;
extern void* lbl_804AF86C;
extern void* lbl_80529DEC;

extern void* __nw__FUl(unsigned long size);
extern void __ct__9J2DScreenFv();
extern void setPriority__9J2DScreenFPCcUlP10JKRArchive(void* pane, const char* name, unsigned long id, void* archive);
extern void fn_80402F04(void* a, void* b);
}

void* fn_80447C30(void* this_) {
    char* pthis = (char*)this_;
    void* screen;
    int i;
    void* obj;
    void* (*get_method)(void);
    void* param;
    
    *(void**)pthis = &lbl_804B1C20;
    *(void**)&lbl_8053AF08 = this_;
    
    screen = __nw__FUl(0x118);
    if (screen != 0) {
        __ct__9J2DScreenFv();
    }
    *(void**)(pthis + 0x4) = screen;
    
    setPriority__9J2DScreenFPCcUlP10JKRArchive(screen, (const char*)&lbl_80490698, 0x110, 0);
    
    for (i = 0; i < 4; i++) {
        obj = __nw__FUl(0x2c);
        if (obj != 0) {
            *(void**)obj = &lbl_804AF86C;
        }
        *(void**)(pthis + 8 + i * 4) = obj;
        
        get_method = *(void*(**)(void))(*(char**)screen + 0x3c);
        param = get_method();
        fn_80402F04(obj, param);
        
        obj = __nw__FUl(0x2c);
        if (obj != 0) {
            *(void**)obj = &lbl_804AF86C;
        }
        *(void**)(pthis + 0x18 + i * 4) = obj;
        
        get_method = *(void*(**)(void))(*(char**)screen + 0x3c);
        param = get_method();
        fn_80402F04(obj, param);
    }
    
    *(char*)(pthis + 0x28) = 0;
    *(char*)(pthis + 0x29) = 0;
    *(char*)(pthis + 0x2a) = 0;
    *(char*)(pthis + 0x2b) = 0;
    *(char*)(pthis + 0x2c) = 0;
    
    return this_;
}
