#include "CommandBezier.h"
#include "Model.h"
#include "Canvas.h"

void CommandBezier::mousePressEvent(Point& point)
{
	if (!isDrawing) {
		bezier= new Bezier();
		bezier->setfirstPoint(point);
		previewLine->setfirstPoint(point);

		previewDraw= true;
	}
	else
		secondClick= true;
}

void CommandBezier::mouseMoveEvent(Point& point)
{
	if (previewDraw) {
		previewLine->setSecondPoint(point);
		model.getCurrentFile()->addShape(previewLine);
	}
	else if (isDrawing) {
		bezier->setThirdPoint(point);
		model.getCurrentFile()->addShape(bezier);
	}
}

void CommandBezier::mouseReleaseEvent(Point& point)
{
	if (!secondClick) {
		previewDraw= false;
		isDrawing= true;
		bezier->setSecondPoint(point);
		model.getCurrentFile()->eraseShape(previewLine);
	}
	else {
		model.getCurrentFile()->addShape(bezier);
		model.getCurrentFile()->getCanvas()->setDrawing(false);
	}
}
