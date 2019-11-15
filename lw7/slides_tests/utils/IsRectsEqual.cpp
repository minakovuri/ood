#include "IsRectsEqual.h"

bool IsRectsEqual(const RectD& rect1, const RectD& rect2)
{
	return rect1.height == rect2.height
		&& rect1.left == rect2.left
		&& rect1.top == rect2.top
		&& rect1.width == rect2.width;
}
