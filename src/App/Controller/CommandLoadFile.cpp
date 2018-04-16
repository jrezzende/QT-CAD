#include "CommandLoadFile.h"
#include "MainWindow.h"
#include "ViewMediator.h"
#include "CADFileManager.h"
#include "CADFile.h"
#include "CADLine.h"
#include "CADBezier.h"
#include "CADArc.h"

#include <fstream>

void CommandLoadFile::execute(CADFileManager& m, ViewMediator& mediator)
{
	std::string filePath= mediator.retrieveFileLabel(LOAD);

	if(filePath.empty())
		return;

   mediator.getCanvas().getPixmap().fill();

	std::ifstream is;

	int type;
	double p1X, p1Y, p2X, p2Y, p3X, p3Y;

	const auto file= new CADFile(filePath, &mediator.getCanvas());
	const auto mementoFile= new CADFile("memento", file->getCanvas());

   m.setCurrentFile(file);
   m.setMementoFile(mementoFile);

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
				file->addShape(*new CADLine(Point(p1X, p1Y), Point(p2X, p2Y)));
				break;
			}
			case BEZIER:
         {
				file->addShape(*new CADBezier(Point(p1X, p1Y), Point(p2X, p2Y), Point(p3X, p3Y)));
				break;
			}
			case ARC:
			{
				file->addShape(*new CADArc(Point(p1X, p1Y), Point(p2X, p2Y), Point(p3X, p3Y)));
				break;
			}
         default:
            break;
		}
	}
			m.setRedoFlag(false);
			m.getCurrentFile()->reprint();

			mediator.setTitle(QString::fromStdString(file->getFileName()));
	}
}