#pragma once
#include "IStyle.h"

using FillStyleEnumerator = std::function<void(StyleCallback)>;

class CGroupFillStyle : public IStyle
{
public:
	CGroupFillStyle(FillStyleEnumerator enumerator);

	std::optional<RGBAColor> GetColor() const final;
	void SetColor(RGBAColor color) final;

	std::optional<bool> IsEnabled() const final;
	void SetEnabled(bool enable) final;

private:
	FillStyleEnumerator m_enumerator;
};
