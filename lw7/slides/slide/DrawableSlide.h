#pragma once
#include <vector>
#include "../IDrawable.h"
#include "ISlide.h"

class CDrawableSlide : public ISlide
{
public:
	double GetWidth() const override;
	double GetHeight() const override;

	size_t GetShapesCount() const override;
	void InsertShape(std::shared_ptr<IDrawableShape> shape, size_t position = std::numeric_limits<size_t>::max()) override;
	std::shared_ptr<IDrawableShape> GetShapeAtIndex(size_t index) const override;
	void RemoveShapeAtIndex(size_t index) override;

	void Draw(const ICanvas& canvas) override;

private:
	std::vector<std::shared_ptr<IShape>> m_shapes;
};