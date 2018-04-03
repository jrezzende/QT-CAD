#include "CommandLoadFile.h"
#include "MainWindow.h"
#include "Model.h"
#include "Canvas.h"
#include "CADFile.h"
#include "CADLine.h"
#include "CADBezier.h"
#include "CADArc.h"

#include <fstream>

void CommandLoadFile::execute(Model& m, MainWindow& w)
{
	std::string filePath= w.getOpenFileName();

	if(filePath.empty())
		return;

	std::ifstream is;

	int type;
	double p1X, p1Y, p2X, p2Y, p3X, p3Y;

	const auto file= new CADFile(filePath, w.createCanvas());
	const auto mementoFile= new CADFile("memento", file->getCanvas());

	m.addFile(file);
	m.addFile(mementoFile);

	is.open(filePath, std::ios::in | std::ios::binary);

	if (is.is_open()) {
		is.seekg(0);

		while (!is.eof()) {
			is.read((char*)&type, sizeof(int));

			is.read((char*)&p1X, sizeof(double));
			is.read((char*)&p1Y, sizeof(double));

			is.read((char*)&p2X, sizeof(double));
			is.read((char*)&p2Y, sizeof(double));

			if (type > 1) {
				is.read((char*)&p3X, sizeof(double));
				is.read((char*)&p3Y, sizeof(double));
			}

			switch (type) 
			{
			case UNDEFINED:
				break;
			case LINE:
			{
				file->addShape(CADLine(Point(p1X, p1Y), Point(p2X, p2Y)));
				break;
			}
			case BEZIER:
         {
				file->addShape(CADBezier(Point(p1X, p1Y), Point(p2X, p2Y), Point(p3X, p3Y)));
				break;
			}
			case ARC:
			{
				file->addShape(CADArc(Point(p1X, p1Y), Point(p2X, p2Y), Point(p3X, p3Y)));
				break;
			}
         default:
            break;
		}
	}
			m.setCurrentFile(file);
			m.setMementoFile(mementoFile);
			m.setMementoFlag(false);
			m.getCurrentFile()->reprint();

			w.setCentralWidget(file->getCanvas());
			w.setWindowTitle(QString::fromStdString(file->getFileName()));
	}
}