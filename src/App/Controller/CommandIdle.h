#pragma once
#ifndef INCLUDED_COMMANDIDLE_H
#define INCLUDED_COMMANDIDLE_H

#include "Command.h"

class CommandIdle : public Command
{
public:
	~CommandIdle()= default;
	CommandIdle()= default;

	void execute(CADFileManager& fmanager, ViewMediator& vmediator) override;
};

#endif //  INCLUDED_COMMANDIDLE_H