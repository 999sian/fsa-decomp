// TU 0x80401848-0x804023d0 — DVD / JKRArchive Asynchronous Loader Queue & Thread.
#include "types.h"
#include "dolphin/os.h"
#include "JSystem/JKernel/JKRThread.h"

extern "C" void __dl__FPv(void* this_);
extern void* lbl_804B0F90[];
extern void* lbl_804B0FA0[];
extern void* lbl_804B0FB0[];
extern void* lbl_804B0FC0[];
extern void* lbl_804B0FD0[];
extern "C" void free__7JKRHeapFPvP7JKRHeap(void* this_, s16 flag);

enum T18AllocDir {
    T18_ALLOC_FORWARD  = 1,
    T18_ALLOC_BACKWARD = 2,
};

struct LoaderNode {
    /* 0x00 */ LoaderNode* mNext;
    /* 0x04 */ u8 mDone;
    /* 0x08 */ virtual ~LoaderNode();
    /* 0x0C */ virtual void execute();
};

// Node for raw DVD-to-RAM rip (vtable lbl_804B0FA0, size 0x20)
struct DvdRipLoaderNode {
    /* 0x00 */ DvdRipLoaderNode* mNext;
    /* 0x04 */ u8 mDone;
    /* 0x08 */ void* mVtable;
    /* 0x0C */ u8 mAllocDir;
    /* 0x10 */ s32 mEntryNum;
    /* 0x14 */ void* mBuffer;
    /* 0x18 */ s32 mBufferSize;
    /* 0x1C */ void* mHeap;
};

// Node for archive/custom object mount (vtable lbl_804B0FB0 / lbl_804B0FC0, size 0x1C)
struct ArchiveLoaderNode {
    /* 0x00 */ ArchiveLoaderNode* mNext;
    /* 0x04 */ u8 mDone;
    /* 0x08 */ void* mVtable;
    /* 0x0C */ u8 mAllocDir;
    /* 0x10 */ s32 mEntryNum;
    /* 0x14 */ void* mArchive;
    /* 0x18 */ void* mHeap;
};

struct RawLoaderQueue {
    /* 0x00 */ u8 mMsgQueueBytes[0x24];
    /* 0x24 */ OSMutex mMutex;
    /* 0x3C */ void* mHead;
    /* 0x40 */ void* mTail;
};

extern "C" void* fn_80401848(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804B0F90;
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void* fn_80401890(DvdRipLoaderNode* this_, s16 arg) {
    if (this_ != 0) {
        this_->mVtable = lbl_804B0FA0;
        if (this_ != 0) {
            this_->mVtable = lbl_804B0FD0;
        }
        if (arg > 0) {
            free__7JKRHeapFPvP7JKRHeap(this_, 0);
        }
    }
    return this_;
}

extern "C" void* loadToMainRAM__12JKRDvdRipperFlPUc15JKRExpandSwitchUlP7JKRHeapQ212JKRDvdRipper15EAllocDirectionUlPiPUl(
    s32 entryNum, u8* dst, s32 expand, u32 size, void* heap, T18AllocDir dir, u32 offset, int* comp, u32* outSize);
extern "C" s32 getSize__7JKRHeapFPv(void* heap, void* ptr);
extern void* lbl_8053ADF4;

extern "C" BOOL fn_804018F0(DvdRipLoaderNode* this_) {
    void* h = this_->mHeap;
    void* heap;
    if (h != NULL) {
        heap = h;
    } else {
        heap = lbl_8053ADF4;
    }
    this_->mBuffer = loadToMainRAM__12JKRDvdRipperFlPUc15JKRExpandSwitchUlP7JKRHeapQ212JKRDvdRipper15EAllocDirectionUlPiPUl(
        this_->mEntryNum, NULL, 1, 0, heap,
        this_->mAllocDir == 1 ? T18_ALLOC_FORWARD : T18_ALLOC_BACKWARD, 0, NULL, NULL);
    if (this_->mBuffer != NULL) {
        this_->mBufferSize = getSize__7JKRHeapFPv(heap, this_->mBuffer);
    }
    this_->mDone = 1;
    return this_->mBuffer != NULL;
}

extern "C" s32 DVDConvertPathToEntrynum(void* arg1);
extern "C" DvdRipLoaderNode* alloc__7JKRHeapFUliP7JKRHeap(s32 size, s32 align, void* heap);

extern void* lbl_8053ADF0;
extern u8 lbl_8053A218;
extern RawLoaderQueue lbl_80529CA0;

extern "C" void* fn_804019A8(void* path, u8 allocDir, void* heap) {
    DvdRipLoaderNode* node;
    s32 entryNum = DVDConvertPathToEntrynum(path);
    if (entryNum == -1) {
        node = 0;
    } else {
        node = alloc__7JKRHeapFUliP7JKRHeap(sizeof(DvdRipLoaderNode), -4, lbl_8053ADF0);
        if (node != 0) {
            node->mVtable = lbl_804B0FD0;
            node->mDone = 0;
            node->mNext = 0;
            node->mVtable = lbl_804B0FA0;
            node->mAllocDir = allocDir;
            if (allocDir == 0) {
                node->mAllocDir = lbl_8053A218;
            }
        }

        if (node != 0) {
            node->mEntryNum = entryNum;
            OSMutex* mutex = &lbl_80529CA0.mMutex;
            node->mHeap = heap;
            OSLockMutex(mutex);

            node->mNext = 0;
            void* tail = lbl_80529CA0.mTail;
            if (tail == 0) {
                lbl_80529CA0.mTail = node;
                lbl_80529CA0.mHead = node;
            } else {
                *(void**)tail = node;
                lbl_80529CA0.mTail = node;
            }

            OSUnlockMutex(mutex);
            OSSendMessage((OSMessageQueue*)&lbl_80529CA0, 0, 0);
        }
    }
    return node;
}

extern "C" void* __nw__FUlP7JKRHeapi(u32 size, void* heap, s32 align);
extern "C" void* fn_80079EFC(void* obj);
extern "C" BOOL fn_8007A198(void* obj, s32 entryNum, T18AllocDir dir);

extern "C" u8 fn_80401AC8(ArchiveLoaderNode* this_) {
    void* heap = this_->mHeap != NULL ? this_->mHeap : lbl_8053ADF4;
    u8 ok = 0;
    if (this_->mArchive == NULL) {
        if (this_->mAllocDir == 1) {
            void* o = __nw__FUlP7JKRHeapi(0x6c, heap, 0x20);
            if (o != NULL) {
                o = fn_80079EFC(o);
            }
            this_->mArchive = o;
        } else {
            void* o = __nw__FUlP7JKRHeapi(0x6c, heap, -0x20);
            if (o != NULL) {
                o = fn_80079EFC(o);
            }
            this_->mArchive = o;
        }
    }
    if (this_->mArchive != NULL) {
        ok = fn_8007A198(this_->mArchive, this_->mEntryNum,
                         this_->mAllocDir == 1 ? T18_ALLOC_FORWARD : T18_ALLOC_BACKWARD);
    }
    this_->mDone = 1;
    return ok;
}

extern "C" void* fn_80401BA4(void* path, void* archive, u8 allocDir, void* heap) {
    ArchiveLoaderNode* node;
    s32 entryNum = DVDConvertPathToEntrynum(path);
    if (entryNum == -1) {
        node = 0;
    } else {
        node = (ArchiveLoaderNode*)alloc__7JKRHeapFUliP7JKRHeap(sizeof(ArchiveLoaderNode), -4, lbl_8053ADF0);
        if (node != 0) {
            node->mVtable = lbl_804B0FD0;
            node->mDone = 0;
            node->mNext = 0;
            node->mVtable = lbl_804B0FB0;
            node->mAllocDir = allocDir;
            node->mEntryNum = -1;
            node->mArchive = archive;
            node->mHeap = 0;
            if (allocDir == 0) {
                node->mAllocDir = lbl_8053A218;
            }
        }

        if (node != 0) {
            node->mEntryNum = entryNum;
            OSMutex* mutex = &lbl_80529CA0.mMutex;
            node->mHeap = heap;
            OSLockMutex(mutex);

            node->mNext = 0;
            void* tail = lbl_80529CA0.mTail;
            if (tail == 0) {
                lbl_80529CA0.mTail = node;
                lbl_80529CA0.mHead = node;
            } else {
                *(void**)tail = node;
                lbl_80529CA0.mTail = node;
            }

            OSUnlockMutex(mutex);
            OSSendMessage((OSMessageQueue*)&lbl_80529CA0, 0, 0);
        }
    }
    return node;
}

extern "C" void* fn_80401CC0(ArchiveLoaderNode* this_, s16 arg) {
    if (this_ != 0) {
        this_->mVtable = lbl_804B0FB0;
        if (this_ != 0) {
            this_->mVtable = lbl_804B0FD0;
        }
        if (arg > 0) {
            free__7JKRHeapFPvP7JKRHeap(this_, 0);
        }
    }
    return this_;
}

struct T18Archive {
    virtual ~T18Archive();
    u8 pad[0x2c];
    u8 mIsMounted; // 0x30
};
extern "C" T18Archive* __ct__13JKRMemArchiveFlQ210JKRArchive15EMountDirection(void* obj, s32 entryNum, s32 dir);

extern "C" BOOL fn_80401D20(ArchiveLoaderNode* this_) {
    void* heap = this_->mHeap != NULL ? this_->mHeap : lbl_8053ADF4;
    T18Archive* arc;
    if (this_->mAllocDir == 1) {
        void* o = __nw__FUlP7JKRHeapi(0x70, heap, 0);
        if (o != NULL) {
            o = __ct__13JKRMemArchiveFlQ210JKRArchive15EMountDirection(o, this_->mEntryNum, 1);
        }
        arc = (T18Archive*)o;
    } else {
        void* o = __nw__FUlP7JKRHeapi(0x70, heap, -4);
        if (o != NULL) {
            o = __ct__13JKRMemArchiveFlQ210JKRArchive15EMountDirection(o, this_->mEntryNum, 2);
        }
        arc = (T18Archive*)o;
    }
    if (arc != NULL && arc->mIsMounted) {
        this_->mArchive = arc;
    } else if (arc != NULL) {
        delete arc;
    }
    this_->mDone = 1;
    return this_->mArchive != NULL;
}

extern "C" void* fn_80401E10(void* path, u8 allocDir, void* heap) {
    ArchiveLoaderNode* node;
    s32 entryNum = DVDConvertPathToEntrynum(path);
    if (entryNum == -1) {
        node = 0;
    } else {
        node = (ArchiveLoaderNode*)alloc__7JKRHeapFUliP7JKRHeap(sizeof(ArchiveLoaderNode), -4, lbl_8053ADF0);
        if (node != 0) {
            node->mVtable = lbl_804B0FD0;
            node->mDone = 0;
            node->mNext = 0;
            node->mVtable = lbl_804B0FC0;
            node->mAllocDir = allocDir;
            node->mEntryNum = -1;
            node->mArchive = 0;
            node->mHeap = 0;
            if (allocDir == 0) {
                node->mAllocDir = lbl_8053A218;
            }
        }

        if (node != 0) {
            node->mEntryNum = entryNum;
            OSMutex* mutex = &lbl_80529CA0.mMutex;
            node->mHeap = heap;
            OSLockMutex(mutex);

            node->mNext = 0;
            void* tail = lbl_80529CA0.mTail;
            if (tail == 0) {
                lbl_80529CA0.mTail = node;
                lbl_80529CA0.mHead = node;
            } else {
                *(void**)tail = node;
                lbl_80529CA0.mTail = node;
            }

            OSUnlockMutex(mutex);
            OSSendMessage((OSMessageQueue*)&lbl_80529CA0, 0, 0);
        }
    }
    return node;
}

extern "C" void* fn_80401F40(ArchiveLoaderNode* this_, s16 arg) {
    if (this_ != 0) {
        this_->mVtable = lbl_804B0FC0;
        if (this_ != 0) {
            this_->mVtable = lbl_804B0FD0;
        }
        if (arg > 0) {
            free__7JKRHeapFPvP7JKRHeap(this_, 0);
        }
    }
    return this_;
}

extern "C" void* fn_80401FA0(ArchiveLoaderNode* this_, s16 arg) {
    if (this_ != 0) {
        this_->mVtable = lbl_804B0FD0;
        if (arg > 0) {
            free__7JKRHeapFPvP7JKRHeap(this_, 0);
        }
    }
    return this_;
}

struct LoaderQueue {
    LoaderQueue() {
        OSInitMessageQueue(&mQueue, &mMsg, 1);
        OSInitMutex(&mMutex);
        mHead = NULL;
        mTail = NULL;
    }
    OSMessageQueue mQueue;
    OSMessage mMsg;
    OSMutex mMutex;
    LoaderNode* mHead;
    LoaderNode* mTail;
};

static OSThread sLoaderThread;
static u8 sLoaderStack[0x1000] __attribute__((aligned(32)));
static LoaderQueue sLoaderQueue;

extern "C" void* fn_80402054(void* param);

static inline void loaderRemove(LoaderQueue* q, LoaderNode* node) {
    OSLockMutex(&q->mMutex);
    LoaderNode* prev = NULL;
    LoaderNode* cur = q->mHead;
    while (cur != NULL) {
        if (cur == node) {
            if (prev != NULL) {
                prev->mNext = cur->mNext;
                if (q->mTail == cur) {
                    q->mTail = prev;
                }
            } else if (q->mHead == q->mTail) {
                q->mHead = NULL;
                q->mTail = NULL;
            } else {
                q->mHead = cur->mNext;
            }
        }
        prev = cur;
        cur = cur->mNext;
    }
    OSUnlockMutex(&q->mMutex);
}

extern "C" void fn_80401FEC(OSPriority prio, void* heap, void* heap2) {
    lbl_8053ADF4 = heap2;
    lbl_8053ADF0 = heap;
    OSCreateThread(&sLoaderThread, fn_80402054, &sLoaderQueue, sLoaderStack + sizeof(sLoaderStack), sizeof(sLoaderStack), prio, 1);
    OSResumeThread(&sLoaderThread);
}

extern "C" void* fn_80402054(void* param) {
    LoaderNode* volatile node;
    LoaderQueue* q = (LoaderQueue*)param;
    JKRThread(OSGetCurrentThread(), 0);
    while (OSReceiveMessage(&q->mQueue, NULL, OS_MESSAGE_BLOCK)) {
        LoaderNode* n;
        while ((n = node = q->mHead) != NULL) {
            loaderRemove(q, n);
            OSSendMessage(&q->mQueue, NULL, OS_MESSAGE_NOBLOCK);
            node->execute();
        }
    }
    return NULL;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
