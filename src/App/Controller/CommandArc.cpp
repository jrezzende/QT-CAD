#include "CommandArc.h"
#include "Model.h"
#include "Canvas.h"

void CommandArc::mousePressEvent(Point & point)
{
	if (!isDrawing) {
		arc= new Arc();
		//previewLine= new Line();
		arc->setfirstPoint(point);
		//previewLine->setfirstPoint(point);

		//previewDraw= true;
	}
	else
		secondClick= true;
}

void CommandArc::mouseMoveEvent(Point & point)
{
	/*if (previewDraw) {
		previewLine->setSecondPoint(point);

		model.getCurrentFile()->addShape(previewLine);
	}*/

	if (isDrawing) {
		arc->setThirdPoint(point);
		model.getCurrentFile()->addShape(arc);
	}
}

void CommandArc::mouseReleaseEvent(Point & point)
{
	if (!secondClick) {
		//previewDraw= false;
		isDrawing= true;

		arc->setSecondPoint(point);

		//model.getCurrentFile()->eraseShape(previewLine);
		//delete previewLine;
	}
	else {
		model.getCurrentFile()->addShape(arc);
	}
}
