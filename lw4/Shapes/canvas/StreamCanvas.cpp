#include "StreamCanvas.h"

CStreamCanvas::CStreamCanvas(std::ostream& stream, Color color)
	: m_stream(stream)
	, m_color(Color::Black)
{
}

void CStreamCanvas::SetColor(Color color)
{
	m_color = color;
}

void CStreamCanvas::DrawLine(Point from, Point to)
{
	m_stream << "Draw " << GetColor() << " line from {" << from.x << ";" << from.y << "} to {" << to.x << ";" << to.y << "}" << std::endl;
}

void CStreamCanvas::DrawEllipse(Point center, double horizontalRadius, double verticalRadius)
{
	m_stream << "Draw " << GetColor() << " ellipse with center in {" << center.x << ";" << center.y << "}, horizontal radius " << horizontalRadius << " and vertical radius " << verticalRadius << std::endl;
}

std::string CStreamCanvas::GetColor()
{
	if (m_color == Color::Black)
	{
		return "Black";
	}
	else if (m_color == Color::Blue)
	{
		return "Blue";
	}
	else if (m_color == Color::Green)
	{
		return "Green";
	}
	else if (m_color == Color::Pink)
	{
		return "Pink";
	}
	else if (m_color == Color::Red)
	{
		return "Red";
	}
	else
	{
		return "Yellow";
	}
}
