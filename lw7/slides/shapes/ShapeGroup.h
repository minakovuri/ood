#pragma once
#include "IShape.h"
#include <vector>

class CShapeGroup 
	: public IShape
	, public std::enable_shared_from_this<IShape>
{
public:
	CShapeGroup();

	size_t GetShapesCount() const override;
	void InsertShape(std::shared_ptr<IShape> shape, size_t position = std::numeric_limits<size_t>::max()) override;
	std::shared_ptr<IShape> GetShapeAtIndex(size_t index) const override;
	void RemoveShapeAtIndex(size_t index) override;

	RectD GetFrame() final;
	void SetFrame(const RectD& rect) final;

	std::shared_ptr<IOutlineStyle> GetOutlineStyle() final;
	std::shared_ptr<const IOutlineStyle> GetOutlineStyle() const final;

	std::shared_ptr<IStyle> GetFillStyle() final;
	std::shared_ptr<const IStyle> GetFillStyle() const final;

private:
	std::shared_ptr<IOutlineStyle> m_outlineStyle;
	std::shared_ptr<IStyle> m_fillStyle;
	std::vector<std::shared_ptr<IShape>> m_shapes;
};