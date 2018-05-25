#pragma once
#ifndef INCLUDED_COMMANDEXIT_H
#define INCLUDED_COMMANDEXIT_H

#include "Command.h"	

class CommandExit : public Command
{
public:
	virtual ~CommandExit()= default;
	CommandExit()= default;

	void execute(CADFileManager& fileManager, ViewMediator& viewMediator) override;
};

#endif //  INCLUDED_COMMANDEXIT_H