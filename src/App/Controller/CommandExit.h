#pragma once
#ifndef INCLUDED_COMMANDEXIT_H
#define INCLUDED_COMMANDEXIT_H

#include "Command.h"	

class CommandExit : public Command
{
public:
	~CommandExit()= default;
	CommandExit()= default;

	void execute(Model& m, MainWindow& w) override;
};

#endif //  INCLUDED_COMMANDEXIT_H