

#include "types.h"

extern "C" void* fn_8013C824(void);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* mgr, void* em);
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void __dl__FPv(void* this_);
extern "C" char lbl_804AE338[];

extern "C" void fn_8036E544(void* this_) {
    char* p = (char*)this_;
    int i = 0;
    do {
        if (*(void**)(p + 0x258)) {
            void* base = fn_8013C824();
            void* mgr = *(void**)((char*)base + 0xc);
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)(p + 0x258));
            *(void**)(p + 0x258) = 0;
        }
        i++;
        p += 4;
    } while (i < 0x14);
    if (*(void**)((char*)this_ + 0x2a8)) {
        void* base = fn_8013C824();
        void* mgr = *(void**)((char*)base + 0xc);
        forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)((char*)this_ + 0x2a8));
        *(void**)((char*)this_ + 0x2a8) = 0;
    }
}

extern "C" void fn_8036E5E4(void) {
}

extern "C" void* fn_8036F880(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AE338;
        char* p = (char*)this_;
        int i = 0;
        do {
            if (*(void**)(p + 0x258)) {
                void* base = fn_8013C824();
                void* mgr = *(void**)((char*)base + 0xc);
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)(p + 0x258));
                *(void**)(p + 0x258) = 0;
            }
            i++;
            p += 4;
        } while (i < 0x14);
        if (*(void**)((char*)this_ + 0x2a8)) {
            void* base = fn_8013C824();
            void* mgr = *(void**)((char*)base + 0xc);
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)((char*)this_ + 0x2a8));
            *(void**)((char*)this_ + 0x2a8) = 0;
        }
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

