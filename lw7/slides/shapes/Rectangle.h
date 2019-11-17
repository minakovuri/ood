#pragma once
#include "SimpleShape.h"

class CRectangle : public CSimpleShape
{
public:
	CRectangle(const PointD& leftTop, const PointD& rightBottom);

	RectD GetFrame() override;
	void SetFrame(const RectD& rect) override;

protected:
	void DrawBehaviour(ICanvas& canvas) const override;

private:
	PointD m_leftTop;
	PointD m_rightBottom;
};
