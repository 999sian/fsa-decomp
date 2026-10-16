

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

extern "C" void fn_80265D8C(char* p)
{
    unsigned char v = *(unsigned char*)(p + 0xca0);
    if (v <= 0xf7) {
        *(unsigned char*)(p + 0xca0) = v + 8;
        return;
    }
    *(unsigned char*)(p + 0xca0) = 0xff;
}

extern "C" void fn_80267018(char* p)
{
    int t;
    if (*(int*)(p + 0x3b4) < 8) {
        t = *(int*)(p + 0x3dc);
        if (t == 0) {
            *(short*)(p + 0x3c4) = 0x375;
        } else if (t == 1) {
            *(short*)(p + 0x3c4) = 0x37d;
        } else if (t == 2) {
            *(short*)(p + 0x3c4) = 0x385;
        } else {
            *(short*)(p + 0x3c4) = 0x38d;
        }
    } else {
        t = *(int*)(p + 0x3dc);
        if (t == 0) {
            *(short*)(p + 0x3c4) = 0x395;
        } else if (t == 1) {
            *(short*)(p + 0x3c4) = 0x39d;
        } else if (t == 2) {
            *(short*)(p + 0x3c4) = 0x3a5;
        } else {
            *(short*)(p + 0x3c4) = 0x3ad;
        }
    }
    *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
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

extern "C" void fn_80267818(char* p)
{
    int t;
    if (*(unsigned char*)(p + 0xb9b) == 1) {
        t = *(int*)(p + 0x3dc);
        if (t == 0) {
            *(short*)(p + 0x3c4) = 0x16b;
        } else if (t == 1) {
            *(short*)(p + 0x3c4) = 0x173;
        } else if (t == 2) {
            *(short*)(p + 0x3c4) = 0x17b;
        } else {
            *(short*)(p + 0x3c4) = 0x183;
        }
    } else {
        t = *(int*)(p + 0x3dc);
        if (t == 0) {
            *(short*)(p + 0x3c4) = 0x123;
        } else if (t == 1) {
            *(short*)(p + 0x3c4) = 0x12a;
        } else if (t == 2) {
            *(short*)(p + 0x3c4) = 0x131;
        } else {
            *(short*)(p + 0x3c4) = 0x138;
        }
    }
    *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fb);
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

