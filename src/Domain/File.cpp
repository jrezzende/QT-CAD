#include "File.h"
#include "Canvas.h"

void File::addShape(Shape * shape)
{
	shapes.push_back(shape);

	reprint();
}

void File::eraseShape(Shape* shape)
{
	for (int i= 0; i < shapes.size(); i++) {
		if(shapes[i] == shape)
			shapes.erase(shapes.begin() + i);
	}
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
