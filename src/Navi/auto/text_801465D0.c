// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801465d0-0x8014665c (1 functions). split_file divides it into the game's real files.

extern "C" int fn_801465D0(void) {
	extern unsigned char lbl_802FF3B0;
	extern unsigned char* lbl_802FF3E0;
	extern unsigned int fn_8014DDC0(void);
	extern void fn_8014CF34(unsigned char*);
	int result = 0;
	if (lbl_802FF3B0 != 0) {
		unsigned int id;
		unsigned char idx;
		for (id = fn_8014DDC0(); id != 0xffffffff; id = *(unsigned int*)(lbl_802FF3E0 + (idx * 0x404 + 0xec))) {
			idx = id & 0xff;
			if (id == *(unsigned int*)(lbl_802FF3E0 + (idx * 0x404 + 0xf4))) {
				fn_8014CF34(lbl_802FF3E0 + idx * 0x404);
				result = 1;
			}
		}
	}
	return result;
}
