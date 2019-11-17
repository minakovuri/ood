#pragma once
#include "SimpleShape.h"

class CEllipse : public CSimpleShape
{
public:
	CEllipse(const PointD& center, double horizontalRadius, double verticalRadius);

	RectD GetFrame() override;
	void SetFrame(const RectD& rect) override;

protected:
	void DrawBehaviour(ICanvas& canvas) const override;

private:
	PointD m_center;
	double m_horizontalRadius;
	double m_verticalRadius;
};
