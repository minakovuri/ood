#include <stdexcept>
#include "SimpleShape.h"

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
{
}

CSimpleShape::CSimpleShape(const RectD& frame, std::shared_ptr<IStyle> outlineStyle)
	: m_frame(frame)
	, m_outlineStyle(std::move(outlineStyle))
{
}

CSimpleShape::CSimpleShape(const RectD& frame, std::shared_ptr<IStyle> outlineStyle, std::shared_ptr<IStyle> fillStyle)
	: m_frame(frame)
	, m_outlineStyle(std::move(outlineStyle))
	, m_fillStyle(std::move(fillStyle))
{
}

/*CSimpleShape::CSimpleShape(const RectD& frame, std::shared_ptr<IStyle> outlineStyle, std::shared_ptr<IStyle> fillStyle, std::shared_ptr<IShape> group)
	: m_frame(frame)
	, m_outlineStyle(std::move(outlineStyle))
	, m_fillStyle(std::move(fillStyle))
	, m_group(std::move(group))
{
}*/

RectD CSimpleShape::GetFrame()
{
	return RectD();
}

void CSimpleShape::SetFrame(const RectD& rect)
{
}

std::shared_ptr<IOutlineStyle> CSimpleShape::GetOutlineStyle()
{
	return std::shared_ptr<IOutlineStyle>();
}

std::shared_ptr<const IOutlineStyle> CSimpleShape::GetOutlineStyle() const
{
	return std::shared_ptr<const IOutlineStyle>();
}

std::shared_ptr<IStyle> CSimpleShape::GetFillStyle()
{
	return std::shared_ptr<IStyle>();
}

std::shared_ptr<const IStyle> CSimpleShape::GetFillStyle() const
{
	return std::shared_ptr<const IStyle>();
}
