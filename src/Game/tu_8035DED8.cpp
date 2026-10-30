

struct Unk8035DA78;
typedef void (Unk8035DA78::*Unk8035DA78Func)();
extern Unk8035DA78Func lbl_804AD6A8[];
extern "C" void fn_8035E57C(Unk8035DA78* self) {
    char* p = (char*)self;
    if (*(int*)(p + 0x234) != 0) *(int*)(p + 0x234) -= 1;
    if (*(int*)(p + 0x244) != 0) *(int*)(p + 0x244) -= 1;
    (self->*lbl_804AD6A8[*(int*)(p + 0x230)])();
}
