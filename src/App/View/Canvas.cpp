#include "Canvas.h"
#include "Point.h"
#include "CommandManager.h"
#include "Shape.h"

#include "qevent.h"
#include "qpainter.h"
#include "qpainterpath.h"
#include "qfiledialog.h"

Canvas::Canvas(CommandManager* _manager, QWidget* parent) : drawing(false), QWidget(parent)
{
	setCursor(QCursor(Qt::ArrowCursor));

	manager= _manager;
	clearMap();

	lineCommand();
}

//std::string Canvas::savePath()
//{
//	return QFileDialog::getSaveFileName(this, QString("Save file"), QString(".dat files (*.dat)")).toStdString();
//}
//
//std::string Canvas::loadPath()
//{
//	return QFileDialog::getOpenFileName(this, QString("Load file"), QString(".dat files (*.dat)")).toStdString();
//}

void Canvas::saveCurrentFile()
{
	manager->saveFileCmd();
}

void Canvas::clearMap()
{
	pixmap.fill();

	dumpShapes();
}

void Canvas::dumpShapes()
{
	manager->clearShapes();
}

void Canvas::dumpLastShape()
{
	manager->eraseLastShape();
}

void Canvas::lineCommand()
{
	manager->lineCommand();
}

void Canvas::bezierCommand()
{
	manager->bezierCommand();
}

void Canvas::arcCommand()
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
	std::vector<Point> shapePoints= shape.getCoordinates();

	QPainterPath path;

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

void Canvas::paintEvent(QPaintEvent * event, Shape& shape)
{
	QPainter shapePainter(this);

	QPainterPath path= getDrawPath(shape);

	shapePainter.drawPath(path);

	event->accept();
}