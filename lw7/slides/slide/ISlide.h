#pragma once
#include "../shapes/IShape.h"

class ISlide
{
	virtual double GetWidth() const = 0;
	virtual double GetHeight() const = 0;
	virtual std::shared_ptr<IShape> GetRootShape() const = 0;

	virtual ~ISlide() = default;
};