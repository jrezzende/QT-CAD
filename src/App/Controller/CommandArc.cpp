#include "CommandArc.h"
#include "Model.h"
#include "Canvas.h"

void CommandArc::mousePressEvent(Point & point)
{
	if (!isDrawing) {
		arc= new Arc();
		arc->setfirstPoint(point);

		previewLine= new Line();
		previewLine->setfirstPoint(point);

		previewDraw= true;
	}
	else
		secondClick= true;
}

void CommandArc::mouseMoveEvent(Point & point)
{
	if (previewDraw) {
		previewLine->setSecondPoint(point);

		model.getCurrentFile()->addShape(previewLine);
	}
	else if (isDrawing) {
		arc->setThirdPoint(point);

		model.getCurrentFile()->addShape(arc);
	}
}

void CommandArc::mouseReleaseEvent(Point & point)
{
	if (previewDraw) {
		model.getCurrentFile()->eraseLastShape();

		arc->setSecondPoint(point);

		previewDraw= false;
		isDrawing= true;
	}
}
