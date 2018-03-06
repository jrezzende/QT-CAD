#pragma once
#ifndef CANVAS_H
#define CANVAS_H

#include "qwidget.h"
#include "qpainter.h"
#include "qpixmap.h"

class Shape;
class CommandManager;

class Canvas : public QWidget
{
	Q_OBJECT

	QPainter painter;
	QPixmap pixmap;

	CommandManager* manager;

	int x, y;

	bool drawing;
	//shortcuts go on canvas or window?
protected:
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
	void paintEvent(QPaintEvent* event);

public:
	~Canvas() {}
	Canvas(CommandManager* manager, QWidget* parent= 0);

	QPixmap& getPixmap() { return pixmap;}

	void setDrawing(bool flag) { drawing= flag; }

	std::string savePath();
	std::string loadPath();
	void saveCurrentFile();

	void clearMap();
	void dumpShapes();
	void dumpLastShape();

	void lineCommand();
	void bezierCommand();
	void arcCommand();

	void drawCanvas(Shape& shape);
	void drawPixmap(Shape& shape);

	QPainterPath getDrawPath(Shape& shape);
};
#endif // !CANVAS_H
