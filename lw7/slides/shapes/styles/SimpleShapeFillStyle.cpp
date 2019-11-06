#include "SimpleShapeFillStyle.h"

const RGBAColor DEFAULT_COLOR = 0xFFFFFF;

CSimpleShapeFillStyle::CSimpleShapeFillStyle()
	: m_color(DEFAULT_COLOR)
	, m_isEnabled(false)
{
}

CSimpleShapeFillStyle::CSimpleShapeFillStyle(RGBAColor color, bool isEnabled)
	: m_color(color)
	, m_isEnabled(isEnabled)
{
}

std::optional<RGBAColor> CSimpleShapeFillStyle::GetColor() const
{
	return m_color;
}

void CSimpleShapeFillStyle::SetColor(RGBAColor color)
{
	m_color = color;
}

std::optional<bool> CSimpleShapeFillStyle::IsEnabled() const
{
	return m_isEnabled;
}

void CSimpleShapeFillStyle::SetEnabled(bool enable)
{
	m_isEnabled = enable;
}
