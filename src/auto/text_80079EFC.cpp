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
    static void* alloc(u32, int, JKRHeap*);
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
    static u32 fetchResource_subroutine(u32, u32, JKRHeap*, int, u8**);
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

extern "C" void free__7JKRHeapFPvP7JKRHeap(void* ptr, void* heap);
extern "C" void remove__10JSUPtrListFP10JSUPtrLink(char* list, u8* link);
extern "C" void __dt__10JKRArchiveFv(void* this_, s32 deleteFlag);
extern "C" void __dl__FPv(void* ptr);
extern "C" void* fn_80079FE8(void* this_, s16 deleteFlag) {
    extern char sVolumeList__13JKRFileLoader[];
    u8* self = (u8*)this_;
    if (self != nullptr) {
        *(void**)self = lbl_80498BB0;
        if (*(u8*)(self + 0x30) == 1) {
            if (*(u8**)(self + 0x44) != nullptr) {
                u8* fileEntry = *(u8**)(self + 0x4c);
                for (u32 i = 0; i < *(u32*)(*(u8**)(self + 0x44) + 0x8); i++) {
                    if (*(void**)(fileEntry + 0x10) != nullptr) {
                        free__7JKRHeapFPvP7JKRHeap(*(void**)(fileEntry + 0x10), *(void**)(self + 0x38));
                    }
                    fileEntry += 0x14;
                }
                free__7JKRHeapFPvP7JKRHeap(*(void**)(self + 0x44), *(void**)(self + 0x38));
                *(void**)(self + 0x44) = nullptr;
            }
            if (*(void**)(self + 0x50) != nullptr) {
                free__7JKRHeapFPvP7JKRHeap(*(void**)(self + 0x50), nullptr);
                *(void**)(self + 0x50) = nullptr;
            }
            if (*(JKRFile**)(self + 0x68) != nullptr) {
                delete *(JKRFile**)(self + 0x68);
            }
            if (*(JKRFile**)(self + 0x64) != nullptr) {
                delete *(JKRFile**)(self + 0x64);
            }
            remove__10JSUPtrListFP10JSUPtrLink(sVolumeList__13JKRFileLoader, self + 0x18);
            *(u8*)(self + 0x30) = 0;
        }
        __dt__10JKRArchiveFv(this_, 0);
        if (deleteFlag > 0) {
            __dl__FPv(this_);
        }
    }
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

extern "C" void* fn_8007A6CC(u8* this_, u8* entry, u32* pSize) {
    u32 sizeptr;
    u8* data;
    if (pSize == nullptr) {
        pSize = &sizeptr;
    }
    u32 flag = *(u32*)(entry + 0x4);
    int compression;
    if ((flag >> 24 & 4) == 0) {
        compression = 0;
    } else if (flag >> 24 & 0x80) {
        compression = 2;
    } else {
        compression = 1;
    }

    if (*(void**)(entry + 0x10) == nullptr) {
        u8* block = *(u8**)(this_ + 0x64);
        u32 size = JKRAramArchive::fetchResource_subroutine(*(u32*)(entry + 0x8) + *(u32*)(block + 0x14), *(u32*)(entry + 0xc), *(JKRHeap**)(this_ + 0x38), compression, &data);
        *pSize = size;
        if (size == 0) {
            return nullptr;
        }
        *(void**)(entry + 0x10) = data;
        if (compression == 2) {
            ((void (*)(void*, void*, u32))(*(void***)this_)[0x48 / 4])(this_, entry, *pSize);
        }
    } else if (compression == 2) {
        *pSize = ((u32 (*)(void*, void*))(*(void***)this_)[0x4c / 4])(this_, entry);
    } else {
        *pSize = *(u32*)(entry + 0xc);
    }
    return *(void**)(entry + 0x10);
}

extern "C" void* fn_8007A7F0(void* this_, void* data, u32 compressedSize, void* entry, u32* pSize) {
    u8* fileEntry = (u8*)entry;
    u32 fileSize = *(u32*)(fileEntry + 0xc);
    if (fileSize > compressedSize) {
        fileSize = compressedSize;
    }

    u32 flag = *(u32*)(fileEntry + 0x4);
    int compression;
    if ((flag >> 24 & 4) == 0) {
        compression = 0;
    } else if (flag >> 24 & 0x80) {
        compression = 2;
    } else {
        compression = 1;
    }

    if (*(void**)(fileEntry + 0x10) == nullptr) {
        u8* block = *(u8**)((u8*)this_ + 0x64);
        fileSize = JKRAramArchive::fetchResource_subroutine(*(u32*)(fileEntry + 0x8) + *(u32*)(block + 0x14), fileSize, (u8*)data, compressedSize & ~0x1f, compression);
    } else {
        if (compression == 2) {
            u32 expandSize = ((u32 (*)(void*, void*))(*(void***)this_)[0x4c / 4])(this_, entry);
            if (expandSize != 0) {
                fileSize = expandSize;
            }
        }
        if (fileSize > compressedSize) {
            fileSize = compressedSize;
        }
        JKRHeap::copyMemory(data, *(void**)(fileEntry + 0x10), fileSize);
    }

    if (pSize != nullptr) {
        *pSize = fileSize;
    }
    return data;
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

extern "C" void* findPtrResource__10JKRArchiveCFPCv(void* this_, const void* resource);
extern "C" u32 fn_8007AAF8(void* this_, const void* resource) {
    u8* self = (u8*)this_;
    if (*(u32*)(self + 0x50) == 0) {
        return ((u32 (*)(void*, const void*))(*(void***)this_)[0x30 / 4])(this_, resource);
    }
    u8* fileEntry = (u8*)findPtrResource__10JKRArchiveCFPCv(this_, resource);
    if (fileEntry == nullptr) {
        return 0xffffffff;
    }
    if ((*(u32*)(fileEntry + 0x4) >> 24 & 4) == 0) {
        return ((u32 (*)(void*, const void*))(*(void***)this_)[0x30 / 4])(this_, resource);
    }
    u32 expandSize = ((u32 (*)(void*, void*))(*(void***)this_)[0x4c / 4])(this_, fileEntry);
    if (expandSize != 0) {
        return expandSize;
    }
    u8 buf[64];
    u8* bufPtr = (u8*)(((u32)buf + 31) & ~31);
    u8* block = *(u8**)(self + 0x64);
    JKRAram::aramToMainRam(*(u32*)(fileEntry + 0x8) + *(u32*)(block + 0x14), bufPtr, 0x20, EXPAND_SWITCH_DEFAULT, 0, nullptr, -1, nullptr);
    expandSize = (bufPtr[4] << 24) | (bufPtr[5] << 16) | (bufPtr[6] << 8) | bufPtr[7];
    ((void (*)(void*, void*, u32))(*(void***)this_)[0x48 / 4])(this_, fileEntry, expandSize);
    return expandSize;
}

