#include "CommandNewFile.h"
#include "MainWindow.h"
#include "Model.h"
#include "File.h"
#include "Canvas.h"

#include <sstream>

void CommandNewFile::execute(Model& m, MainWindow& w)
{
	File* file= new File(w.getNewFileName(), w.createCanvas());	

	m.setCurrentFile(file);
	m.newFile(file);

	w.setCentralWidget(file->getCanvas());
	w.setWindowTitle(QString::fromStdString(file->getFileName()));
}
