#pragma once
#ifndef COMMANDSAVEAS_H
#define COMMANDSAVEAS_H

#include "Command.h"

class CommandSaveAs : public Command
{
public:
	~CommandSaveAs() {}
	CommandSaveAs() {}

	void execute(Model& m, MainWindow& w) override;
};

#endif // !COMMANDSAVEAS_H
