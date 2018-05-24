#include "CommandBezier.h"
#include "CADFileManager.h"
#include "Canvas.h"

void CommandBezier::mousePressEvent(const Point& point)
{
	if (!isDrawing) {
      bezier->setFirstPoint(point);
		previewLine->setFirstPoint(point);
	}
	else {
		secondClick = true;
      bezier->setThirdPoint(point);
      fileManager.currentFile().eraseShape(*previewLine);
	}
}

void CommandBezier::mouseMoveEvent(const Point& point)
{
	if (!isDrawing) {
		previewLine->setSecondPoint(point);
      fileManager.currentFile().addShape(*previewLine);
	}
	else {
		bezier->setThirdPoint(point);
      fileManager.currentFile().addShape(*bezier);
	}
}

void CommandBezier::mouseReleaseEvent(const Point& point)
{
	if (!secondClick) {
      bezier->setSecondPoint(point);
		isDrawing= true;
	}
	else {
      fileManager.currentFile().addShape(*bezier);
      fileManager.currentFile().canvas()->setDrawing(false);
	}
}
