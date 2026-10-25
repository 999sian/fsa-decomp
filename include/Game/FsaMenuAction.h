#ifndef GAME_FSAMENUACTION_H
#define GAME_FSAMENUACTION_H
#include "types.h"
struct FsaMenuActionBase { u32 unk_0[2]; };
struct FsaMenuAction : FsaMenuActionBase {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void setAction(u32*);
};
#endif
