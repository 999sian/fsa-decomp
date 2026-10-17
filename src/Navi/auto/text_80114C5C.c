// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80114c5c-0x80114ccc (2 functions). split_file divides it into the game's real files.

extern "C" int fn_80114F44(int);
extern "C" int fn_80114FE4(int);
extern "C" int fn_80114C5C(int* p)
{
    if (p[2] > 0) {
        return fn_80114F44(p[0]);
    }
    return 1;
}
