#include "canvas/SfmlCanvas.h"
#include "canvas/StreamCanvas.h"
#include "designer/Designer.h"
#include "factory/ShapeFactory.h"
#include "painter/Painter.h"
#include <iostream>
#include <conio.h>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

const std::string PROGRAM_INFO = "How to use this application:\n"
								 "1) To create rectangle: Rectangle <Color> <Left Top Vertex> <Right Bottom Vertex>\n"
								 "2) To create triangle: Triangle <Color> <Vertex 1> <Vertex 2> <Vertex3>\n"
								 "3) To create ellipse: Ellipse <Color> <Center Point> <Horizontal Radius> <Vertical Radius>\n"
								 "4) To create regular polugon : Polygon <Color> <Center Point> <Radius> <Vertexes Count>\n"
								 "5) To stop enter shapes, write \"stop\"\n";

int main()
{
	std::cout << "--- Welcome to Shapes App ---" << std::endl;

	std::cout << PROGRAM_INFO << std::endl;

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

	std::cout << "Select display mode:  (g for graphical, c for console)" << std::endl;
	std::string displayMode;
	std::cin >> displayMode;

	if (displayMode == "c")
	{
		CStreamCanvas streamCanvas(std::cout);

		CPainter painter;
		painter.DrawPicture(draft, streamCanvas);
	}
	else if (displayMode == "g")
	{
		sf::RenderWindow renderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Shapes");
		CSfmlCanvas sfmlCanvas(renderWindow);

		CPainter painter;

		while (renderWindow.isOpen())
		{
			sf::Event event;
			while (renderWindow.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					renderWindow.close();
			}

			renderWindow.clear(sf::Color::White);
			painter.DrawPicture(draft, sfmlCanvas);
			renderWindow.display();
		}
	}
	else
	{
		std::cerr << "You selected unknowm display mode!" << std::endl;
		return 1;
	}

	return 0;
}
