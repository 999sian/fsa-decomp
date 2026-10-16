// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80157fb8-0x80157fec (1 functions). split_file divides it into the game's real files.

extern "C" void fn_801534C0(void* p);
extern "C" unsigned char lbl_802E3B10[];
extern "C" void fn_80157FB8(unsigned char param_1, int param_2)
{
	int off = (param_1 & 0xff) * 0xbc;
	fn_801534C0(lbl_802E3B10 + off);
}
