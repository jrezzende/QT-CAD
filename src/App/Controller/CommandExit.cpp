#include "CommandExit.h"
#include "Model.h"

void CommandExit::execute(Model & m, MainWindow & w)
{
	m.deleteAllFiles();

	exit(0);
}
