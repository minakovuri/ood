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

	/* --- эти методы недоступны --- */
	size_t GetShapesCount() const final;
	void InsertShape(std::shared_ptr<IShape> shape, size_t position = std::numeric_limits<size_t>::max()) final;
	std::shared_ptr<IShape> GetShapeAtIndex(size_t index) const final;
	void RemoveShapeAtIndex(size_t index) final;

private:
	RectD m_frame;
	std::shared_ptr<IOutlineStyle> m_outlineStyle;
	std::shared_ptr<IStyle> m_fillStyle;
};