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
#include "CommandZoom.h"
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
   
   createLineCommand();
}

void Handler::createNewFileCmd()
{
	runCommand(new CommandNewFile());
}

void Handler::createSaveFileCmd()
{
	runCommand(new CommandSave());
}

void Handler::createLoadFileCmd()
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

void Handler::createExitFileCmd()
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
		createLineCommand();

	else if (shapeCommand->hasSecondClick())
	{
		if(shapeCommand->type() == BEZIER)
			createBezierCommand();
		else if(shapeCommand->type() == ARC)
			createArcCommand();
	}
}

void Handler::mouseMoveEvent(const Point& pos)
{
	shapeCommand->mouseMoveEvent(pos);
}

void Handler::createZoomCmd(Point& pos, float zf)
{
   runCommand(new CommandZoom(pos, zf));
}

//////////////////////////////////////////////

void Handler::sendMessageToStatusBar(std::string& msg) const
{
   viewMediator->sendMessage(msg);
}

void Handler::createArcCommand()
{
	if (shapeCommand)
		delete shapeCommand;
	shapeCommand = new CommandArc(cadFileManager, *viewMediator);

   sendMessageToStatusBar(std::string("Drawing mode selected: Arc."));
}

void Handler::createBezierCommand()
{
	if (shapeCommand)
		delete shapeCommand;
	shapeCommand= new CommandBezier(cadFileManager, *viewMediator);

   sendMessageToStatusBar(std::string("Drawing mode selected: Bezier."));
}

void Handler::createLineCommand()
{
	if (shapeCommand)
		delete shapeCommand;
	shapeCommand = new CommandLine(cadFileManager, *viewMediator);

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