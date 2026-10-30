// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8014b32c-0x8014b394 (1 functions). split_file divides it into the game's real files.

extern "C" unsigned short fn_80157170(unsigned char* p, unsigned int idx);
extern unsigned int lbl_802D5364[];
extern "C" short fn_8014B32C(unsigned char* p, void* mode, unsigned int idx)
{
    int v;
    if (mode != 0) {
        v = fn_80157170(p, idx);
    } else {
        idx &= 0x1f;
        if (idx < 0x10) {
            v = ((unsigned int*)(p + 0xac))[idx];
        } else {
            v = lbl_802D5364[idx - 16];
        }
    }
    return v;
}
