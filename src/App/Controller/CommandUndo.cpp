#include "CommandUndo.h"
#include "CADFileManager.h"
#include "ViewMediator.h"
#include "CommandHandler.h"

void CommandUndo::execute(CADFileManager& fileManager, ViewMediator& viewMediator)
{
	if (!fileManager.currentFile().shapesVector().empty()) {
		fileManager.stash().addShape(*fileManager.currentFile().shapesVector().back());
		fileManager.currentFile().eraseLastShape();
	}
   viewMediator.handler().resetMapper();
}