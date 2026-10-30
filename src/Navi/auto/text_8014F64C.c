// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8014f64c-0x8014f6d0 (1 functions). split_file divides it into the game's real files.

extern "C" unsigned int fn_8014F4AC(void* a, void* b, void* c);
extern "C" int fn_8014F64C(void* a, void* b, void* c) {
    unsigned char i;
    void* local[2];

    local[0] = a;
    local[1] = b;
    for (i = 0; i < 15; i++) {
        if (fn_8014F4AC(local[0], local[1], c) != 0) {
            return 1;
        }
    }
    return 0;
}
