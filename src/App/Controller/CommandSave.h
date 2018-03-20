#pragma once
#ifndef COMMANDSAVE_H
#define COMMANDSAVE_H

#include "Command.h"

class Line;
class Bezier;
class Arc;

class CommandSave : public Command
{
public: 
	~CommandSave() {}
	CommandSave() {}

	void persistLine(std::ofstream& os, Line& l);
	void persistBezier(std::ofstream& os, Bezier& b);
	void persistArc(std::ofstream& os, Arc& a);

	void execute(Model& m, MainWindow& w) override;
};

#endif // !COMMANDSAVE_H
