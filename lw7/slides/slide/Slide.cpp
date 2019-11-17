#include "Slide.h"

double CSlide::GetWidth() const
{
	return 0.0;
}

double CSlide::GetHeight() const
{
	return 0.0;
}

size_t CSlide::GetShapesCount() const
{
	return m_shapes.size();
}

void CSlide::InsertShape(std::shared_ptr<IShape> shape, size_t position)
{
}

std::shared_ptr<IShape> CSlide::GetShapeAtIndex(size_t index) const
{
	return std::shared_ptr<IShape>();
}

void CSlide::RemoveShapeAtIndex(size_t index)
{
}

void CSlide::Draw(ICanvas& canvas)
{
	for (size_t i = 0; i < GetShapesCount(); i++)
	{
		auto shape = GetShapeAtIndex(i);
		shape->Draw(canvas);
	}
}

CSlide::~CSlide()
{
}
