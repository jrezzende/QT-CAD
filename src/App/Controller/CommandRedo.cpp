#include "CommandRedo.h"
#include "CADFileManager.h"

void CommandRedo::execute(CADFileManager & m, ViewMediator& mediator)
{
	if (m.mementoFile()->shapesVector().empty())
		return;

	if (m.redo()) {	
		for (size_t i = m.mementoFile()->shapesVector().size() - 1; i > 0; i--)
			m.currentFile()->addFromRedo(*m.mementoFile()->shapesVector().at(i));

		m.currentFile()->addFromRedo(*m.mementoFile()->shapesVector().front());
		m.mementoFile()->eraseAllShapes();
		m.setRedoFlag(false);
	}
	else {
		m.currentFile()->addFromRedo(*m.mementoFile()->shapesVector().back());
		m.mementoFile()->eraseLastShape();
	}
		
	m.currentFile()->reprint();
}