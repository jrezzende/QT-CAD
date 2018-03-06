#include "CommandUndo.h"
#include "Model.h"

void CommandUndo::execute(Model & m, MainWindow & w)
{
	m.getCurrentFile()->eraseLastShape();
}
