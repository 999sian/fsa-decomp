

extern "C" void* fn_8045787C(char*, int);
void* fn_8045787C(char* p, int v);
extern "C" void* fn_8045787C(char* p, int v);
extern "C" void* fn_80457C08(char* p, int v) {
    char* q = p - 0x18;
    return fn_8045787C(q, v);
}
extern "C" void* fn_8045787C(char*, int);
struct FSABase {
    virtual void* fn_80457C08(int v);
};

struct FSAThunkHolder : FSABase {
    int pad[6];
};

struct FSADerived {
    int pad[6];
    virtual void* fn_80457C08(int v);
};
