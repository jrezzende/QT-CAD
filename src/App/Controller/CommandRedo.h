#pragma once
#ifndef INCLUDED_COMMANDREDO_H
#define INCLUDED_COMMANDREDO_H

#include "Command.h"

class CommandRedo : public Command
{
public:
	virtual ~CommandRedo()= default;
	CommandRedo()= default;

	void execute(CADFileManager& fileManager, ViewMediator& viewMediator) override;
};

#endif //  INCLUDED_COMMANDREDO_H