#pragma once
#include "../../slides/shapes/styles/IOutlineStyle.h"
#include "../Colors.h"

class CMockStyle : public IStyle
{
public:
	CMockStyle(RGBAColor color, bool isEnabled);

	std::optional<RGBAColor> GetColor() const final;
	void SetColor(RGBAColor color) final;
	std::optional<bool> IsEnabled() const final;
	void SetEnabled(bool enable) final;

private:
	RGBAColor m_color;
	bool m_isEnabled;
};

class CMockOutlineStyle : public IOutlineStyle
{
public:
	CMockOutlineStyle(RGBAColor color, bool isEnabled, double thickness);

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