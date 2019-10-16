#pragma once
#include "AbstractCommand.h"

using namespace std;

class CInsertImageCommand : public CAbstractCommand
{
protected:
	void DoExecute() override;
	void DoUnexecute() override;
};