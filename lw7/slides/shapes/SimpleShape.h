#pragma once
#include "IShape.h"

class CSimpleShape : public IShape
{
public:
	CSimpleShape();

	std::shared_ptr<IOutlineStyle> GetOutlineStyle() final;
	std::shared_ptr<const IOutlineStyle> GetOutlineStyle() const final;

	std::shared_ptr<IStyle> GetFillStyle() final;
	std::shared_ptr<const IStyle> GetFillStyle() const final;

	std::shared_ptr<IShapeGroup> TryGetGroup() final;
	std::shared_ptr<const IShapeGroup> TryGetGroup() const final;

	void Draw(const ICanvas& canvas) final;

protected:
	virtual void DrawBehaviour(const ICanvas& canvas) const = 0;

private:
	std::shared_ptr<IOutlineStyle> m_outlineStyle;
	std::shared_ptr<IStyle> m_fillStyle;
};