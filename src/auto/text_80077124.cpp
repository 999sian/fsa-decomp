// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
class JPABaseEmitter;

class JPAEmitterCallBack {
public:
    virtual ~JPAEmitterCallBack();
    virtual void execute(JPABaseEmitter*);
    virtual void executeAfter(JPABaseEmitter*);
    virtual void draw(JPABaseEmitter*);
    virtual void drawAfter(JPABaseEmitter*);
};

void JPAEmitterCallBack::execute(JPABaseEmitter*) {}
