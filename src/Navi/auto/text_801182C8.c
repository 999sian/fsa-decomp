// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801182c8-0x80118310 (1 functions). split_file divides it into the game's real files.
extern "C" {
extern unsigned char lbl_802C5F84[];
extern unsigned char lbl_802C5F78[];
void fn_80166BD0(void*, int);
void fn_80118310(void);
void __register_global_object(void*, void*, void*);
}

extern "C" void fn_801182C8(void) {
    fn_80166BD0(lbl_802C5F84, 0);
    __register_global_object(lbl_802C5F84, (void*)fn_80118310, lbl_802C5F78);
}
