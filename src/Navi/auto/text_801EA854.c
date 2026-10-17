// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801ea854-0x801eb0d4 (15 functions). split_file divides it into the game's real files.

extern "C" unsigned char lbl_802F8A48;
extern "C" void TRKAcquireMutex(void* param_1);
extern "C" void TRKReleaseMutex(void* param_1);
extern "C" void fn_80003590(void* param_1, int param_2, unsigned int param_3);
extern "C" void fn_801EAEC8(void* param_1, int param_2) {
    *(int*)((unsigned char*)param_1 + 8) = 0;
    *(int*)((unsigned char*)param_1 + 0xc) = 0;
    if (param_2 == 0) {
        fn_80003590((unsigned char*)param_1 + 0x10, 0, 0x880);
    }
}

extern "C" void TRKReleaseBuffer(int param_1) {
    if (param_1 != -1 && param_1 >= 0 && param_1 < 3) {
        unsigned char* buf = &lbl_802F8A48 + param_1 * 0x890;
        TRKAcquireMutex(buf);
        *(int*)(buf + 4) = 0;
        TRKReleaseMutex(buf);
    }
}
