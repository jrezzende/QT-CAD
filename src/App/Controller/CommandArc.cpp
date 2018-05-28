#include "CommandArc.h"
#include "CADFileManager.h"
#include "Canvas.h"

void CommandArc::mousePressEvent(const Point& point)
{
	if (!isDrawing) {
		arc->setFirstPoint(point);
		previewLine->setFirstPoint(point);
	}
	else {
		secondClick = true;
		arc->setThirdPoint(point);
		fileManager.current().eraseShape(*previewLine);
	}
}

void CommandArc::mouseMoveEvent(const Point& point)
{
	if (!isDrawing) {
		previewLine->setSecondPoint(point);
      fileManager.current().addShape(*previewLine);
	}
	else {
      fileManager.current().addShape(*arc);
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
      fileManager.current().addShape(*arc);
		fileManager.current().canvas()->setDrawing(false);
	}
}
