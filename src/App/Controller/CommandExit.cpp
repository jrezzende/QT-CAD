#include "CommandExit.h"
#include "CADFileManager.h"

void CommandExit::execute(CADFileManager& fileManager, ViewMediator& mediator)
{
   exit(0);
}