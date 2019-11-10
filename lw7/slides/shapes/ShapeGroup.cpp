#include "ShapeGroup.h"
#include "styles/ShapeGroupFillStyle.h"
#include "styles/ShapeGroupOutlineStyle.h"
#include <stdexcept>

CShapeGroup::CShapeGroup()
{
	// TODO: прочитать информацию по ссылке
	auto wptr = std::shared_ptr<CShapeGroup>(this, [](CShapeGroup*) {});

	m_fillStyle = std::make_shared<CShapeGroupFillStyle>(shared_from_this());
	m_outlineStyle = std::make_shared<CShapeGroupOutlineStyle>(shared_from_this());
}

size_t CShapeGroup::GetShapesCount() const
{
	return m_shapes.size();
}

void CShapeGroup::InsertShape(std::shared_ptr<IShape> shape, size_t position)
{
	if (position == std::numeric_limits<size_t>::max())
	{
		m_shapes.push_back(shape);
	}
	else if (position > GetShapesCount() - 1)
	{
		throw std::out_of_range("requested index is out of range");
	}
	else
	{
		m_shapes.insert(m_shapes.begin() + position, shape);
	}
}

std::shared_ptr<IShape> CShapeGroup::GetShapeAtIndex(size_t index) const
{
	return m_shapes.at(index);
}

void CShapeGroup::RemoveShapeAtIndex(size_t index)
{
	if (index > GetShapesCount() - 1)
	{
		throw std::out_of_range("requested index is out of range");
	}

	m_shapes.erase(m_shapes.begin() + index);
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
	return m_outlineStyle;
}

std::shared_ptr<const IOutlineStyle> CShapeGroup::GetOutlineStyle() const
{
	return m_outlineStyle;
}

std::shared_ptr<IStyle> CShapeGroup::GetFillStyle()
{
	return m_fillStyle;
}

std::shared_ptr<const IStyle> CShapeGroup::GetFillStyle() const
{
	return m_fillStyle;
}
