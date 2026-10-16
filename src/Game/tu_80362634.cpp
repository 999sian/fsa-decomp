

#include "types.h"

extern "C" void* fn_8013C824(void);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* mgr, void* emitter);
extern "C" void* fn_804032E8(u32 type, const char* name);
extern "C" void fn_802F745C(void* mgr, void* pos, void* tex, void* prm);
extern "C" void* lbl_8053AB10;
extern "C" const char lbl_80474C10[];
extern "C" const s32 lbl_80474B88[];
extern "C" const s32 lbl_80474BA0[];

extern "C" void fn_80362634(char* self) {
    if (*(void**)(self + 0x300) != NULL) {
        void* mgr = *(void**)((char*)fn_8013C824() + 0xc);
        forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)(self + 0x300));
        *(void**)(self + 0x300) = NULL;
    }
}

extern "C" void fn_8036335C(void) {
}
struct Unk80365AB8;
typedef void (Unk80365AB8::*Unk80365AB8Func)();
extern Unk80365AB8Func lbl_804ADDE8[];
