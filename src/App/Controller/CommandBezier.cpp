#include "CommandBezier.h"
#include "CADFileManager.h"
#include "Canvas.h"

void CommandBezier::mousePressEvent(const Point& point)
{
	if (!isDrawing) {
		bezier->setfirstPoint(point);
		previewLine->setfirstPoint(point);
	}
	else {
		secondClick = true;
		bezier->setThirdPoint(point);
		m.getCurrentFile()->eraseShape(*previewLine);
	}
}

void CommandBezier::mouseMoveEvent(const Point& point)
{
	if (!isDrawing) {
		previewLine->setSecondPoint(point);
		m.getCurrentFile()->addShape(*previewLine);
	}
	else {
		bezier->setThirdPoint(point);
		m.getCurrentFile()->addShape(*bezier);
	}
}

void CommandBezier::mouseReleaseEvent(const Point& point)
{
	if (!secondClick) {
		bezier->setSecondPoint(point);
		isDrawing= true;
	}
	else {
		m.getCurrentFile()->addShape(*bezier);
		m.getCurrentFile()->getCanvas()->setDrawing(false);
		delete previewLine;
	}
}
