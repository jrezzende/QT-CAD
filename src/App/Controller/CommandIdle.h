#pragma once
#ifndef INCLUDED_COMMANDIDLE_H
#define INCLUDED_COMMANDIDLE_H

#include "Command.h"

class CommandIdle : public Command
{
public:
	virtual ~CommandIdle()= default;
	CommandIdle()= default;

   void execute(CADFileManager& fileManager, ViewMediator& viewMediator) override;
};

#endif //  INCLUDED_COMMANDIDLE_H