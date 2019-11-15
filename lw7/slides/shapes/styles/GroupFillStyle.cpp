#include "GroupFillStyle.h"

CGroupFillStyle::CGroupFillStyle(FillStyleEnumerator enumerator)
	: m_enumerator(std::move(enumerator))
{
}

std::optional<RGBAColor> CGroupFillStyle::GetColor() const
{
	std::optional<RGBAColor> color;

	m_enumerator([&](IStyle& style) {
		if (!color)
		{
			color = style.GetColor();
		}
		else if (color != style.GetColor())
		{
			color = std::nullopt;
		}
	});

	return color;
}

void CGroupFillStyle::SetColor(RGBAColor color)
{
	m_enumerator([&](IStyle& style) {
		style.SetColor(color);
	});
}

std::optional<bool> CGroupFillStyle::IsEnabled() const
{
	std::optional<bool> isEnabled;

	m_enumerator([&](IStyle& style) {
		if (!isEnabled)
		{
			isEnabled = style.IsEnabled();
		}
		else if (isEnabled != style.IsEnabled())
		{
			isEnabled = std::nullopt;
		}
	});

	return isEnabled;
}

void CGroupFillStyle::SetEnabled(bool enable)
{
	m_enumerator([&](IStyle& style) {
		style.SetEnabled(enable);
	});
}
