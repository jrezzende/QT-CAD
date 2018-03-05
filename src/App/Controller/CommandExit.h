#pragma once
#ifndef COMMANDEXIT_H
#define COMMANDEXIT_H

#include "Command.h"	

class CommandExit : public Command
{
public:
	~CommandExit() {}
	CommandExit() {}

	void execute(Model& m, MainWindow& w) override;
};
#endif // !COMMANDEXIT_H
