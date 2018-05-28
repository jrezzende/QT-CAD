#include "CommandUndo.h"
#include "CADFileManager.h"
#include "ViewMediator.h"
#include "CommandHandler.h"

void CommandUndo::execute(CADFileManager& fileManager, ViewMediator& viewMediator)
{
	if (!fileManager.current().shapesVector().empty()) {
		fileManager.stash().addShape(*fileManager.current().shapesVector().back());
		fileManager.current().eraseLastShape();
	}
   viewMediator.handler().resetMapper();
}