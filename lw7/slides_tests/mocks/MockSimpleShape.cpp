#include "MockSimpleShape.h"

CMockSimpleShape::CMockSimpleShape(const RectD& frame)
	: m_frame(frame)
{
}

std::optional<RectD> CMockSimpleShape::GetFrame()
{
	return m_frame;
}

void CMockSimpleShape::SetFrame(const RectD& rect)
{
	m_frame = rect;
}

void CMockSimpleShape::DrawBehaviour(ICanvas& canvas) const
{
	auto leftTop = PointD{ m_frame.left, m_frame.top };
	auto rightBottom = PointD{ m_frame.left + m_frame.width, m_frame.top + m_frame.height };

	canvas.DrawLine(leftTop, rightBottom);
}
