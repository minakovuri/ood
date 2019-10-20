#pragma once
#include "../History.h"
#include "IImage.h"

class CImage : public IImage
{
public:
	CImage(CHistory& history, Path path, int width, int height);

	Path GetPath() const override;
	int GetWidth() const override;
	int GetHeight() const override;

	void Resize(int width, int height) override;

private:
	bool IsExtensionValid(Path path) const;

	Path m_path;
	int m_width;
	int m_height;
	CHistory& m_history;
};
