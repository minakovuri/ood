#pragma once
#include "IStyle.h"

// TODO: ��� ������� - ������� ������� � ������� color � enable � ������� �����, ����������� IStyle
class CSimpleShapeFillStyle : public IStyle
{
public:
	CSimpleShapeFillStyle();
	CSimpleShapeFillStyle(RGBAColor color, bool isEnabled);

	std::optional<RGBAColor> GetColor() const final;
	void SetColor(RGBAColor color) final;

	std::optional<bool> IsEnabled() const final;
	void SetEnabled(bool enable) final;

private:
	RGBAColor m_color;
	bool m_isEnabled;
};