#include "../../catch.hpp"
#include "../Editor/document/History.h"

using namespace std;

class MockIncrementCommand : public ICommand
{
public:
	MockIncrementCommand(int& num)
		: m_num(num)
	{
	}

	void Execute() final
	{
		if (m_num + 1 > MAX_NUM)
		{
			throw exception();
		}
		m_num++;
	}

	void Unexecute() final
	{
		m_num--;
	}

private:
	const int MAX_NUM = 3;
	int& m_num;
};

TEST_CASE("execute one command")
{
	CHistory history;

	int num = 0;

	history.AddAndExecuteCommand(make_unique<MockIncrementCommand>(num));
	CHECK(num == 1);
}

TEST_CASE("execute command and undo")
{
	CHistory history;

	int num = 0;

	CHECK_FALSE(history.CanUndo());
	history.AddAndExecuteCommand(make_unique<MockIncrementCommand>(num));
	CHECK(history.CanUndo());

	history.Undo();
	CHECK(num == 0);

	CHECK_FALSE(history.CanUndo());
	history.Undo();
	CHECK(num == 0);
}

TEST_CASE("execute command and redo")
{
	CHistory history;

	int num = 0;

	CHECK_FALSE(history.CanRedo());
	history.AddAndExecuteCommand(make_unique<MockIncrementCommand>(num));
	CHECK_FALSE(history.CanRedo());

	history.Redo();
	CHECK(num == 1);
}

TEST_CASE("execute command, undo and then redo")
{
	CHistory history;

	int num = 0;
	//ICommandPtr commandPtr = make_unique<MockIncrementCommand>(num);

	history.AddAndExecuteCommand(make_unique<MockIncrementCommand>(num));
	history.Undo();
	CHECK(history.CanRedo());

	history.Redo();
	CHECK(num == 1);
	CHECK_FALSE(history.CanRedo());
}

TEST_CASE("execute 3 command, undo 2, redo and execute command")
{
	CHistory history;

	int num = 0;

	history.AddAndExecuteCommand(make_unique<MockIncrementCommand>(num));
	history.AddAndExecuteCommand(make_unique<MockIncrementCommand>(num));
	history.AddAndExecuteCommand(make_unique<MockIncrementCommand>(num));

	CHECK(num == 3);

	history.Undo();
	history.Undo();

	CHECK(num == 1);

	history.Redo();
	CHECK(num == 2);

	history.AddAndExecuteCommand(make_unique<MockIncrementCommand>(num));
	CHECK(num == 3);

	CHECK_THROWS(history.AddAndExecuteCommand(make_unique<MockIncrementCommand>(num)));
}