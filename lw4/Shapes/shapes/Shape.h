#pragma once
#include "../Color.h"
#include "../canvas/ICanvas.h"

class CShape
{
public:
	void Draw(ICanvas& canvas);
	Color GetColor() const;

private:
	Color m_color;
};
