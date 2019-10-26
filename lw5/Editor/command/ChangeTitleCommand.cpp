#include "ChangeTitleCommand.h"

CChangeTitleCommand::CChangeTitleCommand(std::string & target, std::string const & newValue)
	: m_target(target)
	, m_newValue(newValue)
{	
}

void CChangeTitleCommand::DoExecute()
{
	SwapValues();
}

void CChangeTitleCommand::DoUnexecute()
{
	SwapValues();
}

void CChangeTitleCommand::SwapValues()
{
	m_newValue.swap(m_target);
}
