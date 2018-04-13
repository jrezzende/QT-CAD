#include "CommandSave.h"
#include "CADFileManager.h"
#include "MainWindow.h"
#include "ShapeVisitorSaveFile.h"
#include "ViewMediator.h"

void CommandSave::execute(CADFileManager& m, ViewMediator& mediator)
{
	if(m.getCurrentFile()->getStatus())
		return;

   std::vector<CADShape*> shapesInFile = m.getCurrentFile()->getShapes();
   std::ofstream os;

	if (m.getCurrentFile()->getFilePath().empty())
      m.getCurrentFile()->setFilePath(mediator.retrieveFileLabel(SAVE));
   const std::string filePath= m.getCurrentFile()->getFilePath();

	os.open(filePath, std::ios::out | std::ios::binary | std::ios::ate | std::ios::trunc);

	ShapeVisitorSaveFile v(os);

	if (os.is_open()) {
		for (auto shape : shapesInFile)
			shape->accept(v);
	}

	m.getCurrentFile()->setStatus(SAVED);

	os.close();
}
