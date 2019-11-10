#pragma once
#include "../IShape.h"
#include "IStyle.h"

class CShapeGroupFillStyle : public IStyle
{
public:
	CShapeGroupFillStyle(std::shared_ptr<IShape> shapeGroup);

	std::optional<RGBAColor> GetColor() const final;
	void SetColor(RGBAColor color) final;

	std::optional<bool> IsEnabled() const final;
	void SetEnabled(bool enable) final;

private:
	std::shared_ptr<IShape> m_shapeGroup;
};
