// TU 0x8045560C-0x80455CA4: rupee-number popup pictures ("kk_rupyNum_XX.bti").
// A pool of 128 floating digit sprites drawn with 11 J2DPictures (digits 0-9
// and "!"). The singleton pointer lives in .sbss (lbl_8053AF50) and is used by
// scre.cpp.
#include "types.h"
#include "JSystem/J2D/J2DPicture.h"
#include "JSystem/JUtility/TColor.h"

extern "C" ResTIMG* fn_804030C4(u32 type, const char* name);
extern "C" void fn_8013B490(void* obj);
extern "C" void fn_8030C5F0(void* obj, int p2, int p3, int p4, f32* outPos);
extern "C" void* lbl_8053AB10;

class RupyNum;
extern "C" RupyNum* lbl_8053AF50;

class RupyNum {
public:
	struct Elem {
		f32 mX;
		f32 mY;
		f32 mScale;
		JUtility::TColor mColor;
		u8 mDigit;
		u8 mActive;
	};

	RupyNum();
	virtual ~RupyNum();
	void reset();
	void draw();
	void add(u8 digit, int p2, f32 scale, JUtility::TColor color);

	J2DPicture* mPics[11];
	Elem mElems[128];
};

static const char* sTexNames[11] = {
	"kk_rupyNum_00.bti",
	"kk_rupyNum_01.bti",
	"kk_rupyNum_02.bti",
	"kk_rupyNum_03.bti",
	"kk_rupyNum_04.bti",
	"kk_rupyNum_05.bti",
	"kk_rupyNum_06.bti",
	"kk_rupyNum_07.bti",
	"kk_rupyNum_08.bti",
	"kk_rupyNum_09.bti",
	"rupy_num_exclamation.bti",
};

void RupyNum::reset() {
	for (int i = 0; i < 128; i++) {
		mElems[i].mActive = 0;
	}
}

void RupyNum::draw() {
	fn_8013B490(lbl_8053AB10);
	for (int i = 0; i < 128; i++) {
		Elem* e = &mElems[i];
		if (e->mActive == 1) {
			mPics[e->mDigit]->setWhite(e->mColor);
			mPics[e->mDigit]->draw(e->mX, e->mY, e->mScale, e->mScale, false, false, false);
		}
	}
}

void RupyNum::add(u8 digit, int p2, f32 scale, JUtility::TColor color) {
	char* obj = *(char**)((char*)lbl_8053AB10 + 0x24);
	f32 pos[2];
	f32 mul = 48.0f * *(f32*)(obj + 0x858);
	fn_8030C5F0(obj, p2, 0, 0, pos);
	for (int i = 0; i < 128; i++) {
		if (mElems[i].mActive == 0) {
			mElems[i].mActive = 1;
			mElems[i].mDigit = digit;
			mElems[i].mScale = scale * mul;
			mElems[i].mX = pos[0] - mElems[i].mScale / 2.0f;
			mElems[i].mY = pos[1] - mElems[i].mScale / 2.0f;
			mElems[i].mColor.set(color);
			return;
		}
	}
}

RupyNum::~RupyNum() {
	for (int i = 0; i < 11; i++) {
		delete mPics[i];
		mPics[i] = NULL;
	}
	lbl_8053AF50 = NULL;
}

RupyNum::RupyNum() {
	const ResTIMG* img;
	for (int i = 0; i < 11; i++) {
		img = fn_804030C4('TIMG', sTexNames[i]);
		mPics[i] = new J2DPicture(img);
	}
	reset();
	lbl_8053AF50 = this;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
