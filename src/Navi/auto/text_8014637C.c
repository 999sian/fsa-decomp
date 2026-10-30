// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8014637c-0x80146464 (1 functions). split_file divides it into the game's real files.

extern "C" int fn_8014637C(int param_1, int param_2, int param_3)
{
	extern unsigned char* lbl_802FF3E0;
	extern unsigned int fn_8014DDC0(void);
	extern void fn_80155784(int, unsigned int, unsigned char, int);
	int result = 0;
	unsigned int id = fn_8014DDC0();
	while (id != 0xffffffff) {
		unsigned int idx = id & 0xff;
		unsigned int off = idx * 0x404 + 0xf4;
		if (id == *(unsigned int*)(lbl_802FF3E0 + off)) {
			unsigned char* e = lbl_802FF3E0 + idx * 0x404;
			if (*(unsigned long long*)(e + 0x114) & 2) {
				fn_80155784(param_2, idx, e[0x20b], param_3);
			} else {
				fn_80155784(param_2, idx, e[0x122], param_3);
			}
			result = 1;
			id = *(unsigned int*)(lbl_802FF3E0 + (idx * 0x404 + 0xec));
		} else {
			return result;
		}
	}
	return result;
}
