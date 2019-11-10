#include <stdexcept>
#include "SimpleShape.h"
#include "styles/SimpleShapeFillStyle.h"
#include "styles/SimpleShapeOutlineStyle.h"
#include "styles/Colors.h"

size_t CSimpleShape::GetShapesCount() const
{
	throw std::runtime_error("GetShapesCount() is unsupported for simple shape");
}

void CSimpleShape::InsertShape(std::shared_ptr<IShape> shape, size_t position)
{
	throw std::runtime_error("InsertShape() is unsupported for simple shape");
}

std::shared_ptr<IShape> CSimpleShape::GetShapeAtIndex(size_t index) const
{
	throw std::runtime_error("GetShapeAtIndex() is unsupported for simple shape");
}

void CSimpleShape::RemoveShapeAtIndex(size_t index)
{
	throw std::runtime_error("RemoveShapeAtIndex() is unsupported for simple shape");
}

CSimpleShape::CSimpleShape(const RectD& frame)
	: m_frame(frame)
	, m_outlineStyle(std::make_shared<CSimpleShapeOutlineStyle>(true, Colors::Black, 1))
	, m_fillStyle(std::make_shared<CSimpleShapeFillStyle>(true, Colors::White))
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
