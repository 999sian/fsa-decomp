// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800efb88-0x800efc44 (1 functions). split_file divides it into the game's real files.
struct Unk800EFB88Obj { void* vtbl; signed char a; int b; signed char c; float d; };
struct Unk800EFB88Copy { int w[9]; };

extern "C" void* __register_global_object(void* obj, void* dtor, void* reg);
extern "C" void fn_800EFB40(void);
extern "C" char lbl_8028B900[];
extern "C" char lbl_802C5870[];
extern "C" char lbl_8028B818[];
extern "C" float lbl_80301138;
extern "C" Unk800EFB88Obj lbl_802C587C;
extern "C" void fn_800EFB88(void) {
    char* p = lbl_8028B818;
    lbl_802C587C.vtbl = lbl_8028B900;
    lbl_802C587C.a = -1;
    lbl_802C587C.b = 0;
    lbl_802C587C.c = 30;
    lbl_802C587C.d = lbl_80301138;
    __register_global_object(&lbl_802C587C, (void*)fn_800EFB40, lbl_802C5870);
    *(Unk800EFB88Copy*)(p + 0x5c) = *(Unk800EFB88Copy*)(p + 0x38);
}
