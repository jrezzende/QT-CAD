#pragma once
#ifndef INCLUDED_COMMAND_H
#define INCLUDED_COMMAND_H

class CADFileManager;
class ViewMediator;

class Command
{
public:
	virtual ~Command()= default;
	Command()= default;

	virtual void execute(CADFileManager& fmanager, ViewMediator& viewm)= 0;
};

#endif //  INCLUDED_COMMAND_H