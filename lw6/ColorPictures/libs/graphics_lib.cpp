#include <iostream>
#include <sstream>
#include <boost/algorithm/string.hpp>
#include "graphics_lib.h"

using namespace std;

void graphics_lib::CCanvas::SetColor(uint32_t rgbColor)
{
	stringstream stream;
	stream << hex << rgbColor;
	string stringColor("#" + boost::algorithm::to_upper_copy(stream.str()));

	cout << "SetColor " << stringColor << endl;
}

void graphics_lib::CCanvas::MoveTo(int x, int y)
{
	cout << "MoveTo (" << x << ", " << y << ")" << endl;
}

void graphics_lib::CCanvas::LineTo(int x, int y)
{
	cout << "MoveTo (" << x << ", " << y << ")" << endl;
}
