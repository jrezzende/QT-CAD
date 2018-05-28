#pragma once
#ifndef INCLUDED_MAINWINDOW_H
#define INCLUDED_MAINWINDOW_H

#include "qmainwindow.h"
#include "qdesktopwidget.h"
#include "qfiledialog.h"
#include "qstatusbar.h"

class Handler;
class ViewMediator;
class Canvas;

class MainWindow : public QMainWindow
{
	Q_OBJECT

	QStatusBar* statusbar;
	QDesktopWidget* desktop;

   Canvas* windowCanvas;
   ViewMediator* mediator;

   void initializeComponents();
   void createShortcuts();

public:
	~MainWindow();
	explicit MainWindow(ViewMediator* _mediator);

	QStatusBar* status() const { return statusbar; }

	std::string newFileName();
	std::string saveFileName();
	std::string openFileName();

   Canvas& canvas() const { return *windowCanvas; }

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

	void lineSignal() const;
	void bezierSignal() const;
	void arcSignal() const;
};

#endif //  INCLUDED_MAINWINDOW_H