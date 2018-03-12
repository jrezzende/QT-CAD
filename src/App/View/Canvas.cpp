#include "Canvas.h"
#include "Point.h"
#include "CommandManager.h"
#include "Shape.h"

#include "qevent.h"
#include "qpainterpath.h"
#include "qfiledialog.h"

Canvas::Canvas(CommandManager* _manager, QWidget* parent) : QWidget(parent), pixmap(parentWidget()->size())
{
	setCursor(QCursor(Qt::ArrowCursor));

	pixmap.fill();

	painter.begin(&pixmap);

	drawing= false;
	manager= _manager;

	callLine();
}

void Canvas::saveCurrentFile()
{
	manager->saveFileCmd();
}

void Canvas::clearMap()
{
	pixmap.fill();
	update();
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

QPainterPath Canvas::getDrawPath(Shape& shape)
{
	auto shapePoints= shape.getCoordinates();
	path.moveTo(shapePoints[0].x, shapePoints[0].y);

	for(auto point : shapePoints)
		path.lineTo(point.x, point.y);

	return path;
}

void Canvas::drawMap(Shape& shape)
{
	painter.drawPath(getDrawPath(shape));
}

////////////////////////////////////////////////

void Canvas::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton) {
		manager->mousePressEvent(Point::toPoint(event->pos()));
		setDrawing(true);
		event->accept();
	}

	event->ignore();	
}

void Canvas::mouseReleaseEvent(QMouseEvent * event)
{
	if(event->button() == Qt::LeftButton)
		manager->mouseReleaseEvent(Point::toPoint(event->pos()));

	event->accept();
}

void Canvas::mouseMoveEvent(QMouseEvent * event)
{
	if(drawing)
		manager->mouseMoveEvent(Point::toPoint(event->pos()));

	event->accept();
}

void Canvas::paintEvent(QPaintEvent* event)
{
	painter.end();
	QPainter shapePainter(this);

	shapePainter.drawPixmap(shapePainter.viewport(), pixmap);

	shapePainter.end();
	painter.begin(&pixmap);
	event->accept();
}