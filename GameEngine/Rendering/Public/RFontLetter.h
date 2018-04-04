#pragma once
#include "R2DRenderer.h"

enum class ERFontWeight
{
	DontCare = 0,
	Thin = 100,
	ExtraLight = 200,
	UltraLight = 200,
	Light = 300,
	Normal = 400,
	Regular = 400,
	Medium = 500,
	SemiBold = 600,
	DemiBold = 600,
	Bold = 700,
	ExtraBold = 800,
	UltraBold = 800,
	Heavy = 900
};

struct SRFontType
{
	SRFontType()
		: Size(30)
		, Family(L"ＭＳ Ｐゴシック")
		, Itaric(false)
		, Underline(false)
		, StrikeOut(false)
		, Weight(ERFontWeight::Normal)
	{
	}

	int Size;
	wstring Family;
	bool Itaric;
	bool Underline;
	bool StrikeOut;
	ERFontWeight Weight;
};

using CRRFontType = const SRFontType&;

class FRHITexture;
class FFontGenerator;

class FRFontLetter : public FR2DObject
{
private:
	unique_ptr<FRHITexture> Texture;
	Matrix WorldMatrix;
	int2 OriginPoint;
	int2 FontSize; // フォントピクセルのサイズ
	int2 FontRegion; // 余白を含めたサイズ
	int2 TextureSize;
	wchar_t Letter;
	bool IsBrank = false;

public:
	FRFontLetter(FRHIDevice* Device, FFontGenerator* FontGenerator, wchar_t Letter);

	void Render(FR2DRenderer* Renderer, int2 Position, float4 Color) const override;
	uint GetWidth() const override { return FontRegion.X; }
	uint GetHeight() const override { return FontRegion.Y; }
};

class FFontGenerator;

class FRFontSet
{
private:
	FRHIDevice* Device;
	unique_ptr<FFontGenerator> FontGenerator;
	SRFontType FontType;
	map<wchar_t, unique_ptr<FRFontLetter>> FontLetters;

public:
	FRFontSet(FRHIDevice* Device, CRRFontType FontType);
	~FRFontSet();

	FRFontLetter* GetFontLetter(wchar_t Letter);
	SRFontType GetFontType() const { return FontType; }
};

#define CompareAndReturn(A)	if (A < Right.A) return true; if (A > Right.A) return false;

struct SRFontTypeEx : public SRFontType
{
	SRFontTypeEx(SRFontType Base) : SRFontType(Base) {}

	bool operator < (const SRFontTypeEx& Right) const
	{
		CompareAndReturn(Size);
		CompareAndReturn(Weight);
		CompareAndReturn(Family);
		CompareAndReturn(Itaric);
		CompareAndReturn(Underline);
		CompareAndReturn(StrikeOut);
		return false;
	}
};

class FRFontManager
{
private:
	FRHIDevice* Device;
	map<SRFontTypeEx, unique_ptr<FRFontSet>> FontSets;

public:
	FRFontManager(FRHIDevice* Device)
		: Device(Device)
	{
	}

	FRFontSet* GetFontSet(CRRFontType FontType);
};