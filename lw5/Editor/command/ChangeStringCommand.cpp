#include "ChangeStringCommand.h"

CChangeStringCommand::CChangeStringCommand(std::string & target, std::string const & newValue)
	: m_target(target)
	, m_newValue(newValue)
{	
}

void CChangeStringCommand::DoExecute()
{
	SwapValues();
}

void CChangeStringCommand::DoUnexecute()
{
	SwapValues();
}

void CChangeStringCommand::SwapValues()
{
	m_newValue.swap(m_target);
}
