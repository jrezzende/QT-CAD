#pragma once
#ifndef COMMANDBEZIER_H
#define COMMANDBEZIER_H

#include "Command.h"

class CommandBezier : public Command
{
public:
	~CommandBezier() {}
	CommandBezier() {}

	virtual void execute(Model& m, MainWindow& w) override;
};

#endif // !COMMANDBEZIER_H
