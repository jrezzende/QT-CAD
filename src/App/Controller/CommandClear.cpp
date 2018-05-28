#include "CommandClear.h"
#include "CADFileManager.h"
#include "ViewMediator.h"

void CommandClear::execute(CADFileManager& fileManager, ViewMediator& mediator)
{
	if(fileManager.current().shapesVector().empty())
		return;

	for (size_t i = fileManager.current().shapesVector().size() - 1; i > 0; i--)
      fileManager.stash().addShape(*fileManager.current().shapesVector().at(i));

	fileManager.stash().addShape(*fileManager.current().shapesVector().front());
	fileManager.current().eraseAllShapes();
	fileManager.setRedoFlag(true);
}