#include "CADFile.h"
#include "Canvas.h"

void CADFile::addShape(CADShape& shape)
{
	eraseShape(shape);

	shapes.push_back(&shape);

	clearRedo();

	setStatus(NOTSAVED);

	reprint();
}

void CADFile::mementoAddShape(CADShape& shape)
{
	eraseShape(shape);
	
	shapes.push_back(&shape);
}

void CADFile::addFromRedo(CADShape& shape)
{
	eraseShape(shape);

	shapes.push_back(&shape);

	setStatus(NOTSAVED);

	reprint();
}

void CADFile::eraseShape(CADShape& shape)
{
	for (int i = 0; i < shapes.size(); i++) {
		if(shapes[i] == &shape)
			shapes.erase(shapes.begin() + i);
	}

	reprint();
}

void CADFile::eraseLastShape()
{
	if(!(shapes.empty())) 
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
	canvas->clearMap();

	for(auto shape : shapes)
		canvas->drawMap(*shape);
	
	canvas->update();
}
