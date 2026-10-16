

extern "C" void fn_8021F914(int* p, int v) {
    p[1] = 0;
    p[0] = v;
}

extern "C" const float lbl_8053FDD8;
extern "C" const float lbl_8053FDDC;
extern "C" void fn_8021FB44(char* p) {
    *(int*)(p + 0x0) = 0;
    *(int*)(p + 0x4) = 0;
    *(float*)(p + 0x8) = lbl_8053FDDC;
    *(float*)(p + 0xc) = lbl_8053FDDC;
    *(float*)(p + 0x10) = lbl_8053FDDC;
    *(float*)(p + 0x14) = lbl_8053FDDC;
    *(float*)(p + 0x18) = lbl_8053FDDC;
    *(float*)(p + 0x1c) = lbl_8053FDDC;
    *(float*)(p + 0x20) = lbl_8053FDDC;
    *(float*)(p + 0x24) = lbl_8053FDDC;
    *(float*)(p + 0x28) = lbl_8053FDDC;
    *(float*)(p + 0x2c) = lbl_8053FDDC;
    *(float*)(p + 0x30) = lbl_8053FDD8;
    *(int*)(p + 0x34) = 0;
    *(int*)(p + 0x38) = 0;
    *(int*)(p + 0x3c) = 0;
}

