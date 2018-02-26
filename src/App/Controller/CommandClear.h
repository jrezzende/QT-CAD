#pragma once
#ifndef COMMANDCLEAR_H
#define COMMANDCLEAR_H

#include "Command.h"

class CommandClear : public Command
{
public:
	~CommandClear() {}
	CommandClear() {}

	virtual void execute(Model& m, MainWindow& w) override;
};

#endif // !COMMANDCLEAR_H
