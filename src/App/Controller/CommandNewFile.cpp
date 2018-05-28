#include "CommandNewFile.h"
#include "MainWindow.h"
#include "CADFileManager.h"
#include "CommandHandler.h"
#include "CADFile.h"
#include "ViewMediator.h"

void CommandNewFile::execute(CADFileManager& fileManager, ViewMediator& viewMediator)
{
   fileManager.clearShapes();

   const auto file= new CADFile("untitled", &viewMediator.canvas());
	const auto stashFile= new CADFile("stashFile", file->canvas());

	fileManager.setCurrentFile(file);
	fileManager.setStashFile(stashFile);

   viewMediator.handler().resetMapper();
	viewMediator.setWindowWidget(file->canvas());
	viewMediator.setTitle(QString::fromStdString(file->fileName()));
}