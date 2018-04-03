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
#include "CommandUndo.h"
#include "CommandRedo.h"
#include "CommandExit.h"
#include "ShapeCommand.h"

CommandManager::~CommandManager()
{
	delete command;
	delete shapeCommand;
}

CommandManager::CommandManager(Model& m, MainWindow& w) : 
model(m), window(w), shapeCommand(nullptr), firstPoint(nullptr), lastPoint(nullptr)
{
	lineCommand();
}

void CommandManager::newFileCmd()
{
	runCommand(new CommandNewFile());
}

void CommandManager::saveFileCmd()
{
	runCommand(new CommandSave());
}

void CommandManager::loadFileCmd()
{
	runCommand(new CommandLoadFile());
}

void CommandManager::clearShapes()
{
	runCommand(new CommandClear());
}

void CommandManager::eraseLastShape()
{
	runCommand(new CommandUndo());
}

void CommandManager::redoShape()
{
	runCommand(new CommandRedo());
}

void CommandManager::exitFileCmd()
{
	runCommand(new CommandExit());
}

//////////////////////////////////////////////

void CommandManager::mousePressEvent(const Point& pos)
{
	shapeCommand->mousePressEvent(pos);
}

void CommandManager::mouseReleaseEvent(const Point& pos)
{
	shapeCommand->mouseReleaseEvent(pos);
	
	if(shapeCommand->getShape() == LINE)
		lineCommand();

	else if (shapeCommand->hasSecondClick())
	{
		if(shapeCommand->getShape() == BEZIER)
			bezierCommand();
		else if(shapeCommand->getShape() == ARC)
			arcCommand();
	}
}

void CommandManager::mouseMoveEvent(const Point& pos)
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
	if (shapeCommand)
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