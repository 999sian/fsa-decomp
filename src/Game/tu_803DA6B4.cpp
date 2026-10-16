#include "types.h"

struct Tu803DA6B4Sub {
    virtual void v00(s32 how);
};

struct Tu803DA6B4Owner {
    void* vtbl;
    Tu803DA6B4Sub* mpSub;
};

extern "C" char lbl_804B04F8[];
extern "C" void* lbl_8053ADC8;
