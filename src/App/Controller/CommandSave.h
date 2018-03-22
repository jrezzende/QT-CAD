#pragma once
#ifndef COMMANDSAVE_H
#define COMMANDSAVE_H

#include "Command.h"

#include <fstream>

class Line;
class Bezier;
class Arc;

class CommandSave : public Command
{
public: 
	~CommandSave() {}
	CommandSave() {}

	void execute(Model& m, MainWindow& w) override;
};

#endif // !COMMANDSAVE_H