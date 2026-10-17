// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80012630-0x8001267c (1 functions). split_file divides it into the game's real files.

extern char lbl_802049BC[];
extern char lbl_8029FD4C[];
extern char lbl_8029FD40[];
extern "C" void fn_80118364(void*);
extern "C" void fn_8001267C(void*);
extern "C" void __register_global_object(void* object, void* destructor, void* regmem);

extern "C" void fn_80012630(void) {
    *(void**)lbl_8029FD4C = lbl_802049BC;
    fn_80118364(lbl_8029FD4C);
    __register_global_object(lbl_8029FD4C, (void*)fn_8001267C, lbl_8029FD40);
}
