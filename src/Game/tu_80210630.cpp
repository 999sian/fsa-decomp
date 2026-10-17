

extern "C" void fn_801D4F64(void);
extern "C" void fn_801CEBD0(void);

extern "C" void fn_804032E8(unsigned int tag, void* ptr);
extern "C" void fn_802F745C(void* a, ...);
extern "C" void* lbl_804A61A8[];
extern "C" const float lbl_8046A470[];
extern "C" const float lbl_8046A480[];
extern "C" const float lbl_8053FAC0;
extern "C" const float lbl_8053FAC4;
extern "C" const float lbl_8053FAC8;
extern "C" char* lbl_8053AB10;
extern "C" void fn_80210630(char* p, unsigned char flag, unsigned char a, unsigned char b, unsigned char c)
{
	unsigned char blk[0x3c];
	float mat[3][4];
	float v[3];
	unsigned char i;
	int k;

	fn_804032E8(0x54494D47, lbl_804A61A8[*(int*)(p + 0x98) + (flag != 0 ? 4 : 0)]);
	*(int*)(blk + 0x10) = -1;
	*(int*)(blk + 0x14) = -1;
	for (i = 0; i < 16; i += 8) {
		blk[(unsigned char)(i + 0)] = i + 0;
		blk[(unsigned char)(i + 1)] = i + 1;
		blk[(unsigned char)(i + 2)] = i + 2;
		blk[(unsigned char)(i + 3)] = i + 3;
		blk[(unsigned char)(i + 4)] = i + 4;
		blk[(unsigned char)(i + 5)] = i + 5;
		blk[(unsigned char)(i + 6)] = i + 6;
		blk[(unsigned char)(i + 7)] = i + 7;
	}
	k = *(int*)(p + 0x98);
	v[0] = *(float*)(p + 0xc);
	v[1] = *(float*)(p + 0x10);
	v[2] = *(float*)(p + 0x14);
	mat[0][0] = lbl_8053FAC4 * *(float*)(p + 0x54);
	mat[0][1] = lbl_8053FAC0;
	mat[0][2] = lbl_8053FAC0;
	mat[0][3] = lbl_8053FAC0;
	mat[1][0] = lbl_8053FAC0;
	mat[1][1] = lbl_8053FAC4 * *(float*)(p + 0x58);
	mat[1][2] = lbl_8053FAC0;
	mat[1][3] = lbl_8053FAC0;
	mat[2][0] = lbl_8053FAC0;
	mat[2][1] = lbl_8053FAC0;
	mat[2][2] = lbl_8053FAC4 * *(float*)(p + 0x5c);
	mat[2][3] = lbl_8053FAC0;
	v[0] = v[0] + mat[0][0] * (lbl_8053FAC8 * (float)*(unsigned short*)(p + 2) - lbl_8046A470[k]);
	v[1] = v[1] + mat[1][1] * (lbl_8053FAC8 * (float)*(unsigned short*)(p + 4) - lbl_8046A480[k]);
	*(void**)(blk + 0x18) = mat;
	blk[0x14] = c;
	blk[0x1c] = a;
	blk[0x1d] = b;
	blk[0x1e] = 0;
	blk[0x1f] = 1;
	blk[0x20] = 1;
	blk[0x21] = 0;
	blk[0x22] = 0;
	blk[0x23] = 0;
	blk[0x24] = 0;
	blk[0x25] = 0;
	blk[0x26] = 1;
	*(int*)(blk + 0x28) = 3;
	blk[0x2c] = 1;
	blk[0x2d] = 0;
	blk[0x2e] = 0;
	*(int*)(blk + 0x30) = -1;
	*(int*)(blk + 0x34) = 0;
	*(int*)(blk + 0x38) = 2;
	if (*(int*)(p + 4) < 8) {
		fn_802F745C(*(void**)(lbl_8053AB10 + 0x20), p, blk);
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
extern "C" void fn_802108BC(int param_1) {
    float box[4];
    fn_801CE0A4();
    float y = *(float *)(param_1 + 0x58);
    float x = *(float *)(param_1 + 0x54);
    box[3] = lbl_8053FAD8 * y;
    box[1] = lbl_8053FAE4 * y;
    box[0] = lbl_8053FAE0 * x;
    box[2] = lbl_8053FADC * x;
    box[0] += *(float *)(param_1 + 0xc);
    box[2] += *(float *)(param_1 + 0xc);
    box[1] += *(float *)(param_1 + 0x10);
    box[3] += *(float *)(param_1 + 0x10);
    fn_80239914(box, *(unsigned int *)(param_1 + 0x4), *(unsigned int *)(param_1 + 0x198));
    unsigned int a = *(unsigned int *)(param_1 + 0x198);
    unsigned int b = *(unsigned int *)(param_1 + 0x4);
    unsigned char *base = fn_8020D58C();
    fn_8020D8C0(base + base[0] * 0x784 + 4, box, b, a);
}

extern "C" int fn_801D3CE4(void* p, float a, float b);
extern "C" void* fn_801D72D4(void* p);
extern "C" void* lbl_804C3128[];
extern "C" void fn_80210A30(char* p, float* out);
extern "C" void fn_80210990(char* p, int side, float* out)
{
	float x = *(float*)(p + 0x54);
	float y = *(float*)(p + 0x58);
	out[0] = -16.0f * x;
	out[1] = -24.0f * y;
	out[2] = 16.0f * x;
	out[3] = 8.0f * y;
	switch (side) {
	case 0:
		out[2] = out[2] - x * 8.0f;
		break;
	case 1:
		out[0] = out[0] + x * 8.0f;
		break;
	case 2:
		out[3] = out[3] - y * 8.0f;
		break;
	case 3:
		out[1] = out[1] + y * 8.0f;
		break;
	}
}

extern "C" void fn_80210A30(char* p, float* out)
{
	float x = *(float*)(p + 0x54);
	float y = *(float*)(p + 0x58);
	out[0] = x * -16.0f;
	out[1] = y * -24.0f;
	out[2] = x * 16.0f;
	out[3] = y * 8.0f;
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

