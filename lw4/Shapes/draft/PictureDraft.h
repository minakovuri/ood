#pragma once
#include "../shapes/Shape.h"
#include <boost/iterator/indirect_iterator.hpp>
#include <memory>
#include <vector>

class CPictureDraft
{
public:
	CPictureDraft();

	/*CPictureDraft(CPictureDraft&&) = default;
	CPictureDraft& operator=(CPictureDraft&&) = default;

	CPictureDraft(const CPictureDraft&) = delete;
	CPictureDraft& operator=(const CPictureDraft&) = delete;*/

	//typedef boost::indirect_iterator<Storage::const_iterator, const CShape&> ConstIterator;

	//bool IsEmpty() const;

	/*ConstIterator begin() const;
	ConstIterator end() const;*/

	void AddShape(std::unique_ptr<CShape>&& shape);
	std::unique_ptr<CShape> GetShape(unsigned index) const;
	unsigned GetShapesCount() const;

private:
	typedef std::vector<std::unique_ptr<CShape>> Storage;

	Storage m_shapes;
};
