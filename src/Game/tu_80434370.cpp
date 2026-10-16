class J2DGrafContext;
class J2DScreen {
public:
    void draw(float, float, const J2DGrafContext*);
};

class Unk80434370 {
public:
    unsigned char pad[0x6b];
    unsigned char m_state;
};
typedef void (Unk80434370::*Unk80434370Fn)();
extern Unk80434370Fn lbl_804B1690[];

extern "C" char* lbl_8053AB10;
extern "C" void* lbl_8053AED8;
extern "C" const float lbl_80543BD8;
extern "C" void fn_8013B490(void*);
extern "C" void fn_80440EE8(void*);
extern "C" Unk80434370Fn lbl_804B1690[];
extern "C" void fn_80436668(char* param_1)
{
    fn_8013B490(lbl_8053AB10);
    (*(J2DScreen**)(param_1 + 4))->draw(lbl_80543BD8, lbl_80543BD8, *(J2DGrafContext**)(lbl_8053AB10 + 0x10));
    fn_80440EE8(lbl_8053AED8);
}

extern "C" int fn_804366B8(Unk80434370* param_1)
{
    (param_1->*lbl_804B1690[param_1->m_state])();
    return 2 == param_1->m_state;
}
