#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qmainwindow.h"
#include "qwidget.h"

class MainWindow : public QMainWindow
{
	std::vector<QLine*> lines;

	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);

	void paintEvent(QPaintEvent* event);
public:
	MainWindow();



};

#endif // MAINWINDOW_H