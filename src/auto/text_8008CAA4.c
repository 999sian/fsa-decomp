// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "JSystem/JSupport/JSUList.h"

extern JSUPtrList lbl_8052E894;
extern char lbl_804BA1C4[];
extern "C" void fn_8008CAEC(void);
extern "C" void __register_global_object(void* obj, void* dtor, void* handle);
extern "C" void __ct__10JSUPtrListFb(JSUPtrList* list, bool);
extern "C" void fn_8008CAA4(void)
{
    __ct__10JSUPtrListFb(&lbl_8052E894, false);
    __register_global_object(&lbl_8052E894, (void*)fn_8008CAEC, lbl_804BA1C4);
}
