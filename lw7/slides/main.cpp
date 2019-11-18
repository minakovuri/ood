#include "canvas/SFMLCanvas.h"
#include "canvas/StreamCanvas.h"
#include "shapes/Ellipse.h"
#include "shapes/Rectangle.h"
#include "shapes/ShapeGroup.h"
#include "shapes/Triangle.h"
#include "slide/Slide.h"
#include <iostream>

const double SLIDE_WIDTH = 800;
const double SLIDE_HEIGHT = 600;

const char GRAPHICAL_MODE = 'g';
const char CONSOLE_MODE = 'c';

enum HousePalette : RGBAColor
{
	RoofColor = 0x990000FF,
	FacadeColor = 0xFFCC99FF,
	WindowColor = 0x66FFFFFF,
	WindowFrameColor = 0x663300FF,
	DoorColor = 0x663300FF,
};

std::shared_ptr<IShape> CreateHouse()
{
	std::shared_ptr<IShape> roof = std::make_shared<CTriangle>(PointD{ 400, 100 }, PointD{ 100, 200 }, PointD{ 700, 200 });
	roof->GetFillStyle()->SetEnabled(true);
	roof->GetFillStyle()->SetColor(HousePalette::RoofColor);
	roof->GetOutlineStyle()->SetEnabled(false);

	std::shared_ptr<IShape> facade = std::make_shared<CRectangle>(PointD{ 150, 200 }, PointD{ 650, 500 });
	facade->GetFillStyle()->SetEnabled(true);
	facade->GetFillStyle()->SetColor(HousePalette::FacadeColor);
	facade->GetOutlineStyle()->SetEnabled(false);

	std::shared_ptr<IShape> window = std::make_shared<CRectangle>(PointD{ 250, 300 }, PointD{ 350, 400 });
	window->GetFillStyle()->SetEnabled(true);
	window->GetFillStyle()->SetColor(HousePalette::WindowColor);
	window->GetOutlineStyle()->SetEnabled(true);
	window->GetOutlineStyle()->SetColor(HousePalette::WindowFrameColor);
	window->GetOutlineStyle()->SetThickness(20);

	std::shared_ptr<IShape> door = std::make_shared<CRectangle>(PointD{ 500, 300 }, PointD{ 600, 500 });
	door->GetFillStyle()->SetEnabled(true);
	door->GetFillStyle()->SetColor(HousePalette::DoorColor);
	door->GetOutlineStyle()->SetEnabled(false);

	std::shared_ptr<IShape> house = std::make_shared<CShapeGroup>();
	house->TryGetGroup()->InsertShape(roof);
	house->TryGetGroup()->InsertShape(facade);
	house->TryGetGroup()->InsertShape(window);
	house->TryGetGroup()->InsertShape(door);

	return house;
}

std::shared_ptr<ISlide> CreateSlide()
{
	return std::make_shared<CSlide>(SLIDE_WIDTH, SLIDE_HEIGHT);
}

void DrawWithConsole(std::shared_ptr<ISlide> slide)
{
	auto streamCanvas = CStreamCanvas(std::cout);
	slide->Draw(streamCanvas);
}

void DrawWithGraphicApi(std::shared_ptr<ISlide> slide)
{
	auto width = static_cast<unsigned int>(slide->GetWidth());
	auto height = static_cast<unsigned int>(slide->GetHeight());

	sf::RenderWindow renderWindow(sf::VideoMode(width, height), "Graphic slide");
	CSFMLCanvas sfmlCanvas(renderWindow);

	while (renderWindow.isOpen())
	{
		sf::Event event;
		while (renderWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				renderWindow.close();
		}

		renderWindow.clear(sf::Color::Black);
		slide->Draw(sfmlCanvas);
		renderWindow.display();
	}
}

int main()
{
	auto house = CreateHouse();

	auto slide = CreateSlide();
	slide->InsertShape(house);

	char displayMode = GRAPHICAL_MODE;

	if (displayMode == GRAPHICAL_MODE)
	{
		DrawWithGraphicApi(slide);
	}
	else if (displayMode == CONSOLE_MODE)
	{
		DrawWithConsole(slide);
	}
	else
	{
		std::cerr << "You selected unknowm display mode!" << std::endl;
	}

	return 0;
}
