#include "CommandUndo.h"
#include "CADFileManager.h"
#include "CADFile.h"

void CommandUndo::execute(CADFileManager& m, ViewMediator& mediator)
{
	if (!m.getCurrentFile()->getShapes().empty()) {
		m.getMementoFile()->mementoAddShape(*m.getCurrentFile()->getShapes().back());
		m.getCurrentFile()->eraseLastShape();
	}
}
