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
