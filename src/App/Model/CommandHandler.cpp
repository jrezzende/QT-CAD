#include <string>

#include "CommandHandler.h"
#include "Point.h"
#include "CADFileManager.h"
#include "ViewMediator.h"
#include "Command.h"
#include "CommandArc.h"
#include "CommandBezier.h"
#include "CommandClear.h"
#include "CommandIdle.h"
#include "CommandLine.h"
#include "CommandZoom.h"
#include "CommandLoadFile.h"
#include "CommandNewFile.h"
#include "CommandSave.h"
#include "CommandUndo.h"
#include "CommandRedo.h"
#include "CommandExit.h"
#include "ShapeCommand.h"

CommandHandler::~CommandHandler()
{
	delete currentCmd;
	delete shapeCommand;
}

CommandHandler::CommandHandler(CADFileManager& m) :
cadFileManager(m), currentCmd(nullptr), shapeCommand(nullptr)
{
   viewMediator= new ViewMediator(this);
   m.setCanvas(viewMediator->canvas());
   viewMediator->setWindowWidget(&viewMediator->canvas());
   
   createLineCommand();
}

void CommandHandler::createNewFileCmd()
{
	runCommand(new CommandNewFile());
}

void CommandHandler::createSaveFileCmd()
{
	runCommand(new CommandSave());
}

void CommandHandler::createLoadFileCmd()
{
	runCommand(new CommandLoadFile());
}

void CommandHandler::clearShapes()
{
	runCommand(new CommandClear());
}

void CommandHandler::eraseLastShape()
{
	runCommand(new CommandUndo());
}

void CommandHandler::redoShape()
{
	runCommand(new CommandRedo());
}

void CommandHandler::createExitFileCmd()
{
	runCommand(new CommandExit());
}

//////////////////////////////////////////////

void CommandHandler::mousePressEvent(const Point& pos)
{
	shapeCommand->mousePressEvent(pos);
}

void CommandHandler::mouseReleaseEvent(const Point& pos)
{
	shapeCommand->mouseReleaseEvent(pos);
	
	if(shapeCommand->type() == LINE)
		createLineCommand();

	else if (shapeCommand->hasSecondClick())
	{
		if(shapeCommand->type() == BEZIER)
			createBezierCommand();
		else if(shapeCommand->type() == ARC)
			createArcCommand();
	}
}

void CommandHandler::mouseMoveEvent(const Point& pos)
{
	shapeCommand->mouseMoveEvent(pos);
}

void CommandHandler::createZoomCmd(float zf)
{
   runCommand(new CommandZoom(zf));
}

//////////////////////////////////////////////

void CommandHandler::sendMessageToStatusBar(std::string& msg) const
{
   viewMediator->sendMessage(msg);
}

void CommandHandler::createArcCommand()
{
	if (shapeCommand)
		delete shapeCommand;
	shapeCommand = new CommandArc(cadFileManager, *viewMediator);

   sendMessageToStatusBar(std::string("Drawing mode selected: Arc."));
}

void CommandHandler::createBezierCommand()
{
	if (shapeCommand)
		delete shapeCommand;
	shapeCommand= new CommandBezier(cadFileManager, *viewMediator);

   sendMessageToStatusBar(std::string("Drawing mode selected: Bezier."));
}

void CommandHandler::createLineCommand()
{
	if (shapeCommand)
		delete shapeCommand;
	shapeCommand = new CommandLine(cadFileManager, *viewMediator);

   sendMessageToStatusBar(std::string("Drawing mode selected: Line."));
}

//////////////////////////////////////////////

void CommandHandler::runCommand(Command* cmd)
{
	currentCmd= cmd;
   currentCmd->execute(cadFileManager, *viewMediator);

	delete currentCmd;

   currentCmd = new CommandIdle();
}