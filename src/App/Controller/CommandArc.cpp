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
		fileManager.currentFile().eraseShape(*previewLine);
	}
}

void CommandArc::mouseMoveEvent(const Point& point)
{
	if (!isDrawing) {
		previewLine->setSecondPoint(point);
      fileManager.currentFile().addShape(*previewLine);
	}
	else {
      fileManager.currentFile().addShape(*arc);
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
      fileManager.currentFile().addShape(*arc);
		fileManager.currentFile().canvas()->setDrawing(false);
	}
}
