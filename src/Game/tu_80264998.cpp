

extern "C" int fn_802486A0(void*);
extern "C" int fn_80248778(void*);
extern "C" int fn_80240888(void*);
extern "C" void fn_80265D68(char* p)
{
    unsigned char v = *(unsigned char*)(p + 0xca0);
    if (v >= 8) {
        *(unsigned char*)(p + 0xca0) = v - 8;
        return;
    }
    *(unsigned char*)(p + 0xca0) = 0;
}

extern "C" void fn_80267384(char* p)
{
    if (fn_802486A0(p) == 4) {
        int a = fn_80248778(p);
        int b = fn_80240888(p);
        if (b != a) {
            int t = *(int*)(p + 0x3dc);
            if (t == 0) {
                *(short*)(p + 0x3c4) = 0x1bf;
            } else if (t == 1) {
                *(short*)(p + 0x3c4) = 0x1c1;
            } else if (t == 2) {
                *(short*)(p + 0x3c4) = 0x1c3;
            } else {
                *(short*)(p + 0x3c4) = 0x1c3;
            }
            return;
        }
    }
    int t = *(int*)(p + 0x3dc);
    if (t == 0) {
        *(short*)(p + 0x3c4) = 0x3c;
    } else if (t == 1) {
        *(short*)(p + 0x3c4) = 0x3d;
    } else if (t == 2) {
        *(short*)(p + 0x3c4) = 0x3e;
    } else {
        *(short*)(p + 0x3c4) = 0x3f;
    }
}

extern "C" void fn_80267598(char* p)
{
    if (fn_802486A0(p) == 4) {
        int a = fn_80248778(p);
        int b = fn_80240888(p);
        if (b != a) {
            int t = *(int*)(p + 0x3dc);
            if (t == 0) {
                *(short*)(p + 0x3c4) = 0x1bf;
            } else if (t == 1) {
                *(short*)(p + 0x3c4) = 0x1c1;
            } else if (t == 2) {
                *(short*)(p + 0x3c4) = 0x1c3;
            } else {
                *(short*)(p + 0x3c4) = 0x1c3;
            }
            return;
        }
    }
    int t = *(int*)(p + 0x3dc);
    if (t == 0) {
        *(short*)(p + 0x3c4) = 0x3c;
    } else if (t == 1) {
        *(short*)(p + 0x3c4) = 0x3d;
    } else if (t == 2) {
        *(short*)(p + 0x3c4) = 0x3e;
    } else {
        *(short*)(p + 0x3c4) = 0x3f;
    }
}

extern "C" void fn_80268194(char* p)
{
    if (fn_802486A0(p) == 4) {
        int a = fn_80248778(p);
        int b = fn_80240888(p);
        if (b != a) {
            int t = *(int*)(p + 0x3dc);
            if (t == 0) {
                *(short*)(p + 0x3c4) = 0x1bf;
            } else if (t == 1) {
                *(short*)(p + 0x3c4) = 0x1c1;
            } else if (t == 2) {
                *(short*)(p + 0x3c4) = 0x1c3;
            } else {
                *(short*)(p + 0x3c4) = 0x1c3;
            }
            return;
        }
    }
    int t = *(int*)(p + 0x3dc);
    if (t == 0) {
        *(short*)(p + 0x3c4) = 0x3c;
    } else if (t == 1) {
        *(short*)(p + 0x3c4) = 0x3d;
    } else if (t == 2) {
        *(short*)(p + 0x3c4) = 0x3e;
    } else {
        *(short*)(p + 0x3c4) = 0x3f;
    }
}

