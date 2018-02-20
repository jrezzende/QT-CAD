#include "qapplication.h"
#include "MainWindow.h"
#include "Point.h"
#include <iostream>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	MainWindow w;

	return app.exec();
}