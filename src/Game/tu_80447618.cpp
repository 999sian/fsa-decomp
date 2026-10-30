#include "types.h"
struct fn_80447190_Obj {
    virtual void Release(int);
};


struct fn_80447B34_Obj {
    virtual void Release(int);
};

struct JKRArchive;
struct J2DPane {
virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C();
virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4C();
virtual void vf50(); virtual void vf54(); virtual void vf58(); virtual void vf5C();
virtual void vf60(); virtual void vf64(); virtual void vf68(); virtual void vf6C();
virtual void vf70(); virtual void vf74(); virtual void vf78(); virtual void vf7C();
virtual void vf80(); virtual void vf84(); virtual void vf88(); virtual void vf8C();
virtual void vf90(); virtual void vf94(); virtual void vf98(); virtual void vf9C();
virtual void vfA0(); virtual void vfA4(); virtual void vfA8(); virtual void vfAC();
virtual void vfB0(); virtual void vfB4(); virtual void vfB8(); virtual void vfBC();
virtual void vfC0(); virtual void vfC4(); virtual void vfC8(); virtual void vfCC();
virtual void vfD0(); virtual void vfD4(); virtual void vfD8(); virtual void vfDC();
virtual void vfE0(); virtual void vfE4(); virtual void vfE8(); virtual void vfEC();
virtual void vfF0(); virtual void vfF4(); virtual void vfF8(); virtual void vfFC();
virtual void vf100(); virtual void vf104();
virtual void changeTexture(void*, u8);
bool isVisible() const { return mVisible; }
void show() { mVisible = true; }
void hide() { mVisible = false; }
u8 pad[0xac];
bool mVisible;
};
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
    virtual J2DPane* search(u64);
    u8 pad[0x114];
};
struct TagEntry {
    u8 pad[0x30];
    u64 tag0;
    union {
        u8 pad2[0x30];
        struct {
            u8 pad2_[0x10];
            u64 tag2;
            u64 tag3;
            u64 tag4;
            u64 tag5;
        };
    };
    u64 tag1;
};
struct ArcHolder {
    u8 pad[0x10];
    JKRArchive* arc;
};
extern "C" {
extern const TagEntry lbl_80490410[];
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
extern void* lbl_804B1C20[];
extern void* lbl_8053AF08;
extern char lbl_80490698[];
extern char lbl_804AF86C[];
extern char lbl_80529DEC[];

extern void* __nw__FUl(unsigned long size);
extern void __ct__9J2DScreenFv();
extern void setPriority__9J2DScreenFPCcUlP10JKRArchive(void* pane, const char* name, unsigned long id, void* archive);
extern void fn_80402F04(void* a, void* b);
extern void* lbl_8053AED0;
extern f32 fn_8043D514(void* a);
extern f32 fn_8043D57C(void* a);
extern void fn_80402E08(void* a, f32 b, f32 c);
}

extern "C" void* fn_804030C4(u32 type, const char* name);
extern "C" const char* lbl_804B1BF8[];
typedef void (*PaneSetFn)(J2DPane*, void*, int);
extern "C" void fn_8013B490(void*);
extern u8* lbl_8053AB10;
extern f32 lbl_80543D98;
struct J2DGrafContext;
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(J2DScreen*, f32, f32, const J2DGrafContext*);
#pragma opt_propagation off
extern "C" void fn_80447618(Obj80447C30* self) {
    Obj80447C30* p;
    const TagEntry* params;
    s32 i;
    for (i = 0, params = lbl_80490410, p = self; i < 4; i++, p = (Obj80447C30*)((u8*)p + 4), params++) {
        if (i < 2) {
            fn_80402E08(p->a[0], lbl_80543D98, fn_8043D514(lbl_8053AED0));
            fn_80402E08(p->b[0], lbl_80543D98, fn_8043D514(lbl_8053AED0));
        } else {
            fn_80402E08(p->a[0], lbl_80543D98, fn_8043D57C(lbl_8053AED0));
            fn_80402E08(p->b[0], lbl_80543D98, fn_8043D57C(lbl_8053AED0));
        }
        if (self->f2c & (u8)(1 << i)) {
            if (!self->screen->search(params->tag0)->isVisible()) {
                self->screen->search(params->tag0)->show();
                self->screen->search(params->tag1)->show();
            }
        } else {
            if (self->screen->search(params->tag0)->isVisible()) {
                self->screen->search(params->tag0)->hide();
                self->screen->search(params->tag1)->hide();
            }
        }
        if (self->screen->search(params->tag0)->isVisible()) {
            u8* value = &self->f28 + i;
            if (*value >= 100) *value = 99;
            void* t;
            int val = *value;
            int mod = val % 10;
            t = fn_804030C4('TIMG', lbl_804B1BF8[val / 10]);
            self->screen->search(*(u64*)((u8*)params + 0x48))->changeTexture(t, 0);
            self->screen->search(*(u64*)((u8*)params + 0x50))->changeTexture(t, 0);
            t = fn_804030C4('TIMG', lbl_804B1BF8[mod]);
            self->screen->search(*(u64*)((u8*)params + 0x58))->changeTexture(t, 0);
            self->screen->search(*(u64*)((u8*)params + 0x60))->changeTexture(t, 0);
        }
    }
    self->f2c = 0;
}
#pragma opt_propagation reset
extern "C" void fn_80447958(void* self_) {
    u8* self = (u8*)self_;
    fn_8013B490(lbl_8053AB10);
    f32 f = lbl_80543D98;
    draw__9J2DScreenFffPC14J2DGrafContext(*(J2DScreen**)(self + 4), f, f, *(const J2DGrafContext**)(lbl_8053AB10 + 0x10));
}

extern "C" void fn_804479A0(Obj80447C30* self)
{
    void* res;
    for (int i = 0; i < 4; i++) {
        self->f2c &= ~(u8)(1 << i);
        res = fn_804030C4('TIMG', lbl_804B1BF8[0]);
        self->screen->search(*(u64*)(lbl_80490410[i].pad2 + 0x10))->changeTexture(res, 0);
        self->screen->search(*(u64*)(lbl_80490410[i].pad2 + 0x18))->changeTexture(res, 0);
        self->screen->search(*(u64*)(lbl_80490410[i].pad2 + 0x20))->changeTexture(res, 0);
        self->screen->search(*(u64*)(lbl_80490410[i].pad2 + 0x28))->changeTexture(res, 0);
        self->screen->search(lbl_80490410[i].tag0)->hide();
        self->screen->search(lbl_80490410[i].tag1)->hide();
    }
}

extern "C" void __dl__FPv(void*);
extern "C" void* fn_80447B34(void* param_1, short param_2)
{
    void* result = param_1;

    if (result != 0) {
        *(void**)result = (void*)lbl_804B1C20;

        if (((fn_80447190_Obj**)result)[1] != 0) {
            ((fn_80447190_Obj**)result)[1]->Release(1);
        }
        ((fn_80447190_Obj**)result)[1] = 0;

        fn_80447190_Obj** ptr = (fn_80447190_Obj**)result;
        int i = 0;
        do {
            if (ptr[2] != 0) {
                ptr[2]->Release(1);
            }
            ptr[2] = 0;
            if (ptr[6] != 0) {
                ptr[6]->Release(1);
            }
            i++;
            ptr[6] = 0;
            ptr++;
        } while (i < 4);

        lbl_8053AF08 = 0;

        if (param_2 > 0) {
            __dl__FPv(result);
        }
    }

    return result;
}

extern "C" Obj80447C30* fn_80447C30(Obj80447C30* self) {
    self->vt = &lbl_804B1C20;
    lbl_8053AF08 = self;
    self->screen = new J2DScreen();
    self->screen->setPriority((const char*)&lbl_80490698, 0x1100000, ((ArcHolder*)&lbl_80529DEC)->arc);
    for (int i = 0; i < 4; i++) {
        PaneCtrl* p = (PaneCtrl*)operator new(0x2c);
        if (p) p->vt = &lbl_804AF86C;
        self->a[i] = p;
        u64 tag0 = lbl_80490410[i].tag0;
        fn_80402F04(self->a[i], self->screen->search(tag0));
        p = (PaneCtrl*)operator new(0x2c);
        if (p) p->vt = &lbl_804AF86C;
        self->b[i] = p;
        u64 tag1 = lbl_80490410[i].tag1;
        fn_80402F04(self->b[i], self->screen->search(tag1));
    }
    self->f28 = 0;
    self->f29 = 0;
    self->f2a = 0;
    self->f2b = 0;
    self->f2c = 0;
    return self;
}

extern "C" char lbl_8052D000[];
extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __register_global_object(void*, void (*)(void*), void*);
extern "C" char memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[];
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" char memPool___30JASPoolAllocObject_9JAIStream[];
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*);
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" char memPool___35JASPoolAllocObject_13JAISoundChild[];
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" char memPool___27JASPoolAllocObject_6JAISeq[];
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*);
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" char memPool___26JASPoolAllocObject_5JAISe[];
extern "C" void __dt__18JASMemPool_5JAISeFv(void*);
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;
extern "C" void fn_80447D88(void) {
    u32 base = (u32)lbl_8052D000;

    if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, (void*)(base + 0));
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, (void*)(base + 0xc));
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, (void*)(base + 0x18));
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, (void*)(base + 0x24));
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, (void*)(base + 0x30));
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, (void*)(base + 0x3c));
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, (void*)(base + 0x48));
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, (void*)(base + 0x54));
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, (void*)(base + 0x60));
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}

