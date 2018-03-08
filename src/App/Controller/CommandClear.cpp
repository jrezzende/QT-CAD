#include "CommandClear.h"
#include "Model.h"

#include <iostream>

void CommandClear::execute(Model & m, MainWindow & w)
{
	if(!m.getCurrentFile()->getShapes().empty())
		m.getCurrentFile()->eraseAllShapes();
	else
		return;

	// std::cout << "clear" << std::endl; #test purposes only
}
