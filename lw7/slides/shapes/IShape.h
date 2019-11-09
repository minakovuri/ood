#pragma once
#include <memory>
#include "styles/IStyle.h"

// компоновщик - общий контракт для фигуры и группы фигур
class IShape
{
public:
	/* ----- методы фигуры ----- */
	virtual RectD GetFrame() = 0;
	virtual void SetFrame(const RectD& rect) = 0;

	virtual std::shared_ptr<IStyle> GetOutlineStyle() = 0;
	virtual std::shared_ptr<const IStyle> GetOutlineStyle() const = 0;

	virtual std::shared_ptr<IStyle> GetFillStyle() = 0;
	virtual std::shared_ptr<const IStyle> GetFillStyle() const = 0;

	/*virtual std::shared_ptr<IShape> GetGroup() = 0;
	virtual std::shared_ptr<const IShape> GetGroup() const = 0;*/

	/* ----- методы групп фигур ----- */
	virtual size_t GetShapesCount() const = 0;
	virtual void InsertShape(std::shared_ptr<IShape> shape, size_t position = std::numeric_limits<size_t>::max()) = 0;
	virtual std::shared_ptr<IShape> GetShapeAtIndex(size_t index) const = 0;
	virtual void RemoveShapeAtIndex(size_t index) = 0;

	virtual ~IShape() = default;
};
