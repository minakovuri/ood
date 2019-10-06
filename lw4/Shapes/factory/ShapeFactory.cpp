#include "ShapeFactory.h"
#include "../shapes/Rectangle.h"
#include "../shapes/Triangle.h"
#include "../shapes/Ellipse.h"
#include "../shapes/RegularPolygon.h"
#include <boost/algorithm/string.hpp>
#include <sstream>
#include <stdexcept>

using namespace std;

unique_ptr<CShape> CShapeFactory::CreateShape(const string& description)
{
	auto options = ParseOptions(description);

	if (!options.size())
		throw invalid_argument("empty options");

	auto shapeType = options[0];

	ShapePtr shape;

	if (shapeType == "Rectangle")
	{
		shape = CreateRectangle(options);
	}
	else if (shapeType == "Triangle")
	{
		shape = CreateTriangle(options);
	}
	else if (shapeType == "Ellipse")
	{
		shape = CreateEllipse(options);
	}
	else if (shapeType == "Polygon")
	{
		shape = CreateRegularPolygon(options);
	}
	else
	{
		throw invalid_argument("unknown shape type");
	}

	return shape;
}

CShapeFactory::Options CShapeFactory::ParseOptions(const string& description)
{
	Options options;

	istringstream stream(description);
	string option;

	while (stream >> option)
	{
		options.push_back(option);
	}

	return options;
}

Color CShapeFactory::ParseColor(const string& option)
{
	Color color;

	if (option == "Red")
	{
		color = Color::Red;
	}
	else if (option == "Black")
	{
		color = Color::Black;
	}
	else if (option == "Blue")
	{
		color = Color::Blue;
	}
	else if (option == "Green")
	{
		color = Color::Green;
	}
	else if (option == "Pink")
	{
		color = Color::Pink;
	}
	else if (option == "Yellow")
	{
		color = Color::Yellow;
	}
	else
	{
		throw invalid_argument("unknown color name");
	}

	return color;
}

Point CShapeFactory::ParsePoint(const string& option)
{
	vector<string> coordinates;
	boost::algorithm::split(coordinates, option, boost::is_any_of(";"));

	if (coordinates.size() != 2)
		throw invalid_argument("invalid point params count");

	double x = stod(coordinates[0]);
	double y = stod(coordinates[1]);

	return Point{ x, y };
}

ShapePtr CShapeFactory::CreateRectangle(const Options& options)
{
	if (options.size() != 4)
		throw invalid_argument("invalid rectangle options count");

	Color color = ParseColor(options[1]);
	Point leftTop = ParsePoint(options[2]);
	Point rightBottom = ParsePoint(options[3]);

	return make_unique<CRectangle>(color, leftTop, rightBottom);
}

ShapePtr CShapeFactory::CreateTriangle(const Options& options)
{
	if (options.size() != 5)
		throw invalid_argument("invalid triangle options count");

	Color color = ParseColor(options[1]);
	Point vertex1 = ParsePoint(options[2]);
	Point vertex2 = ParsePoint(options[3]);
	Point vertex3 = ParsePoint(options[4]);
	
	return make_unique<CTriangle>(color, vertex1, vertex2, vertex3);
}

ShapePtr CShapeFactory::CreateEllipse(const Options& options)
{
	if (options.size() != 5)
		throw invalid_argument("invalid ellipse options count");

	Color color = ParseColor(options[1]);
	Point center = ParsePoint(options[2]);
	double horizontalRadius = stod(options[3]);
	double verticalRadius = stod(options[4]);

	return make_unique<CEllipse>(color, center, horizontalRadius, verticalRadius);
}

ShapePtr CShapeFactory::CreateRegularPolygon(const Options& options)
{
	if (options.size() != 5)
		throw invalid_argument("invalid regular polygon options count");

	Color color = ParseColor(options[1]);
	Point center = ParsePoint(options[2]);
	double radius = stod(options[3]);
	int vertexesCount = stoi(options[4]);
	if (vertexesCount < 0)
		throw invalid_argument("vertexes count cannot be negative");

	return make_unique<CRegularPolygon>(color, center, radius, (unsigned)(vertexesCount));
}
