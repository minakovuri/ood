#pragma once
#include "../shapes/IDrawableShape.h"

class ISlide : public IDrawable
{
	virtual double GetWidth() const = 0;
	virtual double GetHeight() const = 0;

	virtual size_t GetShapesCount() const = 0;
	virtual void InsertShape(std::shared_ptr<IDrawableShape> shape, size_t position = std::numeric_limits<size_t>::max()) = 0;
	virtual std::shared_ptr<IDrawableShape> GetShapeAtIndex(size_t index) const = 0;
	virtual void RemoveShapeAtIndex(size_t index) = 0;
};