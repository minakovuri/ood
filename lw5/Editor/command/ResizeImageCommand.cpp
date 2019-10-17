#include "ResizeImageCommand.h"
#include <algorithm>

CResizeImageCommand::CResizeImageCommand(int& width, int& height, int newWidth, int newHeight)
	: m_width(width)
	, m_height(height)
	, m_newWidth(newWidth)
	, m_newHeight(newHeight)
{
}

void CResizeImageCommand::DoExecute()
{
	SwapValues();
}

void CResizeImageCommand::DoUnexecute()
{
	SwapValues();
}

void CResizeImageCommand::SwapValues()
{
	std::swap(m_newWidth, m_width);
	std::swap(m_newHeight, m_height);
}
