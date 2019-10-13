#pragma once
#include <deque>
#include "../command/ICommand.h"

class CHistory
{
public:
	CHistory();

	bool CanUndo()const;	
	void Undo();
	bool CanRedo()const;
	void Redo();
	void AddAndExecuteCommand(ICommandPtr && command);

	~CHistory();

private:
	std::deque<ICommandPtr> m_commands;
	size_t m_nextCommandIndex = 0;
};

