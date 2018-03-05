#pragma once
#ifndef COMMANDIDLE_H
#define COMMANDIDLE_H

#include "Command.h"

class CommandIdle : public Command
{
public:
	~CommandIdle() {}
	CommandIdle() {}

	void execute(Model& m, MainWindow& w) override;
};

#endif // !COMMANDIDLE_H