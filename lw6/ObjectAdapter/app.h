#pragma once
#include "libs/shape_drawing_lib.h"

// ������������ ���� ���������� (�������� ��� �����������)
namespace app
{
void PaintPicture(shape_drawing_lib::CCanvasPainter& painter);
void PaintPictureOnCanvas();
void PaintPictureOnModernGraphicsRenderer();
} // namespace app
