#pragma once
#include "IDesigner.h"
#include "../factory/IShapeFactory.h"

class CDesigner : public IDesigner
{
public:
	CDesigner(IShapeFactory& factory);

	CPictureDraft CreateDraft(std::istream& inputData) override;

	~CDesigner();

private:
	IShapeFactory& m_factory;
};
