#include "qevent.h"
#include "qpainterpath.h"
#include "qdebug.h"

#include "Rect.h"
#include "Canvas.h"
#include "Point.h"
#include "MainWindow.h"
#include "CADShape.h"
#include "ViewMediator.h"

Canvas::Canvas(ViewMediator* _mediator, QWidget* parent) : QWidget(parent), pixMap(1920, 1080), mediator(_mediator),
drawing(false), zFactor(1.0)
{
	setCursor(QCursor(Qt::CrossCursor));

	pixMap.fill();

	painter.begin(&pixMap);

	setMouseTracking(true);
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
   pixMap.fill();

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

QPainterPath Canvas::drawPath(CADShape& shape)
{
	auto shapePoints= shape.coordinates();

	QPainterPath path;

	path.moveTo(shapePoints[0].x, shapePoints[0].y);

	for (const auto point : shapePoints) 
		path.lineTo(point.x, point.y);

	return path;
}

void Canvas::drawMap(CADShape& shape)
{
	painter.drawPath(drawPath(shape));
}

////////////////////////////////////////////////

void Canvas::mousePressEvent(QMouseEvent* event)
{
	if (event->button() != Qt::LeftButton) 
      event->ignore();

   mediator->sendMouseEvents(PRESS, *new Point(event->pos().x(), event->pos().y()));
   setDrawing(true);

	event->accept();
}

void Canvas::mouseReleaseEvent(QMouseEvent* event)
{
	if (event->button() != Qt::LeftButton)
      event->ignore();

   mediator->sendMouseEvents(RELEASE, *new Point(event->pos().x(), event->pos().y()));
	setDrawing(false);

	event->accept();
}

void Canvas::mouseMoveEvent(QMouseEvent* event)
{
   if (!drawing) {
      mediator->sendMouseEvents(TRACKING, *new Point(event->pos().x(), event->pos().y()));
      return;
   }

   mediator->sendMouseEvents(MOVE, *new Point(event->pos().x(), event->pos().y()));
	event->accept();
}

void Canvas::wheelEvent(QWheelEvent* event)
{
   if(drawing)
      return;

   if ((event->delta() / 120) > 0) {
      if (zFactor < 1.90f)
         zFactor += 0.10f;
   } else {
      if (zFactor > 0.10f)
         zFactor -= 0.10f;
   }

   mediator->sendMouseEvents(WHEEL, *new Point(event->pos().x(), event->pos().y()));
}

void Canvas::resizeScene(Rect& newArea)
{
   //pixmap copy > pixmap with new rect area
}


void Canvas::paintEvent(QPaintEvent* event)
{
	QPainter shapePainter(this);

	shapePainter.drawPixmap(painter.viewport(), pixMap);

	event->accept();
}