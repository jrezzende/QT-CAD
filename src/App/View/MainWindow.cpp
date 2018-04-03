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
#include "qstatusbar.h"

MainWindow::~MainWindow()
{
   delete manager;
   delete statusbar;
}

MainWindow::MainWindow() : QMainWindow(nullptr), manager(nullptr)
{
	createToolbarAndConnections();
	createShortcuts();
	createStatusBar();
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

	auto toggleTracking = new QAction();

	auto newFileAction = new QAction();
	auto loadFileAction = new QAction();
	auto saveAction = new QAction();
	auto undoAction = new QAction();
	auto redoAction = new QAction();
	auto clearAction = new QAction();
	auto exitAction = new QAction();

	auto lineAction = new QAction();
	auto bezierAction = new QAction();
	auto arcAction = new QAction();

	newFileAction->setIcon(QIcon(":/newfile.png"));
	loadFileAction->setIcon(QIcon(":/load.png"));
	saveAction->setIcon(QIcon(":/save.png"));
	undoAction->setIcon(QIcon(":/undo.png"));
	redoAction->setIcon(QIcon(":/redo.png"));
	clearAction->setIcon(QIcon(":/clear.png"));
	exitAction->setIcon(QIcon(":/exit.png"));

	lineAction->setIcon(QIcon(":/line.png"));
	bezierAction->setIcon(QIcon(":/bezier.png"));
	arcAction->setIcon(QIcon(":/arc.png"));

	toggleTracking->setText("Mouse tracking on/off");

	fileMenu->setTitle("File");
	newFileAction->setText("New File");
	loadFileAction->setText("Load File");
	saveAction->setText("Save");
	undoAction->setText("Undo");
	redoAction->setText("Redo");
	clearAction->setText("Clear");
	exitAction->setText("Exit");

	shapesMenu->setTitle("Shapes");
	lineAction->setText("Line");
	bezierAction->setText("Bezier");
	arcAction->setText("Arc");

	toggleTracking->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_T));

	newFileAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_N));
	loadFileAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
	saveAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));
	undoAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z));
	redoAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Y));
	clearAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_X));
	exitAction->setShortcut(QKeySequence(Qt::ALT + Qt::Key_F4));

	lineAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_L));
	bezierAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_B));
	arcAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_A));

	nav->addMenu(fileMenu);

	fileMenu->addAction(newFileAction);
	fileMenu->addAction(loadFileAction);
	fileMenu->addAction(saveAction);
	fileMenu->addAction(undoAction);
	fileMenu->addAction(redoAction);
	fileMenu->addAction(clearAction);
	fileMenu->addAction(exitAction);

	nav->addMenu(shapesMenu);
	shapesMenu->addAction(lineAction);
	shapesMenu->addAction(bezierAction);
	shapesMenu->addAction(arcAction);

	nav->addAction(toggleTracking);

	toggleTracking->setShortcutContext(Qt::WidgetShortcut);

	newFileAction->setShortcutContext(Qt::WidgetShortcut);
	loadFileAction->setShortcutContext(Qt::WidgetShortcut);
	saveAction->setShortcutContext(Qt::WidgetShortcut);
	undoAction->setShortcutContext(Qt::WidgetShortcut);
	redoAction->setShortcutContext(Qt::WidgetShortcut);
	clearAction->setShortcutContext(Qt::WidgetShortcut);

	lineAction->setShortcutContext(Qt::WidgetShortcut);
	bezierAction->setShortcutContext(Qt::WidgetShortcut);
	arcAction->setShortcutContext(Qt::WidgetShortcut);

	nav->setStyleSheet("font-size: 16px");

	QObject::connect(
		toggleTracking, SIGNAL(triggered()),
		this, SLOT(mouseTrackingAction())
	);

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
		this, SLOT(verifyLoadFileAction())
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

	QObject::connect(redoAction, SIGNAL(triggered()),this, SLOT(redo()));
	QObject::connect(clearAction, SIGNAL(triggered()),this, SLOT(verifyClearAction()));
}

//////////////////////////////////////

void MainWindow::newFile()
{
	manager->getModel().getCurrentFile()->getCanvas()->endPainter();
	manager->newFileCmd();

	statusbar->showMessage(tr("New file action invoked."), 10000);
}

void MainWindow::loadFile()
{
	manager->loadFileCmd();
	
	statusbar->showMessage(tr("Load file action invoked."), 10000);
}

void MainWindow::save()
{
	manager->saveFileCmd();

	statusbar->showMessage(tr("Save file action invoked."), 10000);
}

void MainWindow::undo()
{
	manager->eraseLastShape();

	statusbar->showMessage(tr("Undo action invoked."), 10000);
}

void MainWindow::redo()
{
	manager->redoShape();

	statusbar->showMessage(tr("Redo action invoked."), 10000);
}

void MainWindow::clear()
{
	manager->clearShapes();

	statusbar->showMessage(tr("Clear action invoked."), 10000);
}

void MainWindow::exit()
{
	manager->exitFileCmd();

	statusbar->showMessage(tr("Exit action invoked."), 10000);
}

std::string MainWindow::getNewFileName()
{
	return QFileDialog::getSaveFileName(
      this, tr("New File"), "/Users/joao.mathias/cadfiles/untitled.dat", tr("Dat files (*.dat)")
   ).toStdString();
}

std::string MainWindow::getSaveFileName()
{
	return QFileDialog::getSaveFileName(this, tr("Save file as..."), "/Users/joao.mathias/cadfiles/untitled.dat", tr("Dat files (*.dat)")).toStdString();
}

std::string MainWindow::getOpenFileName()
{
	return QFileDialog::getOpenFileName(this, tr("Open File"),"/Users/joao.mathias/cadfiles/untitled.dat", tr("Dat files (*.dat)")).toStdString();
}

Canvas * MainWindow::createCanvas()
{
	return new Canvas(manager, this);
}

void MainWindow::createShortcuts()
{
	connect(new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_N), this), &QShortcut::activated, this, &MainWindow::verifyNewFileAction);

	connect(new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_O), this), &QShortcut::activated, this, &MainWindow::verifyLoadFileAction);

	connect(new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_S), this), &QShortcut::activated, this, &MainWindow::save);

	connect(new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_L), this), &QShortcut::activated, this, &MainWindow::lineSignal);

	connect(new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_B), this), &QShortcut::activated, this, &MainWindow::bezierSignal);

	connect(new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_A), this), &QShortcut::activated, this, &MainWindow::arcSignal);

	connect(new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z), this), &QShortcut::activated, this, &MainWindow::undo);

	connect(new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Y), this), &QShortcut::activated, this, &MainWindow::redo);

	connect(new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_X), this), &QShortcut::activated, this, &MainWindow::verifyClearAction);

	connect(new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_T), this), &QShortcut::activated, this, &MainWindow::mouseTrackingAction);
}

void MainWindow::createStatusBar()
{
	statusbar= statusBar();
	statusbar->setMaximumWidth(GetSystemMetrics(SM_CXSCREEN));
	statusbar->showMessage(tr("Ready"), 10000);
	statusbar->setStyleSheet("color: black; background-color: LightGoldenRodYellow; font-size: 20px");
	setStatusBar(statusbar);
}

void MainWindow::verifyExitAction() 
{
	if (manager->getModel().getCurrentFile()->getShapes().empty())
		exit();

   if (manager->getModel().getCurrentFile()->getStatus() == NOTSAVED) {
		if (QMessageBox::question(this, "Quit?", "Are you sure you want to exit?",
			QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
			exit();
	}
	else
	   exit();
}

void MainWindow::mouseTrackingAction()
{
	manager->getModel().getCurrentFile()->getCanvas()->toggleTracking();

	statusbar->showMessage(tr("Mouse tracking action invoked."), 10000);
}

void MainWindow::verifyNewFileAction()
{
	if (manager->getModel().getCurrentFile()->getShapes().empty())
		newFile();
	else if (manager->getModel().getCurrentFile()->getStatus() == NOTSAVED) {
		if (QMessageBox::question(this, "Discard file?", "Are you sure you want to discard this file?",
			QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
			newFile();
	}
	else
		newFile();
}

void MainWindow::verifyLoadFileAction()
{
	if (manager->getModel().getCurrentFile()->getStatus() == NOTSAVED) {
		if (QMessageBox::question(this, "Overwrite this file?", "Are you sure you want to discard this file?",
			QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
			manager->getModel().getCurrentFile()->getCanvas()->endPainter();
			loadFile();
		}
	}
	else {
		manager->getModel().getCurrentFile()->getCanvas()->endPainter();
		loadFile();
	}
}

void MainWindow::verifyClearAction()
{
	if(manager->getModel().getCurrentFile()->getShapes().empty())
		clear();
	else if (manager->getModel().getCurrentFile()->getStatus() == NOTSAVED) {
		if(QMessageBox::question(this, "This action cannot be undone!", "Are you sure you want to clear the file?",
			QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
			clear();
	}
}

void MainWindow::lineSignal()
{
	manager->lineCommand();

	statusbar->showMessage(tr("Drawing mode selected: Line."), 10000);
}

void MainWindow::bezierSignal()
{
	manager->bezierCommand();

	statusbar->showMessage(tr("Drawing mode selected: Bezier."), 10000);
}

void MainWindow::arcSignal()
{
	manager->arcCommand();

	statusbar->showMessage(tr("Drawing mode selected: Arc."), 10000);
}