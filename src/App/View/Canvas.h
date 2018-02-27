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
	QPixmap& getPixmap() { return pixmap;}

	std::string savePath();
	std::string loadPath();
	void saveCurrentFile(); // manager

	void clearMap(); // clear all shapes in vector
	void dumpShapes(); // to be called along with clearmap
	void dumpLastShape(); // to be called on undo command

	void lineCommand(); // 
	void bezierCommand(); // draw commands 
	void arcCommand(); // 

	void drawCanvas(Shape& shape);
	void drawPixmap(Shape& shape);

	QPainterPath getDrawPath(Shape& shape);
};
#endif // !CANVAS_H
