#include "CommandSave.h"
#include "CADFileManager.h"
#include "MainWindow.h"
#include "ShapeVisitorSaveFile.h"
#include "ViewMediator.h"

void CommandSave::execute(CADFileManager& m, ViewMediator& mediator)
{
	if(m.currentFile().status())
		return;

   std::vector<std::shared_ptr<CADShape>> shapesInFile = m.currentFile().shapesVector();
   std::ofstream os;

	if (m.currentFile().filePath().empty())
      m.currentFile().setFilePath(mediator.fileLabel(SAVE));

   const std::string filePath= m.currentFile().filePath();

	os.open(filePath, std::ios::out | std::ios::binary | std::ios::ate | std::ios::trunc);

	ShapeVisitorSaveFile v(os);

	if (os.is_open()) {
		for (const auto shape : shapesInFile)
			shape->accept(v);
	}

	m.currentFile().setStatus(SAVED);

	os.close();
}
