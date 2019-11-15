#include "GroupOutlineStyle.h"

CGroupOutlineStyle::CGroupOutlineStyle(OutlineStyleEnumerator enumerator)
	: m_enumerator(std::move(enumerator))
{
}

std::optional<RGBAColor> CGroupOutlineStyle::GetColor() const
{
	std::optional<RGBAColor> color;

	m_enumerator([&](IOutlineStyle& style) {
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

void CGroupOutlineStyle::SetColor(RGBAColor color)
{
	m_enumerator([&](IOutlineStyle& style) {
		style.SetColor(color);
	});
}

std::optional<bool> CGroupOutlineStyle::IsEnabled() const
{
	std::optional<bool> isEnabled;

	m_enumerator([&](IOutlineStyle& style) {
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

void CGroupOutlineStyle::SetEnabled(bool enable)
{
	m_enumerator([&](IOutlineStyle& style) {
		style.SetEnabled(enable);
	});
}

std::optional<double> CGroupOutlineStyle::GetThickness() const
{
	std::optional<double> thickness;

	m_enumerator([&](IOutlineStyle& style) {
		if (!thickness)
		{
			thickness = style.GetThickness();
		}
		else if (thickness != style.GetThickness())
		{
			thickness = std::nullopt;
		}
	});

	return thickness;
}

void CGroupOutlineStyle::SetThickness(double thikness)
{
	m_enumerator([&](IOutlineStyle& style) {
		style.SetThickness(thikness);
	});
}
