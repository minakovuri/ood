#include "OutlineStyle.h"
#include "../../Colors.h"

COutlineStyle::COutlineStyle()
	: m_color(Colors::Black)
	, m_isEnabled(true)
	, m_thickness(1.0)
{
}

COutlineStyle::COutlineStyle(RGBAColor color, bool isEnabled, double thickness)
	: m_color(color)
	, m_isEnabled(isEnabled)
	, m_thickness(thickness)
{
}

std::optional<RGBAColor> COutlineStyle::GetColor() const
{
	return m_color;	
}

void COutlineStyle::SetColor(RGBAColor color)
{
	m_color = color;
}

std::optional<bool> COutlineStyle::IsEnabled() const
{
	return m_isEnabled;
}

void COutlineStyle::SetEnabled(bool enable)
{
	m_isEnabled = enable;
}

std::optional<double> COutlineStyle::GetThickness() const
{
	return m_thickness;
}

void COutlineStyle::SetThickness(double thikness)
{
	m_thickness = thikness;
}
