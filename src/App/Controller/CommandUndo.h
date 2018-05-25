#pragma once
#ifndef INCLUDED_COMMANDUNDO_H
#define INCLUDED_COMMANDUNDO_H

#include "Command.h"

class CommandUndo : public Command
{
public:
	virtual ~CommandUndo()= default;
	CommandUndo()= default;

	void execute(CADFileManager& fileManager, ViewMediator& viewMediator) override;
};

#endif //  INCLUDED_COMMANDUNDO_H