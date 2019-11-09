#include "ShapeGroupFillStyle.h"

CShapeGroupFillStyle::CShapeGroupFillStyle(std::shared_ptr<const IShape> shapeGroup)
	: m_shapeGroup(std::move(shapeGroup))
{
}

std::optional<RGBAColor> CShapeGroupFillStyle::GetColor() const
{
	auto shapesCount = m_shapeGroup->GetShapesCount();

	if (shapesCount == 0)
	{
		return std::nullopt;
	}

	std::optional<RGBAColor> groupFillColor = m_shapeGroup->GetShapeAtIndex(0)->GetFillStyle()->GetColor();

	for (size_t i = 1; i < shapesCount; i++)
	{
		auto currentFillColor = m_shapeGroup->GetShapeAtIndex(i)->GetFillStyle()->GetColor();

		if (*currentFillColor != groupFillColor)
		{
			groupFillColor = std::nullopt;
			break;
		}
	}

	return groupFillColor;
}

void CShapeGroupFillStyle::SetColor(RGBAColor color)
{
	for (size_t i = 0; i < m_shapeGroup->GetShapesCount(); i++)
	{
		m_shapeGroup->GetShapeAtIndex(i)->GetFillStyle()->SetColor(color);
	}
}

std::optional<bool> CShapeGroupFillStyle::IsEnabled() const
{
	auto shapesCount = m_shapeGroup->GetShapesCount();

	if (shapesCount == 0)
	{
		return std::nullopt;
	}

	std::optional<bool> isGroupFillStyleEnabled = m_shapeGroup->GetShapeAtIndex(0)->GetFillStyle()->IsEnabled();

	for (size_t i = 1; i < shapesCount; i++)
	{
		auto isCurrentFillStyleEnabled = m_shapeGroup->GetShapeAtIndex(i)->GetFillStyle()->IsEnabled();

		if (*isCurrentFillStyleEnabled != isGroupFillStyleEnabled)
		{
			isGroupFillStyleEnabled = std::nullopt;
			break;
		}
	}

	return isGroupFillStyleEnabled;
}

void CShapeGroupFillStyle::SetEnabled(bool enable)
{
	for (size_t i = 0; i < m_shapeGroup->GetShapesCount(); i++)
	{
		m_shapeGroup->GetShapeAtIndex(i)->GetFillStyle()->SetEnabled(enable);
	}
}
