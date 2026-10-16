

extern "C" void fn_803721F4(void);
extern "C" void fn_803703C8(void* self);
extern "C" void fn_8022FE80(int, int, int, int, int);
extern "C" unsigned char fn_80388EEC(int);
extern "C" unsigned char fn_80230534(int);
extern "C" void fn_8022CA6C(int, int, int);
extern "C" void fn_8023077C(void);
extern "C" void fn_80458FF0(void*, int, int, int);
extern "C" void __dt__5ActorFv(void*, int);
extern "C" unsigned char __vt__4FGAL[];
extern void* lbl_8053AF80;
extern float lbl_80542E00;
extern float lbl_80542E04;
void operator delete(void* p);
extern "C" void fn_803704E8(void)
{
	fn_803721F4();
}

extern "C" void fn_803703C8(void*);
extern "C" void fn_80370C18(void* this_)
{
	char* p = (char*)this_;
	fn_803703C8(this_);
	fn_8022FE80(0, *(int*)(p + 4), *(int*)(p + 0x198), 1, 0);
	if (fn_80388EEC(0)) {
		*(int*)(p + 0x240) = 0x1e;
		*(int*)(p + 0x230) = 6;
		*(int*)(p + 0x23c) = 0;
	}
}

extern "C" void fn_803711F0(char* self)
{
	fn_803703C8(self);
	fn_8022FE80(0, *(int*)(self + 0x4), *(int*)(self + 0x198), 1, 0);
	if (fn_80388EEC(0) && fn_80230534(0)) {
		*(int*)(self + 0x230) = 3;
		*(int*)(self + 0x3a4) = -1;
		*(int*)(self + 0x3ac) = 3;
		*(char*)(self + 0x3a8) = 0;
		*(int*)(self + 0x3a0) = -1;
		fn_8022CA6C(0, 5, 0);
	}
}

