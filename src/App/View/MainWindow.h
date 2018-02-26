#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qmainwindow.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT
	
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

	void setLayout();
	void createToolbar();
	void createConnections();

public:
	~MainWindow();
	MainWindow();
	void newFile();
	void loadFile();
	void saveAs();
	void save();
	void undo();
	void clear();
	//void exit(); (?)

public slots:
	void verifyExitAction();
	//void verifyClearAction();
};

#endif // MAINWINDOW_H