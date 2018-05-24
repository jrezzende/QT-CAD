#include "CommandUndo.h"
#include "CADFileManager.h"
#include "CADFile.h"
#include "ViewMediator.h"
#include "CommandHandler.h"

void CommandUndo::execute(CADFileManager& m, ViewMediator& mediator)
{
	if (!m.currentFile().shapesVector().empty()) {
		m.mementoFile().addShape(*m.currentFile().shapesVector().back());
		m.currentFile().eraseLastShape();
	}
   mediator.manager().resetMapper();
}