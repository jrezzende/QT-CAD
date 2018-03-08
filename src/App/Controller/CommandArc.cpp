#include "CommandArc.h"
#include "Model.h"
#include "Canvas.h"

void CommandArc::mousePressEvent(Point & point)
{
	if (!isDrawing) {
		arc= new Arc();
		arc->setfirstPoint(point);
	}
	else
		secondClick= true;
	/*if (!isDrawing) {
		arc= new Arc();
		arc->setfirstPoint(point);

		previewLine= new Line();
		previewLine->setfirstPoint(point);

		previewDraw= true;
	}
	else
		secondClick= true;*/
}

void CommandArc::mouseMoveEvent(Point & point)
{
	if (isDrawing) {
		arc->setThirdPoint(point);
		model.getCurrentFile()->addShape(arc);
	}

	/*if (previewDraw) {
		previewLine->setSecondPoint(point);

		model.getCurrentFile()->addShape(previewLine);
	}
	else if (isDrawing) {
		arc->setThirdPoint(point);

		model.getCurrentFile()->addShape(arc);
	}*/
}

void CommandArc::mouseReleaseEvent(Point & point)
{
	if (!isDrawing) {
		arc->setSecondPoint(point);
		isDrawing= true;
	}
	/*if (previewDraw) {
		model.getCurrentFile()->eraseLastShape();

		arc->setSecondPoint(point);

		previewDraw= false;
		isDrawing= true;
	}*/
}
