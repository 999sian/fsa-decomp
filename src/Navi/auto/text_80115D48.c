// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80115d48-0x80115d98 (1 functions). split_file divides it into the game's real files.
struct S16Vec3 {
    short x, y, z;
    S16Vec3() {}
    S16Vec3(short ax, short ay, short az) { x = ax; y = ay; z = az; }
};

extern "C" void __register_global_object(void*, void*, void*);
extern "C" void fn_8001766C(void);
extern char lbl_802C5D48[];
extern S16Vec3 lbl_802FF220;
extern "C" void fn_80115D48(void) {
    S16Vec3 tmp;
    tmp.x = 0;
    tmp.y = 0;
    tmp.z = 0;
    lbl_802FF220 = tmp;
    __register_global_object(&lbl_802FF220, (void*)fn_8001766C, lbl_802C5D48);
}
