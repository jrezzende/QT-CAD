#include "CommandNewFile.h"
#include "MainWindow.h"
#include "Model.h"
#include "CADFile.h"
#include "Canvas.h"

#include <sstream>

void CommandNewFile::execute(Model& m, MainWindow& w)
{
	const auto file= new CADFile("untitled", w.createCanvas());	
	const auto mementoFile= new CADFile("memento", file->getCanvas());

	m.setCurrentFile(file);
	m.addFile(file);
	m.addFile(mementoFile);
	m.setMementoFile(mementoFile);

	w.setCentralWidget(file->getCanvas());
	w.setWindowTitle(QString::fromStdString(file->getFileName()));
}