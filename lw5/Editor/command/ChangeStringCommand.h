#pragma once
#include "AbstractCommand.h"
#include <string>

using namespace std;

class CChangeStringCommand : public CAbstractCommand
{
public:
	CChangeStringCommand(string& target, string const& newValue);

protected:
	void DoExecute() override;
	void DoUnexecute() override;

private:
	void SwapValues();

	string m_newValue;
	string& m_target;
};
