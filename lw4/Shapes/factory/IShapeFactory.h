#pragma once
#include "../shapes/Shape.h"
#include <memory>
#include <string>

struct IShapeFactory
{
public:
	virtual std::unique_ptr<CShape> CreateShape(const std::string& description) = 0;
	virtual ~IShapeFactory() = default;
};
