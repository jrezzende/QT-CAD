#include "File.h"
#include "Canvas.h"

void File::addShape(Shape* newShape)
{
	for (int i = 0; i < shapes.size(); i++) {
		if (shapes[i] == newShape)
			shapes.erase(shapes.begin() + i);
	}

	shapes.push_back(newShape);

	reprint();
}

void File::eraseShape(Shape * shape)
{
	for (int i = 0; i < shapes.size(); i++) {
		if(shapes[0] == shape)
			shapes.erase(shapes.begin() + i);
	}
}

void File::eraseLastShape()
{
	if(shapes.size() >= 1)
		shapes.pop_back();
	else
		return;

	reprint();
}

void File::eraseAllShapes()
{
	shapes.clear();

	reprint();

	canvas->update();
}

void File::reprint()
{
	canvas->clearMap();

	for(auto shape : shapes)
		canvas->drawMap(*shape);

	canvas->update();
}
