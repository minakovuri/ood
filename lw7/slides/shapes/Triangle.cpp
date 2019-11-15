#include "Triangle.h"
#include <algorithm>

CTriangle::CTriangle(const SPoint& vertex1, const SPoint& vertex2, const SPoint& vertex3)
	: m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
{
}

RectD CTriangle::GetFrame()
{
	double minX = std::min({ m_vertex1.x, m_vertex2.x, m_vertex3.x });
	double minY = std::min({ m_vertex1.y, m_vertex2.y, m_vertex3.y });

	double maxX = std::max({ m_vertex1.x, m_vertex2.x, m_vertex3.x });
	double maxY = std::max({ m_vertex1.y, m_vertex2.y, m_vertex3.y });

	return RectD{ minX, minY, maxX - minX, maxY - minY };
}

void CTriangle::SetFrame(const RectD& rect)
{
	const auto currentFrame = GetFrame();

	std::function updateVertexFn = [&](SPoint& vertex) {
		const auto scaleX = (vertex.x - currentFrame.left) / currentFrame.width;
		const auto scaleY = (vertex.y - currentFrame.top) / currentFrame.height;

		vertex = SPoint{ rect.left + rect.width * scaleX, rect.top + rect.height * scaleY };
	};

	updateVertexFn(m_vertex1);
	updateVertexFn(m_vertex2);
	updateVertexFn(m_vertex3);
}

void CTriangle::DrawBehaviour(const ICanvas& canvas) const
{
}
