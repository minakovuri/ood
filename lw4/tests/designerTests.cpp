#include "../../catch.hpp"
#include "../Shapes/designer/Designer.h"
#include "../Shapes/factory/ShapeFactory.h"
#include <sstream>

using namespace std;

TEST_CASE("Test designer")
{
	CShapeFactory factory;

	{
		stringstream inputStream;
		inputStream << "Rectangle Red 5.1;5.1 10.2;10.2";

		CDesigner designer(factory);
		auto draft = designer.CreateDraft(inputStream);

		CHECK(draft.GetShapesCount() == 1);
	}

	{
		stringstream inputStream;
		inputStream << "Triangle Green 1.0;1.0 3.0;1.0 2.0;5.0";

		CDesigner designer(factory);
		auto draft = designer.CreateDraft(inputStream);

		CHECK(draft.GetShapesCount() == 1);
	}

	{
		stringstream inputStream;
		inputStream << "Ellipse Blue 5.0;6.5 10.2 5.6";

		CDesigner designer(factory);
		auto draft = designer.CreateDraft(inputStream);

		CHECK(draft.GetShapesCount() == 1);
	}

	{
		stringstream inputStream;
		inputStream << "Polygon Yellow 5.0;5.0 2.0 5";

		CDesigner designer(factory);
		auto draft = designer.CreateDraft(inputStream);

		CHECK(draft.GetShapesCount() == 1);
	}

	{
		stringstream inputStream;
		inputStream << "Square 1.0;1.0 2.0;1.0 2.0;2.0 1.0;2.0";

		CDesigner designer(factory);
		CHECK_THROWS_AS(designer.CreateDraft(inputStream), invalid_argument);
	}
}