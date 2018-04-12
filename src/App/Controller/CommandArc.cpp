#include "CommandArc.h"
#include "CADFileManager.h"
#include "Canvas.h"

void CommandArc::mousePressEvent(const Point& point)
{
	if (!isDrawing) {
		arc->setfirstPoint(point);
		previewLine->setfirstPoint(point);
	}
	else {
		secondClick = true;
		arc->setThirdPoint(point);
		m.getCurrentFile()->eraseShape(*previewLine);
	}
}

void CommandArc::mouseMoveEvent(const Point& point)
{
	if (!isDrawing) {
		previewLine->setSecondPoint(point);
		m.getCurrentFile()->addShape(*previewLine);
	}
	else {
		m.getCurrentFile()->addShape(*arc);
		arc->setThirdPoint(point);
	}
}

void CommandArc::mouseReleaseEvent(const Point& point)
{
	if (!secondClick) {
		arc->setSecondPoint(point);
		isDrawing= true;
	}
	else {
		m.getCurrentFile()->addShape(*arc);
		m.getCurrentFile()->getCanvas()->setDrawing(false);

		delete previewLine;
	}
}
