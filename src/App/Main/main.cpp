#include "qapplication.h"
#include "MainWindow.h"
#include "Point.h"
#include "Shape.h"
#include "Line.h"
#include <iostream>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	MainWindow w;

	Line* line= new Line(Point(10, 10), Point(50, 50));

	std::cout << line->getShapeType();

	return app.exec();
}