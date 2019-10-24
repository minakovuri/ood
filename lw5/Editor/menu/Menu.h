#pragma once
#include <vector>
#include <functional>
#include <iostream>

using namespace std;

class CMenu
{
public:
	typedef function<void(istream& args)> Command;

	CMenu();
	CMenu(istream& inStream, ostream& outStream);

	void AddItem(const string& shortcut, const string& description, const Command& command);
	void Run();
	void ShowInstructions() const;
	void Exit();

private:
	bool ExecuteCommand(const string& command);

	struct Item
	{
		Item(const string& shortcut, const string& description, const Command& command)
			: shortcut(shortcut)
			, description(description)
			, command(command)
		{
		}

		string shortcut;
		string description;
		Command command;
	};

	vector<Item> m_items;
	bool m_exit = false;

	istream& m_inStream;
	ostream& m_outStream;
};
