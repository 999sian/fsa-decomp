// TU 0x80401848-0x804023d0.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Not yet decompiled: fn_80401FEC/fn_80402054 (loader thread) and the
// __sinit; both need this TU's .bss (lbl_80528980 thread+stack, lbl_80529CA0
// queue) defined here, since retail addresses them off one section base.
#include "types.h"

// ---- from src/Game/fn_80401848_dtor.cpp ----
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804B0F90[];

extern "C" void* fn_80401848(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804B0F90;
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// ---- from src/Game/fn_80401890.cpp ----
extern void* lbl_804B0FA0[];
extern void* lbl_804B0FD0[];

extern "C" void free__7JKRHeapFPvP7JKRHeap(void* this_, s16 flag);

// fn_80401890 - destructor for lbl_804B0FA0, with the base destructor
// INLINED: installs its OWN vtable, then unconditionally (the 2nd "if
// (this)" guard is a leftover from the base destructor's own null
// check, always true here since we already know this_ != 0) installs
// the base's vtable (lbl_804B0FD0, same as fn_80401FA0/fn_80401CC0's
// target) before running the shared cleanup step.
extern "C" void* fn_80401890(void* this_, s16 arg) {
    if (this_ != 0) {
        *(void**)((char*)this_ + 0x8) = lbl_804B0FA0;
        if (this_ != 0) {
            *(void**)((char*)this_ + 0x8) = lbl_804B0FD0;
        }
        if (arg > 0) {
            free__7JKRHeapFPvP7JKRHeap(this_, 0);
        }
    }
    return this_;
}

// ---- DVD load nodes: execute ----
enum T18AllocDir { T18_ALLOC_FORWARD = 1, T18_ALLOC_BACKWARD = 2 };
extern "C" void* loadToMainRAM__12JKRDvdRipperFlPUc15JKRExpandSwitchUlP7JKRHeapQ212JKRDvdRipper15EAllocDirectionUlPiPUl(
    s32 entryNum, u8* dst, s32 expand, u32 size, void* heap, T18AllocDir dir, u32 offset, int* comp, u32* outSize);
extern "C" s32 getSize__7JKRHeapFPv(void* heap, void* ptr);
extern void* lbl_8053ADF4;

extern "C" BOOL fn_804018F0(char* this_) {
    void* h = *(void**)(this_ + 0x1c);
    void* heap;
    if (h != NULL) {
        heap = h;
    } else {
        heap = lbl_8053ADF4;
    }
    *(void**)(this_ + 0x14) = loadToMainRAM__12JKRDvdRipperFlPUc15JKRExpandSwitchUlP7JKRHeapQ212JKRDvdRipper15EAllocDirectionUlPiPUl(
        *(s32*)(this_ + 0x10), NULL, 1, 0, heap, *(u8*)(this_ + 0xc) == 1 ? T18_ALLOC_FORWARD : T18_ALLOC_BACKWARD, 0, NULL, NULL);
    if (*(void**)(this_ + 0x14) != NULL) {
        *(s32*)(this_ + 0x18) = getSize__7JKRHeapFPv(heap, *(void**)(this_ + 0x14));
    }
    *(u8*)(this_ + 0x4) = 1;
    return *(void**)(this_ + 0x14) != NULL;
}



// ---- from src/Game/EffectQueueEnqueueSmall_804019A8.cpp ----
extern "C" s32 DVDConvertPathToEntrynum(void* arg1);
extern "C" char* alloc__7JKRHeapFUliP7JKRHeap(s32 size, s32 align, void* heap);
extern "C" void OSLockMutex(void* mutex);
extern "C" void OSUnlockMutex(void* mutex);
extern "C" void OSSendMessage(void* queue, void* msg, s32 flags);

extern void* lbl_8053ADF0;
extern void* lbl_804B0FD0[];
extern void* lbl_804B0FA0[];
extern u8 lbl_8053A218;
extern u8 lbl_80529CA0[];

extern "C" void* fn_804019A8(void* p1, u8 p2, void* p3) {
    char* node;
    s32 result = DVDConvertPathToEntrynum(p1);
    if (result == -1) {
        node = 0;
    } else {
        node = alloc__7JKRHeapFUliP7JKRHeap(0x20, -4, lbl_8053ADF0);
        if (node != 0) {
            *(void**)(node + 0x8) = lbl_804B0FD0;
            *(u8*)(node + 0x4) = 0;
            *(s32*)(node + 0x0) = 0;
            *(void**)(node + 0x8) = lbl_804B0FA0;
            *(u8*)(node + 0xc) = p2;
            if (p2 == 0) {
                *(u8*)(node + 0xc) = lbl_8053A218;
            }
        }

        if (node != 0) {
            *(s32*)(node + 0x10) = result;
            void* mutex = lbl_80529CA0 + 0x24;
            *(void**)(node + 0x1c) = p3;
            OSLockMutex(mutex);

            *(s32*)(node + 0x0) = 0;
            void* tail = *(void**)(lbl_80529CA0 + 0x40);
            if (tail == 0) {
                *(void**)(lbl_80529CA0 + 0x40) = node;
                *(void**)(lbl_80529CA0 + 0x3c) = node;
            } else {
                *(void**)tail = node;
                *(void**)(lbl_80529CA0 + 0x40) = node;
            }

            OSUnlockMutex(mutex);
            OSSendMessage(lbl_80529CA0, 0, 0);
        }
    }
    return node;
}

// ---- fn_80401AC8 ----
extern "C" void* __nw__FUlP7JKRHeapi(u32 size, void* heap, s32 align);
extern "C" void* fn_80079EFC(void* obj);
extern "C" BOOL fn_8007A198(void* obj, s32 entryNum, T18AllocDir dir);

extern "C" u8 fn_80401AC8(char* this_) {
    void* heap = *(void**)(this_ + 0x18) != NULL ? *(void**)(this_ + 0x18) : lbl_8053ADF4;
    u8 ok = 0;
    if (*(void**)(this_ + 0x14) == NULL) {
        if (*(u8*)(this_ + 0xc) == 1) {
            void* o = __nw__FUlP7JKRHeapi(0x6c, heap, 0x20);
            if (o != NULL) {
                o = fn_80079EFC(o);
            }
            *(void**)(this_ + 0x14) = o;
        } else {
            void* o = __nw__FUlP7JKRHeapi(0x6c, heap, -0x20);
            if (o != NULL) {
                o = fn_80079EFC(o);
            }
            *(void**)(this_ + 0x14) = o;
        }
    }
    if (*(void**)(this_ + 0x14) != NULL) {
        ok = fn_8007A198(*(void**)(this_ + 0x14), *(s32*)(this_ + 0x10),
                         *(u8*)(this_ + 0xc) == 1 ? T18_ALLOC_FORWARD : T18_ALLOC_BACKWARD);
    }
    *(u8*)(this_ + 0x4) = 1;
    return ok;
}

// ---- from src/Game/EffectQueueEnqueue_80401BA4.cpp ----
extern "C" s32 DVDConvertPathToEntrynum(void* arg1);
extern "C" char* alloc__7JKRHeapFUliP7JKRHeap(s32 size, s32 align, void* heap);
extern "C" void OSLockMutex(void* mutex);
extern "C" void OSUnlockMutex(void* mutex);
extern "C" void OSSendMessage(void* queue, void* msg, s32 flags);

extern void* lbl_8053ADF0;
extern void* lbl_804B0FD0[];
extern void* lbl_804B0FB0[];
extern u8 lbl_8053A218;
extern u8 lbl_80529CA0[];

extern "C" void* fn_80401BA4(void* p1, void* p2, u8 p3, void* p4) {
    char* node;
    s32 result = DVDConvertPathToEntrynum(p1);
    if (result == -1) {
        node = 0;
    } else {
        node = alloc__7JKRHeapFUliP7JKRHeap(0x1c, -4, lbl_8053ADF0);
        if (node != 0) {
            *(void**)(node + 0x8) = lbl_804B0FD0;
            *(u8*)(node + 0x4) = 0;
            *(s32*)(node + 0x0) = 0;
            *(void**)(node + 0x8) = lbl_804B0FB0;
            *(u8*)(node + 0xc) = p3;
            *(s32*)(node + 0x10) = -1;
            *(void**)(node + 0x14) = p2;
            *(s32*)(node + 0x18) = 0;
            if (p3 == 0) {
                *(u8*)(node + 0xc) = lbl_8053A218;
            }
        }

        if (node != 0) {
            *(s32*)(node + 0x10) = result;
            void* mutex = lbl_80529CA0 + 0x24;
            *(void**)(node + 0x18) = p4;
            OSLockMutex(mutex);

            *(s32*)(node + 0x0) = 0;
            void* tail = *(void**)(lbl_80529CA0 + 0x40);
            if (tail == 0) {
                *(void**)(lbl_80529CA0 + 0x40) = node;
                *(void**)(lbl_80529CA0 + 0x3c) = node;
            } else {
                *(void**)tail = node;
                *(void**)(lbl_80529CA0 + 0x40) = node;
            }

            OSUnlockMutex(mutex);
            OSSendMessage(lbl_80529CA0, 0, 0);
        }
    }
    return node;
}

// ---- from src/Game/fn_80401CC0.cpp ----
extern void* lbl_804B0FB0[];
extern void* lbl_804B0FD0[];

extern "C" void free__7JKRHeapFPvP7JKRHeap(void* this_, s16 flag);

// fn_80401CC0 - destructor for lbl_804B0FB0, with the base destructor
// INLINED (same shape as fn_80401890): installs its OWN vtable, then
// the base's vtable (lbl_804B0FD0), then runs the shared cleanup step.
extern "C" void* fn_80401CC0(void* this_, s16 arg) {
    if (this_ != 0) {
        *(void**)((char*)this_ + 0x8) = lbl_804B0FB0;
        if (this_ != 0) {
            *(void**)((char*)this_ + 0x8) = lbl_804B0FD0;
        }
        if (arg > 0) {
            free__7JKRHeapFPvP7JKRHeap(this_, 0);
        }
    }
    return this_;
}

// ---- fn_80401D20 ----
struct T18Archive {
    virtual ~T18Archive();
    u8 pad[0x2c];
    u8 mIsMounted; // 0x30
};
extern "C" T18Archive* __ct__13JKRMemArchiveFlQ210JKRArchive15EMountDirection(void* obj, s32 entryNum, s32 dir);

extern "C" BOOL fn_80401D20(char* this_) {
    void* heap = *(void**)(this_ + 0x18) != NULL ? *(void**)(this_ + 0x18) : lbl_8053ADF4;
    T18Archive* arc;
    if (*(u8*)(this_ + 0xc) == 1) {
        void* o = __nw__FUlP7JKRHeapi(0x70, heap, 0);
        if (o != NULL) {
            o = __ct__13JKRMemArchiveFlQ210JKRArchive15EMountDirection(o, *(s32*)(this_ + 0x10), 1);
        }
        arc = (T18Archive*)o;
    } else {
        void* o = __nw__FUlP7JKRHeapi(0x70, heap, -4);
        if (o != NULL) {
            o = __ct__13JKRMemArchiveFlQ210JKRArchive15EMountDirection(o, *(s32*)(this_ + 0x10), 2);
        }
        arc = (T18Archive*)o;
    }
    if (arc != NULL && arc->mIsMounted) {
        *(T18Archive**)(this_ + 0x14) = arc;
    } else if (arc != NULL) {
        delete arc;
    }
    *(u8*)(this_ + 0x4) = 1;
    return *(void**)(this_ + 0x14) != NULL;
}

// ---- from src/Game/EffectQueueEnqueue2_80401E10.cpp ----
extern "C" s32 DVDConvertPathToEntrynum(void* arg1);
extern "C" char* alloc__7JKRHeapFUliP7JKRHeap(s32 size, s32 align, void* heap);
extern "C" void OSLockMutex(void* mutex);
extern "C" void OSUnlockMutex(void* mutex);
extern "C" void OSSendMessage(void* queue, void* msg, s32 flags);

extern void* lbl_8053ADF0;
extern void* lbl_804B0FD0[];
extern void* lbl_804B0FC0[];
extern u8 lbl_8053A218;
extern u8 lbl_80529CA0[];

extern "C" void* fn_80401E10(void* p1, u8 p2, void* p3) {
    char* node;
    s32 result = DVDConvertPathToEntrynum(p1);
    if (result == -1) {
        node = 0;
    } else {
        node = alloc__7JKRHeapFUliP7JKRHeap(0x1c, -4, lbl_8053ADF0);
        if (node != 0) {
            *(void**)(node + 0x8) = lbl_804B0FD0;
            *(u8*)(node + 0x4) = 0;
            *(s32*)(node + 0x0) = 0;
            *(void**)(node + 0x8) = lbl_804B0FC0;
            *(u8*)(node + 0xc) = p2;
            *(s32*)(node + 0x10) = -1;
            *(s32*)(node + 0x14) = 0;
            *(s32*)(node + 0x18) = 0;
            if (p2 == 0) {
                *(u8*)(node + 0xc) = lbl_8053A218;
            }
        }

        if (node != 0) {
            *(s32*)(node + 0x10) = result;
            void* mutex = lbl_80529CA0 + 0x24;
            *(void**)(node + 0x18) = p3;
            OSLockMutex(mutex);

            *(s32*)(node + 0x0) = 0;
            void* tail = *(void**)(lbl_80529CA0 + 0x40);
            if (tail == 0) {
                *(void**)(lbl_80529CA0 + 0x40) = node;
                *(void**)(lbl_80529CA0 + 0x3c) = node;
            } else {
                *(void**)tail = node;
                *(void**)(lbl_80529CA0 + 0x40) = node;
            }

            OSUnlockMutex(mutex);
            OSSendMessage(lbl_80529CA0, 0, 0);
        }
    }
    return node;
}

// ---- from src/Game/fn_80401F40.cpp ----
extern void* lbl_804B0FC0[];
extern void* lbl_804B0FD0[];

extern "C" void free__7JKRHeapFPvP7JKRHeap(void* this_, s16 flag);

// fn_80401F40 - destructor for lbl_804B0FC0, with the base destructor
// INLINED (same shape as fn_80401890/fn_80401CC0): installs its OWN
// vtable, then the base's vtable (lbl_804B0FD0), then runs the shared
// cleanup step.
extern "C" void* fn_80401F40(void* this_, s16 arg) {
    if (this_ != 0) {
        *(void**)((char*)this_ + 0x8) = lbl_804B0FC0;
        if (this_ != 0) {
            *(void**)((char*)this_ + 0x8) = lbl_804B0FD0;
        }
        if (arg > 0) {
            free__7JKRHeapFPvP7JKRHeap(this_, 0);
        }
    }
    return this_;
}

// ---- from src/Game/fn_80401FA0.cpp ----
extern void* lbl_804B0FD0[];

extern "C" void free__7JKRHeapFPvP7JKRHeap(void* this_, s16 flag);

// fn_80401FA0 - destructor for lbl_804B0FD0. Standard "if (this)"
// guard; installs the vtable at this->0x8, then if the incoming s16
// arg is > 0, calls free__7JKRHeapFPvP7JKRHeap(this, 0).
extern "C" void* fn_80401FA0(void* this_, s16 arg) {
    if (this_ != 0) {
        *(void**)((char*)this_ + 0x8) = lbl_804B0FD0;
        if (arg > 0) {
            free__7JKRHeapFPvP7JKRHeap(this_, 0);
        }
    }
    return this_;
}

