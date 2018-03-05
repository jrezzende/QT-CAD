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

void File::eraseLastShape()
{
	shapes.pop_back();

	reprint();
}

void File::eraseAllShapes(Shape * shape)
{
	shapes.clear();

	reprint();
}

void File::reprint()
{
	canvas->clearMap();

	for(auto shape : shapes)
		canvas->drawPixmap(*shape);

	canvas->update();
}
