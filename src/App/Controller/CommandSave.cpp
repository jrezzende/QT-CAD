#include "CommandSave.h"
#include "CADFileManager.h"
#include "MainWindow.h"
#include "ShapeVisitorSaveFile.h"
#include "ViewMediator.h"

void CommandSave::execute(CADFileManager& fileManager, ViewMediator& viewMediator)
{
	if(fileManager.current().status())
		return;

   std::vector<CADShape*> shapesInFile = fileManager.current().shapesVector();
   std::ofstream os;

	if (fileManager.current().filePath().empty())
      fileManager.current().setFilePath(viewMediator.fileLabel(SAVE));

   const std::string filePath= fileManager.current().filePath();

	os.open(filePath, std::ios::out | std::ios::binary | std::ios::ate | std::ios::trunc);

	ShapeVisitorSaveFile v(os);

	if (os.is_open()) {
		for (const auto shape : shapesInFile)
			shape->accept(v);
	}

   fileManager.current().setStatus(SAVED);

	os.close();
}
