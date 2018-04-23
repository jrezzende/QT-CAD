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
	std::string filePath= mediator.fileLabel(LOAD);

	if(filePath.empty())
		return;

   mediator.canvas().pixmap().fill();

	std::ifstream is;

	int type;
	double p1X, p1Y, p2X, p2Y, p3X, p3Y;

	const auto file= new CADFile(filePath, &mediator.canvas());
	const auto mementoFile= new CADFile("memento", file->canvas());

   m.setCurrentFile(file);
   m.setMementoFile(mementoFile);

	is.open(filePath, std::ios::in | std::ios::binary);

	if (is.is_open()) {
		is.seekg(0);

		while (!is.eof()) {
			is.read(reinterpret_cast<char*>(&type), sizeof(int));

			is.read(reinterpret_cast<char*>(&p1X), sizeof(double));
			is.read(reinterpret_cast<char*>(&p1Y), sizeof(double));

			is.read(reinterpret_cast<char*>(&p2X), sizeof(double));
			is.read(reinterpret_cast<char*>(&p2Y), sizeof(double));

			if (type > 1) {
				is.read(reinterpret_cast<char*>(&p3X), sizeof(double));
				is.read(reinterpret_cast<char*>(&p3Y), sizeof(double));
			}

			switch (type) 
			{
			case UNDEFINED:
				break;
			case LINE: {
				file->addShape(*new CADLine(Point(p1X, p1Y), Point(p2X, p2Y)));
				break;
			}
         case BEZIER: {
				file->addShape(*new CADBezier(Point(p1X, p1Y), Point(p2X, p2Y), Point(p3X, p3Y)));
				break;
			}
			case ARC: {
				file->addShape(*new CADArc(Point(p1X, p1Y), Point(p2X, p2Y), Point(p3X, p3Y)));
				break;
			}
         default:
            break;
		}
	}
			m.setRedoFlag(false);
			m.currentFile()->reprint();

			mediator.setTitle(QString::fromStdString(file->fileName()));
	}
}