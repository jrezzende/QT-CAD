#pragma once
#ifndef COMMANDSAVE_H
#define COMMANDSAVE_H

#include "Command.h"

class CommandSave : public Command
{
public: 
	~CommandSave() {}
	CommandSave() {}

	virtual void execute(Model& m, MainWindow& w) override;
};

#endif // !COMMANDSAVE_H
