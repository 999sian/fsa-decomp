

extern "C" void fn_801D4F64(void);
extern "C" void fn_801CEBD0(void);

#define Vec SDKVec
#define PSMTXIdentity SDK_PSMTXIdentity
#include "JSystem/JGeometry/Vec.h"
#undef PSMTXIdentity
#undef Vec
#include "Game/Actor.h"
#include "Game/ItemBase.h"

extern "C" void* fn_804032E8(unsigned int tag, void* id);
extern "C" void fn_802F745C(void* mgr, void* pos, void* tex, void* rec);
extern "C" void* lbl_804A61A8[];
extern "C" const float lbl_8046A470[];
extern "C" const float lbl_8046A480[];
extern "C" const float lbl_8053FAC0;
extern "C" const float lbl_8053FAC4;
extern "C" const float lbl_8053FAC8;
extern "C" const double lbl_8053FAD0;
extern "C" char* lbl_8053AB10;

extern "C" void fn_80210630(Actor* p, unsigned char flag, unsigned char a, unsigned char b, unsigned char c)
{
	struct Rec {
		u8 ids[0x10];
		s32 w10;
		s32 w14;
		void* w18;
		u8 b1c, b1d, b1e, b1f, b20, b21, b22, b23, b24, b25, b26;
		s32 w28;
		u8 b2c, b2d, b2e;
		s32 w30;
		s32 w34;
		s32 w38;
	};
	void* tex = fn_804032E8(0x54494D47, lbl_804A61A8[p->field_98 + (flag ? 4 : 0)]);
	Rec rec;
	float mat[3][4];
	rec.w10 = -1;
	rec.w14 = -1;
	for (u32 i = 0; (u8)i < 0x10; i += 8) {
		rec.ids[(u8)i] = i;
		rec.ids[(u8)(i + 1)] = i + 1;
		rec.ids[(u8)(i + 2)] = i + 2;
		rec.ids[(u8)(i + 3)] = i + 3;
		rec.ids[(u8)(i + 4)] = i + 4;
		rec.ids[(u8)(i + 5)] = i + 5;
		rec.ids[(u8)(i + 6)] = i + 6;
		rec.ids[(u8)(i + 7)] = i + 7;
	}
	float sz = lbl_8053FAC4 * p->field_54.z;
	float sy = lbl_8053FAC4 * p->field_54.y;
	float sx = lbl_8053FAC4 * p->field_54.x;
	rec.w14 = 0;
	rec.b1c = 0;
	float pz = p->field_0C.z;
	rec.b1d = 0;
	JGeometry::TVec3<f32> v(*(JGeometry::TVec3<f32>*)&p->field_0C);
	float ox = lbl_8046A470[p->field_98];
	float oy = lbl_8046A480[p->field_98];
	float vx = v.x;
	float vy = v.y;
	s32 room = p->field_04;
	rec.w18 = 0;
	rec.w10 = -1;
	rec.b1e = 0;
	rec.b1f = 1;
	rec.b20 = 1;
	rec.b21 = 0;
	rec.b22 = 0;
	rec.b23 = 0;
	rec.b24 = 0;
	rec.b25 = 0;
	rec.b26 = 1;
	rec.w28 = 3;
	rec.b2c = 1;
	rec.b2d = 0;
	rec.b2e = 0;
	rec.w30 = -1;
	rec.w34 = 0;
	rec.w38 = 2;
	rec.b1c = a;
	rec.b1d = b;
	*(u8*)&rec.w14 = c;
	mat[0][3] = lbl_8053FAC0;
	mat[1][3] = lbl_8053FAC0;
	mat[2][3] = lbl_8053FAC0;
	mat[0][0] = sx;
	mat[0][1] = lbl_8053FAC0;
	mat[0][2] = lbl_8053FAC0;
	mat[1][0] = lbl_8053FAC0;
	mat[1][1] = sy;
	mat[1][2] = lbl_8053FAC0;
	mat[2][0] = lbl_8053FAC0;
	mat[2][1] = lbl_8053FAC0;
	mat[2][2] = sz;
	rec.w18 = mat;
	v.z = pz;
	v.x = vx + sx * (lbl_8053FAC8 * (float)*(unsigned short*)((char*)tex + 2) - ox);
	v.y = vy + sy * (lbl_8053FAC8 * (float)*(unsigned short*)((char*)tex + 4) - oy);
	if (room < 8) {
		fn_802F745C(*(void**)(lbl_8053AB10 + 0x20), &v, tex, &rec);
	}
}

extern "C" int fn_80210898(void)
{
	fn_801CEBD0();
	return 0;
}

extern const float lbl_8053FAD8;
extern const float lbl_8053FADC;
extern const float lbl_8053FAE0;
extern const float lbl_8053FAE4;
void fn_801CE0A4(int);
void fn_80239914(float *, unsigned int, unsigned int);
unsigned char *fn_8020D58C(void);
void fn_8020D8C0(unsigned char *, float *, unsigned int, unsigned int);
extern "C" void fn_801CE0A4(int);
extern "C" void fn_80239914(float *, unsigned int, unsigned int);
extern "C" unsigned char *fn_8020D58C(void);
extern "C" void fn_8020D8C0(unsigned char *, float *, unsigned int, unsigned int);
extern "C" void fn_801CE0A4(void);
extern "C" const float lbl_8053FAD8;
extern "C" const float lbl_8053FADC;
extern "C" const float lbl_8053FAE0;
extern "C" const float lbl_8053FAE4;
extern "C" void fn_80239914(float* box, unsigned int a, unsigned int b);
extern "C" unsigned char* fn_8020D58C(void);
extern "C" void fn_8020D8C0(unsigned char* p, float* box, unsigned int b, unsigned int a);
static inline void boxProducts108(const char* p,float* box) {
    float d=lbl_8053FAD8* *(const float*)(p+0x58);
    float c=lbl_8053FAE4* *(const float*)(p+0x58);
    float b=lbl_8053FADC* *(const float*)(p+0x54);
    float a=lbl_8053FAE0* *(const float*)(p+0x54);
    box[0]=a;box[1]=c;box[2]=b;box[3]=d;
}
extern "C" void fn_802108BC(int param_1) {
float box[4];
float c,d,b2,a0;
fn_801CE0A4();
d=lbl_8053FAD8 * *(float*)(param_1+0x58);
c=lbl_8053FAE4 * *(float*)(param_1+0x58);
const float& x=*(float*)(param_1+0x54);
b2=lbl_8053FADC * x;
a0=lbl_8053FAE0 * x;
box[0] = a0; box[1] = c; box[2] = b2; box[3] = d;
box[0] += *(float*)(param_1+0xc); box[1] += *(float*)(param_1+0x10); box[2] += *(float*)(param_1+0xc); box[3] += *(float*)(param_1+0x10);
fn_80239914(box,*(unsigned int*)(param_1+4),*(unsigned int*)(param_1+0x198));
unsigned int a = *(unsigned int*)(param_1+0x198);
unsigned int b = *(unsigned int*)(param_1+4);
unsigned char* base = fn_8020D58C();
fn_8020D8C0(base+base[0]*0x784+4,box,b,a);
}

extern "C" int fn_801D3CE4(void* p, float a, float b);
extern "C" void* fn_801D72D4(void* p);
extern "C" void* lbl_804C3128[];
extern "C" void fn_80210A30(char* p, float* out);
static inline void getBox(char* p, float* out)
{
    float bottom;
    float right;
    float y;
    float x;
    float left;
    float top;
    y = *(float*)(p + 0x58);
    x = *(float*)(p + 0x54);
    left = lbl_8053FAE0;
    top = lbl_8053FAE4;
    right = lbl_8053FADC;
    bottom = lbl_8053FAD8;
    out[0] = left * x;
    out[1] = top * y;
    out[2] = right * x;
    out[3] = bottom * y;
}
extern "C" void fn_80210990(char* p, int side, float* out)
{
 float y = *(float*)(p+0x58);
 float x = *(float*)(p+0x54);
 getBox(p,out);
 switch(side) {
 case 0: out[2] -= lbl_8053FAD8*x; break;
 case 1: out[0] += lbl_8053FAD8*x; break;
 case 2: out[3] -= lbl_8053FAD8*y; break;
 case 3: out[1] += lbl_8053FAD8*y; break;
 }
}

extern "C" void fn_80210A30(char* p, float* out) {
    float right;
    float bottom;
    float y;
    float x;
    float left;
    float top;
    y = *(float*)(p + 0x58);
    x = *(float*)(p + 0x54);
    left = lbl_8053FAE0;
    top = lbl_8053FAE4;
    right = lbl_8053FADC;
    bottom = lbl_8053FAD8;
    out[0] = left * x;
    out[1] = top * y;
    out[2] = right * x;
    out[3] = bottom * y;
}

extern "C" bool fn_80210A6C(char* p)
{
	bool r = false;
	if (fn_801D3CE4(p + 0x2a8, 128.0f, 2.0f) == 0) {
		r = true;
	}
	return r;
}

extern "C" void fn_801CEBD0(void);
extern "C" void* fn_801D0F40(void* this_);
extern void* lbl_804A61C8[];
extern "C" void* fn_80210AB4(void* p)
{
	fn_801D0F40(p);
	*(void***)p = lbl_804A61C8;
	*(float*)((char*)p + 0x2a8) = 0.0f;
	return p;
}

static const signed char lbl_8053FAB8[4][2] = { { 0x13, -4 }, { -0x13, -4 }, { 4, 10 }, { -4, -0x1c } };

extern "C" float fn_80210AF8(int i)
{
	return lbl_8053FAB8[i][1];
}

extern "C" float fn_80210B34(int i)
{
	return lbl_8053FAB8[i][0];
}
#include "JSystem/JAudio/JASFakeMatchFSA.h"
