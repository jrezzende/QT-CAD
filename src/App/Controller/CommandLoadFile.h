#pragma once
#ifndef COMMANDLOADFILE_H
#define COMMANDLOADFILE_H

#include "Command.h"

class CommandLoadFile : public Command
{
public:
	~CommandLoadFile() {}
	CommandLoadFile() {}

	void execute(Model& m, MainWindow& w) override;
};

#endif // !COMMANDLOADFILE_H
