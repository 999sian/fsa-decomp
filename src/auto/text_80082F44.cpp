#include "JSystem/JKernel/JKRFileFinder.h"
#include "JSystem/JKernel/JKRArchive.h"
extern char lbl_80498E38[];
extern char lbl_80498E48[];
JKRArcFinder::JKRArcFinder(JKRArchive *archive, long startindex, long entries) : JKRFileFinder()
{
    mArchive = archive;

    mIsAvailable = entries > 0;
    mStartIndex = startindex;
    mEndIndex = startindex + entries - 1;
    mNextIndex = mStartIndex;

    findNextFile();
}

bool fn_80083018(void* param_1) {
    JKRArchive::SDirEntry entry;
    char* self = (char*)param_1;
    if (*(u8*)(self + 0x10) != 0) {
        *(u8*)(self + 0x10) = *(s32*)(self + 0x1c) >= *(s32*)(self + 0x20);
        if (*(u8*)(self + 0x10) != 0) {
            *(u8*)(self + 0x10) = ((JKRArchive*)*(void**)(self + 0x14))->getDirEntry(&entry, *(u32*)(self + 0x20));
            *(char**)(self + 0x0) = entry.mName;
            *(u32*)(self + 0x4) = *(u32*)(self + 0x20);
            *(u16*)(self + 0x8) = entry.mID;
            *(u16*)(self + 0xa) = entry.mFlags;
            *(u8*)(self + 0x11) = (*(u16*)(self + 0xa) >> 1) & 1;
            *(u32*)(self + 0x20) += 1;
        }
    }
    return *(u8*)(self + 0x10);
}

void* fn_800830C4(void* param_1, s16 param_2) {
    if (param_1 != NULL) {
        *(char**)((char*)param_1 + 0xc) = lbl_80498E48;
        if (param_1 != NULL) {
            *(char**)((char*)param_1 + 0xc) = lbl_80498E38;
        }
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

