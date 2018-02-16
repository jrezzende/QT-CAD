#include "Painter.h"
#include "Shapes.h"
#include "qevent.h"
#include "qpainter.h"
#include "qpainterpath.h"

Painter* Painter::instance= nullptr;

Painter* Painter::getInstance()
{
	if(!instance)
		instance= new Painter();

	return instance;
}

void Painter::mousePressEvent(QMouseEvent* event)
{
	if (!drawing) {
		Bezier* bezier = new Bezier(Point(0, 0), Point(0, 0), Point(0, 0));
		bezier->setfirstPoint(Point(event->pos()));

		bezierCurves.push_back(bezier);
	}
	else
		secondClick= true;
}

void Painter::mouseReleaseEvent(QMouseEvent * event)
{
	if (!secondClick) {
		drawing= true;
		bezierCurves.back()->setSecondPoint(event->pos());
	}
	else if(secondClick)
		drawing= false;
}

void Painter::mouseMoveEvent(QMouseEvent * event)
{
	if (secondClick)
		bezierCurves.back()->setThirdPoint(event->pos());
	else
		bezierCurves.back()->setSecondPoint(event->pos());
	
	update();
}

void Painter::paintEvent(QPaintEvent * event)
{
	QPainter painter(this);
	QPainterPath bezierPath;

	for (auto bezier : bezierCurves) {
		bezierPath.moveTo(bezier->getFirstPoint());
	}
}
