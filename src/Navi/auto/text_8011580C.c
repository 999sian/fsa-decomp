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
extern "C" void fn_80115960(Vec3f* out, void* a, void* b);
extern "C" void fn_801C69EC(void*, void*, Vec3f*);
extern "C" float fn_801C6970(void*);
extern "C" void fn_801C692C(void*, Vec3f*);
extern const Vec3f lbl_802C5C94;
extern "C" void fn_8011586C(Vec3f* out, void* a, void* b) {
    Vec3f v;
    fn_801C68C8(a, b, &v);
    *out = v;
}

extern "C" void fn_801C68EC(void*, void*, Vec3f*);
extern "C" void fn_801158C0(Vec3f* out, void* a, void* b) {
    Vec3f v;
    fn_801C68EC(a, b, &v);
    *out = v;
}

extern "C" void fn_80115914(Vec3f* out, void* a) {
    Vec3f v;
    fn_801C6910(a, &v);
    *out = v;
}

extern const float lbl_80301424;

extern "C" void fn_80115960(Vec3f* out, void* a, void* b) {
    Vec3f v;
    fn_801C69EC(a, b, &v);
    *out = v;
}

extern "C" Vec3f* fn_801159B4(Vec3f* out, void* a, void* b) {
    fn_80115960(out, a, b);
    return out;
}

extern const float lbl_8030141C;
extern "C" void fn_801159E0(Vec3f* out, void* a) {
    Vec3f v;
    bool small = fn_801C6970(a) < lbl_8030141C;
    if (!small) {
        fn_801C692C(a, &v);
    } else {
        v = lbl_802C5C94;
    }
    *out = v;
}

extern "C" void fn_80115A74(Vec3f* out, Vec3f* a) {
    fn_801C692C(a, a);
    *out = *a;
}

extern "C" int fn_80115AC8(Vec3f* a) {
    if (fn_801C6970(a) < lbl_8030141C) {
        return 0;
    }
    fn_801C692C(a, a);
    return 1;
}

extern const float lbl_80301424;
extern const float lbl_802FEAB8;
extern "C" int fn_80115B58(Vec3f* a) {
    int ret = 0;
    bool ok = false;
    if ((float)__fabs(a->x) < lbl_80301424 * lbl_802FEAB8 && (float)__fabs(a->y) < lbl_80301424 * lbl_802FEAB8) {
        ok = true;
    }
    if (ok && (float)__fabs(a->z) < lbl_80301424 * lbl_802FEAB8) {
        ret = 1;
    }
    return ret;
}

