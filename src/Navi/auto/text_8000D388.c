// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8000d388-0x8000d404 (1 functions). split_file divides it into the game's real files.

extern "C" void __register_global_object(void* obj, void* dtor, void* reg);
extern "C" void fn_8000D440(void);
extern "C" void fn_8000D404(void);
extern "C" char lbl_8029F8D8[];
extern "C" char* lbl_802FB808;
extern "C" char* lbl_802FB80C;
extern "C" int lbl_802FEB98;

inline void* operator new(unsigned long, void* p) { return p; }

struct Unk8000D388List {
    char* m0;
    char m4[0x110];
    char* m114;
    char* m118;

    void init() {
        m0 = m4;
        m114 = m4 + 0x10;
        m118 = (char*)&m114;
    }
};
extern "C" void fn_8000D388(void) {
    char* base = lbl_8029F8D8;
    Unk8000D388List* p;
    lbl_802FB808 = base + 0x30;
    lbl_802FB80C = lbl_802FB808 + 0x300;
    __register_global_object(&lbl_802FEB98, (void*)fn_8000D440, base + 0x330);
    p = new (base + 0x348) Unk8000D388List;
    __register_global_object(p, (void*)fn_8000D404, base + 0x33c);
}
