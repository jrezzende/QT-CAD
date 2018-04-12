#pragma once
#ifndef INCLUDED_COMMANDNEWFILE_H
#define INCLUDED_COMMANDNEWFILE_H

#include "Command.h"

class CommandNewFile : public Command
{
public:
	~CommandNewFile()= default;
	CommandNewFile()= default;

	void execute(CADFileManager& m, ViewMediator& mediator) override;
};

#endif //  INCLUDED_COMMANDNEWFILE_H