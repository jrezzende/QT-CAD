#include "CommandSave.h"
#include "CADFileManager.h"
#include "MainWindow.h"
#include "ShapeVisitorSaveFile.h"
#include "ViewMediator.h"

void CommandSave::execute(CADFileManager& m, ViewMediator& mediator)
{
	std::vector<CADShape*> shapesInFile= m.getCurrentFile()->getShapes();
	std::string filePath;
	std::ofstream os;

	if(m.getCurrentFile()->getStatus())
		return;

	if (m.getCurrentFile()->getFilePath().empty()) {
		filePath = mediator.retrieveFileLabel(SAVE);
		m.getCurrentFile()->setFilePath(filePath);
	}
	else
		filePath= m.getCurrentFile()->getFilePath();

	os.open(filePath, std::ios::out | std::ios::binary | std::ios::ate | std::ios::trunc);

	ShapeVisitorSaveFile v(os);

	if (os.is_open()) {
		for (auto shape : shapesInFile)
			shape->accept(v);
	}

	m.getCurrentFile()->setStatus(SAVED);

	os.close();
}
