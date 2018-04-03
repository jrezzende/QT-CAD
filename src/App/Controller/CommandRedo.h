#pragma once
#ifndef INCLUDED_COMMANDREDO_H
#define INCLUDED_COMMANDREDO_H

#include "Command.h"

class CommandRedo : public Command
{
public:
	~CommandRedo()= default;
	CommandRedo()= default;

	void execute(Model& m, MainWindow& w) override;
};

#endif //  INCLUDED_COMMANDREDO_H