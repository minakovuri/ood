#pragma once
#include "IStyle.h"
#include "../IShape.h"

class CShapeGroupFillStyle : public IStyle
{
public:
	CShapeGroupFillStyle(std::shared_ptr<const IShape> shapeGroup);

	std::optional<RGBAColor> GetColor() const final;
	void SetColor(RGBAColor color) final;

	std::optional<bool> IsEnabled() const final;
	void SetEnabled(bool enable) final;

private:
	std::shared_ptr<const IShape> m_shapeGroup;
};