#pragma once
#ifndef PAINTER_H
#define PAINTER_H

#include "qwidget.h"
#include "Line.h"
#include "Bezier.h"

class Painter : public QWidget
{
	static Painter* instance;

	std::vector<Line*> lines;
	std::vector<Bezier*> bezierCurves;

protected:
	bool firstClick;
	bool secondClick;
	bool drawing;

	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
	void paintEvent(QPaintEvent* event);

public:
	~Painter()= default;
	Painter() { firstClick= false; secondClick= false; drawing= false; }
	
	static Painter* getInstance();
};

#endif // !PAINTER_H
