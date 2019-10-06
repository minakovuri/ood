#include "Designer.h"

using namespace std;

CDesigner::CDesigner(IShapeFactory& factory)
	: m_factory(factory)
{
}

CPictureDraft CDesigner::CreateDraft(istream& inputData)
{
	CPictureDraft draft;
	string line;

	while (getline(inputData, line))
	{
		draft.AddShape(m_factory.CreateShape(line));
	}

	return draft;
}

CDesigner::~CDesigner()
{
}
