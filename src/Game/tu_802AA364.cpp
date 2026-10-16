

extern "C" char lbl_804A8118[];
extern "C" void __dt__5ActorFv(void *, int);
extern "C" void *fn_802AA364(void *self, short flags) {
    if (self != 0) {
        *(void **)self = lbl_804A8118;
        __dt__5ActorFv(self, 0);
        if (flags > 0) {
            operator delete(self);
        }
    }
    return self;
}

extern "C" void fn_802AA3C4(void) {
}
