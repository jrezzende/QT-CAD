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
	Bezier* bezier= new Bezier(Point(0, 0), Point(0, 0), Point(0, 0));
	bezier->setfirstPoint(Point(event->pos()));

	bezierCurves.push_back(bezier);
}

void Painter::mouseMoveEvent(QMouseEvent * event)
{
	bezierCurves.back()->setSecondPoint(event->pos());
	update();
}

void Painter::mouseReleaseEvent(QMouseEvent * event)
{
}

void Painter::paintEvent(QPaintEvent * event)
{
	QPainter painter(this);

	for (auto bezier : bezierCurves) {
		painter.drawLine(bezier->getFirstPoint().x, bezier->getFirstPoint().y, bezier->getSecondPoint().x, bezier->getSecondPoint().y);
	}
}
