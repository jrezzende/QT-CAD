#include "CommandLoadFile.h"
#include "MainWindow.h"
#include "ViewMediator.h"
#include "CADFileManager.h"
#include "CADLine.h"
#include "CADBezier.h"
#include "CADArc.h"

#include <fstream>

void CommandLoadFile::execute(CADFileManager& fileManager, ViewMediator& viewMediator)
{
	std::string filePath= viewMediator.fileLabel(LOAD);

	if(filePath.empty())
		return;

   viewMediator.canvas().pixmap().fill();

	std::ifstream is;

	int type;
	int p1X, p1Y, p2X, p2Y, p3X, p3Y;

	const auto file= new CADFile(filePath, &viewMediator.canvas());
	const auto stashFile= new CADFile("stashFile", file->canvas());

   fileManager.setCurrentFile(file);
   fileManager.setStashFile(stashFile);

	is.open(filePath, std::ios::in | std::ios::binary);

	if (is.is_open()) {
		is.seekg(0);

		while (!is.eof()) {
			is.read(reinterpret_cast<char*>(&type), sizeof(int));

			is.read(reinterpret_cast<char*>(&p1X), sizeof(int));
			is.read(reinterpret_cast<char*>(&p1Y), sizeof(int));

			is.read(reinterpret_cast<char*>(&p2X), sizeof(int));
			is.read(reinterpret_cast<char*>(&p2Y), sizeof(int));

			if (type > 1) {
				is.read(reinterpret_cast<char*>(&p3X), sizeof(int));
				is.read(reinterpret_cast<char*>(&p3Y), sizeof(int));
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
			fileManager.setRedoFlag(false);
			fileManager.current().reprint();

         viewMediator.setTitle(QString::fromStdString(file->fileName()));
	}
}