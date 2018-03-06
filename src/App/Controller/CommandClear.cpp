#include "CommandClear.h"
#include "Model.h"

void CommandClear::execute(Model & m, MainWindow & w)
{
	m.getCurrentFile()->eraseAllShapes();
}
