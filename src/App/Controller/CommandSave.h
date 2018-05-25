#pragma once
#ifndef INCLUDED_COMMANDSAVE_H
#define INCLUDED_COMMANDSAVE_H

#include "Command.h"

class CommandSave : public Command
{
public: 
	virtual ~CommandSave()= default;
	CommandSave()= default;

	void execute(CADFileManager& fileManager, ViewMediator& viewMediator) override;
};

#endif //  INCLUDED_COMMANDSAVE_H