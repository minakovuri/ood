#pragma once
#include "IOutlineStyle.h"

// TODO: как вариант - вынести геттеры и сеттеры color и enable в базовый класс, реализующий IStyle
class COutlineStyle : public IOutlineStyle
{
public:
	COutlineStyle();
	COutlineStyle(RGBAColor color, bool isEnabled, double thickness);

	std::optional<RGBAColor> GetColor() const final;
	void SetColor(RGBAColor color) final;

	std::optional<bool> IsEnabled() const final;
	void SetEnabled(bool enable) final;

	std::optional<double> GetThickness() const final;
	void SetThickness(double thikness) final;

private:
	RGBAColor m_color;
	bool m_isEnabled;
	double m_thickness;
};
