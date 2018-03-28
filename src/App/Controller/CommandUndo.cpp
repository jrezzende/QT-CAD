#include "CommandUndo.h"
#include "Model.h"
#include "File.h"

void CommandUndo::execute(Model& m, MainWindow& w)
{
	if (m.getCurrentFile()->getShapes().size() > 0) {
		m.getMementoFile()->addShape(m.getCurrentFile()->getShapes().back());
		m.getCurrentFile()->eraseLastShape();
	}
	else
		return;
}
