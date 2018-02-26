#pragma once
#ifndef COMMANDLINE_H
#define COMMANDLINE_H

#include "Command.h"

class CommandLine : public Command
{
public:
	~CommandLine() {}
	CommandLine() {}

	virtual void execute(Model& m, MainWindow& w) override;
};

#endif // !COMMANDLINE_H
