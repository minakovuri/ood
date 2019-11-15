#pragma once
#include "Point.h"
#include "SimpleShape.h"

class CTriangle : public CSimpleShape
{
public:
	CTriangle(const SPoint& vertex1, const SPoint& vertex2, const SPoint& vertex3);

	RectD GetFrame() override;
	void SetFrame(const RectD& rect) override;

protected:
	void DrawBehaviour(const ICanvas& canvas) const override;

private:
	SPoint m_vertex1;
	SPoint m_vertex2;
	SPoint m_vertex3;
};