#include "types.h"
#include "JSystem/JParticle/JPAEmitter.h"


extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* p);
extern "C" void* fn_8013C824(void);
extern "C" char __vt__4GOAL[];
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* a, void* p);
extern "C" void* fn_802A64E8(void* this_, short how) {
    if (this_) {
        volatile u32* slot = (volatile u32*)this_;
        s32 i = 0;
        *(void**)this_ = __vt__4GOAL;
        do {
            if (slot[0xad] != 0) {
                (*(JPAEmitterManager**)((char*)fn_8013C824() + 0xc))->forceDeleteEmitter((JPABaseEmitter*)slot[0xad]);
            }
            if (slot[0xb1] != 0) {
                (*(JPAEmitterManager**)((char*)fn_8013C824() + 0xc))->forceDeleteEmitter((JPABaseEmitter*)slot[0xb1]);
            }
            if (slot[0xb5] != 0) {
                (*(JPAEmitterManager**)((char*)fn_8013C824() + 0xc))->forceDeleteEmitter((JPABaseEmitter*)slot[0xb5]);
            }
            if (slot[0xb9] != 0) {
                (*(JPAEmitterManager**)((char*)fn_8013C824() + 0xc))->forceDeleteEmitter((JPABaseEmitter*)slot[0xb9]);
            }
            if (slot[0xbd] != 0) {
                (*(JPAEmitterManager**)((char*)fn_8013C824() + 0xc))->forceDeleteEmitter((JPABaseEmitter*)slot[0xbd]);
            }
            i++;
            slot++;
        } while (i < 4);
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}
