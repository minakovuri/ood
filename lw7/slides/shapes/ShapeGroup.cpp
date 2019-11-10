#include "ShapeGroup.h"

CShapeGroup::CShapeGroup()
	: m_fillStyle(shared_from_this())
	, m_outlineStyle(shared_from_this())
{
}

size_t CShapeGroup::GetShapesCount() const
{
	return size_t();
}

void CShapeGroup::InsertShape(std::shared_ptr<IShape> shape, size_t position)
{
}

std::shared_ptr<IShape> CShapeGroup::GetShapeAtIndex(size_t index) const
{
	return std::shared_ptr<IShape>();
}

void CShapeGroup::RemoveShapeAtIndex(size_t index)
{
}

RectD CShapeGroup::GetFrame()
{
	return RectD();
}

void CShapeGroup::SetFrame(const RectD& rect)
{
}

std::shared_ptr<IOutlineStyle> CShapeGroup::GetOutlineStyle()
{
	return std::shared_ptr<IOutlineStyle>();
}

std::shared_ptr<const IOutlineStyle> CShapeGroup::GetOutlineStyle() const
{
	return std::shared_ptr<const IOutlineStyle>();
}

std::shared_ptr<IStyle> CShapeGroup::GetFillStyle()
{
	return std::shared_ptr<IStyle>();
}

std::shared_ptr<const IStyle> CShapeGroup::GetFillStyle() const
{
	return std::shared_ptr<const IStyle>();
}
