#pragma once
#ifndef COMMANDREDO_H
#define COMMANDREDO_H

#include "Command.h"

class CommandRedo : public Command
{
public:
	~CommandRedo() {}
	CommandRedo() {}

	void execute(Model& m, MainWindow& w) override;
};
#endif // !COMMANDREDO_H
