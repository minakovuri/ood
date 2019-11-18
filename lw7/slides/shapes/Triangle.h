#pragma once
#include "../CommonTypes.h"
#include "SimpleShape.h"

class CTriangle : public CSimpleShape
{
public:
	CTriangle(const PointD& vertex1, const PointD& vertex2, const PointD& vertex3);

	std::optional<RectD> GetFrame() override;
	void SetFrame(const RectD& rect) override;

protected:
	void DrawBehaviour(ICanvas& canvas) const override;

private:
	PointD m_vertex1;
	PointD m_vertex2;
	PointD m_vertex3;
};