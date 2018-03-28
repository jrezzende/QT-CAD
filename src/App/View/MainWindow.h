#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qmainwindow.h"
#include "qdesktopwidget.h"

#include "qfiledialog.h"
#include "qstatusbar.h"

class CommandManager;
class Canvas;

class MainWindow : public QMainWindow
{
	Q_OBJECT

		CommandManager* manager;
		QDesktopWidget desktop;
		QStatusBar* statusbar;

public:
	~MainWindow();
	MainWindow(QMainWindow* parent = 0);

	CommandManager* getManager() const { return manager; }
	void setManager(CommandManager& _manager) {manager= &_manager;}

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
#endif // MAINWINDOW_H