#include "MainWindow.h"
#include "qtoolbar.h"
#include "qmenubar.h"
#include "Canvas.h"
#include "qevent.h"
#include "qmessagebox.h"

//TODO//ADDICONS
//TODO// all window functions must be on app

MainWindow::~MainWindow()
{
	delete nav;
}

MainWindow::MainWindow()
{	
	auto p= Canvas::getInstance();
	setCentralWidget(p);

	createToolbar();
	setLayout();

	QObject::connect(
		exitAction, SIGNAL(triggered()), 
		this, SLOT(verifyExitAction())
	);

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
	clearAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_X));

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

//must verify if the current file was saved (bool saved)

void MainWindow::verifyExitAction() 
{
	if (QMessageBox::question(this, "Quit", "Are you sure you want to exit?", 
		QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
		close();
}

//void MainWindow::verifyClearAction()
//{
//	if()
//}
