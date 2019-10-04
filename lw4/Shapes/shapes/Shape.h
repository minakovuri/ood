#pragma once
#include "../Color.h"
#include "../canvas/ICanvas.h"

class CShape
{
public:
	CShape() = default;

	Color GetColor() const;

	virtual void Draw(ICanvas& canvas) const = 0;

protected:
	CShape(Color color);

private:
	Color m_color;
};
