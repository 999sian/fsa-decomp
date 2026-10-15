// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#pragma exceptions off

extern "C" void __dt__10JSUPtrListFv(void *, int);
void operator delete(void *);
extern "C" void *fn_8008E6A4(void *self, short flags) {
    if (self != 0) {
        __dt__10JSUPtrListFv(self, 0);
        if (flags > 0) {
            operator delete(self);
        }
    }
    return self;
}

extern "C" float lbl_8053B8A0;
extern "C" void fn_8008E6F8(void *param_1) {
    float f = lbl_8053B8A0;
    *(float *)param_1 = f;
    *(float *)((char *)param_1 + 4) = f;
    *(float *)((char *)param_1 + 8) = f;
    *(unsigned short *)((char *)param_1 + 0xc) = 0;
}

extern "C" void fn_8008E714(void *param_1)
{
    *(unsigned long *)((char *)param_1 + 0x0) = 0;
    *(unsigned long *)((char *)param_1 + 0x4) = 0;
    *(unsigned long *)((char *)param_1 + 0x8) = 0;
    *(unsigned long *)((char *)param_1 + 0x18) = 0;
    *(unsigned char *)((char *)param_1 + 0xc) = 0;
    *(unsigned char *)((char *)param_1 + 0xd) = 0;
    *(unsigned char *)((char *)param_1 + 0xe) = 0;
    *(unsigned char *)((char *)param_1 + 0xf) = 0;
    *(unsigned long *)((char *)param_1 + 0x1c) = 0;
    *(unsigned long *)((char *)param_1 + 0x20) = 0;
    *(unsigned long *)((char *)param_1 + 0x24) = 0;
    *(unsigned long *)((char *)param_1 + 0x28) = 0;
    *(unsigned long *)((char *)param_1 + 0x2c) = 0;
}

extern "C" void *fn_8008E750(void *self, short flags) {
    if (self != 0) {
        __dt__10JSUPtrListFv(self, 0);
        if (flags > 0) {
            operator delete(self);
        }
    }
    return self;
}

