

extern "C" const float lbl_8053FDD8;
extern "C" const float lbl_8053FDDC;
extern "C" void* fn_8013C824();
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void*, void*);
extern int __float_epsilon[];
extern "C" void fn_8013CB44(void*, void*, void*, void*, int);

static inline void approachTimed(float* value, float target, float frames) {
    if (frames < *(float*)__float_epsilon) {
        *value = target;
    } else {
        *value += (lbl_8053FDD8 / frames) * (target - *value);
    }
}

static inline void updateEmitters(char* self) {
    int i = 0;
    void** p = (void**)self;
    do {
        if (p[13]) fn_8013CB44(p[13], self + 8, 0, 0, 1);
        i++;
        p++;
    } while (i < 3);
}

static inline void setEmitterScale(void* emitter, float scale) {
    if (emitter) {
        char* p = (char*)emitter;
        *(float*)(p + 0x98) = scale;
        *(float*)(p + 0x9c) = scale;
        *(float*)(p + 0xa0) = scale;
        *(float*)(p + 0xb0) = scale;
        *(float*)(p + 0xb4) = scale;
    }
}


#pragma optimization_level 3
extern "C" int fn_8021F4B0(char* self) {
    int i;
    void** p;
    int result = 0;
    *(int*)(self + 4) += 1;
    if (*(int*)(self + 4) < 0) *(int*)(self + 4) = 0;
    switch (*(int*)self) {
    case 1:
        if (*(int*)(self + 4) >= 240) {
            *(int*)(self + 4) = 0;
            *(int*)self = 2;
        } else {
            float frames = 240 - *(int*)(self + 4);
            approachTimed((float*)(self + 8), *(float*)(self + 0x14), frames);
            approachTimed((float*)(self + 0xc), *(float*)(self + 0x18), frames);
            approachTimed((float*)(self + 0x10), *(float*)(self + 0x1c), frames);
            i = 0;
            p = (void**)self;
            for (; i < 3; i++, p++) {
                void* emitter = p[13];
                if (emitter) fn_8013CB44(emitter, self + 8, 0, 0, 1);
            }
        }
        break;
    case 2:
        if (*(int*)(self + 4) >= 60) {
            *(int*)(self + 4) = 0;
            *(int*)self = 3;
        }
        break;
    case 3:
        if (*(int*)(self + 4) >= 120) {
            *(int*)(self + 4) = 0;
            result = 1;
            *(int*)self = 4;
        } else {
            float frames = 120 - *(int*)(self + 4);
            approachTimed((float*)(self + 8), *(float*)(self + 0x20), frames);
            approachTimed((float*)(self + 0xc), *(float*)(self + 0x24), frames);
            approachTimed((float*)(self + 0x10), *(float*)(self + 0x28), frames);
            i = 0;
            p = (void**)self;
            for (; i < 3; i++, p++) {
                void* emitter = p[13];
                if (emitter) fn_8013CB44(emitter, self + 8, 0, 0, 1);
            }
        }
        break;
    case 4:
        result = 1;
        break;
    case 5:
        result = 1;
        if (*(int*)(self + 4) >= 60) {
            int i = 0;
            void** p = (void**)self;
            int null = i;
            do {
                if (p[13]) {
                    void* mgr = *(void**)((char*)fn_8013C824() + 0xc);
                    forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, p[13]);
                    p[13] = (void*)null;
                }
                i++;
                p++;
            } while (i < 3);
            *(int*)(self + 4) = 0;
            *(int*)self = 0;
        } else {
            float frames = 60 - *(int*)(self + 4);
            approachTimed((float*)(self + 0x10), *(float*)(self + 0x2c), frames);
            approachTimed((float*)(self + 0x30), lbl_8053FDDC, frames);
            i = 0;
            p = (void**)self;
            for (; i < 3; i++, p++) {
                void* emitter = p[13];
                if (emitter) fn_8013CB44(emitter, self + 8, 0, 0, 1);
            }
            float scale = *(float*)(self + 0x30);
            setEmitterScale(((void**)self)[13], scale);
            setEmitterScale(((void**)self)[14], scale);
            setEmitterScale(((void**)(self + 8))[13], scale);
        }
        break;
    }
    return result;
}
#pragma optimization_level 4
extern "C" void fn_8021F914(int* p, int v) {
    p[1] = 0;
    p[0] = v;
}

extern "C" void* fn_8013C824();
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void*, void*);
extern "C" void fn_8021F924(int* this_) {
    void** p = (void**)this_;
    for (int i = 0; i < 3; i++) {
        if (p[0xd]) {
            void* mgr = *(void**)((char*)fn_8013C824() + 0xc);
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, p[0xd]);
            p[0xd] = 0;
        }
        p++;
    }
    this_[1] = 0;
    this_[0] = 0;
}

extern "C" const float lbl_8053FDE8;
extern "C" const float lbl_8053FDEC;
extern "C" const float lbl_8053FDF0;
extern "C" const float lbl_8053FDF4;
extern "C" void* fn_8013CC50(int room, void* pos, float scale, int id, int a, int b, int c, int d, int e);
extern "C" unsigned short lbl_8053FDD0[3];
extern "C" void fn_8021F9AC(char* this_, float* src) {
    void** p;
    int i;
    float x = src[0];
    float k1 = lbl_8053FDE8;
    float y = src[1];
    float k2 = lbl_8053FDF0;
    float k3 = lbl_8053FDEC;

    *(float*)(this_ + 0x8) = x;
    *(float*)(this_ + 0xc) = y;
    *(float*)(this_ + 0x10) = src[2];
    *(float*)(this_ + 0x14) = *(float*)(this_ + 0x8);
    *(float*)(this_ + 0x18) = *(float*)(this_ + 0xc);
    *(float*)(this_ + 0x1c) = k1 + *(float*)(this_ + 0x10);
    *(float*)(this_ + 0x20) = *(float*)(this_ + 0x8);
    *(float*)(this_ + 0x24) = k2 + *(float*)(this_ + 0xc);
    *(float*)(this_ + 0x28) = k3 + *(float*)(this_ + 0x10);
    *(float*)(this_ + 0x2c) = lbl_8053FDF4 + *(float*)(this_ + 0x10);
    *(int*)(this_ + 0x4) = 0;
    *(int*)(this_ + 0x0) = 1;

    p = (void**)this_;
    for (i = 0; i < 3; i++) {
        p[0xd] = fn_8013CC50(0, this_ + 0x8, *(float*)(this_ + 0x30), lbl_8053FDD0[i], 0, 0, 0, 0, 1);
        p++;
    }
}

extern "C" int* fn_8021FAB8(int* this_, short n) {
    if (this_) {
        int i = 0;
        void** p = (void**)this_;
        int null = i;
        do {
            if (p[0xd]) {
                void* mgr = *(void**)((char*)fn_8013C824() + 0xc);
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, p[0xd]);
                p[0xd] = (void*)null;
            }
            i++;
            p++;
        } while (i < 3);
        this_[1] = 0;
        this_[0] = 0;
        if (n > 0) operator delete(this_);
    }
    return this_;
}

extern "C" const float lbl_8053FDD8;
extern "C" const float lbl_8053FDDC;
extern "C" void fn_8021FB44(char* p) {
    *(int*)(p + 0x0) = 0;
    *(int*)(p + 0x4) = 0;
    *(float*)(p + 0x8) = lbl_8053FDDC;
    *(float*)(p + 0xc) = lbl_8053FDDC;
    *(float*)(p + 0x10) = lbl_8053FDDC;
    *(float*)(p + 0x14) = lbl_8053FDDC;
    *(float*)(p + 0x18) = lbl_8053FDDC;
    *(float*)(p + 0x1c) = lbl_8053FDDC;
    *(float*)(p + 0x20) = lbl_8053FDDC;
    *(float*)(p + 0x24) = lbl_8053FDDC;
    *(float*)(p + 0x28) = lbl_8053FDDC;
    *(float*)(p + 0x2c) = lbl_8053FDDC;
    *(float*)(p + 0x30) = lbl_8053FDD8;
    *(int*)(p + 0x34) = 0;
    *(int*)(p + 0x38) = 0;
    *(int*)(p + 0x3c) = 0;
}

void fn_8021FB94(void) {}
