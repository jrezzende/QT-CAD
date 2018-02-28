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
	arc->setfirstPoint(Point(20, 20));
	arc->setSecondPoint(Point(25, 25));
	arc->setThirdPoint(Point(10, 30));

	arc->getCoordinates();

	return app.exec();
}