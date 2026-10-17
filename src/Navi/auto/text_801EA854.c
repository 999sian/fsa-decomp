// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801ea854-0x801eb0d4 (15 functions). split_file divides it into the game's real files.

extern "C" unsigned char lbl_802F8A48[];
extern "C" void TRKAcquireMutex(void* param_1);
extern "C" void TRKReleaseMutex(void* param_1);
extern "C" void fn_80003590(void* param_1, int param_2, unsigned int param_3);
extern "C" char lbl_80202BC8[];
extern "C" int TRKWriteUARTN(const void* bytes, unsigned int length);
extern "C" void MWTRACE(unsigned char, char*, ...);
extern "C" void* TRK_memcpy(void* dst, const void* src, unsigned int n);
extern "C" int fn_801EA854(void* param_1) {
    int err = TRKWriteUARTN((unsigned char*)param_1 + 0x10, *(unsigned int*)((unsigned char*)param_1 + 8));
    MWTRACE(1, lbl_80202BC8, err);
    return 0;
}

extern "C" void fn_801EA988(void* param_1, unsigned char* param_2, int param_3) {
    int ret;
    unsigned int n;
    int i;
    int err;

    for (i = 0, err = 0; err == 0 && i < param_3; i++) {
        n = 1;
        ret = 0;
        unsigned int remaining = *(unsigned int*)((unsigned char*)param_1 + 8) - *(unsigned int*)((unsigned char*)param_1 + 0xc);
        if (n > remaining) {
            ret = 0x302;
            n = remaining;
        }
        TRK_memcpy(param_2 + i, (unsigned char*)param_1 + *(unsigned int*)((unsigned char*)param_1 + 0xc) + 0x10, n);
        *(unsigned int*)((unsigned char*)param_1 + 0xc) += n;
        err = ret;
    }
}

extern "C" int TRKAppendBuffer_ui8(void* buffer, const unsigned char* data, int count) {
    int err;
    int i;

    for (i = 0, err = 0; err == 0 && i < count; i++) {
        unsigned char ch = data[i];
        unsigned int pos = *(unsigned int*)((unsigned char*)buffer + 0xc);
        int ret;
        if (pos >= 0x880) {
            ret = 0x301;
        } else {
            *(unsigned int*)((unsigned char*)buffer + 0xc) = pos + 1;
            ((unsigned char*)buffer)[pos + 0x10] = ch;
            *(unsigned int*)((unsigned char*)buffer + 8) += 1;
            ret = 0;
        }
        err = ret;
    }
    return err;
}

extern "C" int fn_801EAD68(void* param_1, unsigned char* param_2, unsigned int param_3) {
    int err = 0;
    if (param_3 == 0) {
        return 0;
    }
    unsigned int remaining = *(unsigned int*)((unsigned char*)param_1 + 8) - *(unsigned int*)((unsigned char*)param_1 + 0xc);
    if (param_3 > remaining) {
        err = 0x302;
        param_3 = remaining;
    }
    TRK_memcpy(param_2, (unsigned char*)param_1 + *(unsigned int*)((unsigned char*)param_1 + 0xc) + 0x10, param_3);
    *(unsigned int*)((unsigned char*)param_1 + 0xc) += param_3;
    return err;
}

extern "C" int fn_801EADF4(unsigned char* param_1, unsigned char* param_2, unsigned int param_3) {
    int result = 0;
    if (param_3 == 0) {
        return 0;
    }
    unsigned int pos = *(unsigned int*)(param_1 + 0xc);
    if (0x880 - pos < param_3) {
        result = 0x301;
        param_3 = 0x880 - pos;
    }
    if (param_3 == 1) {
        *(param_1 + pos + 0x10) = *param_2;
    } else {
        TRK_memcpy(param_1 + pos + 0x10, param_2, param_3);
    }
    *(unsigned int*)(param_1 + 0xc) = *(unsigned int*)(param_1 + 0xc) + param_3;
    *(unsigned int*)(param_1 + 8) = *(unsigned int*)(param_1 + 0xc);
    return result;
}

extern "C" int TRKSetBufferPosition(void* param_1, unsigned int param_2) {
    int result = 0;
    if (param_2 > 0x880) {
        result = 0x301;
    } else {
        *(unsigned int*)((unsigned char*)param_1 + 0xc) = param_2;
        if (param_2 > *(unsigned int*)((unsigned char*)param_1 + 8)) {
            *(unsigned int*)((unsigned char*)param_1 + 8) = param_2;
        }
    }
    return result;
}

extern "C" void fn_801EAEC8(void* param_1, int param_2) {
    *(int*)((unsigned char*)param_1 + 8) = 0;
    *(int*)((unsigned char*)param_1 + 0xc) = 0;
    if (param_2 == 0) {
        fn_80003590((unsigned char*)param_1 + 0x10, 0, 0x880);
    }
}

extern "C" void TRKReleaseBuffer(int param_1) {
    if (param_1 != -1 && param_1 >= 0 && param_1 < 3) {
        unsigned char* buf = lbl_802F8A48 + param_1 * 0x890;
        TRKAcquireMutex(buf);
        *(int*)(buf + 4) = 0;
        TRKReleaseMutex(buf);
    }
}

extern "C" unsigned char* TRKGetBuffer(int param_1) {
    unsigned char* ret = 0;
    if (param_1 >= 0 && param_1 < 3) {
        ret = lbl_802F8A48 + param_1 * 0x890;
    }
    return ret;
}

extern "C" int TRKInitializeMutex(void* mutex);
extern "C" int TRKInitializeMessageBuffers(void) {
    unsigned char* buf = lbl_802F8A48;
    int i = 0;
    do {
        TRKInitializeMutex(buf);
        TRKAcquireMutex(buf);
        *(int*)(buf + 4) = 0;
        TRKReleaseMutex(buf);
        i++;
        buf += 0x890;
    } while (i < 3);
    return 0;
}

