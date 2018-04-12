#include "CommandRedo.h"
#include "CADFileManager.h"

void CommandRedo::execute(CADFileManager & m, ViewMediator& mediator)
{
	if (m.getMementoFile()->getShapes().empty())
		return;

	if (m.getRedoFlag()) {	
		for (size_t i = m.getMementoFile()->getShapes().size() - 1; i > 0; i--)
			m.getCurrentFile()->addFromRedo(*m.getMementoFile()->getShapes().at(i));

		m.getCurrentFile()->addFromRedo(*m.getMementoFile()->getShapes().front());
		m.getMementoFile()->eraseAllShapes();
		m.setRedoFlag(false);
	}
	else {
		m.getCurrentFile()->addFromRedo(*m.getMementoFile()->getShapes().back());
		m.getMementoFile()->eraseLastShape();
	}
		
	m.getCurrentFile()->reprint();
}
