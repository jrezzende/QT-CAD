#include "CommandClear.h"
#include "Model.h"
#include "MainWindow.h"

void CommandClear::execute(Model & m, MainWindow & w)
{
	if(m.getCurrentFile()->getShapes().size() == 0)
		return;
	else {
		for (size_t i = m.getCurrentFile()->getShapes().size() - 1; i > 0; i--)
			m.getMementoFile()->addShape(m.getCurrentFile()->getShapes().at(i));
	}
	m.getMementoFile()->addShape(m.getCurrentFile()->getShapes().front());
	m.getCurrentFile()->eraseAllShapes();
	m.setMementoFlag(true);
}
