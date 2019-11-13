#pragma once
#include "IShape.h"

class CSimpleShape : public IShape
{
public:
	CSimpleShape() = delete;
	CSimpleShape(const RectD& frame);

	RectD GetFrame() override;
	void SetFrame(const RectD& rect) override;

	std::shared_ptr<IOutlineStyle> GetOutlineStyle() override;
	std::shared_ptr<const IOutlineStyle> GetOutlineStyle() const override;

	std::shared_ptr<IStyle> GetFillStyle() override;
	std::shared_ptr<const IStyle> GetFillStyle() const override;

	std::shared_ptr<IShapeGroup> TryGetGroup() override;
	std::shared_ptr<const IShapeGroup> TryGetGroup() const override;

	void Draw(const ICanvas& canvas) override;

private:
	RectD m_frame;
	std::shared_ptr<IOutlineStyle> m_outlineStyle;
	std::shared_ptr<IStyle> m_fillStyle;
};