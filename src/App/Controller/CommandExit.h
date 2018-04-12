#pragma once
#ifndef INCLUDED_COMMANDEXIT_H
#define INCLUDED_COMMANDEXIT_H

#include "Command.h"	

class CommandExit : public Command
{
public:
	~CommandExit()= default;
	CommandExit()= default;

	void execute(CADFileManager& m, ViewMediator& mediator) override;
};

#endif //  INCLUDED_COMMANDEXIT_H