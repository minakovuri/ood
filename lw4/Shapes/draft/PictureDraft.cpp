#include "PictureDraft.h"
#include <stdexcept>

using namespace std;

bool CPictureDraft::IsEmpty() const
{
	return m_shapes.empty();
}

void CPictureDraft::AddShape(std::unique_ptr<CShape>&& shape)
{
	m_shapes.push_back(move(shape));
}

CShape& CPictureDraft::GetShape(size_t index) const
{
	if (index >= m_shapes.size())
		throw invalid_argument("requested index is out of range");

	return *m_shapes[index].get();
}

size_t CPictureDraft::GetShapesCount() const
{
	return m_shapes.size();
}
