#include "types.h"

// Keep regional definitions that were present before source-tree consolidation.
#if defined(VERSION_G4SP01) || defined(VERSION_G4SE01)
extern "C" int fn_80113788(char* self) {
    return *(int*)(self + 0x23c);
}

#if defined(VERSION_G4SE01)
extern "C" int fn_80113E98(char* self) {
    switch (*(int*)(self + 0x23c)) {
    case 10:
    case 0x11:
        return 1;
    }
    return 0;
}
#endif

extern "C" void fn_8010DF58(char*);
extern "C" void fn_80113790(char*);
extern "C" void fn_80113B54(char*, int);
extern int lbl_80464830[];
extern "C" void fn_80114C1C(char* self) {
    fn_8010DF58(self);
    fn_80113790(self);
    switch (*(int*)(self + 0x23c)) {
    case 0x10:
        fn_80113B54(self, 0x1d6);
        break;
    default:
        if (*(unsigned char*)(self + 0x232) != 0) {
            fn_80113B54(self, lbl_80464830[*(int*)(self + 0x238)]);
        }
        break;
    }
}

#endif
