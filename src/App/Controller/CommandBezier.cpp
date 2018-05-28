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
      fileManager.current().eraseShape(*previewLine);
	}
}

void CommandBezier::mouseMoveEvent(const Point& point)
{
	if (!isDrawing) {
		previewLine->setSecondPoint(point);
      fileManager.current().addShape(*previewLine);
	}
	else {
		bezier->setThirdPoint(point);
      fileManager.current().addShape(*bezier);
	}
}

void CommandBezier::mouseReleaseEvent(const Point& point)
{
	if (!secondClick) {
      bezier->setSecondPoint(point);
		isDrawing= true;
	}
	else {
      fileManager.current().addShape(*bezier);
      fileManager.current().canvas()->setDrawing(false);
	}
}
