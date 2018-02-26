#pragma once
#ifndef CANVAS_H
#define CANVAS_H

#include "qwidget.h"
#include "Shape.h"

class Bezier;
class Line;

class Canvas : public QWidget
{
	static Canvas* instance;

	std::vector<Shape*> shapes;

	Bezier* bezier;
	Line* line;

protected:
	bool firstClick;
	bool secondClick;
	bool drawing;

	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
	void paintEvent(QPaintEvent* event);

public:
	~Canvas()= default;
	Canvas() { firstClick= false; secondClick= false; drawing= false; }
	
	static Canvas* getInstance();
};

#endif // !CANVAS_H
