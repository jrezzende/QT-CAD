#pragma once
#ifndef INCLUDED_MAINWINDOW_H
#define INCLUDED_MAINWINDOW_H

#include "qmainwindow.h"
#include "qdesktopwidget.h"
#include "qfiledialog.h"
#include "qstatusbar.h"

class CommandManager;
class Canvas;

class MainWindow : public QMainWindow
{
	Q_OBJECT

	QStatusBar* statusbar;
	QDesktopWidget desktop;
	CommandManager* manager;

public:
	~MainWindow();
	MainWindow();

	CommandManager& getManager() const { return *manager; }
	void setManager(CommandManager& _manager) { manager= &_manager;}

	QStatusBar* getStatusBar() const { return statusbar; }

	void setLayout();
	void createToolbarAndConnections();
	void createShortcuts();
	void createStatusBar();

	std::string getNewFileName();
	std::string getSaveFileName();
	std::string getOpenFileName();
	Canvas* createCanvas();

public slots:
	void newFile();
	void loadFile();
	void save();
	void undo();
	void redo();
	void clear();
	void verifyNewFileAction();
	void verifyLoadFileAction();
	void verifyClearAction();
	void verifyExitAction();
	void mouseTrackingAction();
	void exit();

	//////////////////
	void lineSignal();
	void bezierSignal(); // SIGNALS
	void arcSignal();
	///////////////////
};

#endif //  INCLUDED_MAINWINDOW_H