#include "CommandRedo.h"
#include "CADFileManager.h"
#include "ViewMediator.h"
#include "CommandHandler.h"

void CommandRedo::execute(CADFileManager& fileManager, ViewMediator& viewMediator)
{
	if (fileManager.stash().shapesVector().empty())
		return;

	if (fileManager.redo()) {
		for (size_t i = fileManager.stash().shapesVector().size() - 1; i > 0; i--)
         fileManager.currentFile().addFromRedo(*fileManager.stash().shapesVector().at(i));

		fileManager.currentFile().addFromRedo(*fileManager.stash().shapesVector().front());
		fileManager.stash().eraseAllShapes();
		fileManager.setRedoFlag(false);
	}
	else {
		fileManager.currentFile().addFromRedo(*fileManager.stash().shapesVector().back());
		fileManager.stash().eraseLastShape();
	}
	
   viewMediator.handler().resetMapper();
	fileManager.currentFile().reprint();
}