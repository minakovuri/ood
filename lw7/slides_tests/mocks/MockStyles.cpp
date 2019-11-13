#include "MockStyles.h"

CMockStyle::CMockStyle(RGBAColor color, bool isEnabled)
	: m_color(color)
	, m_isEnabled(isEnabled)
{
}

std::optional<RGBAColor> CMockStyle::GetColor() const
{
	return m_color;
}

void CMockStyle::SetColor(RGBAColor color)
{
	m_color = color;
}

std::optional<bool> CMockStyle::IsEnabled() const
{
	return m_isEnabled;
}

void CMockStyle::SetEnabled(bool enable)
{
	m_isEnabled = enable;
}

CMockOutlineStyle::CMockOutlineStyle(RGBAColor color, bool isEnabled, double thickness)
	: m_color(color)
	, m_isEnabled(isEnabled)
	, m_thickness(thickness)
{
}

std::optional<RGBAColor> CMockOutlineStyle::GetColor() const
{
	return m_color;
}

void CMockOutlineStyle::SetColor(RGBAColor color)
{
	m_color = color;
}

std::optional<bool> CMockOutlineStyle::IsEnabled() const
{
	return m_isEnabled;
}

void CMockOutlineStyle::SetEnabled(bool enable)
{
	m_isEnabled = enable;
}

std::optional<double> CMockOutlineStyle::GetThickness() const
{
	return m_thickness;
}

void CMockOutlineStyle::SetThickness(double thikness)
{
	m_thickness = thikness;
}
