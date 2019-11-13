#pragma once
#include "IOutlineStyle.h"

using OutlineStyleEnumerator = std::function<void(OutlineStyleCallback const &)>;

class CGroupOutlineStyle : public IOutlineStyle
{
public:
	CGroupOutlineStyle(OutlineStyleEnumerator& enumerator);

	std::optional<RGBAColor> GetColor() const final;
	void SetColor(RGBAColor color) final;

	std::optional<bool> IsEnabled() const final;
	void SetEnabled(bool enable) final;

	std::optional<double> GetThickness() const final;
	void SetThickness(double thikness) final;

private:
	OutlineStyleEnumerator& m_enumerator;
};