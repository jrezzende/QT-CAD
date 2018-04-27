#pragma once
#ifndef INCLUDED_COMMANDREDO_H
#define INCLUDED_COMMANDREDO_H

#include "Command.h"

class CommandRedo : public Command
{
public:
	~CommandRedo()= default;
	CommandRedo()= default;

	void execute(CADFileManager& fmanager, ViewMediator& vmediator) override;
};

#endif //  INCLUDED_COMMANDREDO_H