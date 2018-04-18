#pragma once
#ifndef INCLUDED_COMMANDSAVE_H
#define INCLUDED_COMMANDSAVE_H

#include "Command.h"

class CommandSave : public Command
{
public: 
	~CommandSave()= default;
	CommandSave()= default;

	void execute(CADFileManager& m, ViewMediator& mediator) override;
};

#endif //  INCLUDED_COMMANDSAVE_H