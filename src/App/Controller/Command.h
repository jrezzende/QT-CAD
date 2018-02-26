#pragma once
#ifndef COMMAND_H
#define COMMAND_H

class Model;
class MainWindow;

class Command
{
public:
	virtual ~Command() {}
	Command() {}

	virtual void execute(Model& m, MainWindow& w)= 0;
};

#endif // !COMMAND_H
