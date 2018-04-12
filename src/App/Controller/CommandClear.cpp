#include "CommandClear.h"
#include "CADFileManager.h"
#include "ViewMediator.h"

void CommandClear::execute(CADFileManager& m, ViewMediator& mediator)
{
	if(m.getCurrentFile()->getShapes().empty())
		return;
	else {
		for (size_t i = m.getCurrentFile()->getShapes().size() - 1; i > 0; i--)
			m.getMementoFile()->mementoAddShape(*m.getCurrentFile()->getShapes().at(i));
	}
	m.getMementoFile()->mementoAddShape(*m.getCurrentFile()->getShapes().front());
	m.getCurrentFile()->eraseAllShapes();
	m.setRedoFlag(true);
}