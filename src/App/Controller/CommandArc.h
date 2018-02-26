#pragma once
#ifndef COMMANDARC_H
#define COMMANDARC_H

#include "Command.h"

class CommandArc : public Command
{
public: 
	~CommandArc() {}
	CommandArc() {}
	
	virtual void execute(Model& m, MainWindow& w) override;
};

#endif // !COMMANDARC_H
