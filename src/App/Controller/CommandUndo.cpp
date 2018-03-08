#include "CommandUndo.h"
#include "Model.h"

#include <iostream>

void CommandUndo::execute(Model & m, MainWindow & w)
{
	if(!m.getCurrentFile()->getShapes().empty())
		m.getCurrentFile()->eraseLastShape();
	else
		return;

	// std::cout << "undo" << std::endl; #test purposes only
}
