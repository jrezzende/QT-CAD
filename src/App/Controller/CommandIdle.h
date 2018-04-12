#pragma once
#ifndef INCLUDED_COMMANDIDLE_H
#define INCLUDED_COMMANDIDLE_H

#include "Command.h"

class CommandIdle : public Command
{
public:
	~CommandIdle()= default;
	CommandIdle()= default;

	void execute(CADFileManager& m, ViewMediator& mediator) override;
};

#endif //  INCLUDED_COMMANDIDLE_H