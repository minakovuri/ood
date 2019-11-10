#pragma once
#include "../IDrawable.h"
#include "IShape.h"

class IDrawableShape
	: public IShape
	, public IDrawable
{
public:
	virtual ~IDrawableShape() = default;
};