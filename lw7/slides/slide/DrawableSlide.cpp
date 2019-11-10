#include "DrawableSlide.h"

double CDrawableSlide::GetWidth() const
{
	return 0.0;
}

double CDrawableSlide::GetHeight() const
{
	return 0.0;
}

size_t CDrawableSlide::GetShapesCount() const
{
	return m_shapes.size();
}

void CDrawableSlide::InsertShape(std::shared_ptr<IDrawableShape> shape, size_t position)
{
}

std::shared_ptr<IDrawableShape> CDrawableSlide::GetShapeAtIndex(size_t index) const
{
	return std::shared_ptr<IDrawableShape>();
}

void CDrawableSlide::RemoveShapeAtIndex(size_t index)
{
}

void CDrawableSlide::Draw(const ICanvas& canvas)
{
	for (size_t i = 0; i < GetShapesCount(); i++)
	{
		auto shape = GetShapeAtIndex(i);
		shape->Draw(canvas);
	}
}
