#pragma once
#ifndef CANVAS_H
#define CANVAS_H

#include "qwidget.h"
#include "qpainter.h"
#include "qpixmap.h"

class Shape;

class Canvas : public QWidget
{
	Q_OBJECT

	static Canvas* instance;

	QPainter painter;
	QPixmap pixmap;

	bool drawing;

protected:
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
	void paintEvent(QPaintEvent* event);

public:
	~Canvas() {}
	Canvas() {}
	
	static Canvas* getInstance();
};

#endif // !CANVAS_H
