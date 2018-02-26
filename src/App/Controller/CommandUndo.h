#pragma once
#ifndef COMMANDUNDO_H
#define COMMANDUNDO_H

#include "Command.h"

class CommandUndo : public Command
{
public:
	~CommandUndo() {}
	CommandUndo() {}

	virtual void execute(Model& m, MainWindow& w) override;
};

#endif // !COMMANDUNDO_H
