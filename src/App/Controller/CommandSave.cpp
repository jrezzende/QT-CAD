#include "CommandSave.h"
#include "Model.h"
#include "MainWindow.h"

#include <iostream>

void CommandSave::execute(Model& m, MainWindow& w)
{
	// std::cout << "save file" << std::endl; #test purposes only

	m.getCurrentFile()->setStatus(SAVED);
}
