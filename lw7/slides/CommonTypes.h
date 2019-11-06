#pragma once
#include <stdint.h>

template <typename T>
struct Rect
{
	T left;
	T top;
	T width;
	T height;
};

typedef Rect<double> RectD;
typedef uint32_t RGBAColor;

template <typename T>
struct Point
{
	T x;
	T y;
};

typedef Point<double> PointD;