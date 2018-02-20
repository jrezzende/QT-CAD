#include "Painter.h"
#include "qevent.h"
#include "qpainter.h"
#include "qpainterpath.h"
#include "Point.h"
#include "Bezier.h"
#include "Line.h"

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
		bezier = new Bezier;
		line = new Line;

		line->setfirstPoint(Point(event->pos()));

		shapes.push_back(line);
	}
	else {		
		bezier->setfirstPoint(line->getFirstPoint());
		bezier->setSecondPoint(line->getSecondPoint());

		shapes.pop_back();
		shapes.push_back(bezier);

		secondClick = true;
	}
}

void Painter::mouseReleaseEvent(QMouseEvent * event)
{
	if (secondClick)
		drawing = false;
	else 
		drawing= true;
}

void Painter::mouseMoveEvent(QMouseEvent * event)
{
	if (secondClick)
		bezier->setThirdPoint(Point(event->pos()));	
	else 
		line->setSecondPoint(Point(event->pos()));
	
	update();
}

void Painter::paintEvent(QPaintEvent * event)
{
	QPainter painter(this);

	for (auto bezier : shapes)
	{
		QPainterPath bezierPath;
		
		bezierPath.moveTo(bezier->getFirstPoint().toQPoint());

		for (auto point : bezier->getCoordinates())
			bezierPath.lineTo(point.toQPoint());

		painter.drawPath(bezierPath);
	}
}
