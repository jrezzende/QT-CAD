#pragma once
#ifndef INCLUDED_COMMANDLOADFILE_H
#define INCLUDED_COMMANDLOADFILE_H

#include "Command.h"

class CommandLoadFile : public Command
{
public:
	virtual ~CommandLoadFile()= default;
	CommandLoadFile()= default;

	void execute(CADFileManager& fileManager, ViewMediator& viewMediator) override;
};

#endif //  INCLUDED_COMMANDLOADFILE_H