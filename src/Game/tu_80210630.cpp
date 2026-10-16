

extern "C" void fn_801D4F64(void);
extern "C" int fn_80210898(void)
{
	fn_801D4F64();
	return 0;
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

