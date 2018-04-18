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
		m.currentFile()->eraseShape(*previewLine);
	}
}

void CommandArc::mouseMoveEvent(const Point& point)
{
	if (!isDrawing) {
		previewLine->setSecondPoint(point);
		m.currentFile()->addShape(*previewLine);
	}
	else {
		m.currentFile()->addShape(*arc);
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
		m.currentFile()->addShape(*arc);
		m.currentFile()->canvas()->setDrawing(false);

		delete previewLine;
	}
}
