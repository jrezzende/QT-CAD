#pragma once
#ifndef COMMANDNEWFILE_H
#define COMMANDNEWFILE_H

#include "Command.h"

class CommandNewFile : public Command
{
public:
	~CommandNewFile() {}
	CommandNewFile() {}

	virtual void execute(Model& m, MainWindow& w) override;
};

#endif // !COMMANDNEWFILE_H
