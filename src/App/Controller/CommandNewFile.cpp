#include "CommandNewFile.h"
#include "MainWindow.h"
#include "CADFileManager.h"
#include "CADFile.h"
#include "ViewMediator.h"

void CommandNewFile::execute(CADFileManager& m, ViewMediator& mediator)
{
   m.clearShapes();
   m.deleteFiles();

	const auto file= new CADFile("untitled", &mediator.canvas());	
	const auto mementoFile= new CADFile("memento", file->canvas());

	m.setCurrentFile(file);
	m.setMementoFile(mementoFile);

	mediator.setWindowWidget(file->canvas());
	mediator.setTitle(QString::fromStdString(file->fileName()));
}