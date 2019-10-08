#pragma once
#include "../shapes/Shape.h"
#include <boost/iterator/indirect_iterator.hpp>
#include <memory>
#include <vector>

class CPictureDraft
{
public:
	CPictureDraft() = default;

	bool IsEmpty() const;
	void AddShape(std::unique_ptr<CShape>&& shape);
	CShape& GetShape(size_t index) const;
	size_t GetShapesCount() const;

private:
	typedef std::vector<std::unique_ptr<CShape>> Storage;

	Storage m_shapes;
};
