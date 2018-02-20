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

	void loadFile(const QString& filename);

protected:
	void closeEvent(QCloseEvent* event) override;

private slots:
	void newFile();
	void open();
	bool save();
	bool saveAs();
	void about();

private:
	void setLayout();
	void createToolbar();
	bool saveFile(const QString& fileName);
	bool flagSave();
	void writeSpecifications();
	void setCurrentFile(const QString& fileName);

	QString currentFile();
};

#endif // MAINWINDOW_H