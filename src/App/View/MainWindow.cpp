#include "MainWindow.h"
#include "Canvas.h"
#include "CommandManager.h"
#include "qt_windows.h"

#include "qtoolbar.h"
#include "qmenubar.h"
#include "qevent.h"
#include "qmessagebox.h"
#include "qshortcut.h"

MainWindow::~MainWindow()
{
	delete nav;
}

MainWindow::MainWindow(QMainWindow* parent) : QMainWindow(parent), manager(nullptr)
{	
	createToolbar();
	createConnections();
	createShortcuts();
	setLayout();

	showMaximized();
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

//////////////////////////////////////

void MainWindow::newFile()
{
	manager->newFile();
}

void MainWindow::loadFile()
{
	manager->loadFile();
}

void MainWindow::save()
{
	manager->saveFile();
}

void MainWindow::exit()
{
	manager->exitFile();
}

std::string MainWindow::getText()
{
	return std::string();
}

std::string MainWindow::getFileName()
{
	return std::string();
}

Canvas * MainWindow::createCanvas()
{
	return new Canvas(manager, this);;
}

void MainWindow::createConnections()
{
	QObject::connect(
	exitAction, SIGNAL(triggered()),
	this, SLOT(verifyExitAction())
	);

	QObject::connect(
	newFileAction, SIGNAL(triggered()),
	this, SLOT(newFile())
	);

	QObject::connect(
	loadFileAction, SIGNAL(triggered()),
	this, SLOT(loadFile())
	);

	QObject::connect(
	saveAction, SIGNAL(triggered()),
	this, SLOT(save())
	);

	QObject::connect(
	lineAction, SIGNAL(triggered()),
	this, SLOT(lineSignal())
	);

	QObject::connect(
	bezierAction, SIGNAL(triggered()),
	this, SLOT(bezierSignal())
	);

	QObject::connect(
	arcAction, SIGNAL(triggered()),
	this, SLOT(arcSignal())
	);
}

void MainWindow::createShortcuts()
{
	connect(new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_N), this), &QShortcut::activated, this, &MainWindow::newFile);
}

void MainWindow::verifyExitAction() 
{
	if (QMessageBox::question(this, "Quit?", "Are you sure you want to exit?", 
		QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
		exit();
}

//////////////////////////////////////

void MainWindow::paintEvent(QPaintEvent * event)
{
	nav->setMaximumWidth(GetSystemMetrics(SM_CXSCREEN));
}

//////////////////////////////////////

void MainWindow::lineSignal()
{
	manager->lineCommand();
}

void MainWindow::bezierSignal()
{
	manager->bezierCommand();
}

void MainWindow::arcSignal()
{
	manager->arcCommand();
}