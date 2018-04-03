#pragma once
#ifndef INCLUDED_COMMANDSAVE_H
#define INCLUDED_COMMANDSAVE_H

#include "Command.h"

class CADLine;
class CADBezier;
class CADArc;

class CommandSave : public Command
{
public: 
	~CommandSave()= default;
	CommandSave()= default;

	void execute(Model& m, MainWindow& w) override;
};

#endif //  INCLUDED_COMMANDSAVE_H