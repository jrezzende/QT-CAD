#include "CommandNewFile.h"
#include "MainWindow.h"
#include "CADFileManager.h"
#include "CommandHandler.h"
#include "CADFile.h"
#include "ViewMediator.h"

void CommandNewFile::execute(CADFileManager& m, ViewMediator& mediator)
{
   m.clearShapes();

   const auto file= new CADFile("untitled", &mediator.canvas());
	const auto stashFile= new CADFile("stashFile", file->canvas());

	m.setCurrentFile(file);
	m.setStashFile(stashFile);

   mediator.manager().resetMapper();
	mediator.setWindowWidget(file->canvas());
	mediator.setTitle(QString::fromStdString(file->fileName()));
}