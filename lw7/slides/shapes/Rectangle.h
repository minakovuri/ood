#pragma once
#include "Point.h"
#include "SimpleShape.h"

class CRectangle : public CSimpleShape
{
public:
	CRectangle(const SPoint& leftTop, const SPoint& rightBottom);

	RectD GetFrame() override;
	void SetFrame(const RectD& rect) override;

protected:
	void DrawBehaviour(const ICanvas& canvas) const override;

private:
	SPoint m_leftTop;
	SPoint m_rightBottom;
};
