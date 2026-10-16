

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

extern "C" void fn_80370508(char* self)
{
	struct VObj { virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(int, int); };
	fn_803703C8(self);
	int state = *(int*)(self + 0x240);
	if (state != 0) {
		if (state == 1) {
			*(int*)(self + 0x368) = 0x104;
		}
	} else if (*(float*)(self + 0x328) < lbl_80542E00) {
		*(float*)(self + 0x328) = *(float*)(self + 0x328) + lbl_80542E04;
	} else {
		fn_80230534(0);
		*(int*)(self + 0x230) = 0xb;
		((VObj*)self)->v10(0xff, 1);
	}
}

extern "C" void fn_803706AC(char* self)
{
	fn_803703C8(self);
	fn_8023077C();
	fn_8022FE80(0, *(int*)(self + 0x4), *(int*)(self + 0x198), 1, 0);
	if (fn_80388EEC(0)) {
		int n = *(int*)(self + 0x394);
		if (n >= 4) {
			if (n == 4) {
				*(int*)(self + 0x230) = 9;
				*(int*)(self + 0x368) = 0x106;
			} else {
				*(int*)(self + 0x230) = 10;
				*(int*)(self + 0x368) = 0x104;
			}
			fn_80458FF0(lbl_8053AF80, 0x100000b, 0, 0);
		} else {
			*(int*)(self + 0x230) = 6;
			*(int*)(self + 0x240) = 0x1e;
		}
	}
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

extern "C" void* fn_80372AA0(void* self, short flag)
{
	if (self) {
		*(void**)self = __vt__4FGAL;
		__dt__5ActorFv(self, 0);
		if (flag > 0) {
			operator delete(self);
		}
	}
	return self;
}

