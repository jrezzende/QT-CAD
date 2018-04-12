#include "CommandExit.h"
#include "CADFileManager.h"

void CommandExit::execute(CADFileManager& m, ViewMediator& mediator)
{
	m.deleteFiles();

	exit(0);
}
