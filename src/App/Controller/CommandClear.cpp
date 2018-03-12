#include "CommandClear.h"
#include "Model.h"
#include "MainWindow.h"
#include "Canvas.h"

void CommandClear::execute(Model & m, MainWindow & w)
{
	m.getCurrentFile()->eraseAllShapes();
}
