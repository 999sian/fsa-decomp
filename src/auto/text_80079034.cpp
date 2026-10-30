// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void* __vt__10J3DMtxCalc[];
extern void* __vt__11J3DShapeMtx[];

class J3DAnmTransform;

class J3DShapeMtx {
public:
    virtual unsigned int getUseMtxNum() const;
};

class J3DMtxCalc {
public:
    virtual ~J3DMtxCalc();
    virtual void setAnmTransform(J3DAnmTransform*);
    virtual void* getAnmTransform();
    virtual void setAnmTransform(unsigned char, J3DAnmTransform*);
    virtual void* getAnmTransform(unsigned char);
    virtual void setWeight(unsigned char, float);
    virtual float getWeight(unsigned char) const;
};

unsigned int J3DShapeMtx::getUseMtxNum() const { return 1; }

void J3DMtxCalc::setAnmTransform(J3DAnmTransform*) {}

void* J3DMtxCalc::getAnmTransform() { return 0; }

void J3DMtxCalc::setAnmTransform(unsigned char, J3DAnmTransform*) {}

void* J3DMtxCalc::getAnmTransform(unsigned char) { return 0; }

void J3DMtxCalc::setWeight(unsigned char, float) {}

float J3DMtxCalc::getWeight(unsigned char) const { return 1.0f; }

J3DMtxCalc::~J3DMtxCalc() {}

