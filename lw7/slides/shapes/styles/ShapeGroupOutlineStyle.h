#pragma once
#include "../IShape.h"
#include "IOutlineStyle.h"

class CShapeGroupOutlineStyle : public IOutlineStyle
{
public:
	CShapeGroupOutlineStyle(std::shared_ptr<const IShape> shapeGroup);

	std::optional<RGBAColor> GetColor() const final;
	void SetColor(RGBAColor color) final;

	std::optional<bool> IsEnabled() const final;
	void SetEnabled(bool enable) final;

	std::optional<double> GetThickness() const final;
	void SetThickness(double thikness) final;

private:
	std::shared_ptr<const IShape> m_shapeGroup;
};