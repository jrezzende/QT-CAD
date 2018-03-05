#include "CommandManager.h"
#include "Point.h"
#include "Model.h"
#include "Canvas.h"
#include "Command.h"
#include "CommandArc.h"
#include "CommandBezier.h"
#include "CommandClear.h"
#include "CommandIdle.h"
#include "CommandLine.h"
#include "CommandLoadFile.h"
#include "CommandNewFile.h"
#include "CommandSave.h"
#include "CommandSaveAs.h"
#include "CommandSetCurrentFile.h"
#include "CommandUndo.h"
#include "CommandExit.h"
#include "ShapeCommand.h"

CommandManager::~CommandManager()
{
	delete command;
	delete shapeCommand;
}

CommandManager::CommandManager(Model& m, MainWindow& w) : model(m), window(w), shapeCommand(nullptr)
{
	command= new CommandIdle();
	lineCommand();
}

void CommandManager::newFile()
{
	runCommand(new CommandNewFile());
}

void CommandManager::saveFile()
{
	runCommand(new CommandSave());
}

void CommandManager::saveAsFile()
{
	runCommand(new CommandSaveAs());
}

void CommandManager::openFile()
{
	runCommand(new CommandLoadFile());
}

void CommandManager::clearShapes()
{
	runCommand(new CommandClear());
}

void CommandManager::clearLastShape()
{
	runCommand(new CommandUndo());
}

void CommandManager::exitFile()
{
	runCommand(new CommandExit());
}

//////////////////////////////////////////////

void CommandManager::mousePressEvent(Point pos)
{
	shapeCommand->mousePressEvent(pos);
}

void CommandManager::mouseReleaseEvent(Point pos)
{
	shapeCommand->mouseReleaseEvent(pos);
	
	if(shapeCommand->getType() == LINE)
		lineCommand();

	else if (shapeCommand->hasSecondClick())
	{
		if(shapeCommand->getType() == BEZIER)
			bezierCommand();
		else if(shapeCommand->getType() == ARC)
			arcCommand();
	}
}

void CommandManager::mouseMoveEvent(Point pos)
{
	shapeCommand->mouseMoveEvent(pos);
}

//////////////////////////////////////////////

void CommandManager::arcCommand()
{
	if (shapeCommand)
		delete shapeCommand;

	shapeCommand = new CommandArc(model);
}

void CommandManager::bezierCommand()
{
	if(shapeCommand)
		delete shapeCommand;

	shapeCommand= new CommandBezier(model);
}

void CommandManager::lineCommand()
{
	if (shapeCommand)
		delete shapeCommand;

	shapeCommand = new CommandLine(model);
}

//////////////////////////////////////////////

void CommandManager::runCommand(Command* cmd)
{
	command= cmd;
	command->execute(model, window);

	delete command;

	command= new CommandIdle();
}