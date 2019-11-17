#pragma once
#include <vector>
#include "ISlide.h"

class CSlide : public ISlide
{
public:
	CSlide(double width, double height);

	double GetWidth() const override;
	double GetHeight() const override;

	size_t GetShapesCount() const override;
	void InsertShape(std::shared_ptr<IShape> shape, size_t position = std::numeric_limits<size_t>::max()) override;
	std::shared_ptr<IShape> GetShapeAtIndex(size_t index) const override;
	void RemoveShapeAtIndex(size_t index) override;

	void Draw(ICanvas& canvas) override;

private:
	std::vector<std::shared_ptr<IShape>> m_shapes;

	double m_width;
	double m_height;
};