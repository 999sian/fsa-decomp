// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80157fec-0x80158020 (1 functions). split_file divides it into the game's real files.

extern "C" void fn_80153568(void* p);
extern "C" unsigned char lbl_802E3B10[];
extern "C" void fn_80157FEC(unsigned char param_1)
{
	fn_80153568(lbl_802E3B10 + (unsigned int)param_1 * 0xbc);
}
