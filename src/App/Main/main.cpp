#include "qapplication.h"
#include "MainWindow.h"
#include "Point.h"
#include "Shape.h"
#include "Line.h"
#include "Arc.h"
#include <iostream>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	MainWindow w;

	Arc* arc= new Arc();
	arc->setfirstPoint(Point(-15, -12));
	arc->setThirdPoint(Point(-15, -30));
	arc->setSecondPoint(Point(-33, -16));
	

	arc->getCoordinates();

	return app.exec();
}