#include "CommandNewFile.h"
#include "MainWindow.h"
#include "CADFileManager.h"
#include "CADFile.h"
#include "ViewMediator.h"

#include <sstream>

void CommandNewFile::execute(CADFileManager& m, ViewMediator& mediator)
{
	const auto file= new CADFile("untitled", &mediator.getCanvas());	
	const auto mementoFile= new CADFile("memento", file->getCanvas());

	m.setCurrentFile(file);
	m.setMementoFile(mementoFile);

	mediator.setWindowWidget(file->getCanvas());
	mediator.setTitle(QString::fromStdString(file->getFileName()));
}