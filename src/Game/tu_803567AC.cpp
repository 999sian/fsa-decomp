

extern "C" void __dt__5ActorFv(void* this_, int how);
void operator delete(void* p);
extern "C" char lbl_804AD1C8[];
extern "C" void* fn_803567AC(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AD1C8;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            operator delete(this_);
        }
    }
    return this_;
}
