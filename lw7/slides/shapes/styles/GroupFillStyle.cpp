#include "GroupFillStyle.h"

CGroupFillStyle::CGroupFillStyle(FillStyleEnumerator enumerator)
	: m_enumerator(std::move(enumerator))
{
}

std::optional<RGBAColor> CGroupFillStyle::GetColor() const
{
	std::optional<RGBAColor> color = std::nullopt;
	bool isInit = false;

	m_enumerator([&](IStyle& style) {
		if (!isInit)
		{
			color = style.GetColor();
			isInit = true;
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
	std::optional<bool> isEnabled = std::nullopt;
	bool isInit = false;

	m_enumerator([&](IStyle& style) {
		if (!isInit)
		{
			isEnabled = style.IsEnabled();
			isInit = true;
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
