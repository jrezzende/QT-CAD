#pragma once
#ifndef INCLUDED_COMMANDSAVE_H
#define INCLUDED_COMMANDSAVE_H

#include "Command.h"

class CommandSave : public Command
{
public: 
	~CommandSave()= default;
	CommandSave()= default;

	void execute(CADFileManager& fmanager, ViewMediator& vmediator) override;
};

#endif //  INCLUDED_COMMANDSAVE_H