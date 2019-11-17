#pragma once
#include "../CommonTypes.h"

class ICanvas
{
public:
	virtual void DrawLine(const PointD& startPoint, const PointD& endPoint) = 0;
	virtual void DrawEllipse(const PointD& leftTop, double width, double height) = 0;
	virtual void SetFillColor(RGBAColor color) = 0;
	virtual void SetLineColor(RGBAColor color) = 0;
	virtual void SetLineThikness(double thikness) = 0;

	virtual ~ICanvas() = default;
};