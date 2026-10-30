// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

class JKRHeap {
public:
    int getFreeSize();
};

class JASBNKParser {
public:
    static void* createBank(const void*, JKRHeap*);
};

extern JKRHeap* JASDram;
extern "C" int lbl_80557688;
extern "C" void* fn_8002FB90(const void*, JKRHeap*);
extern "C" void* fn_8002F34C(const void*, JKRHeap*);
extern "C" void* fn_8002F294(const void* data, JKRHeap* heap);
void* JASBNKParser::createBank(const void* data, JKRHeap* heap) {
    return fn_8002F294(data, heap);
}

extern "C" void* fn_8002F294(const void* data, JKRHeap* heap) {
    if (heap == 0) {
        heap = JASDram;
    }
    int before = heap->getFreeSize();
    void* bank = 0;
    switch (*(int*)((char*)data + 0xc)) {
    case 0:
        bank = fn_8002FB90(data, heap);
        break;
    case 1:
        bank = fn_8002F34C(data, heap);
        break;
    }
    lbl_80557688 += before - heap->getFreeSize();
    return bank;
}

extern "C" void fn_80030380(short* p) {
    short v;
    do {
        v = *p;
        p += 3;
    } while (v <= 10);
}

extern "C" char* fn_80030394(char* base, unsigned long off) {
    if (off == 0) {
        return 0;
    }
    return base + off;
}

extern "C" char* fn_800303AC(char* base, unsigned long off) {
    if (off == 0) {
        return 0;
    }
    return base + off;
}

extern "C" char* fn_800303C4(char* base, unsigned long off) {
    if (off == 0) {
        return 0;
    }
    return base + off;
}

extern "C" char* fn_800303DC(char* base, unsigned long off) {
    if (off == 0) {
        return 0;
    }
    return base + off;
}

extern "C" char* fn_800303F4(char* base, unsigned long off) {
    if (off == 0) {
        return 0;
    }
    return base + off;
}

extern "C" char* fn_8003040C(char* base, unsigned long off) {
    if (off == 0) {
        return 0;
    }
    return base + off;
}

extern "C" char* fn_80030424(char* base, unsigned long off) {
    if (off == 0) {
        return 0;
    }
    return base + off;
}

extern "C" char* fn_8003043C(char* base, unsigned long off) {
    if (off == 0) {
        return 0;
    }
    return base + off;
}

extern "C" char* fn_80030454(char* base, unsigned long off) {
    if (off == 0) {
        return 0;
    }
    return base + off;
}

