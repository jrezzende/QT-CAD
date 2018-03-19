#include "File.h"
#include "Canvas.h"

void File::addShape(Shape* newShape)
{
	eraseShape(newShape);

	shapes.push_back(newShape);

	setStatus(NOTSAVED);

	reprint();
}

void File::eraseShape(Shape* shape)
{
	for (int i = 0; i < shapes.size(); i++) {
		if(shapes[i] == shape)
			shapes.erase(shapes.begin() + i);
	}

	reprint();
}

void File::eraseLastShape()
{
	if(shapes.size() > 0) 
		shapes.pop_back();

	reprint();
}

void File::eraseAllShapes()
{
	shapes.clear();

	reprint();
}

void File::reprint()
{
	canvas->clearMap();

	for(auto shape : shapes)
		canvas->drawMap(*shape);
	
	canvas->update();
}
