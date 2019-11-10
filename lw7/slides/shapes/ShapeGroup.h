#pragma once
#include "IShape.h"

class CShapeGroup 
	: public IShape
	, public std::enable_shared_from_this<IStyle>
{
public:
	CShapeGroup();

	size_t GetShapesCount() const override;
	void InsertShape(std::shared_ptr<IShape> shape, size_t position = std::numeric_limits<size_t>::max()) override;
	std::shared_ptr<IShape> GetShapeAtIndex(size_t index) const override;
	void RemoveShapeAtIndex(size_t index) override;

	/* --- эти методы недоступны --- */
	RectD GetFrame() final;
	void SetFrame(const RectD& rect) final;

	std::shared_ptr<IOutlineStyle> GetOutlineStyle() final;
	std::shared_ptr<const IOutlineStyle> GetOutlineStyle() const final;

	std::shared_ptr<IStyle> GetFillStyle() final;
	std::shared_ptr<const IStyle> GetFillStyle() const final;

	/*std::shared_ptr<IShape> GetGroup() final;
	std::shared_ptr<const IShape> GetGroup() const final;*/
private:
	std::shared_ptr<IStyle> m_outlineStyle;
	std::shared_ptr<IStyle> m_fillStyle;
};