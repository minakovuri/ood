#pragma once
#include "../../slides/shapes/SimpleShape.h"

class CMockSimpleShape : public CSimpleShape
{
public:
	CMockSimpleShape(const RectD& frame);

	RectD GetFrame() final;
	void SetFrame(const RectD& rect) final;

protected:
	void DrawBehaviour(ICanvas& canvas) const final;

private:
	RectD m_frame;
};