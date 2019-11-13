#include "FillStyle.h"

const RGBAColor DEFAULT_COLOR = 0xFFFFFF;

CFillStyle::CFillStyle()
	: m_color(DEFAULT_COLOR)
	, m_isEnabled(false)
{
}

CFillStyle::CFillStyle(RGBAColor color, bool isEnabled)
	: m_color(color)
	, m_isEnabled(isEnabled)
{
}

std::optional<RGBAColor> CFillStyle::GetColor() const
{
	return m_color;
}

void CFillStyle::SetColor(RGBAColor color)
{
	m_color = color;
}

std::optional<bool> CFillStyle::IsEnabled() const
{
	return m_isEnabled;
}

void CFillStyle::SetEnabled(bool enable)
{
	m_isEnabled = enable;
}
