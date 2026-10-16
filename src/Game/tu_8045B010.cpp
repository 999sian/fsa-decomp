

extern "C" void* fn_8045A640(void*);
extern "C" void fn_8045ABC8(void*);
extern "C" void fn_8045AD64(void*);
extern "C" void __ct__14WaveControllerFlll(void*, long, long, long);
extern "C" unsigned char lbl_804B20F8[];
#pragma mark fn_8045B010
extern "C" void fn_8045B010(void* p) {
    return fn_8045AD64((char*)p - 4);
}
extern "C" void fn_8045ABC8(void* p);
extern "C" void fn_8045B018(void* p) {
    fn_8045ABC8((char*)p - 4);
}

#pragma mark fn_8045B010
extern "C" void fn_8045B020(void* p) {
    fn_8045A640((char*)p - 8);
    return;
}
extern "C" char* fn_8045B46C(char* p, unsigned char value, long a, long b, long c) {
    __ct__14WaveControllerFlll(p, a, b, c);
    *(void**)(p + 8) = lbl_804B20F8;
    *(void**)(p + 0x18) = lbl_804B20F8 + 0x24;
    *(unsigned char*)(p + 0x5c) = value;
    return p;
}

