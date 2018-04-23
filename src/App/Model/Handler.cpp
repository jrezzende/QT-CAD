#include <string>

#include "Handler.h"
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

Handler::~Handler()
{
	delete currentCmd;
	delete shapeCommand;
}

Handler::Handler(CADFileManager& m) : 
cadFileManager(m), currentCmd(nullptr), shapeCommand(nullptr)
{
   viewMediator= new ViewMediator(this);
   m.setCanvas(viewMediator->canvas());
   viewMediator->setWindowWidget(&viewMediator->canvas());
   
   lineCommand();
}

void Handler::newFileCmd()
{
	runCommand(new CommandNewFile());
}

void Handler::saveFileCmd()
{
	runCommand(new CommandSave());
}

void Handler::loadFileCmd()
{
	runCommand(new CommandLoadFile());
}

void Handler::clearShapes()
{
	runCommand(new CommandClear());
}

void Handler::eraseLastShape()
{
	runCommand(new CommandUndo());
}

void Handler::redoShape()
{
	runCommand(new CommandRedo());
}

void Handler::exitFileCmd()
{
	runCommand(new CommandExit());
}

//////////////////////////////////////////////

void Handler::mousePressEvent(const Point& pos)
{
	shapeCommand->mousePressEvent(pos);
}

void Handler::mouseReleaseEvent(const Point& pos)
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

void Handler::mouseMoveEvent(const Point& pos)
{
	shapeCommand->mouseMoveEvent(pos);
}

//////////////////////////////////////////////

void Handler::sendMessageToStatusBar(std::string& msg) const
{
   viewMediator->sendMessage(msg);
}

void Handler::arcCommand()
{
	if (shapeCommand)
		delete shapeCommand;
	shapeCommand = new CommandArc(cadFileManager);

   sendMessageToStatusBar(std::string("Drawing mode selected: Arc."));
}

void Handler::bezierCommand()
{
	if (shapeCommand)
		delete shapeCommand;
	shapeCommand= new CommandBezier(cadFileManager);

   sendMessageToStatusBar(std::string("Drawing mode selected: Bezier."));
}

void Handler::lineCommand()
{
	if (shapeCommand)
		delete shapeCommand;
	shapeCommand = new CommandLine(cadFileManager);

   sendMessageToStatusBar(std::string("Drawing mode selected: Line."));
}

//////////////////////////////////////////////

void Handler::runCommand(Command* cmd)
{
	currentCmd= cmd;
   currentCmd->execute(cadFileManager, *viewMediator);

	delete currentCmd;

   currentCmd = new CommandIdle();
}