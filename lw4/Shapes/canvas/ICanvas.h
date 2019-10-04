#pragma once
#include "../Color.h"
#include "../Point.h"

class ICanvas
{
public:
	virtual void SetColor(Color color) = 0;
	virtual void DrawLine(Point from, Point to) = 0;
	virtual void DrawEllipse(Point center, double horizontalRadius, double verticalRadius) = 0;

	virtual ~ICanvas() = default;
};
