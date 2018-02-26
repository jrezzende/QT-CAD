#include "Canvas.h"
#include "qevent.h"
#include "qpainter.h"
#include "qpainterpath.h"
#include "Point.h"

Canvas* Canvas::instance= nullptr;

Canvas* Canvas::getInstance()
{
	if(!instance)
	instance= new Canvas();

	return instance;
}

void Canvas::mousePressEvent(QMouseEvent* event)
{
	
}

void Canvas::mouseReleaseEvent(QMouseEvent * event)
{

}

void Canvas::mouseMoveEvent(QMouseEvent * event)
{

}

void Canvas::paintEvent(QPaintEvent * event)
{
	
}
