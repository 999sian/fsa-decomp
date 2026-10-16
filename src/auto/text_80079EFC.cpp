// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <JSystem/JKernel/JKRDisposer.h>

// JKRFile.h defines the virtual dtor inline; this TU has it out of line.
class JKRFile : JKRDisposer {
public:
    virtual ~JKRFile();
    bool mFileOpen;
};

#include <JSystem/JKernel/JKRCompression.h>

// Trimmed declarations: the real JKRAram.h and JUTException.h pull in JKRFile.h, which this file defines itself.
class JKRHeap {
public:
    static void copyMemory(void*, void*, u32);
};

class JKRAram {
public:
    static u32 aramToMainRam(u32, u8*, u32, JKRExpandSwitch, u32, JKRHeap*, int, u32*);
};

class JUTException {
public:
    static void panic_f(const char*, int, const char*, ...);
};

class JKRAramArchive {
public:
    static u32 fetchResource_subroutine(u32, u32, u8*, u32, int);
};

extern char lbl_8045E0F8[];
extern char lbl_8045E10C[];
extern char lbl_8053B6D0[];

extern void* lbl_80498BB0[];
extern "C" void* fn_8007BC30(void* this_);
extern "C" void* fn_80079EFC(void* this_) {
    fn_8007BC30(this_);
    *(void**)this_ = lbl_80498BB0;
    return this_;
}

JKRFile::~JKRFile() {}

extern "C" bool fn_8007A398(u8* this_, s32 entryNum);
extern "C" void* check_mount_already__10JKRArchiveFlP7JKRHeap(s32 entryNum, void* heap);
extern "C" void prepend__10JSUPtrListFP10JSUPtrLink(char* list, u8* link);
extern "C" void* sCurrentHeap__7JKRHeap;
extern "C" void* sCurrentVolume__13JKRFileLoader;
extern "C" u32 sCurrentDirID__10JKRArchive;
extern "C" char sVolumeList__13JKRFileLoader[];
extern "C" bool fn_8007A198(u8* this_, s32 entryNum, s32 mountDirection) {
    if (entryNum < 0) {
        return 0;
    }
    if (check_mount_already__10JKRArchiveFlP7JKRHeap(entryNum, sCurrentHeap__7JKRHeap) != nullptr) {
        return 0;
    }
    *(u8*)(this_ + 0x30) = 0;
    *(s32*)(this_ + 0x60) = mountDirection;
    *(u8*)(this_ + 0x3c) = 2;
    *(s32*)(this_ + 0x34) = 1;
    *(s32*)(this_ + 0x58) = 2;
    *(void**)(this_ + 0x38) = sCurrentHeap__7JKRHeap;
    *(s32*)(this_ + 0x40) = entryNum;
    if (sCurrentVolume__13JKRFileLoader == nullptr) {
        sCurrentVolume__13JKRFileLoader = this_;
        sCurrentDirID__10JKRArchive = 0;
    }
    if (!fn_8007A398(this_, entryNum)) {
        return 0;
    }
    *(u32*)(this_ + 0x2c) = 0x52415243;
    u8* dirs = *(u8**)(this_ + 0x48);
    *(char**)(this_ + 0x28) = *(char**)(this_ + 0x54) + *(u32*)(dirs + 4);
    prepend__10JSUPtrListFP10JSUPtrLink(sVolumeList__13JKRFileLoader, this_ + 0x18);
    *(u8*)(this_ + 0x30) = 1;
    return 1;
}

u32 JKRAramArchive::fetchResource_subroutine(u32 aramAddr, u32 length, u8* dst, u32 dstLength, int compression)
{
    u32 result;
    u32 size = (length + 0x1f) & ~0x1f;
    u32 alignedDstLength = dstLength & ~0x1f;

    if (compression == 0) {
        if (size > alignedDstLength) {
            size = alignedDstLength;
        }
        JKRAram::aramToMainRam(aramAddr, dst, size, EXPAND_SWITCH_DEFAULT, alignedDstLength, NULL, -1, &result);
        return result;
    }
    if (compression < 0 || compression >= 3) {
        JUTException::panic_f(lbl_8045E0F8, 0x28f, lbl_8053B6D0, lbl_8045E10C);
        return 0;
    }
    JKRAram::aramToMainRam(aramAddr, dst, size, EXPAND_SWITCH_DECOMPRESS, alignedDstLength, NULL, -1, &result);
    return result;
}

