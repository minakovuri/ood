#pragma once
#include "Point.h"
#include "SimpleShape.h"

class CEllipse : public CSimpleShape
{
public:
	CEllipse(const SPoint& center, double horizontalRadius, double verticalRadius);

	RectD GetFrame() override;
	void SetFrame(const RectD& rect) override;

protected:
	void DrawBehaviour(const ICanvas& canvas) const override;

private:
	SPoint m_center;
	double m_horizontalRadius;
	double m_verticalRadius;
};
