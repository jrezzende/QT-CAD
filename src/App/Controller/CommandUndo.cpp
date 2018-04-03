#include "CommandUndo.h"
#include "Model.h"
#include "CADFile.h"

void CommandUndo::execute(Model& m, MainWindow& w)
{
	if (!m.getCurrentFile()->getShapes().empty()) {
		m.addShapeToMemento(m.getCurrentFile()->getShapes().back());
		m.getCurrentFile()->eraseLastShape();
	}
}
