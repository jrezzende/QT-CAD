#pragma once
#ifndef INCLUDED_COMMAND_H
#define INCLUDED_COMMAND_H

class Model;
class MainWindow;

class Command
{
public:
	virtual ~Command()= default;
	Command()= default;

	virtual void execute(Model& m, MainWindow& w)= 0;
};

#endif //  INCLUDED_COMMAND_H