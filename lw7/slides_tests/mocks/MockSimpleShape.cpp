#include "MockSimpleShape.h"

CMockSimpleShape::CMockSimpleShape(const RectD& frame)
	: m_frame(frame)
{
}

RectD CMockSimpleShape::GetFrame()
{
	return m_frame;
}

void CMockSimpleShape::SetFrame(const RectD& rect)
{
	m_frame = rect;
}

void CMockSimpleShape::DrawBehaviour(const ICanvas& canvas) const
{
}
