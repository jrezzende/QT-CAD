#include <string>

#include "Manager.h"
#include "Point.h"
#include "CADFileManager.h"
#include "ViewMediator.h"
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

Manager::~Manager()
{
	delete currentCmd;
	delete shapeCommand;
}

Manager::Manager(CADFileManager& m) : 
cadFileManager(m), currentCmd(nullptr), shapeCommand(nullptr)
{
   viewMediator= new ViewMediator(this);
   m.setCanvas(viewMediator->canvas());
   viewMediator->setWindowWidget(&viewMediator->canvas());
   
   lineCommand();
}

void Manager::newFileCmd()
{
	runCommand(new CommandNewFile());
}

void Manager::saveFileCmd()
{
	runCommand(new CommandSave());
}

void Manager::loadFileCmd()
{
	runCommand(new CommandLoadFile());
}

void Manager::clearShapes()
{
	runCommand(new CommandClear());
}

void Manager::eraseLastShape()
{
	runCommand(new CommandUndo());
}

void Manager::redoShape()
{
	runCommand(new CommandRedo());
}

void Manager::exitFileCmd()
{
	runCommand(new CommandExit());
}

//////////////////////////////////////////////

void Manager::mousePressEvent(const Point& pos)
{
	shapeCommand->mousePressEvent(pos);
}

void Manager::mouseReleaseEvent(const Point& pos)
{
	shapeCommand->mouseReleaseEvent(pos);
	
	if(shapeCommand->type() == LINE)
		lineCommand();

	else if (shapeCommand->hasSecondClick())
	{
		if(shapeCommand->type() == BEZIER)
			bezierCommand();
		else if(shapeCommand->type() == ARC)
			arcCommand();
	}
}

void Manager::mouseMoveEvent(const Point& pos)
{
	shapeCommand->mouseMoveEvent(pos);
}

//////////////////////////////////////////////

void Manager::sendMessageToStatusBar(std::string& msg) const
{
   viewMediator->sendMessage(msg);
}

void Manager::arcCommand()
{
	if (shapeCommand)
		delete shapeCommand;
	shapeCommand = new CommandArc(cadFileManager);

   sendMessageToStatusBar(std::string("Drawing mode selected: Arc."));
}

void Manager::bezierCommand()
{
	if (shapeCommand)
		delete shapeCommand;
	shapeCommand= new CommandBezier(cadFileManager);

   sendMessageToStatusBar(std::string("Drawing mode selected: Bezier."));
}

void Manager::lineCommand()
{
	if (shapeCommand)
		delete shapeCommand;
	shapeCommand = new CommandLine(cadFileManager);

   sendMessageToStatusBar(std::string("Drawing mode selected: Line."));
}

//////////////////////////////////////////////

void Manager::runCommand(Command* cmd)
{
	currentCmd= cmd;
   currentCmd->execute(cadFileManager, *viewMediator);

	delete currentCmd;

   currentCmd = new CommandIdle();
}