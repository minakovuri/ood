#include "Shape.h"

Color CShape::GetColor() const
{
	return m_color;
}

CShape::CShape(Color color)
	: m_color(color)
{
}
