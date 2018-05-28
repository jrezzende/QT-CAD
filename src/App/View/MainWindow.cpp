#include "qt_windows.h"
#include "qmenubar.h"
#include "qevent.h"
#include "qmessagebox.h"
#include "qshortcut.h"
#include "qstring.h"
#include "qstatusbar.h"
#include "qsize.h"

#include "MainWindow.h"
#include "Canvas.h"
#include "ViewMediator.h"
#include "CommandHandler.h"
#include "Model.h"

MainWindow::~MainWindow()
{
   delete statusbar;
   delete desktop;
   delete windowCanvas;
   delete mediator;
}

MainWindow::MainWindow(ViewMediator* _mediator) : QMainWindow(nullptr), statusbar(nullptr), 
desktop(nullptr), windowCanvas(new Canvas(_mediator, this)), mediator(_mediator)
{
	initializeComponents();
	createShortcuts();
}

void MainWindow::initializeComponents()
{
   QRect screenSize = desktop->availableGeometry(this);
   setMinimumSize(QSize(screenSize.width() * 1.0f, screenSize.height() * 1.0f));

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

   fileMenu->addAction(newFileAction);
   fileMenu->addAction(loadFileAction);
   fileMenu->addAction(saveAction);
   fileMenu->addAction(undoAction);
   fileMenu->addAction(redoAction);
   fileMenu->addAction(clearAction);
   fileMenu->addAction(exitAction);

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
	nav->addMenu(shapesMenu);
   nav->addAction(toggleTracking);
   nav->setStyleSheet("font-size: 16px");

	shapesMenu->addAction(lineAction);
	shapesMenu->addAction(bezierAction);
	shapesMenu->addAction(arcAction);

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

	QObject::connect(toggleTracking, SIGNAL(triggered()), this, SLOT(mouseTrackingAction()));
	QObject::connect(exitAction, SIGNAL(triggered()), this, SLOT(verifyExitAction()));
	QObject::connect(newFileAction, SIGNAL(triggered()), this, SLOT(verifyNewFileAction()));
	QObject::connect(loadFileAction, SIGNAL(triggered()), this, SLOT(verifyLoadFileAction()));
	QObject::connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));
	QObject::connect(lineAction, SIGNAL(triggered()), this, SLOT(lineSignal()));
	QObject::connect(bezierAction, SIGNAL(triggered()), this, SLOT(bezierSignal()));
	QObject::connect(arcAction, SIGNAL(triggered()), this, SLOT(arcSignal()));
	QObject::connect(undoAction, SIGNAL(triggered()), this, SLOT(undo()));
	QObject::connect(redoAction, SIGNAL(triggered()), this, SLOT(redo()));
	QObject::connect(clearAction, SIGNAL(triggered()), this, SLOT(verifyClearAction()));

   statusbar = statusBar();
   statusbar->setMaximumWidth(GetSystemMetrics(SM_CXSCREEN));
   statusbar->showMessage(tr("Ready"), 10000);
   statusbar->setStyleSheet("color: black; background-color: LightGoldenRodYellow; font-size: 20px");
   setStatusBar(statusbar);
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

//////////////////////////////////////

void MainWindow::newFile() const
{
	mediator->sendCommand(NEW);
	statusbar->showMessage(tr("New file action invoked."), 10000);
}

void MainWindow::loadFile() const
{
	mediator->sendCommand(LOAD);
	statusbar->showMessage(tr("Load file action invoked."), 10000);
}

void MainWindow::save() const
{
	mediator->sendCommand(SAVE);
	statusbar->showMessage(tr("Save file action invoked."), 10000);
}

void MainWindow::undo() const
{
	mediator->sendCommand(UNDO);
	statusbar->showMessage(tr("Undo action invoked."), 10000);
}

void MainWindow::redo() const
{
	mediator->sendCommand(REDO);
	statusbar->showMessage(tr("Redo action invoked."), 10000);
}

void MainWindow::clear() const
{
	mediator->sendCommand(CLEAR);
	statusbar->showMessage(tr("Clear action invoked."), 10000);
}

void MainWindow::exit() const
{
	mediator->sendCommand(EXIT);
	statusbar->showMessage(tr("Exit action invoked."), 10000);
}

void MainWindow::mouseTrackingAction()
{
   windowCanvas->toggleTracking();
   statusbar->showMessage(tr("Mouse tracking action invoked."), 10000);
}

void MainWindow::lineSignal() const
{
   mediator->sendShapeEvents(LINE);
   statusbar->showMessage(tr("Drawing mode selected: Line."), 10000);
}

void MainWindow::bezierSignal() const
{
   mediator->sendShapeEvents(BEZIER);
   statusbar->showMessage(tr("Drawing mode selected: Bezier."), 10000);
}

void MainWindow::arcSignal() const
{
   mediator->sendShapeEvents(ARC);
   statusbar->showMessage(tr("Drawing mode selected: Arc."), 10000);
}

std::string MainWindow::newFileName()
{
	return QFileDialog::getSaveFileName(
      this, tr("New File"), "/Users/joao.mathias/cadfiles/untitled.dat", tr("Dat files (*.dat)")
   ).toStdString();
}

std::string MainWindow::saveFileName()
{
	return QFileDialog::getSaveFileName(
      this, tr("Save file as..."), "/Users/joao.mathias/cadfiles/untitled.dat", tr("Dat files (*.dat)")
   ).toStdString();
}

std::string MainWindow::openFileName()
{
	return QFileDialog::getOpenFileName(
      this, tr("Open File"),"/Users/joao.mathias/cadfiles/untitled.dat", tr("Dat files (*.dat)")
   ).toStdString();
}

void MainWindow::verifyExitAction() 
{
	if (mediator->handler().currentFileShapes().empty())
		exit();

   if (mediator->handler().currentFileStatus() == NOTSAVED) {
		if (QMessageBox::question(this, "Quit?", "Are you sure you want to exit?",
			QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
			exit();
	}
	exit();
}

void MainWindow::verifyNewFileAction()
{
	if (mediator->handler().currentFileShapes().empty())
      return newFile();

	else if (mediator->handler().currentFileStatus() == NOTSAVED) {
		if (QMessageBox::question(this, "Discard file?", "Are you sure you want to discard this file?",
			QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
         windowCanvas->pixmap().fill();
			return newFile();
	}
		newFile();
}

void MainWindow::verifyLoadFileAction()
{
	if (mediator->handler().currentFileStatus() == NOTSAVED && !(mediator->handler().currentFileShapes().empty())) {
		if (QMessageBox::question(this, "Overwrite this file?", "Are you sure you want to discard this file?",
			QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
         return loadFile();
	}
		loadFile();
}

void MainWindow::verifyClearAction()
{
	if(mediator->handler().currentFileShapes().empty())
      return clear();
	else if (mediator->handler().currentFileStatus() == NOTSAVED) {
		if(QMessageBox::question(this, "This action cannot be undone!", "Are you sure you want to clear the file?",
			QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
			clear();
	}
}