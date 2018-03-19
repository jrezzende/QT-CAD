#include "CommandBezier.h"
#include "Model.h"
#include "Canvas.h"

void CommandBezier::mousePressEvent(Point& point)
{
	if (!isDrawing) {
		bezier = new Bezier();
		bezier->setfirstPoint(point);
		
		previewLine->setfirstPoint(point);
	}
	else
		secondClick= true;
}

void CommandBezier::mouseMoveEvent(Point& point)
{
	if (!isDrawing) {
		previewLine->setSecondPoint(point);

		model.getCurrentFile()->addShape(previewLine);
	}
	else {
		model.getCurrentFile()->eraseShape(previewLine);

		bezier->setThirdPoint(point);
		model.getCurrentFile()->addShape(bezier);
	}
}

void CommandBezier::mouseReleaseEvent(Point& point)
{
	if (!secondClick) {
		bezier->setSecondPoint(point);

		isDrawing= true;
	}
	else {
		model.getCurrentFile()->addShape(bezier);
		model.getCurrentFile()->getCanvas()->setDrawing(false);
		delete previewLine;
	}
}
