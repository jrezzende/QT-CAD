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
	delete manager;
}

MainWindow::MainWindow(QMainWindow* parent) : QMainWindow(parent), manager(nullptr)
{
	createToolbarAndConnections();
	createShortcuts();
	setLayout();

	showMaximized();
}

void MainWindow::setLayout()
{
	setMinimumSize(1024, 768);
	setWindowTitle("QT Cad");
}

void MainWindow::createToolbarAndConnections()
{
	auto nav = menuBar();

	auto fileMenu = new QMenu();
	auto shapesMenu = new QMenu();

	auto newFileAction = new QAction();
	auto loadFileAction = new QAction();
	auto saveAction = new QAction();
	auto undoAction = new QAction();
	auto clearAction = new QAction();
	auto exitAction = new QAction();

	auto lineAction = new QAction();
	auto bezierAction = new QAction();
	auto arcAction = new QAction();

	fileMenu->setTitle("File");
	newFileAction->setText("New File");
	loadFileAction->setText("Load File");
	saveAction->setText("Save");
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
	fileMenu->addAction(saveAction);
	fileMenu->addAction(undoAction);
	fileMenu->addAction(clearAction);
	fileMenu->addAction(exitAction);

	nav->addMenu(shapesMenu);
	shapesMenu->addAction(lineAction);
	shapesMenu->addAction(bezierAction);
	shapesMenu->addAction(arcAction);

	newFileAction->setShortcutContext(Qt::WidgetWithChildrenShortcut);
	loadFileAction->setShortcutContext(Qt::WidgetWithChildrenShortcut);
	saveAction->setShortcutContext(Qt::WidgetWithChildrenShortcut);
	undoAction->setShortcutContext(Qt::WidgetWithChildrenShortcut);
	clearAction->setShortcutContext(Qt::WidgetWithChildrenShortcut);

	lineAction->setShortcutContext(Qt::WidgetWithChildrenShortcut);
	bezierAction->setShortcutContext(Qt::WidgetWithChildrenShortcut);
	arcAction->setShortcutContext(Qt::WidgetWithChildrenShortcut);

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

	QObject::connect(
		undoAction, SIGNAL(triggered()),
		this, SLOT(undo())
	);

	QObject::connect(
		clearAction, SIGNAL(triggered()),
		this, SLOT(clear())
	);
}

//////////////////////////////////////

void MainWindow::newFile()
{
	manager->newFileCmd();
}

void MainWindow::loadFile()
{
	manager->loadFileCmd();
}

void MainWindow::save()
{
	manager->saveFileCmd();
}

void MainWindow::undo()
{
	manager->eraseLastShape();
}

void MainWindow::clear()
{
	manager->clearShapes();
}

void MainWindow::exit()
{
	manager->exitFileCmd();
}

std::string MainWindow::getFileName()
{
	return QFileDialog::getSaveFileName(this).toStdString();
}

std::string MainWindow::getOpenFileName()
{
	return QFileDialog::getOpenFileName(this, tr("Open File")).toStdString();
}

Canvas * MainWindow::createCanvas()
{
	return new Canvas(manager, this);
}

void MainWindow::createShortcuts()
{
	connect(new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_N), this), &QShortcut::activated, this, &MainWindow::newFile);

	connect(new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_O), this), &QShortcut::activated, this, &MainWindow::loadFile);

	connect(new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_S), this), &QShortcut::activated, this, &MainWindow::save);

	connect(new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_L), this), &QShortcut::activated, this, &MainWindow::lineSignal);

	connect(new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_B), this), &QShortcut::activated, this, &MainWindow::bezierSignal);

	connect(new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_A), this), &QShortcut::activated, this, &MainWindow::arcSignal);

	connect(new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z), this), &QShortcut::activated, this, &MainWindow::undo);

	connect(new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_X), this), &QShortcut::activated, this, &MainWindow::clear);
}

void MainWindow::verifyExitAction() 
{
	if (QMessageBox::question(this, "Quit?", "Are you sure you want to exit?", 
		QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
		exit();
}

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