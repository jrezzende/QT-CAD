#include "CADFile.h"
#include "Canvas.h"

void CADFile::addShape(std::shared_ptr<CADShape> shape)
{
	eraseShape(shape);

	shapes.push_back(shape);

   if(this->fileName() == "memento")
      return;

	clearRedo();

	setStatus(NOTSAVED);

	reprint();
}

void CADFile::addFromRedo(std::shared_ptr<CADShape> shape)
{
	eraseShape(shape);

	shapes.push_back(shape);

	setStatus(NOTSAVED);
}

void CADFile::eraseShape(std::shared_ptr<CADShape> shape)
{
	for (int i = 0; i < shapes.size(); i++) {
		if (shapes[i] == shape)
			shapes.erase(shapes.begin() + i);
	}

   if (this->fileName() == "memento")
      return;

	reprint();
}

void CADFile::eraseLastShape()
{
	if (!(shapes.empty())) 
		shapes.pop_back();

	reprint();
}

void CADFile::eraseAllShapes()
{
	shapes.clear();

	reprint();
}

void CADFile::reprint()
{
	drawArea->clearMap();

	for(const auto shape : shapes)
      drawArea->drawMap(*shape);
	
   drawArea->update();
}
