#include "Canvas.h"
#include "Point.h"
#include "CommandManager.h"
#include "Shape.h"

#include "qevent.h"
#include "qpainter.h"
#include "qpainterpath.h"
#include "qfiledialog.h"

Canvas::Canvas(CommandManager* _manager, QWidget* parent) : QWidget(parent), pixmap(parent->size())
{
	setCursor(QCursor(Qt::ArrowCursor));

	drawing= false;
	manager= _manager;
	//clearMap();

	callLine();
}

void Canvas::saveCurrentFile()
{
	manager->saveFileCmd();
}

void Canvas::clearMap()
{
	pixmap.fill();

	//dumpShapes();
}

void Canvas::dumpShapes()
{
	manager->clearShapes();
}

void Canvas::dumpLastShape()
{
	manager->eraseLastShape();
}

void Canvas::callLine()
{
	manager->lineCommand();
}

void Canvas::callBezier()
{
	manager->bezierCommand();
}

void Canvas::callArc()
{
	manager->arcCommand();
}

void Canvas::drawCanvas(Shape& shape)
{
	drawMap(shape);

	update();
}

#include <iostream>

QPainterPath Canvas::getDrawPath(Shape& shape)
{
	std::vector<Point> shapePoints= shape.getCoordinates();
	std::cout << shapePoints.size() << std::endl;
	path.moveTo(shapePoints[0].x, shapePoints[0].y);

	for(auto point : shapePoints)
		path.lineTo(point.x, point.y);

	return path;
}

void Canvas::drawMap(Shape& shape)
{
	painter.drawPath(getDrawPath(shape));

	update();
}

////////////////////////////////////////////////

void Canvas::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton) {
		manager->mousePressEvent(event->pos());
		setDrawing(true);
	}

	event->accept();
}

void Canvas::mouseReleaseEvent(QMouseEvent * event)
{
	if(event->button() == Qt::LeftButton)
		manager->mouseReleaseEvent(event->pos());

	event->accept();
}

void Canvas::mouseMoveEvent(QMouseEvent * event)
{
	if(drawing)
		manager->mouseMoveEvent(event->pos());

	event->accept();
}

void Canvas::paintEvent(QPaintEvent* event)
{
	QPainter shapePainter(this);

	shapePainter.drawPath(path);

	event->accept();
}