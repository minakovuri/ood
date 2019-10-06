#pragma once
#include "IShapeFactory.h"
#include "../shapes/Shape.h"
#include <vector>

using namespace std;

typedef unique_ptr<CShape> ShapePtr;

class CShapeFactory : public IShapeFactory
{
public:
	ShapePtr CreateShape(const string& description) final;

private:
	typedef vector<string> Options;

	Options ParseOptions(const string& description);
	Color ParseColor(const string& option);
	Point ParsePoint(const string& option);

	ShapePtr CreateRectangle(const Options& options);
	ShapePtr CreateTriangle(const Options& options);
	ShapePtr CreateEllipse(const Options& options);
	ShapePtr CreateRegularPolygon(const Options& options);
};
