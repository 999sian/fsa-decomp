// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8011580c-0x80115bd4 (12 functions). split_file divides it into the game's real files.

struct Vec3f { float x, y, z; };

extern "C" void fn_8011580C(void* self, void** cb) {
    ((void (*)(void*, void*))cb[0])(*(void**)((char*)self + 0xc), cb[1]);
}

extern "C" void fn_8011583C(void* self, void** cb) {
    ((void (*)(void*, void*))cb[0])(*(void**)((char*)self + 0xc), cb[1]);
}

extern "C" void fn_801C68C8(void*, void*, Vec3f*);
extern "C" void fn_801C6910(void*, Vec3f*);
extern "C" void fn_80115960(void*);
extern "C" float fn_801C6970(void*);
extern "C" void fn_801C692C(void*, Vec3f*);
extern const Vec3f lbl_802C5C94;
extern "C" void fn_8011586C(Vec3f* out, void* a, void* b) {
    Vec3f v;
    fn_801C68C8(a, b, &v);
    *out = v;
}

