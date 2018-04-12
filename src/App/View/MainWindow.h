#pragma once
#ifndef INCLUDED_MAINWINDOW_H
#define INCLUDED_MAINWINDOW_H

#include "qmainwindow.h"
#include "qdesktopwidget.h"
#include "qfiledialog.h"
#include "qstatusbar.h"

class Manager;
class ViewMediator;
class Canvas;

class MainWindow : public QMainWindow
{
	Q_OBJECT

	QStatusBar* statusbar;
	QDesktopWidget desktop;

   Canvas* canvas;
   ViewMediator* mediator;

   void initializeComponents();
   void createShortcuts();

public:
	~MainWindow();
	MainWindow(ViewMediator* _mediator);

	QStatusBar* getStatusBar() const { return statusbar; }

	std::string getNewFileName();
	std::string getSaveFileName();
	std::string getOpenFileName();

   Canvas& getCanvas() const { return *canvas; }

public slots:
	void newFile() const;
	void loadFile() const;
	void save() const;
	void undo() const;
	void redo() const;
	void clear() const;
   void exit() const;

   void mouseTrackingAction();
	void verifyNewFileAction();
	void verifyLoadFileAction();
	void verifyClearAction();
	void verifyExitAction();	
	
	//////////////////
	void lineSignal() const;
	void bezierSignal() const; // SIGNALS
	void arcSignal() const;
	///////////////////
};

#endif //  INCLUDED_MAINWINDOW_H