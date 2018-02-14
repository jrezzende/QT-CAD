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

	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);

	void paintEvent(QPaintEvent* event);

public:
	~Painter()= default;
	
	static Painter* getInstance();
	void clearVectors() { lines.clear(); bezierCurves.clear(); }
};

#endif // !PAINTER_H
