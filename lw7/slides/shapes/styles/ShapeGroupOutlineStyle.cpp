#include "ShapeGroupOutlineStyle.h"

CShapeGroupOutlineStyle::CShapeGroupOutlineStyle(std::shared_ptr<const IShape> shapeGroup)
	: m_shapeGroup(std::move(shapeGroup))
{
}

std::optional<RGBAColor> CShapeGroupOutlineStyle::GetColor() const
{
	auto shapesCount = m_shapeGroup->GetShapesCount();

	if (shapesCount == 0)
	{
		return std::nullopt;
	}

	std::optional<RGBAColor> groupOutlineColor = m_shapeGroup->GetShapeAtIndex(0)->GetOutlineStyle()->GetColor();

	for (size_t i = 1; i < shapesCount; i++)
	{
		auto currentOutlineColor = m_shapeGroup->GetShapeAtIndex(i)->GetOutlineStyle()->GetColor();

		if (*currentOutlineColor != *groupOutlineColor)
		{
			groupOutlineColor = std::nullopt;
			break;
		}
	}

	return groupOutlineColor;
}

void CShapeGroupOutlineStyle::SetColor(RGBAColor color)
{
	for (size_t i = 0; i < m_shapeGroup->GetShapesCount(); i++)
	{
		m_shapeGroup->GetShapeAtIndex(i)->GetOutlineStyle()->SetColor(color);
	}
}

std::optional<bool> CShapeGroupOutlineStyle::IsEnabled() const
{
	auto shapesCount = m_shapeGroup->GetShapesCount();

	if (shapesCount == 0)
	{
		return std::nullopt;
	}

	std::optional<bool> isGroupOutlineStyleEnabled = m_shapeGroup->GetShapeAtIndex(0)->GetOutlineStyle()->IsEnabled();

	for (size_t i = 1; i < shapesCount; i++)
	{
		auto isCurrentOutlineStyleEnabled = m_shapeGroup->GetShapeAtIndex(i)->GetOutlineStyle()->IsEnabled();

		if (*isCurrentOutlineStyleEnabled != *isGroupOutlineStyleEnabled)
		{
			isGroupOutlineStyleEnabled = std::nullopt;
			break;
		}
	}

	return isGroupOutlineStyleEnabled;
}

void CShapeGroupOutlineStyle::SetEnabled(bool enable)
{
	for (size_t i = 0; i < m_shapeGroup->GetShapesCount(); i++)
	{
		m_shapeGroup->GetShapeAtIndex(i)->GetOutlineStyle()->SetEnabled(enable);
	}
}

std::optional<double> CShapeGroupOutlineStyle::GetThickness() const
{
	auto shapesCount = m_shapeGroup->GetShapesCount();

	if (shapesCount == 0)
	{
		return std::nullopt;
	}

	std::optional<double> groupOutlineThikness = m_shapeGroup->GetShapeAtIndex(0)->GetOutlineStyle()->GetThickness();

	for (size_t i = 1; i < shapesCount; i++)
	{
		auto currentOutlineThikness = m_shapeGroup->GetShapeAtIndex(i)->GetOutlineStyle()->GetThickness();

		if (*currentOutlineThikness != *groupOutlineThikness)
		{
			groupOutlineThikness = std::nullopt;
			break;
		}
	}

	return groupOutlineThikness;
}

void CShapeGroupOutlineStyle::SetThickness(double thikness)
{
	for (size_t i = 0; i < m_shapeGroup->GetShapesCount(); i++)
	{
		m_shapeGroup->GetShapeAtIndex(i)->GetOutlineStyle()->SetThickness(thikness);
	}
}
