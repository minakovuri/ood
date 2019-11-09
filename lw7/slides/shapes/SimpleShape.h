#pragma once
#include "IShape.h"

class CSimpleShape : public IShape
{
public:
	CSimpleShape() = delete;
	CSimpleShape(const RectD& frame);
	CSimpleShape(const RectD& frame, std::shared_ptr<IStyle> outlineStyle);
	CSimpleShape(const RectD& frame, std::shared_ptr<IStyle> outlineStyle, std::shared_ptr<IStyle> fillStyle);
	CSimpleShape(const RectD& frame, std::shared_ptr<IStyle> outlineStyle, std::shared_ptr<IStyle> fillStyle, std::shared_ptr<IShape> group);

	RectD GetFrame() override;
	void SetFrame(const RectD& rect) override;

	std::shared_ptr<IStyle> GetOutlineStyle() override;
	std::shared_ptr<const IStyle> GetOutlineStyle() const override;

	std::shared_ptr<IStyle> GetFillStyle() override;
	std::shared_ptr<const IStyle> GetFillStyle() const override;

	/*std::shared_ptr<IShape> GetGroup() override;
	std::shared_ptr<const IShape> GetGroup() const override;*/

	/* --- эти методы недоступны --- */
	size_t GetShapesCount() const final;
	void InsertShape(std::shared_ptr<IShape> shape, size_t position = std::numeric_limits<size_t>::max()) final;
	std::shared_ptr<IShape> GetShapeAtIndex(size_t index) const final;
	void RemoveShapeAtIndex(size_t index) final;

private:
	RectD m_frame;
	std::shared_ptr<IStyle> m_outlineStyle;
	std::shared_ptr<IStyle> m_fillStyle;
	std::shared_ptr<IShape> m_group;
};