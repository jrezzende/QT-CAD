#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qmainwindow.h"
#include "Painter.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

	QMenu* fileMenu;

	QAction* newFileAction;
	QAction* loadFileAction;
	QAction* saveAction;
	QAction* saveAsAction;
	QAction* undoAction;
	QAction* clearAction;
	QAction* exitAction;
		   
	QMenu* shapesMenu;

	QAction* lineAction;
	QAction* bezierAction;
	QAction* arcAction;

public:
	MainWindow();

	void setLayout();
	void setToolbar();

};

#endif // MAINWINDOW_H