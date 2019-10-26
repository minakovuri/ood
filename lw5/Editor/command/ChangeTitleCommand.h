#pragma once
#include "AbstractCommand.h"
#include <string>

using namespace std;

class CChangeTitleCommand : public CAbstractCommand
{
public:
	CChangeTitleCommand(string& target, string const& newValue);

protected:
	void DoExecute() override;
	void DoUnexecute() override;

private:
	void SwapValues();

	string m_newValue;
	string& m_target;
};
