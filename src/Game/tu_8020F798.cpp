#include "Game/ItemBase.h"
#include "JSystem/JGeometry/Vec.h"
struct Vec3f { float x, y, z; };
struct TblEnt { char pad[0xc]; char* p; f32 f; };
extern TblEnt lbl_8046A238[];
extern "C" void fn_8020F80C(void* self, char* p);
extern "C" u16 fn_8022461C(void* pos, u32 room);
extern "C" void fn_801F0E34(void* self, u32 id, s32 flag);
extern "C" void* fn_8013CC50(u32 id, void* pos, u16 kind, s32 a, f32 scale, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_801CB7A0(void* obj);
extern "C" void fn_801CB71C(void* a, void* b, s32 c, s32 d);
extern "C" u8 fn_8023BCD4(s32 holder);
extern "C" s32 fn_8023CA88(s32 holder);
extern "C" s32 fn_8023CB24(s32 holder);
extern "C" void fn_801EF830(s32 idx, void* pos, DrawRec* rec, u32 mask, void* name, u32 p6, void* p7);
extern "C" void fn_802F86CC(void* layer, void* pos, void* res, s32 id, f32 sx, f32 sy, DrawRec* rec);
extern "C" void fn_801CD0D0(f32* a, f32* b);
extern "C" void fn_801EF574(void* a, void* b, f32* v, DrawRec* rec);
extern "C" void fn_80307AC8(void* obj, s32 id, void* pos, s32 kind, s32 a, s32 b, s32 c);
extern char lbl_8046A448[];
extern char lbl_8046A458[];
extern u8* lbl_8053AAF8;
extern char* lbl_8053AB10;

struct Tu8020F80CResMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* get(u32 type, const char* name);
};

extern "C" void fn_8020F798(char* self)
{
    JGeometry::TVec3f v(*(JGeometry::TVec3f*)(self + 0xc));
    fn_8020F80C(self, lbl_8046A238[*(int*)(self + 0x350)].p + *(int*)(self + 0x280));
    ((JGeometry::TVec3f*)(self + 0xc))->set(v);
}

extern "C" void fn_8020F80C(void* self, char* p)
{
    char* this_ = (char*)self;
    DrawRec rec;
    f32 mtx[3][4];
    u32 mode;
    f32 buf[3];

    if (*(u8*)(this_ + 0xc4) != 0) {
        u8 r = fn_8023BCD4(*(s32*)(this_ + 0xc8));
        ((u8*)&rec.w10)[3] = r;
        if (r == 0) {
            return;
        }
        rec.b1c = 0;
        rec.b1d = 0;
        if (*(s32*)(this_ + 0x138) == 0) {
            fn_801EF830(*(s32*)(this_ + 4), this_ + 0xc, &rec, 0, lbl_8046A448, 0, 0);
        }
        mode = 0;
        rec.b1f = 0;
        if (*(u8*)(this_ + 0xc4) != 0) {
            rec.b20 = 0;
            rec.b1c = fn_8023CA88(*(s32*)(this_ + 0xc8));
            rec.b1d = fn_8023CB24(*(s32*)(this_ + 0xc8)) + 1;
            mtx[0][3] = 0.0f;
            mtx[1][3] = 0.0f;
            mtx[2][3] = 0.0f;
            mtx[0][0] = 1.0f;
            mtx[0][1] = 0.0f;
            mtx[0][2] = 0.0f;
            mtx[1][0] = 0.0f;
            mtx[1][1] = 1.0f;
            mtx[1][2] = 0.0f;
            mtx[2][0] = 0.0f;
            mtx[2][1] = 0.0f;
            mtx[2][2] = -1.0f;
            rec.w18 = mtx;
            mode = 2;
            *(f32*)(this_ + 0x14) -= lbl_8046A238[*(s32*)(this_ + 0x350)].f;
        }
    }
    if (*(s32*)(this_ + 4) < 8) {
        void* res = (*(Tu8020F80CResMgr**)(lbl_8053AAF8 + 0xa4))->get('SOB ', lbl_8046A458);
        fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), this_ + 0xc, res, (s32)p, 1.0f, 1.0f, &rec);
    }
    if (*(s32*)(this_ + 4) == 8) {
        fn_801CD0D0((f32*)(this_ + 0xc), buf);
        fn_801EF574(lbl_8046A458, p, buf, &rec);
    }
    fn_80307AC8(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xc, (s32)p, 0, mode, -1);
}

extern "C" void fn_8020FADC(char* self)
{
    bool bVar2 = false;

    if (fn_8022461C(self + 0xc, *(u32*)(self + 4)) == 0x39) {
        bool bVar1 = false;
        if (*(u8*)(self + 0xc4) == 0 && *(f32*)(self + 0x14) <= 0.0f) {
            if (__fabsf(*(f32*)(self + 0xc) - *(f32*)(self + 0x18)) > 0.001f ||
                __fabsf(*(f32*)(self + 0x10) - *(f32*)(self + 0x1c)) > 0.001f) {
                bVar1 = true;
            }
        }
        if (bVar1) {
            fn_801F0E34(self, 0x4007f, 0);
            if (*(void**)(self + 0x358) == 0) {
                *(void**)(self + 0x358) = fn_8013CC50(*(u32*)(self + 4), self + 0xc, 0x4d2, 0, 1.0f, 0, 0, 0, 1);
            }
        } else {
            bVar2 = true;
        }
    } else {
        bVar2 = true;
    }
    if (bVar2) {
        void* obj = *(void**)(self + 0x358);
        if (obj != 0 && !(*(u32*)((char*)obj + 0xf4) & 0x40)) {
            fn_801CB7A0(obj);
        }
    }
    if (*(void**)(self + 0x358) != 0) {
        fn_801CB71C(self + 0x358, self + 0xc, 0, 0);
    }
}

