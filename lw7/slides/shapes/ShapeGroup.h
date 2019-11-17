#pragma once
#include "IShapeGroup.h"
#include <vector>

class CShapeGroup 
	: public IShapeGroup
	, public IShape
	, public std::enable_shared_from_this<CShapeGroup>
{
public:
	CShapeGroup();

	size_t GetShapesCount() const override;
	void InsertShape(std::shared_ptr<IShape> shape, size_t position = std::numeric_limits<size_t>::max()) override;
	std::shared_ptr<IShape> GetShapeAtIndex(size_t index) const override;
	void RemoveShapeAtIndex(size_t index) override;

	RectD GetFrame() override;
	void SetFrame(const RectD& rect) override;

	std::shared_ptr<IOutlineStyle> GetOutlineStyle() override;
	std::shared_ptr<const IOutlineStyle> GetOutlineStyle() const override;

	std::shared_ptr<IStyle> GetFillStyle() override;
	std::shared_ptr<const IStyle> GetFillStyle() const override;

	std::shared_ptr<IShapeGroup> TryGetGroup() override;
	std::shared_ptr<const IShapeGroup> TryGetGroup() const override;

	void Draw(ICanvas& canvas) override;

private:
	std::shared_ptr<IOutlineStyle> m_outlineStyle;
	std::shared_ptr<IStyle> m_fillStyle;
	std::vector<std::shared_ptr<IShape>> m_shapes;
};