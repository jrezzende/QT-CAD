#include "MainWindow.h"
#include "Canvas.h"
#include "CommandManager.h"
#include "Model.h"

#include "qt_windows.h"
#include "qtoolbar.h"
#include "qmenubar.h"
#include "qevent.h"
#include "qmessagebox.h"
#include "qshortcut.h"
#include "qdebug.h"
#include "qstring.h"

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
	QRect screenSize= desktop.availableGeometry(this);
	setMinimumSize(QSize(screenSize.width() * 1.2f, screenSize.height() * 1.2f));
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
		this, SLOT(verifyNewFileAction())
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
		this, SLOT(verifyClearAction())
	);
}

//////////////////////////////////////

void MainWindow::newFile()
{
	manager->getModel().getCurrentFile()->getCanvas()->endPainter();
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

std::string MainWindow::getFileName(int param)
{
	if(param)
		return QFileDialog::getSaveFileName(this, tr("New File"), "/Users/joao.mathias/Pictures/untitled.png", tr("Dat files (*.dat)")).toStdString();
	else
		return QFileDialog::getSaveFileName(this, tr("Save file as..."), "/Users/joao.mathias/Pictures/untitled.png", tr("Dat files (*.dat)")).toStdString();
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
	connect(new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_N), this), &QShortcut::activated, this, &MainWindow::verifyNewFileAction);

	connect(new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_O), this), &QShortcut::activated, this, &MainWindow::loadFile);

	connect(new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_S), this), &QShortcut::activated, this, &MainWindow::save);

	connect(new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_L), this), &QShortcut::activated, this, &MainWindow::lineSignal);

	connect(new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_B), this), &QShortcut::activated, this, &MainWindow::bezierSignal);

	connect(new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_A), this), &QShortcut::activated, this, &MainWindow::arcSignal);

	connect(new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z), this), &QShortcut::activated, this, &MainWindow::undo);

	connect(new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_X), this), &QShortcut::activated, this, &MainWindow::verifyClearAction);
}

// apply the same pattern when calling load function \/

void MainWindow::verifyExitAction() 
{
	if(manager->getModel().getCurrentFile()->getShapes().size() == 0)
		exit();
	else if(manager->getModel().getCurrentFile()->getStatus() == NOTSAVED) {
		if (QMessageBox::question(this, "Quit?", "Are you sure you want to exit?",
			QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
			exit();
	}
	else
		exit();
}

void MainWindow::verifyNewFileAction()
{
	if(manager->getModel().getCurrentFile()->getShapes().size() == 0)
		newFile();
	else if(manager->getModel().getCurrentFile()->getStatus() == NOTSAVED) {
		if (QMessageBox::question(this, "Discard file?", "Are you sure you want to discard this file?",
			QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
			newFile();
	}
	else
		newFile();
}

void MainWindow::verifyClearAction()
{
	if(!(manager->getModel().getCurrentFile()->getShapes().size() > 0))
		clear();
	else if (manager->getModel().getCurrentFile()->getStatus() == NOTSAVED) {
		if(QMessageBox::question(this, "This action cannot be undone!", "Are you sure you want to clear the file?",
			QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
			clear();
	}
	else
		clear();
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