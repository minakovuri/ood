#include "SimpleShape.h"
#include "styles/Colors.h"
#include "styles/FillStyle.h"
#include "styles/OutlineStyle.h"

CSimpleShape::CSimpleShape(const RectD& frame)
	: m_frame(frame)
	, m_outlineStyle(std::make_shared<COutlineStyle>(true, Colors::Black, 1))
	, m_fillStyle(std::make_shared<CFillStyle>(true, Colors::White))
{
}

RectD CSimpleShape::GetFrame()
{
	return m_frame;
}

void CSimpleShape::SetFrame(const RectD& rect)
{
	m_frame = rect;
}

std::shared_ptr<IOutlineStyle> CSimpleShape::GetOutlineStyle()
{
	return m_outlineStyle;
}

std::shared_ptr<const IOutlineStyle> CSimpleShape::GetOutlineStyle() const
{
	return m_outlineStyle;
}

std::shared_ptr<IStyle> CSimpleShape::GetFillStyle()
{
	return m_fillStyle;
}

std::shared_ptr<const IStyle> CSimpleShape::GetFillStyle() const
{
	return m_fillStyle;
}

std::shared_ptr<IShapeGroup> CSimpleShape::TryGetGroup()
{
	return std::shared_ptr<IShapeGroup>();
}

std::shared_ptr<const IShapeGroup> CSimpleShape::TryGetGroup() const
{
	return std::shared_ptr<const IShapeGroup>();
}

void CSimpleShape::Draw(const ICanvas& canvas)
{
}
