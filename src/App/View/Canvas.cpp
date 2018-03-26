#include "Canvas.h"
#include "Point.h"
#include "CommandManager.h"
#include "MainWindow.h"
#include "Shape.h"

#include "qevent.h"
#include "qpainterpath.h"
#include "qfiledialog.h"

#include <sstream>

Canvas::Canvas(CommandManager* _manager, QWidget* parent) : QWidget(parent), pixmap(parent->size())
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

void Canvas::endPainter()
{
	painter.end();
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

	QPainterPath path;

	path.moveTo(shapePoints[0].x, shapePoints[0].y);

	for (auto point : shapePoints) 
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
	std::ostringstream aux;

	if (event->button() == Qt::LeftButton) {
		manager->mousePressEvent(Point::toPoint(event->pos()));
		setDrawing(true);

		aux << "Mouse press event detected: x: " << event->pos().x() << " y: " << event->pos().y();

		manager->getWindow().getStatusBar()->showMessage(QString::fromStdString(aux.str()));
		event->accept();
	}

	event->ignore();	
}

void Canvas::mouseReleaseEvent(QMouseEvent * event)
{
	std::ostringstream aux;

	if (event->button() == Qt::LeftButton) {
		manager->mouseReleaseEvent(Point::toPoint(event->pos()));

		aux << "Mouse release event detected: x: " << event->pos().x() << " y: " << event->pos().y();

		manager->getWindow().getStatusBar()->showMessage(QString::fromStdString(aux.str()));
	}

	event->accept();
}

void Canvas::mouseMoveEvent(QMouseEvent * event)
{
	std::ostringstream aux;

	if (drawing) {
		manager->mouseMoveEvent(Point::toPoint(event->pos()));

		aux << "Mouse move event detected: x: " << event->pos().x() << " y: " << event->pos().y();

		manager->getWindow().getStatusBar()->showMessage(QString::fromStdString(aux.str()));
	}

	event->accept();
}

void Canvas::paintEvent(QPaintEvent* event)
{
	QPainter shapePainter(this);

	shapePainter.drawPixmap(painter.viewport(), pixmap);

	event->accept();
}