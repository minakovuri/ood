#include "Painter.h"

void CPainter::DrawPicture(CPictureDraft& draft, ICanvas& canvas)
{
	for (size_t i = 0; i < draft.GetShapesCount(); i++)
	{
		CShape& shape = draft.GetShape(i);
		shape.Draw(canvas);
	}
}
