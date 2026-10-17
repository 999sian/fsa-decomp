

#include "types.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, s32 a, s32 b, f32 s0, f32 s1);
extern "C" const char lbl_80474BFC[];
extern "C" f32 lbl_80542B10;

extern "C" void* fn_8013C824(void);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* mgr, void* emitter);
extern "C" void* fn_804032E8(u32 type, const char* name);
extern "C" void fn_802F745C(void* mgr, void* pos, void* tex, void* prm);
extern "C" void* lbl_8053AB10;
extern "C" const char lbl_80474C10[];
extern "C" const s32 lbl_80474B88[];
extern "C" const s32 lbl_80474BA0[];

struct Unk80365AB8;
typedef void (Unk80365AB8::*Unk80365AB8Func)();
extern Unk80365AB8Func lbl_804ADDE8[];
extern Unk80365AB8Func lbl_804ADC38[];
extern "C" f32 lbl_80542BD4;

extern "C" void fn_80362634(char* self) {
    if (*(void**)(self + 0x300) != NULL) {
        void* mgr = *(void**)((char*)fn_8013C824() + 0xc);
        forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)(self + 0x300));
        *(void**)(self + 0x300) = NULL;
    }
}

extern "C" void fn_80362B14(char* self) {
    void* tex = fn_804032E8(0x54494d47, lbl_80474C10);
    if (*(s32*)(self + 4) < 8) {
        fn_802F745C(*(void**)((char*)lbl_8053AB10 + 0x20), self + 0xc, tex, NULL);
    }
}

extern "C" void fn_80362B74(char* self) {
    Vec saved;
    s32 i;

    fn_801F06F0(self, lbl_80474BFC, *(s32*)(self + 0x26c) + *(s32*)(self + 0x264), 0, 7, lbl_80542B10, lbl_80542B10);
    JGeometry::setTVec3f((f32*)(self + 0xc), (f32*)&saved);
    for (i = 0; i < 3; i++) {
        JGeometry::setTVec3f((f32*)(self + 0x27c + i * 0xc), (f32*)(self + 0xc));
        fn_801F06F0(self, lbl_80474BFC, *(s32*)(self + 0x2e8 + i * 4) + *(s32*)(self + 0x264), 0, 7, lbl_80542B10, lbl_80542B10);
    }
    JGeometry::setTVec3f((f32*)&saved, (f32*)(self + 0xc));
}

extern "C" void fn_8036335C(void) {
}

extern "C" void fn_80363F7C(char* self) {
    if (*(s32*)(self + 0x25c) == 0) {
        *(s32*)(self + 0x268) = *(s32*)(self + 0x268) + 1;
        if (*(s32*)(self + 0x268) >= 6) {
            *(s32*)(self + 0x268) = 0;
        }
        *(s32*)(self + 0x25c) = lbl_80474B88[*(s32*)(self + 0x268)];
        *(s32*)(self + 0x264) = lbl_80474BA0[*(s32*)(self + 0x268)];
    }
    ((JGeometry::TVec3<f32>*)(self + 0xc))->add(*(JGeometry::TVec3<f32>*)(self + 0x3c));
}

extern "C" void fn_80364F00(char* this_) {
    if (*(s32*)(this_ + 0x25c) != 0) {
        return;
    }
    *(s32*)(this_ + 0x268) += 1;
    if (*(char*)(*(char**)(this_ + 0x270) + *(s32*)(this_ + 0x268)) < 0) {
        *(s32*)(this_ + 0x268) = 0;
    }
    *(s32*)(this_ + 0x25c) = *(char*)(*(char**)(this_ + 0x270) + *(s32*)(this_ + 0x268));
    *(s32*)(this_ + 0x264) = *(char*)(*(char**)(this_ + 0x274) + *(s32*)(this_ + 0x268));
}

extern "C" f32 lbl_80542BCC;
extern "C" f32 lbl_80542BD0;
extern "C" f32 lbl_80542B0C;
extern "C" s32 fn_801CD664(s32 n);
extern "C" void fn_80364F60(char* this_) {
  if (*(s32*)(this_ + 0x238) != 5) {
    s32 prev = *(s32*)(this_ + 0x264);
    if (*(s32*)(this_ + 0x25c) == 0) {
      *(s32*)(this_ + 0x268) += 1;
      if (*(char*)(*(char**)(this_ + 0x270) + *(s32*)(this_ + 0x268)) < 0) {
        *(s32*)(this_ + 0x268) = 0;
      }
      *(s32*)(this_ + 0x25c) = *(char*)(*(char**)(this_ + 0x270) + *(s32*)(this_ + 0x268));
      *(s32*)(this_ + 0x264) = *(char*)(*(char**)(this_ + 0x274) + *(s32*)(this_ + 0x268));
    }
    s32 cur = *(s32*)(this_ + 0x264);
    if (prev != cur && *(s32*)(this_ + 0x238) >= 4 && *(s32*)(this_ + 0x238) <= 7 && cur == 0) {
      *(s32*)(this_ + 0x25c) += fn_801CD664(5) * 6;
    }
    if (*(s32*)(this_ + 0x238) == 0x1d || *(s32*)(this_ + 0x238) == 0x1e) {
      if (*(s32*)(this_ + 0x268) == 2) {
        if (*(s32*)(this_ + 0x25c) == 0xc) {
          *(f32*)(this_ + 0x44) = lbl_80542BCC;
        } else {
          *(f32*)(this_ + 0x44) = *(f32*)(this_ + 0x44) - lbl_80542BD0;
        }
        *(f32*)(this_ + 0x14) = *(f32*)(this_ + 0x14) + *(f32*)(this_ + 0x44);
      } else {
        f32 zero = lbl_80542B0C;
        *(f32*)(this_ + 0x14) = zero;
        *(f32*)(this_ + 0x44) = zero;
      }
    }
  }
}

extern "C" void* fn_8013CC50(u32 id, void* pos, f32 scale, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern f32 lbl_80542B10;
extern "C" void fn_8036509C(char* self) {
    if (*(s32*)(self + 0x248) != 0) {
        if (*(s32*)(self + 0x248) <= 0xe) {
            if (*(s32*)(self + 0x248) == 0xe) {
                char* p = *(char**)(self + 0x300);
                if (p != NULL) {
                    *(u32*)(p + 0xf4) |= 1;
                    *(s32*)(p + 0x24) = 1;
                    *(void**)(self + 0x300) = NULL;
                }
                *(s32*)(self + 0x258) = 0;
                *(s32*)(self + 0x264) = 0xb;
                fn_8013CC50(*(u32*)(self + 4), self + 0xc, 1.0f, 0x15b, 0, 1, 0, 0, 1);
                fn_8013CC50(*(u32*)(self + 4), self + 0xc, 1.0f, 0x15c, -1, 0, 0, 0, 1);
            } else if (*(s32*)(self + 0x248) == 0xa) {
                *(s32*)(self + 0x264) = 0xa;
            } else if (*(s32*)(self + 0x248) == 8) {
                *(s32*)(self + 0x264) = 9;
            } else if (*(s32*)(self + 0x248) == 6) {
                *(s32*)(self + 0x264) = 8;
            } else if (*(s32*)(self + 0x248) == 4) {
                *(s32*)(self + 0x264) = 2;
            } else if (*(s32*)(self + 0x248) == 2) {
                *(s32*)(self + 0x264) = 1;
            }
        }
        if (*(s32*)(self + 0x248) == 1) {
            *(s32*)(self + 0x25c) = fn_801CD664(9);
            *(s32*)(self + 0x264) = 0;
        }
    } else {
        if (*(s32*)(self + 0x25c) == 0) {
            *(s32*)(self + 0x25c) = 8;
            *(s32*)(self + 0x264) = *(s32*)(self + 0x264) + 1;
            if (*(s32*)(self + 0x264) >= 4) {
                *(s32*)(self + 0x264) = 0;
            }
        }
    }
}

extern "C" void fn_80365220(char* this_) {
    if (*(s32*)(this_ + 0x248) == 0) {
        *(s32*)(this_ + 0x248) = 0x40;
        *(s32*)(this_ + 0x238) += 1;
    }
    if (!(*(u32*)(this_ + 0x238) & 1)) {
        *(f32*)(this_ + 0x10) += lbl_80542BD4;
    } else {
        *(f32*)(this_ + 0x10) -= lbl_80542BD4;
    }
}

extern "C" const s32 lbl_80474BC4[];
extern "C" f32 lbl_80542BD8;
extern "C" void fn_80365274(char* this_) {
    ((JGeometry::TVec3<f32>*)(this_ + 0xc))->add(*(JGeometry::TVec3<f32>*)(this_ + 0x3c));
    s32 state = *(s32*)(this_ + 0x238);
    switch (state) {
    case 0:
    case 2:
        if (*(s32*)(this_ + 0x25c) == 0) {
            *(s32*)(this_ + 0x25c) = *(s32*)(this_ + 0x260);
            *(s32*)(this_ + 0x268) += 1;
            if (*(s32*)(this_ + 0x268) >= 4) {
                *(s32*)(this_ + 0x268) = 0;
            }
            *(s32*)(this_ + 0x264) = lbl_80474BC4[*(s32*)(this_ + 0x268)];
        }
        if (*(s32*)(this_ + 0x248) == 0) {
            *(s32*)(this_ + 0x248) = 0xc6;
            f32 zero = lbl_80542B0C;
            *(f32*)(this_ + 0x44) = zero;
            *(f32*)(this_ + 0x40) = zero;
            *(f32*)(this_ + 0x3c) = zero;
            *(s32*)(this_ + 0x26c) = 0x3ac;
            *(s32*)(this_ + 0x264) = 0;
            if (*(s32*)(this_ + 0x238) == 2) {
                *(u8*)(this_ + 0x11c) = 0;
            } else {
                *(s32*)(this_ + 0x238) = *(s32*)(this_ + 0x238) + 1;
            }
        }
        break;
    case 1: {
        s32 timer = *(s32*)(this_ + 0x248);
        if (timer == 0x8a) {
            *(s32*)(this_ + 0x26c) = 0x3a4;
        } else if (timer == 0x72) {
            *(s32*)(this_ + 0x26c) = 0x3a8;
        } else if (timer == 0x5a) {
            *(s32*)(this_ + 0x26c) = 0x3a4;
        } else if (timer == 0) {
            f32 x = lbl_80542B0C;
            f32 y = lbl_80542BD8;
            *(s32*)(this_ + 0x238) = state + 1;
            *(s32*)(this_ + 0x26c) = 0x3b1;
            *(s32*)(this_ + 0x264) = 0;
            JGeometry::TVec3<f32> v(x, y, x);
            *(JGeometry::TVec3<f32>*)(this_ + 0x3c) = v;
            *(s32*)(this_ + 0x248) = 0x64;
        }
        break;
    }
    }
}

extern "C" void fn_80365AB8(Unk80365AB8* self) {
    (self->*lbl_804ADDE8[*(s32*)((u8*)self + 0x234)])();
}

extern "C" void fn_80365AF0(Unk80365AB8* self) {
    if (*(s8*)((u8*)self + 0x230) == 0) {
        if (*(s32*)((u8*)self + 0x248) != 0) {
            *(s32*)((u8*)self + 0x248) -= 1;
        }
        if (*(s32*)((u8*)self + 0x25c) != 0) {
            *(s32*)((u8*)self + 0x25c) -= 1;
        }
        (self->*lbl_804ADC38[*(s32*)((u8*)self + 0x234)])();
    }
}

extern "C" char lbl_804ADF28[];
extern "C" void __dt__5ActorFv(void* this_, s32 flag);
extern "C" void __dl__FPv(void*);
extern "C" char __vt__4EETC[];
extern "C" void* fn_80366D44(void* this_, short how) {
    if (this_) {
        *(void**)this_ = __vt__4EETC;
        if (*(s32*)((char*)this_ + 0x234) == 3) {
            if (*(void**)((char*)this_ + 0x300)) {
                void* base = fn_8013C824();
                void* mgr = *(void**)((char*)base + 0xc);
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)((char*)this_ + 0x300));
                *(void**)((char*)this_ + 0x300) = 0;
            }
        }
        if (*(s32*)((char*)this_ + 0x234) == 0x10) {
            if (*(void**)((char*)this_ + 0x304)) {
                void* base = fn_8013C824();
                void* mgr = *(void**)((char*)base + 0xc);
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)((char*)this_ + 0x304));
                *(void**)((char*)this_ + 0x304) = 0;
            }
            if (*(void**)((char*)this_ + 0x308)) {
                void* base = fn_8013C824();
                void* mgr = *(void**)((char*)base + 0xc);
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)((char*)this_ + 0x308));
                *(void**)((char*)this_ + 0x308) = 0;
            }
            char* p = (char*)this_;
            int i = 0;
            do {
                if (*(void**)(p + 0x30c)) {
                    void* base = fn_8013C824();
                    void* mgr = *(void**)((char*)base + 0xc);
                    forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)(p + 0x30c));
                    *(void**)(p + 0x30c) = 0;
                }
                i++;
                p += 4;
            } while (i < 4);
        }
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

