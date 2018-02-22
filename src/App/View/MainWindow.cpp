#include "MainWindow.h"
#include "qtoolbar.h"
#include "qmenubar.h"
#include "Painter.h"
#include "qevent.h"

//TODO//ADDICONS
//TODO// all window functions must be on app

MainWindow::~MainWindow()
{
	delete nav;
}

MainWindow::MainWindow()
{	
	auto p= Painter::getInstance();
	setCentralWidget(p);

	createToolbar();
	setLayout();

	QObject::connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

	show();
}

void MainWindow::setLayout()
{
	setMinimumSize(1024, 768);
	setWindowTitle("QT Cad");
}

void MainWindow::createToolbar()
{
	nav = menuBar();

	fileMenu = new QMenu();
	shapesMenu = new QMenu();

	newFileAction = new QAction();
	newFileAction = new QAction();
	loadFileAction = new QAction();
	saveAction = new QAction();
	saveAsAction = new QAction();
	undoAction = new QAction();
	clearAction = new QAction();
	exitAction = new QAction();

	lineAction = new QAction();
	bezierAction = new QAction();
	arcAction = new QAction();

	fileMenu->setTitle("File");
	newFileAction->setText("New File");
	loadFileAction->setText("Load File");
	saveAction->setText("Save");
	saveAsAction->setText("Save As...");
	undoAction->setText("Undo");
	clearAction->setText("Clear");
	exitAction->setText("Exit");

	shapesMenu->setTitle("Shapes");
	lineAction->setText("Line");
	bezierAction->setText("Bezier");
	arcAction->setText("Arc");

	newFileAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_N));
	loadFileAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
	saveAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));
	undoAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z));
	clearAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Asterisk));

	lineAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_L));
	bezierAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_B));
	arcAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_A));

	nav->addMenu(fileMenu);
	fileMenu->addAction(newFileAction);
	fileMenu->addAction(loadFileAction);
	fileMenu->addAction(saveAsAction);
	fileMenu->addAction(saveAction);
	fileMenu->addAction(undoAction);
	fileMenu->addAction(clearAction);
	fileMenu->addAction(exitAction);

	nav->addMenu(shapesMenu);
	shapesMenu->addAction(lineAction);
	shapesMenu->addAction(bezierAction);
	shapesMenu->addAction(arcAction);
}
