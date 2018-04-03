#pragma once
#ifndef INCLUDED_COMMANDNEWFILE_H
#define INCLUDED_COMMANDNEWFILE_H

#include "Command.h"

class CommandNewFile : public Command
{
public:
	~CommandNewFile()= default;
	CommandNewFile()= default;

	void execute(Model& m, MainWindow& w) override;
};

#endif //  INCLUDED_COMMANDNEWFILE_H