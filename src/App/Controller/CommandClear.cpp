#include "CommandClear.h"
#include "CADFileManager.h"
#include "ViewMediator.h"

void CommandClear::execute(CADFileManager& m, ViewMediator& mediator)
{
	if(m.currentFile().shapesVector().empty())
		return;

	for (size_t i = m.currentFile().shapesVector().size() - 1; i > 0; i--)
		m.stash().addShape(*m.currentFile().shapesVector().at(i));

	m.stash().addShape(*m.currentFile().shapesVector().front());
	m.currentFile().eraseAllShapes();
	m.setRedoFlag(true);
}