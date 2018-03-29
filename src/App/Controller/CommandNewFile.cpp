#include "CommandNewFile.h"
#include "MainWindow.h"
#include "Model.h"
#include "File.h"
#include "Canvas.h"

#include <sstream>

void CommandNewFile::execute(Model& m, MainWindow& w)
{
	auto file= new File("untitled", w.createCanvas());	
	auto mementoFile= new File("memento", file->getCanvas());

	m.setCurrentFile(file);
	m.addFile(file);
	m.addFile(mementoFile);
	m.setMementoFile(mementoFile);

	w.setCentralWidget(file->getCanvas());
	w.setWindowTitle(QString::fromStdString(file->getFileName()));
}