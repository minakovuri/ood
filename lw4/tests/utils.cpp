#include "utils.h"
#include <cmath>
#include <cfloat>

bool IsPointsEqual(Point a, Point b)
{
	bool xEquals = abs(a.x - b.x) < DBL_EPSILON;
	bool yEquals = abs(a.y - b.y) < DBL_EPSILON;

	return xEquals && yEquals;
}