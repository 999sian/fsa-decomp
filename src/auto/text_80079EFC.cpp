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
class JKRHeap;

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

