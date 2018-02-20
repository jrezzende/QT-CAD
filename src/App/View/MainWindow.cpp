#include "MainWindow.h"
#include "qtoolbar.h"
#include "qmenubar.h"
#include "Painter.h"
#include "qevent.h"

MainWindow::MainWindow()
{	
	auto p= Painter::getInstance();
	setCentralWidget(p);

	createToolbar();
	setLayout();

	QObject::connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));	

	show();
}

void MainWindow::closeEvent(QCloseEvent* event)
{
	if (flagSave()) {
		writeSpecifications();
		event->accept();
	} else {
		event->ignore();
	}
}

void MainWindow::setLayout()
{
	setMinimumSize(800, 600);
	setWindowTitle("QT Cad");
}

void MainWindow::createToolbar()
{
	fileMenu = new QMenu();

	newFileAction = new QAction();
	newFileAction = new QAction();
	loadFileAction = new QAction();
	saveAction = new QAction();
	saveAsAction = new QAction();
	undoAction = new QAction();
	clearAction = new QAction();
	exitAction = new QAction();

	shapesMenu = new QMenu();

	lineAction = new QAction();
	bezierAction = new QAction();
	arcAction = new QAction();

	auto toolbar = menuBar();

	fileMenu->setTitle("File");
	newFileAction->setText("New File - Ctrl + N");
	loadFileAction->setText("Load File - Ctrl + O");
	saveAction->setText("Save - Ctrl + S");
	saveAsAction->setText("Save As...");
	undoAction->setText("Undo - Ctrl + Z");
	clearAction->setText("Clear - Ctrl + X");
	exitAction->setText("Exit");

	toolbar->addMenu(fileMenu);
	fileMenu->addAction(newFileAction);
	fileMenu->addAction(loadFileAction);
	fileMenu->addAction(saveAsAction);
	fileMenu->addAction(saveAction);
	fileMenu->addAction(undoAction);
	fileMenu->addAction(clearAction);
	fileMenu->addAction(exitAction);

	shapesMenu->setTitle("Shapes");
	lineAction->setText("Line - Ctrl + L");
	bezierAction->setText("Bezier - Ctrl + B");
	arcAction->setText("Arc - Ctrl + A");

	toolbar->addMenu(shapesMenu);
	shapesMenu->addAction(lineAction);
	shapesMenu->addAction(bezierAction);
	shapesMenu->addAction(arcAction);
}
