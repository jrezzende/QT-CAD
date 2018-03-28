#include "CommandRedo.h"
#include "Model.h"

void CommandRedo::execute(Model & m, MainWindow & w)
{
	if (m.getMementoFile()->getShapes().size() == 0)
		return;

	if (m.getMementoFlag()) {	
		for (size_t i = m.getMementoFile()->getShapes().size() - 1; i > 0; i--)
			m.getCurrentFile()->addShape(m.getMementoFile()->getShapes().at(i));

		m.getCurrentFile()->addShape(m.getMementoFile()->getShapes().front());
		m.getMementoFile()->eraseAllShapes();
	}
	else {
		m.getCurrentFile()->addShape(m.getMementoFile()->getShapes().back());
		m.getMementoFile()->eraseLastShape();
	}
		
	m.getCurrentFile()->reprint();
}
