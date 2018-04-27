#pragma once
#ifndef INCLUDED_COMMANDCLEAR_H
#define INCLUDED_COMMANDCLEAR_H

#include "Command.h"

class CommandClear : public Command
{
public:
	~CommandClear()= default;
	CommandClear()= default;

	void execute(CADFileManager& fmanager, ViewMediator& vmediator) override;
};

#endif //  INCLUDED_COMMANDCLEAR_H