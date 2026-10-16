

struct Unk8035DA78;
typedef void (Unk8035DA78::*Unk8035DA78Func)();
extern Unk8035DA78Func lbl_804AD6A8[];
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* base, int id);
extern "C" void fn_8035C1C4(void* self, int a, int b);
extern "C" void fn_8035DFE4(int param_1) {
    char* p = (char*)param_1;
    if (*(int*)(p + 0x234) == 0) {
        if (*(int*)(p + 0x238) == 0) {
            char* found = (char*)fn_801F666C(fn_801F856C(), *(int*)(p + 0x23c));
            if (found != 0) {
                *(int*)(found + 0x234) = 1;
            }
        } else {
            fn_8035C1C4(p, 6, 0x9b);
            *(int*)(p + 0x230) += 1;
        }
    } else if (*(int*)(p + 0x234) < 0xf0) {
        *(int*)(p + 0x248) = 0x18;
    }
}

extern "C" void fn_8035E238(int param_1) {
    char* p = (char*)param_1;
    if (*(int*)(p + 0x244) == 0) {
        *(int*)(p + 0x248) = 0;
    }
    if (*(int*)(p + 0x238) == 0) return;
    *(int*)(p + 0x230) = 3;
    *(int*)(p + 0x234) = 100;
    *(int*)(p + 0x238) = 0;
}

extern "C" void fn_8035E57C(Unk8035DA78* self) {
    char* p = (char*)self;
    if (*(int*)(p + 0x234) != 0) *(int*)(p + 0x234) -= 1;
    if (*(int*)(p + 0x244) != 0) *(int*)(p + 0x244) -= 1;
    (self->*lbl_804AD6A8[*(int*)(p + 0x230)])();
}
