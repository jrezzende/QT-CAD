#include "CommandBezier.h"
#include "Model.h"
#include "Canvas.h"

void CommandBezier::mousePressEvent(Point& point)
{
	if (!isDrawing) {
		bezier= new Bezier();
		previewLine= new Line();
		bezier->setfirstPoint(point);
		previewLine->setfirstPoint(point);

		setPreviewStatus(true);
	}
	else
		secondClick= true;
}

void CommandBezier::mouseMoveEvent(Point& point)
{
	if (previewDraw) {
		previewLine->setSecondPoint(point);
		bezier->setSecondPoint(point);

		model.getCurrentFile()->addShape(previewLine);
	}
	else if (isDrawing) {
		bezier->setThirdPoint(point);

		model.getCurrentFile()->eraseShape(previewLine);
		delete previewLine;

		model.getCurrentFile()->addShape(bezier);
	}
}

void CommandBezier::mouseReleaseEvent(Point& point)
{
	if (!isDrawing) {
		setPreviewStatus(false);
		setDrawStatus(true);
	}
}
