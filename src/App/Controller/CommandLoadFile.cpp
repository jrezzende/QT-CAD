#include "CommandLoadFile.h"
#include "MainWindow.h"
#include "Model.h"
#include "Canvas.h"
#include "File.h"
#include "Line.h"
#include "Bezier.h"
#include "Arc.h"

#include <fstream>

void CommandLoadFile::execute(Model& m, MainWindow& w)
{
	std::string filePath= w.getOpenFileName();

	if(filePath == "")
		return;

	std::ifstream is;

	int type;
	double p1x, p1y, p2x, p2y, p3x, p3y;

	auto file= new File(filePath, w.createCanvas());
	auto mementoFile= new File("memento", file->getCanvas());

	m.addFile(file);
	m.addFile(mementoFile);

	is.open(filePath, std::ios::in | std::ios::binary);

	if (is.is_open()) {
		is.seekg(0);

		while (!is.eof()) {
			is.read((char*)&type, sizeof(int));

			is.read((char*)&p1x, sizeof(double));
			is.read((char*)&p1y, sizeof(double));

			is.read((char*)&p2x, sizeof(double));
			is.read((char*)&p2y, sizeof(double));

			if (type > 1) {
				is.read((char*)&p3x, sizeof(double));
				is.read((char*)&p3y, sizeof(double));
			}

			switch (type) 
			{
			case UNDEFINED:
				break;
			case LINE:
			{
				auto line = new Line(Point(p1x, p1y), Point(p2x, p2y));
				file->addShape(line);
				break;
			}
			case BEZIER:
			{
				auto bezier = new Bezier(Point(p1x, p1y), Point(p2x, p2y), Point(p3x, p3y));
				file->addShape(bezier);
				break;
			}
			case ARC:
			{
				auto arc = new Arc(Point(p1x, p1y), Point(p2x, p2y), Point(p3x, p3y));
				file->addShape(arc);
				break;
			}
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