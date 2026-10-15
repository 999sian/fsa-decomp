// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

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
