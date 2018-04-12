#include "qevent.h"
#include "qpainterpath.h"

#include "Canvas.h"
#include "Point.h"
#include "Manager.h"
#include "MainWindow.h"
#include "CADShape.h"
#include "ViewMediator.h"

#include <sstream>

Canvas::Canvas(ViewMediator* _mediator, QWidget* parent) : QWidget(parent), pixmap(1920, 1080), mediator(_mediator)
{
	setCursor(QCursor(Qt::ArrowCursor));

	pixmap.fill();

	painter.begin(&pixmap);

	setMouseTracking(true);

	drawing= false;
}

void Canvas::toggleTracking()
{
	if (hasMouseTracking()) {
		setMouseTracking(false);
		return;
	}
	setMouseTracking(true);
}

void Canvas::clearMap()
{
   pixmap.fill();

   update();
}

void Canvas::endPainter()
{
	painter.end();
}

void Canvas::callLine() const
{
	mediator->sendShapeEvents(LINE);
}

void Canvas::callBezier() const
{
	mediator->sendShapeEvents(BEZIER);
}

void Canvas::callArc() const
{
	mediator->sendShapeEvents(ARC);
}

void Canvas::drawCanvas(CADShape& shape)
{
	drawMap(shape);

	update();
}

QPainterPath Canvas::getDrawPath(CADShape& shape)
{
	auto shapePoints= shape.getCoordinates();

	QPainterPath path;

	path.moveTo(shapePoints[0].x, shapePoints[0].y);

	for (const auto point : shapePoints) 
		path.lineTo(point.x, point.y);

	return path;
}

void Canvas::drawMap(CADShape& shape)
{
	painter.drawPath(getDrawPath(shape));
}

////////////////////////////////////////////////

void Canvas::mousePressEvent(QMouseEvent* event)
{
	std::ostringstream aux;

	if (event->button() == Qt::LeftButton) {
		mediator->sendMouseEvents(PRESS, Point(event->pos().x(), event->pos().y()));
		setDrawing(true);

		aux << "Mouse press event detected: x: " << event->pos().x() << " y: " << event->pos().y();

      mediator->sendMessage(aux.str());
		event->accept();
	}

	event->ignore();	
}

void Canvas::mouseReleaseEvent(QMouseEvent * event)
{
	std::ostringstream aux;

	if (event->button() == Qt::LeftButton) {
		mediator->sendMouseEvents(RELEASE, Point(event->pos().x(), event->pos().y()));

		aux << "Mouse release event detected: x: " << event->pos().x() << " y: " << event->pos().y();

      mediator->sendMessage(aux.str());
	}

	setDrawing(false);

	event->accept();
}

void Canvas::mouseMoveEvent(QMouseEvent * event)
{
	std::ostringstream aux;

	if (!drawing) {
		aux << "Mouse tracking mode on. Hover position: x: " << event->pos().x() << " y: " << event->pos().y() << ". Press CTRL + T to turn off.";

      mediator->sendMessage(aux.str());
	}

	if (drawing) {
		mediator->sendMouseEvents(MOVE, Point(event->pos().x(), event->pos().y()));

		aux << "Mouse move event detected: x: " << event->pos().x() << " y: " << event->pos().y();

		mediator->sendMessage(aux.str());
	}

	event->accept();
}

void Canvas::paintEvent(QPaintEvent* event)
{
	QPainter shapePainter(this);

	shapePainter.drawPixmap(painter.viewport(), pixmap);

	event->accept();
}