#pragma once
#ifndef INCLUDED_COMMANDCLEAR_H
#define INCLUDED_COMMANDCLEAR_H

#include "Command.h"

class CommandClear : public Command
{
public:
	virtual ~CommandClear()= default;
	CommandClear()= default;

	void execute(CADFileManager& fileManager, ViewMediator& viewMediator) override;
};

#endif //  INCLUDED_COMMANDCLEAR_H