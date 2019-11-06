#include "SimpleShapeOutlineStyle.h"

const RGBAColor DEFAULT_COLOR = 0x000000;

CSimpleShapeOutlineStyle::CSimpleShapeOutlineStyle()
	: m_color(DEFAULT_COLOR)
	, m_isEnabled(true)
	, m_thickness(1.0)
{
}

CSimpleShapeOutlineStyle::CSimpleShapeOutlineStyle(RGBAColor color, bool isEnabled, double thickness)
	: m_color(color)
	, m_isEnabled(isEnabled)
	, m_thickness(thickness)
{
}

std::optional<RGBAColor> CSimpleShapeOutlineStyle::GetColor() const
{
	return m_color;
}

void CSimpleShapeOutlineStyle::SetColor(RGBAColor color)
{
	m_color = color;
}

std::optional<bool> CSimpleShapeOutlineStyle::IsEnabled() const
{
	return m_isEnabled;
}

void CSimpleShapeOutlineStyle::SetEnabled(bool enable)
{
	m_isEnabled = enable;
}

std::optional<double> CSimpleShapeOutlineStyle::GetThickness() const
{
	return m_thickness;
}

void CSimpleShapeOutlineStyle::SetThickness(double thikness)
{
	m_thickness = thikness;
}
