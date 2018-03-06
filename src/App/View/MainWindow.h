#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qmainwindow.h"

class CommandManager;
class Canvas;

class MainWindow : public QMainWindow
{
	Q_OBJECT

	CommandManager* manager;

public:
	QMenuBar* nav;

	QMenu* fileMenu;
	QMenu* shapesMenu;

	QAction* newFileAction;
	QAction* loadFileAction;
	QAction* saveAction;
	QAction* saveAsAction;
	QAction* undoAction;
	QAction* clearAction;
	QAction* exitAction;
	QAction* lineAction;
	QAction* bezierAction;
	QAction* arcAction;
	
	~MainWindow();
	MainWindow(QMainWindow* parent= 0);
	CommandManager* getManager() const { return manager; }

	void setLayout();
	void createToolbar();
	void createConnections();
	void createShortcuts();

	std::string getText();
	std::string getFileName();
	Canvas* createCanvas();

public slots:
	void newFile();
	void loadFile();
	void save();
	void verifyExitAction();
	void exit();
	//////////////////
	void lineSignal();
	void bezierSignal(); // SIGNALS
	void arcSignal();
	//////////////////

protected:
	void paintEvent(QPaintEvent* event) override;
};
#endif // MAINWINDOW_H