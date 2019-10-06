#include "factory/ShapeFactory.h"
#include "designer/Designer.h"
#include "painter/Painter.h"
#include "canvas/StreamCanvas.h"
#include <iostream>

int main()
{
	std::cout << "--- Welcome to Shapes App ---" << std::endl;

	CShapeFactory factory;
	CDesigner desinger(factory);

	CPictureDraft draft;

	try
	{
		draft = desinger.CreateDraft(std::cin);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	CStreamCanvas streamCanvas(std::cout);

	CPainter painter;
	painter.DrawPicture(draft, streamCanvas);

	return 0;
}
