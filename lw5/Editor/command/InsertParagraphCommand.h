#pragma once
#include "AbstractCommand.h"

using namespace std;

class CInsertParagraphCommand : public CAbstractCommand
{
protected:
	void DoExecute() override;
	void DoUnexecute() override;
};