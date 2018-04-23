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
		m.currentFile().eraseShape(previewLine);
	}
}

void CommandBezier::mouseMoveEvent(const Point& point)
{
	if (!isDrawing) {
		previewLine->setSecondPoint(point);
		m.currentFile().addShape(previewLine);
	}
	else {
		bezier->setThirdPoint(point);
		m.currentFile().addShape(bezier);
	}
}

void CommandBezier::mouseReleaseEvent(const Point& point)
{
	if (!secondClick) {
		bezier->setSecondPoint(point);
		isDrawing= true;
	}
	else {
		m.currentFile().addShape(bezier);
		m.currentFile().canvas()->setDrawing(false);
	}
}
