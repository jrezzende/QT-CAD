#include "CommandSave.h"
#include "Model.h"
#include "MainWindow.h"
#include "Canvas.h"
#include "ShapeType.h"
#include "ShapeVisitorSaveFile.h"

void CommandSave::execute(Model& m, MainWindow& w)
{
	std::vector<Shape*> shapesInFile= m.getCurrentFile()->getShapes();
	std::string filePath;
	std::ofstream os;

	if(m.getCurrentFile()->getStatus())
		return;

	if (m.getCurrentFile()->getFilePath().empty()) {
		filePath = w.getSaveFileName();
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
