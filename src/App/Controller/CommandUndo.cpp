#include "CommandUndo.h"
#include "Model.h"

#include <iostream>

void CommandUndo::execute(Model & m, MainWindow & w)
{
	m.getCurrentFile()->eraseLastShape();
}
