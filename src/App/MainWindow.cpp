#include "MainWindow.h"
#include "qtoolbar.h"
#include "qmenubar.h"

MainWindow::MainWindow()
{	
	auto p= Painter::getInstance();
	setCentralWidget(p);

	auto toolbar= menuBar();
	
	auto file= new QMenu("File");
	auto newFile= new QAction("New File - Ctrl + N");
	auto loadFile= new QAction("Load File - Ctrl + O");
	auto save= new QAction("Save -  Ctrl + S");
	auto saveAs= new QAction("Save As...");
	auto undo= new QAction("Undo - Ctrl + Z");
	auto exit= new QAction("Exit");
	toolbar->addMenu(file);
	file->addAction(newFile);
	file->addAction(loadFile);
	file->addAction(saveAs);
	file->addAction(save);
	file->addAction(undo);
	file->addAction(exit);
	
	auto shapes= new QMenu("Shapes");
	auto line= new QAction("Line - Ctrl + L");
	auto bezier= new QAction("Bezier - Ctrl + B");
	auto arc= new QAction("Arc - Ctrl + A");
	toolbar->addMenu(shapes);
	shapes->addAction(line);
	shapes->addAction(bezier);
	shapes->addAction(arc);

	setMinimumSize(800, 600);
	setWindowTitle("QT Cad");
	show();
}
