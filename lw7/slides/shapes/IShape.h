#pragma once
#include <memory>
#include "../IDrawable.h"
#include "styles/IOutlineStyle.h"

class IShapeGroup;

class IShape : public IDrawable
{
public:
	virtual RectD GetFrame() = 0;
	virtual void SetFrame(const RectD& rect) = 0;

	virtual std::shared_ptr<IOutlineStyle> GetOutlineStyle() = 0;
	virtual std::shared_ptr<const IOutlineStyle> GetOutlineStyle() const = 0;

	virtual std::shared_ptr<IStyle> GetFillStyle() = 0;
	virtual std::shared_ptr<const IStyle> GetFillStyle() const = 0;

	virtual std::shared_ptr<IShapeGroup> TryGetGroup() = 0;
	virtual std::shared_ptr<const IShapeGroup> TryGetGroup() const = 0;

	virtual ~IShape() = default;
};
