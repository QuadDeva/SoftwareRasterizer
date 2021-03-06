#pragma once

class Vector2;

/* 
* RenderTarget Reference:
	https://en.wikipedia.org/wiki/Render_Target,
	http://blog.naver.com/fish19/120045605984
*/
class RenderTarget
{
public:
	RenderTarget(UINT InHeight, UINT InWidth);
	RenderTarget(const RenderTarget& InTarget);
	RenderTarget(RenderTarget&& InTarget);
	~RenderTarget();

	inline UINT GetWidth() const { return Width; }
	inline UINT GetHeight() const { return Height; }

	DWORD GetPixel(UINT PixelIndex) const;
	DWORD GetPixel(UINT InX, UINT InY) const;
	DWORD GetPixel(const Vector2& InPosition) const;

	void SetPixel(UINT PixelIndex, DWORD Color);
	void SetPixel(UINT InX, UINT InY, DWORD Color);
	void SetPixel(const Vector2& InPosition, DWORD Color);

	inline HBITMAP GetBitmap() const { return Bitmap; }

	void Clear(DWORD Color);

private:
	void InitBitmap();

private:
	UINT Width;
	UINT Height;
	UINT Size;
	HBITMAP Bitmap;

public:
	DWORD* BitmapBits;

};