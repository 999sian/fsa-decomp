// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801e0d40-0x801e0db8 (1 functions). split_file divides it into the game's real files.

extern "C" void fn_801E0D40(char* param_1, void (*param_2)(char*, int), int param_3, unsigned int param_4)
{
    char* p;

    p = param_1 + param_3 * param_4;
    for (; param_4 != 0; param_4 = param_4 - 1) {
        p = p - param_3;
        (*param_2)(p, -1);
    }
}
