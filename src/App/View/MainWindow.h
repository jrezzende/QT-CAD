#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qmainwindow.h"

#include "qfiledialog.h"

class CommandManager;
class Canvas;

class MainWindow : public QMainWindow
{
	Q_OBJECT

		CommandManager* manager;

public:
	~MainWindow();
	MainWindow(QMainWindow* parent = 0);

	CommandManager* getManager() const { return manager; }
	void setManager(CommandManager& _manager) {manager= &_manager;}

	void setLayout();
	void createToolbarAndConnections();
	void createShortcuts();

	std::string getFileName();
	std::string getOpenFileName();
	Canvas* createCanvas();

public slots:
	void newFile();
	void loadFile();
	void save();
	void undo();
	void clear();
	void verifyExitAction();
	void exit();

	//////////////////
	void lineSignal();
	void bezierSignal(); // SIGNALS
	void arcSignal();
	//////////////////
};
#endif // MAINWINDOW_H