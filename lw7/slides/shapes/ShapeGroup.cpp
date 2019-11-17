#include "ShapeGroup.h"
#include "styles/GroupFillStyle.h"
#include "styles/GroupOutlineStyle.h"
#include <algorithm>
#include <stdexcept>

CShapeGroup::CShapeGroup()
{
	FillStyleEnumerator fsEnumerator = [this](StyleCallback func) {
		for (auto&& shape : m_shapes)
		{
			func(*shape->GetFillStyle());
		}
	};
	m_fillStyle = std::make_shared<CGroupFillStyle>(fsEnumerator);

	OutlineStyleEnumerator osEnumerator = [this](OutlineStyleCallback func) {
		for (auto&& shape : m_shapes)
		{
			func(*shape->GetOutlineStyle());
		}
	};
	m_outlineStyle = std::make_shared<CGroupOutlineStyle>(osEnumerator);

	const auto _ = std::shared_ptr<CShapeGroup>(this, [](CShapeGroup*) {});
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
	if (m_shapes.empty())
	{
		return RectD{ 0, 0, 0, 0 };
	}

	auto firstShapeFrame = m_shapes[0]->GetFrame();

	double minX = firstShapeFrame.left;
	double minY = firstShapeFrame.top;
	double maxX = firstShapeFrame.left + firstShapeFrame.width;
	double maxY = firstShapeFrame.top + firstShapeFrame.height;

	for (auto&& shape : m_shapes)
	{
		auto shapeFrame = shape->GetFrame();

		minX = std::min(minX, shapeFrame.left);
		minY = std::min(minY, shapeFrame.top);

		maxX = std::max(maxX, shapeFrame.left + shapeFrame.width);
		maxY = std::max(maxY, shapeFrame.top + shapeFrame.height);
	}

	return RectD{ minX, minY, maxX - minX, maxY - minY };
}

void CShapeGroup::SetFrame(const RectD& rect)
{
	auto currentGroupFrame = GetFrame();

	for (auto&& shape : m_shapes)
	{
		auto shapeFrame = shape->GetFrame();

		double newShapeLeft = rect.left + (shapeFrame.left - currentGroupFrame.left) / currentGroupFrame.width * rect.width;
		double newShapeTop = rect.top + (shapeFrame.top - currentGroupFrame.top) / currentGroupFrame.height * rect.height;
		double newShapeWidth = shapeFrame.width / currentGroupFrame.width * rect.width;
		double newShapeHeight = shapeFrame.height / currentGroupFrame.height * rect.height;

		auto newShapeFrame = RectD{ newShapeLeft, newShapeTop, newShapeWidth, newShapeHeight };
		shape->SetFrame(newShapeFrame);
	}
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

std::shared_ptr<IShapeGroup> CShapeGroup::TryGetGroup()
{
	return shared_from_this();
}

std::shared_ptr<const IShapeGroup> CShapeGroup::TryGetGroup() const
{
	return shared_from_this();
}

void CShapeGroup::Draw(ICanvas& canvas)
{
}
