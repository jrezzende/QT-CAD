#pragma once
#ifndef COMMANDSETCURRENTFILE_H
#define COMMANDSETCURRENTFILE_H

#include "Command.h"

class CommandSetCurrentFile : public Command
{
public:
	~CommandSetCurrentFile() {}
	CommandSetCurrentFile() {}

	void execute(Model& m, MainWindow& w) override;
};

#endif // !COMMANDSETCURRENTFILE_H
