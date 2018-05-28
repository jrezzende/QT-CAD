#include "CommandClear.h"
#include "CADFileManager.h"
#include "ViewMediator.h"

void CommandClear::execute(CADFileManager& m, ViewMediator& mediator)
{
	if(m.current().shapesVector().empty())
		return;

	for (size_t i = m.current().shapesVector().size() - 1; i > 0; i--)
		m.stash().addShape(*m.current().shapesVector().at(i));

	m.stash().addShape(*m.current().shapesVector().front());
	m.current().eraseAllShapes();
	m.setRedoFlag(true);
}