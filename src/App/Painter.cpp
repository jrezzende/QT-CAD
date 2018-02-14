#include "Painter.h"
#include "Shapes.h"
#include "qevent.h"
#include "qpainter.h"

Painter* Painter::instance= nullptr;

Painter* Painter::getInstance()
{
	if(!instance)
		instance= new Painter();

	return instance;
}

void Painter::mousePressEvent(QMouseEvent* event)
{
	Line* line= new Line(Point(0, 0), Point(0, 0));
	line->setfirstPoint(Point(event->pos()));

	lines.push_back(line);
}

void Painter::mouseMoveEvent(QMouseEvent * event)
{
	lines.back()->setSecondPoint(event->pos());
	update();
}

void Painter::mouseReleaseEvent(QMouseEvent * event)
{
}

void Painter::paintEvent(QPaintEvent * event) // line testing only
{
	QPainter painter(this);

	for (auto line : lines) {
		painter.drawLine(line->getFirstPoint().x, line->getFirstPoint().y, line->getSecondPoint().x, line->getSecondPoint().y);
	}
}
