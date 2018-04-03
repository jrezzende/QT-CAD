#pragma once
#ifndef INCLUDED_COMMANDUNDO_H
#define INCLUDED_COMMANDUNDO_H

#include "Command.h"

class CommandUndo : public Command
{
public:
	~CommandUndo()= default;
	CommandUndo()= default;

	void execute(Model& m, MainWindow& w) override;
};

#endif //  INCLUDED_COMMANDUNDO_H
