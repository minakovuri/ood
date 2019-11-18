#include "Triangle.h"
#include <algorithm>

CTriangle::CTriangle(const PointD& vertex1, const PointD& vertex2, const PointD& vertex3)
	: m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
{
}

std::optional<RectD> CTriangle::GetFrame()
{
	double minX = std::min({ m_vertex1.x, m_vertex2.x, m_vertex3.x });
	double minY = std::min({ m_vertex1.y, m_vertex2.y, m_vertex3.y });

	double maxX = std::max({ m_vertex1.x, m_vertex2.x, m_vertex3.x });
	double maxY = std::max({ m_vertex1.y, m_vertex2.y, m_vertex3.y });

	return RectD{ minX, minY, maxX - minX, maxY - minY };
}

void CTriangle::SetFrame(const RectD& rect)
{
	const auto currentFrame = *GetFrame();

	std::function updateVertexFn = [&](PointD& vertex) {
		const auto scaleX = (vertex.x - currentFrame.left) / currentFrame.width;
		const auto scaleY = (vertex.y - currentFrame.top) / currentFrame.height;

		vertex = PointD{ rect.left + rect.width * scaleX, rect.top + rect.height * scaleY };
	};

	updateVertexFn(m_vertex1);
	updateVertexFn(m_vertex2);
	updateVertexFn(m_vertex3);
}

void CTriangle::DrawBehaviour(ICanvas& canvas) const
{
	if (*GetOutlineStyle()->IsEnabled())
	{
		canvas.DrawLine(m_vertex1, m_vertex2);
		canvas.DrawLine(m_vertex2, m_vertex3);
		canvas.DrawLine(m_vertex3, m_vertex1);
	}

	if (*GetFillStyle()->IsEnabled())
	{
		canvas.FillPolygon(std::vector<PointD>{ m_vertex1, m_vertex2, m_vertex3 });
	}
}
