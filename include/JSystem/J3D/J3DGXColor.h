#ifndef _JSYSTEM_J3D_J3DGXCOLOR_H
#define _JSYSTEM_J3D_J3DGXCOLOR_H

#include "types.h"
#include <dolphin/gx.h>

struct J3DGXColor : public GXColor {
	J3DGXColor() { }

	J3DGXColor(u8 _r, u8 _g, u8 _b, u8 _a)
	{
		r = _r;
		g = _g;
		b = _b;
		a = _a;
	}

	J3DGXColor(const J3DGXColor& other)
	{
#ifdef J3D_GX_COLOR_WORD_COPY
		*(u32*)this = *(const u32*)&other;
#else
		r = other.r;
		g = other.g;
		b = other.b;
		a = other.a;
	#endif
	}

	J3DGXColor(const GXColor& other)
	{
#ifdef J3D_GX_COLOR_WORD_COPY
		*(u32*)this = *(const u32*)&other;
#else
		r = other.r;
		g = other.g;
		b = other.b;
		a = other.a;
	#endif
	}

	J3DGXColor(const u32& other)
	{
#ifdef J3D_GX_COLOR_WORD_COPY
		*(u32*)this = other;
#else
		GXColor* otherBytes = (GXColor*)&other;
		r                   = otherBytes->r;
		g                   = otherBytes->g;
		b                   = otherBytes->b;
		a                   = otherBytes->a;
	#endif
	}

	J3DGXColor& operator=(const GXColor& color)
	{
		*(GXColor*)this = color;
		return *this;
	}

	/** @fabricated */
	const u8* asBytes() const { return (u8*)this; }
};

struct J3DGXColorS10 : public GXColorS10 {
	J3DGXColorS10() { }

	J3DGXColorS10(u16 _r, u16 _g, u16 _b, u16 _a)
	{
		r = _r;
		g = _g;
		b = _b;
		a = _a;
	}

	J3DGXColorS10(f32 _r, f32 _g, f32 _b, u16 _a)
	{
		r = _r;
		g = _g;
		b = _b;
		a = _a;
	}

	J3DGXColorS10(const J3DGXColorS10& other)
	{
#ifdef J3D_GX_COLOR_WORD_COPY
		*(u64*)this = *(const u64*)&other;
#else
		*this = other;
	#endif
	}

	J3DGXColorS10(const GXColorS10& other)
	{
#ifdef J3D_GX_COLOR_WORD_COPY
		*(u64*)this = *(const u64*)&other;
#else
		r = other.r;
		g = other.g;
		b = other.b;
		a = other.a;
	#endif
	}

	J3DGXColorS10(const u64& other)
	{
#ifdef J3D_GX_COLOR_WORD_COPY
		*(u64*)this = *(const u64*)&other;
#else
		GXColorS10* otherBytes = (GXColorS10*)&other;
		r                      = otherBytes->r;
		g                      = otherBytes->g;
		b                      = otherBytes->b;
		a                      = otherBytes->a;
	#endif
	}

	J3DGXColorS10& operator=(const GXColorS10& color)
	{
		*(GXColorS10*)this = color;
		return *this;
	}
};

#endif
