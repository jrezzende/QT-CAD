#include "Canvas.h"
#include "Point.h"

#include "qevent.h"
#include "qpainter.h"
#include "qpainterpath.h"
#include "qfiledialog.h"

Canvas* Canvas::instance= nullptr;

Canvas* Canvas::getInstance()
{
	if(!instance)
	instance= new Canvas();

	return instance;
}

std::string Canvas::savePath()
{
	return QFileDialog::getSaveFileName(this, QString("Save file"), QString(".dat files (*.dat)")).toStdString();
}

std::string Canvas::loadPath()
{
	return QFileDialog::getOpenFileName(this, QString("Load file"), QString(".dat files (*.dat)")).toStdString();
}

void Canvas::saveCurrentFile()
{
	//command save file
}

void Canvas::clearMap()
{
	pixmap.fill();

	//call dumpshapes();
}

void Canvas::dumpShapes()
{
	//clear data shape vector
}

void Canvas::dumpLastShape()
{
	//pop_back shape vector
}

void Canvas::lineCommand()
{
	//start line command
}

void Canvas::bezierCommand()
{
	//start bezier command
}

void Canvas::arcCommand()
{
	//start arc command
}

void Canvas::drawCanvas(Shape & shape)
{

}

void Canvas::drawPixmap(Shape & shape)
{
}

QPainterPath Canvas::getDrawPath(Shape & shape)
{
	return QPainterPath();
}

////////////////////////////////////////////////

void Canvas::mousePressEvent(QMouseEvent* event)
{
	
}

void Canvas::mouseReleaseEvent(QMouseEvent * event)
{

}

void Canvas::mouseMoveEvent(QMouseEvent * event)
{

}

/////////////////////////////////////////////

void Canvas::paintEvent(QPaintEvent * event)
{
	
}
