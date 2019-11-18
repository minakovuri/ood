#include "GroupOutlineStyle.h"

CGroupOutlineStyle::CGroupOutlineStyle(OutlineStyleEnumerator enumerator)
	: m_enumerator(std::move(enumerator))
{
}

std::optional<RGBAColor> CGroupOutlineStyle::GetColor() const
{
	std::optional<RGBAColor> color = std::nullopt;
	bool isInit = false;

	m_enumerator([&](IOutlineStyle& style) {
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

void CGroupOutlineStyle::SetColor(RGBAColor color)
{
	m_enumerator([&](IOutlineStyle& style) {
		style.SetColor(color);
	});
}

std::optional<bool> CGroupOutlineStyle::IsEnabled() const
{
	std::optional<bool> isEnabled = std::nullopt;
	bool isInit = false;

	m_enumerator([&](IOutlineStyle& style) {
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

void CGroupOutlineStyle::SetEnabled(bool enable)
{
	m_enumerator([&](IOutlineStyle& style) {
		style.SetEnabled(enable);
	});
}

std::optional<double> CGroupOutlineStyle::GetThickness() const
{
	std::optional<double> thickness = std::nullopt;
	bool isInit = false;

	m_enumerator([&](IOutlineStyle& style) {
		if (!isInit)
		{
			thickness = style.GetThickness();
			isInit = true;
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
