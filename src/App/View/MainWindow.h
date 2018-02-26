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

public:
	~MainWindow();
	MainWindow();

public slots:
	void verifyExitAction();
	//void verifyClearAction();

private:
	void setLayout();
	void createToolbar();
};

#endif // MAINWINDOW_H