// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80077d64-0x80077da0 (1 functions). split_file divides it into the game's real files.

extern char lbl_802C4E74[];
extern char lbl_802C4E68[];
extern "C" void* fn_80075694(void* p);
extern "C" void fn_80077D04(void* p);
extern "C" void __register_global_object(void* object, void* destructor, void* regmem);
extern "C" void fn_80077D64(void)
{
	__register_global_object(fn_80075694(lbl_802C4E74), (void*)fn_80077D04, lbl_802C4E68);
}
